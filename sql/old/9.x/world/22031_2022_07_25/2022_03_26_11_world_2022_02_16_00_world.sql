--
UPDATE `smart_scripts` SET `action_param2` = 0 WHERE `entryorguid` = 39368 AND `source_type` = 0 AND `action_type` = 11;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 39368 AND `SourceId` = 0;
