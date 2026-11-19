-- Add new collum in the access_requirement table.
ALTER TABLE `access_requirement`  ADD COLUMN `item_level` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `level_max`;

-- All WotLK Heroics require at least an average item level of 180.
UPDATE `access_requirement` SET `item_level`=180 WHERE `mapId` IN (574, 575, 576, 578, 595, 599, 600, 601, 602, 604, 608, 619) AND `difficulty`=1;
-- Trial of the Champion, Pit of Saron, and the Forge of Souls require an average item level of 200.
UPDATE `access_requirement` SET `item_level`=200 WHERE `mapId` IN (632, 650, 658);
-- Halls of Reflection requires an average item level of 219.
UPDATE `access_requirement` SET `item_level`=219 WHERE `mapId`=668;
