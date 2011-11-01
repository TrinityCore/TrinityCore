-- Random Stormwind NPC's
-- Template updates
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_flags`=`unit_flags`|33555200,`speed_walk`=1,`speed_run`=1.14286 WHERE `entry`=37574; -- [DND] Shaker - Small
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_flags`=`unit_flags`|33555200,`speed_walk`=1,`speed_run`=1.14286 WHERE `entry`=37543; -- [DND] Shaker
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=68; -- Stormwind City Guard
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=4075; -- Rat
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768 WHERE `entry`=29093; -- Ian Drake
UPDATE `creature_template` SET `npcflag`=`npcflag`|17 WHERE `entry`=11867; -- Woo Ping

-- Model data 1436 (creature 2456 (Newton Burnside))
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=0,`gender`=0 WHERE `modelid` IN (1436 -- Newton Burnside
,1437 -- John Burnside
,1434 -- Thurman Mullby
,1431 -- Keldric Boucher
,5082 -- Morgan Pestle
,2974 -- Aldwin Laughlin
,5547 -- Ben Trias
,3246 -- Elling Trias
,3167 -- Stormwind City Guard
,25901 -- Ian Drake
,5074 -- Renato Gallina
,7991 -- Auctioneer Chilton
,7992 -- Auctioneer Fitch
,5567 -- Melris Malagan
,1525 -- Crier Goodman
,1541 -- Thomas Miller
,5551 -- Harlan Bagley
,1429 -- Gunther Weller
,11804 -- Woo Ping
,1433 -- Roberto Pupellyverbos
,1427 -- Frederick Stover
,1438); -- Topper McNabb
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=0,`gender`=1 WHERE `modelid` IN (5545 -- Suzetta Gallina
,5444 -- Innkeeper Allison
,1446 -- Lina Stover
,1448 -- Marda Weller
,1443 -- Julia Gallina
,1440 -- Edna Mullby
,1445 -- Lara Moore
,1439 -- Carla Granger
,5446 -- Justine Demalier
,5446 -- Stormwind City Guard
,15594 -- Auctioneer Jaxon
,4888 -- Stephanie Turner
,1450 -- Olivia Burnside
,5546 -- Elaine Trias
,3133 -- Rebecca Laughlin
,1444); -- Kyra Boucher
UPDATE `creature_model_info` SET `bounding_radius`=0.25,`combat_reach`=0,`gender`=2 WHERE `modelid`=5585; -- Fuzz
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=0,`gender`=2 WHERE `modelid` IN (1141,1418); -- Rat
UPDATE `creature_model_info` SET `bounding_radius`=0.075,`combat_reach`=0,`gender`=2 WHERE `modelid`=24719; -- [DND] Shaker - Small
-- Addon data
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=257,`mount`=0,`emote`=0,`auras`=NULL WHERE `entry` IN 
(2456 -- Newton Burnside
,2457 -- John Burnside
,1285 -- Thurman Mullby
,1286 -- Edna Mullby
,1257 -- Keldric Boucher
,1275 -- Kyra Boucher
,279 -- Morgan Pestle
,5193 -- Rebecca Laughlin
,4974 -- Aldwin Laughlin
,4981 -- Ben Trias
,2455 -- Olivia Burnside
,483 -- Elaine Trias
,482 -- Elling Trias
,68 -- Stormwind City Guard
,1432 -- Renato Gallina
,6174 -- Stephanie Turner
,8670 -- Auctioneer Chilton
,15659 -- Auctioneer Jaxon
,8719 -- Auctioneer Fitch
,12480 -- Melris Malagan
,12481 -- Justine Demalier
,2198 -- Crier Goodman
,3518 -- Thomas Miller
,1976 -- Stormwind City Patroller
,1291 -- Carla Granger
,1427 -- Harlan Bagley
,1295 -- Lara Moore
,1289 -- Gunther Weller
,11867 -- Woo Ping
,6740 -- Innkeeper Allison
,1402 -- Topper McNabb
,1287 -- Marda Weller
,1301 -- Julia Gallina
,277 -- Roberto Pupellyverbos
,1431); -- Suzetta Gallina

-- Frederick Stover
-- Lina Stover
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=258,`mount`=0,`emote`=0,`auras`=NULL WHERE `entry` IN (1297,1298); 
DELETE FROM `creature_template_addon` WHERE `entry` IN (37574,37543,29093,25058);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37574,0,0,1,0, NULL), -- [DND] Shaker - Small
(37543,0,0,1,0, NULL), -- [DND] Shaker
(29093,0,0,257,0, NULL), -- Ian Drake
(25058,0,3,1,0, NULL); -- Fuzz
