FROM trinitycore/circle-ci:debian-12-runner

#Setup
WORKDIR /home/circleci
COPY README.md /
COPY --chown=circleci:circleci sql /home/circleci/project/sql
COPY bin /usr/local/bin/
ENTRYPOINT [ "echo",  "Check the README.md file for instructions"]
