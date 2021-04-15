-- Fix startup errors:
-- Set correct questid for Many Wyrm 
UPDATE `smart_scripts` SET `action_param1`=8346 WHERE `entryorguid` IN (15273,15274,15294,15298) AND `source_type`=0 AND `id` IN (0,1);
