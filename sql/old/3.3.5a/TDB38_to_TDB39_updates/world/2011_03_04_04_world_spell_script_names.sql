DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_gift_of_the_harvester';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_death_gate';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(52481, 'spell_item_gift_of_the_harvester'),
(52751, 'spell_dk_death_gate');
