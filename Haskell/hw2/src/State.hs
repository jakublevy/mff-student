{-# LANGUAGE TupleSections #-}

module State(State, state, runState, get, put, evalState) where

newtype State s a = S { runState :: s -> (a, s) }

state :: (s -> (a, s)) -> State s a
state = S

get :: State s s
get = state $ \s -> (s, s)

put :: s -> State s ()
put newState = S $ const ((), newState)

evalState :: State s a -> s -> a
evalState state s = fst $ runState state s

instance Functor (State s) where
-- fmap :: (a -> b) -> State s a -> State s b
   fmap g st = g <$> st
   
instance Applicative (State s) where
-- pure :: a -> State s a
   pure x = S (x,)
   
-- (<*>) :: State s (a -> b) -> State s a -> State s b
   stf <*> stx = do
                 f <- stf
                 f <$> stx
   
instance Monad (State s) where
-- (>>=) :: State s a -> (a -> State s b) -> State s b
   st >>= f = S (\s -> let (x,s') = runState st s in runState (f x) s')