DELETE FROM gossip_menu WHERE entry=37552;
INSERT INTO gossip_menu VALUES (37552, 537552);

DELETE FROM npc_text WHERE id = 537552;
INSERT INTO npc_text (ID, text0_0) VALUES (537552, 'It seems these are the remains that Thalorien was looking for, the last carrier of Quel\'Delar');

-- NPCs
DELETE FROM `creature_template` WHERE `entry` IN (37552, 37205, 37542, 37541, 37539, 37538);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(37552, 0, 0, 0, 0, 0, 30659, 0, 0, 0, 'Thalorien Dawnseeker\'s Remains', '', '', 0, 80, 80, 0, 35, 35, 1, 1, 1.14286, 1, 1, 0, 0, 0, 0, 1, 0, 0, 2, 32772, 44, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_thalorien', 12340),
(37205, 0, 0, 0, 0, 0, 30570, 0, 0, 0, 'Thalorien Dawnseeker', '', '', 0, 80, 80, 0, 35, 35, 0, 1, 1.14286, 1, 1, 400, 600, 0, 472, 2, 1500, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4096, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 10.3181, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 12340),
(37542, 0, 0, 0, 0, 0, 30657, 0, 0, 0, 'Morlen Coldgrip', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 1, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 7.076, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340),
(37541, 0, 0, 0, 0, 0, 30651, 30653, 30654, 0, 'Crypt Raider', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 3.538, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340),
(37539, 0, 0, 0, 0, 0, 30647, 30648, 30649, 30650, 'Ghoul Invader', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 2.9483, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340),
(37538, 0, 0, 0, 0, 0, 30645, 30644, 30643, 30646, 'Scourge Zombie', '', '', 0, 80, 80, 0, 16, 16, 0, 1, 1.14286, 1, 0, 400, 600, 0, 472, 1, 1500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1.887, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 12340);

DELETE FROM `creature_template_addon` WHERE (`entry`=37552);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37552, 0, 0, 0, 0, 0, '25824 31261 31261 1');

DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (37552, 37205, 37542, 37541, 37539, 37538) AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37205, 0, 0, 0, 0, 0, 100, 30, 5000, 7000, 15000, 15000, 11, 67541, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Filotormenta'),
(37205, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 13000, 13000, 11, 67542, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Golpe mortal'),
(37205, 0, 2, 0, 0, 0, 100, 0, 19000, 19000, 19000, 19000, 11, 67716, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Torbellino'),
(37205, 0, 3, 0, 0, 0, 100, 0, 1000, 1000, 8000, 8000, 11, 57846, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thalorien - Golpe heroico'),
(37542, 0, 0, 0, 0, 0, 100, 30, 2000, 3000, 9000, 10000, 11, 50688, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Morlen Manosfrias - Golpe de peste'),
(37541, 0, 0, 0, 0, 0, 100, 30, 1000, 2000, 4000, 5000, 11, 31600, 2, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Asaltante de la cripta - Escarabajos de la cripta'),
(37539, 0, 0, 0, 0, 0, 100, 30, 1000, 2000, 9000, 10000, 11, 38056, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Invasor necrofago - Desgarrar carne'),
(37538, 0, 0, 0, 0, 0, 100, 30, 1000, 2000, 9000, 10000, 11, 49861, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Zombi de la plaga - Mordedura infectada');
-- Loot 
DELETE FROM `creature_loot_template` WHERE (`entry`=37158);
INSERT INTO `creature_loot_template` VALUES 
(37158, 50254, -100, 1, 0, 1, 1);

UPDATE `quest_template` SET `RequiredClasses`=431, `RequiredRaces`=1101 WHERE `Id`=24553;
UPDATE `quest_template` SET `RequiredClasses`=431, `RequiredRaces`=178 WHERE `Id`=24564;
UPDATE `quest_template` SET `RequiredClasses`=1519, `RequiredRaces`=512 WHERE `Id`=24594;
UPDATE `quest_template` SET `RequiredClasses`=1104, `RequiredRaces`=1101 WHERE `Id`=24595;
UPDATE `quest_template` SET `RequiredClasses`=16, `RequiredRaces`=512 WHERE `Id`=24596;
UPDATE `quest_template` SET `RequiredClasses`=1104, `RequiredRaces`=178 WHERE `Id`=24598;
UPDATE `quest_template` SET `RequiredClasses`=35, `RequiredRaces`=0 WHERE `Id`=24545;

DELETE FROM `creature_loot_template` WHERE (`entry`=37158);
INSERT INTO `creature_loot_template` VALUES 
(37158, 50254, -100, 1, 0, 1, 1);


-- ItemScripts
UPDATE `item_template` SET `ScriptName` = 'item_tainted_queldelar' WHERE `entry` IN (49879,49889);

-- Templates
DELETE FROM `creature_template` WHERE entry IN (37523, 36991, 37746, 37763, 37764, 37765, 37781, 38056);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
('37523', 0, 0, 0, 0, 0, 30628, 30629, 30630, 30631, 'Warden of the Sunwell', '', '', 0, 80, 80, 0, 35, 35, 1, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sunwell_warder', 12340),
('36991','0','0','0','0','0','21460','0','0','0','Sunwell Guardian','','','0','80','80','0','35','35','0','1','1.14286','1','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','0','0','9','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','3.45002','1','1','0','0','0','0','0','0','0','144','1','0','0','0','','12340'),
('37746','0','0','0','0','0','20570','17612','0','0','Sunwell Caster Bunny','','','0','1','1','0','114','114','0','1','1.14286','0.72','0','0','0','0','0','1','0','0','1','33554432','0','0','0','0','0','0','0','0','0','10','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','0','0','0','0','0','0','0','0','1','0','0','130','','12340'),
('37763','0','0','0','0','0','19706','0','0','0','Grand Magister Rommath','','','0','80','80','0','35','35','0','1','1.14286','1','3','0','0','0','0','1','0','0','2','0','0','0','0','0','0','0','0','0','0','7','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','261.78','15.8145','1','0','0','0','0','0','0','0','0','1','897','0','0','','12340'),
('37764','0','0','0','0','0','17122','0','0','0','Lor\'themar Theron','Regent Lord of Quel\'Thalas','','0','80','80','0','35','35','0','1','1.14286','1','3','0','0','0','0','1','0','0','2','0','0','0','0','0','0','0','0','0','0','7','76','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1305.56','64.4067','1','1','0','0','0','0','0','0','0','1','2209','0','0','','12340'),
('37765','0','0','0','0','0','18146','0','0','0','Captain Auric Sunchaser','High Elf Representative','','0','80','80','0','35','35','0','1','1.14286','1','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','3.45002','1','1','0','0','0','0','0','0','0','0','1','481','0','0','','12340'),
('37781','0','0','0','0','0','15511','0','0','0','Sunwell Honor Guard','','Directions','0','80','80','0','35','35','0','1','1.14286','1','1','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','7.076','1','1','0','0','0','0','0','0','0','144','1','0','0','0','','12340'),
('38056','0','0','0','0','0','21008','0','0','0','Chamberlain Galiros','','','0','80','80','0','35','35','1','1','1.14286','1','0','0','0','0','0','1','0','0','2','0','0','0','0','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','2.94806','2','1','0','0','0','0','0','0','0','0','1','0','0','0','npc_queldelar_sp','12340');

DELETE FROM `gameobject_template` WHERE (`entry`=195682);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(195682, 10, 8111, 'Portal to Dalaran', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 68328, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'go_dalaran_portal_sunwell', 12340);

-- Spawns
SET @guid := 14568560;
DELETE FROM `creature` WHERE id IN (37523, 36991, 37746, 37763, 37765, 37765, 37781, 38056);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@guid,'37781','580','1','2','0','0','1720.53','615.576','28.0503','5.59377','300','0','0','126','0','0','0','0','0'),
(@guid+1,'37781','580','1','2','0','0','1686.59','644.382','28.1838','2.15293','300','0','0','126','0','0','0','0','0'),
(@guid+2,'37781','580','1','2','0','0','1658.78','629.876','28.3649','5.07855','300','0','0','126','0','0','0','0','0'),
(@guid+3,'36991','580','1','2','0','0','1739.09','717.696','71.1903','4.4777','300','0','0','84','0','0','0','0','0'),
(@guid+4,'36991','580','1','2','0','0','1761.82','707.575','71.1904','3.84232','300','0','0','84','0','0','0','0','0'),
(@guid+5,'36991','580','1','2','0','0','1778.09','692.973','71.1904','3.73393','300','0','0','84','0','0','0','0','0'),
(@guid+6,'37746','580','1','2','0','0','1698.45','628.03','28.1989','3.47949','300','0','0','42','0','0','0','33554432','0'),
(@guid+7,'36991','580','1','2','0','0','1653.57','634.692','28.0849','0.171978','300','0','0','84','0','0','0','0','0'),
(@guid+8,'36991','580','1','2','0','0','1693.99','674.897','28.0503','4.67702','300','0','0','84','0','0','0','0','0'),
(@guid+9,'36991','580','1','2','0','0','1745.8','622.226','28.0503','3.07638','300','0','0','84','0','0','0','0','0'),
(@guid+10,'36991','580','1','2','0','0','1704.76','583.796','28.1657','1.71842','300','0','0','84','0','0','0','0','0'),
(@guid+11,'36991','580','1','2','0','0','1612.32','606.707','33.3215','0.314329','300','0','0','84','0','0','0','0','0'),
(@guid+12,'36991','580','1','2','0','0','1621.18','584.858','33.3215','0.42507','300','0','0','84','0','0','0','0','0'),
(@guid+13,'36991','580','1','2','0','0','1634.67','563.787','33.3215','0.774572','300','0','0','84','0','0','0','0','0'),
(@guid+14,'36991','580','1','2','0','0','1651.28','548.805','33.3215','0.998411','300','0','0','84','0','0','0','0','0'),
(@guid+15,'37781','580','1','2','0','0','1680.19','620.726','28.1394','3.53524','300','0','0','126','0','0','0','0','0'),
(@guid+16,'37763','580','1','2','0','897','1662.56','622.758','28.0502','4.86257','300','0','0','8200','1200','0','0','0','0'),
(@guid+17,'38056','580','1','2','0','0','1671.49','606.427','28.0504','3.83603','300','0','0','41','60','0','0','0','0'),
(@guid+18,'37764','580','1','2','0','0','1665.9','624.107','28.0504','5.00237','300','0','0','16400','1800','0','0','0','0'),
(@guid+19,'37765','580','1','2','0','0','1703.85','602.353','28.0503','2.64381','300','0','0','42','0','0','0','0','0'),
(@guid+20,'37781','580','1','2','0','0','1666.81','631.886','28.0502','4.56725','300','0','0','126','0','0','0','0','0'),
(@guid+21,'37781','580','1','2','0','0','1659.63','625.187','28.2451','1.65029','300','0','0','126','0','0','0','0','0'),
(@guid+22,'37781','580','1','2','0','0','1671.96','631.276','28.0503','4.46279','300','0','0','126','0','0','0','0','0'),
(@guid+23,'37781','580','1','2','0','0','1671.33','624.754','28.0503','1.472','300','0','0','126','0','0','0','0','0'),
(@guid+24,'37781','580','1','2','0','0','1696.11','608.161','28.1093','4.55154','300','0','0','126','0','0','0','0','0');

DELETE FROM `gameobject` WHERE id IN (195682);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
('463134','195682','580','1','2','1669.68','663.748','28.0503','5.2859','0','0','0.478235','-0.878232','300','0','1'),
('463136','195682','580','1','2','1734.47','596.174','28.0503','2.33751','0','0','0.920264','0.391297','300','0','1');

-- Says
SET @entry := -1380561;
DELETE FROM script_texts WHERE entry BETWEEN -1380572 AND -1380561;
INSERT INTO script_texts (entry, content_default, emote) VALUES
(@entry, 'My lords and ladies, I present $N, bearer of Quel\'Delar.', 0),
(@entry - 1, 'Can that really be Quel\'Delar?', 0),
(@entry - 2, 'We shall see.', 0),
(@entry - 3, 'Look at it, Lor\'themar. It is certainly Quel\'Delar.', 1),
(@entry - 4, 'So it is. You have my thanks, $N, for restoring Quel\'Delar to its rightful owners', 0),
(@entry - 5, 'What is the meaning of this treachery?', 0),
(@entry - 6, 'Drop your weapon and surrender, traitor.', 0),
(@entry - 7, 'This is not my doing, Rommath. There is no treachery here.', 0),
(@entry - 8, 'Call off your men. Lor\'themar\'s own foolishness caused his injuries. Quel\'Delar is not chosen; it chooses its master.', 0),
(@entry - 9, 'Guards, return to your posts.', 0),
(@entry - 10,'You will have what you have come for, $N. Take the sword and begone. And you, Auric, have a care for what you say in this sacred place.', 0),
(@entry - 11,'Carry the sword back to Dalaran through that portal, $N. You have done what many quel\'dorei have dreamt of for years. Quel\'Delar has been restored at last.',0)