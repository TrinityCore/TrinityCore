-- ALTER TABLE db_version CHANGE COLUMN required_8227_01_mangos_spell_proc_event required_8237_01_mangos_creature_template bit;

UPDATE creature_template
  SET mindmg = ROUND(mindmg + attackpower), maxdmg=ROUND(maxdmg+attackpower);