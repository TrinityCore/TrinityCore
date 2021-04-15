-- Loot for Hellfire 5-man dungeons Trash (heroic and normal) --
-- -------------------------------------------------------------

-- Hellfire Citadel: Ramparts
SET @Lootid := 17259;
-- set all lootids to same entry (normal and heroic)
UPDATE `creature_template` SET `lootid`=@Lootid WHERE `entry` IN
(17259,17264,17269,17270,17271,17280,17281,17309,17455,17478,17517,18048,18049,18050,18051,18052,18053,18054,18055,18057,18058,18059);
-- populate trashloot table
DELETE FROM `creature_loot_template` WHERE `entry` IN
(17259,17264,17269,17270,17271,17280,17281,17309,17455,17478,17517,18048,18049,18050,18051,18052,18053,18054,18055,18057,18058,18059);
DELETE FROM `creature_loot_template` WHERE `entry`=@Lootid;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- rough indication based on wowhead data of ALL mobs in the dungeon
(@Lootid,14047,40,1,0,1,4), -- Runecloth
(@Lootid,21877,20,1,0,1,4), -- Netherweave Cloth
(@Lootid, 8952,10,1,0,1,4), -- Roasted Quail
(@Lootid, 8766, 5,1,0,1,3), -- Morning Glory Dew
-- references for worldgreys
(@Lootid,1,5,1,0,-24000,1), -- Outland Grey Item Reference1
(@Lootid,2,5,1,0,-24002,1), -- Outland Grey Item Reference2
(@Lootid,3,5,1,0,-24003,1), -- Outland Grey Item Reference3
(@Lootid,4,5,1,0,-24011,1), -- Outland Grey Item Reference4
(@Lootid,5,5,1,0,-24022,1), -- Outland Grey Item Reference5
(@Lootid,6,5,1,0,-24023,1), -- Outland Grey Item Reference6
-- specifics
(@Lootid,5759,0.25,1,0,1,1), -- Thorium Lockbox
(@Lootid,5760,0.30,1,0,1,1), -- Eternium Lockbox
-- Scrolls
(@Lootid,7,5,1,0,-24724,1); -- Scroll of <stat> IV

-- -----------------------------------------
-- -- Hellfire Citadel: The Blood Furnace --
-- -----------------------------------------
SET @Lootid := 17370;
UPDATE `creature_template` SET `lootid`=@Lootid WHERE `entry` IN (17256,17370,17371,17395,17397,17398,17399,17414,17429,17477,17491,17624,17626,17653,18894,19016,18608,18619,18617,18615,18612,18614,18618,18603,18606,18610,18611,18609,18620,21645,21646);

DELETE FROM `creature_loot_template` WHERE `entry` IN (17370,17371,17395,17397,17398,17414,17429,17491,17624,17626,18894);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Lootid,23894,-100,1,0,1,1), -- Fel Orc Blood (quest)
-- most common items
(@Lootid,14047,40,1,0,1,4), -- Runecloth
(@Lootid,21877,20,1,0,1,4), -- Netherweave Cloth
(@Lootid, 8952,10,1,0,1,4), -- Roasted Quail
(@Lootid, 8766, 5,1,0,1,3), -- Morning Glory Dew
-- references for worldgreys
(@Lootid,1,5,1,0,-24000,1), -- Outland Grey Item Reference1
(@Lootid,2,5,1,0,-24002,1), -- Outland Grey Item Reference2
(@Lootid,3,5,1,0,-24003,1), -- Outland Grey Item Reference3
(@Lootid,4,5,1,0,-24011,1), -- Outland Grey Item Reference4
(@Lootid,5,5,1,0,-24022,1), -- Outland Grey Item Reference5
(@Lootid,6,5,1,0,-24023,1), -- Outland Grey Item Reference6
-- specifics
(@Lootid,5759,0.25,1,0,1,1), -- Thorium Lockbox
(@Lootid,5760,0.30,1,0,1,1), -- Eternium Lockbox
-- Scrolls
(@Lootid,7,5,1,0,-24724,1); -- Scroll of <stat> IV

-- -------------------------------------------
-- -- Hellfire Citadel: The Shattered Halls --
-- -------------------------------------------
SET @Lootid := 16507;
UPDATE `creature_template` SET `lootid`=@Lootid WHERE `entry` IN (17669,16507,17622,17462,17427,17420,17083,16699,16704,17695,17670,16700,16593,16594,17464,17694,17465,17461,17671,20593,20582,20576,20590,20589,20594,20567,20587,20579,20581,20595,20586,20583,20578,20574,20588,20584,20577,20580);

DELETE FROM `creature_loot_template` WHERE `entry` IN (16507,16593,16594,16699,16700,16704,17083,17420,17427,17461,17462,17464,17465,17669,17670,17671,17694,17695,17669,16594,17694,17427,17695,17461,16593,17465,17671,17464,17420,17670,16700,16699,16507,16704,17462);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Lootid,21877,40,1,0,2,3), -- Netherweave Cloth
(@Lootid,27854,20,1,0,1,1), -- Smoked Talbuk Venison
(@Lootid,27860,20,1,0,1,1), -- Purified Draenic Water
(@Lootid,31952,2.5,1,0,1,1), -- Khorium Lockbox
-- references
(@Lootid,1,5,1,1,-24002,1), -- Outland Grey Item Reference1
(@Lootid,2,2,1,1,-24009,1), -- Outland Green Reference1
(@Lootid,3,5,1,1,-24011,1), -- Outland Grey Item Reference2
(@Lootid,4,1,1,1,-24012,1), -- Outland Blue Reference1
(@Lootid,5,5,1,1,-24093,1), -- Outland Plans & patterns
-- Scrolls
(@Lootid,6,5,1,0,-24724,1); -- Scroll of <stat> IV
