ALTER TABLE `trinworld542`.`areatrigger_data`   
  DROP COLUMN `Radius`, 
  DROP COLUMN `RadiusTarget`, 
  ADD COLUMN `spellId` INT(11) DEFAULT 0  NOT NULL AFTER `entry`,
  CHANGE `customEntry` `customEntry` INT(11) DEFAULT 0  NOT NULL  AFTER `spellId`,
  CHANGE `customVisualId` `customVisualId` INT(11) DEFAULT 0  NOT NULL  AFTER `customEntry`,
  CHANGE `sphereScale` `Radius` FLOAT UNSIGNED DEFAULT 1  NOT NULL,
  CHANGE `sphereScaleMax` `RadiusTarget` FLOAT UNSIGNED DEFAULT 0  NOT NULL,
  CHANGE `Height` `Height` FLOAT DEFAULT 0  NOT NULL  AFTER `RadiusTarget`,
  CHANGE `HeightTarget` `HeightTarget` FLOAT DEFAULT 0  NOT NULL  AFTER `Height`,
  CHANGE `Float4` `Float4` FLOAT DEFAULT 0  NOT NULL  AFTER `HeightTarget`,
  CHANGE `Float5` `Float5` FLOAT DEFAULT 0  NOT NULL  AFTER `Float4`,
  CHANGE `x` `windX` FLOAT DEFAULT 0  NOT NULL,
  CHANGE `y` `windY` FLOAT DEFAULT 0  NOT NULL,
  CHANGE `z` `windZ` FLOAT DEFAULT 0  NOT NULL,
  CHANGE `o` `windSpeed` FLOAT DEFAULT 0  NOT NULL,
  ADD COLUMN `windType` INT(11) DEFAULT 0  NOT NULL AFTER `windSpeed`,
  ADD COLUMN `polygon` INT(11) DEFAULT 0  NOT NULL AFTER `windType`;
  
  CREATE TABLE `areatrigger_polygon` (
  `entry` int(11) NOT NULL DEFAULT '0',
  `spellId` int(11) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL DEFAULT '0',
  `x` float NOT NULL DEFAULT '0',
  `y` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`,`spellId`,`id`),
  KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;