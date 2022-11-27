SET @CGUID := 1051902;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 164907, 2175, 10424, 10530, '0', 15005, 0, 0, 0, 322.62152099609375, -2057.317626953125, 112.3770675659179687, 1.523632287979125976, 120, 0, 0, 97, 382, 0, 0, 0, 0, 46597); -- Ralia Dreamchaser (Area: Darkmaul Citadel - Difficulty: 0)

UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=164907; -- Ralia Dreamchaser

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 15005;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(15005, 'Cosmetic - See Ralia Dreamchaser at Ancient Druid Stone');

DELETE FROM `phase_area` WHERE `AreaId` = 10530 AND `PhaseId` = 15005;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10530, 15005, 'Cosmetic - See Ralia Dreamchaser for Druid classquest'); -- Darkmaul Citadel

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 15005 AND `SourceEntry` = 10530);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 15005, 10530, 0, 0, 47, 0, 59350, 2 | 8, 0, 0, 'Apply Phase 15005 if Quest 59350 is in progress | complete');

-- Adjust Phase 13831 with Classquest data
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 13831 AND `SourceEntry` = 10529) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 13831 AND `SourceEntry` = 10588) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 13831 AND `SourceEntry` = 10527);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 13831, 10529, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13831 if Quest 55639 is complete | rewarded'), -- Ogre Ruins
(26, 13831, 10529, 0, 0, 47, 0, 59350, 2 | 8, 0, 1, 'Apply Phase 15005 if Quest 59350 is in progress | complete'), -- Ogre Ruins
(26, 13831, 10588, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13831 if Quest 55639 is complete | rewarded'), -- Darkmaul Plains
(26, 13831, 10588, 0, 0, 47, 0, 59350, 2 | 8, 0, 1, 'Apply Phase 15005 if Quest 59350 is in progress | complete'), -- Darkmaul Plains
(26, 13831, 10527, 0, 0, 47, 0, 55639, 2 | 64, 0, 0, 'Apply Phase 13831 if Quest 55639 is complete | rewarded'), -- Hruns Barrows
(26, 13831, 10527, 0, 0, 47, 0, 59350, 2 | 8, 0, 1, 'Apply Phase 15005 if Quest 59350 is in progress | complete'); -- Hruns Barrows

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=59350;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59350, 1, 25, 1, 0, 0, 0, 0, 0, 46597); -- A Druid's Form

DELETE FROM `quest_request_items` WHERE `ID`=59350;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(59350, 0, 0, 0, 0, 'Come. The spirits of nature await us.', 46597); -- A Druid's Form

DELETE FROM `quest_offer_reward` WHERE `ID`=59350;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(59350, 273, 1, 0, 0, 0, 0, 0, 0, 'Good! I can sense the blessing of the spirits flowing through you.\n\nFocus, and you should find that you can take on a new form.', 46597); -- A Druid's Form

DELETE FROM `creature_queststarter` WHERE (`id`=156932 AND `quest`=59350);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156932, 59350, 46597); -- A Druid's Form offered Ralia Dreamchaser

DELETE FROM `creature_questender` WHERE (`id`=164907 AND `quest`=59350);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(164907, 59350, 46597); -- A Druid's Form ended by Ralia Dreamchaser

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`Entry`=164907 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(164907, 0, 0, 0, 741, 46597);
