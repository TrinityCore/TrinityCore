ALTER TABLE db_version CHANGE COLUMN required_7107_01_mangos_string required_7118_01_mangos_skill_discovery_template bit;

ALTER TABLE skill_discovery_template
   DROP PRIMARY KEY,
   ADD PRIMARY KEY (`spellId`,`reqSpell`),
   ADD COLUMN reqClass tinyint(2) unsigned NOT NULL default '0' COMMENT 'class requirement' AFTER reqSpell;
