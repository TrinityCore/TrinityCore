-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = 217 WHERE `name` = 'account';
UPDATE `command` SET `permission` = 218 WHERE `name` = 'account addon';
UPDATE `command` SET `permission` = 219 WHERE `name` = 'account create';
UPDATE `command` SET `permission` = 220 WHERE `name` = 'account delete';
UPDATE `command` SET `permission` = 221 WHERE `name` = 'account lock';
UPDATE `command` SET `permission` = 222 WHERE `name` = 'account lock country';
UPDATE `command` SET `permission` = 223 WHERE `name` = 'account lock ip';
UPDATE `command` SET `permission` = 224 WHERE `name` = 'account onlinelist';
UPDATE `command` SET `permission` = 225 WHERE `name` = 'account password';
UPDATE `command` SET `permission` = 226 WHERE `name` = 'account set';
UPDATE `command` SET `permission` = 227 WHERE `name` = 'account set addon';
UPDATE `command` SET `permission` = 228 WHERE `name` = 'account set gmlevel';
UPDATE `command` SET `permission` = 229 WHERE `name` = 'account set password';
