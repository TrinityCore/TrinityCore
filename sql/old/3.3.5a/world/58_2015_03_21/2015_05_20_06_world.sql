--
DELETE FROM `gossip_menu_option` WHERE `menu_id`=21221;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`, `OptionBroadcastTextID`)VALUES
(21221,0,3,"I would like training.",5,16,0,0,0,0,'', 2603),
(21221,1,0,"I wish to unlearn my talents.",16,16,4461,0,0,0,'', 8271),
(21221,2,0,"I wish to know about Dual Talent Specialization.",1,1,10371,0,0,0,'',33762 );
DELETE FROM `gossip_menu` WHERE `Entry`=21221 AND `text_id`=4793;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (21221, 4793);
UPDATE `npc_text` SET `BroadcastTextId0`=3275 WHERE `id`=1124;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=21221;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, 21221, 1124, 0, 15, 8, 0, 0, 0, '', 'Show gossip text if player is a Rogue'),
(14, 21221, 4793, 0, 15, 1527, 0, 0, 0, '', 'Show gossip text if player is not a Rogue'),
(15, 21221, 0, 0, 15, 8, 0, 0, 0, '', 'Show gossip option if player is a rogue'),
(15, 21221, 1, 0, 15, 8, 0, 0, 0, '', 'Show gossip option if player is a rogue'),
(15, 21221, 2, 0, 15, 8, 0, 0, 0, '', 'Show gossip option if player is a rogue');
