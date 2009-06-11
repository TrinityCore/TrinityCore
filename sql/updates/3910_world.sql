UPDATE `creature_template` SET `ScriptName` = 'npc_threshwackonator' WHERE `entry` = 6669;

DELETE FROM `script_texts` WHERE `entry` IN (-1000413, -1000414);
INSERT INTO script_texts (entry, content_default, sound, type, language, emote, comment) VALUES
(-1000413, 'Threshwackonator First Mate unit prepared to follow', 0, 2, 0, 0, 'threshwackonator EMOTE_START'),
(-1000414, 'YARRR! Swabie, what have ye done?! He\'s gone mad! Baton him down the hatches! Hoist the mast! ARRRR! Every man for hi\'self!', 0, 0, 7, 0, 'threshwackonator SAY_AT_CLOSE');

UPDATE `creature_template` SET `ScriptName` = 'npc_prospector_remtravel' WHERE `entry` = 2917;

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000427 AND -1000415;
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1000415, 'Ok, $n, let\'s go find where I left that mysterious fossil. Follow me!', 0, 0, 7, 0, 'remtravel SAY_REM_START'),
(-1000416, 'Now where did I put that mysterious fossil? Ah, maybe up there...', 0, 0, 7, 0, 'remtravel SAY_REM_RAMP1_1'),
(-1000417, 'Hrm, nothing up here.', 0, 0, 7, 0, 'remtravel SAY_REM_RAMP1_2'),
(-1000418, 'No mysterious fossil here... Ah, but my copy of Green Hills of Stranglethorn. What a good book!', 0, 0, 7, 0, 'remtravel SAY_REM_BOOK'),
(-1000419, 'I bet you I left it in the tent!', 0, 0, 7, 0, 'remtravel SAY_REM_TENT1_1'),
(-1000420, 'Oh wait, that\'s Hollee\'s tent... and it\'s empty.', 0, 0, 7, 0, 'remtravel SAY_REM_TENT1_2'),
(-1000421, 'Interesting... I hadn\'t noticed this earlier...', 0, 0, 7, 0, 'remtravel SAY_REM_MOSS'),
(-1000422, '%s inspects the ancient, mossy stone.', 0, 2, 7, 0, 'remtravel EMOTE_REM_MOSS'),
(-1000423, 'Oh wait! I\'m supposed to be looking for that mysterious fossil!', 0, 0, 7, 0, 'remtravel SAY_REM_MOSS_PROGRESS'),
(-1000424, 'Nope. didn\'t leave the fossil back here!', 0, 0, 7, 0, 'remtravel SAY_REM_PROGRESS'),
(-1000425, 'Ah. I remember now! I gave the mysterious fossil to Hollee! Check with her.', 0, 0, 7, 0, 'remtravel SAY_REM_REMEMBER'),
(-1000426, '%s goes back to work, oblivious to everything around him.', 0, 2, 7, 0, 'remtravel EMOTE_REM_END'),
(-1000427, 'Something tells me this $r wants the mysterious fossil too. Help!', 0, 0, 7, 0, 'remtravel SAY_REM_AGGRO');

DELETE FROM `script_waypoint` WHERE `entry` = 2917;
INSERT INTO `script_waypoint` VALUES
(2917, 0, 4675.812500, 598.614563, 17.645658, 0, 'SAY_REM_START'),
(2917, 1, 4672.844238, 599.325378, 16.417622, 0, ''),
(2917, 2, 4663.449707, 607.430176, 10.494752, 0, ''),
(2917, 3, 4655.969238, 613.761353, 8.523270, 0, ''),
(2917, 4, 4640.804688, 623.999329, 8.377054, 0, ''),
(2917, 5, 4631.678711, 630.801086, 6.414999, 5000, 'SAY_REM_RAMP1_1'),
(2917, 6, 4633.533203, 632.476440, 6.509831, 0, 'ambush'),
(2917, 7, 4639.413574, 637.120789, 13.338119, 0, ''),
(2917, 8, 4642.352051, 637.668152, 13.437444, 0, ''),
(2917, 9, 4645.082031, 634.463989, 13.437208, 5000, 'SAY_REM_RAMP1_2'),
(2917, 10, 4642.345215, 637.584839, 13.435211, 0, ''),
(2917, 11, 4639.630859, 637.233765, 13.339752, 0, ''),
(2917, 12, 4633.363281, 632.462280, 6.488438, 0, ''),
(2917, 13, 4624.714844, 631.723511, 6.264030, 0, ''),
(2917, 14, 4623.525879, 629.718506, 6.201339, 5000, 'SAY_REM_BOOK'),
(2917, 15, 4623.452148, 630.369629, 6.218942, 0, 'SAY_REM_TENT1_1'),
(2917, 16, 4622.622070, 637.221558, 6.312845, 0, 'ambush'),
(2917, 17, 4619.755371, 637.386230, 6.312050, 5000, 'SAY_REM_TENT1_2'),
(2917, 18, 4620.027832, 637.367676, 6.312050, 0, ''),
(2917, 19, 4624.154785, 637.560303, 6.313898, 0, ''),
(2917, 20, 4622.967773, 634.016479, 6.294979, 0, ''),
(2917, 21, 4616.926758, 630.303284, 6.239193, 0, ''),
(2917, 22, 4614.546387, 616.983337, 5.687642, 0, ''),
(2917, 23, 4610.279297, 610.029419, 5.442539, 0, ''),
(2917, 24, 4601.149902, 604.111694, 2.054856, 0, ''),
(2917, 25, 4589.618164, 597.685730, 1.057147, 0, ''),
(2917, 26, 4577.588379, 592.145813, 1.120190, 0, 'SAY_REM_MOSS (?)'),
(2917, 27, 4569.848145, 592.177490, 1.260874, 5000, 'EMOTE_REM_MOSS (?)'),
(2917, 28, 4568.791992, 590.870911, 1.211338, 3000, 'SAY_REM_MOSS_PROGRESS (?)'),
(2917, 29, 4566.722656, 564.077881, 1.343084, 0, 'ambush'),
(2917, 30, 4568.269531, 551.958435, 5.004200, 0, ''),
(2917, 31, 4566.731934, 551.557861, 5.426314, 5000, 'SAY_REM_PROGRESS'),
(2917, 32, 4566.741699, 560.767639, 1.703257, 0, ''),
(2917, 33, 4573.916016, 582.566101, 0.749801, 0, ''),
(2917, 34, 4594.206055, 598.533020, 1.034056, 0, ''),
(2917, 35, 4601.194824, 604.283081, 2.060146, 0, ''),
(2917, 36, 4609.539551, 610.844727, 5.402220, 0, ''),
(2917, 37, 4624.800293, 618.076477, 5.851541, 0, ''),
(2917, 38, 4632.414063, 623.778442, 7.286243, 0, ''),
(2917, 39, 4645.915039, 621.983765, 8.579967, 0, ''),
(2917, 40, 4658.669922, 611.092651, 8.891747, 0, ''),
(2917, 41, 4671.924316, 599.752197, 16.01242, 5000, 'SAY_REM_REMEMBER'),
(2917, 42, 4676.976074, 600.649780, 17.82566, 5000, 'EMOTE_REM_END');

UPDATE `creature_template` SET `ScriptName` = 'npc_myranda_the_hag' WHERE `entry` = 11872;
