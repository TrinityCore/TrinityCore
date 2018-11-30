-- Daryn Lightwind
DELETE FROM `creature_text` WHERE `CreatureID`=7907;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7907,0,0,"Take a look around, $n. Perhaps you will find something that I have missed.",12,0,100,0,0,0,4042,0,"Daryn Lightwind"),
(7907,1,0,"%s gestures at the piles of books.",16,0,100,25,0,0,4043,0,"Daryn Lightwind");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7907;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7907 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=790700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7907,0,0,0,20,0,100,0,2939,0,0,0,80,790700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daryn Lightwind - On Quest 'In Search of Knowledge' Finished - Run Script"),
(790700,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.127147,"Daryn Lightwind - On Script - Set Orientation"),
(790700,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daryn Lightwind - On Script - Say Line 0"),
(790700,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daryn Lightwind - On Script - Say Line 1"),
(790700,9,3,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.82227,"Daryn Lightwind - On Script - Set Orientation");
