UPDATE `creature_template` SET `skinloot`=entry WHERE `entry` IN (30260, 32517, 27641, 28860);
UPDATE `creature_template` SET `skinloot`=70202 WHERE `entry` IN (25774,29693);
UPDATE `creature_template` SET `skinloot`=70203 WHERE `entry`=28257;
UPDATE `creature_template` SET `skinloot`=70207 WHERE `entry`=34137;
UPDATE `creature_template` SET `skinloot`=70208 WHERE `entry` IN (32572,25448,25716,25713);
UPDATE `creature_template` SET `skinloot`=70210 WHERE `entry` IN (33528,40419,26723,31134,36891);
UPDATE `creature_template` SET `skinloot`=70211 WHERE `entry` IN (28847,30206,29875,29931,28203,30432);
UPDATE `creature_template` SET `skinloot`=70212 WHERE `entry` IN (27645,32377,29838,26628,26622,32490,38453,32485,26633,32400,32361,29768,29735,26641,27644,27642,26735,26730,26722,33776,35189,26716,26672,29664,29774);
UPDATE `creature_template` SET `skinloot`=70213 WHERE `entry` IN (27483,29312);
UPDATE `creature_template` SET `skinloot`=70214 WHERE `entry` IN (37217,34564);
UPDATE `creature_template` SET `skinloot`=27641 WHERE `entry` IN (31385,34269,34270,27641,30905,30353);

DELETE FROM `skinning_loot_template` WHERE entry IN (30260,32517,70212,70213,70214,28860,27641);
INSERT INTO `skinning_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- Stoic Mammoth
(30260,33568,100,0,1,3), -- Borean Leather
(30260,42542,-50,0,1,1), -- Stoic Mammoth Hide
-- Loque'nahak
(32517,33568,0,1,1,3), -- Borean Leather
(32517,44128,2,1,1,1), -- Arctic Fur
(32517,44687,100,0,1,1), -- Loque'Nahak's Pelt
-- skinloot 70212
(70212,33568,0,1,1,3), -- Borean Leather
(70212,44128,1,1,1,1), -- Arctic Fur
-- skinloot 70213
(70213,33568,0,1,5,12), -- Borean Leather
(70213,44128,1,1,1,1), -- Arctic Fur
-- skinloot 70214
(70214,33568,0,1,12,16), -- Borean Leather
(70214,44128,25,1,1,1), -- Arctic Fur
-- Sartharion
(28860,33568,0,1,8,12), -- Borean Leather
(28860,38557,0,1,8,12),-- Icy Dragonscale
(28860,44128,1,1,1,1), -- Arctic Fur
--  Centrifuge Construct
(27641,41337,85,0,1,3), -- Whizzed-Out Gizmo
(27641,41338,80,0,1,3), -- Sprung Whirlygig
(27641,39690,15,0,1,3), -- Volatile Blasting Trigger
(27641,39684,8,0,1,1), -- Hair Trigger
(27641,36813,8,0,1,3), -- Sprung Sprocket
(27641,39681,8,0,2,4), -- Handful of Cobalt Bolts
(27641,49050,2,0,1,1), -- Schematic: Jeeves
(27641,39682,1,0,1,1), -- Overcharged Capacitor
(27641,39685,1,0,1,1); -- Indestructible Frame
