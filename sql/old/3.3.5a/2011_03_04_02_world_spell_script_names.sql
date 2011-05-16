DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_profession_research';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_book_of_glyph_mastery';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(60893, 'spell_gen_profession_research'),
(61177, 'spell_gen_profession_research'),
(61288, 'spell_gen_profession_research'),
(61756, 'spell_gen_profession_research'),
(64323, 'spell_item_book_of_glyph_mastery');
