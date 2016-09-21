CREATE TABLE IF NOT EXISTS `scene_script` (
  `ID` INT (11) UNSIGNED NOT NULL,
  `Name` VARCHAR (255) NOT NULL,
  `Script` TEXT NOT NULL,
  `PrevScriptId` INT (11) UNSIGNED NOT NULL,
  `NextScriptId` INT (11) UNSIGNED NOT NULL,
  PRIMARY KEY (`ID`)
) ;

CREATE TABLE IF NOT EXISTS `scene_script_locale` (
  `ID` INT (11) UNSIGNED NOT NULL,
  `locale` VARCHAR (5) NOT NULL,
  `Name_lang` VARCHAR (255) NOT NULL,
  `Script_lang` TEXT NOT NULL,
  PRIMARY KEY (`ID`)
) ;

 
CREATE TABLE IF NOT EXISTS `scene_script_package` (
  `ID` INT (11) UNSIGNED NOT NULL,
  `Name` VARCHAR (255) NOT NULL,
  PRIMARY KEY (`ID`)
) ;

CREATE TABLE IF NOT EXISTS `scene_script_package_locale` (
  `ID` INT (11) UNSIGNED NOT NULL,
  `locale` VARCHAR (5) NOT NULL,
  `Name_lang` VARCHAR (255) NOT NULL,
  PRIMARY KEY (`ID`)
) ;
