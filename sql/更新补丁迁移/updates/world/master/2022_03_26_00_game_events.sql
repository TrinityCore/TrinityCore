DELETE FROM `game_event` WHERE `eventEntry` in (130,131,132,133,134);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES 
(130, '2018-04-18 02:00:00', '2035-03-28 02:00:00', 90720, 10080, 592, 'World Quest Bonus Event', 0, 2),
(131, '2018-04-04 02:00:00', '2035-03-28 02:00:00', 90720, 10080, 563, 'Battleground Bonus Event', 0, 2),
(132, '2018-05-23 02:00:00', '2035-03-28 02:00:00', 90720, 10080, 564, 'Pet Battle Bonus Event', 0, 2),
(133, '2018-05-02 02:00:00', '2035-03-28 02:00:00', 90720, 10080, 561, 'Arena Skirmish Bonus Event', 0, 2),
(134, '2018-05-16 02:00:00', '2035-03-28 02:00:00', 90720, 10080, 591, 'Battle for Azeroth Dungeon Event', 0, 2);
