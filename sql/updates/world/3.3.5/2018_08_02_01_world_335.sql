-- Theldurin the Lost
DELETE FROM `creature_text` WHERE `CreatureID`=2785;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2785,0,0,"%s begins searching through his pack...",16,0,100,0,0,0,870,0,"Theldurin the Lost"),
(2785,1,0,"Ah!  There is my ratchet!  Now let's re-attach these scroll fragments.",12,0,100,0,0,0,871,0,"Theldurin the Lost"),
(2785,2,0,"There we are, $n.  The Scroll is fixed!  Hooray!",12,0,100,4,0,0,872,0,"Theldurin the Lost");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2785;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2785 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=278500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2785,0,0,0,20,0,100,0,692,0,0,0,80,278500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Quest 'The Lost Fragments' Finished - Run Script"),
(278500,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Remove Npc Flag Questgiver+Gossip"),
(278500,9,1,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Set Emote State 69"),
(278500,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 0"),
(278500,9,3,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Set Emote State 0"),
(278500,9,4,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 1"),
(278500,9,5,0,0,0,100,0,4000,4000,0,0,11,5017,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Cast 'Divining Trance'"),
(278500,9,6,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Say Line 2"),
(278500,9,7,0,0,0,100,0,3000,3000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theldurin the Lost - On Script - Add Npc Flag Questgiver+Gossip");
