-- Delete 'Two side mail interaction', 'Allow say chat between factions' and 'Allow channel chat between factions' from Player group
DELETE FROM `rbac_group_roles` WHERE `groupId` = 1 AND `roleId` IN (19, 28, 30);

-- Delete 'Join channels withou announce' from Moderators group
DELETE FROM `rbac_group_roles` WHERE `groupId` = 2 AND `roleId` IN (31);

-- Add 'Allow two side charater accounts'
DELETE FROM `rbac_group_roles` WHERE `roleId` = 34;
INSERT INTO `rbac_group_roles` (`groupId`, `roleId`) VALUES (1, 34);
