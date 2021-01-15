-- Huojin Quartermaster spawns
SET @CGUID:=452541;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,  68869, 1, 0, 0, 1, 0, 0, 0, 0, 2018.892, -4702.828,  28.6567, 1.336241,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Luo Luo (Area: Valley of Honor) (Auras: 19231 - Panda)
(@CGUID+1,  65061, 1, 0, 0, 1, 0, 0, 0, 0, 2025.543, -4714.884, 28.64906,  4.04744,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Brown Dragon Turtle (Area: Valley of Honor)
(@CGUID+2,  65076, 1, 0, 0, 1, 0, 0, 0, 0, 1998.417, -4720.981, 26.96154, 3.840174,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Brown Dragon Turtle (Area: Valley of Honor)
(@CGUID+3,  65063, 1, 0, 0, 1, 0, 0, 0, 0, 2034.248,  -4699.74, 28.42856,        0,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Purple Dragon Turtle (Area: Valley of Honor)
(@CGUID+4,  65008, 1, 0, 0, 1, 0, 0, 0, 0, 2024.453, -4698.135, 28.46393,  5.29936,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Huojin Monk (Area: Valley of Honor)
(@CGUID+5,  65078, 1, 0, 0, 1, 0, 0, 0, 0,  2003.93, -4716.698, 29.48287, 2.349095,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Purple Dragon Turtle (Area: Valley of Honor)
(@CGUID+6,  65008, 1, 0, 0, 1, 0, 0, 0, 0, 2022.241, -4712.988, 28.75003, 2.629947,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Huojin Monk (Area: Valley of Honor)
(@CGUID+7,  65008, 1, 0, 0, 1, 0, 0, 0, 0, 2017.882, -4711.019, 28.90924, 5.843568,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Huojin Monk (Area: Valley of Honor)
(@CGUID+8,  70301, 1, 0, 0, 1, 0, 0, 0, 0, 2010.891, -4722.866, 29.42734, 0.3832374, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Softpaws (Area: Valley of Honor)
(@CGUID+9,  69333, 1, 0, 0, 1, 0, 0, 0, 0, 2020.429, -4699.125, 28.59228, 6.155805,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Disciple Jusi (Area: Valley of Honor)
(@CGUID+10, 62445, 1, 0, 0, 1, 0, 0, 0, 0, 2023.177, -4704.495, 28.58364, 2.697362,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Ji Firepaw (Area: Valley of Honor)
(@CGUID+11, 65008, 1, 0, 0, 1, 0, 0, 0, 0, 2026.585, -4701.569, 28.44965, 2.062142,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Huojin Monk (Area: Valley of Honor)
(@CGUID+12, 66022, 1, 0, 0, 1, 0, 0, 0, 0, 2009.267, -4721.249, 29.59772, 1.031698,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Turtlemaster Odai (Area: Valley of Honor)
(@CGUID+13, 16868, 1, 0, 0, 1, 0, 0, 0, 0, 2027.552, -4723.238, 56.73496, 5.662436,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Winsum (Area: Valley of Honor) (Auras: )
(@CGUID+14, 16869, 1, 0, 0, 1, 0, 0, 0, 0, 2027.464, -4724.991, 56.70838, 0.02177187,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Jising (Area: Valley of Honor) (Auras: )
(@CGUID+15,  5034, 1, 0, 0, 1, 0, 0, 0, 0, 2029.007, -4721.863, 56.77607, 5.029046,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Winwa (Area: Valley of Honor) (Auras: )
(@CGUID+16, 65065, 1, 0, 0, 1, 0, 0, 0, 0, 2017.767, -4748.422, 25.56547, 0.8746974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Red Dragon Turtle (Area: Valley of Honor)
(@CGUID+17, 65071, 1, 0, 0, 1, 0, 0, 0, 0, 1998.502, -4730.889, 25.68424, 5.468535,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Green Dragon Turtle (Area: Valley of Honor)
(@CGUID+18, 65058, 1, 0, 0, 1, 0, 0, 0, 0, 2041.068, -4706.365,  28.4637, 5.445554,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Black Dragon Turtle (Area: Valley of Honor) (Auras: )
(@CGUID+19,  5029, 1, 0, 0, 1, 0, 0, 0, 0, 2030.547, -4722.234, 56.79307, 4.456704,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Jiming (Area: Valley of Honor) (Auras: )
(@CGUID+20, 65074, 1, 0, 0, 1, 0, 0, 0, 0, 2009.509, -4732.733, 27.37105, 3.833675,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Great Blue Dragon Turtle (Area: Valley of Honor)
(@CGUID+21, 65060, 1, 0, 0, 1, 0, 0, 0, 0, 2032.906, -4718.252, 28.33491, 4.387585,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Blue Dragon Turtle (Area: Valley of Honor)
(@CGUID+22,  2756, 1, 0, 0, 1, 0, 0, 0, 0, 2030.028,     -4725, 56.74546, 2.306456,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- Chao-Ju (Area: Valley of Honor) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0,  0, 0,        1,   1, 0, 0, 0, 0, '19231'), -- Luo Luo - 19231 - Panda
(@CGUID+1,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Brown Dragon Turtle
(@CGUID+2,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Great Brown Dragon Turtle
(@CGUID+3,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Purple Dragon Turtle
(@CGUID+4,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Huojin Monk
(@CGUID+5,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Great Purple Dragon Turtle
(@CGUID+6,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Huojin Monk
(@CGUID+7,  0, 0,        0,   1, 0, 0, 0, 0, ''), -- Huojin Monk
(@CGUID+8,  0, 0,        1, 257, 0, 0, 0, 0, ''), -- Softpaws
(@CGUID+9,  0, 0,        0, 257, 0, 0, 0, 0, ''), -- Disciple Jusi
(@CGUID+10, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Ji Firepaw
(@CGUID+11, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Huojin Monk
(@CGUID+12, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Turtlemaster Odai
(@CGUID+13, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Winsum
(@CGUID+14, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Jising
(@CGUID+15, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Winwa
(@CGUID+16, 0, 0, 50331648,   1, 0, 0, 0, 0, ''), -- Red Dragon Turtle
(@CGUID+17, 0, 0, 50331648,   1, 0, 0, 0, 0, ''), -- Great Green Dragon Turtle
(@CGUID+18, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Black Dragon Turtle
(@CGUID+19, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Jiming
(@CGUID+20, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Great Blue Dragon Turtle
(@CGUID+21, 0, 0,        0,   1, 0, 0, 0, 0, ''), -- Blue Dragon Turtle
(@CGUID+22, 0, 0,        0,   1, 0, 0, 0, 0, ''); -- Chao-Ju

DELETE FROM `creature_template_addon` WHERE `entry` IN (2756,5029,5034,16869,16868,66022,62445,69333,42548,70301,65008,68869);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(2756,  0, 0, 0,  1, 0, 0, 0, 0, ''), -- 2756 (Chao-Ju)
(5029,  0, 0, 0,  1, 0, 0, 0, 0, ''), -- 5029 (Jiming)
(5034,  0, 0, 0,  1, 0, 0, 0, 0, ''), -- 5034 (Winwa)
(16869, 0, 0, 0,  1, 0, 0, 0, 0, ''), -- 16869 (Jising)
(16868, 0, 0, 0,  1, 0, 0, 0, 0, ''), -- 16868 (Winsum)
(66022, 0, 0, 0,  1, 0, 0, 0, 0, ''), -- 66022 (Turtlemaster Odai)
(62445, 0, 0, 0,  1, 0, 0, 0, 0, ''), -- 62445 (Ji Firepaw)
(69333, 0, 0, 0,257, 0, 0, 0, 0, ''), -- 69333 (Disciple Jusi)
(42548, 0, 0, 0,  1, 0, 0, 0, 0, ''), -- 42548 (Muddy Crawfish)
(70301, 0, 0, 1,257, 0, 0, 0, 0, ''), -- 70301 (Softpaws)
(65008, 0, 0, 0,  1, 0, 0, 0, 0, ''), -- 65008 (Huojin Monk)
(68869, 0, 0, 1,  1, 0, 0, 0, 0, '19231'); -- 68869 (Luo Luo) - Panda

UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=65060; -- 65060 (Blue Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=65058; -- 65058 (Black Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=65071; -- 65071 (Great Green Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=65065; -- 65065 (Red Dragon Turtle)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=65061; -- 65061 (Brown Dragon Turtle)

UPDATE `creature_model_info` SET `VerifiedBuild`=23420 WHERE `DisplayID` IN(
802,901,1037,1332,1333,2956,4259,4601,4260,4602,5535,8971,
14415,15352,15369,15467,15984,15988,16074,18269,23513,27510,27823,28048,28118,28120,
32936,32937,32938,35192,35193,35194,35195,35198,35301,36585,36598,36615,37328,37329,37330,37331,39637,
42384,43669,44740,45170,45319,45320,45863,45864,45865,46093,47465,47982,48578,61763);

DELETE FROM `npc_vendor` WHERE (`entry`=69333 AND `item`=92070 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=69333 AND `item`=83080 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(69333, 2, 92070, 0, 0, 1, 19984, 0, 23420), -- Huojin Satchel
(69333, 1, 83080, 0, 0, 1,     0, 0, 23420); -- Huojin Tabard

DELETE FROM `gossip_menu` WHERE (`entry`=15500 AND `text_id`=22257) OR (`entry`=14248 AND `text_id`=20031);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(15500, 22257), -- 66022 (Turtlemaster Odai)
(14248, 20031); -- 62445 (Ji Firepaw)

DELETE FROM `npc_text` WHERE `ID`=22257;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(22257, 1, 0, 0, 0, 0, 0, 0, 0, 71584, 0, 0, 0, 0, 0, 0, 0, 23420); -- Turtlemaster Odai
