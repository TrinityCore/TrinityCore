-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = 200 WHERE `name` = '.rbac';
UPDATE `command` SET `permission` = 201 WHERE `name` = '.rbac account';
UPDATE `command` SET `permission` = 202 WHERE `name` = '.rbac account group';
UPDATE `command` SET `permission` = 203 WHERE `name` = '.rbac account group add';
UPDATE `command` SET `permission` = 204 WHERE `name` = '.rbac account group remove';
UPDATE `command` SET `permission` = 205 WHERE `name` = '.rbac account role';
UPDATE `command` SET `permission` = 206 WHERE `name` = '.rbac account role grant';
UPDATE `command` SET `permission` = 207 WHERE `name` = '.rbac account role deny';
UPDATE `command` SET `permission` = 208 WHERE `name` = '.rbac account role revoke';
UPDATE `command` SET `permission` = 209 WHERE `name` = '.rbac account permission';
UPDATE `command` SET `permission` = 210 WHERE `name` = '.rbac account permission grant';
UPDATE `command` SET `permission` = 211 WHERE `name` = '.rbac account permission deny';
UPDATE `command` SET `permission` = 212 WHERE `name` = '.rbac account permission revoke';
UPDATE `command` SET `permission` = 214 WHERE `name` = '.rbac account list groups';
UPDATE `command` SET `permission` = 215 WHERE `name` = '.rbac account list roles';
UPDATE `command` SET `permission` = 216 WHERE `name` = '.rbac account list permissions';
