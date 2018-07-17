/*

		Nightbourne Area Beta asd
		clean design for Ashamane


*/

 -- TELE LOCATION --
DELETE FROM game_tele WHERE id = 1797;
INSERT INTO game_tele (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`)VALUES
(1797, 288.381, 3352.23, 145.444, 2.351534, 1220, 'NightborneSpawn');


 -- UPDATE SPAWN LOCATION IN PLAYERCREATEINFO --
 
UPDATE playercreateinfo SET map = 1220, zone = 7637, position_x = 288.381, position_y = 3352.23, position_z = 145.444, orientation = 2.351534 WHERE race = 27;
 
 -- MISC --
 
 DELETE FROM `areatrigger_template` WHERE `Id` IN (12515, 16575, 5302, 10660, 11513);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(12515, 0, 2, 0.5, 2, 0, 0, 0, 0, 26972),
(16575, 3, 4, 0, 0, 0, 0, 0, 0, 26972),
(5302, 0, 8, 5, 5, 0, 0, 0, 0, 26972),
(10660, 0, 4, 18, 18, 0, 0, 0, 0, 26972),
(11513, 0, 0, 1, 1, 0, 0, 0, 0, 26972);


DELETE FROM `conversation_actors` WHERE (`ConversationId`=6531 AND `Idx`=0) OR (`ConversationId`=6800 AND `ConversationActorId`=60124 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(6531, 0, 0, 26972), -- Full: 0x20197C9880803F800012DD0000465FD7 Creature/0 R1631/S4829 Map: 1220 Entry: 131326 Low: 4612055
(6800, 60124, 0, 26972);


DELETE FROM `conversation_actor_template` WHERE `Id`=60124;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(60124, 126076, 81857, 26972);


DELETE FROM `conversation_line_template` WHERE `Id` IN (14832, 14831, 14830, 14829, 14828, 15516, 15515, 15514, 15513, 15511);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(14832, 38895, 2245536360, 0, 0, 26972),
(14831, 32475, 2245536360, 0, 0, 26972),
(14830, 25441, 2245536360, 0, 0, 26972),
(14829, 13279, 2245536360, 0, 8217, 26972),
(14828, 0, 2245536360, 0, 0, 26972),
(15516, 47630, 606, 0, 0, 26972),
(15515, 35678, 606, 0, 0, 26972),
(15514, 20366, 606, 0, 0, 26972),
(15513, 10427, 606, 0, 0, 26972),
(15511, 0, 606, 0, 0, 26972);

DELETE FROM `conversation_line_template` WHERE `Id` IN (15512);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(15512, 0, 606,  0, 0, 26972); -- GUESSED!



DELETE FROM `conversation_template` WHERE `Id` IN (6800, 6531);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(6800, 15511, 58688, 26972),
(6531, 14828, 52053, 26972);

# Creatures #
 
 -- Templates --
 
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=71100 AND `ID`=1) OR (`CreatureID`=3313 AND `ID`=1) OR (`CreatureID`=5817 AND `ID`=1) OR (`CreatureID`=6466 AND `ID`=1) OR (`CreatureID`=88702 AND `ID`=1) OR (`CreatureID`=88701 AND `ID`=1) OR (`CreatureID`=88703 AND `ID`=1) OR (`CreatureID`=5614 AND `ID`=1) OR (`CreatureID`=5613 AND `ID`=1) OR (`CreatureID`=5611 AND `ID`=1) OR (`CreatureID`=5610 AND `ID`=1) OR (`CreatureID`=5609 AND `ID`=1) OR (`CreatureID`=5606 AND `ID`=1) OR (`CreatureID`=6929 AND `ID`=1) OR (`CreatureID`=62195 AND `ID`=1) OR (`CreatureID`=44871 AND `ID`=1) OR (`CreatureID`=14392 AND `ID`=1) OR (`CreatureID`=44872 AND `ID`=1) OR (`CreatureID`=44876 AND `ID`=1) OR (`CreatureID`=44877 AND `ID`=1) OR (`CreatureID`=44851 AND `ID`=1) OR (`CreatureID`=23635 AND `ID`=1) OR (`CreatureID`=44878 AND `ID`=1) OR (`CreatureID`=3312 AND `ID`=1) OR (`CreatureID`=3323 AND `ID`=1) OR (`CreatureID`=3342 AND `ID`=1) OR (`CreatureID`=23128 AND `ID`=1) OR (`CreatureID`=49750 AND `ID`=1) OR (`CreatureID`=89830 AND `ID`=1) OR (`CreatureID`=72559 AND `ID`=1) OR (`CreatureID`=45337 AND `ID`=1) OR (`CreatureID`=47571 AND `ID`=1) OR (`CreatureID`=44158 AND `ID`=1) OR (`CreatureID`=58155 AND `ID`=1) OR (`CreatureID`=4047 AND `ID`=1) OR (`CreatureID`=46556 AND `ID`=1) OR (`CreatureID`=49622 AND `ID`=1) OR (`CreatureID`=46142 AND `ID`=1) OR (`CreatureID`=3144 AND `ID`=1) OR (`CreatureID`=45339 AND `ID`=1) OR (`CreatureID`=3370 AND `ID`=1) OR (`CreatureID`=35068 AND `ID`=1) OR (`CreatureID`=46555 AND `ID`=1) OR (`CreatureID`=14375 AND `ID`=1) OR (`CreatureID`=14377 AND `ID`=1) OR (`CreatureID`=14376 AND `ID`=1) OR (`CreatureID`=5188 AND `ID`=1) OR (`CreatureID`=3314 AND `ID`=1) OR (`CreatureID`=133168 AND `ID`=1) OR (`CreatureID`=14720 AND `ID`=1) OR (`CreatureID`=45023 AND `ID`=1) OR (`CreatureID`=45019 AND `ID`=1) OR (`CreatureID`=51346 AND `ID`=1) OR (`CreatureID`=46359 AND `ID`=1) OR (`CreatureID`=45545 AND `ID`=1) OR (`CreatureID`=133127 AND `ID`=1) OR (`CreatureID`=45015 AND `ID`=1) OR (`CreatureID`=46357 AND `ID`=1) OR (`CreatureID`=69978 AND `ID`=1) OR (`CreatureID`=69977 AND `ID`=1) OR (`CreatureID`=37072 AND `ID`=1) OR (`CreatureID`=12793 AND `ID`=1) OR (`CreatureID`=74228 AND `ID`=1) OR (`CreatureID`=12790 AND `ID`=1) OR (`CreatureID`=133228 AND `ID`=1) OR (`CreatureID`=46078 AND `ID`=1) OR (`CreatureID`=46358 AND `ID`=1) OR (`CreatureID`=46080 AND `ID`=1) OR (`CreatureID`=12789 AND `ID`=1) OR (`CreatureID`=12798 AND `ID`=1) OR (`CreatureID`=30611 AND `ID`=1) OR (`CreatureID`=12791 AND `ID`=1) OR (`CreatureID`=45566 AND `ID`=1) OR (`CreatureID`=45347 AND `ID`=1) OR (`CreatureID`=12796 AND `ID`=1) OR (`CreatureID`=12795 AND `ID`=1) OR (`CreatureID`=45822 AND `ID`=1) OR (`CreatureID`=133519 AND `ID`=1) OR (`CreatureID`=12794 AND `ID`=1) OR (`CreatureID`=126062 AND `ID`=1) OR (`CreatureID`=46082 AND `ID`=1) OR (`CreatureID`=133521 AND `ID`=1) OR (`CreatureID`=125285 AND `ID`=1) OR (`CreatureID`=73151 AND `ID`=1) OR (`CreatureID`=45565 AND `ID`=1) OR (`CreatureID`=133271 AND `ID`=1) OR (`CreatureID`=12797 AND `ID`=1) OR (`CreatureID`=45814 AND `ID`=1) OR (`CreatureID`=45563 AND `ID`=1) OR (`CreatureID`=133218 AND `ID`=1) OR (`CreatureID`=3296 AND `ID`=1) OR (`CreatureID`=115736 AND `ID`=1) OR (`CreatureID`=107126 AND `ID`=1) OR (`CreatureID`=131413 AND `ID`=1) OR (`CreatureID`=133185 AND `ID`=1) OR (`CreatureID`=132029 AND `ID`=1) OR (`CreatureID`=116658 AND `ID`=1) OR (`CreatureID`=131421 AND `ID`=1) OR (`CreatureID`=131425 AND `ID`=1) OR (`CreatureID`=131414 AND `ID`=1) OR (`CreatureID`=133186 AND `ID`=1) OR (`CreatureID`=131326 AND `ID`=1) OR (`CreatureID`=131420 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(71100, 1, 31824, 0, 0, 0, 0, 0, 0, 0, 0), -- 71100
(3313, 1, 12850, 0, 0, 12745, 0, 0, 0, 0, 0), -- 3313
(5817, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- 5817
(6466, 1, 63252, 0, 0, 0, 0, 0, 0, 0, 0), -- 6466
(88702, 1, 2704, 0, 0, 0, 0, 0, 0, 0, 0), -- 88702
(88701, 1, 5287, 0, 0, 0, 0, 0, 0, 0, 0), -- 88701
(88703, 1, 5289, 0, 0, 0, 0, 0, 5260, 0, 0), -- 88703
(5614, 1, 2716, 0, 0, 0, 0, 0, 0, 0, 0), -- 5614
(5613, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- 5613
(5611, 1, 0, 0, 0, 0, 0, 0, 2551, 0, 0), -- 5611
(5610, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- 5610
(5609, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- 5609
(5606, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- 5606
(6929, 1, 6334, 0, 0, 0, 0, 0, 0, 0, 0), -- 6929
(62195, 1, 73893, 0, 0, 0, 0, 0, 0, 0, 0), -- 62195
(44871, 1, 5289, 0, 0, 0, 0, 0, 5260, 0, 0), -- 44871
(14392, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0), -- 14392
(44872, 1, 5289, 0, 0, 0, 0, 0, 5260, 0, 0), -- 44872
(44876, 1, 5289, 0, 0, 0, 0, 0, 5260, 0, 0), -- 44876
(44877, 1, 5289, 0, 0, 0, 0, 0, 5260, 0, 0), -- 44877
(44851, 1, 3346, 0, 0, 0, 0, 0, 0, 0, 0), -- 44851
(23635, 1, 4994, 0, 0, 0, 0, 0, 0, 0, 0), -- 23635
(44878, 1, 5289, 0, 0, 0, 0, 0, 5260, 0, 0), -- 44878
(3312, 1, 2827, 0, 0, 2196, 0, 0, 2551, 0, 0), -- 3312
(3323, 1, 2200, 0, 0, 0, 0, 0, 0, 0, 0), -- 3323
(3342, 1, 12329, 0, 0, 0, 0, 0, 0, 0, 0), -- 3342
(23128, 1, 29403, 0, 0, 27406, 0, 0, 0, 0, 0), -- 23128
(49750, 1, 1906, 0, 0, 0, 0, 0, 0, 0, 0), -- 49750
(89830, 1, 33161, 0, 0, 0, 0, 0, 0, 0, 0), -- 89830
(72559, 1, 33609, 0, 0, 12454, 0, 0, 49462, 0, 0), -- 72559
(45337, 1, 12421, 0, 0, 0, 0, 0, 0, 0, 0), -- 45337
(47571, 1, 24324, 0, 0, 24324, 0, 0, 0, 0, 0), -- 47571
(44158, 1, 1902, 0, 0, 0, 0, 0, 0, 0, 0), -- 44158
(58155, 1, 17462, 0, 0, 0, 0, 0, 0, 0, 0), -- 58155
(4047, 1, 5304, 0, 0, 0, 0, 0, 0, 0, 0), -- 4047
(46556, 1, 49671, 0, 0, 49671, 0, 0, 0, 0, 0), -- 46556
(49622, 1, 1908, 0, 0, 0, 0, 0, 0, 0, 0), -- 49622
(46142, 1, 5286, 0, 0, 0, 0, 0, 2551, 0, 0), -- 46142
(3144, 1, 10612, 0, 0, 0, 0, 0, 0, 0, 0), -- 3144
(45339, 1, 13709, 0, 0, 0, 0, 0, 0, 0, 0), -- 45339
(3370, 1, 5303, 0, 0, 0, 0, 0, 0, 0, 0), -- 3370
(35068, 1, 11383, 0, 0, 0, 0, 0, 0, 0, 0), -- 35068
(46555, 1, 17383, 0, 0, 0, 0, 0, 0, 0, 0), -- 46555
(14375, 1, 10612, 0, 0, 0, 0, 0, 2507, 0, 0), -- 14375
(14377, 1, 10612, 0, 0, 0, 0, 0, 2507, 0, 0), -- 14377
(14376, 1, 10612, 0, 0, 0, 0, 0, 2507, 0, 0), -- 14376
(5188, 1, 5284, 0, 0, 0, 0, 0, 0, 0, 0), -- 5188
(3314, 1, 10611, 0, 0, 0, 0, 0, 0, 0, 0), -- 3314
(133168, 1, 61337, 0, 0, 0, 0, 0, 50150, 0, 0), -- 133168
(14720, 1, 155857, 0, 0, 0, 0, 0, 0, 0, 0), -- 14720
(45023, 1, 3433, 0, 0, 0, 0, 0, 19993, 0, 0), -- 45023
(45019, 1, 60822, 0, 0, 60822, 0, 0, 0, 0, 0), -- 45019
(51346, 1, 5289, 0, 0, 0, 0, 0, 2507, 0, 0), -- 51346
(46359, 1, 1903, 0, 0, 13604, 0, 0, 0, 0, 0), -- 46359
(45545, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- 45545
(133127, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- 133127
(45015, 1, 13631, 0, 0, 0, 0, 0, 0, 0, 0), -- 45015
(46357, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- 46357
(69978, 1, 14824, 0, 0, 0, 0, 0, 0, 0, 0), -- 69978
(69977, 1, 37123, 0, 0, 0, 0, 0, 0, 0, 0), -- 69977
(37072, 1, 2182, 0, 0, 0, 0, 0, 0, 0, 0), -- 37072
(12793, 1, 6680, 0, 0, 0, 0, 0, 0, 0, 0), -- 12793
(74228, 1, 13631, 0, 0, 0, 0, 0, 5870, 0, 0), -- 74228
(12790, 1, 13612, 0, 0, 0, 0, 0, 0, 0, 0), -- 12790
(133228, 1, 1117, 0, 0, 0, 0, 0, 0, 0, 0), -- 133228
(46078, 1, 3364, 0, 0, 12332, 0, 0, 0, 0, 0), -- 46078
(46358, 1, 3346, 0, 0, 0, 0, 0, 0, 0, 0), -- 46358
(46080, 1, 12862, 0, 0, 0, 0, 0, 0, 0, 0), -- 46080
(12789, 1, 13631, 0, 0, 0, 0, 0, 0, 0, 0), -- 12789
(12798, 1, 12403, 0, 0, 0, 0, 0, 0, 0, 0), -- 12798
(30611, 1, 5289, 0, 0, 0, 0, 0, 2507, 0, 0), -- 30611
(12791, 1, 0, 0, 0, 0, 0, 0, 16582, 0, 0), -- 12791
(45566, 1, 2703, 0, 0, 13859, 0, 0, 0, 0, 0), -- 45566
(45347, 1, 1907, 0, 0, 0, 0, 0, 0, 0, 0), -- 45347
(12796, 1, 10611, 0, 0, 0, 0, 0, 0, 0, 0), -- 12796
(12795, 1, 12786, 0, 0, 0, 0, 0, 0, 0, 0), -- 12795
(45822, 1, 61337, 0, 0, 0, 0, 0, 50150, 0, 0), -- 45822
(133519, 1, 29433, 0, 0, 0, 0, 0, 0, 0, 0), -- 133519
(12794, 1, 21580, 0, 0, 0, 0, 0, 0, 0, 0), -- 12794
(126062, 1, 49767, 0, 0, 0, 0, 0, 0, 0, 0), -- 126062
(46082, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- 46082
(133521, 1, 65795, 0, 0, 0, 0, 0, 5258, 0, 0), -- 133521
(125285, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0), -- 125285
(73151, 1, 100541, 0, 0, 0, 0, 0, 0, 0, 0), -- 73151
(45565, 1, 2703, 0, 0, 13859, 0, 0, 0, 0, 0), -- 45565
(133271, 1, 0, 0, 0, 0, 0, 0, 34268, 0, 0), -- 133271
(12797, 1, 12403, 0, 0, 0, 0, 0, 0, 0, 0), -- 12797
(45814, 1, 61337, 0, 0, 0, 0, 0, 50150, 0, 0), -- 45814
(45563, 1, 2197, 0, 0, 13855, 0, 0, 0, 0, 0), -- 45563
(133218, 1, 38196, 0, 0, 0, 0, 0, 0, 0, 0), -- 133218
(3296, 1, 5289, 0, 0, 0, 0, 0, 2507, 0, 0), -- 3296
(115736, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- 115736
(107126, 1, 28650, 0, 0, 0, 0, 0, 0, 0, 0), -- 107126
(131413, 1, 133177, 0, 0, 0, 0, 0, 0, 0, 0), -- 131413
(133185, 1, 10616, 0, 0, 0, 0, 0, 0, 0, 0), -- 133185 
(132029, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- 132029 
(116658, 1, 140089, 0, 0, 0, 0, 0, 0, 0, 0), -- 116658
(131421, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- 131421
(131425, 1, 133176, 0, 0, 0, 0, 0, 0, 0, 0), -- 131425
(131414, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- 131414
(133186, 1, 109677, 0, 0, 0, 0, 0, 0, 0, 0), -- 133186
(131326, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- 131326
(131420, 1, 133177, 0, 0, 137253, 0, 0, 0, 0, 0); -- 131420

DELETE FROM creature_template_addon WHERE entry IN (133407);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(133407, 0, 0, 0, 1, 0, 0, 0, 0, '262273');

DELETE FROM creature_template WHERE entry IN (132149, 132144, 132026, 131326, 132027, 133186, 131420, 133695, 132032, 133407, 131413, 131424, 131415, 132024, 132029, 131416, 133185, 131425, 132148, 132145, 131414, 131421);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(132026, 0, 0, 73853, 0, 0, 0, 'Chief Telemancer Oculeth', NULL, NULL, NULL, NULL, 6, 6, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 132026
(132027, 0, 0, 73854, 0, 0, 0, 'Arcanist Valtrois', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 132027
(133186, 0, 0, 82769, 82770, 82773, 83248, 'Leyline Navigator', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 64, 0, 1, 1, 0, 123, 26972), -- 133186
(131326, 0, 0, 67345, 0, 0, 0, 'First Arcanist Thalyssra', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 0, 32768, 50, 1, 0, 0, 26972), -- 131326
(131420, 0, 0, 83032, 83010, 0, 0, 'Duskwatch Sentinel', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 2097224, 0, 17.4, 1, 0, 90, 26972), -- 131420
(133695, 0, 0, 72841, 0, 0, 0, 'Maribeth', NULL, 'Innkeeper', NULL, NULL, 6, 6, 0, 0, 0, 7, 134217728, 0, 1, 1, 0, 0, 26972), -- 133695
(132032, 0, 0, 70210, 0, 0, 0, 'Ly''leth Lunastre', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 132032
(133407, 0, 0, 82896, 0, 0, 0, 'Ambassador Blackguard', NULL, NULL, NULL, NULL, -1, 0, 0, 0, 0, 7, 0, 32768, 5, 1, 0, 0, 26972), -- 133407
(131413, 0, 0, 83042, 83049, 0, 0, 'Promenade Guard', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 2097224, 0, 10, 1, 0, 159, 26972), -- 131413
(131424, 0, 0, 62387, 0, 0, 0, 'Trained Shadescale', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 35, 1, 2359368, 0, 9, 1, 0, 0, 26972), -- 131424
(131415, 0, 0, 72211, 0, 0, 0, 'Nighthold Protector', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 9, 2097224, 0, 35, 1, 0, 144, 26972), -- 131415
(132024, 0, 0, 73864, 0, 0, 0, 'Arluelle', NULL, NULL, NULL, NULL, 6, 6, 0, 0, 0, 7, 0, 0, 2, 1, 0, 0, 26972), -- 132024
(132029, 0, 0, 68890, 0, 0, 0, 'Silgryn', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 0, 0, 10, 1, 0, 0, 26972), -- 132029
(131416, 0, 0, 83089, 83091, 83097, 83101, 'Nighthold Citizen', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 64, 0, 1, 1, 0, 159, 26972), -- 131416
(133185, 0, 0, 82764, 82767, 82765, 82768, 'Wildswalker Nightborne', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 64, 0, 1, 1, 0, 123, 26972), -- 133185
(131425, 0, 0, 83039, 83040, 0, 0, 'Terrace Grove-Tender', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 2097224, 0, 1, 1, 0, 159, 26972), -- 131425
(132148, 0, 0, 82257, 82258, 0, 0, 'Nightborne Trainee', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 2, 1, 0, 0, 26972), -- 132148
(132145, 0, 0, 82253, 0, 0, 0, 'Young Su', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 132145
(131414, 0, 0, 83031, 83025, 0, 0, 'Nobleborn Warpcaster', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 2097224, 0, 20.3, 1, 0, 985, 26972), -- 131414
(131421, 0, 0, 83017, 83019, 0, 0, 'Duskwatch Battle-Magus', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 2097224, 0, 17.5, 1, 0, 0, 26972), -- 131421
(132149, 0, 0, 82259, 83123, 0, 0, 'Nightborne Trainee', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 2, 1, 0, 0, 26972), -- 132149
(132144, 0, 0, 52955, 0, 0, 0, 'Ji-Sun', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972); -- 132144

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (44868, 131328, 133452, 133153, 133228, 133522, 133276, 126066, 133519, 126062, 133521, 125285, 133271, 133523, 133209, 133407, 133218, 112336, 116715, 112910, 116716, 132081, 132033, 128242, 131413, 133185, 132026, 132024, 132029, 132149, 131415, 132148, 131421, 131425, 131424, 131416, 131414, 133186, 132032, 132027, 131326, 131420);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(44868, 1, 110, 0, 0, 26972),
(131328, 110, 110, 0, 0, 26972),
(133452, 110, 110, 0, 0, 26972),
(133153, 98, 110, 0, 0, 26972),
(133228, 110, 110, 0, 0, 26972),
(133522, 110, 110, 0, 0, 26972),
(133276, 98, 110, 0, 0, 26972),
(126066, 110, 110, 0, 0, 26972),
(133519, 110, 110, 0, 0, 26972),
(126062, 110, 110, 0, 0, 26972),
(133521, 110, 110, 0, 0, 26972),
(125285, 110, 110, 0, 0, 26972),
(133271, 110, 110, 0, 0, 26972),
(133523, 110, 110, 0, 0, 26972),
(133209, 110, 110, 0, 0, 26972),
(133407, 110, 110, 0, 0, 26972),
(133218, 110, 110, 0, 0, 26972),
(112336, 110, 110, 0, 0, 26972),
(116715, 110, 110, 0, 0, 26972),
(112910, 110, 110, 0, 0, 26972),
(116716, 110, 110, 0, 0, 26972),
(132081, 110, 110, 0, 0, 26972),
(132033, 110, 110, 0, 0, 26972),
(128242, 110, 110, 0, 0, 26972),
(131413, 110, 110, 0, 0, 26972),
(133185, 110, 110, 0, 0, 26972),
(132026, 110, 110, 0, 0, 26972),
(132024, 110, 110, 0, 0, 26972),
(132029, 110, 110, 0, 0, 26972),
(132149, 110, 110, 0, 0, 26972),
(131415, 110, 110, 0, 0, 26972),
(132148, 110, 110, 0, 0, 26972),
(131421, 110, 110, 0, 0, 26972),
(131425, 110, 110, 0, 0, 26972),
(131424, 110, 110, 0, 0, 26972),
(131416, 110, 110, 0, 0, 26972),
(131414, 110, 110, 0, 0, 26972),
(133186, 110, 110, 0, 0, 26972),
(132032, 110, 110, 0, 0, 26972),
(132027, 110, 110, 0, 0, 26972),
(131326, 110, 110, 0, 0, 26972),
(131420, 110, 110, 0, 0, 26972);


UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, unit_class = 1, unit_flags = 33536, unit_flags2 = 2048 WHERE entry = 132149;
UPDATE creature_template SET minlevel = 1, maxlevel = 1, faction = 35, unit_class = 1, unit_flags = 33555200, unit_flags2 = 67110912 WHERE entry = 106873;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 1, unit_flags = 32768, unit_flags2 = 33556480 WHERE entry = 131420;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 131424;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 35, unit_class = 1, unit_flags = 0, unit_flags2 = 2048 WHERE entry = 132145;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 35, unit_class = 1, unit_flags = 0, unit_flags2 = 2048 WHERE entry = 132144;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 7, unit_class = 1, unit_flags = 131072, unit_flags2 = 2048 WHERE entry = 87760;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 2, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 131415;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, unit_class = 1, unit_flags = 33536, unit_flags2 = 2048 WHERE entry = 132149;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 2, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 131421;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 8, unit_flags = 33024, unit_flags2 = 2048 WHERE entry = 131416;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 8, unit_flags = 32768, unit_flags2 = 33556480 WHERE entry = 131414;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2801, unit_class = 8, unit_flags = 32768, unit_flags2 = 33556480 WHERE entry = 131425;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, unit_class = 1, unit_flags = 33536, unit_flags2 = 2048 WHERE entry = 132148;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, npcflag = 1, gossip_menu_id = 21991 WHERE entry = 132026;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, npcflag = 1, gossip_menu_id = 21995 WHERE entry = 132027;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799 WHERE entry = 133186;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799 WHERE entry = 131326;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799 WHERE entry = 131420;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, npcflag = 66177, gossip_menu_id = 22234 WHERE entry = 133695;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 2799, npcflag = 1, gossip_menu_id = 21994 WHERE entry = 132032;
UPDATE `creature_template` SET `AIName`="SmartAI", npcflag = 3, gossip_menu_id = 21993 WHERE `entry`=131326;
UPDATE creature_template SET minlevel = 0, maxlevel = 0, npcflag = 3, faction = 2875, gossip_menu_id = 22182 WHERE entry = 133407;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, npcflag = 2, faction = 2799 WHERE entry = 131328;

DELETE FROM `npc_vendor` WHERE (`entry`=113515 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=141208 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=140299 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=140631 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=140301 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=140286 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=138292 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=113515 AND `item`=128853 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=138295 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=138294 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=128833 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=128834 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=128841 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=128842 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=138292 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=128853 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=141215 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=111903 AND `item`=140298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=141208 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=140299 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=140631 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=140301 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=140286 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=138292 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133695 AND `item`=128853 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(113515, 25, 10290, 0, 0, 1, 0, 0, 26972), -- 10290
(113515, 24, 4342, 0, 0, 1, 0, 0, 26972), -- 4342
(113515, 23, 2325, 0, 0, 1, 0, 0, 26972), -- 2325
(113515, 22, 6261, 0, 0, 1, 0, 0, 26972), -- 6261
(113515, 21, 4340, 0, 0, 1, 0, 0, 26972), -- 4340
(113515, 20, 4341, 0, 0, 1, 0, 0, 26972), -- 4341
(113515, 19, 2605, 0, 0, 1, 0, 0, 26972), -- 2605
(113515, 18, 6260, 0, 0, 1, 0, 0, 26972), -- 6260
(113515, 17, 2604, 0, 0, 1, 0, 0, 26972), -- 2604
(113515, 16, 2324, 0, 0, 1, 0, 0, 26972), -- 2324
(113515, 13, 38426, 0, 0, 1, 0, 0, 26972), -- 38426
(113515, 12, 14341, 0, 0, 1, 0, 0, 26972), -- 14341
(113515, 11, 8343, 0, 0, 1, 0, 0, 26972), -- 8343
(113515, 10, 4291, 0, 0, 1, 0, 0, 26972), -- 4291
(113515, 9, 2321, 0, 0, 1, 0, 0, 26972), -- 2321
(113515, 8, 2320, 0, 0, 1, 0, 0, 26972), -- 2320
(113515, 7, 141208, 0, 0, 1, 0, 0, 26972), -- 141208
(113515, 6, 140299, 0, 0, 1, 0, 0, 26972), -- 140299
(113515, 5, 140631, 0, 0, 1, 0, 0, 26972), -- 140631
(113515, 4, 140301, 0, 0, 1, 0, 0, 26972), -- 140301
(113515, 3, 140286, 0, 0, 1, 0, 0, 26972), -- 140286
(113515, 2, 138292, 0, 0, 1, 0, 0, 26972), -- 138292
(113515, 1, 128853, 0, 0, 1, 0, 0, 26972), -- 128853
(111903, 22, 138295, 2, 0, 1, 0, 0, 26972), -- 138295
(111903, 21, 138294, 0, 0, 1, 0, 0, 26972), -- 138294
(111903, 8, 128833, 0, 0, 1, 0, 0, 26972), -- 128833
(111903, 7, 128834, 0, 0, 1, 0, 0, 26972), -- 128834
(111903, 6, 128841, 0, 0, 1, 0, 0, 26972), -- 128841
(111903, 5, 128842, 0, 0, 1, 0, 0, 26972), -- 128842
(111903, 4, 138292, 0, 0, 1, 0, 0, 26972), -- 138292
(111903, 3, 128853, 0, 0, 1, 0, 0, 26972), -- 128853
(111903, 2, 141215, 0, 0, 1, 0, 0, 26972), -- 141215
(111903, 1, 140298, 0, 0, 1, 0, 0, 26972), -- 140298
(133695, 25, 10290, 0, 0, 1, 0, 0, 26972), -- 10290
(133695, 24, 4342, 0, 0, 1, 0, 0, 26972), -- 4342
(133695, 23, 2325, 0, 0, 1, 0, 0, 26972), -- 2325
(133695, 22, 6261, 0, 0, 1, 0, 0, 26972), -- 6261
(133695, 21, 4340, 0, 0, 1, 0, 0, 26972), -- 4340
(133695, 20, 4341, 0, 0, 1, 0, 0, 26972), -- 4341
(133695, 19, 2605, 0, 0, 1, 0, 0, 26972), -- 2605
(133695, 18, 6260, 0, 0, 1, 0, 0, 26972), -- 6260
(133695, 17, 2604, 0, 0, 1, 0, 0, 26972), -- 2604
(133695, 16, 2324, 0, 0, 1, 0, 0, 26972), -- 2324
(133695, 13, 38426, 0, 0, 1, 0, 0, 26972), -- 38426
(133695, 12, 14341, 0, 0, 1, 0, 0, 26972), -- 14341
(133695, 11, 8343, 0, 0, 1, 0, 0, 26972), -- 8343
(133695, 10, 4291, 0, 0, 1, 0, 0, 26972), -- 4291
(133695, 9, 2321, 0, 0, 1, 0, 0, 26972), -- 2321
(133695, 8, 2320, 0, 0, 1, 0, 0, 26972), -- 2320
(133695, 7, 141208, 0, 0, 1, 0, 0, 26972), -- 141208
(133695, 6, 140299, 0, 0, 1, 0, 0, 26972), -- 140299
(133695, 5, 140631, 0, 0, 1, 0, 0, 26972), -- 140631
(133695, 4, 140301, 0, 0, 1, 0, 0, 26972), -- 140301
(133695, 3, 140286, 0, 0, 1, 0, 0, 26972), -- 140286
(133695, 2, 138292, 0, 0, 1, 0, 0, 26972), -- 138292
(133695, 1, 128853, 0, 0, 1, 0, 0, 26972); -- 128853


 -- Spawns --
 -- BETWEEN 1100002 AND 1100225  some free for missing spawns later --
SET @CGUID=1100002;

DELETE FROM creature WHERE guid BETWEEN @CGUID+1 AND @CGUID+222;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 131326, 1220, 7637, 9502, 3, 0, 0, 0, 0, 279.3646, 3364.045, 145.5591, 5.467539, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131326 (Area: 9502 - Difficulty: 0)
(@CGUID+2, 132032, 1220, 7637, 9502, 3, 0, 0, 0, 0, 282.5434, 3364.898, 145.5591, 4.695381, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132032 (Area: 9502 - Difficulty: 0)
(@CGUID+3, 133695, 1220, 7637, 9502, 3, 0, 0, 0, 0, 308.5, 3370.271, 148.8661, 3.983599, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133695 (Area: 9502 - Difficulty: 0)
(@CGUID+4, 132027, 1220, 7637, 9502, 3, 0, 0, 0, 0, 255.4045, 3385.154, 137.0584, 2.415946, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132027 (Area: 9502 - Difficulty: 0)
(@CGUID+5, 132026, 1220, 7637, 9502, 3, 0, 0, 0, 0, 209.1129, 3413.327, 126.8096, 5.634997, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132026 (Area: 9502 - Difficulty: 0)
(@CGUID+6, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 261.2066, 3364.268, 145.5568, 3.748009, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+7, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 303.5851, 3357.584, 145.5602, 3.833164, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+8, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 326.2674, 3387.331, 148.866, 0.6008496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+9, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 253.2622, 3315.046, 148.866, 3.946538, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+10, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 295.6771, 3365.497, 145.5601, 3.928354, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+11, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 276.6181, 3378.945, 145.5568, 0.9863299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+12, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 275.441, 3345.194, 145.56, 0.7370799, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+13, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 283.632, 3337.442, 145.56, 0.8322693, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+14, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 320.2778, 3299.192, 145.5592, 6.107695, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+15, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 215.4931, 3395.076, 126.809, 1.633002, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+16, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 330.6024, 3319.496, 145.5592, 5.198232, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+17, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 245.1476, 3425.312, 126.809, 2.757744, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+18, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 321.0608, 3310.087, 145.5592, 5.522061, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+19, 131420, 1220, 7637, 9502, 3, 0, 0, 0, 0, 341.5104, 3319.958, 145.5592, 4.627257, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131420 (Area: 9502 - Difficulty: 0)
(@CGUID+20, 133186, 1220, 7637, 9502, 3, 0, 0, 0, 0, 270.3594, 3334.497, 148.8771, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 9502 - Difficulty: 0)
(@CGUID+21, 133186, 1220, 7637, 9502, 3, 0, 0, 0, 0, 368.25, 3281.825, 142.0951, 0.8511931, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 9502 - Difficulty: 0)
(@CGUID+22, 133186, 1220, 7637, 9502, 3, 0, 0, 0, 0, 376.5174, 3226.753, 142.0951, 2.277848, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 9502 - Difficulty: 0)
(@CGUID+23, 133186, 1220, 7637, 9502, 3, 0, 0, 0, 0, 441.901, 3274.434, 142.0951, 4.120476, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 9502 - Difficulty: 0)
(@CGUID+24, 133186, 1220, 7637, 9502, 3, 0, 0, 0, 0, 377.1111, 3190.118, 142.0951, 0.5113269, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 9502 - Difficulty: 0)
(@CGUID+25, 133186, 1, 1637, 5332, 1, 0, 0, 0, 0, 1536.91, -4202.177, 53.62775, 2.940794, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 5332 - Difficulty: 0)
(@CGUID+26, 133186, 1, 1637, 5332, 1, 0, 0, 0, 0, 1573.602, -4130.915, 51.81333, 3.643319, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 5332 - Difficulty: 0)
(@CGUID+27, 133186, 1, 1637, 5332, 1, 0, 0, 0, 0, 1647.948, -4127.083, 48.2991, 0.6892244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133186 (Area: 5332 - Difficulty: 0)
(@CGUID+28, 133407, 1, 1637, 5332, 1, 0, 0, 0, 0, 1564.146, -4191.577, 53.76267, 5.407156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133407 (Area: 5332 - Difficulty: 0) (Auras: 262273 - 262273)
(@CGUID+29, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 440.533, 3305.931, 142.2045, 5.782425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+30, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 442.2934, 3309.09, 142.2031, 5.645847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+31, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 444.0156, 3310.191, 142.2029, 5.782425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+32, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 444.401, 3312.323, 142.2023, 5.503112, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+33, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 442.132, 3306.995, 142.2042, 5.782425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+34, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 454.5486, 3295.684, 142.2039, 2.615341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+35, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 446.4531, 3315.526, 142.2021, 5.370388, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+36, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 448.599, 3318.806, 142.2018, 5.245067, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+37, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 448.3021, 3316.512, 142.2025, 5.782425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+38, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 450.5695, 3319.453, 142.2024, 5.782425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+39, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 446.2917, 3313.286, 142.2027, 5.782425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+40, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 453.408, 3293.58, 142.2041, 2.091494, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+41, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 457.9774, 3297.464, 142.2027, 2.615341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+42, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 456.7882, 3295.569, 142.2026, 2.237276, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+43, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 460.0504, 3297.526, 142.202, 2.373759, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+44, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 461.2066, 3299.378, 142.2024, 2.615341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+45, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 463.3698, 3299.487, 142.2017, 2.502283, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+46, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 464.3316, 3301.406, 142.2021, 2.615341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+47, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 466.3507, 3301.539, 142.2015, 2.615341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+48, 131413, 1220, 7637, 9502, 3, 0, 0, 0, 0, 467.4288, 3303.355, 142.2019, 2.615341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131413 (Area: 9502 - Difficulty: 0)
(@CGUID+49, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 346.9618, 3379.838, 142.9874, 3.879231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+50, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 343.5243, 3379.018, 142.9874, 5.936898, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+51, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 374.4722, 3328.452, 142.0995, 1.821707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+52, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 345.5208, 3376.309, 142.9874, 1.65934, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+53, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 372.0625, 3330.804, 142.0951, 6.099264, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+54, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 375.3229, 3332.168, 142.0951, 4.041597, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+55, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 365.5399, 3416.333, 109.4496, 6.121222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+56, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 364.1892, 3420.478, 109.4497, 5.342509, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+57, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 367.9496, 3413.983, 109.4496, 2.329644, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+58, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 179.5903, 3310.451, 144.1104, 4.192834, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+59, 131415, 1220, 7637, 9502, 3, 0, 0, 0, 0, 259.3589, 3258.035, 142.1368, 1.073551, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131415 (Area: 9502 - Difficulty: 0)
(@CGUID+60, 131415, 1220, 7637, 9502, 3, 0, 0, 0, 0, 383.7017, 3380.063, 143.0096, 2.995802, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131415 (Area: 9502 - Difficulty: 0) 
(@CGUID+61, 131415, 1220, 7637, 9502, 3, 0, 0, 0, 0, 413.9783, 3414.08, 109.4096, 3.168369, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131415 (Area: 9502 - Difficulty: 0) 
(@CGUID+62, 131415, 1220, 7637, 9502, 3, 0, 0, 0, 0, 480.8976, 3333.7, 142.4211, 0.7873353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131415 (Area: 9502 - Difficulty: 0)
(@CGUID+63, 131415, 1220, 7637, 9502, 3, 0, 0, 0, 0, 463.276, 3242.101, 142.1367, 3.654949, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131415 (Area: 9502 - Difficulty: 0) 
(@CGUID+64, 131415, 1220, 7637, 9502, 3, 0, 0, 0, 0, 566.4792, 3306.864, 109.4501, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131415 (Area: 9502 - Difficulty: 0)
(@CGUID+65, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 378.125, 3351.041, 142.1368, 5.553438, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+66, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 274.2552, 3287.345, 142.5959, 4.053353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+67, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 262.6424, 3283.788, 142.9549, 6.142751, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+68, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 375.283, 3391.1, 142.9874, 5.809658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+69, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 387.4219, 3390.662, 142.9874, 3.72026, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+70, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 451.7309, 3260.323, 142.708, 0.9902378, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 474.6609, 3262.367, 142.6617, 0.8574132, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+72, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 461.4904, 3211.6, 142.3736, 4.529336, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+73, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 537.0712, 3385.556, 114.1025, 5.905883, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+74, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 531.8924, 3390.382, 114.0629, 3.753448, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+75, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 572.2552, 3302.675, 109.4501, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+76, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 559.5712, 3364.205, 109.4504, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+77, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 567.9045, 3364.992, 109.4504, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+78, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 406.4683, 3150.156, 142.3846, 3.006921, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+79, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 403.256, 3151.379, 142.3868, 3.551518, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+80, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 427.9514, 3128.203, 142.6535, 3.815975, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+81, 131424, 1220, 7637, 9502, 3, 0, 0, 0, 0, 424.1545, 3107.625, 142.5075, 1.100995, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131424 (Area: 9502 - Difficulty: 0)
(@CGUID+82, 132029, 1220, 7637, 9502, 3, 0, 0, 0, 0, 347.0646, 3272.493, 142.1368, 0.9467555, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132029 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+83, 132024, 1220, 7637, 9502, 3, 0, 0, 0, 0, 351.2276, 3274.588, 142.1368, 0.8688813, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132024 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+84, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 179.3108, 3306.653, 144.1225, 1.972942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+85, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 176.5747, 3308.612, 144.0965, 6.2505, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+86, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 296.401, 3250.299, 142.0951, 3.342769, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+87, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 293.349, 3249.806, 142.0951, 0.1208713, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+88, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 412.9045, 3295.584, 142.0951, 5.626005, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+89, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 375.8941, 3230.128, 142.0951, 3.987114, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+90, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 416.4236, 3295.313, 142.0951, 3.568337, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+91, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 372.0486, 3231.101, 142.0951, 5.52, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+92, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 430.3646, 3232.951, 142.0951, 4.948565, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+93, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 429.4271, 3229.549, 142.0951, 0.7230477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+94, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 406.9392, 3393.767, 142.9874, 6.099264, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+95, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 410.1996, 3395.132, 142.9874, 4.041597, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+96, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 409.349, 3391.417, 142.9874, 1.821707, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+97, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 365.5399, 3416.333, 109.4496, 6.121222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+98, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 367.9496, 3413.983, 109.4496, 2.329644, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+99, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 368.8004, 3417.698, 109.4497, 4.144657, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+100, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 364.1892, 3420.478, 109.4497, 5.342509, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+101, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 476.0972, 3228.528, 142.0951, 4.221406, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+102, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 474.3837, 3225.234, 142.0951, 1.102242, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+103, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 580.6805, 3344.55, 110.937, 3.919877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+104, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 582.8976, 3342.079, 110.937, 3.721653, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+105, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 410.3229, 3137.589, 142.1115, 4.20977, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+106, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 394.8351, 3137.78, 142.1578, 5.320548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+107, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 388.4792, 3129.7, 142.149, 5.996919, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+108, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 414.908, 3125.564, 142.1423, 3.168007, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+109, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 390.9583, 3119.589, 142.2574, 0.4235268, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+110, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 409.2135, 3115.702, 142.1449, 2.105689, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+111, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 375.3976, 3108.142, 142.6788, 4.433678, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+112, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 376.0365, 3104.385, 142.9931, 2.213787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+113, 131416, 1220, 7637, 9502, 3, 0, 0, 0, 0, 372.9097, 3105.636, 142.7031, 0.2081591, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131416 (Area: 9502 - Difficulty: 0)
(@CGUID+114, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 276.6013, 3336.545, 147.2268, 0.6592375, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+115, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 371.4375, 3282.881, 142.0968, 3.031387, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+116, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 369.1285, 3284.741, 142.0951, 4.862344, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+117, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 373.2292, 3227.424, 142.0951, 0.9829136, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+118, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 441.1962, 3272.151, 142.0951, 1.480532, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+119, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 379.566, 3192.458, 142.0951, 4.636858, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+120, 133185, 1220, 7637, 9502, 3, 0, 0, 0, 0, 380.7969, 3188.93, 142.0951, 1.891515, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 9502 - Difficulty: 0)
(@CGUID+121, 133185, 1, 1637, 5332, 1, 0, 0, 0, 0, 1561.872, -4222.542, 54.07872, 2.280081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 5332 - Difficulty: 0)
(@CGUID+122, 133185, 1, 1637, 5332, 1, 0, 0, 0, 0, 1558.043, -4220.842, 54.10798, 0.02771925, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 5332 - Difficulty: 0)
(@CGUID+123, 133185, 1, 1637, 5332, 1, 0, 0, 0, 0, 1571.597, -4130.592, 51.81333, 5.318836, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 5332 - Difficulty: 0)
(@CGUID+124, 133185, 1, 1637, 5332, 1, 0, 0, 0, 0, 1646.663, -4125.558, 48.30014, 0.6947476, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 5332 - Difficulty: 0)
(@CGUID+125, 133185, 1, 1637, 5170, 1, 0, 0, 0, 0, 1640.493, -4381.037, 21.1032, 5.552957, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133185 (Area: 5170 - Difficulty: 0)
(@CGUID+126, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 299.3594, 3268.504, 142.619, 4.073863, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+127, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 366.2674, 3356.632, 142.7827, 1.872591, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+128, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 266.5, 3262.427, 142.0951, 5.398231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+129, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 278.6371, 3262.08, 142.0951, 4.133325, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+130, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 403.8299, 3336.099, 142.0951, 3.412367, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+131, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 267.6875, 3244.163, 142.0951, 1.040404, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+132, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 279.3021, 3243.443, 142.0951, 2.119103, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+133, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 384.026, 3320.228, 142.5865, 1.016561, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+134, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 404.6458, 3314.298, 142.9142, 3.744776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+135, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 321.0695, 3235.386, 142.1258, 6.005882, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+136, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 409.5573, 3360.883, 142.8789, 2.327995, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+137, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 462.4792, 3252.619, 142.3913, 3.689929, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+138, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 479.3351, 3235.758, 142.2072, 2.537066, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+139, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 478.3438, 3210.608, 142.2878, 6.13833, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+140, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 433.5504, 3167.04, 142.3391, 4.623832, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+141, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 420.5382, 3173.779, 142.0951, 5.077163, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+142, 131425, 1220, 7637, 9502, 3, 0, 0, 0, 0, 378.0052, 3163.944, 142.1543, 4.743952, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131425 (Area: 9502 - Difficulty: 0)
(@CGUID+143, 132145, 1220, 7637, 9502, 3, 0, 0, 0, 0, 216.1146, 3290.799, 143.9986, 5.36801, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132145 (Area: 9502 - Difficulty: 0)
(@CGUID+144, 132148, 1220, 7637, 9502, 3, 0, 0, 0, 0, 225.8125, 3284.874, 143.9954, 2.551637, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132148 (Area: 9502 - Difficulty: 0)
(@CGUID+145, 132148, 1220, 7637, 9502, 3, 0, 0, 0, 0, 218.3733, 3283.816, 143.9957, 1.749735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132148 (Area: 9502 - Difficulty: 0)
(@CGUID+146, 132148, 1220, 7637, 9502, 3, 0, 0, 0, 0, 222.6354, 3284.115, 143.9947, 2.292071, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132148 (Area: 9502 - Difficulty: 0)
(@CGUID+147, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 269.8559, 3284.74, 142.8073, 5.072204, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+148, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 269.2344, 3279.589, 142.6452, 1.519746, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+149, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 380.1389, 3384.978, 142.9874, 1.186652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+150, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 386.6898, 3352.173, 142.1368, 3.578065, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+151, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 235.5729, 3264.158, 142.1326, 5.556626, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+152, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 384.7847, 3385.108, 142.9874, 2.027557, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+153, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 412.0284, 3417.565, 109.4096, 0.02684889, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+154, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 414.6526, 3417.635, 109.4096, 3.168444, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+155, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 450.3142, 3201.59, 142.0951, 2.441649, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+156, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 521.5764, 3390.901, 115.1042, 0.372523, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+157, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 562.4739, 3298.175, 109.45, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+158, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 537.5382, 3374.291, 115.1034, 1.180162, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+159, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 529.4739, 3387.432, 115.1, 6.197791, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+160, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 559.9219, 3353.283, 109.4503, 1.170167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+161, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 566.7483, 3351.802, 109.4503, 1.849718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+162, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 569.8837, 3295.595, 109.4501, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+163, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 518.4757, 3435.588, 110.937, 5.680704, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+164, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 399.4167, 3176.091, 142.0951, 0.346278, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+165, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 427.4792, 3117.799, 142.6042, 1.519746, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+166, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 343.1371, 3185.757, 145.3147, 0.8322693, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)	 
(@CGUID+167, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 431.8281, 3119.441, 142.8125, 2.360651, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+168, 131421, 1220, 7637, 9502, 3, 0, 0, 0, 0, 418.1632, 3096.18, 142.0955, 2.332203, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131421 (Area: 9502 - Difficulty: 0)
(@CGUID+169, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 273.5833, 3281.233, 142.5833, 2.360651, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+170, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 242.7639, 3272.128, 142.0951, 5.556626, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+171, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 382.4097, 3389.641, 142.9874, 4.73911, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+172, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 332.6962, 3196.492, 145.3147, 0.7370799, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+173, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 411.1828, 3412.54, 109.4096, 3.168453, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236) (possible waypoints or random movement)
(@CGUID+174, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 412.8757, 3421.124, 109.4096, 0.02675019, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236) (possible waypoints or random movement)
(@CGUID+175, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 564.2639, 3294.6, 109.45, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+176, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 534.5347, 3382.746, 115.1, 1.681841, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+177, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 533.7726, 3387.147, 115.0983, 4.798041, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+178, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 563.9271, 3361.972, 109.4504, 4.6782, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+179, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 521.8507, 3440.141, 110.937, 5.680704, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+180, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 440.5035, 3192.01, 142.0951, 2.29012, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+181, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 405.7083, 3172.409, 142.0965, 1.246601, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+182, 131414, 1220, 7637, 9502, 3, 0, 0, 0, 0, 428.1007, 3122.948, 142.6823, 5.072204, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 131414 (Area: 9502 - Difficulty: 0) (Auras: 203761 - 203761, 67236 - 67236)
(@CGUID+183, 132144, 1220, 7637, 9502, 3, 0, 0, 0, 0, 197.7014, 3259.487, 143.9947, 0.9183772, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132144 (Area: 9502 - Difficulty: 0)
(@CGUID+184, 132149, 1220, 7637, 9502, 3, 0, 0, 0, 0, 223.4271, 3280.097, 143.9961, 2.118889, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132149 (Area: 9502 - Difficulty: 0)
(@CGUID+185, 132149, 1220, 7637, 9502, 3, 0, 0, 0, 0, 222.7656, 3288.3, 143.9957, 2.797261, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132149 (Area: 9502 - Difficulty: 0)
(@CGUID+186, 132149, 1220, 7637, 9502, 3, 0, 0, 0, 0, 204.9583, 3266.373, 143.9948, 3.853179, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132149 (Area: 9502 - Difficulty: 0)
(@CGUID+187, 132149, 1220, 7637, 9502, 3, 0, 0, 0, 0, 199.8733, 3267.311, 143.9964, 4.361809, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 132149 (Area: 9502 - Difficulty: 0)
	


	-- Gossip --
	
DELETE FROM `gossip_menu` WHERE (`MenuId`=22182 AND `TextId`=33984) OR (`MenuId`=20389 AND `TextId`=30489) OR (`MenuId`=20376 AND `TextId`=28901) OR (`MenuId`=21991 AND `TextId`=33680) OR (`MenuId`=22001 AND `TextId`=33695) OR (`MenuId`=22000 AND `TextId`=33694) OR (`MenuId`=21995 AND `TextId`=30966) OR (`MenuId`=21993 AND `TextId`=33683) OR (`MenuId`=21994 AND `TextId`=33684) OR (`MenuId`=22234 AND `TextId`=7821);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22182, 33984), -- 133407
(20389, 30489), -- 113515
(20376, 28901), -- 111903
(21991, 33680), -- 132026
(22001, 33695), -- 132024
(22000, 33694), -- 132029
(21995, 30966), -- 132027
(21993, 33683), -- 131326
(21994, 33684), -- 132032
(22234, 7821); -- 133695

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=20389 AND `OptionIndex`=1) OR (`MenuId`=20389 AND `OptionIndex`=0) OR (`MenuId`=20376 AND `OptionIndex`=1) OR (`MenuId`=20376 AND `OptionIndex`=0) OR (`MenuId`=22234 AND `OptionIndex`=1) OR (`MenuId`=22234 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(20389, 1, 1, 'What do you have for sale?', 0),
(20389, 0, 5, 'Make this inn your home.', 0),
(20376, 1, 0, '<Take a drink.>', 0),
(20376, 0, 1, 'I would like to buy from you.', 0),
(22234, 1, 1, 'What do you have for sale?', 0),
(22234, 0, 5, 'Make this inn your home.', 0);

UPDATE gossip_menu_option SET OptionType=8, OptionNpcFlag=66177 WHERE MenuId=22234 AND OptionIndex = 0;
UPDATE gossip_menu_option SET OptionType=3, OptionNpcFlag=66177 WHERE MenuId=22234 AND OptionIndex = 1;

/*
 NOT FIXED DONT UNCOMMENT 
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(131328, @GROUP_ID+0, @ID+, 'Stars guide you, $p. I have heard intriguing talk of the Hillsbrad Foothills. I will likely journey there.', 12, 0, 100, 1, 0, 0, UNKNOWN, 'Melitier Vahlouran to Player');
*/

-- Ambassador Blackguard SAI
SET @AMBASSADOR_BLACKGUARD := 133407;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@AMBASSADOR_BLACKGUARD;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@AMBASSADOR_BLACKGUARD AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AMBASSADOR_BLACKGUARD,0,0,0,20,0,100,0,49933,0,0,0,206,6800,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ambassador Blackguard - On Quest 'For the Horde' Return - conversation");



-- First Arcanist Thalyssra SAI THANKS ÐϴVΞΓϺΛΠ - 930®#4327
SET @FIRST_ARCANIST_THALYSSRA := 131326;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FIRST_ARCANIST_THALYSSRA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FIRST_ARCANIST_THALYSSRA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FIRST_ARCANIST_THALYSSRA,0,0,0,19,0,100,0,49933,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"First Arcanist Thalyssra - On Quest 'For the Horde' Taken - Say Line 0"),
(@FIRST_ARCANIST_THALYSSRA,0,1,0,52,0,100,0,0,@FIRST_ARCANIST_THALYSSRA,0,0,1,1,11000,0,0,0,0,1,0,0,0,0,0,0,0,"First Arcanist Thalyssra - On Text 0 Over - Say Line 1"),
(@FIRST_ARCANIST_THALYSSRA,0,2,0,52,0,100,0,1,@FIRST_ARCANIST_THALYSSRA,0,0,1,2,11000,0,0,0,0,1,0,0,0,0,0,0,0,"First Arcanist Thalyssra - On Text 1 Over - Say Line 2"),
(@FIRST_ARCANIST_THALYSSRA,0,3,0,52,0,100,0,2,@FIRST_ARCANIST_THALYSSRA,0,0,1,3,11000,0,0,0,0,1,0,0,0,0,0,0,0,"First Arcanist Thalyssra - On Text 2 Over - Say Line 3"),
(@FIRST_ARCANIST_THALYSSRA,0,4,0,52,0,100,0,3,@FIRST_ARCANIST_THALYSSRA,0,0,1,4,11000,0,0,0,0,1,0,0,0,0,0,0,0,"First Arcanist Thalyssra - On Text 3 Over - Say Line 4");

DELETE FROM creature_text WHERE CreatureID=@FIRST_ARCANIST_THALYSSRA;
INSERT INTO creature_text (CreatureID, GroupID, ID, Text, Type, Language, Probability, Emote, Duration, Sound, BroadcastTextId, TextRange, comment)VALUES
(@FIRST_ARCANIST_THALYSSRA, 0, 0, 'When our city faced its darkest hour, the heroes of Azeroth fought with us to drive out the Legion. Some did so reluctantly.', 12, 0, 100, 1, 0, 0, 143276, 0, ''),
(@FIRST_ARCANIST_THALYSSRA, 1, 1, 'But the sin''dorei--the blood elves--showed us respect and understanding. Their kinship proved there were others in Azeroth who share our values.', 12, 0, 100, 1, 0, 0, 143277, 0, ''),
(@FIRST_ARCANIST_THALYSSRA, 2, 2, 'Now it is our turn to demonstrate the strength and honor we bring to the Horde.', 12, 0, 100, 1, 0, 0, 143288, 0, ''),
(@FIRST_ARCANIST_THALYSSRA, 3, 3, 'Go to Orgrimmar. Join with our allies and forge a new future together.', 12, 0, 100, 1, 0, 0, 143293, 0, ''),
(@FIRST_ARCANIST_THALYSSRA, 4, 4, 'As you travel the roads of Azeroth, tell those you meet of the nightborne''s proud history... and show them that we live in seclusion no longer.', 12, 0, 100, 1, 0, 0, 143292, 0, '');


DELETE FROM `npc_text` WHERE `ID` IN (33984 /*33984*/, 30489 /*30489*/, 28901 /*28901*/, 33695 /*33695*/, 33694 /*33694*/, 33680 /*33680*/, 30966 /*30966*/, 33683 /*33683*/, 33684 /*33684*/, 7821 /*7821*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33984, 1, 1, 1, 1, 1, 0, 0, 0, 147209, 147208, 147207, 147206, 147205, 0, 0, 0, 26972), -- 33984
(30489, 1, 1, 1, 0, 0, 0, 0, 0, 122396, 122397, 122398, 0, 0, 0, 0, 0, 26972), -- 30489
(28901, 1, 0, 0, 0, 0, 0, 0, 0, 108945, 0, 0, 0, 0, 0, 0, 0, 26972), -- 28901
(33695, 1, 0.25, 0, 0, 0, 0, 0, 0, 144677, 144678, 0, 0, 0, 0, 0, 0, 26972), -- 33695
(33694, 1, 1, 1, 0, 0, 0, 0, 0, 144672, 144674, 144676, 0, 0, 0, 0, 0, 26972), -- 33694
(33680, 1, 1, 1, 0, 0, 0, 0, 0, 144383, 144384, 144386, 0, 0, 0, 0, 0, 26972), -- 33680
(30966, 1, 1, 1, 0, 0, 0, 0, 0, 124862, 124865, 124863, 0, 0, 0, 0, 0, 26972), -- 30966
(33683, 0.5, 1, 0, 0, 0, 0, 0, 0, 144396, 144621, 0, 0, 0, 0, 0, 0, 26972), -- 33683
(33684, 1, 0, 0, 0, 0, 0, 0, 0, 144397, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33684
(7821, 1, 0, 0, 0, 0, 0, 0, 0, 10889, 0, 0, 0, 0, 0, 0, 0, 26972); -- 7821
 
 # Quests stuff #
 
-- Templates --

DELETE FROM `quest_template` WHERE `ID` IN (28493 /*28493*/, 50303 /*50303*/, 8468 /*8468*/, 24974 /*24974*/, 14438 /*14438*/, 25170 /*25170*/, 25945 /*25945*/, 13618 /*13618*/, 871 /*871*/, 14129 /*14129*/, 9329 /*9329*/, 26965 /*26965*/, 28096 /*28096*/, 25236 /*25236*/, 31813 /*31813*/, 49933 /*49933*/, 46748 /*46748*/, 46736 /*46736*/, 46735 /*46735*/, 46277 /*46277*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(28493, 2, -1, 60, 0, 15, 331, 0, 0, 13612, 1, 1, 125, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Warchief''s Command: Ashenvale!', 'Report to Kadrak at the Mor''shan Rampart on the border between the Northern Barrens and Ashenvale.', 'All able bodied members of the Horde are hereby ordered to report to Kadrak at the Mor''shan Rampart on the border between the Northern Barrens and Ashenvale. Aid in driving the night elves from the forest, so that we may claim its resources for our people!$B$BTo reach the Mor''shan Rampart, you must take the Gold Road north from Crossroads in the Northern Barrens.$B$BDestiny calls!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 28493
(50303, 2, 20, 255, 0, 20, -440, 0, 0, 0, 0, 1, 125, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 67108864, 0, 6, 'Stranger in a Strange Land', 'Find the Warchief''s Command board in Orgrimmar.', 'Hi. I''m Ambassador Blackguard.\n\n<Blackguard looks down at a piece of paper in his hand.>\n\nOn behalf of the warchief, I am honored to welcome you to Orgrimmar, $r.\n\n<Glances at you, smiles unconvincingly, then looks back at the paper.>\n\nAs a lifetime of adventure unfolds... ugh!\n\nThat''s it! I''m tired of reading this same greeting day in and day out.\n\nGo figure out where you can fight things, then talk to your emissary.\n\nPlease just leave me alone.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 50303
(8468, 2, -1, 20, 0, 5, 3430, 0, 0, 0, 5, 1, 2500, 6, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 911, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 1, 0, 0, 234881970, 0, 1, 'Wanted: Thaelis the Hungerer', 'Bring Thaelis''s Head to Sergeant Kan''ren at Falconwing Square in Eversong Woods.', 'The city of Silvermoon hereby issues a reward for the head of Thaelis the Hungerer, notorious Wretched ringleader.  He is wanted for repeated crimes against the general populace of Silvermoon City, including the murder of two city guards.$B$BReport to Sergeant Kan''ren to collect the reward.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 8468
(24974, 2, -1, 20, 0, 4, 85, 0, 0, 0, 4, 1, 900, 4, 1, 60, 0, 0, 0, 73435, 0, 0, 52059, 0, 1, 0, 2097160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52059, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Ever So Lonely', 'Use the Murloc Leash on a Vile Fin murloc at the Whispering Shore, then return it to Sedrick Calston at Calston Estate.', 'You work hard your whole life, and what do you get?  Killed by a plague.  Then you work even harder in undeath, and what do you get?  Money, yes, and a small estate with a few pesky hangers-on, but happiness?  Not so much.$b$bI''m lonely in my old age, $n.  I need a companion.  Use this leash on one of the murlocs at the Whispering Shore to the northwest.  You''ll have to weaken it first before it can be leashed.  Then bring it back to me.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 24974
(14438, 2, -1, 20, 18631, 4, 215, 0, 0, 14491, 5, 1, 1200, 5, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 1, 0, 0, 234881970, 0, 0, 'Sharing the Land', 'Kill 15 Palemane Gnolls then return to Ahmo Thunderhorn in Bloodhoof Village.', '$n, there are many conflicts that wound this land. It is my hope that you will not bear witness to as many of them as our elders have. Yet there is one that I would ask you to seek. It will give you some sense of how terrible, if left unchecked, even a small threat can be to the land.$B$BPalemane gnolls have settled to the south of Bloodhoof and in a cave to the west. They disrespect our attempts to communicate with them, and they slay the wildlife of Mulgore unbridled.$B$BWords are no longer the answer.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 14438
(25170, 2, -1, 20, 0, 5, 14, 0, 0, 25165, 4, 1, 1200, 5, 1, 60, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 530, 0, 0, 0, 5, 5, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Cleaning Up the Coastline', 'Obtain 5 handfuls of Crawler Mucus.', 'Heya mon!  Bom''bay be workin'' on some new mojo.  You wanna try a piece of it?  Well, before ya do, Bom''bay''s gonna need ya to pick up some jujus.$b$bFirst, Bom''bay needs ya to get some o'' the goop from the crabs down by the water.  Let me see your hands!$b$b<Bom''bay examines your hands closely.>$b$bBom''bay gonna need 5 handfuls.  Go on now!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 25170
(25945, 2, -1, 60, 0, 20, 406, 0, 0, 25999, 2, 1, 0, 0, 1, 30, 77851, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'We''re Here to Do One Thing, Maybe Two...', 'Take the Krom''gar Wagon to the Fold in Stonetalon Mountains.', 'You''re in Hellscream''s army now, $n, and in Hellscream''s army we kick butt and take names. Gone are the days of our people starving in the streets of Orgrimmar as we sign treaties with elves. We take what we need now. Kalimdor belongs to the Horde!$B$BThe Alliance attempts to stop our expansion every chance they get. Unsatisfied with owning most of the Eastern Kingdoms, those pig-lickers want it all!$B$BOverlord Krom''gar has called for more troops in Stonetalon. Get on the caravan west of here and go!', 'Krom''gar Wagon taken to the Fold', 'Report to Saurboz at the Fold in Stonetalon Mountains to join the Krom''gar army.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 25945
(13618, 2, -1, 60, 0, 15, 331, 0, 0, 13619, 5, 1, 1200, 5, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Find Gorat!', 'Kadrak at Mor''shan Ramparts wants you to search the Fallen Sky Lake region for Gorat.', 'Gorat is one of the Horde''s most adept assassins.$b$bThe mere mention of his name strikes fear into the hearts of our Alliance foes.$b$bHe is reliable, fiercely loyal, and - until now - punctual.$b$bSomething''s not right, $c.$b$bGorat''s mission was to find and eliminate the elf in charge of this assault on the ramparts.$b$bHe should be somewhere in the region of Fallen Sky Lake.$b$bFind him!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 13618
(871, 2, -1, 60, 0, 10, 17, 0, 0, 872, 5, 1, 0, 0, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'In Defense of Far Watch', 'Kill 8 Razormane Plunderers and 3 Razormane Hunters.', 'All the quilboars are our enemies, $n. Some just prove to be more of a nuisance than others.$B$BThe Razormane tribe has been attacking our supply caravans that roll through here from Orgrimmar. I have scouts seeking the leader of these raids, but until then, any losses you can inflict on the filthy pig men would aid us.$B$BStart just south of here, where they''ve been raiding our camps near the river. Seek them out, and slay them.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 871
(14129, 2, -1, 60, 0, 10, 16, 0, 0, 14134, 5, 1, 0, 0, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 65544, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1133, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Runaway Shredder!', 'Attack one of the Runaway Shredders near the rear gates of Orgrimmar and hop inside once it''s been significantly damaged.', 'I''ve been trying to impress our new Horde allies with our legendary goblin efficiency, but in hindsight automating the shredders was a bad idea. Now they''re mindless killing machines, rampaging over the countryside. Don''t get me wrong - that kind of thing has its place - but for the time being I need a brave $c to help me get these things under control.$B$BIt''s easy. Automated shredders, like all machines, must first be beaten into submission. Afterwards, seize the controls and I''ll radio you instructions.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 14129
(9329, 2, -1, 60, 0, 10, 3433, 0, 0, 9758, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 922, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881458, 0, 1, 'The Forsaken', 'Speak with High Executor Mavren at Tranquillien in the Ghostlands.', 'I know it seems strange, but the Forsaken are here to help. You should speak with their leader, High Executor Mavren.  He''s in the tower on the west side of town.$B$BAnd, $c, when you''re done talking with him return to me; I have something dire that needs to be dealt with immediately!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 9329
(26965, 2, -1, 60, 0, 10, 130, 0, 0, 0, 4, 1, 0, 0, 1, 60, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4194312, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'The Warchief Cometh', 'Stand by for Warchief Garrosh Hellscream''s arrival.', 'You''re just in time, $nnub. It is $nnub, right?$B$B<Grand Executor Mortuus looks at a sheet of paper.>$B$BYes, that''s what the paperwork says: "$nnub."$B$B<Grand Executor Mortuus points to your name on the sheet of paper.>$B$BWhere was I? Oh yes, you''re just in time! The Warchief should be arriving at any moment to meet with our leader and savior, the Dark Lady herself. Just stand by and be at your best behavior. I expect that when this demonstration is over we will all receive commendations!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 26965
(28096, 2, -1, 60, 3525, 15, 267, 0, 0, 28111, 5, 1, 0, 0, 1, 90, 0, 0, 0, 0, 0, 0, 62932, 0, 1, 0, 3145736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62932, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Welcome to the Machine', 'Hand out 3 Quests.', 'Come in here dear $g boy:girl;, have a cigar. You''re gonna go far and fly high as a ranking officer of the Forsaken. Yes, indeed, this is the good life and you are going to live it!$B$BI want you to take these orders and dispense them to the lowly scrubs that come along looking for work. Who you give what to is wholly at your discretion.$B$BWhen you''re ready, mount up on my trusty skeletal steed - so they don''t miss you - and start living the life! Which means just stand there and wait.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 28096
(25236, 2, -1, 20, 0, 5, 14, 0, 0, 0, 5, 1, 1200, 5, 1, 90, 0, 0, 0, 0, 0, 0, 52574, 0, 1, 0, 1048584, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52574, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Thunder Down Under', 'Attach a Mageweave Tether to 8 Drowned Thunder Lizards in Thunder Ridge.', 'Our army needs water, and luckily the elements gave us plenty of that when the cataclysm hit.  The water that filled up the canyon to the southwest should do the trick.$b$bUnfortunately, the corpses of thunder lizards still sit at the bottom of the canyon, and their electrical discharges are a bit too dangerous.  I''ve got grunts that can lift them out of the water, but we need someone agile enough to attach the other end of the rope.  Are you my $g man: woman;, $n?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 25236
(31813, 2, -1, 255, 0, 1, -394, 102, 0, 31814, 5, 1, 1200, 5, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 524288, 2176, 0, 0, 0, 0, 89125, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 234881970, 0, 0, 'Dagra the Fierce', 'Defeat Dagra the Fierce in a pet battle.', 'Der be another trainer not far from here that you ought to fight to test your worth.$b$bDagra the Fierce waits on the northern slope of Thorn Hill, east of The Crossroads. If you be beatin'' her, you just might have what it takes.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 31813
(49933, 2, 20, 255, 0, 20, -440, 0, 0, 50303, 1, 1, 125, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 157028, 157759, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 67108864, 0, 6, 'For the Horde', 'Meet Ambassador Blackguard at the Orgrimmar Embassy.', 'After ages standing alone, we are once again poised to become part of something greater. Our alliance with the Horde affords us a fresh start, a unique chance that must not be squandered.\n\nThe warchief''s ambassador awaits you in Orgrimmar, $n. From there, you will set out on a journey across Azeroth. Fight to defend this land, and claim a place for the shal''dorei within it.\n\nShow the world who we are, $c. Bring honor to the Horde, for in so doing, you will bring honor to Suramar.', '', 'Meet Ambassador Blackguard at the Orgrimmar Embassy.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 49933
(46748, 2, 110, 255, 0, 110, 7637, 128, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34078720, 536870912, 0, 0, 0, 0, 152105, 142005, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 'Supplies From the Nightfallen', 'Speak with First Arcanist Thalyssra in Suramar for your reward.', 'Outlander, I have some supplies for you. These goods are yours, earned by your continued efforts to our forces here in Suramar.\n\nI shall set aside similar treasures should you choose to aid our people more.\n\nYou have my deepest thanks.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 46748
(46736, 0, -1, 255, 0, 110, 0, 143, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 100728840, 33554432, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 0, 'Contribute to Nether Disruptor', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 26972), -- 46736
(46735, 0, -1, 255, 0, 110, 0, 143, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 100728840, 33554432, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 0, 'Contribute to Command Center', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 26972), -- 46735
(46277, 0, -1, 255, 0, 110, 0, 143, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 100729096, 33554432, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 'Contribute to Mage Tower', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 26972); -- 46277

DELETE FROM creature_queststarter WHERE (id = 131326 AND quest = 49933) OR (id = 133407 AND quest = 50303);
 INSERT INTO creature_queststarter (`id`, `quest`)VALUES
(131326,49933), -- for the horde
(133407,50303); --  Stranger in a Strange Land

DELETE FROM creature_questender WHERE (id = 133407 AND quest = 49933) OR (id = 131328 AND quest = 50303);
INSERT INTO creature_questender (`id`, `quest`)VALUES
(133407, 49933), -- for the horde
(131328, 50303); -- stranger in a strange land
 
 DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=42859 AND `Idx`=0) OR (`CreatureEntry`=39049 AND `Idx`=0) OR (`CreatureEntry`=8524 AND `Idx`=0) OR (`CreatureEntry`=112336 AND `Idx`=0) OR (`CreatureEntry`=112910 AND `Idx`=4) OR (`CreatureEntry`=112910 AND `Idx`=3) OR (`CreatureEntry`=112910 AND `Idx`=2) OR (`CreatureEntry`=112910 AND `Idx`=1) OR (`CreatureEntry`=112910 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(42859, 0, 57758, 26972), -- 42859
(39049, 0, 52270, 26972), -- 39049
(8524, 0, 61372, 26972), -- 8524
(112336, 0, 129888, 26972), -- 112336
(112910, 4, 134808, 26972), -- 112910
(112910, 3, 129903, 26972), -- 112910
(112910, 2, 129888, 26972), -- 112910
(112910, 1, 135515, 26972), -- 112910
(112910, 0, 127262, 26972); -- 112910

DELETE FROM `quest_visual_effect` WHERE (`ID`=312111 AND `Index`=0) OR (`ID`=259624 AND `Index`=0) OR (`ID`=269049 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(312111, 0, 8517, 26972),
(259624, 0, 6043, 26972),
(269049, 0, 1026, 26972);

DELETE FROM `quest_objectives` WHERE `ID` IN (312111 /*312111*/, 259624 /*259624*/, 267187 /*267187*/, 267186 /*267186*/, 264756 /*264756*/, 265539 /*265539*/, 254390 /*254390*/, 254389 /*254389*/, 266900 /*266900*/, 266110 /*266110*/, 253201 /*253201*/, 253200 /*253200*/, 253199 /*253199*/, 265482 /*265482*/, 269049 /*269049*/, 289536 /*289536*/, 289535 /*289535*/, 289167 /*289167*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(312111, 50303, 14, 0, 1, 65213, 1, 0, 0, 0, 'Warchief''s Command Board found', 26972), -- 312111
(259624, 8468, 1, 0, 0, 21781, 1, 0, 1, 0, '', 26972), -- 259624
(267187, 24974, 0, 1, 1, 38887, 1, 0, 0, 0, 'Vile Fin returned', 26972), -- 267187
(267186, 24974, 0, 0, 0, 38923, 1, 0, 0, 0, 'Vile Fin captured', 26972), -- 267186
(264756, 14438, 0, 0, 0, 42354, 15, 0, 0, 0, 'Palemane Gnolls', 26972), -- 264756
(265539, 25170, 1, 0, 0, 4888, 5, 0, 1, 0, '', 26972), -- 265539
(254390, 871, 0, 1, 1, 3265, 3, 0, 0, 0, '', 26972), -- 254390
(254389, 871, 0, 0, 0, 3267, 8, 0, 0, 0, '', 26972), -- 254389
(266900, 14129, 0, 0, 0, 35111, 1, 0, 0, 0, 'Runaway Shredder Captured', 26972), -- 266900
(266110, 26965, 0, 0, 0, 44629, 1, 0, 0, 0, 'Stand by for Warchief Garrosh Hellscream''s arrival', 26972), -- 266110
(253201, 28096, 0, 2, 2, 47442, 1, 0, 0, 0, 'Third Quest Dispensed', 26972), -- 253201
(253200, 28096, 0, 1, 1, 47443, 1, 0, 0, 0, 'Second Quest Dispensed', 26972), -- 253200
(253199, 28096, 0, 0, 0, 47444, 1, 0, 0, 0, 'First Quest Dispensed', 26972), -- 253199
(265482, 25236, 0, 0, 0, 39464, 8, 0, 0, 0, 'Drowned Thunder Lizard removed', 26972), -- 265482
(269049, 31813, 11, 0, 0, 66135, 1, 1, 0, 0, 'Defeat Dagra the Fierce', 26972), -- 269049
(289536, 46736, 4, 0, -1, 1342, 100, 0, 0, 0, '', 26972), -- 289536
(289535, 46735, 4, 0, -1, 1342, 100, 0, 0, 0, '', 26972), -- 289535
(289167, 46277, 4, 0, -1, 1342, 100, 0, 0, 0, '', 26972); -- 289167
 
 
 
 
# Objects #
 
  -- Templates --
DELETE FROM gameobject_template WHERE entry IN (279579, 279671, 279670, 279295, 281316, 266919, 254148, 254147, 254145, 254149, 254239, 251844, 254238, 254276, 265470, 259929, 265469, 254828); 
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(279579, 22, 12807, 'Portal to Orgrimmar', '', '', '', 1, 259106, -1, 0, 0, 1, 55254, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 279579
(279671, 22, 36654, 'Portal to Shal''Aran', '', '', '', 1, 263029, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 279671
(279670, 22, 8111, 'Portal to Dalaran', '', '', '', 1, 239570, -1, 0, 0, 1, 29029, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 279670
(279295, 22, 47619, 'Portal to The Nighthold', '', '', '', 0.75, 259125, -1, 0, 0, 0, 55254, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 279295
(281316, 22, 47619, 'Portal to The Nighthold', '', '', '', 1, 259125, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 281316
(266919, 0, 34945, 'The Nighthold Portcullis', '', '', '', 1, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 266919
(254148, 11, 30558, 'Gondola', '', '', '', 0.9999999, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254148
(254147, 11, 30558, 'Gondola', '', '', '', 0.9999997, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254147
(254145, 11, 30558, 'Gondola', '', '', '', 0.9999997, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254145
(254149, 11, 30558, 'Gondola', '', '', '', 0.9999998, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254149
(254239, 11, 30558, 'Gondola', '', '', '', 0.9999998, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254239
(251844, 0, 35528, 'Door', '', '', '', 0.7524738, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 251844
(254238, 11, 30558, 'Gondola', '', '', '', 1.000001, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254238
(254276, 11, 30558, 'Gondola', '', '', '', 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 254276
(265470, 11, 30558, 'Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath004', '', '', '', 0.9999998, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 265470
(259929, 11, 30558, 'Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_ShortSouth01', '', '', '', 0.9999998, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 259929
(265469, 11, 30558, 'Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath003', '', '', '', 0.9999997, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 265469
(254828, 7, 34367, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 254828


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (235794 /*235794*/, 252303 /*252303*/, 206110 /*206110*/, 223739 /*223739*/, 223814 /*223814*/, 259114 /*259114*/, 206735 /*206735*/, 203977 /*203977*/, 203969 /*203969*/, 203979 /*203979*/, 280650 /*280650*/, 251844 /*251844*/, 266919 /*266919*/, 279579 /*279579*/, 279671 /*279671*/, 279670 /*279670*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(235794, 0, 262144), -- 235794
(252303, 1375, 0), -- 252303
(206110, 0, 32), -- 206110
(223739, 0, 48), -- 223739
(223814, 1375, 48), -- 223814
(259114, 125, 0), -- 259114
(206735, 1735, 0), -- 206735
(203977, 94, 4), -- 203977
(203969, 0, 4), -- 203969
(203979, 94, 4), -- 203979
(280650, 1735, 0), -- 280650
(251844, 0, 32), -- 251844
(266919, 0, 32), -- 266919
(279579, 0, 32), -- 279579
(279671, 0, 32), -- 279671
(279670, 0, 32); -- 279670


DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=203977 AND `Idx`=0) OR (`GameObjectEntry`=203969 AND `Idx`=0) OR (`GameObjectEntry`=203979 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(203977, 0, 57877, 26972), -- 203977
(203969, 0, 57766, 26972), -- 203969
(203979, 0, 57878, 26972); -- 203979

  -- Spawns --
SET @OGUID=20000016;

DELETE FROM gameobject WHERE guid BETWEEN @OGUID+1 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 279579, 1220, 7637, 9502, 3, 0, 0, 212.9983, 3427.951, 126.7257, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 279579 (Area: 9502 - Difficulty: 0)
(@OGUID+2, 279671, 1220, 7637, 9502, 3, 0, 0, 239.7587, 3438.77, 126.7257, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 279671 (Area: 9502 - Difficulty: 0)
(@OGUID+3, 279670, 1220, 7637, 9502, 3, 0, 0, 201.7847, 3400.765, 126.7257, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 279670 (Area: 9502 - Difficulty: 0)
(@OGUID+4, 279295, 1, 1637, 5332, 1, 0, 0, 1595.684, -4203.519, 53.86691, 0, 0, 0, 0, 1, 120, 255, 1, 26972), -- 279295 (Area: 5332 - Difficulty: 0)
(@OGUID+5, 281316, 1220, 7637, 7928, 3, 0, 0, 1778.347, 4616.864, 124.741, 0.337644, 0, 0, 0.1680212, 0.9857834, 7200, 255, 1, 26972), -- 281316 (Area: 7928 - Difficulty: 0)
(@OGUID+6, 254148, 1220, 7637, 9502, 3, 0, 0, 869.861, 4216.877, 0.1015637, 2.453083, 0, 0, 0.9413271, 0.3374956, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+7, 254147, 1220, 7637, 9502, 3, 0, 0, 1234.817, 3738.016, 0.1514663, 2.598866, 0.0006079674, -0.000957489, 0.9634056, 0.2680454, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+8, 254145, 1220, 7637, 9502, 3, 0, 0, 441.9613, 3749.586, 0.1015638, 3.108445, 0, 0, 0.9998627, 0.01657281, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+9, 254149, 1220, 7637, 9502, 3, 0, 0, 1007.973, 3777.788, 0.1015171, 2.947497, 0, 0, 0.9952946, 0.09689554, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+10, 254239, 1220, 7637, 9502, 3, 0, 0, 492.3362, 4064.585, 0.1015638, 5.660151, 0, 0, -0.3065033, 0.9518696, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+11, 254238, 1220, 7637, 9502, 3, 0, 0, 324.9208, 3909.51, 0.1015638, 2.175544, 0, 0, 0.8855944, 0.4644595, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+12, 254276, 1220, 7637, 9502, 3, 0, 0, 684.0871, 3851.781, 0.1015638, 4.412364, 0, 0, -0.8048429, 0.5934879, 7200, 255, 24, 26972), -- 0 (Area: 9502 - Difficulty: 0)
(@OGUID+13, 254828, 1220, 7637, 9502, 3, 0, 0, 187.9913, 3301.943, 142.0069, 1.221729, 0, 0, 0.573576, 0.8191524, 7200, 255, 1, 26972), -- 254828 (Area: 9502 - Difficulty: 0)
(@OGUID+14, 266919, 1220, 7637, 9502, 3, 0, 0, 1235.946, 4205.98, -65.18047, 2.617989, 0, 0, 0.9659252, 0.2588213, 7200, 255, 1, 26972); -- 266919 (Area: 9502 - Difficulty: 0)


DELETE FROM spell_target_position WHERE ID IN (259106, 263029, 259125);
INSERT INTO spell_target_position (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`)VALUES
(259106, 0, 1, 1590.86, -4199.37, 53.6, 26972), -- Portal to orgrimmar
(259125, 0, 1220, 288.38, 3352.23, 145.44, 26972), -- Return Portal to Nighthold
(263029, 0, 1220, 1772.3, 4615.48, 124.81, 26972); -- Portal to Shal'aran

SET @PHASE_169  = 172329; -- default phase?
SET @PHASE_170  = 59073; -- alliance
SET @PHASE_171  = 59074; -- horde?

UPDATE gameobject SET PhaseId = 171 WHERE guid = @OGUID+4;
UPDATE creature SET PhaseId = 171 WHERE guid = @CGUID+28;

DELETE FROM spell_area WHERE (spell = @PHASE_171 AND racemask = 67108864) OR (spell = @PHASE_169 AND racemask = 67108864);
INSERT INTO spell_area (`spell`, `area`, `teamid`, `racemask`, `flags`) VALUES 
(@PHASE_171, 5332, 1, 67108864, 3),
(@PHASE_169, 5332, 1, 67108864, 3);
