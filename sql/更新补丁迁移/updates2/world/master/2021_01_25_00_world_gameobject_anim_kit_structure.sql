ALTER TABLE `gameobject_addon` ADD `AIAnimKitID` INT(10) UNSIGNED DEFAULT '0' NOT NULL AFTER `WorldEffectID`;

ALTER TABLE `gameobject_template_addon` ADD `AIAnimKitID` INT(10) UNSIGNED DEFAULT '0' NOT NULL AFTER `WorldEffectID`;
