-- 
DELETE FROM `command` WHERE `name` LIKE 'account%';

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 366 AND 382;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(366, '### USAGE: .account set addon [<accountname>] <expansion>
Sets the specified account\'s, or targeted player\'s account\'s expansion level. 0 = WoW, 1 = TBC, 2 = WotLK.'),
(367, '### USAGE: .account set sec regmail <accountname> <email> <confirm email>
Replaces the registration email on record for the specified account.'),
(368, '### USAGE: .account set sec email <accountname> <email> <confirm email>
Replaces the email on record for the specified account.'),
(369, '### USAGE: .account set 2fa <accountname> <secret>
Provide a base32 encoded secret to setup two-factor authentication for the account.
Specify \'off\' to disable two-factor authentication for the account.'),
(370, '### USAGE: .account set seclevel [<accountname>] <level> [<realm>]
Set the security level for the specified account, or the targeted player\'s account, to the specified level on the specified realm.
Cannot be used on self. Levels range from 0 (player) to 3 (administrator). Realm ID defaults to -1 (all realms).'),
(371, '### USAGE: .account set password <accountname> <password> <confirm password>
Changes the password for the specified account.'),
(372, '### USAGE: .account 2fa setup
Begins setup of two-factor authentication for this account.'),
(373, '### USAGE: .account 2fa remove <token>
Provide a current 2FA token to disable two-factor authentication for this account.'),
(374, '### USAGE: .account addon <expansion>
Sets this account\'s expansion level. 0 = WoW, 1 = TBC, 2 = WotLK.'),
(375, '### USAGE: .account create <name> <password> [<email>]
Creates a new account with the specified password and email (if specified).'),
(376, '### USAGE: .account delete <name>
Deletes the specified account. Cannot be used on self while connected.'),
(377, '### USAGE: .account email <old email> <password> <new email> <confirm new email>
Changes the email on record for this account.'),
(378, '### USAGE: .account onlinelist
Shows a list of all currently-connected accounts.'),
(379, '### USAGE: .account lock country <on/off>
While enabled, you will only be able to log in from IP addresses in your current country.'),
(380, '### USAGE: .account lock ip <on/off>
While enabled, you will only be able to log in from your current IP address.'),
(381, '### USAGE: .account password <old password> <new password> <confirm password> [<email>]
Changes the password for this account.
Whether you need to specify your email address depends on the server settings.'),
(382, '### USAGE: .account
Prints information about the current account.');
