DROP TABLE IF EXISTS `character_template`;
CREATE TABLE IF NOT EXISTS `character_template` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(70) NOT NULL,
  `description` varchar(100) NOT NULL,
  `level` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `character_template_class`;
CREATE TABLE IF NOT EXISTS `character_template_class` (
  `templateId` int(10) unsigned NOT NULL,
  `factionGroup` tinyint(3) unsigned NOT NULL COMMENT '3 - Alliance, 5 - Horde',
  `class` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`templateId`,`factionGroup`,`class`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
