DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (7744, 42292, 59752);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pvp_trinket_wotf_shared_cd','spell_wotf_shared_cd','spell_pvp_trinket_shared_cd');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(7744,  'spell_wotf_shared_cd'),
(42292, 'spell_pvp_trinket_shared_cd'),
(59752, 'spell_pvp_trinket_shared_cd');
