ALTER TABLE `playercreateinfo_reputation`
  ADD `race` tinyint(3) unsigned NOT NULL default '0' FIRST,
  ADD `class` tinyint(3) unsigned NOT NULL default '0' AFTER `race`;

UPDATE `playercreateinfo_reputation`,`playercreateinfo`
  SET `playercreateinfo_reputation`.`race` = `playercreateinfo`.`race`, 
      `playercreateinfo_reputation`.`class` = `playercreateinfo`.`class`
  WHERE `playercreateinfo_reputation`.`createid` = `playercreateinfo`.`createid`;

ALTER TABLE `playercreateinfo_reputation`
  DROP KEY `playercreateinfo_reputation_index`,
  DROP `createid`,
  ADD KEY `playercreateinfo_race_class_index` (`race`,`class`);
	