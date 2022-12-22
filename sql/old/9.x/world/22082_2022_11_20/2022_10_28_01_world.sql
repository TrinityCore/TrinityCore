SET @CGUID := 395775;
SET @OGUID := 242412;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=8987, `maxlevel`=3 WHERE `entry`=23971; -- Traveling Orphan
UPDATE `creature_template` SET `gossip_menu_id`=9471, `minlevel`=60, `maxlevel`=60 WHERE `entry`=23973; -- Masked Orphan Matron

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23971; -- 23971 (Traveling Orphan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23973; -- 23973 (Masked Orphan Matron)

-- Gossips
DELETE FROM `gossip_menu` WHERE `MenuID`=8987 AND `TextID`=11477;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8987, 11477, 45745); -- 23971 (Traveling Orphan)

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE (`MenuID`=9471 AND `TextID`=11473) OR (`MenuID`=8989 AND `TextID`=12137) OR (`MenuID`=8880 AND `TextID`=11590);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=9471 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9471, 0, 0, 'Who is the Headless Horseman?', 22620, 0, 8880, 0, 0, 0, NULL, 0, 45745);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (23973,23971));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(23973, 0, 0, 0, 425, 45745),
(23971, 0, -4, -2, 1723, 45745);

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=45745 WHERE `entry`=190067; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=190067; -- Candy Bucket

-- Quests
DELETE FROM `quest_poi` WHERE (`QuestID`=11219 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=11450 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=11450 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(11219, 0, 0, -1, 0, 0, 0, 18, 0, 1, 0, 0, 0, 0, 0, 45745), -- Stop the Fires!
(11450, 0, 1, 0, 262899, 23537, 530, 94, 0, 3, 0, 0, 0, 0, 0, 45745), -- Fire Training
(11450, 0, 0, -1, 0, 0, 530, 94, 0, 1, 0, 0, 0, 0, 0, 45745); -- Fire Training
 
UPDATE `quest_poi` SET `VerifiedBuild`=45745 WHERE (`QuestID`=12139 AND `BlobIndex`=2 AND `Idx1`=5) OR (`QuestID`=12139 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=12139 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=12139 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=12139 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=12139 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=12155 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=12155 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=12155 AND `BlobIndex`=0 AND `Idx1`=0);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=11219 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=11450 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=11450 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=11450 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=11450 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=11450 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(11219, 0, 0, 2240, 283, 34, 45745), -- Stop the Fires!
(11450, 1, 3, 9265, -6812, 27, 45745), -- Fire Training
(11450, 1, 2, 9211, -6809, 28, 45745), -- Fire Training
(11450, 1, 1, 9216, -6761, 26, 45745), -- Fire Training
(11450, 1, 0, 9257, -6761, 25, 45745), -- Fire Training
(11450, 0, 0, 9516, -6815, 16, 45745); -- Fire Training
 
UPDATE `quest_poi_points` SET `VerifiedBuild`=45745 WHERE (`QuestID`=12139 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=12139 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=12139 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=12139 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=12139 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=12139 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=12155 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=12155 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=12155 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (12139, 12155);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(12139, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- "Let the Fires Come!"
(12155, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Smash the Pumpkin

UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=45745 WHERE `ID`=11219; -- Stop the Fires!
UPDATE `quest_details` SET `VerifiedBuild`=45745 WHERE `ID`=11450; -- Fire Training
 
DELETE FROM `quest_request_items` WHERE `ID`=12139;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(12139, 0, 0, 0, 0, 'The Horde''s children need you!  Do not abandon them!', 45745); -- "Let the Fires Come!"

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=0, `CompletionText`='The Horde''s children need you!  Do not abandon them!', `VerifiedBuild`=45745 WHERE `ID`=11219; -- Stop the Fires!
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=45745 WHERE `ID`=11450; -- Fire Training
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=45745 WHERE `ID`=12155; -- Smash the Pumpkin

UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `RewardText`='The fires are out!  You and your fire brigade were victorious!  Hah!$B$BThe Headless Horseman''s attack has failed, but until he and his head are destroyed together, he will return.$B$BUntil then, however, let''s take comfort in the safety you brought our children.  I am honored to have watched your brave work today.', `VerifiedBuild`=45745 WHERE `ID`=11219; -- Stop the Fires!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `RewardText`='The fires are out!  You and your fire brigade were victorious!  Hah!$B$BThe Headless Horseman''s attack has failed, but until he and his head are destroyed together, he will return.$B$BUntil then, however, let''s take comfort in the safety you brought our children.  I am honored to have watched your brave work today.', `VerifiedBuild`=45745 WHERE `ID`=12139; -- "Let the Fires Come!"
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You found this inside the Headless Horseman''s jack-o-lantern?  It is an old symbol of the Light.  It must have been the Horseman''s, before he was cursed and turned into the monster he is today.  Thank you, $n.  This symbol deserves to be with paladins.  I will make sure they get it.$B$BOh, and I almost forgot!  You have a secret admirer...$B$BOne of the children wanted you to have this.  $gShe:He; was too shy to give it to you $gherself:himself;.', `VerifiedBuild`=45745 WHERE `ID`=12155; -- Smash the Pumpkin
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $n.  Children, take a good look at this $c.  Let $ghim:her; be a fine example for you to follow.', `VerifiedBuild`=45745 WHERE `ID`=11450; -- Fire Training
UPDATE `quest_offer_reward` SET `VerifiedBuild`=45745 WHERE `ID`=12364;

DELETE FROM `creature_queststarter` WHERE (`id`=23973 AND `quest`=12139);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(23973, 12139, 45745); -- "Let the Fires Come!" offered Masked Orphan Matron

UPDATE `creature_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=23973 AND `quest` IN (11219,11450));

UPDATE `creature_questender` SET `VerifiedBuild`=45745 WHERE (`id`=23973 AND `quest` IN (11219,12139,12155,11450));

DELETE FROM `game_event_creature_quest` WHERE `id`=23973;

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=45745 WHERE (`id`=186887 AND `quest`=12155);

UPDATE `gameobject_questender` SET `VerifiedBuild`=45745 WHERE (`id`=190067 AND `quest`=12364);

UPDATE `conditions` SET `Comment`='Show quest ''Fire Brigade Practice'' if player is located in Falconwing Square' WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=11450;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (17338,17339,19342,19345,84937,86582,86583,86584,86585,85707);
DELETE FROM `game_event_creature` WHERE `guid` IN (17338,17339,19342,19345,84937,86582,86583,86584,86585,85707);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+46;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 16221, 530, 3430, 0, '0', 0, 0, 0, 1, 9237.046875, -6772.4140625, 24.82743453979492187, 0.453785598278045654, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45745), -- Silvermoon Guardian (Area: 0 - Difficulty: 0)
(@CGUID+1, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9484.7578125, -6836.046875, 22.84036445617675781, 6.056292533874511718, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+2, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9488.1201171875, -6839.47705078125, 34.7965240478515625, 4.415682792663574218, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+3, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9492.0546875, -6843.42822265625, 24.72461128234863281, 6.195918560028076171, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+4, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9484.2314453125, -6835.5146484375, 26.35922622680664062, 0.541052043437957763, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+5, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9522.5439453125, -6861.8466796875, 27.51523971557617187, 0.383972436189651489, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+6, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9493.908203125, -6843.91259765625, 31.31162643432617187, 1.239183783531188964, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+7, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9493.0966796875, -6844.48193359375, 26.878021240234375, 4.660028934478759765, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+8, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9522.3330078125, -6860.87841796875, 30.574859619140625, 3.071779489517211914, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+9, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9490.0205078125, -6841.36962890625, 25.54996109008789062, 2.408554315567016601, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+10, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9493.873046875, -6845.267578125, 22.25846481323242187, 0.157079637050628662, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+11, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9518.2529296875, -6861.82470703125, 27.37059402465820312, 2.076941728591918945, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+12, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9491.857421875, -6842.9052734375, 31.83344650268554687, 4.031710624694824218, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+13, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9494.318359375, -6845.75146484375, 31.83377838134765625, 5.497786998748779296, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+14, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9528.8642578125, -6861.88330078125, 26.62176513671875, 1.989675283432006835, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+15, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9489.296875, -6839.09619140625, 30.86766242980957031, 3.892084121704101562, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+16, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9525.984375, -6861.8916015625, 35.42512893676757812, 2.460914134979248046, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+17, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9532.123046875, -6860.72119140625, 30.996368408203125, 1.448623299598693847, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+18, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9525.9580078125, -6861.89111328125, 32.72249221801757812, 5.410520553588867187, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+19, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9488.5869140625, -6839.94775390625, 32.0623321533203125, 1.361356854438781738, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+20, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9520.044921875, -6861.83349609375, 25.78749465942382812, 3.50811171531677246, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+21, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9530.2001953125, -6862.0107421875, 32.43022918701171875, 3.298672199249267578, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+22, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9486.5771484375, -6837.88671875, 26.53663063049316406, 3.577924966812133789, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+23, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9486.8564453125, -6836.50830078125, 30.49737930297851562, 0.122173048555850982, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+24, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9528.2822265625, -6860.74169921875, 31.19398117065429687, 2.879793167114257812, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+25, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9491.064453125, -6840.9013671875, 30.91507720947265625, 3.124139308929443359, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+26, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9519.9150390625, -6860.65185546875, 31.00365257263183593, 4.066617012023925781, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+27, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9484.3251953125, -6834.25146484375, 31.40592193603515625, 4.729842185974121093, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+28, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9525.7646484375, -6861.86376953125, 27.53145980834960937, 5.009094715118408203, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+29, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9484.677734375, -6835.826171875, 31.83631515502929687, 4.555309295654296875, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+30, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9523.30078125, -6861.935546875, 32.4274444580078125, 3.246312379837036132, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+31, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9530.9345703125, -6861.89453125, 23.13298606872558593, 0.314159274101257324, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+32, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9532.2177734375, -6861.90576171875, 26.8124542236328125, 2.687807083129882812, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+33, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9488.748046875, -6840.0791015625, 27.1339874267578125, 0.244346097111701965, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+34, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9516.0654296875, -6861.8115234375, 24.70286750793457031, 1.553343057632446289, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+35, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9534.833984375, -6861.92431640625, 26.10526657104492187, 2.234021425247192382, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+36, 23537, 530, 3430, 3665, '0', 0, 0, 0, 0, 9525.6728515625, -6860.65283203125, 30.71270751953125, 4.450589656829833984, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Falconwing Square - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+37, 23537, 530, 3430, 0, '0', 0, 0, 0, 0, 9235.0185546875, -6783.47607421875, 25.52999687194824218, 1.326450228691101074, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: 0 - Difficulty: 0)
(@CGUID+38, 23537, 530, 3430, 0, '0', 0, 0, 0, 0, 9229.3251953125, -6780.56396484375, 27.1305389404296875, 0.471238881349563598, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: 0 - Difficulty: 0)
(@CGUID+39, 23537, 530, 3430, 0, '0', 0, 0, 0, 0, 9225.48046875, -6765.25732421875, 26.13934898376464843, 0.279252678155899047, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: 0 - Difficulty: 0)
(@CGUID+40, 23537, 530, 3430, 0, '0', 0, 0, 0, 0, 9224.12890625, -6777.6748046875, 28.46907806396484375, 4.450589656829833984, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: 0 - Difficulty: 0)
(@CGUID+41, 23537, 530, 3430, 0, '0', 0, 0, 0, 0, 9224.6826171875, -6770.99609375, 27.34550857543945312, 5.846852779388427734, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: 0 - Difficulty: 0)
(@CGUID+42, 23971, 530, 3430, 3665, '0', 0, 0, 0, 0, 9514.5205078125, -6815.9541015625, 16.57184028625488281, 0.92502450942993164, 120, 0, 0, 41, 0, 0, 0, 0, 0, 45745), -- Traveling Orphan (Area: Falconwing Square - Difficulty: 0)
(@CGUID+43, 23971, 530, 3430, 3665, '0', 0, 0, 0, 0, 9515.90625, -6815.921875, 16.57149314880371093, 1.850049018859863281, 120, 0, 0, 41, 0, 0, 0, 0, 0, 45745), -- Traveling Orphan (Area: Falconwing Square - Difficulty: 0)
(@CGUID+44, 23971, 530, 3430, 3665, '0', 0, 0, 0, 0, 9517.009765625, -6815.09130859375, 16.537353515625, 2.844886541366577148, 120, 0, 0, 27, 0, 0, 0, 0, 0, 45745), -- Traveling Orphan (Area: Falconwing Square - Difficulty: 0)
(@CGUID+45, 23971, 530, 3430, 3665, '0', 0, 0, 0, 0, 9513.796875, -6814.9091796875, 16.56868362426757812, 0.157079637050628662, 120, 0, 0, 41, 0, 0, 0, 0, 0, 45745), -- Traveling Orphan (Area: Falconwing Square - Difficulty: 0)
(@CGUID+46, 23973, 530, 3430, 3665, '0', 0, 0, 0, 0, 9515.57421875, -6814.62646484375, 16.55568695068359375, 4.415682792663574218, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745); -- Masked Orphan Matron (Area: Falconwing Square - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 36050 AND 36108;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 38357 AND 38367;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 38794 AND 38803;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 39604 AND 39608;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78308 AND 78318;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78404 AND 78408;
DELETE FROM `gameobject` WHERE `guid` IN (36382,36383,36384,36814,36815,37236,37237,37238,37239,37585,37699,39876,43050,43051,66921);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 36050 AND 36108;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 38357 AND 38367;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 38794 AND 38803;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 39604 AND 39608;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78308 AND 78318;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78404 AND 78408;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (36382,36383,36384,36814,36815,37236,37237,37238,37239,37585,37699,39876,43050,43051,66921);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+115;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 530, 3430, 3665, '0', 0, 0, 9542.095703125, -6797.44384765625, 16.47561454772949218, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+1, 180405, 530, 3430, 3665, '0', 0, 0, 9477.763671875, -6788.11865234375, 16.49356460571289062, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+2, 180405, 530, 3430, 3665, '0', 0, 0, 9485.40625, -6834.0693359375, 17.10750770568847656, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+3, 180405, 530, 3430, 3665, '0', 0, 0, 9525.94140625, -6873.06689453125, 18.7498016357421875, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+4, 180405, 530, 3430, 3665, '0', 0, 0, 9494.7939453125, -6891.3701171875, 29.18750381469726562, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+5, 180406, 530, 3430, 3665, '0', 0, 0, 9543.6982421875, -6778.75439453125, 15.11356353759765625, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+6, 180406, 530, 3430, 3665, '0', 0, 0, 9482.650390625, -6771.931640625, 16.49356460571289062, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+7, 180406, 530, 3430, 3665, '0', 0, 0, 9516.724609375, -6852.7158203125, 19.00880241394042968, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+8, 180407, 530, 3430, 3665, '0', 0, 0, 9530.5986328125, -6768.01025390625, 15.36301898956298828, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+9, 180407, 530, 3430, 3665, '0', 0, 0, 9494.3984375, -6842.97900390625, 17.07756805419921875, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+10, 180407, 530, 3430, 3665, '0', 0, 0, 9547.5107421875, -6806.57275390625, 16.40133857727050781, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+11, 180407, 530, 3430, 3665, '0', 0, 0, 9535.09375, -6852.92724609375, 19.01387977600097656, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+12, 180411, 530, 3430, 3665, '0', 0, 0, 9525.7060546875, -6869.39208984375, 25.61795234680175781, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+13, 180415, 530, 3430, 3665, '0', 0, 0, 9514.84765625, -6799.79150390625, 17.92718887329101562, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+14, 180415, 530, 3430, 3665, '0', 0, 0, 9520.564453125, -6799.73291015625, 17.92718887329101562, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+15, 180415, 530, 3430, 3665, '0', 0, 0, 9512.4052734375, -6803.29150390625, 17.92718887329101562, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+16, 180415, 530, 3430, 3665, '0', 0, 0, 9519.29296875, -6799.37841796875, 17.92718887329101562, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+17, 180415, 530, 3430, 3665, '0', 0, 0, 9512.7890625, -6801.93115234375, 17.92718887329101562, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+18, 180415, 530, 3430, 3665, '0', 0, 0, 9521.6865234375, -6800.74951171875, 17.92718887329101562, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+19, 180415, 530, 3430, 3665, '0', 0, 0, 9513.8349609375, -6800.80908203125, 17.92718887329101562, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+20, 180415, 530, 3430, 3665, '0', 0, 0, 9516.0517578125, -6799.4052734375, 17.92718887329101562, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+21, 180415, 530, 3430, 3665, '0', 0, 0, 9506.6533203125, -6769.60400390625, 18.15343666076660156, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+22, 180415, 530, 3430, 3665, '0', 0, 0, 9511.7236328125, -6770.71875, 17.96957015991210937, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+23, 180415, 530, 3430, 3665, '0', 0, 0, 9496.392578125, -6767.71875, 18.11989402770996093, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+24, 180415, 530, 3430, 3665, '0', 0, 0, 9521.3740234375, -6770.25, 18.0019989013671875, 5.288348197937011718, 0, 0, -0.4771585464477539, 0.878817260265350341, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+25, 180415, 530, 3430, 3665, '0', 0, 0, 9516.5908203125, -6772.1162109375, 18.10790443420410156, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+26, 180415, 530, 3430, 3665, '0', 0, 0, 9522.6875, -6801.75927734375, 17.92718887329101562, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+27, 180415, 530, 3430, 3665, '0', 0, 0, 9530.5517578125, -6765.90478515625, 16.724609375, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+28, 180415, 530, 3430, 3665, '0', 0, 0, 9503.0126953125, -6842.32177734375, 18.1165771484375, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+29, 180415, 530, 3430, 3665, '0', 0, 0, 9485.154296875, -6819.3994140625, 18.159088134765625, 0.087265998125076293, 0, 0, 0.043619155883789062, 0.999048233032226562, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+30, 180415, 530, 3430, 3665, '0', 0, 0, 9541.732421875, -6841.69775390625, 18.11527442932128906, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+31, 180415, 530, 3430, 3665, '0', 0, 0, 9475.9580078125, -6770.57275390625, 18.20501518249511718, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+32, 180415, 530, 3430, 3665, '0', 0, 0, 9544.978515625, -6778.125, 16.53426551818847656, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+33, 180415, 530, 3430, 3665, '0', 0, 0, 9552.5478515625, -6816.048828125, 18.06805038452148437, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+34, 180415, 530, 3430, 3665, '0', 0, 0, 9481.7255859375, -6815.61474609375, 18.06168556213378906, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+35, 180415, 530, 3430, 3665, '0', 0, 0, 9516.2392578125, -6810.06787109375, 17.92718887329101562, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+36, 180415, 530, 3430, 3665, '0', 0, 0, 9556.2314453125, -6830.97216796875, 18.19346809387207031, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+37, 180415, 530, 3430, 3665, '0', 0, 0, 9521.7451171875, -6808.63525390625, 17.92718887329101562, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+38, 180415, 530, 3430, 3665, '0', 0, 0, 9543.4814453125, -6796.77587890625, 18.11649894714355468, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+39, 180415, 530, 3430, 3665, '0', 0, 0, 9554.0302734375, -6821.0380859375, 18.07317924499511718, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+40, 180415, 530, 3430, 3665, '0', 0, 0, 9512.8720703125, -6807.66259765625, 17.92718887329101562, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+41, 180415, 530, 3430, 3665, '0', 0, 0, 9513.923828125, -6808.72607421875, 17.92718887329101562, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+42, 180415, 530, 3430, 3665, '0', 0, 0, 9465.9150390625, -6788.8193359375, 18.13464736938476562, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+43, 180415, 530, 3430, 3665, '0', 0, 0, 9491.3984375, -6766.66650390625, 18.03796958923339843, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+44, 180415, 530, 3430, 3665, '0', 0, 0, 9550.6435546875, -6811.33349609375, 18.10545158386230468, 2.024578809738159179, 0, 0, 0.848047256469726562, 0.529920578002929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+45, 180415, 530, 3430, 3665, '0', 0, 0, 9512.4580078125, -6806.3525390625, 17.92718887329101562, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+46, 180415, 530, 3430, 3665, '0', 0, 0, 9512.7158203125, -6844.9375, 18.14415168762207031, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+47, 180415, 530, 3430, 3665, '0', 0, 0, 9470.7060546875, -6770.6005859375, 18.32486343383789062, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+48, 180415, 530, 3430, 3665, '0', 0, 0, 9555.119140625, -6826.04150390625, 18.02724266052246093, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+49, 180415, 530, 3430, 3665, '0', 0, 0, 9523.08203125, -6803.03466796875, 17.92718887329101562, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+50, 180415, 530, 3430, 3665, '0', 0, 0, 9548.744140625, -6806.56103515625, 18.10751533508300781, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+51, 180415, 530, 3430, 3665, '0', 0, 0, 9478.7724609375, -6793.34716796875, 18.11178779602050781, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+52, 180415, 530, 3430, 3665, '0', 0, 0, 9481.12109375, -6770.33447265625, 18.05984115600585937, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+53, 180415, 530, 3430, 3665, '0', 0, 0, 9484.0771484375, -6769.7119140625, 18.04311752319335937, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+54, 180415, 530, 3430, 3665, '0', 0, 0, 9520.7490234375, -6809.64306640625, 17.92718887329101562, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+55, 180415, 530, 3430, 3665, '0', 0, 0, 9471.099609375, -6788.78125, 18.13372611999511718, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+56, 180415, 530, 3430, 3665, '0', 0, 0, 9543.888671875, -6783.125, 17.37310409545898437, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+57, 180415, 530, 3430, 3665, '0', 0, 0, 9485.92578125, -6829.3369140625, 18.15577125549316406, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+58, 180415, 530, 3430, 3665, '0', 0, 0, 9488.7470703125, -6767.53662109375, 18.04392814636230468, 2.268925428390502929, 0, 0, 0.906307220458984375, 0.422619491815567016, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+59, 180415, 530, 3430, 3665, '0', 0, 0, 9523.1376953125, -6806.27490234375, 17.92718887329101562, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+60, 180415, 530, 3430, 3665, '0', 0, 0, 9515.6279296875, -6849.15283203125, 18.17986488342285156, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+61, 180415, 530, 3430, 3665, '0', 0, 0, 9526.126953125, -6768.265625, 17.50362586975097656, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+62, 180415, 530, 3430, 3665, '0', 0, 0, 9514.9931640625, -6809.7314453125, 17.92718887329101562, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+63, 180415, 530, 3430, 3665, '0', 0, 0, 9465.62890625, -6770.55908203125, 18.20173454284667968, 3.281238555908203125, 0, 0, -0.99756336212158203, 0.069766148924827575, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+64, 180415, 530, 3430, 3665, '0', 0, 0, 9476.3525390625, -6788.94091796875, 18.10409355163574218, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+65, 180415, 530, 3430, 3665, '0', 0, 0, 9540.375, -6792.71875, 18.12548255920410156, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+66, 180415, 530, 3430, 3665, '0', 0, 0, 9546.3408203125, -6839.501953125, 18.18597412109375, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+67, 180415, 530, 3430, 3665, '0', 0, 0, 9486.8251953125, -6824.27099609375, 18.10711097717285156, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+68, 180415, 530, 3430, 3665, '0', 0, 0, 9508.0927734375, -6842.5537109375, 18.16142463684082031, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+69, 180415, 530, 3430, 3665, '0', 0, 0, 9519.501953125, -6810.0244140625, 17.92718887329101562, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+70, 180415, 530, 3430, 3665, '0', 0, 0, 9522.787109375, -6807.51806640625, 17.92718887329101562, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+71, 180415, 530, 3430, 3665, '0', 0, 0, 9541.7470703125, -6787.82666015625, 17.90674400329589843, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+72, 180415, 530, 3430, 3665, '0', 0, 0, 9466.5302734375, -6849.29443359375, 18.35664558410644531, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+73, 180415, 530, 3430, 3665, '0', 0, 0, 9536.44921875, -6850.259765625, 18.15285682678222656, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+74, 180415, 530, 3430, 3665, '0', 0, 0, 9538.138671875, -6845.44091796875, 18.20700263977050781, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+75, 180415, 530, 3430, 3665, '0', 0, 0, 9466.5146484375, -6849.4609375, 18.48859024047851562, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+76, 180415, 530, 3430, 3665, '0', 0, 0, 9530.236328125, -6865.38037109375, 20.15276527404785156, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+77, 180415, 530, 3430, 3665, '0', 0, 0, 9530.2783203125, -6865.52685546875, 20.03467941284179687, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+78, 180415, 530, 3430, 3665, '0', 0, 0, 9530.0556640625, -6882.47314453125, 19.6388702392578125, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 45745), -- CandleBlack01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+79, 180426, 530, 3430, 3665, '0', 0, 0, 9515.7841796875, -6795.328125, 17.9299774169921875, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+80, 180426, 530, 3430, 3665, '0', 0, 0, 9509.4814453125, -6800.1181640625, 28.54047584533691406, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+81, 180426, 530, 3430, 3665, '0', 0, 0, 9512.6328125, -6796.80908203125, 21.92292976379394531, 1.378809213638305664, 0, 0, 0.636077880859375, 0.771624863147735595, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+82, 180426, 530, 3430, 3665, '0', 0, 0, 9508.240234375, -6804.861328125, 17.78327369689941406, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+83, 180426, 530, 3430, 3665, '0', 0, 0, 9521.302734375, -6795.298828125, 22.86036109924316406, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+84, 180426, 530, 3430, 3665, '0', 0, 0, 9513.0751953125, -6813.01025390625, 17.4391937255859375, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+85, 180426, 530, 3430, 3665, '0', 0, 0, 9526.1318359375, -6800.05908203125, 23.5549774169921875, 4.869470596313476562, 0, 0, -0.64944744110107421, 0.760406434535980224, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+86, 180426, 530, 3430, 3665, '0', 0, 0, 9522.5224609375, -6812.955078125, 17.84175491333007812, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+87, 180426, 530, 3430, 3665, '0', 0, 0, 9517.3017578125, -6814.24658203125, 22.23591041564941406, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+88, 180426, 530, 3430, 3665, '0', 0, 0, 9527.392578125, -6804.6474609375, 17.46470069885253906, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+89, 180426, 530, 3430, 3665, '0', 0, 0, 9509.4775390625, -6809.375, 30.91398429870605468, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+90, 180426, 530, 3430, 3665, '0', 0, 0, 9525.9189453125, -6809.330078125, 20.52720069885253906, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- Bat01 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+91, 180427, 530, 3430, 3665, '0', 0, 0, 9518.3701171875, -6795.10400390625, 20.38127517700195312, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+92, 180427, 530, 3430, 3665, '0', 0, 0, 9524.205078125, -6797.63720703125, 20.21470451354980468, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+93, 180427, 530, 3430, 3665, '0', 0, 0, 9508.673828125, -6802.27783203125, 19.11672019958496093, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+94, 180427, 530, 3430, 3665, '0', 0, 0, 9526.9912109375, -6802.361328125, 17.88136863708496093, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+95, 180427, 530, 3430, 3665, '0', 0, 0, 9508.3271484375, -6807.12353515625, 23.22756195068359375, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+96, 180427, 530, 3430, 3665, '0', 0, 0, 9511.15625, -6811.8037109375, 17.31927490234375, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+97, 180427, 530, 3430, 3665, '0', 0, 0, 9524.3779296875, -6811.376953125, 27.16613006591796875, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+98, 180427, 530, 3430, 3665, '0', 0, 0, 9514.7626953125, -6813.6494140625, 20.67620277404785156, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+99, 180427, 530, 3430, 3665, '0', 0, 0, 9520.181640625, -6813.85791015625, 19.39680099487304687, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+100, 180427, 530, 3430, 3665, '0', 0, 0, 9526.884765625, -6807.205078125, 36.64525604248046875, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+101, 180427, 530, 3430, 3665, '0', 0, 0, 9511.0341796875, -6798.35791015625, 35.7977447509765625, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 45745), -- Bat02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+102, 180472, 530, 3430, 3665, '0', 0, 0, 9476.1806640625, -6851.85791015625, 33.72943878173828125, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+103, 180472, 530, 3430, 3665, '0', 0, 0, 9481.2666015625, -6856.990234375, 23.58030509948730468, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+104, 180472, 530, 3430, 3665, '0', 0, 0, 9469.3359375, -6858.72216796875, 33.71020889282226562, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+105, 180472, 530, 3430, 3665, '0', 0, 0, 9474.4755859375, -6863.29541015625, 23.573211669921875, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+106, 180472, 530, 3430, 3665, '0', 0, 0, 9484.8974609375, -6882.01904296875, 33.8115692138671875, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Falconwing Square - Difficulty: 0)
(@OGUID+107, 180523, 530, 3430, 3665, '0', 0, 0, 9476.9990234375, -6850.93798828125, 17.9411468505859375, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 120, 255, 1, 45745), -- Apple Bob (Area: Falconwing Square - Difficulty: 0)
(@OGUID+108, 186234, 530, 3430, 3665, '0', 0, 0, 9510.8359375, -6811.96533203125, 16.48661231994628906, 0.418878614902496337, 0, 0, 0.207911491394042968, 0.978147625923156738, 120, 255, 1, 45745), -- Water Barrel (Area: Falconwing Square - Difficulty: 0)
(@OGUID+109, 186234, 530, 3430, 3665, '0', 0, 0, 9235.0615234375, -6770.26318359375, 24.79453277587890625, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 45745), -- Water Barrel (Area: Falconwing Square - Difficulty: 0)
(@OGUID+110, 186720, 530, 3430, 0, '0', 0, 0, 9229.306640625, -6780.560546875, 27.05394935607910156, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 45745), -- Fire Effigy (Area: 0 - Difficulty: 0)
(@OGUID+111, 186720, 530, 3430, 0, '0', 0, 0, 9235.0498046875, -6783.404296875, 25.44256019592285156, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 45745), -- Fire Effigy (Area: 0 - Difficulty: 0)
(@OGUID+112, 186720, 530, 3430, 0, '0', 0, 0, 9225.4619140625, -6765.23388671875, 26.05803871154785156, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 45745), -- Fire Effigy (Area: 0 - Difficulty: 0)
(@OGUID+113, 186720, 530, 3430, 0, '0', 0, 0, 9224.697265625, -6771.0048828125, 27.25944709777832031, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 45745), -- Fire Effigy (Area: 0 - Difficulty: 0)
(@OGUID+114, 186720, 530, 3430, 0, '0', 0, 0, 9224.1533203125, -6777.71533203125, 28.38528251647949218, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 45745), -- Fire Effigy (Area: 0 - Difficulty: 0)
(@OGUID+115, 190067, 530, 3430, 3665, '0', 0, 0, 9469.6787109375, -6861.2607421875, 17.43587303161621093, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 45745); -- Candy Bucket (Area: Falconwing Square - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+46;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0), 
(12, @CGUID+1), 
(12, @CGUID+2), 
(12, @CGUID+3), 
(12, @CGUID+4), 
(12, @CGUID+5), 
(12, @CGUID+6), 
(12, @CGUID+7), 
(12, @CGUID+8), 
(12, @CGUID+9), 
(12, @CGUID+10),
(12, @CGUID+11),
(12, @CGUID+12),
(12, @CGUID+13),
(12, @CGUID+14),
(12, @CGUID+15),
(12, @CGUID+16),
(12, @CGUID+17),
(12, @CGUID+18),
(12, @CGUID+19),
(12, @CGUID+20),
(12, @CGUID+21),
(12, @CGUID+22),
(12, @CGUID+23),
(12, @CGUID+24),
(12, @CGUID+25),
(12, @CGUID+26),
(12, @CGUID+27),
(12, @CGUID+28),
(12, @CGUID+29),
(12, @CGUID+30),
(12, @CGUID+31),
(12, @CGUID+32),
(12, @CGUID+33),
(12, @CGUID+34),
(12, @CGUID+35),
(12, @CGUID+36),
(12, @CGUID+37),
(12, @CGUID+38),
(12, @CGUID+39),
(12, @CGUID+40),
(12, @CGUID+41),
(12, @CGUID+42),
(12, @CGUID+43),
(12, @CGUID+44),
(12, @CGUID+45),
(12, @CGUID+46);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+115;
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
(12, @OGUID+40),
(12, @OGUID+41),
(12, @OGUID+42),
(12, @OGUID+43),
(12, @OGUID+44),
(12, @OGUID+45),
(12, @OGUID+46),
(12, @OGUID+47),
(12, @OGUID+48),
(12, @OGUID+49),
(12, @OGUID+50),
(12, @OGUID+51),
(12, @OGUID+52),
(12, @OGUID+53),
(12, @OGUID+54),
(12, @OGUID+55),
(12, @OGUID+56),
(12, @OGUID+57),
(12, @OGUID+58),
(12, @OGUID+59),
(12, @OGUID+60),
(12, @OGUID+61),
(12, @OGUID+62),
(12, @OGUID+63),
(12, @OGUID+64),
(12, @OGUID+65),
(12, @OGUID+66),
(12, @OGUID+67),
(12, @OGUID+68),
(12, @OGUID+69),
(12, @OGUID+70),
(12, @OGUID+71),
(12, @OGUID+72),
(12, @OGUID+73),
(12, @OGUID+74),
(12, @OGUID+75),
(12, @OGUID+76),
(12, @OGUID+77),
(12, @OGUID+78),
(12, @OGUID+79),
(12, @OGUID+80),
(12, @OGUID+81),
(12, @OGUID+82),
(12, @OGUID+83),
(12, @OGUID+84),
(12, @OGUID+85),
(12, @OGUID+86),
(12, @OGUID+87),
(12, @OGUID+88),
(12, @OGUID+89),
(12, @OGUID+90),
(12, @OGUID+91),
(12, @OGUID+92),
(12, @OGUID+93),
(12, @OGUID+94),
(12, @OGUID+95),
(12, @OGUID+96),
(12, @OGUID+97),
(12, @OGUID+98),
(12, @OGUID+99),
(12, @OGUID+100),
(12, @OGUID+101),
(12, @OGUID+102),
(12, @OGUID+103),
(12, @OGUID+104),
(12, @OGUID+105),
(12, @OGUID+106),
(12, @OGUID+107),
(12, @OGUID+108),
(12, @OGUID+109),
(12, @OGUID+110),
(12, @OGUID+111),
(12, @OGUID+112),
(12, @OGUID+113),
(12, @OGUID+114),
(12, @OGUID+115);
