-- 
DROP TABLE IF EXISTS `creature_template_sparring`;
CREATE TABLE `creature_template_sparring` (
  `Entry` int unsigned NOT NULL,
  `NoNPCDamageBelowHealthPct` float NOT NULL,
  PRIMARY KEY (`Entry`,`NoNPCDamageBelowHealthPct`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- transition from old sparring system
DELETE FROM `creature_template_sparring` WHERE `Entry` IN(32882,32883,32885,32886,32907,32908);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(32882, 100),
(32883, 100),
(32885, 100),
(32907, 100),
(32908, 100);

-- example in sentinel hill
DELETE FROM `creature_template_sparring` WHERE `Entry` IN(54372, 54373, 54371, 42407);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(54372, 85),
(54373, 85),
(54371, 85),
(42407, 85),
(51915, 85);
