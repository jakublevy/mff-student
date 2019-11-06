#!/bin/sh

mkdir -p build
cwd=$(pwd)
cd build
stack exec -- ghc ../Main.hs ../TokenParser.hs ../StringParser.hs ../State.hs ../Parser.hs ../SlepysLexer.hs ../SlepysPrettifier.hs -odir . -hidir . -o slepys
cd $cwd
