--
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 0x00020000 WHERE `entry` IN (5202,4952,30121,23076,25534);

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 5202);
UPDATE `creature_template_addon` SET `auras` = "7056" WHERE `entry` = 5202;

UPDATE `creature_template_addon` SET `auras` = "7056" WHERE `entry` = 4952;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25534;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25534 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25534,0,0,0,25,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"En'kilah Blood Globe - On Reset - Set Reactstate Passive");

-- Full of hacks Mimiron
UPDATE `creature_template` SET `speed_run` = 1.42857142857, `BaseAttackTime` = 5000, `unit_flags` = 256, `unit_flags2` = 2080 WHERE `entry` = 34362; -- Proximity Mine
UPDATE `creature_template` SET `unit_flags` = 33554432, `unit_flags2` = 2080, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (34047,34110); -- Rocket Strike
UPDATE `creature_model_info` SET `BoundingRadius` = 0.82500005, `CombatReach` = 2.75 WHERE `DisplayID` = 29070;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `speed_walk` = 1.2, `speed_run` = 1, `unit_flags` = 33554432, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 34050; -- Rocket (Mimiron Visual)
UPDATE `creature_model_info` SET `BoundingRadius` = 0.3, `CombatReach` = 3 WHERE `DisplayID` = 29073;
UPDATE `creature_template` SET `speed_walk` = 1.2, `speed_run` = 1.42857142857, `unit_flags` = 33554432, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 34071; -- Leviathan Mk II
UPDATE `creature_template` SET `speed_run` = 1.42857142857, `BaseAttackTime` = 5000, `unit_flags` = 33554432, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 34149; -- Frost Bomb
UPDATE `creature_template` SET `speed_run` = 1.42857142857, `BaseAttackTime` = 5000, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 34211; -- Burst Target

-- Hodir
UPDATE `creature_template` SET `unit_flags` = 33554944 WHERE `entry` = 33174;
UPDATE `creature_template` SET `speed_run` = 0.99206284114 WHERE `entry` IN (33169,33173);
-- Two Flash Freeze are broken completely, cannot apply passive reactstate flag because it will prevent combat and
-- in script they enter in combat with freezed by them creatures, this means they are always in combat with them
-- with any player in aggro range and combat(those unit flags in script will not prevent it) will be never removed, clap-clap
UPDATE `creature_template` SET `unit_flags` = 0, `unit_flags2` = 32 WHERE `entry` IN (32926,33352);
UPDATE `creature_template` SET `unit_flags` = 0, `unit_flags2` = 32 WHERE `entry` IN (32938,33353);

-- Ingvar Throw Dummy, different speed in heroic, nice, nice, everything is nice
UPDATE `creature_template` SET `unit_flags` = 33554432, `unit_flags2` = 2080, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 23997;
UPDATE `creature_template` SET `speed_walk` = 12, `speed_run` = 4.28571428571, `unit_flags` = 33554432, `unit_flags2` = 2080, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 31835;

-- Ticking Time Bomb, broken with or without flags
UPDATE `creature_template` SET `speed_run` = 0.85714285714, `unit_flags` = 33554432, `unit_flags2` = 32, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 32246;
