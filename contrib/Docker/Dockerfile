FROM funjoker/circle-ci:4.3.4-buildpacks-focal

#Setup
WORKDIR /home/circleci
COPY README.md /
COPY --chown=circleci:circleci sql /home/circleci/project/sql
COPY ["authserver", "mapextractor", "mmaps_generator", "vmap4assembler", "vmap4extractor", "worldserver", "/usr/local/bin/"]
ENTRYPOINT [ "echo",  "Check the README.md file for instructions"]
