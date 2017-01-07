ALTER TABLE `waypoint_data`
	CHANGE COLUMN `wpguid` `wpguid` INT(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `action_chance`;
