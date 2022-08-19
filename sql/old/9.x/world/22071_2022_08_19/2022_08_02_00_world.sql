DELETE FROM `creature_questitem` WHERE `CreatureEntry` IN (99611,33288,17882,26723,23954,118289,18344,29120);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(99611, 4, 139453, 43206), -- Dantalionax
(99611, 3, 139319, 43206), -- Dantalionax
(99611, 2, 138969, 43206), -- Dantalionax
(99611, 1, 138971, 43206), -- Dantalionax
(99611, 0, 138968, 43206), -- Dantalionax
(33288, 0, 157030, 43340), -- Yogg-Saron
(17882, 0, 33826, 43345), -- The Black Stalker
(17882, 1, 24248, 43345), -- The Black Stalker
(17882, 2, 24427, 43345), -- The Black Stalker
(26723, 0, 43665, 43345), -- Keristrasza
(23954, 0, 33330, 43345), -- Ingvar the Plunderer
(23954, 1, 43662, 43345), -- Ingvar the Plunderer
(118289, 0, 151249, 43345), -- Maiden of Vigilance
(118289, 1, 151250, 43345), -- Maiden of Vigilance
(118289, 2, 151248, 43345), -- Maiden of Vigilance
(18344, 0, 28490, 43345), -- Nexus-Prince Shaffar
(18344, 1, 33835, 43345), -- Nexus-Prince Shaffar
(29120, 0, 43726, 43345), -- Anub'arak
(29120, 1, 43411, 43345); -- Anub'arak

UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=580.0128173828125 WHERE `entry`=180773; -- Vigilant Guardian
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=470.25 WHERE `entry`=181398; -- Mal'Ganis
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=470.25 WHERE `entry`=181399; -- Kin'tessa
UPDATE `creature_template` SET `HealthScalingExpansion`=8 WHERE `entry` IN (181925, 182039, 183664, 183665, 183666, 183973, 184519, 184527, 184528, 184533, 184534, 184535, 184576, 184577, 184585, 184597, 184599, 184601, 184613, 184627, 184830, 185145, 185154, 185155, 185268, 185271, 185274, 185402, 185499, 186785);
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=992.75 WHERE `entry`=181954; -- Anduin Wrynn
UPDATE `creature_template` SET `HealthScalingExpansion`=0 WHERE `entry` IN (111068, 153851, 153876, 122968, 127503, 98637, 135448, 136160, 102266, 177269, 141806);
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=441 WHERE `entry`=182777; -- Rygelon
UPDATE `creature_template` SET `HealthScalingExpansion`=8 WHERE `entry`=182778; -- Collapsing Quasar
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=8 WHERE `entry`=183033; -- Grim Reflection
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=3 WHERE `entry`=183138; -- Inchoate Shadow
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=1045 WHERE `entry`=183463; -- Remnant of a Fallen King
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=8 WHERE `entry`=183669; -- Fiendish Soul
UPDATE `creature_template` SET `HealthScalingExpansion`=8 WHERE `entry`=183793; -- March of the Damned
UPDATE `creature_template` SET `HealthScalingExpansion`=8 WHERE `entry`=183945; -- Unstable Matter
UPDATE `creature_template` SET `HealthModifier`=5 WHERE `entry`=163122; -- Brittlebone Warrior
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=56395; -- Shado-Pan Novice
UPDATE `creature_template` SET `HealthModifier`=50 WHERE `entry`=56439; -- Sha of Doubt
UPDATE `creature_template` SET `HealthModifier`=37.5 WHERE `entry`=56448; -- Wise Mari
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=56472; -- Fragrant Lotus
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=56473; -- Flying Snow
UPDATE `creature_template` SET `HealthModifier`=9.375 WHERE `entry`=56511; -- Corrupt Living Water
UPDATE `creature_template` SET `HealthModifier`=42.5 WHERE `entry`=56541; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=56542; -- Splash Stalker
UPDATE `creature_template` SET `HealthModifier`=45 WHERE `entry`=56589; -- Striker Ga'dok
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=56631; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=45 WHERE `entry`=56636; -- Commander Ri'mok
UPDATE `creature_template` SET `HealthModifier`=57.5 WHERE `entry`=56637; -- Ook-Ook
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=56640; -- Ball of Fire
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=56646; -- Fire Flower
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=56658; -- Corrupt Droplet
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=56678; -- Jade Staff
UPDATE `creature_template` SET `HealthModifier`=0.150000005960464477 WHERE `entry`=56713; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=45 WHERE `entry`=56717; -- Hoptallus
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=56718; -- Hopper
UPDATE `creature_template` SET `HealthModifier`=55 WHERE `entry`=56719; -- Sha of Violence
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=56731; -- Habanero Brew
UPDATE `creature_template` SET `HealthModifier`=37.5 WHERE `entry`=56732; -- Liu Flameheart
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=56746; -- Fizzy Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=35 WHERE `entry`=56747; -- Gu Cloudstrike
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=56748; -- Sudsy Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=25 WHERE `entry`=56754; -- Azure Serpent
UPDATE `creature_template` SET `HealthModifier`=37.5 WHERE `entry`=56762; -- Yu'lon
UPDATE `creature_template` SET `HealthModifier`=6 WHERE `entry`=56763; -- Regenerating Sha
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=56764; -- Consuming Sha
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=56765; -- Destroying Sha
UPDATE `creature_template` SET `HealthModifier`=1.875 WHERE `entry`=56766; -- Volatile Energy
UPDATE `creature_template` SET `HealthModifier`=4 WHERE `entry`=56767; -- Shado-Pan Fire Archer
UPDATE `creature_template` SET `HealthModifier`=3.75 WHERE `entry`=56783; -- Hozen Hollerer
UPDATE `creature_template` SET `HealthModifier`=1.875 WHERE `entry`=56792; -- Figment of Doubt
UPDATE `creature_template` SET `HealthModifier`=37.5 WHERE `entry`=56849; -- Hozen Bouncer
UPDATE `creature_template` SET `HealthModifier`=1 WHERE `entry`=164363; -- Undying Stonefiend
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=56862; -- Drunken Hozen Brawler
UPDATE `creature_template` SET `HealthModifier`=9.375 WHERE `entry`=56863; -- Sleepy Hozen Brawler
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=56865; -- Aqua Dancer
UPDATE `creature_template` SET `HealthModifier`=0.75, `ManaModifier`=1 WHERE `entry`=56867; -- Fiery Trickster
UPDATE `creature_template` SET `HealthModifier`=3.75 WHERE `entry`=56870; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=56875; -- Krik'thik Demolisher
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=56876; -- Krik'thik Sapper
UPDATE `creature_template` SET `HealthModifier`=62.5 WHERE `entry`=56877; -- Raigonn
UPDATE `creature_template` SET `HealthModifier`=45 WHERE `entry`=56884; -- Taran Zhu
UPDATE `creature_template` SET `HealthModifier`=3.75 WHERE `entry`=56889; -- Serpent's Spine Defender
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=56890; -- Krik'thik Infiltrator
UPDATE `creature_template` SET `HealthModifier`=8 WHERE `entry`=56895; -- Weak Spot
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=56896; -- Volatile Munitions
UPDATE `creature_template` SET `HealthModifier`=45 WHERE `entry`=56906; -- Saboteur Kip'tilak
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=56915; -- Sun
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=56917; -- Stable Munitions
UPDATE `creature_template` SET `HealthModifier`=11.25 WHERE `entry`=56924; -- Inflamed Hozen Brawler
UPDATE `creature_template` SET `HealthModifier`=1.125 WHERE `entry`=56927; -- Hozen Party Animal
UPDATE `creature_template` SET `HealthModifier`=4.5 WHERE `entry`=56930; -- Krik'thik Swarm Bringer
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=57080; -- Corrupted Scroll
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=57097; -- Hozen Party Animal
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=57109; -- Minion of Doubt
UPDATE `creature_template` SET `HealthModifier`=1 WHERE `entry`=164702; -- Carrion Worm
UPDATE `creature_template` SET `HealthModifier`=4.5 WHERE `entry`=165260; -- Oozing Leftovers
UPDATE `creature_template` SET `HealthModifier`=2 WHERE `entry`=165556; -- Fleeting Manifestation
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=58108; -- Krik'thik Infiltrator
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=58198; -- Shado-Pan Disciple
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=58201; -- Sha Manifestation
UPDATE `creature_template` SET `HealthModifier`=30 WHERE `entry`=58202; -- Serpent's Spine Defender
UPDATE `creature_template` SET `HealthModifier`=2.8125 WHERE `entry`=58319; -- Lesser Sha
UPDATE `creature_template` SET `HealthModifier`=9, `ManaModifier`=47.25400161743164062 WHERE `entry`=58803; -- Residual Hatred
UPDATE `creature_template` SET `HealthModifier`=12 WHERE `entry`=58807; -- Vestige of Hatred
UPDATE `creature_template` SET `HealthModifier`=12 WHERE `entry`=58810; -- Fragment of Hatred
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=58815; -- Swirling Sunfire
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=58826; -- Zao Sunseeker
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=58856; -- Haunting Sha
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=58865; -- Haunting Sha
UPDATE `creature_template` SET `HealthModifier`=7.5 WHERE `entry`=59074; -- Uncle Gao
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=59075; -- Ancestral Brewmaster
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=59426; -- Bopper
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=59458; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=59459; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=59460; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=59461; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=59464; -- Hopper
UPDATE `creature_template` SET `HealthModifier`=50 WHERE `entry`=59479; -- Yan-Zhu the Uncasked
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=59494; -- Yeasty Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=59519; -- Stout Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=11.25 WHERE `entry`=59520; -- Fizzy Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=11.25 WHERE `entry`=59522; -- Sudsy Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=5.625 WHERE `entry`=59544; -- The Nodding Tiger
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=59545; -- The Golden Beetle
UPDATE `creature_template` SET `HealthModifier`=15, `ManaModifier`=7 WHERE `entry`=59546; -- The Talking Fish
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=59547; -- Jiang
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=59551; -- Bopper
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=59552; -- The Crybaby Hozen
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=59553; -- The Songbird Queen
UPDATE `creature_template` SET `HealthModifier`=9.375 WHERE `entry`=59555; -- Haunting Sha
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=59598; -- Lesser Sha
UPDATE `creature_template` SET `HealthModifier`=13.125 WHERE `entry`=59605; -- Sodden Hozen Brawler
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=59684; -- Hozen Party Animal
UPDATE `creature_template` SET `HealthModifier`=22.5 WHERE `entry`=59704; -- Chen Stormstout
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=59741; -- Shado-Pan Guardian
UPDATE `creature_template` SET `HealthModifier`=13.5 WHERE `entry`=59751; -- Shado-Pan Warden
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=59752; -- Shado-Pan Ambusher
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=59800; -- Krik'thik Rager
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=59801; -- Krik'thik Wind Shaper
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=59804; -- Gripping Hatred
UPDATE `creature_template` SET `HealthModifier`=5.25 WHERE `entry`=59808; -- Shado-Pan Stormbringer
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=59811; -- Unstable Energy
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=59822; -- Auntie Stormstout
UPDATE `creature_template` SET `HealthModifier`=0.075000002980232238 WHERE `entry`=59824; -- Golden Hopling
UPDATE `creature_template` SET `HealthModifier`=0.5 WHERE `entry`=59835; -- Krik'thik Swarmer
UPDATE `creature_template` SET `HealthModifier`=9.375 WHERE `entry`=59873; -- Corrupt Living Water
UPDATE `creature_template` SET `HealthModifier`=1.875 WHERE `entry`=59891; -- Fallen Jin'yu
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=59895; -- Shado-Pan Monk
UPDATE `creature_template` SET `HealthModifier`=0.224999994039535522 WHERE `entry`=60005; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=0.224999994039535522 WHERE `entry`=60006; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=0.224999994039535522 WHERE `entry`=60007; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=60208; -- Hopling
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=60276; -- Hozen Clinger
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=61213; -- Krik'thik Conscript
UPDATE `creature_template` SET `HealthModifier`=13.5, `ManaModifier`=9.450799942016601562 WHERE `entry`=61216; -- Glintrok Hexxer
UPDATE `creature_template` SET `HealthModifier`=13.5, `ManaModifier`=9.450799942016601562 WHERE `entry`=61239; -- Glintrok Oracle
UPDATE `creature_template` SET `HealthModifier`=15.75 WHERE `entry`=61240; -- Glintrok Skulker
UPDATE `creature_template` SET `HealthModifier`=18 WHERE `entry`=61242; -- Glintrok Ironhide
UPDATE `creature_template` SET `HealthModifier`=45 WHERE `entry`=61243; -- Gekkan
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=61247; -- Glintrok Greenhorn
UPDATE `creature_template` SET `HealthModifier`=18 WHERE `entry`=61337; -- Glintrok Ironhide
UPDATE `creature_template` SET `HealthModifier`=15.75 WHERE `entry`=61338; -- Glintrok Skulker
UPDATE `creature_template` SET `HealthModifier`=13.5, `ManaModifier`=9.450799942016601562 WHERE `entry`=61339; -- Glintrok Oracle
UPDATE `creature_template` SET `HealthModifier`=13.5, `ManaModifier`=9.450799942016601562 WHERE `entry`=61340; -- Glintrok Hexxer
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=61387; -- Quilen Guardian
UPDATE `creature_template` SET `HealthModifier`=12 WHERE `entry`=61389; -- Kargesh Highguard
UPDATE `creature_template` SET `HealthModifier`=6 WHERE `entry`=61392; -- Harthak Flameseeker
UPDATE `creature_template` SET `HealthModifier`=50 WHERE `entry`=61398; -- Xin the Weaponmaster
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=61399; -- Glintrok Scout
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61415; -- Giant Cave Bat
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61431; -- Glintrok Scout
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61432; -- Glintrok Pillager
UPDATE `creature_template` SET `HealthModifier`=30 WHERE `entry`=61442; -- Kuai the Brute
UPDATE `creature_template` SET `HealthModifier`=33.75 WHERE `entry`=61444; -- Ming the Cunning
UPDATE `creature_template` SET `HealthModifier`=33.75 WHERE `entry`=61445; -- Haiyan the Unstoppable
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=61447; -- Gurthan Scrapper
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=61449; -- Harthak Adept
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=61450; -- Kargesh Grunt
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=61453; -- Mu'Shiba
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61455; -- Gurthan Quilen
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61549; -- Gurthan Scrapper
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61550; -- Harthak Adept
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=61551; -- Kargesh Grunt
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=61679; -- Crossbow
UPDATE `creature_template` SET `HealthModifier`=75 WHERE `entry`=61884; -- Xin the Weaponmaster
UPDATE `creature_template` SET `HealthModifier`=6 WHERE `entry`=61945; -- Gurthan Iron Maw
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=61946; -- Harthak Stormcaller
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=61947; -- Kargesh Ribcrusher
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=62171; -- Serpent Warrior
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=62358; -- Corrupt Droplet
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=62360; -- Corrupt Droplet
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=63717; -- Shado-Pan Disciple
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=63739; -- Quilen Statue
UPDATE `creature_template` SET `HealthModifier`=0.75, `movementId`=144 WHERE `entry`=64243; -- Glintrok Scout
UPDATE `creature_template` SET `HealthModifier`=30 WHERE `entry`=64387; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=64547; -- Gurthan Scrapper
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=64548; -- Kargesh Grunt
UPDATE `creature_template` SET `HealthModifier`=9 WHERE `entry`=64549; -- Shado-Pan Ice Archer
UPDATE `creature_template` SET `HealthModifier`=3.75 WHERE `entry`=65111; -- Serpent's Spine Defender
UPDATE `creature_template` SET `HealthModifier`=2.25 WHERE `entry`=65257; -- Unleashed Sha
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=65317; -- Xiang
UPDATE `creature_template` SET `HealthModifier`=3.75 WHERE `entry`=65337; -- Serpent's Spine Defender
UPDATE `creature_template` SET `HealthModifier`=15 WHERE `entry`=65362; -- Minion of Doubt
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=65375; -- Ancestral Brewmaster
UPDATE `creature_template` SET `HealthModifier`=0.375 WHERE `entry`=65376; -- Ancestral Brewmaster
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=65392; -- Nibbler
UPDATE `creature_template` SET `HealthModifier`=6.75 WHERE `entry`=65402; -- Gurthan Swiftblade
UPDATE `creature_template` SET `HealthModifier`=6 WHERE `entry`=65414; -- Ethereal Sha
UPDATE `creature_template` SET `HealthModifier`=5.25 WHERE `entry`=66413; -- Yeasty Brew Alemental
UPDATE `creature_template` SET `HealthModifier`=0.5 WHERE `entry`=66652; -- Lesser Volatile Energy
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=67229; -- Master Snowdrift
UPDATE `creature_template` SET `HealthModifier`=0.75 WHERE `entry`=67231; -- Trial of the King

DELETE FROM `gameobject_template` WHERE `entry` IN (374999,375058,375366,375025,375383,369781,375992,373588,373591,370497,370435,373504,370173,352012,370016,373478,373503,375106,370332,373561,359153,375759,370455,375347,373562,369685,370498,373479,375223,
370285,375070,370175,375222,373466,370468,375536,370405,370196,375085,375088,375166,370193,375132,375089,375167,375148,375136,370522,370471,375157,375207,375159,375142,370174,370180,375357,352006,370346,370525,375391,375151,357214,370521,357221,375087,
375388,375139,373521,375134,375370,375974,375138,375082,375092,370472,370172,375141,375150,375152,375160,370520,370524,375901,370198,375889,375192,375154,375390,373443,375981,370518,375158,375147,375091,375083,375133,375155,375164,375161,375153,375137,
375086,375146,375156,375144,370171,375084,375143,370470,375090,375393,375149,375081,375747,370183,370519,375988,375165,375163,375135,375145,375140,375389,375162,375905,375486,375407,375371,370199,370458,369259,368939,368990,375003,369466,357216,368942,
369464,375008,368991,345443,368383,375093,368249,368381,368937,369892,375950,373483,369889,369316,370083,369315,368940,374928,369888,375002,369465,369887,357215,376252,369467,368382,365063,368941,374927,368943,375675,368247,370457,357213,373505,373643,
375345,375879,375694,357219,369314,357218,373463,373584,357217,339277,364482,375483,368222,375368,374975,368670,373496,368671,351870,325470,368672,368673,361338,245074,368364,245108,361334,245653,359887,361342,368365,367952,349796,359841,369104,367954,
245097,245082,368353,365355,249745,358384,359850,359848,248576,359870,367950,368348,367955,368352,251315,367956,268611,359892,245642,245078,369105,357093,359877,367964,361301,352754,245072,358380,367953,367940,353078,359871,260282,367963,245129,369103,
359866,353079,368359,359854,368349,359890,245132,359881,367985,353516,353080,359875,260285,359900,353515,367951,359843,359852,368355,368366,359862,367960,368354,368361,367962,248556,361379,245081,245654,260283,355208,368367,359886,359857,374972,367958,
367944,245131,361336,359885,359898,245130,368301,352750,359861,359878,359855,245076,356881,245125,359847,367941,369106,252186,368351,359845,375678,359896,265512,352752,245636,353072,368362,374974,245655,353517,359891,364413,268454,359882,368363,359883,
359860,359888,359859,357260,359846,355971,373484,361353,251676,245055,356398,367961,359895,245098,361339,369107,358383,353331,359893,260286,356728,359864,265511,367957,367959,361297,368350,245073,245128,358297,359865,368627,356539,359880,367943,363581,
367942,376249,375502,245077,353251,356752,250988,260284,375495,368771,373526,340058,370140,375423,373525,370507,374925,368680,368598,368658,375272,368657,375766,368988,375984,368597,368887,369218,373551,370449,373594,373494,375524,368755,373549,375359,
375533,375977,369220,375405,368669,375485,279657,375534,376026,375384,340085,368888,369342,369219,375480,375382,356705,356748,373517,375985,375369,369192,370389,373527,375385,375281,375030,370505,369262,369186,369606,369188,375765,375386,368656,373495,
368603,375532,368770,368987,369190,368595,373548,375287,374924,369187,375354,373649,369172,370403,375422,375224,373461,369227,375987,375986,375392,354075,368660,354192,368360,357336,357156,358358,356607,325436,354438,368625,375191,374976,353090,236857,
373520,368356,356697,358360,356596,343588,353817,376251,243761,353075,353325,375676,356597,355844,368626,353328,353088,361320,368357,356733,357338,361361,376569,236866,373519,357206,353067,353089,369235,353073,361352,358362,357335,353322,343586,355845,
375189,357159,236858,236863,357337,353084,375190,368221,361381,368358,357252,369313,361319,236862,355826,357205,355877,361348,357245,356720,356700,356693,377031,376514,368631,230839,234284,234266,367990,357254,339941,272805,234281,376258,230838,367987,
376106,375874,376323,376320,376108,376989,375990,376987,279008,376986,376988,278983,376322,278980,278981,376321,376897,376109,278982,376107);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(374999, 5, 71364, 'Charged Orb', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Charged Orb
(375058, 10, 72024, 'Toccatian Cache', '', 'Inspecting', '', 0.5, 2034, 0, 0, 10000, 0, 0, 1, 0, 0, 109, 369493, 0, 0, 1, 157298, 0, 0, 0, 1, 27637, 1, 0, 93710, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Toccatian Cache
(375366, 50, 15121, 'Tarachnid Eggs', 'questinteract', 'Searching', '', 2, 1691, 109803, 0, 0, 0, 0, 90, 0, 0, 19680, 0, 0, 0, 3, 365820, 0, 0, 4971, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Tarachnid Eggs
(375025, 10, 71460, 'Teleporter', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 27494, 0, 0, 93695, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Teleporter
(375383, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.300000011920928955, 1691, 109580, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Protoform Schematic
(369781, 10, 69194, 'Neglected Conductor', 'questinteract', 'Calling Koh Shira', '', 1, 1691, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 359918, 0, 0, 0, 212844, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Neglected Conductor
(375992, 5, 72523, 'Blocked Door', '', '', '', 1.159999966621398925, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Blocked Door
(373588, 10, 71463, 'Mercurial Concordance', 'inspect', '', '', 1, 1634, 0, 0, 3000, 0, 0, 0, 8395, 297, 109, 362219, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 94126, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Mercurial Concordance
(373591, 6, 71933, 'Empowered Punisher Mine', '', '', '', 1.60000002384185791, 0, 78, 3, 362487, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Empowered Punisher Mine
(370497, 10, 71702, 'Quadrangular Altar', 'questinteract', 'Activating', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 363752, 0, 0, 0, 27700, 0, 0, 0, 0, 0, 1, 0, 94575, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2057, 42560), -- Quadrangular Altar
(370435, 0, 69946, 'Door', '', '', '', 1, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Door
(373504, 5, 72011, 'Repository Conduit', '', '', '', 0.60000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Repository Conduit
(370173, 5, 71228, 'Progenitor Soul Orb', '', '', '', 0.999998986721038818, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Progenitor Soul Orb
(352012, 5, 60780, 'Statue of Denathrius', '', '', '', 1.470000028610229492, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Statue of Denathrius
(370016, 30, 71064, 'Ancient Tablet', '', '', '', 3, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Ancient Tablet
(373478, 6, 71933, 'Punisher Mine', '', '', '', 0.800000011920928955, 0, 78, 5, 361213, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Punisher Mine
(373503, 10, 71607, 'Repository Console', 'speak', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27555, 0, 0, 94973, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2057, 42560), -- Repository Console
(375106, 3, 70455, 'Instructional Bit', 'questinteract', 'Collecting', '', 0.5, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109485, 0, 0, 0, 0, 2057, 42560), -- Instructional Bit
(370332, 10, 71284, 'Button', 'questinteract', '', '', 0.60000002384185791, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 359773, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93374, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Button
(373561, 50, 71678, 'Forgotten Proto-Vault', '', 'Opening', '', 1, 1691, 109075, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4926, 10, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Forgotten Proto-Vault
(359153, 5, 62930, 'Nest', '', '', '', 0.100000001490116119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Nest
(375759, 10, 71393, 'Runic Syllable', 'questinteract', '', '', 1.20000004768371582, 3400, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 367490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 95688, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 42560), -- Runic Syllable
(370455, 10, 69194, 'Neglected Conductor', 'questinteract', 'Calling Koh Shira', '', 1, 1691, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 359921, 0, 0, 0, 212844, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Neglected Conductor
(375347, 5, 72220, 'Barrier', '', '', '', 0.800000011920928955, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Barrier
(373562, 10, 71463, 'Excitable Concordance', 'inspect', '', '', 1, 1634, 0, 0, 3000, 0, 0, 0, 8382, 297, 109, 362219, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 94126, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Excitable Concordance
(369685, 10, 69194, 'Terraforming Record', 'questinteract', 'Activating', '', 1, 1691, 0, 0, 0, 0, 0, 0, 0, 0, 0, 359127, 0, 0, 0, 27700, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Terraforming Record
(370498, 10, 71703, 'Triangular Altar', 'questinteract', 'Activating', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 363754, 0, 0, 0, 27700, 0, 0, 0, 0, 0, 1, 0, 94576, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2057, 42560), -- Triangular Altar
(373479, 3, 71420, 'Sacred Relic', 'questinteract', 'Collecting', '', 0.400000005960464477, 43, 0, 1, 0, 0, 0, 0, 0, 65096, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109010, 0, 0, 0, 0, 2057, 42560), -- Sacred Relic
(375223, 3, 72754, 'Repository Vault', 'questinteract', 'Searching', '', 0.699999988079071044, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19680, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109514, 1, 0, 0, 0, 2057, 42560), -- Repository Vault
(370285, 5, 72195, 'Vault Console', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Vault Console
(375070, 10, 71460, 'Teleporter', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 27519, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42560), -- Teleporter
(370175, 5, 71228, 'Progenitor Soul Orb', '', '', '', 0.98999941349029541, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42560), -- Progenitor Soul Orb
(375222, 3, 72293, 'Protoform Tool', 'questinteract', 'Searching', '', 1, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19680, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109513, 1, 0, 0, 0, 2057, 42560), -- Protoform Tool
(373466, 50, 71909, 'Catalyzed Apple', 'questinteract', 'Collecting', '', 1.20000004768371582, 43, 109001, 0, 0, 0, 0, 15, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2060, 42560), -- Catalyzed Apple
(370468, 5, 66537, 'Shadow Bulwark', '', '', '', 1.899999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 837, 42560), -- Shadow Bulwark
(375536, 3, 71057, 'Xy\'rath\'s Booby-Trapped Cache', '', '', '', 0.300000011920928955, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 366937, 0, 0, 0, 109829, 1, 0, 0, 0, 2057, 42560), -- Xy'rath's Booby-Trapped Cache
(370405, 10, 70455, 'Orb of Transference', 'questinteract', '', '', 0.300000011920928955, 3355, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Orb of Transference
(370196, 5, 71242, '9PRG_Orb_B01', '', '', '', 1.468591213226318359, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9PRG_Orb_B01
(375085, 5, 72318, '9FX_Generic_Progenitor_Drip', '', '', '', 0.24253818392753601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_Generic_Progenitor_Drip
(375088, 5, 70564, '9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal', '', '', '', 0.054438211023807525, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal
(375166, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(370193, 5, 71242, '9PRG_Orb_B01', '', '', '', 1.468591094017028808, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9PRG_Orb_B01
(375132, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375089, 5, 72318, '9FX_Generic_Progenitor_Drip', '', '', '', 0.24253818392753601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_Generic_Progenitor_Drip
(375167, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375148, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375136, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(370522, 5, 71242, 'Containment Sphere', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(370471, 5, 71242, 'Containment Sphere', '', '', '', 1.299999952316284179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375157, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375207, 10, 72025, 'Mezzonic Cache', '', 'Inspecting', '', 0.5, 2034, 0, 0, 1, 0, 0, 1, 0, 0, 0, 369493, 0, 0, 1, 157298, 0, 0, 0, 1, 27637, 1, 0, 93710, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Mezzonic Cache
(375159, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375142, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(370174, 5, 71228, 'Progenitor Soul Orb', '', '', '', 0.999999046325683593, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Progenitor Soul Orb
(370180, 5, 71242, 'Containment Sphere', '', '', '', 1.299999952316284179, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375357, 35, 72882, '9DU_ProgenitorRaid_DrawBridge02', '', '', '', 0.999999821186065673, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_ProgenitorRaid_DrawBridge02
(352006, 5, 60638, 'Anima Extractor', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Anima Extractor
(370346, 22, 71925, 'Stone Soup', 'Interact', '', '', 0.60000002384185791, 308460, 70, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 754, 42698), -- Stone Soup
(370525, 5, 71242, 'Containment Sphere', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375391, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109628, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375151, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(357214, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338890, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42698), -- Broken Mirror
(370521, 5, 71242, 'Containment Sphere', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(357221, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338897, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42698), -- Broken Mirror
(375087, 5, 72318, '9FX_Generic_Progenitor_Drip', '', '', '', 0.242538169026374816, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_Generic_Progenitor_Drip
(375388, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109638, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375139, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(373521, 22, 63415, 'Emergency Broker Portal', '', '', '', 1, 362325, -1, 0, 0, 0, 95603, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Emergency Broker Portal
(375134, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01 Instance', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01 Instance
(375370, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109574, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375974, 50, 44039, 'Crystallized Echo of the First Song', '', 'Opening', '', 0.300000011920928955, 1691, 110154, 0, 0, 0, 0, 30, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 684, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Crystallized Echo of the First Song
(375138, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375082, 5, 70564, '9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal', '', '', '', 0.054438211023807525, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal
(375092, 5, 70564, '9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal', '', '', '', 0.054438207298517227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal
(370472, 5, 71242, 'Containment Sphere', '', '', '', 1.25, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(370172, 5, 71228, 'Progenitor Soul Orb', '', '', '', 0.999999046325683593, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Progenitor Soul Orb
(375141, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375150, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375152, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375160, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(370520, 5, 71242, 'Containment Sphere', '', '', '', 1.299999952316284179, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(370524, 5, 71242, 'Containment Sphere', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375901, 3, 71678, 'Treasures of the First Ones', '', '', '', 2, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2546, 0, 1, 0, 0, 110024, 0, 0, 0, 0, 2167, 42698), -- Treasures of the First Ones
(370198, 5, 71242, '9PRG_Orb_B01', '', '', '', 1.46859133243560791, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9PRG_Orb_B01
(375889, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109625, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375192, 10, 71404, 'Fulgore Alcove Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 364797, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Fulgore Alcove Arrangement
(375154, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375390, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109627, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(373443, 22, 9381, 'Firim\'s Portal', 'questinteract', '', '', 1, 360776, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Firim's Portal
(375981, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109643, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(370518, 5, 71242, 'Containment Sphere', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375158, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375147, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375091, 5, 72318, '9FX_Generic_Progenitor_Drip', '', '', '', 0.24253818392753601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_Generic_Progenitor_Drip
(375083, 5, 72318, '9FX_Generic_Progenitor_Drip', '', '', '', 0.24253818392753601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_Generic_Progenitor_Drip
(375133, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01 Instance', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01 Instance
(375155, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375164, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375161, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375153, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375137, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375086, 5, 70564, '9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal', '', '', '', 0.054438207298517227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal
(375146, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375156, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375144, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(370171, 5, 71228, 'Progenitor Soul Orb', '', '', '', 0.999999046325683593, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Progenitor Soul Orb
(375084, 5, 70564, '9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal', '', '', '', 0.054438207298517227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal
(375143, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(370470, 5, 71242, 'Containment Sphere', '', '', '', 1.25, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375090, 5, 70564, '9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal', '', '', '', 0.054438207298517227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_BrokerCity_EmpoweredBroker_ProtoProgenitorPortal
(375393, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109631, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375149, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375081, 5, 72318, '9FX_Generic_Progenitor_Drip', '', '', '', 0.242538169026374816, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9FX_Generic_Progenitor_Drip
(375747, 5, 72886, 'Collision Flight Roost', '', '', '', 0.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Collision Flight Roost
(370183, 5, 71242, 'Containment Sphere', '', '', '', 1.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(370519, 5, 71242, 'Containment Sphere', '', '', '', 1.399999976158142089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Containment Sphere
(375988, 50, 70399, 'Firim in Exile, Epilogue', '', 'Collecting', '', 1, 43, 110202, 0, 0, 0, 0, 2, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 5031, 10, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Firim in Exile, Epilogue
(375165, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375163, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375135, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375145, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375140, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375389, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109630, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375162, 35, 71769, '9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9DU_PROGENITORRAID_JAILERFIGHT_TrapDoor01
(375905, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109640, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375486, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.300000011920928955, 1691, 109590, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(375407, 5, 72992, 'Calmed Soul River', '', '', '', 0.999999523162841796, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- Calmed Soul River
(375371, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.5, 1691, 109575, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Protoform Schematic
(370199, 5, 71242, '9PRG_Orb_B01', '', '', '', 1.46859133243560791, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42698), -- 9PRG_Orb_B01
(370458, 10, 61069, 'Mawsworn Cell', 'questinteract', 'Unlocking', '', 1.10000002384185791, 3351, 0, 0, 2, 0, 0, 0, 0, 0, 0, 359909, 0, 0, 0, 24815, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2057, 42698), -- Mawsworn Cell
(369259, 10, 61271, 'Portal to Customs', 'point', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Portal to Customs
(368939, 22, 69860, 'Signature Authorization Device and Transport Facility', 'interact', '', '', 0.999999821186065673, 356555, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Signature Authorization Device and Transport Facility
(368990, 0, 70756, 'Force Field', '', '', '', 3.5, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Force Field
(375003, 0, 70756, 'Force Field', '', '', '', 6, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Force Field
(369466, 19, 65009, 'Mailbox', '', '', '', 0.999999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Mailbox
(357216, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338892, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42852), -- Broken Mirror
(368942, 5, 69861, 'Delivery Portal', '', '', '', 0.999999701976776123, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Delivery Portal
(369464, 19, 65009, 'Mailbox', '', '', '', 1.499999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Mailbox
(375008, 0, 11753, 'Challenge Mode - Start Door (Dome 1.75) [DNT]', '', '', '', 1.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Challenge Mode - Start Door (Dome 1.75) [DNT]
(368991, 10, 69931, 'Force Field', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Force Field
(345443, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 320085, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42852), -- Broken Mirror
(368383, 5, 69927, 'Xy Cartel Signature', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Xy Cartel Signature
(375093, 22, 71925, 'Stone Soup', 'Interact', '', '', 0.60000002384185791, 308460, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 754, 42852), -- Stone Soup
(368249, 5, 68410, 'Door', '', '', '', 0.999999582767486572, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Door
(368381, 5, 69929, 'Au Cartel Signature', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Au Cartel Signature
(368937, 5, 61271, 'Portal', '', '', '', 0.999999701976776123, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Portal
(369892, 3, 71034, 'Expedition Report A37J - Part 4', '', 'Collecting', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108580, 1, 0, 0, 0, 2042, 42852), -- Expedition Report A37J - Part 4
(375950, 50, 73406, 'Bauble of Pure Innovation', '', 'Opening', '', 0.300000011920928955, 1691, 110149, 0, 0, 0, 0, 600, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 40, 1, 0, 0, 0, 1, 684, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42852), -- Bauble of Pure Innovation
(373483, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2437, 0, 1, 0, 0, 109026, 0, 5, 107535, 0, 1279, 42852), -- Challenger's Cache
(369889, 3, 71034, 'Expedition Report A37J - Part 1', '', 'Collecting', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108577, 1, 0, 0, 0, 2042, 42852), -- Expedition Report A37J - Part 1
(369316, 10, 61271, 'Portal', 'point', '', '', 0.999999880790710449, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Portal
(370083, 5, 71108, 'Microphone Stand', '', '', '', 1.299999952316284179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Microphone Stand
(369315, 10, 61271, 'Portal', 'point', '', '', 0.999999880790710449, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Portal
(368940, 5, 69861, 'Delivery Portal', '', '', '', 0.999999761581420898, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Delivery Portal
(374928, 3, 72392, 'Buried Artifact', 'questinteract', '', '', 0.5, 3366, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109287, 0, 0, 0, 0, 2057, 42852), -- Buried Artifact
(369888, 3, 71034, 'Expedition Report A37J - Foreword', '', 'Collecting', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108576, 1, 0, 0, 0, 2042, 42852), -- Expedition Report A37J - Foreword
(375002, 10, 69931, 'Force Field', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Force Field
(369465, 19, 65009, 'Mailbox', '', '', '', 1.499999761581420898, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Mailbox
(369887, 3, 71034, 'Cartel Al Incident Report', '', 'Collecting', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108575, 1, 0, 0, 0, 2042, 42852), -- Cartel Al Incident Report
(357215, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338891, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42852), -- Broken Mirror
(376252, 8, 9510, 'Anima Reservoir', '', '', '', 1, 2132, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Anima Reservoir
(369467, 19, 65009, 'Mailbox', '', '', '', 1.249999880790710449, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Mailbox
(368382, 5, 69928, 'Zo Cartel Signature', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Zo Cartel Signature
(365063, 0, 70756, 'Force Field', '', '', '', 6, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Force Field
(368941, 5, 69861, 'Delivery Portal', '', '', '', 0.999999761581420898, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Delivery Portal
(374927, 3, 72391, 'Buried Artifact', 'questinteract', '', '', 0.5, 3366, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109287, 0, 0, 0, 0, 2057, 42852), -- Buried Artifact
(368943, 5, 69861, 'Delivery Portal', '', '', '', 0.999999821186065673, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Delivery Portal
(375675, 47, 72927, 'Forge of Bonds', '', '', '', 1, 83089, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 837, 42852), -- Forge of Bonds
(368247, 5, 68410, 'Door', '', '', '', 0.999999582767486572, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42852), -- Door
(370457, 0, 13594, 'Column Collision', '', '', '', 0.430000007152557373, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2165, 42979), -- Column Collision
(357213, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338888, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42979), -- Broken Mirror
(373505, 3, 71421, 'Targeting Relic', 'questinteract', 'Collecting', '', 0.400000005960464477, 43, 0, 1, 0, 0, 0, 0, 0, 65119, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109035, 0, 0, 0, 0, 2057, 42979), -- Targeting Relic
(373643, 0, 69946, 'Vessel Chamber Door', '', '', '', 1, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- Vessel Chamber Door
(375345, 5, 71607, 'Secured Automa Console', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42979), -- Secured Automa Console
(375879, 10, 72360, 'Egress Phrase', 'questinteract', 'Speaking', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 367731, 0, 0, 0, 216095, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 2057, 42979), -- Egress Phrase
(375694, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.300000011920928955, 1691, 109632, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 42979), -- Protoform Schematic
(357219, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338895, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 42979), -- Broken Mirror
(369314, 10, 10328, 'ErrorCube', '', '', '', 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42979), -- ErrorCube
(357218, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338894, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 43114), -- Broken Mirror
(373463, 3, 69797, 'Progenitor Relic', 'questinteract', 'Collecting', '', 0.60000002384185791, 43, 0, 1, 0, 0, 0, 0, 0, 65072, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108999, 0, 0, 0, 0, 2057, 43114), -- Progenitor Relic
(373584, 10, 71463, 'Excitable Concordance', 'inspect', '', '', 1, 1634, 0, 0, 3000, 0, 0, 0, 8391, 297, 109, 362219, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 94126, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Excitable Concordance
(357217, 22, 59223, 'Broken Mirror', '', '', '', 0.649999976158142089, 338893, -1, 0, 0, 0, 77231, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 43114), -- Broken Mirror
(339277, 5, 59458, 'Forgotten Mirror', '', '', '', 0.60000002384185791, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Forgotten Mirror
(364482, 3, 65374, 'Collected Sinstone Fragments', '', 'Collecting', '', 0.800000011920928955, 57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 346816, 0, 0, 4584, 106483, 0, 0, 0, 0, 746, 43114), -- Collected Sinstone Fragments
(375483, 50, 72340, 'Stolen Scroll', '', 'Opening', '', 0.60000002384185791, 1691, 109673, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4994, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43114), -- Stolen Scroll
(368222, 3, 59951, 'Trueheart Spear', 'questinteract', 'Collecting', '', 1.299999952316284179, 43, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 140307, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107399, 0, 0, 0, 0, 2043, 43114), -- Trueheart Spear
(375368, 48, 69193, 'Creation Catalyst Console', 'questinteract', '', '', 0.75, 3, 0, 0, 0, 10, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Creation Catalyst Console
(374975, 5, 71393, '[DNT] Cypher C Icon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- [DNT] Cypher C Icon
(368670, 0, 69359, 'Door', '', '', '', 1.008324265480041503, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Door
(373496, 10, 66588, 'Sample Container', 'questinteract', 'Collecting', '', 0.400000005960464477, 43, 65117, 0, 3000, 0, 0, 0, 0, 0, 0, 361456, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43114), -- Sample Container
(368671, 0, 69359, 'Door', '', '', '', 1.008324384689331054, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Door
(351870, 5, 60638, 'Anima Extractor', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Anima Extractor
(325470, 5, 29574, 'Relay Device', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Relay Device
(368672, 0, 69359, 'Door', '', '', '', 0.768879473209381103, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Door
(368673, 0, 69359, 'Door', '', '', '', 0.768879473209381103, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43114), -- Door
(361338, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(245074, 5, 29594, 'Scroll', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Scroll
(368364, 0, 51162, 'Doodad_8hu_KulTiras_ChairSmall019', '', '', '', 1.435030460357666015, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall019
(245108, 10, 310, 'Copper Vein', '', '', '', 1, 0, 0, 0, 15000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5703, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Copper Vein
(361334, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(245653, 5, 30217, 'Spring Rolls', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Spring Rolls
(359887, 7, 47630, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(361342, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(368365, 0, 51162, 'Doodad_8hu_KulTiras_ChairSmall021', '', '', '', 1.435030698776245117, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall021
(367952, 5, 9513, 'Lobstrok Eggs', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Lobstrok Eggs
(349796, 3, 51775, 'Gilded Plum Chest', '', 'Opening', '', 1, 43, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 331854, 0, 0, 0, 102052, 0, 0, 0, 0, 746, 43206), -- Gilded Plum Chest
(359841, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(369104, 10, 30191, 'Security Panel', '', '', '', 0.999999761581420898, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 346471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88685, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Security Panel
(367954, 5, 16619, 'Egg', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(245097, 5, 34442, 'Pedestal', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Pedestal
(245082, 5, 11279, 'Brew Still', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Brew Still
(368353, 7, 51162, 'Doodad_8hu_KulTiras_ChairSmall010', '', '', '', 1.143811225891113281, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall010
(365355, 0, 28938, 'vault door', '', '', '', 0.670000076293945312, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- vault door
(249745, 45, 9510, 'Summoning Celestial', '', '', '', 1, 164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Summoning Celestial
(358384, 5, 59475, 'Purified Nectar', '', '', '', 0.699999988079071044, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 745, 43206), -- Purified Nectar
(359850, 7, 38132, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(359848, 7, 51162, 'Chair', '', '', '', 1.059999942779541015, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(248576, 45, 9510, 'Training Troops', '', '', '', 1, 124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Training Troops
(359870, 7, 38132, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(367950, 5, 69021, 'Painting', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Painting
(368348, 7, 47541, 'Doodad_8hu_KulTiras_ChairSmall005', '', '', '', 0.900000631809234619, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall005
(367955, 5, 16497, 'Egg', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(368352, 7, 51162, 'Doodad_8hu_KulTiras_ChairSmall009', '', '', '', 1.143811225891113281, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall009
(251315, 22, 12658, 'Portal to Peak of Serenity', '', '', '', 1, 216029, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Portal to Peak of Serenity
(367956, 5, 69022, 'Egg', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(268611, 45, 9510, 'Training Troops', '', '', '', 1, 229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Training Troops
(359892, 8, 16752, 'Broiling Pit', '', '', '', 0.829999983310699462, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Broiling Pit
(245642, 5, 30200, 'Training Target', '', '', '', 2.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Training Target
(245078, 5, 11457, 'Book', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Book
(369105, 10, 30191, 'Security Panel', '', '', '', 0.999999761581420898, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 346471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88685, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Security Panel
(357093, 3, 64602, 'Magical Curio', 'questinteract', 'Collecting', '', 1, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 81612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104464, 1, 0, 0, 0, 746, 43206), -- Magical Curio
(359877, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(367964, 5, 69025, 'Flowers', '', '', '', 0.400000005960464477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Flowers
(361301, 7, 32290, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(352754, 3, 61574, 'Silver Strongbox', '', 'Opening', '', 0.800000011920928955, 3233, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 331855, 0, 0, 4263, 102622, 0, 0, 0, 0, 2060, 43206), -- Silver Strongbox
(245072, 5, 13072, 'Portal Shrine', '', '', '', 1.049999952316284179, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Portal Shrine
(358380, 3, 66938, 'Glenzu Original', '', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 106045, 1, 0, 0, 0, 807, 43206), -- Glenzu Original
(367953, 5, 42338, 'Egg', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(367940, 3, 1407, 'Theotar\'s Egg', 'questinteract', 'Collecting', '', 1, 43, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 87727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4712, 107260, 1, 0, 0, 0, 837, 43206), -- Theotar's Egg
(353078, 5, 64428, '[DNT] Floating Planter 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- [DNT] Floating Planter 01
(359871, 7, 38132, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(260282, 5, 38457, 'Appocalypse Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Appocalypse Appearance
(367963, 5, 69024, 'Flowers', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Flowers
(245129, 5, 11937, 'Transportation Mandala', '', '', '', 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Transportation Mandala
(369103, 10, 30191, 'Security Panel', '', '', '', 0.999999821186065673, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 346471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88685, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Security Panel
(359866, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(353079, 5, 64429, '[DNT] Floating Planter 01B', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- [DNT] Floating Planter 01B
(368359, 7, 51162, 'Doodad_8hu_KulTiras_ChairSmall006', '', '', '', 1.27090001106262207, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall006
(359854, 7, 47037, 'Stool', '', '', '', 1.080000042915344238, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Stool
(368349, 7, 51162, 'Doodad_8hu_KulTiras_ChairSmall003', '', '', '', 1.14381110668182373, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall003
(359890, 8, 48901, 'Cookpot', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Cookpot
(245132, 5, 11368, 'Transportation Mandala', '', '', '', 4, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Transportation Mandala
(359881, 7, 32290, 'Chair', '', '', '', 1.110000014305114746, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(367985, 10, 1407, 'Theotar\'s Extra Ears', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 350630, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Theotar's Extra Ears
(353516, 3, 61574, 'Silver Strongbox', '', 'Opening', '', 0.800000011920928955, 3233, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 331855, 0, 0, 4272, 102810, 0, 0, 0, 0, 2060, 43206), -- Silver Strongbox
(353080, 5, 64430, '[DNT] Floating Planter 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- [DNT] Floating Planter 02
(359875, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(260285, 5, 38460, 'Appocalypse Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Appocalypse Appearance
(359900, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(353515, 5, 64194, 'Ripe Purian', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Ripe Purian
(367951, 5, 7784, 'Nexus Dragon Egg', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Nexus Dragon Egg
(359843, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(359852, 8, 49368, 'Anvil', '', '', '', 0.990000009536743164, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Anvil
(368355, 5, 46089, 'Doodad_8XP_MEETINGSTONE001', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8XP_MEETINGSTONE001
(368366, 5, 52189, 'Doodad_8HU_KULTIRAS_BANKVAULTDOOR001', '', '', '', 1.254604935646057128, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8HU_KULTIRAS_BANKVAULTDOOR001
(359862, 7, 38132, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(367960, 5, 12446, 'Egg', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(368354, 7, 51162, 'Doodad_8hu_KulTiras_ChairSmall011', '', '', '', 1.143811464309692382, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall011
(368361, 7, 47541, 'Doodad_8hu_KulTiras_ChairSmall023', '', '', '', 0.900001049041748046, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall023
(367962, 5, 69023, 'Flowers', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Flowers
(248556, 45, 9510, 'Training Troops', '', '', '', 1, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Training Troops
(361379, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(245081, 5, 11278, 'Brew Still', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Brew Still
(245654, 5, 26597, 'Fried Fish', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Fried Fish
(260283, 5, 38458, 'Appocalypse Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Appocalypse Appearance
(355208, 22, 61216, 'Anima Gateway', 'interact', '', '', 0.930000007152557373, 334362, -1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Anima Gateway
(368367, 5, 51318, 'Doodad_8HU_KulTiras_LogFire01_light002', '', '', '', 1.15694582462310791, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8HU_KulTiras_LogFire01_light002
(359886, 7, 32290, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(359857, 19, 49371, 'Mailbox', '', '', '', 1, 924, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Mailbox
(374972, 5, 71397, '[DNT] Cypher D Icon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- [DNT] Cypher D Icon
(367958, 5, 12445, 'Egg', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(367944, 3, 1411, 'Lord Garridan\'s Egg', 'questinteract', 'Collecting', '', 1, 43, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 87727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4715, 107263, 1, 0, 0, 0, 837, 43206), -- Lord Garridan's Egg
(245131, 5, 3271, 'Serenity Transporter Light', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Serenity Transporter Light
(361336, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(359885, 7, 32290, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(359898, 7, 15407, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Stool
(245130, 5, 2471, 'Chi Transporter Light', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Chi Transporter Light
(368301, 10, 69600, 'Infernal Cryptogram', 'questinteract', 'Copying', '', 1, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74690, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Infernal Cryptogram
(352750, 10, 59118, 'Tribute', '', '', '', 0.800000011920928955, 3225, 0, 0, 0, 0, 0, 1, 0, 0, 0, 329313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 80717, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Tribute
(359861, 7, 32290, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(359878, 7, 38132, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(359855, 7, 32290, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(245076, 5, 12790, 'Scroll', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Scroll
(356881, 5, 59069, 'Rubble', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Rubble
(245125, 10, 10765, 'Jung\'s Special Brew', '', '', '', 1, 0, 0, 0, 15000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Jung's Special Brew
(359847, 8, 49369, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Forge
(367941, 10, 69009, 'Theotar\'s Egg-Hunting Basket', 'questinteract', 'Collecting', '', 3, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 350429, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 4719, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Theotar's Egg-Hunting Basket
(369106, 10, 30191, 'Security Panel', '', '', '', 0.999999821186065673, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 346471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88685, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Security Panel
(252186, 45, 9510, 'Requisitioned Seal of Fate', '', '', '', 1, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Requisitioned Seal of Fate
(368351, 7, 51162, 'Doodad_8hu_KulTiras_ChairSmall006', '', '', '', 1.143811345100402832, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall006
(359845, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(375678, 47, 72927, 'Forge of Bonds', '', '', '', 1, 77547, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 837, 43206), -- Forge of Bonds
(359896, 7, 15407, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Stool
(265512, 5, 11032, 'Weapon Rack', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 43206), -- Weapon Rack
(352752, 5, 64194, 'Ripe Purian', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Ripe Purian
(245636, 5, 11053, 'Training Target', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Training Target
(353072, 5, 64420, '[PH] Lore Scroll 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- [PH] Lore Scroll 01
(368362, 7, 47541, 'Doodad_8hu_KulTiras_ChairSmall022', '', '', '', 0.900000989437103271, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall022
(374974, 5, 71402, '[DNT] Cypher B Icon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- [DNT] Cypher B Icon
(245655, 5, 30219, 'Fried Chicken', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Fried Chicken
(353517, 10, 59118, 'Tribute', '', '', '', 0.800000011920928955, 3225, 0, 0, 0, 0, 0, 1, 0, 0, 0, 331424, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 81212, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Tribute
(359891, 48, 50482, 'Scrap-O-Matic 1000', '', '', '', 1, 2, 1, 1, 2055, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Scrap-O-Matic 1000
(364413, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Campfire
(268454, 10, 11278, 'Brew Still', 'questinteract', 'Using', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 238436, 0, 0, 0, 19700, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Brew Still
(359882, 8, 49422, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Forge
(368363, 0, 51162, 'Doodad_8hu_KulTiras_ChairSmall018', '', '', '', 1.435030460357666015, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall018
(359883, 5, 38132, 'Bench', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(359860, 7, 38132, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(359888, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(359859, 8, 16752, 'Broiling Pit', '', '', '', 0.829999983310699462, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Broiling Pit
(357260, 22, 61216, 'Anima Gateway', 'interact', '', '', 1, 339512, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Anima Gateway
(359846, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(355971, 3, 66213, 'Stoneborn Glaive', 'questinteract', 'Collecting', '', 1.399999976158142089, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104215, 0, 0, 0, 0, 746, 43206), -- Stoneborn Glaive
(373484, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 2442, 0, 1, 0, 0, 109027, 0, 5, 107535, 0, 1279, 43206), -- Challenger's Cache
(361353, 8, 51381, 'Brazier', '', '', '', 1, 4, 10, 195641, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Brazier
(251676, 22, 34879, 'Portal to Dalaran', 'interact', '', '', 1, 192241, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Portal to Dalaran
(245055, 5, 30184, 'Statue of Liu Lang', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Statue of Liu Lang
(356398, 10, 2, 'Recruiting Poster', 'questinteract', 'Placing', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 337174, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 43206), -- Recruiting Poster
(367961, 5, 12444, 'Egg', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(359895, 7, 47037, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Stool
(245098, 47, 30185, 'Forge of the Roaring Mountain', '', '', '', 1, 37061, 1, 0, 640, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Forge of the Roaring Mountain
(361339, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(369107, 10, 30191, 'Titan Console', '', '', '', 0.999999821186065673, 0, 0, 0, 15000, 0, 0, 0, 0, 0, 0, 346427, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88685, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Titan Console
(358383, 3, 64424, 'Purified Nectar', '', 'Collecting', '', 0.699999988079071044, 43, 0, 5, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 105630, 0, 0, 0, 0, 745, 43206), -- Purified Nectar
(353331, 3, 58999, 'Faerie Stash', '', 'Opening', '', 0.5, 57, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 705, 2, 0, 0, 0, 0, 0, 0, 331853, 0, 0, 4224, 102785, 0, 0, 0, 0, 2060, 43206), -- Faerie Stash
(359893, 7, 47037, 'Stool', '', '', '', 1.159999966621398925, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Stool
(260286, 5, 38461, 'Appocalypse Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Appocalypse Appearance
(356728, 3, 59988, 'Mikanikos\' Extravagant Tribute', '', 'Opening', '', 0.569999992847442626, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 104286, 0, 0, 0, 0, 746, 43206), -- Mikanikos' Extravagant Tribute
(359864, 7, 38132, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(265511, 5, 10721, 'Weapon Rack', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 43206), -- Weapon Rack
(367957, 5, 16861, 'Egg', '', '', '', 0.059999998658895492, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(367959, 5, 12447, 'Egg', '', '', '', 0.300000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Egg
(361297, 7, 32290, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(368350, 7, 47541, 'Doodad_8hu_KulTiras_ChairSmall004', '', '', '', 0.90000087022781372, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Doodad_8hu_KulTiras_ChairSmall004
(245073, 5, 11039, 'Writing Desk Stool', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Writing Desk Stool
(245128, 5, 12273, 'Transportation Mandala', '', '', '', 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Transportation Mandala
(358297, 3, 64424, 'Purified Nectar', 'questinteract', 'Collecting', '', 0.699999988079071044, 43, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104833, 0, 0, 0, 0, 745, 43206), -- Purified Nectar
(359865, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Chair
(368627, 3, 66016, 'Observation Device', 'questinteract', 'Collecting', '', 0.5, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107593, 0, 0, 0, 0, 2043, 43206), -- Observation Device
(356539, 50, 58907, 'Lush Widowbloom', '', '', '', 1.5, 3140, 104322, 0, 0, 1, 1, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 807, 43206), -- Lush Widowbloom
(359880, 7, 38132, 'Bench', '', '', '', 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Bench
(367943, 3, 1408, 'Prince Renathal\'s Egg', 'questinteract', 'Collecting', '', 1, 43, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 87727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4716, 107262, 1, 0, 0, 0, 837, 43206), -- Prince Renathal's Egg
(363581, 43, 50198, 'Wind\'s Redemption', '', '', '', 1, 1806, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Wind's Redemption
(367942, 3, 1410, 'Temel\'s Egg', 'questinteract', 'Collecting', '', 1, 43, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 87727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4714, 107261, 1, 0, 0, 0, 837, 43206), -- Temel's Egg
(376249, 8, 9510, 'Anima Reservoir', '', '', '', 1, 2132, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Anima Reservoir
(375502, 50, 71142, 'Protoform Schematic', '', 'Opening', '', 0.150000005960464477, 1691, 109589, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43206), -- Protoform Schematic
(245077, 5, 29595, 'Wooden Scroll', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Wooden Scroll
(353251, 5, 64194, 'Ripe Purian', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Ripe Purian
(356752, 3, 64973, 'Cryptkeeper Kassir\'s Extravagant Tribute', '', 'Opening', '', 0.75, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 102423, 0, 0, 0, 0, 746, 43206), -- Cryptkeeper Kassir's Extravagant Tribute
(250988, 5, 11324, 'Brewery Door', '', '', '', 1.10000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 642, 43206), -- Brewery Door
(260284, 5, 38459, 'Appocalypse Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 43206), -- Appocalypse Appearance
(375495, 3, 71284, 'Undulating Foliage', '', 'Gathering', '', 1, 1691, 109730, 1, 0, 0, 0, 0, 0, 0, 750, 0, 0, 0, 1, 24982, 0, 0, 95469, 0, 3, 0, 0, 0, 0, 0, 0, 365820, 0, 0, 5001, 109730, 0, 108, 0, 0, 2057, 43340), -- Undulating Foliage
(368771, 10, 60086, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353268, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(373526, 10, 65822, 'Place Shard', 'questinteract', 'Placing', '', 1, 1691, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 361823, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 93917, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Place Shard
(340058, 3, 259, 'Baedos\' Regurgitated Treasure', '', 'Opening', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102059, 0, 0, 0, 0, 743, 43340), -- Baedos' Regurgitated Treasure
(370140, 50, 72587, 'Damaged Jiro Stash', '', 'Opening', '', 1, 1691, 108641, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4891, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Damaged Jiro Stash
(375423, 50, 72966, 'Offering to the First Ones', '', 'Looting', '', 0.5, 1691, 109670, 0, 0, 0, 0, 45, 0, 0, 108144, 0, 0, 0, 3, 365820, 0, 0, 4987, 10, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Offering to the First Ones
(373525, 10, 65821, 'Place Shard', 'questinteract', 'Placing', '', 1, 1691, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 361812, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 93915, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Place Shard
(370507, 10, 71403, 'Secundus Locus Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 362646, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Secundus Locus Arrangement
(374925, 5, 72282, 'Rubble Pile', '', '', '', 0.800000011920928955, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Rubble Pile
(368680, 10, 59323, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353268, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(368598, 10, 12777, 'Ritual Focus', 'questinteract', '', '', 0.050000000745058059, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355082, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Ritual Focus
(368658, 10, 59920, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353470, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(375272, 50, 66614, 'Mawsworn Cache', '', 'Opening', '', 0.699999988079071044, 1691, 109519, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4964, 10, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Mawsworn Cache
(368657, 10, 59920, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353240, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(375766, 10, 73210, 'Dangerous Orb of Power', 'interact', 'Absorbing', '', 2.5, 43, 0, 0, 3000, 0, 0, 30, 0, 0, 0, 367523, 0, 0, 0, 150452, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Dangerous Orb of Power
(368988, 5, 57742, 'Cage', '', '', '', 1.799999952316284179, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Cage
(375984, 50, 70399, 'Firim in Exile, Part 4', '', 'Collecting', '', 1, 43, 110198, 0, 0, 0, 0, 2, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 5027, 10, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Firim in Exile, Part 4
(368597, 10, 12777, 'Ritual Focus', 'questinteract', '', '', 0.050000000745058059, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Ritual Focus
(368887, 10, 59323, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353348, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(369218, 5, 12777, 'Ritual Focus', 'questinteract', '', '', 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Ritual Focus
(373551, 10, 72132, 'Orb', 'questinteract', 'Pushing', '', 0.699999988079071044, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 362166, 0, 0, 0, 213749, 0, 0, 0, 0, 0, 1, 0, 94081, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Orb
(370449, 10, 71986, 'Fractal Cypher A', 'questinteract', 'Examining', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 359837, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Fractal Cypher A
(373594, 10, 71401, 'Primus Locus Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 362536, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Primus Locus Arrangement
(373494, 10, 71986, 'Fractal Cypher B', 'questinteract', 'Examining', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 361436, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Fractal Cypher B
(375524, 5, 72282, 'Suspicious Rubble Pile', '', '', '', 0.800000011920928955, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Suspicious Rubble Pile
(368755, 10, 59323, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353268, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(373549, 5, 72132, 'Orb', '', '', '', 0.800000011920928955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Orb
(375359, 5, 72282, 'Glowing Rubble Pile', '', '', '', 0.800000011920928955, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Glowing Rubble Pile
(375533, 5, 72792, 'Button Indicator - Dim', '', '', '', 0.349999994039535522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Button Indicator - Dim
(375977, 3, 69484, 'Firim\'s Research Notes', '', 'Collecting', '', 1, 1690, 0, 0, 0, 0, 0, 0, 0, 65749, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110153, 0, 0, 0, 0, 2057, 43340), -- Firim's Research Notes
(369220, 5, 12777, 'Ritual Focus', 'questinteract', '', '', 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Ritual Focus
(375405, 50, 71419, 'Filched Artifact', '', 'Opening', '', 0.5, 1691, 109660, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4979, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Filched Artifact
(368669, 10, 60086, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353268, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(375485, 50, 72311, 'Protoflora Harvester', '', 'Opening', '', 1, 1691, 109677, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4996, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Protoflora Harvester
(279657, 3, 8685, 'General\'s Cache', '', '', '', 1.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 1134, 0, 0, 0, 0, 91423, 0, 0, 0, 0, 1020, 43340), -- General's Cache
(375534, 5, 72792, 'Button Indicator - Dim', '', '', '', 0.349999994039535522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Button Indicator - Dim
(376026, 5, 70428, 'Triggered Trap', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Triggered Trap
(375384, 10, 72283, 'Fallen Rock', '', '', '', 0.400000005960464477, 3382, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 366395, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95316, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Fallen Rock
(340085, 5, 59979, 'Yellow Goo', '', '', '', 0.180000007152557373, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Yellow Goo
(368888, 10, 60086, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353348, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(369342, 2, 12421, 'Pandaren Wood Carving', '', '', '', 0.5, 0, 24656, 0, 0, 0, 0, 0, 0, 0, 0, 91970, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Pandaren Wood Carving
(369219, 5, 12777, 'Ritual Focus', 'questinteract', '', '', 0.050000000745058059, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Ritual Focus
(375480, 22, 9011, 'Portal to Torghast', '', '', '', 1, 366748, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 709, 43340), -- Portal to Torghast
(375382, 50, 72931, 'Crushed Supply Crate', '', 'Opening', '', 1, 1691, 109578, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 95269, 0, 3, 366494, 0, 0, 4976, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Crushed Supply Crate
(356705, 3, 66312, 'Plague Deviser Marileth\'s Extravagant Tribute', '', 'Opening', '', 0.569999992847442626, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 104309, 0, 0, 0, 0, 746, 43340), -- Plague Deviser Marileth's Extravagant Tribute
(356748, 3, 64973, 'Stonehead\'s Extravagant Tribute', '', 'Opening', '', 0.75, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 104318, 0, 0, 0, 0, 746, 43340), -- Stonehead's Extravagant Tribute
(373517, 10, 65820, 'Place Shard', 'questinteract', 'Placing', '', 1, 1691, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 361747, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 93864, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Place Shard
(375985, 50, 70399, 'Firim in Exile, Part 5', '', 'Collecting', '', 1, 43, 110199, 0, 0, 0, 0, 2, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 5028, 10, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Firim in Exile, Part 5
(375369, 50, 71411, 'Gnawed Valise', '', 'Opening', '', 1, 1691, 109573, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 366314, 0, 0, 4973, 10, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Gnawed Valise
(369192, 10, 61671, 'Fae Ritual Oils', 'questinteract', 'Placing', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355205, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 92486, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Fae Ritual Oils
(370389, 5, 65582, 'Transmitter', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Transmitter
(373527, 10, 65823, 'Place Shard', 'questinteract', 'Placing', '', 1, 1691, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 361826, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 93918, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Place Shard
(375385, 10, 72940, 'Fallen Rock', '', '', '', 0.300000011920928955, 3382, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 366396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95267, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Fallen Rock
(375281, 50, 72966, 'Stolen Relic', '', 'Opening', '', 0.400000005960464477, 1691, 109524, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4965, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Stolen Relic
(375030, 5, 69194, 'Lexical Console', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Lexical Console
(370505, 10, 71393, 'Interior Locus Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 362607, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Interior Locus Arrangement
(369262, 3, 66614, 'Zovaal\'s Vault', '', 'Collecting', '', 2.619999885559082031, 43, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4816, 107932, 0, 0, 0, 0, 2043, 43340), -- Zovaal's Vault
(369186, 10, 65422, 'Basket of Flowers', 'questinteract', 'Picking Up', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355197, 0, 0, 0, 125962, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Basket of Flowers
(369606, 5, 69511, 'Path to Relic [DNT]', '', '', '', 1.20000004768371582, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Path to Relic [DNT]
(369188, 10, 61671, 'Fae Ritual Oils', 'questinteract', 'Picking Up', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355198, 0, 0, 0, 125962, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Fae Ritual Oils
(375765, 10, 9806, 'Forgotten Pump', 'interact', 'Activating', '', 4, 0, 0, 0, 15000, 0, 0, 30, 0, 0, 0, 367525, 0, 0, 0, 27700, 0, 0, 0, 0, 0, 0, 0, 95696, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Forgotten Pump
(375386, 5, 72931, 'Crushed Supply Crate', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Crushed Supply Crate
(368656, 10, 59920, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353239, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(373495, 10, 71986, 'Fractal Cypher C', 'questinteract', 'Examining', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 361437, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Fractal Cypher C
(368603, 10, 32687, 'The Sisters\' Tear', '', 'Collecting', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 352670, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- The Sisters' Tear
(375532, 5, 72792, 'Button Indicator - Dim', '', '', '', 0.349999994039535522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Button Indicator - Dim
(368770, 10, 59323, 'Record of War', 'questinteract', 'Examining', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353348, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(368987, 10, 65229, 'Sigil of Binding', 'questinteract', 'Collecting', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 354046, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Sigil of Binding
(369190, 10, 70178, 'Basket of Incense', 'questinteract', 'Placing', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355202, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 0, 0, 91453, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Basket of Incense
(368595, 10, 12777, 'Ritual Focus', 'questinteract', '', '', 0.050000000745058059, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Ritual Focus
(373548, 50, 71607, 'Template Archive', '', 'Opening', '', 1, 1691, 109072, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4925, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Template Archive
(375287, 56, 9510, 'Crystallized Bolstering Spheroid', '', '', '', 2, 0, 72076, 0, 684, 26, 71895, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Crystallized Bolstering Spheroid
(374924, 10, 72359, 'Ingress Phrase', 'questinteract', 'Attuning', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 363319, 0, 0, 0, 82628, 0, 0, 0, 0, 0, 1, 0, 56965, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Ingress Phrase
(369187, 10, 70178, 'Basket of Incense', 'questinteract', 'Picking Up', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 355199, 0, 0, 0, 125962, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Basket of Incense
(375354, 3, 66614, 'Domination Cache', '', 'Opening', '', 0.899999976158142089, 3376, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 365820, 0, 0, 4968, 109570, 0, 108, 0, 0, 2057, 43340), -- Domination Cache
(373649, 10, 72360, 'Ingress Phrase', 'questinteract', 'Placing', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 362815, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 2057, 43340), -- Ingress Phrase
(369172, 50, 70399, 'Lost Memento', '', 'Opening', '', 1.70000004768371582, 1691, 107858, 0, 0, 0, 0, 600, 0, 0, 21400, 0, 0, 0, 3, 360665, 0, 0, 4785, 40, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 743, 43340), -- Lost Memento
(370403, 5, 59213, 'Soul Mirror', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43340), -- Soul Mirror
(375422, 50, 73035, 'Overgrown Protofruit', '', 'Opening', '', 2, 1691, 109669, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 0, 0, 3, 365820, 0, 0, 4986, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Overgrown Protofruit
(375224, 10, 71564, 'Ingress Override', 'questinteract', 'Opening', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 362822, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Ingress Override
(373461, 3, 71900, 'Chromatic Rosid', 'questinteract', 'Collecting', '', 1.5, 1702, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 95914, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108998, 1, 0, 0, 0, 2057, 43340), -- Chromatic Rosid
(369227, 50, 69234, 'Stolen Anima Vessel', '', '', '', 1, 57, 107870, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 353380, 0, 1, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 742, 43340), -- Stolen Anima Vessel
(375987, 50, 70399, 'Firim in Exile, Part 7', '', 'Collecting', '', 1, 43, 110201, 0, 0, 0, 0, 2, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 5030, 10, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Firim in Exile, Part 7
(375986, 50, 70399, 'Firim in Exile, Part 6', '', 'Collecting', '', 1, 43, 110200, 0, 0, 0, 0, 2, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 5029, 10, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43340), -- Firim in Exile, Part 6
(375392, 3, 72962, 'Repair Tool', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109645, 0, 0, 0, 0, 2057, 43340), -- Repair Tool
(354075, 3, 65140, 'Blank Parchment', 'questinteract', 'Collecting', '', 1, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98531, 1, 0, 0, 0, 2060, 43340), -- Blank Parchment
(368660, 10, 59920, 'Record of War', 'questinteract', 'Checking For Traps', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 353246, 0, 0, 0, 210531, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2043, 43340), -- Record of War
(354192, 3, 14316, 'Stoneborn Satchel', '', 'Opening', '', 2, 57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 705, 2, 0, 0, 0, 0, 0, 0, 331854, 0, 0, 4328, 103255, 0, 0, 0, 0, 2060, 43345), -- Stoneborn Satchel
(368360, 5, 51318, 'Doodad_8HU_KulTiras_LogFire01_light001', '', '', '', 1.248052716255187988, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Doodad_8HU_KulTiras_LogFire01_light001
(357336, 3, 61206, 'Fresh Ardenweald Anima', 'questinteract', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104536, 1, 0, 0, 0, 746, 43345), -- Fresh Ardenweald Anima
(357156, 3, 65376, 'Confiscated Instruments', 'questinteract', 'Collecting', '', 0.5, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104497, 1, 0, 0, 0, 746, 43345), -- Confiscated Instruments
(358358, 10, 43313, 'Remains of Emeni, the Kinslayer', 'questinteract', 'Projecting Emeni', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 341963, 0, 0, 0, 205438, 0, 0, 0, 0, 0, 1, 0, 56965, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 837, 43345), -- Remains of Emeni, the Kinslayer
(356607, 3, 66306, 'Violet Frill', 'questinteract', 'Collecting', '', 0.25, 259, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104354, 0, 0, 0, 0, 746, 43345), -- Violet Frill
(325436, 10, 44416, 'Wanderer\'s Wayshrine', '', 'Offering', '', 1, 1922, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 294695, 0, 0, 1, 155929, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 845, 43345), -- Wanderer's Wayshrine
(354438, 5, 57742, 'Cage', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Cage
(368625, 3, 66016, 'Observation Device', 'questinteract', 'Collecting', '', 0.5, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107591, 0, 0, 0, 0, 2043, 43345), -- Observation Device
(375191, 10, 71400, 'Dormant Alcove Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 364796, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Dormant Alcove Arrangement
(374976, 50, 71678, 'Symphonic Vault', '', 'Opening', '', 0.60000002384185791, 1691, 109318, 0, 0, 0, 0, 45, 0, 0, 21400, 0, 94465, 0, 3, 365820, 0, 0, 4942, 10, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2057, 43345), -- Symphonic Vault
(353090, 5, 59110, '[DNT] Floating Scrolls 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [DNT] Floating Scrolls 03
(236857, 5, 9517, 'Fang of the Doomwing', '', '', '', 0.699999988079071044, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Fang of the Doomwing
(373520, 5, 71284, 'Restoration Matrix', '', '', '', 0.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Restoration Matrix
(368356, 7, 47630, 'Doodad_8hu_KulTiras_ChairLarge001', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Doodad_8hu_KulTiras_ChairLarge001
(356697, 3, 66312, 'Alexandros Mograine\'s Extravagant Tribute', '', 'Opening', '', 0.569999992847442626, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 104312, 0, 0, 0, 0, 746, 43345), -- Alexandros Mograine's Extravagant Tribute
(358360, 5, 45526, 'Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Table
(356596, 3, 66314, 'Feather Cap', 'questinteract', 'Collecting', '', 0.25, 259, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104351, 0, 0, 0, 0, 746, 43345), -- Feather Cap
(343588, 22, 59574, 'Censer of Discipline', 'questinteract', '', '', 1, 324976, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Censer of Discipline
(353817, 10, 27772, 'Portal to ?', '', 'Activating', '', 1, 3197, 0, 0, 1, 0, 0, 0, 0, 0, 0, 332449, 0, 0, 0, 27700, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 709, 43345), -- Portal to ?
(376251, 8, 9510, 'Anima Reservoir', '', '', '', 1, 2132, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Anima Reservoir
(243761, 22, 9834, 'Ogre Waygate', '', '', '', 1.25, 182464, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 302, 43345), -- Ogre Waygate
(353075, 5, 64424, '[DNT] Open Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [DNT] Open Crate
(353325, 3, 61574, 'Silver Strongbox', '', 'Opening', '', 0.800000011920928955, 3233, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 331855, 0, 0, 4269, 102778, 0, 0, 0, 0, 2060, 43345), -- Silver Strongbox
(375676, 47, 72927, 'Forge of Bonds', '', '', '', 1, 74343, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 837, 43345), -- Forge of Bonds
(356597, 3, 44573, 'Lacy Bell Morel', 'questinteract', 'Collecting', '', 0.25, 259, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104352, 0, 0, 0, 0, 746, 43345), -- Lacy Bell Morel
(355844, 10, 62425, 'Tubbins\'s Lucky Teapot', 'questinteract', 'Collecting', '', 1, 93, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 322057, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 78382, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 43345), -- Tubbins's Lucky Teapot
(368626, 3, 66016, 'Observation Device', 'questinteract', 'Collecting', '', 0.5, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107592, 0, 0, 0, 0, 2043, 43345), -- Observation Device
(353328, 10, 59118, 'Tribute', '', '', '', 0.800000011920928955, 3225, 0, 0, 0, 0, 0, 1, 0, 0, 0, 331025, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 81031, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Tribute
(353088, 5, 58879, '[DNT] Floating Scrolls 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [DNT] Floating Scrolls 01
(361320, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Chair
(368357, 7, 47541, 'Doodad_8hu_KulTiras_ChairSmall004', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Doodad_8hu_KulTiras_ChairSmall004
(356733, 3, 59988, 'Kleia and Pelagos\' Extravagant Tribute', '', 'Opening', '', 0.569999992847442626, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 104299, 0, 0, 0, 0, 746, 43345), -- Kleia and Pelagos' Extravagant Tribute
(357338, 3, 59976, 'Fresh Revendreth Anima', 'questinteract', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104537, 1, 0, 0, 0, 746, 43345), -- Fresh Revendreth Anima
(361361, 8, 51381, 'Brazier', '', '', '', 1, 4, 10, 195641, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Brazier
(376569, 0, 71470, 'Defense Matrix', '', '', '', 0.649999976158142089, 0, 0, 3000, 0, 0, 0, 0, 5793, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Defense Matrix
(236866, 5, 10355, 'Writhing Tendril', '', '', '', 0.150000005960464477, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Writhing Tendril
(373519, 10, 72067, 'Restoration Matrix', 'openhandglow', '', '', 0.5, 3359, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Restoration Matrix
(357206, 3, 65376, 'Confiscated Stage Props', 'questinteract', 'Collecting', '', 0.5, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104506, 1, 0, 0, 0, 746, 43345), -- Confiscated Stage Props
(353067, 5, 64420, '[PH] Lore Scroll 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [PH] Lore Scroll 02
(353089, 5, 58968, '[DNT] Floating Scrolls 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [DNT] Floating Scrolls 02
(369235, 50, 69234, 'Stolen Anima Vessel', '', '', '', 1, 57, 107873, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 353380, 0, 1, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 742, 43345), -- Stolen Anima Vessel
(353073, 5, 64420, '[PH] Lore Scroll 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [PH] Lore Scroll 03
(361352, 8, 51381, 'Brazier', '', '', '', 1, 4, 10, 195641, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Brazier
(358362, 9, 48439, 'The Legend of Emeni, the Kinslayer', 'inspect', '', '', 1, 8188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- The Legend of Emeni, the Kinslayer
(357335, 3, 59644, 'Fresh Bastion Anima', 'questinteract', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104534, 1, 0, 0, 0, 746, 43345), -- Fresh Bastion Anima
(353322, 5, 64194, 'Ripe Purian', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Ripe Purian
(343586, 22, 59574, 'Censer of Service', 'questinteract', '', '', 1, 324978, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Censer of Service
(355845, 10, 62425, 'Tubbins\'s Lucky Teapot', 'interact', 'Collecting', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 336325, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 81762, 1, 4675, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 43345), -- Tubbins's Lucky Teapot
(375189, 10, 71396, 'Repertory Alcove Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 364794, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Repertory Alcove Arrangement
(357159, 3, 66500, 'Stack of Promotional Posters', 'questinteract', 'Collecting', '', 1, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104500, 1, 0, 0, 0, 746, 43345), -- Stack of Promotional Posters
(236858, 5, 9517, 'Fang of the Sky Terror', '', '', '', 0.800000011920928955, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Fang of the Sky Terror
(236863, 5, 7942, 'Crystallized Steam', '', '', '', 0.25, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Crystallized Steam
(357337, 3, 58528, 'Fresh Maldraxxus Anima', 'questinteract', 'Collecting', '', 0.300000011920928955, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104535, 1, 0, 0, 0, 746, 43345), -- Fresh Maldraxxus Anima
(353084, 5, 58061, '[DNT] Light', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- [DNT] Light
(375190, 10, 71399, 'Rondure Alcove Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 364795, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Rondure Alcove Arrangement
(368221, 0, 37971, 'Spikes', '', '', '', 3.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Spikes
(361381, 8, 51381, 'Brazier', '', '', '', 1, 4, 10, 195641, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Brazier
(368358, 7, 47541, 'Doodad_8hu_KulTiras_ChairSmall005', '', '', '', 0.999999940395355224, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Doodad_8hu_KulTiras_ChairSmall005
(357252, 5, 64196, 'Symbol of Service', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Symbol of Service
(369313, 5, 70393, 'Rubble', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Rubble
(361319, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Chair
(236862, 5, 22636, 'Globe of Dead Water', '', '', '', 0.025000000372529029, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Globe of Dead Water
(355826, 5, 61762, 'Wheelbarrow', '', '', '', 0.930000007152557373, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Wheelbarrow
(357205, 3, 65376, 'Confiscated Stage Lights', 'questinteract', 'Collecting', '', 0.5, 93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104505, 1, 0, 0, 0, 746, 43345), -- Confiscated Stage Lights
(355877, 3, 59232, 'Duskmire Rose', '', 'Plucking', '', 0.300000011920928955, 259, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202730, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104182, 0, 0, 0, 0, 746, 43345), -- Duskmire Rose
(361348, 7, 51162, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43345), -- Chair
(357245, 5, 65636, 'Massive Sinstone', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43971), -- Massive Sinstone
(356720, 3, 65402, 'Choofa\'s Extravagant Tribute', '', 'Opening', '', 0.419999986886978149, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 102422, 0, 0, 0, 0, 746, 43971), -- Choofa's Extravagant Tribute
(356700, 3, 66312, 'Grandmaster Vole\'s Extravagant Tribute', '', 'Opening', '', 0.569999992847442626, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 104306, 0, 0, 0, 0, 746, 43971), -- Grandmaster Vole's Extravagant Tribute
(356693, 3, 66312, 'Baroness Vashj\'s Extravagant Tribute', '', 'Opening', '', 0.569999992847442626, 1691, 0, 1000000, 1, 0, 0, 74028, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 77958, 0, 0, 0, 0, 0, 0, 0, 2415, 0, 0, 0, 4260, 102420, 0, 0, 0, 0, 746, 43971), -- Baroness Vashj's Extravagant Tribute
(377031, 5, 74881, 'Soul River', '', '', '', 0.999999761581420898, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43971), -- Soul River
(376514, 5, 50355, 'Sleeping Mat', '', '', '', 0.60000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43971), -- Sleeping Mat
(376106, 5, 54586, 'Plague Eater Formula', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Plague Eater Formula
(375874, 19, 4591, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Mailbox
(376323, 5, 54759, 'Broken Plague Barrel', '', '', '', 3.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Broken Plague Barrel
(376320, 5, 54757, 'Broken Plague Barrel', '', '', '', 3.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Broken Plague Barrel
(376108, 5, 54585, 'Plague Eater Formula', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Plague Eater Formula
(376989, 5, 74842, 'Door', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Door
(375990, 5, 59721, 'Alchemy Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Alchemy Table
(376987, 5, 7390, 'Door', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Door
(279008, 5, 743, 'Doodad_UndeadSign_Fletcher01', '', '', '', 0.999999940395355224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Doodad_UndeadSign_Fletcher01
(376986, 5, 7390, 'Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Door
(376988, 5, 7390, 'Door', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Door
(278983, 5, 663, 'Doodad_UnderCitySignPostPointer54', '', '', '', 0.659018754959106445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Doodad_UnderCitySignPostPointer54
(376322, 5, 54585, 'Broken Plague Barrel', '', '', '', 3.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Broken Plague Barrel
(278980, 5, 663, 'Doodad_UnderCitySignPostPointer38', '', '', '', 0.659018754959106445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Doodad_UnderCitySignPostPointer38
(278981, 5, 663, 'Doodad_UnderCitySignPostPointer37', '', '', '', 0.659018754959106445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Doodad_UnderCitySignPostPointer37
(376321, 5, 54759, 'Batrider Target', '', '', '', 3.5, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Batrider Target
(376897, 5, 462, 'Door', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Door
(376109, 5, 54586, 'Plague Eater Formula', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Plague Eater Formula
(278982, 5, 663, 'Doodad_UnderCitySignPostPointer39', '', '', '', 0.659018754959106445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Doodad_UnderCitySignPostPointer39
(376107, 5, 54585, 'Plague Eater Formula', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44061), -- Plague Eater Formula
(368631, 3, 66132, 'Drop Box', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107596, 0, 0, 0, 0, 2043, 44232), -- Drop Box
(230839, 8, 8202, 'Doodad_StratholmeFloatingEmbers078', '', '', '', 0.785986840724945068, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44232), -- Doodad_StratholmeFloatingEmbers078
(234284, 3, 14316, 'Charred Satchel', '', 'Opening', '', 1.5, 57, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 681, 4, 100, 0, 0, 0, 0, 0, 81040, 0, 0, 0, 55453, 0, 0, 0, 0, 755, 44232), -- Charred Satchel
(234266, 5, 19870, 'Tauren Remains', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44232), -- Tauren Remains
(367990, 10, 7734, 'Theotar\'s Bonfire', '', 'Lighting Bonfire', '', 0.60000002384185791, 2763, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 350722, 0, 0, 0, 208364, 0, 0, 0, 0, 0, 0, 0, 92404, 1, 4875, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 396, 44232), -- Theotar's Bonfire
(357254, 5, 61106, 'Champion\'s Animacone', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44232), -- Champion's Animacone
(339941, 5, 59683, 'Ambroseeds', '', '', '', 1.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44232), -- Ambroseeds
(272805, 5, 35398, 'Banner', '', '', '', 1.25, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 337, 44232), -- Banner
(234281, 3, 15490, 'Adventurers Pack', '', 'Opening', '', 1.20000004768371582, 57, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 681, 4, 100, 0, 0, 0, 0, 0, 81040, 0, 0, 0, 55452, 0, 0, 0, 0, 755, 44232), -- Adventurers Pack
(376258, 10, 4398, 'Portal to Ruins of Lordaeron', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 369903, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 96122, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 866, 44232), -- Portal to Ruins of Lordaeron
(230838, 8, 8202, 'Doodad_StratholmeFloatingEmbers079', '', '', '', 0.785986840724945068, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44232), -- Doodad_StratholmeFloatingEmbers079
(367987, 5, 6762, 'Hanging, Tall/Thin, Large - MFF', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44232); -- Hanging, Tall/Thin, Large - MFF

UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221003; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220999; -- Timeless Chest
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=223088; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220986; -- Blackguard's Jetsam
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220994; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221764; -- Roasted Seed
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=42560 WHERE `entry`=290898; -- Heartsbane Scrolls
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221015; -- Timeless Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=49498, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=223193; -- Giant Clam
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221016; -- Timeless Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41530, `ContentTuningId`=267, `VerifiedBuild`=42560 WHERE `entry`=211326; -- Tap Tool
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220901; -- Gleaming Treasure Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221017; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=90, `VerifiedBuild`=42560 WHERE `entry`=375290; -- Cypher-Bound Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221001; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220995; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=42560 WHERE `entry`=248887; -- Pile of Ancient Arkhana
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220833; -- Damaged Diving Helmet
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221020; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=222687; -- Ordon Supplies
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221019; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221000; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221004; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220807; -- Neverending Spritewood
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221006; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221690; -- Sand-Covered Egg
UPDATE `gameobject_template` SET `Data6`=90, `VerifiedBuild`=42560 WHERE `entry`=375362; -- Avian Nest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=40485, `ContentTuningId`=57, `VerifiedBuild`=42560 WHERE `entry`=209836; -- Freshly Fallen Petals
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=222684; -- Glinting Sand
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=42560 WHERE `entry`=221543; -- Rain Poppy
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=220903; -- Gleaming Crane Statue
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42921, `ContentTuningId`=267, `VerifiedBuild`=42560 WHERE `entry`=213795; -- Stormstout Secrets
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221010; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=42560 WHERE `entry` IN (290895, 290897); -- Heartsbane Focus
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221024; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=267, `VerifiedBuild`=42560 WHERE `entry`=211319; -- Relief Bucket
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221002; -- Timeless Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=42560 WHERE `entry`=290896; -- Heartsbane Grimoire
UPDATE `gameobject_template` SET `Data6`=0, `Data26`=1, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=223539; -- Snowdrift Tiger Talons
UPDATE `gameobject_template` SET `ContentTuningId`=267, `VerifiedBuild`=42560 WHERE `entry` IN (211315, 211314, 211313); -- Brew Tap
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=42560 WHERE `entry`=221542; -- Green Tea Leaf
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=42560 WHERE `entry`=221413; -- Lin Family Scroll
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=42560 WHERE `entry`=221541; -- Trillium Vein
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=223089; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221747; -- Huge Yak Roast
UPDATE `gameobject_template` SET `Data6`=90, `VerifiedBuild`=42560 WHERE `entry`=375404; -- Sandworn Chest
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221005; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=90, `VerifiedBuild`=42560 WHERE `entry`=375530; -- Forgotten Treasure Vault
UPDATE `gameobject_template` SET `Data6`=90, `VerifiedBuild`=42560 WHERE `entry`=375373; -- Discarded Automa Scrap
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=169, `VerifiedBuild`=42560 WHERE `entry`=221014; -- Timeless Chest
UPDATE `gameobject_template` SET `Data6`=90, `VerifiedBuild`=42560 WHERE `entry`=375363; -- Mawsworn Supply Chest
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=42560 WHERE `entry`=221539; -- Rich Ghost Iron Deposit
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27856, `ContentTuningId`=28, `VerifiedBuild`=42698 WHERE `entry`=202263; -- Pirate Booty
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16466, `ContentTuningId`=28, `VerifiedBuild`=42698 WHERE `entry`=179496; -- Dented Footlocker
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=20581, `ContentTuningId`=41, `VerifiedBuild`=42698 WHERE `entry`=184504; -- Bloodmaul Brew Keg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27856, `ContentTuningId`=28, `VerifiedBuild`=42698 WHERE `entry`=203021; -- Pirate Booty
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27856, `ContentTuningId`=28, `VerifiedBuild`=42698 WHERE `entry`=203022; -- Pirate Booty
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18753, `ContentTuningId`=38, `VerifiedBuild`=42698 WHERE `entry`=182116; -- Fulgor Spore
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=20911, `ContentTuningId`=41, `VerifiedBuild`=42698 WHERE `entry`=184744; -- T'chali's Hookah
UPDATE `gameobject_template` SET `ContentTuningId`=676, `VerifiedBuild`=42698 WHERE `entry`=183046; -- Blindweed
UPDATE `gameobject_template` SET `ContentTuningId`=41, `VerifiedBuild`=42698 WHERE `entry`=184737; -- The Thunderspike
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27856, `ContentTuningId`=28, `VerifiedBuild`=42698 WHERE `entry`=203019; -- Pirate Booty
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=20806, `ContentTuningId`=41, `VerifiedBuild`=42698 WHERE `entry`=184689; -- Draenethyst Mine Crystal
UPDATE `gameobject_template` SET `Data18`=40, `VerifiedBuild`=42698 WHERE `entry`=375404; -- Sandworn Chest
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=42852 WHERE `entry`=350967; -- 9NC_Necro_Chair01
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=42852 WHERE `entry`=353149; -- 9MAL_SlimeFall_Necropolis_B01
UPDATE `gameobject_template` SET `Data33`=107535, `VerifiedBuild`=42852 WHERE `entry`=354991; -- Challenger's Cache
UPDATE `gameobject_template` SET `Data33`=107535, `VerifiedBuild`=42852 WHERE `entry`=354987; -- Challenger's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=651, `VerifiedBuild`=42852 WHERE `entry`=2061; -- Campfire
UPDATE `gameobject_template` SET `Data33`=107535, `VerifiedBuild`=42852 WHERE `entry`=354990; -- Challenger's Cache
UPDATE `gameobject_template` SET `Data0`=93, `VerifiedBuild`=42979 WHERE `entry`=364869; -- Mawforged Weapon Rack
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=242533; -- Transport (Both)
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry` IN (243961, 243512, 243701); -- Horde Destroyer Ship
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=242628; -- Carrier Ship
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=243110; -- Horde Destroyer
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry` IN (243699, 242625); -- Transport Ship
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43114 WHERE `entry`=209805; -- Great Pandaren Banquet
UPDATE `gameobject_template` SET `Data2`=4, `VerifiedBuild`=43114 WHERE `entry`=373478; -- Punisher Mine
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=43114 WHERE `entry`=281250; -- Mojo Mixer
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=243304; -- Carrier - Horde
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=243513; -- Horde Submarine Ship
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=43114 WHERE `entry`=273454; -- Chalice of Calling
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=243113; -- Horde Submarine
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=243372; -- Battleship (Horde)
UPDATE `gameobject_template` SET `ContentTuningId`=360, `VerifiedBuild`=43114 WHERE `entry`=243515; -- Battleship Ship - Horde
UPDATE `gameobject_template` SET `Data33`=107535, `VerifiedBuild`=43114 WHERE `entry`=354986; -- Challenger's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=205, `VerifiedBuild`=43206 WHERE `entry`=179585; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=77, `VerifiedBuild`=43206 WHERE `entry`=180600; -- Unstable Mana Crystal Crate
UPDATE `gameobject_template` SET `ContentTuningId`=1159, `VerifiedBuild`=43206 WHERE `entry` IN (246727, 246057); -- Doodad_7WD_Warden_Bridge001
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=43206 WHERE `entry`=252266; -- Delayeth's Journal: The Jewels of the Isles
UPDATE `gameobject_template` SET `ContentTuningId`=331, `VerifiedBuild`=43206 WHERE `entry`=250867; -- Keg of Spicy Grog
UPDATE `gameobject_template` SET `ContentTuningId`=1162, `VerifiedBuild`=43206 WHERE `entry`=252966; -- Nightborne Bazaar
UPDATE `gameobject_template` SET `ContentTuningId`=336, `VerifiedBuild`=43206 WHERE `entry`=269141; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43206 WHERE `entry`=245084; -- High End Keg
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43206 WHERE `entry`=245083; -- Keg Stands
UPDATE `gameobject_template` SET `ContentTuningId`=682, `VerifiedBuild`=43206 WHERE `entry`=253981; -- Extravagant Chest
UPDATE `gameobject_template` SET `ContentTuningId`=292, `VerifiedBuild`=43206 WHERE `entry`=281872; -- Sea Stalks
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23956, `ContentTuningId`=14, `VerifiedBuild`=43206 WHERE `entry`=188691; -- Vordrassil's Seed
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=43206 WHERE `entry`=209354; -- Golden Lotus
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25911, `ContentTuningId`=163, `VerifiedBuild`=43206 WHERE `entry`=192908; -- Crystalline Heartwood
UPDATE `gameobject_template` SET `ContentTuningId`=1159, `VerifiedBuild`=43206 WHERE `entry`=246418; -- Doodad_7DU_Warden_PlatformIcicles001
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23916, `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=188601; -- Sweetroot
UPDATE `gameobject_template` SET `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=189972; -- Ruuna's Crystal Ball
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23969, `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=188702; -- Grooved Cog
UPDATE `gameobject_template` SET `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=188458; -- Seer of Zeb'Halak
UPDATE `gameobject_template` SET `Data12`=682, `ContentTuningId`=682, `VerifiedBuild`=43206 WHERE `entry`=254003; -- Legion Cache
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26884, `ContentTuningId`=390, `VerifiedBuild`=43206 WHERE `entry`=113768; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=43206 WHERE `entry`=249460; -- Crate of Sabelite Sulfate
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=43206 WHERE `entry`=280937; -- Ramp
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43206 WHERE `entry`=245085; -- Standard Keg
UPDATE `gameobject_template` SET `ContentTuningId`=1162, `VerifiedBuild`=43206 WHERE `entry` IN (252967, 253047, 253046, 252968); -- Nightborne Goods
UPDATE `gameobject_template` SET `size`=0.60000002384185791, `VerifiedBuild`=43206 WHERE `entry`=357434; -- Instruction Dais
UPDATE `gameobject_template` SET `ContentTuningId`=1159, `VerifiedBuild`=43206 WHERE `entry`=253162; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=43206 WHERE `entry` IN (280939, 280940, 280941, 280938); -- Fence
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43206 WHERE `entry`=252874; -- The Fel Tome of Vorgalus Dor
UPDATE `gameobject_template` SET `Data33`=107535, `ContentTuningId`=1179, `VerifiedBuild`=43206 WHERE `entry`=252674; -- Challenger's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=43206 WHERE `entry`=280936; -- Collision
UPDATE `gameobject_template` SET `ContentTuningId`=57, `VerifiedBuild`=43206 WHERE `entry`=209550; -- Blushleaf Cluster
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23971, `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=188705; -- High Tension Spring
UPDATE `gameobject_template` SET `ContentTuningId`=682, `VerifiedBuild`=43206 WHERE `entry`=253982; -- Spoils of Nightmare
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=43206 WHERE `entry`=248056; -- Bear Totem
UPDATE `gameobject_template` SET `Data33`=300, `VerifiedBuild`=43206 WHERE `entry`=357170; -- Lever
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26677, `ContentTuningId`=196, `VerifiedBuild`=43206 WHERE `entry`=193402; -- Rusted Prisoner's Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=682, `VerifiedBuild`=43206 WHERE `entry`=245324; -- Rich Leystone Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=336, `VerifiedBuild`=43206 WHERE `entry`=269140; -- Forge
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23970, `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=188703; -- Notched Sprocket
UPDATE `gameobject_template` SET `ContentTuningId`=331, `VerifiedBuild`=43206 WHERE `entry`=251026; -- Salvage
UPDATE `gameobject_template` SET `ContentTuningId`=77, `VerifiedBuild`=43206 WHERE `entry`=180918; -- Wanted: Thaelis the Hungerer
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26884, `ContentTuningId`=390, `VerifiedBuild`=43206 WHERE `entry`=113769; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26884, `ContentTuningId`=390, `VerifiedBuild`=43206 WHERE `entry`=113770; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `ContentTuningId`=1159, `VerifiedBuild`=43206 WHERE `entry`=245335; -- Proximity Bomb
UPDATE `gameobject_template` SET `ContentTuningId`=619, `VerifiedBuild`=43206 WHERE `entry`=249386; -- Arcane Barrier
UPDATE `gameobject_template` SET `ContentTuningId`=1159, `VerifiedBuild`=43206 WHERE `entry`=247010; -- Volcano
UPDATE `gameobject_template` SET `ContentTuningId`=390, `VerifiedBuild`=43206 WHERE `entry`=194047; -- Easter Egg Trap
UPDATE `gameobject_template` SET `name`='Buried Cache', `VerifiedBuild`=43206 WHERE `entry`=357937; -- Burried Cache
UPDATE `gameobject_template` SET `ContentTuningId`=47, `VerifiedBuild`=43206 WHERE `entry`=189313; -- Wolfsbane Root
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26884, `ContentTuningId`=390, `VerifiedBuild`=43206 WHERE `entry`=113771; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `ContentTuningId`=77, `VerifiedBuild`=43206 WHERE `entry`=181584; -- Battered Crate Trap
UPDATE `gameobject_template` SET `ContentTuningId`=336, `VerifiedBuild`=43206 WHERE `entry`=267266; -- Hearthstone Board
UPDATE `gameobject_template` SET `ContentTuningId`=44, `VerifiedBuild`=43206 WHERE `entry`=191163; -- Blaze
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43206 WHERE `entry`=249694; -- Mug
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194956; -- Cache of Innovation
UPDATE `gameobject_template` SET `ContentTuningId`=1017, `VerifiedBuild`=43340 WHERE `entry` IN (181547, 181552, 181523, 181540, 181525, 181516, 181518, 181519, 181546, 181524, 181549, 181539, 181542, 181543, 181529, 181531, 181520, 181544, 181526, 181538, 181536, 181521, 181551, 181512, 181530, 181517, 181532, 181533, 181511, 181515, 181541, 181537, 181527, 181514, 181535, 181548, 181528, 181513, 181550, 181510, 181522, 181534, 181545); -- Plague Fissure
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29522, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=203090; -- Sunken Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=279655; -- Cache of Heroic Innovation
UPDATE `gameobject_template` SET `ContentTuningId`=1022, `VerifiedBuild`=43340 WHERE `entry` IN (176822, 176840, 176809, 176908, 176827, 176818, 176836, 176813, 176841, 176819, 176916, 176837, 176917, 176830, 176839, 176909, 176913, 176914, 176834, 176922, 176812, 176514, 176825, 176814, 176515, 176912, 176829, 176831, 176824, 176816, 176821, 176920, 176919, 176918, 176921, 176815, 176832, 176817, 176811, 176910, 176915, 176810, 176826, 176911, 176835, 176828, 176513, 176823, 176842, 176833, 176838, 176820); -- Lava Fissure
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28689, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202960; -- Rocket Car Parts
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=279649; -- Cache of the Leviathan
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191761; -- Prototype Console
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry` IN (194541, 194543, 194542); -- Harpoon Gun
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191553; -- U.D.E.D. Dispenser
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=43340 WHERE `entry`=192881; -- Thinking with Portals - A Memorandum on Proper Portal Usage
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28689, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202956; -- Rocket Car Parts
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=297899; -- Cache of Toys
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194565; -- Ulduar Raid - Razorscale - Broken Harpoon
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194328; -- Freya's Gift
UPDATE `gameobject_template` SET `Data6`=2, `VerifiedBuild`=43340 WHERE `entry`=375982; -- Firim in Exile, Part 2
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25277, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191533; -- Charred Wreckage
UPDATE `gameobject_template` SET `ContentTuningId`=1017, `VerifiedBuild`=43340 WHERE `entry`=181356; -- Sapphiron Birth
UPDATE `gameobject_template` SET `Data3`=0, `Data26`=1, `VerifiedBuild`=43340 WHERE `entry`=369523; -- Celestial Shadowlands Chart
UPDATE `gameobject_template` SET `ContentTuningId`=885, `VerifiedBuild`=43340 WHERE `entry`=268054; -- Kel'Thuzad and the Forming of the Scourge
UPDATE `gameobject_template` SET `ContentTuningId`=677, `VerifiedBuild`=43340 WHERE `entry`=190176; -- Frost Lotus
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25277, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191535; -- Charred Wreckage
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28689, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202957; -- Rocket Car Parts
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194262; -- RX-214 Repair-o-matic Station TRAP
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=195309; -- Mysterious Snow Mound
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=297860; -- General's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=677, `VerifiedBuild`=43340 WHERE `entry`=191019; -- Adder's Tongue
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194307; -- Cache of Winter
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=195046; -- Cache of Living Stone
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191760; -- Inventor's Library Console
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=43340 WHERE `entry`=192882; -- Polymorphic Rules & Regulations
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=43340 WHERE `entry`=192895; -- Kirin Tor Monthly (March Issue)
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43340 WHERE `entry`=251211; -- Well-worn Scroll
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22367, `ContentTuningId`=23, `VerifiedBuild`=43340 WHERE `entry`=186463; -- Wyrmtail
UPDATE `gameobject_template` SET `Data1`=0, `Data15`=0, `Data25`=1121, `Data30`=88689, `ContentTuningId`=1017, `VerifiedBuild`=43340 WHERE `entry`=181366; -- Four Horsemen Chest
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=192181; -- The Heart of the Storm
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25364, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191770; -- Eagle Egg
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=43340 WHERE `entry`=187562; -- Rusty Lever
UPDATE `gameobject_template` SET `ContentTuningId`=334, `VerifiedBuild`=43340 WHERE `entry`=244795; -- The Windrunner
UPDATE `gameobject_template` SET `Data6`=2, `VerifiedBuild`=43340 WHERE `entry`=375983; -- Firim in Exile, Part 3
UPDATE `gameobject_template` SET `name`='Campfire', `VerifiedBuild`=43340 WHERE `entry`=191704; -- Campire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23975, `ContentTuningId`=46, `VerifiedBuild`=43340 WHERE `entry`=189288; -- Wintergarde Mine Bomb
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194822; -- Gift of the Observer
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=43340 WHERE `entry`=192709; -- The Schools of Arcane Magic - Abjuration
UPDATE `gameobject_template` SET `Data6`=2, `VerifiedBuild`=43340 WHERE `entry`=375973; -- Firim in Exile, Part 1
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194569; -- Ulduar Teleporter
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202975; -- Submerged Outhouse
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25277, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191536; -- Charred Wreckage
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43340 WHERE `entry`=251209; -- Frosted Doughnut
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25620, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191843; -- Dried Gnoll Rations
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23949, `ContentTuningId`=46, `VerifiedBuild`=43340 WHERE `entry`=188671; -- Siegesmith Bomb
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194312; -- Cache of Storms
UPDATE `gameobject_template` SET `ContentTuningId`=334, `VerifiedBuild`=43340 WHERE `entry`=244817; -- Forsaken Ship
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28689, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202961; -- Rocket Car Parts
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25277, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191530; -- Charred Wreckage
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191544; -- Rusty Cage
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191708; -- Disturbed Snow
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=279656; -- Cache of Heroic Storms
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43340 WHERE `entry`=250417; -- Archmage Vargoth's Journal
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194625; -- Flee to the Surface
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194316; -- Iron Dwarf Mole Machine
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194907; -- Snow Mound
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194752; -- Celestial Planetarium Access
UPDATE `gameobject_template` SET `Data26`=1, `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194519; -- Harpoon Gun
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=23964, `ContentTuningId`=46, `VerifiedBuild`=43340 WHERE `entry`=188699; -- Strange Ore
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43340 WHERE `entry`=251210; -- Crystal Ball
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194462; -- The Dragon Soul
UPDATE `gameobject_template` SET `ContentTuningId`=1022, `VerifiedBuild`=43340 WHERE `entry`=176511; -- Onyxia Egg
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25364, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191773; -- Eagle Egg
UPDATE `gameobject_template` SET `ContentTuningId`=1017, `VerifiedBuild`=43340 WHERE `entry` IN (202277, 202278); -- Orb of Naxxramas
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=297873; -- Titan's Cache
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28689, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202958; -- Rocket Car Parts
UPDATE `gameobject_template` SET `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191502; -- Land Mine
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=297850; -- Iron Cache
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=279654; -- Freya's Heroic Gift
UPDATE `gameobject_template` SET `ContentTuningId`=677, `VerifiedBuild`=43340 WHERE `entry`=190170; -- Talandra's Rose
UPDATE `gameobject_template` SET `ContentTuningId`=1020, `VerifiedBuild`=43340 WHERE `entry`=194200; -- Rare Cache of Winter
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=25341, `ContentTuningId`=50, `VerifiedBuild`=43340 WHERE `entry`=191568; -- K3 Equipment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=24201, `ContentTuningId`=46, `VerifiedBuild`=43340 WHERE `entry`=190032; -- Wintergarde Munitions Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28689, `ContentTuningId`=21, `VerifiedBuild`=43340 WHERE `entry`=202959; -- Rocket Car Parts
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215954, 214187); -- Iron Amulet
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=43345 WHERE `entry`=192713; -- The Schools of Arcane Magic - Enchantment
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=43345 WHERE `entry`=209350; -- Silkweed
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=43345 WHERE `entry` IN (304124, 304068); -- Plague Bomb
UPDATE `gameobject_template` SET `ContentTuningId`=302, `VerifiedBuild`=43345 WHERE `entry`=236912; -- Deactivated Ogre Waygate
UPDATE `gameobject_template` SET `ContentTuningId`=681, `VerifiedBuild`=43345 WHERE `entry`=243334; -- Withered Herb
UPDATE `gameobject_template` SET `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216162; -- Mound of Dirt
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41387, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210620; -- Ancient Dynastic Tablet
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42246, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211765; -- Sra'thik Weapon
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215943, 214198); -- Carved Bronze Mirror
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=241669; -- Siege Equipment Blueprints
UPDATE `gameobject_template` SET `ContentTuningId`=886, `VerifiedBuild`=43345 WHERE `entry`=243282; -- Viking Pepe
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42449, `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=212085; -- Starshade
UPDATE `gameobject_template` SET `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216322; -- Bounty Board
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41331, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210348; -- Dry Fire Wood
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214196, 215941); -- Walking Cane of Brewfather Ren Yun
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=43345 WHERE `entry`=304067; -- Engine Gearing
UPDATE `gameobject_template` SET `Data16`=1, `VerifiedBuild`=43345 WHERE `entry`=369689; -- Lever
UPDATE `gameobject_template` SET `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211568; -- Snow Lily Incense
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=215872; -- Halberd of the Unscathed
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=43345 WHERE `entry`=268969; -- Ancient Door
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215946, 214201); -- Pearl of Yu'lon
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218960, 218968); -- Ancient Sap Feeder
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry` IN (234198, 234194, 234196); -- Timber
UPDATE `gameobject_template` SET `ContentTuningId`=681, `VerifiedBuild`=43345 WHERE `entry`=243314; -- True Iron Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=51, `VerifiedBuild`=43345 WHERE `entry`=201969; -- Ball and chain
UPDATE `gameobject_template` SET `ContentTuningId`=254, `VerifiedBuild`=43345 WHERE `entry` IN (204979, 204972); -- Halls of Origination Transit Device
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218969, 218961); -- The Praying Mantid
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210024; -- Light Grain
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=211331; -- Vintage Bug Sprayer
UPDATE `gameobject_template` SET `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211531; -- Yaungol Oil Derrick
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214193, 215939); -- Pandaren Tea Set
UPDATE `gameobject_template` SET `ContentTuningId`=234, `VerifiedBuild`=43345 WHERE `entry`=182145; -- Freezing Trap
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry` IN (215137, 215135); -- Sprinkler
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=43345 WHERE `entry`=278432; -- Obviously Safe Chest
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218966, 218974); -- Kypari Sap Container
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=243205; -- Inferno Shot
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=95737, `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=325619; -- Titan Artifact
UPDATE `gameobject_template` SET `ContentTuningId`=274, `VerifiedBuild`=43345 WHERE `entry`=233916; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210191; -- Memorial Flame of Zhu
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42311, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211779; -- Mao-Willow
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41035, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210186; -- Slick Mudfish
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218971, 218963); -- Remains of a Paragon
UPDATE `gameobject_template` SET `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216419; -- Undisturbed Soil
UPDATE `gameobject_template` SET `ContentTuningId`=1218, `VerifiedBuild`=43345 WHERE `entry`=243354; -- Felmouth Frenzy School
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=234193; -- Small Timber
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=325397; -- Suntouched Obelisk
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=43345 WHERE `entry`=215412; -- Sha-Touched Herb
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41331, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210858; -- Dry Fire Wood
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215942, 214197); -- Empty Keg of Brewfather Xin Wo Yin
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=43345 WHERE `entry`=237590; -- Lovely Coconut
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214200, 215945); -- Apothecary Tins of Yao Firmpaw
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=56658, `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=237227; -- Highmaul Reliquary
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215948, 214181); -- Manacles of Rebellion
UPDATE `gameobject_template` SET `ContentTuningId`=44, `VerifiedBuild`=43345 WHERE `entry`=192788; -- Berinand's Research
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215940, 214194); -- Pandaren Game Board
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=43345 WHERE `entry` IN (287163, 287165); -- Glowing Mushroom
UPDATE `gameobject_template` SET `ContentTuningId`=681, `VerifiedBuild`=43345 WHERE `entry`=243313; -- Blackrock Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=325414; -- Ancient Sundial
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=215719; -- Dented Shovel
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41153, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210209; -- Imperial Lotus
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=234195; -- Large Timber
UPDATE `gameobject_template` SET `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry` IN (212131, 212133, 212132); -- Niuzao Food Supply
UPDATE `gameobject_template` SET `ContentTuningId`=254, `VerifiedBuild`=43345 WHERE `entry`=207669; -- The Maker's Lift Controller
UPDATE `gameobject_template` SET `Data7`=5793, `Data8`=0, `VerifiedBuild`=43345 WHERE `entry`=215992; -- Ancient Amber Chunk
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18459, `ContentTuningId`=37, `VerifiedBuild`=43345 WHERE `entry`=181671; -- Fel Horde Banner
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=43345 WHERE `entry`=201885; -- Ice Wall
UPDATE `gameobject_template` SET `ContentTuningId`=245, `VerifiedBuild`=43345 WHERE `entry`=188528; -- Ormorok's Containment Sphere
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42706, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=212877; -- Highly Explosive Yaungol Oil Barrel
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry`=212174; -- Reef Octopus Swarm
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=43345 WHERE `entry`=320324; -- Blooms' Blessing Potion
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=43345 WHERE `entry`=237729; -- Pillar of Life
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215950, 214183); -- Terracotta Arm
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=43345 WHERE `entry`=232353; -- Overseer's Chair
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42246, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211766; -- Sra'thik Weapon
UPDATE `gameobject_template` SET `Data20`=0, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211456; -- Kafa'goot "Deposit"
UPDATE `gameobject_template` SET `ContentTuningId`=254, `VerifiedBuild`=43345 WHERE `entry` IN (207219, 207218); -- Beacon of Light
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41440, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210942; -- Partially Chewed Carrot
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26169, `ContentTuningId`=249, `VerifiedBuild`=43345 WHERE `entry`=193059; -- Vrykul Weapons
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214189, 215956); -- Mogu Coin
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215951, 214184); -- Petrified Bone Whip
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218965, 218973); -- Pollen Collector
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210946; -- Mite Trap
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218970, 218962); -- Inert Sound Beacon
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=209921; -- Muddy Water
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=241642; -- Tanaan Blood Orange
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=40870, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210002; -- Stolen Barley Sack
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215944, 214199); -- Gold-Inlaid Porcelain Funerary Figurine
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=325481; -- Amathet Armaments
UPDATE `gameobject_template` SET `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216150; -- Horde Supply Crate
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=43345 WHERE `entry`=223508; -- Star Reading
UPDATE `gameobject_template` SET `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=214734; -- Sik'thik Cage
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=43345 WHERE `entry`=230714; -- Illusion Charm
UPDATE `gameobject_template` SET `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216274; -- Signal Fire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41436, `ContentTuningId`=57, `VerifiedBuild`=43345 WHERE `entry`=210921; -- Celestial Jade
UPDATE `gameobject_template` SET `ContentTuningId`=236, `VerifiedBuild`=43345 WHERE `entry`=193051; -- Nerubian Scourge Egg
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215949, 214182); -- Mogu Runestone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27730, `ContentTuningId`=242, `VerifiedBuild`=43345 WHERE `entry`=201592; -- Infused Saronite Bars
UPDATE `gameobject_template` SET `ContentTuningId`=676, `VerifiedBuild`=43345 WHERE `entry`=181276; -- Flame Cap
UPDATE `gameobject_template` SET `ContentTuningId`=245, `VerifiedBuild`=43345 WHERE `entry`=188527; -- Anomalus' Containment Sphere
UPDATE `gameobject_template` SET `ContentTuningId`=482, `VerifiedBuild`=43345 WHERE `entry`=181030; -- Immolation Trap VI
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41595, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211480; -- Kafa'kota Berries
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215952, 214185); -- Thunder King Insignia
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=40870, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210001; -- Stolen Malt Sack
UPDATE `gameobject_template` SET `ContentTuningId`=234, `VerifiedBuild`=43345 WHERE `entry`=182054; -- The Underspore
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210022; -- Fresh Grain
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=43345 WHERE `entry`=234022; -- Timber
UPDATE `gameobject_template` SET `Data4`=18367, `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry`=214969; -- Manacles of Rebellion - Chains
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=43345 WHERE `entry`=290975; -- Silver Nugget
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=43345 WHERE `entry`=233073; -- Syth's Bookcase
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=43345 WHERE `entry`=232989; -- Basket of Arakkoa Goods
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=42449, `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=212084; -- Starshade
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41440, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210938; -- Partially Chewed Carrot
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=212643; -- Mark of the Empress
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=332552; -- The Origins of the Mogu
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=43345 WHERE `entry`=225924; -- Shadowmoon Cage
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=43345 WHERE `entry`=209329; -- Rich Kyparite Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=232256; -- Hemet's Keg O' Brew
UPDATE `gameobject_template` SET `ContentTuningId`=64, `VerifiedBuild`=43345 WHERE `entry`=228861; -- Siege Parts
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41481, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211143; -- Mogu Relic
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218964, 218972); -- Mantid Lamp
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=43345 WHERE `entry`=237765; -- Prickly Guava
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41035, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210184; -- Slick Mudfish
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=212933; -- Sonar Tower
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=43345 WHERE `entry`=215885; -- Klaxxi'vess
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=241529; -- Looted Treasures
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry`=212163; -- Emperor Salmon School
UPDATE `gameobject_template` SET `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211023; -- Cast Iron Pot
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210214; -- Memorial Flame of Po
UPDATE `gameobject_template` SET `ContentTuningId`=676, `VerifiedBuild`=43345 WHERE `entry`=181275; -- Ragveil
UPDATE `gameobject_template` SET `ContentTuningId`=706, `VerifiedBuild`=43345 WHERE `entry`=316500; -- Hide-No-More 2000
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=19848, `ContentTuningId`=234, `VerifiedBuild`=43345 WHERE `entry`=183385; -- Sanguine Hibiscus
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry` IN (239943, 239942); -- Iron Horde Cage
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214190, 215957); -- Worn Monument Ledger
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=43345 WHERE `entry`=233099; -- Wanted Poster
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry` IN (212099, 212100, 212104, 212105); -- Crocolisk Eggs
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=34736, `ContentTuningId`=56, `VerifiedBuild`=43345 WHERE `entry`=205823; -- Unexploded Mortar Shell
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41037, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210188; -- Rain-Slick Honeycomb
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41459, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211018; -- Root Vegetable
UPDATE `gameobject_template` SET `ContentTuningId`=1040, `VerifiedBuild`=43345 WHERE `entry`=241110; -- Meeting Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41443, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=211117; -- Spideroot
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=239839; -- Box of Iron Horde Equipment
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=218750; -- Work Orders
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41387, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210619; -- Ancient Dynastic Tablet
UPDATE `gameobject_template` SET `ContentTuningId`=292, `VerifiedBuild`=43345 WHERE `entry`=281079; -- Star Moss
UPDATE `gameobject_template` SET `ContentTuningId`=798, `VerifiedBuild`=43345 WHERE `entry`=188522; -- Arcane Trap
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=43345 WHERE `entry`=237728; -- Pillar of Creation
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41603, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211507; -- Pitch Pot
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=43345 WHERE `entry`=237772; -- Gorgraberry
UPDATE `gameobject_template` SET `Data1`=0, `Data6`=0, `Data18`=680, `Data19`=2, `Data26`=0, `Data30`=42938, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=213960; -- Yaungol Fire Carrier
UPDATE `gameobject_template` SET `ContentTuningId`=677, `VerifiedBuild`=43345 WHERE `entry`=190174; -- Frozen Herb
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214186, 215953); -- Edicts of the Thunder King
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=215700; -- Northeast Feeder
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41443, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210945; -- Spideroot
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=241728; -- Elixir of Reckless Power
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=43345 WHERE `entry`=181278; -- Ancient Lichen
UPDATE `gameobject_template` SET `ContentTuningId`=67, `VerifiedBuild`=43345 WHERE `entry`=231184; -- Offering Bowl
UPDATE `gameobject_template` SET `ContentTuningId`=254, `VerifiedBuild`=43345 WHERE `entry`=328463; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=482, `VerifiedBuild`=43345 WHERE `entry`=280498; -- Forge of Light
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=241517; -- Mysterious Fruit
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41481, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211148; -- Mogu Relic
UPDATE `gameobject_template` SET `ContentTuningId`=167, `VerifiedBuild`=43345 WHERE `entry`=218462; -- Portal to the Isle of Thunder
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (218959, 218967); -- Banner of the Mantid Empire
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=325505; -- Amathet War Banner
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=213973; -- Klaxxi Sonic Relay
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=241626; -- Sand-Encrusted Egg
UPDATE `gameobject_template` SET `ContentTuningId`=245, `VerifiedBuild`=43345 WHERE `entry`=188526; -- Telestra's Containment Sphere
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215947, 214202); -- Standard of Niuzao
UPDATE `gameobject_template` SET `ContentTuningId`=302, `VerifiedBuild`=43345 WHERE `entry`=237066; -- Inscription Work Order
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=214281; -- Kypari Ik Beacon
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=325477; -- Amathet Idol
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (214195, 215917); -- Twin Steins of Brewfather Quan Tou Kuo
UPDATE `gameobject_template` SET `castBarCaption`='Tightening the valve.', `Data10`=133534, `Data13`=1, `Data14`=69105, `Data22`=19634, `Data23`=1, `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216253; -- Faulty Valve
UPDATE `gameobject_template` SET `ContentTuningId`=191, `VerifiedBuild`=43345 WHERE `entry`=298918; -- Loose Rock
UPDATE `gameobject_template` SET `ContentTuningId`=191, `VerifiedBuild`=43345 WHERE `entry`=284411; -- Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=218765; -- Empty Crate
UPDATE `gameobject_template` SET `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=212634; -- Portal to Shan'ze Dao
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41596, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=211474; -- Suncrawler
UPDATE `gameobject_template` SET `ContentTuningId`=302, `VerifiedBuild`=43345 WHERE `entry`=237120; -- Alchemy Work Order
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=43345 WHERE `entry`=233634; -- Timber
UPDATE `gameobject_template` SET `ContentTuningId`=639, `VerifiedBuild`=43345 WHERE `entry`=271099; -- Spoils of the Legion's Fall
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry`=212173; -- Redbelly Mandarin School
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=214292; -- Kunchong Cage
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=215162; -- Pest Repeller
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41387, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210618; -- Ancient Dynastic Tablet
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41485, `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry`=211160; -- Pristine Crane Egg
UPDATE `gameobject_template` SET `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211837; -- Father's Bedroll
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41459, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211019; -- Root Vegetable
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=43345 WHERE `entry`=201848; -- Halls of Reflection Portcullis
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=43345 WHERE `entry`=234023; -- Large Timber
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=215698; -- Master Plow
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=343589; -- Crystallized Void
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=332551; -- Will of Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41595, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211454; -- Kafa'kota Bush
UPDATE `gameobject_template` SET `ContentTuningId`=62, `VerifiedBuild`=43345 WHERE `entry`=215762; -- Central Feeder
UPDATE `gameobject_template` SET `ContentTuningId`=59, `VerifiedBuild`=43345 WHERE `entry`=216177; -- Domination Point Lumber
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=230962; -- Pillar of Wind
UPDATE `gameobject_template` SET `ContentTuningId`=816, `VerifiedBuild`=43345 WHERE `entry`=237599; -- Botani Effects
UPDATE `gameobject_template` SET `ContentTuningId`=1218, `VerifiedBuild`=43345 WHERE `entry`=229068; -- Fat Sleeper School
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41603, `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211506; -- Pitch Pot
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41035, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210185; -- Slick Mudfish
UPDATE `gameobject_template` SET `ContentTuningId`=860, `VerifiedBuild`=43345 WHERE `entry` IN (215955, 214188); -- Warlord's Branding Iron
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=215705; -- Tillers Shrine
UPDATE `gameobject_template` SET `Data1`=1, `VerifiedBuild`=43345 WHERE `entry`=207547; -- Lift of the Makers
UPDATE `gameobject_template` SET `ContentTuningId`=498, `VerifiedBuild`=43345 WHERE `entry`=269255; -- 7.2 Tomb Raid - Kil'jaeden - Warp Tunnel Skybox
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41367, `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210565; -- Dark Soil
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=230671; -- Summoning Brazier
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=239768; -- Gutrek's Blade
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210857; -- Dry Fire Wood
UPDATE `gameobject_template` SET `ContentTuningId`=61, `VerifiedBuild`=43345 WHERE `entry`=211836; -- Father's Shield
UPDATE `gameobject_template` SET `ContentTuningId`=68, `VerifiedBuild`=43345 WHERE `entry`=231838; -- Gorehowl
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=210213; -- Memorial Flame of Rin
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=41481, `ContentTuningId`=60, `VerifiedBuild`=43345 WHERE `entry`=211147; -- Mogu Relic
UPDATE `gameobject_template` SET `ContentTuningId`=816, `VerifiedBuild`=43345 WHERE `entry`=237669; -- Ogre Cage
UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=43345 WHERE `entry`=225918; -- Ancestor's Totem
UPDATE `gameobject_template` SET `ContentTuningId`=176, `VerifiedBuild`=43345 WHERE `entry`=239979; -- Bottle of Machinery Grease
UPDATE `gameobject_template` SET `ContentTuningId`=680, `VerifiedBuild`=43345 WHERE `entry`=209312; -- Kyparite Deposit
UPDATE `gameobject_template` SET `ContentTuningId`=58, `VerifiedBuild`=43345 WHERE `entry`=211330; -- Rusty Watering Can
UPDATE `gameobject_template` SET `ContentTuningId`=703, `VerifiedBuild`=43345 WHERE `entry`=334659; -- Bottled Lightning
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=43345 WHERE `entry`=209355; -- Fool's Cap
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=43345 WHERE `entry`=287000; -- Mark of Ash
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=43971 WHERE `entry`=351544; -- Secret Treasure
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=43971 WHERE `entry`=179944; -- Meeting Stone Summoning Portal
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=43971 WHERE `entry`=353330; -- Faerie Stash
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=43971 WHERE `entry`=354113; -- Stoneborn Satchel
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=43971 WHERE `entry`=376028; -- 9BO_Brokers_Chair01
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=43971 WHERE `entry`=351541; -- Secret Treasure
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=43971 WHERE `entry`=353233; -- Enchanted Chest
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=44015 WHERE `entry` IN (251288, 249045, 249044); -- Gravestone
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=44015 WHERE `entry`=282419; -- Simple Gravestone
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=44015 WHERE `entry`=284451; -- Pirate Grog
UPDATE `gameobject_template` SET `ContentTuningId`=45, `VerifiedBuild`=44015 WHERE `entry`=186236; -- Valgarde Cannon
UPDATE `gameobject_template` SET `Data33`=107535, `VerifiedBuild`=44015 WHERE `entry`=354972; -- Challenger's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=45, `VerifiedBuild`=44015 WHERE `entry`=186894; -- Large Harpoon Lever
UPDATE `gameobject_template` SET `Data4`=1, `VerifiedBuild`=44015 WHERE `entry`=303147; -- Summoning Portal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22930, `ContentTuningId`=45, `VerifiedBuild`=44015 WHERE `entry`=186912; -- Valgarde Supply Crate
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=44015 WHERE `entry`=291225; -- Small Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=44015 WHERE `entry`=291272; -- Ruined Wedding Cake
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22771, `ContentTuningId`=45, `VerifiedBuild`=44015 WHERE `entry`=186662; -- Reagent Pouch
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=44015 WHERE `entry`=297881; -- Enchanted Chest
UPDATE `gameobject_template` SET `Data33`=107535, `VerifiedBuild`=44061 WHERE `entry`=354988; -- Challenger's Cache
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44061 WHERE `entry`=354852; -- Sprouting Growth
UPDATE `gameobject_template` SET `name`='Here Lies King Terenas Menethil II', `Data0`=1731, `Data2`=4, `VerifiedBuild`=44061 WHERE `entry`=278952; -- Doodad_TerenasPlaque
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44061 WHERE `entry`=354856; -- Slime-Coated Crate
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44127 WHERE `entry`=354647; -- Hearty Dragon Plume
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44127 WHERE `entry`=356820; -- Large Lunarlight Pod
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=44232 WHERE `entry`=2576; -- Altar of the Tides
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry` IN (187927, 187929, 187943, 187924, 187921, 187945, 207985, 208093, 207993, 187917, 207987, 187936, 187923); -- Alliance Bonfire
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry` IN (188049, 188152, 187882, 188146, 188150, 188148, 188144, 188145, 188147, 188139, 188135, 188149, 188138, 188134, 188137, 188143); -- Ice Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29585, `ContentTuningId`=14, `VerifiedBuild`=44232 WHERE `entry`=203215; -- Eldre'thar Relic
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=187708; -- Torch Target Brazier
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223107; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry` IN (187950, 207992, 187959, 187961, 187952, 208094, 187957, 187968, 207986, 187965); -- Horde Bonfire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26827, `ContentTuningId`=5, `VerifiedBuild`=44232 WHERE `entry`=194107; -- Encrusted Clam
UPDATE `gameobject_template` SET `ContentTuningId`=29, `VerifiedBuild`=44232 WHERE `entry`=206597; -- Twilight's Hammer Crate
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273849; -- Light
UPDATE `gameobject_template` SET `ContentTuningId`=691, `VerifiedBuild`=44232 WHERE `entry`=319208; -- Buzzbox 111
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18452, `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=181686; -- Warsong Lumber Pile
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=1701, `ContentTuningId`=72, `VerifiedBuild`=44232 WHERE `entry`=1673; -- Fel Cone
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=44232 WHERE `entry`=281674; -- Azerite-Dusted Blade
UPDATE `gameobject_template` SET `ContentTuningId`=16, `VerifiedBuild`=44232 WHERE `entry`=201877; -- Battlescar Flagpole
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry` IN (272209, 273513); -- The Vindicaar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26865, `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=310496; -- Potion of Wildfire
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=276918; -- Smelting Vessel
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18629, `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=181891; -- Blood Mushroom
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195693; -- Fatherstone
UPDATE `gameobject_template` SET `ContentTuningId`=18, `VerifiedBuild`=44232 WHERE `entry` IN (58, 179426); -- Gri'lek the Wanderer
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=208830; -- Rice Pile
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry` IN (276296, 273273); -- Netherlight Crucible
UPDATE `gameobject_template` SET `type`=0, `Data1`=0, `Data2`=3000, `Data7`=5793, `Data8`=1, `VerifiedBuild`=44232 WHERE `entry`=368249; -- Door
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=44232 WHERE `entry`=203384; -- Seldarria's Egg
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=44232 WHERE `entry`=281718; -- HELP WANTED
UPDATE `gameobject_template` SET `ContentTuningId`=72, `VerifiedBuild`=44232 WHERE `entry`=2741; -- Chest of the Sky
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29585, `ContentTuningId`=14, `VerifiedBuild`=44232 WHERE `entry`=203216; -- Eldre'thar Relic
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=8409, `ContentTuningId`=22, `VerifiedBuild`=44232 WHERE `entry`=143980; -- Gordunni Scroll
UPDATE `gameobject_template` SET `Data6`=0, `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223105; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=6711, `ContentTuningId`=22, `VerifiedBuild`=44232 WHERE `entry`=142185; -- Flame of Byltan
UPDATE `gameobject_template` SET `ContentTuningId`=733, `VerifiedBuild`=44232 WHERE `entry`=316792; -- Pilfered Iron Ore
UPDATE `gameobject_template` SET `displayId`=39475, `Data26`=1, `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181336; -- Flame of Orgrimmar
UPDATE `gameobject_template` SET `displayId`=39475, `Data26`=1, `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181337; -- Flame of Thunder Bluff
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18546, `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=181854; -- Sand Pear
UPDATE `gameobject_template` SET `ContentTuningId`=55, `VerifiedBuild`=44232 WHERE `entry`=205539; -- Tormented Tomb-Robber
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181306; -- Camp Jug
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39754, `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=208814; -- Buried Kimchi Jar
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181605; -- Ribbon Pole
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=44232 WHERE `entry`=267838; -- Cake
UPDATE `gameobject_template` SET `Data6`=0, `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=221617; -- Skull-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=277263; -- Legion Portal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27537, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195601; -- Element 116
UPDATE `gameobject_template` SET `ContentTuningId`=408, `VerifiedBuild`=44232 WHERE `entry`=208829; -- Rice Basket
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27572, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=196395; -- Defiled Relic
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44232 WHERE `entry`=353650; -- Steward's Golden Chest
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195450; -- Nijel's Point Ruin
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=44232 WHERE `entry`=267840; -- Wine Bottle
UPDATE `gameobject_template` SET `displayId`=39476, `Data26`=1, `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181334; -- Flame of Darnassus
UPDATE `gameobject_template` SET `Data6`=0, `Data26`=115607, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=220832; -- Sunken Treasure
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15124, `ContentTuningId`=200, `VerifiedBuild`=44232 WHERE `entry`=178186; -- Sapphire of Aku'Mai
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273784; -- Portal to Dalaran
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=275101; -- Lightforged Beacon
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=44232 WHERE `entry`=319226; -- Darkshore Cache
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28373, `ContentTuningId`=16, `VerifiedBuild`=44232 WHERE `entry`=202477; -- Siege Engine Scrap
UPDATE `gameobject_template` SET `Data6`=0, `VerifiedBuild`=44232 WHERE `entry`=209653; -- Cooking Fire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=26865, `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=194202; -- Potion of Wildfire
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223537; -- Flameheart Shawl
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=44232 WHERE `entry`=292686; -- Ominous Altar
UPDATE `gameobject_template` SET `Data6`=0, `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223104; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=44232 WHERE `entry` IN (303017, 293844); -- Ordinary Pebble
UPDATE `gameobject_template` SET `ContentTuningId`=691, `VerifiedBuild`=44232 WHERE `entry`=319209; -- Buzzbox 627
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44232 WHERE `entry`=144063; -- Equinex Monolith
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=269266; -- Vindicaar Bunker
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=44232 WHERE `entry`=280992; -- Siren Wind Chimes
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10980, `ContentTuningId`=32, `VerifiedBuild`=44232 WHERE `entry`=164778; -- Blue Power Crystal
UPDATE `gameobject_template` SET `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=182114; -- Corrupted Crystal Aura
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27239, `ContentTuningId`=32, `VerifiedBuild`=44232 WHERE `entry`=195022; -- Venomhide Egg
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181305; -- Camp Table
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=272190; -- Navigation Console
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=44232 WHERE `entry`=281647; -- Posted Notice
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16464, `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=179489; -- Waterlogged Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=22, `VerifiedBuild`=44232 WHERE `entry`=144050; -- Gordunni Trap
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273850; -- Shadow
UPDATE `gameobject_template` SET `ContentTuningId`=72, `VerifiedBuild`=44232 WHERE `entry`=208046; -- Fel Cone
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=187892; -- Ice Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=10980, `ContentTuningId`=32, `VerifiedBuild`=44232 WHERE `entry`=164658; -- Blue Power Crystal
UPDATE `gameobject_template` SET `displayId`=39476, `Data26`=1, `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=188128; -- Flame of the Exodar
UPDATE `gameobject_template` SET `ContentTuningId`=206, `VerifiedBuild`=44232 WHERE `entry`=178827; -- Meeting Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18501, `ContentTuningId`=76, `VerifiedBuild`=44232 WHERE `entry`=181757; -- Stillpine Grain
UPDATE `gameobject_template` SET `Data30`=95217, `ContentTuningId`=260, `VerifiedBuild`=44232 WHERE `entry`=209547; -- Murozond's Temporal Cache
UPDATE `gameobject_template` SET `ContentTuningId`=252, `VerifiedBuild`=44232 WHERE `entry` IN (209438, 209440, 209441, 209439); -- Time Transit Device
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=22355, `ContentTuningId`=23, `VerifiedBuild`=44232 WHERE `entry`=186423; -- Witchbane
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=194612; -- Ritual Gem
UPDATE `gameobject_template` SET `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=202275; -- Wrathscale Fountain
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=36130, `ContentTuningId`=257, `VerifiedBuild`=44232 WHERE `entry`=207415; -- Twilight Documents
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=44232 WHERE `entry`=267843; -- Table
UPDATE `gameobject_template` SET `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=181928; -- Princess Stillpine's Cage
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=13944, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=176582; -- Shellfish Trap
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29585, `ContentTuningId`=14, `VerifiedBuild`=44232 WHERE `entry`=203214; -- Eldre'thar Relic
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=44232 WHERE `entry`=241319; -- Libram
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=44232 WHERE `entry`=292917; -- Sparkling Tidescale
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=55449, `ContentTuningId`=755, `VerifiedBuild`=44232 WHERE `entry`=234271; -- Hollowed Skull
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=44232 WHERE `entry`=271616; -- Marked Goods
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=44232 WHERE `entry`=267839; -- Cake Slice
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=207321; -- Hero's Call Board
UPDATE `gameobject_template` SET `ContentTuningId`=23, `VerifiedBuild`=44232 WHERE `entry`=205332; -- Wanted Poster
UPDATE `gameobject_template` SET `Data2`=3000, `VerifiedBuild`=44232 WHERE `entry`=177444; -- Stone Door
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=6708, `ContentTuningId`=22, `VerifiedBuild`=44232 WHERE `entry`=142186; -- Flame of Lahassa
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223087; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `type`=0, `Data1`=0, `Data2`=3000, `Data7`=5793, `Data8`=1, `VerifiedBuild`=44232 WHERE `entry`=368247; -- Door
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195600; -- Smouldering Stone
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44232 WHERE `entry`=352596; -- Sprouting Growth
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223098; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=208815; -- Buried Jar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27565, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195674; -- Aloe Thistle
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=188073; -- Ahune Bonfire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15124, `ContentTuningId`=200, `VerifiedBuild`=44232 WHERE `entry`=178185; -- Sapphire of Aku'Mai
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273846; -- Crown Pedestal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27568, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195692; -- Cenarion Supply Crate
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=188130; -- Ice Stone
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=44232 WHERE `entry`=289310; -- WANTED: Raging Earthguard
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181302; -- Camp Crate
UPDATE `gameobject_template` SET `ContentTuningId`=46, `VerifiedBuild`=44232 WHERE `entry`=188539; -- Coldwind Tree
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=293885; -- Portal to Exodar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16465, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=179493; -- Mossy Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=44232 WHERE `entry`=266403; -- Book Pile 1
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=44232 WHERE `entry`=148504; -- A Conspicuous Gravestone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=11141, `ContentTuningId`=32, `VerifiedBuild`=44232 WHERE `entry`=164958; -- Bloodpetal Sprout
UPDATE `gameobject_template` SET `ContentTuningId`=864, `VerifiedBuild`=44232 WHERE `entry`=325983; -- Portal to Stormwind
UPDATE `gameobject_template` SET `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=194629; -- Ritual Ground Rune
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28439, `ContentTuningId`=22, `VerifiedBuild`=44232 WHERE `entry`=202606; -- Stonetear
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=35745, `ContentTuningId`=656, `VerifiedBuild`=44232 WHERE `entry`=206905; -- Cursed Shackles
UPDATE `gameobject_template` SET `ContentTuningId`=809, `VerifiedBuild`=44232 WHERE `entry`=309572; -- Antique Telescope
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=44232 WHERE `entry`=267842; -- Fountain
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=181307; -- Camp Mug
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=44232 WHERE `entry`=278252; -- Job Flyer
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28373, `ContentTuningId`=16, `VerifiedBuild`=44232 WHERE `entry`=202478; -- Siege Engine Scrap
UPDATE `gameobject_template` SET `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223096; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=44232 WHERE `entry`=292673; -- A Damp Scroll
UPDATE `gameobject_template` SET `ContentTuningId`=32, `VerifiedBuild`=44232 WHERE `entry`=148503; -- Fire Plume Ridge Hot Spot
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273684; -- Magical Boots
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39774, `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=208831; -- Teldrassil Clam
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry` IN (273682, 273681); -- Crate
UPDATE `gameobject_template` SET `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195588; -- Swoop Nest
UPDATE `gameobject_template` SET `ContentTuningId`=691, `VerifiedBuild`=44232 WHERE `entry`=317407; -- Goblin Heavy Borer
UPDATE `gameobject_template` SET `ContentTuningId`=656, `VerifiedBuild`=44232 WHERE `entry`=208226; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=188021; -- Camp Pavilion
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18426, `ContentTuningId`=76, `VerifiedBuild`=44232 WHERE `entry`=181644; -- Azure Snapdragon
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273499; -- Ven'orn Egg
UPDATE `gameobject_template` SET `ContentTuningId`=835, `VerifiedBuild`=44232 WHERE `entry`=321840; -- Zelling's Boat
UPDATE `gameobject_template` SET `ContentTuningId`=691, `VerifiedBuild`=44232 WHERE `entry`=317406; -- Goblin Miner
UPDATE `gameobject_template` SET `Data1`=0, `Data15`=0, `Data30`=46588, `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=188192; -- Ice Chest
UPDATE `gameobject_template` SET `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223538; -- Riverspeaker's Trident
UPDATE `gameobject_template` SET `ContentTuningId`=650, `VerifiedBuild`=44232 WHERE `entry`=281073; -- Smoke Stack
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27521, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=195535; -- Bleached Skullpile
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=44232 WHERE `entry`=278571; -- Campfire
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16464, `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=179487; -- Waterlogged Footlocker
UPDATE `gameobject_template` SET `Data6`=0, `Data17`=0, `ContentTuningId`=169, `VerifiedBuild`=44232 WHERE `entry`=223109; -- Moss-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=55, `VerifiedBuild`=44232 WHERE `entry`=206390; -- Slitherer Egg
UPDATE `gameobject_template` SET `ContentTuningId`=394, `VerifiedBuild`=44232 WHERE `entry`=188020; -- Camp Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=2934, `ContentTuningId`=12, `VerifiedBuild`=44232 WHERE `entry`=17282; -- Bathran's Hair
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=44232 WHERE `entry`=203294; -- Krom'gar Log Book
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273683; -- Magical Hat
UPDATE `gameobject_template` SET `ContentTuningId`=337, `VerifiedBuild`=44232 WHERE `entry`=273764; -- Portal to The Vindicaar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=16465, `ContentTuningId`=19, `VerifiedBuild`=44232 WHERE `entry`=179491; -- Waterlogged Footlocker
UPDATE `gameobject_template` SET `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=181779; -- Impact Site Crystal
UPDATE `gameobject_template` SET `ContentTuningId`=21, `VerifiedBuild`=44232 WHERE `entry`=203248; -- Horn Mouthpiece
UPDATE `gameobject_template` SET `ContentTuningId`=72, `VerifiedBuild`=44232 WHERE `entry`=2740; -- Chest of the Raven Claw
UPDATE `gameobject_template` SET `ContentTuningId`=650, `VerifiedBuild`=44232 WHERE `entry`=281071; -- Goblin Battery
UPDATE `gameobject_template` SET `Data25`=1047, `ContentTuningId`=259, `VerifiedBuild`=44232 WHERE `entry`=205216; -- Neptulon's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=693, `VerifiedBuild`=44232 WHERE `entry`=313879; -- Everburning Fuel
UPDATE `gameobject_template` SET `ContentTuningId`=876, `VerifiedBuild`=44232 WHERE `entry`=208825; -- Shrine of the Ancestors
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=15124, `ContentTuningId`=200, `VerifiedBuild`=44232 WHERE `entry`=178184; -- Sapphire of Aku'Mai
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18628, `ContentTuningId`=4, `VerifiedBuild`=44232 WHERE `entry`=181892; -- Aquatic Stinkhorn
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44232 WHERE `entry`=352086; -- Blackhound Cache
UPDATE `gameobject_template` SET `ContentTuningId`=344, `VerifiedBuild`=44232 WHERE `entry`=267841; -- Candle
UPDATE `gameobject_template` SET `ContentTuningId`=292, `VerifiedBuild`=44232 WHERE `entry`=293749; -- Rasboralus School

DELETE FROM `gameobject_questitem` WHERE `GameObjectEntry` IN (375106,373479,375223,375222,374928,374927,373505,373463,349796,352754,358380,353516,355971,353331,358297,368627,375495,340058,375977,375354,
373461,354075,354192,357336,357156,356607,368625,356596,353325,356597,368626,357338,357206,357335,357159,357337,239768,357205,368631,310496);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(375106, 0, 189438, 42560), -- Instructional Bit
(373479, 0, 187996, 42560), -- Sacred Relic
(375223, 0, 189500, 42560), -- Repository Vault
(375222, 0, 189501, 42560), -- Protoform Tool
(374928, 0, 188738, 42852), -- Buried Artifact
(374927, 0, 188738, 42852), -- Buried Artifact
(373505, 0, 188137, 42979), -- Targeting Relic
(373463, 0, 187944, 43114), -- Progenitor Relic
(349796, 1, 179318, 43206), -- Gilded Plum Chest
(349796, 0, 179327, 43206), -- Gilded Plum Chest
(352754, 1, 179321, 43206), -- Silver Strongbox
(352754, 0, 179327, 43206), -- Silver Strongbox
(358380, 0, 181356, 43206), -- Glenzu Original
(353516, 1, 179321, 43206), -- Silver Strongbox
(353516, 0, 179327, 43206), -- Silver Strongbox
(355971, 0, 181500, 43206), -- Stoneborn Glaive
(353331, 1, 179327, 43206), -- Faerie Stash
(353331, 0, 179320, 43206), -- Faerie Stash
(358297, 0, 183186, 43206), -- Purified Nectar
(368627, 0, 186171, 43206), -- Observation Device
(375495, 3, 190955, 43340), -- Undulating Foliage
(375495, 2, 190927, 43340), -- Undulating Foliage
(375495, 1, 190955, 43340), -- Undulating Foliage
(375495, 0, 190927, 43340), -- Undulating Foliage
(340058, 1, 179321, 43340), -- Baedos' Regurgitated Treasure
(340058, 0, 179327, 43340), -- Baedos' Regurgitated Treasure
(375977, 0, 190940, 43340), -- Firim's Research Notes
(375354, 1, 190955, 43340), -- Domination Cache
(375354, 0, 190927, 43340), -- Domination Cache
(373461, 0, 187942, 43340), -- Chromatic Rosid
(354075, 0, 171343, 43340), -- Blank Parchment
(354192, 1, 179318, 43345), -- Stoneborn Satchel
(354192, 0, 179327, 43345), -- Stoneborn Satchel
(357336, 0, 182360, 43345), -- Fresh Ardenweald Anima
(357156, 0, 182310, 43345), -- Confiscated Instruments
(356607, 0, 181839, 43345), -- Violet Frill
(368625, 0, 186169, 43345), -- Observation Device
(356596, 0, 181829, 43345), -- Feather Cap
(353325, 1, 179321, 43345), -- Silver Strongbox
(353325, 0, 179327, 43345), -- Silver Strongbox
(356597, 0, 181830, 43345), -- Lacy Bell Morel
(368626, 0, 186170, 43345), -- Observation Device
(357338, 0, 182361, 43345), -- Fresh Revendreth Anima
(357206, 0, 182312, 43345), -- Confiscated Stage Props
(357335, 0, 182358, 43345), -- Fresh Bastion Anima
(357159, 0, 182302, 43345), -- Stack of Promotional Posters
(357337, 0, 182359, 43345), -- Fresh Maldraxxus Anima
(239768, 0, 120998, 43345), -- Gutrek's Blade
(357205, 0, 182311, 43345), -- Confiscated Stage Lights
(368631, 0, 186175, 44232), -- Drop Box
(310496, 0, 44967, 44232); -- Potion of Wildfire

DELETE FROM `npc_text` WHERE `ID` IN (43616,43629,43880,43637,42382,44096,43750,43756,43615,43752,43618,43617,43735,24749,43773,43719,43562,43591,43596,43712,43553,43902,43718,43836,43881,43772,25444,25463,43827,43987,43908,
25451,43594,43511,43901,43762,43786,43976,43985,43907,43593,44027,43769,44104,43536,44034,43767,43710,43975,43577,43763,42825,43761,43770,43595,43789,44013,43997,42798,44009,43788,44000,43783,43978,43977,43996,43980,44003,
44001,43999,43790,43998,43994,40117,42769,43830,40603,42770,43828,44097,41449,42021,42734,43558,28924,42731,43169,28917,40496,40642,31580,40495,28907,43027,43568,43556,43104,43571,43768,43105,42989,42789,42750,43004,42998,
42848,42900,42740,42859,43128,41157,41459,41613,41115,41158,42147,42296,42173,42160,43916,43561,41457,43703,42171,41748,41156,41453,41456,42604,44075,41860,36764,41663);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(43616, 0, 0, 0, 0, 0, 0, 0, 0, 213068, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43616
(43629, 1, 0, 0, 0, 0, 0, 0, 0, 213135, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43629
(43880, 0, 0, 0, 0, 0, 0, 0, 0, 215080, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43880
(43637, 0, 0, 0, 0, 0, 0, 0, 0, 213195, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43637
(42382, 1, 0, 0, 0, 0, 0, 0, 0, 205811, 0, 0, 0, 0, 0, 0, 0, 42560), -- 42382
(44096, 1, 0, 0, 0, 0, 0, 0, 0, 216250, 0, 0, 0, 0, 0, 0, 0, 42560), -- 44096
(43750, 0, 0, 0, 0, 0, 0, 0, 0, 212707, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43750
(43756, 0, 0, 0, 0, 0, 0, 0, 0, 214047, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43756
(43615, 0, 0, 0, 0, 0, 0, 0, 0, 213066, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43615
(43752, 0, 0, 0, 0, 0, 0, 0, 0, 214045, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43752
(43618, 0, 0, 0, 0, 0, 0, 0, 0, 213070, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43618
(43617, 0, 0, 0, 0, 0, 0, 0, 0, 213069, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43617
(43735, 0, 0, 0, 0, 0, 0, 0, 0, 213891, 0, 0, 0, 0, 0, 0, 0, 42560), -- 43735
(24749, 1, 0, 0, 0, 0, 0, 0, 0, 87403, 0, 0, 0, 0, 0, 0, 0, 42698), -- 24749
(43773, 0, 0, 0, 0, 0, 0, 0, 0, 214158, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43773
(43719, 0, 0, 0, 0, 0, 0, 0, 0, 213701, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43719
(43562, 0, 0, 0, 0, 0, 0, 0, 0, 212847, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43562
(43591, 0, 0, 0, 0, 0, 0, 0, 0, 213031, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43591
(43596, 0, 0, 0, 0, 0, 0, 0, 0, 202272, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43596
(43712, 0, 0, 0, 0, 0, 0, 0, 0, 213597, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43712
(43553, 0, 0, 0, 0, 0, 0, 0, 0, 212809, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43553
(43902, 0, 0, 0, 0, 0, 0, 0, 0, 215438, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43902
(43718, 0, 0, 0, 0, 0, 0, 0, 0, 213672, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43718
(43836, 1, 0, 0, 0, 0, 0, 0, 0, 215136, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43836
(43881, 0, 0, 0, 0, 0, 0, 0, 0, 215080, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43881
(43772, 0, 0, 0, 0, 0, 0, 0, 0, 214152, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43772
(25444, 1, 0, 0, 0, 0, 0, 0, 0, 89049, 0, 0, 0, 0, 0, 0, 0, 42698), -- 25444
(25463, 1, 0, 0, 0, 0, 0, 0, 0, 90085, 0, 0, 0, 0, 0, 0, 0, 42698), -- 25463
(43827, 0, 0, 0, 0, 0, 0, 0, 0, 214684, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43827
(43987, 0, 0, 0, 0, 0, 0, 0, 0, 215923, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43987
(43908, 0, 0, 0, 0, 0, 0, 0, 0, 215481, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43908
(25451, 1, 0, 0, 0, 0, 0, 0, 0, 89069, 0, 0, 0, 0, 0, 0, 0, 42698), -- 25451
(43594, 0, 0, 0, 0, 0, 0, 0, 0, 198154, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43594
(43511, 0, 0, 0, 0, 0, 0, 0, 0, 212737, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43511
(43901, 0, 0, 0, 0, 0, 0, 0, 0, 215439, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43901
(43762, 0, 0, 0, 0, 0, 0, 0, 0, 214142, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43762
(43786, 0, 0, 0, 0, 0, 0, 0, 0, 212946, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43786
(43976, 0, 0, 0, 0, 0, 0, 0, 0, 215882, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43976
(43985, 1, 0, 0, 0, 0, 0, 0, 0, 215820, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43985
(43907, 0, 0, 0, 0, 0, 0, 0, 0, 215480, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43907
(43593, 0, 0, 0, 0, 0, 0, 0, 0, 213034, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43593
(44027, 0, 0, 0, 0, 0, 0, 0, 0, 216042, 0, 0, 0, 0, 0, 0, 0, 42698), -- 44027
(43769, 0, 0, 0, 0, 0, 0, 0, 0, 214149, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43769
(44104, 0, 0, 0, 0, 0, 0, 0, 0, 216296, 0, 0, 0, 0, 0, 0, 0, 42698), -- 44104
(43536, 0, 0, 0, 0, 0, 0, 0, 0, 212770, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43536
(44034, 1, 0, 0, 0, 0, 0, 0, 0, 216051, 0, 0, 0, 0, 0, 0, 0, 42698), -- 44034
(43767, 0, 0, 0, 0, 0, 0, 0, 0, 214145, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43767
(43710, 0, 0, 0, 0, 0, 0, 0, 0, 213593, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43710
(43975, 0, 0, 0, 0, 0, 0, 0, 0, 215873, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43975
(43577, 0, 0, 0, 0, 0, 0, 0, 0, 212949, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43577
(43763, 0, 0, 0, 0, 0, 0, 0, 0, 214144, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43763
(42825, 1, 0, 0, 0, 0, 0, 0, 0, 209175, 0, 0, 0, 0, 0, 0, 0, 42698), -- 42825
(43761, 0, 0, 0, 0, 0, 0, 0, 0, 214136, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43761
(43770, 0, 0, 0, 0, 0, 0, 0, 0, 214150, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43770
(43595, 0, 0, 0, 0, 0, 0, 0, 0, 212743, 0, 0, 0, 0, 0, 0, 0, 42698), -- 43595
(43789, 0, 0, 0, 0, 0, 0, 0, 0, 214257, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43789
(44013, 0, 0, 0, 0, 0, 0, 0, 0, 215970, 0, 0, 0, 0, 0, 0, 0, 42979), -- 44013
(43997, 0, 0, 0, 0, 0, 0, 0, 0, 215928, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43997
(42798, 1, 0, 0, 0, 0, 0, 0, 0, 208986, 0, 0, 0, 0, 0, 0, 0, 42979), -- 42798
(44009, 0, 0, 0, 0, 0, 0, 0, 0, 215971, 0, 0, 0, 0, 0, 0, 0, 42979), -- 44009
(43788, 0, 0, 0, 0, 0, 0, 0, 0, 214256, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43788
(44000, 0, 0, 0, 0, 0, 0, 0, 0, 215934, 0, 0, 0, 0, 0, 0, 0, 42979), -- 44000
(43783, 0, 0, 0, 0, 0, 0, 0, 0, 214202, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43783
(43978, 0, 0, 0, 0, 0, 0, 0, 0, 215833, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43978
(43977, 0, 0, 0, 0, 0, 0, 0, 0, 215832, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43977
(43996, 0, 0, 0, 0, 0, 0, 0, 0, 215927, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43996
(43980, 0, 0, 0, 0, 0, 0, 0, 0, 215830, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43980
(44003, 0, 0, 0, 0, 0, 0, 0, 0, 215937, 0, 0, 0, 0, 0, 0, 0, 42979), -- 44003
(44001, 0, 0, 0, 0, 0, 0, 0, 0, 215936, 0, 0, 0, 0, 0, 0, 0, 42979), -- 44001
(43999, 0, 0, 0, 0, 0, 0, 0, 0, 215935, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43999
(43790, 0, 0, 0, 0, 0, 0, 0, 0, 214260, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43790
(43998, 0, 0, 0, 0, 0, 0, 0, 0, 215930, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43998
(43994, 0, 0, 0, 0, 0, 0, 0, 0, 215929, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43994
(40117, 1, 0, 0, 0, 0, 0, 0, 0, 193258, 0, 0, 0, 0, 0, 0, 0, 42979), -- 40117
(42769, 1, 0, 0, 0, 0, 0, 0, 0, 207525, 0, 0, 0, 0, 0, 0, 0, 42979), -- 42769
(43830, 0, 0, 0, 0, 0, 0, 0, 0, 214701, 0, 0, 0, 0, 0, 0, 0, 42979), -- 43830
(40603, 1, 0, 0, 0, 0, 0, 0, 0, 197267, 0, 0, 0, 0, 0, 0, 0, 42979), -- 40603
(42770, 1, 0, 0, 0, 0, 0, 0, 0, 207528, 0, 0, 0, 0, 0, 0, 0, 42979), -- 42770
(43828, 1, 0, 0, 0, 0, 0, 0, 0, 214686, 0, 0, 0, 0, 0, 0, 0, 43114), -- 43828
(44097, 1, 0, 0, 0, 0, 0, 0, 0, 216252, 0, 0, 0, 0, 0, 0, 0, 43114), -- 44097
(41449, 1, 0, 0, 0, 0, 0, 0, 0, 202202, 0, 0, 0, 0, 0, 0, 0, 43206), -- 41449
(42021, 1, 1, 1, 1, 1, 1, 1, 0, 205550, 203152, 203150, 203149, 203148, 203146, 203142, 0, 43206), -- 42021
(42734, 0, 0, 0, 0, 0, 0, 0, 0, 207989, 0, 0, 0, 0, 0, 0, 0, 43206), -- 42734
(43558, 1, 0, 0, 0, 0, 0, 0, 0, 212833, 0, 0, 0, 0, 0, 0, 0, 43206), -- 43558
(28924, 1, 0, 0, 0, 0, 0, 0, 0, 109085, 0, 0, 0, 0, 0, 0, 0, 43206), -- 28924
(42731, 0, 0, 0, 0, 0, 0, 0, 0, 207972, 0, 0, 0, 0, 0, 0, 0, 43206), -- 42731
(43169, 0, 0, 0, 0, 0, 0, 0, 0, 211867, 0, 0, 0, 0, 0, 0, 0, 43206), -- 43169
(28917, 1, 0, 0, 0, 0, 0, 0, 0, 109035, 0, 0, 0, 0, 0, 0, 0, 43206), -- 28917
(40496, 1, 0, 0, 0, 0, 0, 0, 0, 196233, 0, 0, 0, 0, 0, 0, 0, 43206), -- 40496
(40642, 1, 0, 0, 0, 0, 0, 0, 0, 197633, 0, 0, 0, 0, 0, 0, 0, 43206), -- 40642
(31580, 1, 0, 0, 0, 0, 0, 0, 0, 129330, 0, 0, 0, 0, 0, 0, 0, 43206), -- 31580
(40495, 1, 0, 0, 0, 0, 0, 0, 0, 196229, 0, 0, 0, 0, 0, 0, 0, 43206), -- 40495
(28907, 1, 0, 0, 0, 0, 0, 0, 0, 107966, 0, 0, 0, 0, 0, 0, 0, 43206), -- 28907
(43027, 0, 0, 0, 0, 0, 0, 0, 0, 211284, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43027
(43568, 1, 0, 0, 0, 0, 0, 0, 0, 212876, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43568
(43556, 1, 0, 0, 0, 0, 0, 0, 0, 212825, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43556
(43104, 0, 0, 0, 0, 0, 0, 0, 0, 211508, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43104
(43571, 1, 0, 0, 0, 0, 0, 0, 0, 212895, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43571
(43768, 0, 0, 0, 0, 0, 0, 0, 0, 214146, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43768
(43105, 0, 0, 0, 0, 0, 0, 0, 0, 211508, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43105
(42989, 1, 0, 0, 0, 0, 0, 0, 0, 210930, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42989
(42789, 0, 0, 0, 0, 0, 0, 0, 0, 208968, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42789
(42750, 0, 0, 0, 0, 0, 0, 0, 0, 208260, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42750
(43004, 0, 0, 0, 0, 0, 0, 0, 0, 211102, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43004
(42998, 0, 0, 0, 0, 0, 0, 0, 0, 210993, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42998
(42848, 0, 0, 0, 0, 0, 0, 0, 0, 208967, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42848
(42900, 0, 0, 0, 0, 0, 0, 0, 0, 209658, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42900
(42740, 0, 0, 0, 0, 0, 0, 0, 0, 192479, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42740
(42859, 0, 0, 0, 0, 0, 0, 0, 0, 209355, 0, 0, 0, 0, 0, 0, 0, 43340), -- 42859
(43128, 0, 0, 0, 0, 0, 0, 0, 0, 209896, 0, 0, 0, 0, 0, 0, 0, 43340), -- 43128
(41157, 1, 0, 0, 0, 0, 0, 0, 0, 200538, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41157
(41459, 1, 0, 0, 0, 0, 0, 0, 0, 202233, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41459
(41613, 1, 0, 0, 0, 0, 0, 0, 0, 203467, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41613
(41115, 1, 0, 0, 0, 0, 0, 0, 0, 200277, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41115
(41158, 1, 0, 0, 0, 0, 0, 0, 0, 200539, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41158
(42147, 1, 0, 0, 0, 0, 0, 0, 0, 206110, 0, 0, 0, 0, 0, 0, 0, 43345), -- 42147
(42296, 1, 0, 0, 0, 0, 0, 0, 0, 206192, 0, 0, 0, 0, 0, 0, 0, 43345), -- 42296
(42173, 1, 0, 0, 0, 0, 0, 0, 0, 206321, 0, 0, 0, 0, 0, 0, 0, 43345), -- 42173
(42160, 1, 0, 0, 0, 0, 0, 0, 0, 206150, 0, 0, 0, 0, 0, 0, 0, 43345), -- 42160
(43916, 0, 0, 0, 0, 0, 0, 0, 0, 215515, 0, 0, 0, 0, 0, 0, 0, 43345), -- 43916
(43561, 0, 0, 0, 0, 0, 0, 0, 0, 212533, 0, 0, 0, 0, 0, 0, 0, 43345), -- 43561
(41457, 1, 0, 0, 0, 0, 0, 0, 0, 202227, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41457
(43703, 0, 0, 0, 0, 0, 0, 0, 0, 213536, 0, 0, 0, 0, 0, 0, 0, 43345), -- 43703
(42171, 1, 0, 0, 0, 0, 0, 0, 0, 206314, 0, 0, 0, 0, 0, 0, 0, 43345), -- 42171
(41748, 1, 0, 0, 0, 0, 0, 0, 0, 204484, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41748
(41156, 1, 0, 0, 0, 0, 0, 0, 0, 200533, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41156
(41453, 1, 0, 0, 0, 0, 0, 0, 0, 202222, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41453
(41456, 1, 0, 0, 0, 0, 0, 0, 0, 202226, 0, 0, 0, 0, 0, 0, 0, 43345), -- 41456
(42604, 0, 0, 0, 0, 0, 0, 0, 0, 207373, 0, 0, 0, 0, 0, 0, 0, 43345), -- 42604
(44075, 0, 0, 0, 0, 0, 0, 0, 0, 216171, 0, 0, 0, 0, 0, 0, 0, 43345), -- 44075
(41860, 1, 1, 1, 1, 1, 1, 1, 1, 204954, 204955, 204956, 204957, 204958, 204959, 204960, 204961, 43345), -- 41860
(36764, 1, 0, 0, 0, 0, 0, 0, 0, 166784, 0, 0, 0, 0, 0, 0, 0, 43345), -- 36764
(41663, 1, 1, 1, 1, 1, 1, 1, 1, 204043, 204044, 204045, 204046, 204047, 204048, 204049, 204050, 43345); -- 41663

UPDATE `npc_text` SET `BroadcastTextId0`=213417, `VerifiedBuild`=42560 WHERE `ID`=41823; -- 41823
UPDATE `npc_text` SET `BroadcastTextId0`=214449, `VerifiedBuild`=42979 WHERE `ID`=25240; -- 25240

DELETE FROM `page_text` WHERE `ID` IN (8395,8439,8437,8441,8440,8438,8382,8393,8153,8188);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(8395, '|L295-Existence is |l|L290-contextual.|l|L295- The |l|L294-light |l|L295-cannot be defined without the |l|L290-dark|l|L295-, to have |l|L294-one requires|l|L295- the other. Language is also |l|L290-contextual|l|L295-, there is only meaning with reasoning. The |l|L294-deeper|l|L295- the reasoning, the ever |l|L290-changing|l|L295- the meaning. Their thoughts encompass everything and |l|L290-nothing|l|L295- all at once. They are what|l|L294- we cannot|l|L295- comprehend.|l', 0, 0, 0, 42560), -- 8395
(8439, 'What he began in the Sepulcher was meant to cascade outward from one Zereth to the next, until all were dominated by his power. The heart of the Shadowlands acting as a doorway to the heart of each cosmic force in turn, one after another bound to his will.\n\nBut if his scheme was thwarted, then why is my mind so ill at ease?', 8440, 0, 0, 42698), -- 8439
(8437, 'Though the Jailer has been defeated and the Shadowlands made whole again, I find myself unable to celebrate these victories.\n\nFor I have studied the inner workings of the Sepulcher. Seen the powers with which the Jailer sought to remake reality. And these observations fill me with a fear that shakes the very core of my being.', 8438, 0, 0, 42698), -- 8437
(8441, 'I pray that the First Ones anticipated such an eventuality. That they would leave measures in place to preserve their grand design.\n\nUnless... \n\nUnless their design was never meant to endure.\n\nAnd that... that is the possibility that haunts me.', 0, 0, 0, 42698), -- 8441
(8440, 'Because I have seen how fragile the pattern is. How delicate the scales that keep the six forces in balance.\n\nAnd if the Jailer, in his act of malevolence, left behind but the most imperceptible of cracks in that pattern, then I fear what is tiny now will only grow, until the balance itself is prone to be shattered by another force applying relentless pressure.', 8441, 0, 0, 42698), -- 8440
(8438, 'It is clear to me now that there must be a Zereth for each force of the cosmos, and within them, an inner sanctum akin to the Sepulcher.\n\nAnd if that is true, then these sanctums must be connected on some fundamental level; a connection that the Jailer sought to exploit.', 8439, 0, 0, 42698), -- 8438
(8382, '|L290-There is |l|L294-purpose to each of|l|L290- us.|l|L294- Built with intention|l|L290- we each perform |l|L294- our task to |l|L290- perfection.|l|L294- Building. Tending. |l|L290- Guiding. |l|L294- Maintaining. We fulfill their wishes perfectly balanced. Their design|l|L290- not to be questioned.|l', 0, 0, 0, 43206), -- 8382
(8393, '|L290-When does an idea truly become its own individual? Every one of us is carefully created, structured, and meant to serve a purpose. Each line painstakingly drawn and put together to create a strong latticework, but still whole on its own. When is the line distinct from the design?|l', 0, 0, 0, 43206), -- 8393
(8153, 'Ta Cartel Stock Requirements\n\n1. A talking frog. Most won\'t admit they are able to communicate unless they have a good reason. Try doing things that might trick them to speak up or laugh.\n\n2. Some regenerative magma. Try looking somewhere really hot for something really ancient.\n\n3. An original \"Glenzu\" artwork created with Luminous Pigment. You will need to provide enough pigment, perhaps ten or so, for the artist to do his best work.', 0, 0, 0, 43206), -- 8153
(8188, 'Here lies the remains of Emeni, the Kinslayer.\n\nBorn into an era of peace she did not belong to.\n\nNo kin was safe while she thirsted for power.\n\nNo rival was safe while she thirsted for victory.\n\nNo bystander was safe while she thirsted for violence.\n\nNo sethrak was safe while she drew breath.\n\nBut rest easy now, young ones, for the fabled kinslayer of Slithering Gulch is long dead.\n\nLet all who gaze on her remains take solace in their silence.', 0, 0, 0, 43345); -- 8188

DELETE FROM `quest_template` WHERE `ID` IN (65413,65417,65412,53359,65138,53291);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(65413, 3, 0, 2057, 13536, 109, 0, 0, 0, 1, 0, 1, 0, 365237, 0, 0, 0, 0, 1, 0, 6881344, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 2006, 8, 0, 0, 'Puzzling It Out', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42698), -- -Unknown-
(65417, 3, 0, 2057, 13536, 109, 0, 0, 0, 1, 0, 1, 0, 365237, 0, 0, 0, 0, 1, 0, 6881344, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 2006, 8, 0, 0, 'Connecting It All', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 43114), -- -Unknown-
(65412, 3, 0, 2057, 13536, 109, 0, 0, 0, 1, 0, 1, 0, 365237, 0, 0, 0, 0, 1, 0, 6881344, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 2006, 8, 0, 0, 'Puzzling It Out', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 43340), -- -Unknown-
(53359, 0, 0, 290, -432, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 32768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 15000, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 0, 0, 'Arathi Donations: Steelskin Potion', '', '', '', '', 1553, 0, 0, 0, 500, 0, 0, 0, '', '', '', '', 0, 0, 43340), -- -Unknown-
(65138, 0, 0, 2060, 10413, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 'Friend of a Friend: Plague Deviser Marileth', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 44325), -- -Unknown-
(53291, 3, 0, 464, 8500, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 590144, 0, 2, 2549, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2159, 2156, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7500, 7500, 0, 0, 0, 0, 0, 0, 18446744073709551615, 827, 7, 0, 0, 'Blooming Star Moss', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 44325); -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (422891,422899,422889,341289,341058);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(422891, 65413, 0, 0, 7, 184489, 1, 0, 0, 0, 'Glissandian Cache unlocked', 42698), -- 422891
(422899, 65417, 0, 0, 7, 184489, 1, 0, 0, 0, 'Cantaric Cache unlocked', 43114), -- 422899
(422889, 65412, 0, 0, 7, 184489, 1, 0, 0, 0, 'Glissandian Cache unlocked', 43340), -- 422889
(341289, 53359, 1, 0, 0, 152557, 2, 0, 0, 0, '', 43340), -- 341289
(341058, 53291, 0, 0, 0, 143403, 1, 0, 0, 0, 'Blooming Star Moss Gathered', 44325); -- 341058

DELETE FROM `quest_visual_effect` WHERE `ID`=341058;
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(341058, 0, 10259, 44325);

DELETE FROM `quest_reward_display_spell` WHERE `QuestID`=65138;
INSERT INTO `quest_reward_display_spell` (`QuestID`, `Idx`, `SpellID`, `PlayerConditionID`, `VerifiedBuild`) VALUES
(65138, 0, 361711, 0, 44325);

UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=42560 WHERE `ID`=44119; -- DANGER: Volshax, Breaker of Will
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=42560 WHERE `ID`=42963; -- DANGER: Rulf Bonesnapper
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=42698 WHERE `ID`=53308; -- Luminous Monelite
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=42698 WHERE `ID`=51580; -- Rear Admiral Hainsworth
UPDATE `quest_template` SET `FlagsEx`=0, `VerifiedBuild`=42698 WHERE `ID`=42239; -- Halls of Valor: The Bear King
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=42852 WHERE `ID`=54332; -- Darkshore Donations: Star Moss
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=43114 WHERE `ID`=363; -- Rude Awakening
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43114 WHERE `ID`=43027; -- DANGER: Mortiferous
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43114 WHERE `ID`=42927; -- DANGER: Malisandra
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=43206 WHERE `ID`=1536; -- Call of Water
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43206 WHERE `ID`=44303; -- WANTED: Dreadbog
UPDATE `quest_template` SET `Flags`=6881344, `VerifiedBuild`=43206 WHERE `ID`=65405; -- Perplexing Problem
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=43340 WHERE `ID`=53362; -- Arathi Donations: Meaty Haunch
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=43340 WHERE `ID`=52792; -- Arathi Donations: Akunda's Bite
UPDATE `quest_template` SET `Flags`=6881344, `VerifiedBuild`=43340 WHERE `ID`=65407; -- Pattern Recognition
UPDATE `quest_template` SET `ContentTuningID`=347, `RewardFactionValue1`=6, `RewardFactionValue2`=6, `VerifiedBuild`=43340 WHERE `ID`=43802; -- Watery Graves
UPDATE `quest_template` SET `ContentTuningID`=290, `LogTitle`='Arathi Donations: Straddling Viridium', `VerifiedBuild`=43340 WHERE `ID`=53258; -- Wartime Donations: Straddling Viridium
UPDATE `quest_template` SET `ContentTuningID`=706, `VerifiedBuild`=43340 WHERE `ID`=54403; -- Tidesage Clarissa
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43340 WHERE `ID`=42820; -- DANGER: Aegir Wavecrusher
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=43340 WHERE `ID`=53292; -- Blooming Siren's Sting
UPDATE `quest_template` SET `Flags`=6881344, `VerifiedBuild`=43340 WHERE `ID`=65410; -- Puzzling Situation
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=43340 WHERE `ID`=8; -- A Rogue's Deal
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=43340 WHERE `ID`=53257; -- Arathi Donations: Versatile Kyanite
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=43340 WHERE `ID`=36; -- Westfall Stew
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43340 WHERE `ID`=41342; -- Thick Bear Hide
UPDATE `quest_template` SET `RewardBonusMoney`=0, `Expansion`=-2, `VerifiedBuild`=43340 WHERE `ID`=26; -- A Lesson to Learn
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43345 WHERE `ID`=41292; -- Work Order: Dreamleaf
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43345 WHERE `ID`=41266; -- Raft Fishing
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43345 WHERE `ID`=44017; -- WANTED: Apothecary Faldren
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=43345 WHERE `ID`=54334; -- Darkshore Donations: Electroshock Mount Motivator
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43345 WHERE `ID`=41291; -- Dreamleaf Cluster
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43345 WHERE `ID`=41439; -- Exquisite Leystone Deposits
UPDATE `quest_template` SET `FlagsEx`=0, `VerifiedBuild`=43345 WHERE `ID`=42714; -- Darkheart Thicket: Mythana
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=43971 WHERE `ID`=53289; -- Flourishing Sea Stalks
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=43971 WHERE `ID`=27; -- A Lesson to Learn
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43971 WHERE `ID`=46844; -- Cathedral of Eternal Night: Mistress of Blades
UPDATE `quest_template` SET `FlagsEx`=0, `VerifiedBuild`=43971 WHERE `ID`=42806; -- DANGER: Fjorlag, the Grave's Chill
UPDATE `quest_template` SET `Flags`=6881344, `VerifiedBuild`=43971 WHERE `ID`=65406; -- Connecting It All
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43971 WHERE `ID`=44290; -- WANTED: Bristlemaul
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=43971 WHERE `ID`=41091; -- Lords of the Hills
UPDATE `quest_template` SET `ContentTuningID`=290, `LogTitle`='Arathi Donations: Frost-Laced Ammunition', `VerifiedBuild`=44015 WHERE `ID`=53261; -- Wartime Donations: Frost-Laced Ammunition
UPDATE `quest_template` SET `ContentTuningID`=691, `VerifiedBuild`=44015 WHERE `ID`=54824; -- Shattershard
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=44061 WHERE `ID`=44050; -- The Felsworn Must Fall
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=44232 WHERE `ID`=42242; -- Halls of Valor: A Gift for Vethir
UPDATE `quest_template` SET `FlagsEx`=0, `VerifiedBuild`=44232 WHERE `ID`=41498; -- Leystone Basilisks
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=44232 WHERE `ID`=54337; -- Darkshore Donations: Umbra Shard
UPDATE `quest_template` SET `FlagsEx`=0, `VerifiedBuild`=44232 WHERE `ID`=42864; -- DANGER: Captain Dargun
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=44232 WHERE `ID`=53285; -- Blooming Star Moss
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=44232 WHERE `ID`=54356; -- Darkshore Donations: Quick Golden Beryl
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=44232 WHERE `ID`=53324; -- Rough Monelite
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=44325 WHERE `ID`=53247; -- Arathi Donations: Battle Flag: Spirit of Freedom
UPDATE `quest_template` SET `FlagsEx`=32768, `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=44325 WHERE `ID`=54340; -- Darkshore Donations: Enchant Ring - Seal of Haste
UPDATE `quest_template` SET `RewardBonusMoney`=12600 WHERE `ID`=60840;
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=44325 WHERE `ID`=41500; -- Leyworms
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=44325 WHERE `ID`=51977; -- Sabertron
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=44325 WHERE `ID`=43619; -- WANTED: Shara Felbreath
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=44325 WHERE `ID`=54351; -- Darkshore Donations: Deep Sea Bandage
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=44325 WHERE `ID`=54353; -- Darkshore Donations: Blood-Stained Bone
UPDATE `quest_template` SET `ContentTuningID`=347, `AllowableRaces`=18446744073709551615, `VerifiedBuild`=44325 WHERE `ID`=41304; -- Flourishing Starlight Roses
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=44325 WHERE `ID`=53304; -- Blooming Siren's Sting

UPDATE `quest_objectives` SET `Description`='Received orders from Paratrooper Jacobs', `VerifiedBuild`=42698 WHERE `ID`=336356; -- 336356
UPDATE `quest_objectives` SET `Amount`=2, `VerifiedBuild`=44015 WHERE `ID`=341012; -- 341012
