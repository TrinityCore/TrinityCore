delete from spell_trigger where spell_id = 109186 and aura in (33076,47750);
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
(109186, 114255, 13, 0, 0, 0, 0, 0, 0, 7, 33076, 0, 0, 'Свет и Тьма тригер Пробуждение Света'),
(109186, 114255, 13, 0, 0, 0, 0, 0, 0, 7, 47750, 0, 0, 'Свет и Тьма тригер Пробуждение Света');

delete from spell_proc_check where entry = 109186 and checkspell in (33076,47750);
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(109186, 0, 0, 33076, 0, 15, 0, 7, 0, 0, 'Свет и Тьма прок от Молитва восстановления'),
(109186, 0, 0, 47750, 0, 15, 0, 7, 0, 0, 'Свет и Тьма прок от Исповедь');