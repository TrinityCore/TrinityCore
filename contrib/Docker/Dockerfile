FROM trinitycore/circle-ci:3.3.5-buildpacks-focal

#Setup
COPY ["authserver", "mapextractor", "mmaps_generator", "vmap4assembler", "vmap4extractor", "worldserver", "/usr/local/bin/"]
COPY README.md /
ENTRYPOINT [ "echo Check the README.md file for instructions"]