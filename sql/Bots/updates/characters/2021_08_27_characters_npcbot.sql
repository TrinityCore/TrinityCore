-- An update for shifted roles
UPDATE `characters_npcbot` SET `roles` = (roles & 0x1) | ((roles & ~0x1) << 1);
