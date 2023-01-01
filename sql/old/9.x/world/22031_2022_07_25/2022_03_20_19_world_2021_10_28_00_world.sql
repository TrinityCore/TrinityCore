--
UPDATE `creature_addon` SET `bytes1` = `bytes1` &~ 131072;
UPDATE `creature_template_addon` SET `bytes1` = `bytes1` &~ 131072;

UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '8279 30991' WHERE `entry` = 23090;
UPDATE `creature_addon` SET `auras` = '8279 30991' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 23090);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23090 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 23090;

-- Credit: vmangos
UPDATE `creature_template_addon` SET `auras` = '20540' WHERE `entry` = 12856;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 12856 AND `source_type` = 0 AND `id` = 3;

UPDATE `creature_template_addon` SET `auras` = '7939 22766 8601' WHERE `entry` = 7110;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 7110;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 7110 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7110,0,0,0,0,0,100,0,6000,9000,16000,19000,0,11,13578,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jadefire Shadowstalker - In Combat - Cast 'Jadefire'");

-- They may be not applied to all of them
DELETE FROM `smart_scripts` WHERE `entryorguid` = 938 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 938;
