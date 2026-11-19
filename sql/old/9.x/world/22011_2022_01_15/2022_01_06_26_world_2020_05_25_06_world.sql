-- Maxx A. Million Mk. V SAI (Sources: CMaNGOS & https://www.youtube.com/watch?v=pGIRyYnzeR8 & https://www.youtube.com/watch?v=95H-ydIWnCE)
SET @ID := 19589;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 19578;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ID,19578) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ID*100+0,@ID*100+1,@ID*100+2,@ID*100+3,1957800,1957801) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,10191,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Quest 'Mark V is Alive!' Taken - Run Script"),
(@ID,0,1,0,40,0,100,0,1,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Waypoint 1 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,7,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Waypoint 7 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,17,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Waypoint 17 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,29,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Waypoint 29 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,37,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Waypoint 37 Reached - Run Script"),
(@ID,0,6,0,6,0,100,0,0,0,0,0,0,6,10191,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Death - Fail Quest 'Mark V is Alive!'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Set Emote State 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Set Faction 113"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,53,0,19589,0,0,0,2,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,5.408872,"Maxx A. Million Mk. V - On Script - Set Orientation"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Say Line 0"),
(@ID*100+1,9,3,0,0,0,100,0,0,0,0,0,0,80,1957800,0,0,0,0,0,19,19578,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Run Script (Bot-Specialist Alley)"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Play Emote 35"),
(@ID*100+2,9,2,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,20,183771,10,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Despawn Closest Gameobject 'Draenei Machine'"),
(@ID*100+2,9,3,0,0,0,100,0,8000,8000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Say Line 1"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.628319,"Maxx A. Million Mk. V - On Script - Set Orientation"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,80,1957801,0,0,0,0,0,19,19578,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Run Script (Bot-Specialist Alley)"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Add NPC Flag Questgiver"),
(@ID*100+3,9,3,0,0,0,100,0,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Set Flags Immune To Players & Immune To NPC's"),
(@ID*100+3,9,4,0,0,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Set Faction 35"),
(@ID*100+3,9,5,0,0,0,100,0,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Set Emote State 64"),
(@ID*100+3,9,6,0,0,0,100,0,2000,2000,0,0,0,15,10191,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Maxx A. Million Mk. V - On Script - Quest Credit 'Mark V is Alive!'"),

-- Run NYI OOC event only in phase 1
(19578,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Respawn - Set Event Phase 1"),
-- Stop OOC event, if waypoint will be used, stop it here
(1957800,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Event Phase 2"),
(1957800,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,19589,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Orientation Closest Creature 'Maxx A. Million Mk. V'"),
(1957800,9,2,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Emote State 0"),
(1957800,9,3,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Say Line 3"),
(1957800,9,4,0,0,0,100,0,9000,9000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Orientation Home Position"),
-- Original timers unknown, probably incorrect to put this here since this should be done in OOC event
-- for now let's keep this here just to restore initial emote
(1957800,9,5,0,0,0,100,0,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Emote State 133"),
-- Back to OOC event
(1957800,9,6,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Event Phase 1"),

-- Stop OOC event, if waypoint will be used, stop it here
(1957801,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Event Phase 2"),
(1957801,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,19589,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Orientation Closest Creature 'Maxx A. Million Mk. V'"),
(1957801,9,2,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Emote State 0"),
(1957801,9,3,0,0,0,100,0,2000,2000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Say Line 4"),
(1957801,9,4,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Orientation Home Position"),
-- Original timers unknown, probably incorrect to put this here since this should be done in OOC event
-- for now let's keep this here just to restore initial emote
(1957801,9,5,0,0,0,100,0,0,0,0,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Emote State 133"),
-- Back to OOC event
(1957801,9,6,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bot-Specialist Alley - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID` IN (@ID,19578);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"All systems on-line.  Prepare yourself, we leave shortly.",12,0,100,0,0,0,19481,0,"Maxx A. Million Mk. V"),
(@ID,1,0,"Proceed.",12,0,100,0,0,0,19484,0,"Maxx A. Million Mk. V"),
-- Probably they're grouped differently, maybe 16999 and 17000 too
(19578,0,0,"Alright, Mk. I, that should just about do it.  Let's just flip your switch here...",12,0,100,0,0,0,16964,0,"Bot-Specialist Alley"),
(19578,1,0,"Oh no!  Will I ever get you working?!",12,0,100,0,0,0,16965,0,"Bot-Specialist Alley"),
(19578,2,0,"Mark II, get your metallic behind back here this instant!",12,0,100,0,0,0,16998,0,"Bot-Specialist Alley"),
(19578,3,0,"Be careful in there and come back in one piece!",12,0,100,1,0,0,17003,0,"Bot-Specialist Alley"),
(19578,4,0,"You're back!  Were you able to get all of the machines?",12,0,100,4,0,0,17014,0,"Bot-Specialist Alley");

DELETE FROM `script_waypoint` WHERE `entry` = 19589;
DELETE FROM `waypoints` WHERE `entry` = 19589;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(19589,1,3358.22,3728.25,141.204,"Maxx A. Million Mk. V"),
(19589,2,3368.05,3715.51,142.057,"Maxx A. Million Mk. V"),
(19589,3,3389.04,3701.21,144.648,"Maxx A. Million Mk. V"),
(19589,4,3419.51,3691.41,146.598,"Maxx A. Million Mk. V"),
(19589,5,3437.83,3699.2,147.235,"Maxx A. Million Mk. V"),
(19589,6,3444.85,3700.89,147.088,"Maxx A. Million Mk. V"),
(19589,7,3449.89,3700.14,148.118,"Maxx A. Million Mk. V"),
(19589,8,3443.55,3682.09,149.219,"Maxx A. Million Mk. V"),
(19589,9,3452.6,3674.65,150.226,"Maxx A. Million Mk. V"),
(19589,10,3462.6,3659.01,152.436,"Maxx A. Million Mk. V"),
(19589,11,3469.18,3649.47,153.178,"Maxx A. Million Mk. V"),
(19589,12,3475.11,3639.41,157.213,"Maxx A. Million Mk. V"),
(19589,13,3482.26,3617.69,159.126,"Maxx A. Million Mk. V"),
(19589,14,3492.7,3606.27,156.419,"Maxx A. Million Mk. V"),
(19589,15,3493.52,3595.06,156.581,"Maxx A. Million Mk. V"),
(19589,16,3490.4,3588.45,157.764,"Maxx A. Million Mk. V"),
(19589,17,3485.21,3585.69,159.979,"Maxx A. Million Mk. V"),
(19589,18,3504.68,3594.44,152.862,"Maxx A. Million Mk. V"),
(19589,19,3523.6,3594.48,145.393,"Maxx A. Million Mk. V"),
(19589,20,3537.01,3576.71,135.748,"Maxx A. Million Mk. V"),
(19589,21,3551.73,3573.12,128.013,"Maxx A. Million Mk. V"),
(19589,22,3552.12,3614.08,127.847,"Maxx A. Million Mk. V"),
(19589,23,3536.14,3639.78,126.031,"Maxx A. Million Mk. V"),
(19589,24,3522.94,3646.47,131.989,"Maxx A. Million Mk. V"),
(19589,25,3507.21,3645.69,138.153,"Maxx A. Million Mk. V"),
(19589,26,3485.15,3645.64,137.755,"Maxx A. Million Mk. V"),
(19589,27,3472.18,3633.88,140.352,"Maxx A. Million Mk. V"),
(19589,28,3435.34,3613.69,140.725,"Maxx A. Million Mk. V"),
(19589,29,3417.4,3612.4,141.143,"Maxx A. Million Mk. V"),
(19589,30,3411.04,3621.14,142.454,"Maxx A. Million Mk. V"),
(19589,31,3404.47,3636.89,144.434,"Maxx A. Million Mk. V"),
(19589,32,3380.55,3657.06,144.332,"Maxx A. Million Mk. V"),
(19589,33,3375,3676.86,145.298,"Maxx A. Million Mk. V"),
(19589,34,3388.87,3685.48,146.818,"Maxx A. Million Mk. V"),
(19589,35,3393.99,3699.4,144.858,"Maxx A. Million Mk. V"),
(19589,36,3354.95,3726.02,141.428,"Maxx A. Million Mk. V"),
(19589,37,3351.4,3722.33,141.397,"Maxx A. Million Mk. V");
