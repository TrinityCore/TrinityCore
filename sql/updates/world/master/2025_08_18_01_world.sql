SET @CGUID := 10006796;
SET @OGUID := 10001693;

SET @NPCTEXTID := 600119;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233346, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1514.1197509765625, -725.1319580078125, -129.7012939453125, 3.801227331161499023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Thorntail Matriarch (Area: The Oasis - Difficulty: 0) CreateObject1
(@CGUID+1, 232648, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1414.7239990234375, -808.06427001953125, -138.291824340820312, 3.996766090393066406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62493); -- Slateback Alpha (Area: The Oasis - Difficulty: 0) CreateObject1 (Auras: 465256 - Foundation 1 - Spawn Aura)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465256'); -- Slateback Alpha - 465256 - Foundation 1 - Spawn Aura

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 494777, 2738, 15336, 15792, '0', 0, 0, 1335.2708740234375, -1029.0694580078125, -98.3940963745117187, 5.593780994415283203, 0, 0, -0.33791637420654296, 0.941176116466522216, 120, 255, 1, 62493); -- The Oasis Console (Area: The Oasis - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=233346; -- Thorntail Matriarch
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=232648; -- Slateback Alpha

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (233346,232648));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(233346, 0, 10, 4, 1, 284932, 0x80080048, 0, 0), -- Thorntail Matriarch
(232648, 0, 10, 4, 1, 284072, 0x80080048, 0, 0); -- Slateback Alpha

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=233346 AND `DifficultyID`=0); -- 233346 (Thorntail Matriarch) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3007, `StaticFlags1`=0x10000000, `VerifiedBuild`=62493 WHERE (`Entry`=232648 AND `DifficultyID`=0); -- 232648 (Slateback Alpha) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=233346 AND `MenuID` IN (38098,37141)) OR (`CreatureID`=232648 AND `MenuID`=36878);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(233346, 37141, 62493), -- Thorntail Matriarch
(232648, 36878, 62493); -- Slateback Alpha

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+7;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 276994, 0, 0, 0, 0, 0, 0, 0, 62493), -- 494777 (The Oasis Console)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 276900, 0, 0, 0, 0, 0, 0, 0, 62493), -- 494777 (The Oasis Console)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 281603, 0, 0, 0, 0, 0, 0, 0, 62493), -- 232648 (Slateback Alpha)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 281607, 0, 0, 0, 0, 0, 0, 0, 62493), -- 233346 (Thorntail Matriarch)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 274867, 0, 0, 0, 0, 0, 0, 0, 62493), -- 232648 (Slateback Alpha)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 276900, 0, 0, 0, 0, 0, 0, 0, 62493), -- 494777 (The Oasis Console)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 276787, 0, 0, 0, 0, 0, 0, 0, 62493), -- 233346 (Thorntail Matriarch)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 276900, 0, 0, 0, 0, 0, 0, 0, 62493); -- 494777 (The Oasis Console)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37164 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37165 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=38097 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=38098 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=36878 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=37174 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=37141 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=37178 AND `TextID`=@NPCTEXTID+7);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37164, @NPCTEXTID+0, 62493), -- 494777 (The Oasis Console)
(37165, @NPCTEXTID+1, 62493), -- 494777 (The Oasis Console)
(38097, @NPCTEXTID+2, 62493), -- 232648 (Slateback Alpha)
(38098, @NPCTEXTID+3, 62493), -- 233346 (Thorntail Matriarch)
(36878, @NPCTEXTID+4, 62493), -- 232648 (Slateback Alpha)
(37174, @NPCTEXTID+5, 62493), -- 494777 (The Oasis Console)
(37141, @NPCTEXTID+6, 62493), -- 233346 (Thorntail Matriarch)
(37178, @NPCTEXTID+7, 62493); -- 494777 (The Oasis Console)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=4 AND `MenuID`=37164) OR (`OptionID`=0 AND `MenuID` IN (37165,37174,37178)) OR (`OptionID`=1 AND `MenuID`=36878) OR (`OptionID`=3 AND `MenuID`=37164) OR (`OptionID`=2 AND `MenuID` IN (37141,37164));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37164, 125344, 4, 0, 'Lapbugs', 0, 0, 0, 37178, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(37165, 125355, 0, 0, 'Check another species.', 0, 0, 0, 37164, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(36878, 132138, 1, 0, '<Carefully reach out to the slateback alpha.>', 0, 0, 1, 38097, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(37174, 132542, 0, 0, 'Check another species.', 0, 0, 0, 37164, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(37164, 125345, 3, 0, 'Thorntails', 0, 0, 0, 37174, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(37178, 125358, 0, 0, 'Check another species.', 0, 0, 0, 37164, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(37141, 132139, 2, 0, '<Carefully reach out to the thorntail matriarch.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493),
(37164, 125346, 2, 0, 'Slatebacks', 0, 0, 0, 37165, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 62493);

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=231820 AND `quest` IN (87338,87339));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 87338, 62493), -- Day One Orientation offered by Ve'nari
(231820, 87339, 62493); -- Ongoing Activities offered by Ve'nari

DELETE FROM `creature_questender` WHERE (`id`=231820 AND `quest`=87338);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 87338, 62493); -- Day One Orientation ended by Ve'nari

DELETE FROM `quest_details` WHERE `ID` IN (87338 /*Day One Orientation*/, 87339 /*Ongoing Activities*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(87338, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Day One Orientation
(87339, 1, 0, 0, 0, 0, 0, 0, 0, 62493); -- Ongoing Activities

DELETE FROM `quest_request_items` WHERE `ID`=87338;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(87338, 0, 1, 0, 0, 'Have you familiarized yourself with the animals?', 62493); -- Day One Orientation

DELETE FROM `quest_template_addon` WHERE `ID` IN (87338,87339);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(87338, 0, 0, 0, 87337, 87340, -87338, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(87339, 0, 0, 0, 87337, 87340, -87338, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (36878));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 36878, 1, 0, 0, 47, 0, 87338, 8, 0, '', 0, 'Player for which gossip text is shown has Day One Orientation (87338) in state incomplete'),
(15, 36878, 1, 0, 0, 48, 0, 457894, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 457894 == 1 (but hasn\'t rewarded quest yet)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (37141));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 37141, 2, 0, 0, 47, 0, 87338, 8, 0, '', 0, 'Player for which gossip text is shown has Day One Orientation (87338) in state incomplete'),
(15, 37141, 2, 0, 0, 48, 0, 457893, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 457893 == 1 (but hasn\'t rewarded quest yet)');

-- Slateback Alpha smart ai
SET @ENTRY := 232648;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 36878, 1, 0, 0, 0, 33, 232648, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 36878 selected - Gossip player: Give kill credit Slateback Alpha (232648)', '');

-- Thorntail Matriarch smart ai
SET @ENTRY := 233346;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 37141, 2, 0, 0, 0, 80, 23334600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 2 from menu 37141 selected - Self: Start timed action list id #Thorntail Matriarch #0 (23334600) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 2 from menu 37141 selected - Gossip player: Close gossip', '');

-- Timed list 23334600 smart ai
SET @ENTRY := 23334600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 233346, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Give kill credit 233346', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 5, 377, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Play emote 377', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Despawn instantly', '');
