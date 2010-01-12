-- Alter data1 column in gameobject_template to allow signed value
ALTER TABLE `gameobject_template` CHANGE `data1` `data1temp` INT(10);
ALTER TABLE `gameobject_template` ADD `data1` INT SIGNED NOT NULL DEFAULT '-1' AFTER `data0`;
UPDATE `gameobject_template` SET `data1` = `data1temp`;
ALTER TABLE `gameobject_template` DROP `data1temp`;
