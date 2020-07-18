--
UPDATE `creature_template` SET `npcflag`=4194305 WHERE `entry`=9988;
UPDATE `conditions` SET `ConditionValue1` =4 WHERE `SourceGroup`=9576 AND `SourceTypeOrReferenceId`=15;
UPDATE `creature_template` SET `npcflag`=4194305 WHERE  `npcflag`=4194304 ;
UPDATE `creature_template` SET `npcflag`=4194307 WHERE  `npcflag`=4194306 ;
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry` IN (9976,9978,9979,9982,9985,9986,10048,10049,10051,10052,10057,10058,11105,13616,15131,16094,16586,16656,16824,17896,18984,19018,21336,21517,22469,9896,19325,22551,22577,23392,24905,24974,25037,25519,29251,30155,31991,32105,35290);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup`=9821;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 9821, 13557, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 9821, 13584, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1);

UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1, `action_menu_id`=9820 WHERE `menu_id`=9821 AND `id`=1;

DELETE FROM `gossip_menu` WHERE `entry`=11971 AND `text_id`=16788;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (11971,16788);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup`=11971;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 11971, 16788, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 11971, 16789, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1);

DELETE FROM `npc_text` WHERE id=16788;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`, `Probability0`) VALUES 
(16788, "Hey der, mon.$B$BDid ya want ta be stablin' yer pets, or were ya lookin' for a lost companion?", 45395, 1);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 11971;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(11971,0,0,'I''d like to stable my pet here.',30181,14,4194304,0,0,0,0,'',0),
(11971,1,1,'I''m looking for a lost companion.',56613,1,1,9820,0,0,0,'',0);

DELETE FROM `gossip_menu` WHERE `entry`=9864 AND `text_id`=13662;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (9864,13662);

UPDATE `npc_text` SET `text0_0`="", `text0_1`="Well met, Battle-Sister. I can help stable your pets or assist you in recovering lost companions.", `BroadcastTextID0`=30667 WHERE `ID`=13662;

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 9864;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(9864,0,0,'I''d like to stable my pet here.',30181,14,4194304,0,0,0,0,'',0),
(9864,1,1,'I''m looking for a lost companion.',56613,1,1,9820,0,0,0,'',0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup`=9864;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 9864, 13662, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is a hunter', 0),
(14, 9864, 13661, 0, 15, 4, 0, 0, 0, '', 'Show gossip text if player is not a hunter', 1);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 9212 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(9212,1,0,'I''d like to stable my pet here.',30181,14,4194304,0,0,0,0,'',0);

DELETE FROM `gossip_menu` WHERE `entry`=9820 AND `text_id`=13584;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (9820,13584);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 9820;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(9820,0,0,'I''ve lost Miniwing.',30182,1,1,0,0,0,0,'',0),
(9820,1,0,'I''ve lost my Jubling.',30183,1,1,0,0,0,0,'',0),
(9820,2,0,'I''ve lost my sprite darter hatchling.',30192,1,1,0,0,0,0,'',0),
(9820,3,0,'I''ve lost my worg pup.',30196,1,1,0,0,0,0,'',0),
(9820,4,0,'I''ve lost my Smolderweb hatchling.',30197,1,1,0,0,0,0,'',0),
(9820,5,0,'I''ve lost my Prairie Chicken.',30217,1,1,0,0,0,0,'',0),
(9820,6,0,'I''ve lost my wolpertinger.',30224,1,1,0,0,0,0,'',0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup`=9820;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(15, 9820, 0, 0, 8, 10898, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 0, 0, 2, 31760, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 0, 0, 25, 39181, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 1, 0, 8, 7946, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 1, 0, 2, 19450, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 1, 0, 2, 19462, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 1, 0, 25, 23811, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 2, 0, 8, 4298, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 2, 0, 2, 11474, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 2, 0, 25, 15067, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 3, 0, 8, 4729, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 3, 0, 2, 12264, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 3, 0, 25, 15999, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 4, 0, 8, 4862, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 4, 0, 2, 12529, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 4, 0, 25, 16450, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 5, 0, 8, 3861, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 5, 0, 2, 11110, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 5, 0, 25, 13548, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),   
(15, 9820, 5, 1, 8, 13840, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 5, 1, 2, 11110, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 5, 1, 25, 13548, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 6, 0, 8, 11117, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 6, 0, 2, 32233, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 6, 0, 25, 39709, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1),
(15, 9820, 6, 1, 8, 11431, 0, 0, 0, '', 'Show the gossip option if the player rewarded the quest', 0),
(15, 9820, 6, 1, 2, 32233, 1, 1, 0, '', 'Show the gossip option if the player Didn''t have the item', 1),
(15, 9820, 6, 1, 25, 39709, 0, 0, 0, '', 'Show the gossip option if the player Didn''t lear the spell', 1);

UPDATE `creature_template` SET `ScriptName`="npc_stable_master" WHERE `entry` IN (10052, 9978, 33854, 16764, 9986, 9987, 9989, 10045, 10046, 10047, 10048, 10049, 10050, 10051, 10053, 10054, 10055, 10056, 10057, 10058, 10059, 10060, 10061, 10062, 10063, 10085, 11069, 11104, 11105, 11117, 11119, 13616, 9983,  9982,  15131, 9981,  16094, 16185, 9985,  16656, 9980, 16824, 17485, 17666, 17896, 18244, 18250, 18984, 19018, 9979,  19368, 19476, 21336, 21517, 21518, 22468, 22469, 9896,  19325, 23392, 24905, 24974, 25037, 27010, 27385,  24066, 24067, 24154, 24350, 25519, 9977,  16586, 9976,  26597, 26721, 9984,  6749,  27056, 27065, 27068, 27150, 27183, 27194, 27948, 28057, 28690, 28790, 29250, 29251, 29658, 29740, 29906, 29948, 29959, 29967, 35344, 30039, 30155, 30304, 35290, 35291, 30008, 9988);
