/*ALTER TABLE db_version CHANGE COLUMN required_7369_01_mangos_quest_template required_7376_01_mangos_spell_area bit;*/

ALTER TABLE spell_area
  CHANGE COLUMN `aura_spell`  `aura_spell` mediumint(8) NOT NULL default '0';