--
SET @CGUID := 1050135;

DELETE FROM `quest_offer_reward` WHERE `ID` IN (50313 /*-Unknown-*/, 49772 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50313, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome to this beautiful city, $n. I am sure you will feel as welcome by the other members of the Alliance as I do.\n\nI have met a number of the city guards. Good people, though there are a few things they could learn from us.', 40593), -- -Unknown-
(49772, 1, 0, 0, 0, 0, 0, 0, 0, 'What have we here? One of the famed Lightforged draenei! Welcome, welcome.\n\nThank you for your service against the Legion, $n. Truly an inspiration!', 40593); -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=50313 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50313 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50313 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(50313, 0, 2, 32, 0, 0, 0, 84, 0, 0, 0, 0, 0, 1456603, 0, 40593), -- -Unknown-
(50313, 0, 1, 0, 312152, 65238, 0, 84, 0, 2, 0, 0, 0, 0, 0, 40593), -- -Unknown-
(50313, 0, 0, -1, 0, 0, 0, 84, 0, 0, 0, 0, 0, 1430411, 0, 40593); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49772 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49772 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

DELETE FROM `quest_poi_points` WHERE (`QuestID`=50313 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50313 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50313 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(50313, 2, 0, -8173, 801, 74, 40593), -- -Unknown-
(50313, 1, 0, -8348, 634, 0, 40593), -- -Unknown-
(50313, 0, 0, -8340, 637, 95, 40593); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49772 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49772 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID`=50313;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(50313, 1, 1, 0, 0, 0, 0, 0, 0, 40593); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=50313;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(50313, 0, 0, 0, 0, 'I can feel the Light in this place.', 40593); -- -Unknown-

UPDATE `quest_template` SET `RewardMoney`=200, `VerifiedBuild`=40593 WHERE `ID`=50313; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=90, `VerifiedBuild`=40593 WHERE `ID`=49772; -- -Unknown-

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2916, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `VerifiedBuild`=40593 WHERE `entry`=131334; -- Vindicator Minkey
UPDATE `creature_template_model` SET `VerifiedBuild`=40593 WHERE (`CreatureID`=131334 AND `Idx`=0); -- Vindicator Minkey

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 131334, 0, 1519, 5316, '0', 10036, 0, 0, 0, -8340.1611328125, 637.16839599609375, 95.515106201171875, 3.320595502853393554, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40593); -- Vindicator Minkey (Area: Olivia's Pond - Difficulty: 0)

DELETE FROM `creature_questender` WHERE `id`=131334 AND `quest`=50313;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(131334, 50313); -- Stranger in a Strange Land

DELETE FROM `creature_text` WHERE `CreatureID`=131334;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(131334, 0, 0, 'Light be with you, $n. I plan to  seek the Legion upon Azeroth to continue our eternal battle.', 12, 0, 100, 1, 0, 0, 143327, 5, 'Vindicator Minkey to Player');

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=10036;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 10036, 'Cosmetic: Lightforged Draenei Intro - Vindicator Minkey, Quest: Stranger in a Strange Land (50313)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup`=10036 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10036, 1519, 0, 0, 47, 0, 50313, 0x2|0x8, 0, 0, 'Allow phase 10036 if quest status of Stranger in a Strange Land (50313) is incomplete or complete');
