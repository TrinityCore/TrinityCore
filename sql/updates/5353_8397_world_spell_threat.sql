-- ALTER TABLE db_version CHANGE COLUMN required_8397_01_mangos_spell_chain required_8397_02_mangos_spell_threat bit;

DELETE FROM spell_threat WHERE entry IN (7405,8380,11596,11597,25225);
