{-# LANGUAGE TupleSections #-}

module State(State
           , state
           , runState
           , get
           , gets
           , put
           , evalState) where

newtype State s a = S { runState :: s -> (a, s) }

state :: (s -> (a, s)) -> State s a
state = S

get :: State s s
get = state $ \s -> (s, s)

gets :: (s -> a) -> State s a
gets f = state $ \s -> (f s, s)

put :: s -> State s ()
put newState = S $ const ((), newState)

evalState :: State s a -> s -> a
evalState state s = fst $ runState state s

instance Functor (State s) where
-- fmap :: (a -> b) -> State s a -> State s b
   fmap g st = state $ \s -> let (x,y) = runState st s
                             in (g x, y)
   
instance Applicative (State s) where
-- pure :: a -> State s a
   pure x = state (x,)
   
-- (<*>) :: State s (a -> b) -> State s a -> State s b
   stf <*> stx = state $ \s -> let (f, s2) = runState stf s
                                   (x, s3) = runState stx s2
                               in (f x, s3)
   
instance Monad (State s) where
-- (>>=) :: State s a -> (a -> State s b) -> State s b
   st >>= f = S (\s -> let (x,s') = runState st s 
                       in runState (f x) s')
