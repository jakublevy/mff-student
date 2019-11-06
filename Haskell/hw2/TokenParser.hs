{-# LANGUAGE LambdaCase #-}

module TokenParser(TokenParser
                 , token
                 , lexem
                 , module SlepysLexer
                 , module Parser) where

import Control.Monad.Fail
import SlepysLexer
import Parser

type TokenParser = Parser [Token]

token :: TokenParser Token
token = makeParser $ \case
                     ((l,t) : xs) -> [((l, t), xs)]
                     [] -> []

lexem :: TokenParser Lexem
lexem = snd <$> token
