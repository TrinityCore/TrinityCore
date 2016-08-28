DELETE FROM `spell_script_names` WHERE `spell_id`= 94949;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(94949, 'spell_anhuur_divine_reckoning');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 75322;
INSERT INTO `spell_linked_spell` VALUES (75322, 74938, 0, 'Reverberating Hymn - Cast Light Shield');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15988;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15988, 11, 0, 0, 'achievement_hate_that_song');
