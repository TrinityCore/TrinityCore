-- Creature templates
UPDATE `creature_template` SET `faction`=1750, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=175184; -- Succubus Minion
UPDATE `creature_template` SET `faction`=49, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115695; -- Dampscale Patriarch
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=23383; -- Skyguard Prisoner
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags3`=8388608 WHERE `entry`=23257; -- Skyguard Windcharger
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=23029; -- Talonsworn Forest-Rager
UPDATE `creature_template` SET `speed_run`=2.142857074737548828 WHERE `entry`=22980; -- Skyguard Scout
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22463; -- Wounded Sha'tar Vindicator
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22457; -- Sand Gnome Trigger
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=22377; -- Akuno
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=22370; -- Mekeda
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=22365; -- Ethan
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=22340; -- Terokkar Arakkoa Fly Target
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=21963; -- Enslaved Doomguard
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=21902; -- Cabal Spell-weaver
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=21870; -- Unliving Initiate
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=21869; -- Unliving Guardian
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21856; -- Skettis Kneel Target 04
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21855; -- Skettis Arakkoa Spell Origin 02
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21794; -- Skettis Arakkoa Spell Origin 01
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21793; -- Skettis Kneel Target 03
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21792; -- Skettis Kneel Target 02
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21791; -- Skettis Kneel Target 01
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=21728; -- Skettis Surger
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=21661; -- Cabal Skirmisher
UPDATE `creature_template` SET `BaseAttackTime`=1200 WHERE `entry`=21504; -- Pathaleon the Calculator's Image
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=21317; -- Aimi
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=20895; -- Miiji
UPDATE `creature_template` SET `npcflag`=640 WHERE `entry`=20892; -- Ruogo
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=19847; -- Levixus
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=19718; -- Provisioner Tsaalt
UPDATE `creature_template` SET `unit_flags`=33280 WHERE `entry`=18760; -- Isla Starmane
UPDATE `creature_template` SET `BaseAttackTime`=3000 WHERE `entry`=18685; -- Okrek
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18675; -- Soolaveen
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18647; -- Deathskitter
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=18480; -- Broken Corpse
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=17076; -- Lady Liadrin
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=8912896 WHERE `entry`=15241; -- Gryphon Rider Guard
UPDATE `creature_template` SET `unit_flags3`=8912896 WHERE `entry`=2615; -- Air Force Alarm Bot (Horde)
UPDATE `creature_template` SET `unit_flags3`=8912896 WHERE `entry`=2614; -- Air Force Alarm Bot (Alliance)

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry`=21724);
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (175184,24893,23415,23383,23367,23363,23306,23257,23219,23093,23092,23051,23048,23042,23038,23029,23016,22991,22986,22982,22980,22831,22807,22481,22477,22476,22464,22463,22462,22458,22457,22456,22453,22446,22441,22424,22420,22407,22388,22387,22381,22378,22377,22371,22370,22365,22364,22355,22340,22314,22288,22278,22272,22105,22100,22045,21967,21963,21957,21941,21911,21907,21903,21902,21899,21898,21870,21869,21859,21858,21856,21855,21852,21846,21804,21794,21793,21792,21791,21728,21724,21723,21662,21661,21660,21654,21650,21649,21644,21504,21465,21368,21324,21317,21313,21285,21284,21242,21200,21198,21039,21007,20986,20895,20894,20893,20892,20891,20890,20877,20876,20874,20809,20767,19847,19718,19697,19693,19689,19679,19677,19676,19674,19673,19672,19659,19417,18843,18760,18717,18716,18707,18685,18675,18670,18647,18588,18566,18554,18548,18541,18540,18539,18490,18480,18475,18460,18455,18454,18453,18452,18438,18424,18273,18262,18260,17143,16805,16769,15241,5355,2614,1410,115695,62583,61440,61255,61142,61081,49833,25580,24905,24886,24885,23131,23102,23094,23091,22307,22095,22001,21999,21996,21993,21854,21849,21636,21515,21489,21463,21451,21443,21429,21405,21400,21399,21398,21397,21370,21194,21193,21192,21188,19773,19772,19607,19606,19296,19181,19159,19154,19147,19056,19053,19048,19042,19038,19003,19002,19000,18999,18984,18973,18962,18960,18959,18957,18809,18807,18750,18745,18720,18719,18718,18714,18713,18712,18705,18704,18676,18595,18583,18492,18477,18476,18470,18469,18468,18467,18466,18465,18464,18463,18461,18459,18457,18456,18451,18450,18449,18447,18446,18437,18390,18389,18387,18386,18385,18384,18383,18252,18249,17467,17142,17088,17076,16932,16899,16898,16810,16772,16519,15991,2615,385));
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (175184,24893,23415,23383,23367,23363,23306,23257,23219,23093,23092,23051,23048,23042,23038,23029,23016,22991,22986,22982,22980,22831,22807,22481,22477,22476,22464,22463,22462,22458,22457,22456,22453,22446,22441,22424,22420,22407,22388,22387,22381,22378,22377,22371,22370,22365,22364,22355,22340,22314,22288,22278,22272,22105,22100,22045,21967,21963,21957,21941,21911,21907,21903,21902,21899,21898,21870,21869,21859,21858,21856,21855,21852,21846,21804,21794,21793,21792,21791,21728,21724,21723,21662,21661,21660,21654,21650,21649,21644,21504,21465,21368,21324,21317,21313,21285,21284,21242,21200,21198,21039,21007,20986,20895,20894,20893,20892,20891,20890,20877,20876,20874,20809,20767,19847,19718,19697,19693,19689,19679,19677,19676,19674,19673,19672,19659,19417,18843,18760,18717,18716,18707,18685,18675,18670,18647,18588,18566,18554,18548,18541,18540,18539,18490,18480,18475,18460,18455,18454,18453,18452,18438,18424,18273,18262,18260,17143,16805,16769,15241,5355,2614,1410));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(175184, 0, 0, 0, 39, 1, 0.699999988079071044, 0.870000004768371582, 197795, 0, 0, 48526),
(24893, 0, 0, 0, 39, 1, 1.35000002384185791, 1, 22944, 0, 0, 48526),
(23415, 0, 0, 0, 39, 1, 1, 1, 19724, 0, 0, 48526),
(23383, 0, 0, 0, 39, 1, 1, 1, 19679, 4096, 0, 48526),
(23367, 0, 0, 0, 39, 1, 1, 1, 19657, 0, 0, 48526),
(23363, 0, 0, 0, 39, 1, 1, 1, 19646, 0, 0, 48526),
(23306, 0, 0, 0, 39, 1, 1, 1, 19525, 0, 0, 48526),
(23257, 0, 0, 0, 39, 1, 6, 1, 19433, 0, 0, 48526),
(23219, 0, 0, 0, 39, 1, 1, 1, 19357, 1, 0, 48526),
(23093, 0, 0, 0, 39, 1, 1, 1, 19085, 0, 0, 48526),
(23092, 0, 0, 0, 39, 1, 1, 1, 19083, 0, 0, 48526),
(23051, 0, 0, 0, 39, 1, 1, 1, 19001, 1, 0, 48526),
(23048, 0, 0, 0, 39, 1, 1, 1, 18995, 0, 0, 48526),
(23042, 0, 0, 0, 39, 1, 1, 1, 18983, 0, 0, 48526),
(23038, 0, 0, 0, 39, 1, 1, 1, 18975, 128, 0, 48526),
(23029, 0, 0, 0, 39, 1, 4, 3, 18953, 256, 0, 48526),
(23016, 0, 0, 0, 39, 1, 1, 1, 18929, 0, 0, 48526),
(22991, 0, 0, 0, 39, 1, 1.35000002384185791, 1, 18879, 0, 0, 48526),
(22986, 0, 0, 0, 39, 1, 1, 1, 18869, 0, 0, 48526),
(22982, 0, 0, 0, 39, 1, 1, 1, 18861, 0, 0, 48526),
(22980, 0, 0, 0, 39, 1, 1, 1, 18857, 0, 0, 48526),
(22831, 0, 0, 0, 39, 1, 1, 1, 18562, 0, 0, 48526),
(22807, 0, 0, 0, 39, 1, 1, 1, 18518, 1, 0, 48526),
(22481, 0, 0, 0, 39, 1, 1, 1, 18420, 0, 0, 48526),
(22477, 0, 0, 0, 39, 1, 2, 1, 18412, 0, 0, 48526),
(22476, 0, 0, 0, 39, 1, 2, 1, 18411, 0, 0, 48526),
(22464, 0, 0, 0, 39, 1, 1, 1, 18387, 4096, 0, 48526),
(22463, 0, 0, 0, 39, 1, 3, 1, 18385, 0, 0, 48526),
(22462, 0, 0, 0, 39, 1, 3, 1, 18383, 0, 0, 48526),
(22458, 0, 0, 0, 39, 1, 1, 1, 18374, 4096, 0, 48526),
(22457, 0, 0, 0, 39, 1, 1, 1, 18372, 0, 0, 48526),
(22456, 0, 0, 0, 39, 1, 3, 1, 18370, 0, 0, 48526),
(22453, 0, 0, 0, 39, 1, 3, 1, 18364, 0, 0, 48526),
(22446, 0, 0, 0, 39, 1, 1, 1, 18349, 0, 0, 48526),
(22441, 0, 0, 0, 39, 1, 2, 1, 18339, 2147483688, 0, 48526),
(22424, 0, 0, 0, 39, 1, 1, 1, 18304, 4096, 0, 48526),
(22420, 0, 0, 0, 39, 1, 1, 1, 18296, 0, 0, 48526),
(22407, 0, 0, 0, 2109, 9, 3, 1, 18271, 0, 0, 48526),
(22388, 0, 0, 0, 39, 1, 1, 1, 18224, 0, 0, 48526),
(22387, 0, 0, 0, 39, 1, 1, 1, 18221, 0, 0, 48526),
(22381, 0, 0, 0, 39, 1, 1.20000004768371582, 1, 18210, 0, 0, 48526),
(22378, 0, 0, 0, 39, 1, 1, 1, 18203, 0, 0, 48526),
(22377, 0, 0, 0, 39, 1, 1.299999952316284179, 1, 18201, 0, 0, 48526),
(22371, 0, 0, 0, 39, 1, 1, 1, 18188, 0, 0, 48526),
(22370, 0, 0, 0, 39, 1, 1.299999952316284179, 1, 18186, 0, 0, 48526),
(22365, 0, 0, 0, 39, 1, 1, 1, 18174, 0, 0, 48526),
(22364, 0, 0, 0, 39, 1, 1, 1, 18172, 0, 0, 48526),
(22355, 0, 0, 0, 39, 1, 0.100000001490116119, 1, 18152, 8, 0, 48526),
(22340, 0, 0, 0, 39, 1, 1, 1, 18121, 0, 0, 48526),
(22314, 0, -4, -4, 1723, 9, 1, 1, 18071, 0, 0, 48526),
(22288, 0, 0, 0, 39, 1, 1, 1, 18010, 0, 0, 48526),
(22278, 0, 0, 0, 39, 1, 2, 1, 17988, 0, 0, 48526),
(22272, 0, 0, 0, 39, 1, 1, 1, 17974, 0, 0, 48526),
(22105, 0, 0, 0, 39, 1, 1, 1, 17735, 65537, 0, 48526),
(22100, 0, 0, 0, 39, 1, 1, 1, 17730, 1, 0, 48526),
(22045, 0, 0, 0, 39, 1, 1, 1, 17676, 0, 0, 48526),
(21967, 0, 0, 0, 39, 1, 1, 1, 17603, 0, 0, 48526),
(21963, 0, 0, 0, 39, 1, 1, 1, 17599, 0, 0, 48526),
(21957, 0, 0, 0, 39, 1, 1, 1, 17593, 0, 0, 48526),
(21941, 0, 0, 0, 39, 1, 1, 1, 17579, 0, 0, 48526),
(21911, 0, 0, 0, 39, 1, 1, 1, 17554, 0, 0, 48526),
(21907, 0, 0, 0, 39, 1, 1, 1, 17550, 0, 0, 48526),
(21903, 0, 0, 0, 39, 1, 1, 1, 17544, 0, 0, 48526),
(21902, 0, 0, 0, 39, 1, 1, 1, 17543, 0, 0, 48526),
(21899, 0, 0, 0, 39, 1, 1, 1, 17540, 0, 0, 48526),
(21898, 0, 0, 0, 39, 1, 1, 1, 17539, 0, 0, 48526),
(21870, 0, 0, 0, 39, 1, 1, 1, 17506, 2, 0, 48526),
(21869, 0, 0, 0, 39, 1, 1, 1, 17505, 2, 0, 48526),
(21859, 0, 0, 0, 39, 1, 1, 1, 17493, 16, 0, 48526),
(21858, 0, 0, 0, 2109, 9, 3, 1, 17492, 0, 0, 48526),
(21856, 0, 0, 0, 39, 1, 1, 1, 17490, 0, 0, 48526),
(21855, 0, 0, 0, 39, 1, 1, 1, 17489, 0, 0, 48526),
(21852, 0, 0, 0, 39, 1, 1, 1, 17486, 0, 0, 48526),
(21846, 0, 0, 0, 39, 1, 1, 1, 17480, 16, 0, 48526),
(21804, 0, 0, 0, 39, 1, 0.449999988079071044, 0.300000011920928955, 17442, 1, 0, 48526),
(21794, 0, 0, 0, 39, 1, 1, 1, 17432, 0, 0, 48526),
(21793, 0, 0, 0, 39, 1, 1, 1, 17431, 0, 0, 48526),
(21792, 0, 0, 0, 39, 1, 1, 1, 17430, 0, 0, 48526),
(21791, 0, 0, 0, 39, 1, 1, 1, 17429, 0, 0, 48526),
(21728, 0, 0, 0, 39, 1, 1, 1, 17368, 0, 0, 48526),
(21724, 0, 0, 0, 39, 1, 2, 1, 17364, 1, 0, 48526),
(21723, 0, 0, 0, 39, 1, 1.299999952316284179, 1, 17363, 1, 0, 48526),
(21662, 0, 0, 0, 39, 1, 1, 1, 17292, 0, 0, 48526),
(21661, 0, 0, 0, 39, 1, 1, 1, 17291, 0, 0, 48526),
(21660, 0, 0, 0, 39, 1, 1, 1, 17290, 0, 0, 48526),
(21654, 0, 0, 0, 39, 1, 1, 1, 17284, 16, 0, 48526),
(21650, 0, 0, 0, 39, 1, 1, 1, 17280, 0, 0, 48526),
(21649, 0, 0, 0, 39, 1, 1, 1, 17279, 0, 0, 48526),
(21644, 0, 0, 0, 39, 1, 1, 1, 17277, 0, 0, 48526),
(21504, 0, 0, 0, 37, 1, 17, 10, 17245, 0, 0, 48526),
(21465, 0, 0, 0, 39, 1, 1, 1, 17203, 0, 0, 48526),
(21368, 0, 0, 0, 39, 1, 1, 1, 17106, 0, 0, 48526),
(21324, 0, 0, 0, 39, 1, 1, 1, 17059, 0, 0, 48526),
(21317, 0, -4, -4, 1723, 9, 1, 1, 17052, 0, 0, 48526),
(21313, 0, 0, 0, 40, 1, 1, 1, 17048, 0, 0, 48526),
(21285, 0, 0, 0, 39, 1, 1, 1, 17014, 0, 0, 48526),
(21284, 0, 0, 0, 39, 1, 1, 1, 17013, 0, 0, 48526),
(21242, 0, 0, 0, 39, 1, 1, 1, 16973, 0, 0, 48526),
(21200, 0, 0, 0, 39, 1, 1, 1, 16931, 0, 0, 48526),
(21198, 0, 0, 0, 39, 1, 1, 1, 16929, 0, 0, 48526),
(21039, 0, 0, 0, 39, 1, 1, 1, 16748, 0, 0, 48526),
(21007, 0, 0, 0, 39, 1, 1, 1, 16717, 0, 0, 48526),
(20986, 0, 0, 0, 39, 1, 1.25, 1, 16697, 0, 0, 48526),
(20895, 0, -4, -4, 1723, 9, 1, 1, 16572, 0, 0, 48526),
(20894, 0, -4, -4, 1723, 9, 1, 1, 16571, 0, 0, 48526),
(20893, 0, 0, 0, 39, 1, 2, 1, 16570, 0, 0, 48526),
(20892, 0, 0, 0, 39, 1, 2, 1, 16569, 0, 0, 48526),
(20891, 0, 0, 0, 39, 1, 2, 1, 16568, 0, 0, 48526),
(20890, 0, 0, 0, 39, 1, 2, 1, 16567, 0, 0, 48526),
(20877, 0, 0, 0, 39, 1, 1.20000004768371582, 1, 16540, 0, 0, 48526),
(20876, 0, 0, 0, 39, 1, 1.20000004768371582, 1, 16539, 0, 0, 48526),
(20874, 0, 0, 0, 39, 1, 1, 1, 16535, 0, 0, 48526),
(20809, 0, 0, 0, 39, 1, 1, 1, 16450, 0, 0, 48526),
(20767, 0, 0, 0, 39, 1, 1, 1, 16408, 0, 0, 48526),
(19847, 0, 0, 0, 39, 1, 2, 3, 15716, 2147483648, 0, 48526),
(19718, 0, 0, 0, 39, 1, 1, 1, 15584, 0, 0, 48526),
(19697, 0, 0, 0, 39, 1, 1, 1, 15559, 0, 0, 48526),
(19693, 0, 0, 0, 39, 1, 1, 1, 15555, 0, 0, 48526),
(19689, 0, 0, 0, 39, 1, 1, 1, 15551, 0, 0, 48526),
(19679, 0, 0, 0, 39, 1, 5, 3, 15541, 0, 0, 48526),
(19677, 0, -1, 0, 222, 1, 5, 3, 15539, 0, 0, 48526),
(19676, 0, 0, 0, 39, 1, 5, 3, 15538, 0, 0, 48526),
(19674, 0, 0, 0, 39, 1, 1, 1, 15536, 0, 0, 48526),
(19673, 0, -1, 1, 222, 1, 5, 3, 15535, 0, 0, 48526),
(19672, 0, -3, 0, 222, 1, 5, 3, 15534, 0, 0, 48526),
(19659, 0, 0, 0, 872, 9, 1, 1, 15521, 0, 0, 48526),
(19417, 0, 0, 0, 39, 1, 1, 1, 15243, 0, 0, 48526),
(18843, 0, 0, 0, 40, 1, 1, 1, 14620, 0, 0, 48526),
(18760, 0, 0, 0, 39, 1, 1.25, 1.25, 14521, 4096, 0, 48526),
(18717, 0, 0, 0, 39, 1, 1, 1, 14473, 0, 0, 48526),
(18716, 0, 0, 0, 39, 1, 1, 1, 14472, 0, 0, 48526),
(18707, 0, 0, 0, 39, 1, 2, 1, 14464, 2147483649, 0, 48526),
(18685, 0, 0, 0, 39, 1, 2, 5, 14434, 0, 0, 48526),
(18675, 0, 0, 0, 39, 1, 1, 1, 14424, 0, 0, 48526),
(18670, 0, 0, 0, 39, 1, 1, 1, 14417, 1, 0, 48526),
(18647, 0, 0, 0, 39, 1, 4, 1, 14390, 1, 0, 48526),
(18588, 0, 0, 0, 39, 1, 2, 2, 14329, 2147483648, 0, 48526),
(18566, 0, 0, 0, 39, 1, 1, 1, 14317, 0, 0, 48526),
(18554, 0, 0, 0, 39, 1, 2.5, 1, 14298, 0, 0, 48526),
(18548, 0, 0, 0, 39, 1, 1.299999952316284179, 1, 14292, 0, 0, 48526),
(18541, 0, 0, 0, 39, 1, 2, 1, 14285, 2147483648, 0, 48526),
(18540, 0, 0, 0, 39, 1, 2, 1, 14284, 2147483648, 0, 48526),
(18539, 0, 0, 0, 39, 1, 2, 1, 14283, 2147483648, 0, 48526),
(18490, 0, 0, 0, 39, 1, 1, 1, 14228, 0, 0, 48526),
(18480, 0, 0, 0, 39, 1, 1, 1, 14218, 128, 0, 48526),
(18475, 0, 0, 0, 39, 1, 1, 1, 14211, 0, 0, 48526),
(18460, 0, 0, 0, 39, 1, 1, 1, 14192, 0, 0, 48526),
(18455, 0, 0, 0, 39, 1, 1, 1, 14187, 0, 0, 48526),
(18454, 0, 0, 0, 39, 1, 1, 1, 14186, 0, 0, 48526),
(18453, 0, 0, 0, 39, 1, 1, 1, 14185, 0, 0, 48526),
(18452, 0, 0, 0, 39, 1, 1, 1, 14184, 0, 0, 48526),
(18438, 0, 0, 0, 39, 1, 2, 1, 14168, 2147483649, 0, 48526),
(18424, 0, 0, 0, 39, 1, 1, 1, 14153, 0, 0, 48526),
(18273, 0, 0, 0, 39, 1, 11, 1, 13944, 0, 0, 48526),
(18262, 0, 0, 0, 39, 1, 1.75, 1, 13933, 0, 0, 48526),
(18260, 0, 0, 0, 39, 1, 1, 1, 13931, 0, 0, 48526),
(17143, 0, 0, 0, 39, 1, 1, 1, 12532, 0, 0, 48526),
(16805, 0, 0, 0, 39, 1, 1, 1, 12185, 0, 0, 48526),
(16769, 0, 0, 0, 39, 1, 1, 1, 12147, 0, 0, 48526),
(15241, 0, 0, 0, 777, 1, 2, 1, 10504, 8, 0, 48526),
(5355, 0, 0, 0, 39, 1, 1, 1, 4606, 0, 0, 48526),
(2614, 0, 0, 0, 777, 1, 1.10000002384185791, 1, 2206, 0, 0, 48526),
(1410, 0, 0, 0, 39, 1, 1, 1, 1123, 0, 0, 48526);

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=48526 WHERE (`DifficultyID`=0 AND `Entry` IN (115695,62583,61440,61255,61142,61081,49833,25580,24905,24886,24885,23131,23102,23094,23091,22307,22095,22001,21999,21996,21993,21854,21849,21636,21515,21489,21463,21451,21443,21429,21405,21400,21399,21398,21397,21370,21194,21193,21192,21188,19773,19772,19607,19606,19296,19181,19159,19154,19147,19056,19053,19048,19042,19038,19003,19002,19000,18999,18984,18973,18962,18960,18959,18957,18809,18807,18750,18745,18720,18719,18718,18714,18713,18712,18705,18704,18676,18595,18583,18492,18477,18476,18470,18469,18468,18467,18466,18465,18464,18463,18461,18459,18457,18456,18451,18450,18449,18447,18446,18437,18390,18389,18387,18386,18385,18384,18383,18252,18249,17467,17142,17088,17076,16932,16899,16898,16810,16772,16519,15991,2615,385));
UPDATE `creature_template_difficulty` SET `DamageModifier`=4.6 WHERE (`DifficultyID`=0 AND `Entry` IN (18647,18273,18707,19674,19676,23257,19847,21465,21504,23029,21858,22463,22446,15241,22453,22456,22462,18588));
UPDATE `creature_template_difficulty` SET `DamageModifier`=7.5 WHERE (`DifficultyID`=0 AND `Entry` IN (19677,21724,22441));
UPDATE `creature_template_difficulty` SET `LootID`=1410, `PickPocketLootID`=1410, `SkinLootID`=0, `GoldMin`=957, `GoldMax`=1288 WHERE `DifficultyID`=0 AND `Entry`=1410;
UPDATE `creature_template_difficulty` SET `LootID`=5355, `PickPocketLootID`=5355, `SkinLootID`=0, `GoldMin`=952, `GoldMax`=1177 WHERE `DifficultyID`=0 AND `Entry`=5355;
UPDATE `creature_template_difficulty` SET `LootID`=16769, `PickPocketLootID`=16769, `SkinLootID`=0, `GoldMin`=897, `GoldMax`=1084 WHERE `DifficultyID`=0 AND `Entry`=16769;
UPDATE `creature_template_difficulty` SET `LootID`=16805, `PickPocketLootID`=16805, `SkinLootID`=0, `GoldMin`=179, `GoldMax`=239 WHERE `DifficultyID`=0 AND `Entry`=16805;
UPDATE `creature_template_difficulty` SET `LootID`=17143, `PickPocketLootID`=17143, `SkinLootID`=0, `GoldMin`=146, `GoldMax`=196 WHERE `DifficultyID`=0 AND `Entry`=17143;
UPDATE `creature_template_difficulty` SET `LootID`=18260, `PickPocketLootID`=18260, `SkinLootID`=0, `GoldMin`=175, `GoldMax`=233 WHERE `DifficultyID`=0 AND `Entry`=18260;
UPDATE `creature_template_difficulty` SET `LootID`=0, `PickPocketLootID`=18262, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=18262;
UPDATE `creature_template_difficulty` SET `LootID`=18438, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=18438;
UPDATE `creature_template_difficulty` SET `LootID`=18452, `PickPocketLootID`=18452, `SkinLootID`=0, `GoldMin`=174, `GoldMax`=232 WHERE `DifficultyID`=0 AND `Entry`=18452;
UPDATE `creature_template_difficulty` SET `LootID`=18453, `PickPocketLootID`=18453, `SkinLootID`=0, `GoldMin`=148, `GoldMax`=199 WHERE `DifficultyID`=0 AND `Entry`=18453;
UPDATE `creature_template_difficulty` SET `LootID`=18454, `PickPocketLootID`=18454, `SkinLootID`=0, `GoldMin`=170, `GoldMax`=226 WHERE `DifficultyID`=0 AND `Entry`=18454;
UPDATE `creature_template_difficulty` SET `LootID`=18455, `PickPocketLootID`=18455, `SkinLootID`=0, `GoldMin`=153, `GoldMax`=205 WHERE `DifficultyID`=0 AND `Entry`=18455;
UPDATE `creature_template_difficulty` SET `LootID`=18460, `PickPocketLootID`=18460, `SkinLootID`=0, `GoldMin`=179, `GoldMax`=239 WHERE `DifficultyID`=0 AND `Entry`=18460;
UPDATE `creature_template_difficulty` SET `LootID`=18475, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=18475;
UPDATE `creature_template_difficulty` SET `LootID`=18539, `PickPocketLootID`=18539, `SkinLootID`=0, `GoldMin`=162, `GoldMax`=217 WHERE `DifficultyID`=0 AND `Entry`=18539;
UPDATE `creature_template_difficulty` SET `LootID`=18540, `PickPocketLootID`=18540, `SkinLootID`=0, `GoldMin`=170, `GoldMax`=226 WHERE `DifficultyID`=0 AND `Entry`=18540;
UPDATE `creature_template_difficulty` SET `LootID`=18541, `PickPocketLootID`=18541, `SkinLootID`=0, `GoldMin`=174, `GoldMax`=232 WHERE `DifficultyID`=0 AND `Entry`=18541;
UPDATE `creature_template_difficulty` SET `LootID`=18548, `PickPocketLootID`=18548, `SkinLootID`=0, `GoldMin`=869, `GoldMax`=1000 WHERE `DifficultyID`=0 AND `Entry`=18548;
UPDATE `creature_template_difficulty` SET `LootID`=18554, `PickPocketLootID`=18554, `SkinLootID`=0, `GoldMin`=307, `GoldMax`=406 WHERE `DifficultyID`=0 AND `Entry`=18554;
UPDATE `creature_template_difficulty` SET `LootID`=18588, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=580, `GoldMax`=762 WHERE `DifficultyID`=0 AND `Entry`=18588;
UPDATE `creature_template_difficulty` SET `LootID`=18647, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=1083, `GoldMax`=1420 WHERE `DifficultyID`=0 AND `Entry`=18647;
UPDATE `creature_template_difficulty` SET `LootID`=18670, `PickPocketLootID`=0, `SkinLootID`=70061, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=18670;
UPDATE `creature_template_difficulty` SET `LootID`=18685, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=245, `GoldMax`=325 WHERE `DifficultyID`=0 AND `Entry`=18685;
UPDATE `creature_template_difficulty` SET `LootID`=18707, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=18707;
UPDATE `creature_template_difficulty` SET `LootID`=19847, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=2574, `GoldMax`=3367 WHERE `DifficultyID`=0 AND `Entry`=19847;
UPDATE `creature_template_difficulty` SET `LootID`=21198, `PickPocketLootID`=21198, `SkinLootID`=0, `GoldMin`=175, `GoldMax`=233 WHERE `DifficultyID`=0 AND `Entry`=21198;
UPDATE `creature_template_difficulty` SET `LootID`=21200, `PickPocketLootID`=21200, `SkinLootID`=0, `GoldMin`=146, `GoldMax`=196 WHERE `DifficultyID`=0 AND `Entry`=21200;
UPDATE `creature_template_difficulty` SET `LootID`=21242, `PickPocketLootID`=21242, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21242;
UPDATE `creature_template_difficulty` SET `LootID`=21284, `PickPocketLootID`=21284, `SkinLootID`=0, `GoldMin`=182, `GoldMax`=242 WHERE `DifficultyID`=0 AND `Entry`=21284;
UPDATE `creature_template_difficulty` SET `LootID`=21285, `PickPocketLootID`=21285, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21285;
UPDATE `creature_template_difficulty` SET `LootID`=21324, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21324;
UPDATE `creature_template_difficulty` SET `LootID`=21368, `PickPocketLootID`=21368, `SkinLootID`=0, `GoldMin`=177, `GoldMax`=236 WHERE `DifficultyID`=0 AND `Entry`=21368;
UPDATE `creature_template_difficulty` SET `LootID`=21644, `PickPocketLootID`=21644, `SkinLootID`=0, `GoldMin`=254, `GoldMax`=337 WHERE `DifficultyID`=0 AND `Entry`=21644;
UPDATE `creature_template_difficulty` SET `LootID`=21649, `PickPocketLootID`=21649, `SkinLootID`=0, `GoldMin`=216, `GoldMax`=287 WHERE `DifficultyID`=0 AND `Entry`=21649;
UPDATE `creature_template_difficulty` SET `LootID`=21650, `PickPocketLootID`=21650, `SkinLootID`=0, `GoldMin`=207, `GoldMax`=276 WHERE `DifficultyID`=0 AND `Entry`=21650;
UPDATE `creature_template_difficulty` SET `LootID`=21660, `PickPocketLootID`=21660, `SkinLootID`=0, `GoldMin`=146, `GoldMax`=196 WHERE `DifficultyID`=0 AND `Entry`=21660;
UPDATE `creature_template_difficulty` SET `LootID`=21661, `PickPocketLootID`=21661, `SkinLootID`=0, `GoldMin`=172, `GoldMax`=229 WHERE `DifficultyID`=0 AND `Entry`=21661;
UPDATE `creature_template_difficulty` SET `LootID`=21662, `PickPocketLootID`=21662, `SkinLootID`=0, `GoldMin`=172, `GoldMax`=229 WHERE `DifficultyID`=0 AND `Entry`=21662;
UPDATE `creature_template_difficulty` SET `LootID`=21723, `PickPocketLootID`=0, `SkinLootID`=70064, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21723;
UPDATE `creature_template_difficulty` SET `LootID`=21724, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21724;
UPDATE `creature_template_difficulty` SET `LootID`=21728, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21728;
UPDATE `creature_template_difficulty` SET `LootID`=21804, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21804;
UPDATE `creature_template_difficulty` SET `LootID`=21902, `PickPocketLootID`=21902, `SkinLootID`=0, `GoldMin`=143, `GoldMax`=192 WHERE `DifficultyID`=0 AND `Entry`=21902;
UPDATE `creature_template_difficulty` SET `LootID`=21907, `PickPocketLootID`=21907, `SkinLootID`=0, `GoldMin`=145, `GoldMax`=195 WHERE `DifficultyID`=0 AND `Entry`=21907;
UPDATE `creature_template_difficulty` SET `LootID`=21911, `PickPocketLootID`=21911, `SkinLootID`=0, `GoldMin`=216, `GoldMax`=287 WHERE `DifficultyID`=0 AND `Entry`=21911;
UPDATE `creature_template_difficulty` SET `LootID`=21941, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=21941;
UPDATE `creature_template_difficulty` SET `LootID`=21963, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=141, `GoldMax`=189 WHERE `DifficultyID`=0 AND `Entry`=21963;
UPDATE `creature_template_difficulty` SET `LootID`=22045, `PickPocketLootID`=22045, `SkinLootID`=0, `GoldMin`=184, `GoldMax`=245 WHERE `DifficultyID`=0 AND `Entry`=22045;
UPDATE `creature_template_difficulty` SET `LootID`=22100, `PickPocketLootID`=0, `SkinLootID`=70061, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=22100;
UPDATE `creature_template_difficulty` SET `LootID`=22105, `PickPocketLootID`=0, `SkinLootID`=70061, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=22105;
UPDATE `creature_template_difficulty` SET `LootID`=22378, `PickPocketLootID`=22378, `SkinLootID`=0, `GoldMin`=153, `GoldMax`=205 WHERE `DifficultyID`=0 AND `Entry`=22378;
UPDATE `creature_template_difficulty` SET `LootID`=0, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=173, `GoldMax`=231 WHERE `DifficultyID`=0 AND `Entry`=22381;
UPDATE `creature_template_difficulty` SET `LootID`=22387, `PickPocketLootID`=22387, `SkinLootID`=0, `GoldMin`=153, `GoldMax`=205 WHERE `DifficultyID`=0 AND `Entry`=22387;
UPDATE `creature_template_difficulty` SET `LootID`=22388, `PickPocketLootID`=22388, `SkinLootID`=0, `GoldMin`=174, `GoldMax`=232 WHERE `DifficultyID`=0 AND `Entry`=22388;
UPDATE `creature_template_difficulty` SET `LootID`=22807, `PickPocketLootID`=0, `SkinLootID`=70064, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=22807;
UPDATE `creature_template_difficulty` SET `LootID`=23029, `PickPocketLootID`=0, `SkinLootID`=80002, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=23029;
UPDATE `creature_template_difficulty` SET `LootID`=23051, `PickPocketLootID`=0, `SkinLootID`=0, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=23051;
UPDATE `creature_template_difficulty` SET `LootID`=23219, `PickPocketLootID`=0, `SkinLootID`=70161, `GoldMin`=0, `GoldMax`=0 WHERE `DifficultyID`=0 AND `Entry`=23219;

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=48526 WHERE `DisplayID` IN (1281, 4162, 20848, 45998, 5905, 36616, 36617, 2957, 15469, 23548, 22910, 22730, 22717, 22716, 21478, 21436, 18634, 21182, 23003, 21261, 17868, 21396, 21228, 21227, 21215, 21213, 21458, 21158, 17188, 21169, 21194, 21184, 21044, 17248, 17216, 16379, 16381, 21037, 21031, 21038, 16491, 21023, 21018, 20998, 21036, 21057, 21056, 21053, 21032, 17869, 19912, 20961, 7804, 20962, 7935, 16213, 80, 12929, 14501, 4616, 37744, 20790, 6351, 5265, 1196, 14707, 16269, 4629, 20696, 20695, 20597, 20693, 20692, 20694, 20564, 20565, 21081, 21082, 20755, 20753, 20752, 20754, 16878, 20617, 20183, 20184, 15880, 5564, 20425, 20424, 20396, 20395, 20394, 20563, 20393, 20537, 20391, 20562, 23501, 17864, 20602, 18628, 20289, 20348, 20343, 17612, 20296, 19595, 20024, 21113, 20269, 20268, 20267, 20266, 19646, 20534, 20223, 19581, 20189, 20188, 20187, 20190, 20186, 20185, 20744, 20165, 20152, 20137, 20145, 20143, 20141, 20140, 19984, 19957, 19335, 17440, 17494, 1404, 16924, 18616, 19214, 19522, 19523, 20660, 19144, 19140, 19138, 19134, 19654, 19105, 21020, 19627, 19645, 17906, 19036, 19028, 18838, 18711, 2585, 644, 18556, 18547, 18546, 18493, 18492, 18483, 18484, 18491, 18478, 18446, 18444, 18829, 18436, 18435, 18830, 18438, 18440, 18439, 18437, 18415, 4602, 4260, 4601, 4259, 4559, 18421, 3737, 5706, 5771, 2577, 18827, 31984, 18146, 18127, 18108, 17978, 18125, 18121, 18097, 18096, 18095, 37578, 18087, 18086, 62616, 21039, 18063, 18923, 18216, 18012, 18003, 17976, 17958, 17900, 17860, 70783, 17849, 17847, 17850, 17848, 17833, 11417, 11419, 1192, 17574, 8271, 19998, 20025, 17812, 16876, 17811, 18073, 18072, 17810, 18427, 18428, 17809, 17808, 17806, 17805, 16875, 17005, 17006, 17807, 17804, 17798, 17795, 2281, 18100, 17737, 17736, 17735, 17734, 17731, 17730, 17650, 11546, 11551, 17639, 17636, 16633, 17973, 17974, 18133, 17988, 18132, 18130, 16820, 19844, 18215, 18825, 18824, 18826, 18213, 18206, 18205, 18207, 18208, 18113, 18112, 18111, 17981, 15947, 17202, 18196, 18198, 18199, 18197, 6303, 2958, 134, 18201, 18200, 18202, 18203, 229);
UPDATE `creature_model_info` SET `CombatReach`=1.016326546669006347, `VerifiedBuild`=48526 WHERE `DisplayID`=20738;
UPDATE `creature_template_model` SET `VerifiedBuild`=48526 WHERE (`Idx`=0 AND `CreatureID` IN (23042,21654,18685,21907,21284,21313,16805,22095,21397,18437,23415,22982,19697,22105,22476,22453,21285,61440,18716,18386,19773,18583,61255,18450,18476,18714,22980,23051,19672,22272,18453,15241,18595,23131,18959,21398,18390,16899,21007,18480,21855,22371,21846,22420,18262,18843,21324,18718,23091,23093,23094,24905,18745,19000,21039,1410,18492,18539,23029,22831,21957,22463,22446,20874,24893,21429,22424,19606,18447,18973,18468,18466,23383,23363,21856,21650,22481,22364,22307,18452,17088,18389,21911,19693,19676,22462,20891,21849,21368,21405,18541,18676,385,16810,20767,21504,18438,18464,18457,21903,21963,22457,21869,18675,20894,21858,18588,175184,18712,19159,18566,18446,18540,21854,17076,23367,23016,20986,19674,22464,21859,2914,22365,20876,23092,18807,2615,19042,18809,2614,18424,18461,21644,19677,22045,22100,21463,21443,22807,19038,18760,18456,62583,21791,19718,21317,20877,22407,18454,18720,115695,21194,21193,18384,19053,18704,18387,18252,18554,16769,5355,23048,19847,20893,18707,21200,22377,18717,18705,19056,18477,18470,21370,18455,22355,22288,18467,16898,18469,23038,49833,22388,23102,19002,18383,19607,21399,18463,165189,21804,22991,19417,22441,22456,20890,19659,21198,21660,16519,24885,21996,21899,17467,17143,61081,21724,21649,21792,19679,21902,21242,22387,22378,22314,18719,18465,21188,18713,19181,18670,17142,21728,21794,23219,21852,22477,20892,19296,18459,16772,21465,61366,16932,18451,18449,23257,21941,22458,21489,21451,18999,18490,25580,21723,18475,18960,19772,22986,19673,61142,18647,22340,21661,22381,21192,18385,22001,21400,18548,18750,21793,18460,18260,18962,18957,19154,19147,20809,21967,21870,20895,18273,21662,24886,19048,18249,21993,19003,21999,1412,23306,19689,22370,22278,21515,21636,18984,15991,21898)) OR (`Idx`=1 AND `CreatureID` IN (21654,21907,21284,16805,22982,21285,61440,18716,22980,16899,21855,21846,18718,23094,19000,21039,1410,22831,21957,22463,20874,24893,21429,18973,23383,21856,17088,20767,21903,22457,21869,21858,19159,22464,21859,2914,20876,2615,2614,19677,22045,21463,21443,21791,20877,22407,16769,5355,18717,22288,16898,49833,23102,22991,21660,16519,21996,21899,21792,21902,21242,22378,22314,18719,21794,21852,61366,23257,21489,21451,18999,18490,22986,61142,22340,21661,22001,18548,21793,18460,19147,20809,21967,21870,21662,19048,21993,19003,21999,19689,21636,21898)) OR (`Idx`=3 AND `CreatureID` IN (21284,21285,61440,18716,22980,21846,19000,1410,22463,18973,23383,17088,21858,21859,2914,20876,20877,22407,16769,5355,18717,49833,16519,22314,18719,21852,23257,18999,18490,61142,19689,21636)) OR (`Idx`=2 AND `CreatureID` IN (21284,16805,21285,61440,18716,22980,21846,18718,23094,19000,1410,22463,20874,18973,23383,17088,21858,22464,21859,2914,20876,22045,20877,22407,16769,5355,18717,49833,21660,16519,21902,22314,18719,21852,61366,23257,18999,18490,61142,21661,18460,19689,21636));

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185191; -- Darkstone of Terokk
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185139; -- Malukaz's Candles
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry` IN (185211, 185210); -- Cursed Egg
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry` IN (182794, 185952); -- Cage
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry` IN (182582, 182583); -- Draenei Vessel
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185218; -- Violet Signal Fire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=21111, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184815; -- Sealed Coffin
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry` IN (184843, 184842); -- Torgos's Bane
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185913; -- Skull Pile
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182547; -- Orb of Translocation
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185549; -- Monstrous Kaliri Egg
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182587; -- Wanted Poster
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=21111, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184813; -- Sealed Coffin
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185551; -- Shrine of the Hawk
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=21111, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184812; -- Sealed Coffin
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185219; -- Bloodstone Signal Fire
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=20721, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182542; -- Sealed Box
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry` IN (185212, 185208); -- [PH] Arakkoa Egg
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184725; -- Mana Bomb
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182566; -- Western Altar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=21111, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184814; -- Sealed Coffin
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=19346, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185201; -- Eye of Veil Shienor
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182956; -- School of Darter
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182543; -- Orb of Translocation
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182563; -- Northern Altar
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185216; -- Sapphire Signal Fire
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185217; -- Emerald Signal Fire
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185226; -- Cabal Chest
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182546; -- Orb of Translocation
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=21867, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185220; -- Massive Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=21111, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184810; -- Sealed Coffin
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184794; -- Sealed Box
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=182548; -- Orb of Translocation
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=21111, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=184811; -- Sealed Coffin
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=21871, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185225; -- Cabal Chest
UPDATE `gameobject_template` SET `displayId`=0, `Data3`=0, `Data6`=0, `VerifiedBuild`=48526 WHERE `entry`=183144; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=22199, `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185954; -- Hazzik's Package
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185547; -- Shrine of the Eagle
UPDATE `gameobject_template` SET `ContentTuningId`=39, `VerifiedBuild`=48526 WHERE `entry`=185928; -- Ancient Skull Pile

UPDATE `gameobject_template_addon` SET `WorldEffectID`=8830 WHERE `entry`=278575; -- Hero's Call Board
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8830 WHERE `entry`=278347; -- Warchief's Command Board
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry` IN (185226, 185225, 185224); -- Cabal Chest
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=185220; -- Massive Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=185201; -- Eye of Veil Shienor
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=185200; -- Eye of Veil Reskk
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=183104; -- Terokkar Banner
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181555; -- Fel Iron Deposit
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181281; -- Mana Thistle
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=29784; -- Basic Campfire

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=184810 AND `Idx`=1) OR (`GameObjectEntry`=184812 AND `Idx` IN (1,2,3)) OR (`GameObjectEntry`=184813 AND `Idx` IN (1,2,3)) OR (`GameObjectEntry`=184814 AND `Idx` IN (2,3)) OR (`GameObjectEntry`=184815 AND `Idx` IN (1,2,3));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(184810, 1, 30524, 48526); -- Sealed Coffin

UPDATE `gameobject_questitem` SET `VerifiedBuild`=48526 WHERE (`Idx`=0 AND `GameObjectEntry` IN (184811,184814,184815,182584,185954,185225,185220,184812,185226,181385,182542,185201,184810,184813,182581,185224,185200,182541,182601)) OR (`Idx`=1 AND `GameObjectEntry`=184814);
