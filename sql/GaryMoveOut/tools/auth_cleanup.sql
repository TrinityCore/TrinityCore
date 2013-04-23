-- Execute in auth-database
-- REPLACE: `characters` with your characters database

-- CHARACTERS SECTION
DELETE FROM `characters`.`characters` WHERE `account` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `characters`.`account_data` WHERE `accountId` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `characters`.`account_instance_times` WHERE `accountId` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `characters`.`account_tutorial` WHERE `accountId` NOT IN (SELECT `id` FROM `account`);

-- AUTH SECTION
DELETE FROM `account_access` WHERE `id` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `account_access` WHERE `RealmID` != -1 AND `RealmID` NOT IN (SELECT `id` FROM `realmlist`);

DELETE FROM `account_banned` WHERE `id` NOT IN (SELECT `id` FROM `account`);

DELETE FROM `realmcharacters` WHERE `acctid` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `realmcharacters` WHERE `realmid` NOT IN (SELECT `id` FROM `realmlist`);

-- CUSTOM - ACCOUNT SAVING
-- DELETE FROM `account_preserved` WHERE `account` NOT IN (SELECT `id` FROM `account`);

-- CUSTOM - VOTESHOP
-- DELETE FROM `voteshop`.`voting` WHERE `voteshop`.`voting`.`id` NOT IN (SELECT `id` FROM `account`);