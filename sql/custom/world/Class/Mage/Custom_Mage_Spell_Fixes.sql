-- Shatter mastery script
DELETE FROM `spell_script_names` WHERE `spell_id`=1246769 AND `ScriptName`='spell_mage_shatter';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (1246769, 'spell_mage_shatter');

-- Remove all custom effects for 44614
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 44614;

-- Add dummy effect for EFFECT_3 to override DBC and fire on target (ImplicitTarget1=6 = TARGET_UNIT_TARGET_ENEMY)
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(44614, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0);

-- Flurry scripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (228596, 228354);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(228596, 'spell_mage_flurry_damage_spell'),
(228354, 'spell_mage_flurry_missile_damage');

-- Shatter proc data (handles Frostbolt, Frostfire Bolt, Flurry damage, Ice Lance)
DELETE FROM `spell_proc` WHERE `SpellId`=1246769;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `ProcFlags2`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(1246769, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0, 0, 2, 0, 0, 0, 0, 101, 0, 0);
-- Frostbite passive: add dummy aura effect so it is applied to the caster and can trigger procs
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 1248825;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(1248825, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
-- Frostbite script and proc: PHASE_HIT (2), HitMask=2 (PROC_HIT_CRITICAL only)
DELETE FROM `spell_script_names` WHERE `spell_id` = 1248825;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (1248825, 'spell_mage_frostbite');
DELETE FROM `spell_proc` WHERE `SpellId` = 1248825;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `ProcFlags2`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(1248825, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0, 0, 2, 2, 0, 0, 0, 101, 0, 0);

-- Brain Freeze passive (190447) - aura fix handled in SpellMgr.cpp ApplySpellFix (DBC spell, serverside_spell_effect not applicable)
-- Brain Freeze buff (190446) - aura fix handled in SpellMgr.cpp ApplySpellFix (DBC spell, serverside_spell_effect not applicable)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (190446, 190447);
DELETE FROM `spell_script_names` WHERE `spell_id` = 190447;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (190447, 'spell_mage_brain_freeze');
DELETE FROM `spell_proc` WHERE `SpellId` = 190447;
-- chance=100 because the script performs the actual roll (25% base + Frozen Touch bonus)
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `ProcFlags2`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(190447, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0, 0, 2, 0, 0, 0, 0, 100, 0, 0);

-- Icicles passive (1246832) - generates Icicles every 6 seconds in combat
DELETE FROM `spell_script_names` WHERE `spell_id` IN (1246832, 199786);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1246832, 'spell_mage_icicles'),
(199786, 'spell_mage_glacial_spike');

-- Add periodic dummy effect to Icicles passive (Effect=6 for APPLY_AURA, EffectAura=226 for periodic dummy, 6000ms period)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 1246832;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(1246832, 0, 0, 6, 226, 0, 0, 6000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Remove incorrect serverside spell entries if they exist
DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (1246833, 199786);

-- 1222865 (Glacial Spike! transform): SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS (332)
-- EFFECT_0: replace Frostbolt (116) with Glacial Spike (199786)
-- EFFECT_1: replace Frostfire Bolt (431044) with Glacial Spike (199786)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 1222865;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(1222865, 0, 0, 6, 332, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 199786, 116, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(1222865, 1, 0, 6, 332, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 199786, 431044, 0, 0, 0, 0, 0, 0, 0, 1, 0);
DELETE FROM `spell_script_names` WHERE `spell_id` = 1222865;

-- Remove proc data from 1222865 (Glacial Spike!) to prevent it from auto-removing on spell casts
-- It should only be removed when Glacial Spike (199786) is cast
DELETE FROM `spell_proc` WHERE `SpellId` = 1222865;

-- Suppress "does not have triggered spell" spam from 228695 (PvP Rules Enabled)
-- The DBC aura effect has PROC_TRIGGER_SPELL with no TriggerSpell set; override all its effects with a no-op dummy
DELETE FROM `spell_proc` WHERE `SpellId` = 228695;
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 228695;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(228695, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Remove proc data from 112965 (Fingers of Frost passive) - proc is handled by script, not DB proc
DELETE FROM `spell_proc` WHERE `SpellId` = 112965;

-- 205030 - Frozen Touch: bonus % chance for Fingers of Frost and Brain Freeze from Frostbolt
DELETE FROM `spell_script_names` WHERE `spell_id` = 205030;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (205030, 'spell_mage_frozen_touch');

-- EFFECT_0 = bonus Fingers of Frost proc chance (15%), EFFECT_1 = bonus Brain Freeze proc chance (15%)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 205030;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(205030, 0, 0, 6, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(205030, 1, 0, 6, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Frozen Touch no longer needs a proc; its EFFECT_0/EFFECT_1 bonus values are read by Fingers of Frost and Brain Freeze scripts.
DELETE FROM `spell_proc` WHERE `SpellId` = 205030;

-- 460590 - Permafrost Lances (passive talent): DBC effect fixed via SpellMgr correction in SpellMgr.cpp
-- (SPELL_AURA_DUMMY replaces PROC_TRIGGER_SPELL; no DB override needed)
DELETE FROM `spell_proc` WHERE `SpellId` = 460590;
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 460590;

-- 455122 - Permafrost Lances buff: +10% frost damage done for 15 seconds (Frozen Orb duration)
-- SPELL_AURA_MOD_DAMAGE_PERCENT_DONE (79), EffectMiscValue1=16 (SPELL_SCHOOL_MASK_FROST), ImplicitTarget1=1 (self)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 455122;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(455122, 0, 0, 6, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 16, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- 385167 - Everlasting Frost: cast Frozen Orb grants EFFECT_0 stacks of FoF; EFFECT_1% chance on Frozen Orb damage
DELETE FROM `spell_script_names` WHERE `spell_id` = 385167;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (385167, 'spell_mage_everlasting_frost');

-- EFFECT_0 = number of FoF stacks on cast (value from DBC, e.g. 2), EFFECT_1 = % chance on damage (e.g. 10)
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 385167;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(385167, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(385167, 1, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- No spell_proc needed for 385167; per-hit FoF chance is handled directly in spell_mage_frozen_orb_damage::HandleHit
DELETE FROM `spell_proc` WHERE `SpellId` = 385167;

-- 1246752 - Mastery: Freeze and Shatter
-- EFFECT_0: SPELL_AURA_MASTERY (215), base 8 - scales with mastery rating; read by GetMasteryFreezeBonus() for
--           script-handled spells (Frozen Orb damage, Flurry missiles).
-- EFFECT_1: SPELL_AURA_MASTERY (215), base 8 - scales with mastery rating; read by GetMasteryShatterBonus() for
--           script-handled spells (Shatter damage).
-- EFFECT_2: SPELL_AURA_MOD_DAMAGE_PERCENT_DONE (79), MiscValue=16 (Frost school), base 8 - covers ALL frost spells
--           that go through the engine damage pipeline (Frostbolt, Cone of Cold, Glacial Spike, etc.).
--           No SpellClassMask so no SPELL_ATTR8_MASTERY_AFFECTS_POINTS filtering is applied here.
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 1246752;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(1246752, 0, 0, 6, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(1246752, 1, 0, 6, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(1246752, 2, 0, 6, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 16, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- 228597 - Frostbolt (damage component): register script for Piercing Cold handling
DELETE FROM `spell_script_names` WHERE `spell_id` = 228597 AND `ScriptName` = 'spell_mage_frostbolt_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (228597, 'spell_mage_frostbolt_damage');

-- 378919 - Piercing Cold
-- DBC ADD_PCT_MODIFIER SpellClassMask does not match this server's spell IDs for Frostbolt/Flurry.
-- Override EFFECT_0 with DUMMY (EffectBasePoints=20) so scripts can read GetAmount()=20.
-- Scripts in spell_mage.cpp handle the crit bonus for Frostbolt and Flurry missiles.
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 378919;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(378919, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Frozen Orb (84714) full implementation
-- Run this file fresh to apply all Frozen Orb DB changes

-- AreaTrigger Template
DELETE FROM `areatrigger_template` WHERE `Id` = 70001 AND `IsCustom` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES (70001, 1, 0, 0, 0, 0);

-- AreaTrigger Create Properties (Shape 0 = Sphere, radius 4 yards)
DELETE FROM `areatrigger_create_properties` WHERE `Id` = 70001 AND `IsCustom` = 1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES (70001, 1, 70001, 1, 0, 0, 0, 0, 0, 0, 0, 0, 84714, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_mage_frozen_orb', 0);

-- Spell Script for 84714 cast spell
DELETE FROM `spell_script_names` WHERE `spell_id` = 84714;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (84714, 'spell_mage_frozen_orb');

-- Spell Script for 84721 damage spell
DELETE FROM `spell_script_names` WHERE `spell_id` = 84721;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (84721, 'spell_mage_frozen_orb_damage');

-- Serverside effect for 84721: AOE frost school damage at destination
-- Effect=2 (SCHOOL_DAMAGE), Coefficient=0.408, EffectBasePoints=75, EffectMiscValue1=16 (frost), EffectRadiusIndex1=8 (6yd), ImplicitTarget1=22, ImplicitTarget2=15
DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 84721;
-- Coefficient=0 so CalcBaseValue returns flat EffectBasePoints=75 only; SP scaling handled in script
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES (84721, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 75, 16, 0, 8, 0, 0, 0, 0, 0, 22, 15);

DELETE FROM `spell_proc` WHERE `SpellId` IN (385167,1222865,460590);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `ProcFlags2`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES 
(385167, 0, 0, 0, 0, 0, 0, 0x10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
(1222865, 0, 0, 0, 0, 0, 0, 0x10000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
(460590, 0, 0, 0, 0, 0, 0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- Spell Script for 235219 Cold Snap Updated
DELETE FROM `spell_script_names` WHERE `spell_id` = 235219;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (235219, 'spell_mage_cold_snap_custom');

-- Spell Script for 112965 - Fingers of Frost Updated
DELETE FROM `spell_script_names` WHERE `spell_id` = 112965;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (112965, 'spell_mage_fingers_of_frost_custom');

-- Spell Script for // 44614 - Flurry (cast) - Manual missile control
DELETE FROM `spell_script_names` WHERE `spell_id` = 44614;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (44614, 'spell_mage_flurry_custom');

-- Spell Script for // 228598 - Ice Lance (damage)
DELETE FROM `spell_script_names` WHERE `spell_id` = 228598;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (228598, 'spell_mage_ice_lance_damage_custom');

-- Spell Script for // 205021 - Ray of Frost spell and aura pair
DELETE FROM `spell_script_names` WHERE `spell_id` = 205021;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (205021, 'spell_mage_ray_of_frost_custom');

-- Spell Script for Flame ON is no longer needed as effect is handled by core.
DELETE FROM `spell_script_names` WHERE `spell_id` = 205029;
