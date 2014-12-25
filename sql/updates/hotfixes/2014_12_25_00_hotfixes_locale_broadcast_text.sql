SET @world_db_name := 'world_db_name_goes_here_or_error_in_yo_face'; -- fill in your world database name

DROP TABLE IF EXISTS `locales_broadcast_text`;
CREATE TABLE `locales_broadcast_text` (
`ID`  mediumint(8) UNSIGNED NOT NULL DEFAULT 0 ,
`MaleText_loc1` longtext,
`MaleText_loc2` longtext,
`MaleText_loc3` longtext,
`MaleText_loc4` longtext,
`MaleText_loc5` longtext,
`MaleText_loc6` longtext,
`MaleText_loc7` longtext,
`MaleText_loc8` longtext,
`FemaleText_loc1` longtext,
`FemaleText_loc2` longtext,
`FemaleText_loc3` longtext,
`FemaleText_loc4` longtext,
`FemaleText_loc5` longtext,
`FemaleText_loc6` longtext,
`FemaleText_loc7` longtext,
`FemaleText_loc8` longtext,
`VerifiedBuild` smallint(5) NULL DEFAULT 0,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

SET @query := CONCAT('INSERT INTO `locales_broadcast_text` SELECT * FROM `', @world_db_name, '`.`locales_broadcast_text`;');
PREPARE stmt FROM @query;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

SET @query := CONCAT('DROP TABLE IF EXISTS `', @world_db_name, '`.`locales_broadcast_text`;');
PREPARE stmt2 FROM @query;
EXECUTE stmt2;
DEALLOCATE PREPARE stmt2;
