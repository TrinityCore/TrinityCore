DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_item_discerning_eye_beast_dummy';

DELETE FROM `spelleffect_dbc` WHERE `Id`= 155920;
INSERT INTO `spelleffect_dbc` (`Id`, `EffectIndex`, `Effect`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectRadiusIndex`, `EffectSpellId`, `Comment`) VALUES
(155920, 0, 77, 22, 7, 12, 75880, 'Spawn Living Embers EFFECT_0');
