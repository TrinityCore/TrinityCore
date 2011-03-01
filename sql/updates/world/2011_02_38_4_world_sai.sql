-- c27842 Fenrick Barlowe
-- ================================
SET @ENTRY := 27842;
SET @SCRIPT1 := 2784201;
SET @SCRIPT2 := 2784202;
-- ================================
-- take random movement off of npc (smartAI will control pathing)
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid`=114186;
-- * create text into the DB
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(@ENTRY,0,0, 'Bat gizzards again for the gnomes tonight...',0,0,100,1,0,0, 'Fenrick Barlowe text'),
(@ENTRY,0,1, 'What do they expect, making the bats come in at that angle? Broken necks and gamey bat stew, that''s what they get.',0,0,100,1,0,0, 'Fenrick Barlowe text'),
(@ENTRY,0,2, '''We like trees, Fenrick. They provide cover.'' They won''t let me chop them down, either.',0,0,100,1,0,0, 'Fenrick Barlowe text'),
(@ENTRY,0,3, 'I wonder how many reinforcements need to suffer injury before they allows us to chop down these idiotic trees. They''re costing us a fortune in bats. Maybe I''ll rig a harness or two...',0,0,100,1,0,0, 'Fenrick Barlowe text');
-- create path
-- point 8 reposition to face bat, do text - kneel for 10 seconds
-- point 5 do text - kneel for 10 seconds
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,3246.2,-642.609,165.239, 'Fenrick Barlowe path'),
(@ENTRY,2,3240.42,-645.154,165.399, 'Fenrick Barlowe path'),
(@ENTRY,3,3245.75,-664.935,166.789, 'Fenrick Barlowe path'),
(@ENTRY,4,3250.1,-663.819,166.789, 'Fenrick Barlowe path'),
(@ENTRY,5,3254.69,-661.435,167.188, 'Fenrick Barlowe path - kneel here - do text'),
(@ENTRY,6,3252.36,-659.146,167.118, 'Fenrick Barlowe path'),
(@ENTRY,7,3252.63,-648.746,165.904, 'Fenrick Barlowe path'),
(@ENTRY,8,3249.21,-647.163,165.7, 'Fenrick Barlowe path - kneel here - do text');
-- set SAI to npc
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- create scripts for random text, emotes, and pathing
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@SCRIPT1,@SCRIPT2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- AI
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'on spawn start path'),
(@ENTRY,0,1,0,40,0,100,0,5,@ENTRY,0,0,80,@SCRIPT1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'at wp 5 run script1'),
(@ENTRY,0,2,0,40,0,100,0,8,@ENTRY,0,0,80,@SCRIPT2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'at wp 8 run script2'),
-- script 1
(@SCRIPT1,9,0,0,0,0,100,0,0,0,0,0,54,13000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'pause pathing'),
(@SCRIPT1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'say random text'),
(@SCRIPT1,9,2,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1=8 kneel'),
(@SCRIPT1,9,3,0,0,0,100,0,11000,11000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1=0 stand up'),
-- script 2
(@SCRIPT2,9,0,0,0,0,100,0,0,0,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'pause pathing'),
(@SCRIPT2,9,1,0,40,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'say random text'),
(@SCRIPT2,9,2,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,10,108509,27787,0,0,0,0,0, 'face bat'),
(@SCRIPT2,9,3,0,0,0,100,0,1000,1000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1=8 kneel'),
(@SCRIPT2,9,4,0,0,0,100,0,11000,11000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set bytes1=0 stand up');
-- need the following fix also
-- c27787 Venomspite Riding Bat
UPDATE `creature` SET `unit_flags`=`unit_flags`|570688256,`dynamicflags`=`dynamicflags`|32 WHERE `guid` IN (108508,108509);
DELETE FROM `creature_addon` WHERE `guid` IN (108508,108509);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES
(108508,1, '29266 0 29266 1'),(108509,1, '29266 0 29266 1');
