-- XXXXXXXXXXXXXXXXXXXXX
-- X   Mage Trainers   X
-- XXXXXXXXXXXXXXXXXXXXX

-- Gossip Condition for Mage Trainers
SET @GOSSIP := 63; -- http://www.wowhead.com/npc=2128 "Tirisfal Glades" http://www.wowhead.com/npc=23103 "Undercity"
SET @TEXTYES := 562;
SET @TEXTNO := 563;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=23103;

SET @GOSSIP := 64; -- http://www.wowhead.com/npc=5880 "Durotar"
SET @TEXTYES := 564;
SET @TEXTNO := 565;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4484; -- http://www.wowhead.com/npc=5498 "Stormwind City"
SET @TEXTYES := 538;
SET @TEXTNO := 539;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4485; -- http://www.wowhead.com/npc=5497 "Stormwind City"
SET @TEXTYES := 538;
SET @TEXTNO := 539;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4486; -- http://www.wowhead.com/npc=331 "Stormwind City"
SET @TEXTYES := 538;
SET @TEXTNO := 539;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4517; -- http://www.wowhead.com/npc=7311 "Orgrimmar"
SET @TEXTYES := 564;
SET @TEXTNO := 565;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4518; -- http://old.wowhead.com/npc=5883 "Orgrimmar"
SET @TEXTYES := 564;
SET @TEXTNO := 565;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4519; -- http://old.wowhead.com/npc=5885 "Orgrimmar"
SET @TEXTYES := 564;
SET @TEXTNO := 565;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4520; -- http://old.wowhead.com/npc=5882 "Orgrimmar"
SET @TEXTYES := 564;
SET @TEXTNO := 565;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4537; -- http://www.wowhead.com/npc=4568 "Undercity"
SET @TEXTYES := 562;
SET @TEXTNO := 563;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4538; -- http://www.wowhead.com/npc=4567 "Undercity"
SET @TEXTYES := 562;
SET @TEXTNO := 563;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4539; -- http://www.wowhead.com/npc=4566 "Undercity"
SET @TEXTYES := 562;
SET @TEXTNO := 563;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4552; -- http://www.wowhead.com/npc=5144 5145,5146,7312 "Ironforge"
SET @TEXTYES := 560;
SET @TEXTNO := 561;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4651; -- http://old.wowhead.com/npc=5884 "Durotar"
SET @TEXTYES := 564;
SET @TEXTNO := 565;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4654; -- http://www.wowhead.com/npc=2124 "Tirisfal Glades"
SET @TEXTYES := 562;
SET @TEXTNO := 563;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4660; -- http://www.wowhead.com/npc=198 "Elwynn Forest"
SET @TEXTYES := 538;
SET @TEXTNO := 539;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4661; -- http://www.wowhead.com/npc=328 "Elwynn Forest"
SET @TEXTYES := 538;
SET @TEXTNO := 539;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4685; -- http://www.wowhead.com/npc=1228 "Dun Morogh"
SET @TEXTYES := 558;
SET @TEXTNO := 559;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 4686; -- http://old.wowhead.com/npc=944 "Dun Morogh"
SET @TEXTYES := 560;
SET @TEXTNO := 561;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 6648; -- 15279,16269,16651,16652,16653 "Blood elf Mage trainers"
SET @TEXTYES := 9190;
SET @TEXTNO := 9191;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 7264; -- 16500,16749,17481,17513,17514 "Draenei Mage Trainers"
SET @TEXTYES := 8589;
SET @TEXTNO := 8590;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 9990; -- http://www.wowhead.com/npc=28956 28958 "Dalaran Mage Trainers"
SET @TEXTYES := 13845;
SET @TEXTNO := 13846;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

SET @GOSSIP := 9580; -- http://www.wowhead.com/npc=27704 "Dustwallow Marsh"
SET @TEXTYES := 12929;
SET @TEXTNO := 12930;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=27704;

-- Gossip Condition for Mage Trainers
SET @GOSSIP := 7366; -- http://www.wowhead.com/npc=17105 "Darnassus"
SET @TEXTYES := 8799;
SET @TEXTNO := 8800;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=17105;

-- Gossip Condition for Mage Trainers
SET @GOSSIP := 4535; -- http://www.wowhead.com/npc=3049 "Thunder Bluff"
SET @TEXTYES := 562;
SET @TEXTNO := 663;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage'),
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in mage training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=3049;

-- XXXXXXXXXXXXXXXXXXXXXX
-- X  Warlock Trainers  X
-- XXXXXXXXXXXXXXXXXXXXXX

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 1503;
SET @TEXTYES := 2175;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 1522;
SET @TEXTYES := 2193;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 2381;
SET @TEXTYES := 2193;
SET @TEXTNO := 5723;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 2383;
SET @TEXTYES := 5714;
SET @TEXTNO := 5715;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 2384;
SET @TEXTYES := 2193;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4503;
SET @TEXTYES := 5693;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4504;
SET @TEXTYES := 5693;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4505;
SET @TEXTYES := 5693;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4566;
SET @TEXTYES := 2193;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4567;
SET @TEXTYES := 2193;
SET @TEXTNO := 5723;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4603;
SET @TEXTYES := 2193;
SET @TEXTNO := 5723;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4604;
SET @TEXTYES := 2193;
SET @TEXTNO := 5723;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4609;
SET @TEXTYES := 5719;
SET @TEXTNO := 5720;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I submit myself for further training my master.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4610;
SET @TEXTYES := 5719;
SET @TEXTNO := 5720;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I submit myself for further training, my master.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=4565;

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4641;
SET @TEXTYES := 5714;
SET @TEXTNO := 5715;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4643;
SET @TEXTYES := 5714;
SET @TEXTNO := 5715;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4655;
SET @TEXTYES := 5719;
SET @TEXTNO := 5720;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I submit myself for further training my master.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4656;
SET @TEXTYES := 5719;
SET @TEXTNO := 5720;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I submit myself for further training my master.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4667;
SET @TEXTYES := 2193;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4681;
SET @TEXTYES := 2193;
SET @TEXTNO := 5723;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4682;
SET @TEXTYES := 2193;
SET @TEXTNO := 5722;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 6628;
SET @TEXTYES := 7882;
SET @TEXTNO := 7903;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 7437;
SET @TEXTYES := 9006;
SET @TEXTNO := 7903;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I am interested in warlock training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"Learn about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 7566;
SET @TEXTYES := 9184;
SET @TEXTNO := 9185;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"It is a greater knowledge of the ways of the warlock that I crave.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warlock Trainers
SET @GOSSIP := 4642;
SET @TEXTYES := 5714;
SET @TEXTNO := 5715;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,256,0,0,0,'','Show gossip text if player is a Warlock'),
(14,@GOSSIP,@TEXTNO,0,15,1279,0,0,0,'','Show gossip text if player is not a Warlock');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"It is a greater knowledge of the ways of the warlock that I crave.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=988;

-- XXXXXXXXXXXXXXXXXXXXXX
-- X  Paladin Trainers  X
-- XXXXXXXXXXXXXXXXXXXXXX

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 2304;
SET @TEXTYES := 2999;
SET @TEXTNO := 3975;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=5149;

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4556;
SET @TEXTYES := 3974;
SET @TEXTNO := 3975;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=5148;

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4557;
SET @TEXTYES := 3974;
SET @TEXTNO := 3975;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=5147;

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4469;
SET @TEXTYES := 3976;
SET @TEXTNO := 3977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4470;
SET @TEXTYES := 3976;
SET @TEXTNO := 3977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4471;
SET @TEXTYES := 3976;
SET @TEXTNO := 3977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4662;
SET @TEXTYES := 3976;
SET @TEXTNO := 3977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=8140;

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4463;
SET @TEXTYES := 3976;
SET @TEXTNO := 3977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4464;
SET @TEXTYES := 3976;
SET @TEXTNO := 3977;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4477;
SET @TEXTYES := 3974;
SET @TEXTNO := 3975;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 4478;
SET @TEXTYES := 3974;
SET @TEXTNO := 3975;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 7260;
SET @TEXTYES := 8582;
SET @TEXTNO := 8584;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Paladin Trainers
SET @GOSSIP := 8111;
SET @TEXTYES := 10040;
SET @TEXTNO := 10041;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,2,0,0,0,'','Show gossip text if player is a Paladin'),
(14,@GOSSIP,@TEXTNO,0,15,1533,0,0,0,'','Show gossip text if player is not a Paladin');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I would like to train further in the ways of the Light.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- XXXXXXXXXXXXXXXXXXXXXX
-- X  Warrior Trainers  X
-- XXXXXXXXXXXXXXXXXXXXXX

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 523;
SET @TEXTYES := 1040;
SET @TEXTNO := 4985;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=985;

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 655;
SET @TEXTYES := 1218;
SET @TEXTNO := 4973;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=3408;

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 656;
SET @TEXTYES := 1219;
SET @TEXTNO := 4984;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4091;
SET @TEXTYES := 4992;
SET @TEXTNO := 4993;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"Yes. I have.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4475;
SET @TEXTYES := 1216;
SET @TEXTNO := 5721;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4481;
SET @TEXTYES := 1216;
SET @TEXTNO := 5721;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4482;
SET @TEXTYES := 1216;
SET @TEXTNO := 5721;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4509;
SET @TEXTYES := 1040;
SET @TEXTNO := 4985;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4511;
SET @TEXTYES := 1040;
SET @TEXTNO := 4985;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4525;
SET @TEXTYES := 1218;
SET @TEXTNO := 4973;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4526;
SET @TEXTYES := 1218;
SET @TEXTNO := 4973;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4527;
SET @TEXTYES := 1218;
SET @TEXTNO := 4973;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4546;
SET @TEXTYES := 1219;
SET @TEXTNO := 4984;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4547;
SET @TEXTYES := 1219;
SET @TEXTNO := 4984;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4548;
SET @TEXTYES := 1219;
SET @TEXTNO := 4984;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4568;
SET @TEXTYES := 4989;
SET @TEXTNO := 4988;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4569;
SET @TEXTYES := 1215;
SET @TEXTNO := 5724;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4570;
SET @TEXTYES := 1215;
SET @TEXTNO := 5724;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4578;
SET @TEXTYES := 1217;
SET @TEXTNO := 5725;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=4089;

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4579;
SET @TEXTYES := 1217;
SET @TEXTNO := 5725;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4581;
SET @TEXTYES := 1217;
SET @TEXTNO := 5725;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4645;
SET @TEXTYES := 1218;
SET @TEXTNO := 4973;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4649;
SET @TEXTYES := 1216;
SET @TEXTNO := 5721;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4650;
SET @TEXTYES := 1216;
SET @TEXTNO := 5721;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4653;
SET @TEXTYES := 1219;
SET @TEXTNO := 4984;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=2119;

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4683;
SET @TEXTYES := 1215;
SET @TEXTNO := 5724;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4684;
SET @TEXTYES := 1215;
SET @TEXTNO := 5724;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4696;
SET @TEXTYES := 1217;
SET @TEXTNO := 5725;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 4697;
SET @TEXTYES := 1217;
SET @TEXTNO := 5725;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Warrior Trainers
SET @GOSSIP := 7263;
SET @TEXTYES := 8587;
SET @TEXTNO := 8588;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1,0,0,0,'','Show gossip text if player is a Warrior'),
(14,@GOSSIP,@TEXTNO,0,15,1534,0,0,0,'','Show gossip text if player is not a Warrior');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I require warrior training.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- XXXXXXXXXXXXXXXXXXXXXX
-- X   Druid Trainers   X
-- XXXXXXXXXXXXXXXXXXXXXX

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 1403;
SET @TEXTYES := 4786;
SET @TEXTNO := 2037;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 3921;
SET @TEXTYES := 4774;
SET @TEXTNO := 4775;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 3924;
SET @TEXTYES := 4782;
SET @TEXTNO := 4781;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 3925;
SET @TEXTYES := 4784;
SET @TEXTNO := 4783;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=9465;

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 3926;
SET @TEXTYES := 4786;
SET @TEXTNO := 4785;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4507;
SET @TEXTYES := 4784;
SET @TEXTNO := 4783;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=5506;

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4508;
SET @TEXTYES := 4784;
SET @TEXTNO := 4783;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4571;
SET @TEXTYES := 4782;
SET @TEXTNO := 4781;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4605;
SET @TEXTYES := 5716;
SET @TEXTNO := 5717;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4606;
SET @TEXTYES := 5716;
SET @TEXTNO := 5717;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4607;
SET @TEXTYES := 5716;
SET @TEXTNO := 5717;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4687;
SET @TEXTYES := 4784;
SET @TEXTNO := 4783;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4688;
SET @TEXTYES := 4784;
SET @TEXTNO := 4783;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=3597;

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 7567;
SET @TEXTYES := 9195;
SET @TEXTNO := 9194;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 4646;
SET @TEXTYES := 5716;
SET @TEXTNO := 5717;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=8142;

-- Gossip Condition for Druid Trainers
SET @GOSSIP := 7567;
SET @TEXTYES := 9195;
SET @TEXTNO := 9194;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,15,1024,0,0,0,'','Show gossip text if player is a Druid'),
(14,@GOSSIP,@TEXTNO,0,15,511,0,0,0,'','Show gossip text if player is not a Druid');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training as a druid.",5,16,0,0,0,0,''),
(@GOSSIP,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,''),
(@GOSSIP,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'');

