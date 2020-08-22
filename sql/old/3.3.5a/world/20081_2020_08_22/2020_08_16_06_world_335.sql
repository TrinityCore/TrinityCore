--
UPDATE `areatrigger_teleport` SET `VerifiedBuild` = 15882 WHERE `ID` IN (4917,4919,4921,4922,4923,4924,4925,4927,4928,4929,4930,4931,4932,4933,4934,4935,4936,4941,4944,5127,5128,5129,5130,5131,5132,5133,5134,5135,5136,5137,5138,5148,5326,5328,5329,5330,5331,5740,4304,4233,4267,2406,2407,2408,2409,2410,2411);

UPDATE `areatrigger_teleport` SET /*Scholomance Instance*/ `target_position_x`=1273.91, `target_position_y`=-2553.09, `target_position_z`=91.8393, `target_orientation`=3.57792, `VerifiedBuild`=15882 WHERE `ID`=2568; -- WSL 4012
UPDATE `areatrigger_teleport` SET /*Pit of Saron (Exit)*/ `target_position_x`=5595.78, `target_position_y`=2013.27, `target_position_z`=798.041, `target_orientation`=0.78539, `VerifiedBuild`=15882 WHERE `ID`=5683; -- WSL 3924
UPDATE `areatrigger_teleport` SET /*Forge of Souls (Exit)*/ `target_position_x`=5667.65, `target_position_y`=2007.45, `target_position_z`=798.041, `target_orientation`=2.35619, `VerifiedBuild`=15882 WHERE `ID`=5688; -- WSL 3923

-- There's 3 areatriggers, not only one
UPDATE `areatrigger_teleport` SET `Name` = "Thousand Needles - Test of Faith (Target)" WHERE `ID` = 943;
DELETE FROM `areatrigger_teleport` WHERE `ID` IN (942,944);
INSERT INTO `areatrigger_teleport` (`ID`,`Name`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`,`VerifiedBuild`) VALUES
(942,"Thousand Needles - Test of Faith (Target)",1,-5191.27,-2802.59,-7.21111,5.67232,15882),
(944,"Thousand Needles - Test of Faith (Target)",1,-5191.27,-2802.59,-7.21111,5.67232,15882);
