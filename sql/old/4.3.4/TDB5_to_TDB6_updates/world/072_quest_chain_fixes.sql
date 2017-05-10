-- The Rise of the Darkspear
UPDATE `quest_template` SET `RequiredClasses`=1    WHERE `Id`=24607; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=4    WHERE `Id`=24776; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=8    WHERE `Id`=24770; -- Rogue
UPDATE `quest_template` SET `RequiredClasses`=16   WHERE `Id`=24782; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=64   WHERE `Id`=24758; -- Shaman
UPDATE `quest_template` SET `RequiredClasses`=128  WHERE `Id`=24750; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256  WHERE `Id`=26272; -- Warlock
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id`=24764; -- Druid

-- The Basics: Hitting Things
UPDATE `quest_template` SET `PrevQuestId`=24607 WHERE `Id`=24639; -- Warrior
UPDATE `quest_template` SET `PrevQuestId`=24776 WHERE `Id`=24777; -- Hunter
UPDATE `quest_template` SET `PrevQuestId`=24770 WHERE `Id`=24771; -- Rogue
UPDATE `quest_template` SET `PrevQuestId`=24782 WHERE `Id`=24783; -- Priest
UPDATE `quest_template` SET `PrevQuestId`=24758 WHERE `Id`=24759; -- Shaman
UPDATE `quest_template` SET `PrevQuestId`=24750 WHERE `Id`=24751; -- Mage
UPDATE `quest_template` SET `PrevQuestId`=26272 WHERE `Id`=26273; -- Warlock
UPDATE `quest_template` SET `PrevQuestId`=24764 WHERE `Id`=24765; -- Druid

-- A Rough Start
UPDATE `quest_template` SET `PrevQuestId`=24639 WHERE `Id`=24641; -- Warrior
UPDATE `quest_template` SET `PrevQuestId`=24777 WHERE `Id`=24779; -- Hunter
UPDATE `quest_template` SET `PrevQuestId`=24771 WHERE `Id`=24773; -- Rogue
UPDATE `quest_template` SET `PrevQuestId`=24783 WHERE `Id`=24785; -- Priest
UPDATE `quest_template` SET `PrevQuestId`=24759 WHERE `Id`=24761; -- Shaman
UPDATE `quest_template` SET `PrevQuestId`=24751 WHERE `Id`=24753; -- Mage
UPDATE `quest_template` SET `PrevQuestId`=26273 WHERE `Id`=26275; -- Warlock
UPDATE `quest_template` SET `PrevQuestId`=24765 WHERE `Id`=24767; -- Druid

-- Insert "Wildmane Cat Pelt" into Wildmane Cat loot template
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/50222
DELETE FROM `creature_loot_template` WHERE `entry`=38046 AND `item`=50222;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupId`,`mincountOrRef`,`maxcount`) VALUES
(38046,50222,-100,1,0,1,1); -- Wildmane Cat Pelt
UPDATE `creature_template` SET `lootid`=38046 WHERE `entry`=38046; -- Wildmane Cat

-- Proving Pit
UPDATE `quest_template` SET `PrevQuestId`=24641 WHERE `Id`=24642; -- Warrior
UPDATE `quest_template` SET `PrevQuestId`=24779 WHERE `Id`=24780; -- Hunter
UPDATE `quest_template` SET `PrevQuestId`=24773 WHERE `Id`=24774; -- Rogue
UPDATE `quest_template` SET `PrevQuestId`=24785 WHERE `Id`=24786; -- Priest
UPDATE `quest_template` SET `PrevQuestId`=24761 WHERE `Id`=24762; -- Shaman
UPDATE `quest_template` SET `PrevQuestId`=24753 WHERE `Id`=24754; -- Mage
UPDATE `quest_template` SET `PrevQuestId`=26275 WHERE `Id`=26276; -- Warlock
UPDATE `quest_template` SET `PrevQuestId`=24767 WHERE `Id`=24768; -- Druid

-- The Arts of a Warrior
UPDATE `quest_template` SET `PrevQuestId`=24642 WHERE `Id`=24640; -- Warrior
-- The Arts of a Hunter
UPDATE `quest_template` SET `PrevQuestId`=24780 WHERE `Id`=24778; -- Hunter
-- The Arts of a Rogue
UPDATE `quest_template` SET `PrevQuestId`=24774 WHERE `Id`=24772; -- Rogue
-- Learnin= tha Word
UPDATE `quest_template` SET `PrevQuestId`=24786 WHERE `Id`=24784; -- Priest
-- The Arts of a Shaman
UPDATE `quest_template` SET `PrevQuestId`=24762 WHERE `Id`=24760; -- Shaman
-- The Arts of a Mage
UPDATE `quest_template` SET `PrevQuestId`=24754 WHERE `Id`=24752; -- Mage
-- The Arts of a Warlock
UPDATE `quest_template` SET `PrevQuestId`=26276 WHERE `Id`=26274; -- Warlock
-- The Arts of a Druid
UPDATE `quest_template` SET `PrevQuestId`=24768 WHERE `Id`=24766; -- Druid

-- More Than Expected
UPDATE `quest_template` SET `PrevQuestId`=24640 WHERE `Id`=24643; -- Warrior
UPDATE `quest_template` SET `PrevQuestId`=24778 WHERE `Id`=24781; -- Hunter
UPDATE `quest_template` SET `PrevQuestId`=24772 WHERE `Id`=24775; -- Rogue
UPDATE `quest_template` SET `PrevQuestId`=24784 WHERE `Id`=24787; -- Priest
UPDATE `quest_template` SET `PrevQuestId`=24760 WHERE `Id`=24763; -- Shaman
UPDATE `quest_template` SET `PrevQuestId`=24752 WHERE `Id`=24755; -- Mage
UPDATE `quest_template` SET `PrevQuestId`=26274 WHERE `Id`=26277; -- Warlock
UPDATE `quest_template` SET `PrevQuestId`=24766 WHERE `Id`=24769; -- Druid
