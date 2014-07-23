--
UPDATE `smart_scripts` SET `event_param4`=10000 WHERE  `entryorguid` IN (7380,7381,7382,7383,7384,7385,22816) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param3`=4500 WHERE  `entryorguid`=32255 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `conditions`WHERE `SourceEntry` = '62004';
