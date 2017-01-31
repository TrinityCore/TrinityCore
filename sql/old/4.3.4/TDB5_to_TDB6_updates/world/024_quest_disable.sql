-- "The Master of Fenris Isle" quest chain was removed in 4.0.3a
-- Following items, related to the quest, are no longer needed in loot templates
-- Essence of Nightlash (3622), Rot Hide Ichor (3236), Thule's Head (3623)
-- http://www.wowpedia.org/The_Master_of_Fenris_Isle_quest_chain
DELETE FROM `creature_loot_template` WHERE `item` IN (3622,3236,3623);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (437,438,439,443,444,446,448,442);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,437,0,0,0,'Disable quest The Dead Fields (Removed in 4.0.3a)'),
(1,438,0,0,0,'Disable quest The Decrepit Ferry (Removed in 4.0.3a)'),
(1,439,0,0,0,'Disable quest Rot Hide Clues (Removed in 4.0.3a)'),
(1,443,0,0,0,'Disable quest Rot Hide Ichor (Removed in 4.0.3a)'),
(1,444,0,0,0,'Disable quest Rot Hide Origins (Removed in 4.0.3a)'),
(1,446,0,0,0,'Disable quest Thule Ravenclaw (Removed in 4.0.3a)'),
(1,448,0,0,0,'Disable quest Report to Hadrec (Removed in 4.0.3a)'),
(1,442,0,0,0,'Disable quest Assault on Fenris Isle (Removed in 4.0.3a)');
