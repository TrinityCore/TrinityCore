SET @CGUID := 11000831;
SET @NPCTEXTID := 610032;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 241042, 0, 15968, 15995, '0', 26249, 0, 0, 0, 7219.01123046875, -4106.63037109375, 104.9899826049804687, 4.802604198455810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67186); -- Mysterious Rootway (Area: Fairbreeze Village - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000001 WHERE `entry`=241042; -- Mysterious Rootway

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `StaticFlags1`=0x0, `StaticFlags3`=0x2000000, `StaticFlags5`=0x1, `VerifiedBuild`=67314 WHERE (`Entry`=241042 AND `DifficultyID`=0); -- 241042 (Mysterious Rootway) - Sessile, Floating - CannotTurn - UntargetableByClient

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` = 28444;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(28444, 78289, 0, 67186);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_the_root_cause_open_portal' WHERE `Id` = 28444;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=28444 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(28444, 105442, 11000790, 0, 0, 0, 0, 0, 67186); -- Full: 0x2030780000E7280000F2950000705DD8 Creature/0 R3102/S62101 Map: 0 (Eastern Kingdoms) Entry: 236704 (Orweyna) Low: 7364056

DELETE FROM `conversation_line_template` WHERE `Id` IN (81180, 81179, 79342, 78289);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(81180, 0, 1, 1, 0, 67186),
(81179, 0, 0, 1, 0, 67186),
(79342, 0, 0, 0, 0, 67186),
(78289, 0, 0, 0, 0, 67186);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 26249;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(26249, 'Cosmetic - See Mysterious Rootway at Fairbreeze Village');

DELETE FROM `phase_area` WHERE `PhaseId` = 26249;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15995, 26249, 'See Mysterious Rootway at Fairbreeze Village');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 26248 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 26248, 0, 0, 0, 47, 0, 89402, 2|8|64, 0, 0, 'Apply Phase 26248 if Quest 89402 is complete|in progress|rewarded'),
(26, 26248, 0, 0, 0, 47, 0, 86899, 2|64, 0, 1, 'Apply Phase 26248 if Quest 86899 is not complete|rewarded'),
(26, 26248, 0, 0, 0, 48, 0, 464543, 0, 1, 1, 'Apply Phase 26248 if Questobjective 464543 is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 26249 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 26249, 0, 0, 0, 47, 0, 86899, 2|64, 0, 0, 'Apply Phase 26249 if Quest 86899 is complete|rewarded'),
(26, 26249, 0, 0, 1, 47, 0, 86899, 8, 0, 0, 'Apply Phase 26249 if Quest 86899 is in progress'),
(26, 26249, 0, 0, 1, 48, 0, 464543, 0, 1, 0, 'Apply Phase 26249 if Questobjective 464543 is rewarded');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=236704 AND `quest`=86899);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(236704, 86899, 66838); -- The Root Cause offered by Orweyna

DELETE FROM `quest_details` WHERE `ID`=86899;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(86899, 1, 0, 0, 0, 0, 0, 0, 0, 66838); -- The Root Cause

DELETE FROM `quest_poi` WHERE (`QuestID`=86899 AND `BlobIndex`=0 AND `Idx1`=4);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(86899, 0, 4, 32, 0, 0, 0, 2395, 0, 0, 0, 0, 0, 2768734, 0, 67186); -- The Root Cause

UPDATE `quest_poi` SET `ObjectiveIndex`=2, `QuestObjectiveID`=459756, `QuestObjectID`=253687, `Flags`=2, `SpawnTrackingID`=0, `VerifiedBuild`=67186 WHERE (`QuestID`=86899 AND `BlobIndex`=0 AND `Idx1`=3); -- The Root Cause
UPDATE `quest_poi` SET `Flags`=2, `VerifiedBuild`=67186 WHERE (`QuestID`=86899 AND `BlobIndex`=0 AND `Idx1`=2); -- The Root Cause
UPDATE `quest_poi` SET `VerifiedBuild`=67186 WHERE (`QuestID`=86899 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=86899 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=93057 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=93057 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=94866 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=94866 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=92150 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=92150 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50604 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=53436 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50599 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50601 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48639 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48639 AND `BlobIndex`=3 AND `Idx1`=2) OR (`QuestID`=48639 AND `BlobIndex`=2 AND `Idx1`=1) OR (`QuestID`=48639 AND `BlobIndex`=1 AND `Idx1`=0) OR (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=42421 AND `BlobIndex`=4 AND `Idx1`=5) OR (`QuestID`=42421 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=42421 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=42421 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=42421 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42421 AND `BlobIndex`=1 AND `Idx1`=0) OR (`QuestID`=42420 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42420 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=86899 AND `Idx1`=4 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(86899, 4, 0, 7307, -4130, 89, 67186); -- The Root Cause

UPDATE `quest_poi_points` SET `X`=7221, `Y`=-4107, `Z`=0, `VerifiedBuild`=67186 WHERE (`QuestID`=86899 AND `Idx1`=3 AND `Idx2`=0); -- The Root Cause
UPDATE `quest_poi_points` SET `VerifiedBuild`=67186 WHERE (`QuestID`=86899 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=86899 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=86899 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=93057 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=93057 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=94866 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=94866 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=92150 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=10) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=92150 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50604 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50604 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=53436 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50599 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50601 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42421 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42420 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42420 AND `Idx1`=0 AND `Idx2`=0);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=236704 AND `MenuID`=40378);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(236704, 40378, 66838); -- Orweyna

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 299238, 0, 0, 0, 0, 0, 0, 0, 66838); -- 236704 (Orweyna)

DELETE FROM `gossip_menu` WHERE (`MenuID`=40378 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40378, @NPCTEXTID+0, 66838); -- 236704 (Orweyna)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=40378 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(40378, 135559, 0, 0, 'I\'m ready. Let\'s go!', 45852, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838); -- OptionBroadcastTextID: 45852 - 47369 - 50940 - 111807 - 132063

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (40378));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 40378, 0, 0, 0, 9, 0, 86899, 0, 0, '', 0, 'Player for which gossip text is shown has quest The Root Cause (86899) active');

-- Spelltarget pos.
DELETE FROM `spell_target_position` WHERE (`ID`=1226563 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(1226563, 0, 0, 2694, -180.490005493164062, -2153.219970703125, 1176.699951171875, 67314); -- Spell: 1226563 (Teleport) Effect 0: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 241042;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(241042, 1226563, 1, 0);

-- Orweyna smart ai
SET @ENTRY := 236704;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 40378, 0, 0, 0, 0, 33, 236704, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 40378 selected - Gossip player: Give kill credit Orweyna (236704)', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 143, 28444, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 40378 selected - Gossip player: Start conversation (28444) Actors<> (first line 78289)', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 40378 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 7, 0, 0, 0, 80, 23670400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 7 - Self: Start timed action list id #Orweyna #0 (23670400) (update out of combat)', ''),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 2, 8, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Despawn instantly', '');

-- Halduron Brightwing smart ai
SET @ENTRY := 240715;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 10, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Despawn instantly', '');

-- Timed list 23670400 smart ai
SET @ENTRY := 23670400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 85, 1227327, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Cast spell 1227327 on self', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Owner/Summoner: Cast spell 82238 on self', '');

-- Mysterious Rootway smart ai
SET @ENTRY := 241042;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 73, 0, 100, 0, 0, 0, 0, 0, 0, 33, 253687, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Clicker: Give kill credit  Kill Credit: Portal Taken (253687)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 241042, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Clicker: Give kill credit Mysterious Rootway (241042)', '');

-- Path Orweyna
SET @ENTRY := 236704;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Orweyna - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 7286.8853, -4147.608, 89.09489, NULL, 0),
(@PATH, 1, 7272.6475, -4143.533, 88.78289, NULL, 0),
(@PATH, 2, 7257.244, -4130.1147, 88.74363, NULL, 0),
(@PATH, 3, 7247.751, -4126.193, 93.06993, NULL, 0),
(@PATH, 4, 7235.901, -4124.1787, 97.01976, NULL, 0),
(@PATH, 5, 7228.421, -4123.6147, 98.5907, NULL, 0),
(@PATH, 6, 7223.507, -4117.3027, 102.05774, NULL, 0),
(@PATH, 7, 7220.033, -4107.6895, 105.14824, NULL, 7088),
(@PATH, 8, 7220.0835, -4104.0693, 106.351685, NULL, 0);

-- Path Halduron
SET @ENTRY := 240715;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Halduron Brightwing - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 7288.2744, -4145.8315, 89.09489, NULL, 0),
(@PATH, 1, 7268.6416, -4141.3853, 87.11374, NULL, 0),
(@PATH, 2, 7263.4385, -4135.4443, 86.96283, NULL, 0),
(@PATH, 3, 7258.6953, -4130.4517, 88.48486, NULL, 0),
(@PATH, 4, 7252.2163, -4126.356, 91.45217, NULL, 0),
(@PATH, 5, 7243.7466, -4125.0034, 94.81014, NULL, 0),
(@PATH, 6, 7235.979, -4123.9946, 97.07729, NULL, 0),
(@PATH, 7, 7222.3403, -4121.033, 100.96966, NULL, 0),
(@PATH, 8, 7218.5723, -4116.618, 102.97466, NULL, 0),
(@PATH, 9, 7215.1895, -4109.369, 104.89932, NULL, 5251),
(@PATH, 10, 7220.5703, -4103.2153, 106.615486, NULL, 0);

-- Gob Template
DELETE FROM `gameobject_template` WHERE `entry` IN (584262 /*Cushion*/, 626905 /*Cushion*/, 584261 /*Cushion*/, 584274 /*Chair*/, 573007 /*Chair*/, 584281 /*Bench*/, 584644 /*Chair*/, 573006 /*Chair*/, 627029 /*627029*/, 627044 /*627044*/, 584227 /*Chair*/, 584271 /*Chair*/, 582089 /*Bench*/, 573001 /*Chair*/, 584267 /*Chair*/, 573009 /*Chair*/, 584248 /*Cushion*/, 584226 /*Chair*/, 547520 /*Runestone*/, 626900 /*Cushion*/, 573008 /*Chair*/, 584648 /*Chair*/, 626898 /*Cushion*/, 570257 /*Umbric's Laboratory*/, 587067 /*Orb of Translocation*/, 584286 /*Bench*/, 573005 /*Chair*/, 573004 /*Chair*/, 584285 /*Bench*/, 584646 /*Chair*/, 584251 /*Cushion*/, 584645 /*Chair*/, 582090 /*Orb of Translocation*/, 584259 /*Bench*/, 584272 /*Chair*/, 526992 /*Orb of Translocation*/, 584247 /*Chair*/, 526989 /*Orb of Translocation*/, 573678 /*Cushion*/, 587068 /*Orb of Translocation*/, 584124 /*Bench*/, 573002 /*Chair*/, 526991 /*Orb of Translocation*/, 526990 /*Orb of Translocation*/, 560856 /*Runestone*/, 626819 /*Orb of Translocation*/, 587646 /*Orb of Translocation*/, 584283 /*Bench*/, 627045 /*627045*/, 626899 /*Cushion*/, 554869 /*Anvil*/, 639448 /*Orb of Translocation*/, 584284 /*Bench*/, 626903 /*Cushion*/, 584237 /*Cushion*/, 584126 /*Bench*/, 584268 /*Chair*/, 584249 /*Cushion*/, 555879 /*Orb of Translocation*/, 626901 /*Cushion*/, 621909 /*Mailbox*/, 526987 /*Orb of Translocation*/, 584282 /*Bench*/, 584125 /*Bench*/, 582091 /*Orb of Translocation*/, 584647 /*Chair*/, 584790 /*Orb of Translocation*/, 639447 /*Orb of Translocation*/, 584273 /*Chair*/, 554868 /*Forge*/, 584250 /*Cushion*/, 584269 /*Chair*/, 573000 /*Chair*/, 526988 /*Orb of Translocation*/, 494914 /*Orb of Translocation*/, 584228 /*Chair*/, 626902 /*Cushion*/, 626820 /*Orb of Translocation*/, 573003 /*Chair*/, 572494 /*Dropped Sword*/, 527211 /*Hiding Spot*/, 578273 /*Delivery Crate*/, 619649 /*Vista Point*/, 619648 /*Vista Point*/, 544167 /*Grappling Hook Rope*/, 527187 /*Hiding Bush*/, 617534 /*Gilded Armillary Sphere*/, 537181 /*Lightbloom Plant*/, 544171 /*Grappling Hook Rope*/, 619621 /*Vista Point*/, 529610 /*Lightbloom Feather*/, 520359 /*Smuggled Cargo*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(584262, 7, 99999, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(626905, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584261, 7, 99999, 'Cushion', '', '', '', 1.279999971389770507, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584274, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(573007, 7, 96998, 'Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584281, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(584644, 7, 96998, 'Chair', '', '', '', 0.999999225139617919, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(573006, 7, 99278, 'Chair', '', '', '', 0.999999701976776123, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(627029, 0, 96998, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- 627029
(627044, 0, 96998, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- 627044
(584227, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584271, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(582089, 7, 96999, 'Bench', '', '', '', 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(573001, 7, 96998, 'Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584267, 7, 96998, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(573009, 7, 96998, 'Chair', '', '', '', 0.999999701976776123, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584248, 7, 99999, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584226, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(547520, 22, 106529, 'Runestone', 'questinteract', '', '', 1.5, 1245837, -1, 0, 0, 1, 18814, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Runestone
(626900, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(573008, 7, 96998, 'Chair', '', '', '', 0.999999701976776123, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584648, 7, 96998, 'Chair', '', '', '', 0.999999225139617919, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(626898, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(570257, 43, 112086, 'Umbric\'s Laboratory', '', '', '', 1, -1, 0, 13, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Umbric's Laboratory
(587067, 22, 98276, 'Orb of Translocation', '', '', '', 1, 1280643, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584286, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(573005, 7, 96998, 'Chair', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(573004, 7, 96998, 'Chair', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584285, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(584646, 7, 96998, 'Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584251, 7, 99999, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584645, 7, 96998, 'Chair', '', '', '', 0.999999284744262695, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(582090, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1278019, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584259, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(584272, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(526992, 22, 98276, 'Orb of Translocation', '', '', '', 1, 1280604, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584247, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(526989, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1280561, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(573678, 7, 99999, 'Cushion', '', '', '', 0.99999934434890747, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(587068, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1280644, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584124, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(573002, 7, 96998, 'Chair', '', '', '', 0.999999403953552246, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(526991, 22, 98276, 'Orb of Translocation', '', '', '', 1, 1280613, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(526990, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1280559, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(560856, 56, 106529, 'Runestone', 'questinteract', '', '', 1.439999938011169433, 0, 106529, 1, 896, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Runestone
(626819, 22, 98276, 'Orb of Translocation', 'questinteract', '', '', 0.999999761581420898, 1280099, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(587646, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1280638, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584283, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(627045, 0, 96998, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- 627045
(626899, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(554869, 8, 104963, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 103828, 0, 30091, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Anvil
(639448, 22, 98276, 'Orb of Translocation', '', '', '', 0.999999761581420898, 1280102, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584284, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(626903, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584237, 7, 99999, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584126, 7, 96999, 'Bench', '', '', '', 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(584268, 7, 96998, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584249, 7, 99999, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(555879, 22, 98276, 'Orb of Translocation', 'questinteract', '', '', 0.999999582767486572, 1280017, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(626901, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(621909, 19, 108516, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Mailbox
(526987, 22, 98276, 'Orb of Translocation', '', '', '', 1, 1280614, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584282, 7, 97001, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(584125, 7, 96999, 'Bench', '', '', '', 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Bench
(582091, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1278020, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584647, 7, 99278, 'Chair', '', '', '', 0.999999403953552246, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(584790, 22, 97121, 'Orb of Translocation', '', '', '', 1, 1280637, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(639447, 22, 98276, 'Orb of Translocation', '', '', '', 0.999999821186065673, 1280099, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584273, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(554868, 8, 107879, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 103829, 0, 30092, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Forge
(584250, 7, 99999, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(584269, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(573000, 7, 96998, 'Chair', '', '', '', 0.999999463558197021, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(526988, 22, 98276, 'Orb of Translocation', '', '', '', 1, 1280603, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(494914, 22, 98276, 'Orb of Translocation', 'questinteract', '', '', 0.999999821186065673, 1280167, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(584228, 7, 99278, 'Chair', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(626902, 7, 100004, 'Cushion', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Cushion
(626820, 22, 98276, 'Orb of Translocation', 'questinteract', '', '', 0.999999463558197021, 1280102, -1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Orb of Translocation
(573003, 7, 99278, 'Chair', '', '', '', 0.999999523162841796, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66838), -- Chair
(572494, 10, 112651, 'Dropped Sword', 'interact', 'Drinking', '', 1, 4191, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1252113, 0, 0, 1, 21295, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Dropped Sword
(527211, 10, 103490, 'Hiding Spot', 'questinteract', 'Investigating', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1258785, 0, 0, 1, 178675, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Hiding Spot
(578273, 10, 74555, 'Delivery Crate', 'questinteract', 'Picking Up', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1256721, 0, 0, 1, 125962, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Delivery Crate
(619649, 10, 74696, 'Vista Point', 'openhandglow', '', '', 1, 1635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1275626, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 150324, 0, 7463, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 66838), -- Vista Point
(619648, 10, 74696, 'Vista Point', 'openhandglow', '', '', 1, 1635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1275626, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 150323, 0, 7462, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 66838), -- Vista Point
(544167, 10, 96428, 'Grappling Hook Rope', 'questinteract', 'Using', '', 1, 2173, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1236346, 0, 0, 1, 19700, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Grappling Hook Rope
(527187, 10, 103660, 'Hiding Bush', 'questinteract', 'Investigating', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1258791, 0, 0, 1, 178675, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Hiding Bush
(617534, 3, 114177, 'Gilded Armillary Sphere', '', 'Collecting', '', 0.75, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 257503, 0, 0, 0, 0, 0, 32768, 0, 0, 0, 0, 0, 1241120, 0, 0, 7429, 137771, 0, 0, 0, 0, 80, 3085, 66838), -- Gilded Armillary Sphere
(537181, 5, 105226, 'Lightbloom Plant', '', '', '', 0.200000002980232238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Lightbloom Plant
(544171, 10, 96428, 'Grappling Hook Rope', 'questinteract', 'Using', '', 1, 2173, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1236346, 0, 0, 1, 19700, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Grappling Hook Rope
(619621, 10, 74696, 'Vista Point', 'openhandglow', '', '', 1, 1635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1275626, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 150320, 0, 7460, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 66838), -- Vista Point
(529610, 5, 69362, 'Lightbloom Feather', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838), -- Lightbloom Feather
(520359, 10, 35827, 'Smuggled Cargo', 'questinteract', 'Destroying', '', 1.5, 99, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1232900, 0, 0, 1, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 3085, 66838); -- Smuggled Cargo
