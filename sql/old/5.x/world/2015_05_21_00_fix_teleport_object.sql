-- add missing  loot
DELETE FROM `gameobject_loot_template` WHERE entry='206203';
INSERT INTO `gameobject_loot_template` VALUES ('206203', '62317', '-99.69', '1', '0', '1', '1');
UPDATE gameobject_template SET data1=206203 WHERE entry=206203;
-- add missing loot
DELETE FROM `gameobject_loot_template` WHERE entry='209774';
INSERT INTO `gameobject_loot_template` VALUES ('209774', '2589', '5.14', '1', '0', '1', '2');
INSERT INTO `gameobject_loot_template` VALUES ('209774', '74615', '-3.33', '1', '0', '1', '1');
INSERT INTO `gameobject_loot_template` VALUES ('209774', '74634', '-90', '1', '0', '1', '1');
UPDATE gameobject_template SET data1=209774 WHERE entry=209774;
-- fix teleport  players when loot loot  objects 
UPDATE `gameobject_template` SET `data2`='0', `data3`='0', `data4`='0', `data5`='0', `data6`='0', `data7`='0', `data8`='0', `data9`='0', `data10`='0', `data11`='0', `data12`='0', `data13`='0' WHERE entry IN (19905 ,19904 ,19906 ,176209 ,178087 ,202467 ,187659 ,187660 ,187661 ,187683 ,188015 ,188016 ,188017 ,188018 ,188120 ,188164 ,188236 ,188237 ,188441 ,189992 ,190032 ,190189 ,188238 ,190500 ,190702 ,191209 ,191210 ,191530 ,191531 ,191532 ,191533 ,191534 ,191537 ,191576 ,186885 ,186886 ,187697 ,188367 ,188442 ,189288 ,189291 ,190510 ,191535 ,191536 ,192243 ,193406 ,190561 ,190558 ,190562 ,190563 ,190560 ,190614 ,190613 ,190612 ,193403 ,193404 ,193405 ,206410 ,206408 ,206411 ,195118 ,204352 ,205422 ,205153 ,201871 ,206573 ,196403 ,196472 ,196473 ,195201 ,201977 ,207256 ,207346 ,195074 ,195054 ,203374 ,204410 ,201579 ,207382 ,196834 ,206199 ,206292 ,206203 ,206389 ,206672 ,206673 ,196462 ,207383 ,207381 ,207384 ,195239 ,209327 ,209774);
