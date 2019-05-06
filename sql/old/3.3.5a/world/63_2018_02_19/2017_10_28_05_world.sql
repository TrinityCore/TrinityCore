-- Supervisor Raelen
DELETE FROM `creature_text` WHERE `CreatureID`=10616;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10616,0,0,"We have yet to meet our quota for the wood demand.  Now back to work with you.",12,7,100,25,0,0,6890,0,"Supervisor Raelen"),
(10616,0,1,"Daylight is still upon us so let's see that axe of yours chopping some more wood.",12,7,100,1,0,0,6891,0,"Supervisor Raelen"),
(10616,0,2,"We need to get this wagon filled by the end of the day.  So back to work with you.  Chop, chop!",12,7,100,5,0,0,6892,0,"Supervisor Raelen");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10616;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10616 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1061600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10616,0,0,0,75,0,100,0,0,11328,1,20000,80,1061600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Supervisor Raelen - On 'Eastvale Peasant' in Range - Run Script"),
(1061600,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Supervisor Raelen - On Script - Say Line 0");
