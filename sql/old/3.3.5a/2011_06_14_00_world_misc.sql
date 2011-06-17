UPDATE `creature_template` set `VehicleId` = 129 WHERE `entry` = 28710;
UPDATE `creature_template` set `npcflag`=`npcflag`|0x1000000 WHERE `entry` IN (28710,29838,33114,33167,34161);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (28710,29838,33114,33167,34161);
INSERT INTO `npc_spellclick_spells` VALUES
(28710,46598,0,0,0,1,0,0,0),
(29838,46598,0,0,0,1,0,0,0),
(33114,46598,0,0,0,1,0,0,0),
(33167,46598,0,0,0,1,0,0,0),
(34161,46598,0,0,0,1,0,0,0);

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 29838;
INSERT INTO `vehicle_template_accessory` VALUES
(29838,29836,0,0,'Drakkari Battle Rider on Drakkari Rhino, not minion',6,30000);

DELETE FROM `creature` WHERE `id` = 29836;
