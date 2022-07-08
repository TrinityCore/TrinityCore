DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_windfury','spell_sha_windfury_weapon','spell_sha_windfury_weapon_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(33757,'spell_sha_windfury_weapon'),
(319773,'spell_sha_windfury_weapon_proc');
