--
DELETE FROM `graveyard_zone` WHERE `ID`=512 AND `GhostZone`=148 AND `Faction`=67;
UPDATE `graveyard_zone` SET `Faction`=0 WHERE `ID` IN (35,469) AND `GhostZone`=148;
