--
SET @MARKER1 := 20473; -- Surveying Marker One
SET @MARKER2 := 20475; -- Surveying Marker Two
SET @MARKER3 := 20476; -- Surveying Marker Three

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@MARKER1,@MARKER2,@MARKER3) AND `source_type`=0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry IN(@MARKER1,@MARKER2,@MARKER3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MARKER1,0,0,0,8,0,100,0,35246,0,0,0,33,@MARKER1,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Surveying Marker One - On Spellhit - Quest Credit"),
(@MARKER2,0,0,0,8,0,100,0,35246,0,0,0,33,@MARKER2,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Surveying Marker Two - On Spellhit - Quest Credit"),
(@MARKER3,0,0,0,8,0,100,0,35246,0,0,0,33,@MARKER3,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Surveying Marker Three - On Spellhit - Quest Credit");
