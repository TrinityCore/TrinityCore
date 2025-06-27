--
ALTER TABLE `gameobject_template_addon`
	ADD COLUMN `artkit0` INT NOT NULL DEFAULT 0 AFTER `maxgold`,
	ADD COLUMN `artkit1` INT NOT NULL DEFAULT 0 AFTER `artkit0`,
	ADD COLUMN `artkit2` INT NOT NULL DEFAULT 0 AFTER `artkit1`,
	ADD COLUMN `artkit3` INT NOT NULL DEFAULT 0 AFTER `artkit2`;
