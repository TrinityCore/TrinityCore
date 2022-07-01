# Docker

The Circle CI Linux pch job uses the Dockerfile contained in the same folder as this README to create an image with the binaries built for Linux, and stores that in the job artifacts. For the 3.3.5 and master branches, it also pushes the images to https://hub.docker.com/r/trinitycore/trinitycore .

The instructions below expect a basic knowledge of how to configure TrinityCore and how to use Docker.

## Load the Docker image
For the 3.3.5 and master branches, it's possible to pull the images from DockerHub.
- For latest 3.3.5, use the following command:
  ```
  docker pull trinitycore/trinitycore:3.3.5
  ```
- For latest master, use the following command:
  ```
  docker pull trinitycore/trinitycore:master
  ```
- For a specific 3.3.5 or master commit, use the following command, replacing "commit_hash" with the hash of the commit:
  ```
  docker pull trinitycore/trinitycore:commit_hash
  ```

For Pull Requests or branches other than 3.3.5 or master, follow the steps below to load the image from Circle CI:
1. Click the green tick ✔ next to each commit.
1. Scroll to "ci/circleci: pch" and click "Details".
1. Log in to Circle CI if necessary. You may have to repeat the previous steps after logging in, to reach the correct page.
1. Click the "Artifacts" tab in the Circle CI website.
1. Download the docker.tar.gz archive containing the docker image.
1. Load the image into your Docker host, using the following command:
    ```
    docker load -i docker.tar.gz
    ```

## Start authserver/worldserver from Docker
1. Copy the .conf files from the TrinityCore GitHub repository to a local folder which will be passed on as a mapped volume to Docker.
1. Set the MySQL host in the .conf files to use the UNIX socket of MySQL, i.e.: `".;/var/run/mysqld/mysqld.sock;username;password;database"`
1. Set the "DataDir" config in worldserver.conf to `"/trinity/data"`
1. Start authserver or worldserver as desired, mapping the required volumes:

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

Note that the WORKDIR is set to /home/circleci and all logs will be saved to that folder by default. You can export the logs from the container with
```
docker cp "container name":/home/circleci/name.log name.log
```

For more instructions, please check the official docker documentation.

## Limitations:

- Database connection: The instructions provided expect MySQL to run on the host machine. Change `docker run` parameters and .conf settings to fit your scenario.
- To import TDB using the autoupdater:
  1. Download the TDB sql file from GitHub.
  1. Map it with `--volume=/path/to/TDB_full_name.sql:/home/circleci/TDB_full_name.sql` added to the commands specified in the main steps above.
  1. Run the container.
