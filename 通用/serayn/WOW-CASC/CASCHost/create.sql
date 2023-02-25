 SET GLOBAL innodb_file_format=Barracuda; 
 SET GLOBAL innodb_file_per_table=ON; 
 SET GLOBAL innodb_large_prefix=ON; 
 
 CREATE TABLE IF NOT EXISTS `root_entries` ( 
 `Id` BIGINT NOT NULL AUTO_INCREMENT, 
 `Path` VARCHAR(1024), 
 `FileDataId` INT UNSIGNED, 
 `Hash` BIGINT UNSIGNED, 
 `MD5` VARCHAR(32), 
 `BLTE` VARCHAR(32), 
 `PurgeAt` DATE NULL, 
 PRIMARY KEY(`Id`), 
 UNIQUE INDEX `Path` (`Path`) 
 ) COLLATE = 'utf8_general_ci' ENGINE=InnoDB ROW_FORMAT=DYNAMIC; 