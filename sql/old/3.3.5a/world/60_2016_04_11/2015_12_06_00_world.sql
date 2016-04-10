-- 
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=11956;

DELETE FROM `smart_scripts` WHERE `entryorguid`=11956 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11956, 0, 0, 0, 62, 0, 100, 0, 3884, 0, 0, 0, 15, 5930, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Great Bear Spirit - On Gossip Select - Quest explored'),
(11956, 0, 1, 0, 62, 0, 100, 0, 3884, 1, 0, 0, 15, 5929, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Great Bear Spirit - On Gossip Select - Quest explored');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3884;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,3884,0,0,9,5930,0,0,0,0,'','Show the gossip option if the quest 5930 is taken'),
(15,3884,1,0,9,5929,0,0,0,0,'','Show the gossip option if the quest 5929 is taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=3882;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(14,3882,4719,0,9,5929,0,0,0,"Only show text_id 4719 if the quest 5929 is taken"),
(14,3882,4719,1,9,5930,0,0,0,"Only show text_id 4719 if the quest 5930 is taken");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3882;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,3882,0,0,9,5930,0,0,0,0,'','Show the gossip option if the quest 5930 is taken'),
(15,3882,0,1,9,5929,0,0,0,0,'','Show the gossip option if the quest 5929 is taken');

DELETE FROM `gossip_menu` WHERE `entry`=3882 AND `text_id`=4719;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (3882, 4719);

DELETE FROM `gossip_menu` WHERE `entry`=3882 AND `text_id`=4719;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (3882, 4719);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3881, 3882, 3883, 3884);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(3882,0,0,'What do you represent, spirit?',7439,1,1,3881,0,0,0,'',0),
(3881,0,0,'I seek to understand the importance of strength of the body.',7442,1,1,3883,0,0,0,'',0),
(3883,0,0,'I seek to understand the importance of strength of the heart.',7444,1,1,3884,0,0,0,'',0),
(3884,0,0,'I have heard your words, Great Bear Spirit, and I understand.  I now seek your blessings to fully learn the way of the Claw.',7446,1,1,3885,0,0,0,'',0),
(3884,1,0,'I have heard your words, Great Bear Spirit, and I understand.  I now seek your blessings to fully learn the way of the Claw.',7446,1,1,3885,0,0,0,'',0);
