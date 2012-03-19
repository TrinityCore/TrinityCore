UPDATE `creature_template` set `VehicleId` = 436 WHERE `entry` = 36355;
UPDATE `creature_template` set `npcflag`=`npcflag`|0x1000000 WHERE `entry` IN (36355,36356);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (36355,36356);
INSERT INTO `npc_spellclick_spells` VALUES
(36355,66245,0,0,0,1,0,0,0),
(36356,66245,0,0,0,1,0,0,0);
