module SlepysParser(parseTokens
                  , Slepys
                  ) where

import TokenParser

type Id = (LineNum, String)

data Expr = IntConst Integer
          | StringConst String
          | Id Id
          | Add Expr Expr
          | Sub Expr Expr
          | Mult Expr Expr
          | Div Expr Expr
          | Call Id [Expr]
          | Equal Expr Expr
          | Less Expr Expr
          | Greater Expr Expr
          | LessOrEqual Expr Expr
          | GreaterOrEqual Expr Expr
    deriving (Show) --todo: remove

data Method = Method { header :: MethodHeader
                     , body :: [Statement]
                     }

data MethodHeader = MethodHeader { identifier :: Id 
                                 , parameters :: [Id]
                                 }

data Statement = Expr Expr
               | While Expr [Statement]
               | If Expr [Statement] [Statement]
               | MethodDef Method
               | Assignment Id Expr
               | Skip

type Slepys = [Statement]

formalParameters :: TokenParser [Id]
formalParameters = do
                   (i, Identifier n) <- token
                   rest <- many $ do
                                  Comma <- lexem
                                  (j, Identifier m) <- token
                                  return (j, m)

                   return $ (i, n) : rest 
               <|> pure []

methodHeader :: TokenParser MethodHeader
methodHeader = do
               Def <- lexem
               (i, Identifier mName) <- token
               LPar <- lexem
               params <- formalParameters
               RPar <- lexem
               Colon <- lexem
               return $ MethodHeader (i,mName) params

blockBody :: TokenParser [Statement]
blockBody = do
            IndentIn <- lexem
            stms <- some statement <|> pass
            IndentOut <- lexem
            return stms

pass :: TokenParser [Statement]
pass = do
       Pass <- lexem
       return [Skip]

method :: TokenParser Statement
method = do
         h <- methodHeader
         b <- blockBody
         let m = Method { 
             header = h
           , body = b
         }
         return $ MethodDef m

    
   
factor :: TokenParser Expr
factor =     do
            Val n <- lexem
            return $ IntConst n
         <|> do
            Str s <- lexem
            return $ StringConst s
         <|> do
            (i, Identifier id) <- token
            LPar <- lexem
            args <- arguments 
            RPar <- lexem
            return $ Call (i, id) args
         <|> do
            (i, Identifier id) <- token
            return $ Id (i, id)
         <|> do
            LPar <- lexem
            e <- expr
            RPar <- lexem
            return e

arguments :: TokenParser [Expr]
arguments =  do
             e <- expr
             es <- many $ do
                          Comma <- lexem
                          expr
             return $ e : es
         <|> pure []

createExpr :: Expr -> (Lexem, Expr) -> Expr
createExpr e1 (Gt, e2) = Greater e1 e2
createExpr e1 (Lt, e2) = Less e1 e2
createExpr e1 (Ge, e2) = GreaterOrEqual e1 e2
createExpr e1 (Le, e2) = LessOrEqual e1 e2
createExpr e1 (Plus, e2) = Add e1 e2
createExpr e1 (Minus, e2) = Sub e1 e2
createExpr e1 (Asterisks, e2) = Mult e1 e2
createExpr e1 (Slash, e2) = Div e1 e2

functor :: TokenParser Expr
functor = do
          f <- factor
          funcOps <- many $ do
                            op <- relOp
                            e <- factor
                            return (op, e)
          return $ foldl createExpr f funcOps

term :: TokenParser Expr
term = do
       f <- functor
       funcOps <- many $ do
                         op <- binOp2
                         e <- functor
                         return (op, e)
       return $ foldl createExpr f funcOps

expr :: TokenParser Expr
expr = do
       t <- term
       termOps <- many $ do
                         op <- binOp3
                         t <- term
                         return (op, t)
       return $ foldl createExpr t termOps
        
statementLexem :: TokenParser Lexem
statementLexem = g <$> lexem
    where 
        g :: Lexem -> Lexem
        g l |   l == TokenParser.While
             || l == TokenParser.If    = l

isBooleanExpr :: Expr -> Bool
isBooleanExpr (Equal _ _) = True
isBooleanExpr (Less _ _) = True
isBooleanExpr (Greater _ _) = True
isBooleanExpr (LessOrEqual _ _) = True
isBooleanExpr (GreaterOrEqual _ _) = True
isBooleanExpr _ = False

booleanExpr :: TokenParser Expr
booleanExpr = do
              e <- expr
              if isBooleanExpr e then
                 return e
              else empty 


statement :: TokenParser Statement
statement =     do
                kw <- statementLexem
                be <- booleanExpr
                Colon <- lexem
                b <- blockBody
                if kw == TokenParser.If then
                    do
                        Else <- lexem
                        Colon <- lexem
                        SlepysParser.If be b <$> blockBody
                    <|>
                    do
                        return $ SlepysParser.If be b []
                else 
                        return $ SlepysParser.While be b
            <|> assignment
            <|> method
                

relOp :: TokenParser Lexem
relOp = g <$> lexem
    where
        g l |   l == Gt
             || l == Lt
             || l == Ge
             || l == Le = l

binOp2 :: TokenParser Lexem
binOp2 = g <$> lexem
    where
        g l |   l == Plus
             || l == Minus = l

binOp3 :: TokenParser Lexem
binOp3 = g <$> lexem
    where
        g l |   l == Asterisks
             || l == Slash     = l

assignment :: TokenParser Statement
assignment = do
             (i, Identifier n) <- token
             Assign <- lexem
             Assignment (i, n) <$> expr

slepys :: TokenParser [Statement]
slepys = many statement

parseTokens :: [Token] -> Either String [Statement]
parseTokens tok = case parse slepys tok of
                    [(stms, [])] -> Right stms
                    [] -> Left "Undefined parsing error occurred"
                    [(_, (erLine, erLex) : xs)] -> Left $ "Error on line " ++ show erLine ++ " near " ++ show erLex