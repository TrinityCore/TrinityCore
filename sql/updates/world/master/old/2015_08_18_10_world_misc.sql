DELETE FROM `spell_script_names` WHERE (`spell_id`='34026') AND (`ScriptName`='spell_hun_glyph_of_marked_for_die');
DELETE FROM `spell_script_names` WHERE (`spell_id`='3044') AND (`ScriptName`='spell_hun_glyph_of_marked_for_die');
DELETE FROM `spell_script_names` WHERE (`spell_id`='34026') AND (`ScriptName`='spell_hun_glyph_of_marked_for_die_pet');
DELETE FROM `spell_script_names` WHERE (`spell_id`='53209') AND (`ScriptName`='spell_hun_glyph_of_marked_for_die');
DELETE FROM `spell_script_names` WHERE (`spell_id`='53301') AND (`ScriptName`='spell_hun_glyph_of_marked_for_die');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('1130', 'spell_hun_of_marked_for_die');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type2`, `hitmask`, `comment`) VALUES ('3044', '1130', '8', '1', 'Hunter\'s Mark');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type2`, `hitmask`, `comment`) VALUES ('53209', '1130', '8', '1', 'Hunter\'s Mark');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type2`, `hitmask`, `comment`) VALUES ('53301', '1130', '8', '1', 'Hunter\'s Mark');