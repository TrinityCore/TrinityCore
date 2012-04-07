DELETE FROM `spell_script_names` WHERE `spell_id` IN (38441,66316,67100,67101,67102);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38441,'spell_gen_50pct_pct_from_max_hp'), -- Cataclysmic Bolt
(66316,'spell_gen_50pct_pct_from_max_hp'), -- Spinning Pain Spike 10m
(67100,'spell_gen_50pct_pct_from_max_hp'), -- Spinning Pain Spike 25m
(67101,'spell_gen_50pct_pct_from_max_hp'), -- Spinning Pain Spike 10m heroic
(67102,'spell_gen_50pct_pct_from_max_hp'); -- Spinning Pain Spike 25m heroic
