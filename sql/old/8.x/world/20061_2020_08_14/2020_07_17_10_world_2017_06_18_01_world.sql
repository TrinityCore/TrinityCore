DELETE FROM `creature_text` WHERE `CreatureID`=20071;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(20071, 1, 0, 'You didn\'t really think I\'d do business with you again, did you? Sometimes, the best way to return to profitability is to know when to cut your losses.', 12, 0, 100, 1, 0, 0, 17618, 0, 'Wind Trader Marid to Player'),
(20071, 0, 0, 'Let us hold our discussion in a more... private place. Follow me, $n.', 12, 0, 100, 1, 0, 0, 17615, 0, 'Wind Trader Marid to Player');

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8071;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES 
(8071, 0, 0, 'Wind Trader Marid, I\'ve returned with more information on the nether drakes. I\'m prepared to be your business partner, and for an extra sum, I\'ll take care of that troublesome elf and her human friend.', 17754, 1, 1);

UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=0 WHERE  `entry`=20071;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=20071;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20071, 0, 0, 1, 62, 0, 100, 0, 8071, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Gossip Select - Set Store Targetlist'),
(20071, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Gossip Select - Close Gossip'),
(20071, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Gossip Select - Say Line 0'),
(20071, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Gossip Select - Set NPC Flags'),
(20071, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 20071, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Gossip Select - Start WP'),
(20071, 0, 5, 6, 40, 0, 100, 0, 10, 20071, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0.4537856, 'Wind Trader Marid - On Reached WP 10 - Set Orientation'),
(20071, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Reached WP 10 - Set Home Position'),
(20071, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Reached WP 10 - Say Line 1'),
(20071, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Reached WP 10 - Set Faction'),
(20071, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Reached WP 10 - Set Unit Flags'),
(20071, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Reached WP 10 - Set Defensive'),
(20071, 0, 11, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wind Trader Marid - On Evade - Despawn'),
(20071, 0, 12, 13, 4, 0, 100, 0, 0, 0, 0, 0, 12, 20101, 1, 60000, 1, 0, 0, 8, 0, 0, 0, 4322.216, 2148.113, 124.918, 4.014257, 'Wind Trader Marid - On Aggro - Summon Netherstalkwe'),
(20071, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 20101, 1, 60000, 1, 0, 0, 8, 0, 0, 0, 4327.583, 2133.33, 126.4966, 3.508112, 'Wind Trader Marid - On Aggro - Summon Netherstalkwe');

DELETE FROM `waypoints` WHERE `entry`=20071;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(20071, 1, 4296.338, 2216.264, 122.231, 'Wind Trader Marid'),
(20071, 2, 4302.872, 2204.899, 120.7829, 'Wind Trader Marid'),
(20071, 3, 4306.264, 2197.094, 119.4814, 'Wind Trader Marid'),
(20071, 4, 4307.128, 2187.726, 115.1026, 'Wind Trader Marid'),
(20071, 5, 4310.083, 2182.954, 117.2381, 'Wind Trader Marid'),
(20071, 6, 4310.326, 2175.833, 118.5926, 'Wind Trader Marid'),
(20071, 7, 4311.009, 2166.498, 117.6943, 'Wind Trader Marid'),
(20071, 8, 4310.087, 2155.008, 125.7436, 'Wind Trader Marid'),
(20071, 9, 4307.198, 2145.444, 128.3736, 'Wind Trader Marid'),
(20071, 10, 4305.531, 2141.197, 129.5266, 'Wind Trader Marid');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8071;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8071, 0, 0, 0, 9, 0, 10273, 0, 0, 0, 0, 0, '', 'Show gossip option 8071 if player has quest 10273');
