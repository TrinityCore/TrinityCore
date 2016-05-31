-- Lost Drakkari Spirit SAI
SET @ENTRY := 29129;
SET @AURA := 17327;
SET @SPELL1 := 37361;
SET @SPELL2 := 24050;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,@AURA,0,2000,2000,11,@AURA,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lost Drakkari Spirit - Aura Spirit Particles not present - Add Aura Spirit Particles'),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lost Drakkari Spirit - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lost Drakkari Spirit - On Aggro - Set Phase 1'),
(@ENTRY,0,3,0,0,1,100,0,0,0,1000,1000,11,@SPELL1,1,0,0,0,0,2,0,0,0,0,0,0,0,'Lost Drakkari Spirit - Combat - Cast Arcane Bolt (Phase 1)'),
(@ENTRY,0,4,5,3,1,100,0,15,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lost Drakkari Spirit - Mana at 15% - Allow combat movement (Phase 1)'),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lost Drakkari Spirit - Mana at 15% - Set phase 2 (Phase 1)'),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lost Drakkari Spirit - At 35 yards - Allow combat movement (Phase 1)'),
(@ENTRY,0,7,0,9,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lost Drakkari Spirit - Below 15 yards - Prevent combat movement (Phase 1)'),
(@ENTRY,0,8,0,3,2,100,0,100,30,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lost Drakkari Spirit - Mana above 30% - Set phase 1 (Phase 2)'),
(@ENTRY,0,9,0,0,0,100,0,10000,16000,15000,18000,11,@SPELL2,1,0,0,0,0,2,0,0,0,0,0,0,0,'Lost Drakkari Spirit - Combat - Cast Spirit Burst');
