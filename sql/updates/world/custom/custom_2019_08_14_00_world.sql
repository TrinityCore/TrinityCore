UPDATE `creature_template` SET `npcflag`= 0, `VehicleId`= 1111 WHERE `entry`= 45455;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 45455;

DELETE FROM `creature` WHERE `guid` IN (368211, 368210);
DELETE FROM `creature_addon` WHERE `guid` IN (368211, 368210);

SET @CGUID := 383032;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Spawned after Grandvizier Ertan died
(@CGUID+0, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -775.517, -70.9323, 640.3123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+1, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -310.4583, -29.74479, 625.0833, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+2, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -848.227, -68.724, 654.2203, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+3, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -844.885, -205.135, 660.7083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+4, 45504, 657, 0, 0, 3, 169, 0, 0, 0, -906.08, -176.514, 664.5053, 2.86234, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream Landing Zone
-- Spawned after Altairus died
(@CGUID+5, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -1229.64, 412.26, 641.2933, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+6, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -1245.21, 230.986, 690.6083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+7, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -1190.88, 125.203, 737.6243, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+8, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -382.441, 42.31597, 625.0833, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+9, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -1138.55, 178.524, 711.4943, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+10, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -1282.07, 344.856, 660.9873, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream
(@CGUID+11, 45504, 657, 0, 0, 3, 169, 0, 0, 0, -1193.67, 472.835, 634.8653, 0.5061455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slipstream Landing Zone
-- Spawned after Asaad died
(@CGUID+12, 45455, 657, 0, 0, 3, 169, 0, 0, 0, -746.9566, 529.1406, 644.8316, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Slipstream

DELETE FROM `spawn_group_template` WHERE `groupId` IN (406, 407, 408);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(406, 'The Vortex Pinnacle - Grandvizier Ertan Slipstreams', 4),
(407, 'The Vortex Pinnacle - Altairus Slipstreams', 4),
(408, 'The Vortex Pinnacle - Asaad Slipstreams', 4);

SET @SPAWNGROUP := 406;
DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+0),
(@SPAWNGROUP, 0, @CGUID+1),
(@SPAWNGROUP, 0, @CGUID+2),
(@SPAWNGROUP, 0, @CGUID+3),
(@SPAWNGROUP, 0, @CGUID+4);

SET @SPAWNGROUP := 407;
DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+5),
(@SPAWNGROUP, 0, @CGUID+6),
(@SPAWNGROUP, 0, @CGUID+7),
(@SPAWNGROUP, 0, @CGUID+8),
(@SPAWNGROUP, 0, @CGUID+9),
(@SPAWNGROUP, 0, @CGUID+10),
(@SPAWNGROUP, 0, @CGUID+11);

SET @SPAWNGROUP := 408;
DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+12);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` IN (406, 407, 408);
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(657, 0, 8, 406, 1), -- Enable group when Grandvizier Ertan is DONE
(657, 1, 8, 407, 1), -- Enable group when Alairus is DONE
(657, 2, 8, 408, 1); -- Enable group when Asaad is DONE

DELETE FROM `spell_target_position` WHERE `ID` IN (89499, 89501);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(89499, 0, 657, -906.08, -176.514, 664.5053, 2.86234),
(89501, 0, 657, -1193.67, 472.835, 634.8653, 0.5061455);
