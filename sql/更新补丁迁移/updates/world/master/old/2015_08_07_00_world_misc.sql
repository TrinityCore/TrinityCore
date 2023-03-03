/*
SQLyog Community v12.12 (64 bit)
MySQL - 5.6.24-log 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

replace into `spell_trigger_dummy` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `check_spell_id`, `comment`) values('97462','97463','38','0','0','0','0','0','0','7','0','0','0','0','Ободряющий клич');
replace into `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) values('97462','56','6','0','0','0','0','0','7','0','0','0','0','0','Ободряющий клич');
replace into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values('53385','144595','0','0','0','144593','0','25','0','0','0','0','0','cast Divine Storm add aura Divine Purpose');
delete FROM spell_proc_event WHERE entry IN (86703);
delete FROM spell_proc_event WHERE entry IN (62459);
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values('62459','0','0','0','0','0','0','0','3','0','0','0','7');

