module Main(main) where

import Control.Monad
import Control.Monad.Combinators.Expr
import Data.Void
import Text.Megaparsec
import Text.Megaparsec.Char
import qualified Text.Megaparsec.Char.Lexer as L

main :: IO ()
main = return ()

lineCmnt = L.skipLineComment "//"
blockCmnt = L.skipBlockComment "/*" "*/"

sc :: Parser ()
sc = L.space (void $ takeWhile1P Nothing f) lineCmnt blockCmnt
  where
    f x = x == ' ' || x == '\t'

scn :: Parser ()
scn = L.space space1 lineCmnt empty

lexeme :: Parser a -> Parser a
lexeme = L.lexeme sc

symbol :: String -> Parser String
symbol = L.symbol sc

symbolC :: Char -> Parser Char
symbolC c = do
            symbol [c] 
            return c

integer :: Parser Integer
integer = lexeme L.decimal

semi :: Parser String
semi = symbol ";"

rword :: String -> Parser ()
rword w = (lexeme . try) (string w *> notFollowedBy alphaNumChar)

rws :: [String] 
rws = ["if","def","else","while","pass"]

ident :: Parser String
ident = (lexeme . try) (p >>= check)
  where p = (:) <$> identFirst <*> many identRest
        check x = if x `elem` rws
                then fail $ "keyword " ++ show x ++ " cannot be an identifier"
                else return x
        
        identFirst = lowerChar <|> symbolC '_'
        identRest = alphaNumChar <|> symbolC '_'