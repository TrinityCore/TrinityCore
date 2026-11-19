SET @CGUID := 7003177;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 128529, 1643, 8721, 9130, '0', 9192, 0, 0, 0, -373.48785400390625, 1283.5694580078125, 22.8849029541015625, 2.311525821685791015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60822); -- Lucille Waycrest (Area: Hangman's Point - Difficulty: 0) CreateObject1 (Auras: 248932 - Tied Up)

DELETE FROM `creature_template_addon` WHERE `entry` IN (128529 /*128529 (Lucille Waycrest) - Tied Up*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(128529, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248932'); -- 128529 (Lucille Waycrest) - Tied Up

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=128529 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60822 WHERE (`Entry`=128529 AND `DifficultyID`=0); -- 128529 (Lucille Waycrest) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 9192;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9192, 'Cosmetic - See Lucille Waycrest during Witch test');

DELETE FROM `phase_area` WHERE `PhaseId` = 9192;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9130, 9192, 'See Lucille Waycrest during Witch test');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (9191,9192) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9191, 0, 0, 0, 47, 0, 48198, 8, 0, 1, 'Apply Phase 9191 if Quest 48198 is not in progress'),
(26, 9192, 0, 0, 0, 47, 0, 48198, 8, 0, 0, 'Apply Phase 9192 if Quest 48198 is not in progress');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (5696, 5695, 5694, 5685, 5698);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5696, 12749, 0, 60822),
(5695, 12743, 0, 60822),
(5694, 12738, 0, 60822),
(5685, 12725, 0, 60822),
(5698, 12761, 0, 60822);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_burden_of_proof_speak_with_constable' WHERE `Id` = 5685;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_burden_of_proof_first_test_given' WHERE `Id` = 5694;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_burden_of_proof_second_test_given' WHERE `Id` = 5695;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_burden_of_proof_third_test_given' WHERE `Id` = 5696;

DELETE FROM `conversation_actors` WHERE (`Idx`=1 AND `ConversationId` IN (5685,5694,5695,5696)) OR (`Idx`=0 AND `ConversationId` IN (5685,5694,5695,5696,5698)) OR (`Idx`=2 AND `ConversationId` IN (5694,5695,5696)) OR (`Idx`=3 AND `ConversationId`=5696);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5685, 60052, @CGUID+0, 1, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607D8440007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 128529 (Lucille Waycrest) Low: 2701243
(5685, 59853, 0, 0, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607A7480007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 2701243
(5694, 60052, 0, 2, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607D8440007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 128529 (Lucille Waycrest) Low: 2701243
(5694, 59853, 0, 1, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607A7480007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 2701243
(5694, 60047, 7002080, 0, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD608CF3C0007A1600002937BC Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 144335 (Fletcher's Hollow Villager) Low: 2701244
(5695, 60052, 0, 0, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607D8440007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 128529 (Lucille Waycrest) Low: 2701243
(5695, 59853, 0, 2, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607A7480007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 2701243
(5695, 60045, 7002081, 1, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD608CF4C0007A1600002937BC Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 144339 (Fletcher's Hollow Villager) Low: 2701244
(5696, 60052, 0, 0, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607D8440007A16000029BBF9 Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 128529 (Lucille Waycrest) Low: 2735097
(5696, 59853, 0, 3, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD607A7480007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 2701243
(5696, 60045, 7002081, 2, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD608CF4C0007A1600002937BC Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 144339 (Fletcher's Hollow Villager) Low: 2701244
(5696, 60049, 7002083, 1, 0, 0, 0, 0, 60822), -- Full: 0x203CE0CD608CF440007A1600002937BC Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 144337 (Fletcher's Hollow Villager) Low: 2701244
(5698, 59853, 7002088, 0, 0, 0, 0, 0, 60822); -- Full: 0x203CE0CD607A7480007A1600002937BB Creature/0 R3896/S31254 Map: 1643 (Kul Tiras) Entry: 125394 (Constable Henry Framer) Low: 2701243

DELETE FROM `conversation_line_template` WHERE `Id` IN (12759, 12724, 12723, 12722, 12721, 12725, 12742, 12741, 12740, 12739, 12738, 12748, 12747, 12746, 12745, 12744, 12743, 12758, 12755, 12754, 12753, 12752, 12751, 12750, 12749, 12761);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(12759, 0, 1, 0, 0, 60822),
(12724, 0, 0, 0, 0, 60822),
(12723, 0, 0, 0, 0, 60822),
(12722, 0, 0, 0, 0, 60822),
(12721, 0, 0, 0, 0, 60822),
(12725, 0, 0, 0, 0, 60822),
(12742, 0, 2, 0, 0, 60822),
(12741, 0, 1, 0, 0, 60822),
(12740, 0, 1, 0, 0, 60822),
(12739, 0, 1, 0, 0, 60822),
(12738, 0, 0, 0, 0, 60822),
(12748, 0, 0, 0, 0, 60822),
(12747, 0, 2, 0, 0, 60822),
(12746, 0, 2, 0, 0, 60822),
(12745, 0, 2, 0, 0, 60822),
(12744, 0, 1, 0, 0, 60822),
(12743, 0, 0, 0, 0, 60822),
(12758, 0, 0, 0, 0, 60822),
(12755, 0, 3, 0, 0, 60822),
(12754, 0, 0, 0, 0, 60822),
(12753, 0, 3, 0, 0, 60822),
(12752, 0, 3, 0, 0, 60822),
(12751, 0, 2, 0, 0, 60822),
(12750, 0, 1, 0, 0, 60822),
(12749, 0, 0, 0, 0, 60822),
(12761, 0, 0, 0, 0, 60822);

-- Gossip
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (21407));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 21407, 0, 0, 0, 47, 0, 48198, 8, 0, '', 0, 'Player for which gossip text is shown has The Burden of Proof (48198) in state incomplete'),
(15, 21407, 0, 0, 0, 48, 0, 291661, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 291661 < 1 or has rewarded the quest');

-- ScriptName
DELETE FROM `spell_script_names` WHERE `spell_id` IN (250118,248808,249108,249110);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(250118, 'spell_drustvar_ping_lucille_burden_of_proof'),
(248808, 'spell_drustvar_cut_onions_burden_of_proof'),
(249108, 'spell_drustvar_release_bloodflies_burden_of_proof'),
(249110, 'spell_drustvar_administering_venom_burden_of_proof');

DELETE FROM `event_script_names` WHERE `Id` IN (59763,59764,59765);
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(59763, 'SmartEventTrigger'),
(59764, 'SmartEventTrigger'),
(59765, 'SmartEventTrigger');

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 128529;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(128529, 250118, 1, 0);

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48198,48171);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48198, 1, 0, 0, 0, 0, 0, 0, 0, 60822), -- The Burden of Proof
(48171, 1, 1, 25, 0, 0, 0, 0, 0, 61967); -- The Curse of Fletcher's Hollow

DELETE FROM `creature_queststarter` WHERE (`id`=125380 AND `quest`=48198) OR (`id`=125380 AND `quest`=48171);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(125380, 48198, 60822), -- The Burden of Proof offered by Lucille Waycrest
(125380, 48171, 61967); -- The Curse of Fletcher's Hollow offered by Lucille Waycrest

DELETE FROM `creature_questender` WHERE (`id`=125380 AND `quest`=48198);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(125380, 48198, 61967); -- The Burden of Proof ended by Lucille Waycrest

DELETE FROM `quest_template_addon` WHERE `ID` = 48171;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48171, 0, 0, 0, 48198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Curse of Fletcher's Hollow

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 291971;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291971, NULL, NULL, NULL, 1, 1);

-- Lucille Waycrest smart ai
SET @ENTRY := 125380;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 21395, 0, 0, 0, 0, 85, 250087, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21395 selected - Gossip player: Cast spell 250087 on self', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 48198, 0, 0, 0, 0, 143, 5698, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest The Burden of Proof (48198) - Player who accepted quest: Start conversation (5698) Actors<> (first line 12761)', '');

-- Constable Henry Framer smart ai
SET @ENTRY := 125394;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 48283, 0, 0, 0, 0, 143, 5665, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Standing Accused (48283) - Player who accepted quest: Start conversation (5665) Actors<> (first line 12676)', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 21407, 0, 0, 0, 0, 143, 5685, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21407 selected - Gossip player: Start conversation (5685) Actors<> (first line 12725)', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21407 selected - Gossip player: Close gossip', '');

-- Conversation ai
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = 59763 AND `source_type` = 3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(59763, 3, 0, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 5694, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent - Start conversation 5694 to Action Invoker');

-- Conversation ai
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = 59764 AND `source_type` = 3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(59764, 3, 0, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 5695, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent - Start conversation 5695 to Action Invoker');

-- Conversation ai
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = 59765 AND `source_type` = 3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(59765, 3, 0, 0, '', 87, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 5696, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On SendEvent - Start conversation 5696 to Action Invoker');

-- Path for Constable Henry Farmer
SET @ENTRY := 125394;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Constable Henry Framer - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -375.0528, 1285.2463, 22.08916, NULL, 0),
(@PATH, 1, -374.0528, 1285.9963, 22.08916, NULL, 0),
(@PATH, 2, -373.5528, 1286.4963, 22.08916, NULL, 0),
(@PATH, 3, -372.333, 1287.51, 22.819433, 2.2248, 10470),
(@PATH, 4, -374.0528, 1285.9963, 23.9963, NULL, 0),
(@PATH, 5, -375.0528, 1285.2463, 22.0694, NULL, 0),
(@PATH, 6, -377.77258, 1282.9827, 22.819433, 2.238, 0);

-- Path for Constable Henry Farmer
SET @ENTRY := 125394;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Constable Henry Framer - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -380.656, 1281.16, 22.698519, 2.3066, 8420),
(@PATH, 1, -375.175, 1282.52, 22.819433, NULL, 8662),
(@PATH, 2, -377.77258, 1282.9827, 22.819433, 2.238, 0);

-- Path for Constable Henry Farmer
SET @ENTRY := 125394;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Constable Henry Framer - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -372.333, 1287.45, 22.819433, 4.4781, 21418),
(@PATH, 1, -377.77258, 1282.9827, 22.819433, 2.238, 0);

-- Path for Constable Henry Farmer
SET @ENTRY := 125394;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Constable Henry Framer - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -376.17517, 1285.0858, 22.819433, 2.238, 6237),
(@PATH, 1, -377.77258, 1282.9827, 22.819433, 0.1413, 0);
