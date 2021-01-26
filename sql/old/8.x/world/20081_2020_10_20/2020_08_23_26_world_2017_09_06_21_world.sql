-- Privateer Groy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2616;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2616 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2616,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Privateer Groy - Out of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=2616;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2616,0,0,"Where in the Outlands are those shipments? For days they keep me waiting!",12,7,100,0,0,0,737,0,"Privateer Groy"),
(2616,0,1,"Stupidity! I'm surrounded by stupidity!",12,7,100,0,0,0,738,0,"Privateer Groy"),
(2616,0,2,"Orcs are smarter than those couriers! Where the blazes are they?",12,7,100,0,0,0,739,0,"Privateer Groy");
