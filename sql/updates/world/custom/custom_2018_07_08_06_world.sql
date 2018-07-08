DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_sha_flametongue_weapon',
'spell_sha_windfury_weapon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(10400, 'spell_sha_flametongue_weapon'),
(33757, 'spell_sha_windfury_weapon');
