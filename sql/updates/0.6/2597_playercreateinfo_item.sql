ALTER TABLE `playercreateinfo_item`
  ADD `race` tinyint(3) unsigned NOT NULL default '0' FIRST,
  ADD `class` tinyint(3) unsigned NOT NULL default '0' AFTER `race`;

UPDATE `playercreateinfo_item`,`playercreateinfo`
  SET `playercreateinfo_item`.`race` = `playercreateinfo`.`race`, 
      `playercreateinfo_item`.`class` = `playercreateinfo`.`class`
  WHERE `playercreateinfo_item`.`createid` = `playercreateinfo`.`createid`;

ALTER TABLE `playercreateinfo_item`
  DROP KEY `playercreateinfo_items_index`,
  DROP `createid`,
  DROP `bagIndex`,
  DROP `slot`,
  ADD KEY `playercreateinfo_race_class_index` (`race`,`class`);
	