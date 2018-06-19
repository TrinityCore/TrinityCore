
 --       AshamaneCore        --
-- // World update 0.2 by Nexon // --
  --       Legion 7.2.5        --

  
-- Table `creature_template`
UPDATE `creature_template` SET `DamageModifier` = 4.5 WHERE (entry = 1850);
UPDATE `creature_template` SET `DamageModifier` = 3.5 WHERE (entry = 50737);
UPDATE `creature_template` SET `DamageModifier` = 3.5 WHERE (entry = 33497);
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE (entry = 98618);
UPDATE `creature_template` SET `faction` = 7 WHERE (entry = 100061);
UPDATE `creature_template` SET `name` = 'Jeune scrutesang', `minlevel` = 110, `maxlevel` = 110, `faction` = 14, `HealthModifier` = 0.8 WHERE (entry = 115675);
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.2 WHERE (entry = 111383);
UPDATE `creature_template` SET `MovementType` = 1, `speed_walk` = 1, `speed_run` = 1.2, `unit_flags` = 0, `type_flags` = 0 WHERE (entry = 111383);
UPDATE `creature_template` SET `name` = 'Patriarche scrutesang', `HealthModifier` = 2, `minlevel` = 110, `maxlevel` = 110, `faction` = 14, `HealthModifier` = 3 WHERE (entry = 115670);
UPDATE `creature_template` SET `name` = 'Matriarche scrutesang', `HealthModifier` = 4, `minlevel` = 110, `maxlevel` = 110, `faction` = 14 WHERE (entry = 115674);
UPDATE `creature_template` SET `name` = 'Nid de matriarche scrutesang', `minlevel` = 110, `maxlevel` = 110, `faction` = 7 WHERE (entry = 115922);
UPDATE `creature_template` SET `name` = 'Nid de scrutesang', `minlevel` = 110, `maxlevel` = 110, `faction` = 7 WHERE (entry = 115681);
UPDATE `creature_template` SET `name` = 'Garde-nid scrutesang', `minlevel` = 110, `maxlevel` = 110, `faction` = 14 WHERE (entry = 115666);
UPDATE `creature_template` SET `spell3` = 168167, `spell4` = 0, `spell5` = 0 WHERE (entry = 78116);
UPDATE `creature_template` SET `name` = 'Illnea Roncesang', `subname` = 'Commerce de sang', `minlevel` = 110, `maxlevel` = 110, `npcflag` = 128 WHERE (entry = 115264);
UPDATE `creature_template` SET `faction` = 7, `unit_flags` = 4  WHERE (entry = 115666);
UPDATE `creature_template` SET `unit_flags` = 4 WHERE (entry = 115922);
UPDATE `creature_template` SET `unit_flags` = 4 WHERE (entry = 115681);
UPDATE `creature_template` SET `InhabitType` = 2 WHERE (entry = 44475);
UPDATE `creature_template` SET `unit_flags` = 33685510 WHERE (entry = 86062);
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE (entry = 44316);
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE (entry = 44315);
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE (entry = 44475);
UPDATE `creature_template` SET `modelid1` = 26760, `modelid3` = 0, `modelid4` = 0, `minlevel` = 37, `maxlevel` = 37, `faction` = 14 WHERE (entry = 50778);
UPDATE `creature_template` SET `unit_flags` = 0 WHERE (entry = 45165);
UPDATE `creature_template` SET `unit_flags` = 0, `unit_flags2` = 2048 WHERE (entry = 90230);
UPDATE `creature_template` SET `unit_flags2` = 2048 WHERE (entry = 93619);
UPDATE `creature_template` SET `DamageModifier` = 0.7 WHERE (entry = 86969);
UPDATE `creature_template` SET `DamageModifier` = 0.7 WHERE (entry = 101943);
UPDATE `creature_template` SET `DamageModifier` = 0.7 WHERE (entry = 93619);
UPDATE `creature_template` SET `DamageModifier` = 0.8 WHERE (entry = 89016);




-- Table `creature` 
INSERT IGNORE INTO `creature` (`guid`, `id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUES ('20548913', '3627', '-9039.14', '877.866', '110.196', '2.04797', '300', '164');

-- Table `creature_addon` 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('177633', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('86129', '164381');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20549217', '227301');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10124404', '233');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('10124382', '1'); 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20549294', '1'); 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('212140', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('212021', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('212139', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20549387', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20549390', '234');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508287', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508287', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508260', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508250 ', '432'); 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508252', '432'); 
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20549871', '10');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508243', '11');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508276', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508381', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508699', '227301');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508678', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508676', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508713', '1');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20508666', '14915');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508630', '223977');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20508429', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20549875', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20549881', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20546621', '76701');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546621', '380');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546695', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20549903', '174794');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546675', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546662', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546664', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546658', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `auras`) VALUES ('20546729', '175959');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546729', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546705', '483');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546716', '483');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546718', '432');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546707', '37');
UPDATE `creature_addon` SET `emote` = 38 WHERE (guid = 20546706);
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546708', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546709', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546704', '461');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546700', '461');
UPDATE `creature_addon` SET `emote` = 461 WHERE (guid = 20546698);
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546786', '483');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546837', '483');
INSERT IGNORE INTO `creature_addon` (`guid`, `emote`) VALUES ('20546823', '483');


-- Table `creature_template_addon` 
UPDATE `creature_template_addon` SET `auras`='0' WHERE  `entry`= 45165;


-- Table `creature_loot_template`
DELETE FROM `creature_loot_template` WHERE (Entry = 50778);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(50778, 7430, 0, 0.19, 0, 1, 0, 1, 1, ''),
(50778, 9875, 0, 3, 0, 1, 0, 1, 1, ''),
(50778, 7454, 0, 4, 0, 1, 0, 1, 1, ''),
(50778, 7462, 0, 4, 0, 1, 0, 1, 1, ''),
(50778, 12205, 0, 51, 0, 1, 0, 1, 1, ''),
(50778, 9863, 0, 5, 0, 1, 0, 1, 1, '');

-- Table `gameobject_template`
UPDATE `gameobject_template` SET `name` = 'Salles de l\'équilibre' WHERE (entry = 259391);
UPDATE `gameobject_template` SET `name` = 'barrière invisible', `size` = 1 WHERE (entry = 259095);
UPDATE `gameobject_template` SET `name` = 'Porte domaine de classe : voleur' WHERE (entry = 251033);
UPDATE `gameobject_template` SET `name` = 'Porte de domaine de classe : Paladin' WHERE (entry = 251304);
UPDATE `gameobject_template` SET `name` = 'Domaine de classe des Paladins vers Dalaran' WHERE (entry = 251673);


-- Table `item_loot_template` 
DELETE FROM `item_loot_template` WHERE `entry`='141344';
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Groupid`, `MinCount`, `MaxCount`,`Comment`) VALUES
(141344, 139026, 4.8, 1, 0, 1, 1,''),
(141344, 139025, 14, 1, 0, 1, 1,''),
(141344, 139020, 13, 1, 0, 1, 1,''),
(141344, 139023, 12, 1, 0, 1, 1,''),
(141344, 139024, 11, 1, 0, 1, 1,''),
(141344, 139021, 12, 1, 0, 1, 1,''),
(141344, 140581, 0.04, 1, 0, 1, 1,'');

DELETE FROM `item_loot_template` WHERE `entry`='140224';
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Groupid`, `MinCount`, `MaxCount`,`Comment`) VALUES
(140224, 124115, 37, 1, 0, 10, 20,''),
(140224, 124113, 36, 1, 0, 10, 20,''),
(140224, 124117, 23, 1, 0, 10, 20,''),
(140224, 124120, 23, 1, 0, 10, 20,''),
(140224, 124119, 22, 1, 0, 10, 20,''),
(140224, 124118, 22, 1, 0, 10, 20,''),
(140224, 124121, 21, 1, 0, 10, 20,''),
(140224, 124439, 17, 1, 0, 10, 20,''),
(140224, 124438, 17, 1, 0, 10, 20,''),
(140224, 124116, 1.3, 1, 0, 1, 1,'');

DELETE FROM `item_loot_template` WHERE `entry`='140221';
REPLACE INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Groupid`, `MinCount`, `MaxCount`,`Comment`) VALUES
(140221, 129100, 49, 1, 0, 3, 9,''),
(140221, 130174, 16, 1, 0, 1, 2,''),
(140221, 130176, 16, 1, 0, 1, 2,''),
(140221, 130177, 16, 1, 0, 1, 2,''),
(140221, 130172, 16, 1, 0, 1, 2,''),
(140221, 130175, 16, 1, 0, 1, 2,''),
(140221, 130173, 15, 1, 0, 1, 2,''),
(140221, 129099, 13, 1, 0, 2, 6,''),
(140221, 130202, 12, 1, 0, 2, 6,''),
(140221, 130203, 12, 1, 0, 2, 6,''),
(140221, 130204, 12, 1, 0, 2, 6,''),
(140221, 130200, 11, 1, 0, 2, 6,''),
(140221, 130201, 11, 1, 0, 2, 6,''),
(140221, 130178, 9, 1, 0, 1, 1,''),
(140221, 130179, 9, 1, 0, 1, 1,''),
(140221, 130181, 9, 1, 0, 1, 1,''),
(140221, 130180, 8, 1, 0, 1, 1,''),
(140221, 130183, 8, 1, 0, 1, 1,''),
(140221, 130182, 8, 1, 0, 1, 1,'');

DELETE FROM `item_loot_template` WHERE `entry`='140222';
REPLACE INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Groupid`, `MinCount`, `MaxCount`,`Comment`) VALUES
(140222, 124104, 22, 1, 0, 10, 20,''),
(140222, 124105, 22, 1, 0, 2, 4,''),
(140222, 124102, 22, 1, 0, 10, 20,''),
(140222, 124103, 22, 1, 0, 10, 20,''),
(140222, 124101, 21, 1, 0, 10, 20,''),
(140222, 124112, 19, 1, 0, 10, 20,''),
(140222, 124109, 19, 1, 0, 10, 20,''),
(140222, 124107, 19, 1, 0, 10, 20,''),
(140222, 124111, 18, 1, 0, 10, 20,''),
(140222, 124108, 18, 1, 0, 10, 20,''),
(140222, 124110, 18, 1, 0, 10, 20,''),
(140222, 124106, 1, 1, 0, 1, 1,'');

DELETE FROM `item_loot_template` WHERE `entry`='140225';
REPLACE INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Groupid`, `MinCount`, `MaxCount`,`Comment`) VALUES
(140225, 123919, 48, 1, 0, 10, 20,''),
(140225, 123918, 48, 1, 0, 10, 20,''),
(140225, 124444, 1.2, 1, 0, 1, 1,''),
(140225, 121356, 2, 1, 0, 1, 1,''),
(140225, 121342, 2, 1, 0, 1, 1,''),
(140225, 121355, 2, 1, 0, 1, 1,''),
(140225, 121338, 2, 1, 0, 1, 1,''),
(140225, 121351, 2, 1, 0, 1, 1,''),
(140225, 121336, 2, 1, 0, 1, 1,''),
(140225, 121341, 2, 1, 0, 1, 1,''),
(140225, 121343, 2, 1, 0, 1, 1,''),
(140225, 121362, 2, 1, 0, 1, 1,''),
(140225, 121344, 2, 1, 0, 1, 1,''),
(140225, 121367, 2, 1, 0, 1, 1,''),
(140225, 121334, 2, 1, 0, 1, 1,''),
(140225, 121353, 2, 1, 0, 1, 1,''),
(140225, 121360, 2, 1, 0, 1, 1,''),
(140225, 121359, 2, 1, 0, 1, 1,''),
(140225, 121335, 2, 1, 0, 1, 1,''),
(140225, 121366, 2, 1, 0, 1, 1,''),
(140225, 121363, 2, 1, 0, 1, 1,''),
(140225, 121350, 2, 1, 0, 1, 1,''),
(140225, 121365, 2, 1, 0, 1, 1,''),
(140225, 121340, 2, 1, 0, 1, 1,''),
(140225, 121333, 2, 1, 0, 1, 1,''),
(140225, 121352, 2, 1, 0, 1, 1,''),
(140225, 121346, 2, 1, 0, 1, 1,''),
(140225, 121347, 2, 1, 0, 1, 1,''),
(140225, 121349, 2, 1, 0, 1, 1,''),
(140225, 121354, 2, 1, 0, 1, 1,''),
(140225, 121332, 2, 1, 0, 1, 1,''),
(140225, 121337, 2, 1, 0, 1, 1,''),
(140225, 121373, 2, 1, 0, 1, 1,''),
(140225, 121368, 2, 1, 0, 1, 1,''),
(140225, 121357, 2, 1, 0, 1, 1,''),
(140225, 121358, 2, 1, 0, 1, 1,''),
(140225, 121372, 2, 1, 0, 1, 1,''),
(140225, 121348, 2, 1, 0, 1, 1,''),
(140225, 121345, 2, 1, 0, 1, 1,''),
(140225, 121339, 2, 1, 0, 1, 1,''),
(140225, 121370, 2, 1, 0, 1, 1,''),
(140225, 121364, 2, 1, 0, 1, 1,''),
(140225, 121371, 2, 1, 0, 1, 1,''),
(140225, 121361, 2, 1, 0, 1, 1,''),
(140225, 121369, 2, 1, 0, 1, 1,''),
(140225, 134323, 0.2, 1, 0, 1, 1,''),
(140225, 121406, 0.2, 1, 0, 1, 1,''),
(140225, 139118, 0.2, 1, 0, 1, 1,''),
(140225, 139098, 0.2, 1, 0, 1, 1,''),
(140225, 134214, 0.2, 1, 0, 1, 1,''),
(140225, 134301, 0.2, 1, 0, 1, 1,''),
(140225, 121408, 0.2, 1, 0, 1, 1,''),
(140225, 121387, 0.2, 1, 0, 1, 1,''),
(140225, 121328, 0.2, 1, 0, 1, 1,''),
(140225, 121288, 0.2, 1, 0, 1, 1,''),
(140225, 139129, 0.2, 1, 0, 1, 1,''),
(140225, 121409, 0.2, 1, 0, 1, 1,''),
(140225, 121376, 0.2, 1, 0, 1, 1,''),
(140225, 121388, 0.2, 1, 0, 1, 1,''),
(140225, 134243, 0.2, 1, 0, 1, 1,''),
(140225, 121394, 0.2, 1, 0, 1, 1,''),
(140225, 134396, 0.2, 1, 0, 1, 1,''),
(140225, 134319, 0.2, 1, 0, 1, 1,''),
(140225, 134329, 0.2, 1, 0, 1, 1,''),
(140225, 134173, 0.2, 1, 0, 1, 1,''),
(140225, 134352, 0.2, 1, 0, 1, 1,''),
(140225, 121389, 0.2, 1, 0, 1, 1,'');

