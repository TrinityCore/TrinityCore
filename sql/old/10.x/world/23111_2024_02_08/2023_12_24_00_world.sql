UPDATE `creature_template` SET `npcflag`= 0, `VehicleId`= 1111, `ScriptName`= 'npc_vp_slipstream' WHERE `entry`= 45455;
UPDATE `creature_template` SET `unit_flags`= 0x2000000, `flags_extra`= 0x80,`ScriptName`= 'npc_vp_slipstream_landing_zone' WHERE `entry`= 45504;

DELETE FROM `creature_template_addon` WHERE `entry`= 45455;
INSERT INTO `creature_template_addon` (`entry`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(45455, 1, 5, '85021');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (45455, 45504);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(45455, 0, 1, 0),
(45504, 0, 1, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 45455;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(45455, 84965, 1, 0);

DELETE FROM `creature` WHERE `guid` IN (368211, 368210);
DELETE FROM `creature_addon` WHERE `guid` IN (368211, 368210);

SET @CGUID := 3000463;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `StringId`, `VerifiedBuild`) VALUES
-- Spawned after Grandvizier Ertan died
(@CGUID+0, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -775.517, -70.9323, 640.3123, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_ertan_1', 15595), -- Slipstream
(@CGUID+1, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -310.4583, -29.74479, 625.0833, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_entrance_1', 15595), -- Slipstream
(@CGUID+2, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -848.227, -68.724, 654.2203, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_ertan_2',15595), -- Slipstream
(@CGUID+3, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -844.885, -205.135, 660.7083, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_ertan_3', 15595), -- Slipstream
(@CGUID+4, 45504, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -906.08, -176.514, 664.5053, 2.86234, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_landing_zone_1', 15595), -- Slipstream Landing Zone
-- Spawned after Altairus died
(@CGUID+5, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -1229.64, 412.26, 641.2933, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_altairus_5', 15595), -- Slipstream
(@CGUID+6, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -1245.21, 230.986, 690.6083, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_altairus_3', 15595), -- Slipstream
(@CGUID+7, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -1190.88, 125.203, 737.6243, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_altairus_1', 15595), -- Slipstream
(@CGUID+8, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -382.441, 42.31597, 625.0833, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_entrance_2', 15595), -- Slipstream
(@CGUID+9, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -1138.55, 178.524, 711.4943, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_altairus_2', 15595), -- Slipstream
(@CGUID+10, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -1282.07, 344.856, 660.9873, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_altairus_4', 15595), -- Slipstream
(@CGUID+11, 45504, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -1193.67, 472.835, 634.8653, 0.5061455, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_landing_zone_2', 15595), -- Slipstream Landing Zone
-- Spawned after Asaad died
(@CGUID+12, 45455, 657, 0, 0, '1,2,24', 169, 0, 0, 0, -746.9566, 529.1406, 644.8316, 0, 7200, 0, 0, 0, 0, 0, NULL, NULL, 'vp_slipstream_back_to_entrance', 15595); -- Slipstream

DELETE FROM `spawn_group_template` WHERE `groupId` IN (1038, 1039, 1040);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(1038, 'The Vortex Pinnacle - Grandvizier Ertan Slipstreams', 4),
(1039, 'The Vortex Pinnacle - Altairus Slipstreams', 4),
(1040, 'The Vortex Pinnacle - Asaad Slipstreams', 4);

SET @SPAWNGROUP := 1038;
DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+0),
(@SPAWNGROUP, 0, @CGUID+1),
(@SPAWNGROUP, 0, @CGUID+2),
(@SPAWNGROUP, 0, @CGUID+3),
(@SPAWNGROUP, 0, @CGUID+4);

SET @SPAWNGROUP := 1039;
DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+5),
(@SPAWNGROUP, 0, @CGUID+6),
(@SPAWNGROUP, 0, @CGUID+7),
(@SPAWNGROUP, 0, @CGUID+8),
(@SPAWNGROUP, 0, @CGUID+9),
(@SPAWNGROUP, 0, @CGUID+10),
(@SPAWNGROUP, 0, @CGUID+11);

SET @SPAWNGROUP := 1040;
DELETE FROM `spawn_group` WHERE `groupId`= @SPAWNGROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP, 0, @CGUID+12);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` IN (1038, 1039, 1040);
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(657, 0, 8, 1038, 1), -- Enable group when Grandvizier Ertan is DONE
(657, 1, 8, 1039, 1), -- Enable group when Alairus is DONE
(657, 2, 8, 1040, 1); -- Enable group when Asaad is DONE

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_vp_slipstream', 'spell_vp_slipstream_shortcut');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84978, 'spell_vp_slipstream'),
(84989, 'spell_vp_slipstream'),
(85395, 'spell_vp_slipstream'),
(85396, 'spell_vp_slipstream'),
(85017, 'spell_vp_slipstream'),
(89499, 'spell_vp_slipstream_shortcut'),
(89501, 'spell_vp_slipstream_shortcut');

DELETE FROM `spell_script_names` WHERE `spell_id`= 79737;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79737, 'spell_gen_eject_all_passengers');
