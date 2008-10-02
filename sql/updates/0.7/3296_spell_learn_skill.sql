DROP TABLE IF EXISTS `spell_learn_skill`;
CREATE TABLE `spell_learn_skill` (
  `entry` smallint(6) unsigned NOT NULL default '0',
  `SkillID` smallint(6) NOT NULL default '0',
  `Value` int(11) default '0',
  `MaxValue` int(11) default '0',
  PRIMARY KEY (`entry`),
  UNIQUE KEY spell_skill(`entry`,`SkillID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

INSERT INTO `spell_learn_skill` VALUES 
/*================== Armor ============*/
/*Cloth            */( 9078,415,  1,  1),
/*Leather          */( 9077,414,  1,  1),
/*Mail             */( 8737,413,  1,  1),
/*Plate Mail       */(  750,293,  1,  1),
/*Shield           */( 9116,433,  1,  1),
/*================== Melee Weapons ====*/
/*Axes             */(  196, 44,  1,  0),
/*Two-Handed Axes  */(  197,172,  1,  0),
/*Staves           */(  227,136,  1,  0),
/*Maces            */(  198, 54,  1,  0),
/*Two-Handed Maces */(  199,160,  1,  0),
/*Swords           */(  201, 43,  1,  0),
/*Two-Handed Swords*/(  202, 55,  1,  0),
/*Daggers          */( 1180,173,  1,  0),
/*Fist Weapons     */(15590,473,  1,  0),
/*Polearms         */(  200,229,  1,  0),
/*Spears (Polearms)*/( 3386,229,  1,  0),
/*================== Range Weapons ====*/
/*Bows             */(  264, 45,  1,  0),
/*Crossbows        */( 5011,226,  1,  0),
/*Guns             */(  266, 46,  1,  0),
/*Thrown           */( 2567,176,  1,  0),
/*Wands            */( 5009,228,  1,  0),
/*================== Others ===========*/
/*Poisons          */( 2842, 40,  1,  0),
/*Min riding       */(33388,762, 75, 75),
/*Mid riding       */(33391,762,150,150),
/*Pick Lock(Rogue) */( 1804,633,  1,  0),
/*================== Languages ========*/
                     (  668, 98, -1, -1),
                     (  669,109, -1, -1),
                     (  670,115, -1, -1),
                     (  671,113, -1, -1),
                     (  672,111, -1, -1),
                     (  813,137, -1, -1),
                     (  814,138, -1, -1),
                     (  815,139, -1, -1),
                     (  816,140, -1, -1),
                     (  817,141, -1, -1),
                     ( 7340,313, -1, -1),
                     ( 7341,315, -1, -1),
                     (17737,673, -1, -1),
/*================== Generic Skills ===*/
/*Defense          */(  204, 95,  1,  0),
/*Unarmed          */(  203,162,  1,  0);
