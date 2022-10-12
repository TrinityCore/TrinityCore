UPDATE `creature_template` SET  `ScriptName` = 'boss_rook_stonetoe' WHERE `entry` = 71475;
UPDATE `creature_template` SET  `ScriptName` = 'boss_he_softfoot' WHERE `entry` = 71479;
UPDATE `creature_template` SET  `ScriptName` = 'boss_sun_tenderheart' WHERE `entry` = 71480;
--
DELETE FROM creature WHERE id in (71711, 71684, 71686, 71478, 71482, 71474, 71477, 71476, 71481);
--
UPDATE `creature_template` SET `VehicleId` = '2906', `InhabitType` = '4', `ScriptName` = 'npc_golden_lotus_control' WHERE `entry` = 71683;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 71683;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(71683, 46598, 1, 0);
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 71683;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('71683', '71711', '0', '1', '', '8', '0'),
('71683', '71684', '1', '1', '', '8', '0'),
('71683', '71686', '2', '1', '', '8', '0');
UPDATE `creature_template_addon` SET `auras` = '143870' WHERE `creature_template_addon`.`entry` = 71683;
--
UPDATE `creature_template` SET `modelid1` = '11686', `VehicleId` = '2909', `InhabitType` = '4', `ScriptName` = '', `flags_extra` = '128' WHERE `entry` = 71711;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 71711;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(71711, 46598, 1, 0);
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 71711;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('71711', '71478', '0', '0', '', '8', '0');
--
UPDATE `creature_template` SET `modelid1` = '11686', `VehicleId` = '2907', `InhabitType` = '4', `ScriptName` = '', `flags_extra` = '128' WHERE `entry` = 71684;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 71684;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(71684, 46598, 1, 0);
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 71684;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('71684', '71482', '0', '0', '', '8', '0'),
('71684', '71474', '1', '0', '', '8', '0');
--
UPDATE `creature_template` SET `modelid1` = '11686', `VehicleId` = '2908', `InhabitType` = '4', `ScriptName` = '', `flags_extra` = '128' WHERE `entry` = 71686;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 71686;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(71686, 46598, 1, 0);
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = 71686;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
('71686', '71477', '0', '0', '', '8', '0'),
('71686', '71476', '1', '0', '', '8', '0'),
('71686', '71481', '2', '0', '', '8', '0');
--
UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` in (71478, 71482, 71474, 71477, 71476, 71481, 71695);

--
DELETE FROM creature where id = 71695;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) VALUES
(71695, 1136, 6738, 6798, 16632, 1, 11686, 0, 1243.884, 1015.989, 452.25, 0.0479199, 600, 1, 0, 436137, 436137, 2, 0, 33554432, 0, 0);

UPDATE `creature_template_addon` SET `path_id` = '71695' WHERE `entry` = 71695;
DELETE FROM `waypoint_data` WHERE id = 71695;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`, `wpguid`) VALUES 
('71695', '0', '1241.576', '1000.554', '452.25', '0', '0', '0', '0', '100', '71695', '0'),
('71695', '1', 1243.884, 1015.989, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '2', 1240.109, 1031.133, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '3', 1230.827, 1043.68, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '4', 1217.449, 1051.719, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '5', 1202.014, 1054.027, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '6', 1186.87, 1050.253, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '7', 1174.323, 1040.97, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '8', 1166.284, 1027.593, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '9', 1163.976, 1012.157, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '10', 1167.75, 997.0134, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '11', 1177.033, 984.4667, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '12', 1190.41, 976.4273, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '13', 1205.846, 974.1192, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '14', 1220.99, 977.8938, 452.25, '0', '0', '0', '0', '100', '71695', '0'),
('71695', '15', 1233.536, 987.1764, 452.25, '0', '0', '0', '0', '100', '71695', '0');
