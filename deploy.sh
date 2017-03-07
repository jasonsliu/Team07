#!/bin/bash

rm -rf deploy/
mkdir deploy/
cp config_deploy deploy/
cp Dockerfile.run deploy/
cp -r files/ deploy/
cp -r files1/ deploy/
cp -r files2/ deploy/

#build the binary
docker build -t httpserver.build .
docker run httpserver.build > binary.tar
tar -xvf binary.tar -C ./deploy

#build the new image
docker build -t httpserver -f deploy/Dockerfile.run ./deploy
docker run --rm -t -p 8080:8080 httpserver

rm -f binary.tar
