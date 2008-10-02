ALTER TABLE `item_template`
 ADD COLUMN `RequiredArenaRank` INT(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ExtendedCost`;