-- Nefarian T2 Head
SET @REF:= 34348; (found by StoredProc)

-- Delete all so we can also renumber the itemids on refs for old loot
DELETE FROM `creature_loot_template` WHERE `entry`=11583; 
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(11583,19002,100,1,0,1,1),
(11583,19003,100,1,0,1,1),
(11583,21138,-100,1,0,1,1),
(11583,21142,-100,1,0,1,1),
(11583,1,100,1,1,-34002,2),
(11583,2,100,1,1,-34003,2),
(11583,3,100,1,1,-34009,2),
(11583,4,100,1,1,-34010,2),
(11583,5,100,1,1,-@REF,2);

DELETE FROM `reference_loot_template` WHERE `entry`=@REF;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@REF,16929,0,1,1,1,1), -- Nemesis Skullcap (Warlock)
(@REF,16914,0,1,1,1,1), -- Netherwind Crown (Mage)
(@REF,16963,0,1,1,1,1), -- Helm of Wrath (Warrior)
(@REF,16908,0,1,1,1,1), -- Bloodfang Hood (Rogue)
(@REF,16955,0,1,1,1,1), -- Judgement Crown (Paladin)
(@REF,16900,0,1,1,1,1), -- Stormrage Cover (Druid)
(@REF,16939,0,1,1,1,1), -- Dragonstalker's Helm (Hunter)
(@REF,16921,0,1,1,1,1), -- Halo of Transcendence (Priest)
(@REF,16947,0,1,1,1,1); -- Helmet of Ten Storms (Shaman)
