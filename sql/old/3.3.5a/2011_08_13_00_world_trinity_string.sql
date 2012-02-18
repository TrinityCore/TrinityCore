DELETE FROM `trinity_string` WHERE `entry` IN (453, 550, 714, 716);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES 
(453,'Ban time remaining: %s, Banned by: %s, Reason: %s'),
(550,'Mute time remaining: %s'),
(716,'Map: %s, Area: %s'),
(714,'Map: %s, Area: %s, Zone: %s, Phase: %u');
