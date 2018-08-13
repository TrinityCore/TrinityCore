SET @NPC_JAMES_CLARK                             := 13159;
SET @NPC_SHADOWY_FIGURE                          := 43515;
SET @NPC_FARMER_SALDEAN                          := 233;

-- Fix drops for http://www.wowhead.com/npc=13159/james-clark and link to drops
UPDATE `creature_template`
SET `lootid` = 13159
WHERE `entry` = @NPC_JAMES_CLARK;

DELETE FROM `creature_loot_template`
WHERE `Entry` = 13159;

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES('13159','1307','0','88.7498','1','1','0','1','1','');
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES('13159','57122','0','100.0','1','1','0','1','1','');

-- Fix http://www.wowhead.com/quest=26297/the-dawning-of-a-new-day 
-- spawn trigger for moonbrook speech is in the wrong place
UPDATE `creature`
SET `position_x` = -10954.5,
`position_y` = 1509,
`position_z` = 54
WHERE `id` = @NPC_SHADOWY_FIGURE;

-- fix farmer saldean, who is a carrion bird who cannot sell (been out in the wilds too long)
UPDATE `creature_template`
SET `family` = 0,
`type` = 7
WHERE `entry` = @NPC_FARMER_SALDEAN;

UPDATE `gossip_menu_option`
SET `OptionType` = 3,
`OptionNpcFlag` = 128
WHERE `MenuId` = 1781
AND `OptionIndex` = 0;
