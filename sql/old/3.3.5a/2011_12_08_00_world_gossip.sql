-- fixing conflict in number of gossip_menu_option.menu_id -- compare 2011_10_23_04_world_sai.sql with 2011_10_23_07_world_sai.sql
SET @ENTRY := 18417;
SET @OLDGOSSIP := 21304;
SET @NEWGOSSIP := 21312;
SET @QUEST_PUPIL := 10646;
-- Fixing smart_scripts
UPDATE `smart_scripts` SET `event_param1`=@NEWGOSSIP WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2 AND `action_param1`=@QUEST_PUPIL;
-- Fixing gossip_menu_option
UPDATE `gossip_menu_option` SET `action_menu_id`=@NEWGOSSIP WHERE `menu_id`=@OLDGOSSIP+5;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@NEWGOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@NEWGOSSIP,0,0,"There was something else I wanted to ask you, Altruis.",1,3,@OLDGOSSIP+0);
