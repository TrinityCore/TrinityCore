delete from spell_proc_event where entry = 54936;
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values('54936','0','0','0','0','0','0','16384','3','0','100','0','7');
delete FROM spell_proc_check WHERE entry IN (54936);
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('54936','0','0','114163','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Символ торжества');
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('54936','0','0','130551','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Символ торжества');
delete from spell_linked_spell where spell_trigger = 53385 or spell_effect = -144595;
delete from spell_linked_spell where spell_trigger = 53385 or spell_effect = 144595;
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values('53385','144595','0','0','0','144593','0','25','0','0','0','0','0','cast Divine Storm add aura Divine Purpose');

delete from spell_proc_event where entry = 48484;
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('48484','0','0','33876','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Зараженные раны');
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('48484','0','0','33878','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Зараженные раны');
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('48484','0','0','6807','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Зараженные раны');
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('48484','0','0','6785','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Зараженные раны');
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('48484','0','0','5221','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Зараженные раны');

delete FROM spell_proc_check WHERE entry IN (146874);
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('146874','0','0','0','0','0','0','7','-1','-1','0','0','0','0','0','0','0','1','0','0','Звериное неистовство');
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('146874','0','0','127538','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Звериное неистовство');

delete FROM spell_linked_spell WHERE spell_effect IN (138916);
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values('1833','138916','0','0','0','138106','-51713','0','0','0','0','0','0','Рыцарь плаща и кинжала');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values('703','138916','0','0','0','138106','-51713','0','0','0','0','0','0','Рыцарь плаща и кинжала');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values('8676','138916','0','0','0','138106','-51713','0','0','0','0','0','0','138916');

insert ignore into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values
('3408','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-121733','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('5761','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-121733','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('108211','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-121733','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108215','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Паралитический яд'),
('108215','0','0','-121733','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Паралитический яд'),
('108215','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Паралитический яд'),
('108215','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Паралитический яд'),
('108215','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Паралитический яд');

delete FROM spell_trigger WHERE spell_id IN (76838);
insert into `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `procFlags`, `procEx`, `check_spell_id`, `addptype`, `schoolMask`, `dummyId`, `dummyEffect`, `comment`) values('76838','76858','0','20','0','0','0','0','0','0','1','0','200','0','0','0','0','-1','0','0','0','Искусность: удача в бою');

ALTER TABLE `pet_stats`   
  ADD COLUMN `haste` INT(3) DEFAULT 1  NOT NULL AFTER `damage`;

insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('78203','0','0','124464','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Сумеречный призрак');

delete from spell_linked_spell where spell_trigger = 123258 or spell_effect = -17;
delete from spell_linked_spell where spell_trigger = 17 or spell_effect = -123258;

insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values('124465','34919','0','0','0','0','0','0','0','0','0','0','0','Прикосновение вампира');
