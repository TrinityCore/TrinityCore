DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pal_blessing_of_protection',
'spell_pal_divine_shield');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1022,   'spell_pal_blessing_of_protection'),
(204018, 'spell_pal_blessing_of_protection'),
(642,    'spell_pal_divine_shield');
