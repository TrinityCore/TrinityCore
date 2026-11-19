DELETE FROM `creature_template_addon` WHERE `entry` IN (25343, 33229, 25342);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(25343, 0, 0x0, 0x1, '43167 29266'), -- Dead Caravan Worker - Spirit Particles (green), Permanent Feign Death
(33229, 0, 0x0, 0x1, ''), -- Melee Target
(25342, 0, 0x0, 0x1, '43167 29266'); -- Dead Caravan Guard - Spirit Particles (green), Permanent Feign Death


DELETE FROM `areatrigger_teleport` WHERE `id`=3928;
DELETE FROM `areatrigger_involvedrelation` WHERE `id` IN (225, 362, 2726);
DELETE FROM `areatrigger_tavern` WHERE `id` IN (713, 716, 720, 982, 1025, 2286, 4486);

DELETE FROM `npc_vendor` WHERE `item` IN (30633, 30634);

DELETE FROM `creature_loot_template` WHERE `item` IN (5397, 3930, 3467, 3499, 3704, 4882, 7923, 9299, 10460, 13305, 18266, 13303, 13306, 13302, 13304, 13307, 21762, 21761, 18268, 13873);
DELETE FROM `gameobject_loot_template` WHERE `item` IN (5397, 18266);
DELETE FROM `pickpocketing_loot_template` WHERE `item` IN (7923, 8072);
DELETE FROM `reference_loot_template` WHERE `item`=43650;

DELETE FROM `item_script_names` WHERE `id`=5397;
DELETE FROM `item_template_addon` WHERE `id`=39903;

DELETE FROM `spell_area` WHERE `spell`=58730;
DELETE FROM `spell_pet_auras` WHERE `spell` IN (35029, 35030, 56316, 56317, 56318, 34455, 34459);
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-61291, -49012, -49011, -42846, -42843, -38704, -38699, -27075, -27068, -25345, -24133, -24132, -10212, -10211, -8417, -8416, -5145, -5144, 15430, 15431, 17850, 17851, 17852, 17853, 17854, 25331, 27272, 27799, 27800, 27801, 32390, 32391, 45246, 47987, 47988, 48077, 48078, 48384, 48395, 48396, 51209, 61290, 61846, 61847, 69381);
DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (-28682, 57339, -61840, 57340, 60448, 60465, 60466, 52874, 66233);
DELETE FROM `spell_scripts` WHERE `id` IN (49203, 51662);

DELETE FROM `creature_formations` WHERE `memberGUID` IN (120831, 120833, 120835, 123124, 123111, 123113, 123149, 123151, 123148, 202000, 201957, 202122, 202199, 202028, 202098, 201954, 202121, 201934, 202196, 201988, 202227, 202145, 201914, 202054);
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (123157, 127743, 127745, 127752, 127754);

DELETE FROM `creature_addon` WHERE `guid` IN (55823, 75829, 40101, 40087, 40055, 40050, 40042, 40030, 40012, 40011, 40007, 40001, 132566, 66686, 42157, 42156, 131518, 131542, 42155, 42154, 42153, 131648, 132841, 133027, 133492, 133681, 202846, 203183, 203184, 203185, 203186, 203187, 203188, 203189, 203190, 203191, 203192, 203193, 203194);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=60089 AND `ElseGroup`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31883 AND `SourceEntry`=60123;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31893 AND `SourceEntry`=60123;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31894 AND `SourceEntry`=60123;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31895 AND `SourceEntry`=60123;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=31896 AND `SourceEntry`=60123;


DELETE FROM `creature_equip_template` WHERE `entry` IN (1976, 33468, 33698, 32713, 32721, 32712, 32711, 2621, 68, 3296, 5839, 7026, 7027, 14849, 15045, 15062, 15063, 15075, 15087, 15089, 16580, 16582, 16733, 16831, 16842, 16864, 17138, 17147, 17190, 17191, 17192, 18260, 18489, 18794, 19068, 19147, 21368, 21717, 21742, 22016, 22018, 22253, 22407, 22982, 23257, 23115, 23146, 25115, 25994, 28126, 28596, 29016, 24938, 23676, 23865, 23866, 24015, 24642, 24911, 25198, 27203, 27953, 28609, 29451);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(1976, 1899, 143, 2551), -- Stormwind City Patroller
(33468, 35117, 24328, 0), -- Silvermoon Valiant
(33698, 46107, 45856, 2551), -- Argent Peacekeeper
(32713, 19884, 0, 0), -- Juwanamana
(32721, 44655, 0, 0), -- Felcaster Virim
(32712, 27842, 0, 0), -- The Amazing Zanzo
(32711, 0, 0, 44643), -- Warp-Huntress Kula
(2621, 10612, 12453, 5260), -- Hammerfall Guardian
(68, 1899, 143, 2551), -- Stormwind City Guard
(3296, 5289, 0, 2507), -- Orgrimmar Grunt
(5839, 1910, 0, 0), -- Dark Iron Geologist
(7026, 2177, 0, 0), -- Blackrock Sorcerer
(7027, 45123, 0, 0), -- Blackrock Slayer
(14849, 3362, 13605, 0), -- Darkmoon Faire Carnie
(15045, 3367, 0, 0), -- Arathi Farmer
(15062, 1903, 0, 0), -- Arathi Lumberjack
(15063, 1903, 0, 0), -- Arathi Blacksmith
(15075, 12862, 0, 0), -- Forsaken Miner
(15087, 3367, 0, 0), -- Forsaken Stablehand
(15089, 19015, 0, 0), -- Forsaken Lumberjack
(16580, 18062, 12452, 5260), -- Thrallmar Grunt
(16582, 10898, 12456, 13924), -- Thrallmar Marksman
(16733, 24017, 24331, 34312), -- Exodar Peacekeeper
(16831, 1904, 0, 0), -- Nethergarde Infantry
(16842, 1901, 1901, 0), -- Honor Hold Defender
(16864, 12856, 12857, 0), -- Stormwind Infantry
(17138, 5288, 0, 0), -- Warmaul Reaver
(17147, 12959, 0, 0), -- Kil'sorrow Cultist
(17190, 6227, 0, 0), -- Siltfin Murloc
(17191, 6228, 0, 0), -- Siltfin Oracle
(17192, 6225, 0, 5870), -- Siltfin Hunter
(18260, 5300, 0, 0), -- Boulderfist Invader
(18489, 0, 0, 5260), -- Garadar Defender
(18794, 12421, 0, 0), -- Cabal Ritualist
(19068, 18062, 0, 5260), -- Garadar Wolf Rider
(19147, 2704, 0, 0), -- Allerian Peasant
(21368, 29419, 29419, 0), -- Ethereal Plunderer
(21717, 31600, 31466, 0), -- Dragonmaw Wrangler
(21742, 27405, 24322, 0), -- Sunfury Eradicator
(22016, 31208, 0, 0), -- Eclipsion Soldier
(22018, 30636, 0, 0), -- Eclipsion Cavalier
(22253, 31600, 31466, 0), -- Dragonmaw Ascendant
(22407, 3367, 13610, 2551), -- Caravan Defender
(22982, 2705, 0, 0), -- Skyguard Navigator
(23257, 2028, 0, 0), -- Skyguard Windcharger
(23115, 0, 0, 5870), -- Ogri'la Peacekeeper
(23146, 31603, 31466, 0), -- Dragonmaw Enforcer
(24938, 34301, 0, 34277), -- Shattered Sun Marksman
(25115, 31743, 34588, 0), -- Shattered Sun Warrior
(25994, 1906, 2081, 0), -- Flame Eater
(28126, 2717, 0, 28581), -- Don Carlos
(28596, 5292, 0, 0), -- Dwarven Construction Worker
(29016, 31824, 0, 0), -- Steam Tank Engineer
(23676, 5300, 0, 0), -- Iron Rune Destroyer
(23865, 25160, 0, 0), -- Vengeance Bringer
(23866, 1895, 1984, 0), -- North Fleet Sailor
(24015, 34820, 0, 0), -- Winterskorn Defender
(24642, 2716, 0, 0), -- Drunken Northsea Pirate
(24911, 2704, 0, 12523), -- Cursed Sea Dog
(25198, 10617, 0, 0), -- Winterfin Gatherer
(27203, 12944, 12932, 0), -- Onslaught Footman
(27953, 38209, 0, 19368), -- Wyrmrest Protector
(28609, 38723, 12932, 5259), -- Scarlet Infantryman
(29451, 40608, 0, 0); -- Vargul Slayer


UPDATE `creature_template` SET `spell1`=0 WHERE `spell1`=8182;
UPDATE `creature_template` SET `spell1`=0 WHERE `entry`=8510;
UPDATE `creature_template` SET `spell3`=0 WHERE `entry`=11455;
UPDATE `creature_template` SET `spell4`=0 WHERE `entry`=11488;
UPDATE `creature_template` SET `spell1`=0 WHERE `entry`=18176;
UPDATE `creature_template` SET `spell1`=0 WHERE `entry`=18179;
UPDATE `creature_template` SET `spell1`=0 WHERE `entry`=18312;
UPDATE `creature_template` SET `PetSpellDataId`=0 WHERE `entry`=21634;
UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=266; -- Wiley the Black
UPDATE `creature_template` SET `pickpocketloot`=0 WHERE `entry`=7051; -- Malformed Defias Drone
UPDATE `creature_template` SET `pickpocketloot`=0 WHERE `entry`=7287; -- Foreman Silixiz

UPDATE `creature_template` SET `npcflag`=129 WHERE `entry`=1460; -- Unger Statforth
UPDATE `creature_template` SET `npcflag`=129 WHERE `entry`=4885; -- Gregor MacVince
UPDATE `creature_template` SET `npcflag`=4227 WHERE `entry`=10856; -- Argent Quartermaster Hasana
UPDATE `creature_template` SET `npcflag`=4227 WHERE `entry`=10857; -- Argent Quartermaster Lightspark
UPDATE `creature_template` SET `npcflag`=131 WHERE `entry`=11057; -- Apothecary Dithers
UPDATE `creature_template` SET `npcflag`=4227 WHERE `entry`=16376; -- Craftsman Wilhelm
UPDATE `creature_template` SET `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=19368; -- Crinn Pathfinder
UPDATE `creature_template` SET `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=27068; -- Matthew Ackerman
UPDATE `creature_template` SET `npcflag`=129 WHERE `entry`=27814; -- Brew Vendor
UPDATE `creature_template` SET `npcflag`=129, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=33854; -- Thomas Partridge
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=40209; -- Grex Brainboiler
UPDATE `creature_template` SET `minlevel`=48, `maxlevel`=48, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=48607; -- Muurald
UPDATE `creature_template` SET `minlevel`=48, `maxlevel`=48, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=48608; -- Kamar
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=54649; -- Big Zokk Torquewrench
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512 WHERE `entry`=54650; -- Kezzik the Striker
UPDATE `creature_template` SET `npcflag`=4241 WHERE `entry`=55684; -- Jordan Smith
