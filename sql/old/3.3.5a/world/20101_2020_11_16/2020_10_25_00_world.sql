-- Migrate orientation changes
UPDATE `waypoint_data` SET `orientation` = 3.33358, `action` = 0 WHERE `id` = 831970 AND `point` = 3;
UPDATE `waypoint_data` SET `orientation` = 3.03687, `action` = 0 WHERE `id` = 831970 AND `point` = 6;
UPDATE `waypoint_data` SET `orientation` = 2.96706, `action` = 0 WHERE `id` = 831950 AND `point` = 3;
UPDATE `waypoint_data` SET `orientation` = 3.26377, `action` = 0 WHERE `id` = 831950 AND `point` = 5;
DELETE FROM `waypoint_scripts` WHERE `id` IN (8319701,8319702,8319501,8319502);

-- Tempest-Forge Patroller SAI (The one with texts)
SET @ID := -83177;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,300000,600000,300000,600000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Forge Patroller - Out of Combat - Say Line 0"),
(@ID,0,1,0,0,0,100,2,6100,10400,6800,16900,11,35012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast 'Charged Arcane Missile' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,6100,10400,6800,16900,11,38941,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast 'Charged Arcane Missile' (Heroic Dungeon)"),
(@ID,0,3,0,0,0,100,0,9700,16400,12500,20500,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast 'Knockdown'"),
(@ID,0,4,0,2,0,100,1,0,50,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Forge Patroller - Between 0-50% Health - Call for Help (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = 19166;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19166,0,0,"Any intruders must be eliminated!",14,0,100,0,0,0,16785,0,"Tempest-Forge Patroller"),
(19166,0,1,"Protect the Mechanar at all costs!",14,0,100,0,0,0,17913,0,"Tempest-Forge Patroller");

-- Update gameobjects
UPDATE `gameobject_template_addon` SET `faction` = 1375, `flags` = 32 WHERE `entry` = 184449;
UPDATE `gameobject_template_addon` SET `faction` = 1375, `flags` = 32 WHERE `entry` = 184632;
UPDATE `gameobject_template_addon` SET `faction` = 94 WHERE `entry` = 185015;

DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (184465,185015));
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 34902;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 150052;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 150053;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 6033;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 6034;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 6032;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 242;
UPDATE `gameobject_addon` SET `parent_rotation2` = 1, `parent_rotation3` = -0 WHERE `guid` = 236;

UPDATE `gameobject` SET `position_x` = 0, `position_y` = 0, `position_z` = 0, `orientation` = 3.14159, `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 34902 AND `id` = 183788;
UPDATE `gameobject` SET `position_x` = 145.198, `position_y` = -44.5185, `position_z` = 1.00919, `orientation` = 2.74016, `rotation2` = 0.979924, `rotation3` = 0.19937, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 20463 AND `id` = 185015;
UPDATE `gameobject` SET `position_x` = 155.423, `position_y` = -29.7322, `position_z` = 1.00882, `orientation` = 2.00713, `rotation2` = 0.843391, `rotation3` = 0.5373, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 20473 AND `id` = 185015;
UPDATE `gameobject` SET `position_x` = 163.7, `position_y` = -27.3792, `position_z` = 1.00893, `orientation` = 4.72984, `rotation2` = -0.700909, `rotation3` = 0.713251, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 20467 AND `id` = 185015;
UPDATE `gameobject` SET `position_x` = 148.266, `position_y` = -35.25, `position_z` = 1.00923, `orientation` = 2.47837, `rotation2` = 0.945518, `rotation3` = 0.325568, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 20464 AND `id` = 185015;
UPDATE `gameobject` SET `spawnMask` = 3, `position_x` = -38.0125, `position_y` = 0.10273, `position_z` = 0.504373, `orientation` = 3.14159, `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 150052 AND `id` = 184227;
UPDATE `gameobject` SET `spawnMask` = 3, `position_x` = -38.0125, `position_y` = 0.10273, `position_z` = 0.504373, `orientation` = 3.14159, `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 150053 AND `id` = 184228;
UPDATE `gameobject` SET `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 6033 AND `id` = 184322;
UPDATE `gameobject` SET `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 6034 AND `id` = 184449;
UPDATE `gameobject` SET `position_x` = 222.543, `position_y` = 70.6106, `position_z` = -0.00479339, `orientation` = 4.67748, `rotation2` = -0.719339, `rotation3` = 0.694659, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 44743 AND `id` = 184465;
UPDATE `gameobject` SET `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 6032 AND `id` = 184632;
UPDATE `gameobject` SET `spawnMask` = 3, `id` = 184225, `position_x` = 73.9475, `position_y` = 149.684, `position_z` = 27.7701, `orientation` = 3.14159, `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 242 AND `id` = 184221;
UPDATE `gameobject` SET `spawnMask` = 3, `id` = 184226, `position_x` = 73.9475, `position_y` = 149.684, `position_z` = 27.7701, `orientation` = 3.14159, `rotation2` = -1, `rotation3` = 0, `animprogress` = 255, `VerifiedBuild` = 14545 WHERE `guid` = 236 AND `id` = 184222;

-- Missing Cache of the Legion for heroic mode
DELETE FROM `gameobject` WHERE `guid` = 10001 AND `id` = 184849;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(10001,184849,554,0,0,2,1,222.543,70.6106,-0.00479339,4.67748,0,0,-0.719339,0.694659,86400,255,1,"",0);

-- Parts of key are not linked to any quest
UPDATE `creature_loot_template` SET `QuestRequired` = 0 WHERE `Item` IN (30436,30437) AND `Reference` = 0;
