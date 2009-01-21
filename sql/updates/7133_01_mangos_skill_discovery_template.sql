ALTER TABLE db_version CHANGE COLUMN required_7118_01_mangos_skill_discovery_template required_7133_01_mangos_skill_discovery_template bit;

ALTER TABLE skill_discovery_template
   DROP `reqClass`,
   ADD COLUMN `reqSkillValue` smallint(5) unsigned NOT NULL default '0' COMMENT 'skill points requirement' AFTER reqSpell;
