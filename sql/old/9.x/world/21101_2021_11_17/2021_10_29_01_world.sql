--
SET @CGUID := 1050139;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 164818, 2222, 10413, 12917, '0', 14986, 0, 0, 0, -1899.52783203125, 7645.5302734375, 4193.80859375, 1.381728410720825195, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40443), -- The Curator (Area: Sinfall - Difficulty: 0)
(@CGUID+1, 164796, 2222, 10413, 12917, '0', 14986, 0, 0, 0, -1891.4617919921875, 7650.27783203125, 4193.80859375, 2.007128715515136718, 120, 0, 0, 117910, 2434, 0, 2, 0, 0, 40443), -- Prince Renathal (Area: Sinfall - Difficulty: 0)
(@CGUID+2, 164817, 2222, 10413, 12917, '0', 14986, 0, 0, 0, -1881.923583984375, 7652.99853515625, 4193.89208984375, 2.27655792236328125, 120, 0, 0, 188660, 5751, 0, 0, 0, 0, 40443), -- The Accuser (Area: Sinfall - Difficulty: 0)
(@CGUID+3, 164817, 2222, 10413, 12917, '0', 14986, 0, 0, 0, -1870, 7700.509765625, 4192.169921875, 1.361356854438781738, 120, 0, 0, 188660, 5751, 0, 0, 0, 0, 40443); -- The Accuser (Area: Sinfall - Difficulty: 0)

DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN(164818, 164796, 164817);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(164818, 0, 0, 0, 837, 40443),
(164796, 0, 0, 0, 837, 40443),
(164817, 0, 0, 0, 837, 40443);

UPDATE `creature_template` SET `VerifiedBuild`=40443 WHERE `entry`=164818; -- The Curator
UPDATE `creature_template_model` SET `VerifiedBuild`=40443 WHERE (`CreatureID`=164818 AND `Idx`=0); -- The Curator
UPDATE `creature_model_info` SET `VerifiedBuild`=40443 WHERE `DisplayID`=93111;

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `VerifiedBuild`=40443 WHERE `entry`=164796; -- Prince Renathal
UPDATE `creature_template_model` SET `VerifiedBuild`=40443 WHERE (`CreatureID`=164796 AND `Idx`=0); -- Prince Renathal
UPDATE `creature_model_info` SET `VerifiedBuild`=40443 WHERE `DisplayID`=94910;

UPDATE `creature_template` SET `VerifiedBuild`=40443 WHERE `entry`=164817; -- The Accuser
UPDATE `creature_template_model` SET `VerifiedBuild`=40443 WHERE (`CreatureID`=164817 AND `Idx`=0); -- The Accuser
UPDATE `creature_model_info` SET `VerifiedBuild`=40443 WHERE `DisplayID`=93103;

DELETE FROM `creature_queststarter` WHERE `id`=164796 AND `quest`=59321;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(164796, 59321); -- Sacred Covenant

DELETE FROM `creature_questender` WHERE `id`=164796 AND `quest`=59315;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(164796, 59315); -- The Court of Harvesters

DELETE FROM `quest_template_addon` WHERE `ID` IN(59321);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`) VALUES
(59321, 59315, 59323);

UPDATE `quest_template` SET `VerifiedBuild`=40443 WHERE `ID`=59321; -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=40443 WHERE (`QuestID`=59321 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (59321 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59321, 1, 0, 0, 0, 0, 0, 0, 0, 40443); -- -Unknown-

DELETE FROM `quest_offer_reward` WHERE `ID` IN (59321 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(59321, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome, I must admit my eagerness to partake in this monumental occasion.', 40443); -- -Unknown-

DELETE FROM `phase_area` WHERE `AreaId`=12917 AND `PhaseId`=14986;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(12917, 14986, 'Cosmetic: Venthyr Covenant Intro - Court of Harvesters');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND `SourceGroup`=14986 AND `SourceEntry`=12917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 14986, 12917, 0, 0, 47, 0, 59315, 0x2|0x8, 0, 0, 'Allow phase 14986 if quest state of Court of Harvesters (59315) is incomplete, completed'),
(26, 14986, 12917, 0, 1, 8, 0, 59315, 0, 0, 0, 'Allow phase 14986 if quest state of Court of Harvesters (59315) is rewarded'),
(26, 14986, 12917, 0, 1, 47, 0, 59321, 0x1|0x8, 0, 0, 'Allow phase 14986 if quest state of Sacred Covenant (59321) is not taken, incomplete');
