DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_mana_tide_totem','spell_sha_cleansing_totem_pulse','spell_sha_healing_stream_totem','spell_sha_mana_spring_totem','spell_sha_chain_heal','spell_sha_flame_shock','spell_sha_sentry_totem');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(16191,'spell_sha_mana_tide'),
(52041,'spell_sha_healing_stream_totem'),
(1064,'spell_sha_chain_heal'),
(8050,'spell_sha_flame_shock');
