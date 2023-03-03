-- DB update 2021_02_17_01 -> 2021_02_18_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_17_01';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_17_01 2021_02_18_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1613064807626370000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1613064807626370000');

ALTER TABLE `spell_dbc`
    CHANGE `Description_Lang_enUS` `Description_Lang_enUS` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_enGB` `Description_Lang_enGB` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_koKR` `Description_Lang_koKR` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_frFR` `Description_Lang_frFR` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_deDE` `Description_Lang_deDE` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_enCN` `Description_Lang_enCN` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_zhCN` `Description_Lang_zhCN` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_enTW` `Description_Lang_enTW` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_zhTW` `Description_Lang_zhTW` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_esES` `Description_Lang_esES` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_esMX` `Description_Lang_esMX` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_ruRU` `Description_Lang_ruRU` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_ptPT` `Description_Lang_ptPT` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_ptBR` `Description_Lang_ptBR` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_itIT` `Description_Lang_itIT` VARCHAR(200) DEFAULT NULL,
    CHANGE `Description_Lang_Unk` `Description_Lang_Unk` VARCHAR(200) DEFAULT NULL;

DELETE FROM `spell_dbc` WHERE `ID` IN (1454, 1455, 1456, 11687, 11688, 11689, 27222, 57946);
INSERT INTO `spell_dbc` VALUES
(1454, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(1455, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 65, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(1456, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 131, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(11687, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 214, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(11688, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 305, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(11689, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 826, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(27222, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 1123, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0),
(57946, 0, 0, 0, 65536, 1024, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 0, 0, 101, 0, 16, 6, 6, 0, -2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 1999, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1225, 0, 208, 0, 0, 'Life Tap', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Rank 1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.\r\n', 'Converts ${$m1} health into ${$m1*$<mult>+$SPS*.5*$<mult>} mana.  Spell power increases the amount of mana returned.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 133, 1500, 0, 5, 262144, 0, 0, 0, 1, 1, 0, 1065350000, 1065350000, 1065350000, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 175, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
