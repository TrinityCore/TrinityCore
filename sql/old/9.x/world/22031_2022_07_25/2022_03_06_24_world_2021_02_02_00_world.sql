-- Inactive Fel Reaver
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 22293;
UPDATE `creature_template_addon` SET `auras` = "38757" WHERE `entry` = 22293;

UPDATE `smart_scripts` SET `event_flags` = 0, `comment` = "Inactive Fel Reaver - On Quest 'Nether Gas In a Fel Fire Engine' Finished - Run Script" WHERE `entryorguid` = 22293 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2229300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2229300,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Inactive Fel Reaver - On Script - Say Line 0"),
(2229300,9,1,0,0,0,100,0,0,0,0,0,0,28,38757,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Inactive Fel Reaver - On Script - Remove Aura 'Fel Reaver Freeze'"),
(2229300,9,2,0,0,0,100,0,0,0,0,0,0,89,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Inactive Fel Reaver - On Script - Start Random Movement"),
-- This part need more love
(2229300,9,3,0,0,0,100,0,6000,6000,0,0,0,33,22293,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Inactive Fel Reaver - On Script - Quest Credit 'Fel Reavers, No Thanks!'"),
(2229300,9,4,0,0,0,100,0,0,0,0,0,0,85,38758,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Inactive Fel Reaver - On Script - Invoker Cast '[PH] Quest reward: Nether Gas In a Fel Fire Engine'"),
(2229300,9,5,0,0,0,100,0,0,0,0,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Inactive Fel Reaver - On Script - Kill Self");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 22293;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(22293,1,0,0,0,0,0,0);

-- The Etymidian
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28092;
UPDATE `creature_template_addon` SET `auras` = "16245 25900" WHERE `entry` = 28092;

-- Slime-Covered Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 20158;
UPDATE `creature_template_addon` SET `bytes1` = 0, `auras` = "29266" WHERE `entry` = 20158;

-- T'chali the Witch Doctor
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 21349;
UPDATE `creature` SET `position_x` = 1792.966796875, `position_y` = 6406.4443359375, `position_z` = -11.9013652801513671, `orientation` = 0, `VerifiedBuild` = 15050 WHERE `guid` = 74753 AND `id` = 21349;

-- Veras Darkshadow
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.714285731315612792, `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 22952;

-- Harrowmeiser
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 23823;
UPDATE `creature_template_addon` SET `auras` = "25900" WHERE `entry` = 23823;

-- Monte Muzzleshot
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 27987;

-- Harry's Bomber
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28277;
UPDATE `creature` SET `VerifiedBuild` = 15595 WHERE `guid` = 106834 AND `id` = 28277;
UPDATE `creature` SET `unit_flags` = 33587968, `VerifiedBuild` = 15595 WHERE `guid` = 106836 AND `id` = 28277;
DELETE FROM `creature_template_addon` WHERE `entry` = 28277;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(28277,0,0,0,1,0,0,"29826");

-- Citizen of Havenshire
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28576;

-- Riplash Sorceress
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24662;
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 24662;

-- Slain Tuskarr
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24678;

-- Sseratus
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28089;

-- Quetz'lun
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 28672;
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = "29266" WHERE `entry` = 28672;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 28672);

-- Mine Car, Dragonmaw Foreman
-- They roots and stuns themselves at some points, Mine Car stuns by 29826 and no spell for Dragonmaw Foreman
-- or wasn't shown due to some reasons in 2 particular builds
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 23289;
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 23376;
