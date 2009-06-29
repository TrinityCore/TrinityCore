DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (16857);
DELETE FROM `spell_bonus_data` WHERE `entry` IN (60089);
INSERT INTO `spell_bonus_data` (entry, direct_bonus, dot_bonus, ap_bonus, comments) VALUES
(60089, 0, 0, 0.05, 'Faerie Fire (feral)');