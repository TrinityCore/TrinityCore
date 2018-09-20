-- 
UPDATE `smart_scripts` SET `target_type`=7 WHERE  `event_type` IN (4) AND `target_type`=2;
UPDATE `smart_scripts` SET `target_type`=16 WHERE  `event_type` IN (4) AND `target_type`=5;
UPDATE `smart_scripts` SET `event_type`=0 WHERE `entryorguid`=18701 AND `source_type`=0 AND `id`=1;
