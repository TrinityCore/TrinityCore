-- Creature templates
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry` IN (32600, 32597); -- Dalaran Visitor
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry` IN (32596, 32598, 32601); -- Dalaran Visitor
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry` IN (29668, 29673); -- Arathi Basin Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry` IN (29669, 29674); -- Alterac Valley Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry` IN (29670, 29675); -- Eye of the Storm Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry` IN (34952, 34953); -- Isle of Conquest Portal
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=32724; -- Warmage Mumplina
UPDATE `creature_template` SET `unit_flags3`=8388608 WHERE `entry`=32722; -- Warmage Lukems
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=27870; -- Wild Flower
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry` IN (29672, 29667); -- Warsong Gulch Portal
UPDATE `creature_template` SET `npcflag`=281474976710659 WHERE `entry`=49750; -- Warchief's Herald
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=37859; -- Ignis the Furnace Master Image
UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=31236; -- Dappled Stag
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31796; -- Cosmetic Worg Pup
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31742; -- Cosmetic Prairie Dog
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31795; -- Cosmetic Smolderweb Hatchling
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31740; -- Cosmetic Turtle
UPDATE `creature_template` SET `unit_flags3`=67108864 WHERE `entry`=31233; -- Sinewy Wolf
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31741; -- Cosmetic Rabbit
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29766; -- Cosmetic Totem Alliance Water
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31735; -- Cosmetic Pig
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29764; -- Cosmetic Totem Alliance Earth
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31732; -- Cosmetic Rat
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29765; -- Cosmetic Totem Alliance Fire
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31733; -- Cosmetic Cockroach
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31730; -- Cosmetic Frog
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29763; -- Cosmetic Totem Alliance Air
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31719; -- Cosmetic Frenzy
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31728; -- Cosmetic Cat Set 1/2
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31729; -- Cosmetic Cat Set 2/2
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=18927; -- Human Commoner
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31714; -- Cosmetic Ribbon Snake
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=20102; -- Goblin Commoner
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31710; -- Cosmetic Black Kingsnake
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31711; -- Cosmetic Brown Snake
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29782; -- Cosmetic Mechanical Sheep
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=31709; -- Cosmetic Albino Snake
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29780; -- Cosmetic Mechanical Chicken
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=29812; -- [DND] Dalaran Toy Store Plane String Bunny
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29781; -- Cosmetic Mechanical Squirrel
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=28160; -- Archmage Pentarus
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29777; -- Cosmetic Mechanical Gorilla
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29784; -- Cosmetic Clockwork Robot (Blue)
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29785; -- Cosmetic Clockwork Robot (Red)
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=29807; -- [DND] Dalaran Toy Store Plane String Hook
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=29783; -- Cosmetic Clockwork Robot
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32441; -- Underbelly Croc
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=31229; -- Ancient Watcher
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=31400; -- Azure Front Channel Stalker
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=30352; -- Skybreaker Marine
UPDATE `creature_template` SET `unit_flags3`=335544320 WHERE `entry`=32435; -- Vern
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=33778; -- Tournament Hippogryph
UPDATE `creature_template` SET `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=30755; -- Kor'kron Reaver

UPDATE `creature_template_addon` SET `visibilityDistanceType`=0 WHERE `entry`=16128; -- 16128 (Rhonin)
UPDATE `creature_template_addon` SET `visibilityDistanceType`=0 WHERE `entry`=28332; -- 28332 (Generic Trigger LAB (Large AOI))

-- Difficulties
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (31402,32748,19481,61081,96773,96772,32652,32606,73516,73517,34252,35498,28990,28997,31581,31582,37941,35495,33963,35607,29535,50152,50153,50150,29538,50144,29537,36776,50142,50148,50147,31756,23033,35826,31085,31081,31080,174271,50171,50163,29523,29494,28994,28992,35500,50174,32265,35497,50158,50156,50157,29497,50160,31580,47581,29496,28991,31579,35494,35594,37942,33964,32747,29528,28958,32749,30094,51512,29703,29491,32744,32745,32322,32743,29548,29527,32425,47579,28995,34330,32466,30885,28956,36774,31768,29715,32337,20102,29499,29529,28993,31758,32516,69973,32428,32339,32746,29702,31757,32336,69971,29495,28160,31755,23472,25058,29802,32328,30095,29547,69321,69318,15732,32342,32470,15730,40212,35496));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29778 AND `DifficultyID`=0); -- Scout Nisstina
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (32600,32596,32598,32597,32601)); -- Dalaran Visitor
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32709 AND `DifficultyID`=0); -- Hunaka Greenhoof
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32697 AND `DifficultyID`=0); -- Dak'hal the Black
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (29668,29673)); -- Arathi Basin Portal
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (29669,29674)); -- Alterac Valley Portal
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (29670,29675)); -- Eye of the Storm Portal
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (34952,34953)); -- Isle of Conquest Portal
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32631 AND `DifficultyID`=0); -- Alfred Copperworth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32737 AND `DifficultyID`=0); -- Archmage John Nicholas
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32741 AND `DifficultyID`=0); -- Conjurer Weinhaus
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32734 AND `DifficultyID`=0); -- Arcanist Ginsberg
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32735 AND `DifficultyID`=0); -- Alchemist Burroughs
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32738 AND `DifficultyID`=0); -- Kat Sunflower
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32724 AND `DifficultyID`=0); -- Warmage Mumplina
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32722 AND `DifficultyID`=0); -- Warmage Lukems
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32287 AND `DifficultyID`=0); -- Archmage Alvareaux
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32843 AND `DifficultyID`=0); -- Tabea
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32844 AND `DifficultyID`=0); -- Apollo
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=16128 AND `DifficultyID`=0); -- Rhonin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30117 AND `DifficultyID`=0); -- Archmage Modera
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30115 AND `DifficultyID`=0); -- Vereesa Windrunner
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=52649 WHERE (`Entry`=30116 AND `DifficultyID`=0); -- Archmage Aethas Sunreaver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32733 AND `DifficultyID`=0); -- Joboba Mezbreaker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32728 AND `DifficultyID`=0); -- Illusionist Karina
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28699 AND `DifficultyID`=0); -- Charles Worth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28726 AND `DifficultyID`=0); -- Dominique Stefano
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29510 AND `DifficultyID`=0); -- Linna Bruder
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29508 AND `DifficultyID`=0); -- Andellion
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29509 AND `DifficultyID`=0); -- Namha Moonwater
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28700 AND `DifficultyID`=0); -- Diane Cannings
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28696 AND `DifficultyID`=0); -- Derik Marks
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29507 AND `DifficultyID`=0); -- Manfred Staller
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32651 AND `DifficultyID`=0); -- Wounded Dalaran Shield Guard
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29640 AND `DifficultyID`=0); -- Josie Birch
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28706 AND `DifficultyID`=0); -- Olisarra the Kind
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32653 AND `DifficultyID`=0); -- Wounded Dalaran Serpent
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32650 AND `DifficultyID`=0); -- Wounded Dalaran Protector
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29511 AND `DifficultyID`=0); -- Lalla Brightweave
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29628 AND `DifficultyID`=0); -- Angelique Butler
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29512 AND `DifficultyID`=0); -- Ainderu Summerleaf
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28718 AND `DifficultyID`=0); -- Ranid Glowergold
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32684 AND `DifficultyID`=0); -- Mona Everspring
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32677 AND `DifficultyID`=0); -- Whirt the All-Knowing
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32515 AND `DifficultyID`=0); -- Braeg Stoutbeard
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28721 AND `DifficultyID`=0); -- Tiffany Cartier
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32172 AND `DifficultyID`=0); -- Harold Winston
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28722 AND `DifficultyID`=0); -- Bryan Landers
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29514 AND `DifficultyID`=0); -- Findle Whistlesteam
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28697 AND `DifficultyID`=0); -- Timofey Oshenko
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29929 AND `DifficultyID`=0); -- Mechano-Hog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435712, `VerifiedBuild`=52649 WHERE (`Entry`=40160 AND `DifficultyID`=0); -- Frozo the Renowned
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29513 AND `DifficultyID`=0); -- Didi the Wrench
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28725 AND `DifficultyID`=0); -- Patricia Egan
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28698 AND `DifficultyID`=0); -- Jedidiah Handers
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28728 AND `DifficultyID`=0); -- Dorian Fines
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32706 AND `DifficultyID`=0); -- Saedelin Whitedawn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=52649 WHERE (`Entry`=93432 AND `DifficultyID`=0); -- Nethaera's Light
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28703 AND `DifficultyID`=0); -- Linzy Blackbolt
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=27870 AND `DifficultyID`=0); -- Wild Flower
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=26043 AND `DifficultyID`=0); -- Steam Burst
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29506 AND `DifficultyID`=0); -- Orland Schaeffer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28694 AND `DifficultyID`=0); -- Alard Schmied
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32451 AND `DifficultyID`=0); -- Dalaran Citizen
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28716 AND `DifficultyID`=0); -- Palja Amboss
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28675 AND `DifficultyID`=0); -- Teller Rames
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29282 AND `DifficultyID`=0); -- Paymaster Alstein
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28676 AND `DifficultyID`=0); -- Teller Althiellis
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28677 AND `DifficultyID`=0); -- Teller Hanners
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (29672,29667)); -- Warsong Gulch Portal
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29657 AND `DifficultyID`=0); -- High Arcanist Savor
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=50149 AND `DifficultyID`=0); -- Vinsun
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29665 AND `DifficultyID`=0); -- Pazik "The Pick" Prylock
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=37780 AND `DifficultyID`=0); -- Dark Ranger Vorel
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32249 AND `DifficultyID`=0); -- Worg Pup
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268697600, `VerifiedBuild`=52649 WHERE (`Entry`=32664 AND `DifficultyID`=0); -- Segacedi
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32170 AND `DifficultyID`=0); -- Magister Surdiel
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31886 AND `DifficultyID`=0); -- Nargut
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32252 AND `DifficultyID`=0); -- Wanathan
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31557 AND `DifficultyID`=0); -- Uda the Beast
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32251 AND `DifficultyID`=0); -- Shokavis
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=36670 AND `DifficultyID`=0); -- Magister Hathorel
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32420 AND `DifficultyID`=0); -- Mimbihi
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32415 AND `DifficultyID`=0); -- Hamaka
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31885 AND `DifficultyID`=0); -- Rhukah
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32253 AND `DifficultyID`=0); -- Kyunghee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32419 AND `DifficultyID`=0); -- Umbiwa
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32412 AND `DifficultyID`=0); -- Mato
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32418 AND `DifficultyID`=0); -- Abohba
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29631 AND `DifficultyID`=0); -- Awilo Lon'gomba
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31031 AND `DifficultyID`=0); -- Misensi
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32692 AND `DifficultyID`=0); -- Arcanist Alec
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32687 AND `DifficultyID`=0); -- Linda Ann Kastinglow
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31238 AND `DifficultyID`=0); -- Hira Snowdawn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28674 AND `DifficultyID`=0); -- Aludane Whitecloud
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32732 AND `DifficultyID`=0); -- Dorfus Alphamage
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32730 AND `DifficultyID`=0); -- Goldlilly Gleamingfell
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31439 AND `DifficultyID`=0); -- Archmage Timear
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29325 AND `DifficultyID`=0); -- Torgo the Younger
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29660 AND `DifficultyID`=0); -- Grand Marauder Sai
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32169 AND `DifficultyID`=0); -- Arcanist Braedin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32424 AND `DifficultyID`=0); -- Laire Brewgold
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30608 AND `DifficultyID`=0); -- Paymaster Amadi
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30606 AND `DifficultyID`=0); -- Paymaster Chang
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30607 AND `DifficultyID`=0); -- Teller Plushner
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30604 AND `DifficultyID`=0); -- Teller Almeida
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30605 AND `DifficultyID`=0); -- Teller Gee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32426 AND `DifficultyID`=0); -- Coira Longrifle
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28686 AND `DifficultyID`=0); -- Caliel Brightwillow
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=20735 AND `DifficultyID`=0); -- Archmage Lan'dalock
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28692 AND `DifficultyID`=0); -- "Red" Jack Findle
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=37776 AND `DifficultyID`=0); -- Apprentice Nelphi
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=196, `StaticFlags1`=536870912, `VerifiedBuild`=52649 WHERE (`Entry`=37859 AND `DifficultyID`=0); -- Ignis the Furnace Master Image
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32715 AND `DifficultyID`=0); -- Sorrow
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28691 AND `DifficultyID`=0); -- Susana Averoy
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=50155 AND `DifficultyID`=0); -- Naseev
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=31517 AND `DifficultyID`=0); -- Dalaran Fountain Invis Stalker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28705 AND `DifficultyID`=0); -- Katherine Lee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31032 AND `DifficultyID`=0); -- Derek Odds
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32416 AND `DifficultyID`=0); -- Stefen Cotter
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28682 AND `DifficultyID`=0); -- Inzi Charmlight
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30490 AND `DifficultyID`=0); -- Rin Duoctane
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29530 AND `DifficultyID`=0); -- Binzik Goldbook
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32450 AND `DifficultyID`=0); -- Badluck
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=35790 AND `DifficultyID`=0); -- Usuri Brightcoin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28715 AND `DifficultyID`=0); -- Endora Moorehead
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28742 AND `DifficultyID`=0); -- Marcia Chase
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32514 AND `DifficultyID`=0); -- Vanessa Sellers
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29636 AND `DifficultyID`=0); -- Hagatha Moorehead
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32421 AND `DifficultyID`=0); -- Marcella Bloom
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=36669 AND `DifficultyID`=0); -- Arcanist Tybalin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32413 AND `DifficultyID`=0); -- Isirami Fairwind
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=15760 AND `DifficultyID`=0); -- Winter Reveler
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29505 AND `DifficultyID`=0); -- Imindril Spearsong
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31236 AND `DifficultyID`=0); -- Dappled Stag
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32702 AND `DifficultyID`=0); -- Drog Skullbreaker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28776 AND `DifficultyID`=0); -- Elizabeth Ross
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31796 AND `DifficultyID`=0); -- Cosmetic Worg Pup
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28774 AND `DifficultyID`=0); -- Andrew Matthews
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29532 AND `DifficultyID`=0); -- Ajay Green
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32693 AND `DifficultyID`=0); -- Sabriana Sorrowgaze
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31742 AND `DifficultyID`=0); -- Cosmetic Prairie Dog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31795 AND `DifficultyID`=0); -- Cosmetic Smolderweb Hatchling
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=33031 AND `DifficultyID`=0); -- Sebastian Bower
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32690 AND `DifficultyID`=0); -- Bitty Frostflinger
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28708 AND `DifficultyID`=0); -- Kizi Copperclip
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32691 AND `DifficultyID`=0); -- Magus Fansy Goodbringer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32679 AND `DifficultyID`=0); -- Darthalia Ebonscorch
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31740 AND `DifficultyID`=0); -- Cosmetic Turtle
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31233 AND `DifficultyID`=0); -- Sinewy Wolf
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29478 AND `DifficultyID`=0); -- Jepetto Joybuzz
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31741 AND `DifficultyID`=0); -- Cosmetic Rabbit
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32689 AND `DifficultyID`=0); -- Adorean Lew
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29476 AND `DifficultyID`=0); -- Dagna Flintlock
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31852 AND `DifficultyID`=0); -- Wooly Mammoth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=33027 AND `DifficultyID`=0); -- Jessica Sellers
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32686 AND `DifficultyID`=0); -- Tomas Riogain
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=52649 WHERE (`Entry`=36851 AND `DifficultyID`=0); -- Aquanos
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28704 AND `DifficultyID`=0); -- Dorothy Egan
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29716 AND `DifficultyID`=0); -- Clockwork Assistant
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28723 AND `DifficultyID`=0); -- Larana Drome
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29766 AND `DifficultyID`=0); -- Cosmetic Totem Alliance Water
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28702 AND `DifficultyID`=0); -- Professor Pallin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28690 AND `DifficultyID`=0); -- Tassia Whisperglen
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32685 AND `DifficultyID`=0); -- Kitz Proudbreeze
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32216 AND `DifficultyID`=0); -- Mei Francis
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31735 AND `DifficultyID`=0); -- Cosmetic Pig
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29764 AND `DifficultyID`=0); -- Cosmetic Totem Alliance Earth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32683 AND `DifficultyID`=0); -- Grezla the Hag
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31732 AND `DifficultyID`=0); -- Cosmetic Rat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29765 AND `DifficultyID`=0); -- Cosmetic Totem Alliance Fire
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=36856 AND `DifficultyID`=0); -- Shandy Glossgleam
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32680 AND `DifficultyID`=0); -- Fabioso the Fabulous
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31733 AND `DifficultyID`=0); -- Cosmetic Cockroach
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32681 AND `DifficultyID`=0); -- The Magnificent Merleaux
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31730 AND `DifficultyID`=0); -- Cosmetic Frog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29763 AND `DifficultyID`=0); -- Cosmetic Totem Alliance Air
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32678 AND `DifficultyID`=0); -- Emeline Fizzlefry
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=31719 AND `DifficultyID`=0); -- Cosmetic Frenzy
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28951 AND `DifficultyID`=0); -- Breanni
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31728 AND `DifficultyID`=0); -- Cosmetic Cat Set 1/2
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=52649 WHERE (`Entry`=31769 AND `DifficultyID`=0); -- Stabled Hunter Pet
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32676 AND `DifficultyID`=0); -- Grindle Firespark
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31729 AND `DifficultyID`=0); -- Cosmetic Cat Set 2/2
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32726 AND `DifficultyID`=0); -- The Chooch
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32727 AND `DifficultyID`=0); -- Natalie Tootiblare
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32675 AND `DifficultyID`=0); -- Babagahnoosh the Grumpy
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29261 AND `DifficultyID`=0); -- Windle Sparkshine
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32668 AND `DifficultyID`=0); -- Emi
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32669 AND `DifficultyID`=0); -- Colin
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28687 AND `DifficultyID`=0); -- Amisi Azuregaze
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31136 AND `DifficultyID`=0); -- High Warlord Uro
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32731 AND `DifficultyID`=0); -- Metopious Loreseeker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28685 AND `DifficultyID`=0); -- Narisa Redgold
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32729 AND `DifficultyID`=0); -- Lofwyr Le'Fleur
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31714 AND `DifficultyID`=0); -- Cosmetic Ribbon Snake
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28701 AND `DifficultyID`=0); -- Timothy Jones
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32411 AND `DifficultyID`=0); -- Afsaneh Asrar
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30137 AND `DifficultyID`=0); -- Shifty Vickers
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32207 AND `DifficultyID`=0); -- Armored Brown Bear
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29641 AND `DifficultyID`=0); -- Theresa Wolf
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31710 AND `DifficultyID`=0); -- Cosmetic Black Kingsnake
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31711 AND `DifficultyID`=0); -- Cosmetic Brown Snake
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=52649 WHERE (`Entry`=34244 AND `DifficultyID`=0); -- Jean Pierre Poulain
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29782 AND `DifficultyID`=0); -- Cosmetic Mechanical Sheep
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=31709 AND `DifficultyID`=0); -- Cosmetic Albino Snake
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29780 AND `DifficultyID`=0); -- Cosmetic Mechanical Chicken
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28727 AND `DifficultyID`=0); -- Edward Egan
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=52649 WHERE (`Entry`=34984 AND `DifficultyID`=0); -- World Trigger (Not Floating)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=29812 AND `DifficultyID`=0); -- [DND] Dalaran Toy Store Plane String Bunny
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29781 AND `DifficultyID`=0); -- Cosmetic Mechanical Squirrel
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28693 AND `DifficultyID`=0); -- Enchanter Nalthanis
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32403 AND `DifficultyID`=0); -- Sandra Bartan
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=33422 AND `DifficultyID`=0); -- Unbound Seer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32334 AND `DifficultyID`=0); -- Nixi Fireclaw
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29777 AND `DifficultyID`=0); -- Cosmetic Mechanical Gorilla
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29493 AND `DifficultyID`=0); -- Jarold Puller
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29784 AND `DifficultyID`=0); -- Cosmetic Clockwork Robot (Blue)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29785 AND `DifficultyID`=0); -- Cosmetic Clockwork Robot (Red)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29049 AND `DifficultyID`=0); -- Arille Azuregaze
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=29807 AND `DifficultyID`=0); -- [DND] Dalaran Toy Store Plane String Hook
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28714 AND `DifficultyID`=0); -- Ildine Sorrowspear
UPDATE `creature_template_difficulty` SET `StaticFlags1`=256, `VerifiedBuild`=52649 WHERE (`Entry`=29783 AND `DifficultyID`=0); -- Cosmetic Clockwork Robot
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31228 AND `DifficultyID`=0); -- Grove Walker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30104 AND `DifficultyID`=0); -- Adamman the Trader
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=33026 AND `DifficultyID`=0); -- Sarah Brady
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268959744, `VerifiedBuild`=52649 WHERE (`Entry`=32441 AND `DifficultyID`=0); -- Underbelly Croc
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=31229 AND `DifficultyID`=0); -- Ancient Watcher
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=31400 AND `DifficultyID`=0); -- Azure Front Channel Stalker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32688 AND `DifficultyID`=0); -- Archmage Tenaj
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30352 AND `DifficultyID`=0); -- Skybreaker Marine
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=52649 WHERE (`Entry`=27047 AND `DifficultyID`=0); -- Invisible Stalker (Floating Only)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=52649 WHERE (`Entry`=31689 AND `DifficultyID`=0); -- Gnome Diver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30726 AND `DifficultyID`=0); -- Archivist Betha
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=52649 WHERE (`Entry`=31643 AND `DifficultyID`=0); -- Dalaran Well Teleport Bunny
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28707 AND `DifficultyID`=0); -- Angelo Pescatore
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=32435 AND `DifficultyID`=0); -- Vern
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=33778 AND `DifficultyID`=0); -- Tournament Hippogryph
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=28989 AND `DifficultyID`=0); -- Aemara
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=52649 WHERE (`Entry`=25171 AND `DifficultyID`=0); -- Invisible Stalker (Scale x0.5)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=30755 AND `DifficultyID`=0); -- Kor'kron Reaver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29254 AND `DifficultyID`=0); -- Silver Covenant Guardian Mage
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29714 AND `DifficultyID`=0); -- Lucian Trias
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=52649 WHERE (`Entry`=28332 AND `DifficultyID`=0); -- Generic Trigger LAB (Large AOI)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29156 AND `DifficultyID`=0); -- Archmage Celindra
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=52649 WHERE (`Entry`=29255 AND `DifficultyID`=0); -- Sunreaver Guardian Mage

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`!=0 AND `Entry` IN (29778,32600,32596,32598,32597,32601,32709,32697,29668,29673,29669,29674,29670,29675,34952,34953,32631,32737,32741,32734,32735,32738,32724,32722,32287,32843,32844,16128,30117,30115,30116,32733,32728,28699,28726,29510,29508,29509,28700,28696,29507,32651,29640,28706,32653,32650,29511,29628,29512,28718,32684,32677,32515,28721,32172,28722,29514,28697,29929,40160,29513,28725,28698,28728,32706,93432,28703,27870,26043,29506,28694,32451,28716,28675,29282,28676,28677,29672,29667,29657,50149,29665,37780,32249,32664,32170,31886,32252,31557,32251,36670,32420,32415,31885,32253,32419,32412,32418,29631,31031,32692,32687,31238,28674,32732,32730,31439,29325,29660,32169,32424,30608,30606,30607,30604,30605,32426,28686,20735,28692,37776,37859,32715,28691,50155,31517,28705,31032,32416,28682,30490,29530,32450,35790,28715,28742,32514,29636,32421,36669,32413,15760,29505,31236,32702,28776,31796,28774,29532,32693,31742,31795,33031,32690,28708,32691,32679,31740,31233,29478,31741,32689,29476,31852,33027,32686,36851,28704,29716,28723,29766,28702,28690,32685,32216,31735,29764,32683,31732,29765,36856,32680,31733,32681,31730,29763,32678,31719,28951,31728,31769,32676,31729,32726,32727,32675,29261,32668,32669,28687,31136,32731,28685,32729,31714,28701,32411,30137,32207,29641,31710,31711,34244,29782,31709,29780,28727,34984,29812,29781,28693,32403,33422,32334,29777,29493,29784,29785,29049,29807,28714,29783,31228,30104,33026,32441,31229,31400,32688,30352,27047,31689,30726,31643,28707,32435,33778,28989,25171,30755,29254,29714,28332,29156,29255,31402,32748,19481,61081,96773,96772,32652,32606,73516,73517,34252,35498,28990,28997,31581,31582,37941,35495,33963,35607,29535,50152,50153,50150,29538,50144,29537,36776,50142,50148,50147,31756,23033,35826,31085,31081,31080,174271,50171,50163,29523,29494,28994,28992,35500,50174,32265,35497,50158,50156,50157,29497,50160,31580,47581,29496,28991,31579,35494,35594,37942,33964,32747,29528,28958,32749,30094,51512,29703,29491,32744,32745,32322,32743,29548,29527,32425,47579,28995,34330,32466,30885,28956,36774,31768,29715,32337,20102,29499,29529,28993,31758,32516,69973,32428,32339,32746,29702,31757,32336,69971,29495,28160,31755,23472,25058,29802,32328,30095,29547,69321,69318,15732,32342,32470,15730,40212,35496));

DELETE FROM `creature_questitem` WHERE `CreatureEntry`=36776 AND `DifficultyID`=1;

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=52649 WHERE `DisplayID` IN (25195, 26525, 17476, 28183, 28181, 26495, 26484, 26499, 29743, 28205, 28119, 28174, 28177, 28173, 28172, 19284, 28178, 27944, 27949, 27886, 28317, 52602, 16024, 26771, 28222, 26770, 28171, 28166, 23337, 24916, 25615, 25649, 26377, 26336, 26335, 25616, 25612, 26337, 28124, 26398, 25622, 28125, 5966, 28123, 26378, 26376, 28152, 28145, 28000, 25645, 27799, 25646, 26374, 25613, 25871, 46947, 51414, 31713, 25648, 25614, 25651, 28189, 61133, 25619, 24897, 24898, 24895, 24890, 23501, 26338, 25611, 29145, 29833, 25876, 25637, 25881, 25596, 26103, 25597, 25598, 26503, 26494, 27560, 27557, 30841, 26072, 26413, 29831, 28986, 26445, 26496, 36907, 36906, 36904, 36898, 26444, 26417, 30686, 36900, 26443, 30439, 9563, 12200, 36899, 27801, 26501, 29744, 36905, 36903, 26074, 18793, 18785, 837, 26073, 18805, 18804, 22003, 27853, 27616, 27852, 28680, 27961, 27957, 27019, 27854, 27960, 21270, 27955, 27959, 26394, 27448, 30042, 28162, 28155, 27585, 27524, 27587, 25595, 21272, 28170, 28168, 27215, 27592, 26138, 27217, 26502, 26414, 27800, 27963, 27161, 27159, 27160, 27157, 27158, 27965, 27465, 25604, 27216, 36893, 19744, 36756, 26321, 25609, 26309, 25878, 30764, 29834, 36894, 30807, 17200, 29835, 28191, 25608, 36882, 36879, 36881, 36883, 26312, 25621, 27449, 36880, 27958, 25602, 27556, 27068, 26372, 35705, 29921, 25636, 26311, 25655, 27999, 26397, 25877, 27962, 28755, 27559, 27956, 29832, 30842, 28987, 26339, 28204, 10957, 23167, 28201, 25674, 27719, 25673, 19339, 26373, 28163, 24607, 28160, 28161, 28147, 27883, 24235, 18800, 26396, 28159, 27244, 25807, 28433, 28154, 30415, 25620, 26442, 25647, 28207, 26521, 26759, 25618, 25607, 28153, 27822, 37403, 27680, 26437, 26518, 25879, 28150, 28199, 26519, 30358, 28148, 3233, 28202, 28149, 26517, 28146, 17170, 27918, 28194, 25791, 11709, 26330, 26997, 28144, 5555, 28164, 28165, 28143, 26395, 26078, 28208, 35704, 25594, 27972, 25605, 27398, 27509, 26070, 25806, 30310, 28169, 20833, 18801, 25603, 26441, 28167, 26440, 2954, 26075, 27954, 19342, 26779, 27821, 27782, 1206, 2957, 29132, 26526, 26313, 2955, 802, 27334, 7920, 25650, 28006, 26465, 26532, 25610, 27952, 28618, 28203, 26438, 2710, 27914, 26464, 26310, 25166, 27912, 26524, 26307, 26530, 26531, 25882, 26570, 25635, 26547, 26998, 16925, 26557, 27766, 1988, 26766, 28432, 833, 27211, 47456, 47453, 8811, 17612, 28156, 27331, 27657, 27287, 13349, 20763, 27930, 22471, 25875, 17188, 27329, 29076, 26068, 27915, 25947, 29836, 26071);
UPDATE `creature_model_info` SET `BoundingRadius`=0.425056040287017822, `CombatReach`=0.300000011920928955, `VerifiedBuild`=52649 WHERE `DisplayID`=27718;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.25, `VerifiedBuild`=52649 WHERE `DisplayID`=16259;

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=52649 WHERE `entry` IN (194019, 191665, 191959, 193174, 192197, 193578, 191997, 191684, 192872, 201936, 192843, 193786, 192070, 194939, 278457, 191939, 191915, 191928, 192097, 191733, 192095, 191901, 191903, 200297, 191440, 193785, 192207, 191918, 191912, 193932, 193627, 192083, 191462, 191466, 191889, 191894, 191475, 191029, 193929, 192099, 192109, 192856, 192498, 192697, 193089, 191768, 192113, 194942, 193902, 192219, 192216, 192893, 191676, 191929, 191988, 191895, 191941, 192093, 178435, 180797, 195427, 193787, 193180, 194940, 191940, 193071, 192221, 191951, 192089, 191913, 191934, 193918, 192823, 191677, 194018, 192854, 208317, 192117, 194943, 193898, 192214, 193173, 191916, 192088, 191910, 193924, 193624, 192090, 191946, 191980, 191899, 191468, 191482, 201301, 192839, 191230, 178429, 191009, 193935, 194147, 191935, 191998, 193930, 193928, 193951, 178434, 193949, 191680, 193019, 192069, 192628, 193178, 193177, 191948, 192205, 191909, 193912, 191897, 191904, 191479, 180798, 191943, 201935, 200296, 192211, 192200, 191735, 191919, 191931, 193085, 191983, 191465, 191900, 191896, 191478, 180799, 201300, 192713, 192847, 192004, 191681, 191965, 192210, 192199, 193175, 191953, 180844, 191932, 193931, 191993, 191992, 191473, 191469, 192827, 192845, 178746, 191886, 193179, 193897, 192208, 193936, 208316, 193927, 192851, 193082, 193911, 191892, 192084, 192818, 192651, 192086, 201934, 192887, 192852, 195428, 192112, 192116, 192218, 192059, 192010, 191911, 191994, 191995, 193914, 191472, 191891, 192098, 192828, 192840, 266869, 191955, 192002, 192202, 214500, 193626, 192096, 191687, 193919, 191974, 191463, 191481, 193189, 187567, 194021, 193205, 192848, 193782, 195533, 191958, 194941, 192212, 190960, 193921, 191927, 278574, 191986, 191461, 191683, 191471, 193926, 192853, 192824, 192233, 195532, 193783, 193088, 191949, 194945, 191966, 193899, 191734, 193987, 192091, 191678, 193081, 191991, 191893, 191476, 191229, 191682, 192227, 194020, 184633, 192115, 192209, 192213, 192103, 191674, 193915, 191984, 191981, 193913, 191888, 191467, 192085, 191679, 192068, 187194, 192228, 192846, 192855, 192629, 192003, 193781, 193901, 192223, 191942, 193922, 192844, 192841, 191444, 193202, 192820, 193942, 194938, 192892, 193900, 193086, 192196, 192094, 193083, 191887, 192836, 192850, 191956, 192882, 193904, 194011, 192849, 194944, 193903, 193934, 191675, 191917, 187299, 191732, 191987, 191947, 191999, 191890, 191474, 191688, 201299, 192092, 192838, 191030, 192110, 192234, 188215, 193784, 194937, 193896, 193176, 192204, 191924, 191975, 193422, 192111, 202443, 192230, 191731, 192118, 192119, 192222, 193625, 191990, 193172, 191902, 191464, 191477, 191445, 191954, 192825, 191952, 179976, 192087, 192229, 194012, 191950, 192102, 192224, 192217, 192201, 192203, 193925, 191925, 191933, 193916, 193084, 193910, 191989, 193920, 193423, 191957, 193214, 192232, 191769, 191964, 194946, 193402, 192215, 192206, 193923, 191926, 191686, 193080, 193917, 191898, 191480, 194115, 193909, 180796, 191741, 201855, 202616, 192225, 191960, 192114, 192220, 193087, 191914, 193933, 191930, 193950, 192198, 191470, 193190, 191945, 192067, 191028, 193610, 192231);
UPDATE `gameobject_template` SET `ContentTuningId`=196, `VerifiedBuild`=52649 WHERE `entry`=192869; -- LAVA BLAST - by Pyroco

UPDATE `gameobject_template_addon` SET `WorldEffectID`=2773 WHERE `entry`=266869; -- Fishing Bobber
UPDATE `gameobject_template_addon` SET `flags`=262144, `WorldEffectID`=8830 WHERE `entry`=208317; -- Warchief's Command Board
UPDATE `gameobject_template_addon` SET `flags`=262144, `WorldEffectID`=8830 WHERE `entry`=208316; -- Hero's Call Board
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=192820; -- Tower
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry` IN (192234, 192232, 192230, 192227); -- Argent Vanguard Tower
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry` IN (192233, 192231, 192228, 192229); -- Argent Vanguard Support
UPDATE `gameobject_template_addon` SET `WorldEffectID`=16227 WHERE `entry` IN (191030, 191028, 191029); -- Barbershop Chair

UPDATE `gameobject_questitem` SET `VerifiedBuild`=52649 WHERE (`Idx`=0 AND `GameObjectEntry` IN (192827,192818,192828,192825,192824,192823));
