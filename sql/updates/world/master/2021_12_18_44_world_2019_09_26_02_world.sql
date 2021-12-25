--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (68,1756,1976,3296,14304) AND `source_type`=0 AND `id` = 0;
DELETE FROM `conditions` WHERE `SourceEntry` IN (68,1756,1976,3296,14304) AND `SourceTypeOrReferenceId` = 22;
