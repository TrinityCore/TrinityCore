--
UPDATE `creature_model_info` SET `BoundingRadius`=0.210000008344650268, `CombatReach`=0.900000035762786865 WHERE `DisplayID`=4566;
UPDATE `creature_model_info` SET `CombatReach`=8.75 WHERE `DisplayID`=27226;
UPDATE `creature_model_info` SET `Gender`=0 WHERE `DisplayID`=29836;
UPDATE `creature_model_info` SET `Gender`=0 WHERE `DisplayID`=29833;
UPDATE `creature_model_info` SET `CombatReach`=9.899999618530273437 WHERE `DisplayID`=27982;

UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32282; -- Wintergrasp Ghost Rune
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=31402; -- Azure Scalebane
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=30392; -- Navigator Anderlain
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=37107; -- Spiritual Reflection
UPDATE `creature_template` SET `unit_flags`=33088 WHERE `entry`=36955; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `npcflag`=`npcflag`|2048|512|256 WHERE `entry`=19718; -- Provisioner Tsaalt
UPDATE `creature_template` SET `npcflag`=`npcflag`|1024|512 WHERE `entry`=20986; -- Dealer Tariq
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=19689; -- Draenei Pilgrim
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=21443; -- Bone Wastes - Orb Waypoint 01
UPDATE `creature_template` SET `npcflag`=`npcflag`|2048|1024|512|256 WHERE `entry`=19679; -- "Slim"
UPDATE `creature_template` SET `npcflag`=`npcflag`|512 WHERE `entry`=20893; -- Morula
UPDATE `creature_template` SET `npcflag`=`npcflag`|256 WHERE `entry`=20892; -- Ruogo
UPDATE `creature_template` SET `minlevel`=66 WHERE `entry`=21313; -- Dead Clefthoof
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=32342; -- Green Paladin
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27640; -- Ring-Lord Conjurer
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27633; -- Azure Inquisitor
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27641; -- Centrifuge Construct
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27636; -- Azure Ley-Whelp
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=27639; -- Ring-Lord Sorceress
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=37498; -- Coliseum Champion
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=37497; -- Coliseum Champion
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=37603; -- Coliseum Champion
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=37605; -- Coliseum Champion
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29262; -- Gorgril Rigspark
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=32657; -- Privateer Stonemantle
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=0 WHERE `entry`=32654; -- SOTA Alliance Gun 1
UPDATE `creature_template` SET `npcflag`=1, `unit_flags`=32768 WHERE `entry`=32658; -- Privateer Zierhut
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=0 WHERE `entry`=32661; -- SOTA Alliance Gun 2
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32768; -- Invisible Stalker (Floating, Uninteractible, Large, Sessile, Custom Phase 2)
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90 WHERE `entry`=29; -- Kanrethad
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=0 WHERE `entry`=32655; -- SOTA Horde Gun 2
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=32659; -- Dread Captain Winge
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32662; -- Invisible Stalker (Floating, Uninteractible, Large, Sessile, Custom Phase 1)
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `speed_run`=0.985714316368103027, `unit_flags`=16384, `unit_flags2`=0 WHERE `entry`=28781; -- Battleground Demolisher
UPDATE `creature_template` SET `speed_walk`=1.20000004768371582, `speed_run`=0.985714316368103027, `unit_flags`=16384, `unit_flags2`=0 WHERE `entry`=32796; -- Battleground Demolisher
UPDATE `creature_template` SET `unit_flags`=16384, `unit_flags2`=0 WHERE `entry`=27894; -- Antipersonnel Cannon
UPDATE `creature_template` SET `unit_flags`=16384, `unit_flags2`=0 WHERE `entry`=32795; -- Antipersonnel Cannon
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=30878; -- Vesperon Controller
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=30648; -- Fire Cyclone
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=0, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry`=31103; -- Twilight Egg (Cosmetic)
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=27804; -- Golluck Rockfist
UPDATE `creature_template` SET `unit_flags2`=2050 WHERE `entry`=26778; -- Anub'et'kan Vehicle Trigger
UPDATE `creature_template` SET `unit_flags2`=2050 WHERE `entry`=26777; -- High Chief Icemist Vehicle Trigger
UPDATE `creature_template` SET `minlevel`=71 WHERE `entry`=26643; -- Rabid Grizzly
UPDATE `creature_template` SET `unit_flags`=33554944 WHERE `entry`=30492; -- Loken Controller
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=28835; -- Stormforged Construct
UPDATE `creature_template` SET `speed_walk`=3.2, `speed_run`=1.42857 WHERE `entry`=30978; -- Stormfury Revenant
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=28836; -- Stormforged Runeshaper
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=30975; -- Stormforged Runeshaper
UPDATE `creature_template` SET `speed_run`=1.28571 WHERE `entry`=30981; -- Titanium Vanguard
UPDATE `creature_template` SET `unit_flags2`=2080 WHERE `entry`=28546; -- Ionar
UPDATE `creature_template` SET `unit_flags2`=2080, `speed_walk`=3.2, `speed_run`=1.42857 WHERE `entry`=31537; -- Ionar
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=28965; -- Titanium Thunderer
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=30982; -- Titanium Thunderer
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=28961; -- Titanium Siegebreaker
UPDATE `creature_template` SET `speed_run`=1.42857 WHERE `entry`=30980; -- Titanium Siegebreaker
UPDATE `creature_template` SET `speed_walk`=1.55556 WHERE `entry`=30970; -- Slag
UPDATE `creature_template` SET `speed_walk`=0.888888, `speed_run`=2 WHERE `entry`=31536; -- Volkhan
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=30977; -- Stormforged Tactician
UPDATE `creature_template` SET `speed_walk`=1.6, `speed_run`=1.85714 WHERE `entry`=31538; -- Loken
UPDATE `creature_template` SET `speed_run`=1.28571 WHERE `entry`=30968; -- Hardened Steel Skycaller
UPDATE `creature_template` SET `speed_run`=1.28571 WHERE `entry`=30966; -- Hardened Steel Berserker
UPDATE `creature_template` SET `speed_run`=0.992063 WHERE `entry`=30974; -- Stormforged Mender
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=1.42857 WHERE `entry`=31533; -- General Bjarngrim
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=28578; -- Hardened Steel Reaver
UPDATE `creature_template` SET `speed_run`=1.28571 WHERE `entry`=30967; -- Hardened Steel Reaver
UPDATE `creature_template` SET `unit_flags`=0, `dynamicflags`=0 WHERE `entry`=26809; -- Ravaged Crystalline Ice Giant
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=26291; -- Crystalline Ice Giant
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31459; -- Forgotten One
UPDATE `creature_template` SET `maxlevel`=75 WHERE `entry`=30419; -- Bound Water Elemental
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31454; -- Bound Water Elemental
UPDATE `creature_template` SET `maxlevel`=75 WHERE `entry`=30416; -- Bound Fire Elemental
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31453; -- Bound Fire Elemental
UPDATE `creature_template` SET `maxlevel`=75 WHERE `entry`=30418; -- Bound Air Elemental
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31452; -- Bound Air Elemental
UPDATE `creature_template` SET `maxlevel`=75 WHERE `entry`=30329; -- Savage Cave Beast
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31470; -- Savage Cave Beast
UPDATE `creature_template` SET `unit_flags`=33554432, `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry`=30413; -- Channel Image Target
UPDATE `creature_template` SET `maxlevel`=75 WHERE `entry`=30319; -- Twilight Darkcaster
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31472; -- Twilight Darkcaster
UPDATE `creature_template` SET `maxlevel`=75 WHERE `entry`=30111; -- Twilight Worshipper
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31475; -- Twilight Worshipper
UPDATE `creature_template` SET `minlevel`=74 WHERE `entry`=30179; -- Twilight Apostle
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31471; -- Twilight Apostle
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31460; -- Frostbringer
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31457; -- Eye of Taldaram
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31466; -- Plague Walker
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31442; -- Ahn'kahar Slasher
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31443; -- Ahn'kahar Spell Flinger
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31450; -- Ahn'kahar Web Winder
UPDATE `creature_template` SET `BaseAttackTime`=3000 WHERE `entry`=30338; -- Ahn'kahar Swarmer
UPDATE `creature_template` SET `BaseAttackTime`=3000 WHERE `entry`=31447; -- Ahn'kahar Swarmer
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31455; -- Deep Crawler
UPDATE `creature_template` SET `minlevel`=80, `speed_run`=0.992063 WHERE `entry`=31449; -- Ahn'kahar Watcher
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=32325; -- Gold Priest
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31604; -- Anub'ar Prime Guard
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31587; -- Anub'ar Brood Keeper
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31598; -- Anub'ar Darter
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31603; -- Anub'ar Necromancer
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31596; -- Anub'ar Crypt Fiend
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31591; -- Anub'ar Champion
UPDATE `creature_template` SET `minlevel`=80 WHERE `entry`=31609; -- Anub'ar Webspinner
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=32343; -- Green Priest
UPDATE `creature_template` SET `scale`=1 WHERE `entry`=38564; -- Shadowy Mercenary
UPDATE `creature_template` SET `BaseAttackTime`=1800 WHERE `entry`=38112; -- Falric
UPDATE `creature_template` SET `BaseAttackTime`=1800 WHERE `entry`=38599; -- Falric
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32651; -- Wounded Dalaran Shield Guard
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=0 WHERE `entry`=35587; -- Argent Peacekeeper
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=35589; -- Jaeren Sunsworn
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29509; -- Namha Moonwater
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32515; -- Braeg Stoutbeard
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29513; -- Didi the Wrench
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29511; -- Lalla Brightweave
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32684; -- Mona Everspring
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28997; -- Griselda Hunderland
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32172; -- Harold Winston
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=28366; -- Wintergrasp Tower Cannon
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=31151; -- Tactical Officer Kilrath
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=31091; -- Commander Dardosh
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=28010; -- Stranded Thresher
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=28113; -- Mosswalker Victim
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=28443; -- Thalgran Blightbringer
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=768 WHERE `entry`=14732; -- PvP CTF Credit Marker
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33555200 WHERE `entry`=14645; -- Warsong Gulch Herald
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30196; -- Ebon Blade Prisoner
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29405; -- Uzo Deathcaller
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29344; -- Lord-Commander Arete
UPDATE `creature_template` SET `npcflag`=384, `unit_flags`=32768 WHERE `entry`=30070; -- Initiate Gahark
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30067; -- Initiate Claget
UPDATE `creature_template` SET `npcflag`=3200, `unit_flags`=32768 WHERE `entry`=30069; -- Initiate Roderick
UPDATE `creature_template` SET `unit_flags`=33587968, `dynamicflags`=0 WHERE `entry`=29515; -- Dead Death's Rise Vrykul
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29396; -- Setaal Darkmender
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29517; -- Darkmender's Ghoul
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=29456; -- Aurochs Grimbane
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=20213; -- World Trigger (Alliance Friendly + Invis Man)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=33555200 WHERE `entry`=20212; -- World Trigger (Horde Friendly + Invis Man)
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=30631; -- Darkrider Arly
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30708; -- Crusader Olakin Sainrith
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=30993; -- "Patches"
UPDATE `creature_template` SET `unit_flags`=512, `dynamicflags`=0 WHERE `entry`=31130; -- Festering Corpse
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=31153; -- Tactical Officer Ahbramis
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=31036; -- Commander Zanneth
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=30740; -- Valiance Expedition Champion

UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=15189; -- 15189
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=9936; -- 9936
