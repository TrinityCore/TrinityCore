UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(29851,29860,29858,29859);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(29851,29860,29858,29859) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2985100 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2985100, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 12, 29860, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 8552.679, 2653.384, 652.3538, 5.757316, 'General Lightsbane - Script - Summon Vile'),
(2985100, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 12, 29858, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 8597.88, 2668.878, 652.3538, 4.433503, 'General Lightsbane - Script - Summon Lady Nightswood'),
(2985100, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 12, 29859, 1, 300000, 0, 0, 0, 8, 0, 0, 0, 8556.31, 2633.728, 652.4367, 0.3490658, 'General Lightsbane - Script - Summon The Leaper'),
(29851, 0, 0, 1, 7, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29860, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Set Data on Vile'),
(29851, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29858, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Set Data on Lady Nightswood'),
(29851, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29859, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Set Data on The Leaper'),
(29851, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Evade - Despawn'),
(29851, 0, 4, 5, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Just Summoned - Say Line'),
(29851, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Just Summoned - Attack'),
(29851, 0, 6, 0,  4, 0, 100, 0, 0, 0, 0, 0, 80, 2985100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Agro - Run Timed Action List (IC Only)'),
(29851, 0, 7, 0,  9, 0, 100, 0, 0, 5, 13000, 18000, 11, 60186, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Range - Cast Plague Strike'),
(29851, 0, 8, 0,  9, 0, 100, 0, 0, 5, 8000, 11000, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Range - Cast Cleave'),
(29851, 0, 9, 0,  9, 0, 100, 0, 3000, 5000, 10000, 15000, 11, 60160, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Range - Cast Death and Decay'),
(29851, 0, 10, 11, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29860, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Death - Set Data on Vile'),
(29851, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29858, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Death - Set Data on Lady Nightswood'),
(29851, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 29859, 0, 0, 0, 0, 0, 0, 'General Lightsbane - On Death - Set Data on The Leaper'),
(29860, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29860, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Just Summoned - Start WP'),
(29860, 0, 1, 2, 40, 0, 100, 0, 8, 29860, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Set Home Position'),
(29860, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Set Aggresive'),
(29860, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Say Line'),
(29860, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 29851, 0, 0, 0, 0, 0, 0, 'Vile - On Reached WP8 - Attack General Lightsbane'),
(29860, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Data Set 1 1 - Despawn'),
(29860, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 37548, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Agro - Cast Taunt'),
(29860, 0, 7, 0, 0, 0, 100, 0, 8000, 15000, 10000, 15000, 11, 37548, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - IC - Cast Taunt'),
(29860, 0, 8, 0, 9, 0, 100, 0, 0, 5, 5000, 8000, 11, 6253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Vile - On Range - Cast Back Hand'),
(29860, 0, 9, 0, 0, 0, 100, 0, 10000, 15000, 15000, 23000, 11, 56646, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vile - IC - Cast Enrage'),
(29858, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29858, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Just Summoned - Start WP'),
(29858, 0, 1, 2, 40, 0, 100, 0, 7, 29858, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Set Home Position'),
(29858, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Set Aggresive'),
(29858, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Say Line'),
(29858, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 29851, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Reached WP7 - Attack General Lightsbane'),
(29858, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Data Set 1 1 - Despawn'),
(29858, 0, 6, 0, 0, 0, 100, 0, 0, 8000, 13000, 18000, 11, 5884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - IC - Cast Banshee Curse'),
(29858, 0, 7, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 16838, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Nightswood - On Range - Cast Banshee Banshee Shiek'),
(29859, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 1, 29859, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Just Summoned - Start WP'),
(29859, 0, 1, 2, 40, 0, 100, 0, 6, 29859, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Set Home Position'),
(29859, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Set Aggresive'),
(29859, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Say Line'),
(29859, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 29851, 0, 0, 0, 0, 0, 0, 'The Leaper - On Reached WP7 - Attack General Lightsbane'),
(29859, 0, 5, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Data Set 1 1 - Despawn'),
(29859, 0, 6, 0, 9, 0, 100, 0, 0, 5, 4000, 7000, 11, 60195, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Sinister Strike'),
(29859, 0, 7, 0, 0, 0, 100, 0, 5000, 8000, 30000, 35000, 11, 60177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'The Leaper - On Range - Cast Hunger For Blood');

DELETE FROM `waypoints` WHERE `entry` IN(29860,29858,29859);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(29860, 1,8550.583, 2654.241, 652.3538, 'Vile'),
(29860, 2,8551.562, 2654.033, 652.3538, 'Vile'),
(29860, 3,8554.787, 2652.161, 652.3538, 'Vile'),
(29860, 4,8560.368, 2648.921, 652.3538, 'Vile'),
(29860, 5,8576.063, 2639.811, 652.3538, 'Vile'),
(29860, 6,8577.143, 2639.184, 652.3538, 'Vile'),
(29860, 7,8578.033, 2638.667, 652.3539, 'Vile'),
(29860, 8,8578.033, 2638.667, 652.3539, 'Vile'),
(29858, 1,8598.499, 2671.039, 652.3538, 'Lady Nightswood'),
(29858, 2,8598.224, 2670.077, 652.3538, 'Lady Nightswood'),
(29858, 3,8597.247, 2666.667, 652.3538, 'Lady Nightswood'),
(29858, 4,8595.948, 2662.132, 652.3538, 'Lady Nightswood'),
(29858, 5,8593.374, 2653.144, 652.3538, 'Lady Nightswood'),
(29858, 6,8589.56, 2639.825, 652.3538, 'Lady Nightswood'),
(29858, 7,8589.56, 2639.825, 652.3538, 'Lady Nightswood'),
(29859, 1,8558.935, 2633.13, 652.1038, 'The Leaper'),
(29859, 2,8567.935, 2631.38, 652.1038, 'The Leaper'),
(29859, 3,8569.185, 2631.38, 652.1038, 'The Leaper'),
(29859, 4,8577.435, 2631.88, 652.1038, 'The Leaper'),
(29859, 5,8585.435, 2632.38, 652.1038, 'The Leaper'),
(29859, 6,8586.87, 2632.519, 652.3538, 'The Leaper');

DELETE FROM `creature_text` WHERE `entry` IN(29860,29859,29858,29851);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(29860, 0, 0, 'SMASH!', 12, 0, 100, 0, 0, 0, 'Vile',30471),
(29859, 0, 0, 'MRMRFRMRFRMRRRR!', 12, 0, 100, 0, 0, 0, 'The Leaper',30472),
(29858, 0, 0, 'My dear general, your time has come!', 12, 0, 100, 0, 0, 0, 'Lady Nightswood',30470),
(29851, 0, 0, 'You''re the one that''s been disrupting things? This should be easy.', 12, 0, 100, 0, 0, 0, 'General Lightsbane',30465);

-- General Lightsbane 13:52:37
-- Vile 13:52:44
-- Lady Nightswood 13:52:55
-- The Leaper 13:53:06
