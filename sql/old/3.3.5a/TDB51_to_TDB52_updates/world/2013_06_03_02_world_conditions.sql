-- Gossip Condition for Ultham Ironhorn "Dwarf riding trainer"
SET @GOSSIP  := 4014;
SET @TEXTYES := 4871;
SET @TEXTNO  := 5858;
SET @FACTION := 47;
SET @RACE    := 4;
SET @NOTRACE := 1787;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Dwarf'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Ironforge'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Dwarf'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Ironforge'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Dwarf'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Ironforge');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=4772;

-- Gossip Condition for Velma Warnam "Forsaken riding trainer"
SET @GOSSIP  := 4015;
SET @TEXTYES := 4873;
SET @TEXTNO  := 5859;
SET @FACTION := 68;
SET @RACE    := 16;
SET @NOTRACE := 1775;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Forsaken'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Undercity'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Forsaken'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Undercity'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Forsaken'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Undercity');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Benjy Featherwhistle "Gnomeregan riding trainer"
SET @GOSSIP  := 4016;
SET @TEXTYES := 4878;
SET @TEXTNO  := 5860;
SET @FACTION := 54;
SET @RACE    := 64;
SET @NOTRACE := 1727;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Gnome'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Gnomeregan'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Gnome'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Gnomeregan'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Gnome'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Gnomeregan');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Randel Hunter "Human riding trainer"
SET @GOSSIP  := 4018;
SET @TEXTYES := 4876;
SET @TEXTNO  := 5861;
SET @FACTION := 72;
SET @RACE    := 1;
SET @NOTRACE := 1790;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Human'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Stormwind'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Human'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Stormwind'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Human'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Stormwind');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Jartsam "Night Elf riding trainer"
SET @GOSSIP  := 4019;
SET @TEXTYES := 4877;
SET @TEXTNO  := 5862;
SET @FACTION := 69;
SET @RACE    := 8;
SET @NOTRACE := 1783;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Night Elf'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Darnassus'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Night Elf'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Darnassus'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Night Elf'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Darnassus');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Kildar "Orc riding trainer"
SET @GOSSIP  := 4020;
SET @TEXTYES := 4879;
SET @TEXTNO  := 5863;
SET @FACTION := 76;
SET @RACE    := 2;
SET @NOTRACE := 1789;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is an Orc'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Orgrimmar'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not an Orc'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Orgrimmar'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is an Orc'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Orgrimmar');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Kar Stormsinger "Tauren riding trainer"
SET @GOSSIP  := 4021;
SET @TEXTYES := 4874;
SET @TEXTNO  := 5864;
SET @FACTION := 81;
SET @RACE    := 32;
SET @NOTRACE := 1759;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Tauren'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Thunder Bluff'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Tauren'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Thunder Bluff'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Tauren'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Thunder Bluff');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Xar'Ti  "Troll riding trainer"
SET @GOSSIP  := 4022;
SET @TEXTYES := 4875;
SET @TEXTNO  := 5865;
SET @FACTION := 530;
SET @RACE    := 128;
SET @NOTRACE := 1663;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Troll'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Darkspear Trolls'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Troll'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Darkspear Trolls'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Troll'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Darkspear Trolls');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=7953;

-- Gossip Condition for Perascamin  "Blood Elf riding trainer"
SET @GOSSIP  := 8275;
SET @TEXTYES := 10308;
SET @TEXTNO  := 10310;
SET @FACTION := 911;
SET @RACE    := 512;
SET @NOTRACE := 1279;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Blood Elf'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Silvermoon City'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Blood Elf'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Silvermoon City'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Blood Elf'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Silvermoon City');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=16280;

-- Gossip Condition for Aalun "Draenei riding trainer"
SET @GOSSIP  := 8553;
SET @TEXTYES := 10792;
SET @TEXTNO  := 10705;
SET @FACTION := 930;
SET @RACE    := 1024;
SET @NOTRACE := 767;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTYES,0,16,@RACE,0,0,0,'','Show gossip text if player is a Draenei'),
(14,@GOSSIP,@TEXTYES,1,5,@FACTION,128,0,0,'','Show gossip text if player is Exalted with Exodar'),
(14,@GOSSIP,@TEXTNO,0,16,@NOTRACE,0,0,0,'','Show gossip text if player is not a Draenei'),
(14,@GOSSIP,@TEXTNO,0,5,@FACTION,127,0,0,'','Show gossip text if player is Not Exalted with Exodar'),
(15,@GOSSIP,0,0,16,@RACE,0,0,0,'','Show gossip option if player is a Draenei'),
(15,@GOSSIP,0,1,5,@FACTION,128,0,0,'','Show gossip option if player is a Exalted with Exodar');
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTYES;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTYES);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTNO;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXTNO);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"I seek training to ride a steed.",5,16,0,0,0,0,'');

-- Gossip Condition for Olrokk "Riding trainer"
SET @GOSSIP  := 8628;
SET @TEXT    := 10817;
-- Add Any Missing Gossip Menu item
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXT;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,@TEXT);
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE menu_id=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,3,"Train me.",5,16,0,0,0,0,'');
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=20500;
