-- DB update 2021_04_11_13 -> 2021_04_11_14
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_11_13';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_11_13 2021_04_11_14 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617795276143794300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617795276143794300');

DELETE FROM `item_loot_template` WHERE (`Entry` = 16882);
INSERT INTO `item_loot_template` VALUES
(16882, 422, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Dwarven Mild'),
(16882, 929, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Healing Potion'),
(16882, 1206, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Moss Agate'),
(16882, 1529, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Jade'),
(16882, 1705, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Lesser Moonstone'),
(16882, 1710, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Greater Healing Potion'),
(16882, 2836, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Coarse Stone'),
(16882, 2883, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Plans: Deadly Bronze Poniard'),
(16882, 3013, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Scroll of Protection'),
(16882, 3357, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Liferoot'),
(16882, 3393, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Recipe: Minor Magic Resistance Potion'),
(16882, 3608, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Plans: Mighty Iron Hammer'),
(16882, 3864, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Citrine'),
(16882, 3874, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Plans: Polished Steel Boots'),
(16882, 4348, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Pattern: Phoenix Gloves'),
(16882, 4350, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Pattern: Spider Silk Slippers'),
(16882, 4410, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Schematic: Shadow Goggles'),
(16882, 4412, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Schematic: Moonsight Rifle'),
(16882, 4999, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Azora\'s Will'),
(16882, 5374, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Small Pocket Watch'),
(16882, 5498, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Small Lustrous Pearl'),
(16882, 5500, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Iridescent Pearl'),
(16882, 5503, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Clam Meat'),
(16882, 5504, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Tangy Clam Meat'),
(16882, 5568, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Smooth Pebble'),
(16882, 5578, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Plans: Silvered Bronze Breastplate'),
(16882, 6046, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Plans: Steel Weapon Chain'),
(16882, 6391, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Pattern: Stylish Green Shirt'),
(16882, 6409, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Insignia Belt'),
(16882, 6613, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Sage\'s Bracers'),
(16882, 7363, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Pattern: Pilferer\'s Gloves'),
(16882, 11098, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Formula: Enchant Cloak - Lesser Shadow Resistance'),
(16882, 11967, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Zircon Band'),
(16882, 11983, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Chrome Ring'),
(16882, 11984, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Cobalt Ring'),
(16882, 11994, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Coral Band'),
(16882, 12006, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Meadow Ring'),
(16882, 12007, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Prairie Ring'),
(16882, 12008, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Savannah Ring'),
(16882, 12052, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Ring of the Moon'),
(16882, 12053, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Volcanic Rock Ring'),
(16882, 12054, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Demon Band'),
(16882, 16746, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Warsong Report'),
(16882, 16882, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Battered Junkbox'),
(16882, 17124, 0, 2.5, 0, 1, 0, 1, 1, 'Battered Junkbox - Syndicate Emblem');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
