CREATE TABLE `spell_enchant_proc_data` (
  `entry` INT(10) UNSIGNED NOT NULL,
  `customChance` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `PPMChance` FLOAT UNSIGNED NOT NULL DEFAULT '0', 
  `procEx` FLOAT UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Spell enchant proc data';

-- Frostbrand Weapon
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (2, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (12, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (524, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (1667, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (1668, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (2635, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (3782, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (3783, 0, 8.8,0);
INSERT INTO spell_enchant_proc_data (`entry`, `customChance`, `PPMChance`,`procEx`) VALUES (3784, 0, 8.8,0);