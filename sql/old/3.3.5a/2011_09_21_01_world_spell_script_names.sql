DELETE FROM `spell_script_names` WHERE `spell_id` IN (53475,53487,54015);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53475, 'spell_gen_oracle_wolvar_reputation'), -- Set Oracle Faction Friendly
(53487, 'spell_gen_oracle_wolvar_reputation'), -- Set Wolvar Faction Honored
(54015, 'spell_gen_oracle_wolvar_reputation'); -- Set Oracle Faction Honored