UPDATE `creature_template` SET `ScriptName`='npc_brann_bronzebeard_ulduar_intro' WHERE `entry`=33579;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=48750 AND `spell_effect`=48770;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_burning_depths_necrolyte_image';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48750, 'spell_gen_burning_depths_necrolyte_image');
