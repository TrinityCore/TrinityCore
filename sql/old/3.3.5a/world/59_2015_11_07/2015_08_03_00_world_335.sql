--
-- 3.3.5 only
SET @KINELORY := 2713; -- Kinelory
SET @QUEST    := 660; -- Hints of a New Plague? (part 4)

-- Fix Apothecary Jorell text target
UPDATE `smart_scripts` SET `target_type`=21, `target_param1`=20 WHERE `entryorguid`=2733 AND `source_type`=0;

-- Update quest template addon
UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `id`=@QUEST;

UPDATE `creature` SET `spawntimesecs`=90 WHERE `id`=2713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KINELORY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KINELORY AND `source_type`=0 AND `id`>=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KINELORY ,0,2,3,19,0,100,0,@QUEST,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kinelory - On Quest 'Hints of a New Plague?' Taken - Say Line 0"),
(@KINELORY ,0,3,4,61,0,100,0,@QUEST,0,0,0,53,0,2713,0,@QUEST,0,1,1,0,0,0,0,0,0,0,"Kinelory - On Quest 'Hints of a New Plague?' Taken - Start Waypoint"),
(@KINELORY ,0,4,5,61,0,100,0,@QUEST,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Quest 'Hints of a New Plague?' Taken - Remove Npc Flag Questgiver"),
(@KINELORY ,0,5,6,61,0,100,0,@QUEST,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Quest 'Hints of a New Plague?' Taken - Remove Flag Immune To NPC's"),
(@KINELORY ,0,6,0,61,0,100,0,@QUEST,0,0,0,64,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kinelory - On Quest 'Hints of a New Plague?' Taken - Store Targetlist"),
(@KINELORY ,0,7,8,40,0,100,0,10,2713,0,0,1,1,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 10 Reached - Say Line 1"),
(@KINELORY ,0,8,0,61,0,100,0,10,2713,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 10 Reached - Pause Waypoint"),
(@KINELORY ,0,9,10,40,0,100,0,17,2713,0,0,1,2,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 17 Reached - Say Line 2"),
(@KINELORY ,0,10,11,61,0,100,0,17,2713,0,0,1,3,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 17 Reached - Say Line 3"),
(@KINELORY ,0,11,0,61,0,100,0,17,2713,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 17 Reached - Pause Waypoint"),
(@KINELORY ,0,12,13,40,0,100,0,18,2713,0,0,1,4,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 18 Reached - Say Line 4"),
(@KINELORY ,0,13,0,61,0,100,0,18,2713,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 18 Reached - Pause Waypoint"),
(@KINELORY ,0,14,15,40,0,100,0,19,2713,0,0,1,5,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 19 Reached - Say Line 5"),
(@KINELORY ,0,15,16,61,0,100,0,19,2713,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 19 Reached - Set Run On"),
(@KINELORY ,0,16,0,61,0,100,0,19,2713,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 19 Reached - Pause Waypoint"),
(@KINELORY ,0,17,18,40,0,100,0,34,2713,0,0,1,6,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 34 Reached - Say Line 6"),
(@KINELORY ,0,18,19,61,0,100,0,34,2713,0,0,1,7,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 34 Reached - Say Line 7"),
(@KINELORY ,0,19,0,61,0,100,0,34,2713,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 34 Reached - Pause Waypoint"),
(@KINELORY ,0,20,21,40,0,100,0,35,2713,0,0,15,@QUEST,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Waypoint 35 Reached - Quest Credit 'Hints of a New Plague?'"),
(@KINELORY ,0,21,0,61,0,100,0,35,2713,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 35 Reached - Despawn Instant"),
(@KINELORY ,0,22,23,11,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Respawn - Set Npc Flag Questgiver"),
(@KINELORY ,0,23,0,61,0,100,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Respawn - Set Flag Immune To NPC's"),
(@KINELORY ,0,24,0,4,0,50,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Aggro - Say Line 8"),
(@KINELORY ,0,25,0,40,0,100,0,1,2713,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 1 Reached - Set Home Position"),
(@KINELORY ,0,26,0,6,0,100,0,0,0,0,0,6,@QUEST,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Just Died - Fail Quest 'Hints of a New Plague?'");

-- Kinelory Texts
DELETE FROM `creature_text` WHERE `entry` = @KINELORY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@KINELORY,0,0,'Well then, let\'s get this started. The longer we\'re here, the more damage the undead could be doing back in Hillsbrad.',12,7,100,0,0,0,816,0,'Kinelory'),
(@KINELORY,1,0,'All right, this is where we really have to be on our paws. Be ready!',12,7,100,0,0,0,817,0,'Kinelory'),
(@KINELORY,2,0,'Watch my rear! I\'ll see what I can find in all this junk...',12,7,100,0,0,0,818,0,'Kinelory'),
(@KINELORY,3,0,'%s begins rummaging through the apothecary\'s belongings.',16,7,100,0,0,0,819,0,'Kinelory'),
(@KINELORY,4,0,'I bet Quae\'ll think this is important. She\'s pretty knowledgeable about these things--no expert, but knowledgable.',12,7,100,0,0,0,821,0,'Kinelory'),
(@KINELORY,5,0,'Okay, let\'s get out of here quick quick! Try and keep up. I\'m going to make a break for it.',12,7,100,0,0,0,822,0,'Kinelory'),
(@KINELORY,6,0,'%s hands her pack to Quae.',16,7,100,0,0,0,891,0,'Kinelory'),
(@KINELORY,7,0,'We made it! Quae, we made it!',12,7,100,0,0,0,892,0,'Kinelory'),
(@KINELORY,8,0,'Attack me if you will, but you won\'t stop me from getting back to Quae.',12,7,100,0,0,0,897,0,'Kinelory');

-- Kinelory Waypoints
DELETE FROM `waypoints` WHERE `entry`=@KINELORY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@KINELORY, 1, -1416.91, -3044.12, 36.21, 'Kinelory'),
(@KINELORY, 2, -1408.43, -3051.35, 37.79, 'Kinelory'),
(@KINELORY, 3, -1399.45, -3069.20, 31.25, 'Kinelory'),
(@KINELORY, 4, -1400.28, -3083.14, 27.06, 'Kinelory'),
(@KINELORY, 5, -1405.30, -3096.72, 26.36, 'Kinelory'),
(@KINELORY, 6, -1406.12, -3105.95, 24.82, 'Kinelory'),
(@KINELORY, 7, -1417.41, -3106.80, 16.61, 'Kinelory'),
(@KINELORY, 8, -1433.06, -3101.55, 12.56, 'Kinelory'),
(@KINELORY, 9, -1439.86, -3086.36, 12.29, 'Kinelory'),
(@KINELORY, 10, -1450.48, -3065.16, 12.58, 'Kinelory'),
(@KINELORY, 11, -1456.15, -3055.53, 12.54, 'Kinelory'),
(@KINELORY, 12, -1459.41, -3035.16, 12.11, 'Kinelory'),
(@KINELORY, 13, -1472.47, -3034.18, 12.44, 'Kinelory'),
(@KINELORY, 14, -1495.57, -3034.48, 12.55, 'Kinelory'),
(@KINELORY, 15, -1524.91, -3035.47, 13.15, 'Kinelory'),
(@KINELORY, 16, -1549.05, -3037.77, 12.98, 'Kinelory'),
(@KINELORY, 17, -1555.69, -3028.02, 13.64, 'Kinelory'),
(@KINELORY, 18, -1555.69, -3028.02, 13.64, 'Kinelory'),
(@KINELORY, 19, -1555.69, -3028.02, 13.64, 'Kinelory'),
(@KINELORY, 20, -1551.19, -3037.78, 12.96, 'Kinelory'),
(@KINELORY, 21, -1584.60, -3048.77, 13.67, 'Kinelory'),
(@KINELORY, 22, -1602.14, -3042.82, 15.12, 'Kinelory'),
(@KINELORY, 23, -1610.68, -3027.42, 17.22, 'Kinelory'),
(@KINELORY, 24, -1601.65, -3007.97, 24.65, 'Kinelory'),
(@KINELORY, 25, -1581.05, -2992.32, 30.85, 'Kinelory'),
(@KINELORY, 26, -1559.95, -2979.51, 34.30, 'Kinelory'),
(@KINELORY, 27, -1536.51, -2969.78, 32.64, 'Kinelory'),
(@KINELORY, 28, -1511.81, -2961.09, 29.12, 'Kinelory'),
(@KINELORY, 29, -1484.83, -2960.87, 32.54, 'Kinelory'),
(@KINELORY, 30, -1458.23, -2966.80, 40.52, 'Kinelory'),
(@KINELORY, 31, -1440.20, -2971.20, 43.15, 'Kinelory'),
(@KINELORY, 32, -1427.85, -2989.15, 38.09, 'Kinelory'),
(@KINELORY, 33, -1420.27, -3008.91, 35.01, 'Kinelory'),
(@KINELORY, 34, -1427.58, -3032.53, 32.31, 'Kinelory'),
(@KINELORY, 35, -1427.40, -3035.17, 32.26, 'Kinelory');
