-- [Q] [A/H] In Service Of The Lich King
-- The Lich King SAI
SET @ENTRY := 25462;
SET @QUEST := 12593;
SET @SPELL_EXLOSION := 58024;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0 WHERE `id`=@QUEST;
DELETE FROM `quest_start_scripts` WHERE `id`=@QUEST;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,@QUEST,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - On Quest Accept - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,3000,3000,0,0,11,@SPELL_EXLOSION,0,0,0,0,0,7,0,0,0,0,0,0,0,"The Lich King - On Script - Cast 'Icecrown Airship - A - Attack - 02b Cannon Explosion, Shield'"); -- After three seconds
