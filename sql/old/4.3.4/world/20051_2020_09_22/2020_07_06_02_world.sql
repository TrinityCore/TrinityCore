-- Nalorakk
SET @ENTRY := 23576;
UPDATE `creature_template` SET `lootid`= `entry`, `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= @ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`= @ENTRY;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(@ENTRY, 0, 69557, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69554, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69555, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69556, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69558, 0, 1, 1, 1, 1);

-- Jan'alai
SET @ENTRY := 23578;
UPDATE `creature_template` SET `lootid`= `entry`, `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= @ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`= @ENTRY;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(@ENTRY, 0, 69560, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69563, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69559, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69562, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69561, 0, 1, 1, 1, 1);

-- Halazzi
SET @ENTRY := 23577;
UPDATE `creature_template` SET `lootid`= `entry`, `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= @ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`= @ENTRY;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(@ENTRY, 0, 69566, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69565, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69564, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69568, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69567, 0, 1, 1, 1, 1);

-- Hex Lord Malacrass
SET @ENTRY := 24239;
UPDATE `creature_template` SET `lootid`= `entry`, `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= @ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`= @ENTRY;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(@ENTRY, 0, 69570, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69572, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69571, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69569, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69573, 0, 1, 1, 1, 1),
(@ENTRY, 0, 70080, 0, 1, 1, 1, 1),
(@ENTRY, 0, 69762, 0.9, 0, 1, 1, 1);

-- Daakara
SET @ENTRY := 23863;
UPDATE `creature_template` SET `lootid`= `entry`, `mingold`= 17000, `maxgold`= 23000 WHERE `entry`= @ENTRY;
DELETE FROM `reference_loot_template` WHERE `Entry`= @ENTRY * 10;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(@ENTRY * 10, 69581, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69577, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69576, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69582, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69574, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69575, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69579, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69580, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69578, 0, 1, 1, 1, 1),
(@ENTRY * 10, 69583, 0, 1, 1, 1, 1);

DELETE FROM `creature_loot_template` WHERE `Entry`= @ENTRY;
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`, `LootMode`) VALUES
(@ENTRY, @ENTRY * 10, @ENTRY * 10, 100, 1, 2, 2, 1),
(@ENTRY, 0, 52078, 0, 2, 1, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 1 AND `SourceGroup` IN (23576, 23578, 23577, 23863, 24239) AND `SourceEntry`= 33307;

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (23576, 23578, 23577, 24239, 23863);
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`, `CurrencyId1`, `CurrencyCount1`) VALUES
(23576, 1162, 7, 250, 395, 7000),
(23578, 1162, 7, 250, 395, 7000),
(23577, 1162, 7, 250, 395, 7000),
(24239, 1162, 7, 250, 395, 7000),
(23863, 1162, 7, 250, 395, 7000);
