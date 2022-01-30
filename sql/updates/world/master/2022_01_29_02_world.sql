DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_light_hammer_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(114918,'spell_pal_light_hammer_periodic');

UPDATE `creature_template` SET `unit_flags`=33554440, `unit_flags2`=67143680, `unit_flags3`=1, `ScriptName`='npc_pet_pal_light_hammer' WHERE `entry`=59738;

