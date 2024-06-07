SET @ATID := 67;
SEt @ATCP := 55;
SET @ATIDSPAWN := 69;

-- Instance Template
DELETE FROM `instance_template` WHERE `map` = 1762;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1762, 0, 'instance_kings_rest');

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (137020 /*137020 (Shadow of Zul) - Zul Shadowform*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(137020, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '269058'); -- 137020 (Shadow of Zul) - Zul Shadowform

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 16, 18, 10, 16, 18, 10, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1762, '23,8,2', -945.071, 2602.210, 833.052, 1.556985, 0, 0, 0, 'at_kings_rest_trigger_intro_event_with_zul', 'KingsRest - Trigger intro Conversation for Zul', 0);

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=7690;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(7690, 17525, 0, 54904);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_kings_rest_intro' WHERE `Id` = 7690;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=7690 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(7690, 64206, 0, 0, 0, 0, 0, 54904); -- Full: 0x0

DELETE FROM `conversation_line_template` WHERE `Id` IN (17527, 17526, 17525);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(17527, 0, 0, 0, 1, 54904),
(17526, 0, 0, 0, 1, 54904),
(17525, 0, 0, 0, 1, 54904);
