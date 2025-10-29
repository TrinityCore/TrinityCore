SET @ATSPAWNID := 266;
SET @ATPROPERTIESID := 163;
SET @ATID := 169;
SET @CGUID := 10006844;

-- Creature
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2722, `VerifiedBuild`=57388 WHERE (`Entry`=216619 AND `DifficultyID`=0); -- 216619 (Orator Krix'vizk) - CanSwim
UPDATE `creature_template_addon` SET `auras`='422356' WHERE `entry`=216619;
UPDATE `creature_template` SET `ScriptName`='boss_orator_krix_vizk' WHERE `entry`=216619;
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x41000001 WHERE `entry`=220769; -- Orator Krix'vizk

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 220769, 2669, 14979, 15111, '1,2,23,8,205', '0', 0, 0, 0, -1857.5416259765625, -1155.314208984375, -1244.12255859375, 0.737591743469238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 57388); -- Orator Krix'vizk (Area: Umbral Bazaar - Difficulty: Mythic) CreateObject1

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` = 220769);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(220769, 23, 0, 0, 1279, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 57388); -- 220769 (Orator Krix'vizk) - Sessile, Floating

-- Instance
DELETE FROM `instance_template` WHERE `map`=2669;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2669, 0, 'instance_city_of_threads');

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (34764, 35433, 34738));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(34764, 0, 0, 57388),
(35433, 0, 0, 58238),
(34738, 0, 0, 57292);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId`=35803 AND `IsCustom`=0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(35803, 0, 0, 449122, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (31997, 32026));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(32026, 0, 34764, 0, 2, 0, 0, 0, 0, -1, 0, 82, NULL, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_orator_krix_vizk_lingering_influence', 58238), -- Spell: 434923 (Lingering Influence)
(31997, 0, 34738, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 5, 10, 10, 80, 80, 30, 30, 10, 10, 'at_orator_krix_vizk_chains_of_oppression', 58238); -- Spell: 434691 (Chains of Oppression)

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0),
(@ATID+1, 1, 1, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+2;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 2669, '1,2,8,23', -1691.11, -903.29, -1249.49, 1.498532, 0, 0, 0, 'at_orator_conversation_intro_1', 'City of Threads - Orator Krixvizk Conversation 1', 56647),
(@ATSPAWNID+1, @ATPROPERTIESID+1, 1, 2669, '1,2,8,23', -1790.64, -1026.74, -1243.88, 1.247988, 0, 0, 0, 'at_orator_conversation_intro_2', 'City of Threads - Orator Krixvizk Conversation 2', 56647),
(@ATSPAWNID+2, @ATPROPERTIESID+0, 1, 2669, '1,2,8,23', -1826.44, -1082.34, -1244.16, 1.094052, 0, 0, 0, 'at_orator_conversation_intro_3', 'City of Threads - Orator Krixvizk Conversation 3', 56647);

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @ATPROPERTIESID+0 AND @ATPROPERTIESID+2;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 1, 10, 50, 5, 10, 50, 5, 0, 0, '', 0),
(@ATPROPERTIESID+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 50, 50, 0, 0, 0, 0, 0, 0, '', 0),
(@ATPROPERTIESID+2, 1, 35433, 0, 16, 0, 0, 0, 0, -1, 0, 601, 443437, 30000, 12, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_orator_krix_vizk_doubt', 58238); -- SpellForVisuals: 443437 (Shadows of Doubt)

-- Jumpcharge Parameters
DELETE FROM `jump_charge_params` WHERE `id`=959;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`) VALUES
(959, 35, 0, 56.1096, NULL, NULL, NULL);

-- Conversations
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (24642, 24643, 24644));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(24644, 51642, 0, 216619, 116692, 0, 0, 57388),
(24642, 51642, 0, 220769, 116692, 0, 0, 57388),
(24643, 51642, 0, 216619, 116692, 0, 0, 57388);

DELETE FROM `conversation_template` WHERE `Id` IN (24642, 24643, 24644);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(24644, 67092, 0, 57388),
(24643, 67091, 0, 57388),
(24642, 67085, 0, 57388);

DELETE FROM `conversation_line_template` WHERE `Id` IN (67085, 67091, 67092);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(67092, 1751, 0, 0, 0, 57388),
(67091, 1751, 0, 0, 0, 57388),
(67085, 1751, 0, 0, 0, 57388);

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (440310, 448560, 434808, 448561, 434829);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(440310, 'spell_orator_krix_vizk_chains_of_oppression_periodic'),
(448560, 'spell_orator_krix_vizk_shadows_of_doubt_selector'),
(434808, 'spell_orator_krix_vizk_terrorize_selector'),
(448561, 'spell_orator_krix_vizk_shadows_of_doubt_periodic'),
(434829, 'spell_orator_krix_vizk_vociferous_indoctrination_periodic');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=216619;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(216619, 0, 0, 'Come! Let us speak.', 14, 0, 100, 0, 0, 247788, 262861, 0, 'Orator Krix\'vizk'),
(216619, 1, 0, 'Bow before me!', 14, 0, 100, 0, 0, 247792, 262867, 0, 'Orator Krix\'vizk'),
(216619, 1, 1, 'Bend the knee!', 14, 0, 100, 0, 0, 247791, 262866, 0, 'Orator Krix\'vizk'),
(216619, 2, 0, 'We revel in your fear!', 14, 0, 100, 0, 0, 247794, 262869, 0, 'Orator Krix\'vizk'),
(216619, 2, 1, 'Your terror is our victory!', 14, 0, 100, 0, 0, 247793, 262868, 0, 'Orator Krix\'vizk'),
(216619, 3, 0, 'We rise through conquest!', 14, 0, 100, 0, 0, 247797, 262872, 0, 'Orator Krix\'vizk'),
(216619, 3, 1, 'Azj-Kahet will thrive!', 14, 0, 100, 0, 0, 247798, 262873, 0, 'Orator Krix\'vizk'),
(216619, 4, 0, 'Should have listened.', 14, 0, 100, 0, 0, 247789, 262862, 0, 'Orator Krix\'vizk'),
(216619, 4, 1, 'Blessed silence.', 14, 0, 100, 0, 0, 247790, 262863, 0, 'Orator Krix\'vizk'),
(216619, 4, 2, 'I shall prepare your eulogy myself.', 14, 0, 100, 0, 0, 247799, 262864, 0, 'Orator Krix\'vizk'),
(216619, 5, 0, 'My... beautiful... voice...', 14, 0, 100, 0, 0, 247800, 262865, 0, 'Orator Krix\'vizk');
