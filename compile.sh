#!/bin/bash

cd ./build
make

cd ../api
./compiler ../code.txt