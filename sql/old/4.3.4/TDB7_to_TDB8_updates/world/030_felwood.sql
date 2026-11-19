-- Hanah Southsong SAI
SET @ENTRY := 43073;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,12428,1,0,0,11,90126,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hanah Southsong - Gossip Option Select - Cast 'Taxi: Whisperwind Grove to Irontree Clearing"),
(@ENTRY,0,1,0,62,0,100,0,12428,2,0,0,11,90155,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hanah Southsong - Gossip Option Select - Cast 'Taxi: Whisperwind Grove to Talonbranch Glade'");

-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id`=12428;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(12428, 0, 2, 'I need a ride.', 0, 0, ''),
(12428, 1, 0, 'I''ve got a ride to Irontree Clearing waiting for me on behalf of Fez Hobnob.', 0, 0, ''), -- Requires quest 28372 active
(12428, 2, 0, 'I have a ride to Talonbranch Glade courtesy of James Hallow.', 0, 0, ''); -- Requires quest 28381 active
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=3409, `option_id`=4, `npc_option_npcflag`=8192 WHERE `menu_id`=12428 AND `id`=0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=48673, `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=12428 AND `id` IN (1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=48727, `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id`=12428 AND `id` IN (2);
