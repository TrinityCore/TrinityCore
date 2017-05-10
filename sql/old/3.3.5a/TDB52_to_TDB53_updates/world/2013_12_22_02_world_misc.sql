-- Axle SAI
SET @ENTRY := 23995;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,23995,1,0,0,0,1,0,0,0,0,0,0,0,"Axle - On Respawn - Start Waypoint"),
(@ENTRY,0,1,2,40,0,100,0,4,23995,0,0,54,24000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Axle - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,2399500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Axle - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,3,4,40,0,100,0,8,23995,0,0,54,140000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Axle - On Waypoint 8 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,23995,0,0,0,0,0,1,0,0,0,0,0,0,0,"Axle - On Waypoint 8 Reached - Set Orientation Home Position"),
(@ENTRY,0,5,6,62,0,100,0,9123,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Axle - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0,"Axle - On Gossip Option 0 Selected - Invoker Cast 'Trick or Treat'");

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=9123);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(9123,0,0, 'Trick or Treat!',1,1,0,0,0,0, ''),
(9123,2,5, 'Make this inn your home.',8,65536,0,0,0,0, ''),
(9123,3,1, 'Let me browse your goods.',3,128,0,0,0,0, '');

-- Add condition for Gossip Option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9123;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9123, 0, 0, 0, 1, 0, 24755, 0, 0, 1, 0, 0, '', 'Gossip Option - Player must not have aura Tricked or Treated'),
(15, 9123, 0, 0, 0, 12, 0, 12, 0, 0, 0, 0, 0, '', 'Gossip Option - Hallow''s End event must be active');
