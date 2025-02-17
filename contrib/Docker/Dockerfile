FROM trinitycore/circle-ci:3.3.5-base-22.04

#Setup
WORKDIR /home/circleci
COPY README.md /
COPY --chown=circleci:circleci sql /home/circleci/project/sql
COPY bin /usr/local/bin/
ENTRYPOINT [ "echo",  "Check the README.md file for instructions"]
