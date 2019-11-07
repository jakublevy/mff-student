module Parser(Parser(parse), makeParser, (<|>), empty, some, many) where

import Control.Applicative
import Control.Monad.Fail

newtype Parser s a = P { parse :: s -> [(a, s)] }

makeParser :: (s -> [(a, s)]) -> Parser s a
makeParser = P

instance Functor (Parser s) where
 -- fmap :: (a -> b) -> Parser a -> Parser b
    fmap f (P p) = P $ \inp -> p inp >>= \(x, out) -> return (f x, out)

instance Applicative (Parser s) where
 -- pure :: a -> Parser a
    pure x = P $ \out -> [(x, out)]

 -- (<*>) :: Parser (a -> b) -> Parser a -> Parser b
    P pf <*> p = P $ \inp -> pf inp >>= \(f, inp2) -> parse (fmap f p) inp2

instance Monad (Parser s) where
 -- return = pure
 
 -- (>>=) :: Parser a -> (a -> Parser b) -> Parser b
    P p >>= f = P $ \inp -> p inp >>= \(x, inp2) -> parse (f x) inp2

instance Alternative (Parser s) where
 -- empty :: Parser a
    empty = P $ const []

 -- (<|>) :: Parser a -> Parser a -> Parser a
    P p1 <|> P p2 = P $ \inp -> case p1 inp of 
                                    [(x, out)] -> [(x, out)]
                                    [] -> p2 inp

 -- many :: StringParser a -> Parser [a]
    many p = some p <|> pure []

 -- some :: Parser a -> Parser [a]
    some p = (:) <$> p <*> many p

instance MonadFail (Parser a) where
    fail msg = empty