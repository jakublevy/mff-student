{-# LANGUAGE TupleSections #-}

import Control.Monad
import Control.Monad.Combinators.Expr
import Data.Void
import Text.Megaparsec
import Text.Megaparsec.Char
import qualified Text.Megaparsec.Char.Lexer as L
import Data.Char

type Parser = Parsec Void String

lineCmnt = L.skipLineComment "#"
blockCmnt = L.skipBlockComment "/*" "*/"

sc :: Parser ()
sc = L.space (void $ takeWhile1P Nothing f) lineCmnt blockCmnt
  where
    f x = x == ' ' || x == '\t'

scn :: Parser ()
scn = L.space space1 lineCmnt blockCmnt

lexeme :: Parser a -> Parser a
lexeme = L.lexeme sc


-- parser :: Parser (String, [String])
parser :: Parser (String, [(String, [String])])
parser = pItemList <* eof

-- pItemList :: Parser (String, [String]) -- header and list items
pItemList :: Parser (String, [(String, [String])])
pItemList = L.nonIndented scn (L.indentBlock scn p)
  where
    p = do
      header <- pItem
      return (L.IndentSome Nothing (return . (header, )) pComplexItem)


pItem :: Parser String
pItem = lexeme (takeWhile1P Nothing f) <?> "list item"
  where
    f x = isAlphaNum x || x == '-'


pComplexItem :: Parser (String, [String])
pComplexItem = L.indentBlock scn p
  where
    p = do
      header <- pItem
      return (L.IndentMany Nothing (return . (header, )) pItem)

-- pComplexItem :: Parser (String, [String])
-- pComplexItem = L.indentBlock scn p
--   where
--     p = do
--       header <- pItem
--       return (L.IndentMany Nothing (return . (header, )) pLineFold)

pLineFold :: Parser String
pLineFold = L.lineFold scn $ \sc' ->
  let ps = takeWhile1P Nothing f `sepBy1` try sc'
      f x = isAlphaNum x || x == '-'
  in unwords <$> ps <* sc