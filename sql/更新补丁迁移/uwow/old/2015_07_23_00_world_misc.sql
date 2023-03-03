replace into `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `procFlags`, `procEx`, `check_spell_id`, `addptype`, `schoolMask`, `dummyId`, `dummyEffect`, `comment`) values
('144841','146874','0','20','1','0','0','0','0','0','7','0','0','0','0','0','0','3','0','0','0','Item - Druid T16 Feral 4P Bonus');
insert into `world_visible_distance` (`type`, `id`, `distance`, `comment`) values('2','5170','50','Огриммар: Алея силы');
insert into `world_visible_distance` (`type`, `id`, `distance`, `comment`) values('2','5356','35','Огриммар: Крепость Громмаш');

DELETE FROM spell_proc_check WHERE entry IN (145738,144671);
DELETE FROM spell_trigger WHERE spell_id IN (144641);
replace into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values
('34471','144671','0','0','0','144641','0','0','0','0','0','0','0','Item - Hunter T16 4P Bonus'),
('19574','145738','0','0','0','144641','0','0','0','0','0','0','0','Item - Hunter T16 4P Bonus');