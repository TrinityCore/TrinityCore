--
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=2000, `unit_flags`=33555200 WHERE `entry`=16045; -- Isalien Trigger
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11492; -- Alzzin the Wildshaper
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=14349; -- Pimgib
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=14327; -- Lethtendris
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11457; -- Wildspawn Hellcaller
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11490; -- Zevrim Thornhoof
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11456; -- Wildspawn Shadowstalker
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=13276; -- Wildspawn Imp
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=13280; -- Hydrospawn
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=13197; -- Fel Lash
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11453; -- Wildspawn Trickster
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11455; -- Wildspawn Felsworn
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11451; -- Wildspawn Satyr
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11454; -- Wildspawn Betrayer
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11452; -- Wildspawn Rogue
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=11491; -- Old Ironbark
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11465; -- Warpwood Stomper
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11461; -- Warpwood Guardian
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=13196; -- Phase Lasher
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=13021; -- Warpwood Crusher
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=14354; -- Pusillin
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=13285; -- Death Lash
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=13022; -- Whip Lasher
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11464; -- Warpwood Tangler
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=11462; -- Warpwood Treant

UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='29266' WHERE `entry`=17062; -- 17062 (Fel Orc Corpse)
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29093; -- Ian Drake
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=15893; -- Lunar Firework Credit Marker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=15894; -- Lunar Cluster Credit Marker
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=18547; -- Scryer Arcanist
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=16852; -- Sedai's Corpse
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=17062; -- Fel Orc Corpse
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=22431; -- Anchorite Barada
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33555200 WHERE `entry`=13796; -- PvP Mine Credit Marker
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33555200 WHERE `entry`=13756; -- PvP Graveyard Credit Marker
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33555200 WHERE `entry`=13778; -- PvP Tower Credit Marker
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585 WHERE `entry`=16927; -- Stonescythe Whelp

UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=29728; -- Walter Soref
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=34983; -- Deathstalker Fane
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=34985; -- Misery
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=35611; -- Magistrix Erembria
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=35021; -- Marog
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=36225; -- Dark Ranger Anya
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30711; -- Margaux Parchley
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30729; -- Ickabod Pimlen
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29139; -- Naznik Sureshave
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29095; -- Edward Cairn
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=36224; -- Dark Ranger Clea
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=40437; -- Battered Brewer

UPDATE `page_text` SET `Text`='Here lies King Terenas Menethil II -- Last True King of Lordaeron.\n\nGreat were his deeds -- long was his reign -- unthinkable was his death. \n\n         \"May the Father lie blameless for the deeds of the son. \n          May the bloodied crown stay lost and forgotten.\"\n' WHERE `ID`=1731; -- 1731

UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=8458; -- 8458
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=1619; -- 1619
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=3421; -- 3421
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=10780; -- 10780
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=10778; -- 10778
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=10776; -- 10776
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=10775; -- 10775
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=10771; -- 10771
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=6287; -- 6287
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=11042; -- 11042
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=5193; -- 5193
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=5099; -- 5099
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=3193; -- 3193
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=5821; -- 5821

UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=11598; -- Risen Guardian
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=64 WHERE `entry`=1853; -- Darkmaster Gandling
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=16047; -- Kormok Trigger
