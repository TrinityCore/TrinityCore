/*ALTER TABLE db_version CHANGE COLUMN required_7349_01_mangos_spell_area required_7369_01_mangos_quest_template bit;*/

ALTER TABLE quest_template
  DROP COLUMN ReqSourceRef1,
  DROP COLUMN ReqSourceRef2,
  DROP COLUMN ReqSourceRef3,
  DROP COLUMN ReqSourceRef4;
