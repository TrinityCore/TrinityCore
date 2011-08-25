-- Not the right-way™
-- Dummy effect with caster as target
DELETE FROM `spell_dbc` WHERE `id` IN (68308);
INSERT INTO `spell_dbc` (`Id`,`Effect1`,`EffectImplicitTargetA1`,`EffectImplicitTargetB1`,`comment`)
VALUES
(68308, 3, 1, 0, 'Vault of Archavon - Earth, Wind & Fire - Achievement Check');
