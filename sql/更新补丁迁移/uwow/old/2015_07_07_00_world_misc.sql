/*
SQLyog Community v12.12 (64 bit)
MySQL - 5.6.24-log 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) values
('-5487','-106922','0','0','0','0','0','0','0','0','0','0','0','Мощь Урсока');

insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values
('145152','0','0','0','0','0','0','4112','0','0','0','0','7');

DELETE FROM spell_linked_spell WHERE spell_trigger = -22812 AND spell_effect = 132402;
