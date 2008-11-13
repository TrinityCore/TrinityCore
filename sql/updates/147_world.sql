DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (46648, 46019, 46021, -46021, 46020);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46648, 44866, 1, 'Spectral Blast');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46019, 46021, 1, 'Teleport: Spectral Realm');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46021, 44852, 1, 'Spectral Realm Aura');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-46021, 46020, 0, 'Teleport: Normal Realm');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46020, 44867, 1, 'Spectral Exhaustion');

DELETE FROM spell_target_position WHERE `id` IN (46019, 46020);
INSERT INTO spell_target_position () VALUES (46019, 580, 1704.34, 928.17, -74.558, 0);
INSERT INTO spell_target_position () VALUES (46020, 580, 1704.34, 928.17, 53.079, 0);

-- Magtheridon Earthquake
DELETE FROM spell_script_target WHERE `entry` IN (30657);
INSERT INTO spell_script_target VALUES ('30657', '1', '24136');