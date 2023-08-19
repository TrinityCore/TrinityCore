FROM The-Cataclysm-Preservation-Project/circle-ci:4.3.4-base-22.04

#Setup
WORKDIR /home/circleci
COPY README.md /
COPY --chown=circleci:circleci sql /home/circleci/project/sql
COPY bin /usr/local/bin/
COPY lib /usr/local/lib/
ENTRYPOINT [ "echo",  "Check the README.md file for instructions"]
