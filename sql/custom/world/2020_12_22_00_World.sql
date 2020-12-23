-- fix npc_vendor playerconditionid errors

UPDATE `npc_vendor` SET `PlayerConditionId` = 0 WHERE `PlayerConditionId` IN (15127, 23396, 40209, 50484, 54648, 54649, 58152, 69334);