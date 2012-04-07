DELETE FROM `spell_script_names` WHERE `spell_id` IN (20625,29142,35139,42393,49882,55269,56578);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(20625,'spell_gen_bp_damage_pct_from_max_hp'), -- Ritual of Doom Sacrifice
(29142,'spell_gen_bp_damage_pct_from_max_hp'), -- Eyesore Blaster
(35139,'spell_gen_bp_damage_pct_from_max_hp'), -- Throw Boom's Doom
(42393,'spell_gen_bp_damage_pct_from_max_hp'), -- Brewfest - Attack Keg
(49882,'spell_gen_bp_damage_pct_from_max_hp'), -- Leviroth Self-Impale
(55269,'spell_gen_bp_damage_pct_from_max_hp'), -- Deathly Stare
(56578,'spell_gen_bp_damage_pct_from_max_hp'); -- Rapid-Fire Harpoon

DELETE FROM `spell_script_names` WHERE `spell_id`=38441;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38441,'spell_gen_cataclysmic_bolt'); -- Cataclysmic Bolt
