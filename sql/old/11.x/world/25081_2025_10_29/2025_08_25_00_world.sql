SET @CGUID := 10006798;
SET @OGUID := 10001694;

SET @GOB_ENTRY := 10000000;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233187, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1302.4739990234375, -885.94793701171875, -126.032546997070312, 1.051946163177490234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62706), -- Data Collection Drone (Area: The Oasis - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 233187, 2738, 15336, 15792, '0', 0, 0, 0, 0, 1227.921142578125, -844.20733642578125, -124.653602600097656, 4.836744308471679687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62706); -- Data Collection Drone (Area: The Oasis - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 516786, 2738, 15336, 15792, '0', 0, 0, 1297.3524169921875, -759.8367919921875, -137.005340576171875, 0, 0, 0, 0, 1, 120, 255, 1, 62706), -- Torn-up Earth (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+1, 516792, 2738, 15336, 15792, '0', 0, 0, 1394.41845703125, -803.27777099609375, -139.8629150390625, 0, 0, 0, 0, 1, 120, 255, 1, 62706), -- Watering Jug (Area: The Oasis - Difficulty: 0) CreateObject1
(@OGUID+2, @GOB_ENTRY, 2738, 15336, 15792, '0', 0, 0, 1412.061523, -800.647034, -138.438431, 0, 0, 0, 0, 1, 120, 255, 1, 62706); -- K'areshi Plant (Area: The Oasis - Difficulty: 0)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=17196646400, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x20 WHERE `entry`=233187; -- Data Collection Drone

DELETE FROM `gameobject_template` WHERE `entry` = @GOB_ENTRY;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(@GOB_ENTRY, 8, 0, 'K''areshi Plant', '', '', '', 1, 2222, 10, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -62706); -- K'areshi Plant (Spellfocus)

DELETE FROM `gameobject_template` WHERE `entry` IN (516792 /*Watering Jug*/, 516786 /*Torn-up Earth*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(516792, 3, 97887, 'Watering Jug', 'questinteract', '', '', 1, 2124, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130842, 0, 0, 0, 0, 3007, 62706), -- Watering Jug
(516786, 10, 75129, 'Torn-up Earth', 'questinteract', 'Leveling earth.', '', 3, 3723, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 469881, 0, 0, 0, 276309, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62706); -- Torn-up Earth

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (233187));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(233187, 0, 10, 1, 1, 284677, 0x0, 0, 0); -- Data Collection Drone

UPDATE `creature_template_difficulty` SET `ContentTuningID`=3007, `VerifiedBuild`=62706 WHERE (`Entry`=233187 AND `DifficultyID`=0); -- 233187 (Data Collection Drone) - 

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=28311;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(28311, 77832, 0, 62706);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=28311 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(28311, 102228, 10006795, 0, 0, 0, 0, 0, 62706); -- Full: 0x203ADD5640E26300002A89000025D9CB Creature/0 R3767/S10889 Map: 2738 (K'aresh) Entry: 231820 (Ve'nari) Low: 2480587

DELETE FROM `conversation_line_template` WHERE `Id` IN (77834, 77833, 77832);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(77834, 0, 0, 0, 0, 62706),
(77833, 0, 0, 0, 0, 62706),
(77832, 0, 0, 0, 0, 62706);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 233187;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(233187, 0, 0, 'Would you be interested in filling out a satisfaction survey about your interaction today?', 12, 0, 100, 1, 0, 0, 0, 5, 'Data Collection Drone to Player');

-- Loot
DELETE FROM `gameobject_loot_template` WHERE `Entry` = 130842;
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(130842, 0, 236641, 100, 1, 1, 0, 1, 1, 'Watering Jug');

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 233187;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(233187, 469827, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 18) AND (`SourceGroup` IN (233187));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(18, 233187, 469827, 0, 0, 47, 0, 87339, 8, 0, '', 0, 'Clicker has Ongoing Activities (87339) in state incomplete'),
(18, 233187, 469827, 0, 0, 48, 0, 457923, 0, 1, '', 1, 'Clicker hasn\'t quest objective 457923 < 1 or has rewarded the quest');

-- Quest
DELETE FROM `quest_request_items` WHERE `ID`=87339;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(87339, 0, 1, 0, 0, 'Have you been hard at work?', 0); -- Ongoing Activities

DELETE FROM `creature_questender` WHERE (`id`=231820 AND `quest`=87339);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(231820, 87339, 62706); -- Ongoing Activities ended by Ve'nari

-- Spawntracking
DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2723099 /*Map: 2738 (K'aresh) - Phase: 0*/, 2723111 /*Map: 2738 (K'aresh) - Phase: 25276*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2723099, 2738, 0, 0, 0, 62706), -- Map: 2738 (K'aresh) - Phase: 0
(2723111, 2738, 0, 0, 0, 62706); -- Map: 2738 (K'aresh) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2723099 AND `QuestObjectiveId`=457857) OR (`SpawnTrackingId`=2723111 AND `QuestObjectiveId`=457924);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2723099, 457857, 62706), -- 2723099
(2723111, 457924, 62706); -- 2723111

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveIds`) VALUES
(2723099, 1, @OGUID+0, 457857), -- Torn-up Earth
(2723111, 1, @OGUID+1, 457924); -- Watering Jug

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+0, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+0, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+0, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 0, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 2, 0, NULL, NULL, NULL, NULL);

-- Ve'nari smart ai
SET @ENTRY := 231820;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 87339, 0, 0, 0, 0, 143, 28311, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Ongoing Activities (87339) - Player who accepted quest: Start conversation 28311', '');

-- Data Collection Drone smart ai
SET @ENTRY := 233187;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 0, 54, 60000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Self: Pause path for 60000 ms', ''),
(@ENTRY, 0, 1, 2, 8, 0, 100, 0, 469827, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  469827 hit - Self: Look at Caster', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  469827 hit - Caster: Talk 0 to invoker', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 244059, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  469827 hit - Caster: Give kill credit Kill Credit  (244059)', '');

-- Path for Data Collection Drone
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 233187;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Data Collection Drone - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1227.5354, -841.25183, -124.14137, NULL, 8328),
(@PATH, 1, 1223.7646, -880.0996, -123.935776, NULL, 28023),
(@PATH, 2, 1235.9968, -882.0809, -123.70522, NULL, 8376);

UPDATE `creature` SET `position_x`=1227.5354, `position_y`=-841.25183, `position_z`=-124.14137, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Data Collection Drone
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 233187;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Data Collection Drone - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1317.0851, -853.60815, -127.79284, NULL, 17915),
(@PATH, 1, 1293.8005, -901.1426, -120.94093, NULL, 7988);

UPDATE `creature` SET `position_x`=1317.0851, `position_y`=-853.60815, `position_z`=-127.79284, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
