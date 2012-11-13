-- Pathing for Ol' Sooty Entry: 1225
SET @NPC := 8877;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawntimesecs`=1200,`spawndist`=0,`MovementType`=2,`position_x`=-5716.181152,`position_y`=-3110.810791,`position_z`=316.686523 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5716.181152,-3110.810791,316.686523,0,0,0,100,0), 
(@PATH,2,-5716.187012,-3093.080078,325.600677,0,0,0,100,0), 
(@PATH,3,-5712.214355,-3090.297607,327.738647,0,0,0,100,0), 
(@PATH,4,-5705.484375,-3092.523438,329.362366,0,0,0,100,0), 
(@PATH,5,-5681.826660,-3110.568848,338.121887,0,0,0,100,0), 
(@PATH,6,-5659.498535,-3122.215576,344.336151,0,0,0,100,0), 
(@PATH,7,-5639.585938,-3124.536133,348.404938,0,0,0,100,0), 
(@PATH,8,-5618.112793,-3110.905762,360.618225,0,0,0,100,0), 
(@PATH,9,-5621.486816,-3096.315918,368.247772,0,0,0,100,0), 
(@PATH,10,-5632.212891,-3078.608398,374.990936,0,0,0,100,0), 
(@PATH,11,-5629.793457,-3056.124023,384.465576,0,0,0,100,0), 
(@PATH,12,-5642.278809,-3036.872314,385.471649,0,0,0,100,0), 
(@PATH,13,-5609.369141,-3006.883301,386.288177,0,0,0,100,0), 
(@PATH,14,-5643.634277,-3036.388672,385.531891,0,0,0,100,0), 
(@PATH,15,-5630.174805,-3057.015869,384.385712,0,0,0,100,0), 
(@PATH,16,-5629.840332,-3065.496338,381.129578,0,0,0,100,0), 
(@PATH,17,-5634.866211,-3078.448975,374.489044,0,0,0,100,0), 
(@PATH,18,-5620.416504,-3101.081543,364.819855,0,0,0,100,0), 
(@PATH,19,-5624.629395,-3117.040527,354.493805,0,0,0,100,0), 
(@PATH,20,-5644.949707,-3125.081787,347.271362,0,0,0,100,0), 
(@PATH,21,-5660.741699,-3121.580566,343.975922,0,0,0,100,0), 
(@PATH,22,-5676.210938,-3111.586914,340.021484,0,0,0,100,0), 
(@PATH,23,-5691.895508,-3102.994385,333.646698,0,0,0,100,0), 
(@PATH,24,-5711.662109,-3088.433594,328.761566,0,0,0,100,0), 
(@PATH,25,-5717.663574,-3099.033691,321.686920,0,0,0,100,0), 
(@PATH,26,-5705.214844,-3132.324219,315.837585,0,0,0,100,0), 
(@PATH,27,-5679.014160,-3185.046875,319.508057,0,0,0,100,0);

-- Set chaining for Doomguard minion quests
UPDATE `quest_template` SET `PrevQuestId`=7581 WHERE `Id`=7582; -- Complete The Prison's Bindings before The Prison's Casing
UPDATE `quest_template` SET `PrevQuestId`=7582 WHERE `Id`=7583; -- Complete The Prison's Casing before Suppression




-- update quest linking for Egg Collection
UPDATE `quest_template` SET `NextQuestId`=5522 WHERE `Id`=4735;
-- --------------------------------------------------------------------------------------------------------------
-- Test of Endurance (Gecko32)
DELETE FROM `event_scripts` WHERE `id`=747 AND `command`=10 AND `datalong`=4100; -- Remove summon of Screeching Harpies
UPDATE `event_scripts` SET `delay`=5 WHERE `id`=747 AND `command`=10 AND `datalong`=4490; -- Lower summon time of Grenka Bloodscreech from 40 sec to 5 sec
-- --------------------------------------------------------------------------------------------------------------
-- Tapper Swindlekeg (24711) fix Alliance faction exploitation (nelgano)
UPDATE `creature_template` SET `unit_flags`=4864 WHERE `entry`=24711;
-- --------------------------------------------------------------------------------------------------------------
DELETE FROM `gameobject` WHERE `guid`=335;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(335,1684,1,1,1,1524.929,-4371.182,17.94367,1.62046,0,0,0,1,300,100,1);

DELETE FROM `gameobject` WHERE `guid`IN (335,);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(335,324,1,1,1,-6314,507.647,7.651,0.496,0,0,0,0,2700,100,1),
(347,1684,1,1,1,1524.929,-4371.182,17.94367,1.62046,0,0,0,1,300,100,1);

-- Fix Jormungar Tunneler
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26467;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=26467;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26467 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26467,0,0,0,11,0,100,0,0,0,0,0,11,47677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jormungar Tunneler - On spawn - Spellcast Jormungar Tunnel Passive'),
(26467,0,1,0,21,0,100,0,0,0,0,0,11,47677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jormungar Tunneler - On reached homeposition - Spellcast Jormungar Tunnel Passive'),
(26467,0,2,0,1,0,100,0,3000,5000,15000,18000,11,51879,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jormungar Tunneler - On update (IC) - Spellcast Corrode Flesh'),
(26467,0,3,0,4,0,100,0,0,0,0,0,28,47677,0,0,0,0,0,1,0,0,0,0,0,0,0,'Jormungar Tunneler - On aggro - Remove Jormungar Tunnel Passive');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Update Fjord Hawk: Lots of these had incorrect movement.
DELETE FROM `creature_addon` WHERE `guid` IN (112058,112059,112088,112089,112091,112114,112115,112141,112142,112149,112150,112151,112152,112153,112154,112155,112156,112157,112158);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(112058,0,1,1,''),(112059,0,1,1,''),(112088,0,1,1,''),
(112089,0,1,1,''),(112091,0,1,1,''),(112114,0,1,1,''),
(112115,0,1,1,''),(112141,0,1,1,''),(112142,0,1,1,''),
(112149,0,1,1,''),(112150,0,1,1,''),(112151,0,1,1,''),
(112152,0,1,1,''),(112153,0,1,1,''),(112154,0,1,1,''),
(112155,0,1,1,''),(112156,0,1,1,''),(112157,0,1,1,''),(112158,0,1,1,'');
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (112058,112059,112088,112089,112091,112114,112115,112141,112142,112149,112150,112151,112152,112153,112154,112155,112156,112157,112158);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- SAI for Lashers
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` BETWEEN 88228 AND 88237;
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` BETWEEN 131438 AND 131457;
UPDATE `creature_addon` SET `auras`='' WHERE `guid`=131452;
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` IN (106897,106898,106899,106900,106902,106903,106909,106910,106911,106912,106913,106914,106915,106916,106917,106918);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN(27254,30845,34300);
DELETE FROM `creature_ai_scripts` WHERE `creature_id`IN(27254,30845,34300);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27254,30845,34300) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Emerald Lasher
(27254,0,0,2,11,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On spawn - Set unitfield_bytes1 9 (submerged)'),
(27254,0,1,2,21,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On reached homeposition - Set unitfield_bytes1 9 (submerged)'),
(27254,0,2,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - Linked with event 0 or 1 - Disable combat movement'),
(27254,0,3,0,4,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On aggro - Spellcast Stand'),
(27254,0,4,0,0,0,100,0,1500,1500,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Emerald Lasher - On update (IC) - Enable combat movement'),
(27254,0,5,0,0,0,100,0,4000,7000,9000,13000,11,51901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Emerald Lasher - On update (IC) - Spellcast Dream Lash'),
-- Living Lasher
(30845,0,0,2,11,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On spawn - Set unitfield_bytes1 9 (submerged)'),
(30845,0,1,2,21,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On reached homeposition - Set unitfield_bytes1 9 (submerged)'),
(30845,0,2,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - Linked with event 0 or 1 - Disable combat movement'),
(30845,0,3,0,4,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On aggro - Spellcast Stand'),
(30845,0,4,0,0,0,100,0,1500,1500,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Living Lasher - On update (IC) - Enable combat movement'),
(30845,0,5,0,0,0,100,0,4000,7000,9000,13000,11,51901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Living Lasher - On update (IC) - Spellcast Dream Lash'),
-- 34300 Mature Lasher
(34300,0,0,2,11,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On spawn - Set unitfield_bytes1 9 (submerged)'),
(34300,0,1,2,21,0,100,0,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On reached homeposition - Set unitfield_bytes1 9 (submerged)'),
(34300,0,2,0,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - Linked with event 0 or 1 - Disable combat movement'),
(34300,0,3,0,4,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On aggro - Spellcast Stand'),
(34300,0,4,0,0,0,100,0,1500,1500,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mature Lasher - On update (IC) - Enable combat movement'),
(34300,0,5,0,0,0,100,0,4000,7000,9000,13000,11,51901,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mature Lasher - On update (IC) - Spellcast Dream Lash');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Secrets of the Scourge
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `entry`=12312;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Icehorn updates from sniffs
UPDATE `creature_template` SET `speed_run`=0.9920629, `rank`=4, `unit_flags`=32832, `family`=43, `type_flags`=65537 WHERE `entry`=32361;
DELETE FROM `creature_template_addon` WHERE `entry`=32361;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(32361,0,0,1,'60915');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Dragonblight optical improvements
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (27203,30058);
UPDATE `creature_template` SET `inhabitType`=4 WHERE `entry`=30078;
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (131075,131077);
UPDATE `creature_addon` SET `auras`='42048' WHERE `guid`=131066;
UPDATE `creature_addon` SET `auras`='42049' WHERE `guid`=106614;
UPDATE `creature_addon` SET `auras`='42050' WHERE `guid`=131068;
UPDATE `creature_addon` SET `auras`='42051' WHERE `guid`=106634;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (27222,27223,30078);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-102199,-105487,-105488,-105489,-105495,-131055,-131056,-131058,-131059) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-102199,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Footman - On reset - Set event phase 1'),
(-102199,0,1,2,1,1,100,0,2000,2000,12000,14000,11,48115,0,0,0,0,0,19,27222,30,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 1) - Spellcast Shoot on Archery Target'),
(-102199,0,2,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 1) - Set event phase 2'),
(-102199,0,3,4,1,2,100,0,16000,18000,16000,18000,11,48117,0,0,0,0,0,19,27223,30,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 2) - Spellcast Shoot on Archery Target'),
(-102199,0,4,0,61,2,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Footman - On OOC update (phase 2) - Set event phase 4'),
(-105487,0,0,0,1,0,100,0,2000,2000,0,0,11,55840,0,0,0,0,0,10,107492,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Blue Wyrmrest Warden Beam'),
(-105488,0,0,0,1,0,100,0,2000,2000,0,0,11,55841,0,0,0,0,0,10,107491,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Yellow Wyrmrest Warden Beam'),
(-105489,0,0,0,1,0,100,0,2000,2000,0,0,11,55841,0,0,0,0,0,10,107491,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Yellow Wyrmrest Warden Beam'),
(-105495,0,0,0,1,0,100,0,2000,2000,0,0,11,55840,0,0,0,0,0,10,107492,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Blue Wyrmrest Warden Beam'),
(-131055,0,0,0,1,0,100,0,2000,2000,0,0,11,55838,0,0,0,0,0,10,131075,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Green Wyrmrest Warden Beam'),
(-131056,0,0,0,1,0,100,0,2000,2000,0,0,11,55824,0,0,0,0,0,10,131077,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Red Wyrmrest Warden Beam'),
(-131058,0,0,0,1,0,100,0,2000,2000,0,0,11,55838,0,0,0,0,0,10,131075,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Green Wyrmrest Warden Beam'),
(-131059,0,0,0,1,0,100,0,2000,2000,0,0,11,55824,0,0,0,0,0,10,131077,0,0,0,0,0,0,'Warden of the Chamber - On reset - Spellcast Red Wyrmrest Warden Beam');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Borean Tundra visual improvement and missing spawn
SET @GOGUID :=356; -- need 1 set by TDB
SET @GUID :=43460; -- need 3 set by TDB
DELETE FROM `gameobject` WHERE `guid`=@GOGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GOGUID,187879,571,1,1,4207.366,4056.894,91.62077,2.792518,0,0,0.984807,0.1736523,300,100,1);
DELETE FROM `creature` WHERE `guid` in (@GUID+0,@GUID+1,@GUID+2);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,24021,571,1,1,21999,0,4207.475,4056.687,93.53715,2.094395,300,0,0,42,0,0,0,0,0),
(@GUID+1,23837,571,1,1,11686,0,4207.471,4056.705,93.66189,3.979351,300,0,0,42,0,0,0,0,0),
(@GUID+2,24957,571,1,1,0,0,4200.877,4056.888,92.28766,6.25263,300,0,0,7185,7196,0,0,0,0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=24957 AND `source_type`=0 AND `id` IN (1,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24957,0,1,0,11,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,'Cult Plaguebringer - On spawn - Spellcast Plague Cauldron Beam'),
(24957,0,3,0,21,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,'Cult Plaguebringer - On reached homeposition - Spellcast Plague Cauldron Beam');
UPDATE `creature_addon` SET `auras`='45797' WHERE `guid` IN (98730,115941);
DELETE FROM `creature_addon` WHERE `guid` IN (@GUID+0,@GUID+1);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@GUID+0,0,0,1,'45797'),
(@GUID+1,0,0,1,'45797');


SET @GUID :=43494; -- need 8 set by TDB
SET @OGUID :=5681; -- need 3 set by TDB

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9426 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9615 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9426,0,0, 'Remove the Eye of the Prophets from the idol''s face.',1,1,0,0,0,0, ''),
(9615,1,0, 'I need another of your elixirs, Drakuru.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9426 AND `text_id` IN (12669,12670);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9426,12669),(9426,12670);

-- Creature Template update from sniff
UPDATE `creature_template` SET `minLevel`=70, `maxLevel`=70, `unit_flags`=33024, `AIName`='SmartAI' WHERE `entry` IN (26500);
UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=33024, `AIName`='SmartAI' WHERE `entry` IN (26543,26701,26787);

UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=61 WHERE `item`=35799 AND `entry`=26447;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=58 WHERE `item`=35799 AND `entry`=26425;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE `item`=35836;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=49 WHERE `item`=36743 AND `entry`=26704;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=50 WHERE `item`=36743 AND `entry`=27554;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=51 WHERE `item`=36758 AND `entry`=26795;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=48 WHERE `item`=36758 AND `entry`=26797;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=66 WHERE `item`=38303 AND `entry`=26620;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=67 WHERE `item`=38303 AND `entry`=26639;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=15 WHERE `item`=38303 AND `entry`=27431;

UPDATE `creature_involvedrelation` SET `id`=26543 WHERE `quest`=12007;
UPDATE `creature_involvedrelation` SET `id`=26701 WHERE `quest`=12802;
UPDATE `creature_involvedrelation` SET `id`=26787 WHERE `quest`=12068;
UPDATE `creature_questrelation` SET `id`=26543 WHERE `quest`=12042;
UPDATE `creature_questrelation` SET `id`=26701 WHERE `quest`=12068;
UPDATE `creature_questrelation` SET `id`=26787 WHERE `quest`=12238;

DELETE FROM `creature_text` WHERE `entry`=26500;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26500,0,0,'I''ll be waitin'' for ya, mon.',15,0,100,0,0,0,'Image of Drakuru');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47110;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9426 AND `SourceEntry`=12670;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9426 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9615 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47110,0,0,31,0,3,26498,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 01'),
(13,1,47110,0,1,31,0,3,26559,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 02'),
(13,1,47110,0,2,31,0,3,26700,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 03'),
(13,1,47110,0,3,31,0,3,26789,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 04'),
(13,1,47110,0,4,31,0,3,28015,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 05'),
(14,9426,12670,0,0,2,0,35806,1,1,0,0,'','Seer of Zeb''Halak - Show different gossip if player has item Eye of the Propehts'),
(15,9426,0,0,0,9,0,12007,0,0,0,0,'','Seer of Zeb''Halak - Show gossip option if player has taken quest 12007'),
(15,9426,0,0,0,2,0,35806,1,1,1,0,'','Seer of Zeb''Halak - Show gossip option if player has not item Eye of the Propehts'),
(15,9615,1,0,0,8,0,11990,0,0,0,0,'','Drakuru - Show gossip option if player has rewarded quest 11990'),
(15,9615,1,0,0,8,0,12238,0,0,1,0,'','Drakuru - Show gossip option if player has not rewarded quest 12238'),
(15,9615,1,0,0,2,0,35797,1,1,1,0,'','Drakuru - Show gossip option if player has not item Drakuru''s Elixir');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=188458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26498,26559,26700,26789);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26498,26500,26543,26559,26700,26701,26787,26789) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26423 AND `source_type`=0 AND `id` IN (2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=188458 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26423,0,2,3,62,0,100,0,9615,1,0,0,85,50021,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - Invoker spellcast Replace Drakuru''s Elixir'),
(26423,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - Close gossip'),
(26498,0,0,0,8,0,100,0,47110,0,0,0,11,47117,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 01 - On spellhit - Spellcast Script Cast Summon Image of Drakuru'),
(26500,0,0,1,19,0,100,0,12007,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Say text'),
(26500,0,1,0,61,0,100,0,12007,0,0,0,11,47122,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru'),
(26543,0,0,1,19,0,100,0,12042,0,0,0,11,47308,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 02'),
(26559,0,0,0,8,0,100,0,47110,0,0,0,11,47149,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 02 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 02'),
(26700,0,0,0,8,0,100,0,47110,0,0,0,11,47316,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 03 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 03'),
(26701,0,0,1,19,0,100,0,12068,0,0,0,11,47403,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 03'),
(26787,0,0,1,19,0,100,0,12238,0,0,0,11,48417,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 04'),
(26789,0,0,0,8,0,100,0,47110,0,0,0,11,47405,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 04 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 04'),
(188458,1,0,1,62,0,100,0,9426,0,0,0,85,47293,0,0,0,0,0,7,0,0,0,0,0,0,0,'Seer of Zeb''Halak - On gossip option select - Invoker spellcast Create Eye of the Prophets'),
(188458,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Seer of Zeb''Halak - On gossip option select - Close gossip');

DELETE FROM `spell_scripts` WHERE `id` IN (47117,47149,47316,47405,50439);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(47117,0,0,15,47118,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru - Spellcast Envision Drakuru
(47149,0,0,15,47150,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru 02 - Spellcast Envision Drakuru
(47316,0,0,15,47317,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru 03 - Spellcast Envision Drakuru
(47405,0,0,15,47406,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru 04 - Spellcast Envision Drakuru
(50439,0,0,15,50440,2,0,0,0,0,0); -- Script Cast Summon Image of Drakuru 05 - Spellcast Envision Drakuru

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-47122,-47308,-47403,-48417);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-47122,-47118,0,'On Strip Detect Drakuru fade - Remove Envision Drakuru'),
(-47308,-47150,0,'On Strip Detect Drakuru 02 fade - Remove Envision Drakuru'),
(-47403,-47317,0,'On Strip Detect Drakuru 03 fade - Remove Envision Drakuru'),
(-48417,-47406,0,'On Strip Detect Drakuru 04 fade - Remove Envision Drakuru');

DELETE FROM `creature` WHERE `guid` in (@GUID+0,@GUID+1,@GUID+2,@GUID+3,@GUID+4,@GUID+5,@GUID+6,@GUID+7);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,26498,571,1,1,19595,0,3386.607,-1805.944,115.2497,3.001966,300,0,0,0,0,0,0,0,0),
(@GUID+1,26500,571,1,1,0,0,3386.272,-1805.434,115.4441,4.939282,300,0,0,0,0,0,0,0,0),
(@GUID+2,26559,571,1,1,19595,0,4243.962,-2024.805,238.2487,1.411705,300,0,0,0,0,0,0,0,0),
(@GUID+3,26543,571,1,1,0,0,4243.962,-2024.805,238.2487,1.411705,300,0,0,0,0,0,0,0,0),
(@GUID+4,26700,571,1,1,19595,0,4523.894,-3472.863,228.2441,4.695459,300,0,0,0,0,0,0,0,0),
(@GUID+5,26701,571,1,1,0,0,4523.894,-3472.863,228.2441,4.695459,300,0,0,0,0,0,0,0,0),
(@GUID+6,26787,571,1,1,0,0,4599.709,-4876.9,48.95556,0.719772,300,0,0,0,0,0,0,0,0),
(@GUID+7,26789,571,1,1,19595,0,4599.709,-4876.9,48.95556,0.719772,300,0,0,0,0,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (26500,26543,26701,26787);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26500,0,0,65536,1,0,'43167 47119'),
(26543,0,0,65536,1,0,'43167 47119'),
(26701,0,0,65536,1,0,'43167 47119'),
(26787,0,0,65536,1,0,'43167 47119');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,188600,571,1,1,3980.721,-1956.352,210.6624,1.169369,0,0,0,1,120,255,1),
(@OGUID+1,188600,571,1,1,3957.188,-1908.295,209.97,0.8901166,0,0,0,1,120,255,1),
(@OGUID+2,188600,571,1,1,3964.761,-1884.524,208.2739,1.692969,0,0,0,1,120,255,1);

-- Fix [Q]{A/H} Meet At The Grave
UPDATE `creature_template_addon` SET `auras`='10848' WHERE `entry`=9299; -- allow to be seen in world of death
UPDATE `creature_template` SET `npcflag`=32770,`unit_flags`=768 WHERE `entry`=9299; -- makes unseen in world of living

DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (15198, 47937);
INSERT INTO `player_factionchange_items` (`race_A`, `alliance_id`, `commentA`, `race_H`, `horde_id`, `commentH`) VALUES
(0, 15198, 'Knight\'s Colors', 0, 15199, 'Stone Guard\'s Herald'),
(0, 47937, 'Girdle of the Nether Champion', 0, 48009, 'Belt of the Nether Champion');

UPDATE `game_event` SET `start_time`= '2012-11-18 01:00:00' WHERE `eventEntry`=26;