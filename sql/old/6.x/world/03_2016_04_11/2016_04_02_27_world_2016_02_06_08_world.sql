-- 
-- DB/Creature: Koren - Gossipoptions
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7435;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(7435, 0, 1, 'I\'m in need of your skill as a blacksmith, Koren.', 14188, 3, 128, 0, 0, 0, 0, NULL, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID` = 15 AND `SourceGroup` = 7435;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 7435, 0, 0, 0, 5, 0, 967, 224, 0, 0, 0, 0, '', 'Koren - Show Vendor option if Honored Exalted with Violet Eye');
