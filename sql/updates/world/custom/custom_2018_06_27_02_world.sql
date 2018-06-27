-- Thrashing Charge
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 43743;
-- Crystal Shard
UPDATE `creature_template` SET `ScriptName`= 'npc_crystal_shard' WHERE `entry`= 49267;

DELETE FROM `creature_template_addon` WHERE `entry`= 49267;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(49267, '92079');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_corborus_crystal_barrage_targeting',
'spell_corborus_crystal_barrage');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81634, 'spell_corborus_crystal_barrage_targeting'),
(81638, 'spell_corborus_crystal_barrage');

-- Serverside spells
DELETE FROM `spell_dbc` WHERE `Id`= 92079;
INSERT INTO `spell_dbc`(`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES
(92079, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Shrink');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160083;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectApplyAuraName`, `EffectBasePoints`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160083, 6, 61, -90, 0, 0, 0, 0, 0, 0, 92079, 0, 'Shrink');
