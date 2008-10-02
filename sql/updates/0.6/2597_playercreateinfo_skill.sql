ALTER TABLE `playercreateinfo_skill`
  ADD `race` tinyint(3) unsigned NOT NULL default '0' FIRST,
  ADD `class` tinyint(3) unsigned NOT NULL default '0' AFTER `race`;

UPDATE `playercreateinfo_skill`,`playercreateinfo`
  SET `playercreateinfo_skill`.`race` = `playercreateinfo`.`race`, 
      `playercreateinfo_skill`.`class` = `playercreateinfo`.`class`
  WHERE `playercreateinfo_skill`.`createid` = `playercreateinfo`.`createid`;

ALTER TABLE `playercreateinfo_skill`
  DROP PRIMARY KEY,
  DROP `createid`,
  ADD PRIMARY KEY  (`race`,`class`,`Skill`);
	