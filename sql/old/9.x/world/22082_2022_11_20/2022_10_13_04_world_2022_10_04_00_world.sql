-- Add Missing gossip text
DELETE FROM `gossip_menu` WHERE `MenuID`=7346 AND `TextID`=8760;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (7346,8760);

-- Conditions for gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7346;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7346,8759,0,0,8,0,9067,0,0,1,0,0,'','Show gossip text 8759 if quest ''The Party Never Ends'' is not rewarded'),
(14,7346,8760,0,0,8,0,9067,0,0,0,0,0,'','Show gossip text 8760 if quest ''The Party Never Ends'' is rewarded');

-- Remove hack SAI from Fireworks Launchers
UPDATE `gameobject_template` SET `AIName`='' WHERE `entry`=180771;
DELETE FROM `smart_scripts` WHERE `entryorguid`=180771 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17056 AND `source_type`=0;
-- Correct facing 
UPDATE `creature` SET `orientation`=2.14675498 WHERE `guid`=59449;

-- Correct equipment
UPDATE `creature` SET `equipment_id`=0 WHERE `id`=17056;
-- Correct Addon
UPDATE `creature_addon` SET `bytes1`=0,`bytes2`=1,`emote`=0 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=17056);
UPDATE `creature_addon` SET `auras`='42386' WHERE `guid` IN (59434);
-- Move start location
UPDATE `creature` SET `position_x`=8679.53,`position_y`=-6342.703,`position_z`=55.914032,`orientation`=6.2308254 WHERE `guid`=59444;

-- Add Missing meat equipment
DELETE FROM `creature_equip_template` WHERE `CreatureID`=17056 AND `ID`=2;
INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`ItemID1`,`ItemID2`,`ItemID3`,`VerifiedBuild`) VALUES (17056,2,2202,0,0,0);

-- Pathing for Eversong Partygoer Entry: 17056
DELETE FROM `waypoint_data` WHERE `id` IN (594440,594441,594442,594443,594444);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(594440,1,8680.874,-6340.5757,55.93538,NULL,0,0,0,100,0),
(594440,2,8685.874,-6338.5757,55.94099,NULL,0,0,0,100,0),
(594440,3,8687.746,-6339.301,55.93539,NULL,0,0,0,100,0),
(594440,4,8687.746,-6339.301,55.93539,4.502949,1000,0,0,100,0),
(594441,1,8689.3545,-6332.7295,55.95669,NULL,0,0,0,100,0),
(594441,2,8691,-6332.577,55.95949,NULL,0,0,0,100,0),
(594441,3,8691,-6332.577,55.95949,5.148721,1000,0,0,100,0),
(594442,1,8681.171,-6329.512,55.948093,NULL,0,0,0,100,0),
(594442,2,8681.171,-6329.512,55.948093,2.303835,1000,0,0,100,0),
(594443,1,8675.356,-6334.1494,55.932705,NULL,0,0,0,100,0),
(594443,2,8675.356,-6334.1494,55.932705,3.124139,1000,0,0,100,0),
(594444,1,8678.709,-6342.523,55.915527,NULL,0,0,0,100,0),
(594444,2,8679.53,-6342.703,55.914032,NULL,0,0,0,100,0),
(594444,3,8679.53,-6342.703,55.914032,6.230825,1000,0,0,100,0);

UPDATE `creature` SET `ScriptName`='npc_partygoer_pather' WHERE `guid`=59444;
UPDATE `creature` SET `ScriptName`='npc_partygoer' WHERE `guid` IN (59435,59436,59437,59438,59439,59440,59441,59442,59443,59445,59446,59447,59448,59449);

-- Sempstress Ambershine SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16366 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16366,0,0,0,1,0,100,0,8000,15000,8000,15000,0,10,1,5,11,18,24,25,1,0,0,0,0,0,0,0,0,'Sempstress Ambershine - OOC - Random Emote');

-- Botanist Tyniarrel SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16367;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16367 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16367,0,0,0,1,0,100,0,8000,15000,8000,15000,0,10,1,5,11,18,24,25,1,0,0,0,0,0,0,0,0,'Botanist Tyniarrel - OOC - Random Emote');
