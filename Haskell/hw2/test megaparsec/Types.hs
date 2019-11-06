module Types where

type Identifier = (Int, String)


data Expr = IntConst Integer
          | StringConst String
          | Id Identifier
          | Add Expr Expr
          | Sub Expr Expr
          | Mult Expr Expr
          | Div Expr Expr
          | Call String [Expr]
          | Equal Expr Expr
          | Less Expr Expr
          | Greater Expr Expr
          | LessOrEqual Expr Expr
          | GreaterOrEqual Expr Expr

data Method = Method { identifier :: Identifier 
                     , parameters :: [Identifier]
                     , body :: [Statement]
                     }

data Statement = E Expr
               | While Expr [Statement]
               | If Expr [Statement] [Statement]
               | MethodDef Method
               | Assignment Identifier Expr

type Slepys = [Statement]