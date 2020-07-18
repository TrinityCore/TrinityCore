-- Thadius Grimshade
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8022;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8022 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=802200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8022,0,0,0,19,0,100,0,2992,0,0,0,80,802200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thadius Grimshade - On Quest 'The Divination' Taken - Run Script"),
(802200,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thadius Grimshade - On Script - Remove Npc Flag Questgiver"),
(802200,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thadius Grimshade - On Script - Say Line 0"),
(802200,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thadius Grimshade - On Script - Say Line 1"),
(802200,9,3,0,0,0,100,0,0,0,0,0,50,144069,10,0,0,0,0,8,0,0,0,-10999,-3484.47,103.122,2.52228,"Thadius Grimshade - On Script - Summon Gameobject Grimshade's Vision"),
(802200,9,4,0,0,0,100,0,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thadius Grimshade - On Script - Say Line 2"),
(802200,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thadius Grimshade - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=8022;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8022,0,0,"Make no sound during the ritual.  One misstep could spell our doom...",12,0,100,0,0,0,4126,0,"Thadius Grimshade"),
(8022,1,0,"Now, watch...",12,0,100,0,0,0,4127,0,"Thadius Grimshade"),
(8022,2,0,"There.  It is done.",12,0,100,0,0,0,4128,0,"Thadius Grimshade");
