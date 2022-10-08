-- new cache version
update `version` set cache_id = cache_id + 1;

-- Start HardFix
UPDATE `quest_template` SET Level = -1 WHERE `ZoneOrSort` = 4714;

-- Fix PhaseShift poi
UPDATE `quest_poi` SET WorldMapAreaId = 545 WHERE `mapid` = 654;

-- Journeyman Riding learned with Running Wild
DELETE FROM `spell_learn_spell` WHERE `entry` = 87840;
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`, `ReqSpell`, `Active`) VALUES 
('87840', '33391', '0', '1');

-- Visual. q14094. Conteiner beam
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 46896;

-- --------------------------------------
-- QUEST_SACRIFICES Q14212
-- -------------------------------------- 

-- Hource summon
-- UPDATE `quest_template` SET `SourceSpellId` = '67766' WHERE `Id` =14212;
-- Hource wp
DELETE FROM `script_waypoint` WHERE `entry` = 35231;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(35231, 1, -1733.16, 1657.12, 20.487, 0, NULL),
(35231, 2, -1708.57, 1668.38, 20.603, 0, NULL),
(35231, 3, -1672.35, 1654.15, 20.4894, 0, NULL),
(35231, 4, -1667.97, 1621.56, 20.4894, 0, NULL),
(35231, 5, -1695.44, 1613.45, 20.4894, 0, NULL),
(35231, 6, -1706.51, 1635.75, 20.4894, 0, NULL),
(35231, 7, -1695.11, 1672.98, 20.6713, 0, NULL),
(35231, 8, -1672.25, 1704.1, 20.4989, 0, NULL),
(35231, 9, -1647.89, 1709.19, 20.4978, 0, NULL),
(35231, 10, -1610.74, 1711.23, 22.6819, 0, NULL),
(35231, 11, -1559.29, 1707.9, 20.4853, 0, NULL),
(35231, 12, -1541.24, 1635.49, 21.23, 0, NULL),
(35231, 13, -1516.68, 1622.81, 20.4866, 0, NULL),
(35231, 14, -1441.73, 1629.45, 20.4866, 0, NULL),
(35231, 15, -1423.11, 1603.72, 20.4866, 0, NULL),
(35231, 16, -1416.55, 1583.68, 20.485, 0, NULL),
(35231, 17, -1447.75, 1538.23, 20.4857, 0, NULL),
(35231, 18, -1465.08, 1533.48, 20.4857, 0, NULL),
(35231, 19, -1500.87, 1564.68, 20.4867, 0, NULL),
(35231, 20, -1536.46, 1579.09, 27.7734, 0, NULL),
(35231, 21, -1542.2, 1573.9, 29.2055, 0, NULL);

-- Q14348
UPDATE `quest_template` SET `RequiredSourceItemId1` = '49202', `RequiredSourceItemCount1` = '4' WHERE `Id` = 14348;

-- Leader of the Pack Q14386  -- PhaseShift
DELETE FROM phase_definitions WHERE `zoneId` = 4714 AND entry = 1;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `wmAreaId`, `comment`) VALUES
(4714, 1, 1, 182, 655, 678, 'Worgen Bracke Islands');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 4714;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(23, 4714, 1, 0, 0, 28, 0, 14386, 0, 0, 0, 0, '', NULL),
(23, 4714, 1, 0, 1, 8, 0, 14386, 0, 0, 0, 0, '', NULL),
(23, 4714, 1, 0, 2, 14, 0, 14466, 0, 0, 0, 0, '', NULL);

-- Q14404
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 49337;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 49338;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 49339;

-- The Hungry Ettin Q14416
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36540;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('36540', '43671', '1', '0');

-- Q14400
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 49279;

-- Q14401
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 49281;

-- The King's Observatory Q14466
DELETE FROM phase_definitions WHERE `zoneId` = 4714 AND entry = 2;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `wmAreaId`, `comment`) VALUES
(4714, 2, 1, 186, 656, 679, 'Worgen Bracke Islands p.2');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 4714 AND SourceEntry = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(23, 4714, 2, 0, 0, 28, 0, 14466, 0, 0, 0, 0, '', NULL),
(23, 4714, 2, 0, 1, 8, 0, 14466, 0, 0, 0, 0, '', NULL);

-- Q24628
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 50017;

-- Q24646
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 50086;

-- Slowing the Inevitable Q24920
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 38615;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('38615', '72472', '3', '0');
UPDATE `creature_template` SET `npcflag` = '16777216', `VehicleId` = '641', `spell1` = '72246', `spell2` = '72849', `InhabitType` = '4', `ScriptName` = 'npc_captured_riding_bat' WHERE `entry` = 38540;
DELETE FROM `script_waypoint` WHERE `entry` = 38540;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
-- go to battle
(38540, 1, -1663.25, 1621.879, 25.96168, 0, NULL),
(38540, 2, -1637.625, 1617.241, 33.15612, 0, NULL),
(38540, 3, -1595.771, 1606.172, 44.07281, 0, NULL),
(38540, 4, -1545.931, 1598.307, 44.07281, 0, NULL),
(38540, 5, -1448.483, 1587.66, 44.07281, 0, NULL),
(38540, 6, -1395.726, 1615.543, 44.07281, 0, NULL),
(38540, 7, -1319.311, 1680.958, 44.07281, 0, NULL),
-- should be cycle
(38540, 8, -1241.325, 1747.767, 53.76252, 0, NULL),
(38540, 9, -1186.814, 1708.936, 53.76252, 0, NULL),
(38540, 10, -1107.872, 1646.177, 53.76252, 0, NULL),
(38540, 11, -1056.335, 1608.783, 53.76252, 0, NULL),
(38540, 12, -984.1858, 1623.411, 64.90141, 0, NULL),
(38540, 13, -960.5712, 1668.052, 69.84588, 0, NULL),
(38540, 14, -919.2639, 1708.543, 90.70698, 0, NULL),
(38540, 15, -859.6215, 1700.193, 90.70698, 0, NULL),
(38540, 16, -864.6215, 1626.049, 90.70698, 0, NULL),
(38540, 17, -887.007, 1510.622, 90.70698, 0, NULL),
(38540, 18, -950.3246, 1506.309, 82.34586, 0, NULL),
(38540, 19, -1025.245, 1428.929, 74.51246, 0, NULL),
(38540, 20, -1077.819, 1401.005, 58.4569, 0, NULL),
(38540, 21, -1143.061, 1407.379, 51.04022, 0, NULL),
(38540, 22, -1197.042, 1471.483, 47.34577, 0, NULL),
(38540, 23, -1269.991, 1510.726, 47.34577, 0, NULL),
(38540, 24, -1352.618, 1566.734, 47.34577, 0, NULL),
(38540, 25, -1379.911, 1681.13, 47.34577, 0, NULL),
(38540, 26, -1304.021, 1763.345, 54.04024, 0, NULL),
(38540, 27, -1277.788, 1762.722, 55.95692, 0, NULL),
-- back waypoint
(38540, 28, -1304.236, 1650.365, 64.76084, 0, NULL),
(38540, 29, -1410.293, 1638.58, 37.38527, 0, NULL),
(38540, 30, -1491.441, 1632.97, 32.0797, 0, NULL),
(38540, 31, -1578.608, 1633.108, 32.0797, 0, NULL),
(38540, 32, -1621.252, 1625.786, 29.66303, 0, NULL),
(38540, 33, -1637.115, 1616.464, 28.71857, 0, NULL),
(38540, 34, -1657.575, 1619.925, 25.35749, 0, NULL),
(38540, 35, -1665.67, 1630.521, 25.35749, 0, NULL),
(38540, 36, -1667.727, 1662.474, 22.60748, 0, NULL);

-- Laid to Rest Q24602 
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance` = '-100' WHERE `item` = 49921;


-- They Have Allies, But So Do We Q24681
-- 38150 -> 37927
UPDATE `creature_template` SET `npcflag` = '16777216' WHERE entry = 38150;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 38150;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES ('38150', '71238', '3', '0');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 71238;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('18', '38150', '71238', '0', '0', '9', '0', '24681', '0', '0', '0', '0', '', NULL);
UPDATE `creature_template` SET `npcflag` = '16777216', `VehicleId` = '866', `spell1` = '70735', `spell2` = '70732', `spell4` = '59737' WHERE entry = 37927;