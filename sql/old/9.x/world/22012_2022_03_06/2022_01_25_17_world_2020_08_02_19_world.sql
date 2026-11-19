-- Father Kamaros SAI (Source: Sniffs & https://www.youtube.com/watch?v=p5T9py6wWzw)
SET @ID := 31279;
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = @ID;
UPDATE `creature_addon` SET `bytes1` = 0 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = @ID);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Respawn - Set Flag Standstate Kneel"),
(@ID,0,1,0,4,0,30,0,0,0,0,0,0,1,5,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Father Kamaros - On Aggro - Say Line 5"),
-- Probably no reason to not reset main spell for caster AI
(@ID,0,2,0,0,0,100,0,0,0,3400,4700,0,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Father Kamaros - In Combat CMC - Cast 'Holy Smite'"),
(@ID,0,3,0,0,0,100,256,5000,6200,11700,15600,0,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Shadow Word: Pain' (No Reset)"),
-- He casts it while in combat on allies (on player) and not on escort start
(@ID,0,4,0,0,0,100,256,0,0,6000,10000,0,11,58921,32,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Power Word: Fortitude' (No Reset)"),
-- According to https://www.youtube.com/watch?v=wqJRG-FTLVQ and sniffs
-- must be used on player too but we can't do it in one event
(@ID,0,5,0,0,0,100,256,0,4000,7000,14000,14000,11,32595,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Power Word: Shield' (No Reset)"),
(@ID,0,6,0,19,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Quest Taken - Run Script"),
(@ID,0,7,0,40,0,100,0,21,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Waypoint 21 Reached - Run Script"),
(@ID,0,8,0,40,0,100,0,24,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Waypoint 24 Reached - Despawn (1000)"),
(@ID,0,9,0,6,0,100,0,0,0,0,0,0,6,13221,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Death - Fail Quest 'I'm Not Dead Yet!'"),
(@ID,0,10,0,6,0,100,0,0,0,0,0,0,6,13229,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Death - Fail Quest 'I'm Not Dead Yet!'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Remove Flag Standstate Kneel"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 1"),
(@ID*100+0,9,4,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 2"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,6,0,0,0,100,0,5000,5000,0,0,0,53,0,31279,0,0,0,1,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 3"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,0,15,13221,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Quest Credit 'I'm Not Dead Yet!'"),
(@ID*100+1,9,3,0,0,0,100,0,0,0,0,0,0,15,13229,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Quest Credit 'I'm Not Dead Yet!'"),
(@ID*100+1,9,4,0,0,0,100,0,4000,4000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 4"),
(@ID*100+1,9,5,0,0,0,100,0,4000,4000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Play Emote 1"),
(@ID*100+1,9,6,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Set Run On");

-- Father Kamaros SAI (Source: Sniffs & https://www.youtube.com/watch?v=p5T9py6wWzw)
SET @ID := 32800;
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = @ID;
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Respawn - Set Flag Standstate Kneel"),
(@ID,0,1,0,4,0,30,0,0,0,0,0,0,1,5,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Father Kamaros - On Aggro - Say Line 5"),
-- Probably no reason to not reset main spell for caster AI
(@ID,0,2,0,0,0,100,0,0,0,3400,4700,0,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Father Kamaros - In Combat CMC - Cast 'Holy Smite'"),
(@ID,0,3,0,0,0,100,256,5000,6200,11700,15600,0,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Shadow Word: Pain' (No Reset)"),
-- He casts it while in combat on allies (on player) and not on escort start
(@ID,0,4,0,0,0,100,256,0,0,6000,10000,0,11,58921,32,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Power Word: Fortitude' (No Reset)"),
-- According to https://www.youtube.com/watch?v=wqJRG-FTLVQ and sniffs
-- must be used on player too but we can't do it in one event
(@ID,0,5,0,0,0,100,256,0,4000,7000,14000,14000,11,32595,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - In Combat - Cast 'Power Word: Shield' (No Reset)"),
(@ID,0,6,0,19,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Quest Taken - Run Script"),
(@ID,0,7,0,40,0,100,0,21,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Waypoint 21 Reached - Run Script"),
(@ID,0,8,0,40,0,100,0,24,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Waypoint 24 Reached - Despawn (1000)"),
(@ID,0,9,0,6,0,100,0,0,0,0,0,0,6,13481,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Death - Fail Quest 'Let's Get Out of Here!'"),
(@ID,0,10,0,6,0,100,0,0,0,0,0,0,6,13482,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Death - Fail Quest 'Let's Get Out of Here!'"),

-- Since we don't have a simple way to load waypoint, we have to duplicate action lists
-- because later it will be easier to update both scripts
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Remove Flag Standstate Kneel"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 1"),
(@ID*100+0,9,4,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 2"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,6,0,0,0,100,0,5000,5000,0,0,0,53,0,32800,0,0,0,1,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 3"),
(@ID*100+1,9,2,0,0,0,100,0,0,0,0,0,0,15,13481,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Quest Credit 'Let's Get Out of Here!'"),
(@ID*100+1,9,3,0,0,0,100,0,0,0,0,0,0,15,13482,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Quest Credit 'Let's Get Out of Here!'"),
(@ID*100+1,9,4,0,0,0,100,0,4000,4000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Father Kamaros - On Script - Say Line 4"),
(@ID*100+1,9,5,0,0,0,100,0,4000,4000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Play Emote 1"),
(@ID*100+1,9,6,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Father Kamaros - On Script - Set Run On");

DELETE FROM `waypoints` WHERE `entry` IN (31279,32800);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(31279,1,6717.6904,3443.2432,682.687,"Father Kamaros"),
(31279,2,6718.762,3435.7378,682.3103,"Father Kamaros"),
(31279,3,6722.3506,3431.3716,682.242,"Father Kamaros"),
(31279,4,6731.009,3433.3816,682.1853,"Father Kamaros"),
(31279,5,6742.377,3443.0815,679.90356,"Father Kamaros"),
(31279,6,6752.7676,3453.6272,676.74646,"Father Kamaros"),
(31279,7,6768.5146,3467.874,672.9478,"Father Kamaros"),
(31279,8,6779.0215,3479.7495,673.0938,"Father Kamaros"),
(31279,9,6788.5806,3481.9812,676.28046,"Father Kamaros"),
(31279,10,6799.746,3483.9277,679.7172,"Father Kamaros"),
(31279,11,6808.936,3483.4111,683.36584,"Father Kamaros"),
(31279,12,6823.6616,3483.8047,688.5365,"Father Kamaros"),
(31279,13,6844.1562,3480.054,691.90576,"Father Kamaros"),
(31279,14,6890.3213,3478.8525,697.388,"Father Kamaros"),
(31279,15,6918.0796,3479.9023,702.74207,"Father Kamaros"),
(31279,16,6945.9097,3475.4602,708.7313,"Father Kamaros"),
(31279,17,6967.8853,3470.103,710.34485,"Father Kamaros"),
(31279,18,6978.2534,3467.9526,710.8566,"Father Kamaros"),
(31279,19,7006.3325,3458.2712,697.653,"Father Kamaros"),
(31279,20,7022.8506,3449.9045,696.6406,"Father Kamaros"),
(31279,21,7037.923,3440.7744,695.54376,"Father Kamaros"), --
(31279,22,7056.45,3428.8298,695.0076,"Father Kamaros"),
(31279,23,7072.7354,3418.1975,695.0446,"Father Kamaros"),
(31279,24,7085.5522,3408.04,694.9196,"Father Kamaros"),
(32800,1,6717.6904,3443.2432,682.687,"Father Kamaros"),
(32800,2,6718.762,3435.7378,682.3103,"Father Kamaros"),
(32800,3,6722.3506,3431.3716,682.242,"Father Kamaros"),
(32800,4,6731.009,3433.3816,682.1853,"Father Kamaros"),
(32800,5,6742.377,3443.0815,679.90356,"Father Kamaros"),
(32800,6,6752.7676,3453.6272,676.74646,"Father Kamaros"),
(32800,7,6768.5146,3467.874,672.9478,"Father Kamaros"),
(32800,8,6779.0215,3479.7495,673.0938,"Father Kamaros"),
(32800,9,6788.5806,3481.9812,676.28046,"Father Kamaros"),
(32800,10,6799.746,3483.9277,679.7172,"Father Kamaros"),
(32800,11,6808.936,3483.4111,683.36584,"Father Kamaros"),
(32800,12,6823.6616,3483.8047,688.5365,"Father Kamaros"),
(32800,13,6844.1562,3480.054,691.90576,"Father Kamaros"),
(32800,14,6890.3213,3478.8525,697.388,"Father Kamaros"),
(32800,15,6918.0796,3479.9023,702.74207,"Father Kamaros"),
(32800,16,6945.9097,3475.4602,708.7313,"Father Kamaros"),
(32800,17,6967.8853,3470.103,710.34485,"Father Kamaros"),
(32800,18,6978.2534,3467.9526,710.8566,"Father Kamaros"),
(32800,19,7006.3325,3458.2712,697.653,"Father Kamaros"),
(32800,20,7022.8506,3449.9045,696.6406,"Father Kamaros"),
(32800,21,7037.923,3440.7744,695.54376,"Father Kamaros"), --
(32800,22,7056.45,3428.8298,695.0076,"Father Kamaros"),
(32800,23,7072.7354,3418.1975,695.0446,"Father Kamaros"),
(32800,24,7085.5522,3408.04,694.9196,"Father Kamaros");

-- Shown in https://www.youtube.com/watch?v=wqJRG-FTLVQ and web archive (wowhead)
DELETE FROM `creature_text` WHERE `CreatureID` IN (31279,32800) AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(31279,5,0,"Face your judgment by the Light!",12,0,100,0,0,0,31950,0,"Father Kamaros"),
(31279,5,1,"You will never take me alive!",12,0,100,0,0,0,31952,0,"Father Kamaros"),
(31279,5,2,"The Argent Crusade never surrenders!",12,0,100,0,0,0,31953,0,"Father Kamaros"),
(32800,5,0,"Face your judgment by the Light!",12,0,100,0,0,0,31950,0,"Father Kamaros"),
(32800,5,1,"You will never take me alive!",12,0,100,0,0,0,31952,0,"Father Kamaros"),
(32800,5,2,"The Argent Crusade never surrenders!",12,0,100,0,0,0,31953,0,"Father Kamaros");

-- Emotes were not added to one of them
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 31279 AND `GroupID` = 2;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 31279 AND `GroupID` = 3;
UPDATE `creature_text` SET `Emote` = 2 WHERE `CreatureID` = 31279 AND `GroupID` = 4;
