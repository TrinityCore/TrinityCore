INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`, `Comment`) VALUES ('57', '60295', '1', '') ON DUPLICATE KEY UPDATE `Entry`=57;
UPDATE `gameobject_template` SET `Data1`='57' WHERE  `entry`=57;
UPDATE `gameobject_template` SET `castBarCaption`='Obtaining' WHERE  `entry`=57;

UPDATE creature_template SET minlevel=63 WHERE entry = 169769 ;
UPDATE creature_template SET maxlevel=63 WHERE entry = 169769 ;
UPDATE creature_template_scaling SET levelscalingmin=63 WHERE entry = 169769;
UPDATE creature_template_scaling SET levelscalingmax=63 WHERE entry = 169769;
UPDATE creature_template SET lootid=169769 WHERE entry = 169769;

DELETE FROM `spell_target_position` WHERE `ID` IN (323581);
INSERT INTO `spell_target_position`(`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(323581, 0, 2287, -2209.5, 5544.76, 4224.14, 36949);

UPDATE `gameobject_template` SET `Data0`='323581' WHERE  `entry`=349295;

UPDATE `creature_template` SET `ScriptName`='boss_muehzala' WHERE  `entry`=169769;

DELETE FROM `player_classlevelstats` WHERE `class`=2;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`) VALUES
(2, 1, 17, 6, 19, 20),
(2, 2, 18, 7, 21, 22),
(2, 3, 20, 7, 23, 24),
(2, 4, 22, 8, 25, 26),
(2, 5, 24, 9, 27, 28),
(2, 6, 26, 9, 29, 30),
(2, 7, 28, 10, 30, 32),
(2, 8, 29, 10, 32, 34),
(2, 9, 31, 11, 34, 36),
(2, 10, 33, 12, 36, 38),
(2, 11, 36, 13, 38, 40),
(2, 12, 39, 14, 40, 42),
(2, 13, 43, 15, 42, 44),
(2, 14, 46, 16, 44, 46),
(2, 15, 48, 17, 46, 48),
(2, 16, 50, 18, 48, 50),
(2, 17, 52, 18, 50, 52),
(2, 18, 54, 19, 51, 54),
(2, 19, 56, 20, 53, 56),
(2, 20, 58, 20, 55, 58),
(2, 21, 60, 21, 57, 60),
(2, 22, 62, 22, 59, 62),
(2, 23, 64, 22, 61, 64),
(2, 24, 66, 23, 63, 66),
(2, 25, 68, 24, 65, 68),
(2, 26, 70, 25, 67, 70),
(2, 27, 72, 25, 69, 72),
(2, 28, 74, 26, 71, 74),
(2, 29, 77, 27, 73, 77),
(2, 30, 79, 28, 75, 79),
(2, 31, 82, 29, 78, 82),
(2, 32, 84, 29, 80, 84),
(2, 33, 87, 30, 83, 87),
(2, 34, 90, 31, 86, 90),
(2, 35, 93, 32, 88, 93),
(2, 36, 96, 34, 91, 96),
(2, 37, 99, 35, 94, 99),
(2, 38, 102, 36, 97, 102),
(2, 39, 106, 37, 101, 106),
(2, 40, 109, 38, 104, 109),
(2, 41, 113, 40, 108, 113),
(2, 42, 117, 41, 112, 117),
(2, 43, 121, 42, 116, 121),
(2, 44, 126, 44, 120, 126),
(2, 45, 130, 46, 124, 130),
(2, 46, 135, 47, 128, 135),
(2, 47, 140, 49, 133, 140),
(2, 48, 145, 51, 138, 145),
(2, 49, 150, 52, 143, 150),
(2, 50, 155, 54, 148, 155),
(2, 51, 193, 67, 187, 193),
(2, 52, 208, 73, 204, 208),
(2, 53, 224, 78, 223, 224),
(2, 54, 241, 84, 244, 241),
(2, 55, 260, 91, 267, 260),
(2, 56, 280, 98, 292, 280),
(2, 57, 299, 104, 317, 299),
(2, 58, 319, 112, 343, 319),
(2, 59, 340, 119, 372, 340),
(2, 60, 450, 157, 414, 450);

DELETE FROM `player_classlevelstats` WHERE `class`=1;
INSERT INTO `player_classlevelstats` (`class`, `level`, `str`, `agi`, `sta`, `inte`) VALUES
(1, 1, 17, 12, 23, 14),
(1, 2, 18, 13, 25, 15),
(1, 3, 20, 14, 27, 16),
(1, 4, 22, 15, 29, 18),
(1, 5, 24, 17, 31, 19),
(1, 6, 26, 18, 33, 20),
(1, 7, 28, 20, 34, 22),
(1, 8, 29, 21, 36, 23),
(1, 9, 31, 22, 38, 24),
(1, 10, 33, 23, 40, 26),
(1, 11, 36, 25, 42, 27),
(1, 12, 39, 27, 43, 29),
(1, 13, 43, 30, 45, 30),
(1, 14, 46, 32, 46, 31),
(1, 15, 48, 33, 48, 33),
(1, 16, 50, 35, 50, 34),
(1, 17, 52, 36, 51, 35),
(1, 18, 54, 37, 52, 37),
(1, 19, 56, 39, 54, 38),
(1, 20, 58, 40, 55, 39),
(1, 21, 60, 41, 57, 41),
(1, 22, 62, 43, 59, 42),
(1, 23, 64, 44, 61, 44),
(1, 24, 66, 46, 63, 45),
(1, 25, 68, 47, 65, 46),
(1, 26, 70, 48, 67, 48),
(1, 27, 72, 50, 69, 49),
(1, 28, 74, 51, 71, 51),
(1, 29, 77, 53, 73, 52),
(1, 30, 79, 55, 75, 54),
(1, 31, 82, 56, 78, 56),
(1, 32, 84, 58, 80, 57),
(1, 33, 87, 60, 83, 59),
(1, 34, 90, 62, 86, 61),
(1, 35, 93, 64, 88, 63),
(1, 36, 96, 66, 91, 65),
(1, 37, 99, 68, 94, 67),
(1, 38, 102, 71, 97, 70),
(1, 39, 106, 73, 101, 72),
(1, 40, 109, 76, 104, 74),
(1, 41, 113, 78, 108, 77),
(1, 42, 117, 81, 112, 80),
(1, 43, 121, 84, 116, 82),
(1, 44, 126, 87, 120, 85),
(1, 45, 130, 90, 124, 88),
(1, 46, 135, 93, 128, 92),
(1, 47, 140, 96, 133, 95),
(1, 48, 145, 100, 138, 98),
(1, 49, 150, 103, 143, 102),
(1, 50, 155, 107, 148, 106),
(1, 51, 193, 133, 187, 131),
(1, 52, 208, 143, 204, 141),
(1, 53, 224, 154, 223, 152),
(1, 54, 241, 166, 244, 164),
(1, 55, 260, 179, 267, 177),
(1, 56, 280, 193, 292, 190),
(1, 57, 299, 206, 317, 203),
(1, 58, 319, 220, 343, 217),
(1, 59, 340, 235, 372, 231),
(1, 60, 450, 310, 414, 306);

UPDATE creature_template SET lootid=46264 WHERE entry = 46264;
UPDATE creature_template SET lootid=59150 WHERE entry = 59150;
UPDATE creature_template SET lootid=17991 WHERE entry = 17991;
UPDATE creature_template SET lootid=17942  WHERE entry = 17942 ;
UPDATE creature_template SET lootid=18341  WHERE entry = 18341 ;
UPDATE creature_template SET lootid=18343  WHERE entry = 18343 ;
UPDATE creature_template SET lootid=131318  WHERE entry = 131318 ;
UPDATE creature_template SET lootid=131817  WHERE entry = 131817 ;
UPDATE creature_template SET lootid=131383  WHERE entry = 131383 ;
UPDATE creature_template SET lootid=133007  WHERE entry = 133007 ;
UPDATE creature_template SET lootid=164267 WHERE entry = 164267 ;

UPDATE creature_template SET lootid=170850 WHERE entry = 170850;
UPDATE creature_template SET lootid=170838 WHERE entry = 170838;
UPDATE creature_template SET lootid=164510 WHERE entry = 164510;
UPDATE creature_template SET lootid=167994 WHERE entry = 167994;
UPDATE creature_template SET lootid=169875 WHERE entry = 169875;
UPDATE creature_template SET lootid=167998 WHERE entry = 167998;
UPDATE creature_template SET lootid=170690 WHERE entry = 170690;
UPDATE creature_template SET lootid=174210 WHERE entry = 174210;
UPDATE creature_template SET lootid=169927 WHERE entry = 169927;
UPDATE creature_template SET lootid=174773 WHERE entry = 174773;
UPDATE creature_template SET lootid=163086 WHERE entry = 163086;
UPDATE creature_template SET lootid=162744 WHERE entry = 162744;
UPDATE creature_template SET lootid=167536 WHERE entry = 167536;
UPDATE creature_template SET lootid=167533 WHERE entry = 167533;
UPDATE creature_template SET lootid=164506 WHERE entry = 164506;
UPDATE creature_template SET lootid=162317 WHERE entry = 162317;
UPDATE creature_template SET lootid=164267 WHERE entry = 164267;

UPDATE creature_template SET lootid=71483 WHERE entry = 71483;
UPDATE creature_template SET lootid=58778 WHERE entry = 58778;
UPDATE creature_template SET lootid=26401 WHERE entry = 26401;
UPDATE creature_template SET lootid=63976 WHERE entry = 63976;
UPDATE creature_template SET lootid=50822 WHERE entry = 50822;

UPDATE creature_template SET lootid=65862 WHERE entry = 65862;
UPDATE creature_template SET lootid=64403 WHERE entry = 64403;
UPDATE creature_template SET lootid=64706 WHERE entry = 64706;
UPDATE creature_template SET lootid=58992 WHERE entry = 58992;
UPDATE creature_template SET lootid=64614 WHERE entry = 64614;
UPDATE creature_template SET lootid=64029 WHERE entry = 64029;
UPDATE creature_template SET lootid=63996 WHERE entry = 63996;
UPDATE creature_template SET lootid=64122 WHERE entry = 64122;
UPDATE creature_template SET lootid=67133 WHERE entry = 67133;

UPDATE creature_template SET lootid=110570 WHERE entry = 110570;
UPDATE creature_template SET lootid=58928 WHERE entry = 58928;
UPDATE creature_template SET lootid=62596 WHERE entry = 62596;
UPDATE creature_template SET lootid=64173 WHERE entry = 64173;
UPDATE creature_template SET lootid=65735 WHERE entry = 65735;
UPDATE creature_template SET lootid=64158 WHERE entry = 64158;
UPDATE creature_template SET lootid=64588 WHERE entry = 64588;
UPDATE creature_template SET lootid=64615 WHERE entry = 64615;
UPDATE creature_template SET lootid=64557 WHERE entry = 64557;

UPDATE creature_template SET lootid=163457 WHERE entry = 163457;
UPDATE creature_template SET lootid=163459 WHERE entry = 163459;
UPDATE creature_template SET lootid=168318 WHERE entry = 168318;
UPDATE creature_template SET lootid=163458 WHERE entry = 163458;
UPDATE creature_template SET lootid=163506 WHERE entry = 163506;
UPDATE creature_template SET lootid=163524 WHERE entry = 163524;
UPDATE creature_template SET lootid=173729 WHERE entry = 173729;
UPDATE creature_template SET lootid=166411 WHERE entry = 166411;
UPDATE creature_template SET lootid=168718 WHERE entry = 168718;

UPDATE creature_template SET lootid=168717 WHERE entry = 168717;
UPDATE creature_template SET lootid=163589 WHERE entry = 163589;
UPDATE creature_template SET lootid=163077 WHERE entry = 163077;
UPDATE creature_template SET lootid=168845 WHERE entry = 168845;
UPDATE creature_template SET lootid=168843 WHERE entry = 168843;

UPDATE creature_template SET lootid=168844 WHERE entry = 168844;
UPDATE creature_template SET lootid=162061 WHERE entry = 162061;

UPDATE creature_template SET lootid=171211 WHERE entry = 171211;
UPDATE creature_template SET lootid=171014 WHERE entry = 171014;

UPDATE creature_template SET lootid=171010 WHERE entry = 171010;
UPDATE creature_template SET lootid=170623 WHERE entry = 170623;
UPDATE creature_template SET lootid=171011 WHERE entry = 171011;
UPDATE creature_template SET lootid=163460 WHERE entry = 163460;
UPDATE creature_template SET lootid=171013 WHERE entry = 171013;

UPDATE creature_template SET faction=14 WHERE entry = 170838;

-- Entry AreaTrigger = 130000
REPLACE INTO `areatrigger_involvedrelation` VALUES (130000, 29356);
-- Guid in table aretrigger = 108 NOTE: we cant use 103, it is in use already. -Varjgard


UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=23224;

UPDATE `gameobject` SET `spawnDifficulties` = '1,2' WHERE `id` = 182947;
UPDATE `gameobject` SET `spawnDifficulties` = '2' WHERE `id` = 184222 AND `map` IN (553,554);


UPDATE `creature` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1893;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1893;

-- The Rotting Mire 1892  9153.376, 9691.307, 6.3429, 1.5364347
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (1723,1744,1745,1764);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `requiredItemLevel`, `VerifiedBuild`) VALUES 
(1723, 'The Rotting Mire 38', 9153.376, 9691.307, 6.3429, 1.5364347, 0, 28153),
(1744, 'The Rotting Mire 39', 9153.376, 9691.307, 6.3429, 1.5364347, 0, 28153),
(1745, 'The Rotting Mire 40', 9153.376, 9691.307, 6.3429, 1.5364347, 0, 28153),
(1764, 'The Rotting Mire 45', 9153.376, 9691.307, 6.3429, 1.5364347, 0, 28153);

UPDATE `creature` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1892;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1892;

-- Jorundall 1879   14404.991, 11490.11, 6.3429, 4.09958
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (1932,1933,1934,1935,2041,2056);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `requiredItemLevel`, `VerifiedBuild`) VALUES 
(1932, 'Jorundall 38', 14404.991, 11490.11, 6.3429, 4.09958, 0, 28153),
(1933, 'Jorundall 39', 14404.991, 11490.11, 6.3429, 4.09958, 0, 28153),
(1934, 'Jorundall 40', 14404.991, 11490.11, 6.3429, 4.09958, 0, 28153),
(1935, 'Jorundall 45', 14404.991, 11490.11, 6.3429, 4.09958, 0, 28153),
(2041, 'Jorundall 153 pvp', 14404.991, 11490.11, 6.3429, 4.09958, 0, 28153),
(2056, 'Jorundall 153', 14404.991, 11490.11, 6.3429, 4.09958, 0, 28153);

UPDATE `creature` SET `spawnDifficulties`='38,39,40,45,153' WHERE `map`=1879;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45,153' WHERE `map`=1879;

-- Verdant Wilds  1882                9440/verdant-wilds 1724,1743,1746,1763,2058  
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (1724,1743,1746,1763,2058);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `requiredItemLevel`, `VerifiedBuild`) VALUES 
(1724, 'Verdant Wilds 38', 14917.806, 15177.087, 10.872437, 0, 0, 28153),
(1743, 'Verdant Wilds 39', 14917.806, 15177.087, 10.872437, 0, 0, 28153),
(1746, 'Verdant Wilds 40', 14917.806, 15177.087, 10.872437, 0, 0, 28153),
(1763, 'Verdant Wilds 45', 14917.806, 15177.087, 10.872437, 0, 0, 28153),
(2058, 'Verdant Wilds 153', 14917.806, 15177.087, 10.872437, 0, 0, 28153);

UPDATE `creature` SET `spawnDifficulties`='38,39,40,45,153' WHERE `map`=1882;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45,153' WHERE `map`=1882;

--  Whispering Reef  1883  1735,1740,1749,1908 -913.84894, 2159.6199, 28.34297, 0
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (1735,1740,1749,1908);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `requiredItemLevel`, `VerifiedBuild`) VALUES 
(1735, 'Whispering Reef 38', -913.84894, 2159.6199, 28.34297, 0, 0, 28153),
(1740, 'Whispering Reef 39', -913.84894, 2159.6199, 28.34297, 0, 0, 28153),
(1749, 'Whispering Reef 40', -913.84894, 2159.6199, 28.34297, 0, 0, 28153),
(1908, 'Whispering Reef 45', -913.84894, 2159.6199, 28.34297, 08, 0, 28153);

UPDATE `creature` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1883;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1883;




-- TO DO
-- Crestfall 2124 潮落岛 1987,1985,1986,1984,2057
UPDATE `creature` SET `spawnDifficulties`='38,39,40,45,153' WHERE `map`=2124;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45,153' WHERE `map`=2124;
-- Molten Cay     1897         熔火海礁     9496/熔火海礁  1750,1751,1752,1765
UPDATE `creature` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1897;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1897;
-- Un\'gol Ruins  1813 安戈尔废墟 9469/         1687,1738,1739,1761
UPDATE `creature` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1813;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1813;
--  Skittering Hollow 1898   飞掠谷  1725,1742,1747,1767
UPDATE `creature` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1898;
UPDATE `gameobject` SET `spawnDifficulties`='38,39,40,45' WHERE `map`=1898;


DELETE FROM `instance_template` WHERE `map` IN (1814,1892,1893,1879,2124,1897,1813,1882,1898,1883);
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`, `insideResurrection`) VALUES 
(1814, 1642, 'scenario_havenswood', 1, 1),
(1892, 1642, 'scenario_the_rotting_mire', 1, 1),
(1893, 1642, 'scenario_the_dread_chain', 1, 1),
(1879, 1642, 'scenario_jorundall', 1, 1),
(2124, 1642, 'scenario_crestfall', 1, 1),
(1897, 1642, 'scenario_molten_cay', 1, 1),
(1813, 1642, 'scenario_ungol_ruins', 1, 1),
(1882, 1642, 'scenario_verdant_wilds', 1, 1),
(1898, 1642, 'scenario_skittering_hollow', 1, 1),
(1883, 1642, 'scenario_whispering_reef', 1, 1);

UPDATE creature_template SET lootid=164185 WHERE entry = 164185;

-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 156681);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '156681';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (156681, 6666, 10185, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '6666';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (6666, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '6666';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('6666', '3908', '10000', '0', '0', '0'),
('6666', '310949', '5500000', '0', '0', '0'),
('6666', '184479', '10000', '0', '0', '0'),
('6666', '184480', '100000', '0', '0', '0'),
('6666', '173249', '100000', '165', '0', '0'),
('6666', '173198', '100000', '165', '0', '0'),
('6666', '173246', '10000', '165', '1', '0');


DELETE FROM `quest_objectives` WHERE `ID` IN (405017 /*405017*/, 406744 /*406744*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(405017, 60545, 0, 2, 0, 170749, 1, 2, 0, 0, 'Usa el teletransportador para ir al Trono Helado', 38134), -- 405017
(406744, 60545, 14, 0, 1, 87208, 1, 0, 0, 0, 'Aprende sobre el destino de tus líderes', 38134); -- 406744

UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396607; -- 396607
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388261; -- 388261
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=336624; -- 336624
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=335866; -- 335866
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339035; -- 339035
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=339250; -- 339250
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=333763; -- 333763


DELETE FROM `areatrigger_template` WHERE `Id`=21507;
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(21507, 1, 0, 4, 35, 35, 0, 0, 0, 0, 38134);


DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=17255 AND `AreaTriggerId`=21507);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(17255, 21507, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- SpellId : 301630



UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0


UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7526 AND `Idx`=0);


UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=17138;


UPDATE `conversation_template` SET `LastLineEndTime`=3200, `VerifiedBuild`=38134 WHERE `Id`=7526;

DELETE FROM `gameobject_template_addon` WHERE `entry`=326165;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(326165, 0, 4, 0, 0); -- Roca de prospección

UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=287467; -- Parte de barco vieja
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=287463; -- Parte de barco vieja
UPDATE `gameobject_template_addon` SET `flags`=2375680, `WorldEffectID`=2437 WHERE `entry`=291267; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=293349; -- Lonchera descartada
UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=275074; -- Cofre del tesoro pequeño


DELETE FROM `quest_poi` WHERE (`QuestID`=51314 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51314 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51314 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51534 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51534 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(51314, 0, 2, 32, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1497895, 0, 38134), -- -Unknown-
(51314, 0, 1, 0, 335387, 155878, 1643, 942, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51314, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1497895, 0, 38134), -- -Unknown-
(51534, 0, 1, 32, 0, 0, 1643, 942, 0, 2, 0, 54815, 0, 0, 0, 38134), -- -Unknown-
(51534, 0, 0, 31, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-



UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50158 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50158 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50157 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50157 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51554 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51554 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51159 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51159 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51159 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51217 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51217 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51217 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49745 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49745 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49745 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51552 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51552 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50733 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50733 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=51314 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51314 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51314 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51534 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=51534 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(51314, 2, 0, 2591, 223, 57, 38134), -- -Unknown-
(51314, 1, 7, 2540, 176, 48, 38134), -- -Unknown-
(51314, 1, 6, 2488, 184, 50, 38134), -- -Unknown-
(51314, 1, 5, 2647, 355, 59, 38134), -- -Unknown-
(51314, 1, 4, 2744, 410, 33, 38134), -- -Unknown-
(51314, 1, 3, 2780, 414, 30, 38134), -- -Unknown-
(51314, 1, 2, 2774, 365, 32, 38134), -- -Unknown-
(51314, 1, 1, 2651, 207, 52, 38134), -- -Unknown-
(51314, 1, 0, 2592, 172, 45, 38134), -- -Unknown-
(51314, 0, 0, 2591, 223, 57, 38134), -- -Unknown-
(51534, 1, 0, 2712, 603, 0, 38134), -- -Unknown-
(51534, 0, 7, 2630, 121, 0, 38134), -- -Unknown-
(51534, 0, 6, 2698, 222, 0, 38134), -- -Unknown-
(51534, 0, 5, 2783, 247, 0, 38134), -- -Unknown-
(51534, 0, 4, 2808, 230, 0, 38134), -- -Unknown-
(51534, 0, 3, 2833, 208, 0, 38134), -- -Unknown-
(51534, 0, 2, 2855, 174, 0, 38134), -- -Unknown-
(51534, 0, 1, 2837, 113, 0, 38134), -- -Unknown-
(51534, 0, 0, 2696, 31, 0, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50136 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50135 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50134 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50133 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49960 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49886 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51310 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50158 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50158 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50157 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50157 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51554 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51554 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51159 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51159 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51159 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51217 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51217 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51217 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50909 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50910 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50908 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49755 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49746 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49745 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49745 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49745 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49744 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51552 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51552 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50733 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50733 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID`=51554;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(51554, 396, 5, 396, 0, 0, 300, 300, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49886; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49886; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49886; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50136; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50135; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50134; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49886; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49960; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49886; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51314; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51310; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50158; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50157; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51159; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51159; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51217; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51217; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50909; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50909; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50910; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50910; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50908; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50908; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50908; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49755; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49746; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49745; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49744; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49744; -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (53436 /*-Unknown-*/, 51193 /*-Unknown-*/, 51192 /*-Unknown-*/, 51359 /*-Unknown-*/, 51351 /*-Unknown-*/, 51350 /*-Unknown-*/, 51309 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(53436, 0, 0, 0, 0, 'Vuelve a verme cuando hayas terminado de ayudar a la Alianza, $n.', 38134), -- -Unknown-
(51193, 0, 0, 0, 0, 'No me juzgues. Este martillo es el mejor.', 0), -- -Unknown-
(51192, 0, 0, 0, 0, '¿Encontraste algo útil?', 0), -- -Unknown-
(51359, 0, 0, 0, 0, 'Mis chamanes son cada vez mejores, ¿no? Con las primeras invocaciones ya generamos una pelea bien candente...', 38134), -- -Unknown-
(51351, 0, 0, 0, 0, '¿Conseguiste las púas?', 0), -- -Unknown-
(51350, 0, 0, 0, 0, '¿Conseguiste el cactus para el bálsamo?', 0), -- -Unknown-
(51309, 0, 0, 0, 0, 'No me preocupaba que estuvieran rotas. Un poco de fuego jamás les haría daño a estas rocas.', 0); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`ID`=268750 AND `EffectIndex`=1);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(268750, 1, 1643, 2639.550048828125, 66.4499969482421875, 41.15999984741210937, 38134); -- Spell: 268750 (Horde Attack) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (141354 /*141354 (Conscripto Canto Tormenta)*/, 139176 /*139176 (Torre de asedio)*/, 141355 /*141355*/, 150898 /*150898*/, 155070 /*155070 (Lecho de flores exuberantes) - [DNT] Flower Patch + Sunshaft*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(141354, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 141354 (Conscripto Canto Tormenta)
(139176, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 139176 (Torre de asedio)
(141355, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 141355
(150898, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 150898
(155070, 0, 0, 0, 1, 0, 0, 0, 0, '301630'); -- 155070 (Lecho de flores exuberantes) - [DNT] Flower Patch + Sunshaft

UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=134752; -- 134752 (Alcaldesa Roz)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=130073; -- 130073 (Briarback Lookout)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=134636; -- 134636 (Cazatesoros)
UPDATE `creature_template_addon` SET `mount`=0, `bytes1`=262144, `auras`='145363' WHERE `entry`=129750; -- 129750 (Hostigador zarzalomo)
UPDATE `creature_template_addon` SET `aiAnimKit`=947 WHERE `entry`=132297; -- 132297 (Mozo de labranza reparado)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=129906; -- 129906 (Tunelador zarzalomo)
UPDATE `creature_template_addon` SET `auras`='277331 133716' WHERE `entry`=136942; -- 136942 (Yarsel'ghun)
UPDATE `creature_template_addon` SET `auras`='277331' WHERE `entry`=136950; -- 136950 (Flebotomista zandalari)
UPDATE `creature_template_addon` SET `auras`='78828' WHERE `entry`=135883; -- 135883 (Durmok Crinoscura)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='154470' WHERE `entry`=131697; -- 131697 (Oso pardo de las Tierras Altas)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='154470' WHERE `entry`=141147; -- 141147 (Pescador de Presabrenna)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='262154' WHERE `entry`=136584; -- 136584 (Lanzahachas de la Horda)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='255379 154470' WHERE `entry`=128838; -- 128838 (Pack Mule)
UPDATE `creature_template_addon` SET `aiAnimKit`=14713 WHERE `entry`=136517; -- 136517 (Vernice Campoáureo)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=139165; -- 139165 (Asaltante orco)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=138060; -- 138060 (Cañón de azerita)
UPDATE `creature_template_addon` SET `aiAnimKit`=1455 WHERE `entry`=138055; -- 138055 (Máquina de guerra experimental)
UPDATE `creature_template_addon` SET `auras`='11196' WHERE `entry`=140925; -- 140925 (Doc Marrtens)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=137104; -- 137104 (Asaltante orco)
UPDATE `creature_template_addon` SET `aiAnimKit`=13880 WHERE `entry`=130733; -- 130733 (Niño aterrado)
UPDATE `creature_template_addon` SET `aiAnimKit`=913 WHERE `entry`=136580; -- 136580 (Aldeano aterrorizado)
UPDATE `creature_template_addon` SET `aiAnimKit`=12092 WHERE `entry`=129749; -- 129749 (Bruto arrasador)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='269585' WHERE `entry`=134426; -- 134426 (Técnico zapador)
UPDATE `creature_template_addon` SET `auras`='239020 145363' WHERE `entry`=131272; -- 131272 (Aldeano de Presabrenna)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=130190; -- 130190 (Sargento Calvin)
UPDATE `creature_template_addon` SET `aiAnimKit`=1320 WHERE `entry`=141484; -- 141484 (Ciudadano de Presabrenna)
UPDATE `creature_template_addon` SET `aiAnimKit`=1320 WHERE `entry`=141482; -- 141482 (Ciudadana de Presabrenna)
UPDATE `creature_template_addon` SET `aiAnimKit`=10463 WHERE `entry`=141353; -- 141353 (Empleado Ebert)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=137988; -- 137988
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=138007; -- 138007
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=138014; -- 138014
UPDATE `creature_template_addon` SET `auras`='261762' WHERE `entry`=127739; -- 127739
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126709; -- 126709
UPDATE `creature_template_addon` SET `auras`='115385' WHERE `entry`=133285; -- 133285
UPDATE `creature_template_addon` SET `auras`='109525' WHERE `entry`=127626; -- 127626 (Mordedor de agua fresca)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=133264; -- 133264
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='' WHERE `entry`=133309; -- 133309
UPDATE `creature_template_addon` SET `auras`='244863' WHERE `entry`=142774; -- 142774
UPDATE `creature_template_addon` SET `auras`='272105' WHERE `entry`=135889; -- 135889
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=140906; -- 140906 (Rata de muelle)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=134722; -- 134722 (Vagabundo demacrado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=124805; -- 124805 (Mozo de cuadra)
UPDATE `creature_template_addon` SET `auras`='244971' WHERE `entry`=143844; -- 143844 (Marino ocioso)
UPDATE `creature_template_addon` SET `bytes2`=1, `aiAnimKit`=15780 WHERE `entry`=135675; -- 135675 (7th Legion Marine)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=135678; -- 135678 (Cañonero de la Séptima Legión)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=132638; -- 132638 (Noble kultirana)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=142371; -- 142371 (Oficial Astley)
UPDATE `creature_template_addon` SET `aiAnimKit`=13281 WHERE `entry`=143295; -- 143295 (Pregonero de Boralus)
UPDATE `creature_template_addon` SET `auras`='271317' WHERE `entry`=135230; -- 135230 (Inspector de Boralus)
UPDATE `creature_template_addon` SET `auras`='281608 267658' WHERE `entry`=133536; -- 133536 (Grix "Puños de hierro" Barlow)
UPDATE `creature_template_addon` SET `bytes1`=5, `bytes2`=256 WHERE `entry`=133325; -- 133325 (Comerciante de Drustvar)
UPDATE `creature_template_addon` SET `auras`='271334' WHERE `entry`=140313; -- 140313 (Cadete guardia del puerto)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=143502; -- 143502 (Whisky)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=142166; -- 142166 (Trabajador de embarcadero Vientos Alisios)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='273259' WHERE `entry`=140350; -- 140350 (Capitán de la guardia del puerto)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=135509; -- 135509 (Ciudadano de Boralus)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=123642; -- 123642 (Boralus Citizen)


UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131645 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=133953 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135745 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=141354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132118 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132297 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136942 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=134848 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136273 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139977 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139549 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141147 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141143 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140534 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139570 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136587 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136584 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136481 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=94621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136463 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135857 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135874 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136469 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=136517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139967 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136230 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136519 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139176 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139168 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139167 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139165 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138125 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136204 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=141355 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=708, `VerifiedBuild`=38134 WHERE (`Entry`=150898 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138055 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140925 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138028 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129836 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=119508 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137622 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130733 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136580 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136957 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136958 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130820 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=789, `VerifiedBuild`=38134 WHERE (`Entry`=155070 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138322 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138178 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5 WHERE `DisplayID`=6106;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=48169;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82237;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369618415832519, `CombatReach`=1 WHERE `DisplayID`=74789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.180290251970291137, `CombatReach`=0.649999976158142089 WHERE `DisplayID`=72186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895694732666015, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=84065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369678020477294, `CombatReach`=1 WHERE `DisplayID`=88674;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895739436149597, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=86546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.266274839639663696, `CombatReach`=0.960000038146972656 WHERE `DisplayID`=72183;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5 WHERE `DisplayID`=1963;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78954;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=84965;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84970;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5 WHERE `DisplayID`=66292;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=55309;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87156;
UPDATE `creature_model_info` SET `BoundingRadius`=0.502200007438659667, `CombatReach`=2.02500009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=84835;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=56556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.974700033664703369, `CombatReach`=4.050000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=84831;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86392;
UPDATE `creature_model_info` SET `BoundingRadius`=0.259999990463256835, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=87079;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88427;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579469561576843261, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=52607;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579469561576843261 WHERE `DisplayID`=52598;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88428;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=81567;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=84444;
UPDATE `creature_model_info` SET `BoundingRadius`=0.228800013661384582, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=84454;
UPDATE `creature_model_info` SET `BoundingRadius`=0.321299970149993896, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84349;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=87386;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84436;
UPDATE `creature_model_info` SET `BoundingRadius`=0.275399982929229736, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=81294;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579469561576843261 WHERE `DisplayID`=60964;
UPDATE `creature_model_info` SET `BoundingRadius`=0.724336981773376464, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=52599;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579469561576843261 WHERE `DisplayID`=52602;
UPDATE `creature_model_info` SET `BoundingRadius`=2.08085036277770996, `VerifiedBuild`=38134 WHERE `DisplayID`=90951;
UPDATE `creature_model_info` SET `BoundingRadius`=2.374366044998168945, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=85702;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88477;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96323;
UPDATE `creature_model_info` SET `BoundingRadius`=0.191469371318817138, `VerifiedBuild`=38134 WHERE `DisplayID`=77040;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87015;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85413;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77042;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87350;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=25092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.168620049953460693, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=304;
UPDATE `creature_model_info` SET `BoundingRadius`=12.02260112762451171, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84777;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87347;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88686;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=86529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.140088886022567749, `CombatReach`=0.5 WHERE `DisplayID`=87565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=87495;
UPDATE `creature_model_info` SET `BoundingRadius`=0.253760010004043579, `CombatReach`=1.830000042915344238 WHERE `DisplayID`=5565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.351899981498718261, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=75719;


UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=135874 AND `item`=159867 AND `ExtendedCost`=0 AND `type`=1); -- Rockskip Mineral Water
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=135874 AND `item`=163051 AND `ExtendedCost`=0 AND `type`=1); -- Seafarer's Biscuit

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (141354,141355));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(141354, 1, 153405, 0, 0, 0, 0, 0, 0, 0, 0), -- Conscripto Canto Tormenta
(141355, 1, 153405, 0, 0, 0, 0, 0, 155815, 0, 0); -- -Unknown-

UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=139088 AND `ID`=3); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=143572 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=143574 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=142784 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=139088 AND `ID`=2); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=142778 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=80057 WHERE (`CreatureID`=135792 AND `ID`=2); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=1905 WHERE (`CreatureID`=135792 AND `ID`=1); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=31824 WHERE (`CreatureID`=135678 AND `ID`=3); -- Cañonero de la Séptima Legión
UPDATE `creature_equip_template` SET `ItemID1`=1906 WHERE (`CreatureID`=135678 AND `ID`=2); -- Cañonero de la Séptima Legión
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=135678 AND `ID`=1); -- Cañonero de la Séptima Legión
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=135509 AND `ID`=1); -- Ciudadano de Boralus

DELETE FROM `gossip_menu` WHERE (`MenuId`=26846 AND `TextId`=42723);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(26846, 42723, 38134); -- 177193 (Kiku)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22453 AND `TextId`=34460); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22453 AND `TextId`=34460); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22512 AND `TextId`=34588); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22453 AND `TextId`=34460); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22453 AND `TextId`=34460); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22453 AND `TextId`=34460); -- 0


UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131645; -- Jinete zarzalomo
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=134752; -- Alcaldesa Roz
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=133953; -- Sergeant Calvin
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=130073; -- Briarback Lookout
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=134636; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135745; -- Reptador de esquisto
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=141354; -- Conscripto Canto Tormenta
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=132207; -- Cápsula de zarzas
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129750; -- Hostigador zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132118; -- Granjero Burton
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132297; -- Mozo de labranza reparado
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=129870; -- Maestro de jabalíes zarzalomo
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=129869; -- Comerraíces hambriento
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129906; -- Tunelador zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136942; -- Yarsel'ghun
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136950; -- Flebotomista zandalari
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=134848; -- Kudra Espada del Viento
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141205; -- Erdi Sangradientes
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=135882; -- Ogarth Hachero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136273; -- Ensamblador de la avanzada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139977; -- Ensamblador de la avanzada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135883; -- Durmok Crinoscura
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=131697; -- Oso pardo de las Tierras Altas
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=139549; -- Turn In Target
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=141147; -- Pescador de Presabrenna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141143; -- Hermana Absenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140534; -- Escudo de carne
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=136318; -- Peón orco
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139570; -- Explorador de la Horda
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=136587; -- Asaltante de la Horda
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136584; -- Lanzahachas de la Horda
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=131387; -- Zorro colacobre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136481; -- Cañón
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33554432, `unit_flags2`=67110912 WHERE `entry`=94621; -- Acechador invisible
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=128838; -- Pack Mule
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=136591; -- Oso pardo de las Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33040 WHERE `entry`=136462; -- Alex Purnell
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33024 WHERE `entry`=136463; -- Elsbeth Martinel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135857; -- Daryl Eckhart
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136451; -- Dalia Zarzagacela
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135874; -- Lea Martinel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135682; -- Patrick Eckhart
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=139615; -- Pluma de Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136469; -- Rojillo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136517; -- Vernice Campoáureo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139967; -- Jen Zarzagacela
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136230; -- Ciudadano herido
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135860; -- Bruto invasor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136519; -- Hogarth Reed
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags2`=2129920, `unit_flags3`=1 WHERE `entry`=139176; -- Torre de asedio
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139170; -- Demoledor
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139168; -- Rebanacabezas sanguinario
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139167; -- Técnico zapador
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139165; -- Asaltante orco
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=130899; -- Commander Wormwood
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136206; -- Cachorro dientegélido
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138125; -- Ingeniero de tanques
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136204; -- Alfa dientegélido
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136205; -- Aullador dientegélido
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=141355; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=768 WHERE `entry`=150898; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=138060; -- Cañón de azerita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=138055; -- Máquina de guerra experimental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768, `dynamicflags`=128 WHERE `entry`=139030; -- Explosivos colocados
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768, `dynamicflags`=128 WHERE `entry`=139031; -- Explosivos colocados
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140925; -- Doc Marrtens
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138028; -- Campeón Tétanos
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129836; -- Spelltwister Moephus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=119508; -- Efecto de hechizo - Conejo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=832 WHERE `entry`=137622; -- Demoledor
UPDATE `creature_template` SET `speed_run`=1.714285731315612792 WHERE `entry`=137104; -- Asaltante orco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=130733; -- Niño aterrado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136580; -- Aldeano aterrorizado
UPDATE `creature_template` SET `VehicleId`=5949 WHERE `entry`=129749; -- Bruto arrasador
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129867; -- Zepelín bombardero
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=138931; -- Poppers
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136957; -- Zepelín bombardero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136958; -- Zepelín bombardero
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138930; -- Joven de Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768, `dynamicflags`=128 WHERE `entry`=130820; -- Fuego embravecido
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=141716; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=1140852736 WHERE `entry`=155070; -- Lecho de flores exuberantes
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=126709; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=294912 WHERE `entry`=127626; -- Mordedor de agua fresca
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=143559; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=143560; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=141698; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=88696; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=88697; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138744; -- Alapresta
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=143846; -- Alleria Brisaveloz
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135614; -- Maestro Mathias Shaw
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138321; -- Capitán Shwayder
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138322; -- Lion's Guard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138178; -- Anduin Wrynn
UPDATE `creature_template` SET `gossip_menu_id`=21307 WHERE `entry`=121235; -- Taelia
UPDATE `creature_template` SET `gossip_menu_id`=22600 WHERE `entry`=135808; -- Proveedora Fray
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=142371; -- Oficial Astley
UPDATE `creature_template` SET `gossip_menu_id`=26846 WHERE `entry`=177193; -- Kiku


DELETE FROM `page_text` WHERE `ID`=7870;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(7870, 'Comenzó de manera muy simple.$B$BLos obsequios de Canto Tormenta guiaron a los peces hacia nuestras redes y orientaron el agua hacia nuestra boca.$B$BHabíamos dejado de ser esclavos de los elementos. Ahora éramos sus amos.', 0, 0, 0, 38134); -- 7870


DELETE FROM `npc_text` WHERE `ID`=42723;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(42723, 0, 0, 0, 0, 0, 0, 0, 0, 207903, 0, 0, 0, 0, 0, 0, 0, 38134); -- 42723

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34588; -- 34588
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34460; -- 34460

UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17970;


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=13378 AND `AreaTriggerId`=17970); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0


UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7151 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7151 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6641 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6641 AND `Idx`=0);


UPDATE `conversation_line_template` SET `StartTime`=6169, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=16270;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=16269;
UPDATE `conversation_line_template` SET `StartTime`=4600, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15140;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=15139;


UPDATE `conversation_template` SET `LastLineEndTime`=11981, `VerifiedBuild`=38134 WHERE `Id`=7151;
UPDATE `conversation_template` SET `LastLineEndTime`=11450, `VerifiedBuild`=38134 WHERE `Id`=6641;


UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291263; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `flags`=262145 WHERE `entry`=294537; -- Tótem de guardazarzas
UPDATE `gameobject_template_addon` SET `flags`=262145 WHERE `entry`=282452; -- Tótem de guardazarzas
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=293350; -- Cofre de madera tallado
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=11667 WHERE `entry`=278433; -- Pilar terráneo

DELETE FROM `quest_request_items` WHERE `ID` IN (53436 /*-Unknown-*/, 51193 /*-Unknown-*/, 51192 /*-Unknown-*/, 51359 /*-Unknown-*/, 51351 /*-Unknown-*/, 51350 /*-Unknown-*/, 51309 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(53436, 0, 0, 0, 0, 'Vuelve a verme cuando hayas terminado de ayudar a la Alianza, $n.', 38134), -- -Unknown-
(51193, 0, 0, 0, 0, 'No me juzgues. Este martillo es el mejor.', 0), -- -Unknown-
(51192, 0, 0, 0, 0, '¿Encontraste algo útil?', 0), -- -Unknown-
(51359, 0, 0, 0, 0, 'Mis chamanes son cada vez mejores, ¿no? Con las primeras invocaciones ya generamos una pelea bien candente...', 38134), -- -Unknown-
(51351, 0, 0, 0, 0, '¿Conseguiste las púas?', 0), -- -Unknown-
(51350, 0, 0, 0, 0, '¿Conseguiste el cactus para el bálsamo?', 0), -- -Unknown-
(51309, 0, 0, 0, 0, 'No me preocupaba que estuvieran rotas. Un poco de fuego jamás les haría daño a estas rocas.', 0); -- -Unknown-


UPDATE `creature_template_addon` SET `aiAnimKit`=14414 WHERE `entry`=137459; -- 137459 (Granjera Deal)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=140595; -- 140595 (Cazador Canto Tormenta)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=136914; -- 136914 (Albatros picocéano)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=134752; -- 134752 (Alcaldesa Roz)
UPDATE `creature_template_addon` SET `aiAnimKit`=14414 WHERE `entry`=130078; -- 130078 (Granjero capturado)
UPDATE `creature_template_addon` SET `aiAnimKit`=14470 WHERE `entry`=130395; -- 130395 (Briarback Warcaller)
UPDATE `creature_template_addon` SET `auras`='258156' WHERE `entry`=130073; -- 130073 (Briarback Lookout)
UPDATE `creature_template_addon` SET `mount`=29283 WHERE `entry`=137104; -- 137104 (Asaltante orco)
UPDATE `creature_template_addon` SET `mount`=0, `bytes1`=262144, `auras`='145363' WHERE `entry`=129750; -- 129750 (Hostigador zarzalomo)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=130452; -- 130452 (Perro guardián fiel)
UPDATE `creature_template_addon` SET `aiAnimKit`=947 WHERE `entry`=132297; -- 132297 (Mozo de labranza reparado)


UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=133953 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138733 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138700 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131949 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132204 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131645 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132118 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132297 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83325;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5 WHERE `DisplayID`=66292;
UPDATE `creature_model_info` SET `BoundingRadius`=1.411821842193603515, `CombatReach`=2.90000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86493;
UPDATE `creature_model_info` SET `BoundingRadius`=2.272244453430175781, `CombatReach`=2.083333492279052734, `VerifiedBuild`=38134 WHERE `DisplayID`=81687;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88562;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=29253;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5 WHERE `DisplayID`=6106;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=80463;
UPDATE `creature_model_info` SET `BoundingRadius`=3.76745772361755371, `CombatReach`=3 WHERE `DisplayID`=86974;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=86529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82237;
UPDATE `creature_model_info` SET `BoundingRadius`=0.18394915759563446, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=5369;
UPDATE `creature_model_info` SET `BoundingRadius`=0.168620049953460693, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=304;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5 WHERE `DisplayID`=1963;


UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=137459; -- Granjera Deal
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134141; -- Maestro de manada zarzalomo
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=140595; -- Cazador Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=139793; -- Oso pardo zarpapúa
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=133953; -- Sergeant Calvin
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=134752; -- Alcaldesa Roz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138733; -- Triturador zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138709; -- Targeting Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138700; -- Creador zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131949; -- Asaltante zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536, `dynamicflags`=128 WHERE `entry`=130078; -- Granjero capturado
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=1739, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=130395; -- Briarback Warcaller
UPDATE `creature_template` SET `BaseAttackTime`=1739 WHERE `entry`=130073; -- Briarback Lookout
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=18432 WHERE `entry`=129870; -- Maestro de jabalíes zarzalomo
UPDATE `creature_template` SET `unit_flags`=67141632, `unit_flags2`=18432 WHERE `entry`=129869; -- Comerraíces hambriento
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=134963; -- Karla Buentiempo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132206; -- Espinas enredadoras
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132204; -- Espinácula espinafilada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131645; -- Jinete zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132118; -- Granjero Burton
UPDATE `creature_template` SET `speed_run`=1.714285731315612792 WHERE `entry`=137104; -- Asaltante orco
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129750; -- Hostigador zarzalomo
UPDATE `creature_template` SET `npcflag`=16777216, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=130452; -- Perro guardián fiel
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=132297; -- Mozo de labranza reparado


UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=136419 AND `Idx`=0); -- Tirapiedras ettin
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=136421 AND `Idx`=0); -- Aplastatierra ettin

