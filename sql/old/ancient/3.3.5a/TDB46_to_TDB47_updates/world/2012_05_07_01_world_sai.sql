-- Ymirjar Skycaller SAI addition
SET @ENTRY   := 31260; -- NPC entry
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,25,0,100,6,0,0,0,0,11,46598,0,0,0,0,0,19,36891,20,0,0,0,0,0, 'Ymirjar Skycaller - Reset - Cast Ride Vehicle Hardcoded');

-- Wrathbone Laborer SAI
SET @ENTRY   := -201800; -- NPC entry
SET @SPELL1  := 70302; -- Blinding Dirt
SET @SPELL2  := 70278; -- Puncture Wound
SET @SPELL3  := 69572; -- Shovelled!
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,8000,10000,11000,11,@SPELL1,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Wrathbone Laborer - Combat - Cast Blinding Dirt'),
(@ENTRY,0,1,0,0,0,100,6,8000,9000,9000,10000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wrathbone Laborer - Combat - Cast Puncture Wound (Normal)'),
(@ENTRY,0,2,0,0,0,100,6,5000,6000,7000,8000,11,@SPELL3,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Wrathbone Laborer - Combat - Cast Shovelled! (Normal)');

-- Wrathbone Laborer pathing
SET @NPC := 201800;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=584.4202,`position_y`=188.9149,`position_z`=509.6726 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,584.4202,188.9149,509.6726,0,0,0,100,0),
(@PATH,2,583.6736,193.9653,509.7404,3000,0,48,100,0),
(@PATH,3,583.6736,193.9653,509.7404,3000,0,48,100,0),
(@PATH,4,583.6736,193.9653,509.7404,3000,0,48,100,0),
(@PATH,5,583.6736,193.9653,509.7404,3000,0,48,100,0),
(@PATH,6,594.0781,190.2622,508.8613,0,0,0,100,0),
(@PATH,7,604.9809,191.5451,507.6583,0,0,0,100,0),
(@PATH,8,617.8438,191.3455,507.5206,0,0,0,100,0),
(@PATH,9,633.1597,186.8281,508.6275,3000,0,48,100,0),
(@PATH,10,633.1597,186.8281,508.6275,3000,0,48,100,0),
(@PATH,11,624.3472,190.9705,507.7706,0,0,0,100,0),
(@PATH,12,613.3229,189.9236,507.3956,0,0,0,100,0),
(@PATH,13,604.5156,189.651,507.3956,0,0,0,100,0),
(@PATH,14,593.9844,187.4479,508.9778,0,0,0,100,0),
(@PATH,15,584.4202,188.9149,509.6726,0,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id`=48;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`guid`) VALUES
(48,0,1,38,67);

-- Add Overlord Drakuru riders to Stonespine Gargoyle
UPDATE creature_template SET InhabitType=4,`flags_extra`=`flags_extra`|128 WHERE entry=28717;
DELETE FROM `creature` WHERE `id`=28717 AND `map`=658;
DELETE FROM `vehicle_template_accessory` WHERE `entry`=36896;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(36896,28717,1,0, 'Overlord Drakuru on Stonespine Gargoyle',6,30000);
