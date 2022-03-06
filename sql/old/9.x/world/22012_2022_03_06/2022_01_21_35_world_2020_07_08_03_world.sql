--
SET @ID := 5391;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Script - Say Line 2"),
(@ID*100+0,9,4,0,0,0,100,0,3000,3000,0,0,0,9,0,0,0,0,0,0,20,37118,0,0,0,0,0,0,0,"Galen Goodward - On Script - Activate Closest Gameobject 'Galen's Cage'"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,53,0,5391,0,0,0,2,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Start Waypoint"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Remove Flags Immune To Players"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Set Faction 250");

SET @ID := 16295;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Remove NPC Flags Gossip & Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,2000,2000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Remove Flag Standstate Kneel"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,9,0,0,0,0,0,0,20,181152,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Activate Closest Gameobject (Cage)"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 0"),
(@ID*100+0,9,6,0,0,0,100,0,2000,2000,0,0,0,53,0,16295,0,0,0,2,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Start Waypoint"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,2,1603,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Faction 1603");

SET @ID := 17969;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Kayra Longmane - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kayra Longmane - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kayra Longmane - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,3000,3000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kayra Longmane - On Script - Remove Flag Standstate Kneel"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,53,0,17969,0,0,0,2,1,0,0,0,0,0,0,0,0,"Kayra Longmane - On Script - Start Waypoint"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kayra Longmane - On Script - Set Faction 495");
