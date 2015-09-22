-- Delete orphaned by missing account ids
DELETE FROM `account_access` WHERE `id` NOT IN ( SELECT `id` FROM `account` );
DELETE FROM `account_banned` WHERE `id` NOT IN ( SELECT `id` FROM `account` );
DELETE FROM `account_muted` WHERE `guid` NOT IN ( SELECT `id` FROM `account` );
DELETE FROM `logs_ip_actions` WHERE `account_id` NOT IN ( SELECT `id` FROM `account` );
DELETE FROM `rbac_account_permissions` WHERE `accountId` NOT IN ( SELECT `id` FROM `account` );
DELETE FROM `realmcharacters` WHERE `account_id` NOT IN ( SELECT `id` FROM `account` );

-- Delete orphaned by missing realm ids
DELETE FROM `logs` WHERE `realm` NOT IN ( SELECT `id` FROM `realmlist` );
DELETE FROM `realmcharacters` WHERE `realmid` NOT IN ( SELECT `id` FROM `realmlist` );
DELETE FROM `uptime` WHERE `realm` NOT IN ( SELECT `id` FROM `realmlist` );

-- Delete orphaned by missing rbac_permissions ids
DELETE FROM `rbac_account_permissions` WHERE `permissionId` NOT IN ( SELECT `id` FROM `rbac_permissions` );
DELETE FROM `rbac_default_permissions` WHERE `permissionId` NOT IN ( SELECT `id` FROM `rbac_permissions` );
DELETE FROM `rbac_linked_permissions` WHERE `id` NOT IN ( SELECT `id` FROM `rbac_permissions` );
DELETE FROM `rbac_linked_permissions` WHERE `linkedId` NOT IN ( SELECT `id` FROM `rbac_permissions` );
