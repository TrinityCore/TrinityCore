-- Fix quest Bloody Imp-ossible!

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=18884;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=18884;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18884;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18884,0,0,0,11,0,100,0,0,0,0,0,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warp Chaser - On Spawn - Cast Phasing Invisibility'),
(18884,0,1,0,0,0,100,0,500,2000,7000,15000,11,37417,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warp Chaser - In Combat - Cast Charge'),
(18884,0,2,0,0,0,100,0,3000,5000,10000,15000,11,32739,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warp Chaser - In Combat - Cast Venomous Bite'),
(18884,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,22484,10,0,0,0,0,0, 'Warp Chaser - On Death - Set Data on Zeppit');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=22484;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=22484;
DELETE FROM `smart_scripts` WHERE `entryorguid`=22484;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22484,0,0,0,38,0,100,0,1,1,0,0,11,39244,0,0,0,0,0,21,10,0,0,0,0,0,0, 'Zeppit - On Data Set - Cast on Master');

-- DELETE FROM `creature_loot_template` WHERE `item` = 31813;
-- DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=31813;
