-- Note: quest_objectives need new full parse to get proper Order
ALTER TABLE `quest_objectives` ADD COLUMN `Order` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Type`;
