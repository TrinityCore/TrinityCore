SET @CGUID := 6003596;

SET @NPCTEXTID := 560011;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 99986, 1220, 7502, 7502, '0', 6054, 0, 0, 1, -932.0242919921875, 4415.23974609375, 744.08087158203125, 4.479055404663085937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61491), -- Apata Highmountain (Area: Dalaran - Difficulty: 0) CreateObject1
(@CGUID+1, 100810, 1220, 7502, 7502, '0', 6054, 0, 0, 1, -791.3507080078125, 4386.0458984375, 740.24078369140625, 0.043211385607719421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61491), -- Grif Wildheart (Area: Dalaran - Difficulty: 0) CreateObject1
(@CGUID+2, 100171, 1220, 7502, 7581, '0', 6054, 0, 0, 0, -893.83856201171875, 4524.96728515625, 730.78021240234375, 0.182910159230232238, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61491); -- Courier Larkspur (Area: Dalaran City - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, ''); -- Apata Highmountain

-- Template
UPDATE `creature_template` SET `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=100171; -- Courier Larkspur
UPDATE `creature_template` SET `npcflag`=1, `BaseAttackTime`=1500, `unit_flags2`=0x800 WHERE `entry`=100810; -- Grif Wildheart
UPDATE `creature_template` SET `faction`=1665, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=99986; -- Apata Highmountain

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=488, `StaticFlags1`=0x10000000, `VerifiedBuild`=61491 WHERE (`Entry`=100171 AND `DifficultyID`=0); -- 100171 (Courier Larkspur) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=488, `StaticFlags1`=0x10000000, `VerifiedBuild`=61491 WHERE (`Entry`=100810 AND `DifficultyID`=0); -- 100810 (Grif Wildheart) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=488, `StaticFlags1`=0x10000000, `VerifiedBuild`=61491 WHERE (`Entry`=99986 AND `DifficultyID`=0); -- 99986 (Apata Highmountain) - CanSwim

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (100810,99986));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(100810, 1, 0, 0, 0, 0, 0, 0, 2552, 0, 0, 61491), -- Grif Wildheart
(99986, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 61491); -- Apata Highmountain

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 6054;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6054, 'Cosmetic - See Grif Wildheart - Courier Larkspur - Apata Highmountain in Dalaran');

DELETE FROM `phase_area` WHERE `PhaseId` = 6054;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7502, 6054, 'See Grif Wildheart - Courier Larkspur - Apata Highmountain in Dalaran');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 6054 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 6054, 0, 0, 0, 47, 0, 41415, 2|8, 0, 0, 'Apply Phase 5852 if Quest 41415 is in progress | complete');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=100171 AND `MenuID`=19397) OR (`CreatureID`=99986 AND `MenuID`=19033) OR (`CreatureID`=100810 AND `MenuID`=19399);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(100171, 19397, 61491), -- Courier Larkspur
(99986, 19033, 61491), -- Apata Highmountain
(100810, 19399, 61491); -- Grif Wildheart

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+5;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 106756, 0, 0, 0, 0, 0, 0, 0, 61491), -- 99986 (Apata Highmountain)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 106758, 0, 0, 0, 0, 0, 0, 0, 61491), -- 100171 (Courier Larkspur)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 106762, 0, 0, 0, 0, 0, 0, 0, 61491), -- 100171 (Courier Larkspur)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 106757, 0, 0, 0, 0, 0, 0, 0, 61491), -- 100810 (Grif Wildheart)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 106778, 0, 0, 0, 0, 0, 0, 0, 61491), -- 100810 (Grif Wildheart)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 101745, 0, 0, 0, 0, 0, 0, 0, 61491); -- 99986 (Apata Highmountain)

DELETE FROM `gossip_menu` WHERE (`MenuID`=19395 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=19396 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=19397 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=19398 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=19399 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=19033 AND `TextID`=@NPCTEXTID+5);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(19395, @NPCTEXTID+0, 61491), -- 99986 (Apata Highmountain)
(19396, @NPCTEXTID+1, 61491), -- 100171 (Courier Larkspur)
(19397, @NPCTEXTID+2, 61491), -- 100171 (Courier Larkspur)
(19398, @NPCTEXTID+3, 61491), -- 100810 (Grif Wildheart)
(19399, @NPCTEXTID+4, 61491), -- 100810 (Grif Wildheart)
(19033, @NPCTEXTID+5, 61491); -- 99986 (Apata Highmountain)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (19399,19033,19397));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(19399, 45259, 0, 0, 'She said you know something about an ancient weapon.', 106746, 0, 0, 19398, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61491),
(19033, 45079, 0, 0, 'I\'m told you know about an ancient weapon.', 106745, 0, 0, 19395, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61491),
(19397, 45240, 0, 0, 'Do you know of a weapon that could help fight the Legion?', 106749, 0, 0, 19396, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61491);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19399));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19399, 0, 0, 0, 47, 0, 41415, 8, 0, '', 0, 'Player for which gossip text is shown has The Hunter\'s Call (41415) in state incomplete'),
(15, 19399, 0, 0, 0, 48, 0, 282341, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 282341 == 1 (but hasn\'t rewarded quest yet)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19033));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19033, 0, 0, 0, 47, 0, 41415, 8, 0, '', 0, 'Player for which gossip text is shown has The Hunter\'s Call (41415) in state incomplete'),
(15, 19033, 0, 0, 0, 48, 0, 282343, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 282343 < 1 or has rewarded the quest');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19397));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19397, 0, 0, 0, 47, 0, 41415, 8, 0, '', 0, 'Player for which gossip text is shown has The Hunter\'s Call (41415) in state incomplete'),
(15, 19397, 0, 0, 0, 48, 0, 282342, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 282342 < 1 or has rewarded the quest');

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (40618 /*Weapons of Legend*/, 41415 /*The Hunter's Call*/, 90705 /*Lorewalking*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40618, 1, 0, 0, 0, 0, 0, 0, 0, 61491), -- Weapons of Legend
(41415, 1, 1, 0, 0, 0, 0, 0, 0, 61491), -- The Hunter's Call
(90705, 1, 1, 0, 0, 0, 500, 0, 0, 61491); -- Lorewalking

DELETE FROM `quest_offer_reward` WHERE `ID`=41415;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(41415, 1, 1, 0, 0, 0, 0, 0, 0, 'Any of the three weapons you learned of would be a huge boon in the war against the Legion.$b$bBut your crusade must start with one of them, so you must choose.', 61491); -- The Hunter's Call

DELETE FROM `quest_request_items` WHERE `ID`=41415;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(41415, 0, 1, 0, 0, 'Have you chosen a lead to pursue first?', 61491); -- The Hunter's Call

DELETE FROM `creature_queststarter` WHERE (`id`=102478 AND `quest` IN (40618,41415));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(102478, 40618, 61491), -- Weapons of Legend offered by Emmarel Shadewarden
(102478, 41415, 61491); -- The Hunter's Call offered by Emmarel Shadewarden

DELETE FROM `quest_template_addon` WHERE `ID` = 40618;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(40618, 0, 0, 0, 41415, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Dreadlord's Prize

-- Grif Wildheart smart ai
SET @ENTRY := 100810;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 19399, 0, 0, 0, 0, 33, 104297, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19399 selected - Gossip player: Give kill credit Kill Credit: Talk to Grif (104297)', '');

-- Apata Highmountain smart ai
SET @ENTRY := 99986;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 19033, 0, 0, 0, 0, 33, 104298, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19033 selected - Gossip player: Give kill credit Kill Credit: Talk to Apata (104298)', '');

-- Courier Larkspur smart ai
SET @ENTRY := 100171;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 19397, 0, 0, 0, 0, 33, 104299, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19397 selected - Gossip player: Give kill credit Kill Credit: Talk to Larkspur (104299)', '');
