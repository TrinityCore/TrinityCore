/*
DELETE FROM `gossip_menu_option` WHERE `menu_id`=5667;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(5667, 0, 0, 'Hey Knot - I''m a Leatherworker. Think you could teach me how to make the ogre suit?', 9403, 1, 1, 0, 0, 0, 0, '', 0),
(5667, 1, 0, 'Hey Knot - I''m a Tailor. Think you could teach me how to make the ogre suit?', 9404, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5667;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 5667, 0, 0, 0, 7, 0, 165, 275, 0, 0, 0, 0, '', 'Only show gossip option if player has Leatherworking with skill level 275'),
(15, 5667, 1, 0, 0, 7, 0, 197, 275, 0, 0, 0, 0, '', 'Only show gossip option if player has Tailoring with skill level 275');

DELETE FROM `smart_scripts` WHERE `entryorguid`=14338 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1433800 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14338, 0, 0, 0, 20, 0, 100, 1, 5525, 0, 0, 0, 80, 1433800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knot - On Free Knot! Reward - run script'),
(14338, 0, 1, 0, 20, 0, 100, 1, 7429, 0, 0, 0, 80, 1433800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knot - On Free Knot! Reward - run script'),
(14338, 0, 2, 0, 34, 0, 100, 0, 0, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knot - On Point Reached - Despawn'),
(14338, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 50, 179511, 43200, 0, 0, 0, 0, 8, 0, 0, 0, 581.241, 524.321, -25.4027, -2.79252, 'Knot - On Reset - Spawn Ball and Chain'),
(14338, 0, 4, 6, 62, 0, 100, 0, 5667, 0, 0, 0, 85, 22816, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Knot - On Gossip Select  - Cast Gordok Ogre Suit'),
(14338, 0, 5, 6, 62, 0, 100, 0, 5667, 1, 0, 0, 85, 22814, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Knot - On Gossip Select  - Cast Gordok Ogre Suit'),
(14338, 0, 6, 0, 61, 0, 100, 0, 5667, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Knot - On Gossip Select  - Close Gossip'),

(1433800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Knot - Script - Say 0'),
(1433800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knot - Script - Remove npc flag'),
(1433800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 43200, 0, 0, 0, 0, 0, 20, 179511, 10, 0, 0, 0, 0, 0, 'Knot - Script - Despawn Ball and Chain'),
(1433800, 9, 3, 0, 0, 0, 100, 0, 500, 500, 0, 0, 50, 179501, 43200, 0, 0, 0, 0, 8, 0, 0, 0, 583.6, 523.44, -25.4, 3.1848, 'Knot - Script - Spawn Cache'),
(1433800, 9, 4, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 69, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 500.42, 540.966, -25.3194, 2.72271, 'Knot - Script - Move Point');

DELETE FROM `creature_text` WHERE `entry`=14338;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(14338, 0, 0, '$n, I\'ll make sure all my friends in the Cartel know that you\'ve saved my life today.  Here - I\'m going to need to be able to travel light, so please help yourself to my cache of tailoring and leatherworking supplies!  Thanks again - see ya!', 12, 0, 0, 0, 0, 0, 9346, 0, 'Knot');
*/
