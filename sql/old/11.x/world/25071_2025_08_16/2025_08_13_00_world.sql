ALTER TABLE `areatrigger_create_properties_orbit` CHANGE `StartDelay` `ExtraTimeForBlending` INT NOT NULL DEFAULT 0;

ALTER TABLE `creature_template_difficulty` ADD `TypeFlags3` INT UNSIGNED NOT NULL DEFAULT 0 AFTER `TypeFlags2`;
