ALTER TABLE `item_template` ADD `flagsCustom` INT(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `maxMoneyLoot`;
UPDATE `item_template` SET `flagsCustom`=`flagsCustom`|0x1 WHERE `Duration`<0;
UPDATE `item_template` SET `duration`=ABS(`duration`);
ALTER TABLE `item_template` CHANGE `Duration` `duration` INT(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ArmorDamageModifier`;
