--
-- link Graveyard 918 to zone 6456 (Ammen Vale - unlinked zone)
DELETE FROM `graveyard_zone` WHERE `ID`= 918 AND `GhostZone`= 6456;
INSERT INTO `graveyard_zone` (`ID`,`GhostZone`,`Faction`,`Comment`) VALUES
(918, 6456, 469, 'Azuremyst Isle, Crash Site GY - Ammen Vale');
--
