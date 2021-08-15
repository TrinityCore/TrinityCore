--
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=14096; -- You've Really Done It This Time, Kul
UPDATE `quest_offer_reward` SET `Emote1`=396 WHERE `ID`=14152; -- Rescue at Sea
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=14112; -- What Do You Feed a Yeti, Anyway?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13790; -- Among the Champions
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1 WHERE `ID`=13789; -- Taking Battle To The Enemy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=14017; -- The Black Knight's Fate
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=14016; -- The Black Knight's Curse
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13664; -- The Black Knight's Fall
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=13794; -- Eadric the Pure
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13702; -- A Champion Rises
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=13706; -- Valiant Of Darnassus
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=13699; -- The Valiant's Challenge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13718; -- The Valiant's Charge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=13600; -- A Worthy Weapon
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=26012; -- Trouble at Wyrmrest
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3845; -- It's a Secret to Everybody
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000 WHERE `ID`=11951; -- Bait and Switch
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000 WHERE `ID`=11919; -- Drake Hunt
UPDATE `quest_offer_reward` SET `EmoteDelay2`=500 WHERE `ID`=11936; -- Hatching a Plan
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000 WHERE `ID`=11943; -- The Cell
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11344; -- Anguish of Nifflevar

DELETE FROM `quest_poi` WHERE `QuestID`=14112 AND `id` IN (3,2,1);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(14112, 3, -1, 571, 492, 0, 0, 3, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 4, 571, 492, 0, 2, 3, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 1, 11, 571, 492, 0, 1, 3, 12340); -- What Do You Feed a Yeti; Anyway?
DELETE FROM `quest_poi` WHERE `QuestID`=26012 AND `id`=0;
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(26012, 0, -1, 571, 488, 0, 0, 1, 12340); -- Trouble at Wyrmrest
DELETE FROM `quest_poi` WHERE `QuestID`=3802 AND `id` IN (1,0);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(3802, 1, 4, 0, 28, 0, 0, 7, 12340), -- Dark Iron Legacy
(3802, 0, -1, 0, 28, 0, 0, 7, 12340); -- Dark Iron Legacy

UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=14096 AND `id`=2; -- You've Really Done It This Time, Kul
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=14096 AND `id`=1; -- You've Really Done It This Time, Kul
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=14096 AND `id`=0; -- You've Really Done It This Time, Kul
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=12527 AND `id`=4; -- Gluttonous Lurkers
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=12527 AND `id`=1; -- Gluttonous Lurkers
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=11587 AND `id`=2; -- Prison Break
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=11587 AND `id`=0; -- Prison Break
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=11255 AND `id`=1; -- Prisoners of Wyrmskull
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=11255 AND `id`=0; -- Prisoners of Wyrmskull
UPDATE `quest_poi` SET `Priority`=1, `VerifiedBuild`=12340 WHERE `QuestID`=12982 AND `id`=2; -- Ebon Blade Prisoners
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=12982 AND `id`=1; -- Ebon Blade Prisoners
UPDATE `quest_poi` SET `Priority`=2, `VerifiedBuild`=12340 WHERE `QuestID`=12982 AND `id`=0; -- Ebon Blade Prisoners

DELETE FROM `quest_poi_points` WHERE (`QuestID`=14112 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=14112 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=14112 AND `Idx1`=1 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(14112, 3, 0, 8609, 665, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 11, 9050, 1079, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 10, 8999, 1146, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 9, 8989, 1197, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 8, 8994, 1280, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 7, 9025, 1357, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 6, 9076, 1409, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 5, 9164, 1388, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 4, 9231, 1316, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 3, 9231, 1239, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 2, 9226, 1192, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 1, 9200, 1130, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 2, 0, 9148, 1084, 12340), -- What Do You Feed a Yeti, Anyway?
(14112, 1, 0, 9087, 1234, 12340); -- What Do You Feed a Yeti; Anyway?
DELETE FROM `quest_poi_points` WHERE `QuestID`=26012 AND `Idx1`=0 AND `Idx2`=0;
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(26012, 0, 0, 3529, 274, 12340); -- Trouble at Wyrmrest
DELETE FROM `quest_poi_points` WHERE (`QuestID`=3802 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=3802 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(3802, 1, 0, -7365, -1111, 12340), -- Dark Iron Legacy
(3802, 0, 0, -7359, -1115, 12340); -- Dark Iron Legacy

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=14112; -- What Do You Feed a Yeti, Anyway?
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=14017; -- The Black Knight's Fate
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13718; -- The Valiant's Charge
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=14409; -- A Cautious Return
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=13140; -- The Runesmiths of Malykriss

UPDATE `creature_model_info` SET `CombatReach`=3.299999952316284179 WHERE `DisplayID`=27065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.620000004768371582, `CombatReach`=2 WHERE `DisplayID`=27517;
UPDATE `creature_model_info` SET `BoundingRadius`=0.418500006198883056, `CombatReach`=1.35000002384185791 WHERE `DisplayID`=26351;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5 WHERE `DisplayID`=22347;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5 WHERE `DisplayID`=30619;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5 WHERE `DisplayID`=30620;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=1.5 WHERE `DisplayID`=30347;

UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=35102; -- Captain Elleane Wavecrest
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=35098; -- Wavecrest Mariner
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=34907; -- Kvaldir Harpooner
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=35092; -- Kvaldir Deepcaller
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=34925; -- North Sea Kraken
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=35090; -- Captain Aerthas Firehawk
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=35070; -- Firehawk Mariner
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=34947; -- Kvaldir Berserker
UPDATE `creature_template` SET `unit_flags`=33280 WHERE `entry`=34956; -- Kul the Reckless
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=35444; -- The Black Knight
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=38751; -- Black Knight Shield Proxy
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=35106; -- Black Knight Caster
UPDATE `creature_template` SET `unit_flags`=33280 WHERE `entry`=34716; -- Captive Aspirant
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=34810; -- CoD Eye Proxy
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=34728; -- Dark Zealot
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=34735; -- Black Knight's Grave
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=35467; -- Akiak
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=35462; -- Trag Highmountain
UPDATE `creature_template` SET `speed_run`=1.714285731315612792 WHERE `entry`=33513; -- Black Knight's Gryphon
UPDATE `creature_template` SET `BaseAttackTime`=1750, `HoverHeight`=4 WHERE `entry`=35474; -- Vengeful Val'kyr
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=32149; -- Fallen Hero's Spirit
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=37856; -- Flame Leviathan Image
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=28865; -- Ebon Watch Guardian
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=2570; -- Boulderfist Shaman
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=30 WHERE `entry`=2679; -- Wenna Silkbeard
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=1342; -- Mountaineer Rockgar
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=1343; -- Mountaineer Stormpike
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=1362; -- Gothor Brumn
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=1960; -- Pilot Hammerfoot
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=15127; -- Samuel Hawke
UPDATE `creature_template` SET `modelid1`=19188, `modelid2`=19187 WHERE `entry`=19178; -- Forsaken Commoner
UPDATE `creature_template` SET `modelid1`=28232, `modelid2`=3994 WHERE `entry`=2553; -- Witherbark Shadowcaster
UPDATE `creature_template` SET `maxlevel`=40 WHERE `entry`=2812; -- Drovnar Strongbrew
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=37861; -- XT-002 Deconstructor Image
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=26409; -- Rune-Smith Durar
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=26410; -- Rune-Smith Kathorn
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=26414; -- Runic Lightning Gunner
UPDATE `creature_template` SET `maxlevel`=75, `unit_flags`=32768 WHERE `entry`=26406; -- The Anvil
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=27177; -- Iron Rune Overseer
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=26347; -- Runic War Golem
UPDATE `creature_template` SET `modelid1`=28234, `modelid2`=3990 WHERE `entry`=2552; -- Witherbark Troll
UPDATE `creature_template` SET `modelid1`=28223, `modelid2`=3992 WHERE `entry`=2554; -- Witherbark Axe Thrower
UPDATE `creature_template` SET `modelid1`=28237, `modelid2`=3996 WHERE `entry`=2555; -- Witherbark Witch Doctor
UPDATE `creature_template` SET `modelid1`=28226, `modelid2`=3998 WHERE `entry`=2556; -- Witherbark Headhunter
UPDATE `creature_template` SET `modelid1`=28224, `modelid2`=4002 WHERE `entry`=2558; -- Witherbark Berserker
UPDATE `creature_template` SET `HealthModifier`=1.5 WHERE `entry`=2611; -- Fozruk
UPDATE `creature_template` SET `modelid2`=15253, `modelid3`=15252 WHERE `entry`=14991; -- League of Arathor Emissary
UPDATE `creature_template` SET `HealthModifier`=0.150000005960464477 WHERE `entry`=2764; -- Sleeby
UPDATE `creature_template` SET `HealthModifier`=0.150000005960464477 WHERE `entry`=2765; -- Znort
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=15126; -- Rutherford Twing
UPDATE `creature_template` SET `modelid2`=15286, `modelid3`=15285 WHERE `entry`=15128; -- Defiler Elite
UPDATE `creature_template` SET `HealthModifier`=0.150000005960464477 WHERE `entry`=4063; -- Feeboz
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=36479; -- Archmage Mordent Evenshade
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=36481; -- Sentinel Stillbough
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=38317; -- Tear Gas Target Stalker
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=37824; -- Abomination Wing Mad Scientist Stalker
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=36659; -- Abomination Wing Orange Gas Stalker
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=37013; -- Puddle Stalker
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=27118; -- Conquest Hold Raider
UPDATE `creature_template` SET `speed_run`=1.289682745933532714, `unit_flags`=32832, `VehicleId`=265 WHERE `entry`=31221; -- Bloodsunder
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=30953; -- Baelok
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30922; -- Umbral Brute
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=31255; -- Saronite Shaper
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30921; -- Skeletal Runesmith
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30920; -- Lumbering Atrocity
UPDATE `creature_template` SET `speed_run`=1.289682745933532714, `unit_flags`=32832, `VehicleId`=265 WHERE `entry`=31163; -- Icefury
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30894; -- Lithe Stalker
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30957; -- Death Knight Initiate
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=31042; -- Death Knight Adept
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=30956; -- Sapph
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30958; -- Death Knight Initiate
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=27947; -- Horde Commander
UPDATE `creature_template` SET `speed_run`=2 WHERE `entry`=29144; -- Refurbished Steam Tank
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=5492; -- Katherine the Pure
UPDATE `creature_template` SET `unit_flags`=64 WHERE `entry`=9030; -- Ok'thor the Breaker
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=26231; -- Saragosa
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=26265; -- Saragosa's End Invisman
UPDATE `creature_template` SET `unit_flags`=320 WHERE `entry`=26310; -- Malygos
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=26297; -- Voice of Keristrasza
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=27175; -- Transitus Shield Warmage
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=36155; -- Anzim Controller Bunny
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=5491; -- Arthur the Faithful
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=40436; -- Earthen Ring Pathfinder
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=8118; -- Lillian Singh
UPDATE `creature_template` SET `unit_class`=1 WHERE `entry`=5861; -- Twilight Fire Guard
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=24083; -- Enslaved Proto-Drake
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=23730; -- Harold Lagras
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24644; -- Harpoon Master Yavus
UPDATE `creature_template` SET `minlevel`=55 WHERE `entry`=24322; -- Ancient Citizen of Nifflevar
UPDATE `creature_template` SET `minlevel`=55 WHERE `entry`=24323; -- Ancient Citizen of Nifflevar
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=12336; -- Brother Crowley
UPDATE `creature_template` SET `HealthModifier`=1 WHERE `entry`=25743; -- Wooly Mammoth Bull
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=1351; -- Brother Cassius
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=1444; -- Brother Kristoff
UPDATE `creature_template` SET `modelid2`=15467, `modelid3`=8971 WHERE `entry`=15475; -- Beetle
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=5484; -- Brother Benjamin
UPDATE `creature_template` SET `type_flags`=0 WHERE `entry`=5489; -- Brother Joshua
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=40443; -- Earthen Ring Scout
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=34120; -- Brann's Flying Machine
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=1126 WHERE `entry`=33802; -- Focused Eyebeam Right
UPDATE `creature_template` SET `modelid2`=28575, `modelid3`=26442 WHERE `entry`=33346; -- XE-321 Boombot
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=1126 WHERE `entry`=33632; -- Focused Eyebeam
UPDATE `creature_template` SET `modelid1`=0, `modelid3`=29041 WHERE `entry`=34014; -- Sanctum Sentry
UPDATE `creature_template` SET `npcflag`=0, `unit_flags`=32768 WHERE `entry`=13839; -- Royal Dreadguard
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=5750; -- Gina Lang
UPDATE `creature_template` SET `modelid1`=10747, `modelid2`=11375, `modelid3`=7102 WHERE `entry`=16096; -- Steamwheedle Bruiser
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=23863; -- Daakara
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=23879; -- Amani Dragonhawk Spirit
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=23877; -- Amani Lynx Spirit
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=23880; -- Amani Eagle Spirit
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=23878; -- Amani Bear Spirit
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24241; -- Thurg
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24244; -- Gazakroth
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24247; -- Koragg
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24243; -- Lord Raadan
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24239; -- Hex Lord Malacrass
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24374; -- Amani'shi Berserker
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=24551; -- Eagle Event Deactivation Trigger
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24549; -- Amani'shi Tempest
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=23999; -- Harkor
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24175; -- Amani'shi Lookout
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24180; -- Amani'shi Protector
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=24223; -- Eagle Trash Aggro Trigger
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24138; -- Tamed Amani Crocolisk
UPDATE `creature_template` SET `minlevel`=70 WHERE `entry`=23581; -- Amani'shi Medicine Man
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=23576; -- Nalorakk
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=24358; -- Harrison Jones
UPDATE `creature_template` SET `maxlevel`=19 WHERE `entry`=23705; -- Catlord Corpse
UPDATE `creature_template` SET `maxlevel`=19 WHERE `entry`=23716; -- Hexxer Corpse
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=24404; -- Galathryn
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=24403; -- Deez
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=24406; -- Fudgerick
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=24858; -- Soaring Eagle
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=18130; -- Marshfang Ripper
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=16976; -- Ghostly Denizen
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30735; -- Kul Inkspiller
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=30722; -- Neferatti
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=3679; -- Naralex

UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14491; -- 14491
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14409; -- 14409
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14487; -- 14487
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14399; -- 14399
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=14335; -- 14335
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=11279; -- 11279
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=4401; -- 4401
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=8124; -- 8124
UPDATE `npc_text` SET `VerifiedBuild`=12340 WHERE `ID`=4841; -- 4841
