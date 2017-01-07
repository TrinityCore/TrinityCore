ALTER TABLE `waypoint_data`
	CHANGE COLUMN `wpguid` `wpguid` INT(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `action_chance`;

UPDATE `command` SET `help`='Syntax: .wp show $option\nOptions:\non $pathid (or selected creature with loaded path) - Show path\nfirst $pathid (or selected creature with loaded path) - Show first waypoint in path\nlast $pathid (or selected creature with loaded path) - Show last waypoint in path\noff - Hide all paths\ninfo $slected_waypoint - Show info for selected waypoint.' WHERE  `name`='wp show';
