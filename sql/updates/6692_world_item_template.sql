-- Alter Flags column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `Flags` `Flagstemp` INT(10);
ALTER TABLE `item_template` ADD `Flags` INT SIGNED NOT NULL AFTER `Quality`;
UPDATE `item_template` SET `Flags` = `Flagstemp`;
ALTER TABLE `item_template` DROP `Flagstemp`;
-- Alter maxcount column in item_template to allow max signed value
ALTER TABLE `item_template` CHANGE `maxcount` `maxcounttemp` smallINT(5);
ALTER TABLE `item_template` ADD `maxcount` INT SIGNED NOT NULL AFTER `RequiredReputationRank`;
UPDATE `item_template` SET `maxcount` = `maxcounttemp`;
ALTER TABLE `item_template` DROP `maxcounttemp`;
-- Alter stackable column in item_template to allow max signed value
ALTER TABLE `item_template` CHANGE `stackable` `stackabletemp` INT(11);
ALTER TABLE `item_template` ADD `stackable` INT SIGNED DEFAULT 1 AFTER `maxcount`;
UPDATE `item_template` SET `stackable` = `stackabletemp`;
ALTER TABLE `item_template` DROP `stackabletemp`;
-- Alter BuyPrice column in item_template to allow max signed value
ALTER TABLE `item_template` CHANGE `BuyPrice` `BuyPricetemp` INT(10);
ALTER TABLE `item_template` ADD `BuyPrice` INT SIGNED NOT NULL AFTER `BuyCount`;
UPDATE `item_template` SET `BuyPrice` = `BuyPricetemp`;
ALTER TABLE `item_template` DROP `BuyPricetemp`;
-- Alter spellid_1 column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `spellid_1` `spellid_1temp` MEDIUMINT(8);
ALTER TABLE `item_template` ADD `spellid_1` MEDIUMINT(8) SIGNED NOT NULL AFTER `RangedModRange`;
UPDATE `item_template` SET `spellid_1` = `spellid_1temp`;
ALTER TABLE `item_template` DROP `spellid_1temp`;
-- Alter spellid_2 column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `spellid_2` `spellid_2temp` MEDIUMINT(8);
ALTER TABLE `item_template` ADD `spellid_2` MEDIUMINT(8) SIGNED NOT NULL AFTER `spellcategorycooldown_1`;
UPDATE `item_template` SET `spellid_2` = `spellid_2temp`;
ALTER TABLE `item_template` DROP `spellid_2temp`;
-- Alter spellid_3 column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `spellid_3` `spellid_3temp` MEDIUMINT(8);
ALTER TABLE `item_template` ADD `spellid_3` MEDIUMINT(8) SIGNED NOT NULL AFTER `spellcategorycooldown_2`;
UPDATE `item_template` SET `spellid_3` = `spellid_3temp`;
ALTER TABLE `item_template` DROP `spellid_3temp`;
-- Alter spellid_4 column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `spellid_4` `spellid_4temp` MEDIUMINT(8);
ALTER TABLE `item_template` ADD `spellid_4` MEDIUMINT(8) SIGNED NOT NULL AFTER `spellcategorycooldown_3`;
UPDATE `item_template` SET `spellid_4` = `spellid_4temp`;
ALTER TABLE `item_template` DROP `spellid_4temp`;
-- Alter spellid_5 column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `spellid_5` `spellid_5temp` MEDIUMINT(8);
ALTER TABLE `item_template` ADD `spellid_5` MEDIUMINT(8) SIGNED NOT NULL AFTER `spellcategorycooldown_4`;
UPDATE `item_template` SET `spellid_5` = `spellid_5temp`;
ALTER TABLE `item_template` DROP `spellid_5temp`;
-- Alter RandomProperty column in item_template to allow signed value
ALTER TABLE `item_template` CHANGE `RandomProperty` `RandomPropertytemp` MEDIUMINT(8);
ALTER TABLE `item_template` ADD `RandomProperty` MEDIUMINT(8) SIGNED NOT NULL AFTER `sheath`;
UPDATE `item_template` SET `RandomProperty` = `RandomPropertytemp`;
ALTER TABLE `item_template` DROP `RandomPropertytemp`;

