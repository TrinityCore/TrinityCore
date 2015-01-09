-- UPDATE Blood Knight Dawnstar Gossip
SET @ENTRY    := 17832;
SET @GOSSIPID := 7486;
SET @TEXTID   := 9070;
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIPID WHERE `entry`=@ENTRY;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIPID AND `text_id`=@TEXTID;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIPID,@TEXTID);
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIPID) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIPID,0,0, 'Take Blood Knight Insignia',1,1,0,0,0,0, '');
-- Gossip option Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIPID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIPID,0,0,9,9692,0,0,0,'','Show gossip option if player has quest 9692 but not complete'),
(15,@GOSSIPID,0,0,26,24226,1,0,0,'','Show gossip option if player does not have item 24226');
-- SAI for Blood Knight Dawnstar
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIPID,0,0,0,56,24226,1,0,0,0,0,7,0,0,0,0,0,0,0,'Blood Knight Dawnstar - On Gossip option select - Create Blood Knight Insignia'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Blood Knight Dawnstar - On Gossip option select - Close Gossip');
