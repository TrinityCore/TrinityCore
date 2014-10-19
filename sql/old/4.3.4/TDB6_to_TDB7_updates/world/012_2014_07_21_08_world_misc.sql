--
-- UPDATE `npc_trainer` SET `spellcost`=100 WHERE `spell`=688;
DELETE FROM `creature_queststarter` WHERE `quest` IN (1598,1599,1470,1485,8344);
DELETE FROM `creature_questender` WHERE `quest` IN (1598,1599,1470,1485,8344);
-- UPDATE `creature` SET `position_z`=118.247 WHERE `guid`=93289;
-- UPDATE `creature` SET `position_z`=120.9 WHERE `guid`=92879;
