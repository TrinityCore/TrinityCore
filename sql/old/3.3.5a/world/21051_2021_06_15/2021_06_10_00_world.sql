-- Keristrasza
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (262144|512|256) WHERE `entry` IN (26723,30540);

-- Broggok
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (512|256|2) WHERE `entry` IN (17380,18601);

-- Spark of Ionar
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (33554432|2), `spell_school_immune_mask` = 127 WHERE `entry` IN (28926,31867);
DELETE FROM `spelldifficulty_dbc` WHERE `id` = 52667;
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(52667,52667,59833,0,0);
