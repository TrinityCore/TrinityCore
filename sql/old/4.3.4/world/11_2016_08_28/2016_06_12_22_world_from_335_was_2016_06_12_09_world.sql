--
SET @GUID := -65109;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18211;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,18211,0,10,0,0,0,0,"Murkblood Brute - On Just Died - Set Data 0 1"),
(@GUID,0,1,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Brute - On Data Set 0 1 - Set Event Phase 1"),
(@GUID,0,2,0,6,1,100,0,0,0,0,0,82,2,0,0,0,0,0,9,18210,0,10,0,0,0,0,"Murkblood Brute - On Just Died - Add Npc Flag Questgiver (Phase 1)"),
(@GUID,0,3,0,1,0,100,0,0,0,500,1000,81,0,0,0,0,0,0,9,18210,0,10,0,0,0,0,"Murkblood Brute - On Respawn - Remove Npc Flag Questgiver");

SET @GUID := -65110;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,18211,0,10,0,0,0,0,"Murkblood Brute - On Just Died - Set Data 0 1"),
(@GUID,0,1,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Brute - On Data Set 0 1 - Set Event Phase 1"),
(@GUID,0,2,0,6,1,100,0,0,0,0,0,82,2,0,0,0,0,0,9,18210,0,10,0,0,0,0,"Murkblood Brute - On Just Died - Add Npc Flag Questgiver (Phase 1)"),
(@GUID,0,3,0,1,0,100,0,0,0,500,1000,81,0,0,0,0,0,0,9,18210,0,10,0,0,0,0,"Murkblood Brute - On Respawn - Remove Npc Flag Questgiver");


SET @GUID := -28663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18203;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,18203,0,10,0,0,0,0,"Murkblood Raider - On Just Died - Set Data 0 1"),
(@GUID,0,1,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Raider - On Data Set 0 1 - Set Event Phase 1"),
(@GUID,0,2,0,6,1,100,0,0,0,0,0,82,2,0,0,0,0,0,9,18209,0,10,0,0,0,0,"Murkblood Raider - On Just Died - Add Npc Flag Questgiver (Phase 1)"),
(@GUID,0,3,0,1,0,100,0,0,0,500,1000,81,0,0,0,0,0,0,9,18209,0,10,0,0,0,0,"Murkblood Raider - On Respawn - Remove Npc Flag Questgiver");

SET @GUID := -28664;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,18203,0,10,0,0,0,0,"Murkblood Raider - On Just Died - Set Data 0 1"),
(@GUID,0,1,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Raider - On Data Set 0 1 - Set Event Phase 1"),
(@GUID,0,2,0,6,1,100,0,0,0,0,0,82,2,0,0,0,0,0,9,18209,0,10,0,0,0,0,"Murkblood Raider - On Just Died - Add Npc Flag Questgiver (Phase 1)"),
(@GUID,0,3,0,1,0,100,0,0,0,500,1000,81,0,0,0,0,0,0,9,18209,0,10,0,0,0,0,"Murkblood Raider - On Respawn - Remove Npc Flag Questgiver");
