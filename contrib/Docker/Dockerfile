FROM trinitycore/circle-ci:3.3.5-buildpacks-focal

#Setup
COPY authserver /usr/local/bin/
COPY mapextractor /usr/local/bin/
COPY mmaps_generator /usr/local/bin/
COPY vmap4asembler /usr/local/bin/
COPY vmap4extractor /usr/local/bin/
COPY worldserver /usr/local/bin/
COPY README.md /
ENTRYPOINT [ "echo Check the README.md file for instructions"]