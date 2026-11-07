--
SET @SPAWN_GROUP_ID := 399; -- 3

UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+0 WHERE `spawnId` = 93765 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+1 WHERE `spawnId` = 82975 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+2 WHERE `spawnId` = 82976 AND `spawnType` = 0;

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+2;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Serpentshrine Cavern - Fathom-Guard Caribdis",4), -- 399
(@SPAWN_GROUP_ID+1,"Serpentshrine Cavern - Fathom-Guard Tidalvess",4), -- 400
(@SPAWN_GROUP_ID+2,"Serpentshrine Cavern - Fathom-Guard Sharkkis",4); -- 401

UPDATE `creature_template` SET `speed_run` = 2.14285714286, `BaseAttackTime` = 500, `AIName` = 'SmartAI' WHERE `entry` = 21508;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 21508 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21508,0,0,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Coilfang Frenzy - On Spawn - Start Attack"),
(21508,0,1,0,60,0,100,1,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coilfang Frenzy - On Update - Despawn (No Repeat)");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_serpent_shrine_coilfang_water',
'spell_serpent_shrine_frenzy_water');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37025, 'spell_serpent_shrine_coilfang_water'),
(37280, 'spell_serpent_shrine_frenzy_water');
