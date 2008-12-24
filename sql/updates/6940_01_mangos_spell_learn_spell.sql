ALTER TABLE db_version CHANGE COLUMN required_6939_01_mangos_quest_template required_6940_01_mangos_spell_learn_spell bit;

DELETE FROM spell_learn_spell WHERE entry = 2842;
