-- ----------------------------
-- Table structure for guildhouses
-- ----------------------------

DROP TABLE IF EXISTS `guildhouses`;

CREATE TABLE `guildhouses` (
  `id` int(8) unsigned NOT NULL auto_increment,
  `guildId` bigint(20) NOT NULL default '0',
  `x` double NOT NULL,
  `y` double NOT NULL,
  `z` double NOT NULL,
  `map` int(11) NOT NULL,
  `comment` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=42 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records
-- ----------------------------
INSERT INTO `guildhouses` VALUES
('1', '0', '16222', '16266', '14.2', '1', 'GM Island'),
('2', '0', '-10711', '2483', '8', '1', 'Tauren village at Veiled Sea (Silithus)'),
('3', '0', '-8323', '-343', '146', '0', 'Fishing outside an Northshire Abbey (Elwynn Forest'),
('4', '0', '7368', '-1560', '163', '1', 'Troll Village in mountains (Darkshore)'),
('5', '0', '-4151', '-1400', '198', '0', 'Dwarven village outside Ironforge (Wetlands)'),
('6', '0', '-1840', '-4233', '2.14', '0', 'Dwarven village (Arathi Highlands, Forbidding Sea)'),
('8', '0', '-723', '-1076', '179', '1', 'Tauren camp (Mulgore, Red Rock)'),
('9', '0', '-206', '1666', '80', '0', 'Shadowfang Keep an outside instance (Silverpine Forest)'),
('10', '0', '-6374', '1262', '7', '0', 'Harbor house outside Stormwind (Elwynn Forest)'),
('11', '0', '-8640', '580', '96', '0', 'Empty jail between canals (Stormwind)'),
('12', '0', '-4844', '-1066', '502', '0', 'Old Ironforge'),
('13', '0', '-4863', '-1658', '503.5', '0', 'Ironforge Airport'),
('14', '0', '1146', '-165', '313', '37', 'Azshara Crater instance (Alliance entrance)'),
('15', '0', '-123', '858', '298', '37', 'Azshara Crater instance (Horde entrance)'),
('16', '0', '4303', '-2760', '16.8', '0', 'Quel\'Thalas Tower'),
('17', '0', '-6161', '-790', '423', '0', 'Crashed gnome airplane (between Dun Morogh and Searing Gorge)'),
('18', '0', '-11790', '-1640', '54.7', '0', 'Zul\'Gurub an outside instance (Stranglethorn Vale)'),
('19', '0', '-11805', '-4754', '6', '1', 'Goblin village (Tanaris, South Seas)'),
('20', '0', '-9296', '670', '132', '0', 'Villains camp outside an Stormwind (Elwynn Forest)'),
('21', '0', '3414', '-3380', '142.2', '0', 'Stratholm an outside instance'),
('22', '0', '4654', '-3772', '944', '1', 'Kalimdor Hyjal (Aka World Tree)'),
('23', '0', '2176', '-4766', '55', '1', 'The Ring of Valor (Aka. Orgrimmar Arena)'),
('24', '0', '1951.512085', '1530.475586', '247.288147', '1', 'Stonetalon Logging Camp'),
('25', '0', '2813.660645', '2248.552979', '215.524643', '1', 'Stonetalon Ruins'),
('28', '0', '9725.27', '-21.43', '20.03', '1', 'Teldrassil Furbold camp'),
('29', '0', '-3855', '-3479', '579', '0', 'Wetlands mountain camp'),
('30', '0', '-5362', '-2540', '485', '0', 'Ortell\'s Hideout'),
('31', '0', '-12865', '-1396', '115', '0', 'Stranglethorn Secret Cave'),
('32', '0', '-11073', '-1956', '39', '0', 'Karazhan Smiley'),
('33', '0', '-11084', '-1801', '53', '0', 'Well of the Forgotten (Aka. Karazhan Crypt or Lower Karazhan)'),
('34', '0', '1683.235474', '286.458801', '-45.451775', '0', 'Undercity Top Tier'),
('35', '0', '-8521.3', '599.5', '101.399338', '0', 'Stormwind Cut-Throat Alley'),
('36', '0', '-5933', '452', '509', '0', 'Forgotten gnome camp'),
('37', '0', '-920.231323', '7096.489258', '170.35289', '530', 'Outland Nagrand : Newton\'s Remains'),
('38', '0', '-2140.501953', '9142.6875', '137.041855', '530', 'Outland Nagrand : Tomb'),
('39', '0', '-483.401794', '7461.944824', '186.120987', '530', 'Outland Nagrand: Challe\'s Home for Little Tykes'),
('40', '0', '2387.753906', '3191.757324', '152.669388', '530', 'Outland Netherstorm: Nova\'s Shrine');

-- *************************
-- * NPC Guildhouse Keeper *
-- *************************

DELETE FROM creature_template WHERE `entry`=13;

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('13','0','0','0','0','0','26789','0','0','0','Beltez','Guildhouse Keeper',NULL,'0','80','80','0','35','1','1','1.14286','0.75','0','0','1400','1900','1','1','1','0','0','8','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','1','3','1','1','1','1','1','1','0','0','1','0','0','guildmaster','12340');