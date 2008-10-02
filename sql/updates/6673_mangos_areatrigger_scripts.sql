DROP TABLE IF EXISTS `areatrigger_scripts`; 
CREATE TABLE `areatrigger_scripts` (
    `entry` MEDIUMINT( 8 ) NOT NULL ,
    `ScriptName` CHAR( 64 ) NOT NULL ,
    PRIMARY KEY ( `entry` )
) ENGINE = MYISAM DEFAULT CHARSET=utf8;

