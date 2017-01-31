DELETE FROM `spell_scripts` WHERE `id` IN (52160,52163);
DELETE FROM `db_script_string` WHERE `entry` IN (2000000107,2000000108);
DELETE FROM `spell_script_names` WHERE `spell_id` IN (52160,52163);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(52160, 'spell_shango_tracks'),
(52163, 'spell_shango_tracks');
DELETE FROM `trinity_string` WHERE `entry` IN (28634,28635);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(28634, 'These tracks must belong to Shango.'),
(28635, 'These aren''t Shango''s tracks.');
