delete from spell_proc_check where entry = 144624;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(144624, 0, 0, 635, 0, 0, 0, 7, 0, 0, 'Item - Paladin T16 Holy 4P Bonus'),
(144624, 0, 0, 82326, 0, 0, 0, 7, 0, 0, 'Item - Paladin T16 Holy 4P Bonus'),
(144624, 0, 0, 82327, 0, 0, 0, 7, 0, 0, 'Item - Paladin T16 Holy 4P Bonus');

delete from spell_proc_check where entry = 144625;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(144625, 0, 0, 54149, 0, 0, 0, 7, 0, 0, 'Item - Paladin T16 Holy 4P Bonus');

delete from spell_linked_spell where spell_trigger = 54149 and spell_effect = 144624;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(54149, 144624, 0, 144625, 0, 0, 0, 0, 0, 0, 'Item - Paladin T16 Holy 2P Bonus');