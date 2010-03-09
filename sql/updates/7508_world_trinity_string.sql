DELETE FROM `trinity_string` WHERE `entry` IN (6604,6605,6606,6607,6608,6609,6610,6611,6612);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(6604, 'You cannot say, yell or emote until you become level %d.'),
(6605, 'You cannot whisper until you become level %d.'),
(6606, 'You cannot write to channels until you become level %d.'),
(6607, 'You cannot use auction until you become level %d.'),
(6608, 'You cannot write tickets until you become level %d.'),
(6609, 'You cannot trade until you become level %d.'),
(6610, 'You cannot trade with characters lower than level %d.'),
(6611, 'You cannot send mail until you become level %d.'),
(6612, 'You cannot send mail to characters lower than level %d.');
