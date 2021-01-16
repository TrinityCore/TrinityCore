# Docker
Circle CI linux pch job uses the Dockerfile contained in the same folder as this README to create an image with the binaries built for linux and store that in the job artifacts.

The instructions below expect basic knowledge about how to configure TrinityCore and how to use Docker:
1. Click on the green ✔ next to each commit
1. Scroll to "ci/circleci: pch" and click on "Details"
1. Login to Circle CI if necessary. You might have to repeat again the previous steps after logging in to reach the correct page
1. Click on "Artifacts" tab in Circle CI website
1. Download the docker.tar.gz archive containing the docker image
1. Load the image into your Docker host using
    ```
    docker load -i docker.tar.gz
    ```
1. Copy the .conf files from TrinityCore GitHub repository to a local folder that will be passed as mapped volume to docker
1. Set the MySQL host in the .conf files to use the unix socket of MySQL, i.e.: ``".;/var/run/mysqld/mysqld.sock;username;password;database``
1. Set the "DataDir" config in worldserver.conf to ``"/trinity/data"``
1. Start authserver or worldserver as desired, mapping the required volumes
    - authserver
        ```
        docker run --entrypoint=authserver -it --volume=/host/path/to/configs:/home/circleci/project/bin/check_install/etc --volume=/var/run/mysqld/mysqld.sock:/var/run/mysqld/mysqld.sock -p=3724:3724 "image name"
        ```
    - worldserver
        ```
        docker run --entrypoint=worldserver -it --volume=/host/path/to/configs:/home/circleci/project/bin/check_install/etc --volume=/var/run/mysqld/mysqld.sock:/var/run/mysqld/mysqld.sock --volume=/path/to/data/directory:/trinity/data -p=8085:8085 "image name"
        ```
    Change the ports and other parameters as needed. Consult Docker documentation for additional details about possible configuration settings.

## Content
The image contains:
- authserver
- mapextractor
- mmaps_generator
- vmap4asembler
- vmap4extractor
- worldserver
- README&#46;md

You can explore the image using
```
docker run --entrypoint=/bin/bash -it "image name"
```
Note that the WORKDIR is set to /home/circleci and by default all logs will be saved in that folder. You can export the logs from the container with
```
docker cp "container name":/home/circleci/name.log name.log
```

For more instructions please check docker official documentation.

## Limitations:
- Database connection: the instructions provided expect MySQL to run on the host machine. Change ``docker run`` parameters and .conf settings to fit your scenario
- To import TDB using the autoupdater:
  1. Download the TDB sql file from GitHub
  1. Map it with ``--volume=/path/to/TDB_full_name.sql:/home/circleci/TDB_full_name.sql`` added to the commands specified in the main steps above
  1. Run the container
