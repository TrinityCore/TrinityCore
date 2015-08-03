ALTER TABLE `locales_page_text` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `locales_points_of_interest` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc1` `Name_loc1` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc2` `Name_loc2` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc3` `Name_loc3` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc4` `Name_loc4` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc5` `Name_loc5` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc6` `Name_loc6` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc7` `Name_loc7` TEXT;
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc8` `Name_loc8` TEXT;

ALTER TABLE `npc_trainer` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `npc_trainer` CHANGE `spell` `SpellID` MEDIUMINT(8) NOT NULL DEFAULT '0';
ALTER TABLE `npc_trainer` CHANGE `spellcost` `MoneyCost` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `npc_trainer` CHANGE `reqskill` `ReqSkillLine` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `npc_trainer` CHANGE `reqskillvalue` `ReqSkillRank` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `npc_trainer` CHANGE `reqLevel` `ReqLevel` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `page_text` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `page_text` CHANGE `text` `Text` LONGTEXT;
ALTER TABLE `page_text` CHANGE `next_page` `NextPageID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `points_of_interest` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `points_of_interest` CHANGE `x` `PositionX` FLOAT NOT NULL DEFAULT '0';
ALTER TABLE `points_of_interest` CHANGE `y` `PositionY` FLOAT NOT NULL DEFAULT '0';
ALTER TABLE `points_of_interest` CHANGE `icon` `Icon` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `points_of_interest` CHANGE `flags` `Flags` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `points_of_interest` CHANGE `data` `Importance` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `points_of_interest` CHANGE `icon_name` `Name` TEXT;
