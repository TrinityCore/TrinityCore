DELETE FROM `gameobject_template_addon` WHERE `entry`=254237;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(254237, 2402, 0); -- Portal to Dalaran - Broken Isles

UPDATE `gameobject_template_addon` SET `flags`=48 WHERE `entry`=223739; -- The Gates of Orgrimmar

DELETE FROM `creature_template_addon` WHERE `entry` IN (118507 /*118507 (Nightborne Soulstone) - Nightborne Soulstone Fel - Shielded - Large*/, 119540 /*119540 (Kirin Tor Sky Ward) - Kirin Tor Sky Ward Aura*/, 97500 /*97500 (Hunaka Greenhoof)*/, 133186 /*133186 (Leyline Navigator)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(118507, 0, 0, 0, 1, 0, 0, 0, 0, '235195'), -- 118507 (Nightborne Soulstone) - Nightborne Soulstone Fel - Shielded - Large
(119540, 0, 0, 0, 1, 0, 0, 0, 0, '237553'), -- 119540 (Kirin Tor Sky Ward) - Kirin Tor Sky Ward Aura
(97500, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97500 (Hunaka Greenhoof)
(133186, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 133186 (Leyline Navigator)

UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=96198; -- 96198 (Catriona Macrae)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=34330; -- 34330 (Jones)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=96479; -- 96479 (Breanni)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=43062; -- 43062 (Bort)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=44158; -- 44158 (Orgrimmar Skyway Peon)
UPDATE `creature_template_addon` SET `auras`='65526 33209 33207 33208' WHERE `entry`=19177; -- 19177 (Troll Commoner)
UPDATE `creature_template_addon` SET `auras`='79865 56384' WHERE `entry`=47247; -- 47247 (Marud)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=47246; -- 47246 (Ureda)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=3329; -- 3329 (Kor'jus)

DELETE FROM `creature_template_scaling` WHERE `Entry`=133186;
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(133186, 110, 110, 0, 0, 26822);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=107772;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=112545;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=112543;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=106262;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=106263;
UPDATE `creature_template_scaling` SET `VerifiedBuild`=26822 WHERE `Entry`=133271;


UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16910;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65355;
UPDATE `creature_model_info` SET `BoundingRadius`=2.217252, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=74770;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67001;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65413;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65369;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=74782;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72095;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=69790;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25041;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65422;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25673;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=75301;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27955;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64759;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26395;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33542;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36905;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=75130;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25605;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27287;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28160;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28159;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=75302;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42872;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=71599;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26440;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65251;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72104;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27915;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72103;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=47997;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26394;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28143;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28161;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26441;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=22003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25595;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=67362;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72344;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=71019;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27448;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27616;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27019;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27960;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65452;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=71088;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=71017;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27959;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=15180;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3718;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25807;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27592;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65101;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25983;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=69156;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=55989;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34172;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27657;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=59102;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=69627;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=6302;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1924;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=69151;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27681;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64971;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28147;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28156;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25806;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=29056;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27719;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28162;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25875;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28155;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=56704;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=52659;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64049;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27882;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25947;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3585;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1206;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65242;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26307;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=26299;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1669;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5448;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5777;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=59537;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25791;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=69926;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27822;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=2954;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65714;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1072;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5585;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=28158;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=6296;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=47999;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=68480;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17170;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=65233;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=58842;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64048;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=83227;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=901;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=32938;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31737;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=9391;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=8848;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=29396;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=21342;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=81476;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37331;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37330;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37328;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=24164;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37329;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=72817;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31841;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5705;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=15470;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4368;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=5905;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=7511;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=64332;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=45902;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=45903;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=8971;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=62532;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37020;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36583;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31760;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=21072;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33698;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1311;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=37437;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17701;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34184;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17721;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=30413;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33701;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=15468;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33699;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34185;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=31988;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17699;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17700;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17722;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=14732;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=8572;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34049;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36585;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17719;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=33700;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=34047;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42389;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16445;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=16446;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17720;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=36584;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4259;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1334;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4073;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4602;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4492;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4449;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1335;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=61027;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=18678;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=61026;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1328;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4545;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4601;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4354;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35497;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=61028;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1331;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1330;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1327;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=55538;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4355;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35500;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35499;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35498;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=3758;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82773;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=35504;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=1329;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=4260;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=133186 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(133186, 1, 109677, 0, 0, 0, 0, 0, 0, 0, 0); -- Leyline Navigator

INSERT IGNORE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42548, 79276, 0, 0),
(107772, 234590, 0, 0);


UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97692; -- Brother of the Light
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109739; -- Tyrande Whisperwind
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=110623; -- Sunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96811; -- Andrew Matthews
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=107587; -- "The Hammer of Khaz'goroth" Teleport Used Quest Kill Credit
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=110642; -- Fizzi Liverzapper
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96782; -- Lucian Trias
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=112545; -- Zariya
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=112543; -- Khronus Lightwarden
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96797; -- Nargut
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=112847; -- Bewdley
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96798; -- Rhukah
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=108076; -- "Move Like No Other" Lan'dalock's Area Trigger Quest POI Blob
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=103630; -- Elite Forsaken Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=100324; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97141; -- Koraud
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=106528; -- Flower Pot
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31689; -- Gnome Diver
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96842; -- Archmage Tenaj
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96843; -- Darthalia Ebonscorch
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31741; -- Cosmetic Rabbit
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31740; -- Cosmetic Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98724; -- Giada Goldleash
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96830; -- Linda Ann Kastinglow
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96778; -- Aemara
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31729; -- Cosmetic Cat Set 2/2
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31710; -- Cosmetic Black Kingsnake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=107326; -- Draemus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=121602; -- Manapoof
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31730; -- Cosmetic Frog
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96983; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31719; -- Cosmetic Frenzy
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=106548; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101436; -- Wormhole
UPDATE `creature_template` SET `IconName`='openhandglow', `HealthScalingExpansion`=6, `type`=10, `type_flags`=1074790416, `type_flags2`=70, `VerifiedBuild`=26822 WHERE `entry`=127535; -- Greater Invasion Point: Inquisitor Meto
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=82646; -- Venombarb
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=130911; -- Charles Gastly
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=26537; -- Greeb Ramrocket
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=74228; -- Darkspear Headhunter
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=63626; -- Varzok
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44160; -- Suspicious Peon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20488; -- Tawny Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3310; -- Doras
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20491; -- Swift Red Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88704; -- Gran'dul
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=89175; -- Dysong
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3328; -- Ormok
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3330; -- Muragus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3216; -- Arnak Fireblade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=36883; -- Sunwalker Kodo
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18380; -- Swift Yellow Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5639; -- Craven Drok
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3296; -- Orgrimmar Grunt
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26822 WHERE `entry`=127951; -- Infernal Pyreclaw
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26822 WHERE `entry`=68665; -- Harbinger of Flame
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=118524; -- Dalaran Crystal
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97767; -- Hexpriest
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=106951; -- Advisor Stillwater
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=107772; -- Ol' Toomba
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96198; -- Catriona Macrae
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=106815; -- "The Tidestone of Golganneth" Teleport Used Quest Kill Credit ELM
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96955; -- Matron Ossela
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96827; -- Adorean Lew
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97518; -- Saedelin Whitedawn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96836; -- Magus Fansy Goodbringer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93537; -- Misensi
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109554; -- Altius Maximus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109387; -- Beck
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96799; -- Abohba
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=124678; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=104404; -- Thicket Hunter
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=111246; -- Archmage Timear
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=103626; -- Forsaken Guard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96787; -- Warcaster Fanoraithe
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31735; -- Cosmetic Pig
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=115287; -- Serr'ah
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96829; -- Arcanist Alec
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=32751; -- Backbiter
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96777; -- Jarold Puller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96479; -- Breanni
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=25058; -- Fuzz
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97500; -- Hunaka Greenhoof
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97212; -- 7.0 Dalaran - Shopkeeper - Dummy
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=34765; -- Zelli Hotnozzle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=9564; -- Frezza
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93223; -- Generic Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=43062; -- Bort
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14881; -- Spider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=38821; -- Dave's Industrial Light and Magic Bunny (Medium)(Sessile)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=50477; -- Champion Uru'zin
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49131; -- Goblin Hot Rod
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20493; -- Green Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44919; -- Maztha
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44948; -- Wind Rider Cub
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44158; -- Orgrimmar Skyway Peon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3334; -- Rekkul
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88705; -- Kranosh
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47254; -- Gizput
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3189; -- Kor'ghan
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3327; -- Gest
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=92553; -- Kirin Tor Summoner
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=37059; -- Great Sunwalker Kodo
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=32207; -- Armored Brown Bear
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18377; -- Swift Red Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20029; -- Thalassian Warhorse
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=358; -- Timber Wolf
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47246; -- Ureda
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47253; -- Rundok
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26822 WHERE `entry`=71014; -- Lil' Bad Wolf
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=90213; -- Chaos Pup
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=86447; -- Ikky
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26822 WHERE `entry`=7562; -- Brown Snake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=17213; -- Broom
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=7, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=26822 WHERE `entry`=118507; -- Nightborne Soulstone
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=43359; -- ELM General Purpose Bunny Infinite Hide Body
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=107590; -- Mayla Highmountain
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=72587; -- VFX Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97792; -- Sun Priest
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96805; -- Mato
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=110409; -- Credit - Portal Taken
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=119272; -- Sarah the Savage
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96958; -- Summoner Calwen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=119487; -- Talia Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96828; -- Bitty Frostflinger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96785; -- Christi Stockton
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96837; -- Babagahnoosh the Grumpy
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=93536; -- Awilo Lon'gomba
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=54027; -- Lil' Tarecgosa
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96796; -- Uda the Beast
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96802; -- Umbiwa
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=114732; -- Winnie
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=106262; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96788; -- Jessa Weaver
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=27047; -- Invisible Stalker (Floating Only)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31796; -- Cosmetic Worg Pup
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96786; -- Archmage Celindra
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96779; -- Dagna Flintlock
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31714; -- Cosmetic Ribbon Snake
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=113783; -- Savash Windcalller
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=104091; -- Kirin Tor Guardian
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98723; -- Tiffy Trapspring
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=32520; -- Totally Generic Bunny (All Phase)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=28960; -- Totally Generic Bunny (JSB)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=51346; -- Orgrimmar Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109912; -- Captive Wyrmtongue
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=15476; -- Scorpid
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62114; -- Spiny Lizard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=121541; -- Ban-Lu
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20486; -- Blue Wind Rider
UPDATE `creature_template` SET `ManaModifier`=1, `VerifiedBuild`=26822 WHERE `entry`=14720; -- High Overlord Saurfang
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20490; -- Swift Purple Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=19177; -- Troll Commoner
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44725; -- Sunwalker Atohmo
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62198; -- Omakka Wolfbrother
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49837; -- Spiny Lizard
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5875; -- Mordak Darkfist
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=88706; -- Murgul
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5909; -- Cazul
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47233; -- Gordul
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3331; -- Kareth
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=51195; -- Kor'kron Annihilator
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18379; -- Swift Purple Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20030; -- Thalassian Charger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3329; -- Kor'jus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47247; -- Marud
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26822 WHERE `entry`=68661; -- Untamed Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=90207; -- Stinkrot
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=40295; -- Blue Clockwork Rocket Bot
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26822 WHERE `entry`=7567; -- Crimson Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=1, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=26822 WHERE `entry`=119540; -- Kirin Tor Sky Ward
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97725; -- Priestess of Elune
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=34527; -- Dave's Industrial Light and Magic Bunny (Small)
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=99350; -- Shannon Noel
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=119486; -- Apothecary Lee
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97001; -- Orton Bennet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96806; -- Amisi Azuregaze
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96810; -- Archivist Betha
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96784; -- Fialla Sweetberry
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=101846; -- Nomi
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=109390; -- Annie
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=112079; -- Crimson Pilgrim
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96780; -- Aerith Primrose
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=106263; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=34330; -- Jones
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31728; -- Cosmetic Cat Set 1/2
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=124679; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=97512; -- Warp-Huntress Kula
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=113780; -- Innocent Jim
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=92489; -- Mei Francis
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31742; -- Cosmetic Prairie Dog
UPDATE `creature_template` SET `rank`=1, `type_flags`=2162797, `type_flags2`=128, `HealthModifier`=124, `VerifiedBuild`=26822 WHERE `entry`=11982; -- Magmadar
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=98725; -- Lio the Lioness
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133271; -- Highmountain Pathfinder
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1420; -- Toad
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=42548; -- Muddy Crawfish
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=95234; -- Elthyn Da'rai
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62115; -- Dung Beetle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=113395; -- Illidari Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=50488; -- Stone Guard Nargol
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=50323; -- Frizzo Villamar
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=49743; -- Dung Beetle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44918; -- Drakma
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20492; -- Swift Yellow Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=20489; -- Swift Green Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=45230; -- Orgrimmar Brave
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=44735; -- Seer Liwatha
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=3335; -- Hagrus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=5816; -- Katis
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=32640; -- Traveler's Tundra Mammoth
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=47248; -- Gija
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133186; -- Leyline Navigator
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26822 WHERE `entry`=127950; -- Surger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=68664; -- Corefire Imp
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26822 WHERE `entry`=7395; -- Undercity Cockroach


UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=11982 AND `Idx`=0); -- Magmadar
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=104404 AND `Idx`=2); -- Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=104404 AND `Idx`=1); -- Thicket Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=26822 WHERE (`CreatureEntry`=104404 AND `Idx`=0); -- Thicket Hunter

DELETE FROM `gameobject_template` WHERE `entry`=254237;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(254237, 22, 8111, 'Portal to Dalaran - Broken Isles', '', '', '', 1, 224873, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822); -- Portal to Dalaran - Broken Isles

UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245249; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251992; -- The Aegis of Aggramar
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244560; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241480; -- Sword
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=148502; -- Test Object
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250297; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259271; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250500; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259290; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259267; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242177; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250328; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250354; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259273; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242235; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250340; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241969; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259835; -- Fireplace
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=271739; -- Nomi's Test Kitchen
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259277; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250333; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=187572; -- Candle 01 - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250335; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=268086; -- The War of the Ancients
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251311; -- Portal to the Maelstrom
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251624; -- Drape
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242234; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251584; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241955; -- The Hunter's Reach
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250467; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250452; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242172; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181392; -- Hanging, Streamer - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=223739; -- The Gates of Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=207414; -- Waters of Farseeing
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=245923; -- Book
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243324; -- Table
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243293; -- Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204606; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204608; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206736; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206730; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197207; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204191; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=187576; -- Hanging, Square, Small - MFF
UPDATE `gameobject_template` SET `type`=8, `name`='Midsummer Brazier', `Data0`=4, `Data1`=10, `VerifiedBuild`=26822 WHERE `entry`=181355; -- Midsummer Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197313; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197286; -- Shadowdeep Reagents
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=254292; -- Portal to Dalaran
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=105576; -- Summoning Circle
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206529; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197284; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204632; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197323; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=224813; -- Garrison Building Alliance Pet Stable V1
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259307; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251033; -- Facade
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242174; -- Violet Hold Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250463; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=268048; -- Beyond the Dark Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250499; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259269; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250461; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250498; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250360; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250332; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241957; -- The Legerdemain Lounge
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250353; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250348; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250350; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250347; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=246664; -- Test Kitchen Results
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259279; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259280; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=187573; -- Candle 02 - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242224; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242232; -- The Filthy Animal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241949; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251594; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251592; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242223; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251312; -- Shaman Stones
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250449; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259281; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250450; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241970; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259282; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241946; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=187667; -- Hanging, Tall/Thin, Small - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242169; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=188021; -- Camp Pavilion
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206110; -- Portal to Moonglade
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243301; -- Ward
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206609; -- Elevator
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243296; -- Tent
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243295; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243300; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243292; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206732; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204607; -- Torch
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181393; -- Hanging, Tall/Thin, Medium - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206610; -- Elevator
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197257; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206729; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=195142; -- Portal to Hellfire Peninsula
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197276; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197311; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=216056; -- Collision PC Size
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206548; -- Ironwood Staves and Wands
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197279; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206538; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206539; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=235877; -- Portal to Blasted Lands
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251883; -- Archmage Vargoth's Retreat
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=246466; -- Tears of Elune
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244561; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250470; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250358; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250631; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259289; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259270; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=270855; -- Inconspicuous Note
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250460; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244537; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244536; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250359; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250462; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242236; -- One More Glass
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250352; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241954; -- Dalaran Visitor Center
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250336; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241948; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250346; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250334; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250339; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259278; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=246710; -- Nomi's Silver Mackerel
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259274; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242231; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250337; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242226; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242227; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251581; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251585; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250451; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251595; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259283; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250468; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241967; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=210181; -- Deathwing Trophy (0.7)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=164871; -- Zeppelin (The Thundercaller)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243332; -- Tent
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=253169; -- Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=254068; -- Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=252281; -- Supplies
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243302; -- Trap
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243299; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204200; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204205; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197309; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204196; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197307; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197315; -- Meeting Stone
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=188020; -- Camp Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204195; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197278; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=212212; -- Legacy of the Masters (Part 1)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197312; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197322; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206545; -- The Slow Blade
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204631; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204633; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206546; -- Arcane Enclave
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251579; -- Illidari Gateway
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=246944; -- Obliterum Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=252245; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259308; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259265; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250482; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259291; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250357; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259264; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250474; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244534; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=269967; -- Ironbound Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250329; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=268043; -- Icecrown and the Frozen Throne
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250355; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250331; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250351; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250349; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259272; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259266; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242176; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259276; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242225; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259275; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=259426; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250338; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242233; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=278457; -- Warchief's Command Board
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=268073; -- The Founding of Quel'Thalas
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251593; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251580; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=251582; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=244950; -- Dusty Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242228; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=250469; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241947; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241971; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=241956; -- Magical Menagerie
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=242170; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=223814; -- Doodad_OGRaid_FrontGate_Back
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=175080; -- Zeppelin (The Iron Eagle)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=186238; -- Zeppelin, Horde (The Mighty Wind)
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243294; -- Weapon Rack
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243298; -- Scrying Bowl
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=243333; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206741; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206608; -- Elevator
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=181401; -- Hanging, Streamer x3 - MFF
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=203969; -- Prickly Pear Fruit
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197310; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204192; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202717; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197314; -- Darkfire Enclave
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206547; -- Rekkul's Poisons
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197285; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206549; -- Shadowswift Brotherhood
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197280; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=206530; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=197287; -- Dark Earth
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=204634; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=252305; -- Portal to Dalaran


UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=203969 AND `Idx`=0); -- Prickly Pear Fruit
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26822 WHERE (`GameObjectEntry`=246710 AND `Idx`=0); -- Nomi's Silver Mackerel

