-- Create actual gameobjects
DELETE FROM `gameobject_template` WHERE `entry` IN (1649780,1649781,1649782);
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`faction`,`flags`,`size`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`data6`,`data7`,`data8`,`data9`,`data10`,`data11`,`data12`,`data13`,`data14`,`data15`,`data16`,`data17`,`data18`,`data19`,`data20`,`data21`,`data22`,`data23`,`AIName`,`ScriptName`,`WDBVerified`) VALUES
(1649780,0,5995,'Berserk Buff','','','',0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','go_powerup_berserking',0),
(1649781,0,5991,'Food Buff','','','',0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','go_powerup_food',0),
(1649782,5,8244,'Graveyard Teleporter','','','',0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',0);
 
-- Create actual creatures
DELETE FROM `creature_template` WHERE `entry` IN (731130,731131,731132,731133,731134);
INSERT INTO `creature_template` (`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction_A`,`faction_H`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`Health_mod`,`Mana_mod`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) VALUES
(731130,0,0,0,0,0,4449,27165,0,0,'Powerup Summoner','Invisible for Players','',0,80,80,0,35,35,0,1,1.14286,1,0,2,2,0,24,1,2000,0,1,33554432,8,0,0,0,0,0,1,1,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1,1,1,0,0,0,0,0,0,0,0,1,0,128,'npc_summon_powerups',0),
(731131,0,0,0,0,0,4449,27165,0,0,'PvP Island Teleporter','Invisible for Players','',0,80,80,0,35,35,0,1,1.14286,1,0,2,2,0,24,1,2000,0,1,33554432,8,0,0,0,0,0,1,1,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1,1,1,0,0,0,0,0,0,0,0,1,0,128,'npc_teleport_pvp_island',0),
(731132,0,0,0,0,0,4449,27165,0,0,'Mall Teleporter','Invisible for Players','',0,80,80,0,35,35,0,1,1.14286,1,0,2,2,0,24,1,2000,0,1,33554432,8,0,0,0,0,0,1,1,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1,1,1,0,0,0,0,0,0,0,0,1,0,128,'npc_teleport_mall',0),
(731133,0,0,0,0,0,4449,27165,0,0,'Player Kill Credit','Invisible for Players','',0,80,80,0,35,35,0,1,1.14286,1,0,2,2,0,24,1,2000,0,1,33554432,8,0,0,0,0,0,1,1,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1,1,1,0,0,0,0,0,0,0,0,1,0,128,'',0),
(731134,0,0,0,0,0,4449,27165,0,0,'Heal Kill Credit','Invisible for Players','',0,80,80,0,35,35,0,1,1.14286,1,0,2,2,0,24,1,2000,0,1,33554432,8,0,0,0,0,0,1,1,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1,1,1,0,0,0,0,0,0,0,0,1,0,128,'',0);
 
-- Spawn creatures
DELETE FROM `creature` WHERE `id` IN (731130,731131,731132,731133,731134);
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Powerup Summoner
(731130,0,1,1,0,0,-14667,-287.08,48.4846,0.0493581,300,0,0,5342,0,0,0,0,0),
-- PvP Island Teleporter
(731131,0,1,1,0,0,-14891.3,288.352,1.5458,1.89854,300,0,0,5342,0,0,0,0,0),
-- Mall Teleporter
(731132,0,1,1,0,0,-14821,-430.405,0.86809,0.220573,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14505.2,-111.901,0.964192,4.52376,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14613.1,-87.3758,0.84502,5.00758,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14763,-94.0055,2.21235,5.01462,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14608,-470.215,0.553057,1.48899,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14473.9,-209.112,11.897,3.3763,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14435.6,-380.371,3.98269,3.11083,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14728.1,-462.881,3.45376,1.76229,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14890.1,-180.312,1.15432,1.05936,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14892.3,-266.441,1.10542,0.400422,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14867.8,-356.118,2.3242,0.23075,300,0,0,5342,0,0,0,0,0),
(731132,0,1,1,0,0,-14496.6,-462.647,3.60131,2.34114,300,0,0,5342,0,0,0,0,0);
 
-- Spawn teleporter gameobjects
DELETE FROM `gameobject` WHERE `guid`=11676; -- Solid Chest
DELETE FROM `gameobject` WHERE `id`=1649782;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(1649782,0,1,1,-14890.5,288.069,1.47774,1.37626,0,0,0.635092,0.772437,300,0,1),
(1649782,0,1,1,-14613.1,-87.3758,0.84502,5.00758,0,0,0.595433,-0.803405,300,0,1),
(1649782,0,1,1,-14763,-94.0055,2.21235,5.01462,0,0,0.592599,-0.805498,300,0,1),
(1649782,0,1,1,-14608,-470.215,0.553057,1.48899,0,0,0.677601,0.73543,300,0,1),
(1649782,0,1,1,-14473.9,-209.112,11.897,3.3763,0,0,0.993122,-0.117086,300,0,1),
(1649782,0,1,1,-14435.6,-380.371,3.98269,3.11083,0,0,0.999882,0.0153787,300,0,1),
(1649782,0,1,1,-14728.1,-462.881,3.45376,1.76229,0,0,0.771468,0.636268,300,0,1),
(1649782,0,1,1,-14890.1,-180.312,1.15432,1.05936,0,0,0.505259,0.862968,300,0,1),
(1649782,0,1,1,-14892.3,-266.441,1.10542,0.400422,0,0,0.198876,0.980025,300,0,1),
(1649782,0,1,1,-14867.8,-356.118,2.3242,0.23075,0,0,0.115119,0.993352,300,0,1),
(1649782,0,1,1,-14496.6,-462.647,3.60131,2.34114,0,0,0.920973,0.389625,300,0,1),
(1649782,0,1,1,-14505.2,-111.901,0.964192,4.52376,0,0,0.770556,-0.637372,300,0,1),
(1649782,0,1,1,-14821,-430.405,0.86809,0.220573,0,0,0.110063,0.993925,300,0,1);
 
-- Clean up previously implemented addon template for a no-longer used NPC
DELETE FROM `creature_template_addon` WHERE `entry`=731132;
 
-- Spiritual Immunity on area enter
DELETE FROM `spell_area` WHERE `area`=43 AND `spell`=58729;
INSERT INTO `spell_area` (`spell`,`area`,`autocast`) VALUES
(58729,43,1);
 
-- Custom error if player killed another player of own IP address
SET @STRING := 3000;
DELETE FROM `trinity_string` WHERE `entry` IN (@STRING+0,@STRING+1,@STRING+2);
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES
(@STRING+0,"You've killed by a player who is playing with the same IP address as you are. You have been logged and warned.",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(@STRING+1,"You've been killed by a player who is playing with the same IP address as you are. You have been logged and warned.",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(@STRING+2,"You are in combat.",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
 