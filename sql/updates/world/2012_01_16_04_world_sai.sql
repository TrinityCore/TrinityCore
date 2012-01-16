-- [Q] [A/H] Hope Within the Emerald Nightmare
-- This NPC already had SAI so we're only adding additional lines
-- Keeper Remulos SAI
SET @ENTRY := 11832;
SET @QUEST := 13074;
SET @SPELL_FITFUL_DREAM := 57413;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,19,0,100,0,@QUEST,0,0,0,11,@SPELL_FITFUL_DREAM,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keeper Remulos - On Quest Accept - Cast Fitful Dream");
