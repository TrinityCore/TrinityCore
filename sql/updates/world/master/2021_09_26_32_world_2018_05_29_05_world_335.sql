-- Menara Voidrender
DELETE FROM `creature_text` WHERE `CreatureID`=6266;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6266,1,0,"Ok, let's get this orb made...",12,0,100,0,0,0,2663,0,"Menara Voidrender"),
(6266,2,0,"All right.  It's made!",12,0,100,1,0,0,2664,0,"Menara Voidrender");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6266;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6266 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=626600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6266,0,0,0,19,0,100,0,4975,0,0,0,80,626600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Menara Voidrender - On Quest 'The Completed Orb of Noh'Orahil' Taken - Run Script"),
(6266,0,1,0,19,0,100,0,4964,0,0,0,80,626600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Menara Voidrender - On Quest 'The Completed Orb of Dar'Orahil' Taken - Run Script"),
(626600,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Remove Npc Flag Questgiver+Gossip"),
(626600,9,1,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 1"),
(626600,9,2,0,0,0,100,0,0,0,0,0,11,9156,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Cast 'Create Mage's Orb'"),
(626600,9,3,0,0,0,100,0,5500,5500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 2"),
(626600,9,4,0,0,0,100,0,0,0,0,0,15,4975,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tabetha - On Script - Complete Quest 'The Completed Orb of Noh'Orahil'"),
(626600,9,5,0,0,0,100,0,0,0,0,0,15,4964,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tabetha - On Script - Complete Quest 'The Completed Orb of Dar'Orahil'"),
(626600,9,6,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Add Npc Flag Questgiver+Gossip");

UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=4964;
