ALTER TABLE `locales_points_of_interest` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc1` `Name_loc1` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc2` `Name_loc2` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc3` `Name_loc3` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc4` `Name_loc4` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc5` `Name_loc5` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc6` `Name_loc6` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc7` `Name_loc7` TEXT NOT NULL DEFAULT '';
ALTER TABLE `locales_points_of_interest` CHANGE `icon_name_loc8` `Name_loc8` TEXT NOT NULL DEFAULT '';

ALTER TABLE `locales_page_text` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `points_of_interest` CHANGE `data` `Importance` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
