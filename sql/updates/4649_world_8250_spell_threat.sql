-- ALTER TABLE db_version CHANGE COLUMN required_8249_02_mangos_spell_chain required_8250_01_mangos_spell_threat bit;

DELETE FROM `spell_threat` WHERE `entry` IN (778,9749,9907,14274,15629,15630,15631,15632,17390,17391,17392,26993,27011);