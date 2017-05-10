-- Pickpocketing_loot_template
UPDATE creature_template SET pickpocketloot=entry WHERE entry=28200;
DELETE FROM `pickpocketing_loot_template` WHERE entry=28200;
INSERT INTO `pickpocketing_loot_template` (`entry`,`item`,`ChanceorQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Dark Necromance
(28200,37467,100,1,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(28200,43575,100,1,0,1,1),-- Reinforced Junkbox
(28200,35952,30,1,0,1,1),-- Briny Hardcheese
(28200,33447,22,1,0,1,1),-- Runic Healing Potion
(28200,35948,10,1,0,1,1),-- Savory Snowplum
(28200,35950,10,1,0,1,1);-- Sweet Potato Bread
