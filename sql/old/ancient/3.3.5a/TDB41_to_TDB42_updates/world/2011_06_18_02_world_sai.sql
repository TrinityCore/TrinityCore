-- SAI for Lieutenant Commander Thalvos
SET @ENTRY := 16978;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,10848,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Lieutenant Commander Thalvos - On spawn - Cast Shroud of Death on self'),
(@ENTRY,0,1,0,0,0,50,0,4000,4000,8000,8000,11,8242,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Lieutenant Commander Thalvos - Combat - Cast Shield Slam on victim'),
(@ENTRY,0,2,0,0,0,50,0,5000,5000,10000,10000,11,11976,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Lieutenant Commander Thalvos - Combat - Cast Strike on victim');

-- Pathing for Lieutenant Commander Thalvos Entry: 16978
SET @NPC := 59381;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1402.399,`position_y`=2707.896,`position_z`=-27.4831 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1400.287,2711.631,-27.80707,0,0,0,100,0),
(@PATH,2,-1401.863,2713.817,-28.77578,0,0,0,100,0),
(@PATH,3,-1400.287,2711.631,-27.80707,0,0,0,100,0),
(@PATH,4,-1402.399,2707.896,-27.4831,0,0,0,100,0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_shroud_of_death';
