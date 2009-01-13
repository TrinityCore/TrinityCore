ALTER TABLE db_version CHANGE COLUMN required_7074_01_mangos_playercreateinfo_spell required_7075_02_mangos_spell_learn_spell bit;

DELETE FROM spell_learn_spell WHERE Entry = 58984;

INSERT INTO spell_learn_spell VALUES
(58984,21009,1);
