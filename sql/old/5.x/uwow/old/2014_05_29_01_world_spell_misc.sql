update spell_group set spell_id = 127830 where spell_id = 128997;

delete from spell_linked_spell where spell_trigger = 128997 and spell_effect = 127830;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(128997, 127830, 0, 0, 0, 0, 0, 0, 0, 0, 'Hunter - Spirit Beast Blessing');