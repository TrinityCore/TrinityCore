-- rbac simplify
DELETE FROM `rbac_linked_permissions` WHERE `linkedid` IN (378,379,380,381,382,383,384,385,386,852,874);
DELETE FROM `rbac_permissions` WHERE `id` IN (378,379,380,381,382,383,384,385,386,852,874);
