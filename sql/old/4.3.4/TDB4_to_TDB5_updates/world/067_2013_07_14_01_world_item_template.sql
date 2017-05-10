-- 4.x - Item-sparse.db2

/*
UPDATE `item_template` SET `Flags`=0x80000000 WHERE `entry`=23614;
UPDATE `item_template` SET `Flags`=0x80000800 WHERE `entry`=28635;
UPDATE `item_template` SET `Flags`=0x80000800 WHERE `entry`=28636;
UPDATE `item_template` SET `Flags`=0x80000800 WHERE `entry`=28637;
UPDATE `item_template` SET `Flags`=0x80000000 WHERE `entry`=30503;
UPDATE `item_template` SET `Flags`=0x80000000 WHERE `entry`=34868;
UPDATE `item_template` SET `Flags`=0x80000000 WHERE `entry`=37020;
UPDATE `item_template` SET `Flags`=0x80010000 WHERE `entry`=37200;
UPDATE `item_template` SET `Flags`=0x80000040 WHERE `entry`=40652;
UPDATE `item_template` SET `Flags`=0x80000040 WHERE `entry`=40970;
UPDATE `item_template` SET `Flags`=0x80000800 WHERE `entry`=41843;
UPDATE `item_template` SET `Flags`=0x80000800 WHERE `entry`=42782;
*/

ALTER TABLE `item_template` CHANGE `Flags` `Flags` int(10) unsigned NOT NULL DEFAULT '0';
