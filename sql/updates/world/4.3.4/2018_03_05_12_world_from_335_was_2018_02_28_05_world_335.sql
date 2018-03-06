/*
-- Quest "The Rescue"
-- Locked ball and chain
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (1721,1722);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1721,1722) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1721,1,0,0,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,2239,0,0,0,0,0,0,"Locked ball and chain - On Gameobject State Changed - Set Data to Drull"),
(1722,1,0,0,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,2238,0,0,0,0,0,0,"Locked ball and chain - On Gameobject State Changed - Set Data to Tog'thar");

-- Tog'thar / Drull
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (2238,2239);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2238,2239) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (223800,223900) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2238,0,0,0,38,0,100,0,1,1,0,0,80,223800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tog'thar - On Data Set - Run Script"),
(2239,0,0,0,38,0,100,0,1,1,0,0,80,223900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drull - On Data Set - Run Script"),
(223800,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tog'thar - On Script - Say Line 0"),
(223800,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tog'thar - On Script - Say Line 1"),
(223900,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drull - On Script - Say Line 0"),
(223900,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drull - On Script - Say Line 1");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (2238,2239);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2238,0,0,"Have you freed Drull yet? I don't know where he's being held.",12,1,100,6,0,0,593,0,"Tog'thar"),
(2238,1,0,"I will only slow you down, but no pink-skinned humans will keep me from freedom!",12,1,100,15,0,0,595,0,"Tog'thar"),
(2239,0,0,"Ah, it is good to be free of my bonds! Have you freed Tog'thar yet? The humans split us up after our capture.",12,1,100,4,0,0,592,0,"Drull"),
(2239,1,0,"Go on ahead without me! I will make my own way to Tarren Mill.",12,1,100,5,0,0,594,0,"Drull");
*/
