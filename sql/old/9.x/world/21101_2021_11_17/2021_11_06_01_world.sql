--
SET @CGUID := 850144;

UPDATE `quest_template` SET `RewardMoney`=200, `VerifiedBuild`=40725 WHERE `ID`=53500; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=90, `VerifiedBuild`=40725 WHERE `ID`=51486; -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=53500 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=53500 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=53500 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=51486 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40725 WHERE (`QuestID`=51486 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=53500 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=53500 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=53500 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=51486 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40725 WHERE (`QuestID`=51486 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_offer_reward` WHERE `ID` IN (53500 /*Stranger in a Strange Land*/, 51486 /*Fer the Alliance*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(53500, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome tae Stormwind. Too much sun out here if ye ask me.\n\nI\'m off tae seek adventure! An\' somewhere a bit darker.', 40725), -- Stranger in a Strange Land
(51486, 5, 0, 0, 0, 0, 0, 0, 0, 'Ah, there you are, $n! We\'ve been inspecting--err--expecting you!', 40725); -- Fer the Alliance

DELETE FROM `quest_details` WHERE `ID` IN (53500 /*Stranger in a Strange Land*/, 51486 /*Fer the Alliance*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(53500, 1, 5, 0, 0, 0, 5000, 0, 0, 40725), -- Stranger in a Strange Land
(51486, 1, 1, 0, 0, 0, 0, 0, 0, 40725); -- Fer the Alliance

DELETE FROM `quest_request_items` WHERE `ID`=53500;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(53500, 0, 0, 0, 0, 'Greetings.', 40725); -- Stranger in a Strange Land

UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VerifiedBuild`=40725 WHERE `entry`=143978; -- Mudrik Leger
UPDATE `creature_template_model` SET `VerifiedBuild`=40725 WHERE (`CreatureID`=143978 AND `Idx`=0); -- Mudrik Leger
UPDATE `creature_model_info` SET `VerifiedBuild`=40725 WHERE `DisplayID`=70959;

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry`=143978);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(143978, 0, 0, 0, 464, 40725);

DELETE FROM `creature_questender` WHERE `id`=143978 AND `quest`=53500;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(143978, 53500); -- Stranger in a Strange Land

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 143978, 0, 1519, 5316, '0', 11867, 0, 0, 0, -8340.1611328125, 637.16839599609375, 95.515106201171875, 3.320595502853393554, 120, 0, 0, 228950, 0, 0, 0, 0, 0, 40725); -- Mudrik Leger (Area: Olivia's Pond - Difficulty: 0)

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=11867;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 11867, 'Cosmetic: Dark Iron Dwarf Intro - Mudrik Leger, Quest: Stranger in a Strange Land (53500)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup`=11867 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 11867, 1519, 0, 0, 47, 0, 53500, 0x2|0x8, 0, 0, 'Allow phase 11867 if quest status of Stranger in a Strange Land (53500) is incomplete or complete');
