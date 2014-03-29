UPDATE `creature_template` SET `scriptname`='' WHERE `entry`=7564;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=922;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(922,0,1,'I''d like to browse your goods.',3,128,0,0,0,0,NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=922 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,922,0,0,0,8,0,2662,0,0,0,0,0,'','Show gossip menu option if only player has ''Noggenfogger Elixir'' quest rewarded');
