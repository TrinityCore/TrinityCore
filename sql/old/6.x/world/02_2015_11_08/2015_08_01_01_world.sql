DROP TABLE IF EXISTS `creature_template_locale`;
CREATE TABLE IF NOT EXISTS `creature_template_locale` (
  `entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `NameAlt` TEXT,
  `Title` TEXT,
  `TitleAlt` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `creature_template_locale`
  ADD PRIMARY KEY (`entry`,`locale`);

-- koKR
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "koKR", `name_loc1`, `femaleName_loc1`, `subname_loc1`, `VerifiedBuild`  FROM `locales_creature`);

-- frFR
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "frFR", `name_loc2`, `femaleName_loc2`, `subname_loc2`, `VerifiedBuild`  FROM `locales_creature`);

-- deDE
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "deDE", `name_loc3`, `femaleName_loc3`, `subname_loc3`, `VerifiedBuild`  FROM `locales_creature`);

-- zhCN
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "zhCN", `name_loc4`, `femaleName_loc4`, `subname_loc4`, `VerifiedBuild`  FROM `locales_creature`);

-- zhTW
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "zhTW", `name_loc5`, `femaleName_loc5`, `subname_loc5`, `VerifiedBuild`  FROM `locales_creature`);

-- esES
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "esES", `name_loc6`, `femaleName_loc6`, `subname_loc6`, `VerifiedBuild`  FROM `locales_creature`);

-- esMX
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "esMX", `name_loc7`, `femaleName_loc7`, `subname_loc7`, `VerifiedBuild`  FROM `locales_creature`);

-- ruRU
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `VerifiedBuild`)
  (SELECT `entry`, "ruRU", `name_loc8`, `femaleName_loc8`, `subname_loc8`, `VerifiedBuild`  FROM `locales_creature`);

DROP TABLE IF EXISTS `locales_creature`;
