DELETE FROM `game_event` WHERE `eventEntry` IN (82, 83, 53, 54, 18, 19, 20, 21);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `announce`) VALUES
(82, '2020-01-03 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 435, 'Call to Arms: Battle for Gilneas!', 2),
(83, '2020-01-10 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 436, 'Call to Arms: Twim Peaks!', 2),
(18, '2020-01-31 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 283, 'Call to Arms: Alterac Valley!', 2),
(19, '2020-02-07 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 284, 'Call to Arms: Warsong Gulch!', 2),
(20, '2020-01-17 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 285, 'Call to Arms: Arathi Basin!', 2),
(21, '2020-01-24 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 353, 'Call to Arms: Eye of the Storm!', 2),
(53, '2020-02-14 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 400, 'Call to Arms: Strand of the Ancients!', 2),
(54, '2020-02-21 00:01:00', '2030-01-01 06:00:00', 80640, 6240, 420, 'Call to Arms: Isle of Conquest!', 2);
