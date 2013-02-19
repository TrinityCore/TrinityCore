/*ALTER TABLE db_version CHANGE COLUMN required_7207_02_mangos_gameobject required_7209_01_mangos_spell_bonus_data bit;*/

DELETE FROM `spell_bonus_data` WHERE `entry` IN (53595);
INSERT INTO `spell_bonus_data` VALUES
('53595', '0', '0', '0','Paladin - Hammer of the Righteous');
