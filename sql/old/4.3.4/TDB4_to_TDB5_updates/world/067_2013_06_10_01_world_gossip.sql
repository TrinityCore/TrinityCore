-- Gossip for Quarter Master Miranda Breechlock
SET @GOSSIP := 7208;
SET @TEXT := 8498;
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXT;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXT);
DELETE FROM `gossip_menu` WHERE `entry`=7209 AND `text_id`=8499;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7209,8499);
DELETE FROM `gossip_menu` WHERE `entry`=7210 AND `text_id`=8500;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7210,8500);
DELETE FROM `gossip_menu` WHERE `entry`=7212 AND `text_id`=8502;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7212,8502);
DELETE FROM `gossip_menu` WHERE `entry`=7213 AND `text_id`=8503;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7213,8503);

-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,0,"Friendly",1,1,7213,0,0,0,''),
(@GOSSIP,1,0,"Honored",1,1,7209,0,0,0,''),
(@GOSSIP,2,0,"Revered",1,1,7210,0,0,0,''),
(@GOSSIP,3,0,"Exalted",1,1,7212,0,0,0,'');

UPDATE `gossip_menu_option` SET `action_menu_id`=7208 WHERE `menu_id`=3461 AND `id`=2;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` =3461 AND `SourceEntry` IN (1,2);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15,3461,1,0,0,8,0,5401,0,0,0,0,'','I would like to buy from you. - Must have completed Argent Dawn Commission Quest Alliance'),
(15,3461,1,0,1,8,0,5503,0,0,0,0,'','I would like to buy from you. - Must have completed Argent Dawn Commission Quest Mage'),
(15,3461,1,0,2,8,0,5405,0,0,0,0,'','I would like to buy from you. - Must have completed Argent Dawn Commission Quest Horde'),
(15,3461,2,0,0,8,0,5401,0,0,0,0,'','Miranda, could you please tell me the insignia cost of items - Must have completed Argent Dawn Commission Quest Alliance'),
(15,3461,2,0,1,8,0,5503,0,0,0,0,'','Miranda, could you please tell me the insignia cost of items - Must have completed Argent Dawn Commission Quest Mage'),
(15,3461,2,0,2,8,0,5405,0,0,0,0,'','Miranda, could you please tell me the insignia cost of items - Must have completed Argent Dawn Commission Quest Horde');
