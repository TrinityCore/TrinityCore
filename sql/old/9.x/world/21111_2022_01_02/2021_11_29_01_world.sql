-- 
SET @CGUID := 1050145;

-- Creature spawn Captain Garrick 156280
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 156280, 2261, 10424, 10639, '0', 14349, 0, 0, 0, -3.21382498741149902, -0.7211509346961975, 5.605516433715820312, 0.114633336663246154, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079), -- -Unknown- (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 156280, 2261, 10424, 10639, '0', 14350, 0, 0, 0, 37.83321762084960937, -1.40558588504791259, 12.40759944915771484, 3.31911778450012207, 7200, 0, 0, 124, 0, 0, 0, 0, 0, 41079); -- Captain Garrick (Area: -Unknown- - Difficulty: 0)

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 10639 AND `PhaseId` =14349;
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(10639, 14349, 'Cosmetic: NPE - Captain Garrick before Quest 56775 is rewarded');

-- Condition
DELETE FROM `conditions` WHERE `SourceEntry` = 10639 AND `SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 14349;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 14349, 10639, 0, 0, 8, 0, 56775, 0, 0, 1, 0, 0, '', 'Allow Phase 14349 if Quest 56775 IS NOT rewarded');

UPDATE `creature_template_scaling` SET `VerifiedBuild`=41079 WHERE (`Entry`=156280 AND `DifficultyID`=0);
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=16 WHERE `entry`=156280; -- -Unknown-

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` = 156280);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(156280, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0); -- -Unknown-

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 156280 AND `GroupID` IN (0, 1);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(156280, 0, 0, 'Private Cole will run you through the rest of the drills. I need to discuss this storm with the helmsman.', 12, 0, 100, 0, 0, 152734, 184106, 'Captain Garrick to Player'),
(156280, 1, 0, 'Everyone below decks! Now!', 12, 0, 100, 0, 0, 152735, 177674, 'Captain Garrick to Player');

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (58209 /*-Unknown-*/, 56775 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(58209, 66, 0, 0, 0, 0, 0, 0, 0, 'You\'re a skilled $c, recruit. I think you\'ll prove a welcome addition to the main rescue team.', 41079), -- -Unknown-
(56775, 669, 0, 0, 0, 0, 0, 0, 0, 'Good, looks like you\'ve kept up your $c training during our voyage.\n\nI\'m concerned about the sudden turn in weather. Spar with Private Cole while I speak with the ship\'s crew.\n\nCole\'s report will determine where we\'ll place you on our initial expedition team.', 41079); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (58208 /*-Unknown-*/, 58209 /*-Unknown-*/, 56775 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(58208, 1, 6, 0, 0, 0, 0, 0, 0, 41079), -- -Unknown-
(58209, 274, 1, 25, 0, 0, 0, 0, 0, 41079), -- -Unknown-
(56775, 669, 0, 0, 0, 0, 0, 0, 0, 41079); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=56775;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(56775, 0, 0, 0, 0, 'Don\'t be shy. Just walk up to the target dummies, select them, and use your main attack.', 41079); -- -Unknown-

DELETE FROM `creature_model_info` WHERE `DisplayID` = 92690;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(92690, 0.208000004291534423, 1.5, 0, 41079);

-- Conversation Stuff
DELETE FROM `conversation_actors` WHERE (`ConversationId`=12818 AND `Idx`=0);
INSERT INTO `conversation_actors`(`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES
(12818, 73270, @CGUID+0, 0, 0, 0, 41079);

DELETE FROM `conversation_line_template` WHERE `Id`=31445;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(31445, 0, 0, 0, 41079);

DELETE FROM `conversation_template` WHERE `Id`=12818;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(12818, 31445, 0, 41079);

-- SAI Conversation Script for Captain Garrick GUID: @CGUID+0
-- SET SAI in Template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` = 156280;
DELETE FROM `smart_scripts` WHERE `entryorguid` = -(@CGUID+0) AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+0), 0, 0, 0, 19, 0, 100, 0, 56775, 0, 0, 0, 0, '', 143, 12818, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captain Garrick - On Quest accept 56775 - Start Conversation 12818 - To Invoker');

-- Queststarter & ender
DELETE FROM `creature_queststarter` WHERE `id` = 156280 AND `quest` = 56775;
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(156280, 56775);

DELETE FROM `creature_questender` WHERE `id` = 156280 AND `quest` = 56775;
INSERT INTO `creature_questender`(`id`, `quest`) VALUES
(156280, 56775);
