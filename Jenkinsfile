pipeline { 

    environment { 

        registry = "than97/pvpkg" 

        registryCredential = '85454c7d-a176-4e4c-94c2-d415e42a4cc3' 

        dockerImageArchLatest = '' 
        dockerImageArchPython2= ''
        dockerImageCentos8 = '' 
        dockerImageUbuntu1804 = '' 
        dockerImageUbuntu2004 = '' 
    }
// citests agents used to build and test repo.
    agent {
	label 'crossci||waveci'
    }

    stages { 

        // Build stages for each distribution are set to run in parallel. Need to add build artifacts and run tests 
        // for each parallel build. 
 
        stage('Build UHD and GNU Radio') {
        parallel {

              //stage('ArchLinux') { 

                 // steps { 
		      //Build Image

                      // script { 
                        //      dir("${env.WORKSPACE}/Arch") {
                    	//	      dockerImageArch = docker.build(registry + ":$BUILD_NUMBER", "--network host .") 
                  	//}
		       //Test with pvtests

		      //If passed, save UHD package.
                     // }
                //  } 

           //   }

                stage('ArchLinuxLatestImage') { 

                  steps { 
		      //Build Image

                      script { 
                              dir("${env.WORKSPACE}/ArchlinuxLatestImage") {
                    		      dockerImageArchLatest = docker.build(registry + ":$BUILD_NUMBER", "--network host .") 
                  	}
		       //Test with pvtests

		      //If passed, save UHD package.
                      }
                  } 

              }


               stage('CentOS 8') { 

                  steps { 

                       script { 
                             dir("${env.WORKSPACE}/CentOS/8") {
                                     dockerImageCentos8 = docker.build(registry + ":$BUILD_NUMBER", "--network host .") 
                       }
                     }
                    } 

             }



               stage('Ubuntu 20.04 PV libUHD') { 

                   steps { 

                      script { 
                             dir("${env.WORKSPACE}/ubuntu/20.04notsource2") {
                                     dockerImageUbuntu1804 = docker.build(registry + ":$BUILD_NUMBER", "--network host .") 
                        }
                       }
                     } 

             }
             
               stage('Ubuntu 20.04 PV libUHD and Gnuradio from Source') { 

                   steps { 

                      script { 
                              dir("${env.WORKSPACE}/ubuntu/20.04notsource") {
                                       dockerImageUbuntu2004 = docker.build(registry + ":$BUILD_NUMBER", "--network host .") 
                }
               }
           } 

      }

       }
      }

	// Replace with the other distributions
        stage('Deploy our image') { 

            steps { 

                script { 
                   
      
                    docker.withRegistry( '', registryCredential ) { 

                        dockerImageArch.push() 
                        dockerImageArchLatest.psuh()
                        dockerImageCentos8.push() 
                        dockerImageUbuntu1804.push() 
                        dockerImageUbuntu2004.push() 
                    }

                } 

            }

        } 
        stage('Cleaning up') { 

            steps { 

                sh "docker rmi $registry:$BUILD_NUMBER" 

            }
        } 
    }
}


