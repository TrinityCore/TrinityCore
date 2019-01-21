#!/usr/bin/env bash

cd /usr/src

if [[ ! -d build ]]; then
    mkdir build
fi

cd build
cmake ../
make && make install