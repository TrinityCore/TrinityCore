ALTER TABLE `character_inventory` ADD `bag` TINYINT( 3 ) DEFAULT '0' NOT NULL AFTER `guid` ;

ALTER TABLE `character_inventory` DROP PRIMARY KEY ,
ADD INDEX `idx_guid` ( `guid` , `bag` ) ;
