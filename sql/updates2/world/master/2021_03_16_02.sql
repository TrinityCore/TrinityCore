-- DB update 2021_03_16_01 -> 2021_03_16_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_16_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_16_01 2021_03_16_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613997950982437928'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613997950982437928');

-- Convert a load of mechanic_immune_mask's from vmangos, see
-- https://github.com/azerothcore/azerothcore-wotlk/pull/4630
-- for a long explanation of the reasoning behind

-- 'Harvest Golem', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=36;

-- 'Skeletal Warrior', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=48;

-- 'Rock Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646015775 WHERE `entry`=92;

-- 'Harvest Watcher', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=114;

-- 'Harvest Reaper', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=115;

-- 'Skeletal Horror', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=202;

-- 'Skeletal Mage', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=203;

-- 'Earth Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=329;

-- 'Dungar Longdrink', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=352;

-- 'Rusty Harvest Golem', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=480;

-- 'Water Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=510;

-- 'Mor'Ladim', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=522;

-- 'Thor', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=523;

-- 'Skeletal Fiend', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=531;

-- 'Foe Reaper 4000', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=573;

-- 'Fire Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=575;

-- 'Skeletal Miner', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=623;

-- 'Foreman Thistlenettle', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=8388752 WHERE `entry`=626;

-- 'Edwin VanCleef', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608909011 WHERE `entry`=639;

-- 'Sneed's Shredder', mechanic_immune_mask was 76251103
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608925395 WHERE `entry`=642;

-- 'Sneed', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608909011 WHERE `entry`=643;

-- 'Cookie', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608909011 WHERE `entry`=645;

-- 'Mr. Smite', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608909011 WHERE `entry`=646;

-- 'Captain Greenskin', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608909011 WHERE `entry`=647;

-- 'Lesser Water Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=691;

-- 'Marsh Oracle', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=752;

-- 'Swampwalker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=764;

-- 'Swampwalker Elder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=765;

-- 'Tangled Horror', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=766;

-- 'Commander Felstrom', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=771;

-- 'Skeletal Warder', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=785;

-- 'Skeletal Healer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=787;

-- 'Dust Devil', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=832;

-- 'Ariena Stormfeather', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=931;

-- 'Fen Dweller', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1039;

-- 'Fen Creeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1040;

-- 'Fen Lord', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1041;

-- 'Mire Lord', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1081;

-- 'Skeletal Raider', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1110;

-- 'Cursed Sailor', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1157;

-- 'Cursed Marine', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1158;

-- 'Captain Halyndor', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1160;

-- 'Rethiel the Greenwarden', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1244;

-- 'Archbishop Benedictus', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=1284;

-- 'Thysta', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=1387;

-- 'Rattlecage Soldier', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1520;

-- 'Darkeye Bonecaster', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1522;

-- 'Cracked Skull Soldier', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1523;

-- 'Lost Soul', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1531;

-- 'Wailing Ancestor', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1534;

-- 'Shellei Brondir', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=1571;

-- 'Thorgrum Borrelson', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=1572;

-- 'Gryth Thurden', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=1573;

-- 'Nissa Agamand', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1655;

-- 'Devlin Agamand', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1657;

-- 'Captain Dargol', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1658;

-- 'Dextren Ward', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=1663;

-- 'Kam Deepfury', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=1666;

-- 'Targorr the Dread', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=1696;

-- 'Bazil Thredd', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=1716;

-- 'Hamhock', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=1717;

-- 'Bruegal Ironknuckle', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=1720;

-- 'Highlord Bolvar Fordragon', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=1748;

-- 'Gilnid', mechanic_immune_mask was 76234719
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=608909011 WHERE `entry`=1763;

-- 'Skeletal Flayer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1783;

-- 'Skeletal Sorcerer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1784;

-- 'Skeletal Terror', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1785;

-- 'Skeletal Executioner', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1787;

-- 'Skeletal Warlord', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1788;

-- 'Skeletal Acolyte', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1789;

-- 'Cold Wraith', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1800;

-- 'Blood Wraith', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1801;

-- 'Hungering Wraith', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1802;

-- 'Wailing Death', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1804;

-- 'Rotting Behemoth', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1812;

-- 'Decaying Horror', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1813;

-- 'Grand Inquisitor Isillien', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=616644443 WHERE `entry`=1840;

-- 'Highlord Taelan Fordring', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=1842;

-- 'The Husk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1851;

-- 'Araj the Summoner', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=1852;

-- 'Darkmaster Gandling', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235 WHERE `entry`=1853;

-- 'Ravenclaw Raider', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1865;

-- 'Ravenclaw Champion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1869;

-- 'Hand of Ravenclaw', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1870;

-- 'Eliza's Guard', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1871;

-- 'Rattlecage Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1890;

-- 'Stephen Bhartec', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1916;

-- 'Combat Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=1921;

-- 'Lillith Nefara', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1946;

-- 'Lake Skulker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1953;

-- 'Elder Lake Skulker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1954;

-- 'Lake Creeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1955;

-- 'Elder Lake Creeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1956;

-- 'Treant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=1964;

-- 'Ravenclaw Guardian', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=1973;

-- 'Nightlash', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=1983;

-- 'Timberling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2022;

-- 'Timberling Bark Ripper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2025;

-- 'Timberling Trampler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2027;

-- 'Timberling Mire Beast', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2029;

-- 'Elder Timberling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2030;

-- 'Forlorn Spirit', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=2044;

-- 'Ravenclaw Apparition', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=2056;

-- 'Cracked Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2156;

-- 'Stone Behemoth', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2157;

-- 'Oakenscowl', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2166;

-- 'Cursed Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=2176;

-- 'Writhing Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=2177;

-- 'Wailing Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=2178;

-- 'Lady Moongazer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=2184;

-- 'Stone Fury', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2258;

-- 'Ravenclaw Regent', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=2283;

-- 'Borgus Stoutarm', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2299;

-- 'Elemental Slave', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=2359;

-- 'Felicia Maline', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2409;

-- 'Varimathras', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=2425;

-- 'Darla Harris', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2432;

-- 'Narillasanz', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8392272 WHERE `entry`=2447;

-- 'Skeletal Fiend (Enraged Form)', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=2454;

-- 'Remote-Controlled Golem', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=2520;

-- 'Brutus', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2551;

-- 'Rumbling Exile', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2592;

-- 'Spirit of Old', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=2623;

-- 'Syndicate Spectre', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=2638;

-- 'Ward of Laze', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2667;

-- 'Mechanical Squirrel', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2671;

-- 'Explosive Sheep', mechanic_immune_mask was 0
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=902267423 WHERE `entry`=2675;

-- 'Compact Harvest Reaper', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=2676;

-- 'Mechanical Dragonling', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=2678;

-- 'Stone Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2723;

-- 'Lesser Rock Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=2735;

-- 'Ambassador Infernus', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=2745;

-- 'Archaedas', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=2748;

-- 'War Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2751;

-- 'Rumbler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2752;

-- 'Myzrael', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2755;

-- 'Burning Exile', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=2760;

-- 'Cresting Exile', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2761;

-- 'Thundering Exile', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2762;

-- 'Vengeful Surge', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2776;

-- 'King Magni Bronzebeard', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=2784;

-- 'Enraged Rock Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=2791;

-- 'Summoned Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2794;

-- 'Cedrik Prose', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2835;

-- 'Urda', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2851;

-- 'Gringer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2858;

-- 'Gyll', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2859;

-- 'Gorrik', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2861;

-- 'Prismatic Exile', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2887;

-- 'Fam'retor Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=2919;

-- 'Servo', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=2922;

-- 'Lanie Reed', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2941;

-- 'Puppet of Helcular', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=2946;

-- 'Tal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=2995;

-- 'Cairne Bloodhoof', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=3057;

-- 'Unseen', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=3094;

-- 'Silithid Harvester', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=33554432 WHERE `entry`=3253;

-- 'Grisha', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=3305;

-- 'Doras', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=3310;

-- 'Living Flame', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=3417;

-- 'Arch Druid Fandral Staghelm', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=3516;

-- 'Blackmoss the Fetid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3535;

-- 'Overwatch Mark I', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=3538;

-- 'Bogling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3569;

-- 'Cleansed Timberling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3570;

-- 'Miner Johnson', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=3586;

-- 'Devrak', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=3615;

-- 'Lordaeron Citizen', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=3617;

-- 'Mutanus the Devourer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3654;

-- 'Anaya Dawnrunner', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3667;

-- 'Lord Cobrahn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3669;

-- 'Lord Pythas', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3670;

-- 'Lady Anacondra', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3671;

-- 'Lord Serpentis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3673;

-- 'Skum', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3674;

-- 'Disciple of Naralex', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=529 WHERE `entry`=3678;

-- 'Dark Strand Cultist', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=3725;

-- 'Dark Strand Adept', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=3728;

-- 'Shadethicket Moss Eater', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3780;

-- 'Shadethicket Wood Shaper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3781;

-- 'Shadethicket Stone Mover', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3782;

-- 'Shadethicket Raincaller', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3783;

-- 'Shadethicket Bark Ripper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3784;

-- 'Severed Sleeper', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3801;

-- 'Crazed Ancient', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3834;

-- 'Lupine Horror', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3863;

-- 'Deathsworn Captain', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3872;

-- 'Tormented Officer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3873;

-- 'Haunted Servitor', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3875;

-- 'Wailing Guardsman', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=3877;

-- 'Razorclaw the Butcher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=3886;

-- 'Baron Silverlaine', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=3887;

-- 'Rethilgore', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3914;

-- 'Befouled Water Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=3917;

-- 'Withered Ancient', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3919;

-- 'Wolf Master Nandos', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=3927;

-- 'Shadethicket Oracle', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3931;

-- 'Minor Water Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=3950;

-- 'Houndmaster Loksey', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=3974;

-- 'Herod', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=3975;

-- 'Scarlet Commander Mograine', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=3976;

-- 'High Inquisitor Whitemane', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=3977;

-- 'Interrogator Vishas', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=3983;

-- 'Charred Ancient', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4028;

-- 'Blackened Ancient', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4029;

-- 'Vengeful Ancient', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4030;

-- 'Enraged Stone Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4034;

-- 'Furious Stone Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4035;

-- 'Rogue Flame Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=4036;

-- 'Burning Ravager', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=4037;

-- 'Burning Destroyer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=4038;

-- 'XT:4', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4073;

-- 'XT:9', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4074;

-- 'Thundering Boulderkin', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4120;

-- 'Goblin Racer', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4251;

-- 'Gnome Racer', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4252;

-- 'Venture Co. Shredder', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4260;

-- 'Fenrus the Devourer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4274;

-- 'Archmage Arugal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4275;

-- 'Eye of Kilrogg', mechanic_immune_mask was 0
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=902267423 WHERE `entry`=4277;

-- 'Commander Springvale', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4278;

-- 'Odo the Blindwatcher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4279;

-- 'Tharm', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=4312;

-- 'Gorkas', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=4314;

-- 'Nyse', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=4317;

-- 'Baldruc', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=4321;

-- 'Withervine Creeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4382;

-- 'Withervine Rager', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4385;

-- 'Withervine Bark Ripper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4386;

-- 'Withervine Mire Beast', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4387;

-- 'Overlord Ramtusk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4420;

-- 'Charlga Razorflank', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4421;

-- 'Agathelos the Raging', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4422;

-- 'Darnassian Protector', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4423;

-- 'Aggem Thorncurse', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4424;

-- 'Death Speaker Jargba', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4428;

-- 'Haunting Vision', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=4472;

-- 'Rok'Alim the Pounder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4499;

-- 'Wind Howler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4526;

-- 'Stone Rumbler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4528;

-- 'High Inquisitor Fairbanks', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=4542;

-- 'Bloodmage Thalnos', mechanic_immune_mask was 8390928
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=4543;

-- 'Ophelia Montague', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4550;

-- 'Aelthalyste', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4606;

-- 'Gelkis Rumbler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4661;

-- 'Twilight Elementalist', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=4814;

-- 'Aku'mai', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4829;

-- 'Old Serra'kis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4830;

-- 'Lady Sarevess', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4831;

-- 'Twilight Lord Kelris', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4832;

-- 'Earthcaller Halmgar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=4842;

-- 'Grimlok', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=4854;

-- 'Stone Keeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4857;

-- 'Stone Steward', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4860;

-- 'Obsidian Golem', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4872;

-- 'Goblin Drag Car', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4945;

-- 'Gnome Drag Car', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4946;

-- 'Thrall', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=4949;

-- 'Theramore Combat Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=4952;

-- 'Lady Jaina Proudmoore', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=4968;

-- 'Aku'mai Servant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=4978;

-- 'Deviate Lasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5055;

-- 'Archery Target', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=5202;

-- 'Nightmare Scalebane', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=512 WHERE `entry`=5277;

-- 'Nightmare Wyrmkin', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=512 WHERE `entry`=5280;

-- 'Nightmare Wanderer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=512 WHERE `entry`=5283;

-- 'Gnarl Leafbrother', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5354;

-- 'Sea Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=5461;

-- 'Sea Spray', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5462;

-- 'Land Rager', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5465;

-- 'Thistleshrub Dew Collector', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5481;

-- 'Thistleshrub Rootshaper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5485;

-- 'Gnarled Thistleshrub', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5490;

-- 'Practice Target', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=5674;

-- 'Shade of Eranikus', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=5709;

-- 'Jammal'an the Prophet', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=5710;

-- 'Ogom the Wretched', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8912913 WHERE `entry`=5711;

-- 'Morphaz', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=5719;

-- 'Weaver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=5720;

-- 'Dreamscythe', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=5721;

-- 'Hazzas', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=5722;

-- 'Warug's Target Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=5723;

-- 'Deviate Shambler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5761;

-- 'Guardian of Blizzard', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=5764;

-- 'Verdan the Everliving', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=5775;

-- 'Treant Ally', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5806;

-- 'Blazing Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=5850;

-- 'Inferno Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=5852;

-- 'Tempered War Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5853;

-- 'Heavy War Golem', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=5854;

-- 'Magma Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=5855;

-- 'Cursed Sycamore', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5881;

-- 'Mesa Earth Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5889;

-- 'Redrock Earth Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5890;

-- 'Minor Manifestation of Earth', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5891;

-- 'Minor Manifestation of Fire', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=5893;

-- 'Corrupt Minor Manifestation of Water', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5894;

-- 'Minor Manifestation of Water', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5895;

-- 'Fire Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=5896;

-- 'Corrupt Water Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5897;

-- 'Air Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5898;

-- 'Minor Manifestation of Air', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=5902;

-- 'Deviate Faerie Dragon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=5912;

-- 'Boar Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=6021;

-- 'Breyk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=6026;

-- 'Aqua Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6047;

-- 'Highborne Apparition', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=6116;

-- 'Highborne Lichling', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=6117;

-- 'Varo'then's Ghost', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=6118;

-- 'Shade of Elura', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=6133;

-- 'Roogug', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=6168;

-- 'Irradiated Horror', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6220;

-- 'Mechano-Tank', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6225;

-- 'Mechano-Flamewalker', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6226;

-- 'Mechano-Frostwalker', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6227;

-- 'Dark Iron Ambassador', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=6228;

-- 'Crowd Pummeler 9-60', mechanic_immune_mask was 17408
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=6229;

-- 'Peacekeeper Security Suit', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6230;

-- 'Techbot', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6231;

-- 'Arcane Nullifier X-21', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6232;

-- 'Mechanized Sentry', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6233;

-- 'Mechanized Guardian', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6234;

-- 'Electrocutioner 6000', mechanic_immune_mask was 17408
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=6235;

-- 'Cyclonian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6239;

-- 'Gelihast', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=6243;

-- 'Ward of Zanzil', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6386;

-- 'Zanzil Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=6388;

-- 'Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=6412;

-- 'Haunting Phantasm', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6427;

-- 'Arcanist Doan', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=6487;

-- 'Fallen Champion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=6488;

-- 'Ironspine', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=6489;

-- 'Azshir the Sleepless', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=6490;

-- 'Illusionary Phantasm', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6493;

-- 'Bloodpetal Lasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6509;

-- 'Bloodpetal Flayer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6510;

-- 'Bloodpetal Thresher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6511;

-- 'Bloodpetal Trapper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6512;

-- 'Tar Beast', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6517;

-- 'Tar Lurker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6518;

-- 'Tar Lord', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6519;

-- 'Scorching Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=6520;

-- 'Living Blaze', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=6521;

-- 'Tar Creeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6527;

-- 'Mana Surge', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6550;

-- 'Stone Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6560;

-- 'King Mosh', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=545267280 WHERE `entry`=6584;

-- 'The Threshwackonator 4100', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=6669;

-- 'Thalon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=6726;

-- 'Water Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6748;

-- 'Baelog', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=6906;

-- 'Eric "The Swift"', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=6907;

-- 'Olaf', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=6908;

-- 'Revelosh', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=6910;

-- 'Swamp Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=6932;

-- 'Obsidian Sentinel', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7023;

-- 'Obsidian Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=7031;

-- 'Greater Obsidian Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=7032;

-- 'War Reaver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7039;

-- 'Arados the Damned', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=7073;

-- 'Judge Thelgram', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=7074;

-- 'Earthen Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7076;

-- 'Earthen Hallshaper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7077;

-- 'Viscous Fallout', mechanic_immune_mask was 1024
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=7079;

-- 'Warpwood Moss Flayer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7100;

-- 'Warpwood Shredder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7101;

-- 'Dessecus', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7104;

-- 'Toxic Horror', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7132;

-- 'Irontree Wanderer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7138;

-- 'Irontree Stomper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7139;

-- 'Withered Protector', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7149;

-- 'Wrenix's Gizmotronic Apparatus', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7166;

-- 'Ancient Stone Keeper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7206;

-- 'Obsidian Shard', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7209;

-- 'Sand Storm', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7226;

-- 'Ironaya', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=7228;

-- 'Ember', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=7266;

-- 'Chief Ukorz Sandscalp', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7267;

-- 'Witch Doctor Zum'rah', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7271;

-- 'Theka the Martyr', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7272;

-- 'Gahz'rilla', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=7273;

-- 'Sandfury Executioner', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=7274;

-- 'Shadowpriest Sezz'ziz', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7275;

-- 'Galgann Firehammer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=7291;

-- 'Earthen Custodian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7309;

-- 'Skeletal Frostweaver', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7341;

-- 'Skeletal Summoner', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7342;

-- 'Splinterbone Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7343;

-- 'Splinterbone Warrior', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7344;

-- 'Splinterbone Captain', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7345;

-- 'Splinterbone Centurion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7346;

-- 'Frozen Soul', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7352;

-- 'Freezing Spirit', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7353;

-- 'Ragglesnout', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=7354;

-- 'Plaguemaw the Rotting', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=7356;

-- 'Grubbis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=7361;

-- 'Flawless Draenethyst Sphere', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7364;

-- 'Flawless Draenethyst Fragment', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7365;

-- 'Restless Shade', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=7370;

-- 'Earthen Stonecarver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8192 WHERE `entry`=7397;

-- 'Faltering Draenethyst Sphere', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7409;

-- 'Suffering Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=7523;

-- 'Anguished Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=7524;

-- 'Goblin Land Mine', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7527;

-- 'Wandering Forest Walker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=7584;

-- 'Sergeant Bly', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7604;

-- 'Burning Servant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=7738;

-- 'Homing Robot OOX-17/TN', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7784;

-- 'Skeleton of Zum'rah', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=7786;

-- 'Hydromancer Velratha', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7795;

-- 'Nekrum Gutchewer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7796;

-- 'Ruuzlu', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=7797;

-- 'Mekgineer Thermaplugg', mechanic_immune_mask was 17408
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=7800;

-- 'Homing Robot OOX-09/HL', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7806;

-- 'Homing Robot OOX-22/FE', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7807;

-- 'Bera Stonehammer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=7823;

-- 'Bulkrek Ragefist', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=7824;

-- 'Teremus the Devourer', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=7846;

-- 'Mobile Alert System', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7849;

-- 'Lingering Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=7864;

-- 'Alarm-a-bomb 2600', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=7897;

-- 'Walking Bomb', mechanic_immune_mask was 650854271
-- MECHANIC_GRIP from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=8405040 WHERE `entry`=7915;

-- 'High Tinker Mekkatorque', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=7937;

-- 'Tyrande Whisperwind', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=7999;

-- 'Sen'jin Guardian', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=8017;

-- 'Guthrum Thunderfist', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=8018;

-- 'Shyn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=8020;

-- 'Dark Iron Land Mine', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=8035;

-- 'Antu'sul', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=8127;

-- 'Smoldar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8278;

-- 'Faulty War Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8279;

-- 'Scald', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=8281;

-- 'Atal'ai Deathwalker's Spirit', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650870623 WHERE `entry`=8317;

-- 'Nightmare Whelp', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=512 WHERE `entry`=8319;

-- 'Atal'ai Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=8324;

-- 'Mechanical Chicken', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8376;

-- 'Deep Lurker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8384;

-- 'Raze', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8441;

-- 'Avatar of Hakkar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=8443;

-- 'Clunk', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=8447;

-- 'Skeletal Servant', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8477;

-- 'Blighted Surge', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8519;

-- 'Plague Ravager', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8520;

-- 'Blighted Horror', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8521;

-- 'Plague Monstrosity', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8522;

-- 'Scourge Soldier', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8523;

-- 'Cursed Mage', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8524;

-- 'Scourge Warder', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8525;

-- 'Dark Caster', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8526;

-- 'Scourge Guard', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8527;

-- 'Dread Weaver', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8528;

-- 'Scourge Champion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8529;

-- 'Unseen Servant', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=8538;

-- 'Eyeless Watcher', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=8539;

-- 'Torn Screamer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=8540;

-- 'Hate Shrieker', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=8541;

-- 'Death Singer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=8542;

-- 'Atal'alarion', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=8580;

-- 'Frost Spectre', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=8585;

-- 'Alexandra Constantine', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=8609;

-- 'Kroum', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=8610;

-- 'Mithril Dragonling', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=8615;

-- 'Gusting Vortex', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8667;

-- 'Massive Infernal', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=8680;

-- 'Felguard Elite', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=17 WHERE `entry`=8717;

-- 'Deathly Usher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8816;

-- 'Battle Chicken', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405016 WHERE `entry`=8836;

-- 'Muck Splash', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8837;

-- 'Tyrion's Spybot', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=8856;

-- 'Skeletal Mount', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=8884;

-- 'Warbringer Construct', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8905;

-- 'Ragereaver Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8906;

-- 'Wrath Hammer Construct', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8907;

-- 'Molten War Golem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8908;

-- 'Fireguard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=8909;

-- 'Blazing Fireguard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=8910;

-- 'Fireguard Destroyer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=8911;

-- 'Panzor the Invincible', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612466259 WHERE `entry`=8923;

-- 'Princess Moira Bronzebeard', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613103451 WHERE `entry`=8929;

-- 'Pet Bomb', mechanic_immune_mask was 0
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=902267423 WHERE `entry`=8937;

-- 'Malfunctioning Reaver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8981;

-- 'Ironhand Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=8982;

-- 'Golem Lord Argelmach', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=8983;

-- 'Bael'Gar', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9016;

-- 'Lord Incendius', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613121883 WHERE `entry`=9017;

-- 'High Interrogator Gerstahn', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9018;

-- 'Emperor Dagran Thaurissan', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9019;

-- 'Pyromancer Loregrain', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9024;

-- 'Lord Roccor', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613119835 WHERE `entry`=9025;

-- 'Overmaster Pyron', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=9026;

-- 'Gorosh the Dervish', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9027;

-- 'Grizzle', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9028;

-- 'Eviscerator', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9029;

-- 'Ok'thor the Breaker', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9030;

-- 'Anub'shiah', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9031;

-- 'Hedrum the Creeper', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9032;

-- 'General Angerforge', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9033;

-- 'Hate'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9034;

-- 'Anger'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9035;

-- 'Vile'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9036;

-- 'Gloom'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9037;

-- 'Seeth'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9038;

-- 'Doom'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9039;

-- 'Dope'rel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9040;

-- 'Warder Stilgiss', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9041;

-- 'Verek', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9042;

-- 'Fineous Darkvire', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9056;

-- 'Ambassador Flamelash', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9156;

-- 'Burning Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=9178;

-- 'Highlord Omokk', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9196;

-- 'Spirestone Lord Magus', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=9217;

-- 'Spirestone Battle Lord', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=9218;

-- 'Spirestone Butcher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=9219;

-- 'Shadow Hunter Vosh'gajin', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9236;

-- 'War Master Voone', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9237;

-- 'Gaeriyan', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=9299;

-- 'Houndmaster Grebmar', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9319;

-- 'Blazerunner', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=9376;

-- 'Swirling Vortex', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9377;

-- 'Ground Pounder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9396;

-- 'Living Storm', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9397;

-- 'Dark Keeper Vorfalk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9437;

-- 'Dark Keeper Bethek', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9438;

-- 'Dark Keeper Uggel', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9439;

-- 'Dark Keeper Zimrel', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9441;

-- 'Dark Keeper Ofgut', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9442;

-- 'Dark Keeper Pelver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9443;

-- 'Aquementas', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9453;

-- 'Frenzied Black Drake', mechanic_immune_mask was 1104
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=9461;

-- 'Watchman Doomgrip', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=9476;

-- 'Plugger Spazzring', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659931 WHERE `entry`=9499;

-- 'Phalanx', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613119835 WHERE `entry`=9502;

-- 'Hurley Blackbreath', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9537;

-- 'Ribbly Screwspigot', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9543;

-- 'Overlord Wyrmthalak', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9568;

-- 'Arei Transformed', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9599;

-- 'Treant Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9601;

-- 'A-Me 01', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=9623;

-- 'Lil' Smoky', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=9657;

-- 'Ghok Bashguud', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=9718;

-- 'Quartermaster Zigris', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9736;

-- 'Pyroguard Emberseer', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613121883 WHERE `entry`=9816;

-- 'Entropic Beast', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=9878;

-- 'Entropic Horror', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=25094 WHERE `entry`=9879;

-- 'Magmus', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=9938;

-- 'High Priestess of Thaurissan', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613103451 WHERE `entry`=10076;

-- 'Sandarr Dunereaver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=10080;

-- 'Dustwraith', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=10081;

-- 'Zerillis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=10082;

-- 'Tortured Slave', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10117;

-- 'Vault Warder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=10120;

-- 'Lord Victor Nefarius', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10162;

-- 'Lady Sylvanas Windrunner', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=10181;

-- 'Onyxia', mechanic_immune_mask was 650854271
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659963 WHERE `entry`=10184;

-- 'Azurous', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16 WHERE `entry`=10202;

-- 'Halycon', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10220;

-- 'Burning Felguard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=10263;

-- 'Solakar Flamewreath', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646655835 WHERE `entry`=10264;

-- 'Gizrul the Slavener', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10268;

-- 'Gyth', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10339;

-- 'Fellicent's Shade', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10358;

-- 'General Drakkisath', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10363;

-- 'Crystal Fang', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613104987 WHERE `entry`=10376;

-- 'Omusa Thunderhorn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=10378;

-- 'Spectral Citizen', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10384;

-- 'Ghostly Citizen', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10385;

-- 'Vengeful Phantom', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10387;

-- 'Spiteful Phantom', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10388;

-- 'Wrath Phantom', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10389;

-- 'Skeletal Guardian', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10390;

-- 'Skeletal Berserker', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10391;

-- 'Skul', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10393;

-- 'Black Guard Sentry', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10394;

-- 'Eye of Naxxramas', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10411;

-- 'Warchief Rend Blackhand', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10429;

-- 'The Beast', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10430;

-- 'Vectus', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10432;

-- 'Marduk Blackpool', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10433;

-- 'Magistrate Barthilas', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10435;

-- 'Baroness Anastari', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617316187 WHERE `entry`=10436;

-- 'Nerub'enkan', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10437;

-- 'Maleki the Pallid', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10438;

-- 'Ramstein the Gorger', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=10439;

-- 'Baron Rivendare', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1053507419 WHERE `entry`=10440;

-- 'Shrieking Banshee', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10463;

-- 'Wailing Banshee', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10464;

-- 'Splintered Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10478;

-- 'Risen Lackey', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10482;

-- 'Risen Aberration', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10485;

-- 'Risen Warrior', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10486;

-- 'Risen Protector', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10487;

-- 'Risen Construct', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10488;

-- 'Risen Guard', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10489;

-- 'Risen Bonewarder', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10491;

-- 'Spectral Tutor', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10498;

-- 'Spectral Researcher', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10499;

-- 'Spectral Teacher', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=10500;

-- 'Lady Illucia Barov', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10502;

-- 'Jandice Barov', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10503;

-- 'Lord Alexei Barov', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10504;

-- 'Instructor Malicia', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10505;

-- 'Kirtonos the Herald', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10506;

-- 'The Ravenian', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10507;

-- 'Ras Frostwhisper', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617316187 WHERE `entry`=10508;

-- 'Jed Runewatcher', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10509;

-- 'The Unforgiven', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646675226 WHERE `entry`=10516;

-- 'Vol'jin', mechanic_immune_mask was 617299967
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299963 WHERE `entry`=10540;

-- 'Hearthsinger Forresten', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10558;

-- 'Kirtonos the Herald (Spell Visual)', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=10579;

-- 'Urok Doomhowl', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10584;

-- 'Mother Smolderweb', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613104987 WHERE `entry`=10596;

-- 'Branch Snapper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=10641;

-- 'Eck'alom', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=10642;

-- 'Spellmaw', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=3344 WHERE `entry`=10662;

-- 'Manaclaw', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=5184 WHERE `entry`=10663;

-- 'Scryer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299547 WHERE `entry`=10664;

-- 'Scalding Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=10756;

-- 'Boiling Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=10757;

-- 'Timmy the Cruel', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10808;

-- 'Stonespine', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=10809;

-- 'Archivist Galford', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10811;

-- 'Grand Crusader Dathrohan', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=10812;

-- 'Balnazzar', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10813;

-- 'Chromatic Elite Guard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=537601024 WHERE `entry`=10814;

-- 'Wandering Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10816;

-- 'Lord Darkscythe', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10826;

-- 'Undead Scarab', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=10876;

-- 'Lorekeeper Polkelt', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10901;

-- 'Redpath the Corrupted', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10938;

-- 'Ghost of the Past', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10940;

-- 'Darrowshire Betrayer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10947;

-- 'Darrowshire Defender', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10948;

-- 'Marauding Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=10952;

-- 'Summoned Water Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=10955;

-- 'Kodo Spirit', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10988;

-- 'Fallen Hero', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=10996;

-- 'Cannon Master Willey', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=10997;

-- 'Mindless Undead', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11030;

-- 'Malor the Zealous', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=11032;

-- 'Fras Siabi', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=11058;

-- 'Darrowshire Spirit', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11064;

-- 'Cauldron Lord Razarch', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11076;

-- 'Cauldron Lord Malvinious', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11077;

-- 'Cauldron Lord Soulwrath', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11078;

-- 'Black Guard Swordsmith', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11121;

-- 'Yugrek', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=11139;

-- 'Spirit of Trey Lightforge', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11141;

-- 'Undead Postman', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=11142;

-- 'Postmaster Malown', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=11143;

-- 'Riding MechaStrider (Yellow/Green)', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11151;

-- 'Green Skeletal Warhorse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11156;

-- 'Mindless Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11197;

-- 'Crimson Cannon', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11199;

-- 'Summoned Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11200;

-- 'Manifestation of Water', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11256;

-- 'Frail Skeleton', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11258;

-- 'Doctor Theolen Krastinov', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=11261;

-- 'Spectral Projection', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11263;

-- 'Dark Shade', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11284;

-- 'Rory', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11285;

-- 'Spectral Betrayer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11288;

-- 'Spectral Defender', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11289;

-- 'Darrowshire Poltergeist', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11296;

-- 'Molten Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=11321;

-- 'Zealot Lor'Khan', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=604058971 WHERE `entry`=11347;

-- 'Zealot Zath', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=604059227 WHERE `entry`=11348;

-- 'Gurubashi Berserker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=11352;

-- 'Gurubashi Warrior', mechanic_immune_mask was 1
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=11355;

-- 'Gurubashi Champion', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=11356;

-- 'Jin'do the Hexxer', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=11380;

-- 'Bloodlord Mandokir', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299807 WHERE `entry`=11382;

-- 'Illusion of Jandice Barov', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=11439;

-- 'Mushgog', mechanic_immune_mask was 8395857
UPDATE `creature_template` SET `mechanic_immune_mask`=8412241 WHERE `entry`=11447;

-- 'Petrified Treant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11458;

-- 'Warpwood Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11461;

-- 'Warpwood Treant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11462;

-- 'Warpwood Tangler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11464;

-- 'Warpwood Stomper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11465;

-- 'Highborne Summoner', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=11466;

-- 'Tsu'zee', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=612449875 WHERE `entry`=11467;

-- 'Eldreth Apparition', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11471;

-- 'Skeletal Highborne', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11476;

-- 'Arcane Aberration', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11480;

-- 'Mana Remnant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11483;

-- 'Residual Monstrosity', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11484;

-- 'Prince Tortheldrin', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11486;

-- 'Magister Kalendris', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11487;

-- 'Illyanna Ravenoak', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11488;

-- 'Tendris Warpwood', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613121883 WHERE `entry`=11489;

-- 'Zevrim Thornhoof', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11490;

-- 'Old Ironbark', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11491;

-- 'Alzzin the Wildshaper', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11492;

-- 'Immol'thar', mechanic_immune_mask was 8389713
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11496;

-- 'King Gordok', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=11501;

-- 'Ragnaros', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646152031 WHERE `entry`=11502;

-- 'Oggleflint', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=11517;

-- 'Jergosh the Invoker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=11518;

-- 'Bazzalan', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=11519;

-- 'Taragaman the Hungerer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=11520;

-- 'Skeletal Scholomance Student', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11547;

-- 'Magrami Spectre', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11560;

-- 'Undead Ravager', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=11561;

-- 'Whirlwind Ripper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11576;

-- 'Whirlwind Stormwalker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11577;

-- 'Whirlwind Shredder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11578;

-- 'Nefarian', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=11583;

-- 'Risen Guardian', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11598;

-- 'Spectral Marauder', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11620;

-- 'Spectral Corpse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11621;

-- 'Rattlegore', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=11622;

-- 'Morloch', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=11657;

-- 'Molten Giant', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=11658;

-- 'Molten Destroyer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=11659;

-- 'Flamewaker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=11661;

-- 'Flamewaker Priest', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105503 WHERE `entry`=11662;

-- 'Flamewaker Healer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=612515679 WHERE `entry`=11663;

-- 'Flamewaker Elite', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646657887 WHERE `entry`=11664;

-- 'Lava Annihilator', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646020959 WHERE `entry`=11665;

-- 'Firewalker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019969371 WHERE `entry`=11666;

-- 'Flameguard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646152031 WHERE `entry`=11667;

-- 'Firelord', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646152031 WHERE `entry`=11668;

-- 'Flame Imp', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646151967 WHERE `entry`=11669;

-- 'Core Hound', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=11671;

-- 'Core Rager', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646004575 WHERE `entry`=11672;

-- 'Ancient Core Hound', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=11673;

-- 'Taskmaster Snivvle', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=11677;

-- 'Warsong Shredder', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11684;

-- 'Ghostly Raider', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11686;

-- 'Ghostly Marauder', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11687;

-- 'Dust Stormer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11744;

-- 'Cyclone Warrior', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11745;

-- 'Desert Rumbler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11746;

-- 'Desert Rager', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11747;

-- 'Shadowshard Rumbler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11777;

-- 'Shadowshard Smasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11778;

-- 'Ambershard Crusher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11781;

-- 'Ambershard Destroyer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11782;

-- 'Theradrim Shardling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11783;

-- 'Theradrim Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11784;

-- 'Tsunaman', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=11862;

-- 'Spectral Attendant', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=11873;

-- 'Mortar Team Target Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=11875;

-- 'Nathanos Blightcaller', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=11878;

-- 'Shardi', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=11899;

-- 'Brakkar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=11900;

-- 'Andruk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=11901;

-- 'Flamegor', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105503 WHERE `entry`=11981;

-- 'Firemaw', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105503 WHERE `entry`=11983;

-- 'Golemagg the Incinerator', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=11988;

-- 'Majordomo Executus', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=12018;

-- 'Baron Geddon', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646151967 WHERE `entry`=12056;

-- 'Garr', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646152031 WHERE `entry`=12057;

-- 'Lava Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646020959 WHERE `entry`=12076;

-- 'Stormpike Quartermaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=12096;

-- 'Frostwolf Quartermaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=12097;

-- 'Sulfuron Harbinger', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=12098;

-- 'Firesworn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646020959 WHERE `entry`=12099;

-- 'Lava Reaver', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646020959 WHERE `entry`=12100;

-- 'Lava Surger', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646020959 WHERE `entry`=12101;

-- 'Lucifron', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=12118;

-- 'Flamewaker Protector', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=12119;

-- 'Onyxian Warder', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=12129;

-- 'Son of Flame', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16400 WHERE `entry`=12143;

-- 'Korrak the Bloodrager', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=12159;

-- 'Tortured Druid', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=12178;

-- 'Tortured Sentinel', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=12179;

-- 'Shade of Ambermoon', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=12199;

-- 'Princess Theradras', mechanic_immune_mask was 10258
UPDATE `creature_template` SET `mechanic_immune_mask`=646676319 WHERE `entry`=12201;

-- 'Landslide', mechanic_immune_mask was 8210
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=12203;

-- 'Conquered Soul of the Blightcaller', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=12208;

-- 'Barbed Lasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=12219;

-- 'Constrictor Vine', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=12220;

-- 'Cavern Lurker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=12223;

-- 'Cavern Shambler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=12224;

-- 'Celebras the Cursed', mechanic_immune_mask was 10258
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=12225;

-- 'Lord Vyletongue', mechanic_immune_mask was 10258
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=12236;

-- 'Meshlok the Harvester', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=12237;

-- 'Razorlash', mechanic_immune_mask was 10258
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=12258;

-- 'Gehennas', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=12259;

-- 'Shazzrah', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=12264;

-- 'Lava Spawn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646152031 WHERE `entry`=12265;

-- 'Demetria', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=537083743 WHERE `entry`=12339;

-- 'Blue Skeletal Horse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=12341;

-- 'Brown Skeletal Horse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=12342;

-- 'Red Skeletal Horse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=12343;

-- 'Swift Green Skeletal Horse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=12344;

-- 'Blue Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12363;

-- 'Icy Blue Mechanostrider Mod A', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12364;

-- 'Red Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12365;

-- 'Green Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12367;

-- 'White Mechanostrider Mod A', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12368;

-- 'Wailing Spectre', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=12377;

-- 'Damned Soul', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=12378;

-- 'Mortar Team Advanced Target Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12385;

-- 'Lord Kazzak', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235 WHERE `entry`=12397;

-- 'Death Talon Dragonspawn', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613104973 WHERE `entry`=12422;

-- 'Razorgore the Untamed', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=48234335 WHERE `entry`=12435;

-- 'Blackwing Spellbinder', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646135643 WHERE `entry`=12457;

-- 'Blackwing Taskmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=7187 WHERE `entry`=12458;

-- 'Blackwing Warlock', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=12459;

-- 'Death Talon Wyrmguard', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105503 WHERE `entry`=12460;

-- 'Death Talon Overseer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=12461;

-- 'Death Talon Flamescale', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=12463;

-- 'Death Talon Seether', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=12464;

-- 'Death Talon Wyrmkin', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659419 WHERE `entry`=12465;

-- 'Death Talon Captain', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105503 WHERE `entry`=12467;

-- 'Death Talon Hatcher', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659931 WHERE `entry`=12468;

-- 'Arcanite Dragonling', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12473;

-- 'Bibilfaz Featherwhistle', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=12596;

-- 'Vhulgra', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=12616;

-- 'Khaelyn Steelwing', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=12617;

-- 'Mastok Wrilehiss', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=2 WHERE `entry`=12737;

-- 'Faustron', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=12740;

-- 'Tideress', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=12759;

-- 'Chimaerok', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=4096 WHERE `entry`=12800;

-- 'Arcane Chimaerok', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=4096 WHERE `entry`=12801;

-- 'Chimaerok Devourer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=4096 WHERE `entry`=12802;

-- 'Lord Lakmaeran', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=612382288 WHERE `entry`=12803;

-- 'Baron Aquanis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=12876;

-- 'Axtroz', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299547 WHERE `entry`=12899;

-- 'Somnus', mechanic_immune_mask was 2147483647
-- MECHANIC_ENRAGED from AC is enabled, adding
-- MECHANIC_INFECTED from AC is enabled, adding
-- MECHANIC_SLOW_ATTACK from AC is enabled, adding
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1693138683 WHERE `entry`=12900;

-- 'Lorgus Jett', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=12902;

-- 'Vaelastrasz the Corrupt', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299807 WHERE `entry`=13020;

-- 'Warpwood Crusher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=608925267 WHERE `entry`=13021;

-- 'Whip Lasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13022;

-- 'Umi Thorson', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13078;

-- 'Keetar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13079;

-- 'Aggi Rumblestomp', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13086;

-- 'Masha Swiftcut', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13088;

-- 'Alliance Spirit Guide', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=13116;

-- 'Horde Spirit Guide', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=13117;

-- 'Lieutenant Rugba', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13137;

-- 'Lieutenant Spencer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13138;

-- 'Commander Randolph', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13139;

-- 'Deeprot Stomper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13141;

-- 'Deeprot Tangler', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13142;

-- 'Lieutenant Stronghoof', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13143;

-- 'Lieutenant Vol'talar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13144;

-- 'Lieutenant Grummus', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13145;

-- 'Lieutenant Lewis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13147;

-- 'Commander Malgor', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13152;

-- 'Commander Mulfort', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13153;

-- 'Commander Louis Philips', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13154;

-- 'Smith Regzar', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13176;

-- 'Vahgruk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=13177;

-- 'Wing Commander Guse', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13179;

-- 'Wing Commander Jeztor', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13180;

-- 'Wing Commander Mulverick', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13181;

-- 'Phase Lasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13196;

-- 'Fel Lash', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13197;

-- 'Gaelden Hammersmith', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13216;

-- 'Grunnda Wolfheart', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13218;

-- 'Primalist Thurloga', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13236;

-- 'Lokholar the Ice Lord', mechanic_immune_mask was 617299803
UPDATE `creature_template` SET `mechanic_immune_mask`=617316187 WHERE `entry`=13256;

-- 'Murgot Deepforge', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13257;

-- 'Duke Hydraxis', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13278;

-- 'Discordant Surge', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13279;

-- 'Hydrospawn', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613121883 WHERE `entry`=13280;

-- 'Death Lash', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13285;

-- 'Lieutenant Largent', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13296;

-- 'Lieutenant Stouthandle', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13297;

-- 'Lieutenant Greywand', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13298;

-- 'Lieutenant Lonadin', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13299;

-- 'Lieutenant Mancuso', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13300;

-- 'Commander Mortimer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13318;

-- 'Commander Duffy', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13319;

-- 'Commander Karl Philips', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13320;

-- 'Hydraxian Honor Guard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13322;

-- 'Stormpike Mine Layer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13356;

-- 'Frostwolf Mine Layer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13357;

-- 'Frostwolf Shredder Unit', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=13378;

-- 'Stormpike Shredder Unit', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=13416;

-- 'Wing Commander Ichman', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13437;

-- 'Wing Commander Slidore', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13438;

-- 'Wing Commander Vipore', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13439;

-- 'Frostwolf Wolf Rider Commander', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13441;

-- 'Arch Druid Renferal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13442;

-- 'Corporal Noreg Stormpike', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13447;

-- 'Noxxion's Spawn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13456;

-- 'Stormpike Ram Rider Commander', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13577;

-- 'Rotgrip', mechanic_immune_mask was 10258
UPDATE `creature_template` SET `mechanic_immune_mask`=608908883 WHERE `entry`=13596;

-- 'Frostwolf Explosives Expert', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13597;

-- 'Stormpike Explosives Expert', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13598;

-- 'Frostwolf Stable Master', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13616;

-- 'Stormpike Stable Master', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13617;

-- 'Gizlock's Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=13619;

-- 'Noxxious Scion', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13696;

-- 'Noxxious Essence', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13736;

-- 'Corrupt Force of Nature', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=13743;

-- 'Mountaineer Boombellow', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13797;

-- 'Jotek', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1011483136 WHERE `entry`=13798;

-- 'Blackwing Technician', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8 WHERE `entry`=13996;

-- 'Chromaggus', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=14020;

-- 'Phase Lasher (Fire)', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14061;

-- 'Phase Lasher (Nature)', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14062;

-- 'Phase Lasher (Arcane)', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14063;

-- 'Demon Portal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=14081;

-- 'Enraged Felguard', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=604585803 WHERE `entry`=14101;

-- 'Phase Lasher (Frost)', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14184;

-- '7:XT', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14224;

-- 'Drogoth the Roamer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14231;

-- 'Ironbark the Redeemed', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14241;

-- 'Blue Drakonid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=65537 WHERE `entry`=14261;

-- 'Green Drakonid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=65537 WHERE `entry`=14262;

-- 'Bronze Drakonid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=65537 WHERE `entry`=14263;

-- 'Red Drakonid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=65537 WHERE `entry`=14264;

-- 'Black Drakonid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=65537 WHERE `entry`=14265;

-- 'Seeker Aqualon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14269;

-- 'Chromatic Drakonid', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=14302;

-- 'Petrified Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14303;

-- 'Ferra', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=14308;

-- 'Guard Fengus', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613103451 WHERE `entry`=14321;

-- 'Stomper Kreeg', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14322;

-- 'Guard Slip'kik', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613103451 WHERE `entry`=14323;

-- 'Cho'Rush the Observer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14324;

-- 'Captain Kromcrush', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14325;

-- 'Guard Mol'dar', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613103451 WHERE `entry`=14326;

-- 'Lethtendris', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14327;

-- 'Red Skeletal Warhorse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=14331;

-- 'Field Repair Bot 74A', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14337;

-- 'Pimgib', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=75700827 WHERE `entry`=14349;

-- 'Hydroling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14350;

-- 'Pusillin', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14354;

-- 'Thornling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14362;

-- 'Mana Burst', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14397;

-- 'Arcane Torrent', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14399;

-- 'Arcane Feedback', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14400;

-- 'Master Elemental Shaper Krixix', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016862 WHERE `entry`=14401;

-- 'Mirelow', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14424;

-- 'Prince Thunderaan', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617316187 WHERE `entry`=14435;

-- 'Molt Thorn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14448;

-- 'The Windreaver', mechanic_immune_mask was 134144
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646610783 WHERE `entry`=14454;

-- 'Whirling Invader', mechanic_immune_mask was 8
UPDATE `creature_template` SET `mechanic_immune_mask`=16392 WHERE `entry`=14455;

-- 'Princess Tempestria', mechanic_immune_mask was 134144
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646610783 WHERE `entry`=14457;

-- 'Watery Invader', mechanic_immune_mask was 8
UPDATE `creature_template` SET `mechanic_immune_mask`=16392 WHERE `entry`=14458;

-- 'Blazing Invader', mechanic_immune_mask was 8
UPDATE `creature_template` SET `mechanic_immune_mask`=25102 WHERE `entry`=14460;

-- 'Baron Charr', mechanic_immune_mask was 134144
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646610783 WHERE `entry`=14461;

-- 'Thundering Invader', mechanic_immune_mask was 8
UPDATE `creature_template` SET `mechanic_immune_mask`=16392 WHERE `entry`=14462;

-- 'Avalanchion', mechanic_immune_mask was 134144
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646610783 WHERE `entry`=14464;

-- 'Alliance Battle Standard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=14465;

-- 'Horde Battle Standard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=14466;

-- 'Huricanian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=14478;

-- 'Scourge Footsoldier', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=14486;

-- 'Scourge Archer', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=14489;

-- 'Xorothian Dreadsteed', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14502;

-- 'The Cleaner', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650346335 WHERE `entry`=14503;

-- 'Lord Hel'nurath', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=14506;

-- 'High Priest Venoxis', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14507;

-- 'High Priest Thekal', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14509;

-- 'High Priestess Mar'li', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14510;

-- 'Banal Spirit', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14514;

-- 'High Priestess Arlokk', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14515;

-- 'Death Knight Darkreaver', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=14516;

-- 'High Priestess Jeklik', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14517;

-- 'Swift Yellow Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14551;

-- 'Swift White Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14552;

-- 'Swift Green Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14553;

-- 'Swift Stripped Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14554;

-- 'Purple Skeletal Warhorse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=14558;

-- 'Swift Blue Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14562;

-- 'Swift Red Mechanostrider', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14563;

-- 'Terrordale Spirit', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=14564;

-- 'Ebonroc', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105503 WHERE `entry`=14601;

-- 'Sever', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8388688 WHERE `entry`=14682;

-- 'Balzaphon', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14684;

-- 'Lady Falther'ess', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=14686;

-- 'Gurubashi Bat Rider', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14750;

-- 'Frostwolf Battle Standard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=14751;

-- 'Stormpike Battle Standard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135647 WHERE `entry`=14752;

-- 'Dun Baldar North Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14762;

-- 'Dun Baldar South Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14763;

-- 'Icewing Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14764;

-- 'Stonehearth Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14765;

-- 'Iceblood Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14766;

-- 'Tower Point Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14767;

-- 'East Frostwolf Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14768;

-- 'West Frostwolf Marshal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14769;

-- 'Dun Baldar North Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14770;

-- 'Dun Baldar South Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14771;

-- 'East Frostwolf Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14772;

-- 'Iceblood Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14773;

-- 'Icewing Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14774;

-- 'Stonehearth Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14775;

-- 'Tower Point Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14776;

-- 'West Frostwolf Warmaster', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14777;

-- 'Hakkar', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14834;

-- 'Blood Steward of Kirtonos', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14861;

-- 'Emissary Roman'khan', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650870623 WHERE `entry`=14862;

-- 'Parasitic Serpent', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=14884;

-- 'Ysondre', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650198879 WHERE `entry`=14887;

-- 'Lethon', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650198879 WHERE `entry`=14888;

-- 'Emeriss', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650198879 WHERE `entry`=14889;

-- 'Taerar', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650198879 WHERE `entry`=14890;

-- 'High Priestess Jeklik Transform Visual', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=14941;

-- 'Guse's War Rider', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14943;

-- 'Jeztor's War Rider', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14944;

-- 'Mulverick's War Rider', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14945;

-- 'Slidore's Gryphon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14946;

-- 'Ichman's Gryphon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14947;

-- 'Vipore's Gryphon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=14948;

-- 'Powerful Healing Ward', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=113457951 WHERE `entry`=14987;

-- 'Ohgan', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=14988;

-- 'Gurubashi', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=15047;

-- 'Fishbot 5000', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=15079;

-- 'Gri'lek', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15082;

-- 'Hazza'rah', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15083;

-- 'Wushoolay', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15085;

-- 'Swift Zulian Tiger', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15104;

-- 'Forsaken Horse', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15108;

-- 'Gahz'ranka', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15114;

-- 'Portal of Madness', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646135135 WHERE `entry`=15141;

-- 'Mad Voidwalker', mechanic_immune_mask was 131073
UPDATE `creature_template` SET `mechanic_immune_mask`=131072 WHERE `entry`=15146;

-- 'Runk Windtamer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=15178;

-- 'Anachronos', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15192;

-- 'The Banshee Queen', mechanic_immune_mask was 617299803
UPDATE `creature_template` SET `mechanic_immune_mask`=617316187 WHERE `entry`=15193;

-- 'The Duke of Cynders', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15206;

-- 'The Duke of Fathoms', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15207;

-- 'The Duke of Shards', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15208;

-- 'The Duke of Zephyrs', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15220;

-- 'Dream Fog', mechanic_immune_mask was 617299803
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=15224;

-- 'Vekniss Soldier', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15229;

-- 'Vekniss Warrior', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15230;

-- 'Vekniss Guardian', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15233;

-- 'Vekniss Stinger', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15235;

-- 'Vekniss Wasp', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15236;

-- 'Vekniss Hive Crawler', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15240;

-- 'Qiraji Mindslayer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15246;

-- 'Qiraji Brainwasher', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659931 WHERE `entry`=15247;

-- 'Qiraji Lasher', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15249;

-- 'Qiraji Slayer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15250;

-- 'Qiraji Champion', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15252;

-- 'Spirit Shade', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=651116383 WHERE `entry`=15261;

-- 'Obsidian Eradicator', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15262;

-- 'The Prophet Skeram', mechanic_immune_mask was 617299803
UPDATE `creature_template` SET `mechanic_immune_mask`=617299807 WHERE `entry`=15263;

-- 'Anubisath Sentinel', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15264;

-- 'Emperor Vek'nilash', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299807 WHERE `entry`=15275;

-- 'Emperor Vek'lor', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299807 WHERE `entry`=15276;

-- 'Anubisath Defender', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15277;

-- 'Xil'xix', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646938463 WHERE `entry`=15286;

-- 'Aluntir', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646938463 WHERE `entry`=15288;

-- 'Arakis', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646938463 WHERE `entry`=15290;

-- 'Viscidus', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15299;

-- 'Anubisath Warder', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15311;

-- 'Obsidian Nullifier', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=15312;

-- 'Hive'Zara Drone', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15318;

-- 'Hive'Zara Collector', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15319;

-- 'Hive'Zara Soldier', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15320;

-- 'Hive'Zara Sandstalker', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15323;

-- 'Qiraji Gladiator', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15324;

-- 'Hive'Zara Wasp', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15325;

-- 'Hive'Zara Stinger', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15327;

-- 'Flesh Hunter', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15335;

-- 'Hive'Zara Tail Lasher', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019950875 WHERE `entry`=15336;

-- 'Obsidian Destroyer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019969371 WHERE `entry`=15338;

-- 'Ossirian the Unscarred', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15339;

-- 'Moam', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15340;

-- 'General Rajaxx', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15341;

-- 'Qiraji Swarmguard', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15343;

-- 'Kurinnaxx', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15348;

-- 'RC Blimp <PH>', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=15349;

-- 'Anubisath Guardian', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15355;

-- 'Malfurion Stormrage', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15362;

-- 'RC Mortar Tank <PH>', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=15364;

-- 'Tonk Mine', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=15368;

-- 'Ayamiss the Hunter', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15369;

-- 'Buru the Gorger', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15370;

-- 'Halloween Male Ghost', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=15376;

-- 'Merithra of the Dream', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15378;

-- 'Caelestrasz', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15379;

-- 'Arygos', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15380;

-- 'Anachronos the Ancient', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15381;

-- 'Fandral Staghelm', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15382;

-- 'Colonel Zerran', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15385;

-- 'Major Yeggeth', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15386;

-- 'Major Pakkon', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15388;

-- 'Captain Drenn', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15389;

-- 'Captain Xurrem', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15390;

-- 'Captain Qeez', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15391;

-- 'Captain Tuubid', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15392;

-- 'Anachronos Dragon Form', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15410;

-- 'Arygos Dragon Form', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15411;

-- 'Caelestrasz Dragon Form', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15412;

-- 'Merithra Dragon Form', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15413;

-- 'Merithra's Wake', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15427;

-- 'Sand Vortex', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15428;

-- 'Disgusting Oozeling', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15429;

-- 'Omen', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15467;

-- 'Spirit of Azuregos', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15481;

-- 'Eranikus', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15491;

-- 'Buru the Gorger Transform Visual', mechanic_immune_mask was 0
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=0 WHERE `entry`=15507;

-- 'Princess Huhuran', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15509;

-- 'Fankriss the Unyielding', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15510;

-- 'Lord Kri', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15511;

-- 'Buru Egg', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15514;

-- 'Battleguard Sartura', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617297759 WHERE `entry`=15516;

-- 'Ouro', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15517;

-- 'Mana Fiend', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15527;

-- 'Princess Yauj', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15543;

-- 'Vem', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15544;

-- 'Doctor Weavil', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299805 WHERE `entry`=15552;

-- 'Number Two', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=8466263 WHERE `entry`=15554;

-- 'Hive'Zara Larva', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=15555;

-- 'Maws', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15571;

-- 'Eye of C'Thun', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235 WHERE `entry`=15589;

-- 'Hive'Regal Hunter-Killer', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071628127 WHERE `entry`=15620;

-- 'Twilight Corrupter', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15625;

-- 'Eranikus the Redeemed', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15628;

-- 'Spawn of Fankriss', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=113981279 WHERE `entry`=15630;

-- 'Spotlight', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15631;

-- 'Tyrande', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15633;

-- 'Glob of Viscidus', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15667;

-- 'Father Winter's Helper', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15698;

-- 'Winter Reindeer', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15706;

-- 'C'Thun', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235 WHERE `entry`=15727;

-- 'Colossus of Zora', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15740;

-- 'Colossus of Regal', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15741;

-- 'Colossus of Ashi', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry`=15742;

-- 'Colossal Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15743;

-- 'Imperial Qiraji Destroyer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15744;

-- 'Qiraji Captain', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657887 WHERE `entry`=15747;

-- 'Lesser Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657877 WHERE `entry`=15748;

-- 'Qiraji Major', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15750;

-- 'Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657877 WHERE `entry`=15751;

-- 'Qiraji Brigadier General', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657887 WHERE `entry`=15753;

-- 'Greater Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657877 WHERE `entry`=15754;

-- 'Qiraji Lieutenant General', mechanic_immune_mask was 617299803
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657887 WHERE `entry`=15757;

-- 'Supreme Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657877 WHERE `entry`=15758;

-- 'Qiraji Lieutenant', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15806;

-- 'Minor Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657877 WHERE `entry`=15807;

-- 'Eroded Anubisath Warbringer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657877 WHERE `entry`=15810;

-- 'Qiraji Officer', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646657887 WHERE `entry`=15812;

-- 'Qiraji Officer Zod', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15813;

-- 'Qiraji Lieutenant Jo-rel', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15814;

-- 'Qiraji Captain Ka'ark', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15815;

-- 'Qiraji Major He'al-ie', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15816;

-- 'Qiraji Brigadier General Pax-lish', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15817;

-- 'Lieutenant General Nokhor', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=646659935 WHERE `entry`=15818;

-- 'Tentacle Portal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15904;

-- 'Giant Tentacle Portal', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15910;

-- 'Viscidus Trigger', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071644511 WHERE `entry`=15922;

-- 'Thaddius', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15928;

-- 'Stalagg', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15929;

-- 'Feugen', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15930;

-- 'Grobbulus', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15931;

-- 'Gluth', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15932;

-- 'Heigan the Unclean', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15936;

-- 'Maexxna', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15952;

-- 'Grand Widow Faerlina', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15953;

-- 'Noth the Plaguebringer', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15954;

-- 'Anub'Rekhan', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15956;

-- 'The Master's Eye', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=15963;

-- 'Buru Egg Trigger', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15964;

-- 'Naxxramas Template', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=15973;

-- 'Dread Creeper', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021294170 WHERE `entry`=15974;

-- 'Carrion Spinner', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021294170 WHERE `entry`=15975;

-- 'Venom Stalker', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021296219 WHERE `entry`=15976;

-- 'Crypt Reaver', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021296219 WHERE `entry`=15978;

-- 'Tomb Horror', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021296219 WHERE `entry`=15979;

-- 'Naxxramas Cultist', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021294171 WHERE `entry`=15980;

-- 'Naxxramas Acolyte', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021294171 WHERE `entry`=15981;

-- 'Sartura's Royal Guard', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=113981279 WHERE `entry`=15984;

-- 'Sapphiron', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15989;

-- 'Kel'Thuzad', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=15990;

-- 'Loatheb', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=16011;

-- 'Patchwork Golem', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019969362 WHERE `entry`=16017;

-- 'Bile Retcher', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019969362 WHERE `entry`=16018;

-- 'Mad Scientist', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015758352 WHERE `entry`=16020;

-- 'Living Monstrosity', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16021;

-- 'Surgical Assistant', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015751184 WHERE `entry`=16022;

-- 'Embalming Slime', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015758354 WHERE `entry`=16024;

-- 'Living Poison', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015751186 WHERE `entry`=16027;

-- 'Sludge Belcher', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019969362 WHERE `entry`=16029;

-- 'Plague Beast', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952659 WHERE `entry`=16034;

-- 'Frenzied Bat', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=16036;

-- 'Plagued Bat', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945491 WHERE `entry`=16037;

-- 'Lord Valthalak', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=16042;

-- 'Magma Lord Bokk', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=16043;

-- 'Diseased Maggot', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=16056;

-- 'Rotting Maggot', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=16057;

-- 'Theldren', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=8388624 WHERE `entry`=16059;

-- 'Gothik the Harvester', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=16060;

-- 'Instructor Razuvious', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=16061;

-- 'Highlord Mograine', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952987 WHERE `entry`=16062;

-- 'Sir Zeliek', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=16063;

-- 'Thane Korth'azz', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=16064;

-- 'Lady Blaumeux', mechanic_immune_mask was 617299839
-- MECHANIC_GRIP from AC is enabled, adding
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019953019 WHERE `entry`=16065;

-- 'Mor Grayhoof', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=16080;

-- 'Isalien', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=613105499 WHERE `entry`=16097;

-- 'Empyrean', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=512 WHERE `entry`=16098;

-- 'Jarien', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16101;

-- 'Sothos', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16102;

-- 'Love Fool', mechanic_immune_mask was 32
-- MECHANIC_GRIP from AC is enabled, adding
UPDATE `creature_template` SET `mechanic_immune_mask`=8405040 WHERE `entry`=16111;

-- 'Kormok', mechanic_immune_mask was 0
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16118;

-- 'Unrelenting Trainee', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1006764032 WHERE `entry`=16124;

-- 'Unrelenting Rider', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1020936031 WHERE `entry`=16126;

-- 'Spectral Trainee', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1006632960 WHERE `entry`=16127;

-- 'Bile Sludge', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021296219 WHERE `entry`=16142;

-- 'Shadow of Doom', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=16143;

-- 'Spectral Horse', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1006764050 WHERE `entry`=16149;

-- 'Spectral Rider', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1015693151 WHERE `entry`=16150;

-- 'Dark Touched Warrior', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1006830096 WHERE `entry`=16156;

-- 'Doom Touched Warrior', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1006830096 WHERE `entry`=16157;

-- 'Death Touched Warrior', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1006830096 WHERE `entry`=16158;

-- 'Shade of Naxxramas', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015751186 WHERE `entry`=16164;

-- 'Necro Knight', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16165;

-- 'Bony Construct', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015756368 WHERE `entry`=16167;

-- 'Stoneskin Gargoyle', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071628127 WHERE `entry`=16168;

-- 'Skeletal Smith', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=16193;

-- 'Unholy Axe', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16194;

-- 'Naxxramas Combat Dummy', mechanic_immune_mask was 16384
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=16211;

-- 'Unholy Staff', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16215;

-- 'Unholy Swords', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16216;

-- 'Tesla Coil', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=16218;

-- 'Eye Stalk', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=16236;

-- 'Plague Slime', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952659 WHERE `entry`=16243;

-- 'Infectious Ghoul', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015226896 WHERE `entry`=16244;

-- 'Fallout Slime', mechanic_immune_mask was 8388624
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1015758686 WHERE `entry`=16290;

-- 'Mutated Grub', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=16297;

-- 'Spectral Soldier', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=16298;

-- 'Skeletal Shocktrooper', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=16299;

-- 'Scourge Invasion Minion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=16336;

-- 'Scourge Invasion Minion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=16338;

-- 'Zombie Chow', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015226896 WHERE `entry`=16360;

-- 'Necropolis Acolyte', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16368;

-- 'Sewage Slime', mechanic_immune_mask was 8388624
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1015758418 WHERE `entry`=16375;

-- 'Spirit of the Damned', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=16379;

-- 'Bone Witch', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=16380;

-- 'Flameshocker', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=16383;

-- 'Atiesh', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1038073691 WHERE `entry`=16387;

-- 'Deathchill Servant', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015751184 WHERE `entry`=16390;

-- 'Skeletal Soldier', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=16422;

-- 'Spectral Apparition', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8413718 WHERE `entry`=16423;

-- 'Soldier of the Frozen Wastes', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015226896 WHERE `entry`=16427;

-- 'Unstoppable Abomination', mechanic_immune_mask was 8388624
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952722 WHERE `entry`=16428;

-- 'Soul Weaver', mechanic_immune_mask was 8388624
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952722 WHERE `entry`=16429;

-- 'Spectral Spirit', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8405008 WHERE `entry`=16437;

-- 'Skeletal Trooper', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=8602131 WHERE `entry`=16438;

-- 'Guardian of Icecrown', mechanic_immune_mask was 8388624
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019427410 WHERE `entry`=16441;

-- 'Plagued Gargoyle', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1071628127 WHERE `entry`=16446;

-- 'Plagued Ghoul', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019421200 WHERE `entry`=16447;

-- 'Plagued Deathhound', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16448;

-- 'Spirit of Naxxramas', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015751186 WHERE `entry`=16449;

-- 'Necro Knight Guardian', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1019952723 WHERE `entry`=16452;

-- 'Necro Stalker', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021296219 WHERE `entry`=16453;

-- 'Naxxramas Follower', mechanic_immune_mask was 65536
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021294170 WHERE `entry`=16505;

-- 'Naxxramas Worshipper', mechanic_immune_mask was 65537
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021294170 WHERE `entry`=16506;

-- 'Argent Mount', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=16384 WHERE `entry`=16511;

-- 'Crypt Guard', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
-- MECHANIC_PACIFY from vmangos is enabled, ignoring
-- MECHANIC_FUMBLE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1021296218 WHERE `entry`=16573;

-- 'Corpse Scarab', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=16698;

-- 'Spirit of Mograine', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16775;

-- 'Spirit of Blaumeux', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16776;

-- 'Spirit of Zeliek', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16777;

-- 'Spirit of Korth'azz', mechanic_immune_mask was 617299803
-- MECHANIC_BIT32 from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=617299803 WHERE `entry`=16778;

-- 'Plagued Guardian', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015751184 WHERE `entry`=16981;

-- 'Plagued Construct', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019421201 WHERE `entry`=16982;

-- 'Plagued Champion', mechanic_immune_mask was 8388624
UPDATE `creature_template` SET `mechanic_immune_mask`=1015226896 WHERE `entry`=16983;

-- 'Plagued Warrior', mechanic_immune_mask was 8388624
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019421201 WHERE `entry`=16984;

-- 'Cinder Elemental', mechanic_immune_mask was 0
UPDATE `creature_template` SET `mechanic_immune_mask`=646016863 WHERE `entry`=17003;

-- 'Maexxna Spiderling', mechanic_immune_mask was 0
-- MECHANIC_PERSUADE from vmangos is enabled, ignoring
UPDATE `creature_template` SET `mechanic_immune_mask`=1019945489 WHERE `entry`=17055;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
