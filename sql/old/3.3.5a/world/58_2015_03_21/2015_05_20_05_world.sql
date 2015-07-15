--
UPDATE `npc_text` SET `BroadcastTextId0`= 33761 WHERE `id`=14391;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=4007;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4007,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4007,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4007,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4007 AND `text_id` IN (4999, 5000);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4007, 4999), (4007, 5000);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4007;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4007, 4999, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4007, 5000, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4007, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4007, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4007, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4534;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4534,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4534,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4534,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4534 AND `text_id` IN (563, 562);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4534, 563), (4534, 562);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4534;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4534, 562, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is a Mage', 0),
(14, 4534, 563, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is not a Mage', 1),
(15, 4534, 0, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0),
(15, 4534, 1, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0),
(15, 4534, 2, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4092;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4092,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4092,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4092,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4092 AND `text_id` IN (4867, 4993);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4092, 4867), (4092, 4993);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4621;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4621,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4621,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4621,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4621 AND `text_id` IN (4994, 4993);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4621, 4994), (4621, 4993);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4621;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4621, 4994, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4621, 4993, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4621, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4621, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4621, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4694;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4694,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4694,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4694,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4694 AND `text_id` IN (6160, 4993);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4694, 6160), (4694, 4993);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4694;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4694, 6160, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4694, 4993, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4694, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4694, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4694, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4826;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4826,0,3,"I would like training.",5,16,0,0,0,0,'', 2603);
DELETE FROM `gossip_menu` WHERE `Entry`=4826 AND `text_id` IN (5884, 5883);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4826, 5884), (4826, 5883);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=4826;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4826, 5884, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is a Mage', 0),
(14, 4826, 5883, 0, 15, 128, 0, 0, 0, '', 'Show gossip text if player is not a Mage', 1),
(15, 4826, 0, 0, 15, 128, 0, 0, 0, '', 'Show gossip option if player is a Mage', 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4674;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(4674,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(4674,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(4674,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762);
DELETE FROM `gossip_menu` WHERE `Entry`=4674 AND `text_id` IN (4999, 5000);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (4674, 4999), (4674, 5000);

UPDATE `creature_template` SET `gossip_menu_id`= 4007 WHERE `entry`=1231;
UPDATE `creature_template` SET `gossip_menu_id`= 4534 WHERE `entry`=3047;
UPDATE `creature_template` SET `gossip_menu_id`= 4092 WHERE `entry`=3963;
UPDATE `creature_template` SET `gossip_menu_id`= 4621 WHERE `entry`=4138;
UPDATE `creature_template` SET `gossip_menu_id`= 4694 WHERE `entry`=5501;
UPDATE `creature_template` SET `gossip_menu_id`= 4826 WHERE `entry`=5958;
UPDATE `creature_template` SET `gossip_menu_id`= 4092 WHERE `entry`=8308;
UPDATE `creature_template` SET `gossip_menu_id`= 4674 WHERE `entry`=10930;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (4092, 4674);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 4092, 4867, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4092, 4993, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4092, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4092, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4092, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(14, 4674, 4999, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 4674, 5000, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1),
(15, 4674, 0, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4674, 1, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0),
(15, 4674, 2, 0, 15, 4, 0, 0, 0, '', 'Show gossip option if player is a hunter', 0);
