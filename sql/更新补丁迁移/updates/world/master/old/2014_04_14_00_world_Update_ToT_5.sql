DELETE FROM `creature` WHERE `id` = '66410';
DELETE FROM `creature` WHERE `id` = '29888';
DELETE FROM `gameobject` WHERE `id` = '213029' AND `map`= '1098';
DELETE FROM `gameobject` WHERE `id` = '215635' AND `map`= '1098';
INSERT INTO `spell_script_names` (`spell_id` , `ScriptName`) VALUES ('136769' , 'spell_horridon_charge');
UPDATE `creature_template` SET `unit_flags`='0',`unit_flags2`='2048',`mechanic_immune_mask`='650854399',`flags_extra`='1',`ScriptName`='boss_jalak' WHERE `entry`='69374'; 
UPDATE `creature` SET `unit_flags`='526336',`dynamicflags`='24' WHERE `id`='69374'; 