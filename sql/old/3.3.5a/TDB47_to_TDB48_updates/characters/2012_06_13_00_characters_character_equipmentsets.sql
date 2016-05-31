ALTER TABLE `character_equipmentsets`
MODIFY COLUMN `item0` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item1` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item2` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item3` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item4` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item5` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item6` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item7` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item8` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item9` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item10` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item11` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item12` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item13` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item14` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item15` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item16` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item17` int(11) unsigned NOT NULL DEFAULT 0,
MODIFY COLUMN `item18` int(11) unsigned NOT NULL DEFAULT 0;

ALTER TABLE `character_equipmentsets` ADD COLUMN `ignore_mask` int(11) unsigned NOT NULL DEFAULT 0 AFTER `iconname`;
