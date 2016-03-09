UPDATE `creature_template` SET `scriptname`='' WHERE `entry`=4968;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=2465;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(2465, 0, 0, 'Lady Jaina, this may sound like an odd request... but I have a young ward who is quite shy.  You are a hero to him, and he asked me to get your autograph.', 9663, 1, 1, 5850, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2465;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 2465, 0, 0, 0, 9, 0, 558, 0, 0, 0, 0, 0, '', 'Lady Jaina Proudmoore Shows gossip option 2465 if player has quest Jaina''s Autograph');
