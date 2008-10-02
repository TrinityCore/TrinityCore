ALTER TABLE `mail`
    ADD COLUMN `has_items` tinyint(3) unsigned NOT NULL default '0' AFTER `itemTextId`;

UPDATE `mail` SET `has_items` = '1' WHERE `item_guid`<>'0';

DROP TABLE IF EXISTS `mail_items`;
CREATE TABLE `mail_items` (
  `mail_id` int(11) NOT NULL default '0',
  `item_guid` int(11) NOT NULL default '0',
  `item_template` int(11) NOT NULL default '0',
  PRIMARY KEY  (`mail_id`,`item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

INSERT INTO `mail_items` SELECT `id`,`item_guid`,`item_template` FROM `mail` WHERE `mail`.`has_items`>0;

ALTER TABLE `mail`
    DROP COLUMN `item_guid`,
    DROP COLUMN `item_template`;

UPDATE `character` SET data = CONCAT(SUBSTRING(data, 1, length(SUBSTRING_INDEX(data, ' ', 48))), " ", "0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ","0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 140))+2, length(SUBSTRING_INDEX(data, ' ', 225))- length(SUBSTRING_INDEX(data, ' ', 140)) - 1), " ", SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 226))+2, length(SUBSTRING_INDEX(data, ' ', 1249))- length(SUBSTRING_INDEX(data, ' ', 226)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1249))+2, length(SUBSTRING_INDEX(data, ' ', 1259))- length(SUBSTRING_INDEX(data, ' ', 1249)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1259))+2, length(SUBSTRING_INDEX(data, ' ', 1379))- length(SUBSTRING_INDEX(data, ' ', 1259)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1380))+2, length(SUBSTRING_INDEX(data, ' ', 1405))- length(SUBSTRING_INDEX(data, ' ', 1380)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1405))+2, length(SUBSTRING_INDEX(data, ' ', 1410))- length(SUBSTRING_INDEX(data, ' ', 1405)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1410))+2, length(SUBSTRING_INDEX(data, ' ', 1415))- length(SUBSTRING_INDEX(data, ' ', 1410)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1415))+2, length(SUBSTRING_INDEX(data, ' ', 1420))- length(SUBSTRING_INDEX(data, ' ', 1415)) - 1), " ", "0 ",SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1420))+2, length(SUBSTRING_INDEX(data, ' ', 1436))- length(SUBSTRING_INDEX(data, ' ', 1420)) - 1)) WHERE length(SUBSTRING_INDEX(data, ' ', 1436)) < length(data) and length(SUBSTRING_INDEX(data, ' ', 1437)) >= length(data);    
