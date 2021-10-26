ALTER TABLE `creature_template_outfits`
	ADD COLUMN `mainhand` INT(10) NOT NULL DEFAULT -1 AFTER `guildid`;

ALTER TABLE `creature_template_outfits`
	ADD COLUMN `offhand` INT(10) NOT NULL DEFAULT -1 AFTER `mainhand`;

ALTER TABLE `creature_template_outfits`
	ADD COLUMN `ranged` INT(10) NOT NULL DEFAULT -1 AFTER `offhand`;