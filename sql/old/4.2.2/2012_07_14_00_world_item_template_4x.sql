ALTER TABLE `item_template`
 ADD `Unk430_1` float unsigned NOT NULL DEFAULT '1' AFTER `FlagsExtra`,
 ADD `Unk430_2` float NOT NULL DEFAULT '1' AFTER `Unk430_1`,
 ADD `BuyCount` tinyint(3) unsigned NOT NULL DEFAULT '1' AFTER `Unk430_2`;
