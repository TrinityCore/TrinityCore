DELETE FROM `Kitron_string` WHERE `entry` = 11010;
INSERT INTO `Kitron_string` (`entry`,`content_default`) VALUES
(11010, 'You didn''t get kicked out of the instance even if Player::CheckInstanceLoginValid() returned false and without .gm on flag');
