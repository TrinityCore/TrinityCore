DELETE FROM `spell_area` WHERE  `spell`=42316 AND `area`=2079 AND `quest_start`=11142 AND `aura_spell`=0 AND `racemask`=1101 AND `gender`=2;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -42385;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-42385, 42316, 0, 'On remove Alcaz Survey Aura - cast Alcaz Survey Credit');
