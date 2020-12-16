-- Kul'galar Oracle SAI
SET @ID := 30751;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,50,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Kul'galar Oracle - On Aggro - Say Line 0"),
(@ID,0,1,0,0,0,100,0,0,5000,10000,10000,0,11,31516,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kul'galar Oracle - In Combat - Cast 'Mind Blast'"),
(@ID,0,2,0,0,0,100,0,10000,10000,10000,10000,0,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kul'galar Oracle - In Combat - Cast 'Mind Flay'"),
(@ID,0,3,0,2,0,100,0,0,50,15000,15000,0,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kul'galar Oracle - Between 0-50% Health - Cast 'Heal'");

-- http://web.archive.org/web/20110930044957/www.wowhead.com/npc=30751
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"I will take pleasure in gutting you!",12,0,100,0,0,13533,30498,0,"Kul'galar Oracle"),
(@ID,0,1,"I will feed you to the dogs!",12,0,100,0,0,13534,30499,0,"Kul'galar Oracle"),
(@ID,0,2,"Your entrails will make a fine necklace.",12,0,100,0,0,13535,30500,0,"Kul'galar Oracle"),
(@ID,0,3,"Die, maggot!",12,0,100,0,0,13536,30501,0,"Kul'galar Oracle"),
(@ID,0,4,"You come to die!",12,0,100,0,0,13537,30502,0,"Kul'galar Oracle"),
(@ID,0,5,"I spit on you!",12,0,100,0,0,13538,30503,0,"Kul'galar Oracle"),
(@ID,0,6,"Sniveling pig!",12,0,100,0,0,13539,30504,0,"Kul'galar Oracle"),
(@ID,0,7,"Ugglin oo bjorr!",12,0,100,0,0,13540,30505,0,"Kul'galar Oracle"),
(@ID,0,8,"Haraak foln!",12,0,100,0,0,13541,30506,0,"Kul'galar Oracle"),
(@ID,0,9,"I'll eat your heart!",12,0,100,0,0,13542,30508,0,"Kul'galar Oracle");

-- Missing
DELETE FROM `creature` WHERE `guid` IN (131114,131115) AND `id` = 30751;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131114, 30751, 571, 1, 1, 1, 6881.22314453125, 3877.6171875, 628.111328125, 1.099557399749755859, 300, 0, 0, 0),
(131115, 30751, 571, 1, 1, 1, 6864.93017578125, 3892.772216796875, 628.0704345703125, 0.418879032135009765, 300, 0, 0, 0);

-- One with waypoint
UPDATE `creature_addon` SET `path_id` = 1213160 WHERE `guid` = 121316;
UPDATE `creature` SET `position_x` = 6828.8438, `position_y` = 3834.6167, `position_z` = 617.1061, `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = 121316;

DELETE FROM `waypoint_data` WHERE `id` IN (1213160);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1213160,1,6828.8438,3834.6167,617.1061,0,0,0,0,0,0),
(1213160,2,6838.888,3828.5977,617.10724,0,0,0,0,0,0),
(1213160,3,6850.9844,3821.2517,617.1043,0,0,0,0,0,0),
(1213160,4,6850.811,3810.5808,617.1045,0,0,0,0,0,0),
(1213160,5,6844.012,3798.514,617.1186,0,0,0,0,0,0),
(1213160,6,6832.3813,3781.005,617.1016,0,0,0,0,0,0),
(1213160,7,6823.7275,3767.9749,621.0698,0,0,0,0,0,0),
(1213160,8,6815.3276,3764.408,621.07666,0,0,0,0,0,0),
(1213160,9,6802.5513,3772.9504,621.05975,0,0,0,0,0,0),
(1213160,10,6791.561,3780.583,621.0746,0,0,0,0,0,0),
(1213160,11,6791.1,3789.4622,621.0703,0,0,0,0,0,0),
(1213160,12,6799.4443,3802.9565,617.1014,0,0,0,0,0,0),
(1213160,13,6808.6816,3818.294,617.10297,0,0,0,0,0,0),
(1213160,14,6817.262,3831.7695,617.10657,0,0,0,0,0,0);
