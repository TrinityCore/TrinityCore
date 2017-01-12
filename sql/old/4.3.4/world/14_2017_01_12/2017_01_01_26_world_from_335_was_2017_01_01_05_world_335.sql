/*
-- [Q] Lazy Peons -- http://wotlk.openwow.com/quest=5441
-- Spawn points for Peons
SET @PEON1  := 3345;
SET @PEON2  := 3346;
SET @PEON3  := 3347;
SET @PEON4  := 3348;
SET @PEON5  := 6523;
SET @PEON6  := 6524;
SET @PEON7  := 6525;
SET @PEON8  := 6526;
SET @PEON9  := 6527;
SET @PEON10 := 7372;
SET @PEON11 := 7373;
SET @PEON12 := 7374;
SET @PEON13 := 7375;
SET @PEON14 := 7376;

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=10556;
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=10556;

UPDATE `creature` SET `position_x` = -228.4774,   `position_y` = -4283.625,    `position_z` = 65.1967,   `orientation` = 2.894468   WHERE `guid` = 3345;
UPDATE `creature` SET `position_x` = -329.9962,   `position_y` = -4433.717,    `position_z` = 54.78109,  `orientation` = 5.104826   WHERE `guid` = 3346;
UPDATE `creature` SET `position_x` = -231.6027,   `position_y` = -4452.809,    `position_z` = 63.93166,  `orientation` = 4.117736   WHERE `guid` = 3347;
UPDATE `creature` SET `position_x` = -507.4363,   `position_y` = -4376.153,    `position_z` = 46.37408,  `orientation` = 6.219275   WHERE `guid` = 3348;

UPDATE `creature` SET `position_x` = -320.966064, `position_y` = -4127.114746, `position_z` = 51.772881, `orientation` = 3.5617     WHERE `guid` = 6523;
UPDATE `creature` SET `position_x` = -635.911,    `position_y` = -4477.310,    `position_z` = 46.4219,   `orientation` = 2.255680   WHERE `guid` = 6524;
UPDATE `creature` SET `position_x` = -762.9033,   `position_y` = -4322.073,    `position_z` = 46.41716,  `orientation` = 3.038773   WHERE `guid` = 6525;
UPDATE `creature` SET `position_x` = -370.2837,   `position_y` = -4015.476,    `position_z` = 50.76045,  `orientation` = 2.492314   WHERE `guid` = 6526;
UPDATE `creature` SET `position_x` = -754.0301,   `position_y` = -4144.65,     `position_z` = 38.48037,  `orientation` = 0.5896973  WHERE `guid` = 6527;

UPDATE `creature` SET `position_x` = -209.5101,   `position_y` = -4227.287,    `position_z` = 63.72701,  `orientation` = 1.119552   WHERE `guid` = 7372;
UPDATE `creature` SET `position_x` = -773.777405, `position_y` = -4201.205566, `position_z` = 45.349792, `orientation` = 5.097115   WHERE `guid` = 7373;
UPDATE `creature` SET `position_x` = -628.4796,   `position_y` = -4340.696,    `position_z` = 41.84069,  `orientation` = 2.213485   WHERE `guid` = 7374;
UPDATE `creature` SET `position_x` = -269.336365, `position_y` = -4144.420410, `position_z` = 55.177433, `orientation` = 4.241836   WHERE `guid` = 7375;
UPDATE `creature` SET `position_x` = -492.120117, `position_y` = -4452.654297, `position_z` = 50.877014, `orientation` = 0.643769   WHERE `guid` = 7376;

SET @POSITION_X_PILE_PEON1 := -228.318192;
SET @POSITION_Y_PILE_PEON1 := -4277.605957;
SET @POSITION_Z_PILE_PEON1 := 65.324715;
SET @POSITION_O_PILE_PEON1 := 1.029934;

SET @POSITION_X_TREE_PEON1 := -226.786011;
SET @POSITION_Y_TREE_PEON1 := -4285.760742;
SET @POSITION_Z_TREE_PEON1 := 64.969948;
SET @POSITION_O_TREE_PEON1 := 5.159563;

SET @POSITION_X_SPAWN_PEON1 := -228.477005;
SET @POSITION_Y_SPAWN_PEON1 := -4283.620117;
SET @POSITION_Z_SPAWN_PEON1 := 65.196701;
SET @POSITION_O_SPAWN_PEON1 := 2.894470;

-- Lazy Peon SAI
SET @GUID := -@PEON1;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON1*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON1*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON1,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON1*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON1*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON1,@POSITION_Y_PILE_PEON1,@POSITION_Z_PILE_PEON1,@POSITION_O_PILE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON1,@POSITION_Y_TREE_PEON1,@POSITION_Z_TREE_PEON1,@POSITION_O_TREE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON1,@POSITION_Y_PILE_PEON1,@POSITION_Z_PILE_PEON1,@POSITION_O_PILE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON1,@POSITION_Y_TREE_PEON1,@POSITION_Z_TREE_PEON1,@POSITION_O_TREE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON1,@POSITION_Y_SPAWN_PEON1,@POSITION_Z_SPAWN_PEON1,@POSITION_O_SPAWN_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON1*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON1*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON1,@POSITION_Y_PILE_PEON1,@POSITION_Z_PILE_PEON1,@POSITION_O_PILE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON1,@POSITION_Y_TREE_PEON1,@POSITION_Z_TREE_PEON1,@POSITION_O_TREE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON1,@POSITION_Y_PILE_PEON1,@POSITION_Z_PILE_PEON1,@POSITION_O_PILE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON1,@POSITION_Y_TREE_PEON1,@POSITION_Z_TREE_PEON1,@POSITION_O_TREE_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON1,@POSITION_Y_SPAWN_PEON1,@POSITION_Z_SPAWN_PEON1,@POSITION_O_SPAWN_PEON1,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON2 := -331.700409;
SET @POSITION_Y_PILE_PEON2 := -4428.636719;
SET @POSITION_Z_PILE_PEON2 := 53.781979;
SET @POSITION_O_PILE_PEON2 := 2.234198;

SET @POSITION_X_TREE_PEON2 := -334.503632;
SET @POSITION_Y_TREE_PEON2 := -4440.127930;
SET @POSITION_Z_TREE_PEON2 := 54.717014;
SET @POSITION_O_TREE_PEON2 := 4.468656;

SET @POSITION_X_SPAWN_PEON2 := -329.996002;
SET @POSITION_Y_SPAWN_PEON2 := -4433.720215;
SET @POSITION_Z_SPAWN_PEON2 := 54.781101;
SET @POSITION_O_SPAWN_PEON2 := 5.104830;

-- Lazy Peon SAI
SET @GUID := -@PEON2;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON2*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON2*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON2,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON2*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON2*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON2,@POSITION_Y_PILE_PEON2,@POSITION_Z_PILE_PEON2,@POSITION_O_PILE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON2,@POSITION_Y_TREE_PEON2,@POSITION_Z_TREE_PEON2,@POSITION_O_TREE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON2,@POSITION_Y_PILE_PEON2,@POSITION_Z_PILE_PEON2,@POSITION_O_PILE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON2,@POSITION_Y_TREE_PEON2,@POSITION_Z_TREE_PEON2,@POSITION_O_TREE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON2,@POSITION_Y_SPAWN_PEON2,@POSITION_Z_SPAWN_PEON2,@POSITION_O_SPAWN_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON2*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON2*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON2,@POSITION_Y_PILE_PEON2,@POSITION_Z_PILE_PEON2,@POSITION_O_PILE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON2,@POSITION_Y_TREE_PEON2,@POSITION_Z_TREE_PEON2,@POSITION_O_TREE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON2,@POSITION_Y_PILE_PEON2,@POSITION_Z_PILE_PEON2,@POSITION_O_PILE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON2,@POSITION_Y_TREE_PEON2,@POSITION_Z_TREE_PEON2,@POSITION_O_TREE_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON2,@POSITION_Y_SPAWN_PEON2,@POSITION_Z_SPAWN_PEON2,@POSITION_O_SPAWN_PEON2,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON3 := -234.100235    ;
SET @POSITION_Y_PILE_PEON3 := -4450.192871   ;
SET @POSITION_Z_PILE_PEON3 := 63.215687      ;
SET @POSITION_O_PILE_PEON3 := 2.952211       ;

SET @POSITION_X_TREE_PEON3 := -228.190231   ;
SET @POSITION_Y_TREE_PEON3 := -4448.532715  ;
SET @POSITION_Z_TREE_PEON3 := 63.746113     ;
SET @POSITION_O_TREE_PEON3 := 0.026598      ;

SET @POSITION_X_SPAWN_PEON3 := -231.602997     ;
SET @POSITION_Y_SPAWN_PEON3 := -4452.810059    ;
SET @POSITION_Z_SPAWN_PEON3 := 63.931702       ;
SET @POSITION_O_SPAWN_PEON3 := 4.117740        ;

-- Lazy Peon SAI
SET @GUID := -@PEON3;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON3*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON3*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON3,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON3*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON3*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON3,@POSITION_Y_PILE_PEON3,@POSITION_Z_PILE_PEON3,@POSITION_O_PILE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON3,@POSITION_Y_TREE_PEON3,@POSITION_Z_TREE_PEON3,@POSITION_O_TREE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON3,@POSITION_Y_PILE_PEON3,@POSITION_Z_PILE_PEON3,@POSITION_O_PILE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON3,@POSITION_Y_TREE_PEON3,@POSITION_Z_TREE_PEON3,@POSITION_O_TREE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON3,@POSITION_Y_SPAWN_PEON3,@POSITION_Z_SPAWN_PEON3,@POSITION_O_SPAWN_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON3*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON3*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON3,@POSITION_Y_PILE_PEON3,@POSITION_Z_PILE_PEON3,@POSITION_O_PILE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON3,@POSITION_Y_TREE_PEON3,@POSITION_Z_TREE_PEON3,@POSITION_O_TREE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON3,@POSITION_Y_PILE_PEON3,@POSITION_Z_PILE_PEON3,@POSITION_O_PILE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON3,@POSITION_Y_TREE_PEON3,@POSITION_Z_TREE_PEON3,@POSITION_O_TREE_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON3,@POSITION_Y_SPAWN_PEON3,@POSITION_Z_SPAWN_PEON3,@POSITION_O_SPAWN_PEON3,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON4 := -516.796692   ;
SET @POSITION_Y_PILE_PEON4 := -4375.855469  ;
SET @POSITION_Z_PILE_PEON4 := 46.178135     ;
SET @POSITION_O_PILE_PEON4 := 3.609392      ;

SET @POSITION_X_TREE_PEON4 := -509.902527  ;
SET @POSITION_Y_TREE_PEON4 := -4372.287109 ;
SET @POSITION_Z_TREE_PEON4 := 45.631256    ;
SET @POSITION_O_TREE_PEON4 := 0.489787     ;

SET @POSITION_X_SPAWN_PEON4 := -510.443481  ;
SET @POSITION_Y_SPAWN_PEON4 := -4378.929688 ;
SET @POSITION_Z_SPAWN_PEON4 := 45.732010    ;
SET @POSITION_O_SPAWN_PEON4 := 5.155056     ;

-- Lazy Peon SAI
SET @GUID := -@PEON4;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON4*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON4*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON4;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON4,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON4*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON4*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON4,@POSITION_Y_PILE_PEON4,@POSITION_Z_PILE_PEON4,@POSITION_O_PILE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON4,@POSITION_Y_TREE_PEON4,@POSITION_Z_TREE_PEON4,@POSITION_O_TREE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON4,@POSITION_Y_PILE_PEON4,@POSITION_Z_PILE_PEON4,@POSITION_O_PILE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON4,@POSITION_Y_TREE_PEON4,@POSITION_Z_TREE_PEON4,@POSITION_O_TREE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON4,@POSITION_Y_SPAWN_PEON4,@POSITION_Z_SPAWN_PEON4,@POSITION_O_SPAWN_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON4*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON4*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON4,@POSITION_Y_PILE_PEON4,@POSITION_Z_PILE_PEON4,@POSITION_O_PILE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON4,@POSITION_Y_TREE_PEON4,@POSITION_Z_TREE_PEON4,@POSITION_O_TREE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON4,@POSITION_Y_PILE_PEON4,@POSITION_Z_PILE_PEON4,@POSITION_O_PILE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON4,@POSITION_Y_TREE_PEON4,@POSITION_Z_TREE_PEON4,@POSITION_O_TREE_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON4,@POSITION_Y_SPAWN_PEON4,@POSITION_Z_SPAWN_PEON4,@POSITION_O_SPAWN_PEON4,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON5 := -318.612732   ;
SET @POSITION_Y_PILE_PEON5 := -4133.320313  ;
SET @POSITION_Z_PILE_PEON5 := 52.775509     ;
SET @POSITION_O_PILE_PEON5 := 0.337633      ;

SET @POSITION_X_TREE_PEON5 := -317.230438  ;
SET @POSITION_Y_TREE_PEON5 := -4124.106445 ;
SET @POSITION_Z_TREE_PEON5 := 51.838612    ;
SET @POSITION_O_TREE_PEON5 := 1.362578     ;

SET @POSITION_X_SPAWN_PEON5 := -320.966003  ;
SET @POSITION_Y_SPAWN_PEON5 := -4127.109863 ;
SET @POSITION_Z_SPAWN_PEON5 := 51.772900    ;
SET @POSITION_O_SPAWN_PEON5 := 3.561700     ;

-- Lazy Peon SAI
SET @GUID := -@PEON5;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON5*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON5*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON5;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON5,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON5*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON5*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON5,@POSITION_Y_PILE_PEON5,@POSITION_Z_PILE_PEON5,@POSITION_O_PILE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON5,@POSITION_Y_TREE_PEON5,@POSITION_Z_TREE_PEON5,@POSITION_O_TREE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON5,@POSITION_Y_PILE_PEON5,@POSITION_Z_PILE_PEON5,@POSITION_O_PILE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON5,@POSITION_Y_TREE_PEON5,@POSITION_Z_TREE_PEON5,@POSITION_O_TREE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON5,@POSITION_Y_SPAWN_PEON5,@POSITION_Z_SPAWN_PEON5,@POSITION_O_SPAWN_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON5*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON5*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON5,@POSITION_Y_PILE_PEON5,@POSITION_Z_PILE_PEON5,@POSITION_O_PILE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON5,@POSITION_Y_TREE_PEON5,@POSITION_Z_TREE_PEON5,@POSITION_O_TREE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON5,@POSITION_Y_PILE_PEON5,@POSITION_Z_PILE_PEON5,@POSITION_O_PILE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON5,@POSITION_Y_TREE_PEON5,@POSITION_Z_TREE_PEON5,@POSITION_O_TREE_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON5,@POSITION_Y_SPAWN_PEON5,@POSITION_Z_SPAWN_PEON5,@POSITION_O_SPAWN_PEON5,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON6 := -629.116638  ;
SET @POSITION_Y_PILE_PEON6 := -4468.449219 ;
SET @POSITION_Z_PILE_PEON6 := 46.627659    ;
SET @POSITION_O_PILE_PEON6 := 1.305348     ;

SET @POSITION_X_TREE_PEON6 := -634.474487  ;
SET @POSITION_Y_TREE_PEON6 := -4482.156738 ;
SET @POSITION_Z_TREE_PEON6 := 46.124321    ;
SET @POSITION_O_TREE_PEON6 := 4.783332     ;

SET @POSITION_X_SPAWN_PEON6 := -635.911011  ;
SET @POSITION_Y_SPAWN_PEON6 := -4477.310059 ;
SET @POSITION_Z_SPAWN_PEON6 := 46.421902    ;
SET @POSITION_O_SPAWN_PEON6 := 2.255680     ;

-- Lazy Peon SAI
SET @GUID := -@PEON6;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON6*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON6*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON6;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON6,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON6*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON6*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON6,@POSITION_Y_PILE_PEON6,@POSITION_Z_PILE_PEON6,@POSITION_O_PILE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON6,@POSITION_Y_TREE_PEON6,@POSITION_Z_TREE_PEON6,@POSITION_O_TREE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON6,@POSITION_Y_PILE_PEON6,@POSITION_Z_PILE_PEON6,@POSITION_O_PILE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON6,@POSITION_Y_TREE_PEON6,@POSITION_Z_TREE_PEON6,@POSITION_O_TREE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON6,@POSITION_Y_SPAWN_PEON6,@POSITION_Z_SPAWN_PEON6,@POSITION_O_SPAWN_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON6*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON6*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON6,@POSITION_Y_PILE_PEON6,@POSITION_Z_PILE_PEON6,@POSITION_O_PILE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON6,@POSITION_Y_TREE_PEON6,@POSITION_Z_TREE_PEON6,@POSITION_O_TREE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON6,@POSITION_Y_PILE_PEON6,@POSITION_Z_PILE_PEON6,@POSITION_O_PILE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON6,@POSITION_Y_TREE_PEON6,@POSITION_Z_TREE_PEON6,@POSITION_O_TREE_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON6,@POSITION_Y_SPAWN_PEON6,@POSITION_Z_SPAWN_PEON6,@POSITION_O_SPAWN_PEON6,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON7 := -755.114380  ;
SET @POSITION_Y_PILE_PEON7 := -4323.081055 ;
SET @POSITION_Z_PILE_PEON7 := 43.814201    ;
SET @POSITION_O_PILE_PEON7 := 0.698278     ;

SET @POSITION_X_TREE_PEON7 := -757.435791  ;
SET @POSITION_Y_TREE_PEON7 := -4325.995605 ;
SET @POSITION_Z_TREE_PEON7 := 45.419209    ;
SET @POSITION_O_TREE_PEON7 := 4.051932     ;

SET @POSITION_X_SPAWN_PEON7 := -759.837891  ;
SET @POSITION_Y_SPAWN_PEON7 := -4318.93750 ;
SET @POSITION_Z_SPAWN_PEON7 := 44.053291    ;
SET @POSITION_O_SPAWN_PEON7 := 5.042316     ;

-- Lazy Peon SAI
SET @GUID := -@PEON7;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON7*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON7*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON7;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON7,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON7*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON7*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON7,@POSITION_Y_PILE_PEON7,@POSITION_Z_PILE_PEON7,@POSITION_O_PILE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON7,@POSITION_Y_TREE_PEON7,@POSITION_Z_TREE_PEON7,@POSITION_O_TREE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON7,@POSITION_Y_PILE_PEON7,@POSITION_Z_PILE_PEON7,@POSITION_O_PILE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON7,@POSITION_Y_TREE_PEON7,@POSITION_Z_TREE_PEON7,@POSITION_O_TREE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON7,@POSITION_Y_SPAWN_PEON7,@POSITION_Z_SPAWN_PEON7,@POSITION_O_SPAWN_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON7*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON7*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON7,@POSITION_Y_PILE_PEON7,@POSITION_Z_PILE_PEON7,@POSITION_O_PILE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON7,@POSITION_Y_TREE_PEON7,@POSITION_Z_TREE_PEON7,@POSITION_O_TREE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON7,@POSITION_Y_PILE_PEON7,@POSITION_Z_PILE_PEON7,@POSITION_O_PILE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON7,@POSITION_Y_TREE_PEON7,@POSITION_Z_TREE_PEON7,@POSITION_O_TREE_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON7,@POSITION_Y_SPAWN_PEON7,@POSITION_Z_SPAWN_PEON7,@POSITION_O_SPAWN_PEON7,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON8 := -369.242096    ;
SET @POSITION_Y_PILE_PEON8 := -4017.570313   ;
SET @POSITION_Z_PILE_PEON8 := 50.649097      ;
SET @POSITION_O_PILE_PEON8 := 5.221568       ;

SET @POSITION_X_TREE_PEON8 := -374.908752  ;
SET @POSITION_Y_TREE_PEON8 := -4015.791016 ;
SET @POSITION_Z_TREE_PEON8 := 50.530804    ;
SET @POSITION_O_TREE_PEON8 := 2.837883     ;

SET @POSITION_X_SPAWN_PEON8 := -371.200897  ;
SET @POSITION_Y_SPAWN_PEON8 := -4012.190430 ;
SET @POSITION_Z_SPAWN_PEON8 := 50.852230    ;
SET @POSITION_O_SPAWN_PEON8 := 1.337773     ;

-- Lazy Peon SAI
SET @GUID := -@PEON8;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON8*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON8*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON8;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON8,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON8*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON8*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON8,@POSITION_Y_PILE_PEON8,@POSITION_Z_PILE_PEON8,@POSITION_O_PILE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON8,@POSITION_Y_TREE_PEON8,@POSITION_Z_TREE_PEON8,@POSITION_O_TREE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON8,@POSITION_Y_PILE_PEON8,@POSITION_Z_PILE_PEON8,@POSITION_O_PILE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON8,@POSITION_Y_TREE_PEON8,@POSITION_Z_TREE_PEON8,@POSITION_O_TREE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON8,@POSITION_Y_SPAWN_PEON8,@POSITION_Z_SPAWN_PEON8,@POSITION_O_SPAWN_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON8*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON8*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON8,@POSITION_Y_PILE_PEON8,@POSITION_Z_PILE_PEON8,@POSITION_O_PILE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON8,@POSITION_Y_TREE_PEON8,@POSITION_Z_TREE_PEON8,@POSITION_O_TREE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON8,@POSITION_Y_PILE_PEON8,@POSITION_Z_PILE_PEON8,@POSITION_O_PILE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON8,@POSITION_Y_TREE_PEON8,@POSITION_Z_TREE_PEON8,@POSITION_O_TREE_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON8,@POSITION_Y_SPAWN_PEON8,@POSITION_Z_SPAWN_PEON8,@POSITION_O_SPAWN_PEON8,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON9 := -755.819580  ;
SET @POSITION_Y_PILE_PEON9 := -4147.388184 ;
SET @POSITION_Z_PILE_PEON9 := 37.674122    ;
SET @POSITION_O_PILE_PEON9 := 2.231965     ;

SET @POSITION_X_TREE_PEON9 := -752.944031   ;
SET @POSITION_Y_TREE_PEON9 := -4140.561523  ;
SET @POSITION_Z_TREE_PEON9 := 39.402321     ;
SET @POSITION_O_TREE_PEON9 := 1.435571      ;

SET @POSITION_X_SPAWN_PEON9 := -752.252563  ;
SET @POSITION_Y_SPAWN_PEON9 := -4144.263184 ;
SET @POSITION_Z_SPAWN_PEON9 := 38.048325    ;
SET @POSITION_O_SPAWN_PEON9 := 2.000272     ;

-- Lazy Peon SAI
SET @GUID := -@PEON9;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON9*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON9*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON9;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON9,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON9*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON9*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON9,@POSITION_Y_PILE_PEON9,@POSITION_Z_PILE_PEON9,@POSITION_O_PILE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON9,@POSITION_Y_TREE_PEON9,@POSITION_Z_TREE_PEON9,@POSITION_O_TREE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON9,@POSITION_Y_PILE_PEON9,@POSITION_Z_PILE_PEON9,@POSITION_O_PILE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON9,@POSITION_Y_TREE_PEON9,@POSITION_Z_TREE_PEON9,@POSITION_O_TREE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON9,@POSITION_Y_SPAWN_PEON9,@POSITION_Z_SPAWN_PEON9,@POSITION_O_SPAWN_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON9*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON9*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON9,@POSITION_Y_PILE_PEON9,@POSITION_Z_PILE_PEON9,@POSITION_O_PILE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON9,@POSITION_Y_TREE_PEON9,@POSITION_Z_TREE_PEON9,@POSITION_O_TREE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON9,@POSITION_Y_PILE_PEON9,@POSITION_Z_PILE_PEON9,@POSITION_O_PILE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON9,@POSITION_Y_TREE_PEON9,@POSITION_Z_TREE_PEON9,@POSITION_O_TREE_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON9,@POSITION_Y_SPAWN_PEON9,@POSITION_Z_SPAWN_PEON9,@POSITION_O_SPAWN_PEON9,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON10 := -210.639725  ;
SET @POSITION_Y_PILE_PEON10 := -4231.775391 ;
SET @POSITION_Z_PILE_PEON10 := 63.425655    ;
SET @POSITION_O_PILE_PEON10 := 3.377568     ;

SET @POSITION_X_TREE_PEON10 := -212.516220   ;
SET @POSITION_Y_TREE_PEON10 := -4219.286133  ;
SET @POSITION_Z_TREE_PEON10 := 62.137337     ;
SET @POSITION_O_TREE_PEON10 := 1.920655      ;

SET @POSITION_X_SPAWN_PEON10 := -209.509995   ;
SET @POSITION_Y_SPAWN_PEON10 := -4227.290039  ;
SET @POSITION_Z_SPAWN_PEON10 := 63.727001     ;
SET @POSITION_O_SPAWN_PEON10 := 1.119550      ;

-- Lazy Peon SAI
SET @GUID := -@PEON10;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON10*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON10*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON10;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON10,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON10*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON10*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON10,@POSITION_Y_PILE_PEON10,@POSITION_Z_PILE_PEON10,@POSITION_O_PILE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON10,@POSITION_Y_TREE_PEON10,@POSITION_Z_TREE_PEON10,@POSITION_O_TREE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON10,@POSITION_Y_PILE_PEON10,@POSITION_Z_PILE_PEON10,@POSITION_O_PILE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON10,@POSITION_Y_TREE_PEON10,@POSITION_Z_TREE_PEON10,@POSITION_O_TREE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON10,@POSITION_Y_SPAWN_PEON10,@POSITION_Z_SPAWN_PEON10,@POSITION_O_SPAWN_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON10*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON10*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON10,@POSITION_Y_PILE_PEON10,@POSITION_Z_PILE_PEON10,@POSITION_O_PILE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON10,@POSITION_Y_TREE_PEON10,@POSITION_Z_TREE_PEON10,@POSITION_O_TREE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON10,@POSITION_Y_PILE_PEON10,@POSITION_Z_PILE_PEON10,@POSITION_O_PILE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON10,@POSITION_Y_TREE_PEON10,@POSITION_Z_TREE_PEON10,@POSITION_O_TREE_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON10,@POSITION_Y_SPAWN_PEON10,@POSITION_Z_SPAWN_PEON10,@POSITION_O_SPAWN_PEON10,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON11 := -769.523254  ;
SET @POSITION_Y_PILE_PEON11 := -4203.342285 ;
SET @POSITION_Z_PILE_PEON11 := 43.979511    ;
SET @POSITION_O_PILE_PEON11 := 3.577382     ;

SET @POSITION_X_TREE_PEON11 := -775.303101  ;
SET @POSITION_Y_TREE_PEON11 := -4194.231445 ;
SET @POSITION_Z_TREE_PEON11 := 43.429829    ;
SET @POSITION_O_TREE_PEON11 := 2.234346     ;  

SET @POSITION_X_SPAWN_PEON11 := -769.857544  ;
SET @POSITION_Y_SPAWN_PEON11 := -4197.432617 ;
SET @POSITION_Z_SPAWN_PEON11 := 42.244511    ;
SET @POSITION_O_SPAWN_PEON11 := 4.900772     ;

-- Lazy Peon SAI
SET @GUID := -@PEON11;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON11*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON11*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON11,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON11*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON11*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON11,@POSITION_Y_PILE_PEON11,@POSITION_Z_PILE_PEON11,@POSITION_O_PILE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON11,@POSITION_Y_TREE_PEON11,@POSITION_Z_TREE_PEON11,@POSITION_O_TREE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON11,@POSITION_Y_PILE_PEON11,@POSITION_Z_PILE_PEON11,@POSITION_O_PILE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON11,@POSITION_Y_TREE_PEON11,@POSITION_Z_TREE_PEON11,@POSITION_O_TREE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON11,@POSITION_Y_SPAWN_PEON11,@POSITION_Z_SPAWN_PEON11,@POSITION_O_SPAWN_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON11*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON11*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON11,@POSITION_Y_PILE_PEON11,@POSITION_Z_PILE_PEON11,@POSITION_O_PILE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON11,@POSITION_Y_TREE_PEON11,@POSITION_Z_TREE_PEON11,@POSITION_O_TREE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON11,@POSITION_Y_PILE_PEON11,@POSITION_Z_PILE_PEON11,@POSITION_O_PILE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON11,@POSITION_Y_TREE_PEON11,@POSITION_Z_TREE_PEON11,@POSITION_O_TREE_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON11,@POSITION_Y_SPAWN_PEON11,@POSITION_Z_SPAWN_PEON11,@POSITION_O_SPAWN_PEON11,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON12 := -621.197;
SET @POSITION_Y_PILE_PEON12 := -4336.11;
SET @POSITION_Z_PILE_PEON12 := 41.1525;
SET @POSITION_O_PILE_PEON12 := 0.0108;

SET @POSITION_X_TREE_PEON12 := -623.236;
SET @POSITION_Y_TREE_PEON12 := -4349.7;
SET @POSITION_Z_TREE_PEON12 := 41.0866;
SET @POSITION_O_TREE_PEON12 := 4.7389;

SET @POSITION_X_SPAWN_PEON12 := -626.904;
SET @POSITION_Y_SPAWN_PEON12 := -4343.6;
SET @POSITION_Z_SPAWN_PEON12 := 41.5611;
SET @POSITION_O_SPAWN_PEON12 := 1.888;

-- Lazy Peon SAI
SET @GUID := -@PEON12;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON12*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON12*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON12;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON12,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON12*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON12,@POSITION_Y_PILE_PEON12,@POSITION_Z_PILE_PEON12,@POSITION_O_PILE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON12,@POSITION_Y_TREE_PEON12,@POSITION_Z_TREE_PEON12,@POSITION_O_TREE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON12,@POSITION_Y_PILE_PEON12,@POSITION_Z_PILE_PEON12,@POSITION_O_PILE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON12,@POSITION_Y_TREE_PEON12,@POSITION_Z_TREE_PEON12,@POSITION_O_TREE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON12,@POSITION_Y_SPAWN_PEON12,@POSITION_Z_SPAWN_PEON12,@POSITION_O_SPAWN_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON12*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON12,@POSITION_Y_PILE_PEON12,@POSITION_Z_PILE_PEON12,@POSITION_O_PILE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON12,@POSITION_Y_TREE_PEON12,@POSITION_Z_TREE_PEON12,@POSITION_O_TREE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON12,@POSITION_Y_PILE_PEON12,@POSITION_Z_PILE_PEON12,@POSITION_O_PILE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON12,@POSITION_Y_TREE_PEON12,@POSITION_Z_TREE_PEON12,@POSITION_O_TREE_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON12,@POSITION_Y_SPAWN_PEON12,@POSITION_Z_SPAWN_PEON12,@POSITION_O_SPAWN_PEON12,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON13 := -269.135712   ;
SET @POSITION_Y_PILE_PEON13 := -4137.832031  ;
SET @POSITION_Z_PILE_PEON13 := 56.127228     ;
SET @POSITION_O_PILE_PEON13 := 1.371207      ;

SET @POSITION_X_TREE_PEON13 := -263.702606   ;
SET @POSITION_Y_TREE_PEON13 := -4144.720215  ;
SET @POSITION_Z_TREE_PEON13 := 56.156487     ;
SET @POSITION_O_TREE_PEON13 := 5.557373      ;

SET @POSITION_X_SPAWN_PEON13 := -269.335999 ;
SET @POSITION_Y_SPAWN_PEON13 := -4144.419922;
SET @POSITION_Z_SPAWN_PEON13 := 55.177399   ;
SET @POSITION_O_SPAWN_PEON13 := 4.241840    ;

-- Lazy Peon SAI
SET @GUID := -@PEON13;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON13*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON13*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON13,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON13*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON13*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON13,@POSITION_Y_PILE_PEON13,@POSITION_Z_PILE_PEON13,@POSITION_O_PILE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON13,@POSITION_Y_TREE_PEON13,@POSITION_Z_TREE_PEON13,@POSITION_O_TREE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON13,@POSITION_Y_PILE_PEON13,@POSITION_Z_PILE_PEON13,@POSITION_O_PILE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON13,@POSITION_Y_TREE_PEON13,@POSITION_Z_TREE_PEON13,@POSITION_O_TREE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON13,@POSITION_Y_SPAWN_PEON13,@POSITION_Z_SPAWN_PEON13,@POSITION_O_SPAWN_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON13*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON13*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON13,@POSITION_Y_PILE_PEON13,@POSITION_Z_PILE_PEON13,@POSITION_O_PILE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON13,@POSITION_Y_TREE_PEON13,@POSITION_Z_TREE_PEON13,@POSITION_O_TREE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON13,@POSITION_Y_PILE_PEON13,@POSITION_Z_PILE_PEON13,@POSITION_O_PILE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON13,@POSITION_Y_TREE_PEON13,@POSITION_Z_TREE_PEON13,@POSITION_O_TREE_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON13,@POSITION_Y_SPAWN_PEON13,@POSITION_Z_SPAWN_PEON13,@POSITION_O_SPAWN_PEON13,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

SET @POSITION_X_PILE_PEON14 := -494.017792  ;
SET @POSITION_Y_PILE_PEON14 := -4459.838867 ;
SET @POSITION_Z_PILE_PEON14 := 51.533356    ;
SET @POSITION_O_PILE_PEON14 := 4.786746     ;

SET @POSITION_X_TREE_PEON14 := -498.779388  ;
SET @POSITION_Y_TREE_PEON14 := -4457.593750 ;
SET @POSITION_Z_TREE_PEON14 := 51.125401    ;
SET @POSITION_O_TREE_PEON14 := 2.980334     ;

SET @POSITION_X_SPAWN_PEON14 := -492.120117  ;
SET @POSITION_Y_SPAWN_PEON14 := -4452.654297 ;
SET @POSITION_Z_SPAWN_PEON14 := 50.877014    ;
SET @POSITION_O_SPAWN_PEON14 := 0.643769     ;

-- Lazy Peon SAI
SET @GUID := -@PEON14;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Reset - Cast 'Peon Sleeping'"),
(@GUID,0,1,0,1,0,100,0,120000,150000,120000,150000,80,@PEON14*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - Out of Combat - Run Script"), -- Awaken Self script
(@GUID,0,2,3,8,0,100,0,19938,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Reset All Scripts"),
(@GUID,0,3,4,61,0,100,0,19938,0,0,0,80,@PEON14*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Run Script"), -- Awaken by Player Script
(@GUID,0,4,0,61,0,100,0,19938,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lazy Peon - On Spellhit 'Awaken Peon' - Store Targetlist");

-- Conditions to execute SAI
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=3 AND `SourceEntry`=-@PEON14;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,-@PEON14,0,0,1,1,17743,0,0,0,0,0,"","Lazy Peon - Only run script if buff 'Peon Sleeping' is on peon");

-- Actionlist SAI
SET @ENTRY := @PEON14*100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON14*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON14,@POSITION_Y_PILE_PEON14,@POSITION_Z_PILE_PEON14,@POSITION_O_PILE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,5,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON14,@POSITION_Y_TREE_PEON14,@POSITION_Z_TREE_PEON14,@POSITION_O_TREE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,10,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,11,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON14,@POSITION_Y_PILE_PEON14,@POSITION_Z_PILE_PEON14,@POSITION_O_PILE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,13,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,14,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,15,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,16,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON14,@POSITION_Y_TREE_PEON14,@POSITION_Z_TREE_PEON14,@POSITION_O_TREE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,18,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,20,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON14,@POSITION_Y_SPAWN_PEON14,@POSITION_Z_SPAWN_PEON14,@POSITION_O_SPAWN_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");

-- Actionlist SAI
SET @ENTRY := @PEON14*100+1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEON14*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Peon Sleeping'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Talk line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,115,6292,6294,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound Rndmsound 6292 6294"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,33,10556,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lazy Peon - On Script - Add Kill Monstercredit"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run On"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON14,@POSITION_Y_PILE_PEON14,@POSITION_Z_PILE_PEON14,@POSITION_O_PILE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Run Off"),
(@ENTRY,9,8,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,9,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,10,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,11,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON14,@POSITION_Y_TREE_PEON14,@POSITION_Z_TREE_PEON14,@POSITION_O_TREE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,13,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,14,0,0,0,100,0,30000,30000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,15,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_PILE_PEON14,@POSITION_Y_PILE_PEON14,@POSITION_Z_PILE_PEON14,@POSITION_O_PILE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,17,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,20,175784,10,0,0,0,0,0,"Lazy Peon - On Script - Set Orientation Closest Gameobject 'LumberPile'"),
(@ENTRY,9,18,0,0,0,100,0,2500,2500,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,19,0,0,0,100,0,3000,3000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Remove Aura 'Kneel'"),
(@ENTRY,9,20,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_TREE_PEON14,@POSITION_Y_TREE_PEON14,@POSITION_Z_TREE_PEON14,@POSITION_O_TREE_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,4,6197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Play Sound 6197"),
(@ENTRY,9,22,0,0,0,100,0,0,0,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 173"),
(@ENTRY,9,23,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Set Emote State 0"),
(@ENTRY,9,24,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,@POSITION_X_SPAWN_PEON14,@POSITION_Y_SPAWN_PEON14,@POSITION_Z_SPAWN_PEON14,@POSITION_O_SPAWN_PEON14,"Lazy Peon - On Script - Move To Position"),
(@ENTRY,9,25,0,0,0,100,0,5000,5000,0,0,11,17743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lazy Peon - On Script - Cast 'Peon Sleeping'");
*/
