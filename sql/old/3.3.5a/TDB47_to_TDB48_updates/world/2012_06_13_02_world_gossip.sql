-- Missing gossip for Krendle Bigpockets <Durotar Zeppelin Master> in Thunder Bluff
UPDATE `creature_template` SET `gossip_menu_id`=10566 WHERE `entry`=34766;
DELETE FROM `gossip_menu` WHERE `entry`=10566 AND `text_id`=14622;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10566,14622);
-- Missing gossip
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7368 AND `id` IN (3,4);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(7368,3,0,'Acteon, where is the best area to hunt for moongraze stags?',1,1,7423,0,0,0,''),
(7368,4,0,'Acteon, where is the best place to hunt moongraze bucks?',1,1,7424,0,0,0,'');
-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7368 AND `SourceEntry` IN (3,4);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7368,3,0,0,9,9454,0,0,0,0,'','Acteon - Show gossip option if player has quest 9454'),
(15,7368,4,0,0,9,10324,0,0,0,0,'','Acteon - Show gossip option if player has quest 10324');
-- Gossip Condition for Archmage Celindra <Portal Trainer>
SET @GOSSIP := 9777;
SET @TEXTNO := 13455;
SET @TEXTYES := 13456;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,@GOSSIP,@TEXTNO,0,15,1407,0,0,0,'','Show gossip text if player is not a mage'),
(14,@GOSSIP,@TEXTYES,0,15,128,0,0,0,'','Show gossip text if player is a mage');
-- Update NPC 4217 Mathrengyl Bearwalker
DELETE FROM `gossip_menu_option` WHERE `menu_id`=1403 AND `id`=3;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1403,3,1,'I''d like to purchase more Tharlendris seeds.',3,128,0,0,0,0,'');
-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1403 AND `SourceEntry`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1403,3,0,0,8,3781,0,0,0,0,'','Mathrengyl Bearwalker - Show gossip option if player has rewarded quest 3781'); -- available only for druids
 -- Quest 3792 should only be available after quest 3791
UPDATE `quest_template` SET `PrevQuestId`=3791 WHERE `id`=3792;
