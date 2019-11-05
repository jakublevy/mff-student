module Types where
import Text.Megaparsec
import Data.Void

data ROp = Eq
         | Lt
         | Le
         | Gt
         | Ge

data BExpr = Expr ROp Expr

data Expr = IntConst Integer
          | StringConst String
          | Identifier String
          | Add Expr Expr
          | Sub Expr Expr
          | Mult Expr Expr
          | Div Expr Expr
          | Assignment String Expr
          | Call String [Expr]

data Method = Method { identifier :: String 
                     , parameters :: [Expr]
                     , body :: [Statement]
                     }

data Statement = E Expr
               | While BExpr [Statement]
               | If BExpr [Statement] [Statement]
               | MethodDef Method

type Slepys = [Statement]

type Parser = Parsec Void String