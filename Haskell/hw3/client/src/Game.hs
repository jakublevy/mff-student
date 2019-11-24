module Game
  ( isAlive
  , conv
  ) where

import Data.Set(member, insert, empty, Set)
import GameTypes

isAlive :: ScreenState -> Pos -> Bool
isAlive s pos = pos `member` cells s

conv :: String -> Set Pos
conv b = foldl (\a (i, v) -> if v == 'x' then 
                                insert (i `mod` boardW, i `div` boardH) a
                             else a
               ) empty (zip [0..] b)
