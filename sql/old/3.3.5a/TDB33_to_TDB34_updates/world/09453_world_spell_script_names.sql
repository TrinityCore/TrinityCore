DELETE FROM `spell_script_names` WHERE `spell_id`=69057 AND `ScriptName`='spell_marrowgar_bone_spike_graveyard';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (69140,72705) AND `ScriptName`='spell_marrowgar_coldflame';
DELETE FROM `spell_script_names` WHERE `spell_id`=69147 AND `ScriptName`='spell_marrowgar_coldflame_trigger';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (69075,70834,70835,70836) AND `ScriptName`='spell_marrowgar_bone_storm';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(69057,'spell_marrowgar_bone_spike_graveyard'),
(69140,'spell_marrowgar_coldflame'),
(72705,'spell_marrowgar_coldflame'),
(69147,'spell_marrowgar_coldflame_trigger'),
(69075,'spell_marrowgar_bone_storm'),
(70834,'spell_marrowgar_bone_storm'),
(70835,'spell_marrowgar_bone_storm'),
(70836,'spell_marrowgar_bone_storm');
