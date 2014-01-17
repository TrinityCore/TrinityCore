DELETE FROM `creature_text` WHERE `entry` IN (2287, 2706, 2719, 10828, 16357, 17210);
UPDATE `smart_scripts` SET `action_param2`=1 WHERE `action_type`=39 AND `entryorguid` IN (2287, 2706, 2719, 10828, 16357, 17210, 3987);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2287, 2719) AND `action_param1`=1 AND `action_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2706, 10828, 16357, 17210, 3987) AND `action_param1`=0 AND `action_type`=1;
