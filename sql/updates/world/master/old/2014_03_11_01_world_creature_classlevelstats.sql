-- SELECT * FROM  `creature_difficulty_stat` WHERE entry IN ( SELECT entry FROM  `creature_template` WHERE  `exp` =2 AND `minlevel` > 83)

UPDATE  `creature_classlevelstats` SET  `basehp2` =  '56277' WHERE `level` = 90 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '52056' WHERE `level` = 89 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '48152' WHERE `level` = 88 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '44540' WHERE `level` = 87 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '41200' WHERE `level` = 86 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '38110' WHERE `level` = 85 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '35251' WHERE `level` = 84 AND `class` in (1, 2, 4);
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '45021' WHERE `level` = 90 AND `class` = 8;
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '41644' WHERE `level` = 89 AND `class` = 8;
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '38521' WHERE `level` = 88 AND `class` = 8;
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '35632' WHERE `level` = 87 AND `class` = 8;
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '32959' WHERE `level` = 86 AND `class` = 8;
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '30487' WHERE `level` = 85 AND `class` = 8;
UPDATE  `creature_classlevelstats` SET  `basehp2` =  '28201' WHERE `level` = 84 AND `class` = 8;
