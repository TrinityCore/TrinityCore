FROM trinitycore/circle-ci:master-buildpacks-focal

#Setup
WORKDIR /home/circleci
COPY README.md /
COPY --chown=circleci:circleci sql /home/circleci/project/sql
COPY ["bnetserver", "mapextractor", "mmaps_generator", "vmap4assembler", "vmap4extractor", "worldserver", "/usr/local/bin/"]
ENTRYPOINT [ "echo",  "Check the README.md file for instructions"]
