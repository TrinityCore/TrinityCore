-- [Q] [A/H] The Boon of A'dal
-- A'dal SAI
SET @ENTRY := 18481;
SET @QUEST := 13082;
SET @SPELL_BLESSING := 35076;
SET @SPELL_TP_DALARAN := 53141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,0,0,0,11,@SPELL_BLESSING,0,0,0,0,0,1,0,0,0,0,0,0,0,"A'dal - Out of Combat - Cast Blessing of A'dal"), -- From EAI
(@ENTRY,0,1,0,19,0,100,0,@QUEST,0,0,0,11,@SPELL_TP_DALARAN,0,0,0,0,0,7,0,0,0,0,0,0,0,"A'dal - On Quest Accept - Cast Teleport Dalaran");
