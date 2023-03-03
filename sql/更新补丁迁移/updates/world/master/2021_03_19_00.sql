-- DB update 2021_03_18_04 -> 2021_03_19_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_18_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_18_04 2021_03_19_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614187202428005763'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614187202428005763');

-- Modify run and walk speed of multiple creatures
-- Taken from vmangos commit f0a1fbfc87d97d8a876bf569ca9eb09729714cdd
-- and vmangos commit a6919c7e5b86dc94c14ec0c0e9566d2c317b038c

UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=2713; -- Kinelory, speed_walk=1, speed_run=0.99206
UPDATE `creature_template` SET `speed_run`=2 WHERE `entry`=10577; -- Crypt Scarab, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=2170; -- Blackwood Ursa, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=2171; -- Blackwood Shaman, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=2630; -- Earthbind Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=0.571429 WHERE `entry`=2675; -- Explosive Sheep, speed_walk=1.08, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2951; -- Palemane Poacher, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2952; -- Bristleback Quilboar, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2953; -- Bristleback Shaman, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2954; -- Bristleback Battleboar, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2966; -- Battleboar, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2975; -- Venture Co. Hireling, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2989; -- Bael'dun Digger, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=2990; -- Bael'dun Appraiser, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=3068; -- Mazzranache, speed_walk=0.666668, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=3229; -- "Squealer" Thornmantle, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=3680; -- Serpentbloom Snake, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3844; -- Healing Ward IV, speed_walk=0.73, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3902; -- Searing Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3911; -- Stoneclaw Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=4196; -- Silithid Swarm, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=5786; -- Snagglespear, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5873; -- Stoneskin Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5874; -- Strength of Earth Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5879; -- Fire Nova Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5919; -- Stoneskin Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5921; -- Strength of Earth Totem II, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=5932; -- Taskmaster Whipfang, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=6111; -- Fire Nova Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7399; -- Stoneclaw Totem VI, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7403; -- Strength of Earth Totem IV, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7413; -- Frost Resistance Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7416; -- Mana Spring Totem IV, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7466; -- Magma Totem IV, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7484; -- Windfury Totem III, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7845; -- Fire Nova Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=8554; -- Chief Sharptusk Thornmantle, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=4.28571 WHERE `entry`=9526; -- Enraged Gryphon, speed_walk=1, speed_run=4.28571
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=11101; -- Mana Tide Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=12034; -- Koiter, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=698; -- Bloodscalp Tiger, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=756; -- Skullsplitter Panther, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1122; -- Frostmane Hideskinner, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=1.07143 WHERE `entry`=1559; -- King Mukla, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=2522; -- Jaguero Stalker, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=2667; -- Ward of Laze, speed_walk=0.79, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3903; -- Searing Totem III, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=4034; -- Enraged Stone Spirit, speed_walk=1.55556, speed_run=0.857143
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4661; -- Gelkis Rumbler, speed_walk=1.55556, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=7939; -- Feathermoon Sentinel, speed_walk=1, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=11690; -- Gnarlpine Instigator, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=14890; -- Taerar, speed_walk=1.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.428571 WHERE `entry`=15224; -- Dream Fog, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15806; -- Qiraji Lieutenant, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1115; -- Rockjaw Skullthumper, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1116; -- Rockjaw Ambusher, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1123; -- Frostmane Headhunter, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1124; -- Frostmane Shadowcaster, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1134; -- Young Wendigo, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1689; -- Scarred Crag Boar, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=2523; -- Searing Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=2623; -- Spirit of Old, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=2673; -- Target Dummy, speed_walk=1.81, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=2674; -- Advanced Target Dummy, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=2992; -- Healing Ward V, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3527; -- Healing Stream Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3560; -- Healing Ward, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3573; -- Mana Spring Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3579; -- Stoneclaw Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.28571 WHERE `entry`=3864; -- Fel Steed, speed_walk=1, speed_run=1.28571
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3906; -- Healing Stream Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3907; -- Healing Stream Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3908; -- Healing Stream Totem IV, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3909; -- Healing Stream Totem V, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=3912; -- Stoneclaw Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=3921; -- Thistlefur Ursa, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=3922; -- Thistlefur Totemic, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=3923; -- Thistlefur Den Watcher, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=3926; -- Thistlefur Pathfinder, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=3987; -- Dal Bloodclaw, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=4059; -- Forest Spirit, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4107; -- Highperch Wyvern, speed_walk=1, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4109; -- Highperch Consort, speed_walk=1, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4634; -- Kolkar Mauler, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4636; -- Kolkar Battle Lord, speed_walk=0.666668, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4637; -- Kolkar Destroyer, speed_walk=0.666668, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=0.714286 WHERE `entry`=4781; -- Snufflenose Gopher, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=5300; -- Frayfeather Hippogryph, speed_walk=1, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=5304; -- Frayfeather Stagwing, speed_walk=1, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5913; -- Tremor Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5920; -- Stoneskin Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5922; -- Strength of Earth Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5923; -- Poison Cleansing Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5925; -- Grounding Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5926; -- Frost Resistance Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5927; -- Fire Resistance Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=5929; -- Magma Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=6016; -- Elemental Protection Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=6017; -- Lava Spout Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=6066; -- Earthgrab Totem, speed_walk=0.84, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=6110; -- Fire Nova Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=6112; -- Windfury Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=6240; -- Affray Challenger, speed_walk=1.06, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=6378; -- Thunderhead Skystormer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=6651; -- Gatekeeper Rageroar, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=7153; -- Deadwood Warrior, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=7154; -- Deadwood Gardener, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=7155; -- Deadwood Pathfinder, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7366; -- Stoneskin Totem IV, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7367; -- Stoneskin Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7368; -- Stoneskin Totem VI, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7398; -- Stoneclaw Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7400; -- Searing Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7402; -- Searing Totem VI, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7412; -- Frost Resistance Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7414; -- Mana Spring Totem II, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7415; -- Mana Spring Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7425; -- Fire Resistance Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7464; -- Magma Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7465; -- Magma Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7469; -- Nature Resistance Totem III, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7483; -- Windfury Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7486; -- Grace of Air Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7487; -- Grace of Air Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7527; -- Goblin Land Mine, speed_walk=1.16, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=7844; -- Fire Nova Totem IV, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.285714 WHERE `entry`=8317; -- Atal'ai Deathwalker's Spirit, speed_walk=1, speed_run=0.4
UPDATE `creature_template` SET `speed_run`=1.57143 WHERE `entry`=8446; -- Xiggs Fuselighter's Flyingmachine, speed_walk=1.17, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.714286 WHERE `entry`=8937; -- Pet Bomb, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=4.28571 WHERE `entry`=9297; -- Enraged Wyvern, speed_walk=1, speed_run=4.28571
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=9462; -- Chieftain Bloodmaw, speed_walk=0.666668, speed_run=0.992063
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=9464; -- Overlord Ror, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.21429 WHERE `entry`=9683; -- Lar'korwi Mate, speed_walk=1.6, speed_run=1.21429
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=9687; -- Windwall Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=9689; -- Windwall Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=9937; -- Common Kitten, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=10183; -- Moonflare Totem, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=10557; -- Flametongue Totem IV, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=10581; -- Young Arikara, speed_walk=1.07, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=10639; -- Rorgish Jowl, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=10807; -- Brumeran, speed_walk=1.4, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1.07143 WHERE `entry`=11199; -- Crimson Cannon, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=11360; -- Zulian Cub, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=11361; -- Zulian Tiger, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=11365; -- Zulian Panther, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=11380; -- Jin'do the Hexxer, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=11382; -- Bloodlord Mandokir, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=11561; -- Undead Ravager, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=11620; -- Spectral Marauder, speed_walk=1, speed_run=0.857143
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=11621; -- Spectral Corpse, speed_walk=1, speed_run=0.857143
UPDATE `creature_template` SET `speed_run`=1.28571 WHERE `entry`=11710; -- Mirador, speed_walk=1, speed_run=1.28571
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=11727; -- Hive'Zora Wasp, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=11732; -- Hive'Regal Spitfire, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=11875; -- Mortar Team Target Dummy, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.714286 WHERE `entry`=12120; -- Plagueland Termite, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=12265; -- Lava Spawn, speed_walk=1.76, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=12416; -- Blackwing Legionnaire, speed_walk=1.76, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=12420; -- Blackwing Mage, speed_walk=1.76, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=12422; -- Death Talon Dragonspawn, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=12581; -- Mercutio, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=12677; -- Shadumbra, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=12921; -- Enraged Foulweald, speed_walk=1.04, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=13136; -- Hive'Ashi Drone, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=13318; -- Commander Mortimer, speed_walk=1.78, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=14081; -- Demon Portal, speed_walk=1.13, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.714286 WHERE `entry`=14227; -- Hissperak, speed_walk=1.11111, speed_run=0.714286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=14465; -- Alliance Battle Standard, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=14466; -- Horde Battle Standard, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=14474; -- Zora, speed_walk=1.78, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=14509; -- High Priest Thekal, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=14515; -- High Priestess Arlokk, speed_walk=1.18, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=14532; -- Razzashi Venombrood, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=14605; -- Bone Construct, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=14751; -- Frostwolf Battle Standard, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=14752; -- Stormpike Battle Standard, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=2.57143 WHERE `entry`=14862; -- Emissary Roman'khan, speed_walk=1.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.42857 WHERE `entry`=14880; -- Razzashi Skitterer, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=14881; -- Spider, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.571429 WHERE `entry`=14884; -- Parasitic Serpent, speed_walk=1.69, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=14986; -- Shade of Jin'do, speed_walk=1.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=14987; -- Powerful Healing Ward, speed_walk=0.001, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=14988; -- Ohgan, speed_walk=1.18, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.285714 WHERE `entry`=15009; -- Voodoo Spirit, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15041; -- Spawn of Mar'li, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15068; -- Zulian Guardian, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.25714 WHERE `entry`=15077; -- Riggle Bassbait, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.25714 WHERE `entry`=15078; -- Jang, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.25714 WHERE `entry`=15079; -- Fishbot 5000, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.25714 WHERE `entry`=15088; -- Booty Bay Elite, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=15101; -- Zulian Prowler, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=15107; -- Arathi Horse, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15108; -- Forsaken Horse, speed_walk=1, speed_run=1.38571
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=15112; -- Brain Wash Totem, speed_walk=0.001, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15192; -- Anachronos, speed_walk=1, speed_run=2.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15206; -- The Duke of Cynders, speed_walk=1.81, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15212; -- Hoary Templar, speed_walk=1.79, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15229; -- Vekniss Soldier, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15230; -- Vekniss Warrior, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15233; -- Vekniss Guardian, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15235; -- Vekniss Stinger, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15236; -- Vekniss Wasp, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15240; -- Vekniss Hive Crawler, speed_walk=2, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15246; -- Qiraji Mindslayer, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15247; -- Qiraji Brainwasher, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15250; -- Qiraji Slayer, speed_walk=2.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15252; -- Qiraji Champion, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15262; -- Obsidian Eradicator, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15263; -- The Prophet Skeram, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15264; -- Anubisath Sentinel, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15276; -- Emperor Vek'lor, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15277; -- Anubisath Defender, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15286; -- Xil'xix, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15288; -- Aluntir, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15290; -- Arakis, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15299; -- Viscidus, speed_walk=2.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15300; -- Vekniss Drone, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=15304; -- Ancient Mana Spring Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15305; -- Lord Skwol, speed_walk=1.82, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15307; -- Earthen Templar, speed_walk=1.79, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15311; -- Anubisath Warder, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15312; -- Obsidian Nullifier, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15316; -- Qiraji Scarab, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15317; -- Qiraji Scorpion, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15318; -- Hive'Zara Drone, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15319; -- Hive'Zara Collector, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15320; -- Hive'Zara Soldier, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15323; -- Hive'Zara Sandstalker, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15324; -- Qiraji Gladiator, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15325; -- Hive'Zara Wasp, speed_walk=2.4, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15327; -- Hive'Zara Stinger, speed_walk=2.4, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15335; -- Flesh Hunter, speed_walk=2.4, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15336; -- Hive'Zara Tail Lasher, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15338; -- Obsidian Destroyer, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=15339; -- Ossirian the Unscarred, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15340; -- Moam, speed_walk=2.3, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15341; -- General Rajaxx, speed_walk=1, speed_run=2.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15343; -- Qiraji Swarmguard, speed_walk=2.8, speed_run=2.28571
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15344; -- Swarmguard Needler, speed_walk=2.8, speed_run=2.28571
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15348; -- Kurinnaxx, speed_walk=1, speed_run=2.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15355; -- Anubisath Guardian, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15369; -- Ayamiss the Hunter, speed_walk=2.4, speed_run=2.14286
UPDATE `creature_template` SET `speed_run`=0.428571 WHERE `entry`=15370; -- Buru the Gorger, speed_walk=1.2, speed_run=0.42857
UPDATE `creature_template` SET `speed_run`=1.85714 WHERE `entry`=15378; -- Merithra of the Dream, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.85714 WHERE `entry`=15379; -- Caelestrasz, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.85714 WHERE `entry`=15380; -- Arygos, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15385; -- Colonel Zerran, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15386; -- Major Yeggeth, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15387; -- Qiraji Warrior, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15388; -- Major Pakkon, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15389; -- Captain Drenn, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15390; -- Captain Xurrem, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15391; -- Captain Qeez, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15392; -- Captain Tuubid, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15414; -- Qiraji Wasp, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15421; -- Qiraji Drone, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15422; -- Qiraji Tank, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.571429 WHERE `entry`=15428; -- Sand Vortex, speed_walk=1.6, speed_run=0.57143
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15458; -- Commander Stronghammer, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15461; -- Shrieker Scarab, speed_walk=1, speed_run=1.71429
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15462; -- Spitting Scarab, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=15464; -- Strength of Earth Totem V, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=15475; -- Beetle, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=15476; -- Scorpion, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15521; -- Hive'Zara Hatchling, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15527; -- Mana Fiend, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15537; -- Anubisath Warrior, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15538; -- Anubisath Swarmguard, speed_walk=2.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15539; -- General Zog, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15541; -- Twilight Marauder Morna, speed_walk=1, speed_run=1.38571
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15545; -- Cenarion Outrider, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15546; -- Hive'Zara Swarmer, speed_walk=1.71, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.714286 WHERE `entry`=15555; -- Hive'Zara Larva, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15589; -- Eye of C'Thun, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15621; -- Yauj Brood, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15700; -- Warlord Gorchuk, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15701; -- Field Marshal Snowfall, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15720; -- Timbermaw Ancestor, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15727; -- C'Thun, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.85714 WHERE `entry`=15740; -- Colossus of Zora, speed_walk=8.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.85714 WHERE `entry`=15742; -- Colossus of Ashi, speed_walk=8.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15743; -- Colossal Anubisath Warbringer, speed_walk=4.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15744; -- Imperial Qiraji Destroyer, speed_walk=4.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15747; -- Qiraji Captain, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15750; -- Qiraji Major, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15753; -- Qiraji Brigadier General, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15757; -- Qiraji Lieutenant General, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=15803; -- Tranquil Air Totem, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15812; -- Qiraji Officer, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2 WHERE `entry`=15813; -- Qiraji Officer Zod, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=15814; -- Qiraji Lieutenant Jo-rel, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15817; -- Qiraji Brigadier General Pax-lish, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.85714 WHERE `entry`=15818; -- Lieutenant General Nokhor, speed_walk=1.74, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15854; -- Orgrimmar Elite Cavalryman, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.28968 WHERE `entry`=15857; -- Stormwind Cavalryman, speed_walk=1.23, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=15862; -- Ironforge Cavalryman, speed_walk=2.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15896; -- C'Thun Portal, speed_walk=2.4, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=16139; -- Cenarion Hold Reservist, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=9637; -- Scorching Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=15114; -- Gahz'ranka, speed_walk=2.28, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=15141; -- Portal of Madness, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.714286 WHERE `entry`=15163; -- Nightmare Illusion, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15204; -- High Marshal Whirlaxis, speed_walk=1.82, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.28571 WHERE `entry`=15205; -- Baron Kazum, speed_walk=1.82, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=15211; -- Azure Templar, speed_walk=1.77, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=15275; -- Emperor Vek'nilash, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=15963; -- The Master's Eye, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=603; -- Grimtooth, speed_walk=1.65, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1531; -- Lost Soul, speed_walk=1, speed_run=0.857143
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=1534; -- Wailing Ancestor, speed_walk=1, speed_run=0.857143
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=8612; -- Screecher Spirit, speed_walk=0.9, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=9707; -- Scarshield Portal, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=10217; -- Flame Buffet Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=10218; -- Superior Healing Ward, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=10359; -- Sri'skulk, speed_walk=0.98, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=10991; -- Wildpaw Gnoll, speed_walk=1, speed_run=1.19048
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=11837; -- Wildpaw Shaman, speed_walk=1, speed_run=1.19048
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=11838; -- Wildpaw Mystic, speed_walk=1, speed_run=1.19048
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=11839; -- Wildpaw Brute, speed_walk=1, speed_run=1.19048
UPDATE `creature_template` SET `speed_run`=1.19048 WHERE `entry`=11840; -- Wildpaw Alpha, speed_walk=1, speed_run=1.19048
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=12141; -- Ice Totem, speed_walk=1.22, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.71429 WHERE `entry`=12143; -- Son of Flame, speed_walk=1.76, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.38571 WHERE `entry`=13441; -- Frostwolf Wolf Rider Commander, speed_walk=1.79, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.85714 WHERE `entry`=14350; -- Hydroling, speed_walk=1.22, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=14772; -- East Frostwolf Warmaster, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=14773; -- Iceblood Warmaster, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=14776; -- Tower Point Warmaster, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.14286 WHERE `entry`=14777; -- West Frostwolf Warmaster, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=4277; -- Eye of Kilrogg, speed_walk=1.03, speed_run=1.42857
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=10467; -- Mana Tide Totem, speed_walk=1, speed_run=1
UPDATE `creature_template` SET `speed_run`=0.857143 WHERE `entry`=14421; -- Brown Prairie Dog, speed_walk=1, speed_run=0.85714
UPDATE `creature_template` SET `speed_run`=2.85714 WHERE `entry`=15741; -- Colossus of Regal, speed_walk=8.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.55556 WHERE `entry`=691; -- Lesser Water Elemental, speed_walk=1, speed_run=1.28968
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=954; -- Kat Sampson, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1169; -- Dark Iron Insurgent, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2173; -- Reef Frenzy, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2723; -- Stone Golem, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2745; -- Ambassador Infernus, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3112; -- Razormane Scout, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3119; -- Kolkar Drudge, speed_walk=0.92, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3128; -- Kul Tiras Sailor, speed_walk=0.92, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3129; -- Kul Tiras Marine, speed_walk=0.92, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3192; -- Lieutenant Benedict, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3545; -- Claude Erksine, speed_walk=1.14, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3696; -- Ran Bloodtooth, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3752; -- Xavian Rogue, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3754; -- Xavian Betrayer, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3755; -- Xavian Felsworn, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3757; -- Xavian Hellcaller, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3920; -- Anilia, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3926; -- Thistlefur Pathfinder, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3932; -- Bloodtooth Guard, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3987; -- Dal Bloodclaw, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4619; -- Geltharis, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5314; -- Phantim, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.7 WHERE `entry`=5809; -- Watch Commander Zalaphil, speed_walk=1.36, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5826; -- Geolord Mottle, speed_walk=0.96, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=5838; -- Brokespear, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5849; -- Digger Flameforge, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5941; -- Lau'Tiki, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6071; -- Legion Hound, speed_walk=0.92, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6123; -- Dark Iron Spy, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=6143; -- Servant of Arkkoroc, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6196; -- Spitelash Myrmidon, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6352; -- Coralshell Lurker, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6707; -- Fahrad, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6768; -- Lord Jorach Ravenholdt, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6771; -- Ravenholdt Assassin, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6777; -- Zan Shivsproket, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6779; -- Smudge Thunderwood, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7007; -- Tiev Mordune, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7108; -- Jadefire Betrayer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7323; -- Winstone Wolfe, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7324; -- Simone Cantrell, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7325; -- Master Kang, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7434; -- Frostsaber Pride Watcher, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8309; -- Carlo Aurelius, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10618; -- Rivern Frostwind, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10619; -- Glacier, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10918; -- Lorax, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10930; -- Dargh Trueaim, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11030; -- Mindless Undead, speed_walk=0.777776, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11725; -- Hive'Zora Waywatcher, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11726; -- Hive'Zora Tunneler, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=11727; -- Hive'Zora Wasp, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11728; -- Hive'Zora Reaver, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11729; -- Hive'Zora Hive Sister, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11776; -- Salome, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11803; -- Twilight Keeper Exeter, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12474; -- Emeraldon Boughguard, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12475; -- Emeraldon Tree Warder, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12476; -- Emeraldon Oracle, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12498; -- Dreamstalker, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12759; -- Tideress, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=13085; -- Myrokos Silentform, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14449; -- Blackwing Orb Trigger, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14459; -- Nefarian's Troops, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14515; -- High Priestess Arlokk, speed_walk=1.18, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=14532; -- Razzashi Venombrood, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=14880; -- Razzashi Skitterer, speed_walk=1.32, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15069; -- Heart of Hakkar, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.6 WHERE `entry`=15114; -- Gahz'ranka, speed_walk=2.28, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=15117; -- Chained Spirit, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15140; -- Pat's Splash Guy, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15200; -- Twilight Keeper Mayna, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.777776 WHERE `entry`=15205; -- Baron Kazum, speed_walk=1.82, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.777776 WHERE `entry`=15208; -- The Duke of Shards, speed_walk=1.81, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.55556 WHERE `entry`=15211; -- Azure Templar, speed_walk=1.77, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.55556 WHERE `entry`=15307; -- Earthen Templar, speed_walk=1.79, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=16107; -- Apothecary Staffron Lerent, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1863; -- Succubus, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=2170; -- Blackwood Ursa, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=2171; -- Blackwood Shaman, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2675; -- Explosive Sheep, speed_walk=1.08, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2951; -- Palemane Poacher, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2975; -- Venture Co. Hireling, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2982; -- Seer Graytongue, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=2983; -- The Plains Vision, speed_walk=0.75, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2984; -- Seer Wiserunner, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2989; -- Bael'dun Digger, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2990; -- Bael'dun Appraiser, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3051; -- Supervisor Fizsprocket, speed_walk=0.98, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3270; -- Elder Mystic Razorsnout, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3393; -- Captain Fairmount, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3438; -- Kreenig Snarlsnout, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3455; -- Cannoneer Whessan, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3503; -- Silithid Protector, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3844; -- Healing Ward IV, speed_walk=0.73, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3846; -- Talen, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3902; -- Searing Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3911; -- Stoneclaw Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4263; -- Deepmoss Hatchling, speed_walk=0.44, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4509; -- Sargath, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5786; -- Snagglespear, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5859; -- Hagg Taurenbane, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5879; -- Fire Nova Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5919; -- Stoneskin Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6111; -- Fire Nova Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6867; -- Tracking Hound, speed_walk=0.92, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7287; -- Foreman Silixiz, speed_walk=0.97, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7399; -- Stoneclaw Totem VI, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7413; -- Frost Resistance Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7466; -- Magma Totem IV, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7845; -- Fire Nova Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11101; -- Mana Tide Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11901; -- Andruk, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12717; -- Muglash, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12719; -- Marukai, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12721; -- Mitsuwa, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12736; -- Je'neu Sancrea, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12757; -- Karang Amakkar, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12863; -- Warsong Runner, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12961; -- Kil'Hiwana, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12962; -- Wik'Tar, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.444444 WHERE `entry`=16548; -- Mr. Wiggles, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17038; -- Stormwind Firebreather, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17041; -- Orgrimmar Fireeater, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17048; -- Ironforge Firebreather, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17049; -- Darnassus Firebreather, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17050; -- Thunder Bluff Fireeater, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=17051; -- Undercity Fireeater, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=775; -- Kurzen's Agent, speed_walk=1.14, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.6 WHERE `entry`=1559; -- King Mukla, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2178; -- Wailing Highborne, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2184; -- Lady Moongazer, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2634; -- Princess Poobah, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2667; -- Ward of Laze, speed_walk=0.79, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3667; -- Anaya Dawnrunner, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3903; -- Searing Totem III, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7666; -- Archmage Allistarj, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7772; -- Kalin Windflight, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=11690; -- Gnarlpine Instigator, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=14890; -- Taerar, speed_walk=1.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.2 WHERE `entry`=15224; -- Dream Fog, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.777776 WHERE `entry`=314; -- Eliza, speed_walk=2.07, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1018; -- Highland Razormaw, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1019; -- Elder Razormaw, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1755; -- Marzon the Silent Blade, speed_walk=1.08, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1827; -- Scarlet Sentinel, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1832; -- Scarlet Magus, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1834; -- Scarlet Paladin, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1846; -- High Protector Lorik, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=1871; -- Eliza's Guard, speed_walk=1.06, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1883; -- Scarlet Worker, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=2172; -- Strider Clutchmother, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2250; -- Mountain Yeti, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2306; -- Baron Vardus, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2345; -- Dun Garok Rifleman, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2346; -- Dun Garok Priest, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2403; -- Farmer Getz, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2447; -- Narillasanz, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2449; -- Citizen Wilkes, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2462; -- Flesh Eating Worm, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2523; -- Searing Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2573; -- Drywhisker Surveyor, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2574; -- Drywhisker Digger, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2609; -- Geomancer Flintdagger, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=2623; -- Spirit of Old, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=2678; -- Mechanical Dragonling, speed_walk=1.18, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2684; -- Rizz Loosebolt, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2992; -- Healing Ward V, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3527; -- Healing Stream Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3560; -- Healing Ward, speed_walk=0.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3579; -- Stoneclaw Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3585; -- Therysil, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3759; -- Felmusk Rogue, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3762; -- Felmusk Felsworn, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3763; -- Felmusk Shadowstalker, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3799; -- Severed Druid, speed_walk=1.08, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3801; -- Severed Sleeper, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3802; -- Severed Dreamer, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3803; -- Severed Keeper, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3804; -- Forsaken Intruder, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3806; -- Forsaken Infiltrator, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3807; -- Forsaken Assassin, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3808; -- Forsaken Dark Stalker, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3906; -- Healing Stream Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3907; -- Healing Stream Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3912; -- Stoneclaw Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3921; -- Thistlefur Ursa, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3922; -- Thistlefur Totemic, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=3923; -- Thistlefur Den Watcher, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3942; -- Mavoris Cloudsbreak, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3984; -- Nancy Vishas, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=3985; -- Grandpa Vishas, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=3.6 WHERE `entry`=4059; -- Forest Spirit, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4494; -- Scarlet Spellbinder, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4504; -- Frostmaw, speed_walk=1.14, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=4634; -- Kolkar Mauler, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4670; -- Hatefury Rogue, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4671; -- Hatefury Trickster, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4672; -- Hatefury Felsworn, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4673; -- Hatefury Betrayer, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4674; -- Hatefury Shadowstalker, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4675; -- Hatefury Hellcaller, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4711; -- Slitherblade Naga, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4712; -- Slitherblade Sorceress, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4713; -- Slitherblade Warrior, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4714; -- Slitherblade Myrmidon, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4715; -- Slitherblade Razortail, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4716; -- Slitherblade Tidehunter, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4718; -- Slitherblade Oracle, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4719; -- Slitherblade Sea Witch, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4781; -- Snufflenose Gopher, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4787; -- Argent Guard Thaelrid, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4789; -- Fallenroot Rogue, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4798; -- Fallenroot Shadowstalker, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4799; -- Fallenroot Hellcaller, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4805; -- Blackfathom Sea Witch, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4807; -- Blackfathom Myrmidon, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4815; -- Murkshallow Snapclaw, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4818; -- Blindlight Murloc, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4819; -- Blindlight Muckdweller, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4820; -- Blindlight Oracle, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4821; -- Skittering Crustacean, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4822; -- Snapping Crustacean, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4824; -- Aku'mai Fisher, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4831; -- Lady Sarevess, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=4887; -- Ghamoo-ra, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5331; -- Hatecrest Warrior, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5395; -- Felgur Twocuts, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=5398; -- Warug, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5412; -- Gurda Wildmane, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=5600; -- Khan Dez'hepah, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=5601; -- Khan Jehn, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5920; -- Stoneskin Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5922; -- Strength of Earth Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5923; -- Poison Cleansing Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5926; -- Frost Resistance Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5927; -- Fire Resistance Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=5933; -- Achellios the Banished, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=5935; -- Ironeye the Invincible, speed_walk=1.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6016; -- Elemental Protection Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6017; -- Lava Spout Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6019; -- Hornizz Brimbuzzle, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6066; -- Earthgrab Totem, speed_walk=0.84, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=6068; -- Warug's Bodyguard, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6110; -- Fire Nova Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6198; -- Blood Elf Surveyor, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6199; -- Blood Elf Reclaimer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6200; -- Legashi Satyr, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6201; -- Legashi Rogue, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6202; -- Legashi Hellcaller, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6238; -- Big Will, speed_walk=1.13, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6240; -- Affray Challenger, speed_walk=1.06, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6243; -- Gelihast, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6349; -- Great Wavethrasher, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6350; -- Makrinni Razorclaw, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6351; -- Storm Bay Oracle, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.2 WHERE `entry`=6378; -- Thunderhead Skystormer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=6412; -- Skeleton, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=6493; -- Illusionary Phantasm, speed_walk=1.54, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=6585; -- Uhk'loc, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=6651; -- Gatekeeper Rageroar, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7107; -- Jadefire Trickster, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7110; -- Jadefire Shadowstalker, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7115; -- Jaedenar Adept, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7125; -- Jaedenar Hound, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=7153; -- Deadwood Warrior, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=7154; -- Deadwood Gardener, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=7155; -- Deadwood Pathfinder, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7360; -- Dun Garok Soldier, speed_walk=1.08, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7366; -- Stoneskin Totem IV, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7367; -- Stoneskin Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7398; -- Stoneclaw Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7400; -- Searing Totem V, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7412; -- Frost Resistance Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7415; -- Mana Spring Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7425; -- Fire Resistance Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7464; -- Magma Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7465; -- Magma Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7483; -- Windfury Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7486; -- Grace of Air Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7487; -- Grace of Air Totem II, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7527; -- Goblin Land Mine, speed_walk=1.16, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=7543; -- Dark Whelpling, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=7544; -- Crimson Whelpling, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7769; -- Hazzali Parasite, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7844; -- Fire Nova Totem IV, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.5 WHERE `entry`=7918; -- Stone Watcher of Norgannon, speed_walk=0.95, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8152; -- Harnor, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.6 WHERE `entry`=8297; -- Magronos the Unyielding, speed_walk=1.76, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.8 WHERE `entry`=8317; -- Atal'ai Deathwalker's Spirit, speed_walk=1, speed_run=0.4
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8392; -- Pilot Xiggs Fuselighter, speed_walk=1.17, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8408; -- Warlord Krellian, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8420; -- Kim'jael, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8446; -- Xiggs Fuselighter's Flyingmachine, speed_walk=1.17, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8937; -- Pet Bomb, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9454; -- Xavathras, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=9464; -- Overlord Ror, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9516; -- Lord Banehollow, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9636; -- Kireena, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9687; -- Windwall Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9689; -- Windwall Totem III, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10183; -- Moonflare Totem, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10383; -- Broken Cadaver, speed_walk=0.7, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10536; -- Plagued Maggot, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10581; -- Young Arikara, speed_walk=1.07, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10608; -- Scarlet Priest, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=10639; -- Rorgish Jowl, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10648; -- Xavaric, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10697; -- Bile Slime, speed_walk=0.65, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10699; -- Carrion Scarab, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10717; -- Temporal Parasite, speed_walk=0.62, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10719; -- Herald of Thrall, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=10720; -- Galak Assassin, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.777776 WHERE `entry`=10836; -- Farmer Dalson, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10876; -- Undead Scarab, speed_walk=0.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10929; -- Haleh, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10940; -- Ghost of the Past, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.777776 WHERE `entry`=10943; -- Decrepit Guardian, speed_walk=1.72, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10980; -- Umi's Mechanical Yeti, speed_walk=0.23, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11016; -- Captured Arko'narin, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11197; -- Mindless Skeleton, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11199; -- Crimson Cannon, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=11200; -- Summoned Skeleton, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11561; -- Undead Ravager, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11611; -- Cavalier Durgen, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11613; -- Huntsman Radley, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11614; -- Bloodshot, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11637; -- Servant of Alexi Barov, speed_walk=1.14, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11712; -- Lilyn Darkriver, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11730; -- Hive'Regal Ambusher, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11731; -- Hive'Regal Burrower, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=11732; -- Hive'Regal Spitfire, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11733; -- Hive'Regal Slavemaker, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11734; -- Hive'Regal Hive Lord, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11863; -- Azore Aldamort, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11875; -- Mortar Team Target Dummy, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11876; -- Demon Spirit, speed_walk=1.12, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11886; -- Mercutio Filthgorger, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11887; -- Crypt Robber, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12116; -- Priestess of Elune, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.4 WHERE `entry`=12120; -- Plagueland Termite, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12140; -- Guardian of Elune, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12152; -- Voice of Elune, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12178; -- Tortured Druid, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12179; -- Tortured Sentinel, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12257; -- Mechanical Yeti, speed_walk=0.31, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12347; -- Enraged Reef Crawler, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12369; -- Lord Kragaru, speed_walk=1.13, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12422; -- Death Talon Dragonspawn, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12581; -- Mercutio, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12677; -- Shadumbra, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12777; -- Captain Dirgehammer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12782; -- Captain O'Neal, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.2 WHERE `entry`=12818; -- Ruul Snowhoof, speed_walk=0.9, speed_run=1
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12902; -- Lorgus Jett, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=12921; -- Enraged Foulweald, speed_walk=1.04, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12940; -- Vorsha the Lasher, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=13136; -- Hive'Ashi Drone, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=13421; -- Champion Guardian, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=13717; -- Centaur Pariah, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14081; -- Demon Portal, speed_walk=1.13, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14278; -- Ro'Bark, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14337; -- Field Repair Bot 74A, speed_walk=0.6, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14366; -- Warpwood Spores, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14465; -- Alliance Battle Standard, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14466; -- Horde Battle Standard, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=14474; -- Zora, speed_walk=1.78, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14522; -- Ur'dan, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14668; -- Corrupted Infernal, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14751; -- Frostwolf Battle Standard, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14862; -- Emissary Roman'khan, speed_walk=1.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.6 WHERE `entry`=14884; -- Parasitic Serpent, speed_walk=1.69, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=14965; -- Frenzied Bloodseeker Bat, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14987; -- Powerful Healing Ward, speed_walk=0.001, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14988; -- Ohgan, speed_walk=1.18, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14989; -- Poisonous Cloud, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=15009; -- Voodoo Spirit, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=15041; -- Spawn of Mar'li, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15047; -- Gurubashi, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15065; -- Lady, speed_walk=0.9, speed_run=1
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15066; -- Cleo, speed_walk=0.9, speed_run=1
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15068; -- Zulian Guardian, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15071; -- Underfoot, speed_walk=0.9, speed_run=1
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15072; -- Spike, speed_walk=0.9, speed_run=1
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15101; -- Zulian Prowler, speed_walk=1.24, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15112; -- Brain Wash Totem, speed_walk=0.001, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15169; -- Ralo'shan the Eternal Watcher, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15196; -- Deathclasp, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15213; -- Twilight Overlord, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15293; -- Aendel Windspear, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2.4 WHERE `entry`=15299; -- Viscidus, speed_walk=2.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15304; -- Ancient Mana Spring Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.6 WHERE `entry`=15311; -- Anubisath Warder, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2.4 WHERE `entry`=15312; -- Obsidian Nullifier, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15362; -- Malfurion Stormrage, speed_walk=1.27, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15383; -- Sergeant Stonebrow, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=15414; -- Qiraji Wasp, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=15421; -- Qiraji Drone, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.4 WHERE `entry`=15422; -- Qiraji Tank, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15431; -- Corporal Carnes, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15432; -- Dame Twinbraid, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15434; -- Private Draxlegauge, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15437; -- Master Nightsong, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15445; -- Sergeant Major Germaine, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15446; -- Bonnie Stoneflayer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15448; -- Private Porter, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15450; -- Marta Finespindle, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15451; -- Sentinel Silversky, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15452; -- Nurse Stonefield, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15453; -- Keeper Moonshade, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15455; -- Slicky Gastronome, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15456; -- Sarah Sadwhistle, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15457; -- Huntress Swiftriver, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15459; -- Miner Cromwell, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15460; -- Grunt Maug, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15469; -- Senior Sergeant T'kelah, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15512; -- Apothecary Jezel, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15522; -- Sergeant Umala, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15525; -- Doctor Serratus, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15528; -- Healer Longrunner, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15529; -- Lady Callow, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15532; -- Stoneguard Clayhoof, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15533; -- Bloodguard Rawtar, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15534; -- Fisherman Lin'do, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15535; -- Chief Sharpclaw, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15539; -- General Zog, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2.4 WHERE `entry`=15546; -- Hive'Zara Swarmer, speed_walk=1.71, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=15555; -- Hive'Zara Larva, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15610; -- Cenarion Scout Azenel, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15630; -- Spawn of Fankriss, speed_walk=1.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15696; -- War Effort Recruit, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15700; -- Warlord Gorchuk, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15701; -- Field Marshal Snowfall, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15704; -- Senior Sergeant Kai'jin, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15707; -- Master Sergeant Fizzlebolt, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15708; -- Master Sergeant Maclure, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15709; -- Master Sergeant Moonshadow, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=0.666668 WHERE `entry`=15720; -- Timbermaw Ancestor, speed_walk=1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15731; -- Darnassus Commendation Officer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15733; -- Gnomeregan Commendation Officer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15734; -- Ironforge Commendation Officer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15735; -- Stormwind Commendation Officer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15739; -- Thunder Bluff Commendation Officer, speed_walk=1.125, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15740; -- Colossus of Zora, speed_walk=8.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15742; -- Colossus of Ashi, speed_walk=8.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=4.8 WHERE `entry`=15743; -- Colossal Anubisath Warbringer, speed_walk=4.5, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=4.8 WHERE `entry`=15744; -- Imperial Qiraji Destroyer, speed_walk=4.94, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15797; -- Colossus Researcher Sophia, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15798; -- Colossus Researcher Nestor, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15799; -- Colossus Researcher Eazel, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=4.8 WHERE `entry`=15818; -- Lieutenant General Nokhor, speed_walk=1.74, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15842; -- Might of Kalimdor Mage, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15849; -- Might of Kalimdor Druid, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15850; -- Might of Kalimdor Skirmisher, speed_walk=1.2, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=16184; -- Nerubian Overseer, speed_walk=1.1, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=1000; -- Unkillable Test Dummy, speed_walk=1.02, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9637; -- Scorching Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9916; -- Jarquia, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14122; -- Massive Geyser, speed_walk=1.07, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15141; -- Portal of Madness, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15163; -- Nightmare Illusion, speed_walk=1.26, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=2520; -- Remote-Controlled Golem, speed_walk=0.57, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7667; -- Lady Sevine, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7728; -- Kirith the Damned, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=7729; -- Spirit of Kirith, speed_walk=1.23, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8304; -- Dreadscorn, speed_walk=1.05, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=8612; -- Screecher Spirit, speed_walk=0.9, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9707; -- Scarshield Portal, speed_walk=0.91, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=9708; -- Burning Imp, speed_walk=1.21, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=10217; -- Flame Buffet Totem, speed_walk=0.01, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=11258; -- Frail Skeleton, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=11263; -- Spectral Projection, speed_walk=1.15, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12141; -- Ice Totem, speed_walk=1.22, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12143; -- Son of Flame, speed_walk=1.76, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1.55556 WHERE `entry`=14350; -- Hydroling, speed_walk=1.22, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14500; -- J'eevee, speed_walk=1.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14362; -- Thornling, speed_walk=0.25, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=15741; -- Colossus of Regal, speed_walk=8.8, speed_run=1.14286
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=2.14286 WHERE `entry`=11583; -- Nefarian, speed_walk=3.9, speed_run=1.14286

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
