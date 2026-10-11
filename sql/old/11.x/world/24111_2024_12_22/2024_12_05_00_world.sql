SET @CGUID := 10004705;

SET @NPCTEXTID := 600053;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 223637, 2552, 14717, 14717, '0', 23672, 0, 0, 0, 1150.9322509765625, -2015.875, 81.0217437744140625, 0.565037012100219726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Natalia Pearce (Area: Isle of Dorn - Difficulty: 0) CreateObject1

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (23672, 23673);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23672, 'Cosmetic - See Natalia Pearces outside of Freywold Village'),
(23673, 'Cosmetic - See Natalia Pearces outside the Basalteous cave');

DELETE FROM `phase_area` WHERE `PhaseId` IN (23672, 23673);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 23672, 'See Natalia Pearces outside of Freywold Village'),
(14717, 23673, 'See Natalia Pearces outside the Basalteous cave');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23672 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23673 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23672, 0, 0, 0, 47, 0, 82465, 2|8|64, 0, 1, 'Apply Phase 23672 if Quest 82465 is not taken | complete | rewarded'),
(26, 23673, 0, 0, 0, 47, 0, 82465, 2|8|64, 0, 0, 'Apply Phase 23673 if Quest 82465 is taken | complete | rewarded');

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 264304, 0, 0, 0, 0, 0, 0, 0, 57689), -- 223649 (Maluc)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 264317, 0, 0, 0, 0, 0, 0, 0, 57689), -- 223648 (Betta)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 264323, 0, 0, 0, 0, 0, 0, 0, 57689); -- 223652 (Kurron)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34965 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=34968 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=34970 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34965, @NPCTEXTID+0, 57689), -- 223649 (Maluc)
(34968, @NPCTEXTID+1, 57689), -- 223648 (Betta)
(34970, @NPCTEXTID+2, 57689); -- 223652 (Kurron)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (34964,34971,34969));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(34964, 122463, 0, 0, 'What do you know about Basalteous?', 0, 0, 1, 34965, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(34971, 122467, 0, 0, 'Where can I find the Basalteous?', 0, 0, 1, 34970, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(34969, 122466, 0, 0, 'What do you know about Basalteous?', 0, 0, 1, 34968, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (34969,34971,34964));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 34969, 0, 0, 0, 9, 0, 82441, 0, 0, '', 0, 'Player for which gossip text is shown has quest For The Love of Gems (82441) active'),
(15, 34969, 0, 0, 0, 48, 0, 449935, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 449935 < 1 or has rewarded the quest'),
(15, 34971, 0, 0, 0, 9, 0, 82441, 0, 0, '', 0, 'Player for which gossip text is shown has quest For The Love of Gems (82441) active'),
(15, 34971, 0, 0, 0, 48, 0, 449934, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 449934 < 1 or has rewarded the quest'),
(15, 34964, 0, 0, 0, 9, 0, 82441, 0, 0, '', 0, 'Player for which gossip text is shown has quest For The Love of Gems (82441) active'),
(15, 34964, 0, 0, 0, 48, 0, 449933, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 449933 < 1 or has rewarded the quest');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=223637 AND `quest` IN (82465,82441));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(223637, 82465, 57689), -- Precious Gems offered by Natalia Pearce
(223637, 82441, 57689); -- For The Love of Gems offered by Natalia Pearce

DELETE FROM `creature_questender` WHERE (`id`=223637 AND `quest` = 82441);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(223637, 82441, 57689); -- For The Love of Gems ended by Natalia Pearce

DELETE FROM `quest_template_addon` WHERE `ID` = 82465;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(82465, 0, 0, 0, 82441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Precious Gems

-- Betta smart ai
SET @ENTRY := 223648;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 34969, 0, 0, 0, 0, 33, 223648, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34969 selected - Gossip player: Give kill credit Betta (223648)', '');

-- Kurron smart ai
SET @ENTRY := 223652;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 34971, 0, 0, 0, 0, 33, 223652, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34971 selected - Gossip player: Give kill credit Kurron (223652)', '');

-- Maluc smart ai
SET @ENTRY := 223649;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 34964, 0, 0, 0, 0, 33, 223649, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 34964 selected - Gossip player: Give kill credit Maluc (223649)', '');
