UPDATE `spell_dbc` SET `DurationIndex`= 3 WHERE `Id`= 61988;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_divine_shield',
 'spell_pal_hand_of_protection');
 
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1022, 'spell_pal_hand_of_protection'),
(642, 'spell_pal_divine_shield');
