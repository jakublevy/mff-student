module Reader(Reader
           , initReader
           , lastMsg) where

import Control.Concurrent
import Control.Concurrent.MVar(MVar)
import System.IO(Handle, hGetLine)

newtype Reader = Reader (MVar String)

initReader :: Handle -> IO (Reader, ThreadId)
initReader h = do
             m <- newEmptyMVar
             let w = Reader m
             tId <- forkIO $ reader h w
             return (w, tId)

reader :: Handle -> Reader -> IO ()
reader h (Reader m) = loop
    where
        loop = do
               inp <- init <$> hGetLine h
               tryTakeMVar m
               putMVar m inp
               loop

lastMsg :: Reader -> IO (Maybe String)
lastMsg (Reader m) = tryTakeMVar m