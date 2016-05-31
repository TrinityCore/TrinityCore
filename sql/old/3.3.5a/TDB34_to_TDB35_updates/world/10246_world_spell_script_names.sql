DELETE FROM `spell_script_names` WHERE `spell_id` IN (68793,69050) AND `ScriptName`='spell_bronjahm_magic_bane';
DELETE FROM `spell_script_names` WHERE `spell_id`=68861 AND `ScriptName`='spell_bronjahm_consume_soul';
DELETE FROM `spell_script_names` WHERE `spell_id`=69008 AND `ScriptName`='spell_bronjahm_soulstorm_channel';
DELETE FROM `spell_script_names` WHERE `spell_id`=68870 AND `ScriptName`='spell_bronjahm_soulstorm_visual';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(68793,'spell_bronjahm_magic_bane'),
(69050,'spell_bronjahm_magic_bane'),
(68861,'spell_bronjahm_consume_soul'),
(69008,'spell_bronjahm_soulstorm_channel'),
(68870,'spell_bronjahm_soulstorm_visual');
