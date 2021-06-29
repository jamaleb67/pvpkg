import scipy.fftpack
import numpy as np
import sys
import os

from scipy import signal
from datetime import datetime

#Creating Dump file
now = datetime.now() #current date and time
iso_time = now.strftime("%Y%m%d%H%M%S.%f")

leaf_dir = "dump_" + iso_time
parent_dir = "./"

dump_dir = parent_dir + leaf_dir
path = os.path.join("./", dump_dir)
os.makedirs(path)


def dump(vsnk):

    sample_count = range(len(vsnk[0].data()))
    channels = range(len(vsnk))

    for sample in sample_count:
        for channel in channels:
            datum = vsnk[channel].data()[sample]
            sys.stdout.write("%10.5f %10.5f\t" % (datum.real, datum.imag))

        sys.stdout.write("\n")

    sys.stdout.write("\n")
    return None

def dump_file(vsnk, wave_freq):

    sample_count = range(len(vsnk[0].data()))
    channels = range(len(vsnk))

    for sample in sample_count:

        for channel in channels:
            datum = vsnk[channel].data()[sample]
            #Writing to a file
            f = open(path+"/CH_" + str(channel) + "_WF_" + str(wave_freq) + ".dat", "a")
            f.write("%10.5f %10.5f\t" % (datum.real, datum.imag) + "\n")

    return None


def fundamental(real_wave, sample_rate):

    N = len(real_wave)
    T = 1.0 / sample_rate
    x  = np.linspace(int(0.0), int(N * T), int(N))
    xf = np.linspace(int(0.0), int(1.0 / (2.0 * T)), int(N / 2.0))
    yf = 2.0 / N * np.abs(scipy.fftpack.fft(real_wave)[:N // 2])
    indices = np.argwhere(yf > np.max(yf) / 2)

    return np.mean(xf[indices])


def absolute_area(complex_wave):

    return abs(np.trapz(np.absolute(complex_wave)))


def lag(real_wave, imag_wave, sample_rate, wave_freq):

    forewards = np.argmax(signal.correlate(real_wave, imag_wave)) - len(real_wave) + 1
    backwards = np.argmax(signal.correlate(imag_wave, real_wave)) - len(imag_wave) + 1

    lag = (abs(forewards) + abs(backwards)) / 2.0
    return lag / (float(sample_rate) / float(wave_freq))

