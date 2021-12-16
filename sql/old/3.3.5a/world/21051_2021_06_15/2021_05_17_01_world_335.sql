-- Credit for factions goes to vmangos, however with those factions their AI reaction is different from movies
-- https://www.youtube.com/watch?v=cbyKV88LfEg https://www.youtube.com/watch?v=KPrroLvNQ2c https://www.youtube.com/watch?v=GV64q-i420o
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 7956;

-- https://youtu.be/cbyKV88LfEg?t=235
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 7956;
-- Let's change their respawn time too
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 7997;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 7956 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 795600 AND 795603 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7956,0,0,0,63,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Just Created - Set Flag Standstate Kneel"),
(7956,0,1,0,4,0,100,0,0,0,0,0,0,1,3,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Aggro - Say Line 3"),

-- Start
(7956,0,2,0,19,0,100,0,2969,0,0,0,0,80,795600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Quest 'Freedom for All Creatures' Taken - Run Script"),

(795600,9,0,0,0,0,100,0,0,0,0,0,0,67,1,360000,360000,0,0,100,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Create Timed Event 1"),
(795600,9,1,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Store Targetlist"),
(795600,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Set Orientation Invoker"),
(795600,9,3,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Remove Flag Standstate Kneel"),
(795600,9,4,0,0,0,100,0,0,0,0,0,0,2,231,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Set Faction 231"),
(795600,9,5,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Remove Flag Immune To NPC's"),
(795600,9,6,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Remove NPC Flag Questgiver"),
(795600,9,7,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Say Line 0"),
(795600,9,8,0,0,0,100,0,5000,5000,0,0,0,29,4,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Start Follow Invoker"),

-- Success
-- All that stuff with counter should be done via map script, otherwise it will never work properly no matter if it's SAI or C++
(7956,0,3,0,77,0,100,0,1,6,0,0,0,80,795601,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Counter Set 1 6 - Run Script"),

(795601,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Say Line 1"),
(795601,9,1,0,0,0,100,0,0,0,0,0,0,15,2969,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Quest Credit 'Freedom for All Creatures'"),
(795601,9,2,0,0,0,100,0,0,0,0,0,0,41,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Delayed Despawn"),

-- Fail
-- There are 12 of them, let's make a guess that if more than half are killed, the quest fails
(7956,0,4,0,77,0,100,0,2,7,0,0,0,80,795602,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Counter Set 2 7 - Run Script"),

(795602,9,0,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Say Line 2"),
(795602,9,1,0,0,0,100,0,0,0,0,0,0,6,2969,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Fail Quest 'Freedom for All Creatures'"),
(795602,9,2,0,0,0,100,0,0,0,0,0,0,41,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Delayed Despawn"),

-- Time ran out
(7956,0,5,0,59,0,100,0,1,0,0,0,0,80,795603,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Timed Event - Run Script"),

(795603,9,0,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Say Line 4"),
(795603,9,1,0,0,0,100,0,0,0,0,0,0,41,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kindal Moonweaver - On Script - Delayed Despawn"),

-- Combat
(7956,0,6,0,0,0,100,0,0,0,2300,3900,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kindal Moonweaver - In Combat CMC - Cast 'Shoot'"),
(7956,0,7,0,0,0,100,0,5000,7000,8000,11000,0,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Kindal Moonweaver - In Combat - Cast 'Multi-Shot'"),

-- Death
(7956,0,8,0,6,0,100,0,0,0,0,0,0,6,2969,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kindal Moonweaver - On Death - Fail Quest 'Freedom for All Creatures'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 7997 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 799700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- That quest will be more funny when they will use unique waypoints
(7997,0,0,1,38,0,100,0,1,1,0,0,0,53,1,7997,0,0,0,2,1,0,0,0,0,0,0,0,0,"Captured Sprite Darter - On Data Set 1 1 - Start Waypoint"),
(7997,0,1,0,61,0,100,0,0,0,0,0,0,2,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Sprite Darter - On Data Set 1 1 - Set Faction 10"),
-- I have a feeling here they updates entry to Sprite Darter, starts random movement and despawns after some time
(7997,0,2,3,58,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,19,7956,200,0,0,0,0,0,0,"Captured Sprite Darter - On Waypoint Finished - Set Counter 1 1"),
(7997,0,3,0,61,0,100,0,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captured Sprite Darter - On Waypoint Finished - Delayed Despawn"),

(7997,0,4,0,6,0,100,0,0,0,0,0,0,63,2,1,0,0,0,0,19,7956,200,0,0,0,0,0,0,"Captured Sprite Darter - On Death - Set Counter 2 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 7956;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(7956,0,0,"I'm ready when you are, $n. Lead the way!",12,0,100,0,0,0,4079,0,"Kindal Moonweaver"),
(7956,1,0,"We've done it! Meet me back by Jer'kai above the Grim Totem camp.",12,0,100,0,0,0,4080,0,"Kindal Moonweaver"),
-- Surprisingly this text wasn't shown up in wowhead
(7956,2,0,"No! The faerie dragons aren't making it, $n! I must return to Jer'kai to make sure she hasn't been found. Elune be with you.",12,0,100,0,0,0,4081,0,"Kindal Moonweaver"),
(7956,3,0,"Quickly! $n attacks!",12,0,100,0,0,0,4122,0,"Kindal Moonweaver"),
(7956,3,1,"Die, $n. Elune will not have you harm her creatures any longer!",12,0,100,0,0,0,4123,0,"Kindal Moonweaver"),
(7956,3,2,"Death to you, $n. How dare you come within a bow's shot of me!",12,0,100,0,0,0,4124,0,"Kindal Moonweaver"),
(7956,3,3,"You dare touch me?!",12,0,100,0,0,0,4125,0,"Kindal Moonweaver"),
(7956,4,0,"Oh, no! We've run out of time. ",12,0,100,0,0,0,5285,0,"Kindal Moonweaver");
