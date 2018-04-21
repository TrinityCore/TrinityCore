/*
-- Yorus Barleybrew
DELETE FROM `creature_text` WHERE `CreatureID`=6166;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6166,0,0,"$n ran the Gauntlet!  Three cheers for $n!",12,7,100,22,0,0,2308,0,"Yorus Barleybrew"),
(6166,1,0,"Hip hip, hoorah!",12,7,100,4,0,0,2309,0,"Yorus Barleybrew");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6166;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6166 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=616600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6166,0,0,0,20,0,100,0,1699,0,0,0,80,616600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Quest 'The Rethban Gauntlet' Finished - Run Script"),
(616600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Script - Remove Npc Flag Questgiver"),
(616600,9,1,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Script - Say Line 0"),
(616600,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Script - Say Line 1"),
(616600,9,3,0,0,0,100,0,3500,3500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Script - Say Line 1"),
(616600,9,4,0,0,0,100,0,3500,3500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Script - Say Line 1"),
(616600,9,5,0,0,0,100,0,3000,3000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorus Barleybrew - On Script - Add Npc Flag Questgiver");
*/
