ALTER TABLE `playercreateinfo_action`
  ADD `race` tinyint(3) unsigned NOT NULL default '0' FIRST,
  ADD `class` tinyint(3) unsigned NOT NULL default '0' AFTER `race`;

UPDATE `playercreateinfo_action`,`playercreateinfo`
  SET `playercreateinfo_action`.`race` = `playercreateinfo`.`race`, 
      `playercreateinfo_action`.`class` = `playercreateinfo`.`class`
  WHERE `playercreateinfo_action`.`createid` = `playercreateinfo`.`createid`;

ALTER TABLE `playercreateinfo_action`
  DROP KEY `playercreateinfo_actions_index`,
  DROP `createid`,
  ADD KEY `playercreateinfo_race_class_index` (`race`,`class`);
