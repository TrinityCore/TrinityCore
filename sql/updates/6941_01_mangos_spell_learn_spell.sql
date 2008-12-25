ALTER TABLE db_version CHANGE COLUMN required_6940_01_mangos_spell_learn_spell required_6941_01_mangos_spell_learn_spell bit;

DELETE FROM spell_learn_spell WHERE entry = 53428;
INSERT INTO spell_learn_spell VALUES
(53428,53341),
(53428,53343);
