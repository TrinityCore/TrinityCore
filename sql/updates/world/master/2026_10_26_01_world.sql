SET @CGUID := 10006984;

SET @NPCTEXTID := 600178;

SET @ATID := 191;
SET @ATIDSPAWN := 293;
SET @ATCP := 182;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 221841, 2739, 15342, 15380, '0', 23759, 0, 0, 0, 1443.1024169921875, -261.611114501953125, 11.04245948791503906, 4.706870555877685546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 70575), -- Foreman Uzjax (Area: Awakening Machine - Difficulty: 0) CreateObject1
(@CGUID+1, 221839, 2739, 15342, 15380, '0', 23759, 0, 0, 0, 1441.6336669921875, -261.7257080078125, 11.03898143768310546, 4.623592853546142578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 70575); -- Dawn (Area: Awakening Machine - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=3412, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221839; -- Dawn
UPDATE `creature_template` SET `faction`=3398, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221841; -- Foreman Uzjax

DELETE FROM `gameobject_template` WHERE `entry` IN (442744 /*Portal to Orgrimmar*/, 446110 /*Earthen Door*/, 441340 /*Access Dais*/, 442743 /*Portal to Stormwind*/, 452090 /*Access Dais*/, 441084 /*Awakening Scanner*/, 446115 /*Earthen Door*/, 446114 /*Earthen Door*/, 446113 /*Earthen Door*/, 446112 /*Earthen Door*/, 446111 /*Earthen Door*/, 445631 /*Earthen Gate*/, 445630 /*Earthen Gate*/, 445629 /*Earthen Gate*/, 445628 /*Earthen Gate*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(442744, 22, 66649, 'Portal to Orgrimmar', '', '', '', 1, 453339, -1, 0, 1, 1, 55254, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Portal to Orgrimmar
(446110, 0, 89968, 'Earthen Door', '', '', '', 0.926999807357788085, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Door
(441340, 22, 49214, 'Access Dais', '', '', '', 0.400000005960464477, 453336, -1, 0, 1, 1, 123818, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Access Dais
(442743, 22, 66650, 'Portal to Stormwind', '', '', '', 1, 453340, -1, 0, 1, 1, 55254, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Portal to Stormwind
(452090, 22, 49214, 'Access Dais', '', '', '', 0.400000005960464477, 453337, -1, 0, 1, 1, 123818, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Access Dais
(441084, 5, 56939, 'Awakening Scanner', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 863, 70575), -- Awakening Scanner
(446115, 0, 89968, 'Earthen Door', '', '', '', 0.899999737739562988, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Door
(446114, 0, 89968, 'Earthen Door', '', '', '', 0.899999797344207763, 0, 0, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Door
(446113, 0, 89968, 'Earthen Door', '', '', '', 0.899999797344207763, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Door
(446112, 0, 89968, 'Earthen Door', '', '', '', 0.799999833106994628, 0, 0, 10000, 0, 0, 0, 0, 126662, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Door
(446111, 0, 89968, 'Earthen Door', '', '', '', 0.839999794960021972, 0, 0, 20000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Door
(445631, 0, 88326, 'Earthen Gate', '', '', '', 0.999999761581420898, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Gate
(445630, 0, 88326, 'Earthen Gate', '', '', '', 0.999999821186065673, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Gate
(445629, 0, 88326, 'Earthen Gate', '', '', '', 0.999999821186065673, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Earthen Gate
(445628, 0, 88326, 'Earthen Gate', '', '', '', 0.999999761581420898, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70575); -- Earthen Gate

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 23759;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES 
(23759, 'Cosmetic - See init. Dawn and Foreman Uzjax');

DELETE FROM `phase_area` WHERE `AreaId`= 15380 AND `PhaseId` = 23759;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(15380, 23759, 'See init. Dawn and Foreman Uzjax');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23759 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23759, 0, 0, 0, 47, 0, 86900, 2|8|64, 0, 1, 'Apply Phase 23759 if Quest 86900 is not in progress | complete | rewarded');

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x100, `StaticFlags3`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=228602 AND `DifficultyID`=0); -- 228602 (Cognitive Scanner) - Sessile - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x100, `StaticFlags3`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=228603 AND `DifficultyID`=0); -- 228603 (Anomaly Scanner) - Sessile - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x100, `StaticFlags3`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=228597 AND `DifficultyID`=0); -- 228597 (Diagnostics Scanner) - Sessile - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=782, `StaticFlags1`=0x10000000, `VerifiedBuild`=70575 WHERE (`Entry`=221839 AND `DifficultyID`=0); -- 221839 (Dawn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `StaticFlags4`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=230541 AND `DifficultyID`=0); -- 230541 (Archivist) - CanSwim - HideInCombatLog
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `StaticFlags4`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=228006 AND `DifficultyID`=0); -- 228006 (Awakening Caretaker) - CanSwim - HideInCombatLog
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2803, `StaticFlags1`=0x10000000, `VerifiedBuild`=70575 WHERE (`Entry`=221841 AND `DifficultyID`=0); -- 221841 (Foreman Uzjax) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `StaticFlags4`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=228036 AND `DifficultyID`=0); -- 228036 (Cogwalker) - CanSwim - HideInCombatLog
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `StaticFlags4`=0x2000000, `VerifiedBuild`=70575 WHERE (`Entry`=227994 AND `DifficultyID`=0); -- 227994 (Awakening Technician) - CanSwim - HideInCombatLog

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (121394, 120021, 120022, 120008, 121392);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121394, 0.347000002861022949, 1.5, 0, 70575),
(120021, 13.48663902282714843, 0, 0, 70575),
(120022, 13.48663997650146484, 0, 0, 70575),
(120008, 13.48663902282714843, 0, 0, 70575),
(121392, 0.347000002861022949, 1.5, 0, 70575);

UPDATE `creature_model_info` SET `VerifiedBuild`=70575 WHERE `DisplayID` IN (118887, 121404, 121405, 114674, 117694);

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=@ATID+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 2739, '0', 1432.917236, -273.220245, 10.609265, 1.590566, 0, 0, 0, 'SmartAreaTriggerAI', 'Awakening Machine - start Conversation 25326', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 10, 30, 15, 10, 30, 15, 0, 0, '', 0);

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=25326;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(25326, 68937, 0, 70575);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=25326 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(25326, 98762, 1, 221839, 118887, 0, 0, 70575),
(25326, 98764, 0, 221841, 114674, 0, 0, 70575);

DELETE FROM `conversation_line_template` WHERE `Id` IN (68938, 68937);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(68938, 1809, 1, 0, 0, 70575),
(68937, 1808, 0, 0, 0, 70575);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=221841 AND `MenuID`=35980);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(221841, 35980, 70575); -- Foreman Uzjax

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 269513, 0, 0, 0, 0, 0, 0, 0, 70575); -- 221841 (Foreman Uzjax)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35980 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35980, @NPCTEXTID+0, 70575); -- 221841 (Foreman Uzjax)

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=3438;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3438, 9, 4268, 0);

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=227994 AND `ID` IN (2,1));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(227994, 2, 224820, 0, 0, 0, 0, 0, 0, 0, 0, 70575), -- Awakening Technician
(227994, 1, 224821, 0, 0, 0, 0, 0, 0, 0, 0, 70575); -- Awakening Technician

-- Quest
DELETE FROM `quest_details` WHERE `ID`=79200;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(79200, 1, 0, 0, 0, 0, 0, 0, 0, 70575); -- Who am I?

DELETE FROM `creature_queststarter` WHERE (`id`=221839 AND `quest`=79200);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(221839, 79200, 70575); -- Who am I? offered by Dawn

-- Serverside Areatrigger SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATID+0 AND `source_type`=12 AND `id`=0 AND `link`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 1, 0, 0, 0, 0, 0, '', 143, 25326, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On AreaTrigger enter - play Conversation 25326 to Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+0, 1, 0, 0, 47, 0, 79200, 2|8|64, 0, '', 1, 0, 0, '', 'Only trigger areatrigger when quest 79200 is not in progress | complete | rewarded');
