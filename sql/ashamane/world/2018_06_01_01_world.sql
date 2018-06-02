UPDATE areatrigger_template SET ScriptName = '' WHERE Id IN (12606, 9228);

DELETE FROM spell_script_names WHERE scriptname = "spell_pal_consecration";
INSERT INTO spell_script_names VALUES
(26573, "spell_pal_consecration"),
(205228, "spell_pal_consecration");
