UPDATE `creature_template` SET `ScriptName`='npc_illidari_elite' WHERE `entry`=23226;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_illidan_remove_parasitic_shadowfiend';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41923,'spell_illidan_remove_parasitic_shadowfiend');

DELETE FROM `spell_dbc` WHERE `Id`=41923;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `SpellInterruptsId`, `Comment`) VALUES
(41923, 536871296, 268435592, 4, 256, 0, 8, 0, 0, 0, 0, 0, 1, 27, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Parasitic Shadowfiends');

DELETE FROM `spelleffect_dbc` WHERE `Id`=155918;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectValueMultiplier`, `EffectApplyAuraName`, `EffectAmplitude`, `EffectBasePoints`, `EffectBonusMultiplier`, `EffectDamageMultiplier`, `EffectChainTarget`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`) VALUES
(155918, 6, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 22, 15, 41923, 0);
