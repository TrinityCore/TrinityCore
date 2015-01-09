-- -----------------------------------
-- --  Loot for The Siege of Ulduar --
-- -----------------------------------

-- Old Cleanups:
DELETE FROM `reference_loot_template` WHERE `entry` IN ( 34116,34117,34118,34119,34120,34121,34157,34158,34159,34160,34161,34162);
-- -------------------
-- -- Set Variables --
-- -------------------
-- 10 man mode npcids
SET @FlameLevi10 :=33113;
SET @IgnisFM10 :=33118;
SET @Razorscale10 :=33186;
SET @XT002_10 :=33293;
-- 25 man mode npcids (via procedure)
call `sp_get_npc_diffentry`(@FlameLevi10,1,@FlameLevi25);
call `sp_get_npc_diffentry`(@IgnisFM10,1,@IgnisFM25);
call `sp_get_npc_diffentry`(@Razorscale10,1,@Razorscale25);
call `sp_get_npc_diffentry`(@XT002_10,1,@XT002_25);

SET @Emblem := 47241;
SET @Orb := 45087;
-- -------------------------------------
-- -- Set Reference Loot Template ids --
-- -------------------------------------

SET @EmblemRef := 34349; -- First Free ID
SET @OrbRef := @EmblemRef+1;
SET @Flame10Ref := @EmblemRef+2;
SET @Flame25Ref := @EmblemRef+3;
SET @Ignis10Ref := @EmblemRef+4;
SET @Ignis25Ref := @EmblemRef+5;
SET @Razor10Ref := @EmblemRef+6;
SET @Razor25Ref := @EmblemRef+7;
SET @XT002_10Ref := @EmblemRef+8;
SET @XT002_25Ref := @EmblemRef+9;
-- Flame Levithian
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @EmblemRef AND @EmblemRef+9;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Emblem Ref
(@EmblemRef,47241,0,1,1,1,1), -- Emblem of Triumph 1x
-- OrbRef
(@OrbRef,45087,0,1,1,1,1), -- Runed Orb 1x
-- Flame Levithian 10man
(@Flame10Ref,45286,0,1,1,1,1), -- Pyrite Infuser
(@Flame10Ref,45287,0,1,1,1,1), -- Firesoul
(@Flame10Ref,45288,0,1,1,1,1), -- Firestrider Chestguard
(@Flame10Ref,45289,0,1,1,1,1), -- Lifespark Visage
(@Flame10Ref,45291,0,1,1,1,1), -- Combustion Bracers
(@Flame10Ref,45284,0,1,1,1,1), -- Kinetic Ripper
(@Flame10Ref,45282,0,1,1,1,1), -- Ironsoul
(@Flame10Ref,45285,0,1,1,1,1), -- Might of the Leviathan
(@Flame10Ref,45292,0,1,1,1,1), -- Energy Siphon
(@Flame10Ref,45283,0,1,1,1,1), -- Flamewatch Armguards
-- Flame Levithian 25man
(@Flame25Ref,45117,0,1,1,1,1), -- Constructors Handwraps
(@Flame25Ref,45119,0,1,1,1,1), -- Embrace of the Leviathan
(@Flame25Ref,45113,0,1,1,1,1), -- Glowing Ring of Reclamation
(@Flame25Ref,45115,0,1,1,1,1), -- Leviathan Fueling Manual
(@Flame25Ref,45108,0,1,1,1,1), -- Mechanists Bindings
(@Flame25Ref,45106,0,1,1,1,1), -- Strenght of the Automaton
(@Flame25Ref,45109,0,1,1,1,1), -- Gloves of the Fiery Behemoth
(@Flame25Ref,45114,0,1,1,1,1), -- Steamcallers Totem
(@Flame25Ref,45118,0,1,1,1,1), -- Steamworkers Goggles
(@Flame25Ref,45116,0,1,1,1,1), -- Freya's Choker of Warding
(@Flame25Ref,45111,0,1,1,1,1), -- Mimiron's Inferno Couplings
(@Flame25Ref,45112,0,1,1,1,1), -- The Leviathan's Coil
(@Flame25Ref,45107,0,1,1,1,1), -- Iron Riveted War Helm

-- Ignis the Furnace Master 10man
(@Ignis10Ref,45309,0,1,1,1,1), -- Rifle of the Platinum Guard
(@Ignis10Ref,45310,0,1,1,1,1), -- Gauntlets of the Iron Furnace
(@Ignis10Ref,45311,0,1,1,1,1), -- Relentless Edge
(@Ignis10Ref,45312,0,1,1,1,1), -- Gloves of Smoldering Touch
(@Ignis10Ref,45313,0,1,1,1,1), -- Furnace Stone
(@Ignis10Ref,45314,0,1,1,1,1), -- Igniter Rod
(@Ignis10Ref,45316,0,1,1,1,1), -- Armbraces of the Vibrant Flame
(@Ignis10Ref,45317,0,1,1,1,1), -- Shawl of the Caretaker
(@Ignis10Ref,45318,0,1,1,1,1), -- Drape of Fuming Anger
(@Ignis10Ref,45321,0,1,1,1,1), -- Pauldrons of Tempered Will
-- Ignis the Furnace Master 25man
(@Ignis25Ref,45157,0,1,1,1,1), -- Cindershard Ring
(@Ignis25Ref,45158,0,1,1,1,1), -- Heart of Iron
(@Ignis25Ref,45161,0,1,1,1,1), -- Girdle of Embers
(@Ignis25Ref,45162,0,1,1,1,1), -- Flamestalker Boots
(@Ignis25Ref,45164,0,1,1,1,1), -- Helm of the Furnace Master
(@Ignis25Ref,45165,0,1,1,1,1), -- Worldcarver
(@Ignis25Ref,45166,0,1,1,1,1), -- Charred Saronite Greaves
(@Ignis25Ref,45167,0,1,1,1,1), -- Lifeforge Breastplate
(@Ignis25Ref,45168,0,1,1,1,1), -- Pyrelight Circle
(@Ignis25Ref,45169,0,1,1,1,1), -- Totem of the Dancing Flame
(@Ignis25Ref,45170,0,1,1,1,1), -- Scepter of Creation
(@Ignis25Ref,45171,0,1,1,1,1), -- Intensity
(@Ignis25Ref,45185,0,1,1,1,1), -- Flamewrought Cinch
(@Ignis25Ref,45186,0,1,1,1,1), -- Soot-Covered Mantle
(@Ignis25Ref,45187,0,1,1,1,1), -- Wristguards of the Firetender

-- Razorscale 10man
(@Razor10Ref,45298,0,1,1,1,1), -- RazoRazorcale Talon
(@Razor10Ref,45299,0,1,1,1,1), -- Dragonsteel Faceplate
(@Razor10Ref,45301,0,1,1,1,1), -- BraceRazor of the Smothering Inferno
(@Razor10Ref,45302,0,1,1,1,1), -- Treads of the Invader
(@Razor10Ref,45303,0,1,1,1,1), -- Band of Draconic Guile
(@Razor10Ref,45304,0,1,1,1,1), -- Stormtempered Girdle
(@Razor10Ref,45305,0,1,1,1,1), -- Breastplate of the Afterlife
(@Razor10Ref,45306,0,1,1,1,1), -- Binding of the Dragon Matriarch
(@Razor10Ref,45307,0,1,1,1,1), -- Ironscale Leggings
(@Razor10Ref,45308,0,1,1,1,1), -- Eye of the Broodmother
-- Razorscale 25man
(@Razor25Ref,45137,0,1,1,1,1), -- Veranus' Bane
(@Razor25Ref,45138,0,1,1,1,1), -- Drape of the Drakerider
(@Razor25Ref,45139,0,1,1,1,1), -- Dragonslayer's Brace
(@Razor25Ref,45140,0,1,1,1,1), -- RazoRazorcale Shoulderguards
(@Razor25Ref,45141,0,1,1,1,1), -- Proto-hide Leggings
(@Razor25Ref,45142,0,1,1,1,1), -- RemoRazore
(@Razor25Ref,45143,0,1,1,1,1), -- Saronite Mesh Legguards
(@Razor25Ref,45144,0,1,1,1,1), -- Sigil of Deflection
(@Razor25Ref,45146,0,1,1,1,1), -- Shackles of the Odalisque
(@Razor25Ref,45147,0,1,1,1,1), -- Guiding Star
(@Razor25Ref,45148,0,1,1,1,1), -- Living Flame
(@Razor25Ref,45149,0,1,1,1,1), -- BraceRazor of the Broodmother
(@Razor25Ref,45150,0,1,1,1,1), -- Collar of the Wyrmhunter
(@Razor25Ref,45151,0,1,1,1,1), -- Belt of the Fallen Wyrm
(@Razor25Ref,45510,0,1,1,1,1), -- Libram of Discord

-- XT-002 Deconstructor 10man
(@XT002_10Ref,45675,0,1,1,1,1), -- Power Enchancing Loop
(@XT002_10Ref,45676,0,1,1,1,1), -- Chestplate of Vicious Potency
(@XT002_10Ref,45677,0,1,1,1,1), -- Treacherous shoulderpads
(@XT002_10Ref,45679,0,1,1,1,1), -- Gloves of Taut grip
(@XT002_10Ref,45680,0,1,1,1,1), -- Armbands of the construct
(@XT002_10Ref,45682,0,1,1,1,1), -- Pulsing spellshield
(@XT002_10Ref,45685,0,1,1,1,1), -- Plasma Foil
(@XT002_10Ref,45686,0,1,1,1,1), -- Vest of the glowing Cresent
(@XT002_10Ref,45687,0,1,1,1,1), -- Helm of Veiled Energies
(@XT002_10Ref,45694,0,1,1,1,1), -- Conductive cord
(@XT002_10Ref,45867,0,2,2,1,1), -- Breasktplate of the Stoneshaper
(@XT002_10Ref,45868,0,2,2,1,1), -- Aesir's Edge
(@XT002_10Ref,45869,0,2,2,1,1), -- Fluxing Energy Coils
(@XT002_10Ref,45870,0,2,2,1,1), -- Magnetized Projectile Emitter
(@XT002_10Ref,45871,0,2,2,1,1), -- Seal of Ulduar
-- XT-002 Deconstructor 25man
(@XT002_25Ref,45254,0,1,1,1,1), -- Sigil of the Vengeful Heart
(@XT002_25Ref,45251,0,1,1,1,1), -- Shoulderplates of the Deconstructor
(@XT002_25Ref,45247,0,1,1,1,1), -- Signet of the Earthshaker
(@XT002_25Ref,45256,0,1,1,1,1), -- Twisted Visage
(@XT002_25Ref,45250,0,1,1,1,1), -- Crazed Construct Ring
(@XT002_25Ref,45257,0,1,1,1,1), -- Quartz Crystal Wand
(@XT002_25Ref,45260,0,1,1,1,1), -- Boots of Hasty Revival
(@XT002_25Ref,45252,0,1,1,1,1), -- Horologist's Wristguards
(@XT002_25Ref,45253,0,1,1,1,1), -- Mantle of Wavering Calm
(@XT002_25Ref,45258,0,1,1,1,1), -- Sandals of Rash Temperament
(@XT002_25Ref,45249,0,1,1,1,1), -- Brass-lined Boots
(@XT002_25Ref,45246,0,1,1,1,1), -- Golem-Shard Sticker
(@XT002_25Ref,45248,0,1,1,1,1), -- Clockwork Legplates
(@XT002_25Ref,45259,0,1,1,1,1), -- Quartz-studded Harness
(@XT002_25Ref,45255,0,1,1,1,1); -- Thunderfall Totem
-- -----------------------------------------------------------------------------------------------
-- -- END OF REFERENCES -- -- END OF REFERENCES -- -- END OF REFERENCES -- -- END OF REFERENCES --
-- -- END OF REFERENCES -- -- END OF REFERENCES -- -- END OF REFERENCES -- -- END OF REFERENCES --
-- -- END OF REFERENCES -- -- END OF REFERENCES -- -- END OF REFERENCES -- -- END OF REFERENCES --
-- -----------------------------------------------------------------------------------------------

-- Flame Levithian 10Man:
-- NORMAL MODE : 2x [Normal Loot Item] + 1x [Emblem of Valor]
-- ONE TOWER : 2x [Normal Loot Item] + 2x [Emblem of Conquest] + CHANCE TO [Recipe]
-- TWO TOWERS : 2x [Normal Loot Item] + 2x [Emblem of Conquest] + 1x [Runed Orb] + CHANCE TO [Recipe]
-- THREE TOWERS: 2x [Normal Loot Item] + 3x [Emblem of Conquest] + 1x [Runed Orb] + CHANCE TO [Recipe] + 1x [Recipe]
-- FOUR TOWERS : 2x [Normal Loot Item] + 3x [Emblem of Conquest] + 1x [Runed Orb] + CHANCE TO [Recipe] + 1x [Recipe] + 1x [Hard Loot Item]
-- Flame Levithian 25 man
-- NORMAL MODE : 3x [Normal Loot Item] + 1x [Emblem of Conquest] + CHANCE TO [Runed Orb] + CHANCE TO [Recipe]
-- ONE TOWER : 3x [Normal Loot Item] + 2x [Emblem of Conquest] + CHANCE TO [Runed Orb] + CHANCE TO [Recipe]
-- TWO TOWERS : 3x [Normal Loot Item] + 2x [Emblem of Conquest] + CHANCE TO [Runed Orb] + CHANCE TO [Recipe] + 2x [Runed Orb]
-- THREE TOWERS: 3x [Normal Loot Item] + 3x [Emblem of Conquest] + CHANCE TO [Runed Orb] + CHANCE TO [Recipe] + 2x [Runed Orb] + [Recipe]
-- FOUR TOWERS : 3x [Normal Loot Item] + 3x [Emblem of Conquest] + CHANCE TO [Runed Orb] + CHANCE TO [Recipe] + 2x [Runed Orb] + [Recipe] + 1x [Hard Loot Item]

DELETE FROM `creature_loot_template` WHERE `entry` IN (@FlameLevi10,@FlameLevi25,@IgnisFM10,@IgnisFM25,@Razorscale10,@Razorscale25,@XT002_10,@XT002_25);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- ---------------------------
-- -- Flame Levithian 10man --
-- ---------------------------
(@FlameLevi10,1,100,1,0,-@EmblemRef,1), -- 1x emblem
(@FlameLevi10,2,100,1,0,-@Flame10Ref,2), -- 2 from 10man reference
-- Hardmode: 1 tower left
(@FlameLevi10,3,100,2,0,-@EmblemRef,2), -- 2x emblem
(@FlameLevi10,4,100,2,0,-@Flame10Ref,2), -- 2 from 10man reference
-- Hardmode: 2 towers left
(@FlameLevi10,5,100,4,0,-@EmblemRef,2), -- 2x emblem
(@FlameLevi10,6,100,4,0,-@Flame10Ref,2), -- 2 from 10man reference
-- Hardmode: 3 towers left
(@FlameLevi10,7,100,8,0,-@EmblemRef,3), -- 3x emblem
(@FlameLevi10,8,100,8,0,-@Flame10Ref,2), -- 2 from 10man reference
-- Hardmode: 4 towers left
(@FlameLevi10,9,100,16,0,-@EmblemRef,3), -- 3x emblem
(@FlameLevi10,10,100,16,0,-@Flame10Ref,2), -- 2 from 10man reference
-- one from hardmodeloot:
(@FlameLevi10,45296,0,16,1,1,1), -- Twirling Blades
(@FlameLevi10,45293,0,16,1,1,1), -- Handguards of Potent Cures
(@FlameLevi10,45295,0,16,1,1,1), -- Gilded Steel Legplates
(@FlameLevi10,45300,0,16,1,1,1), -- Mantle of Fiery Vengeance
(@FlameLevi10,45297,0,16,1,1,1), -- Shimmering Seal
-- Shared Loot over the modes (masked)
-- Non-Normal (Modes 2|4|8|16)
(@FlameLevi10,11,5,30,0,-34154,1), -- 1 from recepies (chanced)
-- More then 1 tower up (Modes 4|8|16)
(@FlameLevi10,@Orb,100,28,0,1,3), -- Runed Orb (1-3)
-- More then 2 towers up (Modes 8|16)
(@FlameLevi10,12,100,24,0,-34154,1), -- 1 from recepies
-- ---------------------------
-- -- Flame Levithian 25man --
-- ---------------------------
(@FlameLevi25,1,100,1,0,-@EmblemRef,1), -- 1x emblem
(@FlameLevi25,2,100,1,0,-@Flame25Ref,3), -- 3 from 25man reference
-- Hardmode: 1 tower left
(@FlameLevi25,3,100,2,0,-@EmblemRef,2), -- 2x emblem
(@FlameLevi25,4,100,2,0,-@Flame25Ref,3), -- 3 from 25man reference
-- Hardmode: 2 towers left
(@FlameLevi25,5,100,4,0,-@EmblemRef,2), -- 2x emblem
(@FlameLevi25,6,100,4,0,-@Flame25Ref,3), -- 3 from 25man reference
-- Hardmode: 3 towers left
(@FlameLevi25,7,100,8,0,-@EmblemRef,3), -- 3x emblem
(@FlameLevi25,8,100,8,0,-@Flame25Ref,3), -- 3 from 25man reference
-- Hardmode: 4 towers left
(@FlameLevi25,9,100,16,0,-@EmblemRef,3), -- 3x emblem
(@FlameLevi25,10,100,16,0,-@Flame25Ref,3), -- 3 from 25man reference
-- one from hardmodeloot:
(@FlameLevi25,45132,0,16,1,1,1), -- Golden Saronite Dragon
(@FlameLevi25,45133,0,16,1,1,1), -- Pendant of Fiery Havoc
(@FlameLevi25,45134,0,16,1,1,1), -- Plated Leggings of Ruination
(@FlameLevi25,45135,0,16,1,1,1), -- Boots of Fiery Resolution
(@FlameLevi25,45136,0,16,1,1,1), -- Shoulderpads of Dormant Energies
(@FlameLevi25,45086,0,16,1,1,1), -- Rising Sun
(@FlameLevi25,45110,0,16,1,1,1), -- Titanguard
-- Shared Loot over the modes (masked)
-- All Modes (1|2|4|8|16):
(@FlameLevi25,11,5,31,0,-@OrbRef,1), -- Runed Orb (1x Chanced)
(@FlameLevi25,45038,8,1,0,1,1), -- Fragment of Val'anyr (quest only!?)
(@FlameLevi25,12,5,31,0,-34154,1), -- 1 from recepies (chanced)
-- More then 1 tower up (Modes 4|8|16)
(@FlameLevi25,13,100,28,0,-@OrbRef,2), -- Runed Orb (2x garanteed)
-- More then 2 towers up (Modes 8|16)
(@FlameLevi25,14,100,24,0,-34154,1), -- 1 from recepies
-- ------------------------------
-- -- IGNIS THE FURNACE MASTER --
-- ------------------------------
-- Ignis the Furnace Master 10man
(@IgnisFM10,1,100,1,0,-@Ignis10Ref,2), -- 2 items from Ref loot
(@IgnisFM10,@Emblem,100,1,0,1,1), -- 1 Emblem
-- Ignis the Furnace Master 25man
(@IgnisFM25,1,100,1,0,-@Ignis25Ref,3), -- 3 items from Ref loot
(@IgnisFM25,@Emblem,100,1,0,2,2), -- 2 Emblem
(@IgnisFM25,3,10,1,0,-34154,1), -- 1 from recepies
(@IgnisFM25,45038,8,1,0,1,1), -- Fragment of Val'anyr (quest only!?)
(@IgnisFM25,45087,75,1,0,1,1), -- Runed Orb
-- ----------------
-- -- RAZORSCALE --
-- ----------------
-- Razorscale 10man
(@Razorscale10,1,100,1,0,-@Razor10Ref ,2), -- 2 items from ref loot
(@Razorscale10,@Emblem,100,1,0,1,1), -- Emblem of Triumph
-- Razorscale 25man
(@Razorscale25,1,100,1,0,-@Razor25Ref,3), -- 3 items from Ref loot
(@Razorscale25,@Emblem,100,1,0,1,2), -- 2 Emblems
(@Razorscale25,2,10,1,0,-34154,1), -- 1 from recepies
(@Razorscale25,45038,8,1,0,1,1), -- Fragment of Val'anyr (quest only!?)
(@Razorscale25,45087,75,1,0,1,1), -- Runed Orb
-- -------------------------
-- -- XT002 DECONSTRUCTOR --
-- -------------------------
-- X002 Deconstructor 10man (and hardmode)
(@XT002_10,1,100,3,0,-@XT002_10Ref,2), -- 2items from Ref loot
(@XT002_10,@Emblem,100,3,0,1,1), -- 1x Emblem
-- Hard mode 10man only:
(@XT002_10,45442,0,2,1,1,1), -- Sorthalis,Hammer of the Watchers
(@XT002_10,45443,0,2,1,1,1), -- Charm of Meticulous Timing
(@XT002_10,45444,0,2,1,1,1), -- Gloves of the Steady Hand
(@XT002_10,45445,0,2,1,1,1), -- Breastplate of the Devoted
(@XT002_10,45446,0,2,1,1,1), -- Grasps of Reason
-- X002 Deconstructor 25man (and hardmode)
(@XT002_25,1,100,3,0,-@XT002_25Ref,3), -- 3 items from Ref loot
(@XT002_25,2,10,3,0,-34154,1), -- 1 from recepies
(@XT002_25,45038,8,3,0,1,1), -- Fragment of Val'anyr (quest only!?)
(@XT002_25,45087,75,3,0,1,1), -- Runed Orb
(@XT002_25,47241,100,3,0,1,2), -- 2 Emblem of Triumph
-- Hard Mode 25man only:
(@XT002_25,45442,0,2,1,1,1), -- Sorthalis,Hammer of the Watchers
(@XT002_25,45443,0,2,1,1,1), -- Charm of Meticulous Timing
(@XT002_25,45444,0,2,1,1,1), -- Gloves of the Steady Hand
(@XT002_25,45445,0,2,1,1,1), -- Breastplate of the Devoted
(@XT002_25,45446,0,2,1,1,1); -- Grasps of Reason
