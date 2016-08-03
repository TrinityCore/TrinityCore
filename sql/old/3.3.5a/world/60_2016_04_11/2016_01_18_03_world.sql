--
DELETE FROM `creature_text` WHERE `entry` = 11856;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(11856, 0, 0, "Let's go before they find out I'm free!", 12, 0, 100, 1, 0, 0, 8327, 0, 'Kaya SAY_START'),
(11856, 1, 0, "Look out! We're under attack!", 12, 0, 100, 5, 0, 0, 8328, 0, 'Kaya SAY_AMBUSH'),
(11856, 2, 0, "Thank you for helping me. I know my way back from here.", 12, 0, 100, 3, 0, 0, 8329, 0, 'Kaya SAY_END');
