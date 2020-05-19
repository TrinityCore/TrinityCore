DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_gen_cauldron_of_battle',
'spell_gen_flask_of_battle');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92649, 'spell_gen_cauldron_of_battle'),
(92712, 'spell_gen_cauldron_of_battle'),
(92679, 'spell_gen_flask_of_battle');

UPDATE `gameobject_template` SET `ScriptName`= 'go_cauldron_of_battle' WHERE `entry` IN (207354, 207357, 207356, 207358);
