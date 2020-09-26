DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_launch_quest_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93081, 'spell_gen_launch_quest_aura'),
(93216, 'spell_gen_launch_quest_aura');

DELETE FROM `spell_area` WHERE `spell` IN (93081, 93216);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `flags`) VALUES
(93081, 1637, 2, 1),
(93216, 1519, 2, 1);
