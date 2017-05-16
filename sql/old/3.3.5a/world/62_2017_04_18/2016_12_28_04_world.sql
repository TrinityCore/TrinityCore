DELETE FROM `creature_addon` WHERE guid IN(52480,52481);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52480, 0, 0, 8, 1, 0, NULL),
(52481, 0, 0, 8, 1, 0, NULL);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_illidari_nightlord_shadow_inferno';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(39645,'spell_illidari_nightlord_shadow_inferno');
