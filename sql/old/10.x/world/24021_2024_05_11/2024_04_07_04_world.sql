SET @CGUID := 9800105;
SET @OGUID := 9804682;
SET @POOL := 5702;
SET @EVENT := 9;

-- Vendors
DELETE FROM `npc_vendor` WHERE (`entry`=32836 AND `item`=212786 AND `ExtendedCost`=6454 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32836, 1, 212786, 0, 6454, 1, 0, 0, 53989); -- Lovely Duckling

UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=116359 AND `ExtendedCost`=0 AND `type`=1); -- Magnificently-Painted Egg
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=116358 AND `ExtendedCost`=0 AND `type`=1); -- Intricately-Painted Egg
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=116357 AND `ExtendedCost`=0 AND `type`=1); -- Poorly-Painted Egg
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=165802 AND `ExtendedCost`=6454 AND `type`=1); -- Noble Gardener's Hearthstone
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=204675 AND `ExtendedCost`=6131 AND `type`=1); -- A Drake's Big Basket of Eggs
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=164924 AND `ExtendedCost`=2573 AND `type`=1); -- Yellow Spring Circlet
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=164923 AND `ExtendedCost`=2573 AND `type`=1); -- Brown Spring Circlet
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=164922 AND `ExtendedCost`=2573 AND `type`=1); -- Blue Spring Circlet
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=74283 AND `ExtendedCost`=2573 AND `type`=1); -- Pink Spring Circlet
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=74282 AND `ExtendedCost`=2573 AND `type`=1); -- Black Spring Circlet
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=72145 AND `ExtendedCost`=3689 AND `type`=1); -- Swift Springstrider
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=116258 AND `ExtendedCost`=2574 AND `type`=1); -- Mystical Spring Bouquet
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=141532 AND `ExtendedCost`=6131 AND `type`=1); -- Noblegarden Bunny
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=44794 AND `ExtendedCost`=2574 AND `type`=1); -- Spring Rabbit's Foot
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=44803 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Circlet
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=151806 AND `ExtendedCost`=2573 AND `type`=1); -- Elegant Dress
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=151804 AND `ExtendedCost`=2572 AND `type`=1); -- Black Tuxedo Pants
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=6833 AND `ExtendedCost`=2572 AND `type`=1); -- White Tuxedo Shirt
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=188694 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Florist's Pouch
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=44800 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Robes
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=45073 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Flowers
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=44792 AND `ExtendedCost`=2571 AND `type`=1); -- Blossoming Branch
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=53989 WHERE (`entry`=32836 AND `item`=44818 AND `ExtendedCost`=2575 AND `type`=1); -- Noblegarden Egg

-- Quests
UPDATE `quest_template` SET `TreasurePickerID`=2595, `QuestDescription`='Noblegarden, celebration of life and spring! I hope you\'ve been enjoying the egg hunt, friend, because I could use the services of a capable individual like you.\n\nI\'m not certain what form of magic was used in the creation of the eggs, and the druids aren\'t keen on explaining it to me. Perhaps you could collect some shell fragments for me during your egg collection. You can keep the contents of the eggs; all I require is a sufficient sample of the eggs themselves.', `VerifiedBuild`=53989 WHERE `ID`=13480; -- The Great Egg Hunt
UPDATE `quest_template` SET `TreasurePickerID`=2596, `QuestDescription`='Here... take this egg basket and go hunting for brightly colored eggs. Return to me with the basket when you\'ve found ten Noblegarden chocolates, please.', `VerifiedBuild`=53989 WHERE `ID`=13502; -- A Tisket, a Tasket, a Noblegarden Basket
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=13480;

DELETE FROM `quest_poi` WHERE `QuestID`=13480;
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(13480, 3, 9, 32, 0, 0, 530, 97, 0, 0, 0, 0, 0, 276848, 0, 53989), -- The Great Egg Hunt
(13480, 2, 8, 32, 0, 0, 1, 57, 0, 0, 0, 0, 0, 276762, 0, 53989), -- The Great Egg Hunt
(13480, 1, 7, 32, 0, 0, 0, 37, 0, 0, 0, 0, 0, 275765, 0, 53989), -- The Great Egg Hunt
(13480, 0, 6, 32, 0, 0, 0, 27, 0, 0, 0, 0, 0, 276699, 0, 53989), -- The Great Egg Hunt
(13480, 0, 5, 0, 264155, 44806, 2444, 2112, 0, 0, 0, 116906, 0, 0, 0, 53989), -- The Great Egg Hunt
(13480, 3, 4, -1, 0, 0, 530, 97, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13480, 2, 3, -1, 0, 0, 1, 57, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13480, 1, 2, -1, 0, 0, 0, 27, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13480, 0, 1, -1, 0, 0, 0, 37, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13480, 0, 0, -1, 0, 0, 2444, 2112, 0, 0, 0, 0, 0, 2417785, 0, 53989); -- The Great Egg Hunt

UPDATE `quest_poi` SET `VerifiedBuild`=53989 WHERE (`QuestID`=13502 AND `BlobIndex`=3 AND `Idx1`=9) OR (`QuestID`=13502 AND `BlobIndex`=2 AND `Idx1`=8) OR (`QuestID`=13502 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=13502 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=13502 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=13502 AND `BlobIndex`=4 AND `Idx1`=4) OR (`QuestID`=13502 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13502 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13502 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13502 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=75890 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=75890 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=60545 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60545 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56119 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56119 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50605 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50601 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49929 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=14048 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=14048 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=13480 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(13480, 9, 0, -4185, -12498, 44, 53989), -- The Great Egg Hunt
(13480, 8, 0, 9836, 969, 1308, 53989), -- The Great Egg Hunt
(13480, 7, 0, -9453, 44, 57, 53989), -- The Great Egg Hunt
(13480, 6, 0, -5597, -507, 401, 53989), -- The Great Egg Hunt
(13480, 5, 8, 19, -1002, 838, 53989), -- The Great Egg Hunt
(13480, 5, 7, -17, -836, 838, 53989), -- The Great Egg Hunt
(13480, 5, 6, 73, -796, 842, 53989), -- The Great Egg Hunt
(13480, 5, 5, 105, -824, 849, 53989), -- The Great Egg Hunt
(13480, 5, 4, 151, -868, 840, 53989), -- The Great Egg Hunt
(13480, 5, 3, 196, -927, 844, 53989), -- The Great Egg Hunt
(13480, 5, 2, 198, -960, 858, 53989), -- The Great Egg Hunt
(13480, 5, 1, 156, -993, 857, 53989), -- The Great Egg Hunt
(13480, 5, 0, 47, -1012, 838, 53989), -- The Great Egg Hunt
(13480, 4, 0, -4185, -12498, 44, 53989), -- The Great Egg Hunt
(13480, 3, 0, 9836, 969, 1308, 53989), -- The Great Egg Hunt
(13480, 2, 0, -5597, -507, 401, 53989), -- The Great Egg Hunt
(13480, 1, 0, -9453, 44, 57, 53989), -- The Great Egg Hunt
(13480, 0, 0, 64, -987, 838, 53989); -- The Great Egg Hunt

UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=53989 WHERE `ID`=13480; -- The Great Egg Hunt
UPDATE `quest_details` SET `VerifiedBuild`=53989 WHERE `ID`=13502;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 32799, 530, 3524, 3576, '0', 0, 0, 0, 0, -4186.47216796875, -12495.5, 44.44465255737304687, 2.374700784683227539, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Spring Collector (Area: Azure Watch - Difficulty: 0) CreateObject1
(@CGUID+1, 32836, 530, 3524, 3576, '0', 0, 0, 0, 1, -4185.46728515625, -12494.0380859375, 44.44465255737304687, 2.728973150253295898, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989); -- Noblegarden Vendor (Area: Azure Watch - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+96;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113771, 530, 3524, 3576, '0', 0, 0, -4244.74462890625, -12516.26171875, 47.49639892578125, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+1, 113770, 530, 3524, 3576, '0', 0, 0, -4240.671875, -12536, 46.06270599365234375, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+2, 113769, 530, 3524, 3576, '0', 0, 0, -4238.49365234375, -12511.97265625, 46.19207000732421875, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+3, 113771, 530, 3524, 3576, '0', 0, 0, -4233.84375, -12534.5517578125, 45.83507537841796875, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+4, 113768, 530, 3524, 3576, '0', 0, 0, -4232.0673828125, -12510.0615234375, 45.498443603515625, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+5, 113768, 530, 3524, 3576, '0', 0, 0, -4229.93359375, -12539.373046875, 47.32204818725585937, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+6, 113769, 530, 3524, 3576, '0', 0, 0, -4229.58056640625, -12465.6484375, 46.10487747192382812, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+7, 113770, 530, 3524, 3576, '0', 0, 0, -4228.81201171875, -12471.248046875, 45.97747421264648437, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+8, 113771, 530, 3524, 3576, '0', 0, 0, -4226.50830078125, -12461.1337890625, 46.89155197143554687, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+9, 113769, 530, 3524, 3576, '0', 0, 0, -4224.55322265625, -12536.251953125, 45.90106964111328125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+10, 113771, 530, 3524, 3576, '0', 0, 0, -4223.697265625, -12482.1318359375, 45.09798812866210937, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 530, 3524, 3576, '0', 0, 0, -4222.3369140625, -12506.958984375, 45.52767181396484375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+12, 113771, 530, 3524, 3576, '0', 0, 0, -4219.15234375, -12507.3642578125, 45.38512039184570312, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 530, 3524, 3576, '0', 0, 0, -4218.953125, -12486.923828125, 45.95512771606445312, 3.31166696548461914, 0, 0, -0.99638652801513671, 0.084934622049331665, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+14, 113769, 530, 3524, 3576, '0', 0, 0, -4218.46826171875, -12464.912109375, 45.33121490478515625, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+15, 113769, 530, 3524, 3576, '0', 0, 0, -4218.2939453125, -12444.4658203125, 44.77256011962890625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+16, 113770, 530, 3524, 3576, '0', 0, 0, -4215.51220703125, -12524.1728515625, 45.64808273315429687, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+17, 113769, 530, 3524, 3576, '0', 0, 0, -4214.66259765625, -12509.1826171875, 45.62058258056640625, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+18, 113770, 530, 3524, 3576, '0', 0, 0, -4212.9794921875, -12506.271484375, 45.41414642333984375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+19, 113768, 530, 3524, 3576, '0', 0, 0, -4212.07958984375, -12534.8798828125, 49.40731048583984375, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+20, 113771, 530, 3524, 3576, '0', 0, 0, -4208.51416015625, -12519.412109375, 45.92644500732421875, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+21, 113769, 530, 3524, 3576, '0', 0, 0, -4208.2314453125, -12439.9658203125, 45.40089035034179687, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+22, 113768, 530, 3524, 3576, '0', 0, 0, -4207.76416015625, -12558.9716796875, 40.88757705688476562, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+23, 113770, 530, 3524, 3576, '0', 0, 0, -4204.111328125, -12532.3330078125, 45.79191207885742187, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+24, 113771, 530, 3524, 3576, '0', 0, 0, -4203.27880859375, -12435.0439453125, 44.94586181640625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+25, 113768, 530, 3524, 3576, '0', 0, 0, -4196.94482421875, -12443.091796875, 45.49990081787109375, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+26, 113769, 530, 3524, 3576, '0', 0, 0, -4187.65478515625, -12441.2529296875, 43.54225921630859375, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+27, 113771, 530, 3524, 3576, '0', 0, 0, -4186.53662109375, -12437.9677734375, 43.41905593872070312, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+28, 113770, 530, 3524, 3576, '0', 0, 0, -4184.04833984375, -12563.8427734375, 40.13847732543945312, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+29, 113771, 530, 3524, 3576, '0', 0, 0, -4182.41748046875, -12497.8115234375, 44.36132049560546875, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+30, 113771, 530, 3524, 3576, '0', 0, 0, -4180.6552734375, -12501.15234375, 44.36132049560546875, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+31, 113770, 530, 3524, 3576, '0', 0, 0, -4179.55615234375, -12503.681640625, 44.36132049560546875, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+32, 113770, 530, 3524, 3576, '0', 0, 0, -4179.11181640625, -12499.0126953125, 44.36132049560546875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+33, 113771, 530, 3524, 3576, '0', 0, 0, -4178.70361328125, -12506.4892578125, 44.36132049560546875, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+34, 113769, 530, 3524, 3576, '0', 0, 0, -4177.18310546875, -12504.0283203125, 44.36132049560546875, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+35, 113768, 530, 3524, 3576, '0', 0, 0, -4176.45654296875, -12499.5439453125, 44.36132049560546875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+36, 113768, 530, 3524, 3576, '0', 0, 0, -4175.40185546875, -12501.923828125, 44.36132049560546875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+37, 113768, 530, 3524, 3576, '0', 0, 0, -4174.0458984375, -12499.55078125, 44.35198211669921875, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+38, 113768, 530, 3524, 3576, '0', 0, 0, -4171.57958984375, -12539.2119140625, 44.8950042724609375, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+39, 113770, 530, 3524, 3576, '0', 0, 0, -4170.8681640625, -12504.7607421875, 44.36132049560546875, 2.549250125885009765, 0, 0, 0.956460952758789062, 0.29186028242111206, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+40, 113771, 530, 3524, 3576, '0', 0, 0, -4169.34228515625, -12543.484375, 45.19704055786132812, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+41, 113768, 530, 3524, 3576, '0', 0, 0, -4164.70751953125, -12450.853515625, 43.98172760009765625, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+42, 113770, 530, 3524, 3576, '0', 0, 0, -4159.7255859375, -12451.6943359375, 47.19725418090820312, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+43, 113768, 530, 3524, 3576, '0', 0, 0, -4158.24169921875, -12536.68359375, 45.23476028442382812, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+44, 113770, 530, 3524, 3576, '0', 0, 0, -4158.11474609375, -12462.986328125, 45.08803939819335937, 0.16387195885181427, 0, 0, 0.081844329833984375, 0.996645152568817138, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+45, 113771, 530, 3524, 3576, '0', 0, 0, -4156.12060546875, -12427.064453125, 41.67079544067382812, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+46, 113769, 530, 3524, 3576, '0', 0, 0, -4154.8544921875, -12432.228515625, 42.12904739379882812, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+47, 113769, 530, 3524, 3576, '0', 0, 0, -4153.87255859375, -12537.1025390625, 45.58904266357421875, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+48, 113769, 530, 3524, 3576, '0', 0, 0, -4152.5693359375, -12480.7216796875, 44.78427505493164062, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+49, 113771, 530, 3524, 3576, '0', 0, 0, -4151.11572265625, -12476.2529296875, 44.9427337646484375, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+50, 113770, 530, 3524, 3576, '0', 0, 0, -4149.34326171875, -12472.0048828125, 45.14905929565429687, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+51, 113769, 530, 3524, 3576, '0', 0, 0, -4149.318359375, -12451.025390625, 44.22807693481445312, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+52, 113771, 530, 3524, 3576, '0', 0, 0, -4144.59716796875, -12490.173828125, 44.60271835327148437, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+53, 113769, 530, 3524, 3576, '0', 0, 0, -4140.8154296875, -12536.91015625, 45.58305740356445312, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+54, 113771, 530, 3524, 3576, '0', 0, 0, -4138.423828125, -12489.173828125, 43.98773574829101562, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+55, 113771, 530, 3524, 3576, '0', 0, 0, -4130.71435546875, -12457.6259765625, 44.69279861450195312, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+56, 113769, 530, 3524, 3576, '0', 0, 0, -4130.310546875, -12487.00390625, 44.01567840576171875, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+57, 113769, 530, 3524, 3576, '0', 0, 0, -4128.91259765625, -12455.61328125, 45.4173126220703125, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 530, 3524, 3576, '0', 0, 0, -4126.5546875, -12485.4365234375, 44.16746902465820312, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+59, 113771, 530, 3524, 3576, '0', 0, 0, -4125.16015625, -12529.400390625, 44.402801513671875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+60, 113771, 530, 3524, 3576, '0', 0, 0, -4125.05126953125, -12510.56640625, 44.61471939086914062, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+61, 113769, 530, 3524, 3576, '0', 0, 0, -4120.8798828125, -12523.7998046875, 44.01050186157226562, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+62, 113770, 530, 3524, 3576, '0', 0, 0, -4120.3505859375, -12529.9306640625, 44.78305435180664062, 4.721985816955566406, 0, 0, -0.7037057876586914, 0.710491478443145751, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+63, 113770, 530, 3524, 3576, '0', 0, 0, -4119.05859375, -12466.28515625, 44.92216110229492187, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+64, 113771, 530, 3524, 3576, '0', 0, 0, -4107.16357421875, -12484.3095703125, 42.57118606567382812, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+65, 415057, 530, 3524, 3576, '0', 0, 0, -4180.7724609375, -12433.892578125, 43.20893478393554687, 4.749696731567382812, 0, 0, -0.69379425048828125, 0.720173299312591552, 120, 255, 1, 53989), -- Noblegarden Banner - Single Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+66, 415057, 530, 3524, 3576, '0', 0, 0, -4120.32275390625, -12528.46875, 43.70471572875976562, 2.598469257354736328, 0, 0, 0.963353157043457031, 0.268236219882965087, 120, 255, 1, 53989), -- Noblegarden Banner - Single Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+67, 415058, 530, 3524, 3576, '0', 0, 0, -4185.296875, -12495.28515625, 44.08473587036132812, 2.406969547271728515, 0, 0, 0.93329620361328125, 0.359107553958892822, 120, 255, 1, 53989), -- Noblegarden Banner - Double Post [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+68, 415060, 530, 3524, 3576, '0', 0, 0, -4218.64599609375, -12472.0595703125, 46.1803741455078125, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Blue [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+69, 415060, 530, 3524, 3576, '0', 0, 0, -4204.39404296875, -12450.9755859375, 46.46063613891601562, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Blue [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+70, 415066, 530, 3524, 3576, '0', 0, 0, -4213.048828125, -12454.28515625, 46.50804519653320312, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Pink [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+71, 415066, 530, 3524, 3576, '0', 0, 0, -4182.376953125, -12436.7783203125, 44.64780426025390625, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Pink [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+72, 415066, 530, 3524, 3576, '0', 0, 0, -4221.95654296875, -12521.09375, 46.99128341674804687, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Pink [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+73, 415067, 530, 3524, 3576, '0', 0, 0, -4172.595703125, -12505.06640625, 44.36132049560546875, 5.759668350219726562, 0, 0, -0.25877952575683593, 0.96593642234802246, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+74, 415067, 530, 3524, 3576, '0', 0, 0, -4172.1181640625, -12504.888671875, 45.52299118041992187, 6.118410110473632812, 0, 0, -0.08229446411132812, 0.99660801887512207, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+75, 415067, 530, 3524, 3576, '0', 0, 0, -4118.611328125, -12527.951171875, 43.75947952270507812, 0.084323346614837646, 0.000834465026855468, 0.004754066467285156, 0.042143821716308593, 0.999099910259246826, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+76, 415067, 530, 3524, 3576, '0', 0, 0, -4120.392578125, -12530.0419921875, 43.71431350708007812, 5.768385887145996093, 0.009159088134765625, 0.015421867370605468, -0.254608154296875, 0.966877937316894531, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+77, 415069, 530, 3524, 3576, '0', 0, 0, -4170.892578125, -12504.7431640625, 44.36132049560546875, 0.204321354627609252, 0, 0, 0.101983070373535156, 0.99478614330291748, 120, 255, 1, 53989), -- Noblegarden Crate - Open [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+78, 415070, 530, 3524, 3576, '0', 0, 0, -4199.5, -12463.5419921875, 47.07273483276367187, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+79, 415070, 530, 3524, 3576, '0', 0, 0, -4155.94287109375, -12472.669921875, 45.64006805419921875, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+80, 415070, 530, 3524, 3576, '0', 0, 0, -4220.06591796875, -12485.3642578125, 45.65343093872070312, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+81, 415070, 530, 3524, 3576, '0', 0, 0, -4201.3505859375, -12454.955078125, 46.45612335205078125, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+82, 415071, 530, 3524, 3576, '0', 0, 0, -4149.23779296875, -12485.84765625, 50.36017227172851562, 0.735251307487487792, 0, 0, 0.359400749206542968, 0.93318331241607666, 120, 255, 1, 53989), -- Noblegarden Ribbon 0.13 [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+83, 415071, 530, 3524, 3576, '0', 0, 0, -4212.31787109375, -12515.103515625, 49.80424880981445312, 3.509673357009887695, 0, 0, -0.98311233520507812, 0.183003067970275878, 120, 255, 1, 53989), -- Noblegarden Ribbon 0.13 [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+84, 415072, 530, 3524, 3576, '0', 0, 0, -4206.41845703125, -12527.4267578125, 49.7852325439453125, 0.703718185424804687, 0, 0, 0.344643592834472656, 0.938733637332916259, 120, 255, 1, 53989), -- Noblegarden Streamers - Small Hanging [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+85, 415072, 530, 3524, 3576, '0', 0, 0, -4152.28662109375, -12529.44140625, 50.24076080322265625, 2.674384117126464843, 0, 0, 0.972838401794433593, 0.231485351920127868, 120, 255, 1, 53989), -- Noblegarden Streamers - Small Hanging [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+86, 415074, 530, 3524, 3576, '0', 0, 0, -4171.81787109375, -12506.451171875, 44.36132049560546875, 5.52919626235961914, 0, 0, -0.36812782287597656, 0.929775178432464599, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+87, 415074, 530, 3524, 3576, '0', 0, 0, -4176.99853515625, -12494.271484375, 44.36075592041015625, 1.407094955444335937, 0, 0, 0.6469268798828125, 0.76255202293395996, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+88, 415074, 530, 3524, 3576, '0', 0, 0, -4185.46533203125, -12504.7255859375, 44.36132049560546875, 3.326453447341918945, 0, 0, -0.99573135375976562, 0.092298716306686401, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+89, 415074, 530, 3524, 3576, '0', 0, 0, -4153.64404296875, -12484.4970703125, 44.53952789306640625, 3.879959821701049804, -0.01845979690551757, 0.063094139099121093, -0.93047332763671875, 0.360413342714309692, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+90, 415074, 530, 3524, 3576, '0', 0, 0, -4212.76416015625, -12510.40625, 45.421844482421875, 0.196015357971191406, 0.036880970001220703, 0.018044471740722656, 0.097218513488769531, 0.994415760040283203, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+91, 415074, 530, 3524, 3576, '0', 0, 0, -4209.642578125, -12517.732421875, 45.74767303466796875, 0.392149984836578369, -0.07989835739135742, -0.01812458038330078, 0.193987846374511718, 0.977576851844787597, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+92, 415074, 530, 3524, 3576, '0', 0, 0, -4157.8994140625, -12462.9482421875, 45.11624908447265625, 3.681843280792236328, 0, 0, -0.96373748779296875, 0.266852080821990966, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+93, 415074, 530, 3524, 3576, '0', 0, 0, -4214.78466796875, -12475.8994140625, 45.07465744018554687, 5.612176418304443359, 0, 0, -0.32924556732177734, 0.944244325160980224, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+94, 415074, 530, 3524, 3576, '0', 0, 0, -4158.51220703125, -12533.576171875, 45.42237472534179687, 2.134770393371582031, 0.005344867706298828, -0.00358486175537109, 0.875922203063964843, 0.482409447431564331, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+95, 415075, 530, 3524, 3576, '0', 0, 0, -4157.142578125, -12469.78515625, 50.06868743896484375, 2.774232149124145507, 0, 0, 0.983178138732910156, 0.182649165391921997, 120, 255, 1, 53989), -- Noblegarden Hanging Wreath 0.1 [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+96, 415075, 530, 3524, 3576, '0', 0, 0, -4122.546875, -12463.142578125, 48.28002166748046875, 3.897150278091430664, 0, 0, -0.92948627471923828, 0.368856728076934814, 120, 255, 1, 53989); -- Noblegarden Hanging Wreath 0.1 [DNT] (Area: Azure Watch - Difficulty: 0) CreateObject1

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+64;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+1, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+2, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+3, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+4, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+5, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+6, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+7, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+8, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+9, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+10, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+11, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+12, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+13, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+14, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+15, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+16, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+17, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+18, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+19, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+20, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+21, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+22, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+23, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+24, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+25, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+26, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+27, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+28, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+29, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+30, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+31, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+32, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+33, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+34, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+35, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+36, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+37, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+38, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+39, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+40, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+41, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+42, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+43, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+44, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+45, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+46, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+47, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+48, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+49, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+50, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+51, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+52, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+53, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+54, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+55, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+56, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+57, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+58, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+60, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+61, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+62, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+63, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+64, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+96;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+65),
(@EVENT, @OGUID+66),
(@EVENT, @OGUID+67),
(@EVENT, @OGUID+68),
(@EVENT, @OGUID+69),
(@EVENT, @OGUID+70),
(@EVENT, @OGUID+71),
(@EVENT, @OGUID+72),
(@EVENT, @OGUID+73),
(@EVENT, @OGUID+74),
(@EVENT, @OGUID+75),
(@EVENT, @OGUID+76),
(@EVENT, @OGUID+77),
(@EVENT, @OGUID+78),
(@EVENT, @OGUID+79),
(@EVENT, @OGUID+80),
(@EVENT, @OGUID+81),
(@EVENT, @OGUID+82),
(@EVENT, @OGUID+83),
(@EVENT, @OGUID+84),
(@EVENT, @OGUID+85),
(@EVENT, @OGUID+86),
(@EVENT, @OGUID+87),
(@EVENT, @OGUID+88),
(@EVENT, @OGUID+89),
(@EVENT, @OGUID+90),
(@EVENT, @OGUID+91),
(@EVENT, @OGUID+92),
(@EVENT, @OGUID+93),
(@EVENT, @OGUID+94),
(@EVENT, @OGUID+95),
(@EVENT, @OGUID+96);
