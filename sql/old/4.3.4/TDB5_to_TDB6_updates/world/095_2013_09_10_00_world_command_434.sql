/* cs_modify.cpp & cs_debug.cpp only 4.3.4 */

SET @id = 775;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'modify currency';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'debug phase';
