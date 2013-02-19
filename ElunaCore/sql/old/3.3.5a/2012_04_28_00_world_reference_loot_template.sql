-- The Descent into Madness
-- References
-- -------------------------------
-- -- Variables and definitions --
-- -------------------------------
-- Set References
SET @Vezax10Ref := 34373;
SET @Vezax25Ref := @Vezax10Ref+1;
SET @Yogg10Ref := @Vezax10Ref+2;
SET @Yogg25Ref := @Vezax10Ref+3;
SET @Chest := 12034;
SET @Shoulder := 12035;
SET @EmblemRef := 34349;
SET @Recipe := 34154;
SET @Vezax10 := 33271;
SET @Vezax25 := 33449;
SET @Yogg10 := 33288;
SET @Yogg25 := 33955;

-- -------------------------
-- -- Reference Templates --
-- -------------------------
-- Delete previous templates if existing
DELETE FROM `reference_loot_template` WHERE `entry` IN (34131,34132,34133,34164,34165);
DELETE FROM `reference_loot_template` WHERE `entry` IN (@Vezax10Ref,@Vezax25Ref,@Yogg10Ref,@Yogg25Ref,@Chest,@Shoulder);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Vezax 10 man
(@Vezax10Ref,46014,0,1,1,1,1), -- Saronite Animus Cloak
(@Vezax10Ref,46008,0,1,1,1,1), -- Choker of the Abyss
(@Vezax10Ref,46010,0,1,1,1,1), -- Darkstone Ring
(@Vezax10Ref,45996,0,1,1,1,1), -- Hoperender
(@Vezax10Ref,46015,0,1,1,1,1), -- Pendant of Endless Despair
(@Vezax10Ref,46013,0,1,1,1,1), -- Underworld Mantle
(@Vezax10Ref,46012,0,1,1,1,1), -- Vestments of the Piercing Light
(@Vezax10Ref,46009,0,1,1,1,1), -- Bindings of the Depths
(@Vezax10Ref,45997,0,1,1,1,1), -- Gauntlets of the Wretched
(@Vezax10Ref,46011,0,1,1,1,1), -- Shadowbite
-- Vezax 25 man
(@Vezax25Ref,45513,0,1,1,1,1), -- Boots of the Forgotten Dephts
(@Vezax25Ref,45509,0,1,1,1,1), -- Idol of the Corruptor
(@Vezax25Ref,45501,0,1,1,1,1), -- Boots of the Underdweller
(@Vezax25Ref,45512,0,1,1,1,1), -- Grips of the Unbroken
(@Vezax25Ref,45503,0,1,1,1,1), -- Metallic Loop of the Sufferer
(@Vezax25Ref,45505,0,1,1,1,1), -- Belt of Clinging Hope
(@Vezax25Ref,45502,0,1,1,1,1), -- Helm of the Faceless
(@Vezax25Ref,45145,0,1,1,1,1), -- Libram of the Sacred Shield
(@Vezax25Ref,45508,0,1,1,1,1), -- Belt of the Darkspeaker
(@Vezax25Ref,45504,0,1,1,1,1), -- Darkcore Leggings
(@Vezax25Ref,45514,0,1,1,1,1), -- Mantle of the Unknowing
(@Vezax25Ref,45515,0,1,1,1,1), -- Ring of the Vacant Eye
(@Vezax25Ref,45507,0,1,1,1,1), -- The General's Heart
-- Yogg 10 man
(@Yogg10Ref,46016,0,1,1,1,1), -- Abaddon
(@Yogg10Ref,46018,0,1,1,1,1), -- Deliverance
(@Yogg10Ref,46019,0,1,1,1,1), -- Leggings of the Insatiable
(@Yogg10Ref,46021,0,1,1,1,1), -- Royal Seal of King Llane
(@Yogg10Ref,46022,0,1,1,1,1), -- Pendant of a Thousand Maws
(@Yogg10Ref,46024,0,1,1,1,1), -- Kingsbane
(@Yogg10Ref,46025,0,1,1,1,1), -- Devotion
(@Yogg10Ref,46028,0,1,1,1,1), -- Faceguard of the Eyeless Horror
(@Yogg10Ref,46030,0,1,1,1,1), -- Threads of the Dragon Council
(@Yogg10Ref,46031,0,1,1,1,1), -- Touch of Madness
-- Yogg 25 man
(@Yogg25Ref,45521,0,1,1,1,1), -- Earthshaper
(@Yogg25Ref,45522,0,1,1,1,1), -- Blood of the Old God
(@Yogg25Ref,45523,0,1,1,1,1), -- Garona's Guise
(@Yogg25Ref,45524,0,1,1,1,1), -- Chestguard of Insidious Intent
(@Yogg25Ref,45525,0,1,1,1,1), -- Godbane Signet
(@Yogg25Ref,45527,0,1,1,1,1), -- Soulscribe
(@Yogg25Ref,45529,0,1,1,1,1), -- Shawl of Haunted Memories
(@Yogg25Ref,45530,0,1,1,1,1), -- Sanity's Bond
(@Yogg25Ref,45531,0,1,1,1,1), -- Chestguard of the Fallen God
(@Yogg25Ref,45532,0,1,1,1,1), -- Cowl of Dark Whispers
-- Chest for Yogg
(@Chest,45635,0,1,1,1,1), -- Chestguard of the Wayward Conqueror
(@Chest,45636,0,1,1,1,1), -- Chestguard of the Wayward Protector
(@Chest,45637,0,1,1,1,1), -- Chestguard of the Wayward Vanquisher
(@Shoulder,45656,0,1,1,1,1), -- Mantle of the Wayward Conqueror
(@Shoulder,45657,0,1,1,1,1), -- Mantle of the Wayward Protector
(@Shoulder,45658,0,1,1,1,1); -- Mantle of the Wayward Vanquisher

DELETE FROM `creature_loot_template` WHERE `entry` IN(@Vezax10,@Vezax25,@Yogg10,@Yogg25);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ----------------------------------------------------------
-- General Vezax
-- ----------------------------------------------------------
-- 10 man mode
(@Vezax10,1,100,3,0,-@Vezax10Ref,2), -- 2x Normal Loot Item
(@Vezax10,47241,100,3,0,1,1), -- 1x Emblem of Triumph
-- hardmode loot 10
(@Vezax10,46032,0,2,1,1,1), -- Drape of the Faceless General
(@Vezax10,46034,0,2,1,1,1), -- Leggings of Profound Darkness
(@Vezax10,46033,0,2,1,1,1), -- Tortured Earth
(@Vezax10,46035,0,2,1,1,1), -- Aesuga, Hand of the Ardent Champion
(@Vezax10,46036,0,2,1,1,1), -- Void Sabre
-- 25 man mode
(@Vezax25,1,100,3,0,-@Vezax25Ref,3), -- 3x Normal Loot Item
(@Vezax25,47241,100,3,0,1,1), -- 1x Emblem of Triumph
(@Vezax25,2,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Vezax25,3,10,1,0,-34350,1), -- Chance on Runed Orb
-- hardmode loot 25
(@Vezax25,45498,0,2,1,1,1), -- Lotrafen, Spear of the Damned
(@Vezax25,45511,0,2,1,1,1), -- Scepter of Lost Souls
(@Vezax25,45516,0,2,1,1,1), -- Voldrethar, Dark Blade of Oblivion
(@Vezax25,45517,0,2,1,1,1), -- Pendulum of Infinity
(@Vezax25,45519,0,2,1,1,1), -- Vestments of the Blind Denizen
(@Vezax25,45518,0,2,1,1,1), -- Flare of the Heavens
(@Vezax25,45520,0,2,1,1,1), -- Handwraps of the Vigilant
-- ----------------------------------------------------------
-- Yogg Saron
-- ----------------------------------------------------------
-- 10 man
-- All modes
(@Yogg10,1,100,31,0,-@Yogg10Ref,1), -- 1x Normal Loot item for modes 0&1&2&3&4
(@Yogg10,2,100,31,0,-@Chest,1), -- 1x Tier token for modes 0&1&2&3&4
(@Yogg10,47241,100,31,0,1,1), -- 1x Emblem of Triumph for modes 0&1&2&3&4
-- Extra for <3 watchers
(@Yogg10,3,100,30,0,-@EmblemRef,1), -- additional Emblem for modes2&3
-- Extra for <2 watchers
(@Yogg10,4,100,28,0,-34350,1), -- Runed Orb for 0&1&2
(@Yogg10,5,10,28,0,-@Recipe,1), -- Chance on Recipe for 0&1&2
-- Extra for <1 watchers
(@Yogg10,6,100,24,0,-@EmblemRef,1), -- additional Emblem for 0&1
(@Yogg10,7,100,24,0,-@Recipe,1), -- Garanteed Recipe for 0&1
-- Hardmode 10 loot
(@Yogg10,46067,0,24,1,1,1), -- Hammer of Crushing Whispers
(@Yogg10,46068,0,24,1,1,1), -- Amice of Inconceivable Horror
(@Yogg10,46095,0,24,1,1,1), -- Soul-Devouring Cinch
(@Yogg10,46096,0,24,1,1,1), -- Signet of Soft Lament
(@Yogg10,46097,0,24,1,1,1), -- Caress of Insanity
-- Extra for 0 watchers
(@Yogg10,46312,100,16,0,1,1), -- Vanquished Clutches of Yogg-Saron
-- 25 man mode
-- All modes
(@Yogg25,1,100,31,0,-@Yogg25Ref,2), -- 2x Normal Loot item for modes 0&1&2&3&4
(@Yogg25,2,100,31,0,-@Shoulder,2), -- 2x Tier token for modes 0&1&2&3&4
(@Yogg25,47241,100,31,0,1,1), -- 1x Emblem of Triumph for modes 0&1&2&3&4
(@Yogg25,3,10,31,0,-34350,1), -- Chance on Runed Orb for modes 0&1&2&3&4
(@Yogg25,4,10,31,0,-@Recipe,1), -- Chance on Recipe for 0&1&2&3&4
(@Yogg25,45897,100,31,0,1,1), -- Fragment of Val'anyr
-- Extra for <3 watchers
(@Yogg25,5,100,30,0,-@EmblemRef,1), -- additional Emblem for modes2&3
-- Extra for <2 watchers
(@Yogg25,6,100,28,0,-34350,1), -- Runed Orb for 0&1&2
-- Extra for <1 watchers
(@Yogg25,7,100,24,0,-@EmblemRef,1), -- additional Emblem for 0&1
(@Yogg25,8,100,24,0,-@Recipe,1), -- Garanteed Recipe for 0&1
-- Hardmode 25 loot
(@Yogg25,45533,0,24,1,1,1), -- Dark Edge of Depravity
(@Yogg25,45534,0,24,1,1,1), -- Seal of the Betrayed King
(@Yogg25,45535,0,24,1,1,1), -- Show of Faith
(@Yogg25,45536,0,24,1,1,1), -- Legguards of Cunning Deception
(@Yogg25,45537,0,24,1,1,1), -- Threads of the False Oracle
-- Extra for 0 watchers
(@Yogg25,45693,100,16,0,1,1); -- Mimiron's Head

-- Cleanups
DELETE FROM `conditions` WHERE `SourceEntry`=45897 AND `SourceGroup`=33955;
