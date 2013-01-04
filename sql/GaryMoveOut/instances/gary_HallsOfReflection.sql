DELETE FROM `creature` WHERE `id` =37225;  -- Remove spawned Uther
DELETE FROM `creature` WHERE `guid` IN (2022890, 2022900);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('2022890', '38112', '668', '3', '1', '0', '0', '5271.65', '2042.5', '709.32', '5.51217', '604800', '0', '0', '377468', '0', '0', '0', '0', '0');
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('2022900', '38113', '668', '3', '1', '0', '0', '5344.75', '1972.87', '709.319', '2.33445', '604800', '0', '0', '539240', '0', '0', '0', '0', '0');

DELETE FROM `creature` WHERE `id` =36723; -- Frostsworn general
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (2022920, '36723', '668', '3', '1', '0', '2432', '5413.9', '2116.65', '707.695', '3.94765', '604800', '0', '0', '315000', '0', '0', '0', '0', '0');

DELETE FROM `creature_template` WHERE `entry` =37107; -- Spiritual Reflection
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ('37107', '37721', '0', '0', '0', '0', '24653', '0', '0', '0', 'Spiritual Reflection', '', '', '0', '80', '80', '2', '35', '35', '0', '1', '1.14286', '1', '1', '422', '586', '0', '642', '7.5', '0', '0', '1', '32784', '8', '0', '0', '0', '0', '0', '345', '509', '103', '7', '72', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '4', '1', '1', '0', '0', '0', '0', '0', '0', '0', '113', '1', '0', '0', '0', 'npc_spiritual_reflection', '12340');
DELETE FROM `creature_template` WHERE `entry` =36954; -- The Lich King Part 1
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ('36954', '0', '0', '0', '0', '0', '30721', '0', '0', '0', 'The Lich King', '', '', '0', '83', '83', '2', '2102', '2102', '0', '1.8', '2', '1', '3', '509', '683', '0', '805', '35', '2000', '0', '1', '256', '8', '0', '0', '0', '0', '0', '371', '535', '135', '6', '268435500', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '2000', '500', '1', '0', '0', '0', '0', '0', '0', '0', '117', '1', '0', '8388624', '0', 'npc_lich_king_hr', '12340');
DELETE FROM `creature` WHERE `id` =37226;  -- Remove DB spawned LK
DELETE FROM `creature_template` WHERE `entry` =37226;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ('37226', '0', '0', '0', '0', '0', '30721', '0', '0', '0', 'The Lich King', '', '', '0', '83', '83', '2', '2102', '2102', '0', '1.8', '2', '0.8', '3', '509', '683', '0', '805', '35', '2000', '0', '1', '768', '8', '0', '0', '0', '0', '0', '371', '535', '135', '6', '36', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '2000', '500', '1', '0', '0', '0', '0', '0', '0', '0', '151', '1', '2425', '617299955', '0', 'boss_lich_king_hor', '12340');


DELETE FROM `gameobject` WHERE `id` =202302;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES ('1530030', '202302', '668', '3', '1', '5309.51', '2006.64', '709.341', '5.50041', '0', '0', '0.381473', '-0.92438', '604800', '100', '1');
DELETE FROM `gameobject` WHERE `id` =202236;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES ('1530040', '202236', '668', '3', '1', '5309.51', '2006.64', '709.341', '5.53575', '0', '0', '0.365077', '-0.930977', '604800', '100', '1');
DELETE FROM `gameobject` WHERE `id` =201976;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES ('1530120', '201976', '668', '3', '1', '5264.6', '1959.55', '707.695', '0.736951', '0', '0', '0.360194', '0.932877', '300', '100', '0');
DELETE FROM `gameobject` WHERE `id` =197341;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES ('1530110', '197341', '668', '3', '1', '5359.24', '2058.35', '707.695', '3.96022', '0', '0', '0.917394', '-0.397981', '300', '100', '1');

DELETE FROM `creature_template` WHERE `entry` =37554;  -- Sylvanas part 1
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ('37554', '0', '0', '0', '0', '0', '30776', '0', '0', '0', 'Lady Sylvanas Windrunner', '', '', '0', '80', '80', '2', '1770', '1770', '2', '0.888888', '0.99206', '0.8', '1', '346', '499', '0', '287', '7.5', '1000', '0', '8', '33088', '8', '0', '0', '0', '0', '0', '315', '468', '69', '7', '262144', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '500', '100', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1290', '0', '0', 'npc_jaina_and_sylvana_hor_part2', '12340');
DELETE FROM `creature_template` WHERE `entry` =36955; -- Lady Proudmoore part 1
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ('36955', '0', '0', '0', '0', '0', '30867', '0', '0', '0', 'Lady Jaina Proudmoore', '', '', '0', '80', '80', '2', '84', '84', '2', '1', '1.14286', '0.8', '1', '346', '499', '0', '287', '7.5', '0', '0', '8', '0', '8', '0', '0', '0', '0', '0', '315', '468', '69', '7', '262144', '0', '0', '0', '0', '0', '0', '0', '0', '0', '69708', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '0', '3', '500', '100', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1221', '0', '0', 'npc_jaina_and_sylvana_hor_part2', '12340');


UPDATE  `creature_template` SET  `ScriptName` =  'npc_frostworn_general' WHERE  `entry` =36723;
UPDATE  `creature_template` SET  `ScriptName` =  'npc_raging_gnoul' WHERE  `entry` =36940;
UPDATE  `creature_template` SET  `ScriptName` =  'npc_risen_witch_doctor' WHERE  `entry` =36941;
UPDATE  `creature_template` SET  `ScriptName` =  'npc_abon' WHERE  `entry` =37069;

-- Area Trigger, for wave restarter
DELETE FROM `areatrigger_scripts` WHERE `entry` =5697;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES ('5697', 'at_hor_waves_restarter');

-- Normal
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry` IN (38172, 38175, 38176, 38173, 38177, 38113, 38112);
-- Heroic
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry` IN (38599, 38603, 38524, 38525, 38563, 38544, 38564);
-- Fix faction on Heroic 
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16 WHERE `entry` = 37720;
-- Sylvanas Waypoints to ship
DELETE FROM `script_waypoint` WHERE `entry` =37554;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(37554, 0, 5587.68, 2228.59, 733.011, 0, 'WP1'),
(37554, 1, 5600.71, 2209.06, 731.618, 0, 'WP2'),
(37554, 2, 5606.42, 2193.03, 731.129, 0, 'WP3'),
(37554, 3, 5598.56, 2167.81, 730.918, 0, 'WP4 - Summon IceWall 01'),
(37554, 4, 5556.44, 2099.83, 731.827, 0, 'WP5 - Spell Channel'),
(37554, 5, 5543.5, 2071.23, 731.702, 0, 'WP6'),
(37554, 6, 5528.97, 2036.12, 731.407, 0, 'WP7'),
(37554, 7, 5512.04, 1996.7, 735.122, 0, 'WP8'),
(37554, 8, 5504.49, 1988.79, 735.886, 0, 'WP9 - Spell Channel'),
(37554, 9, 5489.65, 1966.39, 737.653, 0, 'WP10'),
(37554, 10, 5475.52, 1943.18, 741.146, 0, 'WP11'),
(37554, 11, 5466.93, 1926.05, 743.536, 0, 'WP12'),
(37554, 12, 5445.16, 1894.95, 748.757, 0, 'WP13 - Spell Channel'),
(37554, 13, 5425.91, 1869.71, 753.237, 0, 'WP14'),
(37554, 14, 5405.12, 1833.94, 757.486, 0, 'WP15'),
(37554, 15, 5370.32, 1799.38, 761.007, 0, 'WP16'),
(37554, 16, 5335.42, 1766.95, 767.635, 0, 'WP17 - Spell Channel'),
(37554, 17, 5311.44, 1739.39, 774.165, 0, 'WP18'),
(37554, 18, 5283.59, 1703.76, 784.176, 0, 'WP19'),
(37554, 19, 5260.4, 1677.78, 784.301, 3000, 'WP20'),
(37554, 20, 5262.44, 1680.41, 784.294, 0, 'WP21'),
(37554, 21, 5260.4, 1677.78, 784.301, 0, 'WP22');
-- Lady Proudmoore Waypoints to ship
DELETE FROM `script_waypoint` WHERE `entry` =36955;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(36955, 0, 5587.68, 2228.59, 733.011, 0, 'WP1'),
(36955, 1, 5600.71, 2209.06, 731.618, 0, 'WP2'),
(36955, 2, 5606.42, 2193.03, 731.129, 0, 'WP3'),
(36955, 3, 5598.56, 2167.81, 730.918, 0, 'WP4 - Summon IceWall 01'),
(36955, 4, 5556.44, 2099.83, 731.827, 0, 'WP5 - Spell Channel'),
(36955, 5, 5543.5, 2071.23, 731.702, 0, 'WP6'),
(36955, 6, 5528.97, 2036.12, 731.407, 0, 'WP7'),
(36955, 7, 5512.04, 1996.7, 735.122, 0, 'WP8'),
(36955, 8, 5504.49, 1988.79, 735.886, 0, 'WP9 - Spell Channel'),
(36955, 9, 5489.65, 1966.39, 737.653, 0, 'WP10'),
(36955, 10, 5475.52, 1943.18, 741.146, 0, 'WP11'),
(36955, 11, 5466.93, 1926.05, 743.536, 0, 'WP12'),
(36955, 12, 5445.16, 1894.95, 748.757, 0, 'WP13 - Spell Channel'),
(36955, 13, 5425.91, 1869.71, 753.237, 0, 'WP14'),
(36955, 14, 5405.12, 1833.94, 757.486, 0, 'WP15'),
(36955, 15, 5370.32, 1799.38, 761.007, 0, 'WP16'),
(36955, 16, 5335.42, 1766.95, 767.635, 0, 'WP17 - Spell Channel'),
(36955, 17, 5311.44, 1739.39, 774.165, 0, 'WP18'),
(36955, 18, 5283.59, 1703.76, 784.176, 0, 'WP19'),
(36955, 19, 5260.4, 1677.78, 784.301, 3000, 'WP20'),
(36955, 20, 5262.44, 1680.41, 784.294, 0, 'WP21'),
(36955, 21, 5260.4, 1677.78, 784.301, 0, 'WP22');
-- Lich King Waypoints
DELETE FROM `script_waypoint` WHERE `entry` =37226;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(37226, 1, 5577.19, 2236, 733.012, 0, 'HoR WP LichKing'),
(37226, 2, 5580.57, 2232.22, 733.012, 0, 'HoR WP LichKing'),
(37226, 3, 5586.67, 2225.54, 733.012, 0, 'HoR WP LichKing'),
(37226, 4, 5590.45, 2221.41, 733.012, 0, 'HoR WP LichKing'),
(37226, 5, 5595.75, 2215.62, 732.101, 0, 'HoR WP LichKing'),
(37226, 6, 5601.21, 2206.49, 731.54, 0, 'HoR WP LichKing'),
(37226, 7, 5605.01, 2197.9, 731.667, 0, 'HoR WP LichKing'),
(37226, 8, 5606.55, 2191.39, 730.977, 0, 'HoR WP LichKing'),
(37226, 9, 5604.68, 2186.11, 730.998, 0, 'HoR WP LichKing'),
(37226, 10, 5602.26, 2179.9, 730.967, 0, 'HoR WP LichKing'),
(37226, 11, 5600.06, 2174.38, 730.924, 0, 'HoR WP LichKing'),
(37226, 12, 5597.29, 2166.81, 730.924, 0, 'HoR WP LichKing'),
(37226, 13, 5596.25, 2160.36, 730.931, 0, 'HoR WP LichKing'),
(37226, 14, 5591.79, 2152.87, 731.008, 0, 'HoR WP LichKing'),
(37226, 15, 5585.47, 2146.63, 731.109, 0, 'HoR WP LichKing'),
(37226, 16, 5579.1, 2140.34, 731.18, 0, 'HoR WP LichKing'),
(37226, 17, 5572.56, 2134.21, 731.092, 0, 'HoR WP LichKing'),
(37226, 18, 5564.08, 2126.53, 730.816, 0, 'HoR WP LichKing'),
(37226, 19, 5559.04, 2117.64, 730.812, 0, 'HoR WP LichKing'),
(37226, 20, 5555.77, 2111.88, 730.995, 0, 'HoR WP LichKing'),
(37226, 21, 5550.82, 2103.14, 731.123, 0, 'HoR WP LichKing'),
(37226, 22, 5546.02, 2094.68, 731.16, 0, 'HoR WP LichKing'),
(37226, 23, 5541.53, 2084.42, 730.999, 0, 'HoR WP LichKing'),
(37226, 24, 5537.5, 2075.18, 730.901, 0, 'HoR WP LichKing'),
(37226, 25, 5533.76, 2063.84, 730.87, 0, 'HoR WP LichKing'),
(37226, 26, 5530.97, 2052.98, 730.981, 0, 'HoR WP LichKing'),
(37226, 27, 5526.75, 2041.73, 731.193, 0, 'HoR WP LichKing'),
(37226, 28, 5522.88, 2031.65, 731.7, 0, 'HoR WP LichKing'),
(37226, 29, 5521.01, 2023.02, 732.396, 0, 'HoR WP LichKing'),
(37226, 30, 5516.55, 2015.36, 733.12, 0, 'HoR WP LichKing'),
(37226, 31, 5513.06, 2007.33, 733.99, 0, 'HoR WP LichKing'),
(37226, 32, 5510.43, 1997.9, 735.016, 0, 'HoR WP LichKing'),
(37226, 33, 5504.53, 1990.39, 735.748, 0, 'HoR WP LichKing'),
(37226, 34, 5499.34, 1983.78, 736.29, 0, 'HoR WP LichKing'),
(37226, 35, 5493.11, 1975.86, 736.852, 0, 'HoR WP LichKing'),
(37226, 36, 5487.58, 1968.81, 737.394, 0, 'HoR WP LichKing'),
(37226, 37, 5483.12, 1961.78, 738.06, 0, 'HoR WP LichKing'),
(37226, 38, 5478.33, 1954.2, 739.343, 0, 'HoR WP LichKing'),
(37226, 39, 5475.2, 1945.84, 740.697, 0, 'HoR WP LichKing'),
(37226, 40, 5472.15, 1938.02, 741.884, 0, 'HoR WP LichKing'),
(37226, 41, 5469.26, 1931.34, 742.813, 0, 'HoR WP LichKing'),
(37226, 42, 5464.23, 1922.25, 744.055, 0, 'HoR WP LichKing'),
(37226, 43, 5458.43, 1912.96, 745.229, 0, 'HoR WP LichKing'),
(37226, 44, 5452.26, 1902.95, 747.091, 0, 'HoR WP LichKing'),
(37226, 45, 5442.44, 1892.51, 749.208, 0, 'HoR WP LichKing'),
(37226, 46, 5435.67, 1879.7, 751.776, 0, 'HoR WP LichKing'),
(37226, 47, 5429.03, 1870.73, 753.151, 0, 'HoR WP LichKing'),
(37226, 48, 5423.72, 1862.16, 754.263, 0, 'HoR WP LichKing'),
(37226, 49, 5417.21, 1851.7, 755.507, 0, 'HoR WP LichKing'),
(37226, 50, 5408.94, 1838.38, 757.002, 0, 'HoR WP LichKing'),
(37226, 51, 5398.8, 1829.61, 757.742, 0, 'HoR WP LichKing'),
(37226, 52, 5388.47, 1817.95, 759.285, 0, 'HoR WP LichKing'),
(37226, 53, 5378.23, 1808.5, 760.316, 0, 'HoR WP LichKing'),
(37226, 54, 5368.5, 1801.35, 760.845, 0, 'HoR WP LichKing'),
(37226, 55, 5360.86, 1793.16, 762.271, 0, 'HoR WP LichKing'),
(37226, 56, 5353.62, 1785.4, 763.868, 0, 'HoR WP LichKing'),
(37226, 57, 5344.78, 1776.09, 765.759, 0, 'HoR WP LichKing'),
(37226, 58, 5336.38, 1768.67, 767.324, 0, 'HoR WP LichKing'),
(37226, 59, 5327.56, 1760.12, 769.332, 0, 'HoR WP LichKing'),
(37226, 60, 5319.62, 1750.7, 771.487, 0, 'HoR WP LichKing'),
(37226, 61, 5313.12, 1742.99, 773.424, 0, 'HoR WP LichKing'),
(37226, 62, 5305.41, 1735.79, 775.473, 0, 'HoR WP LichKing'),
(37226, 63, 5298.93, 1728.16, 777.573, 0, 'HoR WP LichKing'),
(37226, 64, 5292.54, 1720.37, 779.862, 0, 'HoR WP LichKing'),
(37226, 65, 5287.11, 1713.96, 781.667, 0, 'HoR WP LichKing'),
(37226, 66, 5280.14, 1705.21, 784.65, 0, 'HoR WP LichKing'),
(37226, 67, 5277.98, 1701.28, 785.224, 0, 'HoR WP LichKing');

-- Fix ice wall gobjects
DELETE FROM `gameobject_template` WHERE `entry` =201385;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES ('201385', '0', '9214', 'Ice Wall', '', '', '', '1375', '1', '2.5', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '12340');
DELETE FROM `gameobject_template` WHERE `entry` =201885;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES ('201885', '0', '9214', 'Ice Wall', '', '', '', '0', '1', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '12340');
DELETE FROM `gameobject_template` WHERE `entry` =202396;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES ('202396', '0', '9214', 'Ice Wall', '', '', '', '114', '33', '2', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '12340');
DELETE FROM `gameobject_template` WHERE `entry` =500001;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES ('500001', '0', '9214', 'Ice Wall', '', '', '', '1375', '1', '2.5', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '1');
DELETE FROM `gameobject_template` WHERE `entry` =201596; -- Cave
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES ('201596', '0', '9223', 'Cave In', '', '', '', '1375', '4', '2', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '', '', '12340');
-- Gunship models
DELETE FROM `gameobject_template` WHERE `entry` IN (201709, 500002, 202211, 500003);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(201709, 5, 9288, 'Gunship Stairs', '', '', '', 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(202211, 5, 9289, 'Gunship Stairs', '', '', '', 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(500002, 14, 9150, 'The Skybreaker', '', '', '', 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1),
(500003, 14, 8253, 'Orgrim''s Hammer', '', '', '', 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);
-- Spawn Ships
DELETE FROM `gameobject` WHERE `id` IN (201709, 500002, 202211, 500003);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(150180, 202211, 631, 15, 1, -437.351, 1979.57, 190.897, 0, 0, 0, 0, 1, 6000, 100, 1),
(150185, 202211, 631, 15, 1, -437.564, 1959.54, 203.37, 0, 0, 0, 0, 1, 6000, 100, 1),
(153019, 500002, 668, 3, 1, 5247.09, 1586.39, 773.922, 5.86166, 0, 0, 0.209207, -0.977871, 300, 0, 1),
(153020, 500003, 668, 3, 1, 5245.17, 1582.11, 761.72, 5.86166, 0, 0, 0.209207, -0.977871, 300, 0, 1);

-- Spawn Gobject
DELETE FROM `gameobject` WHERE `id` IN ( 201385, 201885, 202396, 500001, 201596, 201709, 500002, 202211, 500003, 202079, 202212, 201710, 202337, 202336 );
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(121712, 202396, 631, 15, 1, 4309.69, 2491.27, 211.171, 0.209439, 0, 0, 0, 0, 120, 0, 0),
(150180, 202211, 631, 15, 1, -437.351, 1979.57, 190.897, 0, 0, 0, 0, 1, 6000, 100, 1),
(150185, 202211, 631, 15, 1, -437.564, 1959.54, 203.37, 0, 0, 0, 0, 1, 6000, 100, 1),
(150335, 202079, 631, 15, 1, -72.7031, 2282.45, 32.8673, -1.5708, 0, 0, 0, 1, 6000, 100, 1),
(153005, 201596, 668, 3, 1, 5275.28, 1694.23, 786.147, 0.981225, 0, 0, 0.471166, 0.882044, 25, 0, 0),
(153006, 500001, 668, 3, 1, 5323.61, 1755.85, 770.305, 0.784186, 0, 0, 0.382124, 0.924111, 604800, 100, 0),
(153009, 202396, 668, 3, 1, 5434.27, 1881.12, 751.303, 0.923328, 0, 0, 0.445439, 0.895312, 604800, 100, 0),
(153010, 201885, 668, 3, 1, 5494.3, 1978.27, 736.689, 1.0885, 0, 0, 0.517777, 0.855516, 604800, 100, 0),
(153015, 201385, 668, 3, 1, 5540.39, 2086.48, 731.066, 1.00057, 0, 0, 0.479677, 0.877445, 604800, 100, 0),
(153016, 202337, 668, 2, 1, 5252.33, 1585.36, 796.062, 2.80195, 0, 0, 0.985615, 0.169007, 604800, 100, 1),
(153017, 202336, 668, 2, 1, 5264.22, 1584.94, 794.359, 2.70142, 0, 0, 0.975878, 0.218315, 604800, 100, 1),
(153018, 202079, 668, 3, 1, 5248.58, 1574.22, 795.209, 0, 0, 0, 0, 1, 604800, 100, 1),
(153019, 500002, 668, 3, 1, 5247.09, 1586.39, 773.922, 5.86166, 0, 0, 0.209207, -0.977871, 300, 0, 1),
(153020, 500003, 668, 3, 1, 5245.17, 1582.11, 761.72, 5.86166, 0, 0, 0.209207, -0.977871, 300, 0, 1),
(153021, 202212, 668, 1, 1, 5253.03, 1585.13, 796.089, 2.75698, 0, 0, 0.981566, 0.191121, 300, 0, 1),
(153022, 201710, 668, 1, 1, 5262.5, 1582.41, 794.342, 2.75698, 0, 0, 0.981566, 0.191121, 300, 0, 1);
-- LK adds
DELETE FROM `creature_template` WHERE `entry` IN (37014, 36940, 36941, 37069, 37550, 37551, 37549);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(36940, 37550, 0, 0, 0, 0, 24993, 0, 0, 0, 'Raging Ghoul', '', '', 0, 80, 80, 2, 1771, 1771, 0, 2, 1.42857, 1, 0, 422, 586, 0, 642, 1, 2000, 0, 1, 0, 8, 0, 0, 0, 0, 0, 345, 509, 103, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 151, 1, 0, 8388624, 0, 'npc_raging_gnoul', 12340),
(36941, 37551, 0, 0, 0, 0, 25245, 0, 0, 0, 'Risen Witch Doctor', '', '', 0, 80, 80, 2, 1771, 1771, 0, 2, 1.42857, 1, 1, 417, 582, 0, 608, 7.5, 2000, 0, 2, 0, 8, 0, 0, 0, 0, 0, 341, 506, 80, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 6, 1, 1, 0, 0, 0, 0, 0, 0, 0, 151, 1, 0, 8388624, 0, 'npc_risen_witch_doctor', 12340),
(37014, 0, 0, 0, 0, 0, 169, 16925, 0, 0, 'Ice Wall Target', '', '', 0, 60, 60, 0, 114, 114, 0, 1, 0.99206, 1, 0, 2, 2, 0, 24, 1, 2000, 0, 1, 33555200, 8, 0, 0, 0, 0, 0, 1, 1, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 7, 1.35, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 128, '', 12340),
(37069, 37549, 0, 0, 0, 0, 30503, 0, 0, 0, 'Lumbering Abomination', '', '', 0, 80, 80, 2, 1771, 1771, 0, 1, 1.14286, 1, 1, 422, 586, 0, 642, 7.5, 2000, 0, 1, 0, 8, 0, 0, 0, 0, 0, 345, 509, 103, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 10, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8388624, 0, 'npc_abon', 12340),
(37549, 0, 0, 0, 37069, 0, 30503, 0, 0, 0, 'Lumbering Abomination (1)', '', '', 0, 80, 80, 2, 1771, 1771, 0, 1, 1.14286, 1, 1, 422, 586, 0, 642, 13, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 345, 509, 103, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8388624, 0, '', 12340),
(37550, 0, 0, 0, 36940, 0, 24993, 0, 0, 0, 'Raging Ghoul (1)', '', '', 0, 80, 80, 2, 1771, 1771, 0, 2, 1.42857, 1, 0, 422, 586, 0, 642, 1, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 345, 509, 103, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1.5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 151, 1, 0, 8388624, 0, '', 12340),
(37551, 0, 0, 0, 36941, 0, 25245, 0, 0, 0, 'Risen Witch Doctor (1)', '', '', 0, 80, 80, 2, 1771, 1771, 0, 2, 1.42857, 1, 1, 417, 582, 0, 608, 13, 0, 0, 2, 0, 8, 0, 0, 0, 0, 0, 341, 506, 80, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 7.5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 151, 1, 0, 8388624, 0, '', 12340);
-- Correct spawn
DELETE FROM `creature` WHERE `id` =37223;
DELETE FROM `creature` WHERE `id` =37221;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES ('2022910', '37221', '668', '3', '1', '0', '0', '5236.67', '1929.91', '707.695', '0.837758', '604800', '0', '0', '5040000', '881400', '0', '0', '0', '0');
-- Normal loot
DELETE FROM `gameobject_loot_template` WHERE `entry` =27985;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(27985, 43102, 100, 1, 0, 1, 1),
(27985, 47241, 100, 1, 0, 2, 2),
(27985, 100000, 100, 1, 1, -100000, 2);
DELETE FROM `reference_loot_template` WHERE `entry` =100000;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(100000, 49839, 0, 1, 1, 1, 1),
(100000, 49840, 0, 1, 1, 1, 1),
(100000, 49841, 0, 1, 1, 1, 1),
(100000, 49842, 0, 1, 1, 1, 1),
(100000, 49843, 0, 1, 1, 1, 1),
(100000, 49844, 0, 1, 1, 1, 1),
(100000, 49845, 0, 1, 1, 1, 1),
(100000, 49846, 0, 1, 1, 1, 1),
(100000, 49847, 0, 1, 1, 1, 1),
(100000, 49848, 0, 1, 1, 1, 1),
(100000, 49849, 0, 1, 1, 1, 1),
(100000, 49851, 0, 1, 1, 1, 1);
-- Heroic Loot
DELETE FROM `gameobject_loot_template` WHERE `entry` =27993;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(27993, 43102, 100, 1, 0, 1, 1),
(27993, 47241, 100, 1, 0, 2, 2),
(27993, 100000, 100, 1, 1, -100001, 2);
DELETE FROM `reference_loot_template` WHERE `entry` =100001;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(100001, 50302, 0, 1, 1, 1, 1),
(100001, 50303, 0, 1, 1, 1, 1),
(100001, 50304, 0, 1, 1, 1, 1),
(100001, 50305, 0, 1, 1, 1, 1),
(100001, 50306, 0, 1, 1, 1, 1),
(100001, 50308, 0, 1, 1, 1, 1),
(100001, 50309, 0, 1, 1, 1, 1),
(100001, 50310, 0, 1, 1, 1, 1),
(100001, 50311, 0, 1, 1, 1, 1),
(100001, 50312, 0, 1, 1, 1, 1),
(100001, 50313, 0, 1, 1, 1, 1),
(100001, 50314, 0, 1, 1, 1, 1);
-- Fix portal spell
UPDATE `gameobject_template` SET `data0`='53141' WHERE `entry`=202079;

-- Creature Text
DELETE FROM `creature_text` WHERE `entry` IN (37221, 37225, 37223, 36954, 38112, 38113, 36955, 37554, 37226, 36723, 37182, 37833, 38177, 38173, 38176, 38175, 38172);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37221, 0, 0, "The chill of this place... Brr... I can feel my blood freezing.", 14, 0, 10, 0, 0, 16631, "Jaina HoR Alliance Intro 1"),
(37221, 1, 0, "What is that! Up ahead! Could it be? Heroes, at my side!", 14, 0, 10, 0, 0, 16632, "Jaina HoR Alliance Intro 2"),
(37221, 2, 0, "Frostmourne: the blade that destroyed our kingdom...", 14, 0, 10, 0, 0, 16633, "Jaina HoR Alliance Intro 3"),
(37221, 3, 0, "Stand back! Touch that blade and your soul will be scarred for all eternity! I must attempt to commune with the spirits locked away within Frostmourne. Give me space. Back up, please.", 14, 0, 10, 0, 0, 16634, "Jaina HoR Alliance Intro 4"),
(37225, 0, 0, "Jaina! Could it truly be you?", 12, 0, 10, 0, 0, 16666, "Uther HoR Alliance Intro 5"),
(37221, 4, 0, "Uther! Dear Uther! I... I'm so sorry.", 12, 0, 10, 0, 0, 16635, "Jaina HoR Alliance Intro 6"),
(37225, 1, 0, "Jaina you haven't much time. The Lich King sees what the sword sees. He will be here shortly!", 12, 0, 10, 0, 0, 16667, "Uther HoR Alliance Intro 7"),
(37221, 5, 0, "Arthas is here? Maybe I...", 12, 0, 10, 0, 0, 16636, "Jaina HoR Alliance Intro 8"),
(37225, 2, 0, "No, girl. Arthas is not here. Arthas is merely a presence within the Lich King's mind. A dwindling presence...", 12, 0, 10, 0, 0, 16668, "Uther HoR Alliance Intro 9"),
(37221, 6, 0, "But Uther, if there's any hope of reaching Arthas. I... I must try.", 12, 0, 10, 0, 0, 16637, "Jaina HoR Alliance Intro 10"),
(37225, 3, 0, "Jaina, listen to me. You must destroy the Lich King. You cannot reason with him. He will kill you and your allies and raise you all as powerful soldiers of the Scourge.", 12, 0, 10, 0, 0, 16669, "Uther HoR Alliance Intro 11"),
(37221, 7, 0, "Tell me how, Uther? How do I destroy my prince? My...", 12, 0, 10, 0, 0, 16638, "Jaina HoR Alliance Intro 12"),
(37225, 4, 0, "Snap out of it, girl. You must destroy the Lich King at the place where he merged with Ner'zhul - atop the spire, at the Frozen Throne. It is the only way.", 12, 0, 10, 0, 0, 16670, "Uther HoR Alliance Intro 13"),
(37221, 8, 0, "You're right, Uther. Forgive me. I... I don't know what got a hold of me. We will deliver this information to the King and the knights that battle the Scourge within Icecrown Citadel.", 12, 0, 10, 0, 0, 16639, "Jaina HoR Alliance Intro 14"),
(37225, 5, 0, "There is... something else that you should know about the Lich King. Control over the Scourge must never be lost. Even if you were to strike down the Lich King, another would have to take his place. For without the control of its master, the Scourge would run rampant across the world - destroying all living things.", 12, 0, 10, 0, 0, 16671, "Uther HoR Alliance Intro 15"),
(37225, 6, 0, "A grand sacrifice by a noble soul...", 12, 0, 10, 0, 0, 16672, "Uther HoR Alliance Intro 16"),
(37221, 9, 0, "Who could bear such a burden?", 12, 0, 10, 0, 0, 16640, "Jaina HoR Alliance Intro 17"),
(37225, 7, 0, "I do not know, Jaina. I suspect that the piece of Arthas that might be left inside the Lich King is all that holds the Scourge from annihilating Azeroth.", 12, 0, 10, 0, 0, 16673, "Uther HoR Alliance Intro 18"),
(37221, 10, 0, "Then maybe there is still hope...", 12, 0, 10, 0, 0, 16641, "Jaina HoR Alliance Intro 19"),
(37225, 8, 0, "No, Jaina! ARRRRRRGHHHH... He... He is coming. You... You must...", 12, 0, 10, 0, 0, 16674, "Uther HoR Alliance Intro 20"),
(37223, 0, 0, "I... I don't believe it! Frostmourne stands before us, unguarded! Just as the Gnome claimed. Come, heroes!", 14, 0, 10, 0, 0, 17049, "Sylvanas HoR Horde Intro 1"),
(37223, 1, 0, "Standing this close to the blade that ended my life... The pain... It is renewed.", 14, 0, 10, 0, 0, 17050, "Sylvanas HoR Horde Intro 2"),
(37223, 2, 0, "I dare not touch it. Stand back! Stand back as I attempt to commune with the blade! Perhaps our salvation lies within...", 14, 0, 10, 0, 0, 17051, "Sylvanas HoR Horde Intro 3"),
(37225, 9, 0, "Careful, girl. I've heard talk of that cursed blade saving us before. Look around you and see what has been born of Frostmourne.", 12, 0, 10, 0, 0, 16659, "Uther HoR Horde Intro 4"),
(37223, 3, 0, "Uther...Uther the Lightbringer. How...", 12, 0, 10, 0, 0, 17052, "Sylvanas HoR Horde Intro 5"),
(37225, 10, 0, "You haven't much time. The Lich King sees what the sword sees. He will be here shortly.", 12, 0, 10, 0, 0, 16660, "Uther HoR Horde Intro 6"),
(37223, 4, 0, "The Lich King is here? Then my destiny shall be fulfilled today!", 12, 0, 10, 0, 0, 17053, "Sylvanas HoR Horde Intro 7"),
(37225, 11, 0, "You cannot defeat the Lich King. Not here. You would be a fool to try. He will kill those who follow you and raise them as powerful servants of the Scourge. But for you, Sylvanas, his reward for you would be worse than the last.", 12, 0, 10, 0, 0, 16661, "Uther HoR Horde Intro 8"),
(37223, 5, 0, "There must be a way... ", 12, 0, 10, 0, 0, 17054, "Sylvanas HoR Horde Intro 9"),
(37225, 12, 0, "Perhaps, but know this: there must always be a Lich King. Even if you were to strike down Arthas, another would have to take his place, for without the control of the Lich King, the Scourge would wash over this world like locusts, destroying all that they touched.", 12, 0, 10, 0, 0, 16662, "Uther HoR Horde Intro 10"),
(37223, 6, 0, "Who could bear such a burden?", 12, 0, 10, 0, 0, 17055, "Sylvanas HoR Horde Intro 11"),
(37225, 13, 0, "I do not know, Banshee Queen. I suspect that the piece of Arthas that might be left inside the Lich King is all that holds the Scourge from annihilating Azeroth.", 12, 0, 10, 0, 0, 16663, "Uther HoR Horde Intro 12"),
(37225, 14, 0, "Alas, the only way to defeat the Lich King is to destroy him at the place he was created.", 12, 0, 10, 0, 0, 16664, "Uther HoR Horde Intro 13"),
(37223, 7, 0, "The Frozen Throne...", 12, 0, 10, 0, 0, 17056, "Sylvanas HoR Horde Intro 14"),
(37225, 15, 0, "Aye. ARRRRRRGHHHH... He... He is coming. You... You must...", 12, 0, 10, 0, 0, 16665, "Uther HoR Horde Intro 15"),
(36954, 0, 0, "SILENCE, PALADIN!", 14, 0, 10, 0, 0, 17225, "HoR Intro LK 1"),
(36954, 1, 0, "So you wish to commune with the dead? You shall have your wish.", 14, 0, 10, 0, 0, 17226, "HoR Intro LK 2"),
(36954, 2, 0, "Falric. Marwyn. Bring their corpses to my chamber when you are through.", 14, 0, 10, 0, 0, 17227, "HoR Intro LK 3"),
(38112, 5, 0, "As you wish, my lord.", 14, 0, 10, 0, 0, 16717, "HoR Intro LK 4"),
(38113, 5, 0, "As you wish, my lord.", 14, 0, 10, 0, 0, 16741, "HoR Intro LK 5"),
(38112, 6, 0, "Soldiers of Lordaeron, rise to meet your master's call!", 14, 0, 10, 0, 0, 16714, "HoR Intro LK 6"),
(37221, 11, 0, "You won't deny me this Arthas! I must know! I must find out!", 14, 0, 10, 0, 0, 16642, "HoR Alliance Intro 20"),
(37223, 8, 0, "You will not escape me that easily, Arthas! I will have my vengeance!", 12, 0, 10, 0, 0, 17057, "Sylvanas HoR Horde Intro 16"),
(36954, 3, 0, "Foolish girl, you seek that which I killed long ago. He is merely a ghost now, a faint echo in my mind.", 14, 0, 10, 0, 0, 17229, "HoR Intro LK 7 Alliance"),
(36954, 4, 0, "I will not make the same mistake again Sylvanas, this time there will be no escape. You failed to serve me in undeath, now all that remains for you is oblivion.", 14, 0, 10, 0, 0, 17228, "HoR Intro LK 7 Horde"),
(37226, 0, 0, "Your allies have arrived, Jaina, just as you promised. You will all become powerful agents of the Scourge.", 14, 0, 10, 0, 0, 17212, "HoR Escape Alliance 1"),
(37226, 1, 0, "I will not make the same mistake again, Sylvanas. This time there will be no escape. You will all serve me in death!", 14, 0, 10, 0, 0, 17213, "HoR Escape Horde 1"),
(36955, 0, 0, "He is too powerful, we must leave this place at once! My magic will hold him in place for only a short time! Come quickly, heroes!", 14, 0, 10, 0, 0, 16644, "HoR Escape Alliance 2"),
(37554, 0, 0, "He's too powerful! Heroes, quickly, come to me! We must leave this place immediately! I will do what I can do hold him in place while we flee.", 14, 0, 10, 0, 0, 17058, "HoR Escape Horde 2"),
(36955, 1, 0, "I will destroy this barrier. You must hold the undead back!", 14, 0, 10, 0, 0, 16607, "HoR Escape Alliance 3 Wall 1"),
(37554, 1, 0, "No wall can hold the Banshee Queen! Keep the undead at bay, heroes! I will tear this barrier down!", 14, 0, 10, 0, 0, 17029, "HoR Escape Horde 3 Wall 1"),
(37226, 2, 0, "Succumb to the chill of the grave.", 14, 0, 10, 0, 0, 17218, "HoR Escape 4 LK"),
(36955, 2, 0, "Another ice wall! Keep the undead from interrupting my incantation so that I may bring this wall down!", 14, 0, 10, 0, 0, 16608, "HoR Escape Alliance 5 Wall 2"),
(37554, 2, 0, "Another barrier? Stand strong, champions! I will bring the wall down!", 14, 0, 10, 0, 0, 17030, "HoR Escape Horde 5 Wall 2"),
(37226, 3, 0, "Another dead end.", 14, 0, 10, 0, 0, 17219, "HoR Escape 6 LK"),
(36955, 3, 0, "He's playing with us! I'll show him what happens to ice when it meets fire!", 14, 0, 10, 0, 0, 16609, "HoR Escape Alliance 7 Wall 3"),
(37554, 3, 0, "I grow tired of these games, Arthas! Your walls can't stop me!", 14, 0, 10, 0, 0, 17031, "HoR Escape Horde 7 Wall 3"),
(37226, 4, 0, "How long can you fight it?", 14, 0, 10, 0, 0, 17220, "HoR Escape 8 LK"),
(36955, 4, 0, "Your barriers can't hold us back much longer, monster. I will shatter them all!", 14, 0, 10, 0, 0, 16610, "HoR Escape Alliance 9 Wall 4"),
(37554, 4, 0, "You won't impede our escape, fiend. Keep the undead off me while I bring this barrier down!", 14, 0, 10, 0, 0, 17032, "HoR Escape Horde 9 Wall 4"),
(36955, 5, 0, "There's an opening up ahead. GO NOW!", 14, 0, 10, 0, 0, 16645, "HoR Escape Alliance 10"),
(37554, 5, 0, "There's an opening up ahead. GO NOW!", 14, 0, 10, 0, 0, 17059, "HoR Escape Horde 10"),
(36955, 6, 0, "We're almost there... Don't give up!", 14, 0, 10, 0, 0, 16646, "HoR Escape Alliance 11"),
(37554, 6, 0, "We're almost there... Don't give up!", 14, 0, 10, 0, 0, 17060, "HoR Escape Horde 11"),
(36955, 7, 0, "It... It's a dead end. We have no choice but to fight. Steel yourself heroes, for this is our last stand!", 14, 0, 10, 0, 0, 16647, "HoR Escape Alliance 12"),
(37554, 7, 0, "BLASTED DEAD END! So this is how it ends. Prepare yourselves, heroes, for today we make our final stand!", 14, 0, 10, 0, 0, 17061, "HoR Escape Horde 12"),
(37182, 0, 0, "Fire! FIRE!", 14, 0, 10, 0, 0, 16721, "HoR Escape Alliance 14"),
(37833, 0, 0, "Fire! FIRE!", 14, 0, 10, 0, 0, 16732, "HoR Escape Horde 14"),
(37182, 1, 0, "Quickly, climb aboard! We mustn't tarry here! There's no telling when this whole mountainside will collapse.", 14, 0, 10, 0, 0, 16722, "HoR Escape Alliance 15"),
(37833, 1, 0, "Get onboard, now! This whole mountainside could collapse at any moment.", 14, 0, 10, 0, 0, 16733, "HoR Escape Horde 15"),
(36955, 8, 0, "Forgive me, heroes. I should have listened to Uther. I... I just had to see for myself. To look into his eyes one last time. I am sorry.", 14, 0, 10, 0, 0, 16648, "HoR Escape Alliance 16"),
(37554, 8, 0, " We are safe, for now. His strength has increased ten-fold since our last battle! It will take a mighty army to destroy the Lich King, an army greater than even the Horde can rouse.", 14, 0, 10, 0, 0, 17062, "HoR Escape Horde 16"),
(36955, 9, 0, "We now know what must be done. I will deliver this news to King Varian and Highlord Fordring.", 14, 0, 10, 0, 0, 16649, "HoR Escape Alliance 16"),
(37226, 5, 0, "There is no escape!", 14, 0, 10, 0, 0, 17217, "boss_the_lich_king_hor 1"),
(37226, 6, 0, "Succumb to the chill of the grave.", 14, 0, 10, 0, 0, 17218, "boss_the_lich_king_hor 2"),
(37226, 7, 0, "Rise minions, do not left them us!", 14, 0, 10, 0, 0, 17216, "boss_the_lich_king_hor 3"),
(37226, 8, 0, "Minions seize them.  Bring their corpses back to me!", 14, 0, 10, 0, 0, 17222, "boss_the_lich_king_hor 4"),
(37226, 9, 0, "Death's cold embrace awaits.", 14, 0, 10, 0, 0, 17221, "boss_the_lich_king_hor 5"),
(37226, 10, 0, "Nowhere to run! You're mine now...", 14, 0, 10, 0, 0, 17223, "boss_the_lich_king_hor 6"),
(37226, 11, 0, "All is lost!", 14, 0, 10, 0, 0, 17215, "boss_the_lich_king_hor wipe"),
(38112, 0, 0, "Men, women and children... None were spared the master's wrath. Your death will be no different.", 14, 0, 10, 0, 0, 16710, "HoR Falric Aggro"),
(38112, 1, 0, "Sniveling maggot!", 14, 0, 10, 0, 0, 16711, "HoR Falric Slay 1"),
(38112, 1, 1, "The children of Stratholme fought with more ferocity!", 14, 0, 10, 0, 0, 16712, "HoR Falric Slay 2"),
(38112, 2, 0, "Despair... so delicious...", 14, 0, 10, 0, 0, 16715, "HoR Falric Impending Despair"),
(38112, 3, 0, "Fear... so exhilarating...", 14, 0, 10, 0, 0, 16716, "HoR Falric Defiling Horor"),
(38112, 4, 0, "Marwyn, finish them...", 14, 0, 10, 0, 0, 16713, "HoR Falric Death"),
(38113, 0, 0, "Death is all that you will find here!", 14, 0, 10, 0, 0, 16734, "HoR Marwyn Aggro"),
(38113, 1, 0, "I saw the same look in his eyes when he died. Terenas could hardly believe it. Hahahaha!", 14, 0, 10, 0, 0, 16735, "HoR Marwyn Slay 1"),
(38113, 1, 1, "Choke on your suffering!", 14, 0, 10, 0, 0, 16736, "HoR Marwyn Slay 2"),
(38113, 2, 0, "Your flesh has decayed before your very eyes!", 14, 0, 10, 0, 0, 16739, "HoR Marwyn Corrupted Flesh"),
(38113, 3, 0, "Waste away into nothingness!", 14, 0, 10, 0, 0, 16734, "HoR Marwyn Well of Corruption"),
(38113, 4, 0, "Yes... Run... Run to meet your destiny... Its bitter, cold embrace, awaits you.", 14, 0, 10, 0, 0, 16737, "HoR Marwyn Death"),
(36723, 0, 0, "You are not worthy to face the Lich King!", 14, 0, 10, 0, 0, 16921, "HoR FrostSworn General Aggro"),
(36723, 1, 0, "Master, I have failed...", 14, 0, 10, 0, 0, 16922, "HoR FrostSworn General Death"),
(38177, 0, 0, 'This is not our final rest.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38173, 0, 0, 'This is not our final rest.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38176, 0, 0, 'This is not our final rest.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38175, 0, 0, 'This is not our final rest.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38172, 0, 0, 'This is not our final rest.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38177, 0, 1, 'All serve the master in death.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38173, 0, 1, 'All serve the master in death.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38176, 0, 1, 'All serve the master in death.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38175, 0, 1, 'All serve the master in death.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38172, 0, 1, 'All serve the master in death.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38177, 0, 2, 'Our souls will never be freed.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38173, 0, 2, 'Our souls will never be freed.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38176, 0, 2, 'Our souls will never be freed.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38175, 0, 2, 'Our souls will never be freed.', 12, 0, 10, 0, 0, 0, 'HoR Trash death'),
(38172, 0, 2, 'Our souls will never be freed.', 12, 0, 10, 0, 0, 0, 'HoR Trash death');
