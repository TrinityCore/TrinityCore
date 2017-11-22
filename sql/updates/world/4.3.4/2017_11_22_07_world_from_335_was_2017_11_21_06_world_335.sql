/*
-- 
-- Feegly the Exiled
DELETE FROM `creature_text` WHERE `CreatureID`=3421;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3421,0,0,"The power of the Tear of the Moons is mine! Mine I say!",12,0,100,5,0,0,1026,0,"Feegly the Exiled"),
(3421,1,0,"%s begins to rub the Tear of the Moons.",16,0,100,0,0,0,1027,0,"Feegly the Exiled"),
(3421,2,0,"Power! Glorious power!",12,0,100,0,0,0,1028,0,"Feegly the Exiled"),
(3421,3,0,"%s begins to make strange grunting noises. The Tear of the Moons drops to the ground and shatters.",16,0,100,0,0,0,1029,0,"Feegly the Exiled");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3421;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3421 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=342100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3421,0,0,0,20,0,100,0,857,0,0,0,80,342100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Quest 'The Tear of the Moons' Finished - Run Script"),
(342100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 0"),
(342100,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 1"),
(342100,9,2,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 2"),
(342100,9,3,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Say Line 3"),
(342100,9,4,0,0,0,100,0,2000,2000,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Play Emote 15"),
(342100,9,5,0,0,0,100,0,2000,2000,0,0,11,5142,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Cast Trogg Form"),
(342100,9,6,0,0,0,100,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Start Random Movement"),
(342100,9,7,0,0,0,100,0,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feegly the Exiled - On Script - Kill Self");

-- Pathing for Feegly the Exiled
UPDATE `creature` SET `position_x`=-4217.83, `position_y`=-2341.47, `position_z`=91.7458, `spawndist`=0, `MovementType`=2 WHERE `guid`=14138;

DELETE FROM `creature_addon` WHERE `guid`=14138;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(14138,141380,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=141380;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(141380,1,-4217.83,-2341.47,91.7458,2.02701,60000,0,0,100,0),
(141380,2,-4219.46,-2336.15,91.8028,2.02701,60000,0,0,100,0);
*/
