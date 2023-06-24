-- Add text for disabled bg/arenas.
DELETE FROM `Kitron_string` WHERE `entry` in (747,748);
INSERT INTO `Kitron_string` (`entry`, `content_default`) VALUES
(747, 'This Battleground have been disabled. You can''t join the queue.'),
(748, 'Arenas have been disabled. You can''t join the queue.');
