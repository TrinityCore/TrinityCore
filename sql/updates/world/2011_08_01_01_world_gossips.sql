-- Variable
SET @GOSSIP := 21258; -- gossip_menu.entry

-- Set actual gossip for Zanza the Restless
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP+0 WHERE `entry`=15042;

-- Insert gossip menu itself
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+0 AND `text_id`=7594;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+0,7594);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+0 AND `text_id`=7595;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+0,7595);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+1 AND `text_id`=7596;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+1,7596);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+2 AND `text_id`=7597;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+2,7597);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+3 AND `text_id`=7598;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+3,7598);

-- Insert the gossip menu options, redirects to the next page which forms a short story by Zanza
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP+0,@GOSSIP+1,@GOSSIP+2);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP+0,0,0,'I think I have heard of this magic.',1,3,@GOSSIP+1,0,0,0,''),
(@GOSSIP+1,0,0,'Arcanum? That sounds very familiar.',1,3,@GOSSIP+2,0,0,0,''),
(@GOSSIP+2,0,0,'What are the components?',1,3,@GOSSIP+3,0,0,0,'');

-- Conditions for gossip menu, the 'story' Zanza tells you becomes available when you hit exalted with Zandalar Tribe.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` BETWEEN @GOSSIP+0 AND @GOSSIP+3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(14,@GOSSIP+0,7594,0,5,270,3,0,0,"Only show text_id 7594 if player is neutral with Zandalar Tribe (270)"),
(14,@GOSSIP+0,7594,1,5,270,4,0,0,"Only show text_id 7594 if player is friendly with Zandalar Tribe (270)"),
(14,@GOSSIP+0,7594,2,5,270,5,0,0,"Only show text_id 7594 if player is honored with Zandalar Tribe (270)"),
(14,@GOSSIP+0,7594,3,5,270,6,0,0,"Only show text_id 7594 if player is reveved with Zandalar Tribe (270)"),
(14,@GOSSIP+0,7595,0,5,270,7,0,0,"Only show text_id 7595 if player is exalted with Zandalar Tribe (270)"),
(15,@GOSSIP+0,0,0,5,270,7,0,0,"Only show gossip option if player is exalted with Zandalar Tribe (270)"),
(15,@GOSSIP+1,0,0,5,270,7,0,0,"Only show gossip option if player is exalted with Zandalar Tribe (270)"),
(15,@GOSSIP+2,0,0,5,270,7,0,0,"Only show gossip option if player is exalted with Zandalar Tribe (270)");
