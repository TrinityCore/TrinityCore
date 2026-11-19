UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `faction_A` = 0 OR `faction_H` = 0;
UPDATE `creature_template` SET `unit_class` = 1 WHERE `unit_class` = 0;
UPDATE `creature_template` SET `npcflag`=`npcflag`|16 WHERE `entry` IN (SELECT `entry` FROM `npc_trainer` WHERE `entry` < 100000);
