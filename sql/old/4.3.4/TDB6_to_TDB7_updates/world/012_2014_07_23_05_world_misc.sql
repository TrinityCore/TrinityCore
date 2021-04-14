DELETE FROM `smart_scripts`  WHERE `entryorguid`=36913;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(36913, 0, 0, 0, 1, 0, 100, 6, 60000, 300000, 300000, 600000, 1, 0, 0, 0, 0, 0, 0, 21, 400, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - Out of Combat - Set Orientation Closest Player'),
(36913, 0, 1, 0, 1, 0, 100, 6, 0, 0, 1000, 1000, 66, 0, 0, 0, 0, 0, 0, 21, 150, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - Out of Combat - Whisper Closest Player'),
(36913, 0, 2, 0, 11, 0, 100, 6, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 21, 150, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - On Spawn Set unit flags Immune to NPC & Immune to PC');

DELETE FROM `creature_text` WHERE `entry`=36913;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(36913, 0, 0, 'Cry out in torment... Let your pain overcome your might...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38355),
(36913, 0, 1, 'Release yourself from the chains of life...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38352),
(36913, 0, 2, 'The Lich King is unstoppable...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38350),
(36913, 0, 3, 'The Master''s will remains inviolate...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38347),
(36913, 0, 4, 'You cannot escape the Master\'s Wrath...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38348),
(36913, 0, 5, 'Death consumes you...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38353),
(36913, 0, 6, 'Give in... to the cold embrace of death...', 15, 0, 14.2857, 0, 0, 0, 'Eye of the Lichking', 38351);
