--
DELETE FROM `gossip_menu` WHERE `entry`=10144 AND `text_id`=14088;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (10144, 14088);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = 10144;
INSERT INTO `gossip_menu_option` (`menu_id`, id, option_icon, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`) VALUES 
(10144, 0, 0, 'I''m interested.', 32566, 1, 1, 0),
(10144, 1, 0, 'I''m interested.', 32566, 1, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10144;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10144;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(15,10144,0,0,27,77,3,0,0,'','The player must be level 77 or higher', 0),
(15,10144,0,0,25,54197,0,0,0,'','Show the gossip if the player doesn''t learn Cold Weather Flying', 1),
(15,10144,0,0,2,44221,1,1,0,'','Show the gossip if the player doesn''t have the item', 1),
(15,10144,0,0,16,2098253,0,0,0,'','Show the gossip if the player is from the alliance', 0),
(15,10144,1,0,27,77,3,0,0,'','The player must be level 77 or higher', 0),
(15,10144,1,0,25,54197,0,0,0,'','Show the gossip if the player doesn''t learn Cold Weather Flying', 1),
(15,10144,1,0,2,44229,1,1,0,'','Show the gossip if the player doesn''t have the item', 1),
(15,10144,1,0,16,946,0,0,0,'','Show the gossip if the player is from the horde', 0),
(14,10144,14088,0,27,77,3,0,0,'','Show the text if the player is level 77 or higher', 0),
(14,10144,14088,0,25,54197,0,0,0,'','Show the text if the player doesn''t learn Cold Weather Flying', 1),
(14,10144,14088,0,2,44221,1,1,0,'','Show the text if the player doesn''t have the item', 1),
(14,10144,14088,0,2,44229,1,1,0,'','Show the text if the player doesn''t have the item', 1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30464;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30464  AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30464, 0, 0, 1, 62, 0, 100, 0, 10144, 0, 0, 0, 85, 60126, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '"Honest" Max  - On Gossip select - additem'),
(30464, 0, 1, 0, 61, 0, 100, 0, 10144, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '"Honest" Max  - On Gossip select - close gossip'),
(30464, 0, 2, 3, 62, 0, 100, 0, 10144, 1, 0, 0, 85, 60128, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '"Honest" Max  - On Gossip select - additem'),
(30464, 0, 3, 0, 61, 0, 100, 0, 10144, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '"Honest" Max  - On Gossip select - close gossip');
