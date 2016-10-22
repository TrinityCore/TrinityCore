-- NPC 35364 Slahtz <Experience Eliminator> / 35365 Behsten <Experience Eliminator>
UPDATE `creature_template` SET `gossip_menu_id`= 10638 WHERE `entry`= 35365; -- 35364 already OK

UPDATE `gossip_menu_option` SET `box_money`= 100000, `box_text`= 'Are you certain you wish to stop gaining experience?', `BoxBroadcastTextID`= 35535 WHERE `menu_id`= 10638 AND `id`= 0;

DELETE FROM `gossip_menu_option` WHERE `menu_id`= 10638 AND `id`= 1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(10638,1,0,'I wish to start gaining experience again.',35532,1,1,0,0,0,100000,'Are you certain you wish to start gaining experience again?',35533,0);
