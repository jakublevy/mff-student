@ECHO OFF
set curdir=%cd%
if not exist build mkdir build
cd build
stack exec -- ghc ../src/Main.hs ../src/TokenParser.hs ../src/StringParser.hs ../src/State.hs ../src/Parser.hs ../src/SlepysLexer.hs ../src/SlepysParser.hs ../src/SlepysPrettifier.hs -odir . -hidir . -o slepys.exe
cd %curdir%
@ECHO OFF
