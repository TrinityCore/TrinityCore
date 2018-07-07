
 --       AshamaneCore        --
-- // Patch note #4 by Nexon // --
  --       Legion 7.3.5        --



-- Table `creature_template`
UPDATE `creature_template` SET `npcflag` = 4736 WHERE (entry = 491);
UPDATE `creature_template` SET `InhabitType` = 2 WHERE (entry = 199);
UPDATE `creature_template` SET `InhabitType` = 2 WHERE (entry = 462);
UPDATE `creature_template` SET `InhabitType` = 2 WHERE (entry = 1109);
UPDATE `creature_template` SET `InhabitType` = 2 WHERE (entry = 154);
UPDATE `creature_template` SET `npcflag` = 0 WHERE (entry = 42383);
UPDATE `creature_template` SET `ScriptName` = 'temporaire_npc_icycle_dm' WHERE (entry = 49481);
UPDATE `creature_template` SET `npcflag` = 268435456, `unit_class` = 1, `unit_flags` = 32768, `type_flags` = 4096 WHERE (entry = 54442);
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 68;
DELETE FROM `creature_template` WHERE (entry = 833);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(833, 0, 0, 0, 0, 0, 52598, 52599, 0, 0, 'Coyote Packleader', '', '', NULL, '', 0, 11, 12, 0, 0, 0, 38, 0, 1, 1.14286, 1, 0, 0, 2000, 2000, 0, 0, 1, 67108872, 2048, 0, 4, 1, 0, 0, 0, 1, 1, 0, 833, 0, 833, 0, 1, 5, 0, 0, 0, 3149, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, '', 25549);
UPDATE `creature_template` SET `type_flags` = 0 WHERE (entry = 95056);
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `rank` = 2, `InhabitType` = 5, `HealthModifier` = 3, `ManaModifier` = 3 WHERE (entry = 121108);

-- Table smart_scripts 
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 210120041);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(210120041, 0, 1, 0, 1, 0, 100, 0, 1000, 6000, 6000, 14000, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 210120040);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(210120040, 0, 1, 0, 1, 0, 100, 0, 1000, 5000, 5000, 15000, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '');



-- DIFF `creature` of id 42407
DELETE FROM `creature` WHERE (id = 42407) AND (guid IN (210119100, 210119093, 210119094, 210119101));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210119100, 42407, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10427, 948.85, 33.3059, 0.784887, 10, 0, 0, 3452, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210119093, 42407, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10417.9, 950.789, 32.3799, 4.77236, 10, 0, 0, 3452, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210119094, 42407, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10413.6, 962.304, 33.3142, 5.18705, 10, 0, 0, 3858, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210119101, 42407, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10398.6, 1027.4, 32.618, 2.88975, 10, 0, 0, 2856, 0, 0, 0, 0, 0, 0, 0, '', 0);
-- DIFF `creature` of id 453
DELETE FROM `creature` WHERE (id = 453) AND (guid IN (210119115, 210119114, 210119121, 210119117));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210119115, 453, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10408.8, 1102.67, 32.7007, 3.65552, 10, 0, 0, 564, 295, 0, 0, 0, 0, 0, 0, '', 0),
(210119114, 453, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10356.6, 1103.37, 37.0145, 2.91332, 10, 0, 0, 564, 295, 0, 0, 0, 0, 0, 0, '', 0),
(210119121, 453, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10424.5, 1120.94, 32.3944, 3.79297, 15, 0, 0, 564, 295, 0, 0, 0, 0, 0, 0, '', 0),
(210119117, 453, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10440.3, 1128.62, 31.8436, 4.09927, 10, 0, 0, 517, 264, 0, 0, 0, 0, 0, 0, '', 0);
-- DIFF `creature` of id 501
DELETE FROM `creature` WHERE (id = 501) AND (guid IN (210119111, 210119109));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210119111, 501, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -10414.2, 1146.27, 34.0509, 4.92001, 15, 0, 0, 441, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210119109, 501, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -10407.8, 1095.78, 32.9159, 2.7955, 10, 0, 0, 441, 0, 0, 0, 0, 0, 0, 0, '', 0);
-- DIFF `creature` of id 452
DELETE FROM `creature` WHERE (id = 452) AND (guid IN (210119112, 210119120, 214774, 210119113, 210119119));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210119112, 452, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10409.8, 1147.66, 34.3878, 3.95004, 10, 0, 0, 441, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210119120, 452, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10430.3, 1124.45, 32.2522, 4.34275, 15, 0, 0, 517, 0, 0, 0, 0, 0, 0, 0, '', 0),
(214774, 452, 0, 40, 922, 1, 0, 0, 0, -1, 383, 0, -10977.3, 879.824, 36.1163, 1.65728, 150, 3, 0, 273, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210119113, 452, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10356.9, 1108.83, 36.8019, 3.52593, 10, 0, 0, 517, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210119119, 452, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -10432.9, 1127.45, 32.1753, 3.60448, 10, 0, 0, 517, 0, 0, 0, 0, 0, 0, 0, '', 0);

-- DIFF `creature` of id 54372
DELETE FROM `creature` WHERE (id = 54372) AND (guid IN (302990, 302992, 303002));
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(302990, 54372, 0, 40, 108, 1, 0, 0, 0, -1, 384, 0, -10586.7, 1192.91, 33.95, 4.407, 15, 3, 0, 273, 0, 1, 0, 0, 0, 0, 0, '', 0),
(302992, 54372, 0, 40, 108, 1, 0, 0, 0, -1, 384, 0, -10553.3, 1148.33, 35.121, 4.31494, 15, 3, 0, 273, 0, 1, 0, 0, 0, 0, 0, '', 0),
(303002, 54372, 0, 40, 108, 1, 0, 0, 0, -1, 384, 0, -10553.7, 1116.52, 38.8708, 4.14995, 15, 3, 0, 273, 0, 1, 0, 0, 0, 0, 0, '', 0);


-- Table `gameobject_template`
UPDATE `gameobject_template` SET `size` = 1 WHERE (entry = 259095);


-- Table `creature_equip_template`
UPDATE `creature_equip_template` SET `ItemID1`='45123' WHERE  `CreatureID`=86087 


-- Table `creature_addon` 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('21011114', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('21011113', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119047', '37');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119046', '35');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119045', '37'); 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119054', '45');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119053', '45');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119052', '45');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119051', '45');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119081', '35');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119061', '37');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119048', '35');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119049', '37');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119050', '38');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119128', '149734');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119130', '227301');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119133', '227301');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119136', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119135', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119139', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119151', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119159', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119160', '208343');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119166', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119167', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('215329', '227301');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119174', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119174', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119175', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210119175', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('21011911', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('21011912', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20343391', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20343390', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508433', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508440', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508657', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508646', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508438', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508439', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508437', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119238', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119246', '149734');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('265869', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508528', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508535', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('210119268', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('188867', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181939', '469');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181939', '157589');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181874', '164381');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181869', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181930', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20548909', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181921', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181919', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181605', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181663 ', '227301');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181866', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181597', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181711', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181937', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181702', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181696', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181941', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181888', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181626', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181886', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181631', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181900', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181911', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181900', '7');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181911', '7');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181627', '163720');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210120024', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210120025', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181616', '7');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181616', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181782', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('210120038', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181799', '10');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181800', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181787', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('10181795', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10181860', '432');
