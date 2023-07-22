UPDATE `creature_template` SET `ScriptName`="npc_pet_pri_shadowfiend_mindbender" WHERE `entry` IN (19668, 62982);

DELETE FROM `spell_script_names` WHERE `spell_id`=195178;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(195178, 'spell_pri_atonement_passive');
