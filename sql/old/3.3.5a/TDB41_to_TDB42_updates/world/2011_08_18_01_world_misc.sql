UPDATE `creature_template` SET `npcflag`=`npcflag`|0x1000000,`VehicleId`=165,`spell1`=54420,`InhabitType`=5 WHERE `entry`=29403;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=29403;
INSERT INTO `npc_spellclick_spells` VALUES
(29403,49641,0,0,0,1,0,0,0);

DELETE FROM `spell_scripts` WHERE `id`=54420;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(54420,1,0,18,0,0,0,0,0,0,0);

