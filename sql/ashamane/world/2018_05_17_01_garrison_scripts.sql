DROP TABLE IF EXISTS `garrison_scripts`;
CREATE TABLE `garrison_scripts`(
    `GarSiteLevelId` INT(11) UNSIGNED NOT NULL,
    `ScriptName` CHAR(64) NOT NULL,
    PRIMARY KEY (`GarSiteLevelId`)
);

INSERT INTO `garrison_scripts` VALUES
(5,   "garrison_level_1_alliance"),
(258, "garrison_level_1_horde"),
(444, "garrison_level_2_alliance"),
(445, "garrison_level_2_horde"),
(6,   "garrison_level_3_alliance"),
(259, "garrison_level_3_horde");
