
-- the (4) in TINYINT(4) is kind of useless here, but whatever. This column should be unsigned.
ALTER TABLE `exploration_basexp` MODIFY COLUMN `level` TINYINT(4) UNSIGNED NOT NULL DEFAULT 0;
