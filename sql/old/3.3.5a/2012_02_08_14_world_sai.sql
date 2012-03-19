SET @ENTRY := 38035; -- Chemical Wagon
SET @SPELL1 := 71599; -- Cosmetic - Explosion (Chemical Wagon)
SET @SPELL2 := 71597; -- Cosmetic - Low Poly Fire (with Sound)

DELETE FROM `conditions` WHERE `SourceEntry`=@SPELL1 AND `SourceTypeOrReferenceId`=13 AND `ConditionTypeOrReference`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,@SPELL1,18,1,@ENTRY, 'Chemical Wagon - Cosmetic - Explosion (Chemical Wagon)');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,8,0,100,0,@SPELL1,0,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Chemical Wagon - Spell Hit - Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,@SPELL2,2,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,"Chemical Wagon - Spell Hit - Cast Cosmetic - Low Poly Fire (with Sound)");
