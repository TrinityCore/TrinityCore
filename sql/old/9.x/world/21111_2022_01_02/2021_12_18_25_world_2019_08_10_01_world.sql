-- 
DELETE FROM `command` WHERE `name` LIKE 'account 2fa%';
DELETE FROM `command` WHERE `name`='account set 2fa';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('account 2fa', 378, 'Syntax: .account 2fa <setup/remove>'),
('account 2fa setup', 379, 'Syntax: .account 2fa setup

Sets up two-factor authentication for this account.'),
('account 2fa remove', 380, 'Syntax: .account 2fa remove <token>

Disables two-factor authentication for this account, if enabled.'),
('account set 2fa', 381, 'Syntax: .account set 2fa <account> <secret/off>

Provide a base32 encoded secret to setup two-factor authentication for the account.
Specify \'off\' to disable two-factor authentication for the account.');



DELETE FROM `trinity_string` WHERE `entry` BETWEEN 88 AND 95;
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 188 AND 190;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(88, "Two-factor authentication commands are not properly setup."),
(89, "Two-factor authentication is already enabled for this account."),
(90, "Invalid two-factor authentication token specified."),
(91, "In order to complete setup, you'll need to set up the device you'll be using as your second factor.

Your 2FA key: %s

Once you have set up your device, confirm by running .account 2fa setup <token> with the generated token."),
(92, "Two-factor authentication has been successfully set up."),
(93, "Two-factor authentication is not enabled for this account."),
(94, "To remove two-factor authentication, please specify a fresh two-factor token from your authentication device."),
(95, "Two-factor authentication has been successfully disabled."),
(188, "The provided two-factor authentication secret is too long."),
(189, "The provided two-factor authentication secret is not valid."),
(190, "Successfully enabled two-factor authentication for '%s' with the specified secret.");
