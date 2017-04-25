DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_lava_burst', 'spell_sha_path_of_flames_spread','spell_sha_ancestral_guidance','spell_sha_ancestral_guidance_heal');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51505,'spell_sha_lava_burst'),
(210621,'spell_sha_path_of_flames_spread'),
(108281,'spell_sha_ancestral_guidance'),
(114911,'spell_sha_ancestral_guidance_heal');
