DELETE FROM `creature_text` WHERE `entry` IN(26860,26862,27102,27037);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(26860, 0, 0, 'I''ve never seen you so eager to cause harm to someone, sister.  Such a pleasant development... very well, go!', 12, 0, 100, 25, 0, 0, 26229, 'Conqueror Krenna to Player'),
(26860, 1, 0, 'That spineless troll has failed me for the last time.  Anthis!  Break his legs!', 12, 0, 100, 53, 0, 0, 26227, 'Conqueror Krenna to Player'),
(26862, 0, 0, 'At once, my lady!', 12, 0, 100, 0, 0, 0, 26228, 'Anthis to Player'),
(27102, 0, 0, 'Let me take care of it, sister.', 12, 0, 100, 0, 0, 0, 27108, 'Gorgonna to Player'),
(27102, 1, 0, 'What were you thinking, provoking her like that?', 15, 0, 100, 0, 0, 0, 27109, 'Gorgonna to Player'),
(27102, 2, 0, 'I used good judgment when you showed none.  I don''t want to see you lead us into ruin, Krenna!', 12, 0, 100, 0, 0, 0, 27027, 'Gorgonna to Player'),
(27102, 3, 0, 'We''ll see about that.', 12, 0, 100, 0, 0, 0, 27028, 'Gorgonna to Player'),
(27102, 4, 0, 'You... half-idiot!  You really did it this time.  I''m going to have to make it look like your leg''s broken.', 12, 0, 100, 0, 0, 0, 27110, 'Gorgonna to Player'),
(27102, 5, 0, 'Now don''t move if you ever want to walk again!', 12, 0, 100, 0, 0, 0, 27111, 'Gorgonna to Player'),
(27037, 0, 0, 'No, please!  Don''t!', 12, 0, 100, 430, 0, 0, 27112, 'Hidetrader Jun''ik to Player');

DELETE FROM `smart_scripts` WHERE `entryorguid`=26860 AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27102 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(2686000,2710200) AND `source_type`=9;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(27102);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(26860, 0, 1, 2, 20, 0, 100, 0, 12178, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Conqueror Krenna - On Quest return (12178) - Store Targetlist'),
(26860, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2686000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conqueror Krenna - On Quest return (12178) - Run Script'),

(27102, 0, 0, 5, 38, 0, 100, 0, 2, 2, 0, 0, 53, 1, 27102, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - On Data Set 2 2 - Start WP'),
(27102, 0, 1, 2, 40, 0, 100, 0, 3, 27102, 0, 0, 54, 9000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - Reached WP3 - Pause WP'),
(27102, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2710200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - Reached WP3 - Run Script'),
(27102, 0, 3, 0, 40, 0, 100, 0, 4, 27102, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.80998, 'Gorgonna - Reached WP4 - Set Orientation'),
(27102, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 5, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - On Data Set 1 1 - Play Emote OneShotSalute'),
(27102, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Gorgonna - On Data Set 2 2 - Say Line 1'),

(2710200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - Script - Say Line 4 '), 
(2710200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27037, 0, 0, 0, 0, 0, 0, 'Gorgonna - Script - Say Line 0 (Hidetrader Jun''ik)'), 
(2710200, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - Script - Say Line 5 '), 
(2710200, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 42908, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gorgonna - Script - Cast Cosmetic - Combat Kick'), 
(2710200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Gorgonna - Script - Turn Run Off'), 

(2686000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Say Line 1'), 
(2686000, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26862, 0, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Say Line 0 (Anthis)'), 
(2686000, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10, 117164, 27102, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Say Line 0 (Gorgonna)'), 
(2686000, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Say Line 0'), -- 15:45:27.765
(2686000, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 117164, 27102, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Set Data (Gorgonna)'),
(2686000, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 117164, 27102, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Set Data (Gorgonna)'),
(2686000, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 10, 117164, 27102, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Send Targetlist (Gorgonna)'), 
(2686000, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 117164, 27102, 0, 0, 0, 0, 0, 'Conqueror Krenna - Script - Set Data (Gorgonna)'); 


DELETE FROM `waypoints` WHERE `entry`=27102;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(27102, 1, 3257.147, -2228.854, 116.0879, 'Gorgonna'),
(27102, 2, 3244.31, -2251.519, 114.7344, 'Gorgonna'),
(27102, 3, 3237.79, -2265.45, 114.2664, 'Gorgonna'),
(27102, 4, 3275.846, -2208.026, 117.0294, 'Gorgonna');

