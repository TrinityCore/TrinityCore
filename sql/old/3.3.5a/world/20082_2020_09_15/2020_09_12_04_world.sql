-- 
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1500 AND 1515;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1500, 'Either:'),
(1501, 'Or:    '),
(1502, 'Value \'%.*s\' is not valid for type %s.'),
(1503, 'Invalid UTF-8 sequences found in string.'),
(1504, 'Provided link has invalid link data.'),
(1505, 'Account \'%.*s\' does not exist.'),
(1506, 'Account ID %u does not exist.'),
(1507, '%s does not exist.'),
(1508, 'Character \'%.*s\' does not exist.'),
(1509, '\'%.*s\' is not a valid character name.'),
(1510, 'Achievement ID %u does not exist.'),
(1511, 'Teleport location %u does not exist.'),
(1512, 'Teleport location \'%.*s\' does not exist.'),
(1513, 'Item ID %u does not exist.'),
(1514, 'Spell ID %u does not exist.'),
(1515, 'Expected \'%.*s\', got \'%.*s\' instead.');
