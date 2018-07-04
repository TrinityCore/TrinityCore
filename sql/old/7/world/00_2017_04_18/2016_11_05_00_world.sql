-- deleted spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_chain_heal','spell_sha_fulmination','spell_sha_glyph_of_healing_wave','spell_sha_healing_stream_totem','spell_sha_lava_lash','spell_sha_lava_lash_spread_flame_shock','spell_sha_nature_guardian','spell_sha_thunderstorm');
-- new spell ids
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_earth_shield','spell_sha_flametongue');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(204288,'spell_sha_earth_shield'),
(194084,'spell_sha_flametongue');
