DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_artifical_stamina','spell_item_artifical_damage');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(211309,'spell_item_artifical_stamina'),
(213428,'spell_item_artifical_damage'),
(219655,'spell_item_artifical_damage'),
(226829,'spell_item_artifical_damage');
