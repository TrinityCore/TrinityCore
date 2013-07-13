-- Fix quest Bloody Imp-ossible!

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=18884;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=18884;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18884;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18884,0,0,0,11,0,100,0,0,0,0,0,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warp Chaser - On Spawn - Cast Phasing Invisibility'),
(18884,0,1,0,0,0,100,0,500,2000,7000,15000,11,37417,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warp Chaser - In Combat - Cast Charge'),
(18884,0,2,0,0,0,100,0,3000,5000,10000,15000,11,32739,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warp Chaser - In Combat - Cast Venomous Bite');

DELETE FROM `creature_loot_template` WHERE `item` = 31813;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(18884, 31813, -100, 1, 0, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=31813;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(1, 18884, 31813, 0, 0, 29, 0, 22484, 10, 0, 0, 0, 0, '', 'Only drop "Warp Chaser Blood" if Zeppit is near creature');
