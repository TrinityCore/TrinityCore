UPDATE `creature_template` SET `gossip_menu_id`=1080, `speed_walk`=1, `speed_run`=1.142857, `rangeattacktime`=2000 WHERE `entry`=7998;

DELETE FROM `gossip_menu` WHERE `entry`=1080;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(1080, 1693); -- 7998

DELETE FROM `gossip_menu_option` WHERE `menu_id`=1080;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(1080, 0, 0, 'I am ready to begin.', 4084, 1, 1, 0, 0, '', 0); -- 7998

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1080;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1080,0,0,0,13,1,1,0,0,0,0,0,'','Show gossip option only if Blastmaster Emi Encounter is not started');
