DROP TABLE IF EXISTS `gameobject_template_locale`;
CREATE TABLE IF NOT EXISTS `gameobject_template_locale` (
  `entry` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `name` TEXT,
  `castBarCaption` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `gameobject_template_locale`
  ADD PRIMARY KEY (`entry`,`locale`);

-- koKR
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
  (SELECT `entry`, "koKR", `name_loc1`, `castbarcaption_loc1`, `VerifiedBuild`  FROM `locales_gameobject`);

-- frFR
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
  (SELECT `entry`, "frFR", `name_loc2`, `castbarcaption_loc2`, `VerifiedBuild`  FROM `locales_gameobject`);

-- deDE
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
  (SELECT `entry`, "deDE", `name_loc3`, `castbarcaption_loc3`, `VerifiedBuild`  FROM `locales_gameobject`);

-- zhCN
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
  (SELECT `entry`, "zhCN", `name_loc4`, `castbarcaption_loc4`, `VerifiedBuild`  FROM `locales_gameobject`);

-- zhTW
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
  (SELECT `entry`, "zhTW", `name_loc5`, `castbarcaption_loc5`, `VerifiedBuild`  FROM `locales_gameobject`);

-- esES
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
  (SELECT `entry`, "esES", `name_loc6`, `castbarcaption_loc6`, `VerifiedBuild`  FROM `locales_gameobject`);

-- esMX
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
 (SELECT `entry`, "esMX", `name_loc7`, `castbarcaption_loc7`, `VerifiedBuild`  FROM `locales_gameobject`);

-- ruRU
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `VerifiedBuild`)
 (SELECT `entry`, "ruRU", `name_loc8`, `castbarcaption_loc8`, `VerifiedBuild`  FROM `locales_gameobject`);

DROP TABLE IF EXISTS `locales_gameobject`;
