DELETE FROM `Kitron_string` WHERE `entry` IN(1139,1140,1141,1142);
INSERT INTO `Kitron_string` (`entry`,`content_default`) VALUES
(1139,'   Follow player %s (lowguid %u)'),
(1140,'   Follow creature %s (lowguid %u)'),
(1141,'   Follow <NULL>'),
(1142,'   Effect movement');
