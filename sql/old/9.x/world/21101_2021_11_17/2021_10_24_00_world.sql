--
SET @CGUID := 1050134;

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `VerifiedBuild`=40443 WHERE `entry`=164742; -- Prince Renathal

DELETE FROM `creature_template_scaling` WHERE(`DifficultyID`=0 AND `Entry` IN (164742, 172367));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(164742, 0, 0, 0, 837, 40443);

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 164742, 2222, 10413, 10986, '0', 14983, 0, 0, 0, -1940.4791259765625, 7754.97509765625, 4228.1572265625, 5.323254108428955078, 120, 0, 0, 117910, 2434, 0, 0, 0, 0, 40443); -- Prince Renathal (Area: Sinfall - Difficulty: 0)

DELETE FROM `creature_queststarter` WHERE `id`=164742 AND `quest`=59315;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(164742, 59315); -- The Court of Harvesters

DELETE FROM `creature_questender` WHERE `id`=164742 AND `quest`=59314;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(164742, 59314); -- Sinfall

DELETE FROM `quest_template_addon` WHERE `ID` IN(63215, 59314, 59315);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`) VALUES
(63215, 0, 59314),
(59314, 63215, 59315),
(59315, 59314, 59321);

DELETE FROM `phase_area` WHERE `AreaId`=12917 AND `PhaseId`=14983;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(12917, 14983, 'Cosmetic: Venthyr Covenant Intro - Prince Renathal upstairs');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND `SourceGroup`=14983 AND `SourceEntry`=12917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 14983, 12917, 0, 0, 47, 0, 59314, 0x2|0x8, 0, 0, 'Allow phase 14983 if quest state of of Sinfall (59314) is incomplete or completed'),
(26, 14983, 12917, 0, 1, 8, 0, 59314, 0, 0, 0, 'Allow phase 14983 if player has quest Sinfall (59314) rewarded'),
(26, 14983, 12917, 0, 1, 14, 0, 59315, 0, 0, 0, 'Allow phase 14983 if player doesn\'t have quest The Court of Harvesters (59315) active');

-- 
UPDATE `quest_template` SET `VerifiedBuild`=40443 WHERE `ID`=59314; -- -Unknown-
UPDATE `quest_template` SET `VerifiedBuild`=40443 WHERE `ID`=59315; -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59315 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59314 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (59315 /*-Unknown-*/, 59314 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59315, 1, 1, 0, 0, 0, 0, 0, 0, 40443), -- -Unknown-
(59314, 1, 1, 0, 0, 0, 0, 0, 0, 40443); -- -Unknown-

DELETE FROM `quest_offer_reward` WHERE `ID` IN (59315 /*-Unknown-*/, 59314 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(59315, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome to our humble court, $p.', 40443), -- -Unknown-
(59314, 1, 0, 0, 0, 0, 0, 0, 0, 'I never doubted you for a moment, $p.', 40443); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=59315;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(59315, 0, 1, 0, 0, 'You will be welcomed by the court, I have no doubt, but first, you must swear an oath before the Harvesters.', 40443); -- -Unknown-
