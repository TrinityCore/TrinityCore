UPDATE `spell_dbc` SET `Attributes`= 0xA9800100, `AttributesEx`= 0x10000420, `AttributesEx2`= 0x00084005, `AttributesEx3`= 0x10170300, `AttributesEx4`= 0x00000080, `AttributesEx5`= 0x00060009, `AttributesEx6`= 0x00001400, `AttributesEx7`= 0x02000000, `AttributesEx8`= 0x00000020, `DurationIndex`= 36, `RangeIndex`= 13 WHERE `Id` IN (110158, 111533);
DELETE FROM `spelleffect_dbc` WHERE `Id` IN (160095, 160096);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectApplyAuraName`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160095, 6, 4, 0, 0, 0, 28, 22, 7, 110158, 0, 'Moruzond Achievement Spell'),
(160096, 6, 4, 0, 0, 0, 28, 22, 7, 111533, 0, 'Madness of Deathwing Achievement Spell');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_dungeon_credit' AND `spell_id` IN (110158, 111533, 105576);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(110158, 'spell_gen_dungeon_credit'),
(111533, 'spell_gen_dungeon_credit'),
(105576, 'spell_gen_dungeon_credit');
