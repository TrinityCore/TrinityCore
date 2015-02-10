--
SET @NPC:= 25968;
UPDATE `creature_template` SET `VehicleId`=30 WHERE `entry`=@NPC;
DELETE FROM `vehicle_template_accessory` where `entry` in (@NPC) AND `accessory_entry` IN (25801);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@NPC,25801,0,0,'Lunchbox',8,0);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = @NPC;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@NPC, 46598, 1, 0);

-- Nedar, Lord of Rhinos SAI
SET @ENTRY := 25801;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Say Line 0 (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,4,1,100,1,0,0,0,0,11,41440,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - On Aggro - Cast 'Shoot' (Phase 1) (No Repeat)"),
(@ENTRY,0,4,0,9,1,100,0,5,30,3500,4100,11,41440,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 5-30 Range - Cast 'Shoot' (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 30-100 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 9-15 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 0-5 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,8,0,9,1,100,0,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nedar, Lord of Rhinos - Within 5-30 Range - Disable Combat Movement (Phase 1)");
-- Complete the Broadcast_text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@ENTRY, 0, 0, 'Your impetuousness will be your end!', 12, 0, 100, 0, 0, 0, 'Nedar', 25103),
(@ENTRY, 0, 1, 'You dare challenge Nedar, lord of the tundral!?', 12, 0, 100, 0, 0, 0, 'Nedar', 25102),
(@ENTRY, 0, 2, 'You don''t stand a chance!', 12, 0, 100, 0, 0, 0, 'Nedar', 25104);

-- Pathing for  Entry: 25968 'TDB FORMAT' 
SET @NPC := 106302;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3170.232,`position_y`=5968.757,`position_z`=96.36165 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3170.232,5968.757,96.36165,0,0,0,0,100,0),
(@PATH,2,3159.33,5950.815,95.96857,0,0,0,0,100,0),
(@PATH,3,3162.685,5902.838,96.0918,0,0,0,0,100,0),
(@PATH,4,3169.452,5888.983,97.71611,0,0,0,0,100,0),
(@PATH,5,3204.079,5874.618,97.02065,0,0,0,0,100,0),
(@PATH,6,3238.726,5868.98,94.07452,0,0,0,0,100,0),
(@PATH,7,3266.804,5867.507,86.87187,0,0,0,0,100,0),
(@PATH,8,3300.308,5874.12,83.72194,0,0,0,0,100,0),
(@PATH,9,3328.993,5853.078,78.86817,0,0,0,0,100,0),
(@PATH,10,3344.677,5812.18,67.82541,0,0,0,0,100,0),
(@PATH,11,3341.184,5774.667,61.2993,0,0,0,0,100,0),
(@PATH,12,3357.205,5767.466,65.42284,0,0,0,0,100,0),
(@PATH,13,3357.227,5799.264,67.74834,0,0,0,0,100,0),
(@PATH,14,3359.967,5824.072,71.90356,0,0,0,0,100,0),
(@PATH,15,3354.479,5873.997,76.9686,0,0,0,0,100,0),
(@PATH,16,3341.863,5907.724,79.92758,0,0,0,0,100,0),
(@PATH,17,3316.034,5925.089,85.70946,0,0,0,0,100,0),
(@PATH,18,3293.812,5947.116,82.76896,0,0,0,0,100,0);
-- 0x2009144760195C0000000C000057E949 .go 3170.232 5968.757 96.36165
