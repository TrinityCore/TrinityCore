/*ALTER TABLE db_version CHANGE COLUMN required_7242_01_mangos_spell_bonus_data required_7249_01_mangos_spell_proc_event bit;*/

DELETE FROM `spell_proc_event` WHERE `entry`='60200';
