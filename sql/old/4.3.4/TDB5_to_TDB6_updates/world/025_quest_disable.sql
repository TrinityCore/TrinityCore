-- "Prove Your Worth" quest chain was removed in 4.0.3a
-- Following items, related to the quest, are no longer needed in loot templates
-- Remedy of Arugal (3155), Glutton Shackle (3156), Darksoul Shackle (3157), Pyrewood Shackle (3218) and Head of Grimson (3634)
-- http://www.wowpedia.org/Quest:Prove_Your_Worth (Note: 2nd, 3rd, 4th and 5th quests have same name)
DELETE FROM `creature_loot_template` WHERE `item` IN (3155,3156,3157,3218,3634);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (421,422,423,424,99);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,421,0,0,0,'Disable quest Prove Your Worth (Removed in 4.0.3a)'),
(1,422,0,0,0,'Disable quest Arugal''s Folly (Removed in 4.0.3a)'),
(1,423,0,0,0,'Disable quest Arugal''s Folly (Removed in 4.0.3a)'),
(1,424,0,0,0,'Disable quest Arugal''s Folly (Removed in 4.0.3a)'),
(1,99,0,0,0,'Disable quest Arugal''s Folly (Removed in 4.0.3a)');
