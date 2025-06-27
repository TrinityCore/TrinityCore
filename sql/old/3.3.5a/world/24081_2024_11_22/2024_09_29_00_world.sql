-- Deletes Ratchet as Ally GY when dying in Thunder Bluff
DELETE FROM `graveyard_zone` WHERE `ID`= 249 AND `GhostZone`= 1638;
-- Adds Bloodhoof Village as Ally GY when dying in Thunder Bluff
DELETE FROM `graveyard_zone` WHERE `ID`= 89 AND `GhostZone`= 1638;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(89, 1638, 469, 'Mulgore, Bloodhoof Village GY - Mulgore');
