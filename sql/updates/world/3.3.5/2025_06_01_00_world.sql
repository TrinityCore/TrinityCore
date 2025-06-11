-- 
DELETE FROM `graveyard_zone` WHERE `ID`=469 AND `GhostZone` IN (141,1657);
UPDATE `graveyard_zone` SET `Faction`=0 WHERE `ID`=91 AND `GhostZone`=141;

DELETE FROM `graveyard_zone` WHERE `ID`=91 AND `GhostZone`=1657;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(91, 1657, 67, 'Teldrassil, Dolanaar GY - Teldrassil');
