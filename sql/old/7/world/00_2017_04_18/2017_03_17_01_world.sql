-- Class: Warrior
-- Spell: Bloodthirst

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_bloodthirst';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(23881,'spell_warr_bloodthirst');
