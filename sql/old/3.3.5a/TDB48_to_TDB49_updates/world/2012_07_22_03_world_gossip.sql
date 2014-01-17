-- Keristrasza (26206)
UPDATE `creature_template` SET `gossip_menu_id` = 9262 WHERE `entry` = 26206;

DELETE FROM `gossip_menu` WHERE `entry`=9262 AND `text_id`=12576;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (9262, 12576);

-- from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9262 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9262 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(9262, 0, 0, 'I am prepared to face Saragosa!', 1, 3, 0, 0, 0, 0, NULL),
(9262, 1, 0, 'Keristrasa, I am finished here. Please return me to the Transitus Shield.', 1, 3, 0, 0, 0, 0, NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9262 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9262 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9262, 0, 0, 0, 9, 0, 11957, 0, 0, 0, 0, '', "Only show gossip if player has quest Saragosa's End"),
(15, 9262, 1, 0, 0, 9, 0, 11967, 0, 0, 0, 0, '', "Only show gossip if player has quest Mustering the Reds");
