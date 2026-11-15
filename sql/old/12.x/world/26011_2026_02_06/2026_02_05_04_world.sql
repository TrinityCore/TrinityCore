SET @CGUID := 10006929;

SET @NPCTEXTID := 600170;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233252, 2552, 14717, 15943, '0', 25025, 0, 0, 1, 2731.713623046875, -609.6319580078125, 10.48090267181396484, 0.055101867765188217, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Vereesa Windrunner (Area: Oztan Isle - Difficulty: 0) CreateObject1
(@CGUID+1, 233253, 2552, 14717, 15943, '0', 25025, 0, 0, 1, 2731.892333984375, -607.65625, 10.58854103088378906, 4.775279998779296875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727); -- Arator (Area: Oztan Isle - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Vereesa Windrunner
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, ''); -- Arator

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 25025;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(25025, 'Cosmetic - See Arator and Vereesa Windrunner at Oztan Isle Cliff');

DELETE FROM `phase_area` WHERE `PhaseId` = 25025;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 25025, 'See Arator and Vereesa Windrunner at Oztan Isle Cliff');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25025 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25025, 0, 0, 0, 47, 0, 84996, 2|64, 0, 0, 'Apply Phase 25025 if Quest 84996 is complete|rewarded'),
(26, 25025, 0, 0, 0, 47, 0, 84997, 2|64, 0, 1, 'Apply Phase 25025 if Quest 84997 is not complete|rewarded');

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=3564;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3564, 27, 4470, 0);

-- Quest
UPDATE `quest_offer_reward` SET `RewardText`='Ugh... <Vereesa doubles over.>\n\nForces of the Void... attacking. Why here... now?', `VerifiedBuild`=65727 WHERE `ID`=84997; -- What Might Come
UPDATE `quest_offer_reward` SET `RewardText`='This seems a fitting place to honor my late husband, Rhonin.\n\nWe should get on with the ceremony.', `VerifiedBuild`=65727 WHERE `ID`=84996; -- Vereesa's Tale

DELETE FROM `creature_queststarter` WHERE (`id`=233252 AND `quest`=84997);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(233252, 84997, 65727); -- What Might Come offered by Vereesa Windrunner

DELETE FROM `creature_questender` WHERE (`id`=233314 AND `quest`=84997) OR (`id`=233252 AND `quest`=84996);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(233314, 84997, 65727), -- What Might Come ended by Vereesa Windrunner
(233252, 84996, 65727); -- Vereesa's Tale ended by Vereesa Windrunner

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 453588;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(453588, NULL, NULL, NULL, 1, 0);

DELETE FROM `quest_template_addon` WHERE `ID` = 84997;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(84997, 0, 0, 0, 84996, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=233252 AND `MenuID`=37118) OR (`CreatureID`=233253 AND `MenuID`=38198);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(233252, 37118, 65727), -- Vereesa Windrunner
(233253, 38198, 65727); -- Arator

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 276502, 0, 0, 0, 0, 0, 0, 0, 65727), -- 233252 (Vereesa Windrunner)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 282003, 0, 0, 0, 0, 0, 0, 0, 65727); -- 233253 (Arator)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37118 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=38198 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37118, @NPCTEXTID+0, 65727), -- 233252 (Vereesa Windrunner)
(38198, @NPCTEXTID+1, 65727); -- 233253 (Arator)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37118 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37118, 125312, 0, 0, '<Witness the ceremony.>', 0, 0, 5, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (37118));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 37118, 0, 0, 0, 9, 0, 84997, 0, 0, '', 0, 'Player for which gossip text is shown has quest What Might Come (84997) active');

-- Difficulty
UPDATE `creature_template` SET `faction`=534, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4800 WHERE `entry`=233252; -- Vereesa Windrunner

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=131865;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(131865, 0.347000002861022949, 1.5, 0, 65727);

-- Vereesa Windrunner smart ai
SET @ENTRY := 233252;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 37118, 0, 0, 0, 0, 85, 1214534, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37118 selected - Gossip player: Cast spell 1214534 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37118 selected - Gossip player: Close gossip', '');

-- Scene 3564
SET @ENTRY := 3564;
UPDATE `scene_template` SET `ScriptName` = 'SmartScene' WHERE `SceneId` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 10 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 10, 0, 0, 80, 0, 100, 0, 0, 0, 0, 0, 0, 33, 233252, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Scene Cancel - Last action invoker: Give kill credit Vereesa Windrunner (233252)', ''),
(@ENTRY, 10, 1, 0, 81, 0, 100, 0, 0, 0, 0, 0, 0, 33, 233252, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Scene Complete - Last action invoker: Give kill credit Vereesa Windrunner (233252)', '');
