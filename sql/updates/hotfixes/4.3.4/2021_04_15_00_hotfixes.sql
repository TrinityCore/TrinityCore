ALTER TABLE `item_extended_cost`
	ADD COLUMN `RequiredGuildLevel` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `RequirementFlags`;