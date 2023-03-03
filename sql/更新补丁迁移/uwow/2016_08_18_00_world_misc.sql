UPDATE `spell_linked_spell` SET `type`='1' WHERE `spell_trigger`='20271' AND `spell_effect`='110300'; 

UPDATE `spell_linked_spell` SET `removeMask`='8' WHERE `spell_trigger`='-119611' AND `spell_effect`='115867' AND `hastalent`='131561'; 

UPDATE `creature_template` SET `spell1`='47468',`spell2`='47481',`spell3`='47482',`spell4`='47484' WHERE `entry`='26125'; 
UPDATE `spell_linked_spell` SET `hastalent`='-63560' WHERE `spell_trigger`='47468' AND `spell_effect`='91776'; 
UPDATE `spell_linked_spell` SET `hastalent`='-63560' WHERE `spell_trigger`='47481' AND `spell_effect`='91800'; 
UPDATE `spell_linked_spell` SET `hastalent`='-63560' WHERE `spell_trigger`='47482' AND `spell_effect`='91809'; 
UPDATE `spell_linked_spell` SET `hastalent`='-63560' WHERE `spell_trigger`='47484' AND `spell_effect`='91838'; 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`='17' AND `ConditionValue1`='63560';

UPDATE `spell_proc_event` SET `Cooldown`='2' WHERE `entry`='86172'; 

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='-55686' AND `spell_effect`='-588';

INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`caster`,`target`,`hastype`,`hastalent`,`hastype2`,`hastalent2`,`chance`,`cooldown`,`duration`,`hitmask`,`removeMask`,`targetCountType`,`targetCount`,`actiontype`,`group`,`comment`) VALUES 
('-55686','-588','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','Символ внутреннего огня - снимаем ауру'); 

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='-98397' AND `comment`='Символ доспехов - снимаем ауру';
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`caster`,`target`,`hastype`,`hastalent`,`hastype2`,`hastalent2`,`chance`,`cooldown`,`duration`,`hitmask`,`removeMask`,`targetCountType`,`targetCount`,`actiontype`,`group`,`comment`) VALUES 
('-98397','-6117','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','Символ доспехов - снимаем ауру'),
('-98397','-30482','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','Символ доспехов - снимаем ауру'),
('-98397','-7302','0','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','Символ доспехов - снимаем ауру'); 

DELETE FROM `spell_linked_spell` WHERE `hastalent`='108839'; 
DELETE FROM `spell_proc_event` WHERE `entry`='108839' AND `effectmask`='7'; 
INSERT INTO `spell_proc_event`(`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`,`effectmask`) VALUES 
('108839','0','0','0','0','0','0','87040','0','0','0','0','7'); 

DELETE FROM `spell_proc_check` WHERE `entry`='108839'; 
INSERT INTO `spell_proc_check`(`entry`,`entry2`,`entry3`,`checkspell`,`hastalent`,`chance`,`target`,`effectmask`,`powertype`,`dmgclass`,`specId`,`spellAttr0`,`targetTypeMask`,`mechanicMask`,`fromlevel`,`perchp`,`spelltypeMask`,`combopoints`,`deathstateMask`,`hasDuration`,`comment`) VALUES 
('108839','0','0','-7268','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Плавучая льдина'),
('108839','0','0','-5143','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Плавучая льдина'),
('108839','0','0','-136511','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Плавучая льдина'),
('108839','0','0','-140384','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Плавучая льдина'),
('108839','0','0','-82691','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Плавучая льдина'); 

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='5143' AND `spell_effect`='-108839';
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`caster`,`target`,`hastype`,`hastalent`,`hastype2`,`hastalent2`,`chance`,`cooldown`,`duration`,`hitmask`,`removeMask`,`targetCountType`,`targetCount`,`actiontype`,`group`,`comment`) VALUES 
('5143','-108839','8','0','0','0','0','0','0','0','0','0','0','0','0','-1','0','0','Чародейские стрелы - плавучая льдина'); 

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='115268' AND `spell_effect`='-3'; 
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`='6358' AND `spell_effect`='-3'; 
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`caster`,`target`,`hastype`,`hastalent`,`hastype2`,`hastalent2`,`chance`,`cooldown`,`duration`,`hitmask`,`removeMask`,`targetCountType`,`targetCount`,`actiontype`,`group`,`comment`) VALUES 
('115268','-3','2','0','0','0','56249','0','0','0','0','0','1','0','0','-1','2','0','Символ обучения демона'),
('6358','-3','2','0','0','0','56249','0','0','0','0','0','1','0','0','-1','2','0','Символ обучения демона'); 

UPDATE `spell_proc_event` SET `procFlags`='20' WHERE `entry`='108211'; 
DELETE FROM `spell_proc_check` WHERE `entry`='108211';
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES
('108211','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд'),
('108211','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Похищающий жизнь яд');

UPDATE `spell_proc_event` SET `procFlags`='20' WHERE `entry`='5761'; 
DELETE FROM `spell_proc_check` WHERE `entry`='5761';
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES
('5761','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд'),
('5761','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Дурманящий яд');

UPDATE `spell_proc_event` SET `procFlags`='20' WHERE `entry`='3408'; 
DELETE FROM `spell_proc_check` WHERE `entry`='3408';
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES
('3408','0','0','-137586','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-137585','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-137584','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд'),
('3408','0','0','-114014','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Калечащий яд');