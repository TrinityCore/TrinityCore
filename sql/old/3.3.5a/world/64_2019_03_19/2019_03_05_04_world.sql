-- 
UPDATE  `creature_template` SET `faction`=290 WHERE `entry` IN (30134);
UPDATE `smart_scripts` SET `event_type`=60 WHERE `entryorguid` IN (30134) AND `source_type`=0 AND `id` IN (13,14);
