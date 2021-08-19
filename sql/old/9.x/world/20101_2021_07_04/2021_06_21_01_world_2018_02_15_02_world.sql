-- 
UPDATE `smart_scripts` SET `target_type`=1 WHERE `action_type`=39;
UPDATE `smart_scripts` SET `target_type`=2 WHERE `target_type`=7 AND `event_type`=2 AND `event_flags`=1 AND `event_param2`=30 AND `action_type`=1;
UPDATE `smart_scripts` SET `target_type`=24 WHERE `target_type`=7 AND `event_type`=2  AND `action_type` IN (33,85);
