--
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=5 WHERE `ID`=12171; -- Of Traitors and Treason
UPDATE `quest_offer_reward` SET `Emote1`=0 WHERE `ID`=11409; -- Now This is Ram Racing... Almost.
UPDATE `quest_offer_reward` SET `Emote1`=6, `EmoteDelay1`=150 WHERE `ID`=12191; -- Chug and Chuck!
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Stranglethorn Vale flame.' WHERE `ID`=11832; -- Honor the Flame
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=13088; -- Northern Cooking

UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=11959 AND `id`=2; -- Slay Loguhn
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=11959 AND `id`=0; -- Slay Loguhn
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=14142 AND `id`=2; -- You've Really Done It This Time, Kul
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=14142 AND `id`=1; -- You've Really Done It This Time, Kul
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=14142 AND `id`=0; -- You've Really Done It This Time, Kul

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=12171; -- Of Traitors and Treason
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=1656; -- A Task Unfinished
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9140; -- Windrunner Village

UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25 WHERE `DisplayID`=21300;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=1.5 WHERE `DisplayID`=29842;
UPDATE `creature_model_info` SET `BoundingRadius`=0.420000016689300537, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=29283;

UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=27909; -- Darkweb Victim
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=38453; -- Arcturis
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=26425; -- Drakkari Warrior
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=70 WHERE `entry`=27336; -- Helpless Wintergarde Villager
UPDATE `creature_template` SET `speed_run`=2.142857074737548828 WHERE `entry`=27768; -- Image of Razuvious
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=26926; -- Duke Vallenhal
UPDATE `creature_template` SET `unit_flags2`=2080 WHERE `entry`=27702; -- Horde Lumberboat
UPDATE `creature_template` SET `unit_flags2`=2080 WHERE `entry`=27689; -- Alliance Lumberboat Explosions
UPDATE `creature_template` SET `unit_flags2`=2080 WHERE `entry`=27688; -- Alliance Lumberboat
UPDATE `creature_template` SET `unit_flags`=33554944 WHERE `entry`=23921; -- Halgrind Torch Bunny 01
UPDATE `creature_template` SET `unit_flags`=33554944 WHERE `entry`=23922; -- Halgrind Torch Bunny 02
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24198; -- Plagued Dragonflayer Rune-Caster
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24199; -- Plagued Dragonflayer Handler
UPDATE `creature_template` SET `unit_flags`=33554944 WHERE `entry`=23923; -- Halgrind Torch Bunny 03
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=23564; -- Plagued Dragonflayer Tribesman
UPDATE `creature_template` SET `modelid1`=239, `modelid2`=229, `modelid3`=236 WHERE `entry`=23747; -- Overworked Nag
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=27322; -- Orsonn Conversation Credit
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=15065; -- Lady
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=15066; -- Cleo
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `unit_flags`=33554432 WHERE `entry`=15063; -- Arathi Blacksmith
UPDATE `creature_template` SET `speed_walk`=0.800000011920928955 WHERE `entry`=27779; -- Image of Noth
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=14440; -- Hunter Sagewind
UPDATE `creature_template` SET `unit_flags`=832 WHERE `entry`=14865; -- Felinni
UPDATE `creature_template` SET `unit_flags`=33587968 WHERE `entry`=33068; -- Darkmoon Faire - Cannon Target Bunny
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=10599; -- Hulfnar Stonetotem
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=10600; -- Thontek Rumblehoof
UPDATE `creature_template` SET `modelid1`=7244, `modelid2`=355, `modelid3`=1122, `modelid4`=3903 WHERE `entry`=2976; -- Venture Co. Laborer
UPDATE `creature_template` SET `modelid1`=7246, `modelid2`=355, `modelid4`=3908 WHERE `entry`=2977; -- Venture Co. Taskmaster
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=23487; -- Wild Wolpertinger
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=15012; -- Javnir Nashak
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=15115; -- Honored Ancestor
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=24373; -- T'chali's Voodoo Brew Festive Keg
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=27216; -- Bizzle Quicklift
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=24372; -- Drohn's Distillery Festive Keg
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=50 WHERE `entry`=28560; -- Citizen of New Avalon
UPDATE `creature_template` SET `minlevel`=30 WHERE `entry`=28662; -- Citizen of Havenshire
UPDATE `creature_template` SET `minlevel`=30 WHERE `entry`=28559; -- Citizen of New Avalon
UPDATE `creature_template` SET `minlevel`=30 WHERE `entry`=28660; -- Citizen of Havenshire
UPDATE `creature_template` SET `speed_run`=1.714285731315612792 WHERE `entry`=28606; -- Havenshire Mare
UPDATE `creature_template` SET `speed_run`=1.714285731315612792, `VehicleId`=123 WHERE `entry`=28605; -- Havenshire Stallion
UPDATE `creature_template` SET `speed_run`=1.714285731315612792, `VehicleId`=123 WHERE `entry`=28607; -- Havenshire Colt
UPDATE `creature_template` SET `speed_run`=1.385714292526245117, `VehicleId`=25 WHERE `entry`=28446; -- Fury
UPDATE `creature_template` SET `maxlevel`=56 WHERE `entry`=28505; -- Enslaved Laborer
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=28385; -- Scarlet Crusade Prisoner
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=2502; -- "Shaky" Phillipe
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=30883; -- Dalaran Prison Event Controller
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=25865; -- Frozen Core
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=25740; -- Ahune
UPDATE `creature_template` SET `unit_flags`=33554944 WHERE `entry`=26190; -- [PH] Spank Target Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=25746; -- [PH] Ahune Loot Loc Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=26120; -- Wisp Dest Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=25973; -- Shaman Bonfire Bunny 002
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=26121; -- Wisp Source Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=25972; -- Shaman Bonfire Bunny 001
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=25961; -- Earthen Ring Totem
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=25745; -- [PH] Ahune Summon Loc Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=25952; -- Slippery Floor Bunny
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=40446; -- Skar'this the Summoner
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=26230; -- Snow Bunny
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=25971; -- Shaman Bonfire Bunny 000
UPDATE `creature_template` SET `speed_run`=1.571428537368774414, `unit_flags2`=0 WHERE `entry`=36557; -- Argent Warhorse
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=35016; -- [ph] Argent Raid Spectator - Generic Bunny
UPDATE `creature_template` SET `modelid2`=11160, `modelid3`=11159 WHERE `entry`=11346; -- Hakkari Oracle
UPDATE `creature_template` SET `modelid2`=11169, `modelid3`=11168 WHERE `entry`=11355; -- Gurubashi Warrior
UPDATE `creature_template` SET `modelid1`=6297, `modelid4`=901 WHERE `entry`=13321; -- Small Frog
UPDATE `creature_template` SET `modelid1`=1986, `modelid2`=1206 WHERE `entry`=3300; -- Adder
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=16310; -- Mana Shifter
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=16601; -- Dying Blood Elf
UPDATE `creature_template` SET `maxlevel`=29 WHERE `entry`=16541; -- Ghostlands Guardian
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=26400; -- Outland Children's Week Silvermoon L70ETC 01 Trigger
UPDATE `creature_template` SET `maxlevel`=10 WHERE `entry`=18792; -- Harassed Citizen
-- Heh, why
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=18727; -- Rarthein
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=16671; -- Mirvedon
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=18763; -- Blood Elf Warlock
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=16668; -- Gloresse
UPDATE `creature_template` SET `npcflag`=128, `unit_flags`=32768 WHERE `entry`=14480; -- Alowicious Czervik
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=34043; -- Lady Palanseer
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=37072; -- Rogg

UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=12779; -- 12779
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=1220; -- 1220
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14040; -- 14040
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=13840; -- 13840
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14791; -- 14791
