ALTER TABLE `character_currency` 
ADD `IncreasedCapQuantity` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `TrackedQuantity`,
ADD `EarnedQuantity` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `IncreasedCapQuantity`;
