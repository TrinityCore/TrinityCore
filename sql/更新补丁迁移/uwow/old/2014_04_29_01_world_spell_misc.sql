delete from spell_proc_check where entry = 144613;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(144613, 0, 0, 31842, 0, 0, 0, 7, 0, 0, 'Item - Paladin T16 Holy 4P Bonus');

delete from spell_linked_spell where spell_trigger = 59578 and spell_effect = 144587;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(31842, 144622, 0, 144613, 0, 0, 0, 0, 0, 0, 'Item - Paladin T16 Holy 4P Bonus');