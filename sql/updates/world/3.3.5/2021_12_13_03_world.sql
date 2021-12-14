--
UPDATE `creature_template` SET `unit_flags2` = 32 WHERE `entry` = 29747;
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '55162 18950' WHERE `entry` = 29747;

UPDATE `creature_template_movement` SET `Flight` = 0 WHERE `CreatureId` = 29790;
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = '18950' WHERE `entry` = 29790;
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 2, `unit_flags2` = `unit_flags2`|32  WHERE `entry` = 29790;

-- Less than 40, only CreateObject1
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` IN (29747,29790);

-- When he despawns (corpse removed), 29790 despawns too, NYI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29747 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29747,0,0,0,37,0,100,0,0,0,0,0,0,116,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Ocular - On AI Initialize - Set Corpse Delay"),
(29747,0,1,0,0,0,100,0,0,0,4000,4000,0,11,55269,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Ocular - In Combat - Cast 'Deathly Stare'"),
(29747,0,2,0,6,0,100,0,0,0,0,0,0,11,55288,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Ocular - On Death - Cast 'It's All Fun and Games: The Ocular On Death'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 55288 AND `ScriptName` = 'spell_the_ocular_on_death';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(55288,'spell_the_ocular_on_death');
