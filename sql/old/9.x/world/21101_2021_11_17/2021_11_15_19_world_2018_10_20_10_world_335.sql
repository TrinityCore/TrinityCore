-- Greishan Ironstove
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3291;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3291 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3291,0,0,0,1,0,100,0,10000,15000,40000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greishan Ironstove - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3291;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3291,0,0,"Fresh Bread! Get your oven fresh bread here!",12,6,100,0,0,0,995,0,"Greishan Ironstove"),
(3291,0,1,"Get'em while they are nice and fresh! Loaves of bread here!",12,6,100,0,0,0,996,0,"Greishan Ironstove"),
(3291,0,2,"All kinds of bread here! Made fresh today. Get'em while they last!",12,6,100,0,0,0,997,0,"Greishan Ironstove"),
(3291,0,3,"Bread here! Loaves of your favorites! Nice and fresh!",12,6,100,0,0,0,998,0,"Greishan Ironstove");
