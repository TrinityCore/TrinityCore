-- Add missing green items to Doomwalker & Badge of Justice to Doomwalker & Doom Lord Kazzak
-- view-source:http://web.archive.org/web/20100413180103/www.wowhead.com/npc=17711
-- view-source:http://web.archive.org/web/20100415005607/www.wowhead.com/npc=18728
-- https://youtu.be/MMgdY4FB-aM?t=418
-- https://youtu.be/v4tXW9FG1kA?t=181
-- https://github.com/cmangos/tbc-db/commit/d10a189755188633a6c9c3a2fc45d8d2729dfee1#diff-b58a7adfa3834b2bdb9f236ea7e979c1R1-R13
UPDATE `creature_loot_template` SET `GroupId` = 0 WHERE `Entry` = 17711 AND `Item` = 34080 AND `Reference` = 34080;
UPDATE `creature_loot_template` SET `Item` = 26043 WHERE `Entry` = 18728 AND `Reference` = 26043;
UPDATE `creature_loot_template` SET `Item` = 4113 WHERE `Entry` = 18728 AND `Reference` = 4113;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (17711,18728) AND `Item` = 29434;
DELETE FROM `creature_loot_template` WHERE `Entry` = 17711 AND `Item` = 4113 AND `Reference` = 4113;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(17711,29434,0,100,0,1,0,2,2),
(18728,29434,0,100,0,1,0,2,2),
(17711,4113,4113,5,0,1,0,1,1);
