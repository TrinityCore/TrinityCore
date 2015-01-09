-- Add Bogblossom to this Bogblossom object for the druid quest (other one already contains it)
DELETE FROM `gameobject_loot_template` WHERE (`entry`=10961) AND (`item`=31950);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES (10961,31950,-100,0,0,1,1);
