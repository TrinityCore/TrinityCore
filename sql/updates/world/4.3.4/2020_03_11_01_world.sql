DELETE FROM `smart_scripts` WHERE `entryorguid`= 17155 AND `source_type`= 1;

DELETE FROM `spell_dbc` WHERE `Id`= 98413;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `DurationIndex`, `RangeIndex`, `SpellCastingRequirementsId`, `Comment`) VALUES
(98413, 0x29800100, 0x10000020, 0x00004005, 0x10100000, 0x00000080, 0x00060008, 0x00021600, 21, 13, 7577, '(Serverside/Non-DB2) See Quest Invis 22');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160098;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectApplyAuraName`, `EffectBasePoints`, `EffectMiscValue`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160098, 6, 19, 100, 30, 1, 0, 98413, 0, '(Serverside/Non-DB2) See Quest Invis 22');
