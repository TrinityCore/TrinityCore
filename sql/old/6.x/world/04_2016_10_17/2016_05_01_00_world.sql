DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_ancestral_awakening';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_ancestral_awakening_proc';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_earthbind_totem';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_earthen_power';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_feedback';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_flame_shock';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_mana_tide_totem';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_rolling_thunder';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_telluric_currents';

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_flametongue';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_fulmination';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_healing_stream_totem';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_healing_stream_totem_heal';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_lava_lash_spread_flame_shock';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_lava_surge';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_nature_guardian';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_tidal_waves';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_windfury';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(10400,'spell_sha_flametongue'),
(88766,'spell_sha_fulmination'),
(5394,'spell_sha_healing_stream_totem'),
(52042,'spell_sha_healing_stream_totem_heal'),
(105792,'spell_sha_lava_lash_spread_flame_shock'),
(77756,'spell_sha_lava_surge'),
(30884,'spell_sha_nature_guardian'),
(51564,'spell_sha_tidal_waves'),
(33757,'spell_sha_windfury');

DELETE FROM `spell_proc_event` WHERE `entry` IN (77756,88766,33757,10400);
INSERT INTO `spell_proc_event` (`entry`,`procFlags`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`) VALUES
(77756,0x00040000,0x00000000,0x00000000,0x00000000,0x00000000),
(88766,0x00000000,0x00000003,0x00001000,0x00000000,0x00000004),
(33757,0x00400000,0x00000000,0x00000000,0x00000000,0x00000000),
(10400,0x00800000,0x00000000,0x00000000,0x00000000,0x00000000);
