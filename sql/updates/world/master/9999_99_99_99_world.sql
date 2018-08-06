DROP TABLE IF EXISTS `pet_levelstats`; 

DROP TABLE IF EXISTS `pet_owner_benefit`;
CREATE TABLE IF NOT EXISTS `pet_owner_benefit` (
  `entry` mediumint(8) unsigned NOT NULL,
  `ap_multiplier` float unsigned NOT NULL DEFAULT '0',
  `sp_multiplier` float unsigned NOT NULL DEFAULT '0',
  `sp_to_ap_multiplier` float unsigned NOT NULL DEFAULT '0',
  `health_multiplier` float unsigned NOT NULL DEFAULT '0',
  `armor_multiplier` float unsigned NOT NULL DEFAULT '0',
  `Comment` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

DELETE FROM `pet_owner_benefit`;
INSERT INTO `pet_owner_benefit` (`entry`, `ap_multiplier`, `sp_multiplier`, `sp_to_ap_multiplier`, `health_multiplier`, `armor_multiplier`, `Comment`) VALUES
(89, 0, 0, 1, 0.5, 4, 'INFERNAL'),
(416, 0, 0, 1, 0.3, 3, 'IMP'),
(417, 0, 0, 1.2, 0.4, 3, 'FELHUNTER'),
(1860, 0, 0, 1.2, 0.5, 4, 'VOIDWALKER'),
(1863, 0, 0, 0.6, 0.4, 3, 'SUCCUBUS'),
(11859, 0, 0, 0.066, 0.4, 3, 'DOOMGUARD'),
(17252, 0, 0, 1.2, 0.5, 4, 'FELGUARD'),
(55659, 0, 0, 1, 0.15, 3, 'WILD_IMP'),
(63508, 0.6, 0, 0, 1, 1, 'XUEN'),
(73967, 1, 0, 0, 1, 4, 'NIUZAO'),
(78158, 0, 0, 0.066, 0.4, 3, 'DOOMGUARD_PET'),
(78217, 0, 0, 1, 0.5, 4, 'INFERNAL_PET'),
(98035, 0, 0, 0, 0.4, 3, 'DREADSTALKER'),
(100324, 1.15, 0, 0, 0.2, 1.25, 'HATI_NORMAL'),
(100868, 1, 0, 0, 1, 1, 'CHI_JI'),
(103673, 0, 0, 1, 0.4, 0, 'DARKGLARE'),
(104493, 1.15, 0, 0, 0.2, 1.25, 'SPITTING_COBRA'),
(106548, 1.15, 0, 0, 0.2, 1.25, 'HATI_HIDDEN_SKIN'),
(106549, 1.15, 0, 0, 0.2, 1.25, 'HATI_HIDDEN_SKIN_2'),
(106550, 1.15, 0, 0, 0.2, 1.25, 'HATI_HIDDEN_SKIN_3'),
(106551, 1.15, 0, 0, 0.2, 1.25, 'HATI_HIDDEN_SKIN_4'),
(108452, 0, 0, 1, 0.5, 4, 'INFERNAL_LORD_OF_FLAMES');
