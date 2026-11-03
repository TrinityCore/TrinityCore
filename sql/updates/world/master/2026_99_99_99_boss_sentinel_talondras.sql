-- Creature
UPDATE `creature_template` SET `ScriptName`='boss_sentinel_talondras' WHERE `entry`=184124;

-- Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (25127));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(25127, 0, 29609, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 90000, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, 'at_sentinel_talondras_resonating_orb', 52106); -- Spell: 372650 (Resonating Orb)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (29609));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(29609, 0, 52106);

DELETE FROM `areatrigger` WHERE `SpawnId`=295;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(295, 184, 1, 2451, '1,2,8,23', 59.3865, -690.463, 217.994446, 1.561093, 0, 0, 0, 'at_sentinel_talondras_intro', 'Sentinel Talondras - Intro', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=184 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `MaxSummons`, `MaxUnits`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(184, 1, 193, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, NULL, NULL, 0, 0, 1, 0, 1, 3, 5, 5, 3, 5, 5, 0, 0, 0, 0, 0, NULL, NULL, NULL, '', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=193 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(193, 1, 1, 0, 0, 0);

-- Instance
DELETE FROM `instance_template` WHERE `map`=2451;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2451, 0, 'instance_uldaman_legacy_of_tyr');

-- Spell Proc
DELETE FROM `spell_proc` WHERE `SpellId` IN (372600);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(372600,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x100,0x0,0x0,0,0,0,0); -- Inexorable

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sentinel_talondras_inexorable', 'spell_sentinel_talondras_ancient_dynamo', 'spell_sentinel_talondras_resonating_orb_marker', 'spell_sentinel_talondras_resonating_orb_selector', 'spell_sentinel_talondras_resonating_orb_stun', 'spell_sentinel_talondras_titanic_empowerment');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(372600, 'spell_sentinel_talondras_inexorable'),
(372716, 'spell_sentinel_talondras_ancient_dynamo'),
(382071, 'spell_sentinel_talondras_resonating_orb_marker'),
(372623, 'spell_sentinel_talondras_resonating_orb_selector'),
(372652, 'spell_sentinel_talondras_resonating_orb_stun'),
(372719, 'spell_sentinel_talondras_titanic_empowerment');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 184124;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(184124, 0, 0, 'Keeper Tyr\'s secrets will be protected!', 14, 0, 100, 0, 0, 203212, 226956, 0, 'Sentinel Talondras'),
(184124, 1, 0, 'Must... regain... strength!', 14, 0, 100, 0, 0, 203206, 226973, 0, 'Sentinel Talondras'),
(184124, 2, 0, 'Stop where you are!', 14, 0, 50, 0, 0, 203207, 226970, 0, 'Sentinel Talondras'),
(184124, 2, 1, 'Halt! You will go no further!', 14, 0, 50, 0, 0, 203208, 226971, 0, 'Sentinel Talondras'),
(184124, 3, 0, 'Let the unworthy be purged!', 14, 0, 100, 0, 0, 203210, 226969, 0, 'Sentinel Talondras'),
(184124, 4, 0, 'An unworthy foe!', 14, 0, 50, 0, 0, 203214, 226957, 0, 'Sentinel Talondras'),
(184124, 4, 1, 'Such weak flesh!', 14, 0, 50, 0, 0, 203215, 226958, 0, 'Sentinel Talondras'),
(184124, 5, 0, 'I will protect the keeper\'s secrets for all of time.', 14, 0, 100, 0, 0, 203216, 226959, 0, 'Sentinel Talondras'),
(184124, 6, 0, '|TInterface\\ICONS\\Shaman_talent_UnleashedFury.blp:20|t Sentinel Talondras charges her |cFFFF0000|Hspell:372716|h[Ancient Dynamo]|h|r while she is not stunned!', 41, 0, 100, 0, 0, 0, 0, 0, 'Sentinel Talondras'),
(184124, 7, 0, 'His memories... are not... for you...', 14, 0, 100, 0, 0, 203213, 226960, 0, 'Sentinel Talondras to Player');

-- Conversation
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` = 19467);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(19467, 85312, 9004417, 0, 0, 0, 0, 0, 52106); -- Full: 0x20422D3260B3CF000000BB0000525DAA Creature/0 R4235/S187 Map: 2451 (Uldaman: Legacy of Tyr) Entry: 184124 Low: 5397930

DELETE FROM `conversation_template` WHERE `Id` =19467;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(19467, 49652, 0, 52106);

DELETE FROM `conversation_line_template` WHERE `Id` = 49652;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(49652, 0, 0, 0, 1, 52106);
