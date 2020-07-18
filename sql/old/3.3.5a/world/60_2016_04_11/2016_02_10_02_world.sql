DELETE FROM `gossip_menu_option` WHERE `menu_id`=9546;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9546, 0, 2, 'Where would you like to fly to?', 10753, 4, 8192, 0, 0, 0, 0, '', 0),
(9546, 1, 0, 'I need to get to Wintergarde Keep fast!', 26697, 1, 1, 0, 0, 0, 0, '', 0),
(9546, 2, 0, 'Greer, I need a gryphon to ride and some bombs to drop on New Agamand!', 23112, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9546;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9546, 1, 0, 0, 28, 0, 12298, 0, 0, 0, 0, 0, '', 'Greer Orehammer - Show gossip option only if player has taken quest 12298'),
(15, 9546, 2, 0, 0, 9, 0, 11332, 0, 0, 0, 0, 0, '', 'Greer Orehammer - Show gossip option only if player has taken quest 11332');

DELETE FROM `smart_scripts` WHERE `entryorguid`=23859 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(23859, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 80, 2385900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Aggro - Run Script'),
(23859, 0, 1, 2, 62, 0, 100, 0, 9546, 2, 0, 0, 56, 33634, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Add Item \'Orehammer\'s Precision Bombs\' 10 Times'),
(23859, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 52, 745, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Cast \'High Commander Halford Wyrmbane: Westguard Keep to Wintergarde Keep Taxi\''),
(23859, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On Gossip Option 1 Selected - Close Gossip'),
(23859, 0, 4, 5, 62, 0, 100, 0, 9546, 1, 0, 0, 11, 48862, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On gossip select - Invoker spellcast'),
(23859, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greer Orehammer - On gossip select - Close gossip');
