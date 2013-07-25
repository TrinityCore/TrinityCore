DELETE FROM `spell_dbc` WHERE `Id`=123456;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `SpellInterruptsId`, `Comment`) VALUES
(123456, 0, 0, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Halion - Summon Twilight Portals');

DELETE FROM `spelleffect_dbc` WHERE `Id` IN (153096,153097);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectValueMultiplier`, `EffectApplyAuraName`, `EffectAplitude`, `EffectBasePoints`, `EffectBonusMultiplier`, `EffectDamageMultiplier`, `EffectChainTarget`, `EffectDieSides`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`) VALUES
(153096, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202796, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 123456, 1),
(153097, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202796, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 123456, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_halion_summon_exit_portals';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(153097, 'spell_halion_summon_exit_portals');
