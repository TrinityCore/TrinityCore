SET @CGUID := 10005736;

SET @NPCTEXTID := 600085;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 231541, 2552, 14771, 14771, '0', 25056, 0, 0, 0, 3212.247314453125, -3073.8837890625, 343.9462890625, 1.542174816131591796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680), -- Sky-Captain Cableclamp (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+1, 230235, 2552, 14771, 14771, '0', 25056, 0, 0, 0, 3212.505126953125, -3072.255126953125, 343.931396484375, 0.037447240203619003, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680), -- Skaggit (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+2, 231541, 2552, 14771, 14771, '0', 25431, 0, 0, 0, 3225.8759765625, -3077.864501953125, 342.837188720703125, 1.542174816131591796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680); -- Sky-Captain Cableclamp (Area: Dornogal - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=230235; -- Skaggit
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=231541; -- Sky-Captain Cableclamp

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x30000100, `VerifiedBuild`=58680 WHERE (`Entry`=230235 AND `DifficultyID`=0); -- 230235 (Skaggit) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x30000100, `VerifiedBuild`=58680 WHERE (`Entry`=231541 AND `DifficultyID`=0); -- 231541 (Sky-Captain Cableclamp) - Sessile, CanSwim, Floating

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (25056, 25431);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25056, 'Cosmetic - See Skaggit and Sky-Captain Cableclamp pre Siren Isle unlock'),
(25431, 'Cosmetic - See Sky-Captain Cableclamp after Siren Isle unlock');

DELETE FROM `phase_area` WHERE `PhaseId` IN (25056, 25431);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14771, 25056, 'Skaggit and Sky-Captain Cableclamp pre Siren Isle unlock'),
(14771, 25431, 'See Sky-Captain Cableclamp after Siren Isle unlock');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (25056,25431) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25056, 0, 0, 0, 47, 0, 84720, 2|64, 0, 1, 'Apply Phase 25056 if Quest 84720 is not complete | rewarded'),
(26, 25056, 0, 0, 0, 48, 0, 453075, 0, 1, 1, 'Apply Phase 25056 if Questobjective 453075 is not rewarded'),
(26, 25431, 0, 0, 0, 47, 0, 84720, 2|64, 0, 0, 'Apply Phase 25431 if Quest 84720 is complete | rewarded'),
(26, 25431, 0, 0, 1, 48, 0, 453075, 0, 1, 0, 'Apply Phase 25431 if Questobjective 453075 is rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=231541 AND `MenuID`=37173) OR (`CreatureID`=230235 AND `MenuID`=36398);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(231541, 37173, 58680), -- Sky-Captain Cableclamp
(230235, 36398, 58680); -- Skaggit

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (37432,37724,36398,37718,37723,37431,37722)) OR (`OptionID`=2 AND `MenuID`=36398) OR (`OptionID`=5 AND `MenuID`=36398) OR (`OptionID`=1 AND `MenuID`=37173) OR (`OptionID`=3 AND `MenuID`=36398) OR (`OptionID`=4 AND `MenuID`=36398) OR (`MenuID`=37173 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37432, 131282, 0, 0, 'No.', 17710, 0, 0, 37431, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680), -- OptionBroadcastTextID: 17710 - 25913 - 30243 - 39548 - 62016 - 66318 - 67492 - 82162 - 93738 - 95797 - 99452 - 113962 - 136126 - 140032 - 140189 - 140192 - 145444 - 145853 - 151700 - 181605 - 182006 - 219430 - 231858 - 244608 - 245792 - 253111 - 275583
(37724, 131617, 0, 0, 'I want to talk about something else.', 0, 0, 0, 36398, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(36398, 131283, 2, 0, 'Where are we going?', 104694, 0, 0, 37432, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680), -- OptionBroadcastTextID: 104694 - 235020
(36398, 124305, 0, 0, 'I am ready to embark.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(37718, 131552, 0, 0, 'I want to talk about something else.', 0, 0, 0, 37173, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(36398, 131553, 5, 0, 'Where is Lady Sena?', 0, 0, 0, 37722, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(37173, 131550, 1, 0, 'What do you know about the Siren Isle?', 0, 0, 0, 37718, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(36398, 131555, 3, 0, 'What do you know about the Siren Isle?', 0, 0, 0, 37724, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(36398, 131554, 4, 0, 'Who are you? Where\'s Gazlowe?', 0, 0, 0, 37723, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(37723, 131616, 0, 0, 'I want to talk about something else.', 0, 0, 0, 36398, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(37431, 131612, 0, 0, 'I want to talk about something else.', 0, 0, 0, 36398, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(37722, 131615, 0, 0, 'I want to talk about something else.', 0, 0, 0, 36398, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680),
(37173, 125352, 0, 0, 'Take me to the Siren Isle.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (36398));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 36398, 0, 0, 0, 47, 0, 84720, 8, 0, '', 0, 'Player for which gossip text is shown has To the Siren Isle! (84720) in state taken');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (37173));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 37173, 0, 0, 0, 47, 0, 84720, 66, 0, '', 0, 'Player for which gossip text is shown has To the Siren Isle! (84720) in state complete, rewarded'),
(15, 37173, 0, 0, 1, 48, 0, 453075, 0, 1, '', 0, 'Player for which gossip text is shown has quest objective 453075 == 1 (but hasn\'t rewarded quest yet)');

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+7;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 279724, 0, 0, 0, 0, 0, 0, 0, 58680), -- 231541 (Sky-Captain Cableclamp)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 279750, 0, 0, 0, 0, 0, 0, 0, 58680), -- 230235 (Skaggit)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 279748, 0, 0, 0, 0, 0, 0, 0, 58680), -- 230235 (Skaggit)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 279747, 0, 0, 0, 0, 0, 0, 0, 58680), -- 230235 (Skaggit)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 278427, 0, 0, 0, 0, 0, 0, 0, 58680), -- 230235 (Skaggit)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 276992, 0, 0, 0, 0, 0, 0, 0, 58680), -- 231541 (Sky-Captain Cableclamp)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 278425, 0, 0, 0, 0, 0, 0, 0, 58680), -- 230235 (Skaggit)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 273989, 0, 0, 0, 0, 0, 0, 0, 58680); -- 230235 (Skaggit)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37718 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37722 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=37723 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=37724 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=37431 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=37173 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=37432 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=36398 AND `TextID`=@NPCTEXTID+7);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37718, @NPCTEXTID+0, 58680), -- 231541 (Sky-Captain Cableclamp)
(37722, @NPCTEXTID+1, 58680), -- 230235 (Skaggit)
(37723, @NPCTEXTID+2, 58680), -- 230235 (Skaggit)
(37724, @NPCTEXTID+3, 58680), -- 230235 (Skaggit)
(37431, @NPCTEXTID+4, 58680), -- 230235 (Skaggit)
(37173, @NPCTEXTID+5, 58680), -- 231541 (Sky-Captain Cableclamp)
(37432, @NPCTEXTID+6, 58680), -- 230235 (Skaggit)
(36398, @NPCTEXTID+7, 58680); -- 230235 (Skaggit)

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=3535;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3535, 30, 4425, 0);

-- Scene 3535
SET @ENTRY := 3535;
UPDATE `scene_template` SET `ScriptName` = 'SmartScene' WHERE `SceneId` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 10 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 10, 0, 0, 81, 0, 100, 0, 0, 0, 0, 0, 0, 85, 463902, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Scene Complete - Self: Cast spell  463902 with flags triggered on self', '');

-- Spelltarget pos.
DELETE FROM `spell_target_position` WHERE (`ID`=463902 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(463902, 0, 0, 2127, 1966.3199462890625, 15.84000015258789062, 39.8600006103515625, 58680); -- Spell: 463902 ([DNT] RTC + Teleport) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=230235 AND `quest`=84720);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(230235, 84720, 58680); -- To the Siren Isle! offered by Skaggit

DELETE FROM `quest_template_addon` WHERE `ID` = 84720;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(84720, 0, 0, 0, 84719, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- To the Siren Isle!

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 453075;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(453075, NULL, NULL, NULL, 1, 0);

-- Skaggit smart ai
SET @ENTRY := 230235;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 36398, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 36398 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 230235, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 36398 selected - Gossip player: Give kill credit Skaggit (230235)', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 470916, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 36398 selected - Gossip player: Cast spell 470916 on self', '');
