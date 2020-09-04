-- Lurgglbr SAI (Source: Sniffs & https://www.youtube.com/watch?v=Z6jT1TzxTZU)
SET @ID := 25208;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Respawn - Set Event Phase 1"),
(@ID,0,1,0,1,1,100,0,30000,30000,60000,180000,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - Out Of Combat - Say Line 4 (Phase 1)"),
(@ID,0,2,0,19,0,100,0,11570,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Quest 'Escape from the Winterfin Caverns' Taken - Run Script"),
(@ID,0,3,0,40,0,100,0,1,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Waypoint 1 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,17,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Waypoint 17 Reached - Run Script"),
(@ID,0,5,0,6,0,100,0,0,0,0,0,0,6,11570,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Death - Fail Quest 'Escape from the Winterfin Caverns'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Remove NPC Flags Gossip & Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,4000,4000,0,0,0,9,0,0,0,0,0,0,20,187369,0,0,0,0,0,0,0,"Lurgglbr - On Script - Activate Closest Gameobject (Cage)"),
(@ID*100+0,9,4,0,0,0,100,0,1000,1000,0,0,0,53,0,25208,0,0,0,2,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Start Waypoint"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Set Faction 113"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Remove Flags Immune To Players & Immune To NPC's"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Say Line 0"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Set Orientation Stored Target 1"),
(@ID*100+1,9,3,0,0,0,100,0,10000,10000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Say Line 1"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Add Flag Immune To NPC's"),
(@ID*100+2,9,1,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Say Line 2"),
(@ID*100+2,9,2,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Say Line 3"),
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Set Orientation Stored Target 1"),
(@ID*100+2,9,4,0,0,0,100,0,6000,6000,0,0,0,15,11570,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lurgglbr - On Script - Quest Credit 'Escape from the Winterfin Caverns'"),
(@ID*100+2,9,5,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lurgglbr - On Script - Despawn (0)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Together we will fight our way out of here. Are you ready?",12,0,100,36,0,0,24310,0,"Lurgglbr"),
(@ID,1,0,"Then we leave!",12,0,100,36,0,0,24311,0,"Lurgglbr"),
(@ID,2,0,"This is far enough. I can make it on my own from here.",12,0,100,36,0,0,24312,0,"Lurgglbr"),
(@ID,3,0,"Thank you for rescuing me, $r. Please tell the king that I am back.",12,0,100,36,0,0,24313,0,"Lurgglbr"),
(@ID,4,0,"Hey you, stranger, come here!",12,0,100,36,0,0,24314,0,"Lurgglbr"),
(@ID,4,1,"If only there were someone nearby who would help me escape.",12,0,100,36,0,0,24315,0,"Lurgglbr"),
(@ID,4,2,"You can't hold me against my will! You've all been brainwashed!",12,0,100,36,0,0,24316,0,"Lurgglbr"),
(@ID,4,3,"Living in these caverns and following that mad lobstrok, Clacker, is unnatural! Let me free!",12,0,100,36,0,0,24317,0,"Lurgglbr");

DELETE FROM `script_waypoint` WHERE `entry` = 25208;
DELETE FROM `waypoints` WHERE `entry` = 25208;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(25208,1,4013.553,6392.097,29.883759,"Lurgglbr"),
(25208,2,4021.1646,6382.944,29.914948,"Lurgglbr"),
(25208,3,4029.606,6372.764,28.714071,"Lurgglbr"),
(25208,4,4053.6875,6366.4673,27.468378,"Lurgglbr"),
(25208,5,4062.2065,6349.471,24.713737,"Lurgglbr"),
(25208,6,4062.8135,6313.4907,25.096079,"Lurgglbr"),
(25208,7,4060.3906,6292.0596,23.855808,"Lurgglbr"),
(25208,8,4079.802,6279.1484,26.83883,"Lurgglbr"),
(25208,9,4127.1934,6281.104,27.951939,"Lurgglbr"),
(25208,10,4162.055,6282.9756,29.702269,"Lurgglbr"),
(25208,11,4179.928,6293.3916,18.743465,"Lurgglbr"),
(25208,12,4203.623,6297.2354,12.024111,"Lurgglbr"),
(25208,13,4218.571,6272.069,8.108217,"Lurgglbr"),
(25208,14,4250.022,6266.3438,0.671937,"Lurgglbr"),
(25208,15,4260.9297,6239.2466,-0.078062996,"Lurgglbr"),
(25208,16,4248.6284,6213.0166,-0.111559555,"Lurgglbr"),
(25208,17,4270.384,6186.938,0.105358124,"Lurgglbr");

-- Mootoo the Younger SAI (Source: Sniffs & https://www.youtube.com/watch?v=D5xCQWeAaVQ & https://www.youtube.com/watch?v=fwHUuUJ7bwE)
SET @ID := 25504;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 25504);
UPDATE `creature_template` SET `unit_flags` = 33536, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25503;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25503 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+4 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Respawn - Set Flag Standstate Sit Down"),
(@ID,0,1,0,19,0,100,0,11664,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Quest 'Escaping the Mist' Taken - Run Script"),
(@ID,0,2,0,40,0,100,0,15,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Waypoint 15 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,26,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Waypoint 26 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,31,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Waypoint 31 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,32,0,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Waypoint 32 Reached - Run Script"),
(@ID,0,6,0,1,1,100,256,20000,25000,20000,25000,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - Out Of Combat - Say Line 5 (Phase 1) (No Reset)"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,6,11664,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Death - Fail Quest 'Escaping the Mist'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Orientation Stored Target 1"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Event Phase 1"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,53,0,25504,0,0,0,2,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Start Waypoint"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Pause Waypoint"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,2,1986,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Faction 1986"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Remove Flag Standstate Sit Down"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Remove NPC Flags Gossip & Questgiver"),
(@ID*100+0,9,9,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Remove Flags Immune To Players & Immune To NPC's"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,4000,4000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Play Emote 25"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Say Line 2"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Run On"),
(@ID*100+3,9,2,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Say Line 3"),
(@ID*100+3,9,3,0,0,0,100,0,0,0,0,0,0,15,11664,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Quest Credit 'Escaping the Mist'"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Say Line 4"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Phasemask 1"),
(@ID*100+4,9,2,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Event Phase 0"),
(@ID*100+4,9,3,0,0,0,100,0,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Despawn (15000)"),
(@ID*100+4,9,4,0,0,0,100,0,4000,4000,0,0,0,100,1,0,0,0,0,0,19,25503,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Send Target 1 (Elder Mootoo)"),
(@ID*100+4,9,5,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,25503,0,0,0,0,0,0,0,"Mootoo the Younger - On Script - Set Data 0 1 (Elder Mootoo)"),

(25503,0,0,0,38,0,100,0,0,1,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Elder Mootoo - On Data Set 0 1 - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (@ID,25503);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Thank you for doing this, $r. I... I think I know how to get back to my father. Please don't let the bad things hurt me.",12,1,100,1,0,0,24746,0,"Mootoo the Younger"),
(@ID,1,0,"I can feel my father's aura. He's definitely this way... come on, $n.",12,1,100,1,0,0,24747,0,"Mootoo the Younger"),
(@ID,2,0,"I see a break in the mist up ahead. We're getting closer!",12,1,100,5,0,0,24748,0,"Mootoo the Younger"),
(@ID,3,0,"FATHER! Father, I'm saved!",12,1,100,0,0,0,24749,0,"Mootoo the Younger"),
(@ID,4,0,"%s hugs Elder Mootoo.",16,1,100,0,0,0,24750,0,"Mootoo the Younger"),
(@ID,5,0,"The mist is death... senseless, without compassion.",12,1,100,1,0,0,24757,0,"Mootoo the Younger"),
(@ID,5,1,"So cold...",12,1,100,1,0,0,24964,0,"Mootoo the Younger"),
(@ID,5,2,"Everyone is dead... Everyone and everything...",12,1,100,1,0,0,24965,0,"Mootoo the Younger"),
(@ID,5,3,"How will we overcome the mist?",12,1,100,1,0,0,27243,0,"Mootoo the Younger"),
(@ID,5,4,"I thought for sure that I would die like all the others!",12,1,100,1,0,0,27244,0,"Mootoo the Younger"),
(@ID,5,5,"What was that! Did you see that?",12,1,100,1,0,0,27245,0,"Mootoo the Younger"),
(@ID,5,6,"Have you heard of the taunka? They are supposedly related to tauren in some way. Can you imagine such a thing?",12,1,100,1,0,0,27246,0,"Mootoo the Younger"),
(25503,0,0,"Mootoo thanks you, $n.",12,1,100,1,0,0,24753,0,"Elder Mootoo");

DELETE FROM `script_waypoint` WHERE `entry` = 25504;
DELETE FROM `waypoints` WHERE `entry` = 25504;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(25504,1,2880.6738,6734.3384,32.886127,"Mootoo the Younger"),
(25504,2,2876.5327,6732.6,32.85344,"Mootoo the Younger"),
(25504,3,2876.252,6729.078,32.425266,"Mootoo the Younger"),
(25504,4,2873.4412,6725.269,29.758915,"Mootoo the Younger"),
(25504,5,2872.7031,6724.9507,29.524113,"Mootoo the Younger"),
(25504,6,2866.8242,6725.592,26.853886,"Mootoo the Younger"),
(25504,7,2866.142,6725.864,26.727451,"Mootoo the Younger"),
(25504,8,2863.9402,6730.9033,24.06852,"Mootoo the Younger"),
(25504,9,2864.0422,6731.4243,23.844753,"Mootoo the Younger"),
(25504,10,2866.9207,6736.123,20.8938,"Mootoo the Younger"),
(25504,11,2868.2148,6737.7114,20.524538,"Mootoo the Younger"),
(25504,12,2871.9204,6733.5293,18.72071,"Mootoo the Younger"),
(25504,13,2872.6318,6732.693,18.503235,"Mootoo the Younger"),
(25504,14,2874.6172,6732.4917,18.505169,"Mootoo the Younger"),
(25504,15,2886.5828,6736.4595,13.996495,"Mootoo the Younger"), --
(25504,16,2892.64,6738.416,13.996495,"Mootoo the Younger"),
(25504,17,2902.5916,6741.8647,14.040568,"Mootoo the Younger"),
(25504,18,2908.333,6743.75,14.245999,"Mootoo the Younger"),
(25504,19,2918.7522,6745.375,13.745999,"Mootoo the Younger"),
(25504,20,2940.5566,6736.793,14.261914,"Mootoo the Younger"),
(25504,21,2968.4268,6743.5464,12.530648,"Mootoo the Younger"),
(25504,22,2987.257,6757.7134,8.530648,"Mootoo the Younger"),
(25504,23,2991.1672,6784.4507,6.409457,"Mootoo the Younger"),
(25504,24,2967.4966,6820.6216,4.683124,"Mootoo the Younger"),
(25504,25,2942.6692,6821.9673,5.1389837,"Mootoo the Younger"),
(25504,26,2906.9712,6819.9146,5.591904,"Mootoo the Younger"), --
(25504,27,2890.5176,6821.1226,4.8475246,"Mootoo the Younger"),
(25504,28,2854.99,6812.297,2.5060225,"Mootoo the Younger"),
(25504,29,2841.5513,6807.1694,3.6310225,"Mootoo the Younger"),
(25504,30,2812.5132,6794.91,4.3343086,"Mootoo the Younger"),
(25504,31,2806.751,6774.1973,5.7093086,"Mootoo the Younger"), --
(25504,32,2807.8342,6747.168,9.066917,"Mootoo the Younger");  --

-- Bonker Togglevolt SAI (Source: https://www.youtube.com/watch?v=J8lcTQZOGOA)
SET @ID := 25589;
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = @ID;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Respawn - Set Flag Standstate Sit Down"),
(@ID,0,1,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Respawn - Set Event Phase 1"),
(@ID,0,2,0,1,1,100,0,30000,30000,60000,180000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - Out Of Combat - Say Line 0 (Phase 1)"),
(@ID,0,3,0,4,0,20,0,0,0,0,0,0,1,5,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Aggro - Say Line 5"),
(@ID,0,4,0,19,0,100,0,11673,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Quest 'Get Me Outa Here!' Taken - Run Script"),
(@ID,0,5,0,40,0,100,0,1,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Waypoint 1 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,29,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Waypoint 29 Reached - Run Script"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,6,11673,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bonker Togglevolt - On Death - Fail Quest 'Get Me Outa Here!'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,53,0,25589,0,0,0,2,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Start Waypoint"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,54,13000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Pause Waypoint"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Set Faction 113"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Remove Flag Standstate Sit Down"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Remove NPC Flags Gossip & Questgiver"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,8,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Say Line 1"),
(@ID*100+0,9,9,0,0,0,100,0,1000,1000,0,0,0,99,3,0,0,0,0,0,20,182531,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Set Lootstate Just Deactivated (Ball and Chain)"),
(@ID*100+0,9,10,0,0,0,100,0,9000,9000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Say Line 2"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Say Line 3"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,3000,3000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Say Line 4"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,15,11673,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Quest Credit 'Get Me Outa Here!'"),
-- No info about this part
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonker Togglevolt - On Script - Despawn (15000)");

UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = @ID AND `GroupID` IN (3,4);

DELETE FROM `script_waypoint` WHERE `entry` = 25589;
DELETE FROM `waypoints` WHERE `entry` = 25589;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(25589,1,4462.37,5372.75,-15.2912,"Bonker Togglevolt"),
(25589,2,4478.7,5377.27,-15.0012,"Bonker Togglevolt"),
(25589,3,4482.25,5390.64,-15.2354,"Bonker Togglevolt"),
(25589,4,4477.09,5405.02,-15.2386,"Bonker Togglevolt"),
(25589,5,4468.71,5416.9,-15.2602,"Bonker Togglevolt"),
(25589,6,4457.24,5426.87,-15.6104,"Bonker Togglevolt"),
(25589,7,4439.7,5433.46,-15.2384,"Bonker Togglevolt"),
(25589,8,4422.63,5432.32,-14.8822,"Bonker Togglevolt"),
(25589,9,4404.71,5422.74,-14.4494,"Bonker Togglevolt"),
(25589,10,4394.68,5406.63,-10.8423,"Bonker Togglevolt"),
(25589,11,4391.99,5392.88,-6.45477,"Bonker Togglevolt"),
(25589,12,4390.65,5370.91,0.504708,"Bonker Togglevolt"),
(25589,13,4393.34,5354.19,3.1859,"Bonker Togglevolt"),
(25589,14,4401.68,5342.78,5.20245,"Bonker Togglevolt"),
(25589,15,4417.98,5335.18,8.31299,"Bonker Togglevolt"),
(25589,16,4431.01,5335.17,11.0135,"Bonker Togglevolt"),
(25589,17,4446.21,5340.58,14.4585,"Bonker Togglevolt"),
(25589,18,4462.73,5350.22,16.8783,"Bonker Togglevolt"),
(25589,19,4475.06,5362.82,19.1229,"Bonker Togglevolt"),
(25589,20,4480.92,5381.72,22.2479,"Bonker Togglevolt"),
(25589,21,4481.31,5394.2,26.2008,"Bonker Togglevolt"),
(25589,22,4476.32,5409.12,29.0811,"Bonker Togglevolt"),
(25589,23,4466.33,5420.75,31.8093,"Bonker Togglevolt"),
(25589,24,4450.66,5430.03,36.2843,"Bonker Togglevolt"),
(25589,25,4431.24,5433.77,38.2282,"Bonker Togglevolt"),
(25589,26,4417.65,5437.11,40.2429,"Bonker Togglevolt"),
(25589,27,4402.5,5440.94,42.7727,"Bonker Togglevolt"),
(25589,28,4387.11,5450.98,48.6992,"Bonker Togglevolt"),
(25589,29,4364.52,5468.98,48.8229,"Bonker Togglevolt"),
(25589,30,4344.02,5483.26,48.0509,"Bonker Togglevolt");
