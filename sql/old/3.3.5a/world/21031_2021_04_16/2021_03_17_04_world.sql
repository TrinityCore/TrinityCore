--
UPDATE `creature_model_info` SET `Gender`=0 WHERE `DisplayID`=856;
UPDATE `creature_model_info` SET `BoundingRadius`=0.14136439561843872, `CombatReach`=0.605847477912902832 WHERE `DisplayID`=4732;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5 WHERE `DisplayID`=22657;

UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 28197;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28197 AND `source_type` = 0;

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=32307; -- Warsong Guard
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=30273; -- Webbed Crusader
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=28276; -- Greater Ley-Whelp
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=30991; -- Greater Ley-Whelp
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27648; -- Phantasmal Naga
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=30911; -- Phantasmal Naga
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27647; -- Phantasmal Ogre
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27649; -- Phantasmal Murloc
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=30910; -- Phantasmal Murloc
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27651; -- Phantasmal Fire
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27653; -- Phantasmal Water
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=30913; -- Phantasmal Water
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27650; -- Phantasmal Air
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=30906; -- Phantasmal Air
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27642; -- Phantasmal Mammoth
UPDATE `creature_template` SET `maxlevel`=81 WHERE `entry`=30909; -- Phantasmal Mammoth
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27645; -- Phantasmal Cloudscraper
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27644; -- Phantasmal Wolf
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27638; -- Azure Ring Guardian
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27635; -- Azure Spellbinder
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=12428; -- Deathguard Kel
UPDATE `creature_template` SET `minlevel`=40 WHERE `entry`=25994; -- Flame Eater
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=10716; -- Belfry Bat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=70, `unit_flags`=33536 WHERE `entry`=26124; -- Midsummer Merchant
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=26355; -- [DND] Midsummer Bonfire Faction Bunny - H
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=24884; -- Padwai, Son of Orfus
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=23804; -- Orfus of Kamagua
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=24902; -- Abdul Relay
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24900; -- Abdul the Insane
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24786; -- Reef Bull
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24797; -- Reef Cow
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24676; -- Crazed Northsea Slaver
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24763; -- Akiaruk
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=28197; -- Kip Trawlskip
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24755; -- Elder Atuik
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24810; -- Anuniaq
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24754; -- Iskaal Refugee
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=27167; -- Kamagua Spearman
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=26558; -- Nutaaq
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=23638; -- Longtusk Fisherman
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=23749; -- Captain Adams
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24038; -- Father Levariol
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=23777; -- Proto-Drake Egg
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=23888; -- Mage-Lieutenant Malister
UPDATE `creature_template` SET `speed_run`=3.428571462631225585 WHERE `entry`=28135; -- Westguard Gryphon
UPDATE `creature_template` SET `speed_run`=3 WHERE `entry`=24705; -- Rope Swing Invisible Vehicle Stalker
UPDATE `creature_template` SET `HoverHeight`=5 WHERE `entry`=27292; -- Flamebringer
UPDATE `creature_template` SET `speed_walk`=3.20000004768371582 WHERE `entry`=27496; -- Refurbished Shredder
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=26363; -- Tallhorn Stag
UPDATE `creature_template` SET `faction`=1912, `unit_flags`=32768 WHERE `entry`=27335; -- Hungering Dead
UPDATE `creature_template` SET `speed_walk`=0.800000011920928955, `speed_run`=0.992062866687774658 WHERE `entry`=27290; -- Hungering Dead
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=27607; -- Plague Wagon
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=27241; -- Risen Gryphon
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=70, `unit_flags2`=0 WHERE `entry`=27359; -- Trapped Wintergarde Villager
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=27268; -- Risen Gryphon Rider
UPDATE `creature_template` SET `maxlevel`=60 WHERE `entry`=25962; -- Fire Eater
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=26511; -- Moa'ki Bottom Thresher
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=35131; -- Durgan Thunderbeak
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=35133; -- Maigra Keenfeather
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=25253; -- Valiance Keep Footman
UPDATE `creature_template` SET `faction`=1891 WHERE `entry`=26448; -- Stars' Rest Sentinel
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=26933; -- Wyrmrest Guardian
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12783; -- Lieutenant Karter
UPDATE `creature_template` SET `maxlevel`=70 WHERE `entry`=26123; -- Midsummer Supplier
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=70 WHERE `entry`=25975; -- Master Fire Eater
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=26258; -- [DND] Midsummer Bonfire Faction Bunny - A

UPDATE `creature_template` SET `modelid1`=19178, `modelid2`=19177 WHERE `entry`=18927; -- Human Commoner
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=5661; -- Brother Malach
UPDATE `creature_template` SET `modelid1`=3976, `modelid2`=3975, `modelid3`=3974, `modelid4`=3973 WHERE `entry`=5680; -- Male Human Captive
UPDATE `creature_template` SET `modelid1`=3980, `modelid2`=3979, `modelid3`=3978, `modelid4`=3977 WHERE `entry`=5681; -- Female Human Captive
UPDATE `creature_template` SET `modelid1`=2536, `modelid2`=9829, `modelid3`=1160 WHERE `entry`=14881; -- Spider
UPDATE `creature_template` SET `modelid1`=2483, `modelid2`=2472 WHERE `entry`=1537; -- Scarlet Zealot
UPDATE `creature_template` SET `IconName`='' WHERE `entry`=1652; -- Deathguard Burgess
UPDATE `creature_template` SET `modelid2`=6303, `modelid3`=2957, `modelid4`=2958 WHERE `entry`=19833; -- Venomous Snake
UPDATE `creature_template` SET `modelid2`=6303, `modelid3`=2957, `modelid4`=2958 WHERE `entry`=19921; -- Viper
