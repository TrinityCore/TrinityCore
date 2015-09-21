# remove approved accounts from banlist

DELETE FROM account_banned WHERE banreason = "New user waiting for approvement" AND active = 0;


