DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pal_light_hammer_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(122773,'spell_pal_light_hammer_init_summon'),
(114918,'spell_pal_light_hammer_periodic');

UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags2`=0x4008800, `unit_flags3`=0x1 WHERE `entry`=59738;

DELETE FROM `creature_template_movement` WHERE `CreatureId`=59738;
INSERT INTO `creature_template_movement` (`CreatureId`,`Flight`,`Rooted`) VALUES
(59738,1,1);
