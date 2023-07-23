UPDATE `creature_template` SET `ScriptName`="npc_pet_pri_shadowfiend_mindbender" WHERE `entry` IN (19668, 62982);

UPDATE `creature_template_addon` SET `auras`="262484" WHERE `entry`=19668;
UPDATE `creature_template_addon` SET `auras`="284621" WHERE `entry`=62982;

DELETE FROM `spell_script_names` WHERE `spell_id` IN(195178, 262484, 284621);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(195178, 'spell_pri_atonement_passive'),
(262484, 'spell_pri_power_leech_passive'),
(284621, 'spell_pri_power_leech_passive');
