--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 54355 AND `spell_effect` = 54402;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(54355, 54402, 0, 'Land Mine');
