-- Add SmartAI for Quel'dorei Magewraith
SET @ENTRY := 17612;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - On reset - Prevent combat movement'),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - On aggro - Set phase 1'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,11921,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - On aggro - Cast Fireball'),
(@ENTRY,0,3,0,9,1,100,0,0,40,4000,5000,11,11921,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Combat - Cast Fireball (phase 1)'),
(@ENTRY,0,4,0,9,1,100,0,0,40,9000,13000,11,31595,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Combat - Cast Arcant Bolt (phase 1)'),
(@ENTRY,0,5,6,3,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Mana at 15% - Allow combat movement'),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Mana at 15% - Set phase 2'),
(@ENTRY,0,7,0,9,1,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - At 35 yards - Allow combat movement (phase 1)'),
(@ENTRY,0,8,0,9,1,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - At 15 yards - Prevent combat movement (phase 1)'),
(@ENTRY,0,9,0,9,1,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - At 5 yards - Allow combat movement (phase 1)'),
(@ENTRY,0,10,0,3,2,100,1,20,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Mana at 20% - Set phase 1 (phase 2)'),
(@ENTRY,0,11,0,0,0,100,0,3000,6000,7000,11000,11,31604,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Combat - Cast Arcant Weakness'),
(@ENTRY,0,12,0,9,0,100,0,0,30,16000,20000,11,11436,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Combat - Cast Slow'),
(@ENTRY,0,13,0,0,0,100,0,11000,18000,11000,18000,11,31596,4,0,0,0,0,2,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - Combat - Cast Counterspell'),
(@ENTRY,0,14,0,6,0,100,1,0,0,0,0,15,9595,0,0,0,0,0,16,0,0,0,0,0,0,0, 'Quel''dorei Magewraith - On death - Complete quest 9595');
