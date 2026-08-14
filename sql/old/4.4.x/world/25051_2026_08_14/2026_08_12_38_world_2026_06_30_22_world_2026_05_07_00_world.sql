--
SET @SPAWN_GROUP_ID := 357; -- 3

-- Hellfire Sentry
DELETE FROM `creature_text` WHERE `CreatureID` = 17517;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17517,0,0,"We are the true Horde!",12,0,100,0,0,0,16697,0,"Hellfire Sentry"),
(17517,0,1,"For Kargath!  For Victory!",12,0,100,0,0,0,16698,0,"Hellfire Sentry"),
(17517,0,2,"Gakarah ma!",12,0,100,0,0,0,16699,0,"Hellfire Sentry"),
(17517,0,3,"The blood is our power! ",12,0,100,0,0,0,16700,0,"Hellfire Sentry"),
(17517,0,4,"Lok'tar Illadari!\n",12,0,100,0,0,0,16701,0,"Hellfire Sentry"),
(17517,0,5,"This world is OURS!",12,0,100,0,0,0,16702,0,"Hellfire Sentry"),
(17517,0,6,"Lok narash!",12,0,100,0,0,0,16703,0,"Hellfire Sentry");

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 17517;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17517 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17517,0,0,0,4,0,15,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Hellfire Sentry - On Aggro - Say Line 0"),
(17517,0,1,0,0,0,100,0,5000,10000,20000,30000,0,11,30621,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hellfire Sentry - In Combat - Cast 'Kidney Shot'");

-- Vazruden the Herald
UPDATE `creature_template` SET `speed_walk` = 4, `speed_run` = 2.57143 WHERE `entry` = 18435;

UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` = 17307;

-- Nazan
UPDATE `creature_template` SET `speed_walk` = 4, `speed_run` = 2.57143, `ScriptName` = '' WHERE `entry` IN (17536,18432);

-- Vazruden
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857, `BaseAttackTime` = 2400 WHERE `entry` = 18434;

-- Misc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 30693;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30693,0,0,31,0,3,17536,0,0,0,0,"","Group 0: Spell 'Call Nazan' (Effect 0) targets creature 'Nazan'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_vazruden_call_nazan',
'spell_vazruden_cone_of_fire',
'spell_vazruden_fireball',
'spell_vazruden_summon_vazruden');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30693, 'spell_vazruden_call_nazan'),
(30926, 'spell_vazruden_cone_of_fire'),
(36921, 'spell_vazruden_cone_of_fire'),
(30691, 'spell_vazruden_fireball'),
(32491, 'spell_vazruden_fireball'),
(33793, 'spell_vazruden_fireball'),
(33794, 'spell_vazruden_fireball'),
(34653, 'spell_vazruden_fireball'),
(36920, 'spell_vazruden_fireball'),
(30717, 'spell_vazruden_summon_vazruden');

UPDATE `gameobject_template_addon` SET `faction` = 14 WHERE `entry` = 182533;

UPDATE `gameobject_template` SET `ScriptName` = 'go_vazruden_liquid_fire' WHERE `entry` IN (180125,181890,182533);

-- Spawn groups
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID WHERE `spawnId` = 202693 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID WHERE `spawnId` = 202705 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID WHERE `spawnId` = 202706 AND `spawnType` = 0;

DELETE FROM `spawn_group_template` WHERE `groupId` = 51;
DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Hellfire Ramparts - Vazruden the Herald",0);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 543 AND `bossStateId` = 3;
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 543 AND `bossStateId` = 2 AND `spawnGroupId` = 51;
DELETE FROM `instance_spawn_groups` WHERE `instanceMapId` = 543 AND `bossStateId` = 2 AND `spawnGroupId` = @SPAWN_GROUP_ID;

INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(543,2,23,@SPAWN_GROUP_ID+0,1);
