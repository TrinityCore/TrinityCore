UPDATE `creature_template` SET `gossip_menu_id`=1882 WHERE  `entry`=3389;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3389 AND  `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3389, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - On Spawn  - Set Phase 1 '),
(3389, 0, 2, 3, 19, 1, 100, 0, 4021, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - On quest accept  - say text 0 '),
(3389, 0, 3, 4, 61, 1, 100, 0, 0, 0, 0, 0, 80, 338900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - Linked with Previous Event -  Run script'),
(3389, 0, 4, 0, 61, 1, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - Linked with Previous Event -  Set Phase 2'),
(3389, 0, 5, 0, 1, 0, 100, 0, 300000, 300000, 300000, 300000, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - OOC (P2)  - Set Phase 1 '),
(3389, 0, 6, 0, 20, 0, 100, 0, 4021, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - On quest Reward  - Set Phase 1 '),
(3389, 0, 7, 8, 62, 1, 100, 0, 1882, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - On Gossip Option Select  - say text 0 '),
(3389, 0, 8, 9, 61, 1, 100, 0, 0, 0, 0, 0, 80, 338900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - Linked with Previous Event -  Run script'),
(3389, 0, 9, 0, 61, 1, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - Linked with Previous Event -  Set Phase 2'),
(3389, 0, 10, 0, 62, 0, 100, 0, 1882, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Regthar Deathgate - On Gossip Option Select  - Close Gossip ');

DELETE FROM `gossip_menu` WHERE `entry`=1882;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(1882, 2533);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=1882;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(1882, 0, 0, 'Where is Warlord Krom''zar?', 4793, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1882;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 1882, 0, 0, 0, 9, 0, 4021, 0, 0, 0, 0, 0, '', 'Regthar Deathgate show gossip only if player on counterattack');
