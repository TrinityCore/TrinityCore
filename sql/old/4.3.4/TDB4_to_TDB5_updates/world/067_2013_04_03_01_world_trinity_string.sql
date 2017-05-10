-- Add Trinity String for Spirit Guide and wintergrasp battle mage
DELETE FROM `trinity_string` WHERE `entry` IN (20071,20072,20074,20073,20070,20075,20076,20077);
INSERT INTO `trinity_string`(`entry`,`content_default`) VALUES 
(20071, 'Guide me to the Sunken Ring Graveyard.'),
(20072, 'Guide me to the Broken Temple Graveyard.'),
(20074, 'Guide me to the Eastspark Graveyard.'),
(20073, 'Guide me to the Westspark Graveyard.'),
(20070, 'Guide me to the Fortress Graveyard.'),
(20075, 'Guide me back to the Horde landing camp.'),
(20076, 'Guide me back to the Alliance landing camp.'),
(20077, 'Queue for Wintergrasp.');
