-- 
UPDATE `smart_scripts` SET `event_type`=0, `event_flags`=1, `event_param1`=10000,`event_param2`=10000, `action_param2`=0 WHERE `entryorguid`= 26919 AND `source_type`= 0 AND `id`= 4;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (4950) AND `source_type`=2;
