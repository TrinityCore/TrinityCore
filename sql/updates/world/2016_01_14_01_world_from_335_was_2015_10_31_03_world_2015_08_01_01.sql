DROP TABLE IF EXISTS `creature_template_locale`;
CREATE TABLE IF NOT EXISTS `creature_template_locale` (
  `entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `FemaleName` TEXT,
  `Title` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`entry`,`locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "koKR", `name_loc1`, `femaleName_loc1`, `subname_loc1`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc1`) > 0 OR LENGTH(`femaleName_loc1`) > 0 OR LENGTH(`subname_loc1`) > 0);

-- frFR
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "frFR", `name_loc2`, `femaleName_loc2`, `subname_loc2`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc2`) > 0 OR LENGTH(`femaleName_loc2`) > 0 OR LENGTH(`subname_loc2`) > 0);

-- deDE
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "deDE", `name_loc3`, `femaleName_loc3`, `subname_loc3`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc3`) > 0 OR LENGTH(`femaleName_loc3`) > 0 OR LENGTH(`subname_loc3`) > 0);

-- zhCN
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "zhCN", `name_loc4`, `femaleName_loc4`, `subname_loc4`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc4`) > 0 OR LENGTH(`femaleName_loc4`) > 0 OR LENGTH(`subname_loc4`) > 0);

-- zhTW
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "zhTW", `name_loc5`, `femaleName_loc5`, `subname_loc5`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc5`) > 0 OR LENGTH(`femaleName_loc5`) > 0 OR LENGTH(`subname_loc5`) > 0);

-- esES
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "esES", `name_loc6`, `femaleName_loc6`, `subname_loc6`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc6`) > 0 OR LENGTH(`femaleName_loc6`) > 0 OR LENGTH(`subname_loc6`) > 0);

-- esMX
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "esMX", `name_loc7`, `femaleName_loc7`, `subname_loc7`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc7`) > 0 OR LENGTH(`femaleName_loc7`) > 0 OR LENGTH(`subname_loc7`) > 0);

-- ruRU
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `FemaleName`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "ruRU", `name_loc8`, `femaleName_loc8`, `subname_loc8`, `VerifiedBuild` FROM `locales_creature` WHERE LENGTH(`name_loc8`) > 0 OR LENGTH(`femaleName_loc8`) > 0 OR LENGTH(`subname_loc8`) > 0);

DROP TABLE IF EXISTS `locales_creature`;
