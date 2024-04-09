SET @CGUID := 9800099;
SET @OGUID := 9804409;
SET @POOL := 5706;
SET @EVENT := 9;

-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=130907; -- Egg

-- Vendors
DELETE FROM `npc_vendor` WHERE (`entry`=32837 AND `item`=212786 AND `ExtendedCost`=6454 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32837, 1, 212786, 0, 6454, 1, 0, 0, 53989); -- Lovely Duckling

UPDATE `npc_vendor` SET `VerifiedBuild`=53989 WHERE (`entry`=18929 AND `item`=8932 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18929 AND `item`=3927 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18929 AND `item`=1707 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18929 AND `item`=422 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18929 AND `item`=414 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=18929 AND `item`=2070 AND `ExtendedCost`=0 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=116359 AND `ExtendedCost`=0 AND `type`=1); -- Magnificently-Painted Egg
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=116358 AND `ExtendedCost`=0 AND `type`=1); -- Intricately-Painted Egg
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=116357 AND `ExtendedCost`=0 AND `type`=1); -- Poorly-Painted Egg
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=165802 AND `ExtendedCost`=6454 AND `type`=1); -- Noble Gardener's Hearthstone
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=204675 AND `ExtendedCost`=6131 AND `type`=1); -- A Drake's Big Basket of Eggs
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=164924 AND `ExtendedCost`=2573 AND `type`=1); -- Yellow Spring Circlet
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=164923 AND `ExtendedCost`=2573 AND `type`=1); -- Brown Spring Circlet
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=164922 AND `ExtendedCost`=2573 AND `type`=1); -- Blue Spring Circlet
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=74283 AND `ExtendedCost`=2573 AND `type`=1); -- Pink Spring Circlet
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=74282 AND `ExtendedCost`=2573 AND `type`=1); -- Black Spring Circlet
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=72145 AND `ExtendedCost`=3689 AND `type`=1); -- Swift Springstrider
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=116258 AND `ExtendedCost`=2574 AND `type`=1); -- Mystical Spring Bouquet
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=141532 AND `ExtendedCost`=6131 AND `type`=1); -- Noblegarden Bunny
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=44794 AND `ExtendedCost`=2574 AND `type`=1); -- Spring Rabbit's Foot
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=44803 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Circlet
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=151806 AND `ExtendedCost`=2573 AND `type`=1); -- Elegant Dress
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=151804 AND `ExtendedCost`=2572 AND `type`=1); -- Black Tuxedo Pants
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=6833 AND `ExtendedCost`=2572 AND `type`=1); -- White Tuxedo Shirt
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=188694 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Florist's Pouch
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=44800 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Robes
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=45073 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Flowers
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=44792 AND `ExtendedCost`=2571 AND `type`=1); -- Blossoming Branch
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=53989 WHERE (`entry`=32837 AND `item`=44818 AND `ExtendedCost`=2575 AND `type`=1); -- Noblegarden Egg

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (415075 /*Noblegarden Hanging Wreath 0.1 [DNT]*/, 428725 /*Noblegarden Streamers - One-sided - Small Hanging [DNT]*/, 415066 /*Noblegarden Candle - Pink [DNT]*/, 415058 /*Noblegarden Banner - Double Post [DNT]*/, 415067 /*Noblegarden Crate - Closed [DNT]*/, 415057 /*Noblegarden Banner - Single Standing [DNT]*/, 415722 /*Noblegarden Hanging Wreath [DNT]*/, 415069 /*Noblegarden Crate - Open [DNT]*/, 415074 /*Noblegarden Wreath Standing [DNT]*/, 415838 /*Noblegarden Candle - Floating [DNT]*/, 415070 /*Noblegarden Flower Vase [DNT]*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(415075, 5, 86405, 'Noblegarden Hanging Wreath 0.1 [DNT]', '', '', '', 0.100000001490116119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Hanging Wreath 0.1 [DNT]
(428725, 5, 88348, 'Noblegarden Streamers - One-sided - Small Hanging [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Streamers - One-sided - Small Hanging [DNT]
(415066, 5, 86397, 'Noblegarden Candle - Pink [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Candle - Pink [DNT]
(415058, 5, 86395, 'Noblegarden Banner - Double Post [DNT]', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Banner - Double Post [DNT]
(415067, 5, 86398, 'Noblegarden Crate - Closed [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Crate - Closed [DNT]
(415057, 5, 86394, 'Noblegarden Banner - Single Standing [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Banner - Single Standing [DNT]
(415722, 5, 86405, 'Noblegarden Hanging Wreath [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Hanging Wreath [DNT]
(415069, 5, 86399, 'Noblegarden Crate - Open [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Crate - Open [DNT]
(415074, 5, 86404, 'Noblegarden Wreath Standing [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Wreath Standing [DNT]
(415838, 5, 86601, 'Noblegarden Candle - Floating [DNT]', '', '', '', 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989), -- Noblegarden Candle - Floating [DNT]
(415070, 5, 86400, 'Noblegarden Flower Vase [DNT]', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53989); -- Noblegarden Flower Vase [DNT]

UPDATE `gameobject_template` SET `Data18`=5, `VerifiedBuild`=53989 WHERE `entry`=113769; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `Data18`=5, `VerifiedBuild`=53989 WHERE `entry`=113771; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `Data18`=5, `VerifiedBuild`=53989 WHERE `entry`=113770; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `Data18`=5, `VerifiedBuild`=53989 WHERE `entry`=113768; -- Brightly Colored Egg

UPDATE `gameobject_template_addon` SET `flags`=2375680 WHERE `entry` IN (113771, 113770, 113769, 113768); -- Brightly Colored Egg

-- Quests
UPDATE `quest_template` SET `TreasurePickerID`=2595, `QuestDescription`='Noblegarden, celebration of life and spring! I hope you\'ve been enjoying the egg hunt, friend, because I could use the services of a capable individual like you. \n\nI\'m not certain what form of magic was used in the creation of the eggs, and the druids aren\'t keen on explaining it to me. Perhaps you could collect some shell fragments for me during your egg collection. You can keep the contents of the eggs; all I require is a sufficient sample of the eggs themselves.', `VerifiedBuild`=53989 WHERE `ID`=13479; -- The Great Egg Hunt
UPDATE `quest_template` SET `TreasurePickerID`=2596, `QuestDescription`='Here--take this egg basket and go hunting for brightly colored eggs. Return to me with the basket when you\'ve found ten Noblegarden chocolates.', `VerifiedBuild`=53989 WHERE `ID`=13503; -- A Tisket, a Tasket, a Noblegarden Basket
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=13479;

DELETE FROM `quest_poi` WHERE `QuestID`=13479;
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(13479, 4, 10, 32, 0, 0, 530, 110, 0, 0, 0, 0, 0, 277151, 0, 53989), -- The Great Egg Hunt
(13479, 3, 9, 32, 0, 0, 530, 94, 0, 0, 0, 0, 0, 277151, 0, 53989), -- The Great Egg Hunt
(13479, 2, 8, 32, 0, 0, 0, 18, 0, 0, 0, 0, 0, 276913, 0, 53989), -- The Great Egg Hunt
(13479, 1, 7, 32, 0, 0, 1, 7, 0, 0, 0, 0, 0, 276988, 0, 53989), -- The Great Egg Hunt
(13479, 0, 6, 32, 0, 0, 1, 1, 0, 0, 0, 0, 0, 277067, 0, 53989), -- The Great Egg Hunt
(13479, 0, 5, 0, 251936, 44806, 2444, 2112, 0, 0, 0, 116906, 0, 0, 0, 53989), -- The Great Egg Hunt
(13479, 3, 4, -1, 0, 0, 530, 94, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13479, 2, 3, -1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13479, 1, 2, -1, 0, 0, 1, 7, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13479, 0, 1, -1, 0, 0, 0, 18, 0, 1, 0, 0, 0, 0, 0, 53989), -- The Great Egg Hunt
(13479, 0, 0, -1, 0, 0, 2444, 2112, 0, 0, 0, 0, 0, 2417785, 0, 53989); -- The Great Egg Hunt

UPDATE `quest_poi` SET `VerifiedBuild`=53989 WHERE (`QuestID`=13503 AND `BlobIndex`=4 AND `Idx1`=10) OR (`QuestID`=13503 AND `BlobIndex`=3 AND `Idx1`=9) OR (`QuestID`=13503 AND `BlobIndex`=2 AND `Idx1`=8) OR (`QuestID`=13503 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=13503 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=13503 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=13503 AND `BlobIndex`=4 AND `Idx1`=4) OR (`QuestID`=13503 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13503 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13503 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13503 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32008 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32008 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=75874 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=61874 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=61874 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=61874 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=61874 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=61874 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=61874 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=61874 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56120 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56120 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53435 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53435 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50606 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50603 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49930 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49930 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE `QuestID`=13479;
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(13479, 10, 0, 9494, -6840, 0, 53989), -- The Great Egg Hunt
(13479, 9, 0, 9494, -6840, 17, 53989), -- The Great Egg Hunt
(13479, 8, 0, 2237, 249, 34, 53989), -- The Great Egg Hunt
(13479, 7, 0, -2332, -353, -9, 53989), -- The Great Egg Hunt
(13479, 6, 0, 325, -4703, 16, 53989), -- The Great Egg Hunt
(13479, 5, 8, 19, -1002, 838, 53989), -- The Great Egg Hunt
(13479, 5, 7, -17, -836, 838, 53989), -- The Great Egg Hunt
(13479, 5, 6, 73, -796, 842, 53989), -- The Great Egg Hunt
(13479, 5, 5, 105, -824, 849, 53989), -- The Great Egg Hunt
(13479, 5, 4, 151, -868, 840, 53989), -- The Great Egg Hunt
(13479, 5, 3, 196, -927, 844, 53989), -- The Great Egg Hunt
(13479, 5, 2, 198, -960, 858, 53989), -- The Great Egg Hunt
(13479, 5, 1, 156, -993, 857, 53989), -- The Great Egg Hunt
(13479, 5, 0, 47, -1012, 838, 53989), -- The Great Egg Hunt
(13479, 4, 0, 9494, -6840, 17, 53989), -- The Great Egg Hunt
(13479, 3, 0, 325, -4703, 16, 53989), -- The Great Egg Hunt
(13479, 2, 0, -2332, -353, -9, 53989), -- The Great Egg Hunt
(13479, 1, 0, 2237, 249, 34, 53989), -- The Great Egg Hunt
(13479, 0, 0, 64, -987, 838, 53989); -- The Great Egg Hunt

UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=53989 WHERE `ID`=13479; -- The Great Egg Hunt
UPDATE `quest_details` SET `VerifiedBuild`=53989 WHERE `ID`=13503;

UPDATE `quest_request_items` SET `CompletionText`='Do you have the Noblegarden chocolates?', `VerifiedBuild`=53989 WHERE `ID`=13503; -- A Tisket, a Tasket, a Noblegarden Basket
UPDATE `quest_request_items` SET `VerifiedBuild`=53989 WHERE `ID`=13479;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=53989 WHERE `ID`=13479;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 32798, 530, 3430, 3665, '0', 0, 0, 0, 0, 9543.50390625, -6834.98095703125, 16.57668685913085937, 2.032543659210205078, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Spring Gatherer (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@CGUID+1, 32837, 530, 3430, 3665, '0', 0, 0, 0, 1, 9544.873046875, -6833.6962890625, 16.57664108276367187, 2.880001068115234375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989); -- Noblegarden Merchant (Area: Falconwing Square - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+90;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113770, 530, 3430, 3665, '0', 0, 0, 9465.041015625, -6770.330078125, 16.55310630798339843, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+1, 113768, 530, 3430, 3665, '0', 0, 0, 9465.3388671875, -6789.05126953125, 16.54677009582519531, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+2, 113770, 530, 3430, 3665, '0', 0, 0, 9468.0439453125, -6795.830078125, 17.0894775390625, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+3, 113769, 530, 3430, 3533, '0', 0, 0, 9468.7314453125, -6813.2080078125, 16.87607192993164062, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+4, 113768, 530, 3430, 3665, '0', 0, 0, 9473.0537109375, -6814.23828125, 16.96545600891113281, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+5, 113769, 530, 3430, 3665, '0', 0, 0, 9475.248046875, -6809.73876953125, 16.58126640319824218, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+6, 113768, 530, 3430, 3665, '0', 0, 0, 9475.8251953125, -6802.6904296875, 16.49495124816894531, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+7, 113768, 530, 3430, 3665, '0', 0, 0, 9476.580078125, -6803.029296875, 17.40802955627441406, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+8, 113770, 530, 3430, 3665, '0', 0, 0, 9477.859375, -6794.8310546875, 16.49660873413085937, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+9, 113771, 530, 3430, 3665, '0', 0, 0, 9477.9296875, -6806.37353515625, 16.49356460571289062, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+10, 113769, 530, 3430, 3665, '0', 0, 0, 9480.9208984375, -6818.58984375, 16.70401763916015625, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 530, 3430, 3665, '0', 0, 0, 9481.080078125, -6815.55712890625, 16.54894065856933593, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+12, 113768, 530, 3430, 3665, '0', 0, 0, 9481.3212890625, -6769.88427734375, 16.50426864624023437, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+13, 113770, 530, 3430, 3665, '0', 0, 0, 9482.1640625, -6833.26025390625, 17.44304656982421875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+14, 113770, 530, 3430, 3665, '0', 0, 0, 9483.5869140625, -6825.03515625, 16.76105880737304687, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 530, 3430, 3665, '0', 0, 0, 9483.8017578125, -6827.62841796875, 16.69309425354003906, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+16, 113768, 530, 3430, 3665, '0', 0, 0, 9485.275390625, -6829.40185546875, 16.59279823303222656, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 530, 3430, 3665, '0', 0, 0, 9491.375, -6766.29150390625, 16.49406814575195312, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+18, 113771, 530, 3430, 3533, '0', 0, 0, 9495.4658203125, -6846.54931640625, 17.44208908081054687, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+19, 113768, 530, 3430, 3665, '0', 0, 0, 9501.7158203125, -6844.98974609375, 16.67441940307617187, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+20, 113768, 530, 3430, 3665, '0', 0, 0, 9502.2998046875, -6762.97021484375, 17.01189994812011718, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+21, 113771, 530, 3430, 3665, '0', 0, 0, 9502.6474609375, -6842.96630859375, 16.54372978210449218, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+22, 113768, 530, 3430, 3665, '0', 0, 0, 9505.6328125, -6800.7177734375, 16.49178695678710937, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+23, 113771, 530, 3430, 3665, '0', 0, 0, 9507.724609375, -6846.98681640625, 16.99977302551269531, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+24, 113769, 530, 3430, 3665, '0', 0, 0, 9511.4794921875, -6770.26513671875, 16.49357795715332031, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+25, 113768, 530, 3430, 3532, '0', 0, 0, 9512.5, -6851.67578125, 16.92402076721191406, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Dawning Lane - Difficulty: 0) CreateObject2
(@OGUID+26, 113769, 530, 3430, 3665, '0', 0, 0, 9512.7314453125, -6804.7919921875, 17.32817268371582031, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+27, 113771, 530, 3430, 3665, '0', 0, 0, 9513.88671875, -6792.2490234375, 16.49246025085449218, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+28, 113770, 530, 3430, 3665, '0', 0, 0, 9515.3251953125, -6849.64697265625, 16.58533477783203125, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+29, 113769, 530, 3430, 3665, '0', 0, 0, 9515.3515625, -6857.80712890625, 16.58345222473144531, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+30, 113769, 530, 3430, 3665, '0', 0, 0, 9516.333984375, -6771.748046875, 16.49357795715332031, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+31, 113771, 530, 3430, 3665, '0', 0, 0, 9516.921875, -6803.25537109375, 17.32817268371582031, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+32, 113768, 530, 3430, 3665, '0', 0, 0, 9516.9736328125, -6806.08203125, 17.32817268371582031, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+33, 113770, 530, 3430, 3665, '0', 0, 0, 9517.7041015625, -6799.71533203125, 17.32817268371582031, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+34, 113769, 530, 3430, 3665, '0', 0, 0, 9517.8701171875, -6809.6748046875, 17.32817268371582031, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+35, 113768, 530, 3430, 3665, '0', 0, 0, 9517.8798828125, -6850.23095703125, 16.49357223510742187, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+36, 113769, 530, 3430, 3665, '0', 0, 0, 9519.1904296875, -6804.69189453125, 17.32817268371582031, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+37, 113768, 530, 3430, 3665, '0', 0, 0, 9520.5126953125, -6769.96240234375, 16.46599578857421875, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+38, 113769, 530, 3430, 3665, '0', 0, 0, 9521.6435546875, -6816.15478515625, 16.48992347717285156, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+39, 113770, 530, 3430, 3665, '0', 0, 0, 9522.673828125, -6804.63916015625, 17.32817268371582031, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+40, 113770, 530, 3430, 3665, '0', 0, 0, 9528.9765625, -6806.951171875, 16.49247932434082031, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+41, 113769, 530, 3430, 3665, '0', 0, 0, 9529.376953125, -6765.759765625, 15.29880237579345703, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+42, 113768, 530, 3430, 3665, '0', 0, 0, 9535.8505859375, -6858.06494140625, 16.67221450805664062, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+43, 113768, 530, 3430, 3665, '0', 0, 0, 9536.599609375, -6850.8671875, 16.52987098693847656, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+44, 113771, 530, 3430, 3665, '0', 0, 0, 9541.005859375, -6791.65625, 16.47096633911132812, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+45, 113769, 530, 3430, 3533, '0', 0, 0, 9542.0224609375, -6853.79150390625, 17.39933013916015625, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject1
(@OGUID+46, 113771, 530, 3430, 3665, '0', 0, 0, 9543.0654296875, -6858.04443359375, 17.3531036376953125, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 530, 3430, 3533, '0', 0, 0, 9543.541015625, -6796.333984375, 16.48163414001464843, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+48, 113771, 530, 3430, 3665, '0', 0, 0, 9543.6142578125, -6786.87060546875, 16.21173667907714843, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+49, 113769, 530, 3430, 3665, '0', 0, 0, 9545.056640625, -6835.8037109375, 16.53373146057128906, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+50, 113771, 530, 3430, 3665, '0', 0, 0, 9545.3935546875, -6777.9873046875, 14.78086566925048828, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+51, 113771, 530, 3430, 3665, '0', 0, 0, 9545.62109375, -6850.70849609375, 17.35140419006347656, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+52, 113768, 530, 3430, 3665, '0', 0, 0, 9546.796875, -6839.79541015625, 16.49825668334960937, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+53, 113768, 530, 3430, 3665, '0', 0, 0, 9549.0673828125, -6848.283203125, 17.22985267639160156, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+54, 113768, 530, 3430, 3665, '0', 0, 0, 9549.1708984375, -6806.85986328125, 16.44730186462402343, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+55, 113770, 530, 3430, 3665, '0', 0, 0, 9551.2763671875, -6828.86669921875, 16.4930419921875, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+56, 113769, 530, 3430, 3665, '0', 0, 0, 9551.388671875, -6831.77734375, 16.49342536926269531, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+57, 113770, 530, 3430, 3665, '0', 0, 0, 9552.7314453125, -6830.08056640625, 17.609283447265625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 530, 3430, 3665, '0', 0, 0, 9552.9208984375, -6815.78662109375, 16.37353515625, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+59, 113771, 530, 3430, 3665, '0', 0, 0, 9555.13671875, -6828.63671875, 16.49392318725585937, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+60, 113770, 530, 3430, 3665, '0', 0, 0, 9555.3203125, -6831.57177734375, 16.4930572509765625, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+61, 113768, 530, 3430, 3665, '0', 0, 0, 9555.583984375, -6825.9541015625, 16.49430656433105468, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+62, 113768, 530, 3430, 3665, '0', 0, 0, 9556.2744140625, -6847.72412109375, 17.26838493347167968, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+63, 113771, 530, 3430, 3665, '0', 0, 0, 9557.2041015625, -6835.95166015625, 16.53261756896972656, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 300, 255, 1, 53989), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+64, 415057, 530, 3430, 3665, '0', 0, 0, 9562.4736328125, -6758.3505859375, 11.64057731628417968, 1.207445025444030761, 0, 0, 0.56771087646484375, 0.823228001594543457, 120, 255, 1, 53989), -- Noblegarden Banner - Single Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+65, 415057, 530, 3430, 3665, '0', 0, 0, 9533.9658203125, -6761.40478515625, 13.77744865417480468, 0.321937501430511474, 0, 0, 0.160274505615234375, 0.987072467803955078, 120, 255, 1, 53989), -- Noblegarden Banner - Single Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+66, 415057, 530, 3430, 3665, '0', 0, 0, 9563.9267578125, -6811.73974609375, 17.27234840393066406, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Banner - Single Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+67, 415058, 530, 3430, 3665, '0', 0, 0, 9544.69140625, -6834.970703125, 16.26798248291015625, 2.325549840927124023, 0, 0, 0.91790771484375, 0.396793931722640991, 120, 255, 1, 53989), -- Noblegarden Banner - Double Post [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+68, 415066, 530, 3430, 3665, '0', 0, 0, 9478.67578125, -6808.9775390625, 18.68935203552246093, 6.251605510711669921, 0.027566909790039062, 0.012857437133789062, -0.01614570617675781, 0.999406874179840087, 120, 255, 1, 53989), -- Noblegarden Candle - Pink [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+69, 415067, 530, 3430, 3665, '0', 0, 0, 9469.3505859375, -6795.86279296875, 17.01796340942382812, 5.814092159271240234, -0.0302748680114746, 0.016658782958984375, -0.23196601867675781, 0.972109913825988769, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+70, 415067, 530, 3430, 3665, '0', 0, 0, 9468.7705078125, -6795.0380859375, 18.17601203918457031, 5.337614059448242187, -0.04013538360595703, 0.005680084228515625, -0.4554452896118164, 0.889340460300445556, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+71, 415067, 530, 3430, 3665, '0', 0, 0, 9468.3310546875, -6794.65625, 16.99466705322265625, 5.426064968109130859, -0.02892303466796875, 0.014117240905761718, -0.41532230377197265, 0.909104824066162109, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+72, 415067, 530, 3430, 3665, '0', 0, 0, 9545.0400390625, -6837.46337890625, 16.4934539794921875, 5.4140472412109375, 0, 0, -0.42101955413818359, 0.907051563262939453, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+73, 415067, 530, 3430, 3665, '0', 0, 0, 9546.5517578125, -6836.9599609375, 16.49346733093261718, 0.141498327255249023, 0, 0, 0.070690155029296875, 0.99749833345413208, 120, 255, 1, 53989), -- Noblegarden Crate - Closed [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+74, 415069, 530, 3430, 3665, '0', 0, 0, 9544.9814453125, -6835.80029296875, 16.49346351623535156, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Crate - Open [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+75, 415070, 530, 3430, 3665, '0', 0, 0, 9494.0810546875, -6860.0400390625, 18.63901138305664062, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+76, 415070, 530, 3430, 3665, '0', 0, 0, 9465.2314453125, -6849.173828125, 18.54521369934082031, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+77, 415070, 530, 3430, 3665, '0', 0, 0, 9487.1953125, -6822.5849609375, 17.17298316955566406, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+78, 415070, 530, 3430, 3665, '0', 0, 0, 9552.0595703125, -6827.6162109375, 17.61172103881835937, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Flower Vase [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+79, 415074, 530, 3430, 3665, '0', 0, 0, 9534.8876953125, -6847.923828125, 16.49345016479492187, 2.345257282257080078, 0, 0, 0.921772956848144531, 0.387730062007904052, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+80, 415074, 530, 3430, 3665, '0', 0, 0, 9498.240234375, -6841.359375, 16.49357032775878906, 1.50025796890258789, 0, 0, 0.681733131408691406, 0.731600940227508544, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+81, 415074, 530, 3430, 3665, '0', 0, 0, 9518.009765625, -6850.41162109375, 16.49357223510742187, 1.09900832176208496, 0, 0, 0.522264480590820312, 0.852783560752868652, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+82, 415074, 530, 3430, 3665, '0', 0, 0, 9467.0517578125, -6787.205078125, 16.49356460571289062, 0.696298897266387939, 0, 0, 0.341158866882324218, 0.940005660057067871, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+83, 415074, 530, 3430, 3665, '0', 0, 0, 9467.373046875, -6772.3056640625, 16.51926422119140625, 5.849381446838378906, 0, 0, -0.21520519256591796, 0.976568818092346191, 120, 255, 1, 53989), -- Noblegarden Wreath Standing [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+84, 415075, 530, 3430, 3665, '0', 0, 0, 9477.6796875, -6859.74853515625, 20.92499542236328125, 2.340645790100097656, 0, 0, 0.920876502990722656, 0.38985443115234375, 120, 255, 1, 53989), -- Noblegarden Hanging Wreath 0.1 [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+85, 415722, 530, 3430, 3665, '0', 0, 0, 9465.849609375, -6781.015625, 35.43180084228515625, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Hanging Wreath [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+86, 415838, 530, 3430, 3665, '0', 0, 0, 9519.45703125, -6801.7568359375, 17.49224281311035156, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Floating [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+87, 415838, 530, 3430, 3665, '0', 0, 0, 9519.416015625, -6807.7880859375, 17.49225425720214843, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Floating [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+88, 415838, 530, 3430, 3665, '0', 0, 0, 9514.6533203125, -6804.73974609375, 17.49224090576171875, 0, 0, 0, 0, 1, 120, 255, 1, 53989), -- Noblegarden Candle - Floating [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+89, 428725, 530, 3430, 3665, '0', 0, 0, 9525.912109375, -6861.82666015625, 27.10174751281738281, 1.553049921989440917, 0, 0, 0.700804710388183593, 0.713353157043457031, 120, 255, 1, 53989), -- Noblegarden Streamers - One-sided - Small Hanging [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+90, 428725, 530, 3430, 3665, '0', 0, 0, 9488.7294921875, -6840.00537109375, 25.13157081604003906, 0.77790224552154541, 0, 0, 0.379218101501464843, 0.925307333469390869, 120, 255, 1, 53989); -- Noblegarden Streamers - One-sided - Small Hanging [DNT] (Area: Falconwing Square - Difficulty: 0) CreateObject1

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+63;
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
(1, @OGUID+63, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+90;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+64),
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
(@EVENT, @OGUID+90);
