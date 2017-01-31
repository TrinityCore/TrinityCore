-- Spell conditions shouldn't have been added
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (41054,41055,45205,45206);
