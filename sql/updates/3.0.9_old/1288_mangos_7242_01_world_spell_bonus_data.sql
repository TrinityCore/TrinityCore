/*ALTER TABLE db_version CHANGE COLUMN required_7235_01_mangos_command required_7242_01_mangos_spell_bonus_data bit;*/

DELETE FROM spell_bonus_data WHERE entry IN (34913, 43043, 43044);
INSERT INTO spell_bonus_data VALUES
 (34913, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 1'),
 (43043, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 2'),
 (43044, 0, 0, 0, 'Mage - Molten Armor Triggered Rank 3');