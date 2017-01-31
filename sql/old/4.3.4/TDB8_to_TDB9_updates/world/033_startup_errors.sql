--
DELETE FROM `spell_script_names` WHERE `spell_id` IN (9454,27687,27695);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(9454, 'spell_gen_gm_freeze'),
(27687, 'spell_kormok_summon_bone_minions'),
(27695, 'spell_kormok_summon_bone_mages');
UPDATE `spell_script_names` SET `spell_id`=43265 WHERE `ScriptName`='spell_dk_death_and_decay';
