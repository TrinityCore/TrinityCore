ALTER TABLE `item_instance`
  ADD `transmogrification` int(10) unsigned not null default '0' AFTER `text`,
  ADD `upgradeId` int(10) unsigned not null default '0' AFTER `transmogrification`,
  ADD `enchantIllusion` int(10) unsigned not null default '0' AFTER `upgradeId`,
  ADD `bonusListIDs` text AFTER `enchantIllusion`;

UPDATE `item_instance` SET `transmogrification`=SUBSTRING_INDEX(SUBSTRING_INDEX(`enchantments`, ' ', 27 + 1), ' ', -1);
UPDATE `item_instance` SET `enchantments`=SUBSTRING_INDEX(`enchantments`, ' ', 45); -- trim the field to 15 enchantments
UPDATE `item_instance` SET `enchantments`=CONCAT(SUBSTRING_INDEX(`enchantments`, ' ', 24), ' ', SUBSTRING_INDEX(`enchantments`, ' ', -15));
