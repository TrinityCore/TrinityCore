-- "Sweet Amber" quest chain was removed in 4.0.3a
-- A Sycamore Branch (742) and Bundle of Charred Oak (743), related to the quests in the chain, are no longer needed in loot template
-- http://www.wowpedia.org/Quest:Sweet_Amber
DELETE FROM `creature_loot_template` WHERE `item`=742;
DELETE FROM `gameobject_loot_template` WHERE `entry`=3844 and`item`=743;
UPDATE `gameobject_template` SET `questItem1`=0, `data1`=0 WHERE `entry`=50982; -- The Charred Oak that drops the Bundle
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (48,49,50,51,53);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,48,0,0,0,'Disable quest Sweet Amber (Removed in 4.0.3a)'),
(1,49,0,0,0,'Disable quest Sweet Amber (Removed in 4.0.3a)'),
(1,50,0,0,0,'Disable quest Sweet Amber (Removed in 4.0.3a)'),
(1,51,0,0,0,'Disable quest Sweet Amber (Removed in 4.0.3a)'),
(1,53,0,0,0,'Disable quest Sweet Amber (Removed in 4.0.3a)');
