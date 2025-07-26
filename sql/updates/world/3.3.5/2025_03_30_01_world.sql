-- Object 'Wanted Poster' (142122) has same quests as 'Wanted Poster' (150075)
DELETE FROM `gameobject_queststarter` WHERE `id`=142122;
INSERT INTO `gameobject_queststarter` (`id`, `quest`) VALUES
(142122, 2781), -- WANTED: Caliph Scorpidsting
(142122, 2875); -- WANTED: Andre Firebeard
