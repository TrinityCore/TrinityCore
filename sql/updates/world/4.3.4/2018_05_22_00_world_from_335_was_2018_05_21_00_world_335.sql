/*
-- 
-- Quests "Investigate the Blue Recluse" & "Investigate the Alchemist Shop"
DELETE FROM `creature_text` WHERE `CreatureID` IN (5497,4568);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5497,0,0,"Here, $n.  Take a chest of containment coffers and a cantation of manifestation.  You will need them for your mission.",12,7,100,25,0,0,2681,0,"Jennea Cannon"),
(4568,0,0,"Take a chest of containment coffers and a cantation of manifestation, $n.  You will need them for your mission.",12,1,100,25,0,0,2682,0,"Anastasia Hartwell");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (5497,4568);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5497,4568) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (549700,456800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5497,0,0,0,19,0,100,0,1920,0,0,0,80,549700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jennea Cannon - On Quest 'Investigate the Blue Recluse' Taken - Run Script"),
(4568,0,0,0,19,0,100,0,1960,0,0,0,80,456800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anastasia Hartwell - On Quest 'Investigate the Alchemist Shop' Taken - Run Script"),
(549700,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.96646,"Jennea Cannon - On Script - Set Orientation"),
(549700,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jennea Cannon - On Script - Say Line 0"),
(549700,9,2,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.858,"Jennea Cannon - On Script - Set Orientation"),
(456800,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.77319,"Anastasia Hartwell - On Script - Set Orientation"),
(456800,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anastasia Hartwell - On Script - Say Line 0"),
(456800,9,2,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.05433,"Anastasia Hartwell - On Script - Set Orientation");
*/
