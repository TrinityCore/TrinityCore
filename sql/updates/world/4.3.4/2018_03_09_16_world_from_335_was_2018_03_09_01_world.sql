-- 
DELETE FROM `conditions` WHERE SourceEntry IN (44608) AND `SourceTypeOrReferenceId`=13;
UPDATE `conditions` SET `SourceGroup`=1  WHERE `SourceEntry` IN (44213,43986) AND `SourceTypeOrReferenceId`=13;
