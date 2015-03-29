--  assign spellscript for Spell: 'Infected Worgen Bite'

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=53095;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(53095,-53094,2,'Infected Worgen Bite - Worgen\'s Call Immunity');

DELETE FROM `spell_script_names` WHERE `spell_id`=53094;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53094,'spell_infected_worgen_bite');
