SET @CGUID := 6005168;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 105602, 1220, 7502, 7596, '0', 6256, 0, 0, 0, -785.13018798828125, 4562.17529296875, 727.25616455078125, 5.064152240753173828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Vindicator Boros (Area: Magus Commerce Exchange - Difficulty: 0) CreateObject1
(@CGUID+1, 105586, 1220, 7502, 7596, '0', 6257, 0, 0, 0, -784.1805419921875, 4576.83935546875, 728.87640380859375, 3.789275646209716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Defender Barrem (Area: Magus Commerce Exchange - Difficulty: 0) CreateObject1 (Auras: 209190 - Felcursed Wounds)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 10389, 0, 0, 0, '209190'); -- Defender Barrem - 209190 - Felcursed Wounds

-- Template
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=105602; -- Vindicator Boros

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=105602 AND `DifficultyID`=0); -- 105602 (Vindicator Boros) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x30000100, `VerifiedBuild`=61609 WHERE (`Entry`=105586 AND `DifficultyID`=0); -- 105586 (Defender Barrem) - Sessile, CanSwim, Floating

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 105602;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(105602, 0, 0, 'A priest! Thank the Light!', 12, 0, 100, 0, 0, 62431, 108556, 0, 'Vindicator Boros to Player');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=105602 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(105602, 1, 105940, 0, 0, 126759, 0, 0, 0, 0, 0, 61609); -- Vindicator Boros

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (6256,6257);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6256, 'Cosmetic - See Vindicator Boros in Dalaran'),
(6257, 'Cosmetic - See Defender Barrem infected with Felcursed Wounds');

DELETE FROM `phase_area` WHERE `PhaseId` IN (6256,6257);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7502, 6256, 'See Vindicator Boros in Dalaran'),
(7502, 6257, 'See Defender Barrem infected with Felcursed Wounds');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (6256,6257) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 6256, 0, 0, 0, 47, 0, 41957, 2|8|64, 0, 0, 'Apply Phase 6256 if Quest 41957 is in progress | complete | rewarded'),
(26, 6257, 0, 0, 0, 47, 0, 41957, 2|8|64, 0, 0, 'Apply Phase 6257 if Quest 41957 is in progress | complete | rewarded');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=41957;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(41957, 0, 0, 0, 0, 0, 0, 0, 0, 61609); -- The Vindicator's Plea

DELETE FROM `quest_offer_reward` WHERE `ID`=41957;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(41957, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you for arriving in such haste, $gBrother:Sister;.', 61609); -- The Vindicator's Plea

DELETE FROM `creature_queststarter` WHERE (`id`=101314 AND `quest`=41957);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(101314, 41957, 61609); -- The Vindicator's Plea offered by Alonsus Faol

DELETE FROM `quest_template_addon` WHERE `ID` = 41957;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(41957, 0, 0, 0, 40706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Vindicator's Plea

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=627 AND `QuestLineId`=243);
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(627, 243, 61609);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (41957));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 41957, 0, 0, 47, 0, 40708, 64, 0, '', 0, 'Player has Holy Chosen (40708) in state rewarded');
