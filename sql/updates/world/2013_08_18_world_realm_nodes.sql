DROP TABLE IF EXISTS `realm_nodes`;

CREATE TABLE `realm_nodes` (
 `mapid_or_role` INT(11) NOT NULL PRIMARY KEY,
 `ip` VARCHAR(16) NOT NULL,
 `port` SMALLINT(5) UNSIGNED
);