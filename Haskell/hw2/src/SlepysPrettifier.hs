module SlepysPrettifier where

import SlepysParser
import State
import Data.List(intercalate)

type Indent = Int

indent :: Indent
indent = 3

indentIn :: State Indent Indent 
indentIn = state (\i -> (i+indent, i+indent))

indentOut :: State Indent Indent
indentOut = state (\i -> (i-indent, i-indent))

makeIndent :: Indent -> String
makeIndent n = replicate n ' '

indentedPrint :: Indent -> String -> String
indentedPrint i s = makeIndent i ++ s

surround :: String -> String
surround s = "\"" ++ s ++ "\""

prettify :: Slepys -> String
prettify slepys = lTrim $ evalState (prettifyStatements slepys) 0
    where 
        lTrim = dropWhile (== '\n')

prettifyIfWhile :: String -> Expr -> [Statement] -> State Indent String
prettifyIfWhile kw e stmts = do
                             ePretty <- prettifyExpr e
                             indentIn
                             sPretty <- prettifyStatements stmts
                             indentOut
                             kwInd <- gets indentedPrint <*> pure (kw ++ " ")
                             closeBracket <- gets indentedPrint <*> pure "}\n"
                             return $ kwInd ++ ePretty ++ ": {\n" ++ sPretty ++ closeBracket

prettifyStatement :: Statement -> State Indent String
prettifyStatement (Expr e) = do 
                             ePretty <- gets indentedPrint <*> prettifyExpr e
                             return $ ePretty ++ ";\n"

prettifyStatement (While e stmts) = prettifyIfWhile "while" e stmts
prettifyStatement (If e stmts []) = prettifyIfWhile "if" e stmts
                                     
prettifyStatement (If e stmts1 stmts2) = do
                                       if_ <- prettifyIfWhile "if" e stmts1
                                       indentIn
                                       elseSPretty <- prettifyStatements stmts2
                                       indentOut
                                       else_ <- gets indentedPrint <*> pure "else"
                                       closeBracket <- gets indentedPrint <*> pure "}\n"
                                       return $ if_ ++ else_ ++ ": {\n" ++ elseSPretty ++ closeBracket
                            
prettifyStatement (Assignment id e) = do
                                      idPretty <- gets indentedPrint <*> prettifyExpr (Id id)
                                      ePretty <- prettifyExpr e
                                      return $ idPretty ++ " = " ++ ePretty ++ ";\n"

prettifyStatement Skip = gets indentedPrint <*> pure "pass;\n"
prettifyStatement (MethodDef m) = do
                                  headerPretty <- prettifyMethodHeader (header m)
                                  indentIn
                                  bodyPretty <- prettifyStatements (body m)
                                  indentOut
                                  closeBracket <- gets indentedPrint <*> pure "}\n"
                                  return $ "\n" ++ headerPretty ++ "\n" ++ bodyPretty ++ closeBracket ++ "\n"

prettifyMethodHeader :: MethodHeader -> State Indent String
prettifyMethodHeader mh = do
                          def <- gets indentedPrint <*> pure "def "
                          return $ def ++ snd (identifier mh) ++ joinParameters (map snd $ parameters mh) ++ ": {"

prettifyStatements :: [Statement] -> State Indent String
prettifyStatements [] = pure []
prettifyStatements (s : stmts) = do
                                 sPretty <- prettifyStatement s
                                 rest <- prettifyStatements stmts
                                 return $ sPretty ++ rest

joinParameters :: [String] -> String
joinParameters xs = "(" ++ intercalate ", " xs ++ ")"

prettifyExpr :: Expr -> State Indent String
prettifyExpr (IntConst n) = pure (show n)
prettifyExpr (StringConst s) = pure (surround s)
prettifyExpr (Id (_, n)) = pure n

prettifyExpr (Call (i, n) ess) = do 
                                 essPretty <- prettifyCallsParams ess
                                 return $ n ++ essPretty
    where
        prettifyExprs :: [Expr] -> State Indent [String]
        prettifyExprs [] = pure []
        prettifyExprs (e : es) = do
                                 ePretty <- prettifyExpr e
                                 rest <- prettifyExprs es
                                 return $ ePretty : rest

        prettifyCallParams :: [Expr] -> State Indent String
        prettifyCallParams es = joinParameters <$> prettifyExprs es

        prettifyCallsParams :: [[Expr]] -> State Indent String
        prettifyCallsParams [] = pure []
        prettifyCallsParams (es : ess) = do
                                         esPretty <- prettifyCallParams es
                                         essPretty <- prettifyCallsParams ess
                                         return $ esPretty ++ essPretty
                                           

--binary cases
prettifyExpr e = case e of
                   Add e1 e2 -> prettifyBinExpr e1 "+" e2
                   Sub e1 e2 -> prettifyBinExpr e1 "-" e2
                   Mult e1 e2 -> prettifyBinExpr e1 "*" e2
                   Div e1 e2 -> prettifyBinExpr e1 "/" e2
                   Equal e1 e2 -> prettifyBinExpr e1 "==" e2
                   Less e1 e2 -> prettifyBinExpr e1 "<" e2
                   Greater e1 e2 -> prettifyBinExpr e1 ">" e2
                   LessOrEqual e1 e2 -> prettifyBinExpr e1 "<=" e2
                   GreaterOrEqual e1 e2 -> prettifyBinExpr e1 ">=" e2

prettifyBinExpr :: Expr -> String -> Expr -> State Indent String
prettifyBinExpr e1 op e2 = (\e1 e2 -> e1 ++ " " ++ op ++ " " ++ e2) <$> prettifyExpr e1 <*> prettifyExpr e2
