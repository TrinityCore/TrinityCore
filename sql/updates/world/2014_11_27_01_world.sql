UPDATE `vehicle_template_accessory` SET `minion`=0 WHERE  `entry` IN(32640,32633);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(32641,32642,32638,32639);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(32641,32642,32638,32639) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(32641, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - Mojodishu - On Has Aura - Set Phase 1'),
(32641, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - On Has No Aura (Phase 1) - Set NPC Flags'),
(32641, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - Link - Say'),
(32641, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drix Blackwrench - Link - Despawn After 2 seconds'),

(32642, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - On Has Aura - Set Phase 1'),
(32642, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - On Has No Aura (Phase 1) - Set NPC Flags'),
(32642, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - Link - Say'),
(32642, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mojodishu - Link - Despawn After 2 seconds'),

(32638, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - Mojodishu - On Has Aura - Set Phase 1'),
(32638, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - On Has No Aura (Phase 1) - Set NPC Flags'),
(32638, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - Link - Say'),
(32638, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hakmud of Argus <Traveling Trader> - Link - Despawn After 2 seconds'),

(32639, 0, 0, 0, 23, 0, 100, 1, 61424, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - On Has Aura - Set Phase 1'),
(32639, 0, 1, 2, 23, 1, 100, 1, 61424, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - On Has No Aura (Phase 1) - Set NPC Flags'),
(32639, 0, 2, 3, 61, 1, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - Link - Say'),
(32639, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gnimo <Adventurous Tinker> - Link - Despawn After 2 seconds');

DELETE FROM `creature_text` WHERE `entry` in(32641,32642,32638,32639);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(32641, 0, 0, 'Our friendship is OVER!', 12, 0, 100, 6, 0, 0, 'Drix Blackwrench',33025),
(32641, 0, 1, 'Hey, yea, I''ve always wanted to be stranded somewhere.', 12, 0, 100, 0, 0, 0, 'Drix Blackwrench',33024),
(32641, 0, 2, 'Oh, I see how it is... You''re gonna do me like that, eh?', 12, 0, 100, 0, 0, 0, 'Drix Blackwrench',33023),
(32641, 0, 3, 'You''re just gonna leave me here? How am I supposed to get home?', 12, 0, 100, 0, 0, 0, 'Drix Blackwrench',33026),
(32642, 0, 0, 'Really, mon? Just like dat you be leavin'' Mojodishu behind?', 12, 0, 100, 1, 0, 0, 'Mojodishu',33027),
(32642, 0, 1, 'Dis bad mojo what you doin''. Don''t say Mojodishu didn''t warn ya!', 12, 0, 100, 0, 0, 0, 'Mojodishu',33028),
(32642, 0, 2, 'Be dat way den!', 12, 0, 100, 0, 0, 0, 'Mojodishu',33029),
(32638, 0, 0, 'Hakmud cannot work under these conditions! Goodbye!', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33017),
(32638, 0, 1, 'I thought we were friend, buddy! You leave Hakmud stranded?', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33018),
(32638, 0, 2, 'Thanks, buddy! Thanks for nothing!', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33014),
(32638, 0, 3, 'What is Hakmud supposed to do now, buddy?', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33016),
(32638, 0, 4, 'Why do you treat Hakmud like this, buddy?', 12, 0, 100, 0, 0, 0, 'Hakmud of Argus <Traveling Trader>',33015),
(32639, 0, 0, 'Goodbye! You were Gnimo''s best friend ever!', 12, 0, 100, 0, 0, 0, 'Gnimo <Adventurous Tinker>',33020),
(32639, 0, 1, 'Nobody loves Gnimo...', 12, 0, 100, 0, 0, 0, 'Gnimo <Adventurous Tinker>',33019),
(32639, 0, 2, 'Time for Gnimo to shut down.', 12, 0, 100, 0, 0, 0, 'Gnimo <Adventurous Tinker>',33021);
