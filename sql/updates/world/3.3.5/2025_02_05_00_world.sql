
-- Intro for quest "The Binding" (1795)
-- Game objects are spawned by the script
DELETE FROM `gameobject` WHERE `guid` IN (29205,50355);
DELETE FROM `gameobject_addon` WHERE `guid` IN (29205,50355);

-- Strahad Farsan Text
DELETE FROM `creature_text` WHERE `CreatureID`=6251;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(6251,0,0,"I hope you're ready, $n. Follow me.",12,0,100,1,0,0,2370,0,"Strahad Farsan"),
(6251,1,0,"Come, my acolytes. Take the rods of channeling and create the greater summoning circle.",12,0,100,1,0,0,2374,0,"Strahad Farsan");

-- Script
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (6251,6252,6253,6254,6268);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN( 6251,6252,6253,6254,6268) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (625100,625101,625102,625103,625200,625300,625400,626800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

-- Strahad Farsan Script
(6251,0,0,0,19,0,100,0,1795,0,0,0,0,80,625100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Quest 'The Binding' Taken - Run Script"),
(6251,0,1,0,40,0,100,0,4,0,0,0,0,80,625101,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Waypoint 4 Reached - Run Script"),
(6251,0,2,0,40,0,100,0,6,0,0,0,0,80,625102,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Waypoint 7 Reached - Run Script"),
(6251,0,3,0,38,0,100,0,0,3,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Data Set 0 3 - Resume Waypoint"),
(6251,0,4,0,40,0,100,0,9,0,0,0,0,80,625103,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Waypoint 10 Reached - Run Script"),

-- Acolyte Magaz Script
(6252,0,0,0,38,0,100,0,0,1,0,0,0,80,625200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Magaz - On Data Set 0 1 - Run Script"),
(6252,0,1,0,38,0,100,0,0,2,0,0,0,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Magaz - On Data Set 0 2 - Play Emote"),

-- Acolyte Fenrick Script
(6253,0,0,0,38,0,100,0,0,1,0,0,0,80,625200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Fenrick - On Data Set 0 1 - Run Script"),
(6253,0,1,0,38,0,100,0,0,2,0,0,0,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Fenrick - On Data Set 0 2 - Play Emote"),

-- Acolyte Wytula Script
(6254,0,0,0,38,0,100,0,0,1,0,0,0,80,625200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Wytula - On Data Set 0 1 - Run Script"),
(6254,0,1,0,38,0,100,0,0,2,0,0,0,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Wytula - On Data Set 0 2 - Play Emote"),

-- Summoned Felhunter Script
(6268,0,0,0,0,0,100,0,5000,11000,11000,17000,0,11,2691,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Summoned Felhunter - In Combat - Cast 'Mana Burn'"),
(6268,0,1,0,54,0,100,0,0,0,0,0,0,80,626800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Summoned Felhunter - On Just Summoned - Run Script"),
(6268,0,2,0,6,0,100,0,2000,2000,0,0,0,45,0,3,0,0,0,0,19,6251,0,0,0,0,0,0,0,"Summoned Felhunter - On Death - Set Data 0 3 (Strahad Farsan)"),

-- Strahad Farsan Timed List 1
(625100,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Remove Npc Flag Questgiver+Gossip"),
(625100,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Say Line 0"),
(625100,9,2,0,0,0,100,0,2000,2000,0,0,0,53,0,6251,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Start Waypoint"),

-- Strahad Farsan Timed List 2
(625101,9,0,0,0,0,100,0,0,0,0,0,0,54,13000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Pause Waypoint"),
(625101,9,1,0,0,0,100,0,1000,1000,0,0,0,11,8677,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Cast 'Summon Effect'"),
(625101,9,2,0,0,0,100,0,6000,6000,0,0,0,50,92252,188,0,0,0,0,8,0,0,0,0,-768.80353,-3721.770,42.0,4.4998,"Strahad Farsan - On Script - Summon Gameobject 'Strahad's Summoning Circle'"),
(625101,9,3,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Say Line 1"),
(625101,9,4,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,6252,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Set Data 0 1 (Acolyte Magaz)"),
(625101,9,5,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,6253,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Set Data 0 1 (Acolyte Fenrick)"),
(625101,9,6,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,6254,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Set Data 0 1 (Acolyte Wytula)"),

-- Strahad Farsan Timed List 3
(625102,9,0,0,0,0,100,0,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Pause Waypoint"),
(625102,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Set Orientation Invoker"),

-- Strahad Farsan Timed List 4
(625103,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.05950,"Strahad Farsan - On Script - Set Orientation"),
(625103,9,1,0,0,0,100,0,1000,1000,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Strahad Farsan - On Script - Add Npc Flag Questgiver+Gossip"),

-- Acolyte Magaz Timed List 1
(625200,9,0,0,0,0,100,0,1000,1000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Magaz - On Data Set - Play Emote"),
(625200,9,1,0,0,0,100,0,5000,5000,0,0,0,11,8675,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Magaz - On Script - Cast 'Warlock Channeling'"),
(625200,9,2,0,0,0,100,0,7500,7500,0,0,0,50,92388,173,0,0,0,0,8,0,0,0,0,-768.80353,-3721.770,44.10,2.5952,"Acolyte Magaz - On Script - Summon Gameobject 'Summoning Circle'"),

-- Acolyte Fenrick Timed List 1
(625300,9,0,0,0,0,100,0,1000,1000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Fenrick - On Data Set - Play Emote"),
(625300,9,1,0,0,0,100,0,5000,5000,0,0,0,11,8675,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Fenrick - On Script - Cast 'Warlock Channeling'"),

-- Acolyte Wytula Timed List 1
(625400,9,0,0,0,0,100,0,1000,1000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Wytula - On Data Set - Play Emote"),
(625400,9,1,0,0,0,100,0,5000,5000,0,0,0,11,8675,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acolyte Wytula - On Script - Cast 'Warlock Channeling'"),

-- Summoned Felhunter Timed List 1
(626800,9,0,0,0,0,100,0,0,0,0,0,0,11,52096,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Summoned Felhunter - On Script - Cast 'Teleport Visual Only'"),
(626800,9,1,0,0,0,100,0,1000,1000,0,0,0,45,0,2,0,0,0,0,19,6252,0,0,0,0,0,0,0,"Summoned Felhunter - On Script - Set Data 0 2 (Acolyte Magaz)"),
(626800,9,2,0,0,0,100,0,0,0,0,0,0,45,0,2,0,0,0,0,19,6253,0,0,0,0,0,0,0,"Summoned Felhunter - On Script - Set Data 0 2 (Acolyte Fenrick)"),
(626800,9,3,0,0,0,100,0,0,0,0,0,0,45,0,2,0,0,0,0,19,6254,0,0,0,0,0,0,0,"Summoned Felhunter - On Script - Set Data 0 2 (Acolyte Wytula)"),
(626800,9,4,0,0,0,100,0,0,0,0,0,0,41,2000,0,0,0,0,0,13,92252,0,100,0,0,0,0,0,"Summoned Felhunter - On Script - Despawn Gameobject 'Strahad's Summoning Circle'"),
(626800,9,5,0,0,0,100,0,0,0,0,0,0,41,2000,0,0,0,0,0,13,92388,0,100,0,0,0,0,0,"Summoned Felhunter - On Script - Despawn Gameobject 'Summoning Circle'"),
(626800,9,6,0,0,0,100,0,500,500,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,0,"Summoned Felhunter - On Script - Start Attacking Closest Player");

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=6251;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES

-- Condition to prevent script from running when there already is a Felhunter spawned
(22,1,6251,0,0,29,0,6268,100,0,1,0,0,"","Smart Event 0 for creature Strahad Farsan only executes if creature 'Summoned Felhunter' not near");

-- Strahad Farsan Waypoints
DELETE FROM `waypoints` WHERE `entry`=6251;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(6251,1,-786.65186,-3722.0166,40.380207,"Strahad Farsan"),
(6251,2,-784.910,-3717.9514,41.09593,"Strahad Farsan"),
(6251,3,-778.20404,-3718.2446,42.591854,"Strahad Farsan"),
(6251,4,-769.45544,-3721.2717,42.424034,"Strahad Farsan"), -- Summon
(6251,5,-767.81177,-3721.42969,42.37064,"Strahad Farsan"),
(6251,6,-762.8201,-3720.283,42.24128,"Strahad Farsan"),  -- Waiting
(6251,7,-768.04926,-3720.5073,42.379726,"Strahad Farsan"),
(6251,8,-781.8862,-3716.743,41.55511,"Strahad Farsan"),
(6251,9,-785.9119,-3723.260,40.515202,"Strahad Farsan"); -- Home
