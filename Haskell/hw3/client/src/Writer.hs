module Writer(Writer
           , initWriter
           , write
           , stopWriter) where

import Control.Concurrent
import Control.Concurrent.MVar(MVar)
import System.IO(Handle, hPutStr, hFlush)

newtype Writer = Writer (MVar WriteCmd)
data WriteCmd = Message Handle String | Stop (MVar ())

initWriter :: IO Writer
initWriter = do
             m <- newEmptyMVar
             let w = Writer m
             forkIO $ writer w
             return w

writer :: Writer -> IO ()
writer (Writer m) = loop
    where
        loop = do
               cmd <- takeMVar m
               case cmd of
                    Message h msg -> do
                                     hPutStr h $ msg ++ "\r\n"
                                     hFlush h
                                     loop
                    Stop s -> putMVar s ()


write :: Writer -> Handle -> String -> IO ()
write (Writer m) h msg = do 
                         forkIO $ putMVar m (Message h msg)
                         return ()

stopWriter :: Writer -> IO ()
stopWriter (Writer m) = do
                  s <- newEmptyMVar
                  putMVar m (Stop s)
                  takeMVar s