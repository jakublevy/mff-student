/*
Vytvoření databáze a tabulek, včetně relací a ostatních constraints.
Obsahuje několik nezbytných funkcí, na kterých tabulky závisí.

*/

CREATE DATABASE [Levý_Fotbal]
COLLATE Czech_CS_AS
with 
	COMPATIBILITY_LEVEL = 140
  , TRUSTWORTHY ON 
GO

USE [Levý_Fotbal]
GO

CREATE TABLE dbo.Sezóna (
	Start DATE NOT NULL
  , Konec DATE NOT NULL
  , Start_Rok  AS (DATEPART(YEAR,Start))
  ,	Konec_Rok  AS (DATEPART(YEAR,Konec))
  ,	CONSTRAINT PK_Sezóna PRIMARY KEY CLUSTERED (Start ASC) 
  , CONSTRAINT UQ_Sezóna_Konec UNIQUE NONCLUSTERED (Konec ASC)
  , CONSTRAINT CK_Sezóna_Konec CHECK ((Start<Konec AND DATEDIFF(YEAR,Start,Konec)<=(1)))
)
GO


CREATE TABLE dbo.Tel (
	Id INT IDENTITY(1,1) NOT NULL
  , Předvolba NVARCHAR(4) NULL
  ,	Číslo NVARCHAR(9) NOT NULL
  , CONSTRAINT PK_Tel PRIMARY KEY CLUSTERED (Id ASC)
  , CONSTRAINT UQ_Tel_Číslo UNIQUE NONCLUSTERED (Číslo ASC)
  ,	CONSTRAINT CK_Tel_Číslo CHECK ((ISNUMERIC(Číslo)=(1) AND LEN(Číslo)=(9)))
  , CONSTRAINT CK_Tel_Předvolba CHECK ((Předvolba IS NULL OR LEFT(Předvolba,(1))='+' AND ISNUMERIC(SUBSTRING(Předvolba,(1),LEN(Předvolba)-(1)))=(1)))
)
GO

CREATE TABLE dbo.Kontakt (
   	Id INT IDENTITY(1,1) NOT NULL
  ,	Jméno NVARCHAR(30) NOT NULL
  ,	Příjmení NVARCHAR(30) NOT NULL
  ,	Email NVARCHAR(50) NULL
  ,	Tel_Id INT NULL
  , CONSTRAINT PK_Kontakt PRIMARY KEY CLUSTERED (Id ASC) 
  , CONSTRAINT CK_Kontakt_Email CHECK ((Email LIKE '%_@__%.__%'))
  , CONSTRAINT CK_Kontakt_Email_Tel_Id_Req CHECK ((Email IS NOT NULL OR Tel_Id IS NOT NULL))
  , CONSTRAINT CK_Kontakt_Jméno_Přijmení CHECK ((Jméno LIKE '[A-Ž][a-ž]%' AND Příjmení LIKE '[A-Ž]%'))
  , CONSTRAINT FK_Kontakt_Tel FOREIGN KEY(Tel_Id) REFERENCES dbo.Tel (Id)
) 
GO

CREATE TABLE dbo.Adresa (
	Id INT IDENTITY(1,1) NOT NULL
  ,	Ulice NVARCHAR(30) NOT NULL
  ,	Č_p NVARCHAR(10) NOT NULL
  ,	Město NVARCHAR(30) NOT NULL
  ,	Psč NVARCHAR(5) NOT NULL
  , CONSTRAINT PK_Adresa PRIMARY KEY CLUSTERED (Id ASC) 
  ,	CONSTRAINT CK_Adresa_Č_p CHECK ((ISNUMERIC(Č_p)=(1) OR Č_p LIKE '%_/_%'))
  ,	CONSTRAINT CK_Adresa_Město CHECK ((LEFT(Město,(1)) LIKE '[A-Ž]'))
  , CONSTRAINT CK_Adresa_Psč CHECK ((Psč LIKE '[1-9][0-9][0-9][0-9][0-9]'))
  , CONSTRAINT CK_Adresa_Ulice CHECK ((LEFT(Ulice,(1)) LIKE '[A-Ž]'))
) 
GO

CREATE TABLE dbo.Klub (
	Id INT IDENTITY(1,1) NOT NULL
  ,	Název NVARCHAR(50) NOT NULL
  ,	Adresa_Id INT NOT NULL
  ,	Pověřená_Osoba_Id INT NULL
  , CONSTRAINT PK_Klub PRIMARY KEY CLUSTERED (Id ASC)
  , CONSTRAINT UQ_Klub_Adresa_Id UNIQUE NONCLUSTERED (Adresa_Id ASC)
  , CONSTRAINT UQ_Klub_Název UNIQUE NONCLUSTERED (Název ASC) 
  , CONSTRAINT FK_Klub_Adresa FOREIGN KEY(Adresa_Id) REFERENCES dbo.Adresa (Id)
  , CONSTRAINT FK_Klub_Kontakt FOREIGN KEY(Pověřená_Osoba_Id) REFERENCES dbo.Kontakt (Id)
  , CONSTRAINT CK_Klub_Název CHECK ((Název LIKE '[a-žA-Ž]%'))
) 
GO

CREATE TABLE dbo.Rozhodčí (
	Id INT IDENTITY(1,1) NOT NULL
  ,	Kontakt_Id INT NOT NULL
  , CONSTRAINT PK_Rozhodčí PRIMARY KEY CLUSTERED (Id ASC) 
  , CONSTRAINT UQ_Rozhodčí UNIQUE NONCLUSTERED (Kontakt_Id ASC) 
  , CONSTRAINT FK_Rozhodčí_Kontakt FOREIGN KEY(Kontakt_Id) REFERENCES dbo.Kontakt (Id)
) 
GO

CREATE TABLE dbo.Soupiska (
	Id INT IDENTITY(1,1) NOT NULL
  ,	Zapsal_Id INT NULL
  ,	CONSTRAINT PK_Soupiska PRIMARY KEY CLUSTERED (Id ASC) 
  , CONSTRAINT FK_Soupiska_Kontakt FOREIGN KEY(Zapsal_Id) REFERENCES dbo.Kontakt (Id)
) 
GO

CREATE TABLE dbo.Ml_Kategorie (
	Název NVARCHAR(20) NOT NULL
  ,	Muži BIT NOT NULL
  ,	Délka_Zápasu_Minut INT NOT NULL
  , CONSTRAINT PK_Ml_Kategorie PRIMARY KEY CLUSTERED (Název ASC, Muži ASC) 
 , CONSTRAINT CK_Délka_Zápasu_Minut CHECK ((Délka_Zápasu_Minut=(90) OR Délka_Zápasu_Minut=(80) OR Délka_Zápasu_Minut=(70) OR Délka_Zápasu_Minut=(60) OR Délka_Zápasu_Minut=(40) OR Délka_Zápasu_Minut=(30))) 
) 
GO

CREATE TABLE dbo.Utkání (
	Id INT IDENTITY(1,1) NOT NULL
  ,	Góly_My INT NOT NULL
  ,	Góly_Soupeř INT NOT NULL
  ,	Góly_My_Poločas INT NULL
  ,	Góly_Soupeř_Poločas INT NULL
  ,	Soupeř_Id INT NOT NULL
  ,	Místo_Konání_Id INT NOT NULL
  ,	Ml_Kategorie_Název NVARCHAR(20) NOT NULL
  ,	Ml_Kategorie_Muži BIT NOT NULL
  ,	Sezóna_Start DATE NOT NULL
  ,	Rozhodčí_Id INT NOT NULL
  ,	Soupiska_Id INT NOT NULL
  , CONSTRAINT PK_Utkání PRIMARY KEY CLUSTERED (Id ASC) 
  , CONSTRAINT FK_Utkání_Adresa FOREIGN KEY(Místo_Konání_Id) REFERENCES dbo.Adresa (Id)
  , CONSTRAINT FK_Utkání_Klub FOREIGN KEY(Soupeř_Id) REFERENCES dbo.Klub (Id)
  , CONSTRAINT FK_Utkání_Ml_Kategorie FOREIGN KEY(Ml_Kategorie_Název, Ml_Kategorie_Muži) REFERENCES dbo.Ml_Kategorie (Název, Muži)
  , CONSTRAINT FK_Utkání_Rozhodčí FOREIGN KEY(Rozhodčí_Id) REFERENCES dbo.Rozhodčí (Id)
  , CONSTRAINT FK_Utkání_Sezóna FOREIGN KEY(Sezóna_Start) REFERENCES dbo.Sezóna (Start)
  , CONSTRAINT FK_Utkání_Soupiska FOREIGN KEY(Soupiska_Id) REFERENCES dbo.Soupiska (Id)
  ,	CONSTRAINT CK_Utkání_Omezení_Gólu CHECK ((Góly_My>=(0) AND Góly_My<=(99) AND Góly_My_Poločas>=(0) AND Góly_My_Poločas<=(99) AND Góly_Soupeř>=(0) AND Góly_Soupeř<=(99) AND Góly_Soupeř_Poločas>=(0) AND Góly_Soupeř_Poločas<=(99)))
  , CONSTRAINT CK_Utkání_Vztah_Góly_Góly_Poločas CHECK ((Góly_My>=Góly_My_Poločas AND Góly_Soupeř>=Góly_Soupeř_Poločas))
)
GO

--Vrátí 1 pokud existuje Klub s hodnotou Adresa_Id = @adresa_id
--Jinak 0
CREATE FUNCTION dbo.Je_Adresa_Adresou_Klubu(@adresa_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @klub_id INT;
	SELECT TOP 1 @klub_id = Id FROM dbo.Klub WHERE Adresa_Id = @adresa_id
	IF @klub_id IS NOT NULL 
		RETURN 1

	RETURN 0
END
GO

--Vrátí 1 pokud existuje Utkání s hodnotou Místo_Konání_Id = @adresa_id
--Jinak 0
CREATE FUNCTION dbo.Je_Adresa_Adresou_Utkání(@adresa_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @utkani_id INT
	SELECT TOP 1 @utkani_id = Id FROM dbo.Utkání WHERE Místo_Konání_Id = @adresa_id
	IF @utkani_id IS NOT NULL
		RETURN 1

	RETURN 0
END
GO

--Vrátí 1 pokud existuje klub sídlící na @adresa_id nebo existuje utkání, které se odehrálo na @adresa_id
--Jinak 0
CREATE FUNCTION dbo.Je_Adresa_Využita(@adresa_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	RETURN dbo.Je_Adresa_Adresou_Klubu(@adresa_id) | dbo.Je_Adresa_Adresou_Utkání(@adresa_id)
END
GO

ALTER TABLE Adresa
ADD Využita AS (dbo.Je_Adresa_Využita(Id))
GO


--Vrátí věk podle parametru @d_nar ~ Datum narození
CREATE FUNCTION dbo.Věk (@d_nar DATE)
RETURNS INT
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @retval INT
		SELECT @retval = FLOOR(DATEDIFF(DAY, @d_nar, GETDATE()) / 365.25)
	RETURN @retval
END
GO

CREATE TABLE dbo.Hráč(
	Reg_Id NVARCHAR(7) NOT NULL
  ,	D_Narození DATE NOT NULL
  ,	Muž BIT NOT NULL
  ,	Kontakt_Id INT NOT NULL
  , CONSTRAINT PK_Hráč PRIMARY KEY CLUSTERED (Reg_Id ASC) 
  , CONSTRAINT UQ_Hráč_Kontakt_Id UNIQUE NONCLUSTERED (Kontakt_Id ASC)
  , CONSTRAINT FK_Hráč_Kontakt FOREIGN KEY(Kontakt_Id) REFERENCES dbo.Kontakt (Id)
  ,	CONSTRAINT CK_Hráč_D_Narození CHECK ((dbo.Věk(D_Narození)>=(5) AND dbo.Věk(D_Narození)<=(99)))
  , CONSTRAINT CK_Hráč_Reg_Id CHECK ((ISNUMERIC(Reg_Id)=(1) AND LEN(Reg_Id)>=(6)))
)
GO


--Vrátí 1 pokud je Kontakt s Id = @kontakt_id hráčem
--Jinak 0
CREATE FUNCTION dbo.Je_Kontakt_Hráčem(@kontakt_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @reg_id NVARCHAR(7)
	SELECT TOP 1 @reg_id = Reg_Id FROM dbo.Hráč WHERE Kontakt_Id = @kontakt_id
	IF @reg_id IS NOT NULL
		RETURN 1

	RETURN 0
END
GO

--Vrátí 1 pokud existuje Kontakt s Id = @kontakt_id, který je pověřenou osobou (správcem) nějakého klubu
--Jinak 0
CREATE FUNCTION dbo.Je_Kontakt_Pověřenou_Osobou_Klubu(@kontakt_id INT)
RETURNS BIT 
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @klub_id INT

	SELECT TOP 1 @klub_id = Id FROM dbo.Klub WHERE Pověřená_Osoba_Id = @kontakt_id
	IF @klub_id IS NOT NULL
		RETURN 1

	RETURN 0
END
GO

--Vrátí 1 pokud je Kontakt s Id = @kontakt_id rozhodčím
--Jinak 0
CREATE FUNCTION dbo.Je_Kontakt_Rozhodčím(@kontakt_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @rozhodci_id INT

	SELECT TOP 1 @rozhodci_id = Id FROM dbo.Rozhodčí WHERE Kontakt_Id = @kontakt_id
	IF @rozhodci_id IS NOT NULL
		RETURN 1

	RETURN 0
END
GO

--Vrátí 1 pokud Kontakt s Id = @kontakt_id zapsal nějakou soupisku
--Jinak 0
CREATE FUNCTION dbo.Zapsal_Kontakt_Soupisku(@kontakt_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	DECLARE @soupiska_id INT
	SELECT TOP 1 @soupiska_id = Id FROM dbo.Soupiska WHERE Zapsal_Id = @kontakt_id
	IF @soupiska_id IS NOT NULL
		RETURN 1

	RETURN 0
END
GO

--Vrátí 1 pokud je Kontakt alespoň jedno z následujících: hráčem, pověřenou osobou (správcem) klubu, rozhodčím, zapisovatel soupisek
--Jinak 0
CREATE FUNCTION dbo.Je_Kontakt_Využit(@kontakt_id INT)
RETURNS BIT
WITH SCHEMABINDING
AS
BEGIN
	RETURN dbo.Je_Kontakt_Hráčem(@kontakt_id) | dbo.Je_Kontakt_Pověřenou_Osobou_Klubu(@kontakt_id) | dbo.Je_Kontakt_Rozhodčím(@kontakt_id) | dbo.Zapsal_Kontakt_Soupisku(@kontakt_id)
END
GO

ALTER TABLE Kontakt
ADD Využit AS dbo.Je_Kontakt_Využit(Id)
GO

CREATE TABLE dbo.Hostování (
	Kontrakt_Id NVARCHAR(15) NOT NULL
  ,	Od DATE NOT NULL
  ,	Do DATE NOT NULL
  ,	Cena_Za_Sezónu MONEY NOT NULL
  ,	Smlouva VARBINARY(MAX) NULL
  ,	Hráč_Reg_Id NVARCHAR(7) NOT NULL
  ,	Členství_Id INT NOT NULL
  , CONSTRAINT PK_Hostování PRIMARY KEY CLUSTERED (Kontrakt_Id ASC) 
  , CONSTRAINT FK_Hostování_Hráč FOREIGN KEY(Hráč_Reg_Id) REFERENCES dbo.Hráč (Reg_Id)
  , CONSTRAINT FK_Hostování_Klub FOREIGN KEY(Členství_Id) REFERENCES dbo.Klub (Id)
  , CONSTRAINT CK_Od_Do CHECK ((DATEDIFF(YEAR,Od,Do)<=(5) AND Od<Do))
) 
GO

CREATE TABLE dbo.Hráč_Soupiska (
	Hráč_Reg_Id NVARCHAR(7) NOT NULL
  ,	Soupiska_Id INT NOT NULL
  ,	Číslo INT NOT NULL
  ,	Náhradník BIT NOT NULL
  , CONSTRAINT PK_Hráč_Soupiska PRIMARY KEY CLUSTERED (Hráč_Reg_Id ASC, Soupiska_Id ASC) 
  , CONSTRAINT FK_Hráč_Soupiska_Hráč FOREIGN KEY(Hráč_Reg_Id) REFERENCES dbo.Hráč (Reg_Id)
  , CONSTRAINT FK_Hráč_Soupiska_Soupiska FOREIGN KEY(Soupiska_Id) REFERENCES dbo.Soupiska (Id) ON DELETE CASCADE
  , CONSTRAINT CK_Hráč_Soupiska CHECK ((Číslo>(0) AND Číslo<(100)))
)
GO

