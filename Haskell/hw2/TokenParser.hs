module TokenParser where

import Control.Monad
import SlepysLexer
import Parser

type TokenParser = Parser [Token]

item :: TokenParser Token
item = makeParser $ \inp -> case inp of
                ((l,t) : xs) -> [((l, t), xs)]
                [] -> []

-- sat :: (Token -> Bool) -> TokenParser String
-- sat p = do


-- newtype TokenParser a = P { parseToken :: [(LineNum, Token)] -> [(a, [(LineNum, Token)])] }

-- makeTokenParser :: ([(LineNum, Token)] -> [(a, [(LineNum, Token)])]) -> TokenParser a
-- makeTokenParser = P