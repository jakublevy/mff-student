module StringParser where

import Parser
import Data.Char(isLower, isUpper, isDigit)

type StringParser = Parser String

item :: StringParser Char
item = makeParser $ \inp -> case inp of
                (x : xs) -> [(x, xs)]
                [] -> []

sat :: (Char -> Bool) -> StringParser Char
sat p = do
        c <- item
        if p c then
            return c
        else 
            empty

upperCase :: StringParser Char
upperCase = sat isUpper

lowerCase :: StringParser Char
lowerCase = sat isLower

letter :: StringParser Char
letter = lowerCase <|> upperCase

digit :: StringParser Char
digit = sat isDigit

char :: Char -> StringParser Char
char c = sat (==c)

string :: String -> StringParser String
string [] = pure []
string (x : xs) = (:) <$> char x <*> string xs

nat :: StringParser Int
nat = fmap read (some digit)

neg :: StringParser Int
neg = do
      char '-'
      n <- nat
      return (-n)

int :: StringParser Int
int = neg <|> nat

space :: StringParser Char
space = sat (== ' ')

spaces :: StringParser Int
spaces = length <$> some space

eol :: StringParser Char
eol = sat (== '\n')

eols :: StringParser Int
eols = length <$> some eol
