-- Deranged Helboar SAI (Source: https://www.youtube.com/watch?v=R_c3kqvAr6g)
-- The 'Burning Spikes' aura already presents in creature_template_addon
SET @ID := 16863;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,2,0,100,1,0,30,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deranged Helboar - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deranged Helboar - On Link - Say Line 0"),
(@ID,0,2,0,6,0,100,0,0,0,0,0,0,11,37689,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deranged Helboar - On Death - Cast 'Tell dog I just died!'");

-- Fel Guard Hound SAI (Source: https://www.youtube.com/watch?v=R_c3kqvAr6g)
SET @ID := 21847;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- I was thinking static spawns will be problem, but they too can use this script as it shown in the video. Funny and fully supported
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Just Summoned - Set Event Phase 1"),
(@ID,0,1,2,8,1,100,0,37689,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Spellhit 'Tell dog I just died!' - Stop Follow (Phase 1)"),
(@ID,0,2,3,61,1,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Link - Set Run Off (Phase 1)"),
-- Contact distance param: Seems like the min value with effect different from 0 is 0.5
-- But 1.5(seems like the correct value) in-game turns to 5.0
(@ID,0,3,4,61,1,100,0,0,0,0,0,0,69,1,0,0,0.5,0,0,7,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Link - Move To Invoker (Phase 1)"),
(@ID,0,4,0,61,1,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Link - Set Event Phase 2 (Phase 1)"),
(@ID,0,5,0,34,0,100,0,8,1,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Reached Point 1 - Run Script"),
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,11,37692,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Cast 'Fake Blood Spurt'"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Play Emote 51"),
(@ID*100+0,9,2,0,0,0,100,0,1500,1500,0,0,0,11,37692,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Cast 'Fake Blood Spurt'"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,5,51,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Play Emote 51"),
(@ID*100+0,9,4,0,0,0,100,0,1000,1000,0,0,0,11,37688,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Cast 'Create Poodad'"),
(@ID*100+0,9,5,0,0,0,100,0,1000,1000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Set Event Phase 1"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Set Run On"),
-- Not 'Start Follow Owner' because we want to provide full support to static spawns too
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Guard Hound - On Script - Evade");
