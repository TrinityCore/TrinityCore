-- Alter data6 column in gameobject_template to allow signed value
ALTER TABLE `gameobject_template` CHANGE `data6` `data6temp` INT(10);
ALTER TABLE `gameobject_template` ADD `data6` INT SIGNED NOT NULL AFTER `data5`;
UPDATE `gameobject_template` SET `data6` = `data6temp`;
ALTER TABLE `gameobject_template` DROP `data6temp`;
