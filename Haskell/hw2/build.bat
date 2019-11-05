@ECHO OFF
set curdir=%cd%
if not exist build mkdir build
cd build
stack exec -- ghc ../Main.hs ../TokenParser.hs ../StringParser.hs ../State.hs ../Parser.hs ../SlepysLexer.hs -odir . -hidir . -o slepys.exe
cd %curdir%
@ECHO OFF
