ALTER TABLE `mail`
  ADD `item_template` int(11) unsigned NOT NULL default '0' AFTER `item`;

UPDATE `mail`,`item_instance`
  SET `item_template` = SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',4),' ',-1)
  WHERE `mail`.`item` = `item_instance`.`guid`;

