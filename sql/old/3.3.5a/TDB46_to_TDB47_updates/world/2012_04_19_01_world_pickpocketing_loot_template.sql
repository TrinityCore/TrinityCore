-- Fix to add pickpocketing loot for humoniods in borean tundra
SET @GORLOCREF := 25100;
SET @BERYLREF := @GORLOCREF+1;
SET @BLOODREF := @GORLOCREF+2;
SET @CHIEFREF := @GORLOCREF+3;
SET @CULTREF := @GORLOCREF+4;
SET @KVALDIRREF := @GORLOCREF+5;
SET @CLAXREF := @GORLOCREF+6;
SET @MAGMOTHREF := @GORLOCREF+7;
-- Create reference templates
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @GORLOCREF AND @GORLOCREF+7;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@GORLOCREF,29576,57,1,0,1,1), -- Shark Bait
(@GORLOCREF,29569,30,1,0,1,1), -- Strong Junkbox
(@GORLOCREF,27858,8,1,0,1,1), -- Sunspring Carp
(@GORLOCREF,22829,3,1,0,1,1), -- Super Healing Potion
(@GORLOCREF,23436,0.5,1,0,1,1), -- Living Ruby
(@GORLOCREF,23437,0.5,1,0,1,1), -- Talasite
(@GORLOCREF,23440,0.5,1,0,1,1), -- Dawnstone
(@GORLOCREF,23438,0.5,1,0,1,1), -- Star of Elune
(@GORLOCREF,23439,0.5,1,0,1,1), -- Noble Topaz
-- --------------------------------------------------
(@BERYLREF,37467,32.5,1,0,1,1), -- A Steamy Romance Novel: Forbidden Love
(@BERYLREF,43575,31,1,0,1,1), -- Reinforced Junkbox
(@BERYLREF,38261,10,1,0,1,1), -- Bent House Key
(@BERYLREF,29448,7,1,0,1,1), -- Mag'har Mild Cheese
(@BERYLREF,29450,7,1,0,1,1), -- Telaari Grapes
(@BERYLREF,33447,6,1,0,1,1), -- Runic Healing Potion
(@BERYLREF,33449,6,1,0,1,1), -- Crusty Flatbread
(@BERYLREF,36863,0.5,1,0,1,1), -- Decahedral Dwarven Dice
-- --------------------------------------------------
(@BLOODREF,29572,37,1,0,1,1), -- Aboriginal Carvings
(@BLOODREF,29569,33,1,0,1,1), -- Strong Junkbox
(@BLOODREF,8952,20,1,0,1,1), -- Roasted Quail
(@BLOODREF,22829,8,1,0,1,1), -- Super Healing Potion
(@BLOODREF,23438,0.5,1,0,1,1), -- Star of Elune
(@BLOODREF,23436,0.5,1,0,1,1), -- Living Ruby
(@BLOODREF,23441,0.5,1,0,1,1), -- Nightseye
(@BLOODREF,23437,0.5,1,0,1,1), -- Talasite
(@BLOODREF,23440,0.5,1,0,1,1), -- Dawnstone
-- --------------------------------------------------
(@CHIEFREF,29569,50,1,0,1,1), -- Strong Junkbox
(@CHIEFREF,27858,20,1,0,1,1), -- Sunspring Carp
(@CHIEFREF,29576,20,1,0,1,1), -- Shark Bait
(@CHIEFREF,22829,10,1,0,1,1), -- Super Healing Potion
-- --------------------------------------------------
(@CULTREF,29569,40,1,0,1,1), -- Strong Junkbox
(@CULTREF,29571,37,1,0,1,1), -- A Steamy Romance Novel
(@CULTREF,30458,8,1,0,1,1), -- Stromgarde Muenster
(@CULTREF,27855,7,1,0,1,1), -- Mag'har Grainbread
(@CULTREF,27856,6,1,0,1,1), -- Skethyl Berries
(@CULTREF,22829,2,1,0,1,1), -- Super Healing Potion
(@CULTREF,36863,0.5,1,0,1,1), -- Decahedral Dwarven Dice
-- --------------------------------------------------
(@KVALDIRREF,29569,39,1,0,1,1), -- Strong Junkbox
(@KVALDIRREF,29570,28,1,0,1,1), -- A Gnome Effigy
(@KVALDIRREF,27855,12,1,0,1,1), -- Mag'har Grainbread
(@KVALDIRREF,27854,12,1,0,1,1), -- Smoked Talbuk Venison
(@KVALDIRREF,22829,7,1,0,1,1), -- Super Healing Potion
(@KVALDIRREF,23436,0.5,1,0,1,1), -- Living Ruby
(@KVALDIRREF,23441,0.5,1,0,1,1), -- Nightseye
(@KVALDIRREF,23440,0.5,1,0,1,1), -- Dawnstone
(@KVALDIRREF,23439,0.5,1,0,1,1), -- Noble Topaz
(@KVALDIRREF,23437,0.5,1,0,1,1), -- Talasite
-- --------------------------------------------------
(@CLAXREF,43575,28,1,0,1,1), -- Reinforced Junkbox
(@CLAXREF,38273,26,1,0,1,1), -- Brain Coral
(@CLAXREF,38274,23,1,0,1,1), -- Large Snail Shell
(@CLAXREF,37452,17,1,0,1,1), -- Fatty Bluefin
(@CLAXREF,33447,6,1,0,1,1), -- Runic Healing Potion
-- --------------------------------------------------
(@MAGMOTHREF,38260,33,1,0,1,1), -- Empty Tobacco Pouch
(@MAGMOTHREF,38261,21,1,0,1,1), -- Bent House Key
(@MAGMOTHREF,33449,16,1,0,1,1), -- Crusty Flatbread
(@MAGMOTHREF,43575,16,1,0,1,1), -- Reinforced Junkbox
(@MAGMOTHREF,33454,9,1,0,1,1), -- Salted Venison
(@MAGMOTHREF,33447,5,1,0,1,1), -- Runic Healing Potion
(@MAGMOTHREF,36862,1,1,0,1,1); -- Worn Troll Dice
-- -------------------
-- -- NPC Variables --
-- -------------------
SET @NPC := 25686;
SET @NPC1 := 25700;
SET @NPC2 := 25687;
SET @NPC3 := 25685;
SET @NPC4 := 25449;
SET @NPC5 := 25316;
SET @NPC6 := 25353;
SET @NPC7 := 25719;
SET @NPC8 := 25804;
SET @NPC9 := 25392;
SET @NPC10 := 25651;
SET @NPC11 := 25836;
SET @NPC12 := 25979;
SET @NPC13 := 25806;
SET @NPC14 := 25720;
SET @NPC15 := 25803;
SET @NPC16 := 25880;
SET @NPC17 := 25618;
SET @NPC18 := 25839;
SET @NPC19 := 25470;
SET @NPC20 := 24567;
SET @NPC21 := 25467;
SET @NPC22 := 25468;
SET @NPC23 := 25501;
SET @NPC24 := 25726;
SET @NPC25 := 25701;
SET @NPC26 := 25725;
SET @NPC27 := 25699;
SET @NPC28 := 24576;
SET @NPC29 := 25605;
SET @NPC30 := 25609;
SET @NPC31 := 25378;
SET @NPC32 := 25843;
SET @NPC33 := 25496;
SET @NPC34 := 25479;
SET @NPC35 := 25760;
SET @NPC36 := 26266;
SET @NPC37 := 26451;
SET @NPC38 := 25521;
SET @NPC39 := 25613;
SET @NPC40 := 25522;
SET @NPC41 := 25520;
SET @NPC42 := 25209;
SET @NPC43 := 25210;
SET @NPC44 := 25216;
SET @NPC45 := 25215;
SET @NPC46 := 25217;
SET @NPC47 := 25789;
SET @NPC48 := 24469;
SET @NPC49 := 25432;
SET @NPC50 := 25433;
SET @NPC51 := 25615;
SET @NPC52 := 25523;
-- ----------------------
-- -- Assign the loots --
-- ----------------------
UPDATE `creature_template` SET `pickpocketloot`=`entry` WHERE `entry` IN (@NPC,@NPC1,@NPC2,@NPC3,@NPC4,@NPC5,@NPC6,@NPC7,@NPC8,@NPC9,@NPC10,@NPC11,@NPC12,@NPC13,@NPC14,@NPC15,@NPC16,@NPC17,@NPC18,@NPC19,@NPC20,@NPC21,@NPC22,@NPC23,@NPC24,@NPC25,@NPC26,@NPC27,@NPC28,@NPC29,@NPC30,@NPC31,@NPC32,@NPC33,@NPC34,@NPC35,@NPC36,@NPC37,@NPC38,@NPC39,@NPC40,@NPC41,@NPC42,@NPC43,@NPC44,@NPC45,@NPC46,@NPC47,@NPC48,@NPC49,@NPC50,@NPC51,@NPC52);
DELETE FROM `pickpocketing_loot_template` WHERE `entry` IN (@NPC,@NPC1,@NPC2,@NPC3,@NPC4,@NPC5,@NPC6,@NPC7,@NPC8,@NPC9,@NPC10,@NPC11,@NPC12,@NPC13,@NPC14,@NPC15,@NPC16,@NPC17,@NPC18,@NPC19,@NPC20,@NPC21,@NPC22,@NPC23,@NPC24,@NPC25,@NPC26,@NPC27,@NPC28,@NPC29,@NPC30,@NPC31,@NPC32,@NPC33,@NPC34,@NPC35,@NPC36,@NPC37,@NPC38,@NPC39,@NPC40,@NPC41,@NPC42,@NPC43,@NPC44,@NPC45,@NPC46,@NPC47,@NPC48,@NPC49,@NPC50,@NPC51,@NPC52);
INSERT INTO `pickpocketing_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- -----------------------------------------------------------------------------------------------
(@NPC,1,100,1,0,-@GORLOCREF,1), -- Gorloc ref loot template on Gorloc Gibberer
(@NPC1,1,100,1,0,-@GORLOCREF,1), -- Gorloc ref loot template on Gorloc Hunter
(@NPC2,1,100,1,0,-@GORLOCREF,1), -- Gorloc ref loot template on Gorloc Steam Belcher
(@NPC3,1,100,1,0,-@GORLOCREF,1), -- Gorloc ref loot template on Gorloc Waddler
-- -----------------------------------------------------------------------------------------------
(@NPC4,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Beryl Reclaimer
(@NPC5,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Beryl Sorcerer
(@NPC6,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Beryl Treasure Hunter
(@NPC7,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Coldarra Spellbinder
(@NPC8,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Harold Lane <The Fur Baron>
(@NPC9,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on High Priest Andorath
(@NPC10,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Cultist Necrolyte
(@NPC11,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Loot Crazed Diver
(@NPC12,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Loot Crazed Hunter
(@NPC13,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Loot Crazed Poacher
(@NPC14,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Inquisitor Caleras
(@NPC15,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Karen "I Don't Caribou" the Culler
(@NPC16,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Minion of Kaw
(@NPC17,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Varidus the Flenser
(@NPC18,1,100,1,0,-@BERYLREF,1), -- Beryl ref loot template on Northsea Mercenary
-- -----------------------------------------------------------------------------------------------
(@NPC19,1,100,1,0,-@BLOODREF,1), -- Bloodspore ref loot template on Bloodspore Firestarter
(@NPC20,1,100,1,0,-@BLOODREF,1), -- Bloodspore ref loot template on Den Vermin
(@NPC21,1,100,1,0,-@BLOODREF,1), -- Bloodspore ref loot template on Bloodspore Harvester
(@NPC22,1,100,1,0,-@BLOODREF,1), -- Bloodspore ref loot template on Bloodspore Roaster
(@NPC23,1,100,1,0,-@BLOODREF,1), -- Bloodspore ref loot template on Gammoth Tender
-- -----------------------------------------------------------------------------------------------
(@NPC24,1,100,1,0,-@CHIEFREF,1), -- Chieftian ref loot template on Chieftain Burblegobble
(@NPC25,1,100,1,0,-@CHIEFREF,1), -- Chieftian ref loot template on Gorloc Dredger
(@NPC26,1,100,1,0,-@CHIEFREF,1), -- Chieftian ref loot template on Chieftain GurgleBoggle
(@NPC27,1,100,1,0,-@CHIEFREF,1), -- Chieftian ref loot template on Gorloc Mud Splasher
(@NPC28,1,100,1,0,-@CHIEFREF,1), -- Chieftian ref loot template on Riplash Myrmidon
-- -----------------------------------------------------------------------------------------------
(@NPC29,1,100,1,0,-@CULTREF,1), -- Cultist ref loot template on Clandestine Cultist <Cult of the Damned>
(@NPC30,1,100,1,0,-@CULTREF,1), -- Cultist ref loot template on En'kilah Necrolord <Cult of the Damned>
(@NPC31,1,100,1,0,-@CULTREF,1), -- Cultist ref loot template on En'kilah Necromancer <Cult of the Damned>
(@NPC32,1,100,1,0,-@CULTREF,1), -- Cultist ref loot template on Northsea Thug
-- -----------------------------------------------------------------------------------------------
(@NPC33,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Kvaldir Mist Lord
(@NPC34,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Kvaldir Mistweaver
(@NPC35,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Kvaldir Raider
(@NPC36,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Heigarr the Horrible
(@NPC37,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Ragnar Drakkarlund
(@NPC37,35774,-100,1,0,1,1), -- Trident of Naz'jan on Ragnar Drakkarlund
(@NPC38,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Skadir Longboatsman
(@NPC39,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Skadir Mistweaver
(@NPC40,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Skadir Raider
(@NPC41,1,100,1,0,-@KVALDIRREF,1), -- Kvaldir ref loot template on Skadir Runecaster
-- -----------------------------------------------------------------------------------------------
(@NPC42,1,100,1,0,-@CLAXREF,1), -- Clax ref loot template on Claximus
(@NPC43,1,100,1,0,-@CLAXREF,1), -- Clax ref loot template on Keymaster Urmgrgl
(@NPC44,1,100,1,0,-@CLAXREF,1), -- Clax ref loot template on Winterfin Oracle
(@NPC45,1,100,1,0,-@CLAXREF,1), -- Clax ref loot template on Winterfin Shorestriker
(@NPC46,1,100,1,0,-@CLAXREF,1), -- Clax ref loot template on Winterfin Warrior
-- -----------------------------------------------------------------------------------------------
(@NPC47,1,100,1,0,-@MAGMOTHREF,1), -- Magmoth2 ref loot template on Gammothra the Tormentor
(@NPC48,1,100,1,0,-@MAGMOTHREF,1), -- Magmoth ref loot template on Magnataur Huntress <Mate of Gammothra>
(@NPC49,1,100,1,0,-@MAGMOTHREF,1), -- Magmoth ref loot template on Mate of Magmothregar
(@NPC50,1,100,1,0,-@MAGMOTHREF,1), -- Magmoth ref loot template on Offspring of Magmothregar
(@NPC51,1,100,1,0,-@MAGMOTHREF,1), -- Magmoth ref loot template on Plagued Magnataur
(@NPC52,1,100,1,0,-@MAGMOTHREF,1); -- Magmoth ref loot template on Skadir Mariner
