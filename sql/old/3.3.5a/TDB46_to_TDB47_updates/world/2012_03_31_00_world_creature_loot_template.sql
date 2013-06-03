-- -------------------------------
-- -- The Antechamber of Ulduar --
-- -------------------------------
-- Creatures
SET @Brundir10 :=32857;
call `sp_get_npc_diffentry`(@Brundir10,1,@Brundir25); -- Get 25man id using procedure
SET @Molgeim10 :=32927;
call `sp_get_npc_diffentry`(@Molgeim10,1,@Molgeim25); -- Get 25man id using procedure
SET @Steelbreaker10 :=32867;
call `sp_get_npc_diffentry`(@Steelbreaker10,1,@Steelbreaker25); -- Get 25man id using procedure
SET @Auriaya10 :=33515;
call `sp_get_npc_diffentry`(@Auriaya10,1,@Auriaya25); -- Get 25man id using procedure
-- Gameobjects
SET @Kologarn10 := 195046; -- Cache of the Living Stone 10man
CALL `sp_get_go_lootid`(@Kologarn10,@CacheLivingStone10); -- Get Lootid from data1 field using procedure
SET @Kologarn25 := 195047; -- Cache of the Living Stone 25man
CALL `sp_get_go_lootid`(@Kologarn25,@CacheLivingStone25); -- Get Lootid from data1 field using procedure
-- bosses
SET @Assembly10Ref := 34359;
SET @Assembly25Ref := @Assembly10Ref+1;
SET @Kologarn10Ref := @Assembly10Ref+2;
SET @Kologarn25Ref := @Assembly10Ref+3;
SET @Auriaya10Ref := @Assembly10Ref+4;
SET @Auriaya25Ref := @Assembly10Ref+5;

-- ------------------------------
-- -- Reference Loot Templates --
-- ------------------------------
-- Delete previous templates if existing
DELETE FROM `reference_loot_template` WHERE `entry` IN (12019,34122,34123,34124,34163,34216);
-- Delete the current if existing & add
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @Assembly10Ref AND @Assembly10Ref+5;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Assembly Of Iron 10man
(@Assembly10Ref,45322,0,1,1,1,1), -- Cloak of the Iron Council
(@Assembly10Ref,45324,0,1,1,1,1), -- Leggings of Swift Reflexes
(@Assembly10Ref,45329,0,1,1,1,1), -- Circlet of True Sight
(@Assembly10Ref,45330,0,1,1,1,1), -- Greaves of Iron Intensity
(@Assembly10Ref,45331,0,1,1,1,1), -- Rune-Etched Nightblade
(@Assembly10Ref,45332,0,1,1,1,1), -- Stormtip
(@Assembly10Ref,45333,0,1,1,1,1), -- Belt of the Iron Servant
(@Assembly10Ref,45378,0,1,1,1,1), -- Boots of the Petrified Forest
(@Assembly10Ref,45418,0,1,1,1,1), -- Lady Maye's Sapphire Ring
(@Assembly10Ref,45423,0,1,1,1,1), -- Runetouch Wristwraps
-- Assembly Of Iron 25man
(@Assembly25Ref,45233,0,1,1,1,1), -- Stormrune Edge
(@Assembly25Ref,45234,0,1,1,1,1), -- Rapture
(@Assembly25Ref,45237,0,1,1,1,1), -- Phaelia's Vestments of the Sprouting Seed
(@Assembly25Ref,45193,0,1,1,1,1), -- Insurmountable Fervor
(@Assembly25Ref,45236,0,1,1,1,1), -- Unblinking Eye
(@Assembly25Ref,45225,0,1,1,1,1), -- Steelbreaker's Embrace
(@Assembly25Ref,45240,0,1,1,1,1), -- Raiments of the Iron Council
(@Assembly25Ref,45226,0,1,1,1,1), -- Ancient Iron Heaume
(@Assembly25Ref,45235,0,1,1,1,1), -- Radiant Seal
(@Assembly25Ref,45227,0,1,1,1,1), -- Iron-studded Mantle
(@Assembly25Ref,45239,0,1,1,1,1), -- Runeshaper's Gloves
(@Assembly25Ref,45224,0,1,1,1,1), -- Drape of the Lithe
(@Assembly25Ref,45232,0,1,1,1,1), -- Runed Ironhide Boots
(@Assembly25Ref,45228,0,1,1,1,1), -- Handguards of the Enclave
(@Assembly25Ref,45238,0,1,1,1,1), -- Overload Legwraps
-- Cache of Living Stone 10man
(@Kologarn10Ref,45701,0,1,1,1,1), -- Greaves of the Earthbinder
(@Kologarn10Ref,45965,0,1,1,1,1), -- Spire of Withering Dreams
(@Kologarn10Ref,45702,0,1,1,1,1), -- Emerald Signet Ring
(@Kologarn10Ref,45696,0,1,1,1,1), -- Mark of the Unyielding
(@Kologarn10Ref,45698,0,1,1,1,1), -- Sabatons of the Iron Watcher
(@Kologarn10Ref,45697,0,1,1,1,1), -- Shoulderguards of the Solemn Watch
(@Kologarn10Ref,45703,0,2,2,1,1), -- Spark of Hope
(@Kologarn10Ref,45700,0,2,2,1,1), -- Stoneguard
(@Kologarn10Ref,45699,0,2,2,1,1), -- Pendant of the Piercing Glare
(@Kologarn10Ref,45704,0,2,2,1,1), -- Shawl of the Shattered Giant
-- Cache of Living Stone 25man
(@Kologarn25Ref,45261,0,1,1,1,1), -- Giant's Bane
(@Kologarn25Ref,45266,0,1,1,1,1), -- Malice
(@Kologarn25Ref,45274,0,1,1,1,1), -- Leggings of the Stoneweaver
(@Kologarn25Ref,45269,0,1,1,1,1), -- Unfaltering Armguards
(@Kologarn25Ref,45268,0,1,1,1,1), -- Gloves of the Pythonic Guardian
(@Kologarn25Ref,45262,0,1,1,1,1), -- Necklace of Unerring Mettle
(@Kologarn25Ref,45275,0,1,1,1,1), -- Bracers of Unleashed Magic
(@Kologarn25Ref,45272,0,1,1,1,1), -- Robes of the Umbral Brute
(@Kologarn25Ref,45267,0,1,1,1,1), -- Saronite Plated Legguards
(@Kologarn25Ref,45263,0,1,1,1,1), -- Wrathstone
(@Kologarn25Ref,45271,0,1,1,1,1), -- Ironmender
(@Kologarn25Ref,45264,0,1,1,1,1), -- Decimator's Armguards
(@Kologarn25Ref,45265,0,1,1,1,1), -- Shoulderpads of the Monolith
(@Kologarn25Ref,45273,0,1,1,1,1), -- Handwraps of Plentiful Recovery
(@Kologarn25Ref,45270,0,1,1,1,1), -- Idol of the Crying Wind
-- Auriaya 10man
(@Auriaya10Ref,45707,0,1,1,1,1), -- Shieldwall of the Breaker
(@Auriaya10Ref,45708,0,1,1,1,1), -- Archaedas' Lost Legplates
(@Auriaya10Ref,45709,0,1,1,1,1), -- Nimble Climber's Belt
(@Auriaya10Ref,45711,0,1,1,1,1), -- Ironaya's Discarded Mantle
(@Auriaya10Ref,45712,0,1,1,1,1), -- Chestplate of Titanic Fury
(@Auriaya10Ref,45713,0,1,1,1,1), -- Nurturing Touch
(@Auriaya10Ref,45832,0,1,1,1,1), -- Mantle of the Preserver
(@Auriaya10Ref,45864,0,1,1,1,1), -- Cover of the Keepers
(@Auriaya10Ref,45865,0,1,1,1,1), -- Raiments of the Corrupted
(@Auriaya10Ref,45866,0,1,1,1,1), -- Elemental Focus Stone
-- Auriaya 25man
(@Auriaya25Ref,45327,0,1,1,1,1), -- Siren's Cry
(@Auriaya25Ref,45437,0,1,1,1,1), -- Runescribed Blade
(@Auriaya25Ref,45315,0,1,1,1,1), -- Stonerender
(@Auriaya25Ref,45439,0,1,1,1,1), -- Unwavering Stare
(@Auriaya25Ref,45326,0,1,1,1,1), -- Platinum Band of the Aesir
(@Auriaya25Ref,45441,0,1,1,1,1), -- Sandals of the Ancient Keeper
(@Auriaya25Ref,45435,0,1,1,1,1), -- Cowl of the Absolute
(@Auriaya25Ref,45438,0,1,1,1,1), -- Ring of the Faithful Servant
(@Auriaya25Ref,45434,0,1,1,1,1), -- Greaves of the Rockmender
(@Auriaya25Ref,45320,0,1,1,1,1), -- Shoulderplates of the Eternal
(@Auriaya25Ref,45325,0,1,1,1,1), -- Gloves of the Stonereaper
(@Auriaya25Ref,45440,0,1,1,1,1), -- Amice of the Stoic Watch
(@Auriaya25Ref,45334,0,1,1,1,1), -- Unbreakable Chestguard
(@Auriaya25Ref,45319,0,1,1,1,1), -- Cloak of the Makers
(@Auriaya25Ref,45436,0,1,1,1,1); -- Libram of the Resolute

-- ---------------------------
-- -- ASSIGN CREATURE LOOTS --
-- ---------------------------
UPDATE `creature_template` SET `lootid`=`entry` WHERE `entry` IN (@Brundir10,@Molgeim10,@Steelbreaker10,@Brundir25,@Molgeim25,@Steelbreaker25,@Auriaya10,@Auriaya25);
DELETE FROM `creature_loot_template` WHERE `entry` IN (@Brundir10,@Molgeim10,@Steelbreaker10,@Brundir25,@Molgeim25,@Steelbreaker25);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ASSEMBLY OF IRON 10-man
-- Stormcaller Brundir killed last
(@Brundir10,1,100,1,0,-@Assembly10Ref,2), -- 2 items from reference loot
(@Brundir10,47241,100,1,0,1,1), -- 1 Emblem of Triumph
-- Runemaster Molgeim killed last
(@Molgeim10,1,100,1,0,-@Assembly10Ref,2), -- 2 items from reference loot
(@Molgeim10,47241,100,1,0,2,2), -- 2 Emblem of Triumph
(@Molgeim10,45506,100,2,0,1,1), -- Archivum Data Disc
(@Molgeim10,45087,75,1,0,1,1), -- Runed Orb
-- Steelbreaker killed last
(@Steelbreaker10,1,100,1,0,-@Assembly10Ref,2), -- 2 items from reference loot
(@Steelbreaker10,47241,100,1,0,2,2), -- 2 Emblem of Triumph
(@Steelbreaker10,45087,75,1,0,1,1), -- Runed Orb
(@Steelbreaker10,45506,100,1,0,1,1), -- Archivum Data Disc for Quest
(@Steelbreaker10,25455,0,1,1,1,1), -- Belt fo the Crystal Tree
(@Steelbreaker10,45447,0,1,1,1,1), -- Watchful Eye of Fate
(@Steelbreaker10,45456,0,1,1,1,1), -- Loop of the Agile
(@Steelbreaker10,45449,0,1,1,1,1), -- The Masticator
(@Steelbreaker10,45448,0,1,1,1,1), -- Perilous Bite
-- ASSEMBLY OF IRON 25-man
-- Stormcaller Brundir killed last
(@Brundir25,1,100,1,0,-@Assembly25Ref,3), -- 3 items from reference loot
(@Brundir25,2,10,1,0,-34154,1), -- Chance on Recipe
(@Brundir25,45038,8,1,0,1,1), -- Fragment of Val'anyr
(@Brundir25,45087,75,1,0,1,1), -- Runed Orb
(@Brundir25,47241,100,1,0,1,2), --  2 Emblems of Triumph
-- Runemaster Molgeim killed last
(@Molgeim25,1,100,1,0,-@Assembly25Ref,3), -- 3 items from reference loot
(@Molgeim25,2,10,1,0,-34154,1), -- Chance on Recipe
(@Molgeim25,45038,8,1,0,1,1), -- Fragment of Val'anyr
(@Molgeim25,45087,75,1,0,1,1), -- Runed Orb
(@Molgeim25,47241,100,1,0,2,2), -- 2 Emblems of Triumph
(@Molgeim25,45506,100,1,0,1,1), -- Archivum Data Disc
-- Steelbreaker killed last
(@Steelbreaker25,1,100,1,0,-@Assembly25Ref,3), -- 3 items from reference loot
(@Steelbreaker25,2,10,1,0,-34154,1), -- Chance on Recipe
(@Steelbreaker25,45038,18,1,0,1,1), -- Fragment of Val'anyr
(@Steelbreaker25,45087,75,1,0,2,2), -- 2x Runed Orb
(@Steelbreaker25,47241,100,1,0,2,2), -- 2 Emblems of Triumph
(@Steelbreaker25,45506,100,1,0,1,1), -- Archivum Data Disc
(@Steelbreaker25,45241,0,1,1,1,1), -- Belt of Colossal Rage
(@Steelbreaker25,45242,0,1,1,1,1), -- Drape of Mortal Downfall
(@Steelbreaker25,45607,0,1,1,1,1), -- Fang of Oblivion
(@Steelbreaker25,45244,0,1,1,1,1), -- Greaves of Swift Vengeance
(@Steelbreaker25,45243,0,1,1,1,1), -- Sapphire Amulet of Renewal
(@Steelbreaker25,45245,0,1,1,1,1); -- Shoulderpads of the Intruder

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (@CacheLivingStone10,@CacheLivingStone25);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- KOLOGARN 10-man
(@CacheLivingStone10,1,100,1,0,-@Kologarn10Ref,2), -- 2 items from reference loot
(@CacheLivingStone10,47241,100,1,0,1,1), -- 1 Emblem of Triumph
-- KOLOGARN 25-Man
(@CacheLivingStone25,1,100,1,0,-@Kologarn25Ref,3), -- 3 items from reference loot
(@CacheLivingStone25,2,10,1,0,-34154,1), -- Chance on Recipe
(@CacheLivingStone25,45038,8,1,0,1,1), -- Fragment of Val'anyr
(@CacheLivingStone25,45087,50,1,0,1,1), -- Runed Orb
(@CacheLivingStone25,47241,100,1,0,1,2); -- 2 Emblems of Triumph

DELETE FROM `creature_loot_template` WHERE `entry` IN (@Auriaya10,@Auriaya25);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- AURIAYA 10-man
(@Auriaya10,1,100,1,0,-@Auriaya10Ref,2), -- 2 items from reference loot
(@Auriaya10,47241,100,1,0,1,1), -- 1 Emblem of Triumph
-- AURIAYA 25-man
(@Auriaya25,1,100,1,0,-@Auriaya25Ref,3), -- 3 items from reference loot
(@Auriaya25,2,10,1,0,-34154,1), -- Chance on Recipe
(@Auriaya25,45038,8,1,0,1,1), -- Fragment of Val'anyr
(@Auriaya25,45087,75,1,0,1,1), -- Runed Orb
(@Auriaya25,47241,100,1,0,1,2); -- 2 Emblems of Triumph
