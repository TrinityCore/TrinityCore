UPDATE `creature_template` SET `npcflag`=4227 WHERE `entry`=38316;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10996 AND `id`=5;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(10996, 5, 1, 'Show me the armor of Scourge lords, Ormus.', 3, 128, 0, 0, 0, 0, '');

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10996 AND `SourceEntry`=5;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10996, 5, 0, 0, 15, 0, 32, 0, 0, 0, 0, 0, '', 'Ormus the Penitent - Show gossip option if player is a Death Knight');
