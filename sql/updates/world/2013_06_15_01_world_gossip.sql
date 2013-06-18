-- Arathandris Silversky
UPDATE `creature_template` SET `gossip_menu_id`=2208 WHERE `entry` IN (9528);
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=2208 AND `text_id`=2844; -- Before Quest 4101
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2208,2844);
DELETE FROM `gossip_menu` WHERE `entry`=2208 AND `text_id`=2845; -- After Quest 4101
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2208,2845);
DELETE FROM `gossip_menu` WHERE `entry`=2208 AND `text_id`=2848; -- If Horde
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2208,2848);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=2208;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(2208,0,0,"I need a Cenarion beacon.",1,1,0,0,0,0,''),
(2208,1,0,"What plants are in Felwood that might be corrupted?",1,1,0,0,0,0,'');
-- Add option conditions for gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup` IN (2208);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,2208,2844,0,8,3781,0,0,1,0,'','Arathandris Silversky - Show gossip text if player has not been rewarded quest 4101'),
(14,2208,2845,0,8,3781,0,0,0,0,'','Arathandris Silversky - Show gossip text if player has been rewarded quest 4101'),
(14,2208,2848,0,6,67,0,0,0,0,'','Arathandris Silversky - Show gossip text if player is horde');
-- Add option conditions for gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (2208);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,2208,0,0,8,3781,0,0,0,0,'','Arathandris Silversky - Show gossip option if player has been rewarded quest 4101'),
(15,2208,0,1,2,11511,1,1,1,0,'','Arathandris Silversky - Show gossip option if player does not have Cenarion Beacon'),
(15,2208,1,0,8,3781,0,0,0,0,'','Arathandris Silversky - Show gossip option if player has been rewarded quest 4101');

-- Maybess Riverbreeze
UPDATE `creature_template` SET `gossip_menu_id`=21400 WHERE `entry` IN (9529);
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=21400 AND `text_id`=2842; -- Before Quest 4102
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21400,2842);
DELETE FROM `gossip_menu` WHERE `entry`=21400 AND `text_id`=2843; -- After Quest 4102
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21400,2843);
DELETE FROM `gossip_menu` WHERE `entry`=21400 AND `text_id`=2849; -- If Alliance
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (21400,2849);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=21400;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(21400,0,0,"I need a Cenarion beacon.",1,1,0,0,0,0,''),
(21400,1,0,"What plants are in Felwood that might be corrupted?",1,1,0,0,0,0,'');
-- Add option conditions for gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (21400);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,21400,0,0,8,3781,0,0,0,0,'','Maybess Riverbreeze - Show gossip option if player has been rewarded quest 4102'),
(15,21400,0,1,2,11511,1,1,1,0,'','Maybess Riverbreeze - Show gossip option if player does not have Cenarion Beacon'),
(15,21400,1,0,8,3781,0,0,0,0,'','Maybess Riverbreeze - Show gossip option if player has been rewarded quest 4102');
