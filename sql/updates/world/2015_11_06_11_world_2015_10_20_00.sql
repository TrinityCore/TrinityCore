-- Gryphoneer Leafbeard - Gossip
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=8100 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8100, 0, 0, 'Send me to Shatter Point!', 17935, 1, 1, 0, 0, 0, 0, NULL, 0);

-- Gryphoneer Leafbeard SAI
SET @ENTRY := 20236;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,8100,0,0,0,11,35066,2,0,0,0,0,7,0,0,0,0,0,0,0,"Gryphoneer Leafbeard - On Gossip Option 0 Selected - Cast 'Taxi - Hellfire Peninsula - Beach Head to Shatter Point'"),
(@ENTRY,0,1,0,61,0,100,0,8100,0,0,0,72,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gryphoneer Leafbeard - On Gossip Option 0 Selected - Close Gossip");
