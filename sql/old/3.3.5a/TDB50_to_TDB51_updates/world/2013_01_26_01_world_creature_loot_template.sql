-- Coren Direbrew ( http://old.wowhead.com/npc=23872 ) loot fix by dele
DELETE FROM `creature_loot_template` WHERE `entry`=23872 AND `item` IN (38280,38281);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(23872,38280,100,1,0,1,1), -- Direbrew's Dire Brew Alliance version
(23872,38281,100,1,0,1,1); -- Direbrew's Dire Brew Horde version 
