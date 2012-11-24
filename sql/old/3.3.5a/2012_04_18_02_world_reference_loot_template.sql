-- ----------------------
-- -- Various Cleanups --
-- ----------------------
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=34105;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceGroup` IN (27081,27085,27073,26963,26955);
DELETE FROM `reference_loot_template` WHERE `entry` IN (12020,12021,12022,34105,34125,34126,34127,34128,34129,34130);
DELETE FROM `gameobject_loot_template` WHERE `entry`=10961; -- Bad Bogblossom fix was bad
UPDATE `gameobject_template` SET `data1`=26956 WHERE `entry`=194315;
-- -------------------------------
-- -- Variables and definitions --
-- -------------------------------
-- Freya 10 man
SET @Freya10k0ID := 194324; -- Freyas Gift 10man ALL elders alive
SET @Freya10k1ID := 194326; -- Freyas Gift 10man killed 1 elder
SET @Freya10k2ID := 194328; -- Freyas Gift 10man killed 2 elder
SET @Freya10k3ID := 194330; -- Freyas Gift 10man killed 3 elder
-- Freya 25 man
SET @Freya25k0ID := 194325; -- Freyas Gift 25man ALL elders alive
SET @Freya25k1ID := 194327; -- Freyas Gift 25man killed 1 elder
SET @Freya25k2ID := 194329; -- Freyas Gift 25man killed 2 elder
SET @Freya25k3ID := 194331; -- Freyas Gift 25man killed 3 elder
-- Hodir
SET @Hodir10nID := 194307; -- Cache of Winter 10man
SET @Hodir10hID := 194200; -- Rare Cache of Winter 10man
SET @Hodir25nID := 194308; -- Cache of Winter 25man
SET @Hodir25hID := 194201; -- Rare Cache of Winter 25man
-- Mimiron
SET @Mimiron10nID := 194789; -- Cache of Innovations 10man
SET @Mimiron25nID := 194956; -- Cache of Innovations 25man
SET @Mimiron10hID := 194957; -- Cache of Innovation 10 man Hardmode
SET @Mimiron25hID := 194958; -- Cache of Innovation 25 man Hardmode
-- Thorim
SET @Thorim10nID := 194312; -- Cache of Storms 10man
SET @Thorim10hID := 194313; -- Cache of Storms 10 man Hardmode
SET @Thorim25nID := 194314; -- Cache of Storms 25man
SET @Thorim25hID := 194315; -- Cache of Storms 25 man Hardmode

-- Use procedure to get Lootid from data1 field and assign it to a variable
-- Freya 10
CALL `sp_get_go_lootid`(@Freya10k0ID,@Freya10k0);
CALL `sp_get_go_lootid`(@Freya10k1ID,@Freya10k1);
CALL `sp_get_go_lootid`(@Freya10k2ID,@Freya10k2);
CALL `sp_get_go_lootid`(@Freya10k3ID,@Freya10k3);
-- Freya 25
CALL `sp_get_go_lootid`(@Freya25k0ID,@Freya25k0);
CALL `sp_get_go_lootid`(@Freya25k1ID,@Freya25k1);
CALL `sp_get_go_lootid`(@Freya25k2ID,@Freya25k2);
CALL `sp_get_go_lootid`(@Freya25k3ID,@Freya25k3);
-- Hodir 10
CALL `sp_get_go_lootid`(@Hodir10nID,@Hodir10n);
CALL `sp_get_go_lootid`(@Hodir10hID,@Hodir10h);
-- Hodir 25
CALL `sp_get_go_lootid`(@Hodir25nID,@Hodir25n);
CALL `sp_get_go_lootid`(@Hodir25hID,@Hodir25h);
-- Mimiron
CALL `sp_get_go_lootid`(@Mimiron10nID,@Mimiron10n);
CALL `sp_get_go_lootid`(@Mimiron10hID,@Mimiron10h);
CALL `sp_get_go_lootid`(@Mimiron25nID,@Mimiron25n);
CALL `sp_get_go_lootid`(@Mimiron25hID,@Mimiron25h);
-- Thorim
CALL `sp_get_go_lootid`(@Thorim10nID,@Thorim10n);
CALL `sp_get_go_lootid`(@Thorim10hID,@Thorim10h);
CALL `sp_get_go_lootid`(@Thorim25nID,@Thorim25n);
CALL `sp_get_go_lootid`(@Thorim25hID,@Thorim25h);
-- Set References
SET @Freya10Ref := 34365;
SET @Freya25Ref := @Freya10Ref+1;
SET @Hodir10Ref := @Freya10Ref+2;
SET @Hodir25Ref := @Freya10Ref+3;
SET @Mimiron10Ref := @Freya10Ref+4;
SET @Mimiron25Ref := @Freya10Ref+5;
SET @Thorim10Ref := @Freya10Ref+6;
SET @Thorim25Ref := @Freya10Ref+7;
SET @HandToken := 12026;
SET @LegToken := @HandToken+1;
SET @LegsToken := @HandToken+2;
SET @ChestToken := @HandToken+3;
SET @HeadToken := @HandToken+4;
SET @GloveToken := @HandToken+5;
SET @ShoulderToken := @HandToken+6;
SET @HelmToken := @HandToken+7;
SET @Recipe := 34154;
-- -------------------------
-- -- Reference Templates --
-- -------------------------
-- Delete previous templates if existing
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @Freya10Ref AND @Freya10Ref+7;
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @HandToken AND @HandToken+7;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Freya 10 man
(@Freya10Ref,45934,0,1,1,1,1), -- Unraveling Reach
(@Freya10Ref,45935,0,1,1,1,1), -- Ironbark Faceguard
(@Freya10Ref,45941,0,1,1,1,1), -- Chestguard of the Lasher
(@Freya10Ref,45936,0,1,1,1,1), -- Legplates of Flourishing Resolve
(@Freya10Ref,45940,0,1,1,1,1), -- Tunic of the Limber Stalker
-- Freya 25 man
(@Freya25Ref,45483,0,1,1,1,1), -- Boots of the Servant
(@Freya25Ref,45482,0,1,1,1,1), -- Leggings of the Lifetender
(@Freya25Ref,45481,0,1,1,1,1), -- Gauntlets of Ruthless Reprisal
(@Freya25Ref,45480,0,1,1,1,1), -- Nymph Heart Charm
(@Freya25Ref,45479,0,1,1,1,1), -- The Lifebinder
-- Freya Tokens
(@HandToken,45644,0,1,1,1,1), -- Gloves of the Wayward Conqueror
(@HandToken,45645,0,1,1,1,1), -- Gloves of the Wayward Protector
(@HandToken,45646,0,1,1,1,1), -- Gloves of the Wayward Vanquisher
(@LegToken,45653,0,1,1,1,1), -- Legplates of the Wayward Conqueror
(@LegToken,45654,0,1,1,1,1), -- Legplates of the Wayward Protector
(@LegToken,45655,0,1,1,1,1), -- Legplates of the Wayward Vanquisher
-- Hodir 10 man
(@Hodir10Ref,45874,0,1,1,1,1), -- Signet of Winter
(@Hodir10Ref,45458,0,1,1,1,1), -- Stormedge
(@Hodir10Ref,45873,0,1,1,1,1), -- Winter's Frigid Embrace
(@Hodir10Ref,45872,0,1,1,1,1), -- Avalanche
(@Hodir10Ref,45454,0,1,1,1,1), -- Cowl of Icy Breaths
-- Hodir 25 man
(@Hodir25Ref,45452,0,1,1,1,1), -- Frostplate Greaves
(@Hodir25Ref,45454,0,1,1,1,1), -- Frost-Bound Chain Bracers
(@Hodir25Ref,45453,0,1,1,1,1), -- Winter's Icy Embrace
(@Hodir25Ref,45450,0,1,1,1,1), -- Northern Barrier
(@Hodir25Ref,45451,0,1,1,1,1), -- Frozen Loop
-- Hodir Tokens
(@LegsToken,45650,0,1,1,1,1), -- Leggings of the Wayward Conqueror
(@LegsToken,45651,0,1,1,1,1), -- Leggings of the Wayward Protector
(@LegsToken,45652,0,1,1,1,1), -- Leggings of the Wayward Vanquisher
(@ChestToken,45632,0,1,1,1,1), -- Breastplate of the Wayward Conqueror
(@ChestToken,45633,0,1,1,1,1), -- Breastplate of the Wayward Protector
(@ChestToken,45634,0,1,1,1,1), -- Breastplate of the Wayward Vanquisher
-- Mimiron 10 man
(@Mimiron10Ref,45974,0,1,1,1,1), -- Shoulderguards of Assimilation
(@Mimiron10Ref,45976,0,1,1,1,1), -- Static Charge Handwraps
(@Mimiron10Ref,45972,0,1,1,1,1), -- Pulse Baton
(@Mimiron10Ref,45973,0,1,1,1,1), -- Stylish Power Cape
(@Mimiron10Ref,45975,0,1,1,1,1), -- Cable of the Metrognome
-- Mimiron 25 man
(@Mimiron25Ref,45492,0,1,1,1,1), -- Malleable Steelweave Mantle
(@Mimiron25Ref,45493,0,1,1,1,1), -- Asimov's Drape
(@Mimiron25Ref,45490,0,1,1,1,1), -- Pandora's Plea
(@Mimiron25Ref,45491,0,1,1,1,1), -- Waistguard of the Creator
(@Mimiron25Ref,45489,0,1,1,1,1), -- Insanity's Grip
-- Mimiron Tokens
(@HeadToken,45647,0,1,1,1,1), -- Helm of the Wayward Conqueror
(@HeadToken,45648,0,1,1,1,1), -- Helm of the Wayward Protector
(@HeadToken,45649,0,1,1,1,1), -- Helm of the Wayward Vanquisher
(@GloveToken,45641,0,1,1,1,1), -- Gauntlets of the Wayward Conqueror
(@GloveToken,45642,0,1,1,1,1), -- Gauntlets of the Wayward Protector
(@GloveToken,45643,0,1,1,1,1), -- Gauntlets of the Wayward Vanquisher
-- Thorim 10 man
(@Thorim10Ref,45927,0,1,1,1,1), -- Handwraps of Resonance
(@Thorim10Ref,45894,0,1,1,1,1), -- Leggings of Unstable Discharge
(@Thorim10Ref,45895,0,1,1,1,1), -- Belt of the Blood Pit
(@Thorim10Ref,45893,0,1,1,1,1), -- Guise of the Midgard Serpent
(@Thorim10Ref,45892,0,1,1,1,1), -- Legacy of Thunder
-- Throim 25 man
(@Thorim25Ref,45468,0,1,1,1,1), -- Leggings of Lost Love
(@Thorim25Ref,45466,0,1,1,1,1), -- Scale of Fates
(@Thorim25Ref,45467,0,1,1,1,1), -- Belt of the Betrayed
(@Thorim25Ref,45469,0,1,1,1,1), -- Sif's Promise
(@Thorim25Ref,45463,0,1,1,1,1), -- Vulmir, the Northern Tempest
-- Thorim Tokens
(@ShoulderToken,45659,0,1,1,1,1), -- Spaulders of the Wayward Conqueror
(@ShoulderToken,45660,0,1,1,1,1), -- Spaulders of the Wayward Protector
(@ShoulderToken,45661,0,1,1,1,1), -- Spaulders of the Wayward Vanquisher
(@HelmToken,45638,0,1,1,1,1), --  Crown of the Wayward Conqueror
(@HelmToken,45639,0,1,1,1,1), --  Crown of the Wayward Protector
(@HelmToken,45640,0,1,1,1,1); --  Crown of the Wayward Vanquisher
-- -------------------------------
-- -- Gameobject Loot Templates --
-- -------------------------------
-- Delete previous templates if existing
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@Freya10k3,@Freya10k2,@Freya10k1,@Freya10k0,@Freya25k3,@Freya25k2,@Freya25k1,@Freya25k0,@Hodir10n,@Hodir10h,@Hodir25n,@Hodir25h,@Mimiron10n,@Mimiron10h,@Mimiron25n,@Mimiron25h,@Thorim10n,@Thorim10h,@Thorim25n,@Thorim25h);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ------------------
-- -- Freya 10 man --
-- ------------------
-- Normal Mode:
(@Freya10k3,1,100,1,0,-@Freya10Ref,1), -- 1 from normal loot
(@Freya10k3,2,100,1,0,-@HandToken,1), -- 1 from tokens
(@Freya10k3,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya10k3,47241,100,1,0,1,1), -- 1x Emblem of Triumph
-- Hard Mode: 1 elder alive
(@Freya10k2,1,100,1,0,-@Freya10Ref,1), -- 1 from normal loot
(@Freya10k2,2,100,1,0,-@HandToken,1), -- 1 from tokens
(@Freya10k2,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya10k2,47241,100,1,0,2,2), -- 2x Emblem of Triumph
(@Freya10k2,45087,100,1,0,1,1), -- Runed Orb
(@Freya10k2,3,100,1,0,-34349,1), -- 1x Emblem of Triumph for Alive Elders
-- Hard Mode: 2 elders alive
(@Freya10k1,1,100,1,0,-@Freya10Ref,1), -- 1 from normal loot
(@Freya10k1,2,100,1,0,-@HandToken,1), -- 1 from tokens
(@Freya10k1,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya10k1,47241,100,1,0,3,3), -- 3x Emblem of Triumph
(@Freya10k1,45087,100,1,0,1,1), -- Runed Orb
(@Freya10k1,3,100,1,0,-@Recipe,1), -- 1 from Recipe
(@Freya10k1,4,100,1,0,-34349,2), -- 2x Emblem of Triumph for Alive Elders
-- Hard Mode: 3 elders alive
(@Freya10k0,1,100,1,0,-@Freya10Ref,1), -- 1 from normal loot
(@Freya10k0,2,100,1,0,-@HandToken,1), -- 1 from tokens
(@Freya10k0,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya10k0,47241,100,1,0,3,3), -- 3x Emblem of Triumph (self)
(@Freya10k0,45087,100,1,0,1,1), -- Runed Orb
(@Freya10k0,3,100,1,0,-@Recipe,1), -- 1 from Recipe
(@Freya10k0,45788,-100,1,0,1,1), -- Freya's Sigil 10 man QUEST ONLY
(@Freya10k0,4,100,1,0,-34349,1), -- 3x Emblem of Triumph for Alive Elders
-- 1 from Hardmode items:
(@Freya10k0,45943,0,1,1,1,1), -- Gloves of Whispering Winds
(@Freya10k0,45946,0,1,1,1,1), -- Fire Orchid Signet
(@Freya10k0,45945,0,1,1,1,1), -- Seed of Budding Carnage
(@Freya10k0,45947,0,1,1,1,1), -- Serilas, Blood Blade of Invar One-Arm
(@Freya10k0,45294,0,1,1,1,1), -- Petrified Ivy Sprig
-- ------------------
-- -- Freya 25 man --
-- ------------------
-- Normal Mode:
(@Freya25k3,1,100,1,0,-@Freya25Ref,1), -- 1 from normal loot
(@Freya25k3,2,100,1,0,-@LegToken,2), -- 2 from tokens
(@Freya25k3,47241,100,1,0,1,1), -- 1x Emblem of Triumph
(@Freya25k3,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya25k3,3,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Freya25k3,45087,10,1,0,1,1), -- Chance on Runed Orb
(@Freya25k3,45083,5,1,0,1,1), -- Fragment of Val'anyr
-- Hard Mode: 1 elder alive
(@Freya25k2,1,100,1,0,-@Freya25Ref,1), -- 1 from normal loot
(@Freya25k2,2,100,1,0,-@LegToken,2), -- 2 from tokens
(@Freya25k2,47241,100,1,0,2,2), -- 2x Emblem of Triumph
(@Freya25k2,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya25k2,3,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Freya25k2,4,10,1,0,-34350,1), -- Chance on Runed Orb
(@Freya25k2,45087,100,1,0,2,2), -- 2x Runed Orb
(@Freya25k2,45083,7,1,0,1,1), -- Fragment of Val'anyr
(@Freya25k2,5,100,1,0,-34349,1), -- 1x Emblem of Triumph for Alive Elder
-- Hard Mode: 2 elders alive
(@Freya25k1,1,100,1,0,-@Freya25Ref,1), -- 1 from normal loot
(@Freya25k1,2,100,1,0,-@LegToken,2), -- 2 from tokens
(@Freya25k1,47241,100,1,0,3,3), -- 3x Emblem of Triumph
(@Freya25k1,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya25k1,3,10,1,0,-34350,1), -- Chance on Runed Orb
(@Freya25k1,45087,100,1,0,2,2), -- 2x Runed Orb
(@Freya25k1,4,100,1,0,-@Recipe,1), -- Recipe
(@Freya25k1,5,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Freya25k1,45083,9,1,0,1,1), -- Fragment of Val'anyr
(@Freya25k1,6,100,1,0,-34349,2), -- 2x Emblem of Triumph for Alive Elder
-- Hard Mode: 3 elders alive
(@Freya25k0,1,100,1,0,-@Freya25Ref,1), -- 1 from normal loot
(@Freya25k0,2,100,1,0,-@LegToken,2), -- 2 from tokens
(@Freya25k0,47241,100,1,0,3,3), -- 3x Emblem of Triumph
(@Freya25k0,46110,100,1,0,1,1), -- Alchemist's Cache
(@Freya25k0,3,10,1,0,-34350,1), -- Chance on Runed Orb
(@Freya25k0,45087,100,1,0,2,2), -- 2x Runed Orb
(@Freya25k0,4,100,1,0,-@Recipe,1), -- Recipe
(@Freya25k0,5,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Freya25k0,45814,-100,1,0,1,1), -- Freya's Sigil 25 man QUEST ONLY
(@Freya25k0,45083,20,1,0,1,1), -- Fragment of Val'anyr
(@Freya25k2,6,100,1,0,-34349,3), -- 3x Emblem of Triumph for Alive Elder
-- 1 from Hardmode items
(@Freya25k0,45484,0,1,1,1,1), -- Bladetwister
(@Freya25k0,45486,0,1,1,1,1), -- Drape of the Sullen Goddess
(@Freya25k0,45487,0,1,1,1,1), -- Handguards of Revitalization
(@Freya25k0,45488,0,1,1,1,1), -- Leggings of the Enslaved Idol
(@Freya25k0,45613,0,1,1,1,1), -- Dreambinder
(@Freya25k0,45485,0,1,1,1,1), -- Bronze Pendant of the Vanir
-- ------------------
-- -- Hodir 10 man --
-- ------------------
(@Hodir10n,1,100,1,0,-@Hodir10Ref,1), -- 1x Normal Loot Item
(@Hodir10n,2,100,1,0,-@LegsToken,1), -- 1x Token
(@Hodir10n,47241,100,1,0,1,1), -- Emblem of Triumph
-- Hard mode:
(@Hodir10h,1,100,1,0,-@Hodir10Ref,1), -- 1x Normal Loot Item
(@Hodir10h,2,100,1,0,-@LegsToken,1), -- 1x Token
(@Hodir10h,47241,100,1,0,1,1), -- Emblem of Triumph
(@Hodir10h,45786,-100,1,0,1,1), -- Hodir's Sigil
-- 1 from Hardmode items
(@Hodir10h,45887,0,1,1,1,1), -- Ice Layered Barrier
(@Hodir10h,45888,0,1,1,1,1), -- Bitter Cold Armguards
(@Hodir10h,45886,0,1,1,1,1), -- Icecore Staff
(@Hodir10h,45876,0,1,1,1,1), -- Shiver
(@Hodir10h,45877,0,1,1,1,1), -- The Boreal Guard
-- ------------------
-- -- Hodir 25 man --
-- ------------------
(@Hodir25n,1,100,1,0,-@Hodir25Ref,1), -- 1x Normal Loot Item
(@Hodir25n,2,100,1,0,-@ChestToken,1), -- 1x Token
(@Hodir25n,47241,100,1,0,1,1), -- Emblem of Triumph
(@Hodir25n,3,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Hodir25n,45087,10,1,0,1,1), -- Chance on Runed Orb
(@Hodir25n,45083,10,1,0,1,1), -- Fragment of Val'anyr
-- Hard mode:
(@Hodir25h,1,100,1,0,-@Hodir25Ref,1), -- 1x Normal Loot Item
(@Hodir25h,2,100,1,0,-@ChestToken,2), -- 2x Token
(@Hodir25h,47241,100,1,0,1,1), -- Emblem of Triumph
(@Hodir25h,45815,-100,1,0,1,1), -- Hodir's Sigil
(@Hodir25h,3,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Hodir25h,45087,10,1,0,1,1), -- Chance on Runed Orb
(@Hodir25h,45083,20,1,0,1,1), -- Fragment of Val'anyr
-- --------------------
-- -- Mimiron 10 man --
-- --------------------
(@Mimiron10n,1,100,1,0,-@Mimiron10Ref,1), -- 1x Normal Loot Item
(@Mimiron10n,2,100,1,0,-@HeadToken,1), -- 1x Token
(@Mimiron10n,47241,100,1,0,1,1), -- 1x Emblem of Triumph
-- Hardmode 10 man
(@Mimiron10h,1,100,1,0,-@Mimiron10Ref,1), -- 1x Normal Loot Item
(@Mimiron10h,2,100,1,0,-@HeadToken,1), -- 1x Token
(@Mimiron10h,47241,100,1,0,1,1), -- 1x Emblem of Triumph
(@Mimiron10h,45787,-100,1,0,1,1), -- Mimiron's Sigel (QUEST ONLY, HARDMODE ONLY)
-- 1 from Hardmode items
(@Mimiron10h,45989,0,1,1,1,1), -- Tempered Mercury Greaves
(@Mimiron10h,45982,0,1,1,1,1), -- Fused Alloy Legplates
(@Mimiron10h,45993,0,1,1,1,1), -- Mimiron's Flight Goggles
(@Mimiron10h,45988,0,1,1,1,1), -- Greaves of the Iron Army
(@Mimiron10h,45990,0,1,1,1,1), -- Fusion Blade
-- --------------------
-- -- Mimiron 25 man --
-- --------------------
(@Mimiron25n,1,100,1,0,-@Mimiron25Ref,1), -- 1x Normal Loot Item
(@Mimiron25n,2,100,1,0,-@GloveToken,2), -- 2x Token
(@Mimiron25n,47241,100,1,0,1,1), -- 1x Emblem of Triumph
(@Mimiron25n,3,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Mimiron25n,45087,10,1,0,1,1), -- Chance on Runed Orb
(@Mimiron25n,45083,8,1,0,1,1), -- Fragment of Val'anyr Normal
-- Hard Mode 25 man
(@Mimiron25h,1,100,1,0,-@Mimiron25Ref,1), -- 1x Normal Loot Item
(@Mimiron25h,2,100,1,0,-@GloveToken,2), -- 2x Token
(@Mimiron25h,47241,100,1,0,1,1), -- 1x Emblem of Triumph
(@Mimiron25h,3,10,1,0,-@Recipe,1), -- Chance on Recipe
(@Mimiron25h,45087,10,1,0,1,1), -- Chance on Runed Orb
(@Mimiron25h,45816,-100,1,0,1,1), -- Mimiron's Sigel (QUEST ONLY, HARDMODE ONLY)
(@Mimiron25h,45083,18,1,0,1,1), -- Fragment of Val'anyr Hardmode
-- 1 from Hardmode items
(@Mimiron25h,45496,0,1,1,1,1), -- Titanskin Cloak
(@Mimiron25h,45494,0,1,1,1,1), -- Delirium's Touch
(@Mimiron25h,45663,0,1,1,1,1), -- Armbands of Bedlam
(@Mimiron25h,45620,0,1,1,1,1), -- Starshard Edge
(@Mimiron25h,45495,0,1,1,1,1), -- Conductive Seal
(@Mimiron25h,45497,0,1,1,1,1), -- Crown of Luminescence
-- -------------------
-- -- Thorim 10 man --
-- -------------------
(@Thorim10n,1,100,1,0,-@Thorim10Ref,1), -- 1x Normal Loot Item
(@Thorim10n,2,100,1,0,-@ShoulderToken,1), -- 1x Token
(@Thorim10n,47241,100,1,0,1,1), -- 1x Emblem of Triumph
-- Hardmode 10 man
(@Thorim10h,1,100,1,0,-@Thorim10Ref,1), -- 1x Normal Loot Item
(@Thorim10h,2,100,1,0,-@ShoulderToken,1), -- 1x Token
(@Thorim10h,47241,100,1,0,1,1), -- 1x Emblem of Triumph
(@Thorim10h,45784,-100,2,0,1,1), -- Thorim's Sigil (QUEST ONLY, HARDMODE ONLY)
-- 1 from Hardmode items
(@Thorim10h,45933,0,2,1,1,1), -- Pendant of the Shallow Grave
(@Thorim10h,45929,0,2,1,1,1), -- Sif's Remembrance
(@Thorim10h,45928,0,2,1,1,1), -- Gauntlets of the Thunder God
(@Thorim10h,45931,0,2,1,1,1), -- Mjolnir Runestone
(@Thorim10h,45930,0,2,1,1,1), -- Combatant's Bootblade
-- -------------------
-- -- Thorim 25 man --
-- -------------------
(@Thorim25n,1,100,3,0,-@Thorim25Ref,1), -- 1x Normal Loot Item
(@Thorim25n,2,100,3,0,-@HelmToken,2), -- 2x Token
(@Thorim25n,47241,100,3,0,1,1), -- 1x Emblem of Triumph
(@Thorim25n,3,10,3,0,-@Recipe,1), -- Chance on Recipe
(@Thorim25n,45087,10,3,0,1,1), -- Chance on Runed Orb
(@Thorim25n,45083,8,1,0,1,1), -- Fragment of Val'anyr Normal
-- Hardmode 25 man
(@Thorim25h,1,100,3,0,-@Thorim25Ref,1), -- 1x Normal Loot Item
(@Thorim25h,2,100,3,0,-@HelmToken,2), -- 2x Token
(@Thorim25h,47241,100,3,0,1,1), -- 1x Emblem of Triumph
(@Thorim25h,3,10,3,0,-@Recipe,1), -- Chance on Recipe
(@Thorim25h,45087,10,3,0,1,1), -- Chance on Runed Orb
(@Thorim25h,45817,-100,1,0,1,1), -- Thorim's Sigil (QUEST ONLY, HARDMODE ONLY)
(@Thorim25h,45083,18,1,0,1,1), -- Fragment of Val'anyr Hardmode
-- 1 from Hardmode items
(@Thorim25h,45471,0,1,1,1,1), -- Fate's Clutch
(@Thorim25h,45570,0,1,1,1,1), -- Skyforge Crossbow
(@Thorim25h,45472,0,1,1,1,1), -- Warhelm of the Champion
(@Thorim25h,45474,0,1,1,1,1), -- Pauldrons of the Combatant
(@Thorim25h,45470,0,1,1,1,1), -- Wisdom's Hold
(@Thorim25h,45473,0,1,1,1,1); -- Embrace of the Gladiator

