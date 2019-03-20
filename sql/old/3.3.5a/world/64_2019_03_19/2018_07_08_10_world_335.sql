-- Dalinda Malem
DELETE FROM `creature_text` WHERE `CreatureID`=5644;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5644,0,0,"Elune be with us! Let's make haste from this evil fortress.",12,7,100,0,0,0,2143,0,"Dalinda Malem"),
(5644,1,0,"I will hurry back to Vahlarriel. Finish off those that you can--I should be fine on my own from here.",12,7,100,0,0,0,2144,0,"Dalinda Malem");

UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid`=26987;

UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=5644;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5644 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (564400,564401) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5644,0,0,0,11,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Respawn - Set Flag Standstate 'Kneel'"),
(5644,0,1,2,19,0,100,0,1440,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dalinda Malem - On Quest 'Return to Vahlarriel' Taken - Store Targetlist"),
(5644,0,2,3,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Quest 'Return to Vahlarriel' Taken - Remove Npc Flag Questgiver"),
(5644,0,3,4,61,0,100,0,0,0,0,0,0,80,564400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Quest 'Return to Vahlarriel' Taken - Run Script"),
(5644,0,4,5,61,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Quest 'Return to Vahlarriel' Taken - Set Faction 113"),
(5644,0,5,0,61,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Quest 'Return to Vahlarriel' Taken - Remove Unit Flag 'Immune to NPC'"),
(5644,0,6,0,6,0,100,0,0,0,0,0,0,6,1440,0,0,0,0,0,12,1,0,0,0,0,0,0,"Dalinda Malem - On Just Died - Fail Quest 'Return to Vahlarriel'"),
(5644,0,7,0,40,0,100,0,15,5644,0,0,0,80,564401,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Waypoint 15 Reached - Run Script"),
(5644,0,8,0,40,0,100,0,16,5644,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Waypoint 16 Reached - Despawn"),
(5644,0,9,0,11,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Respawn - Add Unit Flag 'Immune to NPC'"),
(564400,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Script - Say Line 0"),
(564400,9,1,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Script - Remove Flag Standstate 'Kneel'"),
(564400,9,2,0,0,0,100,0,5000,5000,0,0,0,53,0,5644,0,0,0,2,1,0,0,0,0,0,0,0,"Dalinda Malem - On Script - Start Waypoint"),
(564401,9,0,0,0,0,100,0,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Script - Pause Waypoint"),
(564401,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Script - Say Line 1"),
(564401,9,2,0,0,0,100,0,0,0,0,0,0,15,1440,0,0,0,0,0,12,1,0,0,0,0,0,0,"Dalinda Malem - On Script - Complete Quest 'Return to Vahlarriel'"),
(564401,9,3,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalinda Malem - On Script - Set Run On");

DELETE FROM `script_waypoint` WHERE `entry`=5644;
DELETE FROM `waypoints` WHERE `entry`=5644;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(5644,1,-339.679,1752.04,139.482,""),
(5644,2,-328.957,1734.95,139.327,""),
(5644,3,-350.747,1731.12,139.338,""),
(5644,4,-365.064,1739.04,139.376,""),
(5644,5,-371.105,1746.03,139.374,""),
(5644,6,-383.141,1738.62,138.93,""),
(5644,7,-390.445,1733.98,136.353,""),
(5644,8,-401.368,1726.77,131.071,""),
(5644,9,-416.016,1721.19,129.807,""),
(5644,10,-437.139,1709.82,126.342,""),
(5644,11,-459.862,1687.92,116.059,""),
(5644,12,-460.686,1679.55,111.976,""),
(5644,13,-461.485,1670.94,109.033,""),
(5644,14,-468.53,1645.51,102.811,""),
(5644,15,-474.529,1615.97,97.228,""),
(5644,16,-474.329,1590.01,94.4982,"");
