SET @CGUID := 86075;
SET @POOL := 32492;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6 AND `id`=4131;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 4131, 1, 0, 0, 1, 1, 11143, 0, -6484.09, -3229.87, -112.36, 3.42467, 300, 3, 0, 1221, 0, 1, 0, 0, 0, 0),
(@CGUID+1, 4131, 1, 0, 0, 1, 1, 11143, 0, -6472.31, -3243.75, -113.38, 5.96223, 300, 3, 0, 1221, 0, 1, 0, 0, 0, 0),
(@CGUID+2, 4131, 1, 0, 0, 1, 1, 11143, 0, -6491.48, -3245.93, -112.497, 6.10384, 300, 3, 0, 1221, 0, 1, 0, 0, 0, 0),
(@CGUID+3, 4131, 1, 0, 0, 1, 1, 11143, 0, -6462.86, -3297.58, -104.92, 1.41244, 300, 3, 0, 1221, 0, 1, 0, 0, 0, 0),
(@CGUID+4, 4131, 1, 0, 0, 1, 1, 11143, 0, -6485.84, -3254.02, -113.549, 0.814107, 300, 3, 0, 1221, 0, 1, 0, 0, 0, 0),
(@CGUID+5, 4131, 1, 0, 0, 1, 1, 11143, 0, -6488.36, -3323.74, -94.8076, 3.46016, 300, 5, 0, 1221, 0, 1, 0, 0, 0, 0),
(@CGUID+6, 4131, 1, 0, 0, 1, 1, 11143, 0, -6496.03, -3325.49, -95.8035, 2.63545, 300, 3, 0, 1221, 0, 1, 0, 0, 0, 0);

DELETE FROM `pool_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6 AND `pool_entry` BETWEEN @Pool AND @Pool+6;
DELETE FROM `pool_creature` WHERE `guid` IN(21317,21318,21314,21324,21323,21325,21327) AND `pool_entry` BETWEEN @Pool AND @Pool+6;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@CGUID+0, @Pool, 0, 'Silithid Invader'),
(21317, @Pool, 0, 'Silithid Hive Drone'),
(@CGUID+1, @Pool+1, 0, 'Silithid Invader'),
(21318, @Pool+1, 0, 'Silithid Hive Drone'),
(@CGUID+2, @Pool+2, 0, 'Silithid Invader'),
(21314, @Pool+2, 0, 'Silithid Hive Drone'),
(@CGUID+3, @Pool+3, 0, 'Silithid Invader'),
(21324, @Pool+3, 0, 'Silithid Hive Drone'),
(@CGUID+4, @Pool+4, 0, 'Silithid Invader'),
(21323, @Pool+4, 0, 'Silithid Hive Drone'),
(@CGUID+5, @Pool+5, 0, 'Silithid Invader'),
(21325, @Pool+5, 0, 'Silithid Hive Drone'),
(@CGUID+6, @Pool+6, 0, 'Silithid Invader'),
(21327, @Pool+6, 0, 'Silithid Hive Drone');

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL+0 AND @POOL+6;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL+0, 1, 'Silithid Invader/drone pool 1'),
(@POOL+1, 1, 'Silithid Invader/drone pool 2'),
(@POOL+2, 1, 'Silithid Invader/drone pool 3'),
(@POOL+3, 1, 'Silithid Invader/drone pool 4'),
(@POOL+4, 1, 'Silithid Invader/drone pool 5'),
(@POOL+5, 1, 'Silithid Invader/drone pool 6'),
(@POOL+6, 1, 'Silithid Invader/drone pool 7');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`=32818;

DELETE FROM `smart_scripts` WHERE `entryorguid`=32818 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3281800 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32818, 0, 0, 0, 76, 0, 100, 513, 0, 31442, 6, 0, 80, 3281800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plump Turkey - On Basic Campfire (Trap) within 10 yrds - run script (no repeat)'),
(3281800, 9, 0, 0, 0, 0, 100, 513, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plump Turkey - Script - Stop Follow'),
(3281800, 9, 1, 0, 0, 0, 100, 513, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plump Turkey - Script - Set Run'),
(3281800, 9, 2, 0, 0, 0, 100, 513, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 20, 31442, 0, 0, 0, 0, 0, 0, 'Plump Turkey - Script - Move to Position'),
(3281800, 9, 3, 0, 0, 0, 100, 513, 2000, 2000, 0, 0, 11, 61768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plump Turkey - Script - Cast Turkey Starts to Burn'),
(3281800, 9, 4, 0, 0, 0, 100, 513, 2000, 2000, 0, 0, 11, 61769, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Plump Turkey - Script - Cast Turkey Burns Up');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`=10717;

DELETE FROM `smart_scripts` WHERE `entryorguid`=10717;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10717, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temporal Parasite - On Just Summoned - Say'),
(10717, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 175795, 0, 0, 0, 0, 0, 0, 'Temporal Parasite - On Just Summoned - Despawn Anorhal Silo Temporal Rift'),
(10717, 0, 2, 0, 6, 0, 25, 0, 0, 0, 0, 0, 11, 16619, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temporal Parasite - On Death - Cast Quest - Temporal Parasite Death Summon');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`IN(5307,5308);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(5307,5308);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5307, 0, 0, 0, 8, 0, 100, 0, 12699, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vale Screecher - On Spellhit - Despawn'),
(5307, 0, 1, 0, 1, 0, 100, 0, 1000, 3000, 3000, 5000, 11, 59220, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vale Screecher - IC - Cast Chain Lightning'),
(5308, 0, 0, 0, 8, 0, 100, 0, 12699, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rogue Vale Screecher - On Spellhit - Despawn');
