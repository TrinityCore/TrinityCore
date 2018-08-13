UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=10191;
UPDATE `areatrigger_template` SET `Flags`=1031, `VerifiedBuild`=26822 WHERE `Id`=10003;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=11231;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=9170;

DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=10191) ;
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5484, 10191, 1656, 0, 0, 0, 0, 5000, 5000, 26822); -- SpellId : 198898

DELETE FROM `spell_areatrigger_splines` WHERE (`SpellMiscId`=5484);
INSERT INTO `spell_areatrigger_splines` VALUES
(5484, 0, 2,  0, 0, 26822),
(5484, 1, 40, 0, 0, 26822);

UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=3827 AND `ConversationActorId`=55564 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26822 WHERE (`ConversationId`=3827 AND `ConversationActorId`=55564 AND `Idx`=0);

UPDATE `conversation_actor_template` SET `VerifiedBuild`=26822 WHERE `Id`=55564;

DELETE FROM `conversation_line_template` WHERE `Id` IN (5015, 5014, 1969, 1968, 1885, 1884, 1881, 1880, 1879, 1878, 1883, 1877, 1876, 3947, 1853, 8103, 6497, 6494, 6493, 2299, 2298, 2300, 6555, 2301, 6856, 6855, 6854, 7927);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(5015, 86550, 0, 0, 0, 26822),
(5014, 78750, 0, 3, 0, 26822),
(1969, 73900, 0, 0, 0, 26822),
(1968, 66600, 0, 3, 0, 26822),
(1885, 59250, 0, 0, 0, 26822),
(1884, 51350, 0, 1, 0, 26822),
(1881, 43200, 0, 3, 0, 26822),
(1880, 36000, 0, 0, 0, 26822),
(1879, 28650, 0, 1, 0, 26822),
(1878, 21800, 0, 3, 0, 26822),
(1883, 13150, 0, 2, 0, 26822),
(1877, 8350, 0, 1, 0, 26822),
(1876, 0, 0, 0, 0, 26822),
(3947, 9800, 0, 0, 8250, 26822),
(1853, 0, 0, 0, 0, 26822),
(8103, 17550, 0, 3, 0, 26822),
(6497, 13300, 0, 2, 0, 26822),
(6494, 6600, 0, 1, 0, 26822),
(6493, 0, 0, 0, 0, 26822),
(2299, 12450, 117103135, 4, 0, 26822),
(2298, 10300, 117103135, 3, 0, 26822),
(2300, 5950, 117103135, 2, 0, 26822),
(6555, 3150, 117103135, 1, 0, 26822),
(2301, 0, 117103135, 0, 0, 26822),
(6856, 12150, 28, 3, 0, 26822),
(6855, 8350, 28, 2, 0, 26822),
(6854, 5800, 28, 1, 0, 26822),
(7927, 0, 28, 0, 0, 26822);

UPDATE `conversation_line_template` SET `StartTime`=6094, `Unk`=0, `VerifiedBuild`=26822 WHERE `Id`=8610;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26822 WHERE `Id`=8609;

DELETE FROM `conversation_template` WHERE `Id` IN (3256, 3053, 787, 926, 782);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(3256, 7927, 16500, 26822),
(3053, 6493, 21350, 26822),
(787, 1876, 93750, 26822),
(926, 2301, 16050, 26822),
(782, 1853, 14600, 26822);

UPDATE `conversation_template` SET `LastLineEndTime`=16440, `VerifiedBuild`=26822 WHERE `Id`=3827;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278802 /*Weathered Supply Crate*/, 246707 /*Demon Portal*/, 246706 /*Demon Portal*/, 252303 /*Draenei First Aid Cot*/, 259041 /*Alliance Battleship*/, 250660 /*Alliance Battleship*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(278802, 0, 2121732), -- Weathered Supply Crate
(246707, 0, 262144), -- Demon Portal
(246706, 0, 262144), -- Demon Portal
(252303, 1375, 0), -- Draenei First Aid Cot
(259041, 0, 1048608), -- Alliance Battleship
(250660, 0, 1048608); -- Alliance Battleship

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=237733; -- Portal to Ashran
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=206319; -- Standing, Exterior, Large - MFF

DELETE FROM `scene_template` WHERE (`SceneId`=1445 AND `ScriptPackageID`=1722);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1445, 16, 1722);

DELETE FROM `creature_template_addon` WHERE `entry` IN (133704 /*133704 (High Elf Sorceress)*/, 25536 /*25536 ([DNT] Torch Tossing Target Bunny Controller)*/, 26188 /*26188 ([PH] Torch Catching Target Bunny)*/, 133433 /*133433 (Ghostblade Scout)*/, 133431 /*133431 (Lightforged Sunshield)*/, 18927 /*18927 (Human Commoner) - Gossip NPC Appearance - Midsummer, Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk*/, 100675 /*100675 (Jace Darkweaver)*/, 100428 /*100428 (Lady Jaina Proudmoore)*/, 133509 /*133509 (Riftwarden Acolyte)*/, 83890 /*83890 (Painting)*/, 83883 /*83883 (Peeps)*/, 83882 /*83882 (Brain)*/, 83878 /*83878 (Jennica Holzman)*/, 68980 /*68980 (Voidbinder Sturzah)*/, 66876 /*66876 (Tyler Stockton)*/, 101746 /*101746 (Lord Darius Crowley)*/, 110628 /*110628 (Stormwind Priest) - Global - Replace Stand With Ready1h (Spawn)*/, 110627 /*110627 (Gilnean Druid) - Global - Replace Stand With Ready1h (Spawn)*/, 101818 /*101818 (Gilnean Gryphon)*/, 100634 /*100634 (Gilnean Royal Guard)*/, 101708 /*101708 (Princess Tess Greymane)*/, 100696 /*100696 (Gilnean Gryphon)*/, 101709 /*101709 (Gilnean Gryphon)*/, 100395 /*100395 (Genn Greymane)*/, 101713 /*101713 (Commander Lorna Crowley)*/, 101747 /*101747 (Gilnean Footman)*/, 92461 /*92461 (El-ahrairah)*/, 97503 /*97503 (Stormwind Knight) - Sleep (Ultra-High Priority)*/, 97486 /*97486 (Gilnean Royal Guard) - Sleep (Ultra-High Priority)*/, 93219 /*93219 (Gilnean Royal Guard) - Sleep (Ultra-High Priority)*/, 91949 /*91949 (Gnomeregan Tinkerer) - Sleep (Ultra-High Priority)*/, 94209 /*94209 (Stormwind Knight) - Sleep (Ultra-High Priority)*/, 51348 /*51348 (Stormwind Gryphon Rider)*/, 68 /*68 (Stormwind City Guard)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(133704, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 133704 (High Elf Sorceress)
(25536, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 25536 ([DNT] Torch Tossing Target Bunny Controller)
(26188, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 26188 ([PH] Torch Catching Target Bunny)
(133433, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 133433 (Ghostblade Scout)
(133431, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 133431 (Lightforged Sunshield)
(18927, 0, 0, 0, 257, 0, 0, 0, 0, '65526 33209 33207 33208'), -- 18927 (Human Commoner) - Gossip NPC Appearance - Midsummer, Gossip NPC Periodic - Despawn, Gossip NPC Periodic - Fidget, Gossip NPC Periodic - Talk
(100675, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100675 (Jace Darkweaver)
(100428, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 100428 (Lady Jaina Proudmoore)
(133509, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 133509 (Riftwarden Acolyte)
(83890, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83890 (Painting)
(83883, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 83883 (Peeps)
(83882, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 83882 (Brain)
(83878, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 83878 (Jennica Holzman)
(68980, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 68980 (Voidbinder Sturzah)
(66876, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66876 (Tyler Stockton)
(101746, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101746 (Lord Darius Crowley)
(110628, 0, 0, 0, 1, 0, 0, 0, 0, '227771'), -- 110628 (Stormwind Priest) - Global - Replace Stand With Ready1h (Spawn)
(110627, 0, 0, 8, 1, 0, 0, 0, 0, '227771'), -- 110627 (Gilnean Druid) - Global - Replace Stand With Ready1h (Spawn)
(101818, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101818 (Gilnean Gryphon)
(100634, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100634 (Gilnean Royal Guard)
(101708, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101708 (Princess Tess Greymane)
(100696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100696 (Gilnean Gryphon)
(101709, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101709 (Gilnean Gryphon)
(100395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100395 (Genn Greymane)
(101713, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101713 (Commander Lorna Crowley)
(101747, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101747 (Gilnean Footman)
(92461, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 92461 (El-ahrairah)
(97503, 0, 0, 0, 1, 0, 0, 0, 0, '99480'), -- 97503 (Stormwind Knight) - Sleep (Ultra-High Priority)
(97486, 0, 0, 0, 1, 0, 0, 0, 0, '99480'), -- 97486 (Gilnean Royal Guard) - Sleep (Ultra-High Priority)
(93219, 0, 0, 0, 1, 0, 0, 0, 0, '99480'), -- 93219 (Gilnean Royal Guard) - Sleep (Ultra-High Priority)
(91949, 0, 0, 0, 1, 0, 0, 0, 0, '99480'), -- 91949 (Gnomeregan Tinkerer) - Sleep (Ultra-High Priority)
(94209, 0, 0, 0, 1, 0, 0, 0, 0, '99480'), -- 94209 (Stormwind Knight) - Sleep (Ultra-High Priority)
(51348, 0, 27913, 50331648, 257, 0, 0, 0, 0, ''), -- 51348 (Stormwind Gryphon Rider)
(68, 0, 2410, 0, 257, 0, 0, 0, 0, ''); -- 68 (Stormwind City Guard)

UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=16781; -- 16781 (Midsummer Celebrant)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='46794' WHERE `entry`=26221; -- 26221 (Earthen Ring Elder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=16817; -- 16817 (Festival Loremaster)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=26123; -- 26123 (Midsummer Supplier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=26258; -- 26258 ([DND] Midsummer Bonfire Faction Bunny - A)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=25975; -- 25975 (Master Fire Eater)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='45723 46901' WHERE `entry`=25535; -- 25535 ([DNT] Torch Tossing Target Bunny)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=89715; -- 89715 (Franklin Martin)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=54117; -- 54117 (Vin)
UPDATE `creature_template_addon` SET `auras`='46598 96850 16245' WHERE `entry`=52361; -- 52361 (Toy Cart Bunny)
UPDATE `creature_template_addon` SET `auras`='46598 96847' WHERE `entry`=52359; -- 52359 (Toy Cart)
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=61837; -- 61837 (Leria Nightwind)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=28347; -- 28347 (Miles Sidney)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=100974; -- 100974 (Aysa Cloudsinger)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=102554; -- 102554 (Muradin Bronzebeard)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=51938; -- 51938 (Crithto)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=88537; -- 88537 (Stormwind Mage)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=88535; -- 88535 (Stormwind Mage)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=100501; -- 100501 (Weary-Eyed Mourner)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=47688; -- 47688 (Officer Connelly)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=14423; -- 14423 (Officer Jaxon)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113211; -- 113211 (Officer Fairbanks)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=29152; -- 29152 (Stormwind Dock Worker)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (133433, 133431, 133509, 110628, 110627, 97503, 97486, 93219, 91949, 94209);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(133433, 110, 110, 0, 0, 26822),
(133431, 110, 110, 0, 0, 26822),
(133509, 110, 110, 0, 0, 26822),
(110628, 98, 110, 0, 0, 26822),
(110627, 98, 110, 0, 0, 26822),
(97503, 98, 110, 0, 0, 26822),
(97486, 98, 110, 0, 0, 26822),
(93219, 98, 110, 0, 0, 26822),
(91949, 98, 110, 0, 0, 26822),
(94209, 98, 110, 0, 0, 26822);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=100993;

UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3286;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1765;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1469;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4449;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=83235;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3316;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3291;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=8809;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72819;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1490;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72820;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=61734;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62529;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72817;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62530;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=24778;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1756;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=11747;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3302;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=11746;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37721;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27295;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1485;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3300;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27261;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16413;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=26822 WHERE `DisplayID`=23131;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16354;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1486;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16541;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1477;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1492;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5080;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34931;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1481;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=23792;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=32928;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5081;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=18627;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17612;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36656;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=10591;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3290;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3285;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=83231;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=61764;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1427;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5551;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36786;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1445;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=2148;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1438;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1446;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1439;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5552;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=19091;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=38626;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=22769;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=83230;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33303;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37850;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1544;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42276;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=2239;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42275;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=19670;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1697;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60316;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25319;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25336;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1510;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1522;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16412;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1511;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16433;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31269;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=15921;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33743;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1516;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3281;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3288;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4996;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1521;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1519;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1509;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=18055;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42279;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5000;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5728;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=18053;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42278;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42277;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=134;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26070;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63967;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63969;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63968;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=2961;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63522;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=18931;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5553;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63521;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=344;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1573;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1758;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16854;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33746;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33748;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5075;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31174;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33747;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33745;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=29515;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=29514;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=53832;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=55028;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=29796;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=15321;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5565;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5077;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=21072;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60791;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62748;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35095;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17822;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62092;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65199;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62751;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31658;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=32680;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=32681;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=41667;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=58776;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=59989;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=58786;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60470;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=29172;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60017;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34004;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34005;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=57180;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60540;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60409;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60468;
UPDATE `creature_model_info` SET `BoundingRadius`=0.389, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=61348;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60485;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60560;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=59184;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34116;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60607;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60011;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3519, `CombatReach`=1.725, `VerifiedBuild`=26822 WHERE `DisplayID`=60525;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=57429;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60041;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=61373;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=40027;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=61350;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=60544;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=57178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=57207;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=57155;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=58364;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3519, `CombatReach`=1.725, `VerifiedBuild`=26822 WHERE `DisplayID`=60528;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60014;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60557;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=59263;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=58682;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=57438;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1696;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=57424;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=61368;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1505;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7369064, `VerifiedBuild`=26822 WHERE `DisplayID`=60207;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=38422;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35774;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=39184;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=83236;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1423;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=11873;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33977;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34070;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33974;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=39532;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=338;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1447;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37087;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=14492;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33948;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=221;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=14472;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72724;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5586;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5448;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=257;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=58003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1524;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=8632;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=38420;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=38421;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=39809;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=38800;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=38804;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1498;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=47231;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5549;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1500;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3284;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=13049;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=251;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1499;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3289;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=7008;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=39501;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1501;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1503;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3282;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4885;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3283;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5548;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1495;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4887;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=262;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4626;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25943;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1418;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73080;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3819442, `CombatReach`=1.65, `VerifiedBuild`=26822 WHERE `DisplayID`=73077;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3819442, `CombatReach`=1.65, `VerifiedBuild`=26822 WHERE `DisplayID`=73078;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67315;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=47035;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73079;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=53598;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63732;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63733;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63730;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34889;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34881;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62093;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34520;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=63731;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4054662, `VerifiedBuild`=26822 WHERE `DisplayID`=25850;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73174;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73089;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72228;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=73179;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73178;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73173;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72227;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=73090;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=32939;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5005;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37311;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37310;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25851;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=21342;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25845;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25848;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5006;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25899;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5008;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3167;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25847;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25898;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5446;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1141;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25846;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=133433 AND `ID`=1) OR (`CreatureID`=133431 AND `ID`=1) OR (`CreatureID`=100675 AND `ID`=1) OR (`CreatureID`=100428 AND `ID`=1) OR (`CreatureID`=68 AND `ID`=2) OR (`CreatureID`=101746 AND `ID`=1) OR (`CreatureID`=100634 AND `ID`=1) OR (`CreatureID`=100395 AND `ID`=1) OR (`CreatureID`=101713 AND `ID`=1) OR (`CreatureID`=101747 AND `ID`=1) OR (`CreatureID`=97503 AND `ID`=1) OR (`CreatureID`=91949 AND `ID`=1) OR (`CreatureID`=94209 AND `ID`=1) OR (`CreatureID`=29016 AND `ID`=3);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(133433, 1, 1511, 0, 0, 0, 0, 0, 0, 0, 0), -- Ghostblade Scout
(133431, 1, 0, 0, 0, 42557, 0, 0, 0, 0, 0), -- Lightforged Sunshield
(100675, 1, 128360, 0, 0, 128370, 0, 0, 0, 0, 0), -- Jace Darkweaver
(100428, 1, 2177, 0, 0, 0, 0, 0, 0, 0, 0), -- Lady Jaina Proudmoore
(68, 2, 2715, 0, 0, 143, 0, 0, 2551, 0, 0), -- Stormwind City Guard
(101746, 1, 54877, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Darius Crowley
(100634, 1, 5305, 0, 0, 1984, 0, 0, 2551, 0, 0), -- Gilnean Royal Guard
(100395, 1, 46737, 0, 0, 0, 0, 0, 0, 0, 0), -- Genn Greymane
(101713, 1, 30147, 0, 0, 61512, 0, 0, 110180, 0, 0), -- Commander Lorna Crowley
(101747, 1, 65492, 0, 0, 111717, 0, 0, 0, 0, 0), -- Gilnean Footman
(97503, 1, 1899, 0, 0, 117413, 0, 0, 0, 0, 0), -- Stormwind Knight
(91949, 1, 0, 0, 0, 0, 0, 0, 59367, 0, 0), -- Gnomeregan Tinkerer
(94209, 1, 1899, 0, 0, 117413, 0, 0, 0, 0, 0), -- Stormwind Knight
(29016, 3, 31824, 0, 0, 0, 0, 0, 0, 0, 0); -- Steam Tank Engineer

UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=55684 AND `ID`=1); -- Jordan Smith
UPDATE `creature_equip_template` SET `ItemID1`=2715 WHERE (`CreatureID`=1976 AND `ID`=1); -- Stormwind City Patroller
UPDATE `creature_equip_template` SET `ItemID1`=1911 WHERE (`CreatureID`=29016 AND `ID`=2); -- Steam Tank Engineer
UPDATE `creature_equip_template` SET `ItemID1`=1902 WHERE (`CreatureID`=29152 AND `ID`=1); -- Stormwind Dock Worker
UPDATE `creature_equip_template` SET `ItemID1`=1903 WHERE (`CreatureID`=29016 AND `ID`=1); -- Steam Tank Engineer

DELETE FROM `gossip_menu` WHERE (`MenuId`=19075 AND `TextId`=27884) OR (`MenuId`=19134 AND `TextId`=28003);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(19075, 27884), -- 100429 (Anduin Wrynn)
(19134, 28003); -- 100675 (Jace Darkweaver)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=19075 AND `OptionIndex`=0) OR (`MenuId`=19134 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(19075, 0, 0, 'I come bearing a letter from your father.', 102376),
(19134, 0, 0, 'Show me the proof.', 0); -- OptionBroadcastTextID: 103146 - 103351

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=19134 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(19134, 0, 19134, 0);


UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=1733; -- Zggi
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=9584; -- Jalane Ayrole
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=101004; -- Elerion Bladedancer
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=109912; -- Captive Wyrmtongue
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=84, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133704; -- High Elf Sorceress
UPDATE `creature_template` SET `npcflag`=2, `RangeAttackTime`=2000 WHERE `entry`=11827; -- Kimberly Grant
UPDATE `creature_template` SET `npcflag`=2, `RangeAttackTime`=2000 WHERE `entry`=11828; -- Kelly Grant
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=5504; -- Sheldras Moontree
UPDATE `creature_template` SET `npcflag`=80 WHERE `entry`=30713; -- Catarina Stanford
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=53, `faction`=1733, `npcflag`=0, `unit_flags`=33280 WHERE `entry`=16781; -- Midsummer Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=0, `faction`=1732 WHERE `entry`=26221; -- Earthen Ring Elder
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16817; -- Festival Loremaster
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62 WHERE `entry`=26123; -- Midsummer Supplier
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=1317; -- Lucan Cordell
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=26258; -- [DND] Midsummer Bonfire Faction Bunny - A
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=46180; -- Ithurian Whitespire
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=62, `maxlevel`=62 WHERE `entry`=25975; -- Master Fire Eater
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=50432; -- Deva Marie
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=84, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133433; -- Ghostblade Scout
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=89715; -- Franklin Martin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=37944; -- Stormwind City Patroller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=54117; -- Vin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=84, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133431; -- Lightforged Sunshield
UPDATE `creature_template` SET `speed_walk`=0.4 WHERE `entry`=52359; -- Toy Cart
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1733 WHERE `entry`=87501; -- Paulie
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags`=32768 WHERE `entry`=18927; -- Human Commoner
UPDATE `creature_template` SET `maxlevel`=23 WHERE `entry`=42421; -- Stormwind Fisherman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `unit_flags3`=8192 WHERE `entry`=100754; -- Stormwind Royal Guard
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100981; -- Prophet Velen
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=1.142857 WHERE `entry`=100977; -- Malfurion Stormrage
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100974; -- Aysa Cloudsinger
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100975; -- Falstad Wildhammer
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=1.142857 WHERE `entry`=100973; -- Anduin Wrynn
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100978; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=1.142857 WHERE `entry`=100980; -- Tyrande Whisperwind
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `npcflag`=2 WHERE `entry`=100979; -- Moira Thaurissan
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=101055; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=102554; -- Muradin Bronzebeard
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=100993; -- Felblade Assassin
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93296; -- Coffee
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=93307; -- Rygarius
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=51938; -- Crithto
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=34998; -- Alison Devay
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=34997; -- Devin Fardale
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=15187; -- Cenarion Emissary Jademoon
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=2 WHERE `entry`=1750; -- Grand Admiral Jes-Tereth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=1756; -- Stormwind Royal Guard
UPDATE `creature_template` SET `gossip_menu_id`=19134, `minlevel`=100, `maxlevel`=100, `faction`=2784, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100675; -- Jace Darkweaver
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=1819, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100428; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=1.142857 WHERE `entry`=100457; -- Malfurion Stormrage
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100460; -- Prophet Velen
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=1.142857 WHERE `entry`=100458; -- Tyrande Whisperwind
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `speed_run`=1.142857 WHERE `entry`=100429; -- Anduin Wrynn
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100454; -- Muradin Bronzebeard
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100471; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100455; -- Moira Thaurissan
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=100456; -- Falstad Wildhammer
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=87503; -- Champion's Treadblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=47688; -- Officer Connelly
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=84, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133509; -- Riftwarden Acolyte
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=44582; -- Theresa Denman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=14438; -- Officer Pomeroy
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=14423; -- Officer Jaxon
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=113211; -- Officer Fairbanks
UPDATE `creature_template` SET `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=83890; -- Painting
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=83883; -- Peeps
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `faction`=35, `unit_flags2`=2048 WHERE `entry`=83882; -- Brain
UPDATE `creature_template` SET `minlevel`=61, `maxlevel`=61, `unit_flags2`=2048 WHERE `entry`=83878; -- Jennica Holzman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=1976; -- Stormwind City Patroller
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=3 WHERE `entry`=53626; -- Stormwind Orphan
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=14496; -- Stormwind Orphan
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=57800; -- Thaumaturge Rafir
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=54443; -- Vaultkeeper Razhid
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=54442; -- Warpweaver Hashom
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=1350; -- Theresa Moulaine
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=4294967296, `unit_class`=8, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=68980; -- Voidbinder Sturzah
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=512 WHERE `entry`=1444; -- Brother Kristoff
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=1349; -- Agustus Moulaine
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=5491; -- Arthur the Faithful
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=51081; -- Nathan Stockton
UPDATE `creature_template` SET `RangeAttackTime`=2000 WHERE `entry`=12336; -- Brother Crowley
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction`=12, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=66876; -- Tyler Stockton
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3, `RangeAttackTime`=2000 WHERE `entry`=928; -- Lord Grayson Shadowbreaker
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=5492; -- Katherine the Pure
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=56796; -- Angela Leifeld
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=1351; -- Brother Cassius
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=1348; -- Gregory Ardus
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=1 WHERE `entry`=5484; -- Brother Benjamin
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=5489; -- Brother Joshua
UPDATE `creature_template` SET `gossip_menu_id`=0, `RangeAttackTime`=2000 WHERE `entry`=1212; -- Bishop Farthing
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3, `RangeAttackTime`=2000 WHERE `entry`=376; -- High Priestess Laurena
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=29154; -- Thargold Ironwing
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101746; -- Lord Darius Crowley
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=110628; -- Stormwind Priest
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `speed_walk`=1.2, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=110627; -- Gilnean Druid
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=84, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4511 WHERE `entry`=101818; -- Gilnean Gryphon
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=1819, `speed_walk`=1.2, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=100634; -- Gilnean Royal Guard
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=1732, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101708; -- Princess Tess Greymane
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=84, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4511 WHERE `entry`=100696; -- Gilnean Gryphon
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=84, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=4511 WHERE `entry`=101709; -- Gilnean Gryphon
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100395; -- Genn Greymane
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106, `faction`=2164, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101713; -- Commander Lorna Crowley
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2165, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=101747; -- Gilnean Footman
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=92461; -- El-ahrairah
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=97503; -- Stormwind Knight
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `npcflag`=17179869184, `speed_walk`=1.2, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=97486; -- Gilnean Royal Guard
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `npcflag`=17179869184, `speed_walk`=1.2, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=93219; -- Gilnean Royal Guard
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=91949; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=2879, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200, `unit_flags3`=32 WHERE `entry`=94209; -- Stormwind Knight
UPDATE `creature_template` SET `minlevel`=2 WHERE `entry`=43102; -- Rock Lobster
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=51348; -- Stormwind Gryphon Rider
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1.142857 WHERE `entry`=68; -- Stormwind City Guard
UPDATE `creature_template` SET `faction`=1078, `npcflag`=0 WHERE `entry`=29152; -- Stormwind Dock Worker
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=29712; -- Stormwind Harbor Guard

SET @GROUP_ID := 0;
SET @ID := 0;

INSERT IGNORE INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(100675, @GROUP_ID+0, @ID+0, 'Say the word and I shall reveal the enemy!', 12, 0, 100, 0, 0, 0, 122115, 'Jace Darkweaver to Player'),
(100993, @GROUP_ID+0, @ID+0, 'This world will... perish...', 12, 0, 100, 0, 0, 0, 101192, 'Felblade Assassin to Player'),
(100993, @GROUP_ID+1, @ID+0, 'Your soul will burn!', 12, 0, 100, 0, 0, 0, 101191, 'Felblade Assassin to Player'),
(100993, @GROUP_ID+2, @ID+0, 'We are... infinite...', 12, 0, 100, 0, 0, 0, 101193, 'Felblade Assassin to Player');

INSERT IGNORE INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(52359, 52361, 0, 0, 'Toy Cart - Toy Cart Bunny', 0, 0); -- Toy Cart - Toy Cart Bunny

INSERT IGNORE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(29152, 83580, 0, 0),
(100696, 200569, 0, 0),
(42339, 78974, 0, 0);


UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=113986; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=113404; -- Illidari Darkdealer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93223; -- Generic Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5504; -- Sheldras Moontree
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1316; -- Adair Gilroy
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=26221; -- Earthen Ring Elder
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=26258; -- [DND] Midsummer Bonfire Faction Bunny - A
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=17066; -- Ribbon Pole Debug Target
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5493; -- Arnold Leland
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=50424; -- Terran "Justice" Gregory
UPDATE `creature_template` SET `type_flags`=0, `VerifiedBuild`=26822 WHERE `entry`=54026; -- Dotty
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=12, `movementId`=121, `VerifiedBuild`=26822 WHERE `entry`=40624; -- Celestial Dragon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=61837; -- Leria Nightwind
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=28347; -- Miles Sidney
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18927; -- Human Commoner
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=42339; -- Canal Crab
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44237; -- Maegan Tillman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5482; -- Stephen Ryback
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1328; -- Elly Langston
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=6090; -- Bartleby
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1412; -- Squirrel
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100974; -- Aysa Cloudsinger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100981; -- Prophet Velen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100979; -- Moira Thaurissan
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1752; -- Caledra Dawnbreeze
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93296; -- Coffee
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=24729; -- Alicia
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44243; -- Darnella Winford
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44238; -- Harrison Jones
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=15187; -- Cenarion Emissary Jademoon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1750; -- Grand Admiral Jes-Tereth
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100457; -- Malfurion Stormrage
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=58167; -- Colton Smith
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=2795; -- Lenny "Fingers" McCoy
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=56925; -- Farrah Facet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44583; -- Terrance Denman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29142; -- Jelinek Sharpshear
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=83890; -- Painting
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14497; -- Shellene
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=68980; -- Voidbinder Sturzah
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1444; -- Brother Kristoff
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=66876; -- Tyler Stockton
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1348; -- Gregory Ardus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5484; -- Brother Benjamin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1212; -- Bishop Farthing
UPDATE `creature_template` SET `family`=0, `type`=7, `VerifiedBuild`=26822 WHERE `entry`=376; -- High Priestess Laurena
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49540; -- Stormwind Rat
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29154; -- Thargold Ironwing
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100634; -- Gilnean Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=92461; -- El-ahrairah
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=101818; -- Gilnean Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97503; -- Stormwind Knight
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100429; -- Anduin Wrynn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=32520; -- Totally Generic Bunny (All Phase)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29019; -- Dockhand
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29712; -- Stormwind Harbor Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29016; -- Steam Tank Engineer
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=26822 WHERE `entry`=29152; -- Stormwind Dock Worker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=65011; -- Albino Riding Crane
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=48632; -- Golden King
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18362; -- Swift Purple Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=9158; -- Warhorse
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62106; -- Great Red Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=461; -- Demisette Cloyce
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=9584; -- Jalane Ayrole
UPDATE `creature_template` SET `HealthModifier`=15, `VerifiedBuild`=26822 WHERE `entry`=113392; -- Illidari Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=297; -- Caretaker Folsom
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=11828; -- Kelly Grant
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=30730; -- Stanly McCormick
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=52031; -- Sarana Damir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1315; -- Allan Hafgan
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=25536; -- [DNT] Torch Tossing Target Bunny Controller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=16817; -- Festival Loremaster
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=26188; -- [PH] Torch Catching Target Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49701; -- Bario Matalli
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5494; -- Catherine Leland
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1427; -- Harlan Bagley
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1291; -- Carla Granger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1295; -- Lara Moore
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1297; -- Lina Stover
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=53527; -- Prisoner
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133431; -- Lightforged Sunshield
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=52359; -- Toy Cart
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3520; -- Ol' Emma
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1319; -- Bryan Cross
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=822; -- Young Forest Bear
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=6089; -- Harry Burlguard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1478; -- Aedis Brom
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=42421; -- Stormwind Fisherman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=121541; -- Ban-Lu
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100978; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100993; -- Felblade Assassin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1439; -- Lord Baurles K. Wishock
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=2285; -- Count Remington Ridgewell
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44241; -- Lana Dubing
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=34997; -- Devin Fardale
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1756; -- Stormwind Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101858; -- Jace Darkweaver
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100454; -- Muradin Bronzebeard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100456; -- Falstad Wildhammer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100449; -- Stormwind Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3629; -- David Langston
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=53641; -- Allison Potts
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1367; -- Billy
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=50480; -- Isabel Jones
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44582; -- Theresa Denman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1371; -- Roman
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `family`=0, `VerifiedBuild`=26822 WHERE `entry`=83882; -- Brain
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1405; -- Morris Lawry
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14496; -- Stormwind Orphan
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=57800; -- Thaumaturge Rafir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=54442; -- Warpweaver Hashom
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1349; -- Agustus Moulaine
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=51081; -- Nathan Stockton
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=56796; -- Angela Leifeld
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=7917; -- Brother Sarno
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=6171; -- Duthorian Rall
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=6173; -- Gazin Tenorm
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101708; -- Princess Tess Greymane
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93219; -- Gilnean Royal Guard
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=101819; -- Gilnean Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=4075; -- Rat
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=33030; -- Magnificent Flying Carpet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=65078; -- Great Purple Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=39208; -- Exarch's Elekk
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=32206; -- Armored Brown Bear
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18406; -- Swift Blue Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=30542; -- Rivendare's Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=305; -- White Stallion
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1733; -- Zggi
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5520; -- Spackle Thornberry
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1305; -- Jarel Moor
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109912; -- Captive Wyrmtongue
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133704; -- High Elf Sorceress
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5506; -- Maldryn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=26123; -- Midsummer Supplier
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=338; -- Mazen Mac'Nadir
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=25975; -- Master Fire Eater
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=25535; -- [DNT] Torch Tossing Target Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=89715; -- Franklin Martin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=37944; -- Stormwind City Patroller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=54117; -- Vin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3626; -- Jenn Langston
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=28355; -- Wright Williams
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1333; -- Gerik Koen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5483; -- Erika Tate
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1477; -- Christoph Faral
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=61841; -- Brunn Goldenmug
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=61839; -- Lucas Severing
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=114562; -- Khadgar's Upgraded Servant
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101004; -- Elerion Bladedancer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100399; -- Magus Solgaze
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100754; -- Stormwind Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5806; -- Treant Ally
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100975; -- Falstad Wildhammer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100973; -- Anduin Wrynn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101055; -- Jace Darkweaver
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=4960; -- Bishop DeLavey
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=2504; -- Donyal Tovald
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1440; -- Milton Sheaf
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=93307; -- Rygarius
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=51938; -- Crithto
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=34998; -- Alison Devay
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88535; -- Stormwind Mage
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1751; -- Mithras Ironhill
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100428; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111600; -- Stormwind Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100458; -- Tyrande Whisperwind
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100471; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=55684; -- Jordan Smith
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133509; -- Riftwarden Acolyte
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1370; -- Brandon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44773; -- Anastasia
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14438; -- Officer Pomeroy
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=83883; -- Peeps
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=83878; -- Jennica Holzman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1976; -- Stormwind City Patroller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1350; -- Theresa Moulaine
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=12336; -- Brother Crowley
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5491; -- Arthur the Faithful
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1351; -- Brother Cassius
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=4982; -- Thomas
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=721; -- Rabbit
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101746; -- Lord Darius Crowley
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=110627; -- Gilnean Druid
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101713; -- Commander Lorna Crowley
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=101709; -- Gilnean Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97486; -- Gilnean Royal Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=94209; -- Stormwind Knight
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100395; -- Genn Greymane
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=51348; -- Stormwind Gryphon Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29929; -- Mechano-Hog
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31694; -- Azure Drake Mount
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29582; -- Winged Steed of the Ebon Blade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=28302; -- Acherus Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14565; -- Charger
UPDATE `creature_template` SET `family`=0, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=307; -- Pinto
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5496; -- Sandahl
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1435; -- Zardeth of the Black Claw
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5495; -- Ursula Deline
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95791; -- Falara Nightsong
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=11827; -- Kimberly Grant
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=30713; -- Catarina Stanford
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=16781; -- Midsummer Celebrant
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1312; -- Ardwyn Cailen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1317; -- Lucan Cordell
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=16592; -- Midsummer Bonfire
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1318; -- Jessara Cordell
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=108568; -- Pygmy Owl
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=46180; -- Ithurian Whitespire
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5386; -- Acolyte Dellis
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=42288; -- Robby Flay
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49893; -- Lisa McKeever
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=11068; -- Betty Quin
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26822 WHERE `entry`=71021; -- Lesser Voidcaller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=416; -- Imp
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=131074; -- Lightforged Talbuk
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=50432; -- Deva Marie
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133433; -- Ghostblade Scout
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1298; -- Frederick Stover
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1402; -- Topper McNabb
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1428; -- Rema Schneider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=52361; -- Toy Cart Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=52358; -- Craggle Wobbletop
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=61838; -- Gavin Marlsbury
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=87501; -- Paulie
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1339; -- Mayda Thane
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62954; -- Stormwind Rat
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=54027; -- Lil' Tarecgosa
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1327; -- Reese Langston
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=340; -- Kendor Kabonka
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=61840; -- Naanae
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=6740; -- Innkeeper Allison
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100977; -- Malfurion Stormrage
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100980; -- Tyrande Whisperwind
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=102554; -- Muradin Bronzebeard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111190; -- "The Imposter" Quest SI:7 Courtyard Reached Kill Credit & POI Marker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44239; -- Janric Moller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=17103; -- Emissary Taluun
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=35365; -- Behsten
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88537; -- Stormwind Mage
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=38821; -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100675; -- Jace Darkweaver
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100460; -- Prophet Velen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100455; -- Moira Thaurissan
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100472; -- Aysa Cloudsinger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100501; -- Weary-Eyed Mourner
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=87503; -- Champion's Treadblade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47688; -- Officer Connelly
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1366; -- Adam
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1294; -- Aldric Moore
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1299; -- Lisbeth Schneider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44774; -- Genevieve
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1368; -- Justin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14423; -- Officer Jaxon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=113211; -- Officer Fairbanks
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=53626; -- Stormwind Orphan
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=54443; -- Vaultkeeper Razhid
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=928; -- Lord Grayson Shadowbreaker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5492; -- Katherine the Pure
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5489; -- Brother Joshua
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=110628; -- Stormwind Priest
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101747; -- Gilnean Footman
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=100696; -- Gilnean Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=61366; -- Rat
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=91949; -- Gnomeregan Tinkerer
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=26822 WHERE `entry`=43102; -- Rock Lobster
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29088; -- Stormwind Cannoneer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=68; -- Stormwind City Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=77178; -- Dread Raven
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=40725; -- X-53 Touring Rocket
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=32633; -- Traveler's Tundra Mammoth
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=26822 WHERE `entry`=18376; -- Swift Red Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=304; -- Felsteed

DELETE FROM `gameobject_template` WHERE `entry` IN (250660 /*Alliance Battleship*/, 259041 /*Alliance Battleship*/, 278802 /*Weathered Supply Crate*/, 252303 /*Draenei First Aid Cot*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(250660, 43, 12843, 'Alliance Battleship', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Alliance Battleship
(259041, 43, 12843, 'Alliance Battleship', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Alliance Battleship
(278802, 3, 335, 'Weathered Supply Crate', 'questinteract', 'Opening', '', 1, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 79218, 1, 0, 0, 26822), -- Weathered Supply Crate
(252303, 5, 22759, 'Draenei First Aid Cot', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822); -- Draenei First Aid Cot

UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197043; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197042; -- Wooden Chair
UPDATE `gameobject_template` SET `type`=9, `displayId`=19417, `IconName`='inspect', `Data0`=6771, `Data2`=1, `VerifiedBuild`=26822 WHERE `entry`=266152; -- Crumpled Note
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197037; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197035; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197033; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197015; -- The Slaughtered Lamb
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245923; -- Book
UPDATE `gameobject_template` SET `name`='Book', `VerifiedBuild`=26822 WHERE `entry`=243305; -- Book
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=254068; -- Rug
UPDATE `gameobject_template` SET `name`='Satchel', `VerifiedBuild`=26822 WHERE `entry`=254085; -- Satchel
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243295; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197011; -- Stormwind Staves
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254109; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197026; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197031; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=188174; -- Midsummer Music Doodad
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197023; -- Wooden Chair
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=26822 WHERE `entry`=181605; -- Ribbon Pole
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=187708; -- Torch Target Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197139; -- Old Town
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202010; -- Cathedral Square
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197193; -- Highback Chair
UPDATE `gameobject_template` SET `Data0`=2, `Data2`=7810, `VerifiedBuild`=26822 WHERE `entry`=197189; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202028; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202026; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=188020; -- Camp Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201491; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201508; -- Command Center
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201495; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201510; -- SI:7
UPDATE `gameobject_template` SET `Data1`=29952, `VerifiedBuild`=26822 WHERE `entry`=203762; -- Juicy Apple
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201511; -- Old Town
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201512; -- Old Town
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201542; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201544; -- Warm Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201532; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201534; -- Wooden Chair
UPDATE `gameobject_template` SET `Data1`=29958, `VerifiedBuild`=26822 WHERE `entry`=203800; -- Barrel of Canal Fish
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201676; -- Wooden Bench
UPDATE `gameobject_template` SET `name`='Ship, Icebreaker (Stormwind''s Pride)', `VerifiedBuild`=26822 WHERE `entry`=190536; -- Ship, Icebreaker (Stormwind's Pride)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201674; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201684; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=2657; -- Legends of the Earth
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201646; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201691; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201659; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201647; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201677; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201843; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175735; -- The Guardians of Tirisfal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201690; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201665; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206110; -- Portal to Moonglade
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175745; -- The Dark Portal and the Fall of Stormwind
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175753; -- War of the Spider
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201666; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201661; -- Highback Chair
UPDATE `gameobject_template` SET `name`='Varian''s Coffin', `VerifiedBuild`=26822 WHERE `entry`=245640; -- Varian's Coffin
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201500; -- The Silver Shield
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201987; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=209692; -- Potts' Plates
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=209039; -- The Shady Lady
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181401; -- Hanging, Streamer x3 - MFF
UPDATE `gameobject_template` SET `Data1`=30795, `VerifiedBuild`=26822 WHERE `entry`=204284; -- Stormwind Lobster Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206319; -- Standing, Exterior, Large - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197040; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197038; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197036; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197034; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197086; -- Stone Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254113; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197020; -- The Park
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243324; -- Table
UPDATE `gameobject_template` SET `name`='Cauldron', `VerifiedBuild`=26822 WHERE `entry`=253168; -- Cauldron
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243294; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243301; -- Ward
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254107; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254123; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254110; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254118; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197030; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197029; -- Wooden Chair
UPDATE `gameobject_template` SET `displayId`=39476, `Data0`=1964, `Data26`=1, `VerifiedBuild`=26822 WHERE `entry`=181332; -- Flame of Stormwind
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=207661; -- Cookpot
UPDATE `gameobject_template` SET `Data1`=5429, `VerifiedBuild`=26822 WHERE `entry`=140911; -- Spool of Light Chartreuse Silk Thread
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197022; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197136; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197122; -- Lionheart Armory
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197192; -- Highback Chair
UPDATE `gameobject_template` SET `Data0`=2, `Data2`=7810, `VerifiedBuild`=26822 WHERE `entry`=197188; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202025; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197187; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201514; -- Old Town
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201522; -- Trade District
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201490; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201493; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201494; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201496; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201507; -- Command Center
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201488; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201523; -- Stormwind Keep
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201422; -- Dwarven District
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201530; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201540; -- Wooden Chair
UPDATE `gameobject_template` SET `Data1`=29959, `VerifiedBuild`=26822 WHERE `entry`=203801; -- Sack of Confectioner's Sugar
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201531; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201524; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201528; -- Wooden Chair
UPDATE `gameobject_template` SET `type`=10, `displayId`=30007, `castBarCaption`='Destroying', `size`=0.33, `Data0`=99, `Data14`=24585, `Data20`=1, `Data26`=1, `VerifiedBuild`=26822 WHERE `entry`=246707; -- Demon Portal
UPDATE `gameobject_template` SET `Data1`=-1, `VerifiedBuild`=26822 WHERE `entry`=207416; -- Waters of Farseeing
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=180665; -- Draconic for Dummies
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201656; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201694; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201692; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201648; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201675; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=21581; -- Aftermath of the Second War
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175746; -- The Alliance of Lordaeron
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201641; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201655; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201650; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201653; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201668; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201822; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201521; -- Mailbox
UPDATE `gameobject_template` SET `name`='Large Wreath', `VerifiedBuild`=26822 WHERE `entry`=245687; -- Large Wreath
UPDATE `gameobject_template` SET `displayId`=14650, `VerifiedBuild`=26822 WHERE `entry`=1684; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201981; -- The Argent Dawn
UPDATE `gameobject_template` SET `name`='Portal to Blasted Lands', `VerifiedBuild`=26822 WHERE `entry`=235882; -- Portal to Blasted Lands
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=209297; -- The Three Winds
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201982; -- Just Maces
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181392; -- Hanging, Streamer - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181393; -- Hanging, Tall/Thin, Medium - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=212212; -- Legacy of the Masters (Part 1)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197039; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197088; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197096; -- Mage Quarter
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254112; -- Bench
UPDATE `gameobject_template` SET `name`='Supplies', `VerifiedBuild`=26822 WHERE `entry`=254080; -- Supplies
UPDATE `gameobject_template` SET `name`='Weapon Rack', `VerifiedBuild`=26822 WHERE `entry`=254081; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243300; -- Crate
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254115; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254111; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254122; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197027; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=193981; -- Lexicon of Power
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197024; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181302; -- Camp Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175729; -- Mount Hyjal and Illidan's Gift
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181388; -- Standing, Interior, Medium - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197021; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=35591; -- Fishing Bobber
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201997; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197138; -- Cathedral Square
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202027; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202023; -- Wooden Chair
UPDATE `gameobject_template` SET `Data0`=2, `Data2`=7810, `VerifiedBuild`=26822 WHERE `entry`=197190; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=188021; -- Camp Pavilion
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201492; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201509; -- SI:7
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201497; -- The Five Deadly Venoms
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201538; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201541; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=266354; -- Basic Campfire
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201543; -- Warm Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201525; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201533; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201527; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201680; -- Wooden Bench
UPDATE `gameobject_template` SET `name`='Ship (The Bravery)', `VerifiedBuild`=26822 WHERE `entry`=176310; -- Ship (The Bravery)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201679; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201645; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201683; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201657; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=21582; -- Beyond the Dark Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201685; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201678; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175752; -- The New Horde
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=21583; -- The Kaldorei and the Well of Eternity
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201671; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201682; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201649; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201689; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201651; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175750; -- The Battle of Grim Batol
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201652; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201662; -- Highback Chair
UPDATE `gameobject_template` SET `name`='Collision Wall', `VerifiedBuild`=26822 WHERE `entry`=259880; -- Collision Wall
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201504; -- Pig and Whistle Tavern
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201503; -- Thane's Boots
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206623; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197126; -- Canal Tailor and Fit Shop
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201980; -- City Hall
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202003; -- Uther the Lightbringer
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181391; -- Standing, Interior, Small - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=187653; -- Standing, Post - MFF
UPDATE `gameobject_template` SET `type`=8, `name`='Midsummer Brazier', `Data0`=4, `Data1`=10, `VerifiedBuild`=26822 WHERE `entry`=181355; -- Midsummer Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197041; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197087; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197010; -- Pyrotechnics
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=1561; -- Sealed Crate
UPDATE `gameobject_template` SET `name`='Scroll', `VerifiedBuild`=26822 WHERE `entry`=243297; -- Scroll
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=253169; -- Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=252281; -- Supplies
UPDATE `gameobject_template` SET `name`='Glaive', `VerifiedBuild`=26822 WHERE `entry`=254086; -- Glaive
UPDATE `gameobject_template` SET `name`='Table', `VerifiedBuild`=26822 WHERE `entry`=254082; -- Table
UPDATE `gameobject_template` SET `name`='Satchel', `VerifiedBuild`=26822 WHERE `entry`=254084; -- Satchel
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243299; -- Banner
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254116; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254114; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254108; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197097; -- Mage Quarter
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254117; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197025; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197028; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181305; -- Camp Table
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175758; -- Archimonde's Return and the Flight to Kalimdor
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197018; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=205553; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201996; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197123; -- The Empty Quiver
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202005; -- Cathedral Square
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202004; -- Cathedral Square
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197191; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202006; -- Cathedral Square
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202024; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201506; -- Champions' Hall
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201489; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201505; -- Champions' Hall
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201539; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201537; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201529; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201526; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201536; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201535; -- Wooden Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201686; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201673; -- Wooden Bench
UPDATE `gameobject_template` SET `type`=10, `displayId`=30007, `castBarCaption`='Destroying', `size`=0.33, `Data0`=99, `Data14`=24585, `Data20`=1, `Data26`=1, `VerifiedBuild`=26822 WHERE `entry`=246706; -- Demon Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=210181; -- Deathwing Trophy (0.7)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175738; -- Aegwynn and the Dragon Hunt
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201687; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201681; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201658; -- Stone Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201693; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201688; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201669; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201670; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201672; -- Wooden Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201664; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201663; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201654; -- Stone Bench
UPDATE `gameobject_template` SET `Data0`=176807, `VerifiedBuild`=26822 WHERE `entry`=237733; -- Portal to Ashran
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201667; -- Highback Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201660; -- Highback Chair
UPDATE `gameobject_template` SET `name`='Collision Wall', `VerifiedBuild`=26822 WHERE `entry`=259879; -- Collision Wall
UPDATE `gameobject_template` SET `name`='Flowers (Bunch)', `VerifiedBuild`=26822 WHERE `entry`=245649; -- Flowers (Bunch)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201498; -- Heavy Handed Weapons
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201989; -- Mailbox
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26822 WHERE `entry`=254120; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=201983; -- Righteous Plates
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181354; -- Floating, Medium - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181390; -- Hanging, Square, Medium - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181389; -- Hanging, Tall/Thin, Large - MFF
UPDATE `gameobject_template` SET `name`='Gunship', `VerifiedBuild`=26822 WHERE `entry`=246274; -- Gunship
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181358; -- Hanging, Square, Large - MFF

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=278802 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(278802, 0, 155856, 26822); -- Weathered Supply Crate

UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=203762 AND `Idx`=0); -- Juicy Apple
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=203800 AND `Idx`=0); -- Barrel of Canal Fish
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=204284 AND `Idx`=0); -- Stormwind Lobster Trap
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=140911 AND `Idx`=0); -- Spool of Light Chartreuse Silk Thread
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=203801 AND `Idx`=0); -- Sack of Confectioner's Sugar

DELETE FROM `npc_text` WHERE `ID` IN (27884 /*27884*/, 28003 /*28003*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(27884, 1, 0, 0, 0, 0, 0, 0, 0, 102370, 0, 0, 0, 0, 0, 0, 0, 26822), -- 27884
(28003, 1, 0, 0, 0, 0, 0, 0, 0, 103350, 0, 0, 0, 0, 0, 0, 0, 26822); -- 28003


