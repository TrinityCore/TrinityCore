UPDATE `fishing_loot_template` SET `Chance`='100', `QuestRequired`='1' WHERE  `Item` IN (6717,6718);
UPDATE `fishing_loot_template` SET `Chance`='50', `QuestRequired`='1' WHERE  `Item` IN (1467,45904,114625,114876);
UPDATE `fishing_loot_template` SET `Chance`='30', `QuestRequired`='1' WHERE  `Item`=34868;
UPDATE `fishing_loot_template` SET `Chance`='20', `QuestRequired`='1' WHERE  `Item` IN (16967,16968,16969,16970,34865,34867,45902,45903,73269);
UPDATE `fishing_loot_template` SET `Chance`='10', `QuestRequired`='1' WHERE  `Item`=45328;
UPDATE `fishing_loot_template` SET `Chance`='5', `QuestRequired`='1' WHERE  `Item`=34864;
UPDATE `fishing_loot_template` SET `MinCount`='1' WHERE  `Item` IN (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,43722,43723);
DELETE FROM `fishing_loot_template` WHERE  `Item` IN (43650,118564,118566);
