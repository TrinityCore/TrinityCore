DELETE FROM `trinity_string` WHERE `entry` IN (749, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(749,'│ OS: %s - Latency: %u ms'),
(872, 'Entered email is not equal to registration email, check input'),
(873, 'The new emails do not match'),
(874, 'The email was changed'),
(875, 'Your email can''t be longer than 64 characters, email not changed!'),
(876, 'Email not changed (unknown error)!'),
(877, 'Email change unnecessary, new email is equal to old email'),
(878, 'Your email is: %s'),
(879, '│ Registration Email: %s - Email: %s'),
(880, 'Security Level: %s'),
(881, 'You require an email to change your password.');

UPDATE `command` SET `help` = 'Syntax: .account password $old_password $new_password $new_password [$email]\r\n\r\nChange your account password. You may need to check the actual security mode to see if email input is necessary.' WHERE name = 'account password';
UPDATE `command` SET `help` = 'Syntax: .account\r\n\r\nDisplay the access level of your account and the email adress if you possess the necessary permissions.' WHERE name = 'account';

DELETE FROM `command` WHERE `name` = 'account email';
DELETE FROM `command` WHERE `name` = 'account set sec email';
DELETE FROM `command` WHERE `name` = 'account set sec regmail';

INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('account email', 263, 'Syntax: .account email $oldemail $currentpassword $newemail $newemailconfirmation\r\n\r\n Change your account email. You may need to check the actual security mode to see if email input is necessary for password change'),
('account set sec email', 265, 'Syntax: .account set sec email $accountname $email $emailconfirmation\r\n\r\nSet the email for entered player account.'),
('account set sec regmail', 266, 'Syntax: .account set sec regmail $account $regmail $regmailconfirmation\r\n\r\nSets the regmail for entered player account.');
