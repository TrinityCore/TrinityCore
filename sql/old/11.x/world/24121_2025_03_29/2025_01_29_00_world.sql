SET @CGUID := 10005731;
SET @NPCTEXTID := 600083;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 236055, 2552, 14771, 15044, '0', 25497, 0, 0, 0, 2932.459228515625, -2410.5556640625, 266.3282470703125, 5.356359481811523437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680), -- Chief Officer Hammerflange (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+1, 232132, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2933.677001953125, -2412.3369140625, 266.635772705078125, 2.361375808715820312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680), -- Dawn (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+2, 231110, 2552, 14771, 15044, '0', 0, 0, 0, 0, 2935.595458984375, -2411.2275390625, 266.635772705078125, 2.535473108291625976, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680), -- Saradi (Area: Foundation Hall - Difficulty: 0) CreateObject1 (Auras: 458385 - [DNT] Female Earthen/Dwarf Taking Notes)
(@CGUID+3, 234231, 2552, 14771, 15044, '0', 25497, 0, 0, 1, 2932.697998046875, -2408.795166015625, 266.398193359375, 5.322963237762451171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680), -- Zeppelin Engineer (Area: Foundation Hall - Difficulty: 0) CreateObject1
(@CGUID+4, 234986, 2552, 14771, 15044, '0', 25497, 0, 0, 1, 2930.767333984375, -2410.770751953125, 266.403076171875, 5.554956436157226562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58680); -- Greasemonkey Surveyor (Area: Foundation Hall - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = 10005252;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(10005252, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1216769'); -- 236055 (Chief Officer Hammerflange) - Cooking

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (234986 /*234986 (Greasemonkey Surveyor)*/, 234231 /*234231 (Zeppelin Engineer)*/, 236055 /*236055 (Chief Officer Hammerflange)*/, 231110 /*231110 (Saradi) - [DNT] Female Earthen/Dwarf Taking Notes*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(234986, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 234986 (Greasemonkey Surveyor)
(234231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 234231 (Zeppelin Engineer)
(236055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 236055 (Chief Officer Hammerflange)
(231110, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '458385'); -- 231110 (Saradi) - [DNT] Female Earthen/Dwarf Taking Notes

-- Template
UPDATE `creature_template` SET `faction`=3415, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=234986; -- Greasemonkey Surveyor
UPDATE `creature_template` SET `faction`=3438, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=232132; -- Dawn
UPDATE `creature_template` SET `faction`=3415, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=234231; -- Zeppelin Engineer
UPDATE `creature_template` SET `faction`=3438, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231110; -- Saradi

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58680 WHERE (`Entry`=234986 AND `DifficultyID`=0); -- 234986 (Greasemonkey Surveyor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58680 WHERE (`Entry`=234231 AND `DifficultyID`=0); -- 234231 (Zeppelin Engineer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58680 WHERE (`Entry`=231110 AND `DifficultyID`=0); -- 231110 (Saradi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58680 WHERE (`Entry`=232132 AND `DifficultyID`=0); -- 232132 (Dawn) - CanSwim

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` = @CGUID+0;
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+0, 0, (0x10000000), NULL, NULL, NULL, NULL, NULL, NULL, NULL);


-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 25497;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14771, 25497, 'See Goblins infront of Dawn in the Foundation Hall');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25497 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25497, 0, 0, 0, 47, 0, 84719, 2|8|64, 0, 1, 'Apply Phase 25497 if Quest 84719 is not taken | complete | rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=27051;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(27051, 73939, 0, 58680);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_dawn_accept_the_expedition_awaits' WHERE `Id` = 27051;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=27051 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(27051, 102192, (@CGUID+1), 0, 0, 0, 0, 0, 58680); -- Full: 0x203AF13F00E2B10000305200001551B4 Creature/0 R3772/S12370 Map: 2552 (Khaz Algar (Surface)) Entry: 232132 (Dawn) Low: 1397172

DELETE FROM `conversation_line_template` WHERE `Id`=73939;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(73939, 0, 0, 0, 0, 58680);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (234231, 234986, 236055);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(234231, 0, 0, 'It\'s about time!', 12, 0, 100, 4, 0, 0, 171116, 0, 'Zeppelin Engineer to Player'),
(234986, 0, 0, 'Yea, yea. We know! We know!', 12, 0, 100, 274, 0, 0, 146818, 0, 'Greasemonkey Surveyor to Player'),
(236055, 0, 0, 'Finally, some excitement!', 12, 0, 100, 4, 0, 0, 156121, 0, 'Chief Officer Hammerflange to Player'),
(236055, 1, 0, 'Well, what are you waiting for?', 12, 0, 100, 25, 0, 0, 0, 0, 'Chief Officer Hammerflange to Player'),
(236055, 2, 0, 'Let\'s get moving!', 12, 0, 100, 25, 0, 0, 153564, 0, 'Chief Officer Hammerflange to Player');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=232132 AND `MenuID`=37152);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(232132, 37152, 58680); -- Dawn

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 276801, 0, 0, 0, 0, 0, 0, 0, 58680), -- 232132 (Dawn)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 276804, 0, 0, 0, 0, 0, 0, 0, 58680); -- 232132 (Dawn)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37152 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37155 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37152, @NPCTEXTID+0, 58680), -- 232132 (Dawn)
(37155, @NPCTEXTID+1, 58680); -- 232132 (Dawn)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37152 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37152, 125333, 0, 0, 'Who are you?', 25092, 0, 0, 37155, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58680); -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=232132 AND `quest`=84719);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(232132, 84719, 58680); -- The Expedition Awaits offered by Dawn

DELETE FROM `creature_questender` WHERE (`id`=230235 AND `quest`=84719);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(230235, 84719, 58680); -- The Expedition Awaits ended by Skaggit

-- Dawn smart ai
SET @ENTRY := 232132;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 84719, 0, 0, 0, 0, 143, 27051, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest The Expedition Awaits (84719) - Player who accepted quest: Start conversation (27051) Actors<> (first line 73939)', ''),
(@ENTRY, 0, 1, 0, 60, 0, 100, 0, 5000, 5000, 5000, 5000, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds - Self: Play emote 1', '');

-- Chief Officer Hammerflange smart ai
SET @ENTRY := 236055;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23605500, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Chief Officer Hammerflange #0 (23605500) (update out of combat)', '');

-- Chief Officer Hammerflange smart ai
SET @ENTRY := -10005252;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 1216769, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 1216769 on self', '');

-- Greasemonkey Surveyor smart ai
SET @ENTRY := 234986;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23498600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Greasemonkey Surveyor #0 (23498600) (update out of combat)', '');

-- Greasemonkey Surveyor smart ai
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(-(@CGUID+4), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 1000, 4000, 0, 10, 4, 274, 1, 5, 6, 1005, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time between 1 - 4 seconds (OOC) - Self: Play random emote: 4, 274, 1, 5, 6, 1005', '');

-- Zeppelin Engineer smart ai
SET @ENTRY := 234231;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23423100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Zeppelin Engineer #0 (23423100) (update out of combat)', '');

-- Zeppelin Engineer smart ai
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(-(@CGUID+3), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 1000, 4000, 0, 10, 6, 5, 274, 1005, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time between 1 - 4 seconds (OOC) - Self: Play random emote: 4, 274, 1, 5, 6, 1005', '');

-- Timed list 23605500 smart ai
SET @ENTRY := 23605500;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 2 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.28638, 'After 0 seconds - Self: Set orientation to 2.28638', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Remove rooted', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Disable gravity', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 23605500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #23605500, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 12000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 12 s', '');

-- Timed list 23423100 smart ai
SET @ENTRY := 23423100;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 53, 0, 23423100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Start path #23423100, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 10 s', '');

-- Timed list 23498600 smart ai
SET @ENTRY := 23498600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 53, 0, 23498600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #23498600, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 10 s', '');

-- Path for Chief Officer Hammerflange
SET @ENTRY := 236055;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Chief Officer Hammerflange - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2926.7683, -2410.2683, 266.33633, NULL, 0),
(@PATH, 1, 2920.7683, -2409.0183, 266.33633, NULL, 0),
(@PATH, 2, 2912.0183, -2410.5183, 266.33633, NULL, 0),
(@PATH, 3, 2903.2683, -2417.2683, 266.33633, NULL, 0),
(@PATH, 4, 2893.7683, -2425.0183, 266.83633, NULL, 0),
(@PATH, 5, 2881.2683, -2440.0183, 266.58633, NULL, 0),
(@PATH, 6, 2876.0774, -2448.981, 266.76108, NULL, 0);

-- Path for Zeppelin Engineer
SET @ENTRY := 234231;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Zeppelin Engineer - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2930.2622, -2407.7144, 266.32672, NULL, 0),
(@PATH, 1, 2920.2622, -2404.4644, 266.32672, NULL, 0),
(@PATH, 2, 2908.0122, -2405.4644, 266.57672, NULL, 0),
(@PATH, 3, 2896.2622, -2413.4644, 266.32672, NULL, 0),
(@PATH, 4, 2886.0122, -2424.7144, 266.82672, NULL, 0),
(@PATH, 5, 2875.2622, -2435.2144, 266.57672, NULL, 0),
(@PATH, 6, 2870.5122, -2441.4644, 266.82672, NULL, 0),
(@PATH, 7, 2870.3264, -2445.1338, 266.67188, NULL, 0);

-- Path for Seamonkey Surveyor
SET @ENTRY := 234986;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Greasemonkey Surveyor - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2926.6724, -2410.126, 266.37375, NULL, 0),
(@PATH, 1, 2920.6724, -2409.126, 266.37375, NULL, 0),
(@PATH, 2, 2911.9224, -2410.626, 266.37375, NULL, 0),
(@PATH, 3, 2903.4224, -2417.376, 266.37375, NULL, 0),
(@PATH, 4, 2893.6724, -2424.876, 266.62375, NULL, 0),
(@PATH, 5, 2881.4224, -2439.876, 266.62375, NULL, 0),
(@PATH, 6, 2876.0774, -2448.981, 266.76108, NULL, 0);
