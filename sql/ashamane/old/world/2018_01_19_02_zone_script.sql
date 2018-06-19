DROP TABLE IF EXISTS `zone_scripts`;
CREATE TABLE `zone_scripts`(
    `zoneId` INT(10) UNSIGNED NOT NULL,
    `scriptname` CHAR(64) NOT NULL DEFAULT '',
    PRIMARY KEY (`zoneId`)
);

INSERT INTO `zone_scripts` (zoneId, scriptname) VALUES
(4, "zone_blasted_lands"),
(41, "zone_deadwind_pass"),
(6723, "zone_tanaan_jungle_100"),
(8392, "zone_legion_dalaran_underbelly");

UPDATE creature_template SET scriptname = '' WHERE entry = 114325;
