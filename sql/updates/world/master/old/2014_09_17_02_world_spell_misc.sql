delete from spell_proc_check where entry = 56453;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(56453, 0, 0, 53301, -144641, 0, 0, 1, -1, -1, 'На изготовку! - Разрывной выстрел'),
(56453, 0, 0, 53301, 144641, 20, 0, 7, -1, -1, 'Разрывной выстрел - Item - Hunter T16 4P Bonus'),
(144671, 0, 0, 0, 34471, 0, 0, 7, -1, -1, 'Item - Hunter T16 BM 4P Player Driver'),
(145738, 0, 0, 0, 19574, 0, 0, 7, -1, -1, 'Item - Hunter T16 BM 4P Pet Driver');

delete from spell_linked_spell where spell_trigger = 82928 and spell_effect = 144659;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(82928, 144659, 0, 0, 0, 144641, 0, 0, 0, 0, 0, 0, 'Item - Hunter T16 4P Bonus - Aim Shot');

delete from spell_trigger where spell_id = 144641;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
(144641, 144671, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 'Item - Hunter T16 BM 4P Player Driver'),
(144641, 145738, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 'Item - Hunter T16 BM 4P Pet Driver');

delete from spell_proc_event where entry in (144671, 145738);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(144671, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0, 7),
(145738, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 7);