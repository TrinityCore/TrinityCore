-- Delete all spawnings of Chicken Escapee via quest_start_scripts
DELETE FROM `quest_start_scripts` WHERE `command`=10 AND `datalong`=28161;

-- Elder Harkek SAI
SET @ENTRY := 28138;
SET @SPELL_SEE_INVIS_CHICKEN := 50735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,12532,0,0,0,85,@SPELL_SEE_INVIS_CHICKEN,2,0,0,0,0,7,0,0,0,0,0,0,0,"Elder Harkek - On Quest Accept - Invoker Cast Frenzyheart Chicken: See Invisibility"),
(@ENTRY,0,1,0,19,0,100,0,12702,0,0,0,85,@SPELL_SEE_INVIS_CHICKEN,2,0,0,0,0,7,0,0,0,0,0,0,0,"Elder Harkek - On Quest Accept - Invoker Cast Frenzyheart Chicken: See Invisibility"),
(@ENTRY,0,2,0,20,0,100,0,12532,0,0,0,28,@SPELL_SEE_INVIS_CHICKEN,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elder Harkek - On Quest Complete - Remove Aura Frenzyheart Chicken: See Invisibility"),
(@ENTRY,0,3,0,20,0,100,0,12702,0,0,0,28,@SPELL_SEE_INVIS_CHICKEN,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elder Harkek - On Quest Complete - Remove Aura Frenzyheart Chicken: See Invisibility");
