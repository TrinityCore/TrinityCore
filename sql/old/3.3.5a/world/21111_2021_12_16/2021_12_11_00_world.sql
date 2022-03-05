--
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Reincarnated Skytalon - On Script - Cast 'Circle of Life: Transform into Rabbit'" WHERE `entryorguid` = 2779800 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Reincarnated Skytalon - On Script - Cast 'Circle of Life: Transform into Squirrel'" WHERE `entryorguid` = 2779801 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Reincarnated Skytalon - On Script - Cast 'Circle of Life: Transform into Skunk'" WHERE `entryorguid` = 2779802 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Reincarnated Skytalon - On Script - Cast 'Circle of Life: Transform into Prairie Dog'" WHERE `entryorguid` = 2779803 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Reincarnated Skytalon - On Script - Cast 'Circle of Life: Transform into Fawn'" WHERE `entryorguid` = 2779804 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Reincarnated Skytalon - On Script - Cast 'Circle of Life: Transform into Emerald Skytalon'" WHERE `entryorguid` = 2779805 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Wyrmrest Protector - On Script - Cast 'Wyrmrest Temple - Protector Transform (Nether)'" WHERE `entryorguid` = 2795300 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Wyrmrest Protector - On Script - Cast 'Wyrmrest Temple - Protector Transform (Bronze)'" WHERE `entryorguid` = 2795301 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Wyrmrest Protector - On Script - Cast 'Wyrmrest Temple - Protector Transform (Black)'" WHERE `entryorguid` = 2795302 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Wyrmrest Protector - On Script - Cast 'Wyrmrest Temple - Protector Transform (Green)'" WHERE `entryorguid` = 2795303 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Wyrmrest Protector - On Script - Cast 'Wyrmrest Temple - Protector Transform (Red)'" WHERE `entryorguid` = 2795304 AND `source_type` = 9 AND `id` = 0;
UPDATE `smart_scripts` SET `action_type` = 11, `comment` = "Wyrmrest Protector - On Script - Cast 'Wyrmrest Temple - Protector Transform (Blue)'" WHERE `entryorguid` = 2795305 AND `source_type` = 9 AND `id` = 0;

-- Blood Elf Bandit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17591 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_template_addon` WHERE `entry` = 17591;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(17591, 0, 0, 0, 0, 1, 0, 0, '5916');

-- Arcane Guardian
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18103 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '18950' WHERE `entry` = 18103;

-- Bloodmaul Dire Wolf
UPDATE `creature_template_addon` SET `auras` = '18950' WHERE `entry` = 20058;
UPDATE `creature_addon` SET `auras` = '18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 20058);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 20058 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20058,0,0,0,0,0,100,0,5000,10000,15000,20000,0,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodmaul Dire Wolf - In Combat - Cast 'Rend'");

-- Darnassian Scout
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 15968;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15968 AND `source_type` = 0;

-- Mortar Team Target Dummy
UPDATE `creature_template` SET `minlevel` = 14, `maxlevel` = 14, `AIName` = '' WHERE `entry` = 11875;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11875 AND `source_type` = 0;

-- Creeping Sludge
DELETE FROM `smart_scripts` WHERE `entryorguid` = 12222 AND `source_type` = 0 AND `id` = 1;
UPDATE `creature_template_addon` SET `auras` = '22638' WHERE `entry` = 12222;

-- Released Soul
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30736 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3073600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30736,0,0,0,11,0,100,0,0,0,0,0,0,80,3073600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Released Soul - On Spawn - Run Script"),
(30736,0,1,0,34,0,100,0,8,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Released Soul - On Reached Point 0 - Despawn"),

(3073600,9,0,0,0,0,100,0,0,0,0,0,0,4,37,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Released Soul - On Script - Play Sound 37"),
(3073600,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Released Soul - On Script - Set Run Off"),
(3073600,9,2,0,0,0,100,0,0,0,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,0,0,12,0,"Released Soul - On Script - Rise up");

-- Lazy Peon
UPDATE `smart_scripts` SET `action_type` = 90, `action_param1` = 8 WHERE `entryorguid` IN (334500,334501,334600,334601,334700,334701,334800,334801,652300,652301,652400,652401,652500,652501,652600,652601,652700,652701,737200,737201,737300,737301,737400,737401,737500,737501,737600,737601) AND `source_type` = 9 AND `action_type` = 75 AND `action_param1` = 68442;
UPDATE `smart_scripts` SET `action_type` = 91, `action_param1` = 8 WHERE `entryorguid` IN (334500,334501,334600,334601,334700,334701,334800,334801,652300,652301,652400,652401,652500,652501,652600,652601,652700,652701,737200,737201,737300,737301,737400,737401,737500,737501,737600,737601) AND `source_type` = 9 AND `action_type` = 28 AND `action_param1` = 68442;

-- Disobedient Dragonmaw Peon
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (2331100,2331101,2331102) AND `source_type` = 9 AND `action_type` = 75;

-- Harene Plainwalker & Danwe
UPDATE `smart_scripts` SET `action_type` = 90, `action_param1` = 8 WHERE `entryorguid` IN (1665501,1666700) AND `source_type` = 9 AND `action_type` = 75 AND `action_param1` = 68442;
UPDATE `smart_scripts` SET `action_type` = 91, `action_param1` = 8 WHERE `entryorguid` IN (1665501,1666700) AND `source_type` = 9 AND `action_type` = 28 AND `action_param1` = 68442;
