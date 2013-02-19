/*ALTER TABLE db_version CHANGE COLUMN required_7662_01_mangos_spell_chain required_7662_02_mangos_spell_bonus_data bit;*/

DELETE FROM `spell_bonus_data` WHERE entry IN (50288, 50294);
INSERT INTO `spell_bonus_data` VALUES
(50288, 0.05, 0, 0, "Druid - Starfall"),
(50294, 0.012, 0, 0, "Druid - Starfall AOE");
