--
SET @SPAWN_GROUP_ID := 333; -- 1
SET @CGUID := 142800; -- 5

UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave1' WHERE `guid` IN (144611,144653,144610,144656,144655,144654,144676);
UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave2' WHERE `guid` IN (144619,144617,144616,144660,144659,144658,144677);
UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave3' WHERE `guid` IN (144614,144613,144612,144618,144657,144615,144674);
UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave4' WHERE `guid` IN (144665,144662,144661,144626,144625,144623,144675);
UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave5' WHERE `guid` IN (144622,144621,144620,144664,144624,144663,144652);
UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave6' WHERE `guid` IN (144631,144670,144630,144672,144671,144669,144673);
UPDATE `creature` SET `StringId` = 'GeneralRajaxxWave7' WHERE `guid` IN (144629,144628,144627,144668,144667,144666,144651);

UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `id` IN (15385,15386,15388,15389,15390,15391,15392,15344,15387);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (144611,144619,144614,144665,144622,144631,144629);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(144611,144611,0,0,3,0,0),
(144611,144653,0,0,3,0,0),
(144611,144610,0,0,3,0,0),
(144611,144656,0,0,3,0,0),
(144611,144655,0,0,3,0,0),
(144611,144654,0,0,3,0,0),
(144611,144676,0,0,3,0,0),

(144619,144619,0,0,3,0,0),
(144619,144617,0,0,3,0,0),
(144619,144616,0,0,3,0,0),
(144619,144660,0,0,3,0,0),
(144619,144659,0,0,3,0,0),
(144619,144658,0,0,3,0,0),
(144619,144677,0,0,3,0,0),

(144614,144614,0,0,3,0,0),
(144614,144613,0,0,3,0,0),
(144614,144612,0,0,3,0,0),
(144614,144618,0,0,3,0,0),
(144614,144657,0,0,3,0,0),
(144614,144615,0,0,3,0,0),
(144614,144674,0,0,3,0,0),

(144665,144665,0,0,3,0,0),
(144665,144662,0,0,3,0,0),
(144665,144661,0,0,3,0,0),
(144665,144626,0,0,3,0,0),
(144665,144625,0,0,3,0,0),
(144665,144623,0,0,3,0,0),
(144665,144675,0,0,3,0,0),

(144622,144622,0,0,3,0,0),
(144622,144621,0,0,3,0,0),
(144622,144620,0,0,3,0,0),
(144622,144664,0,0,3,0,0),
(144622,144624,0,0,3,0,0),
(144622,144663,0,0,3,0,0),
(144622,144652,0,0,3,0,0),

(144631,144631,0,0,3,0,0),
(144631,144670,0,0,3,0,0),
(144631,144630,0,0,3,0,0),
(144631,144672,0,0,3,0,0),
(144631,144671,0,0,3,0,0),
(144631,144669,0,0,3,0,0),
(144631,144673,0,0,3,0,0),

(144629,144629,0,0,3,0,0),
(144629,144628,0,0,3,0,0),
(144629,144627,0,0,3,0,0),
(144629,144668,0,0,3,0,0),
(144629,144667,0,0,3,0,0),
(144629,144666,0,0,3,0,0),
(144629,144651,0,0,3,0,0);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+4 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,@CGUID+0),
(@SPAWN_GROUP_ID+0,0,@CGUID+1),
(@SPAWN_GROUP_ID+0,0,@CGUID+2),
(@SPAWN_GROUP_ID+0,0,@CGUID+3),
(@SPAWN_GROUP_ID+0,0,@CGUID+4);

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Ruins of Ahn'Qiraj - Lieutenant General Andorov",4);

-- These positions are not default, no CreateObject2
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+0,15471,509,0,0,1,1,0,1,-8624.473,1471.7743,32.0758,2.3319497,604800,0,0,17605,37290,0,0,33280,0,'',NULL,0),
(@CGUID+1,15473,509,0,0,1,1,0,1,-8624.473,1471.7743,32.0758,2.3319497,604800,0,0,9156,0,0,0,33280,0,'',NULL,0),
(@CGUID+2,15473,509,0,0,1,1,0,1,-8624.473,1471.7743,32.0758,2.3319497,604800,0,0,9156,0,0,0,33280,0,'',NULL,0),
(@CGUID+3,15473,509,0,0,1,1,0,1,-8624.473,1471.7743,32.0758,2.3319497,604800,0,0,9156,0,0,0,33280,0,'',NULL,0),
(@CGUID+4,15473,509,0,0,1,1,0,1,-8624.473,1471.7743,32.0758,2.3319497,604800,0,0,9156,0,0,0,33280,0,'',NULL,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+0;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+0,@CGUID+0,0,0,515,0,0),
(@CGUID+0,@CGUID+1,5,75,515,0,0),
(@CGUID+0,@CGUID+2,5,285,515,0,0),
(@CGUID+0,@CGUID+3,5,330,515,0,0),
(@CGUID+0,@CGUID+4,5,30,515,0,0);

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 15471;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(15471,1,1,0,0,0,0,0);

UPDATE `creature_template_addon` SET `SheathState` = 1 WHERE `entry` IN (15471,15473);

UPDATE `creature_template` SET `gossip_menu_id` = 0, `RegenHealth` = 0, `ScriptName` = 'npc_andorov' WHERE `entry` = 15471;
UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` = 15473;

-- First path is incomplete
DELETE FROM `waypoint_data` WHERE `id` IN (4,5);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(4,1,-8679.187,1535.1178,31.96736,NULL,0,1,0,100,0),
(4,2,-8701.477,1561.7574,32.17472,NULL,0,1,0,100,0),
(4,3,-8720.072,1580.9626,21.511324,NULL,0,1,0,100,0),
(4,4,-8746.162,1603.494,21.613367,NULL,0,1,0,100,0),
(4,5,-8780.431,1617.8787,21.455776,NULL,0,1,0,100,0),
(4,6,-8823.478,1624.6688,19.80574,NULL,0,1,0,100,0),
(4,7,-8855.329,1637.9473,19.790516,NULL,0,1,0,100,0),
(4,8,-8870.721,1648.4009,21.511328,5.637413501739501953,1,1,0,100,0),

(5,1,-8886.095,1598.713,21.4053,NULL,0,1,0,100,0),
(5,2,-8904.383,1578.6167,21.511332,NULL,0,1,0,100,0),
(5,3,-8920.576,1551.9479,21.407932,NULL,0,1,0,100,0),
(5,4,-8939.951,1551.127,21.566868,NULL,0,1,0,100,0);

DELETE FROM `gossip_menu` WHERE `MenuID` = 6629 AND `TextID` = 7883;
DELETE FROM `gossip_menu` WHERE `MenuID` = 7048 AND `TextID` IN (7883,8305);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6629,7883,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6629,7047);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6629,0,0,"Let's find out.",11026,1,1,0,0,0,0,'',0,0),
(7047,0,1,"Let's see what you have.",11820,3,128,0,0,0,0,'',0,0);

DELETE FROM `creature_text` WHERE `CreatureID` = 15471;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15471,0,0,"Remember, Rajaxx, when I said I'd kill you last?",14,0,100,22,0,0,11028,0,"Lieutenant General Andorov"),
(15471,1,0,"I lied...",14,0,100,0,0,0,11477,0,"Lieutenant General Andorov"),
(15471,2,0,"They come now. Try not to get yourself killed, young blood.",14,0,100,22,0,0,11012,0,"Lieutenant General Andorov"),
(15471,3,0,"Come get some!",12,0,100,25,0,0,11478,0,"Lieutenant General Andorov"),
(15471,4,0,"Kill first, ask questions later... Incoming!",14,0,100,45,0,0,11032,0,"Lieutenant General Andorov"),
(15471,5,0,"My work here is done. I'll be sure to let Mar'alith and the others at Cenarion Hold know that you helped me out a little. Be careful in here, you don't have me holdin' your hand past this point.",14,0,100,0,0,0,11560,0,"Lieutenant General Andorov");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 15473;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15473 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15473,0,0,0,0,0,100,0,5000,10000,5000,15000,0,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kaldorei Elite - In Combat - Cast 'Mortal Strike'"),
(15473,0,1,0,0,0,100,0,10000,15000,10000,20000,0,11,26350,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kaldorei Elite - In Combat - Cast 'Cleave'");

UPDATE `creature_template` SET `mingold` = 0, `maxgold` = 0, `AIName` = 'SmartAI' WHERE `entry` = 15344;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15344,15387) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15344,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Swarmguard Needler - On AI Initialize - Set Corpse Delay"),
(15344,0,1,0,0,0,100,0,5000,10000,5000,10000,0,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Swarmguard Needler - In Combat - Cast 'Cleave'"),

(15387,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Qiraji Warrior - On AI Initialize - Set Corpse Delay"),
(15387,0,1,0,0,0,100,0,10000,15000,10000,15000,0,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Qiraji Warrior - In Combat - Cast 'Uppercut'"),
(15387,0,2,0,0,0,100,0,10000,20000,15000,25000,0,11,15588,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Qiraji Warrior - In Combat - Cast 'Thunderclap'"),
(15387,0,3,0,2,0,100,1,0,25,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Qiraji Warrior - Between 0-25% Health - Cast 'Enrage' (No Repeat)"),
(15387,0,4,0,83,0,100,0,8599,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Qiraji Warrior - On Spell Cast 'Enrage' - Say Line 0");
