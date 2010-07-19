-- For quest: Truce?
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=50141;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(50141,50001,0, 'Blood Oath to Blood Oath Aura');
