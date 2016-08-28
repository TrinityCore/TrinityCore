-- 
UPDATE `creature_template` SET `speed_run`=0.42857 WHERE `entry` IN (16027);
UPDATE `smart_scripts` SET `action_param1`=22 WHERE  `entryorguid`=16027 AND `source_type`=0 AND `id`=3 AND `link`=4;
