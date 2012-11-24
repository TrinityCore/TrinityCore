-- Some Dalran and Area Updates (sniff)
-- Template updates
UPDATE `creature_template` SET `exp`=0,`npcflag`=`npcflag`|640 WHERE `entry`=32415; -- Hamaka
UPDATE `creature_template` SET `exp`=0,`npcflag`=`npcflag`|130 WHERE `entry`=31031; -- Misensi
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry`=35826; -- Kaye Toogie
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|4 WHERE `entry`=32428; -- Underbelly Rat
UPDATE `creature_template` SET `npcflag`=`npcflag`|3 WHERE `entry`=36670; -- Magister Hathorel
UPDATE `creature_template` SET `exp`=2,`minlevel`=82,`maxlevel`=82,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200 WHERE `entry`=37858; -- Razorscale Image
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=32328; -- [DND] Dalaran Sewer Arena - Controller - Death
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=32339; -- [DND] Dalaran Sewer Arena - Controller
UPDATE `creature_template` SET `minlevel`=75,`maxlevel`=75,`npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|768 WHERE `entry`=33938; -- Zom Bocom
UPDATE `creature_template` SET `minlevel`=75,`maxlevel`=75,`npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|768 WHERE `entry`=33937; -- Xazi Smolderpipe
UPDATE `creature_template` SET `minlevel`=75,`maxlevel`=75,`npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|512 WHERE `entry`=33936; -- Nargle Lashcord
UPDATE `creature_template` SET `npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|512 WHERE `entry`=34095; -- Trapjaw Rix
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33544 WHERE `entry`=42078; -- Mini Thor
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=32322; -- Gold Warrior
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=32325; -- Gold Priest

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=1.05,`combat_reach`=1.05,`gender`=0 WHERE `modelid`=10957; -- Dappled Stag
UPDATE `creature_model_info` SET `bounding_radius`=0.236,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=27957; -- Hamaka
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=1141; -- Underbelly Rat
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=0.75,`gender`=0 WHERE `modelid`=4449; -- Imp
UPDATE `creature_model_info` SET `bounding_radius`=0.09,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=30806; -- Razorscale Image
UPDATE `creature_model_info` SET `bounding_radius`=0.75,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=27766; -- [DND] Dalaran Sewer Arena - Controller
UPDATE `creature_model_info` SET `bounding_radius`=0.09,`combat_reach`=0,`gender`=2 WHERE `modelid`=32670; -- Mini Thor

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (417,31233,31228,33778,34244,31236,29631,32692,32687,30352,31085,30755,31081,28671,28160,31031,28674,31238,29238,31229,
32596,32415,32419,32418,32253,32412,32602,32732,31439,35826,32428,36670,32251,32252,32420,30659,32730,28991,32470,27047,29497,29534,31851,29493,28989,29533,32686,32683,
29325,31080,20735,28742,29496,32265,31517,29499,37858,29156,29476,28993,32691,32675,30885,32328,32339,32743,23472,33938,33937,33936,34095,29527,28956,28691,28332,28994,28692,
42078,29494,35497,29523,35500,28992,32683,29763,29764,29765,29766,37776,32509,29529,29529,28776,30726,28774,29528,32601,32710,32752,
32322,32325);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(32322,0,0,1,0, NULL), -- Gold Warrior
(32325,0,0,1,0, NULL), -- Gold Priest
(32752,0,0,1,0, NULL), -- Tabitha
(32710,0,0,1,0, NULL), -- Garl Grimgrizzle
(29763,0,0,1,0, NULL), -- Cosmetic Totem Alliance Air
(29764,0,0,1,0, NULL), -- Cosmetic Totem Alliance Earth
(29765,0,0,1,0, NULL), -- Cosmetic Totem Alliance Fire
(29766,0,0,1,0, NULL), -- Cosmetic Totem Alliance Water
(37776,0,0,1,0, NULL), -- Apprentice Nelphi
(32509,0,0,257,0, NULL), -- Brammold Deepmine
(29528,0,0,257,0, NULL), -- Debbi Moore
(29529,0,0,257,0, NULL), -- Ninsianna
(28776,0,0,257,0, NULL), -- Elizabeth Ross
(30726,0,0,257,0, NULL), -- Archivist Betha
(28774,0,0,257,0, NULL), -- Andrew Matthews
(42078,0,0,1,0, NULL), -- Mini Thor
(29494,0,0,257,0, NULL), -- Shen Kang Cheng
(35497,0,0,257,0, NULL), -- Rafael Langrom
(29523,0,0,257,0, NULL), -- Bragund Brightlink
(35500,0,0,257,0, NULL), -- Matilda Brightlink
(28992,0,0,257,0, NULL), -- Valerie Langrom
(32683,0,0,257,0, NULL), -- Grezla the Hag
(32686,0,0,257,0, NULL), -- Crafticus Mindbender
(28692,0,0,257,0, NULL), -- "Red" Jack Findle
(28994,0,0,257,0, NULL), -- Abra Cadabra
(28332,0,0,1,0, NULL), -- Generic Trigger LAB (Large AOI)
(28691,0,0,257,0, NULL), -- Susana Averoy
(30885,0,0,1,0, NULL), -- Blazik Fireclaw
(32328,0,0,1,0, NULL), -- [DND] Dalaran Sewer Arena - Controller - Death
(32339,0,0,1,0, NULL), -- [DND] Dalaran Sewer Arena - Controller
(32743,0,1,1,0, NULL), -- Willard Blauvelt
(23472,0,0,1,0, NULL), -- World Trigger (Large AOI, Not Immune PC/NPC)
(33938,0,0,1,0, NULL), -- Zom Bocom
(33937,0,0,1,0, NULL), -- Xazi Smolderpipe
(33936,0,0,1,0, NULL), -- Nargle Lashcord
(34095,0,0,1,0, NULL), -- Trapjaw Rix
(29527,0,0,257,0, NULL), -- Orton Bennet
(28956,0,0,257,0, NULL), -- Warcaster Fanoraithe
(29534,0,0,1,0, NULL), -- "Baroness" Llana
(31851,0,65536,1,0, NULL), -- Wooly Mammoth
(29493,0,0,257,0, NULL), -- Jarold Puller
(28989,0,0,258,0, NULL), -- Aemara
(29533,0,0,1,0, NULL), -- Schembari "Uncle Sal" Shearbolt
(32675,0,0,257,0, NULL), -- Babagahnoosh the Grumpy
(32691,0,0,257,0, NULL), -- Magus Fansy Goodbringer
(28993,0,0,1,0, NULL), -- Aerith Primrose
(29476,0,0,258,0, NULL), -- Dagna Flintlock
(29156,0,0,257,0, NULL), -- Archmage Celindra
(37858,0,50331648,0,0, NULL), -- Razorscale Image
(32265,0,50331648,1,0, NULL), -- Northrend Daily Dungeon Image Bunny
(31517,0,0,1,0, NULL), -- Dalaran Fountain Invis Stalker
(29499,0,0,257,0, NULL), -- Bartram Haller
(31228,0,0,1,0, NULL), -- Grove Walker
(33778,0,1,1,0, NULL), -- Tournament Hippogryph
(34244,0,0,1,0, NULL), -- Jean Pierre Poulain
(31236,0,0,1,0, NULL), -- Dappled Stag
(29631,0,0,1,0, NULL), -- Awilo Lon'gomba
(32692,0,0,257,0, NULL), -- Arcanist Alec
(32687,0,0,257,0, NULL), -- Linda Ann Kastinglow
(30352,0,0,256,0, NULL), -- Skybreaker Marine
(31085,0,0,1,0, NULL), -- Sky-Reaver Klum
(30755,0,0,256,0, NULL), -- Kor'kron Reaver
(31081,0,0,1,0, NULL), -- Officer Van Rossem
(28160,0,0,257,0, NULL), -- Archmage Pentarus
(28674,0,0,257,0, NULL), -- Aludane Whitecloud
(31031,0,0,1,69, NULL), -- Misensi
(31238,27525,0,257,0, NULL), -- Hira Snowdawn
(29238,0,0,1,0, NULL), -- Scourge Haunt
(31229,0,0,1,0, NULL), -- Ancient Watcher
(32596,0,0,257,0, NULL), -- Dalaran Visitor
(32602,25833,0,257,0, NULL), -- Dalaran Visitor
(32601,22471,0,257,0, NULL), -- Dalaran Visitor
(32415,0,0,1,0, NULL), -- Hamaka
(32419,0,0,1,0, NULL), -- Umbiwa
(32418,0,0,1,0, NULL), -- Abohba
(32253,0,0,2,0, NULL), -- Kyunghee
(32412,0,0,1,0, NULL), -- Mato
(32732,0,0,257,0, NULL), -- Dorfus Alphamage
(31439,0,0,1,0, NULL), -- Archmage Timear
(35826,0,1,1,0, NULL), -- Kaye Toogie
(32428,0,0,1,0, NULL), -- Underbelly Rat
(36670,0,0,1,0, NULL), -- Magister Hathorel
(32251,0,0,2,0, NULL), -- Shokavis
(32252,0,0,2,0, NULL), -- Wanathan
(32420,0,0,1,10, NULL), -- Mimbihi
(30659,0,0,1,333, NULL), -- Violet Hold Guard
(32730,0,0,257,0, NULL), -- Goldlilly Gleamingfell
(28991,0,0,257,0, NULL), -- Valaden Silverblade
(32470,0,0,1,0, NULL), -- Sewer Frog
(27047,0,0,1,0, NULL), -- Invisible Stalker (Floating Only)
(29497,0,0,257,0, NULL), -- Walther Whiteford
(29325,0,0,1,379, NULL), -- Torgo the Younger
(31080,0,0,1,0, NULL), -- Warden Alturas
(20735,0,0,1,0, NULL), -- Archmage Lan'dalock
(28742,0,0,257,0, NULL), -- Marcia Chase
(29496,0,0,257,0, NULL); -- Kerta the Bold

-- Template updates for gameobject
UPDATE `gameobject_template` SET `faction`=0 WHERE `entry`=35591; -- Fishing Bobber
