-- DB update 2021_03_14_01 -> 2021_03_14_02
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_14_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_14_01 2021_03_14_02 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615495161722587900'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615495161722587900');

UPDATE `smart_scripts` SET `action_param1` = 12787 WHERE
(`entryorguid` IN (232, 757, 862, 880, 1039, 1142, 1224, 1520, 1654, 1655, 1656, 1658, 1662, 1693, 1843, 1871, 2236, 2321, 2322, 2323, 2535, 2536, 2582, 2681, 2749, 2773, 2944, 3284, 3285, 3476, 3812, 3814, 3988, 3999, 4202, 4388, 4389, 4390, 4634, 4656, 4687, 5260, 5287, 5477, 5622, 5683, 6020, 6068, 6093, 6140, 6348, 6352, 7067, 7101, 7287, 7307, 7669, 7671, 8961, 11724, 11725, 11789, 11858, 11918, 13159, 14275, 14276, 14426, 15591, 24552, 25027, 25028, 29392)) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `action_param1` = 12787 WHERE
(`entryorguid` IN (669, 1847, 2167, 4348, 4374, 5976, 5977, 6506, 8205, 8216, 11737, 11921)) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `action_param1` = 12787 WHERE
(`entryorguid` = 10946) AND (`source_type` = 0) AND (`id` = 4);

UPDATE `smart_scripts` SET `comment` = 'Skullsplitter Hunter - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 669) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Foulmane - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1847) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Blackwood Pathfinder - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2167) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Noxious Shredder - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4348) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Strashaz Hydra - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4374) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Dreadmaul Brute - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5976) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Dreadmaul Mauler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5977) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Ravasaur Runner - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6506) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Haarka the Ravenous - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 8205) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Retherokk the Berserker - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 8216) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Stonelash Flayer - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11737) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Besseleth - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11921) AND (`source_type` = 0) AND (`id` = 1);

UPDATE `smart_scripts` SET `comment` = 'Horgus the Ravager - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 10946) AND (`source_type` = 0) AND (`id` = 4);

UPDATE `smart_scripts` SET `comment` = 'Farmer Ray - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 232) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Lost One Fisherman - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 757) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Stonard Explorer - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 862) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Erlan Drudgemoor - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 880) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Fen Dweller - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1039) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Mosh\'Ogg Brute - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1142) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Young Threshadon - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1224) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Rattlecage Soldier - Between 20-80% Health - Cast \'Thrash\' (No Repeat)' WHERE
(`entryorguid` = 1520) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Gregor Agamand - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1654) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Nissa Agamand - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1655) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Thurman Agamand - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1656) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Captain Dargol - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1658) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Captain Perrine - Between 20-80% Health - Cast \'Thrash\' (No Repeat)' WHERE
(`entryorguid` = 1662) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Loch Crocolisk - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1693) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Foreman Jerris - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1843) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Eliza\'s Guard - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 1871) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Raging Reef Crawler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2236) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Foreststrider Fledgling - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2321) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Foreststrider - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2322) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Giant Foreststrider - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2323) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Maury "Club Foot" Wilkins - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2535) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Jon-Jon the Crow - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2536) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Dabyrie Laborer - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2582) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Vilebranch Raiding Wolf  - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2681) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Siege Golem - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2749) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Or\'Kalar - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2773) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Boss Tho\'grun - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 2944) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Venture Co. Drudger - Between 20-80% Health - Cast \'Thrash\' (No Repeat)' WHERE
(`entryorguid` = 3284) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Venture Co. Peon - Between 20-80% Health - Cast \'Thrash\' (No Repeat)' WHERE
(`entryorguid` = 3285) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Isha Awak - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 3476) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Clattering Crawler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 3812) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Spined Crawler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 3814) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Venture Co. Operator - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 3988) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Windshear Digger - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 3999) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Gerenzo Wrenchwhistle - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4202) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Young Murk Thresher - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4388) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Murk Thresher - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4389) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Elder Murk Thresher - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4390) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Kolkar Mauler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4634) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Maraudine Mauler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4656) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Deepstrider Searcher - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 4687) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Groddoc Ape - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5260) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Longtooth Howler - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5287) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Noboru the Cudgel - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5477) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Ongeku - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5622) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Comar Villard - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 5683) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Slimeshell Makrura - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6020) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Warug\'s Bodyguard - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6068) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Dead-Tooth Jack - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6093) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Hetaera - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6140) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Wavethrasher - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6348) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Coralshell Lurker - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 6352) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Venture Co. Drone - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 7067) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Warpwood Shredder - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 7101) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Foreman Silixiz - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 7287) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Venture Co. Lookout - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 7307) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Servant of Grol - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 7669) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Servant of Sevine - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 7671) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Felpaw Ravager - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 8961) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Hive\'Ashi Swarmer - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11724) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Hive\'Zora Waywatcher - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11725) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Deep Borer - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11789) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Grundig Darkcloud - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11858) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Gogger Stonepounder - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 11918) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'James Clark - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 13159) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Tamra Stormpike - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 14275) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Scargil - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 14276) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Harb Foulmountain - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 14426) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Minion of Weavil - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 15591) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Sliver - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 24552) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Frenzied Ghoul - Between 5-15% Health - Cast \'Thrash\' (No Repeat)' WHERE
(`entryorguid` = 25027) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Skeletal Ravager - Between 5-15% Health - Cast \'Thrash\' (No Repeat)' WHERE
(`entryorguid` = 25028) AND (`source_type` = 0) AND (`id` = 0);

UPDATE `smart_scripts` SET `comment` = 'Ravenous Jaws - In Combat - Cast \'Thrash\'' WHERE
(`entryorguid` = 29392) AND (`source_type` = 0) AND (`id` = 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
