-- Ulduar - Arm Dead Damage Kologarn difficult modes
DELETE FROM `spelldifficulty_dbc` WHERE `id` =63629;
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(63629,63629,63979);
-- Ulduar - Arm Dead Damage Kologarn should ignore armor
DELETE FROM `spell_custom_attr` WHERE `entry` IN (63629,63979);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(63629, 32768), -- 10
(63979, 32768); -- 25
