delete from spell_proc_check where entry = 144586;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(144586, 0, 0, 59578, 0, 0, 0, 7, 0, 0, 'Item - Paladin T16 Retribution 2P Bonus');

delete from spell_linked_spell where spell_trigger = 59578 and spell_effect = 144587;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(59578, 144587, 0, 144586, 0, 0, 0, 0, 0, 0, 'Item - Paladin T16 Retribution 2P Bonus');