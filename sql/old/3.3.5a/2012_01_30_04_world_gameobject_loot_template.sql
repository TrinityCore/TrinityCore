SET @ITEM :=50274;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (28074,28088,28082,28096) AND `item`=@ITEM;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(28074,@ITEM,-38,1,0,1,1), -- Deathbringer Cache 25 Normal
(28088,@ITEM,-68,1,0,1,1), -- Deathbringer Cache 25 Heroic
(28082,@ITEM,-38,1,0,1,1), -- Cache of the Dreamwalker 25 Normal
(28096,@ITEM,-68,1,0,1,1); -- Cache of the Dreamwalker 25 Heroic
-- only drop if someone is on the quest (negative ChanceOrQuestChance) 
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`= -(ABS(`ChanceOrQuestChance`)) WHERE `item`=50274;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`= -(ABS(`ChanceOrQuestChance`)) WHERE `item`=50274;

-- Dreamwalker and Council should drop 3 items
UPDATE `gameobject_loot_template` SET `maxcount`=3 WHERE `entry`IN (28052,28082,28064,28096) AND `item`=1;
UPDATE `creature_loot_template` SET `maxcount`=3 WHERE `entry` IN (37970,38401,38784,38785) AND `item`=1;
