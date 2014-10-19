UPDATE `creature_template` SET `ScriptName`='boss_prince_taldaram' WHERE `entry`=29308;

UPDATE `creature_template` SET `scale`=1, `speed_walk`=2, `InhabitType`=4, `flags_extra`=128 WHERE `entry` IN (30106,31458,31686,31687);
UPDATE `creature_template` SET `ScriptName`='npc_prince_taldaram_flame_sphere' WHERE `entry` IN (30106,31686,31687);

UPDATE `gameobject_template` SET `flags`=32, `ScriptName`='go_prince_taldaram_sphere' WHERE `entry` IN (193093,193094);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (55931, 55895, 59511, 59512);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(55931, 'spell_prince_taldaram_conjure_flame_sphere'),
(55895, 'spell_prince_taldaram_flame_sphere_summon'),
(59511, 'spell_prince_taldaram_flame_sphere_summon'),
(59512, 'spell_prince_taldaram_flame_sphere_summon');
