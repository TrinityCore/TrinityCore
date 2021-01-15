-- Razorfen Kraul Spawning for Auld Stonespire Entry: 44402, Earthward Totem <Auld Stonespire's Creation> Entry: 44401, Spirit of Agamaggan <Ancient> Entry: 44415, & 2 Summon Enabler Stalkers Entry 53488
SET @NPC := 1; -- 5 required
DELETE FROM `creature` WHERE `guid` IN (@NPC,@NPC+1,@NPC+2,@NPC+3,@NPC+4);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,44402,1,1,1,0,0,1942.24,1556.64,81.58484,5.305801,300,0,0,1,0,0),
(@NPC+1,44401,1,1,1,0,0,1945.06,1562.81,82.35413,1.186824,300,0,0,1,0,0),
(@NPC+2,44415,1,1,1,0,0,2194.63,1911.18,71.02483,2.897247,300,0,0,1,0,0),
(@NPC+3,53488,1,1,1,0,0,1942.403,1547.318,82.32955,1.32645,300,0,0,1,0,0),
(@NPC+4,53488,1,1,1,0,0,1945.729,1563.931,82.22086,1.32645,300,0,0,1,0,0);

-- Creature level update for Razorfen Kraul 4XX
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4422; -- Agathelos the Raging
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4424; -- Aggem Thorncurse <Death's Head Prophet>
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4425; -- Blind Hunter <RARE>
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4421; -- Charlga Razorflank <The Crone>
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4421; -- Death Speaker Jargba <Death's Head Captain>
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4842; -- Earthcaller Halmgar <RARE>
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4420; -- Overlord Ramtusk
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=6168; -- Roogug
UPDATE `creature_template` SET `minlevel`=32,`maxlevel`=33 WHERE `entry`=4425; -- Agam'ar
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4541; -- Blood of Agamaggan
UPDATE `creature_template` SET `minlevel`=24,`maxlevel`=28 WHERE `entry`=6021; -- Boar Spirit
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4515; -- Death's Head Acolyte
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4516; -- Death's Head Adept
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4517; -- Death's Head Priest
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4518; -- Death's Head Sage
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4519; -- Death's Head Seer
UPDATE `creature_template` SET `minlevel`=23,`maxlevel`=23 WHERE `entry`=4625; -- Death's Head Ward Keeper
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4539; -- Greater Kraul Bat
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=4510; -- Heralath Fallowbrook
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4538; -- Kraul Bat
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4623; -- Quilguard Champion
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=4514; -- Raging Agam'ar
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4531; -- Razorfen Beast Trainer
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4532; -- Razorfen Beastmaster
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4442; -- Razorfen Defender
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4522; -- Razorfen Dustweaver
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4525; -- Razorfen Earthbreaker
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=4520; -- Razorfen Geomancer
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4523; -- Razorfen Groundshaker
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=4530; -- Razorfen Handler
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=4536; -- Razorfen Quilguard
UPDATE `creature_template` SET `minlevel`=23,`maxlevel`=24 WHERE `entry`=6132; -- Razorfen Servitor
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=3348; -- Razorfen Spearhide
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=6035; -- Razorfen Stalker
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=34 WHERE `entry`=4440; -- Razorfen Totemic
UPDATE `creature_template` SET `minlevel`=33,`maxlevel`=33 WHERE `entry`=4537; -- Razorfen Warden
UPDATE `creature_template` SET `minlevel`=32,`maxlevel`=33 WHERE `entry`=4535; -- Razorfen Warrior
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4512; -- Rotting Agam'ar
UPDATE `creature_template` SET `minlevel`=29,`maxlevel`=31 WHERE `entry`=4528; -- Stone Rumbler
UPDATE `creature_template` SET `minlevel`=30,`maxlevel`=31 WHERE `entry`=4535; -- Tamed Battleboar
UPDATE `creature_template` SET `minlevel`=31,`maxlevel`=31 WHERE `entry`=4534; -- Tamed Hyena
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=4427; -- Ward Guardian
UPDATE `creature_template` SET `minlevel`=35,`maxlevel`=35 WHERE `entry`=4508; -- Willix the Importer
UPDATE `creature_template` SET `minlevel`=30,`maxlevel`=31 WHERE `entry`=4526; -- Wind Howler
UPDATE `creature_template` SET `minlevel`=34,`maxlevel`=34 WHERE `entry`=44402; -- Auld Stonespire "faction 35"
UPDATE `creature_template` SET `minlevel`=32,`maxlevel`=32 WHERE `entry`=44401; -- Earthward Totem "faction 35"
UPDATE `creature_template` SET `minlevel`=41,`maxlevel`=41 WHERE `entry`=44415; -- Spirit of Agamaggan "faction 35"
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80 WHERE `entry`=53488; -- Summon Enabler Stalker "exp 2 faction 14"

-- DELETE Stone Rumbler spawns from Razorfen Kraul
DELETE FROM `creature` WHERE `guid` IN (87300,87303,87309,87348,87410);
DELETE FROM `creature_addon` WHERE `guid` IN (87300,87303,87309,87348,87410);
-- DELETE Wind Howler spawns from Razorfen Kraul
DELETE FROM `creature` WHERE `guid` IN (87361,87406,87409);
DELETE FROM `creature_addon` WHERE `guid` IN (87361,87406,87409);
-- DELETE Tamed Battleboar spawns from Razorfen Kraul
DELETE FROM `creature` WHERE `guid` IN (87295,87298,87299,87308,87369,87376);
DELETE FROM `creature_addon` WHERE `guid` IN (87295,87298,87299,87308,87369,87376);
-- DELETE Tamed Hyena spawns from Razorfen Kraul
DELETE FROM `creature` WHERE `guid` IN (87339,87341,87366);
DELETE FROM `creature_addon` WHERE `guid` IN (87339,87341,87366);

-- Razorfen Model updates
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5 WHERE `modelid`=6069;

-- 4XX Razorfen Kraul Quest relations for Auld Stonespire 44402 & Spirit of Agamaggan 44415
DELETE FROM `creature_questrelation` WHERE `id`=44402 AND `quest` IN (26906,26901,26907);
DELETE FROM `creature_questrelation` WHERE `id`=44415 AND `quest` IN (26905);
INSERT INTO `creature_questrelation` (`id`,`quest`) VALUES
(44402,26906), -- Agamaggan
(44402,26901), -- Going, Going, Guano!
(44402,26907), -- Take Them Down!
(44415,26905); -- Agamaggan's Charge
DELETE FROM `creature_involvedrelation` WHERE `id`=44402 AND `quest` IN (26908,26901,26907);
DELETE FROM `creature_involvedrelation` WHERE `id`=44415 AND `quest` IN (26905,26906);
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES
(44402,26908), -- Feeling Thorny
(44402,26901), -- Going, Going, Guano!
(44402,26907), -- Take Them Down!
(44415,26906), -- Agamaggan
(44415,26905); -- Agamaggan's Charge
