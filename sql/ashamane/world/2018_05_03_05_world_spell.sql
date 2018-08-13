DELETE FROM spell_script_names WHERE scriptname = "spell_arti_pri_call_of_the_void";
INSERT INTO spell_script_names VALUES
(193371, "spell_arti_pri_call_of_the_void");

UPDATE creature_template SET scriptname = "npc_arti_priest_void_tendril" WHERE entry = 98167;
