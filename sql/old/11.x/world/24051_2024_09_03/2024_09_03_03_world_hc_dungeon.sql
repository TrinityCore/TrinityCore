-- 
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (224853,224609,224387,224276,224271,224249,224240,224221,224219,224152,223981,216649,216648,215407,211291,211290,211289,211140,210156,210108,208743,207946,207940,207939,207207,206705,199619,199618,199617,199615,196712,196645,196115,195930,195929,195928,195927,195878,195855,195696,195138,195119,194897,194896,194895,194745,194487,194367,194241,193462,193373,192788,192481,191574,191164,190485,190381,190294,190206,190034,189893,189886,189719,189478,188067,187894,187238,187231,187224,186644,186246,186151,186116,181861));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(224853, 2, 3, 1, 1, 275789, 72, 0), -- Mutated Hatchling
(224609, 2, 3, 10, 1, 275535, 72, 0), -- Twilight Destroyer
(224387, 2, 3, 8, 1, 275303, 8, 0), -- Twilight Elementalist
(224276, 2, 3, 5.5, 5, 275182, 2097224, 0), -- Twilight Enforcer
(224271, 2, 3, 5, 5, 275173, 2097224, 0), -- Twilight Warlock
(224249, 2, 3, 7.699999809265136718, 1, 275190, 8, 0), -- Twilight Lavabender
(224240, 2, 3, 4.5, 1, 275097, 2097224, 0), -- Twilight Flamerender
(224221, 2, 3, 8.5, 1, 275193, 2097224, 0), -- Twilight Overseer
(224219, 2, 3, 4, 1, 276449, 8, 0), -- Twilight Earthcaller
(224152, 2, 3, 5, 1, 276114, 2097224, 0), -- Twilight Brute
(223981, 2, 3, 1, 1, 274846, 1073741832, 128), -- Void Tendril
(216649, 2, 10, 40, 1, 281617, 2097256, 67108992), -- Vx
(216648, 2, 10, 40, 1, 281613, 2097256, 67108992), -- Nx
(215407, 2, 10, 40, 1, 280401, 2097256, 128), -- Ki'katal the Harvester
(211291, 2, 10, 15, 1, 274159, 2097224, 0), -- Sergeant Shaynemail
(211290, 2, 10, 15, 1, 274151, 270532680, 0), -- Elaena Emberlanz
(211289, 2, 10, 15, 1, 274155, 2097224, 0), -- Taener Duelmal
(211140, 2, 10, 8, 1, 277645, 2097224, 128), -- Arathi Neophyte
(210156, 2, 10, 35, 1, 258192, 2097256, 128), -- Skarmorak
(210108, 2, 10, 40, 1, 274053, 2097256, 128), -- E.D.N.A
(208743, 2, 10, 35, 1, 263545, 2097256, 128), -- Blazikon
(207946, 2, 10, 35, 1, 274146, 270534760, 128), -- Captain Dailcry
(207940, 2, 10, 40, 1, 277910, 270532712, 128), -- Prioress Murrpray
(207939, 2, 10, 35, 1, 273466, 270532712, 128), -- Baron Braunpyke
(207207, 2, 10, 40, 1, 263558, 2097256, 128), -- Voidstone Monstrosity
(206705, 2, 10, 6.5, 1, 280632, 2097224, 0), -- Arathi Footman
(199619, 2, 9, 25, 1, 277495, 0, 0), -- Baqir
(199618, 2, 9, 1.20000004768371582, 1, 277504, 0, 0), -- Carseng
(199617, 2, 9, 1.20000004768371582, 1, 277499, 0, 0), -- Huraq
(199615, 2, 9, 1.20000004768371582, 1, 277492, 0, 0), -- Salukan
(196712, 2, 9, 2, 1, 276958, 2097224, 128), -- Nullification Device
(196645, 2, 9, 1.25, 1, 277609, 2097256, 0), -- Desecrated Bakar
(196115, 2, 9, 8, 1, 277132, 2097480, 0), -- Arcane Tender
(195930, 2, 9, 8, 1, 277618, 2097256, 0), -- Soulharvester Mandakh
(195929, 2, 9, 8, 1, 277615, 2097256, 0), -- Soulharvester Tumen
(195928, 2, 9, 8, 1, 277606, 2097256, 0), -- Soulharvester Duuren
(195927, 2, 9, 8, 1, 277602, 2097256, 0), -- Soulharvester Galtmaa
(195878, 2, 9, 10, 1, 277612, 2097256, 0), -- Ukhel Beastcaller
(195855, 2, 9, 5, 1, 277599, 2097256, 0), -- Risen Warrior
(195696, 2, 9, 10, 1, 277588, 2097256, 0), -- Primalist Thunderbeast
(195138, 2, 9, 0.60000002384185791, 1, 277180, 16778240, 144), -- Detonating Crystal
(195119, 2, 9, 8, 1, 277079, 2097224, 0), -- Primalist Shockcaster
(194897, 2, 9, 3, 1, 277579, 16, 0), -- Stormsurge Totem
(194896, 2, 9, 5, 1, 277583, 2097224, 0), -- Primal Stormshield
(194895, 2, 9, 2, 1, 277593, 2097224, 0), -- Unstable Squall
(194745, 2, 9, 2.5, 1, 276909, 2097224, 128), -- Rotfang Hyena
(194487, 2, 9, 7, 1, 276943, 2097224, 0), -- Vile Rothexer
(194367, 2, 9, 1, 1, 277555, 2097256, 6), -- Dragonkiller Lance
(194241, 2, 9, 7, 1, 276940, 2097224, 0), -- Vile Rothexer
(193462, 2, 9, 12, 1, 277651, 2097256, 0), -- Batak
(193373, 2, 9, 5, 1, 277631, 2097256, 0), -- Nokhud Thunderfist
(192788, 2, 9, 6, 1, 277028, 2097224, 0), -- Qalashi Thaumaturge
(192481, 2, 9, 0.699999988079071044, 1, 276897, 2097224, 128), -- Decaying Slime
(191574, 2, 9, 1, 1, 276953, 0, 128), -- Choking Rotcloud
(191164, 2, 9, 8, 1, 277135, 2097480, 0), -- Arcane Tender
(190485, 2, 9, 22.5, 1, 277099, 2097256, 128), -- Erkhart Stormvein
(190381, 2, 9, 1.5, 1, 276946, 0, 128), -- Rotburst Totem
(190294, 2, 9, 2, 1, 277666, 2097256, 128), -- Nokhud Stormcaster
(190206, 2, 9, 5.5, 1, 277087, 2097224, 0), -- Primalist Flamedancer
(190034, 2, 9, 8.5, 1, 277084, 2097224, 0), -- Blazebound Destroyer
(189893, 2, 9, 1.72500002384185791, 1, 277076, 2097224, 128), -- Infused Whelp
(189886, 2, 9, 3.20000004768371582, 1, 277091, 2097256, 128), -- Blazebound Firestorm
(189719, 2, 9, 130, 1, 276961, 2097256, 128), -- Watcher Irideus
(189478, 2, 9, 31.5, 1, 277024, 2097256, 128), -- Forgemaster Gorek
(188067, 2, 9, 5, 1, 277062, 2097224, 0), -- Flashfrost Chillweaver
(187894, 2, 9, 1.72500002384185791, 1, 277069, 2097224, 0), -- Infused Whelp
(187238, 2, 9, 1, 1, 276934, 2097224, 0), -- Witherling
(187231, 2, 9, 1.5, 1, 276931, 2097224, 0), -- Wither Biter
(187224, 2, 9, 7, 1, 276937, 2097224, 0), -- Vile Rothexer
(186644, 2, 9, 35, 1, 277145, 2097224, 128), -- Leymor
(186246, 2, 9, 3, 1, 276902, 2097224, 0), -- Fleshripper Vulture
(186151, 2, 9, 40, 1, 277657, 2097256, 128), -- Balakar Khan
(186116, 2, 9, 28, 1, 276906, 2097224, 128), -- Gutshot
(181861, 2, 9, 34.65000152587890625, 1, 277033, 2097225, 128); -- Magmatusk

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=0 AND `Entry` IN (230937,229635,229536,229244)); -- Xal'atath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=229537 AND `DifficultyID`=0); -- Void Emissary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (215641,213786,212228,212225,212200,211152,211151,211150,211149,211137,211111,210931,210930)); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=210623 AND `DifficultyID`=0); -- [DNT] Liang Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=198555 AND `DifficultyID`=2); -- Chaos Tear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=198547 AND `DifficultyID`=2); -- Shadowy Tear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=198489 AND `DifficultyID`=2); -- Denizen of the Dream
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=276830 WHERE (`Entry`=197406 AND `DifficultyID`=2); -- Aggravated Skitterfly
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=276842 WHERE (`Entry`=196482 AND `DifficultyID`=2); -- Overgrown Ancient
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=196280 AND `DifficultyID`=2); -- Unstable Tear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=195880 AND `DifficultyID`=2); -- Roaming Rocks
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=195294 AND `DifficultyID`=2); -- Beetle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=192337 AND `DifficultyID`=2); -- Void Tendril
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=189988 AND `DifficultyID`=2); -- Thing From Beyond
UPDATE `creature_template_difficulty` SET `HealthModifier`=1, `CreatureDifficultyID`=277251 WHERE (`Entry`=186696 AND `DifficultyID`=2); -- Quaking Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=185584 AND `DifficultyID`=2); -- Blasphemy
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=277238 WHERE (`Entry`=184581 AND `DifficultyID`=2); -- Baelog
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=277291 WHERE (`Entry`=184132 AND `DifficultyID`=2); -- Earthen Warder
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=277305 WHERE (`Entry`=184131 AND `DifficultyID`=2); -- Earthen Guardian
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=277227 WHERE (`Entry`=184023 AND `DifficultyID`=2); -- Vicious Basilisk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=183143 AND `DifficultyID`=2); -- Vombata Pup
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=182706 AND `DifficultyID`=2); -- Butterfly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=182599 AND `DifficultyID`=2); -- Dragonfly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=180572 AND `DifficultyID`=2); -- Boopers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=180269 AND `DifficultyID`=2); -- Curiosity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (179367,179168)); -- Scavenging Skrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (179366,179167)); -- Damp Skrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=179165 AND `DifficultyID`=2); -- Silver Purrkin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=179164 AND `DifficultyID`=2); -- Curious Purrkin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=174654 AND `DifficultyID`=2); -- Wayward Spellshard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=173994 AND `DifficultyID`=2); -- Will of Remornia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=173200 AND `DifficultyID`=2); -- Bleak Skitterer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=170506 AND `DifficultyID`=2); -- Thunderous Squall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=169411 AND `DifficultyID`=2); -- Lingering Anguish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=169366 AND `DifficultyID`=2); -- Remnant of Apathy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (168734,168732)); -- Raven
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=168702 AND `DifficultyID`=2); -- Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=167354 AND `DifficultyID`=2); -- Writhing Rachis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=167353 AND `DifficultyID`=2); -- Chittering Claw
UPDATE `creature_template_difficulty` SET `HealthModifier`=9 WHERE (`Entry`=166276 AND `DifficultyID`=2); -- Mistveil Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=165855 AND `DifficultyID`=2); -- Moonfrog
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.5 WHERE (`Entry`=165597 AND `DifficultyID`=2); -- Patchwerk Soldier
UPDATE `creature_template_difficulty` SET `TypeFlags`=2097256 WHERE (`Entry`=164517 AND `DifficultyID`=2); -- Tred'ova
UPDATE `creature_template_difficulty` SET `TypeFlags`=2097256 WHERE (`Entry`=164501 AND `DifficultyID`=2); -- Mistcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=163366 AND `DifficultyID`=2); -- Magus of the Dead
UPDATE `creature_template_difficulty` SET `HealthModifier`=2.5 WHERE (`Entry`=163122 AND `DifficultyID`=2); -- Brittlebone Warrior
UPDATE `creature_template_difficulty` SET `HealthModifier`=7.699999809265136718 WHERE (`Entry`=163058 AND `DifficultyID`=2); -- Mistveil Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (158864,13616)); -- Frostwolf Stable Master
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (158863,13617)); -- Stormpike Stable Master
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=155543 AND `DifficultyID`=2); -- Helpless Critter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=154854 AND `DifficultyID`=2); -- Lost Robogrip
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (154476,13442)); -- Archdruid Renferal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (154474,13236)); -- Primalist Thurloga
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=149519 AND `DifficultyID`=2); -- Boralus Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=147692 AND `DifficultyID`=2); -- Alarm-O-Dog
UPDATE `creature_template_difficulty` SET `HealthModifier`=31655.587890625 WHERE (`Entry`=145806 AND `DifficultyID`=2); -- 7th Legion Airship
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=144961 AND `DifficultyID`=2); -- Akaari's Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=144449 AND `DifficultyID`=2); -- Ashvane Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=142699 AND `DifficultyID`=2); -- _JKL - SQL Difficulty 2
UPDATE `creature_template_difficulty` SET `HealthModifier`=2.5 WHERE (`DifficultyID`=2 AND `Entry` IN (138464,136483)); -- Ashvane Deckhand
UPDATE `creature_template_difficulty` SET `HealthModifier`=12 WHERE (`DifficultyID`=2 AND `Entry` IN (137626,137625,137614)); -- Demolishing Terror
UPDATE `creature_template_difficulty` SET `HealthModifier`=6 WHERE (`Entry`=137405 AND `DifficultyID`=2); -- Gripping Terror
UPDATE `creature_template_difficulty` SET `TypeFlags`=2097225 WHERE (`Entry`=136976 AND `DifficultyID`=2); -- T'zala
UPDATE `creature_template_difficulty` SET `TypeFlags2`=144 WHERE (`Entry`=136975 AND `DifficultyID`=2); -- Heavy Ordnance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136407 AND `DifficultyID`=2); -- Wrathguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136406 AND `DifficultyID`=2); -- Shivarra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136404 AND `DifficultyID`=2); -- Bilescourge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136403 AND `DifficultyID`=2); -- Void Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136402 AND `DifficultyID`=2); -- Ur'zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136399 AND `DifficultyID`=2); -- Vicious Hellhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136398 AND `DifficultyID`=2); -- Illidari Satyr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=136380 AND `DifficultyID`=2); -- Rezan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=135002 AND `DifficultyID`=2); -- Demonic Tyrant
UPDATE `creature_template_difficulty` SET `HealthModifier`=40 WHERE (`Entry`=128651 AND `DifficultyID`=2); -- Hadal Darkfathom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=125493 AND `DifficultyID`=2); -- Skyfin Juvenile
UPDATE `creature_template_difficulty` SET `TypeFlags`=73 WHERE (`Entry`=122963 AND `DifficultyID`=2); -- Rezan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=122033 AND `DifficultyID`=2); -- Twilight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=116175 AND `DifficultyID`=2); -- Karam Magespear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (113670,28781)); -- Battleground Demolisher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=104629 AND `DifficultyID`=2); -- Blood Beast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=104091 AND `DifficultyID`=2); -- Kirin Tor Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=103673 AND `DifficultyID`=2); -- Darkglare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (103358,64617,62865)); -- Beast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=100820 AND `DifficultyID`=2); -- Spirit Wolf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=100688 AND `DifficultyID`=2); -- Brightscale Darters
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=99908 AND `DifficultyID`=2); -- Skittering Softshell
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=98035 AND `DifficultyID`=2); -- Dreadstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=97285 AND `DifficultyID`=2); -- Wind Rush Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=96813 AND `DifficultyID`=2); -- Aludane Whitecloud
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=95072 AND `DifficultyID`=2); -- Greater Earth Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=89809 AND `DifficultyID`=2); -- Salteye Tadpole
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=89380 AND `DifficultyID`=2); -- Coastal Sandpiper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=88978 AND `DifficultyID`=2); -- Kelp Scuttler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=88782 AND `DifficultyID`=2); -- Nar'thalas Nightwatcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (88239,80724,13117)); -- Horde Spirit Guide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (88238,80723,13116)); -- Alliance Spirit Guide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=88222 AND `DifficultyID`=2); -- Everbloom Peachick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (83484,70139)); -- RRP Test Creature
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (79417,54030)); -- Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=77942 AND `DifficultyID`=2); -- Primal Storm Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=76168 AND `DifficultyID`=2); -- Ravager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=73400 AND `DifficultyID`=2); -- Healing Ran Invisible Stalker DND
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=72587 AND `DifficultyID`=2); -- VFX Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=71942 AND `DifficultyID`=2); -- Xu-Fu, Cub of Xuen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=68662 AND `DifficultyID`=2); -- Chrominius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=68267 AND `DifficultyID`=2); -- Cinder Kitten
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=65547 AND `DifficultyID`=2); -- Sekret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=65546 AND `DifficultyID`=2); -- Sekrit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (64806,64352)); -- Rapana Whelk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=63508 AND `DifficultyID`=2); -- Xuen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=62900 AND `DifficultyID`=2); -- Wildhammer Gryphon Hatchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=62822 AND `DifficultyID`=2); -- Cousin Slowhands
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=62821 AND `DifficultyID`=2); -- Mystic Birdhat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=61245 AND `DifficultyID`=2); -- Capacitor Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=60199 AND `DifficultyID`=2); -- Rune of Power
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=59738 AND `DifficultyID`=2); -- Light's Hammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=59481 AND `DifficultyID`=2); -- World Trigger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=59394 AND `DifficultyID`=2); -- General Purpose Bunny JMF (Ground)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=59375 AND `DifficultyID`=2); -- Cosmetic Meat Pile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (59271,59262)); -- Demonic Gateway
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=58495 AND `DifficultyID`=2); -- ScottG Test
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=55659 AND `DifficultyID`=2); -- Wild Imp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=54020 AND `DifficultyID`=2); -- General Purpose Bunny JMF (Look 2 - Flying, Huge AOI)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=53605 AND `DifficultyID`=2); -- Bug 93896 Summon Add
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=50485 AND `DifficultyID`=2); -- Carrion Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=47794 AND `DifficultyID`=2); -- Snake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=47319 AND `DifficultyID`=2); -- Leap Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=45439 AND `DifficultyID`=2); -- Cockroach
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=44829 AND `DifficultyID`=2); -- Slate Dragon
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=44828 AND `DifficultyID`=2); -- Nether Scion
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=44826 AND `DifficultyID`=2); -- Storm Rider
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=44653 AND `DifficultyID`=2); -- Time Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=43499 AND `DifficultyID`=2); -- Consecration
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=43359 AND `DifficultyID`=2); -- ELM General Purpose Bunny Infinite Hide Body
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=42373 AND `DifficultyID`=2); -- Crocolisk, Cataclysm
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=41095 AND `DifficultyID`=2); -- Twilight Destroyer
UPDATE `creature_template_difficulty` SET `TypeFlags`=1073742920, `TypeFlags2`=128 WHERE (`Entry`=40486 AND `DifficultyID`=2); -- Alexstrasza's Egg
UPDATE `creature_template_difficulty` SET `TypeFlags`=1075840072 WHERE (`Entry`=40485 AND `DifficultyID`=2); -- Twilight Egg
UPDATE `creature_template_difficulty` SET `HealthModifier`=40, `TypeFlags`=2147483752 WHERE (`Entry`=40484 AND `DifficultyID`=2); -- Erudax
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.75, `TypeFlags2`=128 WHERE (`Entry`=40357 AND `DifficultyID`=2); -- Invoked Shadowflame Spirit
UPDATE `creature_template_difficulty` SET `TypeFlags`=104 WHERE (`Entry`=40320 AND `DifficultyID`=2); -- Valiona
UPDATE `creature_template_difficulty` SET `TypeFlags`=2147483752 WHERE (`Entry`=40319 AND `DifficultyID`=2); -- Drahga Shadowburner
UPDATE `creature_template_difficulty` SET `HealthModifier`=35, `TypeFlags`=2097256 WHERE (`Entry`=40177 AND `DifficultyID`=2); -- Forgemaster Throngus
UPDATE `creature_template_difficulty` SET `HealthModifier`=4, `TypeFlags`=2097224 WHERE (`Entry`=40167 AND `DifficultyID`=2); -- Twilight Beguiler
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.5, `TypeFlags`=2097224 WHERE (`Entry`=40166 AND `DifficultyID`=2); -- Molten Giant
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.5, `TypeFlags`=2097256 WHERE (`Entry`=39900 AND `DifficultyID`=2); -- Enslaved Rock Elemental
UPDATE `creature_template_difficulty` SET `HealthModifier`=30, `TypeFlags`=2097256 WHERE (`Entry`=39625 AND `DifficultyID`=2); -- General Umbriss
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=39392 AND `DifficultyID`=2); -- Faceless Corruptor
UPDATE `creature_template_difficulty` SET `HealthModifier`=1, `TypeFlags2`=128 WHERE (`Entry`=39388 AND `DifficultyID`=2); -- Mutated Hatchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (36356,34778)); -- Flame Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (36355,34777)); -- Siege Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=35387 AND `DifficultyID`=2); -- Leaping Hatchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=35346 AND `DifficultyID`=2); -- Goblin Mechanic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=35345 AND `DifficultyID`=2); -- Gnomish Mechanic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=2 AND `Entry` IN (35273,34802)); -- Glaive Thrower
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34944 AND `DifficultyID`=2); -- Keep Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34935 AND `DifficultyID`=2); -- Horde Gunship Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34929 AND `DifficultyID`=2); -- Alliance Gunship Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34924 AND `DifficultyID`=2); -- High Commander Halford Wyrmbane
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34922 AND `DifficultyID`=2); -- Overlord Agmar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34919 AND `DifficultyID`=2); -- 7th Legion Infantry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34918 AND `DifficultyID`=2); -- Kor'kron Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34793 AND `DifficultyID`=2); -- Catapult
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34775 AND `DifficultyID`=2); -- Demolisher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=34527 AND `DifficultyID`=2); -- Dave's Industrial Light and Magic Bunny (Small)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=32639 AND `DifficultyID`=2); -- Gnimo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=32638 AND `DifficultyID`=2); -- Hakmud of Argus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=31216 AND `DifficultyID`=2); -- Mirror Image
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=30298 AND `DifficultyID`=2); -- Invisible Stalker (Float, Uninteractible, LargeAOI)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=29684 AND `DifficultyID`=2); -- Ticking Bomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=29630 AND `DifficultyID`=2); -- Fanged Pit Viper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=27989 AND `DifficultyID`=2); -- D.I.S.C.O.
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=27894 AND `DifficultyID`=2); -- Antipersonnel Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=27893 AND `DifficultyID`=2); -- Rune Weapon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=27829 AND `DifficultyID`=2); -- Ebon Gargoyle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=26125 AND `DifficultyID`=2); -- Risen Ghoul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=25985 AND `DifficultyID`=2); -- Ahune Ice Spear Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=25757 AND `DifficultyID`=2); -- Ahunite Frostwind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=24207 AND `DifficultyID`=2); -- Army of the Dead
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=23115 AND `DifficultyID`=2); -- Ogri'la Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=19668 AND `DifficultyID`=2); -- Shadowfiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=17966 AND `DifficultyID`=2); -- Action Trigger Test Creature For Kyle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=17252 AND `DifficultyID`=2); -- Felguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=15139 AND `DifficultyID`=2); -- Gahz'ranka Herald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=15106 AND `DifficultyID`=2); -- Frostwolf Envoy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=15103 AND `DifficultyID`=2); -- Stormpike Emissary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14948 AND `DifficultyID`=2); -- Vipore's Gryphon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14947 AND `DifficultyID`=2); -- Ichman's Gryphon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14946 AND `DifficultyID`=2); -- Slidore's Gryphon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14945 AND `DifficultyID`=2); -- Mulverick's War Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14944 AND `DifficultyID`=2); -- Jeztor's War Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14943 AND `DifficultyID`=2); -- Guse's War Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14848 AND `DifficultyID`=2); -- Herald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14777 AND `DifficultyID`=2); -- West Frostwolf Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14776 AND `DifficultyID`=2); -- Tower Point Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14775 AND `DifficultyID`=2); -- Stonehearth Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14774 AND `DifficultyID`=2); -- Icewing Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14773 AND `DifficultyID`=2); -- Iceblood Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14772 AND `DifficultyID`=2); -- East Frostwolf Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14771 AND `DifficultyID`=2); -- Dun Baldar South Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14770 AND `DifficultyID`=2); -- Dun Baldar North Warmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14769 AND `DifficultyID`=2); -- West Frostwolf Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14768 AND `DifficultyID`=2); -- East Frostwolf Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14767 AND `DifficultyID`=2); -- Tower Point Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14766 AND `DifficultyID`=2); -- Iceblood Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14765 AND `DifficultyID`=2); -- Stonehearth Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14764 AND `DifficultyID`=2); -- Icewing Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14763 AND `DifficultyID`=2); -- Dun Baldar South Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14762 AND `DifficultyID`=2); -- Dun Baldar North Marshal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14746 AND `DifficultyID`=2); -- [PH] Horde Tower Lieutenant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14719 AND `DifficultyID`=2); -- [PH] Alliance Tower Lieutenant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14644 AND `DifficultyID`=2); -- [PH] Horde Herald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14643 AND `DifficultyID`=2); -- [PH] Alliance Herald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14285 AND `DifficultyID`=2); -- Frostwolf Battleguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14284 AND `DifficultyID`=2); -- Stormpike Battleguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14283 AND `DifficultyID`=2); -- Stormpike Owl
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14282 AND `DifficultyID`=2); -- Frost Wolf Bloodhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14188 AND `DifficultyID`=2); -- Dirk Swindle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14187 AND `DifficultyID`=2); -- Athramanis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14186 AND `DifficultyID`=2); -- Ravak Grimtotem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14185 AND `DifficultyID`=2); -- Najak Hexxen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14142 AND `DifficultyID`=2); -- Frostwolf Reclaimer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14141 AND `DifficultyID`=2); -- Stormpike Reclaimer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14031 AND `DifficultyID`=2); -- Trigger Vipore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14030 AND `DifficultyID`=2); -- Trigger Slidore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14029 AND `DifficultyID`=2); -- Trigger Ichman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14028 AND `DifficultyID`=2); -- Trigger Jeztor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14027 AND `DifficultyID`=2); -- Trigger Mulverick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14026 AND `DifficultyID`=2); -- Trigger Guse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14019 AND `DifficultyID`=2); -- Tatterhide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14018 AND `DifficultyID`=2); -- Rezrelek
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14017 AND `DifficultyID`=2); -- Withered Troll
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=14016 AND `DifficultyID`=2); -- Ushalac the Gloomdweller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13977 AND `DifficultyID`=2); -- Gash'nak the Cannibal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13959 AND `DifficultyID`=2); -- Alterac Yeti
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13956 AND `DifficultyID`=2); -- Winterax Mystic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13798 AND `DifficultyID`=2); -- Jotek
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13797 AND `DifficultyID`=2); -- Mountaineer Boombellow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13676 AND `DifficultyID`=2); -- Stabled Alterac Ram
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13618 AND `DifficultyID`=2); -- Stabled Frost Wolf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13598 AND `DifficultyID`=2); -- Stormpike Explosives Expert
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13597 AND `DifficultyID`=2); -- Frostwolf Explosives Expert
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13557 AND `DifficultyID`=2); -- Champion Irondeep Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13556 AND `DifficultyID`=2); -- Veteran Irondeep Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13555 AND `DifficultyID`=2); -- Seasoned Irondeep Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13554 AND `DifficultyID`=2); -- Champion Irondeep Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13553 AND `DifficultyID`=2); -- Veteran Irondeep Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13552 AND `DifficultyID`=2); -- Seasoned Irondeep Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13551 AND `DifficultyID`=2); -- Champion Coldmine Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13550 AND `DifficultyID`=2); -- Veteran Coldmine Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13549 AND `DifficultyID`=2); -- Seasoned Coldmine Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13548 AND `DifficultyID`=2); -- Champion Coldmine Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13547 AND `DifficultyID`=2); -- Veteran Coldmine Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13546 AND `DifficultyID`=2); -- Seasoned Coldmine Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13545 AND `DifficultyID`=2); -- Champion Irondeep Raider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13544 AND `DifficultyID`=2); -- Veteran Irondeep Raider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13543 AND `DifficultyID`=2); -- Seasoned Irondeep Raider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13542 AND `DifficultyID`=2); -- Champion Irondeep Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13541 AND `DifficultyID`=2); -- Veteran Irondeep Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13540 AND `DifficultyID`=2); -- Seasoned Irondeep Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13539 AND `DifficultyID`=2); -- Champion Coldmine Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13538 AND `DifficultyID`=2); -- Veteran Coldmine Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13537 AND `DifficultyID`=2); -- Seasoned Coldmine Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13536 AND `DifficultyID`=2); -- Champion Coldmine Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13535 AND `DifficultyID`=2); -- Veteran Coldmine Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13534 AND `DifficultyID`=2); -- Seasoned Coldmine Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13522 AND `DifficultyID`=2); -- Veteran Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13521 AND `DifficultyID`=2); -- Seasoned Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13520 AND `DifficultyID`=2); -- Stormpike Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13518 AND `DifficultyID`=2); -- Veteran Outrunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13517 AND `DifficultyID`=2); -- Seasoned Outrunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13516 AND `DifficultyID`=2); -- Frostwolf Outrunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13496 AND `DifficultyID`=2); -- Risen Ancient
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13449 AND `DifficultyID`=2); -- Warmaster Garrick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13448 AND `DifficultyID`=2); -- Sergeant Yazra Bloodsnarl
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13447 AND `DifficultyID`=2); -- Corporal Noreg Stormpike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13443 AND `DifficultyID`=2); -- Druid of the Grove
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13441 AND `DifficultyID`=2); -- Frostwolf Wolf Rider Commander
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13439 AND `DifficultyID`=2); -- Wing Commander Vipore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13438 AND `DifficultyID`=2); -- Wing Commander Slidore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13437 AND `DifficultyID`=2); -- Wing Commander Ichman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13424 AND `DifficultyID`=2); -- Champion Guardsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13416 AND `DifficultyID`=2); -- Stormpike Shredder Unit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13397 AND `DifficultyID`=2); -- Irondeep Peon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13396 AND `DifficultyID`=2); -- Irondeep Miner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13378 AND `DifficultyID`=2); -- Frostwolf Shredder Unit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13377 AND `DifficultyID`=2); -- Master Engineer Zinfizzlex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13359 AND `DifficultyID`=2); -- Frostwolf Bowman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13358 AND `DifficultyID`=2); -- Stormpike Bowman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13357 AND `DifficultyID`=2); -- Frostwolf Mine Layer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13356 AND `DifficultyID`=2); -- Stormpike Mine Layer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13336 AND `DifficultyID`=2); -- Veteran Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13333 AND `DifficultyID`=2); -- Veteran Guardsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13327 AND `DifficultyID`=2); -- Seasoned Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13324 AND `DifficultyID`=2); -- Seasoned Guardsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13320 AND `DifficultyID`=2); -- Commander Karl Philips
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13319 AND `DifficultyID`=2); -- Commander Duffy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13318 AND `DifficultyID`=2); -- Commander Mortimer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13317 AND `DifficultyID`=2); -- Coldmine Miner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13316 AND `DifficultyID`=2); -- Coldmine Peon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13300 AND `DifficultyID`=2); -- Lieutenant Mancuso
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13299 AND `DifficultyID`=2); -- Lieutenant Lonadin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13298 AND `DifficultyID`=2); -- Lieutenant Greywand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13297 AND `DifficultyID`=2); -- Lieutenant Stouthandle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13296 AND `DifficultyID`=2); -- Lieutenant Largent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13284 AND `DifficultyID`=2); -- Frostwolf Shaman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13281 AND `DifficultyID`=2); -- Furis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13257 AND `DifficultyID`=2); -- Murgot Deepforge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13221 AND `DifficultyID`=2); -- Ryson's Eye in the Sky
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13218 AND `DifficultyID`=2); -- Grunnda Wolfheart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13216 AND `DifficultyID`=2); -- Gaelden Hammersmith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13181 AND `DifficultyID`=2); -- Wing Commander Mulverick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13180 AND `DifficultyID`=2); -- Wing Commander Jeztor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13179 AND `DifficultyID`=2); -- Wing Commander Guse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13178 AND `DifficultyID`=2); -- War Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13176 AND `DifficultyID`=2); -- Smith Regzar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13161 AND `DifficultyID`=2); -- Aerie Gryphon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13155 AND `DifficultyID`=2); -- Deathstalker Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13154 AND `DifficultyID`=2); -- Commander Louis Philips
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13153 AND `DifficultyID`=2); -- Commander Mulfort
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13152 AND `DifficultyID`=2); -- Commander Malgor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13151 AND `DifficultyID`=2); -- Syndicate Master Ryson
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13150 AND `DifficultyID`=2); -- Syndicate Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13149 AND `DifficultyID`=2); -- Syndicate Brigand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13147 AND `DifficultyID`=2); -- Lieutenant Lewis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13146 AND `DifficultyID`=2); -- Lieutenant Murp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13145 AND `DifficultyID`=2); -- Lieutenant Grummus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13144 AND `DifficultyID`=2); -- Lieutenant Vol'talar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13143 AND `DifficultyID`=2); -- Lieutenant Stronghoof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13139 AND `DifficultyID`=2); -- Commander Randolph
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13137 AND `DifficultyID`=2); -- Lieutenant Rugba
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13099 AND `DifficultyID`=2); -- Irondeep Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13098 AND `DifficultyID`=2); -- Irondeep Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13097 AND `DifficultyID`=2); -- Coldmine Surveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13096 AND `DifficultyID`=2); -- Coldmine Explorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13089 AND `DifficultyID`=2); -- Coldmine Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13088 AND `DifficultyID`=2); -- Masha Swiftcut
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13087 AND `DifficultyID`=2); -- Coldmine Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13086 AND `DifficultyID`=2); -- Aggi Rumblestomp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13081 AND `DifficultyID`=2); -- Irondeep Raider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13080 AND `DifficultyID`=2); -- Irondeep Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13079 AND `DifficultyID`=2); -- Keetar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=13078 AND `DifficultyID`=2); -- Umi Thorson
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12158 AND `DifficultyID`=2); -- Winterax Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12156 AND `DifficultyID`=2); -- Winterax Axe Thrower
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12127 AND `DifficultyID`=2); -- Stormpike Guardsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12122 AND `DifficultyID`=2); -- Duros
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12121 AND `DifficultyID`=2); -- Drakan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12097 AND `DifficultyID`=2); -- Frostwolf Quartermaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12096 AND `DifficultyID`=2); -- Stormpike Quartermaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12053 AND `DifficultyID`=2); -- Frostwolf Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12048 AND `DifficultyID`=2); -- Alliance Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=12047 AND `DifficultyID`=2); -- Stormpike Mountaineer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11998 AND `DifficultyID`=2); -- Frostwolf Herald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11997 AND `DifficultyID`=2); -- Stormpike Herald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11949 AND `DifficultyID`=2); -- Captain Balinda Stonehearth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11948 AND `DifficultyID`=2); -- Vanndar Stormpike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11947 AND `DifficultyID`=2); -- Captain Galvangar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11946 AND `DifficultyID`=2); -- Drek'Thar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11840 AND `DifficultyID`=2); -- Wildpaw Alpha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11839 AND `DifficultyID`=2); -- Wildpaw Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11838 AND `DifficultyID`=2); -- Wildpaw Mystic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11837 AND `DifficultyID`=2); -- Wildpaw Shaman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11678 AND `DifficultyID`=2); -- Snowblind Ambusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11677 AND `DifficultyID`=2); -- Taskmaster Snivvle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11676 AND `DifficultyID`=2); -- Fjordune the Greater
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11675 AND `DifficultyID`=2); -- Snowblind Windcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11657 AND `DifficultyID`=2); -- Morloch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11606 AND `DifficultyID`=2); -- Whitewhisker Tunnel Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11605 AND `DifficultyID`=2); -- Whitewhisker Overseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11604 AND `DifficultyID`=2); -- Whitewhisker Geomancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11603 AND `DifficultyID`=2); -- Whitewhisker Digger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11602 AND `DifficultyID`=2); -- Irondeep Skullthumper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=11600 AND `DifficultyID`=2); -- Irondeep Shaman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10991 AND `DifficultyID`=2); -- Wildpaw Gnoll
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10990 AND `DifficultyID`=2); -- Alterac Ram
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10989 AND `DifficultyID`=2); -- Blizzard Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10987 AND `DifficultyID`=2); -- Irondeep Trogg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10986 AND `DifficultyID`=2); -- Snowblind Harpy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10985 AND `DifficultyID`=2); -- Ice Giant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10982 AND `DifficultyID`=2); -- Whitewhisker Vermin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10981 AND `DifficultyID`=2); -- Frost Wolf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10367 AND `DifficultyID`=2); -- Shrye Ragefist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=10364 AND `DifficultyID`=2); -- Yaelika Farclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=6112 AND `DifficultyID`=2); -- Windfury Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=5139 AND `DifficultyID`=2); -- Kurdrum Barleybeard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=5135 AND `DifficultyID`=2); -- Svalbrad Farmountain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=5134 AND `DifficultyID`=2); -- Jonivera Farmountain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=4257 AND `DifficultyID`=2); -- Lana Thunderbrew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=4255 AND `DifficultyID`=2); -- Brogus Thunderbrew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=3625 AND `DifficultyID`=2); -- Rarck
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=3527 AND `DifficultyID`=2); -- Healing Stream Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=3343 AND `DifficultyID`=2); -- Grelkor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=2225 AND `DifficultyID`=2); -- Zora Guthrek
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=603 AND `DifficultyID`=2); -- Grimtooth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=89 AND `DifficultyID`=2); -- Infernal

