
-- adding full Admin rights to account id 1
SET @ACCOUNTID :=1;
DELETE FROM account_access WHERE id = @ACCOUNTID;
INSERT INTO account_access VALUES (@ACCOUNTID, 4, -1);
DELETE FROM rbac_account_groups WHERE accountId = @ACCOUNTID;
INSERT INTO rbac_account_groups (accountId, groupId, realmId) VALUES (@ACCOUNTID, 1, -1);
INSERT INTO rbac_account_groups (accountId, groupId, realmId) VALUES (@ACCOUNTID, 2, -1);
INSERT INTO rbac_account_groups (accountId, groupId, realmId) VALUES (@ACCOUNTID, 3, -1);
INSERT INTO rbac_account_groups (accountId, groupId, realmId) VALUES (@ACCOUNTID, 4, -1);
