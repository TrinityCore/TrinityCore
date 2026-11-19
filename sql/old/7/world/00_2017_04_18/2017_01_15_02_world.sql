-- Add missing loot
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (205890,205891,205892);
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Chance`,`QuestRequired`,`Lootmode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(205890,61972,100,1,1,0,1,1), -- Add missing quest item to Highvale Notes for quest 27626 The Highvale Documents
(205891,61973,100,1,1,0,1,1), -- Add missing quest item to Highvale Records for quest 27626 The Highvale Documents
(205892,61974,100,1,1,0,1,1); -- Add missing quest item to Highvale Report for quest 27626 The Highvale Documents
--
