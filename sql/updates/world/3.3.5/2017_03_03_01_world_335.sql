-- Disable level 60 "Learn Flying" automated mails
DELETE FROM `world`.`mail_level_reward` WHERE  `level`=60 AND `raceMask`=690;
DELETE FROM `world`.`mail_level_reward` WHERE  `level`=60 AND `raceMask`=1101;
