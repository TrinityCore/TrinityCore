-- Naga Claws have Guaranteed drop rates
-- http://eu.battle.net/wow/en/item/24280
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry` IN (18340,18044,18046,18086,18087,18088,18089,19946,19947,20088,20089) and `item`=24280;
DELETE FROM `creature_loot_template` WHERE `entry`=18154 and `item`=24280;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(18154,24280,-100,1,0,1,1); -- Ssslith
