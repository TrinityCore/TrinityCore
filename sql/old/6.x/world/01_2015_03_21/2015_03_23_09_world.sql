DELETE FROM `creature_text` WHERE `entry`=18417;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(18417, 0, 0, 'The information you seek... I cannot give you that freely.  You will have to prove that your enemies are the same as mine.', 12, 0, 100, 25, 0, 0, 19890, 'Altruis the Sufferer to Player'),
(18417, 1, 0, 'This book would give me unlimited power over my enemies... I would become... unstoppable!', 12, 0, 100, 1, 0, 0, 19614, 'Altruis the Sufferer to Player'),
(18417, 2, 0, 'No... you must take this from me, $n!  I feel its dark power swaying my will already!  Use it to destroy Varedis.', 12, 0, 100, 274, 0, 0, 19615, 'Altruis the Sufferer to Player');

DELETE FROM `smart_scripts` WHERE `entryorguid` =18417 AND `source_type`=0 AND `id`>2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18417, 0, 3, 0, 20, 0, 100, 0, 10640, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Altruis the Sufferer - On Quest reward 10640 - Say Line 0'),
(18417, 0, 4, 0, 20, 0, 100, 0, 10689, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Altruis the Sufferer - On Quest reward 10689 - Say Line 0'),
(18417, 0, 5, 0, 20, 0, 100, 0, 10649, 0, 0, 0, 1, 1, 4000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Altruis the Sufferer - On Quest reward 10649 - Say Line 1'),
(18417, 0, 6, 0, 52, 0, 100, 0, 1, 18417, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Altruis the Sufferer - On Text Over Line 1 - Say Line 2');

