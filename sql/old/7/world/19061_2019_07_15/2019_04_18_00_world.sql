-- #### Fix Quest 25370 "Inciting the Elements" in Hyjai zone####

-- Remove loot and fix addon for Twilight Inciter
UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=39926;
DELETE FROM `creature_loot_template` WHERE `Entry`=39926;
DELETE FROM `creature_template_addon` WHERE `entry`=39926;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`auras`) VALUES (39926,0,131072,503316481,0,0, '30991');

-- Set random movement for various creatures
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `id` IN (39921,40229,49728);

-- Add creature text for Faerie Dragon & Twilight Inciter
DELETE FROM `creature_text` WHERE `CreatureID` IN (39921,39926);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39921, 0, 0, 'Meep!  $R is good friend.  Follow now!  We find intruder!', 12, 0, 100, 0, 0, 0, 39943, 'Faerie Dragon'),
(39921, 0, 1, 'We find evil ones now!  Follow!', 12, 0, 100, 0, 0, 0, 40300, 'Faerie Dragon'),
(39921, 0, 2, 'They hide this way!  Quick!', 12, 0, 100, 0, 0, 0, 40301, 'Faerie Dragon'),
(39921, 0, 3, 'We look for the evil ones now, yes?', 12, 0, 100, 0, 0, 0, 40302, 'Faerie Dragon'),
(39921, 1, 0, 'We finds evil one!  Quick!', 14, 0, 100, 0, 0, 0, 39944, 'Faerie Dragon'),
(39921, 1, 1, 'Over here!  You must stop them!', 14, 0, 100, 0, 0, 0, 40303, 'Faerie Dragon'),
(39921, 1, 2, 'You must fight now, $n!', 14, 0, 100, 0, 0, 0, 40304, 'Faerie Dragon'),
(39921, 1, 3, 'Over here, $n!', 14, 0, 100, 0, 0, 0, 40305, 'Faerie Dragon'),
(39926, 0, 0, 'How did you find me?  It matters little... you will die!', 12, 0, 100, 0, 0, 0, 39945, 'Twilight Inciter'),
(39926, 0, 1, 'I''ve been spotted?  Time to die!', 12, 0, 100, 0, 0, 0, 39946, 'Twilight Inciter'),
(39926, 0, 2, 'You will not give away my position, $c!', 12, 0, 100, 0, 0, 0, 39947, 'Twilight Inciter'),
(39926, 0, 3, 'You might have found me, but you won''t bring word back to the others!', 12, 0, 100, 0, 0, 0, 39948, 'Twilight Inciter');

-- Faerie Dragon SAI
SET @ENTRY := 39921;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*10 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faerie Dragon - On spawn - Set event phase"),
(@ENTRY,0,1,2,8,1,100,0,74513,0,60000,60000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Faerie Dragon - On Spell hit - Say 0"),
(@ENTRY,0,2,0,61,1,100,0,0,0,0,0,80,@ENTRY*10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faerie Dragon - On Spell hit - Run script"),
(@ENTRY*10,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faerie Dragon - script - Set event phase"),
(@ENTRY*10,9,1,0,0,0,100,0,3000,3000,3000,3000,89,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faerie Dragon - script - Move to random location 25 yards"),
(@ENTRY*10,9,2,0,0,0,100,0,8000,8000,8000,8000,11,74515,0,0,0,0,0,7,0,0,0,0,0,0,0,"Faerie Dragon - script - Cast 'Forcecast Spot Infiltrator'"),
(@ENTRY*10,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Faerie Dragon - script - Say 1"),
(@ENTRY*10,9,4,0,0,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Faerie Dragon - script - despawn");

-- Twilight Inciter SAI
SET @ENTRY := 39926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,1,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Inciter - Just Summoned - Turn to summoner"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Inciter - Just Summoned - Say 0"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,10000,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Inciter - Combat - Cast: 'Shadowstep'"),
(@ENTRY,0,3,0,67,0,100,0,5000,5000,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Inciter - Combat - Cast: 'Backstab'");

-- fix npc
DELETE FROM `creature_addon` WHERE `guid`=383970;
DELETE FROM `creature_template_addon` WHERE `entry`=40278;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`auras`) VALUES (40278,0,0,1,375,0, '');

-- Tiala Whitemane SAI
SET @ENTRY := 40833;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,2000,2000,11,13236,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tiala Whitemane - OOC - Cast 'Nature Channeling'"),
(@ENTRY,0,1,0,1,0,100,0,2000,2000,2000,2000,92,0,13236,1,0,0,0,1,0,0,0,0,0,0,0,"Tiala Whitemane - OOC - Interupt cast");
