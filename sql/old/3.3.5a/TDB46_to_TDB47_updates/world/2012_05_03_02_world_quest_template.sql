-- Wolvar Orphan quest order
UPDATE `quest_template` SET `prevquestid`=13927,`exclusivegroup`=-13930 WHERE `id` IN (13930,13934,13951);
UPDATE `quest_template` SET `prevquestid`=13930,`exclusivegroup`=-13955 WHERE `id` IN (13955,13957);
UPDATE `quest_template` SET `prevquestid`=13955,`exclusivegroup`=0 WHERE `id`=13938;
UPDATE `quest_template` SET `prevquestid`=13938,`exclusivegroup`=0 WHERE `id`=13960;
-- Oracle Orphan quest order
UPDATE `quest_template` SET `prevquestid`=13926,`exclusivegroup`=-13929 WHERE `id` IN (13929,13933,13950);
UPDATE `quest_template` SET `prevquestid`=13929,`exclusivegroup`=-13954 WHERE `id` IN (13954,13956);
UPDATE `quest_template` SET `prevquestid`=13954,`exclusivegroup`=0 WHERE `id`=13937;
UPDATE `quest_template` SET `prevquestid`=13937,`exclusivegroup`=0 WHERE `id`=13959;
-- Human Orphan quest order
UPDATE `quest_template` SET `prevquestid`=1468,`exclusivegroup`=-1479 WHERE `id` IN (1479,1558,1687);
UPDATE `quest_template` SET `prevquestid`=1479,`exclusivegroup`=-558 WHERE `id` IN (558,4822);
UPDATE `quest_template` SET `prevquestid`=558,`exclusivegroup`=0 WHERE `id`=171;
-- Orcish Orphan quest order
UPDATE `quest_template` SET `prevquestid`=172,`exclusivegroup`=-910 WHERE `id` IN (910,911,1800);
UPDATE `quest_template` SET `prevquestid`=910,`exclusivegroup`=-915 WHERE `id` IN (915,925);
UPDATE `quest_template` SET `prevquestid`=915,`exclusivegroup`=0 WHERE `id`=5502;
-- Draenei Orphan quest order
UPDATE `quest_template` SET `prevquestid`=10943,`exclusivegroup`=-10950 WHERE `id` IN (10950,10952,10954);
UPDATE `quest_template` SET `prevquestid`=10950,`exclusivegroup`=-10956 WHERE `id` IN (10956,10962);
UPDATE `quest_template` SET `NextQuestIdChain`=10968 WHERE `id`=10956;
UPDATE `quest_template` SET `prevquestid`=10968,`exclusivegroup`=0 WHERE `id`=10966;
-- Blood Elf Orphan quest order
UPDATE `quest_template` SET `prevquestid`=10942,`exclusivegroup`=-10945 WHERE `id` IN (10945,10951,10953);
UPDATE `quest_template` SET `prevquestid`=10945,`exclusivegroup`=-10960 WHERE `id` IN (10960,10963);
UPDATE `quest_template` SET `prevquestid`=10960,`exclusivegroup`=0 WHERE `id`=11975;
UPDATE `quest_template` SET `prevquestid`=11975,`exclusivegroup`=0 WHERE `id`=10967;
