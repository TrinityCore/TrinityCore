-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` IN (395177, 395172, 395173, 395180, 395203, 395200, 395209, 395207, 395213, 395219, 395223, 395222, 395220, 395218, 395221);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(395177, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Judicator
(395172, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Judicator
(395173, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Judicator
(395180, 0, 0, 0, 1, 375, 0, 0, 0, 0, ''), -- Scarlet Purifier
(395203, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395200, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395209, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395207, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395213, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395219, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395223, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395222, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395220, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395218, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Scarlet Fanatic
(395221, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''); -- Scarlet Fanatic

-- Set SAI to Template
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (58605 /*Scarlet Judicator*/, 58555 /*Scarlet Fanatic*/, 58569 /*Scarlet Purifier*/, 58590 /*Scarlet Zealot*/);

-- SAI Scripts
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(395177), -(395172), -(395173), -(395180), -(395182), -(395135), -(395184), -(395191), -(395195), -(395179), -(395197), -(395232), -(395237), -(395255), -(395137), -(395181), -(395189), -(395199), -(395198), -(395178), -(395204), -(395229), -(395233), -(395136), -(395183), -(395190), -(395176), -(395231), -(395230), -(395236), -(395235), -(395196), -(395193), -(395192), -(395202), -(395209), -(395207), -(395213), -(395219), -(395223), -(395222), -(395220), -(395218), -(395221));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(395177), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 4000, 4000, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat after 4s - play emote 54 - to self'),
(-(395177), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 5000, 5000, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat after 5s - play emote 36 - to self'),
(-(395172), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 4000, 4000, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat after 4s - play emote 54 - to self'),
(-(395172), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 5000, 5000, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat after 5s - play emote 36 - to self'),
(-(395173), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 4000, 4000, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat after 4s - play emote 54 - to self'),
(-(395173), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 5000, 5000, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat after 5s - play emote 36 - to self'),
(-(395180), 0, 0, 0, 60, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 116016, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds (1s initially) - Self: Cast spell 116016 on Self'),
(-(395182), 0, 0, 0, 1, 0, 100, 0, 23000, 23000, 24000, 24000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 23s and repeat every 24s - Say Text 0 - to self'),
(-(395135), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395184), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395191), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395195), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395179), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395197), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395232), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395237), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395255), 0, 0, 0, 1, 0, 100, 0, 1000, 4000, 5000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 4s and repeat every 5s - 9s - Play Emote 396 - to self'),
(-(395137), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395181), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395189), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395199), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395198), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395178), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395204), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395229), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395233), 0, 0, 0, 1, 0, 100, 0, 2000, 4000, 6000, 9000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s - 4s and repeat every 6s - 9s - Play Emote 396 - to self'),
(-(395136), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395183), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395190), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395176), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395231), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395230), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395236), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395235), 0, 0, 0, 1, 0, 100, 0, 3000, 6000, 8000, 10000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s - 6s and repeat every 8s - 10s - Play Emote 396 - to self'),
(-(395196), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 3000, 7000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 5s and repeat every 3s - 7s - Play Emote 396 - to self'),
(-(395193), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 3000, 7000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 5s and repeat every 3s - 7s - Play Emote 396 - to self'),
(-(395192), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 3000, 7000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 5s and repeat every 3s - 7s - Play Emote 396 - to self'),
(-(395202), 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 3000, 7000, 5, 396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s - 5s and repeat every 3s - 7s - Play Emote 396 - to self'),
(-(395209), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat every 5s - Play Emote 507 - to self'),
(-(395209), 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 6000, 6000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s and repeat every 6s - Play Emote 509 - to self'),
(-(395209), 0, 2, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 477 - to self'),
(-(395209), 0, 3, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 60 - to self'),
(-(395207), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat every 5s - Play Emote 507 - to self'),
(-(395207), 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 6000, 6000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s and repeat every 6s - Play Emote 509 - to self'),
(-(395207), 0, 2, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 477 - to self'),
(-(395207), 0, 3, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 60 - to self'),
(-(395213), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 1s and repeat every 5s - Play Emote 507 - to self'),
(-(395213), 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 6000, 6000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s and repeat every 6s - Play Emote 509 - to self'),
(-(395213), 0, 2, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 477 - to self'),
(-(395213), 0, 3, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 60 - to self'),
(-(395219), 0, 0, 0, 1, 0, 100, 0, 2000, 2000, 6000, 6000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s and repeat every 6s - Play Emote 507 - to self'),
(-(395219), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 509 - to self'),
(-(395219), 0, 2, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 508 - to self'),
(-(395219), 0, 3, 0, 1, 0, 100, 0, 5000, 6000, 9000, 9000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5s and repeat every 9s - Play Emote 60 - to self'),
(-(395223), 0, 0, 0, 1, 0, 100, 0, 2000, 2000, 6000, 6000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s and repeat every 6s - Play Emote 507 - to self'),
(-(395223), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 509 - to self'),
(-(395223), 0, 2, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 508 - to self'),
(-(395223), 0, 3, 0, 1, 0, 100, 0, 5000, 6000, 9000, 9000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5s and repeat every 9s - Play Emote 60 - to self'),
(-(395222), 0, 0, 0, 1, 0, 100, 0, 2000, 2000, 6000, 6000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 2s and repeat every 6s - Play Emote 507 - to self'),
(-(395222), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 509 - to self'),
(-(395222), 0, 2, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 508 - to self'),
(-(395222), 0, 3, 0, 1, 0, 100, 0, 5000, 6000, 9000, 9000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5s and repeat every 9s - Play Emote 60 - to self'),
(-(395220), 0, 0, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 507 - to self'),
(-(395220), 0, 1, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 509 - to self'),
(-(395220), 0, 2, 0, 1, 0, 100, 0, 5000, 5000, 9000, 9000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5s and repeat every 9s - Play Emote 508 - to self'),
(-(395220), 0, 3, 0, 1, 0, 100, 0, 6000, 6000, 10000, 10000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 6s and repeat every 10s - Play Emote 60 - to self'),
(-(395218), 0, 0, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 507 - to self'),
(-(395218), 0, 1, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 509 - to self'),
(-(395218), 0, 2, 0, 1, 0, 100, 0, 5000, 5000, 9000, 9000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5s and repeat every 9s - Play Emote 508 - to self'),
(-(395218), 0, 3, 0, 1, 0, 100, 0, 6000, 6000, 10000, 10000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 6s and repeat every 10s - Play Emote 60 - to self'),
(-(395221), 0, 0, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 3s and repeat every 7s - Play Emote 507 - to self'),
(-(395221), 0, 1, 0, 1, 0, 100, 0, 4000, 4000, 8000, 8000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 4s and repeat every 8s - Play Emote 509 - to self'),
(-(395221), 0, 2, 0, 1, 0, 100, 0, 5000, 5000, 9000, 9000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 5s and repeat every 9s - Play Emote 508 - to self'),
(-(395221), 0, 3, 0, 1, 0, 100, 0, 6000, 6000, 10000, 10000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - after 6s and repeat every 10s - Play Emote 60 - to self');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 58569;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(58569, 0, 0, 'Learn this spell well for it will burn the taint from all those who oppose us.', 12, 0, 100, 0, 0, 0, 59683, 0, 'Scarlet Purifier'),
(58569, 0, 1, 'Good. Channel the flames, feel them course through you.', 12, 0, 100, 396, 0, 0, 59682, 0, 'Scarlet Purifier');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (116016));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(13, 7, 116016, 0, 0, 31, 0, 3, 60197, 0, 0, 'Potential target of the spell is creature, entry is Training Dummy (60197)');
