ALTER TABLE `playercreateinfo_spell`
  ADD `race` tinyint(3) unsigned NOT NULL default '0' FIRST,
  ADD `class` tinyint(3) unsigned NOT NULL default '0' AFTER `race`;

UPDATE `playercreateinfo_spell`,`playercreateinfo`
  SET `playercreateinfo_spell`.`race` = `playercreateinfo`.`race`, 
      `playercreateinfo_spell`.`class` = `playercreateinfo`.`class`
  WHERE `playercreateinfo_spell`.`createid` = `playercreateinfo`.`createid`;

ALTER TABLE `playercreateinfo_spell`
  DROP PRIMARY KEY,
  DROP `createid`,
  ADD PRIMARY KEY  (`race`,`class`,`Spell`);
	