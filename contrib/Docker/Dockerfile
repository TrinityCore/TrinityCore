FROM cataclysmpreservationproject/circle-ci:master-base-22.04

#Setup
WORKDIR /home/circleci
COPY README.md /
COPY --chown=circleci:circleci sql /home/circleci/project/sql
COPY bin /usr/local/bin/
ENTRYPOINT [ "echo",  "Check the README.md file for instructions"]
