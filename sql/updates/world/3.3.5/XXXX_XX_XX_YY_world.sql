-- Assign first aid anti-venom items spellscript
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_antivenom';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(7932, 'spell_item_antivenom'),
(7933, 'spell_item_antivenom'),
(23786, 'spell_item_antivenom');
