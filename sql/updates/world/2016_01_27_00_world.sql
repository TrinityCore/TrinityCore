DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_heroic_leap', 'spell_warr_heroic_leap_jump');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(6544,'spell_warr_heroic_leap'),
(178368,'spell_warr_heroic_leap_jump');

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry`=47319;
