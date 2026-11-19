DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=133019 AND `Idx`=0) OR (`CreatureEntry`=132672 AND `Idx`=0) OR (`CreatureEntry`=132591 AND `Idx`=0) OR (`CreatureEntry`=132584 AND `Idx`=0) OR (`CreatureEntry`=132580 AND `Idx`=0) OR (`CreatureEntry`=132578 AND `Idx`=0) OR (`CreatureEntry`=132203 AND `Idx`=1) OR (`CreatureEntry`=132203 AND `Idx`=0) OR (`CreatureEntry`=132199 AND `Idx`=0) OR (`CreatureEntry`=132164 AND `Idx`=0) OR (`CreatureEntry`=132159 AND `Idx`=0) OR (`CreatureEntry`=132062 AND `Idx`=0) OR (`CreatureEntry`=132055 AND `Idx`=0) OR (`CreatureEntry`=132042 AND `Idx`=0) OR (`CreatureEntry`=131908 AND `Idx`=0) OR (`CreatureEntry`=131907 AND `Idx`=0) OR (`CreatureEntry`=131895 AND `Idx`=0) OR (`CreatureEntry`=131893 AND `Idx`=0) OR (`CreatureEntry`=131892 AND `Idx`=0) OR (`CreatureEntry`=130598 AND `Idx`=0) OR (`CreatureEntry`=130425 AND `Idx`=0) OR (`CreatureEntry`=87910 AND `Idx`=0) OR (`CreatureEntry`=87619 AND `Idx`=0) OR (`CreatureEntry`=86330 AND `Idx`=0) OR (`CreatureEntry`=86329 AND `Idx`=0) OR (`CreatureEntry`=86326 AND `Idx`=0) OR (`CreatureEntry`=86290 AND `Idx`=0) OR (`CreatureEntry`=86275 AND `Idx`=0) OR (`CreatureEntry`=86256 AND `Idx`=0) OR (`CreatureEntry`=85225 AND `Idx`=0) OR (`CreatureEntry`=82900 AND `Idx`=0) OR (`CreatureEntry`=82528 AND `Idx`=0) OR (`CreatureEntry`=82519 AND `Idx`=0) OR (`CreatureEntry`=81811 AND `Idx`=0) OR (`CreatureEntry`=81810 AND `Idx`=0) OR (`CreatureEntry`=81809 AND `Idx`=0) OR (`CreatureEntry`=81808 AND `Idx`=0) OR (`CreatureEntry`=81807 AND `Idx`=0) OR (`CreatureEntry`=81806 AND `Idx`=0) OR (`CreatureEntry`=81780 AND `Idx`=0) OR (`CreatureEntry`=81272 AND `Idx`=0) OR (`CreatureEntry`=81270 AND `Idx`=0) OR (`CreatureEntry`=81269 AND `Idx`=0) OR (`CreatureEntry`=74370 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(133019, 0, 156711, 26365), -- Lazy Prospector
(132672, 0, 129888, 26365), -- Great Eagle
(132591, 0, 156797, 26365), -- Ogmot the Mad
(132584, 0, 156794, 26365), -- Xaarshej
(132580, 0, 156794, 26365), -- Ssinkrix
(132578, 0, 156794, 26365), -- Qroshekx
(132203, 1, 156796, 26365), -- Michiel Voidstrider
(132203, 0, 156797, 26365), -- Michiel Voidstrider
(132199, 0, 156797, 26365), -- Twilight Earthbreaker
(132164, 0, 156711, 26365), -- Bilgewater Shredder
(132159, 0, 133955, 26365), -- T.B. Bret
(132062, 0, 156711, 26365), -- Bilgewater Laborer
(132055, 0, 156711, 26365), -- Bilgewater Prospector
(132042, 0, 156711, 26365), -- Bilgewater Mook
(131908, 0, 156797, 26365), -- Twilight Survivor
(131907, 0, 156797, 26365), -- Twilight Ritualist
(131895, 0, 156794, 26365), -- Silithid Spitfire
(131893, 0, 156794, 26365), -- Silithid Drone
(131892, 0, 156794, 26365), -- Silithid Sentinel
(130598, 0, 155832, 26365), -- Crystal Spine Matriarch
(130425, 0, 136400, 26365), -- Dark Tendril
(87910, 0, 115590, 26365), -- Gorian Rune-Mender
(87619, 0, 115590, 26365), -- Gorian Warden
(86330, 0, 115590, 26365), -- Breaker Ritualist
(86329, 0, 115590, 26365), -- Breaker Ritualist
(86326, 0, 115590, 26365), -- Breaker Ritualist
(86290, 0, 115590, 26365), -- Underbelly Vagrant
(86275, 0, 115590, 26365), -- Gorian Enforcer
(86256, 0, 115590, 26365), -- Gorian High Sorcerer
(85225, 0, 115590, 26365), -- Gorian Sorcerer
(82900, 0, 115590, 26365), -- Gorian Enforcer
(82528, 0, 115590, 26365), -- Gorian Arcanist
(82519, 0, 115590, 26365), -- Highmaul Conscript
(81811, 0, 115590, 26365), -- High Councilor Mal'gris
(81810, 0, 115590, 26365), -- Councilor Daglat
(81809, 0, 115590, 26365), -- Councilor Gorluk
(81808, 0, 115590, 26365), -- Councilor Magknor
(81807, 0, 115590, 26365), -- Councilor Nouk
(81806, 0, 115590, 26365), -- Gorian Royal Guardsman
(81780, 0, 115590, 26365), -- Guard Captain Thag
(81272, 0, 115590, 26365), -- Gorian Runemaster
(81270, 0, 115590, 26365), -- Gorian Guardsman
(81269, 0, 115590, 26365), -- Warden Thul'tok
(74370, 0, 115013, 26365); -- Shadowmoon Peon

UPDATE `creature_questitem` SET `ItemId`=122161, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=90412 AND `Idx`=0); -- Vok Blacktongue
UPDATE `creature_questitem` SET `ItemId`=122160, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=90408 AND `Idx`=0); -- Lor Stonefist
UPDATE `creature_questitem` SET `ItemId`=122162, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=90404 AND `Idx`=0); -- Koros Soulsplinter
UPDATE `creature_questitem` SET `ItemId`=118570, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=87639 AND `Idx`=0); -- Urna Darkfathom
UPDATE `creature_questitem` SET `ItemId`=114976, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=84675 AND `Idx`=0); -- Lug'dol
UPDATE `creature_questitem` SET `ItemId`=114678, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=84245 AND `Idx`=0); -- Rosa the Thief
UPDATE `creature_questitem` SET `ItemId`=112308, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=80335 AND `Idx`=0); -- Witch Lord Morkurk
UPDATE `creature_questitem` SET `ItemId`=112088, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=80295 AND `Idx`=0); -- Vizier Cromaug
UPDATE `creature_questitem` SET `ItemId`=112088, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=80294 AND `Idx`=0); -- Vizier Vorgorsh
UPDATE `creature_questitem` SET `ItemId`=112088, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=80292 AND `Idx`=0); -- Vizier Zulmork
UPDATE `creature_questitem` SET `ItemId`=111528, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79626 AND `Idx`=0); -- Slave Hunter Mol
UPDATE `creature_questitem` SET `ItemId`=111527, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79623 AND `Idx`=0); -- Slave Hunter Krag
UPDATE `creature_questitem` SET `ItemId`=108899, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79621 AND `Idx`=0); -- Slave Hunter Brol
UPDATE `creature_questitem` SET `ItemId`=111066, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79267 AND `Idx`=0); -- Crulgorosh
UPDATE `creature_questitem` SET `ItemId`=111065, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79266 AND `Idx`=0); -- Thulgork
UPDATE `creature_questitem` SET `ItemId`=112088, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79236 AND `Idx`=0); -- Gordunni Warpbinder
UPDATE `creature_questitem` SET `ItemId`=112088, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=79232 AND `Idx`=0); -- Gordunni Magi
UPDATE `creature_questitem` SET `ItemId`=110664, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=78778 AND `Idx`=0); -- Rugrum the Pit Boss
UPDATE `creature_questitem` SET `ItemId`=110116, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=78174 AND `Idx`=0); -- Nub the Torturer
UPDATE `creature_questitem` SET `ItemId`=109162, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=77349 AND `Idx`=0); -- Dur'gol the Ruthless
UPDATE `creature_questitem` SET `ItemId`=109023, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=77020 AND `Idx`=0); -- Kor'gall
UPDATE `creature_questitem` SET `ItemId`=6841, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=74948 AND `Idx`=0); -- Roogug
UPDATE `creature_questitem` SET `ItemId`=106944, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=74707 AND `Idx`=0); -- Gullok
UPDATE `creature_questitem` SET `ItemId`=106942, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=74706 AND `Idx`=0); -- Splorg
UPDATE `creature_questitem` SET `ItemId`=106943, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=74704 AND `Idx`=0); -- Thunk
UPDATE `creature_questitem` SET `ItemId`=104043, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=73440 AND `Idx`=0); -- Shadowmoon Stormcaller
UPDATE `creature_questitem` SET `ItemId`=104042, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=73439 AND `Idx`=0); -- Shadowmoon Magmatic
UPDATE `creature_questitem` SET `ItemId`=107075, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=72873 AND `Idx`=0); -- Slavemaster Turgall
UPDATE `creature_questitem` SET `ItemId`=69678, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=53264 AND `Idx`=0); -- Searris
UPDATE `creature_questitem` SET `ItemId`=69678, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=52300 AND `Idx`=0); -- Seething Pyrelord
UPDATE `creature_questitem` SET `ItemId`=64404, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=48533 AND `Idx`=0); -- Enormous Gyreworm
UPDATE `creature_questitem` SET `ItemId`=65504, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=47056 AND `Idx`=0); -- Gorged Gyreworm
UPDATE `creature_questitem` SET `ItemId`=60814, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=44988 AND `Idx`=0); -- Greater Quicksilver Ooze
UPDATE `creature_questitem` SET `ItemId`=65504, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=44259 AND `Idx`=0); -- Gorged Gyreworm
UPDATE `creature_questitem` SET `ItemId`=65504, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=44257 AND `Idx`=0); -- Gyreworm
UPDATE `creature_questitem` SET `ItemId`=60487, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=44220 AND `Idx`=0); -- Jade Rager
UPDATE `creature_questitem` SET `ItemId`=65660, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=43878 AND `Idx`=0); -- Grand Vizier Ertan
UPDATE `creature_questitem` SET `ItemId`=3910, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=43542 AND `Idx`=1); -- Lime Thief
UPDATE `creature_questitem` SET `ItemId`=3897, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=43542 AND `Idx`=0); -- Lime Thief
UPDATE `creature_questitem` SET `ItemId`=60814, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=43158 AND `Idx`=0); -- Mercurial Ooze
UPDATE `creature_questitem` SET `ItemId`=59062, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=43123 AND `Idx`=0); -- Living Blood
UPDATE `creature_questitem` SET `ItemId`=58168, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=42780 AND `Idx`=0); -- Irestone Rumbler
UPDATE `creature_questitem` SET `ItemId`=65504, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=42766 AND `Idx`=0); -- Gorged Gyreworm
UPDATE `creature_questitem` SET `ItemId`=58168, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=42527 AND `Idx`=0); -- Irestone Rumbler
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=21801 AND `Idx`=0); -- Vhel'kur
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=21148 AND `Idx`=0); -- Rift Keeper
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=21140 AND `Idx`=0); -- Rift Lord
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=21104 AND `Idx`=0); -- Rift Keeper
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=21102 AND `Idx`=0); -- Uvuros
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=18290 AND `Idx`=0); -- Tusker
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=18259 AND `Idx`=0); -- Banthar
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=18258 AND `Idx`=0); -- Bach'lor
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=17839 AND `Idx`=0); -- Rift Lord
UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=17536 AND `Idx`=0); -- Nazan
UPDATE `creature_questitem` SET `ItemId`=21982, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=10584 AND `Idx`=0); -- Urok Doomhowl
UPDATE `creature_questitem` SET `ItemId`=5792, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=4421 AND `Idx`=1); -- Charlga Razorflank
UPDATE `creature_questitem` SET `ItemId`=5793, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=4421 AND `Idx`=0); -- Charlga Razorflank
UPDATE `creature_questitem` SET `ItemId`=6184, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=1088 AND `Idx`=0); -- Monstrous Crawler
UPDATE `creature_questitem` SET `ItemId`=61356, `VerifiedBuild`=26365 WHERE (`CreatureEntry`=922 AND `Idx`=0); -- Silt Crawler
