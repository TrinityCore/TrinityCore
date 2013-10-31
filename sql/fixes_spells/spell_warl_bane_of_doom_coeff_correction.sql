/*
SQLyog Ultimate v9.63 
MySQL - 5.6.14 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

create table `spell_bonus_data` (
	`entry` mediumint (8),
	`direct_bonus` float ,
	`dot_bonus` float ,
	`ap_bonus` float ,
	`ap_dot_bonus` float ,
	`comments` varchar (765)
); 
insert into `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) values('603','0','0.88','-1','-1','Warlock - Bane of Doom');
