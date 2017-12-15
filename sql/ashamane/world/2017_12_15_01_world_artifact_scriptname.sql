DELETE FOM spell_script_names WHERE scriptname IN ("spell_arti_dru_half_moon", "spell_arti_mage_immolation", "spell_arti_mage_phoenix_flames", "spell_arti_mage_phoenix_flames_trigger", "spell_arti_sha_servant_of_the_queen", "spell_arti_sha_caress_of_the_tidemother", "spell_arti_warl_deadwind_harvest", "spell_arti_warl_reap_souls", "spell_arti_warl_dimensional_rift", "npc_warl_chaos_tear", "npc_warl_shadowy_tear", "spell_arti_warl_thalkiels_consumption", "spell_dh_fury_of_the_illidari");

INSERT INTO spell_script_names VALUES (202768, "spell_arti_dru_half_moon");

INSERT INTO spell_script_names VALUES (211918, "spell_arti_mage_immolation");
INSERT INTO spell_script_names VALUES (194466, "spell_arti_mage_phoenix_flames");
INSERT INTO spell_script_names VALUES (224637, "spell_arti_mage_phoenix_flames_trigger");

INSERT INTO spell_script_names VALUES (207357, "spell_arti_sha_servant_of_the_queen");
INSERT INTO spell_script_names VALUES (207354, "spell_arti_sha_caress_of_the_tidemother");

INSERT INTO spell_script_names VALUES (216708, "spell_arti_warl_deadwind_harvest");
INSERT INTO spell_script_names VALUES (216698, "spell_arti_warl_reap_souls");
INSERT INTO spell_script_names VALUES (196586, "spell_arti_warl_dimensional_rift");
INSERT INTO spell_script_names VALUES (211714, "spell_arti_warl_thalkiels_consumption");

INSERT INTO spell_script_names VALUES (201467, "spell_dh_fury_of_the_illidari");

UPDATE creature_template SET scriptname = "npc_warl_chaos_tear" WHERE entry = 108493;
UPDATE creature_template SET scriptname = "npc_warl_shadowy_tear" WHERE entry = 99887;

UPDATE areatrigger_template SET scriptname = "at_dh_fury_of_the_illidari" WHERE entry = 10470;
