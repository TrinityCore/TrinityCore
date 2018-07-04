--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=20;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceEntry` IN (50685, 50686, 50687);
