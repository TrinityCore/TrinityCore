-- It looked like 34000 and 34001 are heroic and normal entries but they're not. Even in CreatureDifficulty they are separate entries
-- Spell 64206 is simply not used but looks like was created for heroic, 64207 probably triggers it
-- We'll use 64209 as trigger of 64208
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectDieSides1` = 1, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 23, `EffectAmplitude1` = 1000, `EffectTriggerSpell1` = 64208, `DmgMultiplier1` = 1 WHERE `Id` = 64209;

UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_consumption' WHERE `ScriptName` = 'spell_four_horsemen_consumption';

DELETE FROM `spell_script_names` WHERE `spell_id` = 64208 AND `ScriptName` = 'spell_gen_consumption';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64208,'spell_gen_consumption');
