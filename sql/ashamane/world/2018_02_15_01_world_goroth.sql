UPDATE creature_template SET mechanic_immune_mask = 2147483647 WHERE entry = 116976;
UPDATE creature_template SET flags_extra = 128 WHERE entry IN (117931, 116976);

DELETE FROM spell_script_names WHERE scriptname = "spell_shattering_star_dummy";
INSERT INTO spell_script_names VALUES
(233274, "spell_shattering_star_dummy");
