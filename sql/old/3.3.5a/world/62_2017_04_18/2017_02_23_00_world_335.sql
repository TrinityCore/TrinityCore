-- 
UPDATE `smart_scripts` SET `action_type`=45, `action_param1`=1, `action_param2`=1, `target_type`=11, `target_param1`=4969, `target_param2`=30, `comment`="Dashel Stonefist - On Script - Set data" WHERE `entryorguid`=496101 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid` IN (4961) AND `source_type`=0 AND `id`=2 AND `event_type`=2;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (4969);
DELETE FROM `smart_scripts` WHERE `entryorguid`=4969 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=496900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(4969, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Old Town Thug - Just summoned - Set invinciblity"),
(4969, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, "Old Town Thug - Just summoned - Start attack"),
(4969, 0, 2, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 496900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Old Town Thug - On data set - action list"),
(496900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Old Town Thug - action list - combat stop"),
(496900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Old Town Thug - action list - combat stop"),
(496900, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Old Town Thug - action list - despawn");
