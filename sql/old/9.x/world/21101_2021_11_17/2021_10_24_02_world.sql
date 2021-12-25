--
SET @CGUID := 1050136;

DELETE FROM `quest_offer_reward` WHERE `ID` IN (50305 /*-Unknown-*/, 49788 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50305, 1, 2, 0, 0, 0, 5000, 0, 0, 'Welcome to Stormwind. Though it is no Silvermoon, the city does have its charms.\n\nIf you came here expecting a warm welcome, I cannot say I have received one myself. But most folk are polite enough.\n\nNo matter. I am off to seek adventure! And perhaps a stiff drink.', 40593), -- -Unknown-
(49788, 5, 0, 0, 0, 0, 0, 0, 0, 'Ah, there you are, $n! We\'ve been inspecting--err--expecting you!', 40593); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=50305 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=50305 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=50305 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49788 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49788 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=50305 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=50305 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=50305 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49788 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40593 WHERE (`QuestID`=49788 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (50305 /*-Unknown-*/, 49788 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(50305, 1, 5, 0, 0, 0, 5000, 0, 0, 40593), -- -Unknown-
(49788, 1, 1, 0, 0, 0, 0, 0, 0, 40593); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=50305;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(50305, 0, 0, 0, 0, 'So, how does Stormwind suit you?', 40593); -- -Unknown-

UPDATE `quest_template` SET `RewardMoney`=200, `VerifiedBuild`=40593 WHERE `ID`=50305; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=90, `VerifiedBuild`=40593 WHERE `ID`=49788; -- -Unknown-

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1732, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `VerifiedBuild`=40593 WHERE `entry`=131347; -- Keira Onyxraven
UPDATE `creature_template_model` SET `VerifiedBuild`=40593 WHERE (`CreatureID`=131347 AND `Idx`=0); -- Keira Onyxraven

DELETE FROM `creature_text` WHERE `CreatureID`=131347 AND `GroupID`=0 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(131347, 0, 0, 'I have only heard stories of Stormwind before now. I will explore its streets and the wonders it holds. May the shadows guide you, $n.', 12, 0, 100, 1, 0, 0, 143328, 'Keira Onyxraven to Player');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 131347, 0, 1519, 5316, '0', 10037, 0, 0, 0, -8340.1611328125, 637.16839599609375, 95.515106201171875, 3.320595502853393554, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40593); -- Keira Onyxraven (Area: Olivia's Pond - Difficulty: 0)

DELETE FROM `creature_questender` WHERE `id`=131347 AND `quest`=50305;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(131347, 50305); -- Stranger in a Strange Land

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=10037;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 10037, 'Cosmetic: Voidelf Intro - Keira Onyxraven, Quest: Stranger in a Strange Land (50305)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup`=10037 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10037, 1519, 0, 0, 47, 0, 50305, 0x2|0x8, 0, 0, 'Allow phase 10037 if quest status of Stranger in a Strange Land (50305) is incomplete or complete');
