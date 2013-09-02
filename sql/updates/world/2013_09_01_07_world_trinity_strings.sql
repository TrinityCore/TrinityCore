DELETE FROM `trinity_string` WHERE entry IN (749, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881);
INSERT INTO `trinity_string` (entry, content_default, content_loc1, content_loc2, content_loc3, content_loc4, content_loc5, content_loc6, content_loc7, content_loc8) VALUES
(749,'│ OS: %s - Latency: %u ms', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(872, 'Entered email is not equal to registration email, check input', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(873, 'The new emails do not match', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(874, 'The email was changed', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(875, 'Your email can''t be longer than 64 characters, email not changed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(876, 'Email not changed (unknown error)!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(877, 'Email change unnecessary, new email is equal to old email', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(878, 'Your email is: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(879, '│ Registration Email: %s - Email: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(880, 'Security Level: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(881, 'You require an email to change your password.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

UPDATE `command` SET help = 'Syntax: .account password $old_password $new_password $new_password [$email]\r\n\r\nChange your account password. You may need to check the actual security mode to see if email input is necessary.' WHERE name = 'account password';

UPDATE `command` SET help = 'Syntax: .account\r\n\r\nDisplay the access level of your account and the email adress if you possess the necessary permissions.' WHERE name = 'account';

DELETE FROM `command` WHERE name = 'account email';
INSERT INTO `command` (name, security, help) VALUES ('account email', 0, 'Syntax: .account email $oldemail $currentpassword $newemail $newemailconfirmation\r\n\r\n Change your account email. You may need to check the actual security mode to see if email input is necessary for password change');

DELETE FROM `command` WHERE name = 'account set sec email';
INSERT INTO `command` (name, security, help) VALUES ('account set sec email', 3, 'Syntax: .account set sec email $accountname $email $emailconfirmation\r\n\r\nSet the email for entered player account.');

DELETE FROM `command` WHERE name = 'account set sec regmail';
INSERT INTO `command` (name, security, help) VALUES ('account set sec regmail', 4, 'Syntax: .account set sec regmail $account $regmail $regmailconfirmation\r\n\r\nSets the regmail for entered player account.');
