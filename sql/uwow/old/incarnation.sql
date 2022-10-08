DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_incarnation';
REPLACE INTO spell_script_names VALUES
(102543, 'spell_dru_incarnation'),
(102558, 'spell_dru_incarnation'),
(102560, 'spell_dru_incarnation'),
(33891, 'spell_dru_incarnation');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (33891, -33891);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_incarnation_tree_of_life';
REPLACE INTO spell_script_names VALUES
(117679, 'spell_dru_incarnation_tree_of_life');