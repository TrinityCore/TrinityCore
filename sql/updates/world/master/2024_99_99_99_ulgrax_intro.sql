SET @ATID := 96;
SET @ATCP := 85;
SET @ATSPAWNID := 99;

-- Creature
UPDATE `creature_template` SET `flags_extra`=536870912, `ScriptName`='boss_ulgrax_the_devourer' WHERE `entry`=215657; -- CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING must be added since the combat is on a gameobject

DELETE FROM `creature_formations` WHERE `leaderGUID`=10001982;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(10001982,10001982,0,0,0,0,0),
(10001982,10002001,0,0,0,0,0),
(10001982,10001998,0,0,0,0,0),
(10001982,10001995,0,0,0,0,0),
(10001982,10001989,0,0,0,0,0);
UPDATE `creature` SET `StringId`='nerubar_palace_intro_trash' WHERE `guid` IN (10001982, 10002001, 10001998, 10001995, 10001989);

DELETE FROM `creature_formations` WHERE `leaderGUID`=10001991;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(10001991,10001991,0,0,0,0,0),
(10001991,10002009,0,0,0,0,0),
(10001991,10002016,0,0,0,0,0),
(10001991,10002018,0,0,0,0,0),
(10001991,10002006,0,0,0,0,0),
(10001991,10002010,0,0,0,0,0);
UPDATE `creature` SET `StringId`='ulgrax_intro_trash' WHERE `guid` IN (10001991, 10002009, 10002016, 10002018, 10002006, 10002010);

-- Instance
DELETE FROM `instance_template` WHERE `map`=2657;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2657, 0, 'instance_nerubar_palace');

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID+0;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = @ATID+0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 30, 60, 2, 30, 60, 2, 0, 0, 'at_ulgrax_intro', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATCP+0, 1, 2657, '14,15,16,17', -2841.09, -273.894, -1189.997, 5.509477, 0, 0, 0, '', 'Nerub\'ar Palace - Ulgrax the Devourer intro', 0);

-- Conversation
DELETE FROM `conversation_line_template` WHERE `Id` IN (66068, 66067, 66066);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(66068, 0, 0, 1, 1, 56513),
(66067, 0, 0, 1, 1, 56513),
(66066, 0, 0, 1, 1, 56513);

DELETE FROM `conversation_template` WHERE `Id` = 24332;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(24332, 66066, 0, 56513);

DELETE FROM `conversation_actors` WHERE `ConversationId`=24332 AND `Idx`=0;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(24332, 97324, 10002046, 0, 0, 0, 0, 0, 56513);

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (451409, 451411);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(451409, 'spell_ulgrax_the_devourer_swallowing_darkness_intro'),
(451411, 'spell_ulgrax_the_devourer_swallowing_darkness_teleport');
