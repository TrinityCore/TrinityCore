-- Dummy effect with caster as target
DELETE FROM `spell_dbc` WHERE `id` IN (68308);
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`Effect1`,`EffectImplicitTargetA1`,`EffectImplicitTargetB1`,`comment`)
VALUES
(68308, 0x09800100, 0x00000420, 0x00004005, 0x10040000, 0x00000080, 0x00000008, 0x00001000, 3, 1, 0, 'Vault of Archavon - Earth, Wind & Fire - Achievement Check');
