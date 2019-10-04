pipeline {
    parameters {
        string(name: 'BUILD_THREADS', defaultValue: '', description: 'Build threads')

        string(name: 'WITH_DYNAMIC_LINKING',  defaultValue: '0',              description: 'Build Option WITH_DYNAMIC_LINKING')
        string(name: 'SCRIPTS',               defaultValue: 'static',         description: 'Build Option SCRIPTS')
        string(name: 'BNETSERVER',            defaultValue: '1',              description: 'Build Option BNETSERVER')
        string(name: 'WORLDSERVER',           defaultValue: '1',              description: 'Build Option WORLDSERVER')
        string(name: 'TOOLS',                 defaultValue: '0',              description: 'Build Option TOOLS')
        string(name: 'WITH_WARNINGS',         defaultValue: '1',              description: 'Build Option WITH_WARNINGS')
        string(name: 'USE_COREPCH',           defaultValue: '1',              description: 'Build Option USE_COREPCH')
        string(name: 'USE_SCRIPTPCH',         defaultValue: '1',              description: 'Build Option USE_SCRIPTPCH')
        string(name: 'WITH_COREDEBUG',        defaultValue: '0',              description: 'Build Option WITH_COREDEBUG')
        string(name: 'CMAKE_BUILD_TYPE',      defaultValue: 'RelWithDebInfo', description: 'Build Option CMAKE_BUILD_TYPE')
        string(name: 'CMAKE_ADDITIONAL',      defaultValue: '',               description: 'Additional CMake parameters')
    }

    agent {
        node {
            label ''
            customWorkspace "/srv/jenkins/${JOB_NAME}"
        }
    }

    options {
        buildDiscarder(logRotator(daysToKeepStr: '30'))
        checkoutToSubdirectory('git')
        disableConcurrentBuilds()
        timestamps()
    }

    stages {
        stage('Build') {
            steps {
                echo 'Building...'
                dir('build') {
                    sh "cmake ../git -DCMAKE_INSTALL_PREFIX=../ -DWITH_DYNAMIC_LINKING=${params.WITH_DYNAMIC_LINKING} -DSCRIPTS=${params.SCRIPTS} -DBNETSERVER=${params.BNETSERVER} -DWORLDSERVER=${params.WORLDSERVER} -DTOOLS=${params.TOOLS} -DWITH_WARNINGS=${params.WITH_WARNINGS} -DUSE_COREPCH=${params.USE_COREPCH} -DUSE_SCRIPTPCH=${params.USE_SCRIPTPCH} -DWITH_COREDEBUG=${params.WITH_COREDEBUG} -DCMAKE_BUILD_TYPE=${params.CMAKE_BUILD_TYPE} -DBoost_NO_BOOST_CMAKE=ON ${params.CMAKE_ADDITIONAL}"
                    sh """
                        set +x

                        THREADS="${GLOBAL_BUILD_THREADS}"

                        if [ ! -z "${params.BUILD_THREADS}" ]; then
                            THREADS="${params.BUILD_THREADS}"
                        fi

                        echo "Build started with \${THREADS} threads."
                        make -j\${THREADS} -k
                    """
                }
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying...'
                dir('build') {
                    sh 'make install'
                }
                dir('bin') {
                    sh './bnetserver  --version'
                    sh './worldserver  --version'
                }
            }
        }
    }
}
