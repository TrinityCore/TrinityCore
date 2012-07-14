-- Update drop chance of Ensorcelled Parchment from 0.2% to 100%
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=100 WHERE `entry`=1570 AND `item`=3706;
-- Change spawntime from 2 secs to 3 minutes
UPDATE `gameobject` SET `spawntimesecs`=180 WHERE `id`=1765;
