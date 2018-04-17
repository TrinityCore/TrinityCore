DELETE FROM spell_script_names WHERE scriptname = "spell_impaling_pull";
INSERT INTO spell_script_names VALUES (121754, "spell_impaling_pull");

UPDATE `creature_template` SET `unit_flags` = 0 WHERE entry = 62346;

UPDATE creature_template_addon SET auras = "" WHERE entry IN (42308, 42309);
UPDATE creature_template_addon SET auras = "29266" WHERE entry IN (582, 237, 238);
