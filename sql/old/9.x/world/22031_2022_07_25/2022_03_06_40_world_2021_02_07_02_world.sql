-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23434 AND `event_type` = 19;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18141 AND `source_type` = 0 AND `id` BETWEEN 3 AND 5;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 18141 AND `SourceId` = 0;
