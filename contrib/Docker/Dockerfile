FROM trinitycore/circle-ci:3.3.5-buildpacks-focal

#Setup
COPY worldserver /usr/local/bin/
COPY authserver /usr/local/bin/
ENTRYPOINT [ "worldserver" ]
#docker run "image name" --entrypoint=authserver --config authserver.conf
#docker run "image name" --entrypoint=worldserver --config worldserver.conf