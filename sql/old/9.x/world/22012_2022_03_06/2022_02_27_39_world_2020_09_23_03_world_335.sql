-- 447 Morganus
SET @ID := 447;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Morganus', 0),
(@ID, 'esMX','Morganus', 0);
-- 448 Recuerdos de la Fiesta de la Cerveza
SET @ID := 448;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Recuerdos de la Fiesta de la Cerveza', 0),
(@ID, 'esMX','Recuerdos de la Fiesta de la Cerveza', 0);
-- 449 Carrera de Carneros de la Fiesta de la Cerveza
SET @ID := 449;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Carrera de Carneros de la Fiesta de la Cerveza', 0),
(@ID, 'esMX','Carrera de Carneros de la Fiesta de la Cerveza', 0);
-- 450 Club de la Cerveza del Mes, Forjaz
SET @ID := 450;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Club de la Cerveza del Mes, Forjaz', 0),
(@ID, 'esMX','Club de la Cerveza del Mes, Forjaz', 0);
-- 451 Recuerdos de la Fiesta de la Cerveza Goblin
SET @ID := 451;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Recuerdos de la Fiesta de la Cerveza Goblin', 0),
(@ID, 'esMX','Recuerdos de la Fiesta de la Cerveza Goblin', 0);
-- 452 Carrera de Carneros de la Fiesta de la Cerveza Goblin
SET @ID := 452;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Carrera de Carneros de la Fiesta de la Cerveza Goblin', 0),
(@ID, 'esMX','Carrera de Carneros de la Fiesta de la Cerveza Goblin', 0);
-- 453 Club de la Cerveza del Mes, Orgrimmar
SET @ID := 453;
DELETE FROM `points_of_interest_locale` WHERE `ID` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`) VALUES
(@ID, 'esES','Club de la Cerveza del Mes, Orgrimmar', 0),
(@ID, 'esMX','Club de la Cerveza del Mes, Orgrimmar', 0);
