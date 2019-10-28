USE Levý_Fotbal 
GO

CREATE NONCLUSTERED INDEX IX_Hostování_Členství_Id ON dbo.Hostování (Členství_Id ASC) INCLUDE(Hráč_Reg_Id,Od,Do,Cena_Za_Sezónu)
CREATE NONCLUSTERED INDEX IX_Hostování_Hráč_Reg_Id ON dbo.Hostování (Hráč_Reg_Id ASC) INCLUDE(Od,Do)


CREATE NONCLUSTERED INDEX IX_Hráč_Soupiska_Hráč_Reg_Id ON dbo.Hráč_Soupiska (Hráč_Reg_Id ASC) 
CREATE NONCLUSTERED INDEX IX_Hráč_Soupiska_Soupiska_Id ON dbo.Hráč_Soupiska (Soupiska_Id ASC) INCLUDE(Náhradník) 

CREATE NONCLUSTERED INDEX IX_Klub_Pověřená_Osoba_Id ON dbo.Klub (Pověřená_Osoba_Id ASC) 

CREATE UNIQUE NONCLUSTERED INDEX UQ_Kontakt_Email ON dbo.Kontakt (Email ASC) WHERE (Email IS NOT NULL)
CREATE UNIQUE NONCLUSTERED INDEX UQ_Kontakt_Tel ON dbo.Kontakt (Tel_Id ASC) WHERE (Tel_Id IS NOT NULL)

CREATE NONCLUSTERED INDEX IX_Sezóna_Konec_Rok ON dbo.Sezóna (Konec_Rok ASC)
CREATE NONCLUSTERED INDEX IX_Sezóna_Start_Rok ON dbo.Sezóna (Start_Rok ASC)

CREATE NONCLUSTERED INDEX IX_Soupiska_Zapsal_Id ON dbo.Soupiska (Zapsal_Id ASC)

CREATE NONCLUSTERED INDEX IX_Utkání_Místo_Konání_Id ON dbo.Utkání (Místo_Konání_Id ASC) 
CREATE NONCLUSTERED INDEX IX_Utkání_Ml_Kategorie ON dbo.Utkání (Ml_Kategorie_Název ASC) INCLUDE(Ml_Kategorie_Muži)
CREATE NONCLUSTERED INDEX IX_Utkání_Rozhodčí_Id ON dbo.Utkání (Rozhodčí_Id ASC)
CREATE NONCLUSTERED INDEX IX_Utkání_Sezóna_Start ON dbo.Utkání (Sezóna_Start ASC)
CREATE NONCLUSTERED INDEX IX_Utkání_Soupeř_Id ON dbo.Utkání (Soupeř_Id ASC) INCLUDE(Góly_My,Góly_Soupeř,Góly_My_Poločas,Góly_Soupeř_Poločas,Místo_Konání_Id,Sezóna_Start,Rozhodčí_Id,Soupiska_Id,Ml_Kategorie_Název,Ml_Kategorie_Muži) 
CREATE NONCLUSTERED INDEX IX_Utkání_Soupiska_Id ON dbo.Utkání (Soupiska_Id ASC)