ALTER TABLE `creature_addon`   
	CHANGE `path_id` `waypointPathId` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
	ADD COLUMN `cyclicSplinePathId` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `waypointPathId`;

ALTER TABLE `creature_template_addon`   
	CHANGE `path_id` `waypointPathId` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
	ADD COLUMN `cyclicSplinePathId` INT(10) UNSIGNED DEFAULT 0 NOT NULL AFTER `waypointPathId`;
