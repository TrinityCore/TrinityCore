DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (10026,10025,10024);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10026, 0, 0, 0, 8, 0, 13419, 0, 0, 0, 0, 0, '', 'Sky-Reaver Klum - Show Gossip if player Has rewarded Quest Preparations for War'),
(15, 10026, 1, 0, 0, 28, 0, 13419, 0, 0, 0, 0, 0, '', 'Sky-Reaver Klum - Show Gossip if player Has completed Quest Preparations for War'),
(15, 10025, 0, 0, 0, 8, 0, 13418, 0, 0, 0, 0, 0, '', 'Officer Van Rossem - Show Gossip if player Has rewarded Quest Preparations for War'),
(15, 10025, 1, 0, 0, 28, 0, 13418, 0, 0, 0, 0, 0, '', 'Officer Van Rossem - Show Gossip if player Has completed Quest Preparations for War'),
(15, 10024, 0, 0, 0, 8, 0, 12521, 0, 0, 0, 0, 0, '', 'Archmage Pentarus - Show Gossip if player Has rewarded Quest Where in the World is Hemet Nesingwary?'),
(15, 10024, 1, 0, 0, 28, 0, 12521, 0, 0, 0, 0, 0, '', 'Archmage Pentarus - Show Gossip if player Has completed Quest Where in the World is Hemet Nesingwary?');

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10025,10024) AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(10025, 0, 0, 'Take me to the ship.', 31625, 1, 1, 0, 0, 0, 0, '', 0),
(10025, 1, 0, 'Take me to the ship.', 31625, 1, 1, 0, 0, 0, 0, '', 0),
(10024, 0, 0, 'I''m ready to fly to Sholazar Basin.', 31594, 1, 1, 0, 0, 0, 0, '', 0),
(10024, 1, 0, 'I''m ready to fly to Sholazar Basin.', 31594, 1, 1, 0, 0, 0, 0, '', 0);
