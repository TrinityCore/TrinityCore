-- DB/Profession: Fixed Jewelcrafting teachers and their spells
SET @JewelcraftingLowlevel := 201024;
SET @JewelcraftingMedlevel := 201025;
SET @JewelcraftingHighlevel := 201026;

SET @JewelcraftingSkill := 755;

DELETE FROM `npc_trainer` WHERE `ID` IN
(@JewelcraftingHighlevel,@JewelcraftingMedlevel,@JewelcraftingLowlevel,
52645,15501,26997,86010,85916,19778,26982,19063,52586,33614,18751,
19775,46675,65098,52657,52587,33680,33590,26915,18774,44582,28701);

INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES

-- Jewelcrafting-Highlevel --
(@JewelcraftingHighlevel,25229,10,@JewelcraftingSkill,0,5), -- Spell Jewelcrafting Rank 1
(@JewelcraftingHighlevel,25230,500,@JewelcraftingSkill,50,0), -- Spell Jewelcrafting Rank 2
(@JewelcraftingHighlevel,28894,5000,@JewelcraftingSkill,125,0), -- Spell Jewelcrafting Rank 3
(@JewelcraftingHighlevel,28895,50000,@JewelcraftingSkill,200,0), -- Spell Jewelcrafting Rank 4
(@JewelcraftingHighlevel,28897,100000,@JewelcraftingSkill,275,0), -- Spell Jewelcrafting Rank 5
(@JewelcraftingHighlevel,51311,350000,@JewelcraftingSkill,350,0), -- Spell Jewelcrafting Rank 6
(@JewelcraftingHighlevel,73318,500000,@JewelcraftingSkill,425,0), -- Spell Jewelcrafting Rank 7
(@JewelcraftingHighlevel,110420,600000,@JewelcraftingSkill,500,0), -- Spell Jewelcrafting Rank 8
(@JewelcraftingHighlevel,31252,100,@JewelcraftingSkill,20,0), -- Spell Prospecting
(@JewelcraftingHighlevel,63743,3000,@JewelcraftingSkill,200,0), -- Spell Amulet of Truesight
(@JewelcraftingHighlevel,26874,5000,@JewelcraftingSkill,210,0), -- Spell Aquamarine Signet
(@JewelcraftingHighlevel,26916,20000,@JewelcraftingSkill,310,0), -- Spell Band of Natural Fire
(@JewelcraftingHighlevel,56196,80000,@JewelcraftingSkill,380,0), -- Spell Blood Sun Necklace
(@JewelcraftingHighlevel,47280,30000,@JewelcraftingSkill,350,0), -- Spell Brilliant Glass
(@JewelcraftingHighlevel,41414,10000,@JewelcraftingSkill,325,0), -- Spell Brilliant Pearl Band
(@JewelcraftingHighlevel,37818,500,@JewelcraftingSkill,65,0), -- Spell Bronze Band of Force
(@JewelcraftingHighlevel,41418,30000,@JewelcraftingSkill,365,0), -- Spell Crown of the Sea Witch
(@JewelcraftingHighlevel,56197,100000,@JewelcraftingSkill,420,0), -- Spell Dream Signet
(@JewelcraftingHighlevel,58143,30000,@JewelcraftingSkill,350,0), -- Spell Earthshadow Ring
(@JewelcraftingHighlevel,64725,100000,@JewelcraftingSkill,420,0), -- Spell Emerald Choker
(@JewelcraftingHighlevel,56531,100000,@JewelcraftingSkill,390,0), -- Spell Enchanted Tear
(@JewelcraftingHighlevel,56203,150000,@JewelcraftingSkill,400,0), -- Spell Figurine - Emerald Boar
(@JewelcraftingHighlevel,59759,150000,@JewelcraftingSkill,400,0), -- Spell Figurine - Monarch Crab
(@JewelcraftingHighlevel,56199,150000,@JewelcraftingSkill,400,0), -- Spell Figurine - Ruby Hare
(@JewelcraftingHighlevel,56202,150000,@JewelcraftingSkill,400,0), -- Spell Figurine - Saphire Owl
(@JewelcraftingHighlevel,56201,150000,@JewelcraftingSkill,400,0), -- Spell Figurine - Twilight Serpent
(@JewelcraftingHighlevel,73478,30000,@JewelcraftingSkill,500,0), -- Spell Fire Prism
(@JewelcraftingHighlevel,34955,2500,@JewelcraftingSkill,180,0), -- Spell Golden Ring of Power
(@JewelcraftingHighlevel,25305,1000,@JewelcraftingSkill,90,0), -- Spell Heavy Silver Ring
(@JewelcraftingHighlevel,62242,150000,@JewelcraftingSkill,425,0), -- Spell Icy Prism
(@JewelcraftingHighlevel,131691,40000,@JewelcraftingSkill,545,0), -- Spell Imperial Amethyst
(@JewelcraftingHighlevel,56195,120000,@JewelcraftingSkill,380,0), -- Spell Jade Dagger Pendant
(@JewelcraftingHighlevel,58144,30000,@JewelcraftingSkill,350,0), -- Spell Jade Ring of Slaying
(@JewelcraftingHighlevel,26911,15000,@JewelcraftingSkill,290,0), -- Spell Living Emerald Pendant
(@JewelcraftingHighlevel,38068,20000,@JewelcraftingSkill,325,0), -- Spell Mercurial Adamantite
(@JewelcraftingHighlevel,25321,1500,@JewelcraftingSkill,120,0), -- Spell Moonsoul Crown
(@JewelcraftingHighlevel,40514,8500,@JewelcraftingSkill,340,0), -- Spell Necklace of the Deep
(@JewelcraftingHighlevel,55402,120000,@JewelcraftingSkill,420,0), -- Spell Persistent Earthsiege Diamond
(@JewelcraftingHighlevel,55399,120000,@JewelcraftingSkill,420,0), -- Spell Powerful Earthsiege Diamond
(@JewelcraftingHighlevel,131686,40000,@JewelcraftingSkill,550,0), -- Spell Primordial Ruby
(@JewelcraftingHighlevel,41429,10000,@JewelcraftingSkill,350,0), -- Spell Purified Shadow Pearl
(@JewelcraftingHighlevel,131593,40000,@JewelcraftingSkill,525,0), -- Spell River's Heart
(@JewelcraftingHighlevel,64727,100000,@JewelcraftingSkill,420,0), -- Spell Runed Mana Band
(@JewelcraftingHighlevel,26903,10000,@JewelcraftingSkill,275,0), -- Spell Sapphire Signet
(@JewelcraftingHighlevel,64728,100000,@JewelcraftingSkill,420,0), -- Spell Scarlet Signet
(@JewelcraftingHighlevel,131759,40000,@JewelcraftingSkill,550,0), -- Spell Secrets of the Stone
(@JewelcraftingHighlevel,64726,100000,@JewelcraftingSkill,420,0), -- Spell Sky Sapphire Amulet
(@JewelcraftingHighlevel,131695,40000,@JewelcraftingSkill,525,0), -- Spell Sun's Radiance
(@JewelcraftingHighlevel,55394,120000,@JewelcraftingSkill,420,0), -- Spell Swift Skyflare Diamond
(@JewelcraftingHighlevel,41415,10000,@JewelcraftingSkill,330,0), -- Spell The Black Pearl
(@JewelcraftingHighlevel,73621,30000,@JewelcraftingSkill,490,0), -- Spell The Perforator
(@JewelcraftingHighlevel,55386,120000,@JewelcraftingSkill,420,0), -- Spell Tireless Skyflare Diamond
(@JewelcraftingHighlevel,34959,3000,@JewelcraftingSkill,200,0), -- Spell Truesilver Commander's Ring
(@JewelcraftingHighlevel,131690,40000,@JewelcraftingSkill,535,0), -- Spell Vermillion Onyx
(@JewelcraftingHighlevel,99540,40000,@JewelcraftingSkill,510,0), -- Spell Vicious Amberjewel Band
(@JewelcraftingHighlevel,99543,45000,@JewelcraftingSkill,520,0), -- Spell Vicious Amberjewel Pendant
(@JewelcraftingHighlevel,99544,45000,@JewelcraftingSkill,520,0), -- Spell Vicious Ruby Choker
(@JewelcraftingHighlevel,99541,40000,@JewelcraftingSkill,510,0), -- Spell Vicious Ruby Signet
(@JewelcraftingHighlevel,99542,45000,@JewelcraftingSkill,520,0), -- Spell Vicious Sapphire Necklace
(@JewelcraftingHighlevel,99539,40000,@JewelcraftingSkill,510,0), -- Spell Vicious Sapphire Ring
(@JewelcraftingHighlevel,131688,40000,@JewelcraftingSkill,535,0), -- Spell Wild Jade
(@JewelcraftingHighlevel,73250,30000,@JewelcraftingSkill,425,0), -- Spell Accurate Nightstone
(@JewelcraftingHighlevel,107627,40000,@JewelcraftingSkill,550,0), -- Spell Accurate Roguestone
(@JewelcraftingHighlevel,53892,10000,@JewelcraftingSkill,350,0), -- Spell Accurate Shadow Crystal
(@JewelcraftingHighlevel,73268,30000,@JewelcraftingSkill,425,0), -- Spell Adept Hessonite
(@JewelcraftingHighlevel,107645,40000,@JewelcraftingSkill,550,0), -- Spell Adept Tiger Opal
(@JewelcraftingHighlevel,73496,30000,@JewelcraftingSkill,435,0), -- Spell Alicite Pendant
(@JewelcraftingHighlevel,26876,3000,@JewelcraftingSkill,220,0), -- Spell Aquamarine Pendant of the Warrior
(@JewelcraftingHighlevel,73270,30000,@JewelcraftingSkill,425,0), -- Spell Artful Hessonite
(@JewelcraftingHighlevel,107646,40000,@JewelcraftingSkill,525,0), -- Spell Artful Tiger Opal
(@JewelcraftingHighlevel,130656,40000,@JewelcraftingSkill,530,0), -- Spell Assassin's Roguestone
(@JewelcraftingHighlevel,31050,25000,@JewelcraftingSkill,320,0), -- Spell Azure Moonstone Ring
(@JewelcraftingHighlevel,107598,40000,@JewelcraftingSkill,550,0), -- Spell Balanced Alexandrite
(@JewelcraftingHighlevel,25498,600,@JewelcraftingSkill,110,0), -- Spell Barbaric Iron Collar
(@JewelcraftingHighlevel,25617,1500,@JewelcraftingSkill,150,0), -- Spell Blazing Citrine Ring
(@JewelcraftingHighlevel,56193,10000,@JewelcraftingSkill,350,0), -- Spell Bloodstone Band
(@JewelcraftingHighlevel,28905,10000,@JewelcraftingSkill,300,0), -- Spell Bold Blood Garnet
(@JewelcraftingHighlevel,53831,10000,@JewelcraftingSkill,350,0), -- Spell Bold Bloodstone
(@JewelcraftingHighlevel,73222,30000,@JewelcraftingSkill,425,0), -- Spell Bold Carnelian
(@JewelcraftingHighlevel,107622,40000,@JewelcraftingSkill,570,0), -- Spell Bold Pandarian Garnet
(@JewelcraftingHighlevel,53852,10000,@JewelcraftingSkill,350,0), -- Spell Brilliant Bloodstone
(@JewelcraftingHighlevel,73225,30000,@JewelcraftingSkill,425,0), -- Spell Brilliant Carnelian
(@JewelcraftingHighlevel,36523,600,@JewelcraftingSkill,75,0), -- Spell Brilliant Necklace
(@JewelcraftingHighlevel,107623,40000,@JewelcraftingSkill,560,0), -- Spell Brilliant Pandarian Garnet
(@JewelcraftingHighlevel,38175,650,@JewelcraftingSkill,80,0), -- Spell Bronze Torc
(@JewelcraftingHighlevel,73620,30000,@JewelcraftingSkill,460,0), -- Spell Carnelian Spikes
(@JewelcraftingHighlevel,53874,10000,@JewelcraftingSkill,350,0), -- Spell Champion's Huge Citrine
(@JewelcraftingHighlevel,107647,40000,@JewelcraftingSkill,545,0), -- Spell Champion's Tiger Opal
(@JewelcraftingHighlevel,25621,2000,@JewelcraftingSkill,180,0), -- Spell Citrine Ring of Rapid Healing
(@JewelcraftingHighlevel,107648,40000,@JewelcraftingSkill,565,0), -- Spell Crafty Tiger Opal
(@JewelcraftingHighlevel,58142,30000,@JewelcraftingSkill,350,0), -- Spell Crystal Chalcedony Amulet
(@JewelcraftingHighlevel,58141,30000,@JewelcraftingSkill,350,0), -- Spell Crystal Citrine Necklace
(@JewelcraftingHighlevel,56205,10000,@JewelcraftingSkill,350,0), -- Spell Dark Jade Focusing Lens
(@JewelcraftingHighlevel,107649,40000,@JewelcraftingSkill,525,0), -- Spell Deadly Tiger Opal
(@JewelcraftingHighlevel,107628,40000,@JewelcraftingSkill,555,0), -- Spell Defender's Roguestone
(@JewelcraftingHighlevel,53880,10000,@JewelcraftingSkill,350,0), -- Spell Deft Huge Citrine
(@JewelcraftingHighlevel,107650,40000,@JewelcraftingSkill,530,0), -- Spell Deft Tiger Opal
(@JewelcraftingHighlevel,34590,10000,@JewelcraftingSkill,300,0), -- Spell Delicate Blood Garnet
(@JewelcraftingHighlevel,53832,10000,@JewelcraftingSkill,350,0), -- Spell Delicate Bloodstone
(@JewelcraftingHighlevel,73223,30000,@JewelcraftingSkill,425,0), -- Spell Delicate Carnelian
(@JewelcraftingHighlevel,107624,40000,@JewelcraftingSkill,530,0), -- Spell Delicate Pandarian Garnet
(@JewelcraftingHighlevel,36526,10000,@JewelcraftingSkill,265,0), -- Spell Diamond Focus Ring
(@JewelcraftingHighlevel,107599,40000,@JewelcraftingSkill,550,0), -- Spell Effulgent Alexandrite
(@JewelcraftingHighlevel,25280,200,@JewelcraftingSkill,50,0), -- Spell Elegant Silver Ring
(@JewelcraftingHighlevel,34961,10000,@JewelcraftingSkill,290,0), -- Spell Emerald Lion Ring
(@JewelcraftingHighlevel,56530,10000,@JewelcraftingSkill,350,0), -- Spell Enchanted Pearl
(@JewelcraftingHighlevel,107600,40000,@JewelcraftingSkill,560,0), -- Spell Energized Alexandrite
(@JewelcraftingHighlevel,53925,10000,@JewelcraftingSkill,350,0), -- Spell Energized Dark Jade
(@JewelcraftingHighlevel,25620,2000,@JewelcraftingSkill,170,0), -- Spell Engraved Truesilver Ring
(@JewelcraftingHighlevel,53923,10000,@JewelcraftingSkill,350,0), -- Spell Lighting Dark Jade
(@JewelcraftingHighlevel,73246,30000,@JewelcraftingSkill,425,0), -- Spell Etched Nightstone
(@JewelcraftingHighlevel,107630,40000,@JewelcraftingSkill,525,0), -- Spell Etched Roguestone
(@JewelcraftingHighlevel,53873,10000,@JewelcraftingSkill,350,0), -- Spell Etched Shadow Crystal
(@JewelcraftingHighlevel,31048,20000,@JewelcraftingSkill,305,0), -- Spell Fel Iron Blood Ring
(@JewelcraftingHighlevel,53876,10000,@JewelcraftingSkill,350,0), -- Spell Fierce Huge Citrine
(@JewelcraftingHighlevel,107651,40000,@JewelcraftingSkill,555,0), -- Spell Fierce Tiger Opal
(@JewelcraftingHighlevel,26872,2500,@JewelcraftingSkill,200,0), -- Spell Figurine - Jade Owl
(@JewelcraftingHighlevel,107652,40000,@JewelcraftingSkill,535,0), -- Spell Fine Tiger Opal
(@JewelcraftingHighlevel,53844,10000,@JewelcraftingSkill,350,0), -- Spell Flashing Bloodstone
(@JewelcraftingHighlevel,107625,40000,@JewelcraftingSkill,550,0), -- Spell Flashing Pandarian Garnet
(@JewelcraftingHighlevel,107601,40000,@JewelcraftingSkill,565,0), -- Spell Forceful Alexandrite
(@JewelcraftingHighlevel,53920,10000,@JewelcraftingSkill,350,0), -- Spell Forceful Dark Jade
(@JewelcraftingHighlevel,73239,30000,@JewelcraftingSkill,425,0), -- Spell Fractured Alicite
(@JewelcraftingHighlevel,107640,40000,@JewelcraftingSkill,535,0), -- Spell Fractured Sunstone
(@JewelcraftingHighlevel,73247,30000,@JewelcraftingSkill,425,0), -- Spell Glinting Nightstone
(@JewelcraftingHighlevel,107631,40000,@JewelcraftingSkill,540,0), -- Spell Glinting Roguestone
(@JewelcraftingHighlevel,53861,10000,@JewelcraftingSkill,350,0), -- Spell Glinting Shadow Crystal
(@JewelcraftingHighlevel,28914,10000,@JewelcraftingSkill,315,0), -- Spell Glinting Shadow Draenite
(@JewelcraftingHighlevel,25287,400,@JewelcraftingSkill,70,0), -- Spell Gloom Band
(@JewelcraftingHighlevel,34960,10000,@JewelcraftingSkill,280,0), -- Spell Glowing Thorium Band
(@JewelcraftingHighlevel,31049,20000,@JewelcraftingSkill,305,0), -- Spell Golden Draenite Ring
(@JewelcraftingHighlevel,25613,1200,@JewelcraftingSkill,135,0), -- Spell Golden Dragon Ring
(@JewelcraftingHighlevel,107632,40000,@JewelcraftingSkill,545,0), -- Spell Guardian's Roguestone
(@JewelcraftingHighlevel,53871,10000,@JewelcraftingSkill,350,0), -- Spell Guardian's Shadow Crystal
(@JewelcraftingHighlevel,31052,30000,@JewelcraftingSkill,335,0), -- Spell Heavy Adamantite Ring
(@JewelcraftingHighlevel,26926,50,@JewelcraftingSkill,5,0), -- Spell Heavy Copper Ring
(@JewelcraftingHighlevel,25612,1500,@JewelcraftingSkill,125,0), -- Spell Heavy Iron Knuckles
(@JewelcraftingHighlevel,36524,800,@JewelcraftingSkill,105,0), -- Spell Heavy Jade Ring
(@JewelcraftingHighlevel,73495,30000,@JewelcraftingSkill,450,0), -- Spell Hessonite Band
(@JewelcraftingHighlevel,25283,100,@JewelcraftingSkill,30,0), -- Spell Inlaid Malachite Ring
(@JewelcraftingHighlevel,28910,10000,@JewelcraftingSkill,300,0), -- Spell Inscribed Flame Spessarite
(@JewelcraftingHighlevel,53872,10000,@JewelcraftingSkill,350,0), -- Spell Inscribed Huge Citrine
(@JewelcraftingHighlevel,107653,40000,@JewelcraftingSkill,555,0), -- Spell Inscribed Tiger Opal
(@JewelcraftingHighlevel,107602,40000,@JewelcraftingSkill,530,0), -- Spell Jagged Alexandrite
(@JewelcraftingHighlevel,53870,10000,@JewelcraftingSkill,350,0), -- Spell Jagged Dark Jade
(@JewelcraftingHighlevel,28917,10000,@JewelcraftingSkill,300,0), -- Spell Jagged Deep Peridot
(@JewelcraftingHighlevel,73274,30000,@JewelcraftingSkill,425,0), -- Spell Jagged Jasper
(@JewelcraftingHighlevel,73494,30000,@JewelcraftingSkill,425,0), -- Spell Jasper Ring
(@JewelcraftingHighlevel,107654,40000,@JewelcraftingSkill,530,0), -- Spell Keen Tiger Opal
(@JewelcraftingHighlevel,107604,40000,@JewelcraftingSkill,525,0), -- Spell Lighting Alexandrite
(@JewelcraftingHighlevel,107655,40000,@JewelcraftingSkill,540,0), -- Spell Lucent Tiger Opal
(@JewelcraftingHighlevel,32178,100,@JewelcraftingSkill,20,0), -- Spell Malachite Pendat
(@JewelcraftingHighlevel,107605,40000,@JewelcraftingSkill,540,0), -- Spell Misty Alexandrite
(@JewelcraftingHighlevel,53922,10000,@JewelcraftingSkill,350,0), -- Spell Misty Dark Jade
(@JewelcraftingHighlevel,107633,40000,@JewelcraftingSkill,525,0), -- Spell Mysterious Roguestone
(@JewelcraftingHighlevel,107641,40000,@JewelcraftingSkill,545,0), -- Spell Mystic Sunstone
(@JewelcraftingHighlevel,73497,30000,@JewelcraftingSkill,460,0), -- Spell Nightstone Choker
(@JewelcraftingHighlevel,107606,40000,@JewelcraftingSkill,530,0), -- Spell Nimble Alexandrite
(@JewelcraftingHighlevel,26907,10000,@JewelcraftingSkill,280,0), -- Spell Onslaught Ring
(@JewelcraftingHighlevel,122661,40000,@JewelcraftingSkill,500,0), -- Spell Ornate Band
(@JewelcraftingHighlevel,26928,100,@JewelcraftingSkill,30,0), -- Spell Ornate Tigerseye Necklace
(@JewelcraftingHighlevel,25610,1500,@JewelcraftingSkill,120,0), -- Spell Pendant of the Agate Shield
(@JewelcraftingHighlevel,107607,40000,@JewelcraftingSkill,555,0), -- Spell Piercing Alexandrite
(@JewelcraftingHighlevel,107656,40000,@JewelcraftingSkill,545,0), -- Spell Polished Tiger Opal
(@JewelcraftingHighlevel,53882,10000,@JewelcraftingSkill,350,0), -- Spell Potent Huge Citrine
(@JewelcraftingHighlevel,107657,40000,@JewelcraftingSkill,560,0), -- Spell Potent Tiger Opal
(@JewelcraftingHighlevel,54017,10000,@JewelcraftingSkill,350,0), -- Spell Precise Bloodstone
(@JewelcraftingHighlevel,73226,30000,@JewelcraftingSkill,425,0), -- Spell Precise Carnelian
(@JewelcraftingHighlevel,107626,40000,@JewelcraftingSkill,540,0), -- Spell Precise Pandarian Garnet
(@JewelcraftingHighlevel,62941,10000,@JewelcraftingSkill,300,0), -- Spell Prismatic Black Diamond
(@JewelcraftingHighlevel,107608,40000,@JewelcraftingSkill,570,0), -- Spell Puissant Alexandrite
(@JewelcraftingHighlevel,73279,30000,@JewelcraftingSkill,425,0), -- Spell Puissant Jasper
(@JewelcraftingHighlevel,41420,8500,@JewelcraftingSkill,325,0), -- Spell Purified Jaggal Pearl
(@JewelcraftingHighlevel,107634,40000,@JewelcraftingSkill,565,0), -- Spell Purified Roguestone
(@JewelcraftingHighlevel,73234,30000,@JewelcraftingSkill,425,0), -- Spell Quick Alicite
(@JewelcraftingHighlevel,53856,10000,@JewelcraftingSkill,350,0), -- Spell Quick Sun Crystal
(@JewelcraftingHighlevel,107642,40000,@JewelcraftingSkill,555,0), -- Spell Quick Sunstone
(@JewelcraftingHighlevel,107609,40000,@JewelcraftingSkill,575,0), -- Spell Radiant Alexandrite
(@JewelcraftingHighlevel,28916,10000,@JewelcraftingSkill,300,0), -- Spell Radiant Deep Peridot
(@JewelcraftingHighlevel,73266,30000,@JewelcraftingSkill,425,0), -- Spell Reckless Hessonite
(@JewelcraftingHighlevel,107658,40000,@JewelcraftingSkill,540,0), -- Spell Reckless Tiger Opal
(@JewelcraftingHighlevel,36525,4000,@JewelcraftingSkill,230,0), -- Spell Red Ring of Destruction
(@JewelcraftingHighlevel,107610,40000,@JewelcraftingSkill,535,0), -- Spell Regal Alexandrite
(@JewelcraftingHighlevel,53918,10000,@JewelcraftingSkill,350,0), -- Spell Regal Dark Jade
(@JewelcraftingHighlevel,53893,10000,@JewelcraftingSkill,350,0), -- Spell Resolute Huge Citrine
(@JewelcraftingHighlevel,107659,40000,@JewelcraftingSkill,575,0), -- Spell Resolute Tiger Opal
(@JewelcraftingHighlevel,107660,40000,@JewelcraftingSkill,575,0), -- Spell Resplendent Tiger Opal
(@JewelcraftingHighlevel,107635,40000,@JewelcraftingSkill,575,0), -- Spell Retaliating Roguestone
(@JewelcraftingHighlevel,28948,10000,@JewelcraftingSkill,325,0), -- Spell Rigid Azure Moonstone
(@JewelcraftingHighlevel,53854,10000,@JewelcraftingSkill,350,0), -- Spell Rigid Chalcedony
(@JewelcraftingHighlevel,107617,40000,@JewelcraftingSkill,525,0), -- Spell Rigid Lapis Lazuli
(@JewelcraftingHighlevel,73230,30000,@JewelcraftingSkill,425,0), -- Spell Rigid Zephyrite
(@JewelcraftingHighlevel,25317,600,@JewelcraftingSkill,80,0), -- Spell Ring of Silver Might
(@JewelcraftingHighlevel,25318,800,@JewelcraftingSkill,100,0), -- Spell Ring of Twilight Shadows
(@JewelcraftingHighlevel,26883,4000,@JewelcraftingSkill,235,0), -- Spell Ruby Pendant of Fire
(@JewelcraftingHighlevel,26908,12000,@JewelcraftingSkill,280,0), -- Spell Sapphire Pendant of Winter Night
(@JewelcraftingHighlevel,107611,40000,@JewelcraftingSkill,545,0), -- Spell Sensei's Alexandrite
(@JewelcraftingHighlevel,73281,30000,@JewelcraftingSkill,425,0), -- Spell Sensei's Jasper
(@JewelcraftingHighlevel,56206,10000,@JewelcraftingSkill,350,0), -- Spell Shadow Crystal Focusing Lens
(@JewelcraftingHighlevel,56208,10000,@JewelcraftingSkill,350,0), -- Spell Shadow Jade Focusing Lens
(@JewelcraftingHighlevel,122662,40000,@JewelcraftingSkill,510,0), -- Spell Shadowfire Necklace
(@JewelcraftingHighlevel,58146,50000,@JewelcraftingSkill,390,0), -- Spell Shadowmight Ring
(@JewelcraftingHighlevel,107612,40000,@JewelcraftingSkill,540,0), -- Spell Shattered Alexandrite
(@JewelcraftingHighlevel,73241,30000,@JewelcraftingSkill,425,0), -- Spell Shifting Nightstone
(@JewelcraftingHighlevel,107636,40000,@JewelcraftingSkill,535,0), -- Spell Shifting Roguestone
(@JewelcraftingHighlevel,53860,10000,@JewelcraftingSkill,350,0), -- Spell Shifting Shadow Crystal
(@JewelcraftingHighlevel,26902,10000,@JewelcraftingSkill,260,0), -- Spell Simple Opal Ring
(@JewelcraftingHighlevel,25284,400,@JewelcraftingSkill,60,0), -- Spell Simple Pearl Ring
(@JewelcraftingHighlevel,73267,30000,@JewelcraftingSkill,425,0), -- Spell Skillful Hessonite
(@JewelcraftingHighlevel,107661,40000,@JewelcraftingSkill,560,0), -- Spell Skillful Tiger Opal
(@JewelcraftingHighlevel,73232,30000,@JewelcraftingSkill,425,0), -- Spell Smooth Alicite
(@JewelcraftingHighlevel,53845,10000,@JewelcraftingSkill,350,0), -- Spell Smooth Sund Crystal
(@JewelcraftingHighlevel,107643,40000,@JewelcraftingSkill,565,0), -- Spell Smooth Sunstone
(@JewelcraftingHighlevel,28950,10000,@JewelcraftingSkill,300,0), -- Spell Solid Azure Moonstone
(@JewelcraftingHighlevel,25490,300,@JewelcraftingSkill,50,0), -- Spell Aolid Bronze Ring
(@JewelcraftingHighlevel,53934,10000,@JewelcraftingSkill,350,0), -- Spell Solid Chalcedony
(@JewelcraftingHighlevel,107619,40000,@JewelcraftingSkill,535,0), -- Spell Solid Lapis Lazuli
(@JewelcraftingHighlevel,73227,30000,@JewelcraftingSkill,425,0), -- Spell Solid Zephyrite
(@JewelcraftingHighlevel,73240,30000,@JewelcraftingSkill,425,0), -- Spell Sovereign Nightstone
(@JewelcraftingHighlevel,107637,40000,@JewelcraftingSkill,535,0), -- Spell Sovereign Roguestone
(@JewelcraftingHighlevel,53859,10000,@JewelcraftingSkill,350,0), -- Spell Sovereign Shadow Crystal
(@JewelcraftingHighlevel,28936,10000,@JewelcraftingSkill,325,0), -- Spell Sovereign Shadow Draenite
(@JewelcraftingHighlevel,28953,10000,@JewelcraftingSkill,300,0), -- Spell Sparkling Azure Moonstone
(@JewelcraftingHighlevel,53941,10000,@JewelcraftingSkill,350,0), -- Spell Sparkling Chalcedony
(@JewelcraftingHighlevel,107620,40000,@JewelcraftingSkill,545,0), -- Spell Sparkling Lapis Lazuli
(@JewelcraftingHighlevel,73228,30000,@JewelcraftingSkill,425,0), -- Spell Sparkling Zephyrite
(@JewelcraftingHighlevel,107662,40000,@JewelcraftingSkill,570,0), -- Spell Splendid Tiger Opal
(@JewelcraftingHighlevel,53891,10000,@JewelcraftingSkill,350,0), -- Spell Stalwart Huge Citrine
(@JewelcraftingHighlevel,107663,40000,@JewelcraftingSkill,565,0), -- Spell Stalwart Tiger Opal
(@JewelcraftingHighlevel,107613,40000,@JewelcraftingSkill,555,0), -- Spell Steady Alexandrite
(@JewelcraftingHighlevel,58145,50000,@JewelcraftingSkill,390,0), -- Spell Stoneguard Band
(@JewelcraftingHighlevel,107621,40000,@JewelcraftingSkill,555,0), -- Spell Stormy Lapis Lazuli
(@JewelcraftingHighlevel,53843,10000,@JewelcraftingSkill,350,0), -- Spell Subtle Sun Crystal
(@JewelcraftingHighlevel,107644,40000,@JewelcraftingSkill,575,0), -- Spell Subtle Sunstone
(@JewelcraftingHighlevel,56194,10000,@JewelcraftingSkill,350,0), -- Spell Sun ROck Ring
(@JewelcraftingHighlevel,130655,40000,@JewelcraftingSkill,570,0), -- Spell Tense Roguestone
(@JewelcraftingHighlevel,107665,40000,@JewelcraftingSkill,550,0), -- Spell Tenuous Tiger Opal
(@JewelcraftingHighlevel,31051,30000,@JewelcraftingSkill,335,0), -- Spell Thick Adamantite Necklace
(@JewelcraftingHighlevel,26927,300,@JewelcraftingSkill,50,0), -- Spell Thick Bronze Necklace
(@JewelcraftingHighlevel,32179,100,@JewelcraftingSkill,20,0), -- Spell Tigersece Band
(@JewelcraftingHighlevel,73243,30000,@JewelcraftingSkill,425,0), -- Spell Timeless Nightstone
(@JewelcraftingHighlevel,107638,40000,@JewelcraftingSkill,560,0), -- Spell Timeless Roguestone
(@JewelcraftingHighlevel,53894,10000,@JewelcraftingSkill,350,0), -- Spell Timeless Shadow Crystal
(@JewelcraftingHighlevel,28925,10000,@JewelcraftingSkill,300,0), -- Spell Timeless Shadow Draenite
(@JewelcraftingHighlevel,26885,5000,@JewelcraftingSkill,240,0), -- Spell Truesilver Healing Ring
(@JewelcraftingHighlevel,107614,40000,@JewelcraftingSkill,545,0), -- Spell Turbid Alexandrite
(@JewelcraftingHighlevel,73249,30000,@JewelcraftingSkill,425,0), -- Spell Veiled Nightstone
(@JewelcraftingHighlevel,107639,40000,@JewelcraftingSkill,530,0), -- Spell Veiled Roguestone
(@JewelcraftingHighlevel,53883,10000,@JewelcraftingSkill,350,0), -- Spell Veiled Shadow Crystal
(@JewelcraftingHighlevel,107615,40000,@JewelcraftingSkill,525,0), -- Spell Vivid Alexandrite
(@JewelcraftingHighlevel,107666,40000,@JewelcraftingSkill,570,0), -- Spell Wicked Tiger Opal
(@JewelcraftingHighlevel,107667,40000,@JewelcraftingSkill,535,0), -- Spell Willful Tiger Opal
(@JewelcraftingHighlevel,107616,40000,@JewelcraftingSkill,535,0), -- Spell Zen Alexandrite
(@JewelcraftingHighlevel,25278,200,@JewelcraftingSkill,50,0), -- Spell Bronze Setting
(@JewelcraftingHighlevel,32801,200,@JewelcraftingSkill,50,0), -- Spell Coarse Stone Statue
(@JewelcraftingHighlevel,32809,3500,@JewelcraftingSkill,225,0), -- Spell Dense Stone Statue
(@JewelcraftingHighlevel,32807,600,@JewelcraftingSkill,110,0), -- Spell Heavy Stone Statue
(@JewelcraftingHighlevel,25615,1500,@JewelcraftingSkill,150,0), -- Spell Mithril Filigree
(@JewelcraftingHighlevel,122663,40000,@JewelcraftingSkill,525,0), -- Spell Scrying Roguestone
(@JewelcraftingHighlevel,32808,2000,@JewelcraftingSkill,175,0), -- Spell Solid Stone Statue
(@JewelcraftingHighlevel,73622,30000,@JewelcraftingSkill,435,0), -- Spell Stardust
(@JewelcraftingHighlevel,26880,3500,@JewelcraftingSkill,225,0), -- Spell Thorium Setting
-- Jewelcrafting-Lowlevel --
(@JewelcraftingLowlevel, 25229, 10, 0, 0, 5), -- Spell Jewelcrafting Rank 1
(@JewelcraftingLowlevel, 32801, 200,@JewelcraftingSkill, 50, 0), -- Spell Coarse Stone Statue
(@JewelcraftingLowlevel, 25283, 100,@JewelcraftingSkill, 30, 0), -- Spell Inlaid Malachite Ring
(@JewelcraftingLowlevel, 25284, 400,@JewelcraftingSkill, 60, 0), -- Spell Simple Pearl Ring
(@JewelcraftingLowlevel, 25287, 400,@JewelcraftingSkill, 70, 0), -- Spell Gloom Band
(@JewelcraftingLowlevel, 25490, 300,@JewelcraftingSkill, 50, 0), -- Spell Solid Bronze Ring
(@JewelcraftingLowlevel, 25278, 200,@JewelcraftingSkill, 50, 0), -- Spell Bronze Setting
(@JewelcraftingLowlevel, 25280, 200,@JewelcraftingSkill, 50, 0), -- Spell Elegant Silver Ring
(@JewelcraftingLowlevel, 26926, 50,@JewelcraftingSkill, 5, 0), -- Spell Heavy Copper Ring
(@JewelcraftingLowlevel, 26927, 300,@JewelcraftingSkill, 50, 0), -- Spell Thick Bronze Necklace
(@JewelcraftingLowlevel, 26928, 100,@JewelcraftingSkill, 30, 0), -- Spell Ornate Tigerseye Necklace
(@JewelcraftingLowlevel, 31252, 100,@JewelcraftingSkill, 20, 5), -- Spell Prospecting
(@JewelcraftingLowlevel, 32179, 100,@JewelcraftingSkill, 20, 0), -- Spell Tigerseye Band
(@JewelcraftingLowlevel, 32178, 100,@JewelcraftingSkill, 20, 0), -- Spell Malachite Pendant
(@JewelcraftingLowlevel, 37818, 500,@JewelcraftingSkill, 65, 0), -- Spell Bronze Band of Force
(@JewelcraftingLowlevel, 36523, 600,@JewelcraftingSkill, 75, 0), -- Spell Brilliant Necklace
-- Jewelcrafting-Teacher --
(52645,-@JewelcraftingHighlevel,0,0,0,0), -- Aessa Silverdew - Darnassus
(15501,-@JewelcraftingHighlevel,0,0,0,0), -- Aleinia - Silvermoon City
(26997,-@JewelcraftingHighlevel,0,0,0,0), -- Alestos - Borean Tundra
(86010,-@JewelcraftingHighlevel,0,0,0,0), -- Alixander Swiftsteel - Silvermoon City
(85916,-@JewelcraftingHighlevel,0,0,0,0), -- Artificer Nissea - Stormshield
(19778,-@JewelcraftingHighlevel,0,0,0,0), -- Farii - The Exodar
(26982,-@JewelcraftingHighlevel,0,0,0,0), -- Geba'li - Borean Tundra
(19063,-@JewelcraftingHighlevel,0,0,0,0), -- Hamanar - Shattrath City
(52586,-@JewelcraftingHighlevel,0,0,0,0), -- Hanner Gembold - Ironforge
(33614,-@JewelcraftingHighlevel,0,0,0,0), -- Jewelcrafting - Shattrath City
(18751,-@JewelcraftingHighlevel,0,0,0,0), -- Kalaen - Hellfire Peninsula
(19775,-@JewelcraftingHighlevel,0,0,0,0), -- Kalinda - Silvermoon City
(46675,-@JewelcraftingHighlevel,0,0,0,0), -- Lugrah - Orgrimmar
(65098,-@JewelcraftingHighlevel,0,0,0,0), -- Mai the Jade Shaper - The Jade Forest
(52657,-@JewelcraftingHighlevel,0,0,0,0), -- Nahari Cloudchaser - Thunder Buff
(52587,-@JewelcraftingHighlevel,0,0,0,0), -- Neller Fayne - Undercity
(33680,-@JewelcraftingHighlevel,0,0,0,0), -- Nemiha - Shattrath City
(33590,-@JewelcraftingHighlevel,0,0,0,0), -- Oluros - Icecrown
(26915,-@JewelcraftingHighlevel,0,0,0,0), -- Ounhulo - Howling Fjord
(18774,-@JewelcraftingHighlevel,0,0,0,0), -- Tatiana - Hellfire Peninsula
(44582,-@JewelcraftingHighlevel,0,0,0,0), -- Theresa Denman - Stormwind
(28701,-@JewelcraftingHighlevel,0,0,0,0); -- Timothy Jones - Dalaran

-- Jewelcrafting Rank 8
-- Added the, so far, last rank of Jewelcrafting(8) to the table
-- first_spell_id = 25229
-- spell_id = 110420
-- rank = 8
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 25229 && `rank` = 8;
INSERT INTO `spell_ranks` (`first_spell_id`,`spell_id`,`rank`) VALUES (25229,110420,8);
