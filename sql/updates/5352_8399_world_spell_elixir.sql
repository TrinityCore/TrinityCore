-- ALTER TABLE db_version CHANGE COLUMN required_8397_02_mangos_spell_threat required_8399_01_mangos_spell_elixir bit;

-- Well Fed (SPELLFAMILY_POTION)
DELETE FROM spell_elixir WHERE entry IN (18191, 18192, 18193, 18194, 18222, 22730, 25661);
INSERT INTO spell_elixir (entry, mask) VALUES
(18191,0x10),
(18192,0x10),
(18193,0x10),
(18194,0x10),
(18222,0x10),
(22730,0x10),
(25661,0x10);
