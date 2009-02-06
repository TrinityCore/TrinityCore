ALTER TABLE db_version CHANGE COLUMN required_7230_01_mangos_spell_chain required_7230_02_mangos_spell_bonus_data bit;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (18220,18937,18938,27265,59092);
INSERT INTO `spell_bonus_data` VALUES
('18220', '0.96', '0', '0', 'Warlock - Dark Pact Rank 1'),
('18937', '0.96', '0', '0', 'Warlock - Dark Pact Rank 2'),
('18938', '0.96', '0', '0', 'Warlock - Dark Pact Rank 3'),
('27265', '0.96', '0', '0', 'Warlock - Dark Pact Rank 4'),
('59092', '0.96', '0', '0', 'Warlock - Dark Pact Rank 5');
