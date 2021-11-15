--
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 31030;
UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (-106860,-106859,-106858,-106857,-106856,-106855,31029,-85829,-85828,2713,4484,12277,17238,25652,31050) AND `source_type` = 0 AND `action_type` = 53;

UPDATE `smart_scripts` SET `action_param6` = 3 WHERE `entryorguid` IN (450001,1789300,2821700,3127900,3280000) AND `source_type` = 9 AND `action_type` = 53;
