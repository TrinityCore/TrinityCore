DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (134058, 134063, 136314);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `LootID`, `PickPocketLootID`, `SkinLootID`, `GoldMin`, `GoldMax`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(136314, 0, 0, 0, 500, 7, 1, 1, 1, 1, 156993, 1610612752, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967),
(136314, 1, 0, 0, 500, 7, 1, 1, 1, 1, 156993, 1610612752, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967),
(136314, 2, 0, 0, 501, 7, 1, 1, 1, 1, 156993, 1610612752, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967),
(136314, 23, 0, 0, 502, 7, 1, 1, 1, 1, 156993, 1610612752, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967),
(134058, 0, 2, 2, 500, 0, 26.25, 0.338862, 1, 1, 140108, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134058, 1, 2, 2, 500, 7, 26.25, 0.338862, 1, 1, 140108, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134058, 2, 2, 2, 501, 7, 26.25, 0.338862, 1, 1, 144306, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134058, 23, 2, 2, 502, 7, 26.25, 0.338862, 1, 1, 144307, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134063, 0, 2, 2, 500, 0, 26.25, 0.338862, 1, 1, 140108, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134063, 1, 2, 2, 500, 7, 26.25, 0.338862, 1, 1, 140108, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134063, 2, 2, 2, 501, 7, 26.25, 0.338862, 1, 1, 144306, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967),
(134063, 23, 2, 2, 502, 7, 26.25, 0.338862, 1, 1, 144307, 2097224, 129, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 61967);

UPDATE `creature_template` SET `faction`=14, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x1080001, `AIName`='SmartAI' WHERE `entry`=136314; -- Blowback
UPDATE `creature_template` SET `ScriptName` = 'boss_brother_ironhull' WHERE `entry`=134063;
UPDATE `creature_template` SET `ScriptName` = 'boss_galecaller_faye' WHERE `entry`=134058;

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (17771,17760,17768,17766));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17771, 0, 0, 34601),
(17760, 0, 0, 34601),
(17768, 0, 0, 34601),
(17766, 0, 0, 34601);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (13147,13160,13154,13157));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(13147, 0, 17760, 0, 6, 0, 6336, 0, 0, -1, 0, 0, NULL, 120000, 0, 4, 2, 2, 4, 4, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_tidesage_council_blowback', 61967), -- Spell: 267836 (Blowback)
(13160, 0, 17771, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 8000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_tidesage_council_reinforcing_ward', 61967), -- Spell: 267905 (Reinforcing Ward)
(13154, 0, 17766, 0, 0, 0, 0, 0, 0, -1, 0, 0, 267891, 8000, 0, 0, 12, 12, 0, 0, 0, 0, 0, 0, 'at_tidesage_council_swiftness_ward_boss', 61967), -- SpellForVisuals: 267891 (Swiftness Ward)
(13157, 0, 17768, 0, 0, 0, 0, 0, 0, -1, 0, 0, 267891, 8000, 0, 0, 11, 11, 0, 0, 0, 0, 0, 0, 'at_tidesage_council_swiftness_ward_player', 61967); -- SpellForVisuals: 267891 (Swiftness Ward)

DELETE FROM `spell_proc` WHERE `SpellId` IN (267830);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(267830,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x1000,0x0,0x0,0,0,0,0); -- Blessing of the Tempest

DELETE FROM `smart_scripts` WHERE `entryorguid`=136314 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(136314, 0, 0, 1, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 267836, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Blowback - On Just Created - Cast Self: Spell 267836'),
(136314, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Blowback - On Linked - Set ReactState Passive'),
(136314, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 89, 20, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Blowback - On Linked - Set Random Move within 20 radius');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_tidesage_council_ward_selector', 'spell_tidesage_council_blessing_of_the_tempest');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(267902, 'spell_tidesage_council_ward_selector'),
(267903, 'spell_tidesage_council_ward_selector'),
(267830, 'spell_tidesage_council_blessing_of_the_tempest');

DELETE FROM `serverside_spell` WHERE `Id` IN (267916, 267894);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `AttributesEx15`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(267916, 0, 0, 0, 0, 0x29240180, 0x000004A8, 0x10484004, 0x00070000, 0x00800080, 0x00060008, 0x00001000, 0x00000040, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, -1, 0, 0, 'Brother Ironhull Gain Energy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(267894, 0, 0, 0, 0, 0x29240180, 0x000004A8, 0x10484004, 0x00070000, 0x00800080, 0x00060008, 0x00001000, 0x00000040, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, -1, 0, 0, 'Galecaller Faye Gain Energy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (267916, 267894);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(267916, 0, 0, 6, 21, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(267894, 0, 0, 6, 21, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (134058, 134063);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Aggro
(134063, 0, 0, 'The tides shall take you!', 14, 0, 50, 0, 0, 102945, 150512, 0, 'Brother Ironhull'),
(134058, 0, 0, 'None shall stand against the storm!', 14, 0, 100, 0, 0, 102934, 150502, 0, 'Galecaller Faye'),

-- Slay
(134058, 3, 0, 'Blown away!', 14, 0, 50, 0, 0, 102936, 150508, 0, 'Galecaller Faye'),
(134058, 3, 1, 'Cleansed by the storm!', 14, 0, 50, 0, 0, 102937, 150509, 0, 'Galecaller Faye'),
(134063, 3, 0, 'You should\'ve stayed ashore!', 14, 0, 50, 0, 0, 102947, 150516, 0, 'Brother Ironhull'),
(134063, 3, 1, 'Enjoy your watery grave!', 14, 0, 50, 0, 0, 102948, 150519, 0, 'Brother Ironhull'),

-- Wipe
(134058, 4, 0, 'Together, my love, we are a force of nature.', 14, 0, 50, 0, 0, 102938, 150510, 0, 'Galecaller Faye'),
(134063, 4, 0, 'I\'ll cast you to the depths for that!', 14, 0, 50, 0, 0, 102944, 150514, 0, 'Brother Ironhull'),

-- Dead
(134058, 5, 0, 'The clouds... break...', 14, 0, 100, 0, 0, 102935, 150506, 0, 'Galecaller Faye'),
(134063, 5, 0, 'Return me... to the sea...', 14, 0, 100, 0, 0, 102946, 150515, 0, 'Brother Ironhull to Brother Ironhull'),

-- Galecaller Faye
(134058, 1, 0, '|TInterface\\Icons\\70_inscription_vantus_rune_azure:20|t%s creates a |cFFFF0000|Hspell:267891|h[Swiftness Ward]|h|r!', 41, 0, 100, 0, 0, 102933, 151969, 0, 'Galecaller Faye'),
(134058, 2, 0, 'The breeze is ever at our backs!', 14, 0, 100, 0, 0, 102933, 151288, 0, 'Galecaller Faye'),
(134058, 6, 0, 'Winds, protect me!', 14, 0, 100, 0, 0, 102930, 151290, 0, 'Galecaller Faye'),
(134058, 7, 0, 'Beloved! No!', 14, 0, 50, 0, 0, 102931, 150504, 0, 'Galecaller Faye'),
(134058, 7, 1, 'The winds will blast the flesh from your bones!', 14, 0, 50, 0, 0, 102932, 150505, 0, 'Galecaller Faye'),

-- Brother Ironhull
(134063, 1, 0, 'My hull is impenetrable!', 14, 0, 100, 0, 0, 102943, 151286, 0, 'Brother Ironhull'),
(134063, 2, 0, '|TInterface\\Icons\\70_inscription_vantus_rune_light:20|t%s creates a |cFFFF0000|Hspell:267905|h[Reinforcing Ward]|h|r!', 41, 0, 100, 0, 0, 102943, 160664, 0, 'Brother Ironhull'),
(134063, 6, 0, 'I\'ll break you to splinters!', 14, 0, 50, 0, 0, 102939, 151287, 0, 'Brother Ironhull'),
(134063, 6, 1, 'NO!', 14, 0, 50, 0, 0, 102940, 150513, 0, 'Brother Ironhull');
