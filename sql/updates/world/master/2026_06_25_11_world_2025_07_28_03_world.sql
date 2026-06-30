--
DELETE FROM `graveyard_zone` WHERE `ID`=512 AND `GhostZone`=148;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=27 AND `SourceGroup`=148 AND `SourceEntry` IN (35,469,512);
