-- Class: Warrior
-- Spect: All
-- Spell: Charge Effect

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_charge_effect';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('218104', 'spell_warr_charge_effect');