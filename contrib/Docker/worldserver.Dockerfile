FROM trinitycore/circle-ci:3.3.5-buildpacks-focal

#Setup
COPY worldserver /usb/bin/worldserver
ENTRYPOINT [ "worldserver" ]
