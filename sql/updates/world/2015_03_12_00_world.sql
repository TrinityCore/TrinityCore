UPDATE `creature_template` SET `gossip_menu_id`=8443 WHERE  `entry`=21769;
DELETE FROM `gossip_menu` WHERE `entry`=8443;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8443, 10549); -- 21769
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8443;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(8443, 0, 0, 'I''ve lost my Kor''kron Flare Gun, sir. May I have another?', 19708, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=21769 AND `source_type`=0 AND `id` IN(3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(21769, 0, 3, 4, 62, 0, 100, 0, 8443, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overlord Or\'barokh - On Gossip Option 0 Selected - Close Gossip'),
(21769, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 38172, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overlord Or\'barokh - On Gossip Option 0 Selected - Cast Create Kor''kron Flare Gun');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8443;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8443, 0, 0, 0, 8, 0, 10750, 0, 0, 0, 0, 0, '', 'Show gossip option if player has the path of conquest rewarded'),
(15, 8443, 0, 0, 0, 8, 0, 10769, 0, 0, 1, 0, 0, '', 'Show gossip option if player does not have Dissension Amongst the Ranks rewarded'),
(15, 8443, 0, 0, 0, 2, 0, 31108, 1, 0, 1, 0, 0, '', 'Show gossip option if player does not have Kor''Kron Flare Gun');
