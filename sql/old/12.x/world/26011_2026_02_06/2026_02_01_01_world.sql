-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=233253; -- Arator

UPDATE `creature_template` SET `ScriptName` = 'npc_vereesa_windrunner_oztan_isle', `AIName` = '' WHERE `entry` = 231042;

-- Phasing (Update Condition)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25024 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25024, 0, 0, 0, 47, 0, 92405, 2|8|64, 0, 0, 'Apply Phase 25024 if Quest 92405 is taken|complete|rewarded'),
(26, 25024, 0, 0, 0, 47, 0, 84996, 2|64, 0, 1, 'Apply Phase 25024 if Quest 84996 is complete|rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27493;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27493, 75392, 0, 65299);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_vereesas_tale' WHERE `Id` = 27493;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27493 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27493, 102984, 0, 0, 0, 0, 0, 65299), -- Full: 0x2042653F00E1A0800000200000677C99 Creature/0 R4249/S32 Map: 2552 (Khaz Algar (Surface)) Entry: 231042 (Vereesa Windrunner) Low: 6782105
(27493, 102985, 1, 0, 0, 0, 0, 65299); -- Full: 0x2042653F00E19FC00000200000677C99 Creature/0 R4249/S32 Map: 2552 (Khaz Algar (Surface)) Entry: 231039 (Arator) Low: 6782105

DELETE FROM `conversation_line_template` WHERE `Id` IN (77713, 77712, 77711, 77703, 77702, 75392);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(77713, 0, 0, 0, 0, 65299),
(77712, 0, 1, 0, 0, 65299),
(77711, 0, 0, 0, 0, 65299),
(77703, 0, 0, 0, 0, 65299),
(77702, 0, 0, 0, 0, 65299),
(75392, 0, 0, 0, 0, 65299);

-- Gossip
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37102 AND `OptionID` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37102, 132038, 1, 0, '<Ask Vereesa to move on.|cFFFF0000--Skip current conversation.>|r', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65299),
(37102, 125280, 0, 0, '<Hear Vereesa\'s tale.>', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65299);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (37102));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 37102, 0, 0, 0, 9, 0, 84996, 0, 0, '', 0, 'Player for which gossip text is shown has quest Vereesa\'s Tale (84996) active'),
(15, 37102, 1, 0, 0, 9, 0, 84996, 0, 0, '', 0, 'Player for which gossip text is shown has quest Vereesa\'s Tale (84996) active');

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 455357;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(455357, NULL, NULL, NULL, 1, 0);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=233253 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(233253, 0, 10, 30, 1, 284746, 0x0, 32768, 0); -- Arator

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3020, `StaticFlags1`=0x10000000, `VerifiedBuild`=65299 WHERE (`Entry`=233253 AND `DifficultyID`=0); -- 233253 (Arator) - CanSwim

-- Arator smart ai
SET @ENTRY := 231039;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 2, 23103900, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 23103900 ended - Self: Despawn instantly', '');

-- Path for Vereesa Windrunner
SET @ENTRY := 231042;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Vereesa Windrunner - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2604.9253, -759.8316, 27.298847, NULL, 0),
(@PATH, 1, 2613.3186, -749.8768, 23.326048, NULL, 0),
(@PATH, 2, 2616.9229, -745.73785, 22.463118, NULL, 0);

-- Path for Arator
SET @ENTRY := 231039;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Arator - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2598.6692, -765.42535, 29.512508, NULL, 0),
(@PATH, 1, 2611.587, -747.559, 23.54781, NULL, 0),
(@PATH, 2, 2616.165, -740.9961, 21.908726, NULL, 0);