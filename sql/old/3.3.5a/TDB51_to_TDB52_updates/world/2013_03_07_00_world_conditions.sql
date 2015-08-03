-- Delete condition that is already covered by spell attribute
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=58846;
