-- "Apprentice's Duties", 2-part quest chain, was removed in 4.0.3a
-- Young Crocolisk Skin (3397) and Giant Crocolisk Skin (3348), related to these quests, are no longer needed in loot template
-- http://www.wowpedia.org/Quest:Apprentice's_Duties / http://www.wowpedia.org/Quest:Young_Crocolisk_Skins
DELETE FROM `creature_loot_template` WHERE `item` IN (3348,3397);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`IN (484,471);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,484,0,0,0,'Disable quest Young Crocolisk Skins (Removed in 4.0.3a)'),
(1,471,0,0,0,'Disable quest Apprentice''s Duties (Removed in 4.0.3a)');
