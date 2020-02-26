-- Hammertoe Grez
UPDATE `creature` SET `spawntimesecs`=90 WHERE `guid`=7723;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2909;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2909 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=290900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2909,0,0,0,19,0,100,0,723,0,0,0,80,290900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammertoe Grez - On Quest 'Prospect of Faith' Taken - Run Script"),
(290900,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammertoe Grez - On Script - Say Line 0"),
(290900,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammertoe Grez - On Script - Say Line 1"),
(290900,9,2,0,0,0,100,0,0,0,0,0,11,4984,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammertoe Grez - On Script - Cast 'Hammertoe's Sacrifice'");

DELETE FROM `creature_text` WHERE `CreatureID`=2909;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2909,0,0,"Go with speed... <cough cough> Find... <cough> Ryedol...",12,7,100,0,0,0,957,0,"Hammertoe Grez"),
(2909,1,0,"%s falls to the ground. His spirit is released with his last breath.",16,0,100,0,0,0,979,0,"Hammertoe Grez");
