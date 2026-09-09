SET @CGUID := 11000832;

SET @NPCTEXTID := 610033;

SET @ATID := 36658;  -- type 19 AT
SET @ATIDSPAWN := 289;
SET @ATCP := 179;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 237330, 2694, 15355, 15922, '0', 26250, 0, 0, 0, -89.7586822509765625, -2128.70654296875, 1172.3935546875, 2.169950008392333984, 120, 0, 0, 0, NULL, NULL, 0x4000800 | 0x00000001, 0xC1000000 | 0x00002000, 67314), -- Frenzied Potatoad (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+1, 237209, 2694, 15355, 15922, '0', 26040, 0, 0, 0, -85.4479141235351562, -2129.31591796875, 1172.132080078125, 3.595875740051269531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Ku'paal (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 239522, 2694, 15355, 15922, '0', 26040, 0, 0, 1, -94.3246536254882812, -2131.444580078125, 1172.8468017578125, 0.607648670673370361, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314), -- Orweyna (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+3, 237858, 2694, 15355, 15922, '0', 26040, 0, 0, 1, -92.3871536254882812, -2128.236083984375, 1172.451171875, 0.553854405879974365, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 67314); -- Halduron Brightwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Frenzied Potatoad
(@CGUID+1, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Ku'paal

UPDATE `creature` SET `StringId` = 'CloneTarget' WHERE `guid` IN (@CGUID+2,@CGUID+3,@CGUID+1);
UPDATE `creature` SET `curHealthPct` = 30 WHERE `guid` = (@CGUID+1);

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2694, '0', -89.931511, -2131.186523, 1172.813232, 2.760301, 0, 26040, 0, 'SmartAreaTriggerAI', 'Harandar - Trigger Conversation 28470 for Ku''paal', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, '', 0); 

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (239522 /*239522 (Orweyna)*/, 237858 /*237858 (Halduron Brightwing)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(239522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 239522 (Orweyna)
(237858, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 237858 (Halduron Brightwing)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800, `RegenHealth` = 0 WHERE `entry`=237209; -- Ku'paal
UPDATE `creature_template` SET `faction`=14, `speed_run`=1.269841432571411132, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags2`=0x4000800, `unit_flags3`=0xC1000000 WHERE `entry`=237330; -- Frenzied Potatoad
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=239522; -- Orweyna
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=237858; -- Halduron Brightwing

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=237209 AND `DifficultyID`=0); -- 237209 (Ku'paal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x20000100, `StaticFlags5`=0x1, `VerifiedBuild`=67314 WHERE (`Entry`=237330 AND `DifficultyID`=0); -- 237330 (Frenzied Potatoad) - Sessile, Floating - UntargetableByClient
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=239522 AND `DifficultyID`=0); -- 239522 (Orweyna) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3313, `StaticFlags1`=0x10000000, `VerifiedBuild`=67314 WHERE (`Entry`=237858 AND `DifficultyID`=0); -- 237858 (Halduron Brightwing) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (26250,26040);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(26250, 'Cosmetic - See dead Frenzied Potatoad at the Road'),
(26040, 'Cosmetic - See Halduron, Orweyna and Ku''paal at the Road');

DELETE FROM `phase_area` WHERE `PhaseId` IN (26250,26040);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15355, 26250, 'See dead Frenzied Potatoad at the Road'),
(15355, 26040, 'See Halduron, Orweyna and Ku''paal at the Road');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (26250,26040) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 26250, 0, 0, 0, 47, 0, 86900, 2|8|64, 0, 0, 'Apply Phase 26250 if Quest 86900 is complete|in progress|rewarded'),
(26, 26040, 0, 0, 0, 47, 0, 86900, 2|8|64, 0, 0, 'Apply Phase 26040 if Quest 86900 is in progress'),
(26, 26040, 0, 0, 0, 48, 0, 458762, 0, 1, 1, 'Apply Phase 26040 if Questobjective 458762 is not rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (29598,28470,29720);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(29598, 81739, 0, 67314),
(28470, 92057, 0, 67602),
(29720, 82118, 0, 67602);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_to_harathir_follow_orweyna' WHERE `Id` = 29598;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_to_harathir_talk_to_kupaal' WHERE `Id` = 29720;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=29598 AND `Idx` IN (1,0)) OR (`ConversationId`=28470 AND `Idx` IN (1,0)) OR (`ConversationId`=29720 AND `Idx` IN (0,1));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGUID`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(29598, 107891, 0, 1, 0, 0, 0, 0, 67314), -- Full: 0x20423150C0E84880002B56000078BCBD Creature/0 R4236/S11094 Map: 2694 (Harandar) Entry: 237858 (Halduron Brightwing) Low: 7912637
(29598, 105508, 0, 0, 0, 0, 0, 0, 67314), -- Full: 0x20423150C0E9E880002B56000078BCBD Creature/0 R4236/S11094 Map: 2694 (Harandar) Entry: 239522 (Orweyna) Low: 7912637
(28470, 105511, (@CGUID+1), 1, 0, 0, 0, 0, 67602), -- Full: 0x203CDD50C0E7A6400023CA0000104E53 Creature/0 R3895/S9162 Map: 2694 (Harandar) Entry: 237209 (Ku'paal) Low: 1068627
(28470, 0, 0, 0, 0, 0, 0, 1, 67602), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775
(29720, 105508, 0, 0, 0, 0, 0, 0, 67602), -- Full: 0x203CDD50C0E9E8800023CA0000105DBA Creature/0 R3895/S9162 Map: 2694 (Harandar) Entry: 239522 (Orweyna) Low: 1072570
(29720, 105511, 0, 1, 0, 0, 0, 0, 67602); -- Full: 0x203CDD50C0E7A6400023CA0000105DBA Creature/0 R3895/S9162 Map: 2694 (Harandar) Entry: 237209 (Ku'paal) Low: 1072570

DELETE FROM `conversation_line_template` WHERE `Id` IN (81740, 81739, 78355, 92057, 82119, 82117, 82118);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(81740, 0, 1, 0, 0, 67314),
(81739, 0, 0, 0, 0, 67314),
(78355, 0, 1, 0, 0, 67602),
(92057, 0, 0, 0, 0, 67602),
(82119, 0, 0, 0, 0, 67602),
(82117, 0, 1, 0, 0, 67602),
(82118, 0, 0, 0, 0, 67602);

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (458763,458762);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(458763, NULL, NULL, 28470, 0, 0),
(458762, NULL, NULL, 29720, 1, 0);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=237209 AND `MenuID`=38392);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(237209, 38392, 67602); -- Ku'paal

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 283411, 0, 0, 0, 0, 0, 0, 0, 67602), -- 237209 (Ku'paal)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 290548, 0, 0, 0, 0, 0, 0, 0, 67602); -- 237209 (Ku'paal)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38391 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=38392 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38391, @NPCTEXTID+0, 67602), -- 237209 (Ku'paal)
(38392, @NPCTEXTID+1, 67602); -- 237209 (Ku'paal)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=38392 AND `OptionID` IN (1,0)) OR (`MenuID`=38391 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(38392, 132536, 1, 0, 'Who are you?', 25092, 0, 0, 38391, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 67602), -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837 - 263541 - 298152
(38392, 132537, 0, 0, 'We are friends of Orweyna and we are here to help.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 67602),
(38391, 132866, 0, 0, 'I want to ask something else.', 61781, 0, 0, 38392, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 67602); -- OptionBroadcastTextID: 61781 - 121489 - 152386 - 157767 - 171009

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (38392));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 38392, 0, 0, 0, 48, 0, 458763, 0, 1, '', 0, 'Player for which gossip text is shown has quest objective 458763 == 1 (but hasn\'t rewarded quest yet)'),
(15, 38392, 0, 0, 0, 48, 0, 458762, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 458762 < 1 or has rewarded the quest'),
(15, 38392, 0, 0, 0, 47, 0, 86900, 8, 0, '', 0, 'Player for which gossip text is shown has To Har\'athir (86900) in state incomplete');

-- Orweyna smart ai
SET @ENTRY := 237480;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 19, 0, 100, 0, 86900, 0, 0, 0, 0, 143, 29598, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest To Har\'athir (86900) - Player who accepted quest: Start conversation (29598) Actors<> (first line 81739)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest To Har\'athir (86900) - Player who accepted quest: Cast spell 82238 on self', '');

-- Orweyna smart ai
SET @ENTRY := 239522;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23952200, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Orweyna #0 (23952200) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 24, 23952200, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 24 of path 23952200 ended - Self: Despawn instantly', ''),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 1, 23952201, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 23952201 ended - Self: Despawn instantly', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 239522 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 239522, 0, 0, 58, 1, 0, 0, 0, 'Cave', 0, 'Object has StringID Cave');

-- Halduron Brightwing smart ai
SET @ENTRY := 237858;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23785800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start timed action list id #Halduron Brightwing #0 (23785800) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 24, 23785800, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 24 of path 23785800 ended - Self: Despawn instantly', ''),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 1, 23785801, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 23785801 ended - Self: Despawn instantly', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 237858 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 237858, 0, 0, 58, 1, 0, 0, 0, 'Cave', 0, 'Object has StringID Cave');

-- Timed list 23952200 smart ai
SET @ENTRY := 23952200;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.6076487, 'After 1 seconds - Self: Set orientation to 0.6076487', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 23952200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #23952200, walk, do not repeat, Passive', '');

-- Timed list 23785800 smart ai
SET @ENTRY := 23785800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.5538544, 'After 1 seconds - Self: Set orientation to 0.5538544', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 53, 0, 23785800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Start path #23785800, walk, do not repeat, Passive', '');

-- Ku'paal smart ai
SET @ENTRY := 237209;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 38392, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 38392 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 237209, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 38392 selected - Gossip player: Give kill credit Ku\'paal (237209)', ''),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 1, 23720900, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 23720900 ended - Self: Despawn instantly', '');

-- Path for Orweyna
SET @ENTRY := 239522;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Orweyna - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -174.77333, -2147.8672, 1177.1106, NULL, 0),
(@PATH, 1, -173.27333, -2148.1172, 1176.6106, NULL, 0),
(@PATH, 2, -172.77333, -2148.1172, 1176.6106, NULL, 0),
(@PATH, 3, -169.77333, -2147.6172, 1176.3606, NULL, 0),
(@PATH, 4, -163.77333, -2146.3672, 1176.3606, NULL, 0),
(@PATH, 5, -161.02333, -2145.6172, 1176.1106, NULL, 0),
(@PATH, 6, -159.02333, -2145.1172, 1175.8606, NULL, 0),
(@PATH, 7, -155.02333, -2144.3672, 1175.6106, NULL, 0),
(@PATH, 8, -152.27333, -2143.8672, 1175.3606, NULL, 0),
(@PATH, 9, -149.27333, -2143.1172, 1175.1106, NULL, 0),
(@PATH, 10, -142.27333, -2141.6172, 1175.1106, NULL, 0),
(@PATH, 11, -135.77333, -2140.1172, 1174.8606, NULL, 0),
(@PATH, 12, -132.02333, -2139.6172, 1174.8606, NULL, 0),
(@PATH, 13, -128.02333, -2138.6172, 1174.6106, NULL, 0),
(@PATH, 14, -125.02333, -2138.1172, 1174.3606, NULL, 0),
(@PATH, 15, -122.02333, -2137.3672, 1174.1106, NULL, 0),
(@PATH, 16, -119.27333, -2136.8672, 1173.8606, NULL, 0),
(@PATH, 17, -117.27333, -2136.3672, 1173.6106, NULL, 0),
(@PATH, 18, -112.27333, -2135.3672, 1173.3606, NULL, 0),
(@PATH, 19, -109.52333, -2134.6172, 1173.3606, NULL, 0),
(@PATH, 20, -107.52333, -2134.3672, 1173.1106, NULL, 0),
(@PATH, 21, -102.52333, -2133.3672, 1172.8606, NULL, 0),
(@PATH, 22, -99.77333, -2132.6172, 1173.1106, NULL, 0),
(@PATH, 23, -95.77333, -2131.8672, 1173.3606, NULL, 0),
(@PATH, 24, -94.32465, -2131.4446, 1172.8811, NULL, 0);

-- Path for Orweyna
SET @ENTRY := 239522;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Orweyna - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -88.33681, -2110.2153, 1169.7644, NULL, 0),
(@PATH, 1, -64.58507, -2089.611, 1167.1196, NULL, 0);

-- Path for Halduron
SET @ENTRY := 237858;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Halduron Brightwing - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -173.42258, -2152.238, 1177.1841, NULL, 0),
(@PATH, 1, -171.67258, -2150.738, 1176.6841, NULL, 0),
(@PATH, 2, -169.67258, -2150.238, 1176.4341, NULL, 0),
(@PATH, 3, -163.92258, -2148.488, 1176.1841, NULL, 0),
(@PATH, 4, -161.17258, -2147.738, 1176.1841, NULL, 0),
(@PATH, 5, -157.17258, -2146.738, 1175.9341, NULL, 0),
(@PATH, 6, -155.17258, -2145.988, 1175.6841, NULL, 0),
(@PATH, 7, -153.42258, -2145.488, 1175.4341, NULL, 0),
(@PATH, 8, -149.42258, -2144.488, 1175.1841, NULL, 0),
(@PATH, 9, -142.67258, -2142.488, 1174.9341, NULL, 0),
(@PATH, 10, -136.92258, -2140.988, 1174.9341, NULL, 0),
(@PATH, 11, -131.42258, -2139.488, 1174.6841, NULL, 0),
(@PATH, 12, -127.67258, -2138.488, 1174.6841, NULL, 0),
(@PATH, 13, -125.67258, -2137.738, 1174.4341, NULL, 0),
(@PATH, 14, -123.92258, -2137.238, 1174.1841, NULL, 0),
(@PATH, 15, -120.92258, -2136.488, 1173.9341, NULL, 0),
(@PATH, 16, -117.17258, -2135.238, 1173.6841, NULL, 0),
(@PATH, 17, -112.17258, -2133.988, 1173.4341, NULL, 0),
(@PATH, 18, -110.42258, -2133.488, 1173.1841, NULL, 0),
(@PATH, 19, -108.42258, -2132.988, 1172.9341, NULL, 0),
(@PATH, 20, -105.67258, -2131.988, 1172.6841, NULL, 0),
(@PATH, 21, -102.67258, -2131.238, 1172.4341, NULL, 0),
(@PATH, 22, -99.92258, -2130.488, 1172.6841, NULL, 0),
(@PATH, 23, -95.92258, -2129.238, 1172.9341, NULL, 0),
(@PATH, 24, -92.38715, -2128.236, 1172.368, NULL, 0);

-- Path for Halduron
SET @ENTRY := 237858;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Halduron Brightwing - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -86.38368, -2110.2917, 1169.7943, NULL, 0),
(@PATH, 1, -70.71181, -2095.1458, 1167.9006, NULL, 0);

-- Path for Kupaal
SET @ENTRY := 237209;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ku''paal - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -93.96875, -2116.7744, 1170.547, NULL, 0),
(@PATH, 1, -65.16493, -2090.8074, 1167.2648, NULL, 0);
