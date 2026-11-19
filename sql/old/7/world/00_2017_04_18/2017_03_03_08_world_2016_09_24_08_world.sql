-- NPC 21217 The Lurker Below, emote (41) text
DELETE FROM `creature_text` WHERE `entry` = 21217;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21217, 0,0, '%s takes a deep breath.', 41, 0, 100, 0, 0, 0, 20021, 1, 'The Lurker Below - EMOTE_SPOUT');
