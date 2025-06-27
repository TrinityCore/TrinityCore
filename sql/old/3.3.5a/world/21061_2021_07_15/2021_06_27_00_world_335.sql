-- For unknown reason wasn't shown in initially used archived page
UPDATE `creature_template` SET `skinloot` = 60001 WHERE `entry` = 15318;

-- Usually we have more than one page archived in 2010 from diffrent months, but only one random is used as source(it's faster to allow
-- web.archive to take you to random page). Last (before data wipe) archived pages has bigger total count(how many times creature was
-- skinned) (almost always it gives more accurate chance and more items(important in cases like this one where creature was skinned only
-- few hundred times. With such total count sometimes it's hard enough to make 100% correct decision)). ​But this case is different in a
-- weird way. For some reason one of items simply dissapeared in May but was shown in April. Since I used the one from May, that made me
-- create completely different template only for one creature for no real reason. This is something to take in consideration in future
-- and use only last pages in cases with small total count
UPDATE `creature_template` SET `skinloot` = 60004 WHERE `entry` IN (8301);
DELETE FROM `skinning_loot_template` WHERE `Entry` IN (60003);

-- Use more-frequently-used very-likely-more-correct values for 60007
UPDATE `skinning_loot_template` SET `Chance` = 10 WHERE `Entry` = 60007 AND `Item` = 15416;
UPDATE `skinning_loot_template` SET `Chance` = 7 WHERE `Entry` = 60007 AND `Item` = 8165;

-- Another bad chose of archived page, the one initially used had 2x smaller total count
-- Make it look like 60058 and 60059 which perfectly matches results with used today archived page
UPDATE `skinning_loot_template` SET `Chance` = 38 WHERE `Entry` = 60020 AND `Item` = 4304;
UPDATE `skinning_loot_template` SET `Chance` = 45 WHERE `Entry` = 60020 AND `Item` = 8170;
UPDATE `skinning_loot_template` SET `Chance` = 10 WHERE `Entry` = 60020 AND `Item` = 15422;

-- Use more-frequently-used very-likely-more-correct values for 60021
UPDATE `skinning_loot_template` SET `Chance` = 58 WHERE `Entry` = 60021 AND `Item` = 8170;
UPDATE `skinning_loot_template` SET `Chance` = 5 WHERE `Entry` = 60021 AND `Item` = 8171;
