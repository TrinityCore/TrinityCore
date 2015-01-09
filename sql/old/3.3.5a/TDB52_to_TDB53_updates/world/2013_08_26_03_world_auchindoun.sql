UPDATE `instance_template` SET `script`='instance_auchenai_crypts' WHERE `map`=558;
UPDATE `instance_template` SET `script`='instance_mana_tombs' WHERE `map`=557; 

DELETE FROM `spell_script_names` WHERE `spell_id` IN (33923, 38796, 33666, 38795, 39365);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(33923, 'spell_murmur_sonic_boom'),
(38796, 'spell_murmur_sonic_boom'),
(33666, 'spell_murmur_sonic_boom_effect'),
(38795, 'spell_murmur_sonic_boom_effect'),
(39365, 'spell_murmur_thundering_storm');

DELETE FROM `creature_ai_scripts` WHERE `id`=1879605;
