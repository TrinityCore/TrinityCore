ALTER TABLE `spell_linked_spell` DROP PRIMARY KEY;

UPDATE creature_template SET scriptname = 'boss_kalecgos' WHERE entry = 24850;
UPDATE creature_template SET scriptname = 'boss_sathrovarr' WHERE entry = 24892;
UPDATE creature_template SET scriptname = 'boss_kalec' WHERE entry = 24891;
UPDATE creature_template SET minhealth = 2018275, maxhealth = minhealth = 2018275 WHERE entry = 24892;
UPDATE creature_template SET minlevel = 73, maxlevel = 73, minhealth = 828555, maxhealth = 828555, armor = 5000, mindmg = 1000, maxdmg = 2000 WHERE entry = 24891;
UPDATE gameobject_template SET scriptname = 'kalocegos_teleporter' WHERE entry = 187055;

INSERT INTO creature_template_addon (entry) SELECT 24891 FROM creature_template_addon WHERE NOT EXISTS(SELECT * FROM creature_template_addon WHERE entry = 24891) LIMIT 1;
INSERT INTO creature_template_addon (entry) SELECT 24892 FROM creature_template_addon WHERE NOT EXISTS(SELECT * FROM creature_template_addon WHERE entry = 24892) LIMIT 1;
UPDATE creature_template_addon SET auras = '45769 0 45769 1' WHERE entry = 24850;
UPDATE creature_template_addon SET auras = '45769 0 45769 1 44801 0 44801 1 44801 2' WHERE entry = 24891;
UPDATE creature_template_addon SET auras = '45769 0 45769 1 44801 0 44801 1 44801 2 44800 0' WHERE entry = 24892;

DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (44869, 46648, 46019, 46021, -46021, 46020);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44869, 44866, 1, 'Spectral Blast Portal');
-- 46648 will cause severe lag if your video card is not good enough
-- INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44869, 46648, 1, 'Spectral Blast Visual');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (44869, 46019, 1, 'Spectral Blast Teleport');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46019, 46021, 1, 'Spectral Realm Aura');
-- 44852 makes boss friendly to you, weird
-- INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46021, 44852, 1, 'Spectral Realm Aura');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (-46021, 46020, 0, 'Teleport: Normal Realm');
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46020, 44867, 1, 'Spectral Exhaustion');

DELETE FROM spell_target_position WHERE `id` IN (46019, 46020);
INSERT INTO spell_target_position () VALUES (46019, 580, 1704.34, 928.17, -74.558, 0);
INSERT INTO spell_target_position () VALUES (46020, 580, 1704.34, 928.17, 53.079, 0);
