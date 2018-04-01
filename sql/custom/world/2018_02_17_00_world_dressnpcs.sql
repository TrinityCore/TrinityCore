ALTER TABLE `creature_template` CHANGE COLUMN `modelid1` `modelid1` BIGINT;
ALTER TABLE `creature_template` CHANGE COLUMN `modelid2` `modelid2` BIGINT;
ALTER TABLE `creature_template` CHANGE COLUMN `modelid3` `modelid3` BIGINT;
ALTER TABLE `creature_template` CHANGE COLUMN `modelid4` `modelid4` BIGINT;
UPDATE creature_template SET modelid1 = (-modelid1) + 3000000000 WHERE modelid1 < 0;
UPDATE creature_template SET modelid2 = (-modelid2) + 3000000000 WHERE modelid2 < 0;
UPDATE creature_template SET modelid3 = (-modelid3) + 3000000000 WHERE modelid3 < 0;
UPDATE creature_template SET modelid4 = (-modelid4) + 3000000000 WHERE modelid4 < 0;
ALTER TABLE `creature_template` CHANGE COLUMN `modelid1` `modelid1` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE COLUMN `modelid2` `modelid2` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE COLUMN `modelid3` `modelid3` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE COLUMN `modelid4` `modelid4` INT(10) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `creature_template_outfits` DROP PRIMARY KEY;
UPDATE creature_template_outfits SET entry = entry + 3000000000 WHERE entry <= 0x7FFFFFFF;
ALTER TABLE `creature_template_outfits` ADD PRIMARY KEY (`entry`);

ALTER TABLE `creature` CHANGE COLUMN `modelid` `modelid` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `game_event_model_equip` CHANGE COLUMN `modelid` `modelid` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_model_info` CHANGE COLUMN `DisplayID` `DisplayID` INT(10) UNSIGNED NOT NULL DEFAULT '0';
