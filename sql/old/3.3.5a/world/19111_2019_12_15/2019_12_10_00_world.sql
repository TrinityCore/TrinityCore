-- 
DELETE FROM `creature` WHERE `guid` IN (120601);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(120601, 27175, 571, 3537, 4121, 1, 1, 0, 1, 3599.8713, 6687.595, 194.964, 4.113135, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340); -- 27175 (Area: 4121 - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry` IN (27175);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(27175, 0, 0, 0, 257, 0, ''); -- 27175

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (27175);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27175) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27175, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 12000, 15000, 0, 11, 12738, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Transitus Shield Warmage - IC - Cast Amplify Damage'),
(27175, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 3000, 4000, 0, 11, 17290, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Transitus Shield Warmage - IC - Cast Fireball'),
(27175, 0, 2, 0, 0, 0, 100, 0, 5000, 6000, 8000, 10000, 0, 11, 56837, 65, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Transitus Shield Warmage - IC - Cast Frostbolt'),
(27175, 0, 3, 0, 0, 0, 100, 0, 7000, 10000, 20000, 25000, 0, 11, 13323, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Transitus Shield Warmage - IC - Cast Polymorph');
