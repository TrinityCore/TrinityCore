-- 
UPDATE `smart_scripts` SET `action_type`=134 WHERE  `action_type` IN (85) AND `target_type` =1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid` IN (27202) AND `source_type`=0 AND `id` IN (4,10);
UPDATE `smart_scripts` SET `action_param2`=2 WHERE  `entryorguid` IN (27202) AND `source_type`=0 AND `id` IN (7);
