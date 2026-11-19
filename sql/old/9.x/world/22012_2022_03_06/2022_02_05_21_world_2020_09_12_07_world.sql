-- Isla Starmane SAI (https://www.youtube.com/watch?v=_kpk1XmPZkA & https://www.youtube.com/watch?v=MdmpUARYJvg)
SET @ID := 18760;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+3 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Probably impossible to confirm if it happens in retail since GO resets in 90 secs and quite possible
-- it's not enough for creature to respawn even if she will be killed after escort start
-- (@ID,0,0,0,11,0,100,0,0,0,0,0,0,32,0,0,0,0,0,0,20,182794,5,0,0,0,0,0,0,"Isla Starmane - On Respawn - Reset Closest Gameobject 'Cage'"),
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Respawn - Set Event Phase 1"),
(@ID,0,1,0,1,1,100,0,30000,30000,60000,180000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - Out Of Combat - Say Line 0 (Phase 1)"),
-- Seems like she can reset timers after evade https://www.youtube.com/watch?v=MdmpUARYJvg
(@ID,0,2,0,0,0,100,0,7000,10000,10000,15000,0,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Isla Starmane - In Combat - Cast 'Wrath'"),
(@ID,0,3,0,0,0,100,0,8000,12000,10000,15000,0,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Isla Starmane - In Combat - Cast 'Moonfire'"),
(@ID,0,4,0,0,0,100,0,0,2000,13000,18000,0,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Isla Starmane - In Combat - Cast 'Entangling Roots'"),
-- No Repeat is experimental. For some reason gossip flag removal is delayed sometimes or always, let's try to simulate it for the first time
(@ID,0,5,0,19,0,100,1,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Quest Taken - Run Script (No Repeat)"),
(@ID,0,6,0,40,0,100,0,1,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Waypoint 1 Reached - Run Script"),
(@ID,0,7,0,40,0,100,0,4,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Waypoint 4 Reached - Run Script"),
(@ID,0,8,0,40,0,100,0,27,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Waypoint 27 Reached - Run Script"),
(@ID,0,9,0,40,0,100,0,30,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Waypoint 30 Reached - Despawn Instant"),
(@ID,0,10,0,6,0,100,0,0,0,0,0,0,6,10051,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Death - Fail Quest 'Escape from Firewing Point!'"),
(@ID,0,11,0,6,0,100,0,0,0,0,0,0,6,10052,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Death - Fail Quest 'Escape from Firewing Point!'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,2000,2000,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Remove NPC Flags Gossip & Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,1000,1000,0,0,0,9,0,0,0,0,0,0,20,182794,5,0,0,0,0,0,0,"Isla Starmane - On Script - Activate Closest Gameobject 'Cage'"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,53,0,18760,0,0,0,2,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Start Waypoint"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Set Faction 113"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Say Line 1"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Say Line 2"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.20155,"Isla Starmane - On Script - Set Orientation"),
(@ID*100+2,9,3,0,0,0,100,0,16000,16000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Say Line 3"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,2000,2000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Say Line 4"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Set Orientation Stored Target 1"),
(@ID*100+3,9,3,0,0,0,100,0,8000,8000,0,0,0,15,10051,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Quest Credit 'Escape from Firewing Point!'"),
(@ID*100+3,9,4,0,0,0,100,0,0,0,0,0,0,15,10052,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Isla Starmane - On Script - Quest Credit 'Escape from Firewing Point!'"),
(@ID*100+3,9,5,0,0,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Set Active"),
(@ID*100+3,9,6,0,0,0,100,0,1000,1000,0,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Play Emote 3"),
(@ID*100+3,9,7,0,0,0,100,0,4000,4000,0,0,0,11,32447,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Cast 'Travel Form'"),
(@ID*100+3,9,8,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Isla Starmane - On Script - Set Run On");

-- http://web.archive.org/web/20120420070331/www.wowhead.com/npc=18760
DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Hello?  Help?",12,0,100,0,0,0,15878,0,"Isla Starmane"),
(@ID,0,1,"<cough> <cough> Damsel in distress over here!",12,0,100,0,0,0,15879,0,"Isla Starmane"),
(@ID,0,2,"When you get a chance do you think you could let me out of here?",12,0,100,0,0,0,15880,0,"Isla Starmane"),
(@ID,0,3,"Don't leave me in here!  Cause if you do, I will find you...",12,0,100,0,0,0,15881,0,"Isla Starmane"),
(@ID,1,0,"Ok, let's get out of here!",12,0,100,0,0,0,15882,0,"Isla Starmane"),
(@ID,2,0,"You sure you're ready?  Take a moment.",12,0,100,0,0,0,15883,0,"Isla Starmane"),
(@ID,3,0,"Alright, let's do this!",12,0,100,0,0,0,15884,0,"Isla Starmane"),
-- 15885 15886 probably related but not used
(@ID,4,0,"Ok, I think I can make it on my own from here.  Thank you so much for breaking me out of there!",12,0,100,0,0,0,15887,0,"Isla Starmane");

DELETE FROM `script_waypoint` WHERE `entry` = 18760;
DELETE FROM `waypoints` WHERE `entry` = 18760;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(18760,1,-2268.2,3091.14,13.82,"Isla Starmane"),
(18760,2,-2278.32,3098.98,13.82,"Isla Starmane"),
(18760,3,-2294.82,3110.59,13.82,"Isla Starmane"),
(18760,4,-2300.71,3114.6,13.82,"Isla Starmane"), --
(18760,5,-2307.36,3122.76,13.79,"Isla Starmane"),
(18760,6,-2312.83,3130.55,12.04,"Isla Starmane"),
(18760,7,-2345.02,3151,8.38,"Isla Starmane"),
(18760,8,-2351.97,3157.61,6.27,"Isla Starmane"),
(18760,9,-2360.35,3171.48,3.31,"Isla Starmane"),
(18760,10,-2371.44,3185.41,0.89,"Isla Starmane"),
(18760,11,-2371.21,3197.92,-0.96,"Isla Starmane"),
(18760,12,-2380.35,3210.45,-1.08,"Isla Starmane"),
(18760,13,-2384.74,3221.25,-1.17,"Isla Starmane"),
(18760,14,-2386.15,3233.39,-1.29,"Isla Starmane"),
(18760,15,-2383.45,3247.79,-1.32,"Isla Starmane"),
(18760,16,-2367.5,3265.64,-1.33,"Isla Starmane"),
(18760,17,-2354.9,3273.3,-1.5,"Isla Starmane"),
(18760,18,-2348.88,3280.58,-0.09,"Isla Starmane"),
(18760,19,-2349.06,3295.86,-0.95,"Isla Starmane"),
(18760,20,-2350.43,3328.27,-2.1,"Isla Starmane"),
(18760,21,-2346.76,3356.27,-2.82,"Isla Starmane"),
(18760,22,-2340.56,3370.68,-4.02,"Isla Starmane"),
(18760,23,-2318.84,3384.6,-7.61,"Isla Starmane"),
(18760,24,-2313.99,3398.61,-10.4,"Isla Starmane"),
(18760,25,-2320.85,3414.49,-11.49,"Isla Starmane"),
(18760,26,-2338.26,3426.06,-11.46,"Isla Starmane"),
(18760,27,-2342.67,3439.44,-11.32,"Isla Starmane"), --
(18760,28,-2344.6,3461.27,-10.44,"Isla Starmane"),
(18760,29,-2396.81,3517.17,-3.55,"Isla Starmane"),
(18760,30,-2439.23,3523,-1.05,"Isla Starmane");
