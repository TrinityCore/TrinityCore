ALTER TABLE db_version CHANGE COLUMN required_7196_02_mangos_spell_bonus_data required_7199_01_mangos_spell_bonus_data bit;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (44614, 139, 49821, 53022, 18265, 31117, 28176);
INSERT INTO `spell_bonus_data` VALUES
('44614', '0.8571', '0', '0', 'Mage - Frostfire Bolt'),
('139', '0', '0.376', '0', 'Priest - Renew'),
('49821', '0.14286', '0', '0', 'Priest - Mind Sear Trigger Rank 1'),
('53022', '0.14286', '0', '0', 'Priest - Mind Sear Trigger Rank 2'),
('18265', '0', '0.1', '0', 'Warlock - Siphon Life'),
('31117', '1.8', '0', '0', 'Warlock - Unstable Affliction Dispell'),
('28176', '0', '0', '0', 'Warlock - Fel Armor');
