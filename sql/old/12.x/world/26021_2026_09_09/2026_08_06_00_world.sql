SET @CGUID := 11000836;

SET @NPCTEXTID := 610035;

SET @ATID := 189;
SET @ATIDSPAWN := 291;
SET @ATCP := 181;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 237865, 2694, 15355, 15922, '0', 27835, 0, 0, 0, -120.217018127441406, -2057.201416015625, 1155.1209716796875, 4.649010181427001953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68974), -- Danul (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+1, 237866, 2694, 15355, 15922, '0', 26533, 0, 0, 0, -9.88194465637207031, -2189.807373046875, 1178.2591552734375, 2.179077863693237304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68974), -- Oorla (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1
(@CGUID+2, 237210, 2694, 15355, 15922, '0', 26041, 0, 0, 1, -50.8107643127441406, -2027.1805419921875, 1160.419677734375, 1.724663138389587402, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68974), -- Orweyna (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 237343, 2694, 15355, 15922, '0', 26041, 0, 0, 1, -42.4565963745117187, -2023.3055419921875, 1160.3970947265625, 1.850510835647583007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68974); -- Halduron Brightwing (Area: Amirdrassil Roots - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 732, 0, 0, 0, 0, ''), -- Danul
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 732, 0, 0, 0, 0, ''); -- Oorla

-- Template
UPDATE `creature_template` SET `faction`=3512, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=237865; -- Danul
UPDATE `creature_template` SET `faction`=3512, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=237866; -- Oorla
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=237343; -- Halduron Brightwing
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=237210; -- Orweyna

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=68974 WHERE (`Entry`=237865 AND `DifficultyID`=0); -- 237865 (Danul) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3087, `StaticFlags1`=0x10000000, `VerifiedBuild`=68974 WHERE (`Entry`=237866 AND `DifficultyID`=0); -- 237866 (Oorla) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3313, `StaticFlags1`=0x10000000, `VerifiedBuild`=68974 WHERE (`Entry`=237343 AND `DifficultyID`=0); -- 237343 (Halduron Brightwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321, `StaticFlags1`=0x10000000, `VerifiedBuild`=68974 WHERE (`Entry`=237210 AND `DifficultyID`=0); -- 237210 (Orweyna) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (27835,26533,26041);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES 
(27835, 'Cosmetic - See Danul'),
(26533, 'Cosmetic - See Oorla'),
(26041, 'Cosmetic - See Orweyna and Halduron');

DELETE FROM `phase_area` WHERE `AreaId`=15355 AND `PhaseId` IN (27835,26533,26041);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(15355, 27835, 'See Danul'),
(15355, 26533, 'See Oorla'),
(15355, 26041, 'See Orweyna and Halduron');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (27835,26533,26041) AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 27835, 0, 0, 0, 47, 0, 86900, 8, 0, 0, 'Apply Phase 27835 if Quest 86900 is in progress'),
(26, 27835, 0, 0, 0, 48, 0, 458762, 0, 1, 0, 'Apply Phase 27835 if Questobjective 457680 is rewarded'),
(26, 27835, 0, 0, 0, 48, 0, 457680, 0, 1, 1, 'Apply Phase 27835 if Questobjective 457680 is not rewarded'),
(26, 26533, 0, 0, 0, 47, 0, 86900, 8, 0, 0, 'Apply Phase 27835 if Quest 86900 is in progress'),
(26, 26533, 0, 0, 0, 48, 0, 458762, 0, 1, 0, 'Apply Phase 27835 if Questobjective 458762 is rewarded'),
(26, 26533, 0, 0, 0, 48, 0, 457679, 0, 1, 1, 'Apply Phase 27835 if Questobjective 457679 is not rewarded'),
(26, 26041, 0, 0, 0, 47, 0, 86900, 8, 0, 0, 'Apply Phase 27835 if Quest 86900 is in progress'),
(26, 26041, 0, 0, 0, 48, 0, 457680, 0, 1, 0, 'Apply Phase 27835 if Questobjective 457680 is rewarded'),
(26, 26041, 0, 0, 0, 48, 0, 457679, 0, 1, 0, 'Apply Phase 27835 if Questobjective 457679 is rewarded');

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=@ATID+0 AND `IsCustom`=1) OR (`Id`=@ATID+1 AND `IsCustom`=1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2694, '0', -120.217018127441406, -2057.201416015625, 1155.1209716796875, 4.649010181427001953, 0, 27835, 0, 'SmartAreaTriggerAI', 'Harandar - start Conversation 29580', 0),
(@ATIDSPAWN+1, @ATCP+0, 1, 2694, '0', -9.88194465637207031, -2189.807373046875, 1178.2591552734375, 2.179077863693237304, 0, 26533, 0, 'SmartAreaTriggerAI', 'Harandar - start Conversation 29580', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 14, 14, 15, 14, 14, 15, 0, 0, '', 0);

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`IN (29580,29575,28747);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(29580, 81684, 0, 68974),
(29575, 81672, 0, 68974),
(28747, 80485, 0, 68974);

DELETE FROM `conversation_line_template` WHERE `Id` IN (81684, 81672, 79354, 80485);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(81684, 0, 0, 0, 0, 68974),
(81672, 0, 0, 0, 0, 68974),
(79354, 0, 1, 0, 0, 68974),
(80485, 0, 0, 0, 0, 68974);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=29580 AND `Idx`=0) OR (`ConversationId`=29575 AND `Idx`=0) OR (`ConversationId`=28747 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(29580, 105498, (@CGUID+0), 0, 0, 0, 0, 0, 68974), -- Full: 0x203AF150C0E84A400004A10000736DCC Creature/0 R3772/S1185 Map: 2694 (Harandar) Entry: 237865 (Danul) Low: 7564748
(29575, 107600, (@CGUID+1), 0, 0, 0, 0, 0, 68974), -- Full: 0x203AF150C0E84A800004A10000736DCD Creature/0 R3772/S1185 Map: 2694 (Harandar) Entry: 237866 (Oorla) Low: 7564749
(28747, 106001, 0, 1, 0, 0, 0, 0, 68974), -- Full: 0x203AF150C0E7A6800004A10000736DCD Creature/0 R3772/S1185 Map: 2694 (Harandar) Entry: 237210 (Orweyna) Low: 7564749
(28747, 106545, 0, 0, 0, 0, 0, 0, 68974); -- Full: 0x203AF150C0E7C7C00004A10000736DCC Creature/0 R3772/S1185 Map: 2694 (Harandar) Entry: 237343 (Halduron Brightwing) Low: 7564748

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=237865 AND `MenuID`=39194) OR (`CreatureID`=237866 AND `MenuID`=39190);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(237865, 39194, 68974), -- Danul
(237866, 39190, 68974); -- Oorla

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 289759, 0, 0, 0, 0, 0, 0, 0, 68974), -- 237865 (Danul)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 289743, 0, 0, 0, 0, 0, 0, 0, 68974); -- 237866 (Oorla)

DELETE FROM `gossip_menu` WHERE (`MenuID`=39194 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=39190 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39194, @NPCTEXTID+0, 68974), -- 237865 (Danul)
(39190, @NPCTEXTID+1, 68974); -- 237866 (Oorla)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39194 AND `OptionID`=0) OR (`MenuID`=39190 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39194, 133726, 0, 0, 'Ku\'paal and Orweyna sent me. It\'s safe to return to the village.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68974),
(39190, 133721, 0, 0, 'Ku\'paal and Orweyna sent me. It\'s safe to return to the village.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68974);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=237343 AND `MenuID`=38640) OR (`CreatureID`=237210 AND `MenuID`=37879);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(237343, 38640, 68974), -- Halduron Brightwing
(237210, 37879, 68974); -- Orweyna

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+2 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 285936, 0, 0, 0, 0, 0, 0, 0, 68974), -- 237343 (Halduron Brightwing)
(@NPCTEXTID+3, 1, 1, 0, 0, 0, 0, 0, 0, 289901, 280596, 0, 0, 0, 0, 0, 0, 68974); -- 237210 (Orweyna)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38640 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=37879 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38640, @NPCTEXTID+2, 68974), -- 237343 (Halduron Brightwing)
(37879, @NPCTEXTID+3, 68974); -- 237210 (Orweyna)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (37879,38640));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37879, 131842, 0, 0, '<Take in the view.>', 0, 0, 4, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68974),
(38640, 133774, 0, 0, 'Let\'s head down.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68974);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (39194,39190));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 39194, 0, 0, 0, 48, 0, 457680, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 457680 < 1 or has rewarded the quest'),
(15, 39190, 0, 0, 0, 48, 0, 457679, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 457679 < 1 or has rewarded the quest');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (37879));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 37879, 0, 0, 0, 48, 0, 460249, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 460249 < 1 or has rewarded the quest');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (38640));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 38640, 0, 0, 0, 48, 0, 460249, 0, 1, '', 0, 'Player for which gossip text is shown has quest objective 460249 == 1 (but hasn\'t rewarded quest yet)');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (237865,237866);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(237865, 0, 0, 'Aw, I was just getting warmed up too.', 12, 0, 100, 1, 0, 300562, 283407, 0, 'Danul to Player'),
(237866, 0, 0, 'Fine, but those were my kills! No taking credit.', 12, 0, 100, 1, 0, 300563, 283406, 0, 'Oorla to Player');

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (457680,457679);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(457680, NULL, NULL, NULL, 1, 1),
(457679, NULL, NULL, NULL, 1, 1);

-- Serverside Areatrigger SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+0 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 1, 0, 0, 0, 0, 0, '', 143, 29580, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation 29580 to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 86900, 8, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 86900 is in progress');

-- Serverside Areatrigger SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+1 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+1, 12, 0, 1, '', 46, 0, 100, 1, 0, 0, 0, 0, 0, '', 143, 29575, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation 29575 to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+1 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+1, 1, 0, 0, 47, 0, 86900, 8, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 86900 is in progress');

-- Danul smart ai
SET @ENTRY := 237865;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 39194, 0, 0, 0, 0, 33, 237865, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 39194 selected - Gossip player: Give kill credit Danul (237865)', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 39194 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23786500, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 39194 selected - Self: Start timed action list id #Danul #0 (23786500) (update out of combat)', '');

-- Timed list 23786500 smart ai
SET @ENTRY := 23786500;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 85, 468982, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast spell 468982 on self', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 3, 0, 130410, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Morph to model 130410', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 60, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Disable gravity', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 23786500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #23786500, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Despawn instantly', '');

-- Oorla smart ai
SET @ENTRY := 237866;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 39190, 0, 0, 0, 0, 33, 237866, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 39190 selected - Gossip player: Give kill credit Oorla (237866)', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 39190 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 23786600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 39190 selected - Self: Start timed action list id #Oorla #0 (23786600) (update out of combat)', '');

-- Timed list 23786600 smart ai
SET @ENTRY := 23786600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 53, 0, 23786600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #23786600, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Despawn instantly', '');

-- Orweyna smart ai
SET @ENTRY := 237210;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 37879, 0, 0, 0, 0, 85, 1227871, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37879 selected - Gossip player: Cast spell 1227871 on self', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 237210, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37879 selected - Gossip player: Give kill credit Orweyna (237210)', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37879 selected - Gossip player: Close gossip', '');

-- Halduron Brightwing smart ai
SET @ENTRY := 237343;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 38640, 0, 0, 0, 0, 143, 28747, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 38640 selected - Gossip player: Start conversation 28747', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 38640 selected - Gossip player: Close gossip', '');

-- Path for Danul
SET @ENTRY := 237865;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Danul - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -119.74827, -2053.1494, 1155.0859, NULL, 0),
(@PATH, 1, -119.05903, -2047.6077, 1154.8983, NULL, 0),
(@PATH, 2, -114.02431, -2038.8298, 1154.8983, NULL, 0),
(@PATH, 3, -105.88021, -2029.1632, 1154.8983, NULL, 0),
(@PATH, 4, -88.17014, -2011.3073, 1154.8983, NULL, 0),
(@PATH, 5, -66.40104, -2008.6649, 1154.8983, NULL, 0);

-- Path for Oorla
SET @ENTRY := 237866;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Oorla - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -23.604166, -2174.882, 1174.5815, NULL, 0),
(@PATH, 1, -29.328125, -2150.0452, 1172.1815, NULL, 0);
