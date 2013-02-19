UPDATE `creature_template` SET `npcflag`=`npcflag` |2 WHERE `entry` IN (25918,25929,25931,25933,25936,25938,25946,32811,32812,32813,32816);

DELETE FROM `creature_loot_template` WHERE `entry` IN(17465,20583) AND `item`=22554;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(17465,22554,15,1,0,1,1), -- Formula: Enchant 2H Weapon - Savagery
(20583,22554,15,1,0,1,1); -- Formula: Enchant 2H Weapon - Savagery
