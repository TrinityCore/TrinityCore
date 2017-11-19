--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pal_blessing_of_protection',
 'spell_pal_divine_shield',
 'spell_pal_lay_on_hands');
INSERT INTO `spell_script_names` (`Spell_Id`, `ScriptName`) VALUES
(1022, 'spell_pal_blessing_of_protection'),
(642, 'spell_pal_divine_shield'),
(633, 'spell_pal_lay_on_hands');
