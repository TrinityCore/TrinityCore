-- Creature
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=274040, `TypeFlags2`=128 WHERE (`Entry`=223237 AND `DifficultyID`=23); -- Volatile Spike Stalker
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2722, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=210108 AND `DifficultyID`=23); -- 210108 (E.D.N.A.) - CanSwim

UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x41080001, `AIName`='SmartAI' WHERE `entry`=223237; -- Volatile Spike Stalker
UPDATE `creature_template` SET `ScriptName`='boss_edna' WHERE `entry`=210108; -- 210108 (E.D.N.A.)
UPDATE `creature_template` SET `ScriptName`='npc_skardyn_invader' WHERE `entry`=224516; -- 224516 (Skardyn Invader)
UPDATE `creature_template` SET `StringId`='edna_intro_trash' WHERE `entry`=210109; -- 210109 (Earth Infused Golem)

DELETE FROM `creature_template_addon` WHERE `entry`=210108;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(210108, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '451704 447230 422356');

-- Instance
DELETE FROM `instance_template` WHERE `map`=2652;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2652, 0, 'instance_the_stonevault');

-- Areatriggers
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (33881, 19401));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(33881, 0, 0, 58238),
(19401, 0, 0, 58238);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (33613, 30324));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(33613, 0, 33881, 0, 4, 0, 0, 0, 0, -1, 0, 0, 424909, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_edna_volatile_spike', 58238), -- SpellForVisuals: 424909 (Volatile Spike)
(30324, 0, 19401, 0, 4, 0, 0, 0, 0, -1, 0, 0, 424909, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0, 0, '', 58238); -- SpellForVisuals: 424909 (Volatile Spike) Unknown purpose (maybe testing?)

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (451705, 447230, 451728, 424889, 424903, 452738, 424805, 424879);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(451705, 'spell_edna_energize'),
(447230, 'spell_edna_skarden_spawn_rp_periodic'),
(451728, 'spell_edna_skarden_spawn_rp'),
(424889, 'spell_edna_seismic_reverberation'),
(424903, 'spell_edna_volatile_spike_selector'),
(452738, 'spell_edna_refracting_beam_selector'),
(424805, 'spell_edna_refracting_beam_instakill'),
(424879, 'spell_edna_earth_shatterer');

-- Volatile Spike SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=223237 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(223237, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 424909, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Volatile Spike Stalker - On Summoned - Cast Self: Volatile Spike'),
(223237, 0, 1, 2, '', 8, 0, 100, 0, 448207, 0, 0, 0, 0, '', 85, 424913, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Volatile Spike Stalker - On Spellhit \'Refracting Beam\' - Cast Self: Volatile Explosion'),
(223237, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Volatile Spike Stalker - On Spellhit \'Refracting Beam\' - Despawn'),
(223237, 0, 3, 4, '', 8, 0, 100, 0, 448220, 0, 0, 0, 0, '', 85, 424913, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Volatile Spike Stalker - On Spellhit \'Earth Shatterer\' - Cast Self: Volatile Explosion'),
(223237, 0, 4, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Volatile Spike Stalker - On Spellhit \'Earth Shatterer\' - Despawn');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` = 424805;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 4, 424805, 0, 0, 51, 0, 5, 224516, 0, '', 0, 0, 0, '', 'Spell \'Refracting Beam\' can only hit \'Skardyn Invader\'');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 210108;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(210108, 0, 0, 'Intruders approaching. Systems on.', 14, 0, 100, 0, 0, 247879, 262600, 0, 'E.D.N.A.'),
(210108, 1, 0, 'Activating defense protocols.', 14, 0, 100, 0, 0, 247879, 262601, 0, 'E.D.N.A.'),
(210108, 2, 0, 'Seismic protocol activated.', 14, 0, 100, 0, 0, 247883, 262604, 0, 'E.D.N.A.'),
(210108, 3, 0, 'Offensive measures engaged.', 14, 0, 100, 0, 0, 250762, 262608, 0, 'E.D.N.A.'),
(210108, 4, 0, 'Dominant intruder identified.', 14, 0, 100, 0, 0, 247884, 262605, 0, 'E.D.N.A.'),
(210108, 5, 0, '|TInterface\\ICONS\\INV_ElementalEarth2.blp:20|t %s begins to cast |cFFFF0000|Hspell:424888|h[Seismic Smash]|h|r.', 41, 0, 100, 0, 0, 247884, 0, 0, 'E.D.N.A.'), -- Unknown BroadcastTextId
(210108, 6, 0, 'Engaging offensive protocols.', 14, 0, 100, 0, 0, 247885, 262606, 0, 'E.D.N.A.'),
(210108, 7, 0, 'Intruder terminated.', 14, 0, 100, 0, 0, 247881, 262602, 0, 'E.D.N.A.'),
(210108, 8, 0, 'All intruders terminated.', 14, 0, 100, 0, 0, 247889, 262610, 0, 'E.D.N.A.'),
(210108, 9, 0, 'All systems... shutting down...', 14, 0, 100, 0, 0, 247890, 262611, 0, 'E.D.N.A.');

-- Conversations
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (25769,25768));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(25769, 99466, 0, 224736, 119519, 0, 0, 58630),
(25768, 99466, 0, 224736, 119519, 0, 0, 58630);

DELETE FROM `conversation_line_template` WHERE `Id` IN (70041, 70040, 70039);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(70041, 1218, 0, 0, 0, 58630),
(70040, 1218, 0, 0, 0, 58630),
(70039, 1218, 0, 0, 0, 58630);

DELETE FROM `conversation_template` WHERE `Id` IN (25814, 25775, 25773, 25772, 25771, 25770, 25769, 25768, 25767, 26511);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(25769, 70041, 0, 58630),
(25768, 70039, 0, 58630);
