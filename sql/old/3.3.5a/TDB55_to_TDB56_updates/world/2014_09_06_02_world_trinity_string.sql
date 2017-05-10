DELETE FROM `trinity_string` WHERE `entry` IN (5045, 5046, 5047, 5048, 5049, 5050, 5051, 5052, 5053, 5054, 5055, 5056);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5045, 'Map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s'),
(5046, 'Player binds: %d'),
(5047, 'Group binds: %d'),
(5048, 'Unbinding map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s'),
(5049, 'Instances unbound: %d'),
(5050, 'Instances loaded: %d'),
(5051, 'Players in instances: %d'),
(5052, 'Instance saves: %d'),
(5053, 'Players bound: %d'),
(5054, 'Groups bound: %d'),
(5055, 'Map is not a dungeon.'),
(5056, 'Map has no instance data.');
