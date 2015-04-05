-- Updates base tables
DROP TABLE IF EXISTS `updates`;
CREATE TABLE `updates` (
    `name` VARCHAR(200) NOT NULL COMMENT 'filename with extension of the update.',
    `hash` CHAR(40) NULL DEFAULT '' COMMENT 'sha1 hash of the sql file.',
    `state` ENUM('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if an update is released or archived.',
    `timestamp` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT 'timestamp when the query was applied.',
    `speed` INT(10) UNSIGNED NOT NULL DEFAULT 0 COMMENT 'time the query takes to apply in ms.',
    PRIMARY KEY (`name`)
)
COMMENT='List of all applied updates in this database.'
COLLATE='utf8_general_ci'
ENGINE=MyISAM;

DROP TABLE IF EXISTS `updates_include`;
CREATE TABLE `updates_include` (
    `path` VARCHAR(200) NOT NULL COMMENT 'directory to include. $ means relative to the source directory.',
    `state` ENUM('RELEASED','ARCHIVED') NOT NULL DEFAULT 'RELEASED' COMMENT 'defines if the directory contains released or archived updates.',
    PRIMARY KEY (`path`)
)
COMMENT='List of directories where we want to include sql updates.'
COLLATE='utf8_general_ci'
ENGINE=MyISAM;

-- Auth database update data
TRUNCATE TABLE `updates_include`;
INSERT INTO `updates_include` (`path`, `state`) VALUES
('$/sql/updates/auth', 'RELEASED'),
('$/sql/custom/auth', 'RELEASED'),
('$/sql/old/3.3.5a/auth', 'ARCHIVED');

INSERT IGNORE INTO `updates` (`name`, `hash`) VALUES
('2015_03_20_00_auth.sql', ''),
('2015_03_20_01_auth.sql', ''),
('2015_03_20_02_auth.sql', '');

