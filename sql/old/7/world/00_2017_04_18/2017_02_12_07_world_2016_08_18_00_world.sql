-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16014;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16014 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16014, 0, 0, 1, 62, 0, 100, 0, 7083, 0, 0, 0, 11, 27754, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mux Manascrambler - On Gossip Option 0 Selected - Cast Create Extra-Dimensional Ghost Revealer'),
(16014, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mux Manascrambler - On Gossip Option 0 Selected - Close Gossip');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=7083 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `box_text`) VALUES 
('7083', 'I seem to have misplaced the distiller, Mux.  Did I happen to leave it here?', '11908', '1', '1', NULL);

DELETE FROM `conditions` WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7083 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 7083, 0, 0, 0, 2, 0, 22115, 1, 0, 1, 0, 0, '', 'Show gossip option if player does not have Extra-Dimensional Ghost Revealer'),
(15, 7083, 0, 0, 0, 8, 0, 8978, 0, 0, 0, 0, 0, '', 'Show gossip menu option if only player has \'Return to Mokvar\' quest Horde rewarded'),
(15, 7083, 0, 0, 1, 2, 0, 22115, 1, 0, 1, 0, 0, '', 'Show gossip option if player does not have Extra-Dimensional Ghost Revealer'),
(15, 7083, 0, 0, 1, 8, 0, 8977, 0, 0, 0, 0, 0, '', 'Show gossip menu option if only player has \'Return to Deliana\' quest Alliance rewarded');
