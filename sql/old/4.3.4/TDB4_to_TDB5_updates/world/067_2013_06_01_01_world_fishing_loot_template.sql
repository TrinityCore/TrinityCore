DELETE FROM `skill_fishing_base_level` WHERE `entry`=4813;
INSERT INTO `skill_fishing_base_level`(`entry`,`skill`) VALUE
(4813,450);

DELETE FROM `fishing_loot_template` WHERE `entry`=4813;
INSERT INTO `fishing_loot_template`(`entry`,`item`,`ChanceOrQuestChance`,`groupid`) VALUES
(4813,41808,58,1),
(4813,43572,20.5,1),
(4813,36794,5.4,1),
(4813,4875,5,1),
(4813,3671,4.5,1),
(4813,25447,4.5,1),
(4813,44475,1.1,1),
(4813,37705,1,1);
