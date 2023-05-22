SET @CGUID := 396023;
SET @OGUID := 244043;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=190070; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=190070; -- Candy Bucket

-- Quests
DELETE FROM `quest_poi` WHERE (`QuestID`=8359 AND `BlobIndex`=2 AND `Idx1`=4) OR (`QuestID`=8359 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=8359 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8359 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8359 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(8359, 2, 4, 32, 0, 0, 1, 85, 0, 0, 0, 0, 0, 80068, 0, 46366), -- Flexing for Nougat
(8359, 1, 3, 32, 0, 0, 1, 85, 0, 0, 0, 0, 0, 1099973, 0, 46366), -- Flexing for Nougat
(8359, 0, 2, 32, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1105479, 0, 46366), -- Flexing for Nougat
(8359, 0, 1, 0, 258953, 6929, 1, 1, 0, 1, 0, 0, 0, 0, 0, 46366), -- Flexing for Nougat
(8359, 0, 0, -1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 46366); -- Flexing for Nougat

UPDATE `quest_poi` SET `VerifiedBuild`=46366 WHERE (`QuestID`=8358 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8358 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8358 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=8360 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=8360 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=8360 AND `BlobIndex`=0 AND `Idx1`=0);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=8359 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=8359 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=8359 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8359 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8359 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(8359, 4, 0, 1573, -4439, 16, 46366), -- Flexing for Nougat
(8359, 3, 0, 1571, -4434, 16, 46366), -- Flexing for Nougat
(8359, 2, 0, 1238, -4395, 28, 46366), -- Flexing for Nougat
(8359, 1, 0, 1634, -4439, 28, 46366), -- Flexing for Nougat
(8359, 0, 0, 1634, -4439, 28, 46366); -- Flexing for Nougat

UPDATE `quest_poi_points` SET `VerifiedBuild`=46366 WHERE (`QuestID`=8358 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8358 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8358 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=8360 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=8360 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=8360 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (8358, 8359, 8360);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8358, 5, 1, 0, 0, 0, 0, 0, 0, 46366), -- Incoming Gumdrop
(8359, 5, 1, 0, 0, 0, 0, 0, 0, 46366), -- Flexing for Nougat
(8360, 1, 1, 0, 0, 0, 0, 0, 0, 46366); -- Dancing for Marzipan

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=46366 WHERE `ID`=8358; -- Incoming Gumdrop
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='No candy until you flex for me, $n...', `VerifiedBuild`=46366 WHERE `ID`=8359; -- Flexing for Nougat
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='You know how to dance, don''t you?  Try by putting your right foot in... then your right foot out... your right foot in... shake it all about...', `VerifiedBuild`=46366 WHERE `ID`=8360; -- Dancing for Marzipan

UPDATE `quest_offer_reward` SET `RewardText`='Wow, you got them all!  You''re awesome!$B$BThank you for trick-or-treating for me.  Here, take these pumpkin treats - I think you''ll like them a lot!$B$BHappy Hallow''s End, $n!', `VerifiedBuild`=46366 WHERE `ID`=8312; -- Hallow's End Treats for Spoops!
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `RewardText`='Woo-woo!  Well done, $n!  Here''s your treat.$B$BHappy Hallow''s End!', `VerifiedBuild`=46366 WHERE `ID`=8358; -- Incoming Gumdrop
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `RewardText`='You are truly mighty, haha!  Well done, and thanks for being such a good sport.  Here''s your candy.$B$BHappy Hallow''s End, $n!', `VerifiedBuild`=46366 WHERE `ID`=8359; -- Flexing for Nougat
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `RewardText`='You''re quite the dancing machine, $n!$B$BHere''s your treat for being such a good sport.  Happy Hallow''s End, and give my best to your little friend!', `VerifiedBuild`=46366 WHERE `ID`=8360; -- Dancing for Marzipan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=12367;

UPDATE `creature_queststarter` SET `VerifiedBuild`=46366 WHERE (`id`=6929 AND `quest`=8359) OR (`id`=11814 AND `quest`=8358);
UPDATE `creature_queststarter` SET `VerifiedBuild`=46366 WHERE (`id`=6746 AND `quest`=8360);

UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=6929 AND `quest`=8359) OR (`id`=15309 AND `quest`=8312) OR (`id`=11814 AND `quest`=8358);
UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=6746 AND `quest`=8360);

DELETE FROM `gameobject_queststarter` WHERE `id`=190070;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190070, 12367, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=190070 AND `quest`=12367);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190070;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 19176, 1, 1638, 5345, '0', 0, 0, 0, 0, -1240.88720703125, 87.83853912353515625, 129.19622802734375, 1.48352980613708496, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Tauren Commoner (Area: Thunder Bluff - Difficulty: 0)
(@CGUID+1, 19176, 1, 1638, 5345, '0', 0, 0, 0, 0, -1240.5191650390625, 90.63541412353515625, 129.010406494140625, 4.834561824798583984, 120, 0, 0, 18771, 0, 0, 3, 0, 0, 46366), -- Tauren Commoner (Area: Thunder Bluff - Difficulty: 0)
(@CGUID+2, 40435, 1, 1638, 5345, '0', 0, 0, 0, 0, -1273.0242919921875, 71.2743072509765625, 127.0668182373046875, 5.8817596435546875, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Headless Ghost (Area: Thunder Bluff - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 227397 AND 227432;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 228126 AND 228150;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 227397 AND 227432;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 228126 AND 228150;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+40;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 1638, 1640, '0', 0, 0, -1021.65948486328125, 215.7366790771484375, 109.1904830932617187, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+1, 180405, 1, 1638, 1640, '0', 0, 0, -998.4334716796875, 245.6555938720703125, 106.3701324462890625, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+2, 180405, 1, 1638, 5345, '0', 0, 0, -1210.3438720703125, 140.6678009033203125, 134.1575164794921875, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+3, 180405, 1, 1638, 5345, '0', 0, 0, -1230.8172607421875, 44.46636199951171875, 127.5323486328125, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+4, 180405, 1, 1638, 5345, '0', 0, 0, -1275.2879638671875, 44.20529556274414062, 131.5706939697265625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+5, 180405, 1, 1638, 5345, '0', 0, 0, -1296.1685791015625, 102.6677780151367187, 130.9096832275390625, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+6, 180405, 1, 1638, 5345, '0', 0, 0, -1259.66845703125, 134.935760498046875, 135.289031982421875, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+7, 180406, 1, 1638, 1640, '0', 0, 0, -949.02618408203125, 256.280853271484375, 97.3452301025390625, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+8, 180406, 1, 1638, 1640, '0', 0, 0, -1064.142333984375, 201.5069427490234375, 108.4929428100585937, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+9, 180406, 1, 1638, 5345, '0', 0, 0, -1216.154541015625, 82.280792236328125, 130.2654571533203125, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+10, 180406, 1, 1638, 5345, '0', 0, 0, -1281.90625, 54.8836822509765625, 131.991729736328125, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+11, 180406, 1, 1638, 5345, '0', 0, 0, -1251.5703125, 135.697998046875, 132.56585693359375, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+12, 180406, 1, 1638, 5345, '0', 0, 0, -1290.6024169921875, 132.8055572509765625, 134.5710601806640625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+13, 180407, 1, 1638, 1640, '0', 0, 0, -981.6856689453125, 290.841583251953125, 110.6410293579101562, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+14, 180407, 1, 1638, 1640, '0', 0, 0, -1056.1158447265625, 198.6920318603515625, 109.130157470703125, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+15, 180407, 1, 1638, 5345, '0', 0, 0, -1199.840087890625, 114.1048431396484375, 134.9963531494140625, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+16, 180407, 1, 1638, 5345, '0', 0, 0, -1263.5943603515625, 40.30658721923828125, 130.707000732421875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+17, 180407, 1, 1638, 5345, '0', 0, 0, -1280.9012451171875, 81.91357421875, 128.3212738037109375, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+18, 180407, 1, 1638, 5345, '0', 0, 0, -1290.6397705078125, 150.0279083251953125, 129.7321319580078125, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+19, 180411, 1, 1638, 0, '0', 0, 0, -1303.5010986328125, 36.4716796875, 135.76690673828125, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 46366), -- G_Ghost_01 (Area: 0 - Difficulty: 0)
(@OGUID+20, 180426, 1, 1638, 1640, '0', 0, 0, -995.53302001953125, 243.704864501953125, 108.2483596801757812, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+21, 180426, 1, 1638, 1640, '0', 0, 0, -995.31427001953125, 243.90625, 107.4028778076171875, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+22, 180426, 1, 1638, 1640, '0', 0, 0, -995.29339599609375, 243.704864501953125, 108.2324600219726562, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+23, 180426, 1, 1638, 1640, '0', 0, 0, -995.8680419921875, 243.8368072509765625, 108.257049560546875, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+24, 180426, 1, 1638, 1640, '0', 0, 0, -996.5555419921875, 244.329864501953125, 108.9696731567382812, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+25, 180426, 1, 1638, 1640, '0', 0, 0, -995.467041015625, 243.763885498046875, 109.227203369140625, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+26, 180426, 1, 1638, 1640, '0', 0, 0, -995.50518798828125, 243.90625, 108.4117889404296875, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+27, 180426, 1, 1638, 1640, '0', 0, 0, -997.2742919921875, 243.33160400390625, 109.18389892578125, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+28, 180426, 1, 1638, 1640, '0', 0, 0, -995.40277099609375, 243.9600677490234375, 110.2166290283203125, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+29, 180426, 1, 1638, 1640, '0', 0, 0, -995.56427001953125, 243.4739532470703125, 109.0562515258789062, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46366), -- Bat01 (Area: Spirit Rise - Difficulty: 0)
(@OGUID+30, 180471, 1, 1638, 5345, '0', 0, 0, -1276.5208740234375, 44.42534637451171875, 136.6909637451171875, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+31, 180471, 1, 1638, 5345, '0', 0, 0, -1281.4305419921875, 53.75520706176757812, 136.660888671875, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+32, 180471, 1, 1638, 0, '0', 0, 0, -1322.24658203125, 29.25173568725585937, 143.4975128173828125, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: 0 - Difficulty: 0)
(@OGUID+33, 180471, 1, 1638, 5345, '0', 0, 0, -1291.1082763671875, 42.1400299072265625, 141.058563232421875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+34, 180472, 1, 1638, 5345, '0', 0, 0, -1277.5731201171875, 50.0302734375, 138.39410400390625, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+35, 180472, 1, 1638, 0, '0', 0, 0, -1309.47509765625, 36.8388671875, 136.3897705078125, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+36, 180472, 1, 1638, 0, '0', 0, 0, -1311.2232666015625, 31.85422134399414062, 136.4650421142578125, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+37, 180472, 1, 1638, 5345, '0', 0, 0, -1294.5069580078125, 39.54340362548828125, 136.4569549560546875, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+38, 180472, 1, 1638, 5345, '0', 0, 0, -1301.648193359375, 41.0711822509765625, 136.4337921142578125, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+39, 180523, 1, 1638, 5345, '0', 0, 0, -1286.758056640625, 37.50309371948242187, 129.4862823486328125, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 46366), -- Apple Bob (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+40, 190070, 1, 1638, 0, '0', 0, 0, -1301.7337646484375, 40.52208328247070312, 129.2085113525390625, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, 46366); -- Candy Bucket (Area: 0 - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0),
(12, @CGUID+1),
(12, @CGUID+2);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+40;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40);
