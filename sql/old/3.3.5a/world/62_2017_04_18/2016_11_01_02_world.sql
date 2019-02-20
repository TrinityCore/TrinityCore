DELETE FROM `gossip_menu_option` WHERE `menu_id`=4085;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(4085, 0, 1, 'Yes, Augustus.  I would like to do business.', 7623, 3, 128, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `gossip_menu` WHERE `entry`=4085;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES 
(4085, 4979, 0),
(4085, 4980, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(14,15) AND `SourceGroup`=4085;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 4085, 4979, 0, 0, 8, 0, 6164, 0, 0, 1, 0, 0, '', 'Augustus - Show Gossip Menu text 4979 if Quest 6164 is not rewarded'),
(14, 4085, 4980, 0, 0, 8, 0, 6164, 0, 0, 0, 0, 0, '', 'Augustus - Show Gossip Menu text 4980 if Quest 6164 is rewarded'),
(15, 4085, 0, 0, 0, 8, 0, 6164, 0, 0, 0, 0, 0, '', 'Augustus - Only allow players who have completed Augustus Receipt Book to access vendor');

UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=12384;
