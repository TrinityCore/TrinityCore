update spell_dummy_trigger SET target = 3 where target = 1;
update spell_dummy_trigger SET caster = 5 where caster = 1;
update spell_dummy_trigger SET target = 1 where target = 2;
update spell_dummy_trigger SET `option` = 6 where `option` = 8;

ALTER TABLE `spell_linked_spell`   
  ADD COLUMN `targetCountType` TINYINT(3) DEFAULT 0  NOT NULL AFTER `removeMask`,
  ADD COLUMN `targetCount` TINYINT(3) DEFAULT -1  NOT NULL AFTER `targetCountType`,
  CHANGE `actiontype` `actiontype` TINYINT(3) DEFAULT 0  NOT NULL;
ALTER TABLE `spell_linked_spell`   
  ADD COLUMN `group` TINYINT(3) DEFAULT 0  NOT NULL AFTER `actiontype`;
ALTER TABLE `spell_linked_spell`
  ADD COLUMN `duration` INT(11) DEFAULT 0  NOT NULL AFTER `cooldown`;
ALTER TABLE `spell_linked_spell`
  DROP INDEX `trigger_effect_type`,
  ADD  UNIQUE INDEX `trigger_effect_type` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `actiontype`);

DELETE FROM spell_dummy_trigger WHERE spell_id IN (119905,119907,119913,119911,119909,119910,119914,119915);
insert into `spell_dummy_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) values
('119905','119899','4','0','1','0','0','0','0','7','0','0','Прижигание ран хозяина (Особая способность)'),
('119907','0','4','0','1','0','0','0','0','7','0','0','Обезоруживание (Особая способность)'),
('119909','0','5','0','1','0','0','0','0','7','0','0','Удар кнутом (Особая способность)'),
('119910','0','4','0','1','0','0','0','0','7','0','0','Запрет чар (Особая способность)'),
('119911','0','4','0','1','0','0','0','0','7','0','0','Оптический удар (Особая способность)'),
('119913','0','5','0','1','0','0','0','0','7','0','0','Кнут Скверны (Особая способность)'),
('119914','89751','4','0','1','0','0','0','0','7','0','0','Буря Скверны (Особая способность)'),
('119915','115831','4','0','1','0','0','0','0','7','0','0','Буря гнева (Особая способность)');

DELETE FROM spell_linked_spell WHERE spell_effect IN (119905,119907,119913,119911,119909,119910,119914,119915);
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastype`, `hastalent`, `hastype2`, `hastalent2`, `chance`, `cooldown`, `hitmask`, `removeMask`, `actiontype`, `comment`) values
('119899','119905','0','2','0','0','0','0','0','0','0','0','0','3','Прижигание ран хозяина (Особая способность)'),
('118093','119907','0','2','0','0','0','0','0','0','0','0','0','3','Обезоруживание (Особая способность)'),
('115781','119911','0','2','0','0','0','0','0','0','0','0','0','3','Оптический удар (Особая способность)'),
('19647','119910','0','2','0','0','0','0','0','0','0','0','0','3','Запрет чар (Особая способность)'),
('89751','119914','0','2','0','0','0','0','0','0','0','0','0','3','Буря Скверны (Особая способность)'),
('115831','119915','0','2','0','0','0','0','0','0','0','0','0','3','Буря гнева (Особая способность)'),
('115770','119913','0','2','0','0','0','0','0','0','0','0','0','3','Кнут Скверны (Особая способность)'),
('6360','119909','0','2','0','0','0','0','0','0','0','0','0','3','Удар кнутом (Особая способность)');


