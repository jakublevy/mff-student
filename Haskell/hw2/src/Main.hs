import SlepysParser
import SlepysLexer
import SlepysPrettifier

import Data.List
import System.Environment
import System.Exit
import System.Directory
import System.IO
import System.FilePath(replaceExtension)

-- main :: IO ()
-- main = do
--        inp <- getContents
--        let res = tokens inp
--        case res of
--             Right tok -> putStrLn (intercalate "\n" (map show tok))
--             Left msg -> putStrLn msg
--        return ()

main :: IO ()
main = do
     args <- getArgs
     if "--help" `elem` args || "-help" `elem` args || "-h" `elem` args then do
        printHelp
        exitSuccess
     else --some work with arguments
        foldl (\_ f -> processFile f) (return ()) args

processFile :: FilePath -> IO ()
processFile fileN = do
                    putStrLn fileN
                    fileExists <- doesFileExist fileN
                    if fileExists then do
                       h <- openFile fileN ReadMode 
                       buf <- hGetContents h
                       ast <- createAst buf
                       outputPretty fileN ast

                       putStrLn ""
                       print ast
                       

                       return () 
                    else do
                        putStrLn $ "   " ++ "ERROR: does not appear to be existing file"
                        exitWith $ ExitFailure 10

outputPretty :: FilePath -> Slepys -> IO ()
outputPretty origFileN ast = do
                         let newFileN = replaceExtension origFileN "pretty"
                         h <- openFile newFileN WriteMode
                         hPutStr h (prettify ast)
                         hClose h


createAst :: String -> IO Slepys
createAst buf = case tokens buf of
                     Right tok -> do
                                  putStrLn "   Lexical Analysis: OK"

                                 --  putStrLn (intercalate "\n" (map show tok))

                                  parsing tok
                     Left msg -> do 
                                 putStrLn $ "   Lexical Analysis: ERROR - " ++ msg
                                 exitWith $ ExitFailure 20 
                    
parsing :: [Token] -> IO Slepys
parsing ts = case parseTokens ts of
                  Right ast -> do
                               putStrLn "   Parsing: OK"
                               return ast
                  Left msg -> do
                              putStrLn $ "   Parsing: ERROR - " ++ msg
                              exitWith $ ExitFailure 30


printHelp :: IO ()
printHelp = putStrLn $ "Usage: " ++ file ++ " <FILE_PATH> [..n]"
                 ++ "\n       " ++  file ++ " {-h | -help | --help}"
                 ++ "\n\nThe following example creates (in case of success) two output files fact.out and fib.out"
                 ++ "\nExample: slepys[.exe] fact.slepys fib.slepys"
                 ++ "\n\nExit codes:  0 - Success"
                 ++ "\n            10 - Supplied argument does not point to an existing file"
                 ++ "\n            20 - Lexical Analysis failed"
                 ++ "\n            30 - Parsing failed"
                 ++ "\n            40 - Semantic Analysis failed"
    where file = "slepys[.exe]"
            