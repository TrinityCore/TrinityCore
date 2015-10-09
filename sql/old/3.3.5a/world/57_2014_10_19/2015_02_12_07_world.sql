-- Dawnblade Marksman SAI
SET @ENTRY := 24979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,0,70,7000,13000,11,45101,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dawnblade Marksman - Within 0-70 Range Out of Combat LoS - Cast 'Flaming Arrow'"),
(@ENTRY,0,1,0,1,0,100,0,3000,3000,5000,5000,11,45101,0,0,0,0,0,19,5202,26,0,0,0,0,0,"Dawnblade Marksman - Out of Combat - Cast 'Flaming Arrow'");

-- Pathing for  Entry: 25001 'TDB FORMAT' 
SET @NPC := 93967;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=12616.02,`position_y`=-6826.477,`position_z`=13.30631 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,12616.02,-6826.477,13.30631,0,0,0,0,100,0),
(@PATH,2,12615.95,-6826.547,13.58466,0,0,0,0,100,0),
(@PATH,3,12607.38,-6830.652,13.76608,0,0,0,0,100,0),
(@PATH,4,12591.51,-6834.896,13.87594,0,0,0,0,100,0),
(@PATH,5,12566.56,-6827.448,16.54662,0,0,0,0,100,0),
(@PATH,6,12579.94,-6832.642,14.98803,0,0,0,0,100,0),
(@PATH,7,12584.21,-6834.116,14.20888,0,0,0,0,100,0),
(@PATH,8,12591.75,-6834.886,13.74139,0,0,0,0,100,0),
(@PATH,9,12607.81,-6830.203,13.69277,0,0,0,0,100,0),
(@PATH,10,12616.39,-6826.547,13.49831,0,0,0,0,100,0),
(@PATH,11,12616.02,-6826.477,13.30631,0,0,0,0,100,0),
(@PATH,12,12615.95,-6826.547,13.5846,0,0,0,0,100,0),
(@PATH,13,12607.6,-6830.664,13.76679,0,0,0,0,100,0),
(@PATH,14,12591.65,-6834.927,13.87652,0,0,0,0,100,0),
(@PATH,15,12566.47,-6827.438,16.55291,0,0,0,0,100,0),
(@PATH,16,12579.94,-6832.642,14.98803,0,0,0,0,100,0),
(@PATH,17,12584.21,-6834.114,14.20937,0,0,0,0,100,0),
(@PATH,18,12591.73,-6834.884,13.74244,0,0,0,0,100,0),
(@PATH,19,12607.78,-6830.21,13.69292,0,0,0,0,100,0),
(@PATH,20,12616.38,-6826.549,13.49841,0,0,0,0,100,0),
(@PATH,21,12616.02,-6826.477,13.30631,0,0,0,0,100,0),
(@PATH,22,12615.95,-6826.547,13.58466,0,0,0,0,100,0),
(@PATH,23,12607.59,-6830.418,13.76704,0,0,0,0,100,0);
-- 0x1C09084240186A4000002E000055E86A .go 12616.02 -6826.477 13.30631

-- Pathing for  Entry: 25001 'TDB FORMAT' 
SET @NPC := 93966;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=12488.71,`position_y`=-6887.34,`position_z`=16.40788 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,12488.71,-6887.34,16.40788,0,0,0,0,100,0),
(@PATH,2,12495.96,-6887.744,16.62086,0,0,0,0,100,0),
(@PATH,3,12491.32,-6874.924,17.07642,0,0,0,0,100,0);
-- 0x1C09084240186A4000002E0000558FDB .go 12488.71 -6887.34 16.40788
