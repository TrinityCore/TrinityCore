-- Lizzarik
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3658;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3658 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3658,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lizzarik - Out of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=3658;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3658,0,0,"Best weapons in the Barrens here!",12,0,100,0,0,0,1212,0,"Lizzarik"),
(3658,0,1,"Step right up! Finest selection of weapons this side of Ashenvale!",12,0,100,0,0,0,1213,0,"Lizzarik"),
(3658,0,2,"Lizzarik has blades. Lizzarik has maces. Lizzarik has all your weapon needs right here!",12,0,100,0,0,0,1214,0,"Lizzarik"),
(3658,0,3,"Act quick! Once it's gone, it's gone! Get your weapons here now!",12,0,100,0,0,0,1215,0,"Lizzarik");
