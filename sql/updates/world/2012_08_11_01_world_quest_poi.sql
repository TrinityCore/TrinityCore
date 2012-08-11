-- PK and new index for quest_poi
ALTER TABLE `quest_poi` DROP INDEX `questId`;
ALTER TABLE `quest_poi` DROP INDEX `id`;
ALTER TABLE `quest_poi` ADD PRIMARY KEY (`questId`, `id`);
ALTER TABLE `quest_poi` ADD INDEX `idx` (`questId`, `id`);

-- Correct data for quest_poi_points that violate the PK
UPDATE `quest_poi_points` SET `idx`=0 WHERE `questId`=25446 AND `id`=0 AND `x`=-1041 AND `y`=-5585;
UPDATE `quest_poi_points` SET `idx`=1 WHERE `questId`=25446 AND `id`=0 AND `x`=-1062 AND `y`=-5631;
UPDATE `quest_poi_points` SET `idx`=2 WHERE `questId`=25446 AND `id`=0 AND `x`=-1066 AND `y`=-5375;
UPDATE `quest_poi_points` SET `idx`=3 WHERE `questId`=25446 AND `id`=0 AND `x`=-1189 AND `y`=-5343;
UPDATE `quest_poi_points` SET `idx`=4 WHERE `questId`=25446 AND `id`=0 AND `x`=-1195 AND `y`=-5618;
UPDATE `quest_poi_points` SET `idx`=5 WHERE `questId`=25446 AND `id`=0 AND `x`=-1269 AND `y`=-5386;
UPDATE `quest_poi_points` SET `idx`=6 WHERE `questId`=25446 AND `id`=0 AND `x`=-1289 AND `y`=-5571;
UPDATE `quest_poi_points` SET `idx`=7 WHERE `questId`=25446 AND `id`=0 AND `x`=-1320 AND `y`=-5477;
UPDATE `quest_poi_points` SET `idx`=8 WHERE `questId`=25446 AND `id`=0 AND `x`=-1322 AND `y`=-5527;
UPDATE `quest_poi_points` SET `idx`=0 WHERE `questId`=25446 AND `id`=1 AND `x`=-1502 AND `y`=-5263;
UPDATE `quest_poi_points` SET `idx`=1 WHERE `questId`=25446 AND `id`=1 AND `x`=-1532 AND `y`=-5341;
UPDATE `quest_poi_points` SET `idx`=2 WHERE `questId`=25446 AND `id`=1 AND `x`=-1589 AND `y`=-5340;
UPDATE `quest_poi_points` SET `idx`=3 WHERE `questId`=25446 AND `id`=1 AND `x`=-1611 AND `y`=-5276;
UPDATE `quest_poi_points` SET `idx`=4 WHERE `questId`=25446 AND `id`=2 AND `x`=-1020 AND `y`=-5153;
UPDATE `quest_poi_points` SET `idx`=5 WHERE `questId`=25446 AND `id`=2 AND `x`=-1089 AND `y`=-5174;
UPDATE `quest_poi_points` SET `idx`=6 WHERE `questId`=25446 AND `id`=2 AND `x`=-1128 AND `y`=-5131;
UPDATE `quest_poi_points` SET `idx`=7 WHERE `questId`=25446 AND `id`=2 AND `x`=-0955 AND `y`=-5186;
UPDATE `quest_poi_points` SET `idx`=0 WHERE `questId`=25446 AND `id`=3 AND `x`=-0654 AND `y`=-5627;
UPDATE `quest_poi_points` SET `idx`=1 WHERE `questId`=25446 AND `id`=3 AND `x`=-0688 AND `y`=-5518;
UPDATE `quest_poi_points` SET `idx`=2 WHERE `questId`=25446 AND `id`=3 AND `x`=-0730 AND `y`=-5656;
UPDATE `quest_poi_points` SET `idx`=3 WHERE `questId`=25446 AND `id`=3 AND `x`=-0732 AND `y`=-5499;
UPDATE `quest_poi_points` SET `idx`=4 WHERE `questId`=25446 AND `id`=3 AND `x`=-0795 AND `y`=-5544;
UPDATE `quest_poi_points` SET `idx`=5 WHERE `questId`=25446 AND `id`=3 AND `x`=-0806 AND `y`=-5674;
UPDATE `quest_poi_points` SET `idx`=6 WHERE `questId`=25446 AND `id`=3 AND `x`=-0835 AND `y`=-5606;
UPDATE `quest_poi_points` SET `idx`=0 WHERE `questId`=25446 AND `id`=4 AND `x`=-0747 AND `y`=-5004;

UPDATE `quest_poi_points` SET `idx`=0  WHERE `questId`=25461 AND `x`=246 AND `y`=-4715;
UPDATE `quest_poi_points` SET `idx`=1  WHERE `questId`=25461 AND `x`=247 AND `y`=-4675;
UPDATE `quest_poi_points` SET `idx`=2  WHERE `questId`=25461 AND `x`=248 AND `y`=-4673;
UPDATE `quest_poi_points` SET `idx`=3  WHERE `questId`=25461 AND `x`=266 AND `y`=-4830;
UPDATE `quest_poi_points` SET `idx`=4  WHERE `questId`=25461 AND `x`=284 AND `y`=-4628;
UPDATE `quest_poi_points` SET `idx`=5  WHERE `questId`=25461 AND `x`=302 AND `y`=-4612;
UPDATE `quest_poi_points` SET `idx`=6  WHERE `questId`=25461 AND `x`=343 AND `y`=-4831;
UPDATE `quest_poi_points` SET `idx`=7  WHERE `questId`=25461 AND `x`=345 AND `y`=-4831;
UPDATE `quest_poi_points` SET `idx`=8  WHERE `questId`=25461 AND `x`=376 AND `y`=-4778;
UPDATE `quest_poi_points` SET `idx`=9  WHERE `questId`=25461 AND `x`=380 AND `y`=-4661;
UPDATE `quest_poi_points` SET `idx`=10 WHERE `questId`=25461 AND `x`=411 AND `y`=-4704;

UPDATE `quest_poi_points` SET `idx`=0  WHERE `questId`=25444 AND `x`=-1014 AND `y`=-4911;
UPDATE `quest_poi_points` SET `idx`=1  WHERE `questId`=25444 AND `x`=-0644 AND `y`=-4999;
UPDATE `quest_poi_points` SET `idx`=2  WHERE `questId`=25444 AND `x`=-0673 AND `y`=-4932;
UPDATE `quest_poi_points` SET `idx`=3  WHERE `questId`=25444 AND `x`=-0673 AND `y`=-5062;
UPDATE `quest_poi_points` SET `idx`=4  WHERE `questId`=25444 AND `x`=-0736 AND `y`=-5100;
UPDATE `quest_poi_points` SET `idx`=5  WHERE `questId`=25444 AND `x`=-0740 AND `y`=-4873;
UPDATE `quest_poi_points` SET `idx`=6  WHERE `questId`=25444 AND `x`=-0808 AND `y`=-4831;
UPDATE `quest_poi_points` SET `idx`=7  WHERE `questId`=25444 AND `x`=-0808 AND `y`=-5100;
UPDATE `quest_poi_points` SET `idx`=8  WHERE `questId`=25444 AND `x`=-0887 AND `y`=-5062;
UPDATE `quest_poi_points` SET `idx`=9  WHERE `questId`=25444 AND `x`=-0892 AND `y`=-4776;
UPDATE `quest_poi_points` SET `idx`=10 WHERE `questId`=25444 AND `x`=-0959 AND `y`=-4995;
UPDATE `quest_poi_points` SET `idx`=11 WHERE `questId`=25444 AND `x`=-0984 AND `y`=-4785;

-- PK for quest_poi_points
ALTER TABLE `quest_poi_points` ADD PRIMARY KEY (`questId`, `id`, `idx`);
