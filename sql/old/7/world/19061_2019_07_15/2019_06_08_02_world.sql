DELETE FROM `item_enchantment_template` WHERE `type`!=2;

ALTER TABLE `item_enchantment_template`
  DROP PRIMARY KEY,
  DROP `type`,
  CHANGE `entry` `Id` int(10) unsigned NOT NULL,
  CHANGE `ench` `BonusListID` int(10) unsigned NOT NULL,
  CHANGE `chance` `chance_temp` float NOT NULL,
  ADD PRIMARY KEY(`Id`,`BonusListID`);

ALTER TABLE `item_enchantment_template` CHANGE `chance_temp` `Chance` float NOT NULL;

RENAME TABLE `item_enchantment_template` TO `item_random_bonus_list_template`;

ALTER TABLE `item_template_addon` ADD `RandomBonusListTemplateId` int(10) unsigned NOT NULL DEFAULT '0';

UPDATE `command` SET `name`='reload item_random_bonus_list_template' WHERE `name`='reload item_enchantment_template';
