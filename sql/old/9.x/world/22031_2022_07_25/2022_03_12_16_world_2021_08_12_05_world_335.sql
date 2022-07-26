-- https://www.wowhead.com/item=22227/starbreeze-village-relic#comments
-- https://www.wowhead.com/item=22226/druidical-remains#comments
-- https://www.wowhead.com/item=22228/brilliant-sword-of-zealotry#comments
-- https://www.wowhead.com/item=22229/soul-ashes-of-the-banished#comments
UPDATE `creature_loot_template` SET `Chance` = 10 WHERE `Item` IN (22226,22227,22228,22229) AND `Reference` = 0;
-- https://www.wowhead.com/quest=8310/breaking-the-code#comments
UPDATE `creature_loot_template` SET `Chance` = 20 WHERE `Item` IN (20457,20458,20459) AND `Reference` = 0;
