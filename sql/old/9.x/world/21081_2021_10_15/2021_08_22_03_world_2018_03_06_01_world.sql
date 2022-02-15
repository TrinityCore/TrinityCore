-- 
-- Gnomeregan Evacuee
DELETE FROM `smart_scripts` WHERE `entryorguid`=7843 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7843,0,6,0,6,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnomeregan Evacuee - On Just Died - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=7843;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7843,0,0,"Aaaaahhh! So close to escaping.",12,7,100,0,0,0,3829,0,"Gnomeregan Evacuee");

-- Addled Leper
DELETE FROM `smart_scripts` WHERE `entryorguid`=6221 AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6221,0,6,0,4,0,40,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Addled Leper - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=6221;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6221,0,0,"No gnome will be left behind.",12,7,100,0,0,0,2422,0,"Addled Leper"),
(6221,0,1,"The troggs...they never stop coming.  Die trogg!  Die!",12,7,100,0,0,0,2423,0,"Addled Leper"),
(6221,0,2,"This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!",12,7,100,0,0,0,2424,0,"Addled Leper"),
(6221,0,3,"A foul trogg if ever I saw one.  Die!",12,7,100,0,0,0,2425,0,"Addled Leper");

-- Leprous Technician
DELETE FROM `smart_scripts` WHERE `entryorguid`=6222 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6222,0,5,0,4,0,20,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Technician - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=6222 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6222,1,0,"No gnome will be left behind.",12,7,100,0,0,0,2422,0,"Leprous Technician"),
(6222,1,1,"The troggs...they never stop coming.  Die trogg!  Die!",12,7,100,0,0,0,2423,0,"Leprous Technician"),
(6222,1,2,"This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!",12,7,100,0,0,0,2424,0,"Leprous Technician"),
(6222,1,3,"A foul trogg if ever I saw one.  Die!",12,7,100,0,0,0,2425,0,"Leprous Technician");

-- Leprous Defender
DELETE FROM `smart_scripts` WHERE `entryorguid`=6223 AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6223,0,5,0,4,0,20,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Defender - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=6223 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6223,1,0,"No gnome will be left behind.",12,7,100,0,0,0,2422,0,"Leprous Defender"),
(6223,1,1,"The troggs...they never stop coming.  Die trogg!  Die!",12,7,100,0,0,0,2423,0,"Leprous Defender"),
(6223,1,2,"This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!",12,7,100,0,0,0,2424,0,"Leprous Defender"),
(6223,1,3,"A foul trogg if ever I saw one.  Die!",12,7,100,0,0,0,2425,0,"Leprous Defender");

-- Leprous Assistant
DELETE FROM `smart_scripts` WHERE `entryorguid`=7603 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7603,0,2,0,4,0,20,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Assistant - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=7603 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7603,1,0,"No gnome will be left behind.",12,7,100,0,0,0,2422,0,"Leprous Assistant"),
(7603,1,1,"The troggs...they never stop coming.  Die trogg!  Die!",12,7,100,0,0,0,2423,0,"Leprous Assistant"),
(7603,1,2,"This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!",12,7,100,0,0,0,2424,0,"Leprous Assistant"),
(7603,1,3,"A foul trogg if ever I saw one.  Die!",12,7,100,0,0,0,2425,0,"Leprous Assistant");

-- Leprous Machinesmith
DELETE FROM `smart_scripts` WHERE `entryorguid`=6224 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6224,0,4,0,4,0,20,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Machinesmith - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=6224 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6224,1,0,"No gnome will be left behind.",12,7,100,0,0,0,2422,0,"Leprous Machinesmith"),
(6224,1,1,"The troggs...they never stop coming.  Die trogg!  Die!",12,7,100,0,0,0,2423,0,"Leprous Machinesmith"),
(6224,1,2,"This sickness clouds my vision, but I know you must be a trogg.  Die foul invader!",12,7,100,0,0,0,2424,0,"Leprous Machinesmith"),
(6224,1,3,"A foul trogg if ever I saw one.  Die!",12,7,100,0,0,0,2425,0,"Leprous Machinesmith");

-- Dark Iron Agent
DELETE FROM `smart_scripts` WHERE `entryorguid`=6212 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6212,0,1,0,4,0,20,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Agent - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=6212 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6212,1,0,"Never cross a Dark Iron, $C.",12,0,100,0,0,0,1934,0,"Dark Iron Agent"),
(6212,1,1,"Time to die, $C.",12,0,100,0,0,0,1935,0,"Dark Iron Agent"),
(6212,1,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,1936,0,"Dark Iron Agent");
