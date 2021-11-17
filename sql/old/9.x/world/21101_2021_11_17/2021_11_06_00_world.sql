--
SET @CGUID := 850145;

DELETE FROM `quest_offer_reward` WHERE `ID` IN (58147 /*-Unknown-*/, 58146 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(58147, 5, 0, 0, 0, 0, 0, 0, 0, 'You will be an excellent representative of what it means to be a mechagnome.\n\nStay shiny out there, friend.', 40725), -- -Unknown-
(58146, 5, 0, 0, 0, 0, 0, 0, 0, 'Ah, there you are, $n! We\'ve been inspecting--err--expecting you!', 40725); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58147 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58147 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58147 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58146 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58146 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58146 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58147 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58147 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58147 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58146 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58146 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=58146 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (58147 /*-Unknown-*/, 58146 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(58147, 1, 1, 0, 0, 0, 5000, 0, 0, 40725), -- -Unknown-
(58146, 1, 1, 0, 0, 0, 0, 0, 0, 40725); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=58147;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(58147, 0, 0, 0, 0, 'So, how does Stormwind suit you?', 40725); -- -Unknown-

UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=90, `VerifiedBuild`=40725 WHERE `ID`=58147; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=90, `VerifiedBuild`=40725 WHERE `ID`=58146; -- -Unknown-

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3175, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `VerifiedBuild`=40725 WHERE `entry`=160600; -- Lulana
UPDATE `creature_template_model` SET `VerifiedBuild`=40725 WHERE (`CreatureID`=160600 AND `Idx`=0); -- Lulana

DELETE FROM `creature_model_info` WHERE `DisplayID`=94291;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(94291, 0.305999994277954101, 1.5, 0, 40725);

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry`=160600);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(160600, 0, 0, 0, 464, 40725);

DELETE FROM `creature_text` WHERE `CreatureID`=160600;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(160600, 0, 0, 'The world has become a much bigger place. I hope you enjoy discovering it, $n.', 12, 0, 100, 1, 0, 0, 184045, 'Lulana to Player');

DELETE FROM `creature_questender` WHERE `id`=160600 AND `quest`=58147;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(160600, 58147); -- Stranger in a Strange Land

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 160600, 0, 1519, 5316, '0', 14345, 0, 0, 0, -8340.1611328125, 637.16839599609375, 95.515106201171875, 3.320595502853393554, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40725); -- Lulana (Area: Olivia's Pond - Difficulty: 0)

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=14345;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 14345, 'Cosmetic: Mechagnome Intro - Lulana, Quest: Stranger in a Strange Land (58147)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup`=14345 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 14345, 1519, 0, 0, 47, 0, 58147, 0x2|0x8, 0, 0, 'Allow phase 11867 if quest status of Stranger in a Strange Land (58147) is incomplete or complete');

DELETE FROM `gossip_menu` WHERE (`MenuId`=24850 AND `TextId`=39155);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(24850, 39155, 40725); -- 160600 (Lulana)

DELETE FROM `npc_text` WHERE `ID`=39155;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(39155, 1, 1, 1, 0, 0, 0, 0, 0, 184037, 184038, 184039, 0, 0, 0, 0, 0, 40725); -- 39155
