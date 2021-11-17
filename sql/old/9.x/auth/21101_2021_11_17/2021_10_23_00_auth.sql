-- rbac simplify
DELETE FROM `rbac_linked_permissions` WHERE `linkedid` IN (834,799,800,801);
DELETE FROM `rbac_permissions` WHERE `id` IN (834,799,800,801);
