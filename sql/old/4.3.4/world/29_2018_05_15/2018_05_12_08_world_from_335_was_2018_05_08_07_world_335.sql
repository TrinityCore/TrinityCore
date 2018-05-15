/*
-- 
-- World Invisible Trigger
SET @GUID := 64987;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,12999,1,0,0,1,1,0,0,5416.44,-742.98,346.204,1.75579,300,0,0,7212,0,0,0,0,0,"",0);

-- Niby the Almighty
DELETE FROM `smart_scripts` WHERE `entryorguid`=14469 AND `source_type`=0 AND `id` IN (1,2,3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1446900,1446901,1446902,1446903) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14469,0,1,0,40,0,100,0,1,14469,0,0,0,80,1446901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Waypoint 1 Reached - Run Script"),
(14469,0,2,0,40,0,100,0,2,14469,0,0,0,80,1446902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Waypoint 2 Reached - Run Script"),
(14469,0,3,0,1,1,100,0,1000,15000,150000,180000,0,80,1446903,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - Out of Combat - Run Script"),
(14469,0,4,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Respawn - Set Event Phase 1"),
(14469,0,5,0,38,0,100,0,1,1,0,0,0,69,0,0,0,0,0,0,8,0,0,0,5413.9,-737.721,344.624,0,"Niby the Almighty - On Data Set - Move to Position"),
(1446900,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Set Event Phase 0"),
(1446900,9,1,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Remove Npc Flag Questgiver+Gossip"),
(1446900,9,2,0,0,0,100,0,0,0,0,0,0,53,0,14469,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Start Waypoint"),
(1446901,9,0,0,0,0,100,0,0,0,0,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Pause Waypoint"),
(1446901,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.2,"Niby the Almighty - On Script - Set Orientation"),
(1446901,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 0"),
(1446901,9,3,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 1"),
(1446901,9,4,0,0,0,100,0,0,0,0,0,0,11,23056,0,0,0,0,0,19,12999,0,0,0,0,0,0,"Niby the Almighty - On Script - Cast 'Call Infernal Destroyer'"),
(1446901,9,5,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,19,14470,100,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 0"),
(1446901,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,19,14470,100,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 1"),
(1446901,9,7,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 2"),
(1446902,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.653,"Niby the Almighty - On Script - Set Orientation"),
(1446902,9,1,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Add Npc Flag Questgiver+Gossip"),
(1446902,9,2,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Set Event Phase 1"),
(1446903,9,0,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 3"),
(1446903,9,1,0,0,0,100,0,5000,5000,0,0,0,11,23053,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Cast 'Infernal Conjure Dummy DND'"),
(1446903,9,2,0,0,0,100,0,3000,3000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 4"),
(1446903,9,3,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,19,14470,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 2 (Impsy)"),
(1446903,9,4,0,0,0,100,0,5000,5000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 5"),
(1446903,9,5,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,14470,0,0,0,0,0,0,"Niby the Almighty - On Script - Set Data to Impsy"),
(1446903,9,6,0,0,0,100,0,0,0,0,0,0,29,1,180,0,0,0,0,19,14470,0,0,0,0,0,0,"Niby the Almighty - On Script - Start Follow"),
(1446903,9,7,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,19,14470,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 3 (Impsy)");

-- Impsy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14470;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14470 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14470,0,0,0,38,0,100,0,1,1,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impsy - On Data Set - Stop Random Movement"),
(14470,0,1,0,38,0,100,0,1,1,0,0,0,53,1,14470,0,0,0,0,1,0,0,0,0,0,0,0,"Impsy - On Data Set - Start Waypoint"),
(14470,0,2,0,40,0,100,0,11,14470,0,0,0,45,1,1,0,0,0,0,19,14469,0,0,0,0,0,0,"Impsy - On Waypoint 11 Reached - Set Data to Niby the Almighty"),
(14470,0,3,0,40,0,100,0,11,14470,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impsy - On Waypoint 11 Reached - Start Random Movement"),
(14470,0,4,0,11,0,100,0,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impsy - On Respawn - Start Random Movement");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=14469 AND `GroupID` IN (3,4,5);
DELETE FROM `creature_text` WHERE `CreatureID`=14470 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14469,3,0,"This is it, Impsy. I can feel it! This is the big one!",12,0,100,5,0,0,9615,0,"Niby the Almighty"),
(14469,3,1,"Brace yourself for the glorious impact, Impsy!",12,0,100,5,0,0,9616,0,"Niby the Almighty"),
(14469,3,2,"Kick me out, will they!? I'll show those uptight cone heads in Stormwind the true power of Niby! BEHOLD!",12,0,100,15,0,0,9617,0,"Niby the Almighty"),
(14469,4,0,"%s shakes his fist in frustration.",16,0,100,0,0,0,9618,0,"Niby the Almighty"),
(14469,5,0,"Why you little!",12,0,100,0,0,0,9622,0,"Niby the Almighty"),
(14470,2,0,"Niby, you are stupid.",12,0,100,0,0,0,9619,0,"Impsy"),
(14470,2,1,"Oh my, what a surprise! Another failure!? But how, oh great one??",12,0,100,0,0,0,9620,0,"Impsy"),
(14470,2,2,"Awe inspiring, master. Your ineptitude is awe inspiring.",12,0,100,0,0,0,9621,0,"Impsy"),
(14470,3,0,"Ack! Help! Crazed gnome trying to kill me!",12,0,100,0,0,0,9623,0,"Impsy");

-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (14469,14470);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(14469,1,5407.19,-753,350.82),
(14469,2,5413.9,-737.721,344.624),
(14470,1,5399.15,-735.454,343.567),
(14470,2,5386.63,-729.446,343.992),
(14470,3,5384.08,-722.534,345.173),
(14470,4,5396.26,-713.693,346.403),
(14470,5,5415.7,-722.556,344.598),
(14470,6,5434.85,-723.435,342.78),
(14470,7,5444.68,-732.313,342.527),
(14470,8,5440.93,-743.161,343.643),
(14470,9,5427.72,-750.631,347.609),
(14470,10,5416.55,-749.533,348.499),
(14470,11,5407.59,-736.618,344.249);
*/
