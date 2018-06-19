UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_crypt_fiend' WHERE `entry` IN (29118,29051,29063,29097);
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_creature_defiled_spirit' WHERE `entry`='75966';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_creature_falling_dagger' WHERE `entry`='75981';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_omen_of_death' WHERE `entry`='76462';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_ritual_of_bones' WHERE `entry`='76518';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_nhalish_prop' WHERE `entry`='75442';
UPDATE `creature_template` SET `ScriptName`='npc_nerzhul_fly' WHERE `entry`='794970';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_nerzul_prop' WHERE `entry`='79497';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_creature_shadow_rune' WHERE `entry`='75778';
UPDATE `creature_template` SET `ScriptName`='shadowmoon_burial_grounds_creature_eclipse_trigger' WHERE `entry`='76052';
DELETE FROM `conditions` WHERE `SourceEntry` IN 
(107287, 107501, 107589, 107518,
108040, 108041, 109213, 110312,
110153, 110157);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 107287, 0, 31, 0, 3, 56598, 'Warmaster Blackhorn - Twilight Barrage dummy'),
(13, 1, 107501, 0, 31, 0, 3, 56598, 'Warmaster Blackhorn - Twilight Barrage dmg 2'),
(13, 1, 107589, 0, 31, 0, 3, 56598, 'Warmaster Blackhorn - Twilight Onslaught dmg 2'),
(13, 2, 107518, 0, 31, 0, 3, 56598, 'Warmaster Blackhorn - Detonate'),
(13, 1, 108040, 0, 31, 0, 3, 56781, 'Warmaster Blackhorn - Artillery Barrage'),
(13, 1, 108041, 0, 31, 0, 3, 56781, 'Warmaster Blackhorn - Artillery Barrage dmg'),
(13, 1, 109213, 0, 31, 0, 3, 56781, 'Warmaster Blackhorn - Artillery Barrage dmg'),
(13, 1, 110312, 0, 31, 0, 3, 56781, 'Warmaster Blackhorn - Siphon Vitality'),
(13, 1, 110153, 0, 31, 0, 3, 56598, 'Warmaster Blackhorn - Broadside'),
(13, 1, 110157, 0, 31, 0, 3, 56598, 'Warmaster Blackhorn - Broadside');
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352, `VehicleId`=4470, `VerifiedBuild`=23222 WHERE `entry`=99800; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.8571429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `VerifiedBuild`=23222 WHERE `entry`=114288; -- Skeletal Warrior
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2099200, `VerifiedBuild`=23222 WHERE `entry`=98989; -- Cosmic Scythe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `speed_run`=1.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=102742; -- Fallen Shieldmaiden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2048, `ScriptName`='npc_seacursed_swiftblade' WHERE `entry`=98919; -- Seacursed Swiftblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33088, `unit_flags2`=67110912 WHERE `entry`=102894; -- Runecarver Slave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2048, `VehicleId`=4521 WHERE `entry`=101013; -- Captured Runecarver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=1, `faction`=14, `unit_flags`=33587200, `unit_flags2`=2099200 WHERE `entry`=97163; -- Cursed Falke
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2099200, `VerifiedBuild`=23222 WHERE `entry`=102306; -- Swirling Pool
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33555200, `unit_flags2`=1073743872, `VerifiedBuild`=23222 WHERE `entry`=101502; -- Helya's Tentacle
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_walk`=1.2, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32832, `unit_flags2`=4196352, `ScriptName`='npc_skjal_maw' WHERE `entry`=99307; -- Skjal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2048, `VehicleId`=4515, `VerifiedBuild`=23222 WHERE `entry`=100839; -- Cosmic Scythe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.8571429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4194304, `VerifiedBuild`=23222 WHERE `entry`=98973; -- Skeletal Warrior
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33587200, `unit_flags2`=4196352, `VerifiedBuild`=23222 WHERE `entry`=102326; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=33556480, `HoverHeight`=3.6 WHERE `entry`=97365; -- Seacursed Mistmender
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `faction`=14, `unit_flags2`=4196352, `ScriptName`='npc_seacursed_soulkeeper' WHERE `entry`=97200; -- Seacursed Soulkeeper
UPDATE `creature_template` SET `minlevel`=103, `maxlevel`=103, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352, `VehicleId`=4545, `VerifiedBuild`=23222 WHERE `entry`=97099; -- Swirling Pool
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784, `ScriptName`='npc_helya_maw_destructor_tentacle' WHERE `entry`=99801; -- Destructor Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=101187584, `HoverHeight`=4 WHERE `entry`=104906; -- Captured Val'kyr
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554688, `unit_flags2`=2048, `VehicleId`=4574, `VerifiedBuild`=23222 WHERE `entry`=102327; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_walk`=1.2, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32832, `unit_flags2`=2048, `ScriptName`='npc_night_watch_mariner' WHERE `entry`=97182; -- Night Watch Mariner
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_walk`=1.6, `speed_run`=1.714286, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=6291456, `ScriptName`='boss_ymiron_maw' WHERE `entry`=96756; -- Ymiron, the Fallen King
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `faction`=14, `unit_class`=8, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=114712; -- Runecarver Slave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=8, `faction`=14, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=102375; -- Runecarver Slave
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352, `VehicleId`=4496, `VerifiedBuild`=23222 WHERE `entry`=100361; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33817344, `unit_flags2`=1073743872, `VerifiedBuild`=23222 WHERE `entry`=101814; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=102769; -- Decrepit Runecarver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_walk`=0.8, `speed_run`=1, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048, `ScriptName`='npc_shroud_hound' WHERE `entry`=97119; -- Shroud Hound
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2048, `VehicleId`=4559 WHERE `entry`=102108; -- Captured Shieldmaiden
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=37750784, `VerifiedBuild`=23222 WHERE `entry`=100362; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352, `VehicleId`=4471, `VerifiedBuild`=23222 WHERE `entry`=99803; -- Destructor Tentacle
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=768, `unit_flags2`=37750784, `VerifiedBuild`=23222 WHERE `entry`=98363; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352, `VehicleId`=4495, `VerifiedBuild`=23222 WHERE `entry`=100359; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_run`=1, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=1142949888, `ScriptName`='boss_helya_maw' WHERE `entry`=96759; -- Helya
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=0.8, `speed_run`=0.8571429, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048, `VerifiedBuild`=23222 WHERE `entry`=114289; -- Skeletal Sorcerer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_walk`=1.6, `speed_run`=1.285714, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=3.9 WHERE `entry`=99033; -- Helarjar Mistcaller
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33587200, `unit_flags2`=4196352, `VerifiedBuild`=23222 WHERE `entry`=98291; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33088, `unit_flags2`=67110912 WHERE `entry`=102896; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784, `ScriptName`='npc_helya_maw_grasping_tentacle' WHERE `entry`=100360; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `VerifiedBuild`=23222 WHERE `entry`=98761; -- Soul Fragment
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_walk`=1.6, `speed_run`=1.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=4196352, `ScriptName`='npc_helarjar_champion' WHERE `entry`=97097; -- Helarjar Champion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554688, `unit_flags2`=2048, `VehicleId`=4573, `VerifiedBuild`=23222 WHERE `entry`=102325; -- Seacursed Rower
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `faction`=14, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2048, `VehicleId`=4383, `ScriptName`='npc_seacursed_slaver' WHERE `entry`=97043; -- Seacursed Slaver
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=39847936, `ScriptName`='boss_harbaron_maw' WHERE `entry`=96754; -- Harbaron
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `speed_run`=0.9920629, `BaseAttackTime`=3000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2048, `VerifiedBuild`=23222 WHERE `entry`=97185; -- The Grimewalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=1073743872, `VehicleId`=4608, `VerifiedBuild`=23222 WHERE `entry`=103115; -- Helheim
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2048, `VerifiedBuild`=23222 WHERE `entry`=97208; -- Spear
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `ScriptName`='npc_helya_maw_piercing_tentacle' WHERE `entry`=100188; -- Piercing Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33817344, `unit_flags2`=2048, `VerifiedBuild`=23222 WHERE `entry`=101504; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2099200, `VerifiedBuild`=23222 WHERE `entry`=100733; -- Charge
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=570688256, `unit_flags2`=67110913 WHERE `entry`=102830; -- Deceased Sorcerer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=14, `speed_run`=1.071429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=2048, `ScriptName`='npc_waterlogged_soul_guard' WHERE `entry`=99188; -- Waterlogged Soul Guard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `speed_run`=1.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `faction`=14, `unit_class`=1, `unit_flags`=32832, `unit_flags2`=67110912 WHERE `entry`=102104; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35 WHERE `entry`=115276;
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14 WHERE `entry`=105746;
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=83 WHERE `entry`=102896;
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=83 WHERE `entry`=102894;
UPDATE `creature_template` SET `ScriptName`='boss_vanessa_vancleef' WHERE `entry`=49541;
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=100733 AND `ID`=1) OR (`CreatureID`=97185 AND `ID`=1) OR (`CreatureID`=98973 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(100733, 1, 1925, 0, 130101), -- Charge
(97185, 1, 115802, 0, 0), -- The Grimewalker
(98973, 1, 106837, 0, 106837); -- Skeletal Warrior  
UPDATE `creature_template` SET `ScriptName`='npc_brewfest_receive_barrel' WHERE `entry` IN (60154);
UPDATE `creature_template` SET `ScriptName`='npc_bane_sphere' WHERE `entry` IN (97099);
UPDATE `creature_template` SET `ScriptName`='npc_darkmoon_rabbit_ird' WHERE `entry` IN (58336);
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_necromancer' WHERE `entry` IN (29119,28925,29064,29098);
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_champion' WHERE `entry` IN (29117,28924,29096,29062);
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_crusher' WHERE `entry` IN (28922);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher_champion" WHERE `entry` = 29117;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher_crypt_fiend" WHERE `entry` = 29118;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher_necromancer" WHERE `entry` = 29119;
UPDATE `creature_template` SET `ScriptName` = 'npc_slaincrewmember' WHERE `entry` = 42747;
UPDATE `creature_template` SET `ScriptName`='npc_boden_the_imposing' WHERE `entry`= 42471;
UPDATE `creature_template` SET `ScriptName`='npc_ricket_ticker' WHERE `entry`=49823;
update creature_template set scriptname = 'npc_haethen_kaul' where entry = 44835; 
UPDATE `creature_template` SET `ScriptName`='npc_gl_gob' WHERE `entry`='35486';
UPDATE `creature_template` SET `ScriptName`= "npc_hot_rod" WHERE `entry` =34840;
UPDATE `creature_template` SET `ScriptName`='npc_original_hot_rod' WHERE `entry`='37676';
UPDATE `creature_template` SET `ScriptName`= "npc_meteor_gob" WHERE `entry` =7000000;
UPDATE `creature_template` SET `ScriptName`= "npc_meteor2_gob" WHERE `entry` =7000001;
UPDATE `creature_template` SET `ScriptName`= "npc_meteor2_gob" WHERE `entry` =241101;
UPDATE creature_template SET ScriptName="npc_shadowmoon_burial_grounds_necrotic_pitch" WHERE entry=76191;
UPDATE `creature_template` SET `ScriptName`='npc_gw' WHERE `entry`='37106';
UPDATE creature_template SET ScriptName="boss_nerzul" WHERE entry=76407;
UPDATE `creature_template` SET `ScriptName`='npc_original_hot_rod' WHERE `entry`='37676';
UPDATE creature_template SET ScriptName = 'npc_subterranean_magma_worm' WHERE entry = 53112;
UPDATE `creature_template` SET `ScriptName`= "npc_nemesis" WHERE `entry` =52383;
UPDATE `creature_template` SET `ScriptName`= "npc_lylagar" WHERE `entry` =52766;
UPDATE creature_template SET ScriptName="boss_nhalish" WHERE entry=75829;
UPDATE `creature_template` SET `ScriptName`= "npc_kayn_sunfury_welcome" WHERE `entry` =98229;
UPDATE creature_template SET ScriptName="npc_shadowmoon_burial_grounds_creature_carrion_worm" WHERE entry=76057;
UPDATE creature_template SET ScriptName='boss_corla' WHERE entry=39679;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14762;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14763;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14764;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14765;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14772;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14773;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14776;
UPDATE `creature_template` SET `ScriptName`= "npc_av_marshal_or_warmaster" WHERE `entry` =14777;
UPDATE `creature_template` SET `ScriptName`= "npc_nithogg_electrical_storm" WHERE `entry` =107338;
UPDATE creature_template SET ScriptName='npc_fire_cyclone' WHERE entry=30648;
UPDATE `creature_template` SET `ScriptName`= "boss_sadana_bloodfury" WHERE `entry` =75509;
UPDATE `creature_template` SET `ScriptName`= "npc_nithogg_static_orb" WHERE `entry` =107353;
UPDATE `creature_template` SET `ScriptName`= "npc_shroud_hound" WHERE `entry` =97119;
UPDATE `creature_template` SET `ScriptName`= "npc_night_watch_mariner" WHERE `entry` =97182;
UPDATE `creature_template` SET `ScriptName`= "npc_seacursed_soulkeeper" WHERE `entry` =97200;
UPDATE `creature_template` SET `ScriptName`= "npc_skjal_maw" WHERE `entry` =99307;
UPDATE `creature_template` SET `ScriptName`= "npc_bane_skeleton" WHERE `entry` =98246;
UPDATE `creature_template` SET `ScriptName`= "venom_sprayer" WHERE `entry` =86547;
UPDATE `creature_template` SET `ScriptName`= "npc_helya_maw_destructor_tentacle" WHERE `entry` =99801;
UPDATE `creature_template` SET `ScriptName`= "npc_void_gara" WHERE `entry` =88707;
UPDATE `creature_template` SET `ScriptName`= "npc_gara" WHERE `entry` =85645;
UPDATE `creature_template` SET `ScriptName`= "npc_groog" WHERE `entry` =80167;
UPDATE `creature_template` SET `ScriptName`= "npc_helarjar_champion" WHERE `entry` =97097;
UPDATE `creature_template` SET `ScriptName`= "npc_waterlogged_soul_guard" WHERE `entry` =99188;
UPDATE `creature_template` SET `ScriptName`= "npc_seacursed_swiftblade" WHERE `entry` =98919;
UPDATE creature_template SET ScriptName="npc_xan_void_realm" WHERE entry=88713;
UPDATE creature_template SET ScriptName="npc_gara_void_creature" WHERE entry=88711;
UPDATE creature_template SET ScriptName="npc_gara_void_creature" WHERE entry=88712;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_gizrul_the_slavener' WHERE `entry`=10268;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_urok_doomhowl' WHERE `entry`=10584;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_lord_valthalak' WHERE `entry`=16042;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_kirtonos_the_herald' WHERE `entry`=10506;
UPDATE `creature_template` SET `ScriptName`='boss_hogger' WHERE `entry`=46254;
UPDATE `creature_template` set `ScriptName` = 'boss_randolph_moloch' WHERE `entry` = 46383;
UPDATE `creature_template` set `ScriptName`='boss_lord_overheat' WHERE `entry`=46264;
UPDATE `creature_template` SET `ScriptName` = 'boss_hexlord_malacrass' WHERE `entry` =24239;
UPDATE `creature_template` SET `ScriptName`='boss_pit_lord_argaloth' WHERE `entry`=47120;
UPDATE `creature_template` SET `ScriptName`='boss_ascendants' WHERE  `entry`=43686;
UPDATE `creature_template` SET `ScriptName` = 'boss_bd_nefarian' WHERE `entry` in (41376, 51104, 51105, 51106);
UPDATE `creature_template` SET `ScriptName` = 'boss_bd_onyxia' WHERE `entry` in (41270, 51116, 51117, 51118);
UPDATE `creature_template` SET `ScriptName` = 'npc_nefarian_intro' WHERE `entry` in (41379);
UPDATE `creature_template` SET `ScriptName` = 'npc_animated_bone_warrior' WHERE `entry` in (41918);
UPDATE `creature_template` SET `ScriptName` = 'npc_chromatic_prototype' WHERE `entry` in (41948, 51119, 51120, 51121);
UPDATE `creature_template` SET `ScriptName` = 'npc_shadowblaze' WHERE `entry` in (42596);
UPDATE `creature_template` SET `ScriptName` = 'boss_foe_reaper_5000' WHERE `entry` =43778;
UPDATE `creature_template` SET  `ScriptName` =  'npc_glubtok_main_platter' WHERE `entry` = '48974';
UPDATE `creature_template` SET  `ScriptName` =  'npc_glubtok_secondary_platter' WHERE `entry` in ('48975', '49039', '49040');
UPDATE `creature_template` SET  `ScriptName` =  'npc_defias_watcher' WHERE `entry` in ('47404', '47403');
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_lord_walden' WHERE `entry`= 46963;
UPDATE `creature_template` SET `ScriptName`='boss_ozumat' WHERE `entry`=42172;
UPDATE `creature_template` SET `ScriptName` = 'boss_tuten_kash' WHERE `entry` = 7355;
UPDATE `creature_template` SET `ScriptName` = 'boss_mordresh_fire_eye' WHERE `entry` = 7357;
UPDATE `creature_template` SET `ScriptName` = 'boss_glutton' WHERE `entry` = 8567;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_zum_rah' WHERE `entry`=7271;
UPDATE `creature_template` SET `ScriptName`='boss_ultraxion' WHERE `entry`=55294;
UPDATE `creature_template` SET `ScriptName`='boss_warlord_zonozz' WHERE `entry`=55308;
UPDATE `creature_template` SET `ScriptName`='npc_warlord_zonozz_void_of_the_unmaking' WHERE `entry`=55334;
UPDATE `creature_template` SET `ScriptName`='npc_warlord_zonozz_tentacle' WHERE `entry` IN (55418, 55416, 55417);
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_flail_of_gorath' WHERE `entry`=57877;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_claw_of_gorath' WHERE `entry`=57890;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_eye_of_gorath' WHERE `entry`=57875;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_teleport' WHERE `entry` IN (57289, 57287);
UPDATE `creature_template` SET `ScriptName`='boss_yorsahj_the_unsleeping' WHERE `entry`=55312;
UPDATE `creature_template` SET `ScriptName`='npc_yorsahj_the_unsleeping_globule' WHERE `entry` IN (55865, 55862, 55864, 55867, 55863, 55866);
UPDATE `creature_template` SET `ScriptName`='npc_yorsahj_the_unsleeping_forgotten_one' WHERE `entry`=56265;
UPDATE `creature_template` SET `ScriptName`='npc_yorsahj_the_unsleeping_mana_void' WHERE `entry`=56231;
UPDATE `creature_template` SET `ScriptName`='boss_hagara_the_stormbinder' WHERE `entry`=55689;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_stormborn_myrmidon' WHERE `entry`=57817;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_stormbinder_adept' WHERE `entry`=57823;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_tornado_stalker' WHERE `entry`=57921;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_twilight_frost_evoker' WHERE `entry`=57807;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_lieutenant_shara' WHERE `entry`=57821;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_icy_tomb' WHERE `entry`=55695;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_ice_lance' WHERE `entry`=56108;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_ice_wave' WHERE `entry`=56104;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_collapsing_icicle' WHERE `entry`=57867;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_frozen_binding_crystal' WHERE `entry`=56136;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_crystal_conductor' WHERE `entry`=56165;
UPDATE `creature_template` SET `ScriptName`='npc_hagara_the_stormbinder_bound_lightning_elemental' WHERE `entry`=56700;
UPDATE `gameobject_template` SET `ScriptName`='go_hagara_the_stormbinder_the_focusing_iris' WHERE `entry`=210132;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_teleport' WHERE `entry` IN (57287, 57377, 57379, 57882);
UPDATE `creature_template` SET `scriptname`= 'boss_morchok'  WHERE `entry`= 55265;
UPDATE creature_template set ScriptName = 'boss_asira_dawnslayer' WHERE entry = 54968;
UPDATE creature_template set ScriptName = 'boss_arcurion' WHERE entry = 54590;
UPDATE creature_template set ScriptName = 'boss_archbishop_benedictus' WHERE entry = 54938;
UPDATE creature_template SET ScriptName = 'boss_perotharn' WHERE entry = 55085;
UPDATE `creature_template` SET `ScriptName`='boss_mannoroth' WHERE `entry`=54969;
UPDATE `creature_template` SET `ScriptName`='boss_prince_taldaram' WHERE `entry`=29308;
UPDATE `creature_template` SET `ScriptName`="boss_king_dred" WHERE `entry`=27483;
UPDATE `creature_template` SET `ScriptName`='boss_four_horsemen_baron' WHERE `entry`=30549;
UPDATE `creature_template` SET `ScriptName`='boss_four_horsemen_thane' WHERE `entry`=16064;
UPDATE `creature_template` SET `ScriptName`='boss_four_horsemen_lady' WHERE `entry`=16065;
UPDATE `creature_template` SET `ScriptName`='boss_four_horsemen_sir' WHERE `entry`=16063;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_nexus_commanders' WHERE `entry` IN(26796,26798);
UPDATE `creature_template` SET `ScriptName` = 'boss_aerial_command_unit', `InhabitType` = 4, `mechanic_immune_mask` = 646135679 WHERE `entry` = 33670;
UPDATE `creature_template` SET `ScriptName` = 'boss_leviathan_mk_ii', `mechanic_immune_mask` = 646135679 WHERE `entry` = 33432;
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839, `ScriptName`='boss_ioc_horde_alliance' WHERE `entry` IN (34922,34924);
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_mennu_the_betrayer' WHERE entry=17991;
UPDATE `creature_template` SET `ScriptName`= "boss_trons" WHERE `entry` =42166;
UPDATE `creature_template` SET `ScriptName`= "boss_trons" WHERE `entry` =42178;
UPDATE `creature_template` SET `ScriptName`='boss_warmaster_blackhorn' WHERE `entry`=56427;
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_goriona' WHERE `entry`=56781;
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_skyfire' WHERE `entry`=56598;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_sky_captain_swayze' WHERE `entry`=55870;
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_twilight_assault_drake' WHERE `entry` IN (56855, 56587);
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_twilight_elite_dreadblade_slayer' WHERE `entry` IN (56854, 56848);
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_skyfire_harpoon_gun' WHERE `entry`=56681;
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_twilight_infiltrator' WHERE `entry`=56922;
UPDATE `creature_template` SET `ScriptName`='npc_warmaster_blackhorn_twilight_sapper' WHERE `entry`=56923;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_rokmar_the_crackler' WHERE entry=17991;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_quagmirran' WHERE entry=17942;
UPDATE creature_template SET ScriptName='boss_ahune' WHERE entry=25740;
UPDATE `creature_template` SET `AIName` = '', ScriptName = 'boss_shattered_executioner', `flags_extra` = 0 WHERE `entry` = 17301;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_commander_sarannis' WHERE `entry`=17976;
UPDATE `creature_template` SET `ScriptName`= 'boss_gatewatcher_gyrokill' WHERE `entry`=19218;
UPDATE `creature_template` SET `AIName` = '',`ScriptName` = 'boss_mechano_lord_capacitus' WHERE `entry` =19219;
UPDATE creature_template SET ScriptName = 'boss_wase_mari' WHERE entry = 56448;
UPDATE `creature_template`  SET `ScriptName` = 'boss_niuzao'  WHERE `entry` = 71954 ;
UPDATE `creature_template` SET `ScriptName` = 'boss_ordos' WHERE `entry` = '72057';
UPDATE `creature_template`  SET `ScriptName` = 'boss_xuen'  WHERE `entry` = 71953 ;
UPDATE `creature_template` SET `ScriptName`='boss_ysondre' WHERE `entry`=14887;
UPDATE `creature_template` SET `ScriptName`='boss_taerar' WHERE `entry`=14890;
UPDATE `creature_template` SET `ScriptName`='boss_emeriss' WHERE `entry`=14889;
UPDATE `creature_template` SET `ScriptName`='boss_taerar' WHERE `entry`=14890;
UPDATE creature_template SET ScriptName='boss_lethon' WHERE entry=14888;
UPDATE creature_template SET ScriptName="mob_CapturedMiner" WHERE entry=74355;
UPDATE `creature_template` SET `ScriptName`='mob_flash_freeze_maloriak' WHERE  `entry`=41576 LIMIT 1;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_nefarian_helper_heroic' WHERE `entry`=49427 LIMIT 1;
UPDATE `creature_template` SET  `ScriptName` =  'npc_rope_ship' WHERE `entry` = '49552';
UPDATE `creature_template` SET  `ScriptName` =  'npc_vanessa_intro' WHERE `entry` = '49429';
UPDATE `creature_template` SET  `ScriptName` =  'npc_note' WHERE `entry` = '49564';
UPDATE `creature_template` SET `ScriptName`= "boss_chi_ji" WHERE `entry` =71952;
UPDATE `creature_template` SET `ScriptName`= "world_boss_yu_lon" WHERE `entry` =71955;
UPDATE `creature_template` SET `ScriptName`= "mob_finkle_einhorn" WHERE `entry` =44202;
UPDATE `creature_template` SET `ScriptName`= "mob_bile_o_tron" WHERE `entry` =44418;
UPDATE `creature_template` SET `ScriptName`= "mob_absolute_zero" WHERE `entry` =41961;
UPDATE `creature_template` SET `ScriptName`= "npc_shadowflame_flashfire" WHERE `entry` =54254;
UPDATE `creature_template` SET `ScriptName`= "mob_nefarian_yeller" WHERE `entry` =49580;
UPDATE `creature_template` SET `ScriptName`= "mob_wild_vortex" WHERE `entry` =104602;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_mennu_the_betrayer' WHERE entry=17941;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_rokmar_the_crackler' WHERE entry=17991;
UPDATE `creature_template` SET `ScriptName`= "npc_legion_flame" WHERE `entry` =34784;
UPDATE `creature_template` SET `ScriptName`= "npc_slime_pool" WHERE `entry` =35176;
UPDATE `creature_template` SET `ScriptName`='npc_melee_hover_disk' WHERE `entry`=30234;
UPDATE `creature_template` SET `ScriptName`='npc_caster_hover_disk' WHERE `entry`=30248;
UPDATE creature_template SET scriptname = "npc_scion_of_eternity" WHERE entry = 30249;
UPDATE creature_template SET scriptname = "npc_nexus_lord" WHERE entry = 30245;
UPDATE `creature_template` SET `ScriptName` = 'npc_mimiron_assault_bot' WHERE `entry` = 34057;
UPDATE `creature_template` SET `faction` = 14 , `ScriptName` = 'npc_mimiron_emergency_fire_bot' WHERE `entry` = 34147;
UPDATE `creature_template` SET `ScriptName` = 'npc_mimiron_computer' WHERE `entry` = 34143;
UPDATE `creature_template` SET `unit_flags` = 33554436, `ScriptName` = 'npc_mimiron_flames' WHERE `entry` IN (34363, 34121);
UPDATE `creature_template` SET `unit_flags` = 33685510, `faction` = 14, `ScriptName` = 'npc_mimiron_frost_bomb' WHERE `entry` = 34149;
UPDATE `creature_template` SET `unit_flags` = 131078, `ScriptName` = 'npc_mimiron_proximity_mine' WHERE `entry` = 34362;
UPDATE `creature_template` set `inhabittype`=4,`unit_flags`=33554688,`unit_flags2`=2048,`ScriptName`="npc_tesla",`MovementType`=0,`flags_extra`=0 WHERE `entry`=16218;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_lightwell" WHERE `entry` =31883;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_lightwell" WHERE `entry` =31893;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_lightwell" WHERE `entry` =31894;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_lightwell" WHERE `entry` =31895;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_lightwell" WHERE `entry` =31896;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_lightwell" WHERE `entry` =31897;
UPDATE creature_template SET ScriptName = "npc_pet_gen_pandaren_monk" WHERE entry = 36911;
UPDATE creature_template SET ScriptName = "npc_pet_gen_egbert" WHERE entry = 23258;
UPDATE creature_template SET mechanic_immune_mask=650854271, flags_extra=0+0x200000, AIName='', ScriptName='npc_xt002_heart' WHERE entry=33329;
UPDATE `creature_template` SET `ScriptName`= "npc_pummeller" WHERE `entry` =33344;
UPDATE `creature_template` SET `ScriptName`='npc_xt_void_zone' WHERE entry = 34001;
UPDATE creature_template SET ScriptName='npc_scrapbot' WHERE entry=33343;
UPDATE `creature_template` SET `ScriptName`= "npc_life_spark" WHERE `entry` =34004;
UPDATE `creature_template` SET `ScriptName`= "npc_vicious_mindslasher" WHERE `entry` =44715;
UPDATE `creature_template` SET `ScriptName`= "npc_vesperon" WHERE `entry` =30449;
UPDATE `creature_template` SET `ScriptName`='npc_spark_of_ionar' WHERE `entry`='28926';
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_static_field',`flags_extra`=130 WHERE `entry`=30592;
UPDATE `creature_template` SET `ScriptName`= "npc_malformed_ooze" WHERE `entry` =27981;
UPDATE `creature_template` SET `ScriptName`= "npc_iron_sludge" WHERE `entry` =28165;
UPDATE `creature_template` SET `ScriptName`='npc_brann_bronzebeard_ulduar_intro' WHERE `entry`=33579;
UPDATE `creature_template` SET `ScriptName`= "npc_boombot" WHERE `entry` =33346;
UPDATE `creature_template` SET `ScriptName`= "npc_slad_ran_viper" WHERE `entry` =29680;
UPDATE `creature_template` SET `ScriptName`= "npc_amanitar_mushrooms" WHERE `entry` =30391;
UPDATE `creature_template` SET `ScriptName`= "npc_amanitar_mushrooms" WHERE `entry` =30435;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_impale_target" WHERE `entry`=29184;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_darter" WHERE `entry` = 29213;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_assassin" WHERE `entry` = 29214;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_guardian" WHERE `entry` = 29216;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_venomancer" WHERE `entry` = 29217;
UPDATE `creature_template` SET `ScriptName` = 'npc_drakkari_invader' WHERE `entry` IN (27709,27753,27754);
UPDATE `creature_template` SET `ScriptName`='npc_prince_taldaram_flame_sphere' WHERE `entry` IN (30106,31686,31687);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_skittering_swarmer" WHERE `entry`=28735;
UPDATE `creature_template` SET `AIName`='',`ScriptName`="npc_gatewatcher_web_wrap" WHERE `entry`=28619;
UPDATE `creature_template` SET `ScriptName`='npc_torch_tossing_target_bunny_controller' WHERE `entry`=25536;
UPDATE `creature_template` SET `ScriptName`='npc_prof_alchemy' WHERE `entry` IN (17909,19052,22427);
UPDATE `creature_template` SET `ScriptName`='npc_prof_blacksmith' WHERE `entry` IN (5164,11145,11146,11176,11177,11178,11191,11192,11193);
UPDATE creature_template SET ScriptName='npc_engineering_tele_trinket' WHERE entry IN (14742,14743,21493,21494);
UPDATE `creature_template` SET `ScriptName`='npc_prof_leather' WHERE `entry` IN (7866,7867,7868,7869,7870,7871);
UPDATE `creature_template` SET `ScriptName`= "npc_essence_of_twin" WHERE `entry` =34567;
UPDATE `creature_template` SET `ScriptName`= "npc_essence_of_twin" WHERE `entry` =34568;
UPDATE `creature_template` SET `ScriptName`= "npc_bullet_controller" WHERE `entry` =34743;
UPDATE `creature_template` SET `ScriptName`= "npc_snobold_vassal" WHERE `entry` =34800;
UPDATE `creature_template` SET `ScriptName`= "npc_molten_golem" WHERE `entry` =28695;
UPDATE `creature_template` SET `ScriptName`= "npc_stormforged_lieutenant" WHERE `entry` =29240;
UPDATE `creature_template` SET `ScriptName`= "npc_jedoga_initiand" WHERE `entry` =30114;
UPDATE `creature_template` SET `ScriptName`= "npc_ahnkahar_nerubian" WHERE `entry` =30176;
UPDATE `creature_template` SET `ScriptName`= "trigger_periodic" WHERE `entry` =16129;
UPDATE `creature_template` SET `ScriptName`="npc_midsummer_bunny_pole" WHERE `entry`=17066;
UPDATE creature_template SET ScriptName="npc_imp_in_a_ball" WHERE entry=23224;
UPDATE `creature_template` SET `ScriptName`="npc_train_wrecker" WHERE `entry`=33404;
UPDATE `creature_template` SET `npcflag`=129, `ScriptName`='npc_argent_squire_gruntling' WHERE `entry`=33238;
UPDATE `creature_template` SET `ScriptName`='npc_prof_tailor' WHERE `entry` IN (22208,22212,22213);
UPDATE `creature_template` SET `ScriptName`='npc_dream_fog' WHERE `entry`=15224;
UPDATE creature_template SET ScriptName='npc_spirit_shade' WHERE entry=15261;
UPDATE `creature_template` SET  `ScriptName` =  'npc_vanessa_nightmare' WHERE `entry` = '49671';
UPDATE `creature_template` SET  `ScriptName` =  'npc_icycle_dm' WHERE `entry` = '49481';
UPDATE `creature_template` SET  `ScriptName` =  'npc_helix_dm' WHERE `entry` = '49674';
UPDATE `creature_template` SET  `ScriptName` =  'npc_glubtok_dm' WHERE `entry` = '49670';
UPDATE `creature_template` SET  `ScriptName` =  'npc_enraged_worgen_dm' WHERE `entry` = '49532';
UPDATE `creature_template` SET  `ScriptName` =  'npc_james_dm' WHERE `entry` = '49539';
UPDATE `creature_template` SET  `ScriptName` =  'npc_rope_away' WHERE `entry` = '49550';
UPDATE `creature_template` SET  `ScriptName` =  'npc_mechanical_dm' WHERE `entry` = '49681';
UPDATE `creature_template` SET  `ScriptName` =  'npc_defias_shadowguard' WHERE `entry` = '49505';
UPDATE `creature_template` SET  `ScriptName` =  'npc_defias_enforcer' WHERE `entry` = '49502';
UPDATE `creature_template` SET  `ScriptName` =  'npc_defias_bloodwizard' WHERE `entry` = '48417';
UPDATE `creature_template` SET  `ScriptName` =  'npc_defias_envoker' WHERE `entry` = '48418';
UPDATE `creature_template` SET  `ScriptName` =  'npc_oaf_lackey' WHERE `entry` = '48445';
UPDATE `creature_template` SET  `ScriptName` =  'npc_goblin_overseer' WHERE `entry` = '48279';
UPDATE `creature_template` SET  `ScriptName` =  'npc_ogre_henchman' WHERE `entry` = '48230';
UPDATE `creature_template` SET  `ScriptName` =  'npc_lightning_orbs' WHERE `entry` = '49520';
UPDATE `creature_template` SET  `ScriptName` =  'npc_vanessa_anchor_bunny' WHERE `entry` = '51624';
UPDATE `creature_template` SET  `ScriptName` =  'npc_defias_cannon' WHERE `entry` = '48266';
UPDATE `creature_template` SET  `ScriptName` =  'npc_mining_powder' WHERE `entry` = '48284';
UPDATE `creature_template` SET  `ScriptName` =  'npc_mining_monkey' WHERE `entry` in ('48278', '48440');
UPDATE `creature_template` SET  `ScriptName` =  'npc_deadmines_bird' WHERE `entry` in ('48447', '48450');
UPDATE `creature_template` SET  `ScriptName` =  'npc_goblin_engineer' WHERE `entry` in ('622', '1731');
UPDATE `creature_template` SET `AIName` = '', ScriptName='mob_mande_wyrm_du_crepuscule' WHERE `entry`=39873;
UPDATE `creature_template` SET `ScriptName`='mob_gardien_de_la_nuee_cramoisie' WHERE `entry`='39381';
UPDATE `creature_template` SET `ScriptName`='npc_young_naga_gob' WHERE (`entry`='10581');
UPDATE `creature_template` SET `ScriptName`='mob_brise_tempete_du_crepuscule' WHERE `entry`='39962';
UPDATE `creature_template` SET `ScriptName`='mob_gardien_de_la_nuee_azur' WHERE `entry`='39854';
UPDATE `creature_template` SET `ScriptName`='npc_crack_isle_gob' WHERE (`entry`='39198');
UPDATE `creature_template` SET `ScriptName`='mob_esprit_de_leau_asservi' WHERE `entry`='39961';
UPDATE `creature_template` SET `ScriptName`='mob_elementaire_de_roche_asservi' WHERE `entry`='39900';
UPDATE `creature_template` SET `ScriptName`='mob_sculpte_terre_du_crepuscule' WHERE `entry`='39890';
UPDATE `creature_template` SET `ScriptName`='mob_chercheflamme_rehausse' WHERE `entry`='39415';
UPDATE `creature_template` SET `ScriptName`='mob_marche_vent_rehausse' WHERE `entry`='39414';
UPDATE `creature_template` SET `ScriptName`='mob_brute_gronn_asservie' WHERE `entry`='40166';
UPDATE `creature_template` SET `ScriptName`='mob_esprit_du_tonnerre_asservie' WHERE `entry`='40269';
UPDATE `creature_template` SET `ScriptName`='mob_grippe_feu_du_crepuscule' WHERE `entry`='39870';
UPDATE `creature_template` SET `ScriptName`='mob_braise_ardente_asservie' WHERE `entry`='39892';
UPDATE `creature_template` SET `ScriptName`='mob_habitant_trogg' WHERE `entry`='39450';
UPDATE `creature_template` SET `ScriptName`='npc_megs_isle_gob' WHERE (`entry`='38432');
UPDATE `creature_template` SET `ScriptName`='mob_imposteur_du_crepuscule' WHERE `entry`='40167';
UPDATE `creature_template` SET `ScriptName`='mob_tisseur_dombre_du_crepuscule' WHERE `entry`='39954';
UPDATE `creature_template` SET `ScriptName`='mob_prophete_de_la_nuee_azur' WHERE `entry`='39855';
UPDATE `creature_template` SET `ScriptName`='mob_maitre_darmes_du_crepuscule' WHERE `entry`='41073';
UPDATE `creature_template` SET `ScriptName`='mob_massacreur_du_crepuscule' WHERE `entry`='40448';
UPDATE `creature_template` SET `ScriptName`='mob_prophete_de_la_nuee_azur' WHERE `entry`='39855';
UPDATE `creature_template` SET `ScriptName`='mob_corrupteur_sans_visage' WHERE `entry`='39392';
UPDATE `creature_template` SET `ScriptName`='mob_seigneur_de_guerre_de_la_nuee_cramoisie' WHERE `entry`='39626';
UPDATE `creature_template` SET `ScriptName`='mob_corrupteur_sans_visage' WHERE `entry`='48844';
UPDATE `creature_template` SET `ScriptName`='mob_prophete_de_la_nuee_azur' WHERE `entry`='40291';
UPDATE `creature_template` SET `ScriptName`='mob_massacreur_du_crepuscule' WHERE `entry`='39956';
UPDATE `creature_template` SET `ScriptName`='mob_seigneur_de_guerre_de_la_nuee_azur' WHERE `entry`='39909';
UPDATE `creature_template` SET `ScriptName` = 'npc_net_red_dragon' WHERE `entry` =42570;
UPDATE `creature_template` SET `ScriptName`='mob_drake_du_crepuscule' WHERE `entry`='41095';
UPDATE `creature_template` SET `ScriptName`='mob_mande_tonnerre_du_crepuscule' WHERE `entry`='40270';
UPDATE `creature_template` SET `ScriptName`='mob_drake_du_crepuscule' WHERE `entry`='39390';
UPDATE `creature_template` SET `ScriptName`='mob_flagellant_aquatique_rehausse' WHERE `entry`='40273';
UPDATE `creature_template` SET `ScriptName`='mob_alexstraszas_eggs' WHERE `entry`=40486 LIMIT 1;
UPDATE  `creature_template` SET  `ScriptName` =  'npc_battered_red_drake' WHERE `entry` = 39294;
UPDATE `creature_template` SET `ScriptName`='mob_brise_roche_rehausse' WHERE `entry`='40272';
UPDATE `creature_template` SET `ScriptName`='mob_braise_ardente_asservie' WHERE `entry`='39892';
UPDATE `creature_template` SET `ScriptName`='mob_brute_gronn_asservie' WHERE `entry`='40166';
UPDATE `creature_template` SET `ScriptName`='mob_faceless' WHERE `entry`=40600 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='mob_faceless' WHERE `entry`=48844 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='mob_invoked_flame_spirit' WHERE `entry`=40357 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='mob_grippe_feu_du_crepuscule' WHERE `entry`='39870';
UPDATE `creature_template` SET `ScriptName`='mob_esprit_du_tonnerre_asservie' WHERE `entry`='40269';
UPDATE `creature_template` SET `AIName`='', `ScriptName`='mob_valiona_gb' WHERE `entry`=40320 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`= "npc_sinster_reflection" WHERE `entry` =25708;
UPDATE creature_template SET ScriptName='npc_kiljaeden_controller' WHERE entry=25608;
UPDATE `creature_template` SET `ScriptName`= "npc_hand_of_the_deceiver" WHERE `entry` =25588;
UPDATE `creature_template` SET `ScriptName`= "npc_felfire_portal" WHERE `entry` =25603;
UPDATE `creature_template` SET `ScriptName`= "npc_volatile_felfire_fiend" WHERE `entry` =25598;
UPDATE `creature_template` SET `ScriptName` = 'npc_felmyst_vapor' WHERE `entry` = 25265;
UPDATE `creature_template` SET `ScriptName` = 'npc_felmyst_vapor_cloud' WHERE `entry` = 25267;
UPDATE `creature_template` set `ScriptName` = 'npc_mortimer_moloch' WHERE `entry` = 46482;
UPDATE `creature_template` SET `ScriptName`= "npc_felmyst_trail" WHERE `entry` =25267;
UPDATE creature_template SET scriptname = "npc_james_36268" WHERE entry = 36288;
UPDATE creature_template SET ScriptName='npc_shadow_image' WHERE entry=25214;
UPDATE creature_template SET scriptname = "npc_cynthia_36267" WHERE entry = 36287;
UPDATE creature_template SET scriptname = "npc_ashley_36269" WHERE entry = 36289;
UPDATE creature_template SET scriptname = "npc_king_greymanes_horse_35905" WHERE entry = 35905;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_flamestrike'     WHERE  `entry`=50297;
UPDATE creature_template SET scriptname = "npc_crowley_horse_35231" WHERE entry = 35231;
UPDATE `creature_template` SET `ScriptName`='npc_council_liquid_ice'      WHERE  `entry`=45452;
UPDATE `creature_template` SET `ScriptName`='npc_council_violent_cyclone' WHERE  `entry`=44747;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_lava_seed'       WHERE  `entry`=45420;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_water_bomb'      WHERE  `entry`=44201;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `scale`=2, `ScriptName`='npc_council_violent_cyclone' WHERE  `entry`=44747;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_inferno_rush'    WHERE  `entry`=47501;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_gravity_well'    WHERE  `entry`=44824;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_liquid_ice'      WHERE  `entry`=45452;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_frozen_orb'      WHERE  `entry`=49518;
UPDATE `creature_template` SET `modelid1`= 11686, `flags_extra`=1, `ScriptName`='npc_council_flamestrike'     WHERE  `entry`=50297;
UPDATE `creature_template` SET `ScriptName`= "npc_archaedas_minions" WHERE `entry` =7077;
UPDATE `creature_template` SET `speed_walk`=2.5,`ScriptName`='npc_voljin_zulaman' WHERE `entry`=52924;
UPDATE `creature_template` SET `ScriptName`='npc_chained_spirit' WHERE `entry`=52156;
UPDATE `creature_template` SET  `ScriptName`='npc_sinestra_add' WHERE  `entry`=48415 LIMIT 1;
UPDATE `creature_template` Set `ScriptName`='npc_warden_thelwater' WHERE `entry`=46409;
UPDATE `creature_template` SET `ScriptName`='npc_eyestalk',`flags_extra`=128 WHERE `entry`=52369;
UPDATE `creature_template` SET `ScriptName`='npc_ohgan' WHERE `entry`=52157;
UPDATE creature_template SET ScriptName='npc_shield_orb' WHERE entry=25502;
UPDATE creature_template SET ScriptName='npc_grauf' WHERE entry=26893;
UPDATE `creature_template` SET `ScriptName`= "npc_armageddon" WHERE `entry` =25735;
UPDATE `creature_template` SET `ScriptName`= "npc_ingvar_throw_dummy" WHERE `entry` =23997;
UPDATE `creature_template` SET `ScriptName` = 'npc_barrel' WHERE `entry` IN (56731);
UPDATE `creature_template` SET `ScriptName`= "npc_annhylde_the_caller" WHERE `entry` =24068;
UPDATE creature_template SET scriptname = "npc_dh_spell_trainer" WHERE entry = 2000008;
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000009','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_dh_spell_trainer','25549');
UPDATE `creature_template` SET `ScriptName`='npc_pet_dk_ebon_gargoyle' WHERE `entry`='27829';
UPDATE creature_template SET ScriptName='npc_palehoof_orb' WHERE entry=26688;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_warlock_darkglare" WHERE `entry` =103673;
UPDATE `creature_template` SET `ScriptName`= "npc_battered_red_drake" WHERE `entry` =48523;
UPDATE `creature_template` SET `ScriptName`= "npc_jadespine_basilisk" WHERE `entry` =4863;
UPDATE `creature_template` SET `ScriptName`= "npc_stonekeepers" WHERE `entry` =4857;
UPDATE `creature_template` SET `ScriptName`= "npc_ravenous_furbolg" WHERE `entry` =26684;
UPDATE `creature_template` SET `ScriptName`= "npc_massive_jormungar" WHERE `entry` =26685;
UPDATE `creature_template` SET `ScriptName`= "npc_ferocious_rhino" WHERE `entry` =26686;
UPDATE `creature_template` SET `ScriptName`= "npc_frenzied_worgen" WHERE `entry` =26683;
UPDATE `creature_template` SET `ScriptName`= "npc_custom_npc" WHERE `entry` =690701;
UPDATE creature_template SET ScriptName='npc_crystal_channel_target' WHERE entry=26712;
UPDATE `creature_template` SET `ScriptName`= "npc_doomfire" WHERE `entry` =18095;
UPDATE `creature_template` SET `ScriptName` = 'npc_water_bubble_hoo' WHERE `entry` =41257;
UPDATE creature_template SET ScriptName='npc_buru_egg' WHERE entry=15514;
UPDATE `creature_template` SET `ScriptName` = 'npc_water_warden_hoo' WHERE `entry` =39802;
UPDATE `creature_template` SET `ScriptName`= "npc_giant_flesh_tentacle" WHERE `entry` =15802;
UPDATE `creature_template` SET `ScriptName` = 'npc_flame_warden_hoo' WHERE `entry` =39800;
UPDATE `creature_template` SET `ScriptName` = 'npc_bloodpetal_blossom' WHERE `entry` =40620;
UPDATE `creature_template` SET `ScriptName` = 'npc_earth_warden_hoo' WHERE `entry` =39801;
UPDATE `creature_template` SET `ScriptName` = 'npc_chaos_seed' WHERE `entry` =41126;
UPDATE `creature_template` SET `ScriptName` = 'npc_air_warden_hoo' WHERE `entry` =39803;
UPDATE `creature_template` SET `ScriptName` = 'npc_brann_bronzebeard_hoo' WHERE `entry` =39908;
UPDATE `creature_template` SET `ScriptName` = 'npc_whirling_winds_hoo' WHERE `entry` =41245;
UPDATE `creature_template` SET `ScriptName`= 'mob_spore' WHERE `entry`=40585;
UPDATE `creature_template` SET `ScriptName` = 'npc_chaos_portal' WHERE `entry` =41055;
UPDATE `creature_template` SET `ScriptName` = 'npc_spatial_flux' WHERE `entry` =39612;
UPDATE `creature_template` SET `ScriptName`= "npc_ancient_wisp" WHERE `entry` =17946;
UPDATE `creature_template` SET `ScriptName`= "npc_towering_infernal" WHERE `entry` =17818;
UPDATE `creature_template` SET `ScriptName` = 'npc_wild_turkey' WHERE `entry` =32820;
UPDATE `creature_template` SET `ScriptName`= "npc_lesser_doomguard" WHERE `entry` =17864;
UPDATE `creature_template` SET `ScriptName`= "npc_nerubian_burrower" WHERE `entry` =34607;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_warrior" WHERE `entry` =34475;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_warrior" WHERE `entry` =34453;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_warlock_wild_imp" WHERE `entry` =99739;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_shaman_fire_elemental" WHERE `entry` =15438;
UPDATE `creature_template` SET `ScriptName`= "npc_firelands_molten_spewer" WHERE `entry` =53545;
UPDATE `creature_template` SET `ScriptName`= "npc_living_vine" WHERE `entry` =40668;
UPDATE `creature_template` SET `ScriptName`= "npc_firelands_molten_erupter" WHERE `entry` =53617;
UPDATE `creature_template` SET `ScriptName`= "npc_suntouched_speaker" WHERE `entry` =39373;
UPDATE `creature_template` SET `ScriptName`= "npc_doomfire_targetting" WHERE `entry` =18104;
UPDATE creature_template SET ScriptName='npc_snufflenose_gopher' WHERE entry=4781;
UPDATE `creature_template` SET `ScriptName`= "npc_claw_tentacle" WHERE `entry` =15725;
UPDATE `creature_template` SET `ScriptName`= "npc_eye_tentacle" WHERE `entry` =15726;
UPDATE `creature_template` SET `ScriptName`= "npc_eye_of_occuthar" WHERE `entry` =52428;
UPDATE `creature_template` SET `ScriptName`= "npc_masked_orphan_matron" WHERE `entry` =23973;
UPDATE `creature_template` SET `ScriptName`= "npc_costumed_orphan_matron" WHERE `entry` =23973;
UPDATE `creature_template` SET `ScriptName`= "npc_midsummer_quest_torch" WHERE `entry` =87246;
UPDATE creature_template SET `AIName`= '',ScriptName = 'npc_idol_room_spawner' WHERE entry=8611;
UPDATE creature_template SET ScriptName='npc_belnistrasz' WHERE entry=8516;
UPDATE creature_template SET ScriptName='npc_hive_zara_larva' WHERE entry=15555;
UPDATE `creature_template` SET `ScriptName`= "npc_giant_eye_tentacle" WHERE `entry` =15334;
UPDATE `creature_template` SET `ScriptName`= "npc_slipstream_two" WHERE `entry` =45457;
UPDATE `creature_template` SET `ScriptName` = 'lady_nazjar_gauntlet' WHERE `entry` =39959;
UPDATE `creature_template` SET `ScriptName` = 'npc_asaad_grounding_field_trigger' WHERE `entry` =46492;
UPDATE `creature_template` SET `ScriptName` = 'npc_ravenous_creeper_trigger' WHERE `entry` = 45813;
UPDATE `creature_template` SET  `ScriptName` =  'npc_tornado_rohash' WHERE `entry` = 46207;
UPDATE `creature_template` SET `ScriptName`= "npc_giant_claw_tentacle" WHERE `entry` =15728;
UPDATE `creature_template` SET `ScriptName`= "npc_defias_blackguard" WHERE `entry` =42698;
UPDATE `creature_template` SET `ScriptName`='npc_slipstream' WHERE  `entry`=45455 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_pri_shadowfiend" WHERE `entry` =19668;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_shaman_earth_elemental" WHERE `entry` =15352;
UPDATE `creature_template` SET `scriptname`='npc_mirror_image' WHERE `entry` IN (31216);
UPDATE `creature_template` SET `scriptname`='npc_pet_mage_mirror_image' WHERE `entry` IN (47243, 47244);
UPDATE `creature_template` SET `ScriptName`= "npc_pet_hunter_snake_trap" WHERE `entry` =19833;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_hunter_snake_trap" WHERE `entry` =19921;
UPDATE creature_template SET ScriptName = "npc_pet_gen_baby_blizzard_bear" WHERE entry = 32841;
UPDATE `creature_template` SET `ScriptName`= "npc_pet_gen_mojo" WHERE `entry` =24480;
UPDATE creature_template SET unit_flags=33554432, flags_extra=128, AIName='', ScriptName='npc_omrogg_heads' WHERE entry=19523;
UPDATE `creature_template` SET `ScriptName`= "npc_hellfire_sentry" WHERE `entry` =17517;
UPDATE `creature_template` SET `ScriptName`= "npc_fel_orc_convert" WHERE `entry` =17083;
UPDATE `creature_template` SET `ScriptName`= "npc_zerekethvoidzone" WHERE `entry` =21101;
UPDATE `creature_template` SET `ScriptName`= "npc_lesser_shadow_fissure" WHERE `entry` =17471;
UPDATE `creature_template` SET `ScriptName`= "npc_warp_splinter_treant" WHERE `entry` =19949;
UPDATE `creature_template` SET `ScriptName`= 'npc_barada' WHERE `entry`= 22431;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'thorngrin_the_tender' WHERE `entry`=17978;
UPDATE `creature_template` SET `ScriptName`= "npc_phoenix_tk" WHERE `entry` =21362;
UPDATE `creature_template` SET `ScriptName`= "npc_phoenix_tk" WHERE `entry` =21362;
UPDATE `creature_template` SET `ScriptName`= "npc_toxic_sporebat" WHERE `entry` =22140;
UPDATE  creature_template SET  ScriptName= 'npc_parasitic_shadowfiend' WHERE  entry=23498;
UPDATE `creature_template` SET `ScriptName`= "npc_underbog_mushroom" WHERE `entry` =17990;
UPDATE `creature_template` SET `ScriptName`= "npc_coilfang_ambusher" WHERE `entry` =21865;
UPDATE  creature_template SET  ScriptName= 'npc_shadowy_construct' WHERE  entry=23111;
UPDATE `creature_template` SET `AIName`= '', `ScriptName` = 'npc_wrathbone_flayer' WHERE `entry`=22953;
UPDATE creature_template SET ScriptName='npc_frozen_core' WHERE entry=25865;
UPDATE  creature_template SET  ScriptName= 'npc_blade_of_azzinoth' WHERE  entry=22996;
UPDATE  creature_template SET  ScriptName= 'npc_flame_of_azzinoth' WHERE  entry=22997;
UPDATE  creature_template SET  ScriptName= 'npc_doom_blossom' WHERE  entry=23123;
UPDATE `creature_template` SET `ScriptName`= "npc_cage_trap_trigger" WHERE `entry` =23304;
UPDATE  creature_template SET  ScriptName= 'npc_tainted_elemental' WHERE  entry=22009;
UPDATE  creature_template SET  ScriptName= 'npc_enchanted_elemental' WHERE  entry=21958;
UPDATE `creature_template` SET `ScriptName`= "npc_water_globule" WHERE `entry` =21913;
UPDATE `creature_template` SET `ScriptName`= "npc_shield_generator_channel" WHERE `entry` =19870;
UPDATE `creature_template` SET `ScriptName`= "npc_greyheart_spellbinder" WHERE `entry` =21806;
UPDATE  creature_template SET  ScriptName= 'npc_shadow_demon' WHERE  entry=23375;
UPDATE creature_template SET AIName='', ScriptName='npc_inner_demon' WHERE entry=21857;
UPDATE `creature_template` SET `ScriptName`= "npc_syth_fire" WHERE `entry` =19203;
UPDATE `creature_template` SET `ScriptName`= "npc_syth_shadow" WHERE `entry` =19206;
UPDATE `creature_template` SET `ScriptName`= "npc_syth_frost" WHERE `entry` =19204;
UPDATE `creature_template` SET `ScriptName`= "npc_syth_fire" WHERE `entry` =19203;
UPDATE creature_template SET AIName='', ScriptName='npc_steamrigger_mechanic' WHERE entry=17951;
UPDATE creature_template SET AIName='', ScriptName='npc_naga_distiller' WHERE entry=17954;
UPDATE `creature_template` SET `ScriptName`= "npc_coilfang_waterelemental" WHERE `entry` =17917;
UPDATE `creature_template` SET `ScriptName`= "npc_ethereal_beacon" WHERE `entry` =18431;
UPDATE `creature_template` SET `ScriptName`= "npc_syth_arcane" WHERE `entry` =19205;
UPDATE `creature_template` SET `ScriptName`= "npc_voidtraveler" WHERE `entry` =19226;
UPDATE `creature_template` SET `ScriptName`= "npc_alchemist_finklestein" WHERE `entry` =28205;
UPDATE `creature_template` SET `ScriptName`= "npc_yor" WHERE `entry` =22930;
UPDATE `creature_template` SET `ScriptName`= "npc_avatar_of_martyred" WHERE `entry` =18478;
UPDATE `creature_template` SET `ScriptName`= "npc_shadowmoon_channeler" WHERE `entry` =17653;
UPDATE `creature_template` SET `ScriptName`= "npc_stolen_soul" WHERE `entry` =18441;
UPDATE `creature_template` SET `ScriptName`= "npc_focus_fire" WHERE `entry` =18374;
UPDATE `creature_template` SET `ScriptName`= "npc_ethereal_apprentice" WHERE `entry` =18430;
UPDATE `creature_template` SET `ScriptName`= "npc_storm_cloud" WHERE `entry` =29939;
UPDATE `creature_template` SET `ScriptName`= "npc_kael_flamestrike" WHERE `entry` =21369;
UPDATE `creature_template` SET `ScriptName`= "npc_solarium_priest" WHERE `entry` =18806;
UPDATE `creature_template` SET `ScriptName`= "npc_hellfire_channeler" WHERE `entry` =17256;
UPDATE `creature_template` SET `ScriptName`= "npc_ember_of_alar" WHERE `entry` =19551;
UPDATE `creature_template` SET `ScriptName`= "npc_kilrek" WHERE `entry` =17229;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_wraith" WHERE `entry` =21062;
UPDATE `creature_template` SET `ScriptName`= "npc_crystalcore_devastator" WHERE `entry` =20040;
UPDATE `creature_template` SET `ScriptName`= "npc_phase_hunter" WHERE `entry` =18879;
UPDATE `creature_template` SET `ScriptName`= "npc_infested_root_walker" WHERE `entry` =22095;
UPDATE `creature_template` SET `ScriptName`= "npc_phoenix_egg_tk" WHERE `entry` =21364;
UPDATE `creature_template` SET `ScriptName`= 'npc_invis_infernal_caster' WHERE `entry`=21417;
UPDATE creature_template SET ScriptName='npc_colonel_jules' WHERE entry=22432;
UPDATE `creature_template` SET `ScriptName`= "npc_rotting_forest_rager" WHERE `entry` =22307;
UPDATE `creature_template` SET `ScriptName`= "npc_enslaved_netherwing_drake" WHERE `entry` =21722;
UPDATE `creature_template` SET `ScriptName`= "npc_oscillating_frequency_scanner_master_bunny" WHERE `entry` =21760;
UPDATE creature_template SET AIName='', ScriptName='npc_ragin_flames' WHERE entry=20481;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_drake" WHERE `entry` =20021;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_drake" WHERE `entry` =21817;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_drake" WHERE `entry` =21820;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_drake" WHERE `entry` =21821;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_drake" WHERE `entry` =21823;
UPDATE `creature_template` SET `ScriptName`= "npc_torloth_the_magnificent" WHERE `entry` =22076;
UPDATE `creature_template` SET `ScriptName`= "npc_flame_patch_alar" WHERE `entry` =20602;
UPDATE creature_template SET ScriptName='npc_dragonmaw_peon' WHERE entry=22252;
UPDATE `creature_template` SET `ScriptName`= "npc_mature_netherwing_drake" WHERE `entry` =21648;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_infernal_attacker' WHERE `entry`=21419;
UPDATE `creature_template` SET `ScriptName`= "npc_unkor_the_ruthless" WHERE `entry` =18262;
UPDATE `creature_template` SET `ScriptName`='npc_madness_of_deathwing_congealing_blood' WHERE `entry`=57798;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_infernal_attacker' WHERE `entry`=21419;
UPDATE `creature_template` SET `ScriptName`='npc_madness_of_deathwing_jump_pad' WHERE `entry`=56699;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_elementium_terror' WHERE `entry` = 56710;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ymirjar_warrior' WHERE  `entry`=26690;
UPDATE `creature_template` SET `ScriptName` = 'npc_madness_of_deathwing_impaling_tentacle' WHERE `entry` = 56724;
UPDATE `creature_template` SET `ScriptName`='npc_morchok_kohcrom' WHERE `entry`=57773;
UPDATE `creature_template` SET `ScriptName`='npc_morchok_resonating_crystal' WHERE `entry`=55346;
UPDATE creature_template SET ScriptName='npc_tempest_minion' WHERE entry=33998;
UPDATE `creature_template` SET `ScriptName`= "npc_flame_warder" WHERE `entry` =35143;
UPDATE creature_template SET ScriptName = 'npc_frozen_orb' WHERE entry = 45322;
update `creature_template` set `ScriptName` = 'npc_archavon_warder' where `entry` = 32353;
UPDATE creature_template SET ScriptName='npc_erekem_guard' WHERE entry=29395;
UPDATE `creature_template` SET `ScriptName`= "npc_felkael_phoenix_egg" WHERE `entry` =24675;
UPDATE `creature_template` SET `ScriptName`= "npc_fel_crystal" WHERE `entry` =24722;
UPDATE `creature_template` SET `ScriptName`= "npc_felkael_phoenix_egg" WHERE `entry` =24675;
UPDATE `creature_template` SET `ScriptName`= "npc_pure_energy" WHERE `entry` =24745;
UPDATE `creature_template` SET `ScriptName`= "npc_firesworn" WHERE `entry` =12099;
UPDATE `creature_template` SET `ScriptName`= "npc_core_rager" WHERE `entry` =11672;
UPDATE creature_template SET ScriptName='npc_scarlet_courier' WHERE entry=29076;
UPDATE `creature_template` SET `ScriptName`= "npc_flamewaker_priest" WHERE `entry` =11662;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_trigger",`InhabitType`=7 WHERE `entry`=16137;
UPDATE `creature_template` SET `ScriptName`= "npc_fiendish_imp" WHERE `entry` =17267;
UPDATE `creature_template` SET `ScriptName`= "npc_ahune_bunny" WHERE `entry` =26346;
UPDATE `creature_template` SET `ScriptName`= "npc_carrion_worm" WHERE `entry` =86925;
UPDATE `creature_template` SET `ScriptName`= "npc_carrion_worm" WHERE `entry` =76057;
UPDATE `creature_template` SET `ScriptName`= "npc_shadowmoon_burial_grounds_creature_carrion_worm" WHERE `entry` =86925;
UPDATE `creature_template` SET `ScriptName`= "npc_shadowmoon_burial_grounds_creature_carrion_worm" WHERE `entry` =88769;
UPDATE `creature_template` SET `ScriptName`= "npc_webwrap" WHERE `entry` =16486;
UPDATE `creature_template` SET `ScriptName`= "npc_felkael_flamestrike" WHERE `entry` =24666;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_livingtrainee" WHERE `entry`=16124;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_livingknight" WHERE `entry`=16125;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_livingrider" WHERE `entry`=16126;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectraltrainee" WHERE `entry`=16127;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectralknight" WHERE `entry`=16148;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectralrider" WHERE `entry`=16150;
UPDATE `creature_template` SET `ScriptName`="npc_gothik_minion_spectralhorse" WHERE `entry`=16149;
UPDATE creature_template SET ScriptName = "npc_stalagg" WHERE entry= 15929;
UPDATE creature_template SET ScriptName = "npc_feugen" WHERE entry= 15930;
UPDATE `creature_template` SET `ScriptName`='npc_zombie_chow' WHERE `entry`=16360;
UPDATE `creature_template` SET `ScriptName` = 'npc_chaotic_rift' WHERE `entry` = '26918';
UPDATE `creature_template` SET `ScriptName`= "npc_faerlina_add" WHERE `entry` =16506;
UPDATE `creature_template` SET `speed_walk`=0.25,`speed_run`=0.285715,`ScriptName`="npc_kelthuzad_skeleton",`AIName`="" WHERE `Entry` in (16427,23561);
UPDATE `creature_template` SET `speed_walk`=0.1,`speed_run`=0.114286,`ScriptName`="npc_kelthuzad_banshee",`AIName`="" WHERE `Entry` in (16429,23563);
UPDATE `creature_template` SET `ScriptName`="npc_kelthuzad_guardian",`AIName`="" WHERE `Entry`=16441;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_dk_understudy" WHERE `entry`=16803;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_druid" WHERE `entry` =34459;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_druid" WHERE `entry` =34469;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_paladin" WHERE `entry` =34445;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_paladin" WHERE `entry` =34465;
UPDATE `creature_template` SET `ScriptName`= "mob_sonar_pulse" WHERE `entry` =41546;
UPDATE `creature_template` SET `ScriptName`= "mob_sonar_pulse" WHERE `entry` =49623;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_dk" WHERE `entry` =34458;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_dk" WHERE `entry` =34461;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_enh_shaman" WHERE `entry` =34455;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_enh_shaman" WHERE `entry` =34463;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_warlock" WHERE `entry` =34450;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_warlock" WHERE `entry` =34474;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_hunter" WHERE `entry` =34448;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_hunter" WHERE `entry` =34467;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_boomkin" WHERE `entry` =34451;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_boomkin" WHERE `entry` =34460;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_rogue" WHERE `entry` =34454;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_rogue" WHERE `entry` =34472;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_shaman" WHERE `entry` =34444;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_shaman" WHERE `entry` =34470;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_mage" WHERE `entry` =34449;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_mage" WHERE `entry` =34468;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_priest" WHERE `entry` =34447;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_priest" WHERE `entry` =34466;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_shadow_priest" WHERE `entry` =34441;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_shadow_priest" WHERE `entry` =34473;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_pet_warlock" WHERE `entry` =35465;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_retro_paladin" WHERE `entry` =34456;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_retro_paladin" WHERE `entry` =34471;
UPDATE `creature_template` SET `ScriptName`= "npc_frost_sphere" WHERE `entry` =34606;
UPDATE `creature_template` SET `ScriptName`= "npc_toc_pet_hunter" WHERE `entry` =35610;
UPDATE `creature_template` SET `ScriptName`= "npc_anubarak_spike" WHERE `entry` =34660;
UPDATE `creature_template` SET `ScriptName`= "npc_infernal_volcano" WHERE `entry` =34813;
UPDATE `creature_template` SET `ScriptName`= "npc_unleashed_dark" WHERE `entry` =34628;
UPDATE `creature_template` SET `ScriptName`= "npc_swarm_scarab" WHERE `entry` =34605;
UPDATE `creature_template` SET `ScriptName`= "npc_nether_portal" WHERE `entry` =34825;
UPDATE `creature_template` SET `ScriptName`= "npc_mistress_of_pain" WHERE `entry` =34826;
UPDATE `creature_template` SET `ScriptName`= "npc_fel_infernal" WHERE `entry` =34815;
UPDATE `creature_template` SET `ScriptName`= "npc_unleashed_light" WHERE `entry` =34630;
UPDATE `creature_template` SET `ScriptName`='npc_tremblement_volcano' WHERE (`entry`='241100');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('241100','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_tremblement_volcano','25549');
UPDATE `creature_template` SET `ScriptName`='npc_explosion_volcano' WHERE (`entry`='241102');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('241102','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_explosion_volcano','25549');
UPDATE `creature_template` SET `ScriptName`='npc_canon_gob' WHERE (`entry`='38526');
UPDATE `creature_template` SET `ScriptName`='npc_crack_isle_gob' WHERE (`entry`='39198');
UPDATE `creature_template` SET `ScriptName`='npc_killag_2' WHERE (`entry`='39066');
UPDATE `creature_template` SET `ScriptName`='npc_Chariot' WHERE (`entry`='39341');
UPDATE `creature_template` SET `ScriptName`='npc_Chariot2' WHERE (`entry`='39329');
UPDATE `creature_template` SET `ScriptName`='npc_grilly_2' WHERE (`entry`='38124');
UPDATE `creature_template` SET `ScriptName`='npc_Prince' WHERE (`entry`='38614');
UPDATE `creature_template` SET `ScriptName`='npc_boot' WHERE (`entry`='38387');
UPDATE `creature_template` SET `ScriptName`='npc_avion_gob' WHERE (`entry`='38929');
UPDATE `creature_template` SET `ScriptName`='npc_meteor2_gob' WHERE (`entry`='241101');
UPDATE `creature_template` SET `ScriptName`='npc_izzy_airplane' WHERE (`entry`='38928');
UPDATE `creature_template` SET `ScriptName`='npc_ceint' WHERE (`entry`='38738');
UPDATE `creature_template` SET `ScriptName`='npc_raptore_gob' WHERE (`entry`='38187');
UPDATE creature_template SET scriptname='npc_sc_millhouse_manastorm' WHERE entry in (43391);
UPDATE creature_template SET scriptname='npc_sc_millhouse_manastorm' WHERE entry in (49653);
UPDATE `creature_template` SET `ScriptName`='npc_oom_isle_gob' WHERE (`entry`='38531');
UPDATE `creature_template` SET `ScriptName`='npc_lodestone' WHERE `entry` IN (43258, 43254);
UPDATE `creature_template` SET `ScriptName`='npc_stalactite_trigger' WHERE `entry`='43159';
UPDATE `creature_template` SET `ScriptName`='npc_poule' WHERE (`entry`='44338');
update creature_template set scriptname = 'npc_xariona' where entry = 50061; 
update creature_template set scriptname = 'npc_haethen_kaul' where entry = 44835; 
UPDATE creature_template SET scriptname='npc_devout_follower' WHERE entry in (42428);
UPDATE creature_template SET scriptname='npc_devout_follower' WHERE entry in (49648);
UPDATE creature_template SET scriptname='npc_seismic_shard' WHERE entry in (42355);
UPDATE creature_template SET scriptname='npc_seismic_shard' WHERE entry in (49657);
UPDATE `creature_template` SET `ScriptName`= "npc_slad_ran_constrictor" WHERE `entry` =29713;
UPDATE `creature_template` SET `ScriptName`='npc_stonefathers_banner' WHERE `entry`=43163 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='npc_imposing_confrontation_quest' WHERE (`entry`='42731');
UPDATE `creature_template` SET `ScriptName` = 'npc_lake_frog' WHERE `entry` IN (33211,33224);
UPDATE `creature_template` SET `gossip_menu_id` = 33220 WHERE `entry` = 33220;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('33220','0','0','Do you know, where I can find Ashwood Brand Sword?','0','1','1','29416');
UPDATE `creature_template` SET `ScriptName`='npc_elemental_energy_quest' WHERE (`entry`='45088');
UPDATE `creature_template` SET `ScriptName`="npc_meteor_strike_flame" WHERE `entry`=40055;
UPDATE `creature_template` SET `ScriptName`='npc_rocket_propelled_warhead' WHERE `entry`=27593;
UPDATE `creature_template` SET `ScriptName`='npc_gunship_rocketeer' WHERE `entry` IN (36978,36982);
UPDATE `creature_template` SET `ScriptName`='npc_frostwing_vrykul' WHERE `entry` IN (37132,38125,37127,37134,37133);
UPDATE `creature_template` SET `ScriptName`='npc_ioc_gunship_captain' WHERE `entry` IN (35003, 34960);
UPDATE `creature_template` SET `ScriptName`="npc_wg_give_promotion_credit" WHERE `entry` IN (30739, 30740, 31036, 31051, 31052, 31053, 31054, 31091, 31101, 31102, 31106, 31107, 31151, 31153);
UPDATE `creature_template` SET `ScriptName`="npc_king_jokkum_vehicle" WHERE `entry`=30331;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`='npc_frostbrood_skytalon' WHERE `entry` = '31137';
UPDATE `creature_template` SET `ScriptName`='npc_torturer_lecraft' WHERE `entry`=27209;
UPDATE creature_template SET `AIName`= '',ScriptName = 'npc_commander_eligor_dawnbringer' WHERE entry=27784;
UPDATE `creature_template` SET `ScriptName`='npc_minigob_manabonk' WHERE `entry`=32838;
UPDATE `creature_template` SET ScriptName = 'npc_brann_bronzebeard_keystone' WHERE `entry`=31810;
UPDATE `creature_template` SET `spell1`=42166, `spell2`=61359, `AIName`= '',ScriptName = 'npc_mindless_abomination' WHERE `entry`=23575;
UPDATE `creature_template` SET `ScriptName`= "npc_nerubar_victim" WHERE `entry` =25284;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ymirjar_witch_doctor' WHERE  `entry`=26691;
UPDATE `creature_template` SET `ScriptName`= "npc_frost_warder" WHERE `entry` =38482;
UPDATE `creature_template` SET `ScriptName`= "npc_frozen_orb_stalker" WHERE `entry` =38461;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ymirjar_harpooner' WHERE  `entry`=26692;
UPDATE `creature_template` SET `ScriptName`='npc_violet_hold_defense_system' WHERE `entry`=30837;
UPDATE `creature_template` SET `ScriptName`= "npc_ichor_globule" WHERE `entry` =29321;
UPDATE `creature_template` SET `ScriptName`='npc_pit_of_saron_icicle' WHERE `entry`=36847;
UPDATE creature_template SET ScriptName='npc_corrupted_soul_fragment' WHERE entry=36535;
UPDATE `creature_template` SET `ScriptName`= "npc_ymirjar_flamebearer" WHERE `entry` =36893;
UPDATE `creature_template` SET `ScriptName`= "npc_iceborn_protodrake" WHERE `entry` =36891;
UPDATE `creature_template` SET `flags_extra`=0, `AIName`='', `ScriptName`='npc_void_sentry' WHERE `entry`=29364; -- Void Sentry
UPDATE `creature_template` SET `ScriptName`= "npc_geist_ambusher" WHERE `entry` =36886;
UPDATE `creature_template` SET `ScriptName`='npc_violet_hold_teleportation_portal' WHERE `entry`=30679;
UPDATE `creature_template` SET `ScriptName`='npc_violet_hold_teleportation_portal_elite' WHERE `entry`=32174;
UPDATE `creature_template` SET `ScriptName`='npc_violet_hold_teleportation_portal_intro' WHERE `entry`=31011;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_stalker" WHERE `entry` =32191;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_spellbreaker" WHERE `entry` =30662;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_spellbreaker" WHERE `entry` =30962;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_sorceror" WHERE `entry` =30667;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_saboteur" WHERE `entry` =31079;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_ring_captain" WHERE `entry` =28236;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_raider" WHERE `entry` =30668;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_mage_slayer" WHERE `entry` =30664;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_mage_slayer" WHERE `entry` =30963;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_invader" WHERE `entry` =30661;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_invader" WHERE `entry` =30961;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_captain" WHERE `entry` =30666;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_binder" WHERE `entry` =30663;
UPDATE `creature_template` SET `ScriptName`= "npc_azure_binder" WHERE `entry` =30918;
UPDATE `creature_template` SET `ScriptName`='npc_jaina_or_sylvanas_intro_hor' WHERE `entry`=37221;
UPDATE `creature_template` SET `ScriptName`='npc_jaina_or_sylvanas_intro_hor' WHERE `entry`=37223;
UPDATE `creature_template` SET `ScriptName` = 'npc_jaina_or_sylvanas_escape_hor' WHERE `entry` in (36955, 37554);
UPDATE creature_template SET ScriptName='npc_fiendish_portal' WHERE entry=17265;
UPDATE creature_template SET scriptname = 'npc_gunship' WHERE entry = 37215;
UPDATE creature_template SET scriptname = 'npc_gunship' WHERE entry = 37540;
UPDATE `creature_template` SET `ScriptName`= "npc_tito" WHERE `entry` =17548;
UPDATE `creature_template` SET `ScriptName`= "npc_felkael_phoenix" WHERE `entry` =24674;
UPDATE `creature_template` SET `ScriptName`= "npc_arcane_sphere" WHERE `entry` =24708;
UPDATE `creature_template` SET `ScriptName`= "npc_cyclone" WHERE `entry` =18412;
UPDATE `creature_template` SET `ScriptName`= "npc_cyclone" WHERE `entry` =46419;
UPDATE `creature_template` SET `ScriptName`= "npc_demon_chain" WHERE `entry` =17248;
UPDATE `creature_template` SET `ScriptName`= "npc_phalanx" WHERE `entry` =9502;
UPDATE `creature_template` SET `ScriptName`= "npc_aran_elemental" WHERE `entry` =17167;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_twilight_flame_caller' WHERE `entry`=39708;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_crazed_mage' WHERE `entry`=39982;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_twilight_torturer' WHERE `entry`=39978;
UPDATE `creature_template` SET `AIName`= '',`ScriptName`= 'npc_blackhand_incarcerator' WHERE `entry`=10316;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_twilight_sadist' WHERE `entry`=39980;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_mad_prisoner' WHERE `entry`=39985;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_raz_the_crazed' WHERE `entry`=39670;
UPDATE `creature_template` SET `ScriptName`= "npc_restless_soul" WHERE `entry` =11122;
UPDATE `creature_template` SET `ScriptName`= "npc_scarlet_trainee" WHERE `entry` =6575;
UPDATE `creature_template` SET `ScriptName`='npc_pulsing_pumpkin' WHERE `entry` = 23694;
UPDATE creature_template SET ScriptName = 'npc_hungry_hobo' WHERE entry = 42617;
UPDATE creature_template SET scriptname = "npc_mirror_image" WHERE entry = 31216;
UPDATE creature_template SET scriptname = "npc_dh_spell_trainer" WHERE entry = 999999;
UPDATE creature_template SET scriptname = "npc_dru_efflorescence" WHERE entry = 47649;
UPDATE `creature_template` SET `unit_flags`=768, `flags_extra`=0, `ScriptName`='npc_quel_delar_sword', `InhabitType`=7 WHERE `entry`=37158;
UPDATE `creature_template` SET `ScriptName`="npc_magister_aledis" WHERE `entry`=20159;
UPDATE `creature_template` SET `ScriptName` = 'npc_lonely_turkey' WHERE `entry` =32956;
UPDATE `creature_template` SET `ScriptName`='npc_ammunae_spore' WHERE `entry`=40669;
UPDATE `creature_template` SET `ScriptName`='npc_spiked_tentacle' WHERE  `entry`=50264 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`= "npc_slipstream_two" WHERE `entry` =104650;
UPDATE `creature_template` SET `ScriptName`= "mob_vortex_wind_rotation_manager" WHERE `entry` =80044;
UPDATE `creature_template` SET `ScriptName`= "npc_horatio_investigate" WHERE `entry` =42558;
UPDATE `creature_template` SET `ScriptName`= "npc_baine_totem" WHERE `entry` =54434;
UPDATE `creature_template` SET `ScriptName`= "npc_lord_geoffery" WHERE `entry` =46948;
UPDATE `creature_template` SET `ScriptName`= "npc_cyclone_shield" WHERE `entry` =46007;
UPDATE `creature_template` SET  `ScriptName` =  'npc_ice_storm_rain' WHERE `entry` = 46734;
UPDATE `creature_template` SET  `ScriptName` =  'npc_wind_funnel' WHERE `entry` = 48855;
UPDATE `creature_template` SET  `ScriptName` =  'npc_wind_funnel' WHERE `entry` = 48854;
UPDATE `creature_template` SET  `ScriptName` =  'npc_ice_storm' WHERE `entry` = 46973;
UPDATE `creature_template` SET  `ScriptName` =  'npc_squall_line' WHERE `entry` = 48852;
UPDATE `creature_template` SET  `ScriptName` =  'npc_squall_line' WHERE `entry` = 47034;
UPDATE `creature_template` SET  `ScriptName` =  'npc_stormling' WHERE `entry` = 47175;
UPDATE `creature_template` SET  `ScriptName` =  'npc_stormling' WHERE `entry` = 47177;
UPDATE `creature_template` SET  `ScriptName` =  'npc_stormling_pre_effect' WHERE `entry` = 47177;
UPDATE `creature_template` SET  `ScriptName` =  'npc_wind_burst_trigger' WHERE `entry` = 8777000;
UPDATE `creature_template` SET `ScriptName`='npc_spine_of_deathwing_burning_tendons' WHERE `entry` IN (56341, 56575);
UPDATE `creature_template` SET  `ScriptName` =  'npc_relentless_storm_initial_vehicle' WHERE `entry` = 47806;
UPDATE `creature_template` SET  `ScriptName` =  'npc_lightning_coulds' WHERE `entry` = 48190;
UPDATE `creature_template` SET  `ScriptName` =  'npc_lightning_coulds' WHERE `entry` = 48196;
UPDATE `creature_template` SET  `ScriptName` =  'npc_relentless_storm_initial_vehicle' WHERE `entry` = 47806;
UPDATE `creature_template` SET  `ScriptName` =  'npc_lightning_coulds' WHERE `entry` = 48190;
UPDATE `creature_template` SET  `ScriptName` =  'npc_lightning_coulds' WHERE `entry` = 48196;
UPDATE `creature_template` SET  `ScriptName` =  'npc_relentless_storm' WHERE `entry` = 47807;
UPDATE `creature_template` SET `ScriptName`='npc_spine_of_deathwing_spawner' WHERE `entry`=53888;
UPDATE `creature_template` SET `ScriptName`='npc_spine_of_deathwing_hideous_amalgamation' WHERE `entry`=53890;
UPDATE `creature_template` SET `ScriptName`='npc_spine_of_deathwing_deathwing' WHERE `entry`=53879;
UPDATE `creature_template` SET `ScriptName`='npc_spine_of_deathwing_corruption' WHERE `entry`=53891;
update creature_template set AIName="", ScriptName="npc_slipstream_alakir" where entry=46045;
UPDATE `creature_template` SET `ScriptName`='npc_spine_of_deathwing_corrupted_blood' WHERE `entry`=53889;
UPDATE `creature_template` SET `ScriptName`= "npc_slipstream_alakir" WHERE `entry` =47066;
UPDATE creature_template SET AIName='', ScriptName='npc_rayne_feathersong' WHERE entry in (52467);
UPDATE creature_template SET unit_flags=0, unit_flags2=0, type_flags=0, npcflag=1, ScriptName='npc_flame_protection_rune' WHERE entry in (52884,52885,52886,52887,52888,52889,52890,53887);
UPDATE creature_template SET npcflag=1, ScriptName='npc_little_lasher' WHERE entry in (53013);
UPDATE creature_template SET ScriptName='npc_anachronos_the_ancient' WHERE entry=15381;
UPDATE creature_template SET ScriptName='npc_druid_of_the_flame_molten_front', InhabitType=5, HoverHeight=10 WHERE entry in (52871,52872);
UPDATE creature_template SET ScriptName='npc_molten_front_vendor' WHERE entry in (53882,53214,53881);
UPDATE creature_template SET IconName='openhandglow', npcflag=1, ScriptName='npc_cinderweb_cocoon' WHERE entry in (52751,52783,52784,52989,52991,52992);
UPDATE `creature_template` SET `minlevel`=1,`maxlevel`=1,`faction`=35,`unit_flags`=33554440,`VehicleId`=550,`InhabitType`=4,`ScriptName`="npc_eagle_spirit" WHERE `entry`=36790;
UPDATE `creature_template` SET `ScriptName`='npc_robot_gob' WHERE `entry`='37598';
UPDATE `creature_template` SET `ScriptName`='npc_boucanier_gob' WHERE `entry`='37179';
UPDATE `creature_template` SET `ScriptName`='npc_citoyen_gob' WHERE `entry`='35075';
UPDATE `creature_template` SET `ScriptName`= "npc_faceless_shadow_weaver" WHERE `entry` =54633;
UPDATE `creature_template` SET `ScriptName`= "npc_ancient_firelord" WHERE `entry` =53864;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_firehawk' WHERE entry In (53245,53249);
UPDATE creature_template SET ScriptName='npc_firehawk_helper' WHERE `entry`=532971;
UPDATE creature_template SET ScriptName='npc_firehawk_helper' WHERE `entry`=532972;
UPDATE creature_template SET ScriptName='npc_firehawk_helper' WHERE `entry`=532973;
UPDATE creature_template SET `AIName`='', ScriptName='npc_flamewaker_shaman' WHERE entry in (53093);
UPDATE creature_template SET `AIName`='', ScriptName='npc_flamewaker_hunter' WHERE entry in (53143);
UPDATE `creature_template` SET `ScriptName`= "npc_flamewaker_hunter_helper" WHERE `entry` =531431;
UPDATE `creature_template` SET `ScriptName`= "npc_flamewaker_hunter_helper" WHERE `entry` =531430;
UPDATE `creature_template` SET `ScriptName`= "npc_flamewaker_shaman_helper" WHERE `entry` =530930;
UPDATE `creature_template` SET `ScriptName`= "npc_flamewaker_hunter_helper2" WHERE `entry` =530931;
UPDATE creature_template SET `AIName`='', ScriptName='npc_flamewaker_sentinel' WHERE entry in (53085);
UPDATE `creature_template` SET `ScriptName`= "mob_golden_orb" WHERE `entry` =51157;
UPDATE `creature_template` SET `ScriptName`= "npc_slipstream_raid" WHERE `entry` =104675;
UPDATE `creature_template` SET `ScriptName`= "npc_Achievement_helper" WHERE `entry` =529810;
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('529810','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_Achievement_helper','25549');
UPDATE `creature_template` SET `ScriptName`= "npc_hyjal_druid" WHERE `entry` =52501;
UPDATE `creature_template` SET `ScriptName`= "npc_flame_protection_rune1" WHERE `entry` =528840;
UPDATE `creature_template` SET `ScriptName`= "npc_fireland_teleporter" WHERE `entry` =100005;
UPDATE creature_template SET speed_walk=1.5, speed_run=1.5, npcflag=16777217, type_flags=2048, unit_flags=16777220, IconName='vehichleCursor', AIName='', spell1=99587, VehicleId=156, InhabitType=5, ScriptName='npc_trained_firehawk' WHERE entry in (53297);
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_quest_trigger' WHERE `entry`=15454;
UPDATE `creature_template` SET `ScriptName`='npc_ranshalla' WHERE `entry`=10300;
UPDATE `creature_template` SET `ScriptName`='npc_qiraj_war_spawn' WHERE `entry` IN (15414,15422,15423,15424);
UPDATE `creature_template` SET `ScriptName`='npc_bling_bling' WHERE `entry`='35120';
UPDATE `creature_template` SET `ScriptName`='npc_bling_bling' WHERE `entry`='35126';
UPDATE `creature_template` SET `ScriptName`='npc_bling_bling' WHERE `entry`='35128';
UPDATE `creature_template` SET `ScriptName`='npc_bling_bling' WHERE `entry`='35130';
UPDATE `creature_template` SET `ScriptName`='npc_shark_gob' WHERE `entry`='37114';
UPDATE `creature_template` SET `ScriptName`='npc_bambo' WHERE `entry`='35186';
UPDATE `creature_template` SET `ScriptName`='npc_defiant_troll' WHERE `entry`='34830';
UPDATE `creature_template` SET `ScriptName`='npc_fourth_and_goal_target' WHERE `entry`='37203';
UPDATE `creature_template` SET `AIName`='', ScriptName='npc_emberspit_scorpion' WHERE entry In (53240);
UPDATE creature_template SET AIName='', ScriptName='npc_currency_required_quest_taker' WHERE entry in (52490,52493);
UPDATE creature_template SET `AIName`='', ScriptName='npc_fireside_chat' WHERE entry in (52921,53259,52824,52134,52986,52669);
UPDATE creature_template SET `AIName`='', ScriptName='npc_cinderweb_spinner2', unit_flags=32772 WHERE entry in (52981);
UPDATE creature_template SET AIName='', ScriptName='npc_molten_behemoth' WHERE entry in (52552);
UPDATE creature_template SET AIName='', ScriptName='npc_melfurion_stormrage' WHERE entry in (52845);
UPDATE creature_template SET AIName='', ScriptName='npc_tholo_whitehoof' WHERE entry in (52903);
UPDATE creature_template SET AIName='', ScriptName='npc_leyara2' WHERE entry in (53014);
UPDATE creature_template SET AIName='', ScriptName='npc_thisalee_crow' WHERE entry in (52907);
UPDATE creature_template SET AIName='', ScriptName='npc_bear_cub' WHERE entry in (40240);
UPDATE  `creature_template` SET  `ScriptName` =  'npc_queen_azshara_hammer_of_divinity' WHERE `entry` = 54864;
UPDATE  creature_template SET  ScriptName= 'npc_webbed_creature' WHERE  entry=17680;
UPDATE creature_template SET AIName='', ScriptName='npc_child_of_tortolla' WHERE entry in (52177,52208);
UPDATE creature_template SET ScriptName = 'npc_ancient_charhound' WHERE entry = 54339;
UPDATE creature_template SET ScriptName = 'npc_druid_of_the_flame' WHERE entry = 54343;
UPDATE creature_template SET ScriptName = 'npc_pyrelord' WHERE entry = 52683;
UPDATE creature_template SET ScriptName = 'npc_ancient_charhound' WHERE entry = 54339;
UPDATE creature_template SET ScriptName = 'npc_druid_of_the_flame' WHERE entry = 54343;
UPDATE creature_template SET ScriptName = 'npc_subterranean_magma_worm' WHERE entry = 53112;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_firehawk' WHERE entry In (53245,53249);
UPDATE `creature_template` SET `AIName`="", `ScriptName`="npc_whisperwind_lasher" WHERE `entry`=47747;
UPDATE `creature_template` SET `ScriptName`='npc_sironas' WHERE `entry`= '17678';
UPDATE `creature_template` SET `ScriptName`= "npc_demolitionist_legoso" WHERE `entry` =17982;
UPDATE `creature_template` SET `ScriptName`= "npc_faceless_brute" WHERE `entry` =54632;
UPDATE `creature_template` SET `ScriptName`= "npc_water_shell" WHERE `entry` =55447;
UPDATE `creature_template` SET `ScriptName`= "npc_thrall_final_hot" WHERE `entry` =54971;
UPDATE creature_template SET AIName='', ScriptName='npc_squirrel', IconName='LootAll', unit_flags=33587200, npcflag=0 WHERE entry in (52195);
UPDATE creature_template SET AIName='', ScriptName='npc_alpine_songbird', unit_flags=33587200 WHERE entry in (52595);
UPDATE creature_template SET AIName='', ScriptName='npc_millagazor' WHERE entry in (52649);
UPDATE creature_template SET ScriptName='npc_tooga' WHERE entry=5955;
UPDATE creature_template SET AIName='', ScriptName='npc_arch_druid_hamuul_runetotem' WHERE entry in (52838);
UPDATE creature_template SET AIName='', ScriptName='npc_galenges' WHERE entry in (52399);
UPDATE creature_template SET AIName='', ScriptName='npc_leyara', mechanic_immune_mask=33554432 WHERE entry in (52863);
UPDATE creature_template SET AIName='', ScriptName='npc_elderlimb' WHERE entry in (52906);
UPDATE `creature_template` SET `ScriptName`= "npc_shadow_borer" WHERE `entry` =54686;
UPDATE creature_template SET AIName='', ScriptName='npc_pyrachnis' WHERE entry in (52749);
UPDATE creature_template SET AIName='', ScriptName='npc_forest_owl', unit_flags=33587200 WHERE entry in (52596);
UPDATE `creature_template` SET `ScriptName`='npc_gyrocoptere_quest_giver' WHERE (`entry`='42015');
UPDATE creature_template SET AIName='', ScriptName='npc_goldwing_hawk', unit_flags=33587200 WHERE entry in (52594);
UPDATE `creature_template` SET `ScriptName`='npc_phaseswift' WHERE (`entry`='2000008');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000008','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_phaseswift','25549');
UPDATE `creature_template` SET `ScriptName`='npc_girocoptere' WHERE (`entry`='2000006');
UPDATE `creature_template` SET `ScriptName`='npc_gunship_boarding_add' WHERE `entry` IN (36950,36957); -- Skybreaker Marine, Kor'kron Reaver
UPDATE `creature_template` SET `ScriptName`='npc_high_overlord_saurfang_igb' WHERE `entry`=36939; -- High Overlord Saurfang
UPDATE `creature_template` SET `ScriptName`='npc_muradin_bronzebeard_igb' WHERE `entry`=36948; -- Muradin Bronzebeard
UPDATE `creature_template` SET `ScriptName`='npc_gunship_boarding_leader' WHERE `entry` IN (36961,36960); -- Skybreaker Sergeant, Kor'kron Sergeant
UPDATE `creature_template` SET `ScriptName`='npc_gunship_gunner' WHERE `entry` IN (36969,36968);
UPDATE `creature_template` SET `ScriptName`='npc_uther_quel_delar' WHERE `entry`=37225;
UPDATE `creature_template` SET `ScriptName` = 'npc_lumbering_abomination' WHERE `entry` = 37069;
UPDATE `creature_template` SET `ScriptName` = 'npc_risen_witch_doctor' WHERE `entry` = 36941;
UPDATE `creature_template` SET `ScriptName`='npc_spiritual_reflection' WHERE `entry`=37068;
UPDATE `creature_template` SET `ScriptName`='npc_the_lich_king_escape_hor', `mechanic_immune_mask`=617299839 WHERE `entry` = 36954;
UPDATE `creature_template` SET `ScriptName`='npc_frostsworn_general' WHERE `entry`=36723;
UPDATE `creature_template` SET `scriptname` = 'npc_ethereal_sphere' WHERE `entry` = 32582;
UPDATE `creature_template` SET `ScriptName` = 'npc_raging_ghoul' WHERE `entry` = 36940;
UPDATE `creature_template` SET `ScriptName`= "npc_anubisath_sentinel" WHERE `entry` =15264;
UPDATE `creature_template` SET `ScriptName`= "npc_sartura_royal_guard" WHERE `entry` =15984;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470660;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470661;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470662;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470663;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470664;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470665;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470666;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_bridge" WHERE `entry` =470667;
UPDATE creature_template SET ScriptName='npc_crate_mine' WHERE entry=42500;
UPDATE `creature_template` SET `speed_run`=1.38571, `unit_flags`=33554440, `ScriptName`="npc_sharpbeak" WHERE `entry`=43161;
UPDATE `creature_template` SET `ScriptName`= "npc_yenniku" WHERE `entry` =2530;
UPDATE `creature_template` SET `ScriptName`='npc_dumpy_and_keeshan' WHERE `entry` IN (43249,43184);
UPDATE `creature_template` SET `ScriptName`= "npc_horatio" WHERE `entry` =42308;
UPDATE `creature_template` SET `ScriptName`= "npc_thug" WHERE `entry` =42387;
UPDATE `creature_template` SET `ScriptName`= "npc_gloomwing" WHERE `entry` =47476;
UPDATE `creature_template` SET `ScriptName`= "npc_emberscar_devourer" WHERE `entry` =46949;
UPDATE `creature_template` SET `ScriptName`= "npc_cadaver_collage" WHERE `entry` =46947;
UPDATE `creature_template` SET `ScriptName`= "npc_torg_drakeflayer" WHERE `entry` =46945;
UPDATE `creature_template` SET `ScriptName`= "npc_hurp_derp" WHERE `entry` =46944;
UPDATE `creature_template` SET `ScriptName`= "npc_sully_kneecapper" WHERE `entry` =46946;
UPDATE `creature_template` SET `ScriptName`= "npc_summoner" WHERE `entry` =96101;
UPDATE `creature_template` SET `gossip_menu_id` = 45068, `ScriptName` = 'npc_tb_spirit_guide' WHERE `entry` IN (45068, 45074);
UPDATE `creature_template` SET `ScriptName`='npc_big_earl' WHERE `entry`=43248;
UPDATE `creature_template` SET `ScriptName`='npc_redridge_citizen' WHERE `entry` IN (43222,43247);
UPDATE `creature_template` SET `ScriptName`= "npc_oox09hl" WHERE `entry` =7806;
UPDATE `creature_template` SET `ScriptName`='npc_bridge_worker_alex' WHERE `entry`=653;
UPDATE `creature_template` SET `ScriptName`= "npc_sumkaja_gob" WHERE `entry` =2000001;
UPDATE `creature_template` SET `ScriptName`= "npc_meteor_gob" WHERE `entry` =7000000;
UPDATE `creature_template` SET `ScriptName`= "npc_meteor_gob" WHERE `entry` =700000;
UPDATE creature_template SET ScriptName = "mob_risen_ghoul" WHERE entry IN (26125, 24207);
UPDATE `creature_template` SET `ScriptName`= "npc_moonlance_single" WHERE `entry` =54582;
UPDATE `creature_template` SET `ScriptName`= "npc_moonlance_single" WHERE `entry` =54580;
UPDATE `creature_template` SET `ScriptName`= "npc_moonlance_single" WHERE `entry` =54581;
UPDATE `creature_template` SET `ScriptName`= "npc_moonlance_single" WHERE `entry` =54574;
UPDATE `creature_template` SET `ScriptName`='npc_lianne_gobelin' WHERE (`entry`='17457');
UPDATE `creature_template` SET `ScriptName`= "mob_blighted_arrows" WHERE `entry` =54403;
UPDATE `creature_template` SET `ScriptName`= "npc_eye_of_the_goddess" WHERE `entry` =54594;
UPDATE `creature_template` SET `ScriptName`= "npc_eye_of_the_goddess" WHERE `entry` =54597;
UPDATE `creature_template` SET `ScriptName`= "npc_murozond_trash" WHERE `entry` =46956;
UPDATE `creature_template` SET `ScriptName`= "npc_icy_tomb" WHERE `entry` =54995;
UPDATE `creature_template` SET `ScriptName`='mob_ghoul_summoner' WHERE (`entry`=54197);
UPDATE `creature_template` SET `ScriptName`= "npc_gurgthock_cata" WHERE `entry` =46935;
UPDATE `creature_template` SET `ScriptName`= "npc_wave_of_virtue" WHERE `entry` =55441;
UPDATE `creature_template` SET `ScriptName`= "npc_corrupting_twilight" WHERE `entry` =55467;
UPDATE `creature_template` SET `ScriptName`= "npc_wave_of_twilight" WHERE `entry` =55469;
UPDATE `creature_template` SET `ScriptName`= "npc_thrall_hot" WHERE `entry` =54634;
UPDATE `creature_template` SET `ScriptName`= "npc_trash_hot" WHERE `entry` =55563;
UPDATE `creature_template` SET `ScriptName`= "npc_frozen_servitor" WHERE `entry` =54555;
UPDATE `creature_template` SET `ScriptName`= "npc_thrall_second_hot" WHERE `entry` =54548;
UPDATE `creature_template` SET `ScriptName`= "npc_twilight_assassin" WHERE `entry` =55106;
UPDATE `creature_template` SET `ScriptName`= "npc_twilight_bruiser" WHERE `entry` =55112;
UPDATE `creature_template` SET `ScriptName`= "npc_twilight_ranger" WHERE `entry` =55107;
UPDATE `creature_template` SET `ScriptName`= "npc_twilight_thug" WHERE `entry` =55111;
UPDATE `creature_template` SET `ScriptName`= "npc_twilight_shadow_walker" WHERE `entry` =55109;
UPDATE `creature_template` SET `ScriptName`='npc_perotharn_eye_of_perotharn' WHERE `entry` IN (55868, 55879);
UPDATE `creature_template` SET `ScriptName`= 'npc_milos_gyro' WHERE `entry`=37198;
UPDATE `creature_template` SET `ScriptName`= "npc_frozen_servitor_arcurion" WHERE `entry` =57197;
UPDATE `creature_template` SET `ScriptName`='npc_trogg_dweller' WHERE `entry`='45467';
UPDATE `creature_template` SET `ScriptName`='npc_eye_of_gorath' WHERE (`entry`='55416');
UPDATE `creature_template` SET `ScriptName`='npc_scourge_of_gorath' WHERE (`entry`='55417');
UPDATE `creature_template` SET `ScriptName`= 'npc_wounded_milita' WHERE `entry`=44405;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_darkened_creation' WHERE  `entry`=44045 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_ancient_water_lord' WHERE `entry`=57160;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_earthen_destroyer' WHERE `entry`=57158;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_earthen_soldier' WHERE `entry`=57159;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_twilight_siege_captain' WHERE `entry`=57280;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_twilight_portal' WHERE `entry`= 57231;
UPDATE `creature_template` SET `ScriptName`='npc_killag_sangrecroc' WHERE (`entry`='42014');
UPDATE `creature_template` SET AIName='', `ScriptName`='npc_dragon_soul_crimson_globule' WHERE `entry`=57386;
UPDATE `creature_template` SET AIName='', `ScriptName`='npc_dragon_soul_acidic_globule' WHERE `entry`=57333;
UPDATE `creature_template` SET AIName='', `ScriptName`='npc_dragon_soul_dark_globule' WHERE `entry`=57382;
UPDATE `creature_template` SET AIName='', `ScriptName`='npc_dragon_soul_shadowed_globule' WHERE `entry`=57388;
UPDATE `creature_template` SET AIName='', `ScriptName`='npc_dragon_soul_cobalt_globule' WHERE `entry`=57384;
UPDATE `creature_template` SET `ScriptName`= "npc_purifying_light" WHERE `entry` =55377;
UPDATE `creature_template` SET `ScriptName`= "npc_dragon_soul_wyrmrest_defense_dragon" WHERE `entry` =27629;
UPDATE `creature_template` SET `ScriptName`= "npc_dragon_soul_wyrmrest_attack_dragon" WHERE `entry` =57398;
UPDATE `creature_template` SET `ScriptName`= "npc_dragon_soul_wyrmrest_deathwing_siege" WHERE `entry` =57380;
UPDATE `creature_template` SET `ScriptName`= "npc_hagara_the_stormbinder_corrupted_fragment" WHERE `entry` =57819;
UPDATE `creature_template` SET `ScriptName`= "npc_creature_damage_limit" WHERE `entry` =2000004;
UPDATE `creature_template` SET `ScriptName`= "npc_galaw" WHERE `entry` =352220;
UPDATE `creature_template` SET `ScriptName`= "npc_high_inquisitor_valroth" WHERE `entry` =29001;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_thrall' WHERE `entry` IN (56667);
UPDATE `creature_template` SET `ScriptName`='npc_head' WHERE `entry`=23775;
UPDATE `creature_template` SET `ScriptName`='npc_friend_gob' WHERE `entry`='34957';
UPDATE `creature_template` SET `ScriptName`='npc_friend_gob' WHERE `entry`='34958';
UPDATE `creature_template` SET `ScriptName`='npc_wisp_invis' WHERE `entry` IN (23686, 24034);
UPDATE creature_template SET scriptname = "npc_cynthia_36267" WHERE entry = 36267;
UPDATE creature_template SET scriptname = "npc_james_36268" WHERE entry = 36268;
UPDATE `creature_template` SET `ScriptName`= "npc_gls_gob" WHERE `entry` =8500000;
UPDATE `creature_template` SET `ScriptName`= "npc_gls_gob" WHERE `entry` =850000;
UPDATE creature_template SET scriptname = "npc_ashley_36269" WHERE entry = 36269;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_fiend' WHERE `entry` =49864;
UPDATE `creature_template` SET  `ScriptName` =  'npc_magma_pull' WHERE `entry` = '49454';
UPDATE `creature_template` SET `ScriptName` = 'npc_spike_stalker' WHERE `entry` =41767;
UPDATE `creature_template` SET `ScriptName`='npc_malignant' WHERE `entry`='39984';
UPDATE `creature_template` SET `ScriptName` = 'npc_haunted_stable_hand' WHERE `entry` =51400;
UPDATE `creature_template` SET `ScriptName`= "npc_behemot" WHERE `entry` =44648;
UPDATE `creature_template` SET `ScriptName`= "npc_SonOfFlame" WHERE `entry` =12143;
UPDATE `creature_template` SET `ScriptName`= "npc_spilled_blood" WHERE `entry` =341781;
UPDATE `creature_template` SET `ScriptName`= "npc_twilight_portal_bot" WHERE `entry` =46301;
UPDATE `creature_template` SET `ScriptName`= "npc_magmaws_pincer" WHERE `entry` =41620;
UPDATE `creature_template` SET `ScriptName`= "mob_atramedes_gong" WHERE `entry` =42949;
UPDATE `creature_template` SET `ScriptName`= "mob_roaring_flame" WHERE `entry` =42001;
UPDATE `creature_template` SET `ScriptName`= "mob_searing_flame" WHERE `entry` =41807;
UPDATE `creature_template` SET `ScriptName`= "mob_roaring_flame_target" WHERE `entry` =42121;
UPDATE `creature_template` SET `ScriptName`= "mob_obnoxious_fiend" WHERE `entry` =49740;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43119;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43128;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43130;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43122;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43127;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43125;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43129;
UPDATE `creature_template` SET `ScriptName`= "mob_maloriak_atramedes_event" WHERE `entry` =43126;
UPDATE `creature_template` SET `ScriptName`= "npc_tot_teleporter" WHERE `entry` =51391;
UPDATE `creature_template` SET `ScriptName`= "npc_tot_teleporter" WHERE `entry` =51395;
UPDATE creature_template SET ScriptName='npc_eye_of_acherus' WHERE entry=28511;
UPDATE `creature_template` SET `ScriptName`= "npc_spectral_ghostly_citizen" WHERE `entry` =10384;
UPDATE `creature_template` SET `ScriptName`= "npc_masked_orphan_matron" WHERE `entry` =23973;
UPDATE `creature_template` SET `ScriptName`= "SmartScene" WHERE `entry` =2000005;
UPDATE `creature_template` SET `ScriptName`= "npc_eye_of_acherus" WHERE `entry` =43126;
UPDATE `creature_template` SET `ScriptName`= "npc_westplains_drifter" WHERE `entry` =42386;
UPDATE `creature_template` SET `ScriptName`= "npc_westplains_drifter" WHERE `entry` =42384;
UPDATE `creature_template` SET `ScriptName`= "npc_shadowy_tower" WHERE `entry` =42662;
UPDATE `creature_template` SET `ScriptName`= "npc_rise_br" WHERE `entry` =42771;
UPDATE `creature_template` SET `ScriptName`= "npc_fire_trigger" WHERE `entry` =42793;
UPDATE `creature_template` SET `ScriptName`= "npc_shadowy_trigger" WHERE `entry` =43515;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =24497;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =24468;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =23558;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =23486;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =24657;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =24510;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =23628;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =24498;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =23627;
UPDATE `creature_template` SET `ScriptName`= "npc_brewfest_belier_quests_givers" WHERE `entry` =27216;
UPDATE `creature_template` SET `ScriptName`= "npc_racer_slam_bunny" WHERE `entry` =27664;
UPDATE `creature_template` SET `ScriptName`= "npc_throw_bomb_bunny" WHERE `entry` =71221;
UPDATE `creature_template` SET `ScriptName`= "npc_midsummer_brasero" WHERE `entry` =27273;
UPDATE `creature_template` SET `ScriptName`= "npc_masked_orphan_matron" WHERE `entry` =23973;
UPDATE `creature_template` SET `ScriptName`= "npc_costumed_orphan_matron" WHERE `entry` =24519;
UPDATE `creature_template` SET `ScriptName`= "npc_healers_active_bunny" WHERE `entry` =2000007;
UPDATE `creature_template` SET `ScriptName`= "npc_wyrmrest_defender" WHERE `entry` =27690;
UPDATE `creature_template` SET `ScriptName`= "npc_wind_burst_trigger" WHERE `entry` =2000010;
UPDATE `creature_template` SET `ScriptName`= "npc_sunball" WHERE `entry` =40835;
UPDATE `creature_template` SET `ScriptName`= "npc_solar_wind_vortex" WHERE `entry` =47922;
UPDATE `creature_template` SET `ScriptName`= "npc_solar_wind_vortex" WHERE `entry` =39635;
UPDATE `creature_template` SET `ScriptName`= "npc_solar_wind_vortex" WHERE `entry` =39634;
UPDATE `creature_template` SET `ScriptName`= "npc_elementar_1" WHERE `entry` =39366;
UPDATE `creature_template` SET `ScriptName`= "npc_elementar_2" WHERE `entry` =39369;
UPDATE `creature_template` SET `ScriptName`= "npc_wyrmrest_defender" WHERE `entry` =27690;
UPDATE `creature_template` SET `ScriptName`= "npc_wyrmrest_defender" WHERE `entry` =27690;
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000010','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_burst_trigger','25549');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000007','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_healers_active_bunny','25549');











UPDATE `creature_template` SET `ScriptName`='npc_Zapnozzle' WHERE (`entry`='36608');
UPDATE `creature_template` SET `ScriptName`='npc_singe_bombe' WHERE (`entry`='34699');
UPDATE `creature_template` SET `ScriptName`='npc_mineur_gob' WHERE (`entry`='35810');
UPDATE `creature_template` SET `ScriptName`='npc_Mechumide' WHERE (`entry`='35769');
UPDATE `creature_template` SET `ScriptName`='npc_chipie_quest_giver_end_event' WHERE `entry`='37680';
UPDATE `creature_template` SET `ScriptName`='npc_tornade_gob' WHERE (`entry`='36178');
UPDATE `creature_template` SET `ScriptName`='npc_pant_gob' WHERE (`entry`='36585');
UPDATE `creature_template` SET `ScriptName`='npc_fusee_gob' WHERE (`entry`='42763');
UPDATE `creature_template` SET `ScriptName`= 'npc_wounded_coldridge_mountaineer' WHERE `entry`=37080;
UPDATE `creature_template` SET `ScriptName`='npc_phaseswift' WHERE (`entry`='9100000');
UPDATE `creature_template` SET `ScriptName`='npc_girocoptere' WHERE (`entry`='9000005');
UPDATE `creature_template` SET `ScriptName`='npc_galaw' WHERE (`entry`='352220');
UPDATE `creature_template` SET `ScriptName`='npc_meteor2_gob' WHERE (`entry`='241101');
UPDATE `creature_template` SET `ScriptName`='npc_tremblement_volcano' WHERE (`entry`='241100');
DELETE FROM spell_script_names WHERE spell_id IN (83883,68281,68211,72887,73000);
REPLACE INTO `spell_script_names` VALUES ('83883', 'spell_q26861_door_dummy');
REPLACE INTO `spell_script_names` VALUES ('68281', 'spell_68281');  
REPLACE INTO `spell_script_names` VALUES ('68211', 'spell_weed_whacker'); 
REPLACE INTO `spell_script_names` VALUES ('72887', 'spell_boot_damage');  
REPLACE INTO `spell_script_names` VALUES ('73000', 'spell_boot_gob');
UPDATE `gameobject_template` SET `ScriptName`='gob_control_gobelin' WHERE (`entry`='201736');
UPDATE `gameobject_template` SET `ScriptName`='gob_red_but' WHERE (`entry`='205065');
UPDATE `gameobject_template` SET `ScriptName`='gob_fronde_gobelin' WHERE (`entry`='196432');
UPDATE `gameobject_template` SET `ScriptName`='gob_dyn_gobelin' WHERE (`entry`='201938');
UPDATE `gameobject_template` SET `ScriptName`='gob_spark_gobelin' WHERE (`entry`='202108');
UPDATE `gameobject_template` SET `ScriptName`='go_setting_sun_brasier' WHERE (`entry`='214358');
DELETE FROM areatrigger_scripts WHERE entry=6216;
REPLACE INTO `areatrigger_scripts` VALUES ('6216', 'at_deepholm_flyover');



replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000006','0','0','0','0','0','22719','0','0','0','Gyrocopter','','vehicleCursor',NULL,'','0','85','85','3','0','0','35','6','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','1073741823','0','npc_girocoptere','25549');



replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('341781','0','0','0','0','0','11686','0','0','0','Spilled Blood of the old god','','',NULL,'','0','85','85','3','0','0','14','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_spilled_blood','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000005','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','SmartScene','25549');

-- Frozen Mountaineer
SET @ENTRY := 41763;
UPDATE `creature_template` SET `ScriptName` ='npc_frozen_mountaineer' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=@ENTRY;


-- Icy Tomb SAI
SET @ENTRY := 41768;
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=64 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icy Tomb - On Reset - Set Reactstate Passive"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,41763,5,0,0,0,0,0,"Icy Tomb - On Death - Set Data 1 1 on target");

-- Water Spout SAI
SET @ENTRY := 41761;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4, `flags_extra`=128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,8000,18000,22000,11,77885,0,0,0,0,0,1,0,0,0,0,0,0,0,"Water Spout - OOC - Cast 'Water Stream'");

-- Condition for source Quest show mark condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=25997 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 25997, 0, 0, 8, 0, 25978, 0, 0, 0, 0, 0, '', 'Show quest mark on questgiver for quest Dark Iron Scheming if quest Entombed in Ice has been rewarded.'),
(19, 0, 25997, 0, 0, 8, 0, 25979, 0, 0, 0, 0, 0, '', 'Show quest mark on questgiver for quest Dark Iron Scheming if quest Dealing with the Surge has been rewarded.');



-- Pathing for Monann Coldforge Entry: 43384
SET @NPC := 307073;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5522.49,`position_y`=-1930.35,`position_z`=398.9774, `orientation`=0.4537856 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5518.66,-1928.455,399.2177,0,0,0,0,100,0),
(@PATH,2,-5510.91,-1926.205,399.2177,0,0,0,0,100,0),
(@PATH,3,-5507.41,-1925.205,399.2177,0,0,0,0,100,0),
(@PATH,4,-5507.41,-1921.955,399.2177,0,0,0,0,100,0),
(@PATH,5,-5511.83,-1921.56,398.958,1.605703,22000,0,476,100,0),
(@PATH,6,-5511.83,-1921.56,398.958,0,25000,0,21,100,0),
(@PATH,7,-5510.515,-1921.225,399.208,0,0,0,0,100,0),
(@PATH,8,-5506.265,-1923.225,399.208,0,0,0,0,100,0),
(@PATH,9,-5508.265,-1927.475,399.208,0,0,0,0,100,0),
(@PATH,10,-5514.2,-1928.89,398.958,0,0,0,0,100,0),
(@PATH,11,-5522.49,-1930.35,398.9774,0.4537856,20000,0,0,100,0);

-- Respawn Helm's Bed Surger
SET @CGUID := 210115000;
SET @CGUID1 := 210112100;
DELETE FROM `creature` WHERE `id`=41762;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5669.751, -1862.565, 399.8657, 1.155607, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+7, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5610.573, -1865.416, 399.4626, 5.13934, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+9, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5639.946, -1888.886, 396.4976, 2.107552, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+10, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5615.873, -1914.267, 396.3925, 3.629547, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+11, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5675.296, -1904.372, 396.4886, 2.015625, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+12, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5700.633, -1900.952, 399.0114, 3.867587, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+13, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5681.731, -1947.516, 396.4861, 4.858893, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+16, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5641.102, -1927.602, 396.4861, 5.184005, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+17, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5575.928, -1925.872, 396.4137, 3.133996, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+19, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5707.853, -1956.87, 396.4976, 5.427558, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+21, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5590.827, -1948.583, 396.448, 1.192716, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+22, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5590.45, -1976.762, 396.4347, 2.748698, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+23, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5548.742, -1950.276, 396.4976, 0.5975769, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+24, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5671.467, -1990.26, 396.3611, 5.660463, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+0, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5667.346, -1992.488, 396.2869, 2.601416, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+3, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5719.235, -1990.257, 396.4976, 4.106979, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+19, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5736.44, -1950.92, 398.4708, 1.258934, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+20, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5680.422, -2042.633, 396.386, 4.651815, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+24, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5769.359, -1974.04, 401.4739, 3.994661, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+25, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5742.633, -2036.312, 396.4976, 1.772768, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+28, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5717.647, -2056.196, 396.4976, 6.015036, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+29, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5672.636, -2074.722, 398.4598, 4.411019, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+30, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5694.443, -2086.331, 400.5424, 3.406474, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+31, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5644.933, -2047.221, 396.4445, 0.5479373, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+35, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5574.728, -2055.29, 396.4728, 2.093844, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+36, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5605.143, -2031.48, 396.277, 1.511136, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+40, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5584.254, -2013.192, 396.4546, 3.848937, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+41, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5545.497, -2002.751, 397.9317, 1.948765, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 304380;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5715.347,`position_y`=-1285.99,`position_z`=390.1207 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5715.347,-1285.99,390.1207,0,0,1,0,100,0),
(@PATH,2,-5711.893,-1272.75,390.0777,0,0,1,0,100,0),
(@PATH,3,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,4,-5708.399,-1246.309,389.6016,0,0,1,0,100,0),
(@PATH,5,-5708.399,-1246.309,389.6016,0,0,1,0,100,0),
(@PATH,6,-5714.655,-1237.602,388.8025,0,0,1,0,100,0),
(@PATH,7,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,8,-5711.893,-1272.75,390.0777,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306745;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5866.543,`position_y`=-1109.323,`position_z`=381.5317 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5866.543,-1109.323,381.5317,0,0,1,0,100,0),
(@PATH,2,-5891.304,-1104.958,382.0053,0,0,1,0,100,0),
(@PATH,3,-5908.681,-1106.906,386.5114,0,0,1,0,100,0),
(@PATH,4,-5920.019,-1119.859,389.8581,0,0,1,0,100,0),
(@PATH,5,-5913.934,-1137.568,389.9782,0,0,1,0,100,0),
(@PATH,6,-5901.929,-1146.99,385.9181,0,0,1,0,100,0),
(@PATH,7,-5885.643,-1159.148,382.1496,0,0,1,0,100,0),
(@PATH,8,-5873.75,-1168.328,382.6564,0,0,1,0,100,0),
(@PATH,9,-5854.797,-1165.993,381.1606,0,0,1,0,100,0),
(@PATH,10,-5842.077,-1154.569,379.5258,0,0,1,0,100,0),
(@PATH,11,-5826.351,-1141.408,379.4123,0,0,1,0,100,0),
(@PATH,12,-5823.428,-1134.105,380.7233,0,0,1,0,100,0),
(@PATH,13,-5828.453,-1117.734,380.8938,0,0,1,0,100,0),
(@PATH,14,-5854.981,-1111.861,381.6089,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5795.042,`position_y`=-1081.163,`position_z`=384.5584 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5795.042,-1081.163,384.5584,0,0,1,0,100,0),
(@PATH,2,-5774.736,-1091.226,383.4236,0,0,1,0,100,0),
(@PATH,3,-5758.776,-1098.299,383.0758,0,0,1,0,100,0),
(@PATH,4,-5751.005,-1116.793,382.5779,0,0,1,0,100,0),
(@PATH,5,-5739.58,-1130.722,382.5506,0,0,1,0,100,0),
(@PATH,6,-5723.457,-1136.545,383.5298,0,0,1,0,100,0),
(@PATH,7,-5751.005,-1116.793,382.5779,0,0,1,0,100,0),
(@PATH,8,-5758.776,-1098.299,383.0758,0,0,1,0,100,0),
(@PATH,9,-5774.736,-1091.226,383.4236,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306777;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5742.963,`position_y`=-1249.083,`position_z`=384.6432 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5742.963,-1249.083,384.6432,0,0,1,0,100,0),
(@PATH,2,-5738.983,-1261.979,386.6171,0,0,1,0,100,0),
(@PATH,3,-5738.731,-1276.325,387.5499,0,0,1,0,100,0),
(@PATH,4,-5742.226,-1291.769,387.6749,0,0,1,0,100,0),
(@PATH,5,-5749.693,-1301.891,388.358,0,0,1,0,100,0),
(@PATH,6,-5762.46,-1302.306,387.7689,0,0,1,0,100,0),
(@PATH,7,-5773.908,-1302.446,386.854,0,0,1,0,100,0),
(@PATH,8,-5762.46,-1302.306,387.7689,0,0,1,0,100,0),
(@PATH,9,-5749.693,-1301.891,388.358,0,0,1,0,100,0),
(@PATH,10,-5742.226,-1291.769,387.6749,0,0,1,0,100,0),
(@PATH,11,-5738.731,-1276.325,387.5499,0,0,1,0,100,0),
(@PATH,12,-5738.983,-1261.979,386.6171,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306783;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5766.144,`position_y`=-1162.479,`position_z`=377.5511 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5766.144,-1162.479,377.5511,0,0,1,0,100,0),
(@PATH,2,-5789.021,-1176.429,375.3125,0,0,1,0,100,0),
(@PATH,3,-5801.693,-1188.995,377.2677,0,0,1,0,100,0),
(@PATH,4,-5808.819,-1207.913,377.8904,0,0,1,0,100,0),
(@PATH,5,-5804.083,-1225.991,378.8262,0,0,1,0,100,0),
(@PATH,6,-5785.128,-1229.493,377.0928,0,0,1,0,100,0),
(@PATH,7,-5769.268,-1235.165,377.9831,0,0,1,0,100,0),
(@PATH,8,-5751.658,-1237.061,380.6151,0,0,1,0,100,0),
(@PATH,9,-5739.147,-1231.196,382.9025,0,0,1,0,100,0),
(@PATH,10,-5728.825,-1219.927,385.0128,0,0,1,0,100,0),
(@PATH,11,-5721.422,-1205.715,383.4461,0,0,1,0,100,0),
(@PATH,12,-5718.646,-1187.306,382.0042,0,0,1,0,100,0),
(@PATH,13,-5715.497,-1167.271,382.3172,0,0,1,0,100,0),
(@PATH,14,-5713.429,-1147.677,384.0744,0,0,1,0,100,0),
(@PATH,15,-5720.075,-1136.651,383.9358,0,0,1,0,100,0),
(@PATH,16,-5749.646,-1151.609,379.835,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306798;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5825.663,`position_y`=-1058.991,`position_z`=392.2917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5825.663,-1058.991,392.2917,0,0,1,0,100,0),
(@PATH,2,-5833.827,-1068.576,389.1699,0,0,1,0,100,0),
(@PATH,3,-5835.689,-1084.356,384.2365,0,0,1,0,100,0),
(@PATH,4,-5832.859,-1097.396,382.294,0,0,1,0,100,0),
(@PATH,5,-5833.827,-1068.576,389.1699,0,0,1,0,100,0),
(@PATH,6,-5825.663,-1058.991,392.2917,0,0,1,0,100,0),
(@PATH,7,-5823.924,-1047.877,393.3915,0,0,1,0,100,0),
(@PATH,8,-5831.094,-1036.976,394.9936,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306803;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5851.602,`position_y`=-1188.856,`position_z`=382.3286 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5851.602,-1188.856,382.3286,0,0,1,0,100,0),
(@PATH,2,-5858.625,-1186.17,383.188,0,0,1,0,100,0),
(@PATH,3,-5864.24,-1178.568,383.1997,0,0,1,0,100,0),
(@PATH,4,-5859.858,-1190.153,383.5593,0,0,1,0,100,0),
(@PATH,5,-5848.592,-1203.2,384.5098,0,0,1,0,100,0),
(@PATH,6,-5837.806,-1210.144,383.5767,0,0,1,0,100,0),
(@PATH,7,-5827.418,-1219.033,381.6001,0,0,1,0,100,0),
(@PATH,8,-5826.543,-1237.811,380.9523,0,0,1,0,100,0),
(@PATH,9,-5826.927,-1252.259,380.9523,0,0,1,0,100,0),
(@PATH,10,-5831.372,-1263.224,383.0304,0,0,1,0,100,0),
(@PATH,11,-5824.005,-1279.222,382.6616,0,0,1,0,100,0),
(@PATH,12,-5831.372,-1263.224,383.0304,0,0,1,0,100,0),
(@PATH,13,-5826.927,-1252.259,380.9523,0,0,1,0,100,0),
(@PATH,14,-5826.543,-1237.811,380.9523,0,0,1,0,100,0),
(@PATH,15,-5827.418,-1219.033,381.6001,0,0,1,0,100,0),
(@PATH,16,-5837.806,-1210.144,383.5767,0,0,1,0,100,0),
(@PATH,17,-5848.592,-1203.2,384.5098,0,0,1,0,100,0),
(@PATH,18,-5859.858,-1190.153,383.5593,0,0,1,0,100,0),
(@PATH,19,-5864.24,-1178.568,383.1997,0,0,1,0,100,0),
(@PATH,20,-5858.625,-1186.17,383.188,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306824;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5847.749,`position_y`=-1380.556,`position_z`=394.8813 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5847.749,-1380.556,394.8813,0,0,1,0,100,0),
(@PATH,2,-5849.337,-1366.879,393.1101,0,0,1,0,100,0),
(@PATH,3,-5847.759,-1351.507,391.5056,0,0,1,0,100,0),
(@PATH,4,-5845.444,-1340.125,389.5625,0,0,1,0,100,0),
(@PATH,5,-5844.009,-1328.102,388.5746,0,0,1,0,100,0),
(@PATH,6,-5847.759,-1351.507,391.5056,0,0,1,0,100,0),
(@PATH,7,-5849.337,-1366.879,393.1101,0,0,1,0,100,0),
(@PATH,8,-5847.749,-1380.556,394.8813,0,0,1,0,100,0),
(@PATH,9,-5850.45,-1393.993,396.3181,0,0,1,0,100,0),
(@PATH,10,-5859.995,-1415.417,401.1159,0,0,1,0,100,0),
(@PATH,11,-5850.45,-1393.993,396.3181,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306802;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5714.655,`position_y`=-1237.602,`position_z`=388.8025 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5714.655,-1237.602,388.8025,0,0,1,0,100,0),
(@PATH,2,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,3,-5711.893,-1272.75,390.0777,0,0,1,0,100,0),
(@PATH,4,-5715.347,-1285.99,390.1207,0,0,1,0,100,0),
(@PATH,5,-5715.198,-1301.186,391.1804,0,0,1,0,100,0),
(@PATH,6,-5708.863,-1318.491,392.3066,0,0,1,0,100,0),
(@PATH,7,-5707.151,-1348.247,394.9361,0,0,1,0,100,0),
(@PATH,8,-5708.863,-1318.491,392.3066,0,0,1,0,100,0),
(@PATH,9,-5715.198,-1301.186,391.1804,0,0,1,0,100,0),
(@PATH,10,-5715.347,-1285.99,390.1207,0,0,1,0,100,0),
(@PATH,11,-5711.893,-1272.75,390.0777,0,0,1,0,100,0),
(@PATH,12,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,13,-5708.399,-1246.309,389.6016,0,0,1,0,100,0);

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('352220','0','0','0','0','0','29680','0','0','0','Prince marchand Gallywix','','',NULL,'','0','85','85','3','0','0','2159','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','613097436','0','npc_galaw','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('7000001','0','0','0','0','0','15880','0','0','0','meteor','','',NULL,'','0','1','1','3','0','0','35','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','3','1','1','1','1','1','1','1','1','0','0','1','0','0','npc_meteor2_gob','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('7000000','0','0','0','0','0','15880','0','0','0','meteor','','',NULL,'','0','1','1','3','0','0','35','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','3','1','1','1','1','1','1','1','1','0','0','1','0','0','npc_meteor_gob','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('8500000','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_gls_gob','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('850000','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_gls_gob','25549');


replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('2000004','0','0','0','0','0','1126','0','0','0','Creature Damage Limit','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_creature_damage_limit','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470660','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');


replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470661','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470662','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470663','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470664','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470665','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470666','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('470667','0','0','0','0','0','35402','0','0','0','Wing Bridge','','',NULL,'','0','85','85','3','0','0','35','16777216','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_wind_bridge','25549');


UPDATE `creature_template` SET `ScriptName`='npc_gl_gob' WHERE `entry`='35486';
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('530931','0','0','0','0','0','11686','0','0','0','flamewaker hunter helper2','','',NULL,'','0','85','85','3','0','0','2252','33554438','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_flamewaker_hunter_helper2','25549');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('530930','0','0','0','0','0','11686','0','0','0','flamewaker shaman helper','','',NULL,'','0','85','85','3','0','0','2252','33554438','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_flamewaker_shaman_helper','25549');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('531430','0','0','0','0','0','11686','0','0','0','Wild Barrage','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_flamewaker_hunter_helper','25549');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('531431','0','0','0','0','0','11686','0','0','0','flamewaker hunter helper','','',NULL,'','0','85','85','3','0','0','2252','33554438','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_flamewaker_hunter_helper','25549');


replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532971','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532972','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532973','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532974','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532975','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532976','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532977','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532978','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532979','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('532980','0','0','0','0','0','11686','0','0','0','firehawk helper 1','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_firehawk_helper','25549');
DELETE FROM creature WHERE id IN (53297,532971,532972,532973,532974,532975,532976,532977,532978,532979,532980);
REPLACE INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
('53297','861','5733','5745','1','1','0','1','1250.56','534.771','61.5737','0.0494363','300','0','0','58662','0','0','0','0','0'),
('53297','861','5733','5815','1','1','0','1','366.364','-352.425','220.638','6.0083','300','0','0','58662','0','0','0','0','0'),
('532971','861','5733','5811','1','1','0','1','514.87','-467.04','188.76','0','300','0','0','0','0','0','0','0','0'),
('532972','861','5733','5811','1','1','0','1','560.34','-604.76','204.38','0','300','0','0','0','0','0','0','0','0'),
('532973','861','5733','5811','1','1','0','1','892.18','-455.54','237.11','0','300','0','0','0','0','0','0','0','0'),
('532974','861','5733','5811','1','1','0','1','878.91','-371.4','221.36','0','300','0','0','0','0','0','0','0','0'),
('532975','861','5733','5811','1','1','0','1','826.62','-379.41','233.25','0','300','0','0','0','0','0','0','0','0'),
('532976','861','5733','5811','1','1','0','1','804.6','-191.4','254.07','0','300','0','0','0','0','0','0','0','0'),
('532977','861','5733','5811','1','1','0','1','773.41','-325.75','212.82','0','300','0','0','0','0','0','0','0','0'),
('532978','861','5733','5811','1','1','0','1','669.86','-384.36','191.38','0','300','0','0','0','0','0','0','0','0'),
('532979','861','5733','5811','1','1','0','1','598.43','-519.02','192','0','300','0','0','0','0','0','0','0','0'),
('532980','861','5733','5811','1','1','0','1','509.3','-443.67','165.64','0','300','0','0','0','0','0','0','0','0');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(106666, 'spell_madness_of_deathwing_carrying_winds_script_1'),
(106669, 'spell_madness_of_deathwing_carrying_winds_script_2'),
(106671, 'spell_madness_of_deathwing_carrying_winds_script_3'),
(106673, 'spell_madness_of_deathwing_carrying_winds_script_4'),
(106675, 'spell_madness_of_deathwing_carrying_winds_script_5'),
(106677, 'spell_madness_of_deathwing_carrying_winds_script_6');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('794970','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_nerzhul_fly','25549');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('75442','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','shadowmoon_burial_grounds_nhalish_prop','25549');
replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values
('690701','0','0','0','0','0','1126','0','0','0','Bunny','','',NULL,'','0','85','85','3','0','0','2252','16777217','1.5','1.5','1','0','0','2000','2000','0','0','1','16777220','2048','0','0','0','0','0','0','4','2048','0','0','0','0','0','0','0','0','0','0','99587','0','0','0','0','0','0','0','156','0','0','','0','5','1','1','1','1','1','1','7','1','0','0','1','0','0','npc_custom_npc','25549');
UPDATE areatrigger_template SET ScriptName='AreaTrigger_SuppresionField' WHERE Id=151582;
UPDATE areatrigger_template SET ScriptName='areatrigger_aqualir_submerge' WHERE Id=10700;
UPDATE areatrigger_template SET ScriptName='at_warl_rain_of_fire' WHERE Id=5420;
UPDATE areatrigger_template SET ScriptName='at_humongris_make_the_snow' WHERE Id=8538;
UPDATE areatrigger_template SET ScriptName='at_deathtalon_screech' WHERE Id=100010;
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('149959','0','16512','0','0','0','0','0','0','areatrigger_shatter_earth','25567');
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('150050','0','16512','0','0','0','0','0','0','areatrigger_volcanic_trantum','25567');
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('167465','0','16384','0','0','0','0','0','0','areatrigger_magma_barrage','25567');
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('7214','0','16384','0','0','0','0','0','0','areatrigger_roltall_heat_wave','25567');
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('6022','0','16384','0','0','0','0','0','0','areatrigger_roltall_burning_slag','25567');
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('5420','0','16384','0','0','0','0','0','0','at_warl_rain_of_fire','25567');
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('151582','0','16512','0','0','0','0','0','0','AreaTrigger_SuppresionField','25567');
UPDATE areatrigger_template SET ScriptName='at_toxic_gas' WHERE Id=100007;
UPDATE areatrigger_template SET ScriptName='at_bramble_patch' WHERE Id=100009;
UPDATE areatrigger_template SET ScriptName='at_frozen_rain' WHERE Id=100008;
UPDATE `areatrigger_template` SET scriptname = "at_dh_darkness" WHERE id = 6615;
REPLACE into `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) values('6615','0','16512','0','0','0','0','0','0','at_dh_darkness','25567');
UPDATE areatrigger_template SET ScriptName='at_unchecked_growth' WHERE Id=10698;
UPDATE areatrigger_template SET ScriptName='at_flamestrike' WHERE Id=8352;
UPDATE areatrigger_template SET ScriptName='at_noxious_breath' WHERE Id=11908;
UPDATE areatrigger_template SET ScriptName='at_shadow_rune1' WHERE Id=11721;
UPDATE areatrigger_template SET ScriptName='at_shadow_rune2' WHERE Id=11813;
UPDATE areatrigger_template SET ScriptName='at_shadow_rune3' WHERE Id=11353;
UPDATE areatrigger_template SET ScriptName='areatrigger_aqualir_submerge' WHERE Id=172189;
UPDATE `areatrigger_template` SET scriptname = "at_dh_shattered_souls" WHERE id IN (8867, 6710, 6007);
REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES ('7656', 'at_gu_intro');
UPDATE `areatrigger_template` SET scriptname = "at_dh_darkness" WHERE id = 6615;
UPDATE `areatrigger_template` SET scriptname = "at_dh_sigil_of_chains" WHERE id = 6031;
UPDATE `areatrigger_template` SET scriptname = "at_dh_sigil_of_flame" WHERE id = 6039;
UPDATE `areatrigger_template` SET scriptname = "at_dh_sigil_of_silence" WHERE id = 6027;
UPDATE `areatrigger_template` SET scriptname = "at_dh_sigil_of_misery" WHERE id = 6351;
UPDATE `areatrigger_template` SET scriptname = "at_dru_starfall" WHERE id = 4756;
UPDATE `areatrigger_template` SET scriptname = "at_dru_ursols_vortex" WHERE id = 314;
REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5420, 'at_warl_rain_of_fire'),
(5760, 'at_earthen_shield_totem'),
(8359, 'at_first_door'),
(6336, 'at_sha_ancestral_protection_totem'),
(3691, 'at_sha_earthquake_totem'),
(6951, 'at_rog_smoke_bomb'),
(1489, 'at_pri_power_word_barrier'),
(11420, 'areatrigger_black_hole'),
(5484, 'at_monk_song_of_chiji'),
(1316, 'at_monk_chi_burst_damage'),
(2763, 'at_monk_windwalking'),
(1315, 'at_monk_chi_burst_heal'),
(4960, "at_nearby_messenger_torvus"),
(373, 'at_monk_gift_of_the_ox_sphere'),
(6615, 'at_dh_darkness'),
(7126, 'areatrigger_at_shadopan_archery'),
(5806,'at_tott_first_tunnel'),
(6281,'at_return_wind'),
(89104, 'at_reletness_storm'),
(149959, 'areatrigger_shatter_earth'),
(6039, 'at_dh_sigil_of_flame'),
(6351, 'at_dh_sigil_of_misery'),
(6027, 'at_dh_sigil_of_silence'),
(2200, 'at_arcane_orb'),
(151582, 'AreaTrigger_SuppresionField'),
(6710, 'at_dh_shattered_souls'),
(6007, 'at_dh_shattered_souls'),
(6031, 'at_dh_sigil_of_chains'),
(983, 'at_dru_solar_beam'),
(4756, 'at_dru_starfall'),
(314, 'at_dru_ursols_vortex'),
(6022, 'areatrigger_roltall_burning_slag'),
(7214, 'areatrigger_roltall_heat_wave'),
(7214, 'Instances::Bloodmaul::areatrigger_roltall_heat_wave'),
(6022, 'Instances::Bloodmaul::areatrigger_roltall_burning_slag'),
(7455, 'Instances::Bloodmaul::areatrigger_magma_barrage'),
(5559, 'Instances::Bloodmaul::areatrigger_volcanic_trantum'),
(5555, 'Instances::Bloodmaul::areatrigger_shatter_earth'),
(151582, 'Instances::Bloodmaul::AreaTrigger_SuppresionField'),
(1315, 'at_monk_chi_burst_heal'),
(1946, "at_nearby_scarshield_infiltrator"),
(12167, "at_nearby_scarshield_infiltrator"),
(12802, "areatrigger_void_devestation"),
(4991, 'at_skadi_gaunlet'),
(5580, 'at_pit_cavern_entrance'),
(5581, 'at_pit_cavern_end');

REPLACE INTO spell_script_names VALUES ('151990', 'spell_ChainGrip');
REPLACE INTO spell_script_names VALUES ('151581', 'spell_SuppressionField');
REPLACE INTO spell_script_names VALUES ('150759', 'spell_FerociousYell');
REPLACE INTO spell_script_names VALUES ('150801', 'spell_RaiseTheMiners');
REPLACE INTO spell_script_names VALUES ('151698', 'spell_VolcanicEruption');
REPLACE INTO spell_script_names VALUES ('152809', 'spell_LavaSplash');

REPLACE INTO spell_script_names VALUES
(149941, "spell_rough_smash"),
(158564, "spell_deathtalon_quills"),
(150324, "spell_shatter_earth"),
(177297, "spell_aura_void_realm"),
(46668, "spell_darkmoon_carousel_whee"),
(83883,'spell_q26861_door_dummy'),
(66298, 'spell_klaxon'),
(150324, "spell_shatter_earth"),
(149975, "spell_dancing_flames"),
(150032, "spell_withering_flames"),
(150045, "spell_molten_impact"),
(150004, "spell_magma_barrage"),
(150007, "spell_magma_barrage_trigger"),
(150306, "spell_magma_barrage_trigger"),
(148852,"spell_groog_rampage"),
(150004, "spell_magma_barrage"),
(167738, "spell_roltall_scorching_aura"),
(212889, "spell_nithogg_static_charge_summon"),
(151581, "spell_SuppressionField"),
(188520, "spell_tanaan_fel_sludge"),
(169421, "spell_frostridge_claiming"),
(212837, "spell_nithogg_crackling_jolt_target"),
(212841, "spell_nithogg_crackling_jolt_damage"),
(212867, "spell_nithogg_electrical_storm_target"),
(212836, "spell_nithogg_tail_lash"),
(102112, "spell_darkmoon_canon_preparation"),
(101260, "spell_darkmoon_staging_area_teleport"),
(101604, "spell_whack_gnoll_whack"),
(101612, "spell_whack_gnoll_override_action"),
(177301, "spell_use_effigy"),
(151990, "spell_ChainGrip"),
(169125, "spell_genesis"),
(169390, "spell_genesis_missile"),
(152792, "spell_shadowmoon_burial_grounds_void_blast"),
(152801, "spell_shadowmoon_burial_grounds_void_vortex"),
(164546, "spell_pilar_of_flames"),
(92042, 'spell_coalesce_achievement'),
(87897, 'spell_glubtok_generic_proc'),
(87900, 'spell_glubtok_generic_proc'),
(91397, 'spell_glubtok_firewall_targetting'),
(109317, 'spell_dragon_soul_lieutenant_shara_frozen_grasp'),
(104448, 'spell_hagara_the_stormbinder_icy_tomb_aoe'),
(104449, 'spell_hagara_the_stormbinder_icy_tomb_dummy'),
(104451, 'spell_hagara_the_stormbinder_icy_tomb'),
(105287, 'spell_hagara_the_stormbinder_ice_lance_target'),
(105367, 'spell_hagara_the_stormbinder_crystal_conduit_target'),
(109557, 'spell_hagara_the_stormbinder_storm_pillars'),
(107439, 'spell_warmaster_blackhorn_twilight_barrage_dmg'),
(109203, 'spell_warmaster_blackhorn_twilight_barrage_dmg'),
(109204, 'spell_warmaster_blackhorn_twilight_barrage_dmg'),
(109205, 'spell_warmaster_blackhorn_twilight_barrage_dmg'),
(106401, 'spell_warmaster_blackhorn_twilight_onslaught_dmg'),
(108862, 'spell_warmaster_blackhorn_twilight_onslaught_dmg'),
(109226, 'spell_warmaster_blackhorn_twilight_onslaught_dmg'),
(109227, 'spell_warmaster_blackhorn_twilight_onslaught_dmg'),
(107595, 'spell_warmaster_blackhorn_blade_rush_dmg'),
(109013, 'spell_warmaster_blackhorn_blade_rush_dmg'),
(109014, 'spell_warmaster_blackhorn_blade_rush_dmg'),
(109015, 'spell_warmaster_blackhorn_blade_rush_dmg'),
(110214, 'spell_warmaster_blackhorn_consuming_shroud'),
(110598, 'spell_warmaster_blackhorn_consuming_shroud'),
(108045, 'spell_warmaster_blackhorn_vengeance'),
(110137, 'spell_warmaster_blackhorn_shockwave_aoe'),
(110153, 'spell_warmaster_blackhorn_broadside'),
(52343,'spell_gatewatcher_subboss_trigger'),
(92067, 'spell_council_static_overload'),
(72887, 'spell_boot_damage'),
(46050, "spell_summon_blood_elves_script"),
(46269, "spell_muru_darkness"),
(45934, "spell_dark_fiend_skin"),
(46205, "spell_transform_visual_missile_periodic"),
(46041, "spell_summon_blood_elves_periodic"),
(82746, "spell_council_glaciate"),
(83067, "spell_council_thundershock"),
(83565, "spell_council_quake"),
(82636, "spell_council_rising_flames"),
(82660, "spell_council_burning_blood"),
(82665, "spell_council_heart_of_ice"),
(84914, "spell_council_liquid_ice"),
(83603, "spell_halfus_stone_touch"),
(84593, "spell_halfus_stone_grip"),
(89421, "spell_sinestra_wreck"),
(89435, "spell_sinestra_wrack_jump"),
(92851, "spell_sinestra_twilight_slicer"),
(89284, "spell_sinestra_twilight_essence"),
(87323, "spell_sinestra_phyrric_focus"),
(86408, "spell_dazzling_destruction"),
(86840, "spell_devouring_flame"),
(93055, "spell_shifting_reality"),
(91317, "spell_whorshipping"),
(81713, "spell_depravity"),
(82919, "spell_sprayed_corruption"),
(81757, "spell_spilled_blood_of_the_old_god"),
(81685, "spell_corrupting_crash"),
(82361, "spell_corruption_of_the_old_god"),
(82411, "spell_debilitating_beam"),
(81836, "spell_corruption_accelerated"),
(93202, "spell_corruption_sickness"),
(92053, "spell_shadow_conductor"),
(88287, "spell_magmaw_massive_crash"),
(82705, "spell_finkles_mixture"),
(77569, "spell_release_abberations"),
(77991, "spell_release_all_abberations"),
(78098, "spell_atramedes_sonic_breath"),
(77827, "spell_nefarian_tail_lash"),
(77944, "spell_onyxia_lightning_discharge"),
(89267, "spell_captain_cookie_setiated"),
(89732, "spell_captain_cookie_nauseated"),
(89268, "spell_captain_cookie_throw_food_targeting"),
(89740, "spell_captain_cookie_throw_food_targeting"),
(90561, "spell_captain_cookie_throw_food_targeting"),
(90582, "spell_captain_cookie_throw_food_targeting"),
(90562, "spell_captain_cookie_throw_food_targeting"),
(90583, "spell_captain_cookie_throw_food_targeting"),
(90563, "spell_captain_cookie_throw_food_targeting"),
(90584, "spell_captain_cookie_throw_food_targeting"),
(90564, "spell_captain_cookie_throw_food_targeting"),
(90585, "spell_captain_cookie_throw_food_targeting"),
(90565, "spell_captain_cookie_throw_food_targeting"),
(90586, "spell_captain_cookie_throw_food_targeting"),
(74846, "spell_bleeding_wound"),
(74634, "spell_ground_siege"),
(75664, "spell_shadow_gale_damage"),
(74976, "spell_disoriented_roar"),
(93757, "spell_ashbury_archangel"),
(93423, "spell_ashbury_asphyxoate_periodic"),
(93857, "spell_summon_worgen_spirits"),
(91436, "spell_springvale_forsaken_ability"),
(91442, "spell_springvale_forsaken_ability"),
(91444, "spell_springvale_forsaken_ability"),
(93573, "spell_toxic_coagulant_red"),
(93572, "spell_toxic_coagulant_green"),
(93520, "spell_pistol_barrage_trigger"),
(93564, "spell_pistol_barrage"),
(93707, "spell_godfrey_summon_ghouls"),
(76047, "spell_ulthok_dark_fissure"),
(73000, 'spell_boot_gob'),
(60510, 'spell_item_soul_preserver'), 
(164615, 'spell_bloodmaul_channel_flames'),
(8344, 'spell_item_universal_remote'),
(133, 'spell_mastery_ignite'),
(2948, 'spell_mastery_ignite'),
(11366, 'spell_mastery_ignite'),
(44614, 'spell_mastery_ignite'),
(108853, 'spell_mastery_ignite'),
(67799, 'spell_item_mind_control_cap'),
(13180, 'spell_item_mind_control_cap'),
(150759, 'spell_FerociousYell'),
(24778, 'spell_dream_fog_sleep'),
(25042, 'spell_mark_of_nature'),
(37657, 'spell_item_lightning_capacitor'),
(54841, 'spell_item_thunder_capacitor'), 
(67712, 'spell_item_toc25_normal_caster_trinket'),      -- Item - Coliseum 25 Normal Caster Trinket
(67758, 'spell_item_toc25_heroic_caster_trinket'),      -- Item - Coliseum 25 Heroic Caster Trinket
(57345, 'spell_item_darkmoon_card_greatness'),
(51640, 'spell_item_taunt_flag_targeting'),
(109894, 'spell_yorsahj_the_unsleeping_whisper'),
(109895, 'spell_yorsahj_the_unsleeping_whisper'),
(109896, 'spell_yorsahj_the_unsleeping_whisper'),
(109897, 'spell_yorsahj_the_unsleeping_whisper'),
(109898, 'spell_yorsahj_the_unsleeping_whisper'),
(103628, 'spell_yorsahj_the_unsleeping_deep_corruption'),
(105571, 'spell_yorsahj_the_unsleeping_digestive_acid_aoe'),
(105530, 'spell_yorsahj_the_unsleeping_mana_void'),
(73002, "spell_font_life"),
(169382, "spell_gaseous_volley"),
(168378, "spell_grasping_vine_jump"),
(172578, "spell_bounding_whirl"),
(46282, "spell_black_hole"),
(164294, "spell_unchecked_growth"),
(170759, "spell_toxic_blood"),
(103434, 'spell_warlord_zonozz_disrupting_shadows'),
(104599, 'spell_warlord_zonozz_disrupting_shadows'),
(104600, 'spell_warlord_zonozz_disrupting_shadows'),
(104601, 'spell_warlord_zonozz_disrupting_shadows'),
(105367, 'spell_hagara_the_stormbinder_lightning_conduit'),
(103958, 'spell_warl_metamorphosis_cost'),
(59915,  'spell_item_discerning_eye_beast_dummy'),
(47960, 'spell_warl_molten_core_dot'),
(70656, 'spell_dk_advantage_t10_4p'),                   -- DK Advantage t10 4p melee
(37336, 'spell_dru_forms_trinket'),                     -- Druid Forms Trinket
(64568, 'spell_gen_blood_reserve'),                     -- Blood Reserve (weapon enchant proc)
(67151, 'spell_hun_t9_4p_bonus'),                       -- Hunter T9 Bonus
(71201, 'spell_igb_battle_experience_check'),           -- Battle Experience (Gunship - ICC)
(60510, 'spell_item_soul_preserver'),                   -- Soul Preserver
(67702, 'spell_item_death_choice'),                     -- Death Choice Trinket
(67771, 'spell_item_death_choice'),                     -- Death Choice Trinket
(37657, 'spell_item_lightning_capacitor'),              -- Lightning Capcitor
(54841, 'spell_item_thunder_capacitor'),                -- Thunder Capacitor
(67712, 'spell_item_toc25_normal_caster_trinket'),      -- Item - Coliseum 25 Normal Caster Trinket
(67758, 'spell_item_toc25_heroic_caster_trinket'),      -- Item - Coliseum 25 Heroic Caster Trinket
(57345, 'spell_item_darkmoon_card_greatness'),          -- Darkmoon Card: Greatness
(27522, 'spell_item_mana_drain'),                       -- Mana Drain
(40336, 'spell_item_mana_drain'),                       -- Mana Drain
(70805, 'spell_rog_t10_2p_bonus'),
(86788, 'spell_blackout'),
(92876, 'spell_blackout'),
(92877, 'spell_blackout'),
(92878, 'spell_blackout'),
(122852, 'spell_inhale'),
(86631, 'spell_engulfing_magic'),
(59262, "spell_npc_warl_demonic_gateway_green"),
(59271, "spell_npc_warl_demonic_gateway_purple"),
(85717, "spell_firebloom_target"),
(7448, "spell_fire"),
(168375, "spell_grasping_vine"),
(167966, "spell_bramble_patch"),
(165213, "spell_enraged_growth"),
(35244, "spell_choking_vines"),
(177731, "spell_agitated_water"),
(79683, "spell_entanglement_missile"),
(164834, "spell_barrage_of_leaves"),
(36300, "spell_growth"),
(170411, "spell_spore_breath"),
(153686, "spell_shadowmoon_burial_grounds_body_slam"),
(153689, "spell_shadowmoon_burial_grounds_necrotic_pitch"),
(165578, "spell_shadowmoon_burial_grounds_corpse_breath"),
(154010, "spell_shadowmoon_burial_grounds_drowned"),
(114790, 'spell_warl_soulburn_seed_of_corruption'),
(342521, "shadowmoon_burial_grounds_initial_teleport"),
(109468, 'spell_warl_soulburn_remove'),
(104225, 'spell_warl_soulburn_remove'),
(104223, 'spell_warl_soulburn_remove'),
(152962, "shadowmoon_burial_grounds_soul"),
(153068, "spell_shadowmoon_burial_grounds_void_devestation_trigger"),
(534556, "shadowmoon_burial_grounds_ritual_of_bones_darkness_trigger"),
(153623, "spell_shadowmoon_burial_grounds_planar_shift"),
(152962, "spell_shadowmoon_burial_grounds_soul_steal"),
(170404, "spell_vine_pull"),
(87385, 'spell_warl_soulburn_seed_of_corruption_damage'),
(105658, "spell_madness_of_deathwing_elementium_meteor_summon"),
(105862, "spell_madness_of_deathwing_hemorrhage_script"),
(66512,'spell_q14076_14092_pound_drum'),
(43375, "spell_q11306_mixing_vrykul_blood"),
(48794,'spell_q12279_cast_net'),
(43972, "spell_q11306_mixing_blood"),
(59064, 'spell_59064_59439_portals'),
(59439, 'spell_59064_59439_portals'),
(170016, "aura_glowbulb_pollen"),
(81782, "aura_barrier"),
(170400, "spell_vine_pull"),
(169847, "spell_frozen_snap"),
(177731, "spell_agitated_water_trig"),
(221335, "aura_archmage_barrier"),
(168375, "aura_grasping_vine"),
(43378, "spell_q11306_failed_mix_43378"),
(43376, "spell_q11306_failed_mix_43376"),
(17767, "spell_warl_shadow_bulwark"),
(74434, "spell_warl_soulburn_override"),
(107018, "spell_madness_of_deathwing_assault_aspects"),
(106382, "spell_madness_of_deathwing_crush_force"),
(105723, "spell_madness_of_deathwing_elementium_blast"),
(108597, "spell_madness_of_deathwing_corrupting_parasite_aoe"),
(108649, "spell_madness_of_deathwing_corrupting_parasite_aura"),
(106548, "spell_madness_of_deathwing_agonizing_pain"),
(107029, "spell_madness_of_deathwing_impale_aspect"),
(106789, "spell_madness_of_deathwing_shrapnel_aoe"),
(108813, "spell_madness_of_deathwing_unstable_corruption"),
(586, 'spell_pri_fade'),
(108416, 'spell_warl_dark_pact'),
(703, 'spell_rog_cloak_and_dagger'),
(1833, 'spell_rog_cloak_and_dagger'),
(8676, 'spell_rog_cloak_and_dagger'),
(20217,'spell_pal_blessing_of_kings'),
(108359, 'spell_warl_dark_regeneration'),
(21562,'spell_pri_power_word_fortitude'),
(7744,  'spell_wotf_shared_cd'),
(27683,'spell_pri_shadow_protection'),
(7744,  'spell_wotf_shared_cd'),
(42292, 'spell_pvp_trinket_shared_cd'),
(59752, 'spell_pvp_trinket_shared_cd'),
(100,    'spell_gen_trigger_exclude_target_aura_spell'),
(172,    'spell_gen_trigger_exclude_caster_aura_spell'),
(1454,   'spell_gen_trigger_exclude_caster_aura_spell'),
(2823,   'spell_gen_trigger_exclude_target_aura_spell'),
(3411,   'spell_gen_trigger_exclude_target_aura_spell'),
(31790,  'spell_gen_trigger_exclude_target_aura_spell'),
(36554,  'spell_gen_trigger_exclude_target_aura_spell'),
(49376,  'spell_gen_trigger_exclude_target_aura_spell'),
(77606,  'spell_gen_trigger_exclude_caster_aura_spell'),
(79830,  'spell_gen_trigger_exclude_target_aura_spell'),
(82828,  'spell_gen_trigger_exclude_target_aura_spell'),
(100780, 'spell_gen_trigger_exclude_caster_aura_spell'),
(100784, 'spell_gen_trigger_exclude_caster_aura_spell'),
(100950, 'spell_gen_trigger_exclude_target_aura_spell'),
(102416, 'spell_gen_trigger_exclude_target_aura_spell'),
(102417, 'spell_gen_trigger_exclude_target_aura_spell'),
(119996, 'spell_gen_trigger_exclude_caster_aura_spell'),
(121471, 'spell_gen_trigger_exclude_caster_aura_spell'),
(122506, 'spell_gen_trigger_exclude_target_aura_spell'),
(131632, 'spell_gen_trigger_exclude_caster_aura_spell'),
(143395, 'spell_gen_trigger_exclude_caster_aura_spell'),
(145158, 'spell_gen_trigger_exclude_caster_aura_spell'),
(146739, 'spell_gen_trigger_exclude_caster_aura_spell'),
(159607, 'spell_gen_trigger_exclude_caster_aura_spell'),
(178338, 'spell_gen_trigger_exclude_caster_aura_spell'),
(193549, 'spell_gen_trigger_exclude_target_aura_spell'),
(194834, 'spell_gen_trigger_exclude_caster_aura_spell'),
(195457, 'spell_gen_trigger_exclude_target_aura_spell'),
(198304, 'spell_gen_trigger_exclude_target_aura_spell'),
(198337, 'spell_gen_trigger_exclude_target_aura_spell'),
(198758, 'spell_gen_trigger_exclude_target_aura_spell'),
(200153, 'spell_gen_trigger_exclude_caster_aura_spell'),
(205523, 'spell_gen_trigger_exclude_caster_aura_spell'),
(212284, 'spell_gen_trigger_exclude_caster_aura_spell'),
(213398, 'spell_gen_trigger_exclude_caster_aura_spell'),
(213831, 'spell_gen_trigger_exclude_caster_aura_spell'),
(219779, 'spell_gen_trigger_exclude_caster_aura_spell'),
(20484,  'spell_gen_trigger_exclude_target_aura_spell'),
(20707,  'spell_gen_trigger_exclude_target_aura_spell'),
(61999,  'spell_gen_trigger_exclude_target_aura_spell'),
(126393, 'spell_gen_trigger_exclude_target_aura_spell'),
(159931, 'spell_gen_trigger_exclude_target_aura_spell'),
(159956, 'spell_gen_trigger_exclude_target_aura_spell'),
(226277, 'spell_gen_trigger_exclude_target_aura_spell'),
(52408, 'spell_gen_seaforium_blast'),
(57669,'spell_gen_replenishment'),
(61782,'spell_gen_replenishment'),
(1126, 'spell_dru_mark_of_the_wild'),
(19740,'spell_pal_blessing_of_might'),
(58630,'spell_gen_dungeon_credit'),
(28764,  'spell_gen_adaptive_warding'),
(101588, 'spell_flarecore_periodic'),
(131474,'spell_gen_fishing'),
(103558, 'spell_choking_smoke_bomb'),
(101625, "spell_pulverize"),
(101588, "spell_flarecore"),
(102726, "spell_mark_of_silence"),
(103597, "spell_throw_knife"),
(103419, "spell_blade_barrier"),
(102480, "spell_icy_boulder"),
(103678, "spell_wave_of_virtue"),
(104516, "spell_seaping_light"),
(108374, "spell_rising_fire_totem"),
(103819, "spell_rising_fire_totem"),
(119626, 'spell_sha_of_anger_aggressive_behaviour'),
(122169, "spell_ook_ook_barrel_ride"),
(136350, 'spell_lightning_tether'),
(106787, "spell_stormstout_brewery_habanero_beer"),
(138390, 'spell_alpha_male_threat'),
(71289,'spell_deathwhisper_dominated_mind'),
(72478,'spell_deathwhisper_summon_spirits'),
(70827, 'spell_pos_ice_shards'),
(66676, 'spell_ioc_seaforium_blast_credit'),
(66672, 'spell_ioc_seaforium_blast_credit'),
(121114, 'spell_resin_weaving'),
(59275, 'spell_summon_gauntlet_mobs_periodic'),
(48642, 'spell_skadi_launch_harpoon'),
(49308, 'spell_skadi_reset_check'),
(61678, 'spell_z_check'),
(49107, 'spell_vehicle_warhead_fuse'),
(49250, 'spell_warhead_detonate'),
(49181, 'spell_warhead_fuse'),
(75886, 'spell_halion_blazing_aura'),
(75887, 'spell_halion_blazing_aura'),
(74803, 'spell_halion_combustion_consumption_periodic'),
(74629, 'spell_halion_combustion_consumption_periodic'),
(120559, 'spell_rimok_saboteur_bombard'),
(59275, 'spell_summon_gauntlet_mobs_periodic'),
(72868,'spell_putricide_slime_puddle_aura'),
(72869,'spell_putricide_slime_puddle_aura'),
(50255, 'spell_skadi_poisoned_spear'),
(59331, 'spell_skadi_poisoned_spear'),
(47594, 'spell_freezing_cloud_area_right'),
(47574, 'spell_freezing_cloud_area_left'),
(47579, 'spell_freezing_cloud_damage'),
(60020, 'spell_freezing_cloud_damage'),
(59275, 'spell_summon_gauntlet_mobs_periodic'),
(48642, 'spell_skadi_launch_harpoon'),
(49308, 'spell_skadi_reset_check'),
(120552, 'spell_kiptilak_munitions_explosion'),
(107268, 'spell_kiptilak_sabotage'),
(107343, 'spell_gadok_strafing'),
(111698, 'spell_shadopan_apparitions'),
(115055, 'spell_shadopan_explosion'),
(115010, 'spell_taran_zhu_grip_of_hate'),
(107085, 'spell_taran_zhu_hate'),
(107200, 'spell_taran_zhu_meditation'),
(106933, 'spell_prey_time'),
(111129, 'spell_overcharged_soul_damage'),
(120142, 'spell_dart'),
(119311, 'spell_dart'),
(119314, 'spell_dart'),
(119337, 'spell_dart'),
(119338, 'spell_dart'),
(123127, 'spell_dart'),
(123128, 'spell_dart'),
(124320, 'spell_dart'),
(124321, 'spell_dart'),
(114927, 'spell_kill_guardians'),
(24750, 'spell_trick'),
(24751, 'spell_trick_or_treat'),
(44436, 'spell_tricky_treat'),
(75071,'spell_effect_fix'),
(78741, 'spell_omnotron_active_trigger'),
(28410,"spell_kelthuzad_chains"),
(66406,'spell_gormok_snobolled'),
(66245,'spell_gormok_ride_player'),
(66342,'spell_gormok_jump_to_hand'),
(66406,'spell_gormok_snobolled'),
(8283, "spell_snufflenose_command"),
(153268, "spell_exhume_the_crypts"),
(153276, "spell_exhume_the_crypts"),
(177694, "spell_water_burst_targeting"),
(66545, 'spell_paletress_summon_memory'),
(66493,'spell_fel_streak_visual'),
(53472,"spell_anubarak_pound"),
(59433,"spell_anubarak_pound"),
(53520,"spell_anubarak_carrion_beetles"),
('88427', 'spell_electrocute'),
('93261', 'spell_wind_burst'),
('93262', 'spell_wind_burst'),
('93263', 'spell_wind_burst'),
('93297', 'spell_lightning_clouds_damage'),
('93298', 'spell_lightning_clouds_damage'),
('93299', 'spell_lightning_clouds_damage'),
('89588', 'spell_lightning_clouds_damage'),
('93255', 'spell_lightning_strike'),
('93256', 'spell_lightning_strike'),
('93257', 'spell_lightning_strike'),
('88214', 'spell_lightning_strike'),
('88238', 'spell_lightning_strike_effect'),
('93854', 'spell_lightning_strike_effect'),
('93855', 'spell_lightning_strike_effect'),
('93856', 'spell_lightning_strike_effect'),
('85422', 'spell_nurture_aura'),
('85429', 'spell_nurture_aura'),
('86367', 'spell_nezir_sleet_storm'),
('93135', 'spell_nezir_sleet_storm'),
('93136', 'spell_nezir_sleet_storm'),
('93137', 'spell_nezir_sleet_storm'),
('85483', 'spell_wind_blast'),
('93138', 'spell_wind_blast'),
('93139', 'spell_wind_blast'),
('89104', 'at_reletness_storm'),
('93140', 'spell_wind_blast'),
(83113, 'spell_bad_intentions'),
(83236, 'spell_hurl'),
(97282, 'spell_lord_rhyolith_conclusive_stomp'),
(100411, 'spell_lord_rhyolith_conclusive_stomp'),
(100968, 'spell_lord_rhyolith_conclusive_stomp'),
(100969, 'spell_lord_rhyolith_conclusive_stomp'),
(97225, 'spell_lord_rhyolith_magma_flow'),
(99875, 'spell_lord_rhyolith_fuse'),
(98034, 'spell_lord_rhyolith_drink_magma'),
(98276, 'spell_lord_rhyolith_lava_strike'),
(99052, 'spell_bethtilac_smoldering_devastation'),
(98934, 'spell_bethtilac_ember_flare'),
(100648, 'spell_bethtilac_ember_flare'),
(100834, 'spell_bethtilac_ember_flare'),
(100835, 'spell_bethtilac_ember_flare'),
(98471, 'spell_bethtilac_burning_acid'),
(100826, 'spell_bethtilac_burning_acid'),
(100827, 'spell_bethtilac_burning_acid'),
(100828, 'spell_bethtilac_burning_acid'),
(101223, 'spell_alysrazor_fieroblast'),
(101294, 'spell_alysrazor_fieroblast'),
(101295, 'spell_alysrazor_fieroblast'),
(101296, 'spell_alysrazor_fieroblast'),
(100640, 'spell_alysrazor_harsh_winds'),
(97128, 'spell_alysrazor_molten_feather'),
(97734, 'spell_alysrazor_molten_feather_script'),
(102111, 'spell_alysrazor_cataclysm'),
(101111, 'spell_shannox_riplimb_dogged_determination'),
(99837, 'spell_shannox_crystal_prison_trap'),
(99838, 'spell_shannox_immolation_trap'),
(101208, 'spell_shannox_immolation_trap'),
(101209, 'spell_shannox_immolation_trap'),
(101210, 'spell_shannox_immolation_trap'),
(99693, 'spell_firelands_ancient_core_hound_dinner_time'),
(99736, 'spell_firelands_ancient_core_hound_flame_breath'),
(97549, 'spell_firelands_ancient_lava_dweller_lava_shower'),
(100263, 'spell_firelands_fire_turtle_hatchling_shell_spin'),
(100797, 'spell_firelands_flame_archon_fiery_torment'),
(99555, 'spell_firelands_molten_lord_summon_lava_jets'),
('74136', 'spell_isiset_supernova'),
(98451, 'spell_staghelm_burning_orbs'),
(98450, 'spell_staghelm_searing_seeds_aura'),
(104621, 'spell_spine_of_deathwing_roll_control_check'),
(109379, 'spell_spine_of_deathwing_searing_plasma_aoe'),
(105845, 'spell_spine_of_deathwing_nuclear_blast'),
(105241, 'spell_spine_of_deathwing_absorb_blood'),
(105846, 'spell_spine_of_deathwing_nuclear_blast_script'),
(106199, 'spine_of_deathwing_blood_corruption'),
(106200, 'spine_of_deathwing_blood_corruption'),
(105777, 'spine_of_deathwing_roll_control'),
(106199, 'spell_spine_of_deathwing_blood_corruption'),
(106200, 'spell_spine_of_deathwing_blood_corruption'),
(106199, 'spell_spine_of_deathwing_blood_corruption_death'),
(105777, 'spell_spine_of_deathwing_roll_control'),
(106199, 'spell_spine_of_deathwing_blood_corruption'),
(106200, 'spell_spine_of_deathwing_blood_corruption'),
(106199, 'spell_spine_of_deathwing_blood_corruption_death'),
(26375, "spell_lunar_festival_invitation"),
(45276, "spell_hol_torch_launch_achievement"),
(98518, "spell_molten_inferno"),
(153153, "spell_shadowmoon_burial_grounds_dark_communion"),
(164685, "spell_shadowmoon_burial_grounds_dark_eclipse"),
(164686, "spell_shadowmoon_burial_grounds_dark_eclipse_damage"),
(153224, "spell_shadowmoon_burial_grounds_shadow_burn"),
(86295, 'spell_storms_edge_aura'),
(86284, 'spell_storms_edge_periodic'),
(86329, 'spell_storms_edge_pull'),
(86311, 'spell_storms_edge_knockback'),
(86299, 'spell_storms_edge'),
(88244,'spell_wind_of_alth'),
(98229, 'spell_staghelm_concentration_aura'),
(107796, 'spell_dragon_soul_ancient_water_lord_flood'),
(107596, 'spell_dragon_soul_earthen_destroyer_boulder_smash'),
(109389, 'spell_dragon_soul_shadowed_globule_deep_corruption'),
(108222, 'spell_dragon_soul_cobalt_globule_mana_void'),
(109233, "spell_dragon_soul_claw_of_gorath_tentacle_toss_aoe_1"),
(109243, "spell_dragon_soul_claw_of_gorath_tentacle_toss_aoe_2"),
(109325, 'spell_hagara_the_stormbinder_frostflake'),
(100745, 'spell_alysrazor_firestorm'),
(101664, 'spell_alysrazor_firestorm'),
(101665, 'spell_alysrazor_firestorm'),
(101666, 'spell_alysrazor_firestorm'),
(66902,'spell_jormungars_burning_spray'), -- Burning Spray 10m normal
(67627,'spell_jormungars_burning_spray'), -- Burning Spray 25m normal
(67628,'spell_jormungars_burning_spray'), -- Burning Spray 10m heroic
(67629,'spell_jormungars_burning_spray'), -- Burning Spray 25m heroic
(66901,'spell_jormungars_paralytic_spray'), -- Paralytic Spray 10m normal
(67615,'spell_jormungars_paralytic_spray'), -- Paralytic Spray 25m normal
(67616,'spell_jormungars_paralytic_spray'), -- Paralytic Spray 10m heroic
(67617,'spell_jormungars_paralytic_spray'), -- Paralytic Spray 25m heroic
(66823,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 10m normal
(67618,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 25m normal
(67619,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 10m heroic
(67620,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 25m heroic
(66830,'spell_jormungars_paralysis'), -- Paralysis
(65032,  'spell_xt002_321_boombot_aura'),
(53035,"spell_hadronox_periodic_summon_champion"),
(53037,"spell_hadronox_periodic_summon_crypt_fiend"),
(53036,"spell_hadronox_periodic_summon_necromancer"),
(53030,"spell_hadronox_leeching_poison"),
(59417,"spell_hadronox_leeching_poison"),
(53177,"spell_hadronox_web_doors"),
(53185,"spell_hadronox_web_doors"),
(88282, 'spell_altairus_upwind_of_altairus'),
(88286, 'spell_altairus_downwind_of_altairus'),
(87618, 'spell_asaad_static_cling'),
(87474, 'spell_asaad_grounding_field'),
(86715, 'spell_asaad_supremacy_dummy'),
(87553, 'spell_asaad_grounding_damage'),
(93994, 'spell_asaad_grounding_damage'),
(87518, 'spell_asaad_supremacy_of_the_storm_summon'),
(86284, 'spell_ertan_storms_edge'),
(86299, 'spell_ertan_storms_edge_triggered'),
(86311, 'spell_ertan_storms_edge_triggered'),
(86310, 'spell_ertan_storms_edge_knockback'),
(81642, 'spell_dust_flail'),
(82168, 'spell_repentance_pull_player'),
(82009, 'spell_repentance_trigger_clone_spell'),
(81960, 'spell_repentance_trigger_clone_spell'),
(82220, 'spell_repentance_trigger_clone_spell'),
(69893, 'spell_copy_melee_weapon'),
(81947, 'spell_repentance_player_kneel'),
(81958, 'spell_repentance_player_summon_mirror'),
(82215, 'spell_repentance_player_summon_mirror'),
(83566, 'spell_wailing_winds'),
(84982, 'spell_gathered_storms'),
(91872, 'spell_gathered_storms_trigger_cast'),
(91871, 'spell_gathered_storms_trigger_cast'),
(109176, 'spell_ultraxion_twilight_instability'),
(103327, 'spell_ultraxion_hour_of_twilight_dmg'),
(105925, 'spell_ultraxion_fading_light'),
(110070, 'spell_ultraxion_fading_light'),
(110069, 'spell_ultraxion_fading_light'),
(110068, 'spell_ultraxion_fading_light'),
(109075, 'spell_ultraxion_fading_light'),
(110080, 'spell_ultraxion_fading_light'),
(110079, 'spell_ultraxion_fading_light'),
(110078, 'spell_ultraxion_fading_light'),
(106162, 'spell_ultraxion_last_defender_of_azeroth'),
(110327, 'spell_ultraxion_last_defender_of_azeroth_dummy'),
(106108, 'spell_ultraxion_heroic_will'),
(105984, 'spell_ultraxion_time_loop'),
(104905, 'spell_perotharn_drain_essence'),
(104906, 'spell_perotharn_drain_essence_dmg'),
(107536, 'spell_perotharn_punishing_flames_dmg'),
(102465, 'spell_queen_azshara_coldflame'),
(104998, 'spell_mannoroth_gift_of_sargeras'),
(55931, 'spell_prince_taldaram_conjure_flame_sphere'),
(55895, 'spell_prince_taldaram_flame_sphere_summon'),
(59511, 'spell_prince_taldaram_flame_sphere_summon'),
(59512, 'spell_prince_taldaram_flame_sphere_summon'),
(52536,"spell_anub_ar_skirmisher_fixtate"),
(52086,"spell_gatewatcher_web_wrap"),
(86930,'spell_asaad_supremacy_entry'),
(52658, "static_overload"),
(59795, "static_overload"),
(130255, "spell_hol_launch_beer"),
(41621, "spell_hol_wolpertinger_net"),
(128956, "spell_hol_belier_base"),
(163946, "spell_hol_belier_renes"),
(164253, "spell_hol_belier_all_speeds"),
(101285, "spell_hol_beliers"),
(88264, "spell_throw_bomb"),
(21343, "spell_winter_veil_snowball"),
(45732, "spell_gen_torch_launch"),
(45390, "spell_gen_ribbon_pole_dancer_check"),
(74946,'spell_throngus_arrow_barage'),
(70046, 'spell_a_trip_to_ironforge_quest_complete'),
(70047, 'spell_follow_that_gyrocopter_quest_start'),
(76143, 'spell_low_health'),
(100865, 'spell_wracking_pain_link'),
(103851, 'spell_morchok_black_blood_of_the_earth'),
(103785, 'spell_morchok_black_blood_of_the_earth_dmg'),
(108570, 'spell_morchok_black_blood_of_the_earth_dmg'),
(110288, 'spell_morchok_black_blood_of_the_earth_dmg'),
(110287, 'spell_morchok_black_blood_of_the_earth_dmg'),
(103414, 'spell_morchok_stomp'),
(108571, 'spell_morchok_stomp'),
(109033, 'spell_morchok_stomp'),
(109034, 'spell_morchok_stomp'),
(103528, 'spell_morchok_target_selected'),
(104573, 'spell_morchok_target_selected'),
(103545, 'spell_morchok_resonating_crystal_dmg'),
(108572, 'spell_morchok_resonating_crystal_dmg'),
(110041, 'spell_morchok_resonating_crystal_dmg'),
(110040, 'spell_morchok_resonating_crystal_dmg'),
(62552,'spell_gen_defend'),
(62719,'spell_gen_defend'),
(66482,'spell_gen_defend'),
(45462, 'spell_dk_plague_strike'),
(129356, 'spell_sha_of_anger_overcome_by_anger'),
(76207, 'spell_mindbender_enslave'),
(91413, 'spell_mindbender_enslave'),
(70769, 'spell_gen_divine_storm_cd_reset'),
(61698,'spell_gen_ds_flush_knockback'),
(99259, 'spell_baleroc_shards_of_torment_aoe'),
(99489, 'spell_baleroc_tormented_aoe'),
(99515, 'spell_baleroc_final_countdown'),
(99517, 'spell_baleroc_final_countdown_script'),
(67039, 'spell_gen_pony_mount_check'),
(53755,'spell_gen_mixology_bonus'),
(53758,'spell_gen_mixology_bonus'),
(53760,'spell_gen_mixology_bonus'),
(54212,'spell_gen_mixology_bonus'),
(62380,'spell_gen_mixology_bonus'),
(53752,'spell_gen_mixology_bonus'),
(28521,'spell_gen_mixology_bonus'),
(42735,'spell_gen_mixology_bonus'),
(28518,'spell_gen_mixology_bonus'),
(28519,'spell_gen_mixology_bonus'),
(28540,'spell_gen_mixology_bonus'),
(28520,'spell_gen_mixology_bonus'),
(17629,'spell_gen_mixology_bonus'),
(17627,'spell_gen_mixology_bonus'),
(17628,'spell_gen_mixology_bonus'),
(17626,'spell_gen_mixology_bonus'),
(28497,'spell_gen_mixology_bonus'),
(60340,'spell_gen_mixology_bonus'),
(60341,'spell_gen_mixology_bonus'),
(60343,'spell_gen_mixology_bonus'),
(60344,'spell_gen_mixology_bonus'),
(60345,'spell_gen_mixology_bonus'),
(60346,'spell_gen_mixology_bonus'),
(53751,'spell_gen_mixology_bonus'),
(53764,'spell_gen_mixology_bonus'),
(53748,'spell_gen_mixology_bonus'),
(60347,'spell_gen_mixology_bonus'),
(53763,'spell_gen_mixology_bonus'),
(53747,'spell_gen_mixology_bonus'),
(53749,'spell_gen_mixology_bonus'),
(33721,'spell_gen_mixology_bonus'),
(53746,'spell_gen_mixology_bonus'),
(28514,'spell_gen_mixology_bonus'),
(28509,'spell_gen_mixology_bonus'),
(28503,'spell_gen_mixology_bonus'),
(28502,'spell_gen_mixology_bonus'),
(38954,'spell_gen_mixology_bonus'),
(39628,'spell_gen_mixology_bonus'),
(54494,'spell_gen_mixology_bonus'),
(39627,'spell_gen_mixology_bonus'),
(28501,'spell_gen_mixology_bonus'),
(28493,'spell_gen_mixology_bonus'),
(39626,'spell_gen_mixology_bonus'),
(33726,'spell_gen_mixology_bonus'),
(28491,'spell_gen_mixology_bonus'),
(39625,'spell_gen_mixology_bonus'),
(28490,'spell_gen_mixology_bonus'),
(54452,'spell_gen_mixology_bonus'),
(33720,'spell_gen_mixology_bonus'),
(24361,'spell_gen_mixology_bonus'),
(17539,'spell_gen_mixology_bonus'),
(17538,'spell_gen_mixology_bonus'),
(17537,'spell_gen_mixology_bonus'),
(17535,'spell_gen_mixology_bonus'),
(11348,'spell_gen_mixology_bonus'),
(11406,'spell_gen_mixology_bonus'),
(26276,'spell_gen_mixology_bonus'),
(11474,'spell_gen_mixology_bonus'),
(24363,'spell_gen_mixology_bonus'),
(11405,'spell_gen_mixology_bonus'),
(11334,'spell_gen_mixology_bonus'),
(11390,'spell_gen_mixology_bonus'),
(11396,'spell_gen_mixology_bonus'),
(11349,'spell_gen_mixology_bonus'),
(21920,'spell_gen_mixology_bonus'),
(11328,'spell_gen_mixology_bonus'),
(3223,'spell_gen_mixology_bonus'),
(3593,'spell_gen_mixology_bonus'),
(3164,'spell_gen_mixology_bonus'),
(7844,'spell_gen_mixology_bonus'),
(3160,'spell_gen_mixology_bonus'),
(3220,'spell_gen_mixology_bonus'),
(3222,'spell_gen_mixology_bonus'),
(63729,'spell_gen_mixology_bonus'),
(3166,'spell_gen_mixology_bonus'),
(8212,'spell_gen_mixology_bonus'),
(2374,'spell_gen_mixology_bonus'),
(2378,'spell_gen_mixology_bonus'),
(3219,'spell_gen_mixology_bonus'),
(2367,'spell_gen_mixology_bonus'),
(673,'spell_gen_mixology_bonus'),
(26679, 'spell_rog_deadly_throw'),
(150011, "spell_magma_barrage_damage");

REPLACE INTO spell_script_names VALUE (17962, 'spell_warl_conflagrate_aura');
REPLACE INTO spell_script_names VALUE (108685, 'spell_warl_conflagrate_aura');
REPLACE INTO spell_script_names VALUE (114175, 'spell_warl_demonic_call');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (25988, 'spell_pal_eye_for_an_eye');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (9799, 'spell_pal_eye_for_an_eye');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('66298', 'spell_klaxon');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('66299', 'spell_radio');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67495', 'spell_bank_67495');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67496', 'spell_bank_67496');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67497', 'spell_bank_67497');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67498', 'spell_bank_67498');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67682', 'spell_kabummbomb');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('67499', 'spell_bank_67499');

UPDATE `gameobject_template` SET `ScriptName`='go_brewfest_music' WHERE `entry`=186221;
UPDATE gameobject_template SET ScriptName="go_shadowmoon_voidblade" WHERE entry=238853;
UPDATE gameobject_template SET ScriptName="go_tonk_console" WHERE entry=209342;
UPDATE gameobject_template SET ScriptName="go_spirit_effigy" WHERE entry=237944;
UPDATE `gameobject_template` SET `ScriptName` = 'go_mimiron_hardmode_button' WHERE `entry` = 194739;
UPDATE `gameobject_template` SET `ScriptName` = 'go_defias_cannon' WHERE `entry` = '16398';
UPDATE `gameobject_template` SET `ScriptName` = 'go_heavy_door' WHERE `entry` = '17154';
UPDATE `gameobject_template` SET `ScriptName` = 'go_deadmines_tp' WHERE `entry` = '19072';
UPDATE `gameobject_template` SET `ScriptName`='go_pirate_day_music' WHERE `entry`=190363;
UPDATE `gameobject_template` SET `ScriptName`='go_orb_of_command' WHERE `entry`='179879';
UPDATE `gameobject_template` SET `ScriptName`='go_midsummer_music' WHERE `entry`=188174;
UPDATE `gameobject_template` SET `ScriptName`='go_darkmoon_faire_music' WHERE `entry`=180335;
UPDATE `gameobject_template` SET `ScriptName`="go_toy_train_set" WHERE `entry`=193963;
UPDATE `gameobject_template` SET `ScriptName`="go_midsummer_ribbon_pole" WHERE `entry`=181605;
UPDATE `gameobject_template` SET `ScriptName`='gob_canon_gobelin' WHERE `entry`='207355';
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209437;
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209438;
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209439;
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209440;
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209441;
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209442;
UPDATE gameobject_template SET ScriptName="time_deliver_device" WHERE entry=209443;
UPDATE `gameobject_template` SET `AIName`= '', `ScriptName`= 'go_brazier_of_the_herald' WHERE `entry`=175564;
UPDATE `gameobject_template` SET `ScriptName` = 'go_orb_of_domination' WHERE `entry` = 177808;
UPDATE `gameobject_template` SET `ScriptName`='go_gauntlet_gate' WHERE `entry`=175357;
UPDATE `gameobject_template` SET `ScriptName` = 'go_throne_of_tides_defence_system' WHERE `entry` =203199;
UPDATE `gameobject_template` SET `ScriptName`='go_well_of_eternity_teleport' WHERE `entry` IN (209997, 209998, 209999, 210000);
UPDATE `gameobject_template` SET `ScriptName`='go_ahune_ice_stone' WHERE `entry`=187882;
UPDATE `gameobject_template` SET `ScriptName`= 'go_finklesteins_cauldron' WHERE `entry`=190498;
UPDATE gameobject_template SET ScriptName='go_activation_crystal' WHERE entry=193611;
UPDATE `gameobject_template` SET `ScriptName`='go_prince_taldaram_sphere' WHERE `entry` IN (193093,193094);
UPDATE gameobject_template SET ScriptName='go_sapphiron_birth' WHERE entry=181356;
UPDATE `gameobject_template` SET `ScriptName`='gob_bank_gobelin' WHERE `entry`='195525';
UPDATE gameobject_template SET ScriptName='go_elune_fire' WHERE entry IN (177417, 177404);
UPDATE gameobject_template SET ScriptName='go_solar_core', type=2 WHERE entry in (208474);
UPDATE gameobject_template SET ScriptName='go_ungoro_soil', type=2 WHERE entry in (208537);
UPDATE gameobject_template SET ScriptName="go_cristal_of_pure_energy" WHERE entry=265541;
UPDATE gameobject_template SET ScriptName="go_hourglass_of_time" WHERE entry=209249;
UPDATE gameobject_template SET ScriptName="go_spirit_effigy" WHERE entry=237944;

DELETE FROM `criteria_data` WHERE `criteria_id` IN (10406, 10405) AND `type` = 18;
DELETE FROM `criteria_data` WHERE `criteria_id` IN (10545,10548,10546,10543,10547,10544, 10450, 10463) AND `type` = 11;
REPLACE INTO `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10544, 11, 0, 0, 'achievement_setup_rocket'),
(10547, 11, 0, 0, 'achievement_setup_rocket'),
(10543, 11, 0, 0, 'achievement_setup_mine'),
(10546, 11, 0, 0, 'achievement_setup_mine'),
(10548, 11, 0, 0, 'achievement_setup_boom'),
(10545, 11, 0, 0, 'achievement_setup_boom'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10054,12,0,0, 'achievement_shutout'),
(10055,12,1,0, 'achievement_shutout'),
(10044,11,0,0, 'achievement_unbroken'),
(10045,11,0,0, 'achievement_unbroken'),
(10044,12,0,0, 'achievement_unbroken'),
(10045,12,1,0, 'achievement_unbroken'),
(10056,11,0,0,'achievement_orbital_bombardment'),
(10056,11,0,0,'achievement_orbital_bombardment'),
(10057,11,0,0,'achievement_orbital_devastation'),
(10058,11,0,0,'achievement_nuked_from_orbit'),
(10059,11,0,0,'achievement_orbital_bombardment'),
(10060,11,0,0,'achievement_orbital_devastation'),
(10061,11,0,0,'achievement_nuked_from_orbit'),
(10218,11,0,0,'achievement_orbit_uary'),
(10219,11,0,0,'achievement_orbit_uary'),
(10068,11,0,0,'achievement_ignis_shattered'), -- Shattered (10 Player)
(10069,11,0,0,'achievement_ignis_shattered'), -- Shattered (25 Player)
(10047,12,0,0, 'achievement_three_car_garage_siege'),
(16848,11,0,0,'achievement_ohganot_so_fast'),
('6084','11','0','0','achievement_minutes_to_midnight'),
(7363, 11, 0, 0, 'achievement_snakes_whyd_it_have_to_be_snakes'),
('18618', '11', '0', '0', 'achievement_lazy_eye'),
(10570, 11, 0, 0, 'achievement_he_feeds_on_your_tears'),
(10568, 11, 0, 0, 'achievement_he_feeds_on_your_tears'),
(15593, 11, 0, 0, 'achievement_headed_south'),
(18494, 11, 0, 0,'achievement_ping_pong_champion'),
(15984, 11, 0, 0, 'achievement_not_static_at_all'),
(17576, 11, 0, 0, 'achievement_bucket_list'),
(17775, 11, 0, 0, 'achievement_bucket_list'),
(17776, 11, 0, 0, 'achievement_bucket_list'),
(17777, 11, 0, 0, 'achievement_bucket_list'),
(17778, 11, 0, 0, 'achievement_bucket_list'),
(17779, 11, 0, 0, 'achievement_bucket_list'),
(18495, 11, 0, 0,'achievement_taste_the_rainbow_BY'),
(18496, 11, 0, 0,'achievement_taste_the_rainbow_RG'),
(18497, 11, 0, 0,'achievement_taste_the_rainbow_BB'),
(18498, 11, 0, 0,'achievement_taste_the_rainbow_PY'),
('6180', '11', '1', '0','achievement_chromatic_champion'),
(18444, 11, 0, 0, 'achievement_deck_defender'),
(7359,11,0,0,'achievement_volunteer_work'),
(18607, 11, 0, 0, 'achievement_dont_stay_so_close_to_me'),
(18363, 11, 0, 0,'achievement_thats_not_cannon'),
(17538, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(17536, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(17535, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(17533, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(7361,11,0,0,'achievement_oh_novos'),
(17450, 11, 0, 0, 'achievement_not_an_ambi_turner'),
(7319,11,0,0,'achievement_less_rabi'),
(7317,11,0,0,'achievement_respect_your_elders'),
(7583,11,0,0,'achievement_share_the_love'),
(17577, 11, 0, 0, 'achievement_share_the_pain'),
(7579,11,0,0,'achievement_consumption_junction'),
('16210', '11', '0', '0', 'achievement_prototype_reaper'),
(17542, 11, 0, 0, 'achievement_death_from_above'),
(11168, 11, 0, 0, 'achievement_food_fight'),
(11168, 16, 404, 0, ''),
(11178, 11, 0, 0, 'achievement_food_fight'),
(11178, 16, 404, 0, ''),
(11179, 11, 0, 0, 'achievement_food_fight'),
(11179, 16, 404, 0, ''),
(11180, 11, 0, 0, 'achievement_food_fight'),
(11180, 16, 404, 0, ''),
(11181, 11, 0, 0, 'achievement_food_fight'),
(11181, 16, 404, 0, ''),
(15988, 11, 0, 0, 'achievement_hate_that_song'),
(4944, 0, 0,  0, ''), -- no criteria data
(4946,11, 0,  0, 'achievement_killed_exp_or_honor_target'),
(4948, 8, 1,  0, ''), -- Beast
(4949, 8, 3,  0, ''), -- Dragonkin
(4950, 8, 2,  0, ''), -- drachkin
(4951, 8, 4,  0, ''), -- Elemental
(4952, 8, 5,  0, ''), -- Giant
(4953, 8, 7,  0, ''), -- Humanoid
(4954, 8, 9,  0, ''), -- Mechanical
(4955, 8, 6,  0, ''), -- Undead
(4956, 8, 10, 0, ''), -- Not specified
(4957, 8, 11, 0, ''), -- Totem
(4958, 8, 12, 0, ''), -- Non-Combat Pet
(7625,11,0,0, 'achievement_bg_sa_artillery'),
(7628,11,0,0, 'achievement_bg_sa_artillery'),
(6800, 6, 3057, 0, ''),
(6800, 11, 0, 0, 'achievement_sickly_gazelle'),
(5541,11,0,0,'achievement_arena_2v2_kills'),
(5542,11,0,0,'achievement_arena_3v3_kills'),
(5543,11,0,0,'achievement_arena_5v5_kills'),
(7636,11,0,0,'achievement_bg_sa_defense_of_ancients'),
(7740,11,0,0,'achievement_bg_sa_defense_of_ancients'),
(9798,11,0,0, 'achievement_tilted'),
(7626, 11, 0, 0, 'achievement_not_even_a_scratch'),
(7634, 11, 0, 0, 'achievement_not_even_a_scratch'),
(7636,11,0,0,'achievement_bg_sa_defense_of_ancients'),
(7740,11,0,0,'achievement_bg_sa_defense_of_ancients'),
(3931,1,9099,0,''),
(3931,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(3931,15,3,0,''),
(12859,1,9099,0,''),
(12859,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(12859,15,3,0,''),
(3929,1,8403,0,''),
(3929,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(3929,15,3,0,''),
(4227,1,8403,0,''),
(4227,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(4227,15,3,0,''),
(12780,11,0,0, 'achievement_once_bitten_twice_shy_n'),
(13012,11,0,0, 'achievement_once_bitten_twice_shy_n'),
(13011,11,0,0, 'achievement_once_bitten_twice_shy_v'),
(13013,11,0,0, 'achievement_once_bitten_twice_shy_v'),
(12978,12,0,0,''),
(12979,12,1,0,''),
(12971,12,2,0,''),
(12980,12,3,0,''),
(12978,11,0,0,'achievement_portal_jockey'),
(12979,11,0,0,'achievement_portal_jockey'),
(12971,11,0,0,'achievement_portal_jockey'),
(12980,11,0,0,'achievement_portal_jockey'),
(13355,12,1,0,''),
(13335,12,0,0,''),
(12757,12,0,0,''),
(12954,12,1,0,''),
(13048,12,2,0,''),
(13059,12,3,0,''),
(13099,12,0,0,''),
(13125,12,2,0,''),
(13124,12,1,0,''),
(13126,12,3,0,''),
(7315,11,0,0,'achievement_intense_cold'),
(7321,11,0,0,'achievement_shatter_resistant'),
(7321,12,1,0,''),
(7264,11,0,0,'achievement_safety_dance'),
(7548,11,0,0,'achievement_safety_dance'),
(7318,11,0,0,'achievement_king_dred'),
(7324,11,0,0,'achievement_emerald_void'),
(7325,11,0,0,'achievement_amber_void'),
(7323,11,0,0,'achievement_ruby_void'),
(7577,11,0,0,'achievement_split_personality'),
(3368,0,0,0,''), -- Alterac Valley
(3369,0,0,0,''), -- Arathi Basin
(3370,0,0,0,''), -- Eye of the Storm
(3371,0,0,0,''), -- Warsong Gulch
(7623,0,0,0,''), -- Strand of the Ancients
(12578,0,0,0,''), -- Isle of Conquest
(3684,7,23505,0,''), -- Berserking killing blow
(5529,0,0,0,''), -- Total Killing Blows
(5512,20,0,0,''), -- Eastern Kingdoms
(5530,20,1,0,''), -- Kalimdor
(5531,20,530,0,''), -- Burning Crusade Areas
(5532,20,571,0,''), -- Northrend
(5533,20,559,0,''), -- Nagrand Arena
(5534,20,562,0,''), -- Blade's Edge Arena
(5535,20,572,0,''), -- Ruind of Lordaeron
(9165,20,617,0,''), -- Dalaran Sewers
(9166,20,618,0,''), -- Ring of Valor
(5536,20,30,0,''), -- Alterac Valley
(5537,20,529,0,''), -- Arathi Basin
(5538,20,489,0,''), -- Warsong Gulch
(5539,20,566,0,''), -- Eye of the Storm
(5540,20,607,0,''), -- Strand of the Ancients
(13254,20,628,0,''), -- Isle of Conquest
(5541,11,0,0,'achievement_arena_2v2_kills'), -- 2v2 Arena Killing Blows
(5542,11,0,0,'achievement_arena_3v3_kills'), -- 3v3 Arena Killing Blows
(5543,11,0,0,'achievement_arena_5v5_kills'), -- 5v5 Arena Killing Blows
(5544,20,30,0,''), -- Alterac Valley Killing Blows
(5545,20,529,0,''), -- Arathi Basin Killing Blows
(5546,20,489,0,''), -- Warsong Gulch Killing Blows
(5547,20,566,0,''), -- Eye of the Storm Killing Blows
(5548,20,607,0,''), -- Strand of the Ancients Killing Blows
(7573,1,30249,0,''), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(7573,11,0,0,'achievement_denyin_the_scion'), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(7574,1,30249,0,''), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(7574,11,0,0,'achievement_denyin_the_scion'), -- Deliver a killing blow to a Scion of Eternity while riding on a hover disk
(10619,1,33142,0,''), -- Leviathan Turret
(10620,1,33142,0,''), -- Leviathan Turret
(11497,1,35273,0,''), -- Glaive Thrower
(11498,1,34775,0,''), -- Demolisher
(11500,1,34793,0,''), -- Catapult
(11501,1,35069,0,''), -- Siege Engine
(12178,1,34802,0,''), -- Glaive Thrower
(12179,1,34775,0,''), -- Demolisher
(12181,1,34793,0,''), -- Catapult
(12182,1,34776,0,''), -- Siege Engine
(13255,20,628,0,''),-- Isle of Conquest Killing Blows
(7328,11,0,0,'achievement_twilight_assist'),
(7329,11,0,0,'achievement_twilight_duo'),
(7330,11,0,0,'achievement_twilight_zone'),
(7331,11,0,0,'achievement_twilight_assist'),
(7332,11,0,0,'achievement_twilight_duo'),
(7333,11,0,0,'achievement_twilight_zone'),
(7614,11,0,0,'achievement_just_cant_get_enough'),
(7615,11,0,0,'achievement_just_cant_get_enough'),
(7612,11,0,0, 'achievement_spore_loser'),
(7612,12,0,0,''),
(7613,11,0,0, 'achievement_spore_loser'),
(7613,12,1,0,''),
(7316,11,0,0,'achievement_chaos_theory'),
(10062,12,0,0, 'achievement_quick_shave'),
(10063,12,1,0, 'achievement_quick_shave'),
(10044,12,0,0, 'achievement_unbroken'),
(10045,12,1,0, 'achievement_unbroken'),
(10054,12,0,0, 'achievement_shutout'),
(10055,12,1,0, 'achievement_shutout'),
(10046,12,0,0, 'achievement_three_car_garage_chopper'),
(10047,12,0,0, 'achievement_three_car_garage_siege'),
(10048,12,0,0, 'achievement_three_car_garage_demolisher'),
(10049,12,1,0, 'achievement_three_car_garage_chopper'),
(10050,12,1,0, 'achievement_three_car_garage_siege'),
(10051,12,1,0, 'achievement_three_car_garage_demolisher'),
(10062,11,0,0, 'achievement_quick_shave'),
(10063,11,0,0, 'achievement_quick_shave'),
(10044,11,0,0, 'achievement_unbroken'),
(10045,11,0,0, 'achievement_unbroken'),
(10054,11,0,0, 'achievement_shutout'),
(10055,11,0,0, 'achievement_shutout'),
(10046,11,0,0, 'achievement_three_car_garage_chopper'),
(10047,11,0,0, 'achievement_three_car_garage_siege'),
(10048,11,0,0, 'achievement_three_car_garage_demolisher'),
(10049,11,0,0, 'achievement_three_car_garage_chopper'),
(10050,11,0,0, 'achievement_three_car_garage_siege'),
(10051,11,0,0, 'achievement_three_car_garage_demolisher'),
(6803,11,0,0,'achievement_defenseless'),
(7598,11,0,0,'achievement_kings_bane'),
(12976,11,0,0,'achievement_three_faced'),
(3804,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3805,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3806,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3807,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3808,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3809,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3810,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3811,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3812,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(3813,11,0,0, 'achievement_resilient_victory'), -- Resilient Victory
(1234,11,0,0, 'achievement_bg_control_all_nodes'), -- Territorial Dominance
(1239,11,0,0, 'achievement_bg_control_all_nodes'), -- Eye of the Storm Domination
(5605,11,0,0, 'achievement_save_the_day'), -- Save the Day
(5606,11,0,0, 'achievement_save_the_day'),
(12060,11,0,0,'achievement_bg_ic_resource_glut'),
(12061,11,0,0,'achievement_bg_ic_resource_glut'),
(12183,11,0,0,'achievement_bg_ic_glaive_grave'),
(1242, 11, 0, 0, 'achievement_bg_av_perfection'),
(1803, 11, 0, 0, 'achievement_bg_av_perfection'),
(1804, 11, 0, 0, 'achievement_bg_av_perfection'),
(1805, 11, 0, 0, 'achievement_bg_av_perfection'),
(1806, 11, 0, 0, 'achievement_bg_av_perfection'),
(1807, 11, 0, 0, 'achievement_bg_av_perfection'),
(1808, 11, 0, 0, 'achievement_bg_av_perfection'),
(1809, 11, 0, 0, 'achievement_bg_av_perfection'),
(1810, 11, 0, 0, 'achievement_bg_av_perfection'),
(1825, 11, 0, 0, 'achievement_bg_av_perfection'),
(1811, 11, 0, 0, 'achievement_bg_av_perfection'),
(1812, 11, 0, 0, 'achievement_bg_av_perfection'),
(1813, 11, 0, 0, 'achievement_bg_av_perfection'),
(1814, 11, 0, 0, 'achievement_bg_av_perfection'),
(1815, 11, 0, 0, 'achievement_bg_av_perfection'),
(1816, 11, 0, 0, 'achievement_bg_av_perfection'),
(1817, 11, 0, 0, 'achievement_bg_av_perfection'),
(1818, 11, 0, 0, 'achievement_bg_av_perfection'),
(1819, 11, 0, 0, 'achievement_bg_av_perfection'),
(1826, 11, 0, 0, 'achievement_bg_av_perfection'),
(3386, 11, 0, 0, 'achievement_everything_counts'),
(3387, 11, 0, 0, 'achievement_everything_counts'),
(3388, 11, 0, 0, 'achievement_everything_counts'),
(3389, 11, 0, 0, 'achievement_everything_counts'),
(4244,11,0,0,'achievement_hadronox_denied'),
(7265,11,0,0,'achievement_momma_said_knock_you_out'), -- Momma Said Knock You Out (10 player)
(7549,11,0,0,'achievement_momma_said_knock_you_out'), -- Momma Said Knock You Out (25 player)
(7590,11,0,0,'achievement_brann_spankin_new'),
(7631,6,4609,0, ''),
(7630,6,4609,0, ''),
(7629,7,52418,0, ''),
(6446,7,52418,0, ''),
(7625,11,0,0, 'achievement_bg_sa_artillery'),
(7628,11,0,0, 'achievement_bg_sa_artillery'),
(6800, 6, 3057, 0, ''),
(6800, 11, 0, 0, 'achievement_sickly_gazelle'),
(1242, 11, 0, 0, 'achievement_bg_av_perfection'),
(1803, 11, 0, 0, 'achievement_bg_av_perfection'),
(1804, 11, 0, 0, 'achievement_bg_av_perfection'),
(1805, 11, 0, 0, 'achievement_bg_av_perfection'),
(1806, 11, 0, 0, 'achievement_bg_av_perfection'),
(1807, 11, 0, 0, 'achievement_bg_av_perfection'),
(1808, 11, 0, 0, 'achievement_bg_av_perfection'),
(1809, 11, 0, 0, 'achievement_bg_av_perfection'),
(1810, 11, 0, 0, 'achievement_bg_av_perfection'),
(1825, 11, 0, 0, 'achievement_bg_av_perfection'),
(1811, 11, 0, 0, 'achievement_bg_av_perfection'),
(1812, 11, 0, 0, 'achievement_bg_av_perfection'),
(1813, 11, 0, 0, 'achievement_bg_av_perfection'),
(1814, 11, 0, 0, 'achievement_bg_av_perfection'),
(1815, 11, 0, 0, 'achievement_bg_av_perfection'),
(1816, 11, 0, 0, 'achievement_bg_av_perfection'),
(1817, 11, 0, 0, 'achievement_bg_av_perfection'),
(1818, 11, 0, 0, 'achievement_bg_av_perfection'),
(1819, 11, 0, 0, 'achievement_bg_av_perfection'),
(1826, 11, 0, 0, 'achievement_bg_av_perfection'),
(3386, 11, 0, 0, 'achievement_everything_counts'),
(3387, 11, 0, 0, 'achievement_everything_counts'),
(3388, 11, 0, 0, 'achievement_everything_counts'),
(3389, 11, 0, 0, 'achievement_everything_counts'),
(12068,11, 0, 0, 'achievement_bg_ic_mowed_down'),
(7567,11,0,0,'achievement_the_hundred_club'),
(7567,12,0,0,''),
(7568,11,0,0,'achievement_the_hundred_club'),
(7568,12,1,0,''),
(10173,11,0,0,'achievement_shadowdodger'),
(10306,11,0,0,'achievement_shadowdodger'),
(10451,11,0,0,'achievement_smell_saronite'),
(10462,11,0,0,'achievement_smell_saronite'),
(7593,11,0,0,'achievement_abuse_the_ooze'),
(10447,11,0,0,'achievement_knock_on_wood'),
(10447,12,0,0,''),
(10448,11,0,0,'achievement_knock_knock_on_wood'),
(10448,12,0,0,''),
(10449,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10449,12,0,0,''),
(10459,11,0,0,'achievement_knock_on_wood'),
(10459,12,1,0,''),
(10460,11,0,0,'achievement_knock_knock_on_wood'),
(10460,12,1,0,''),
(10461,11,0,0,'achievement_knock_knock_knock_on_wood'),
(10461,12,1,0,''),
(7703, 6, 4197, 0, ''),
(7703, 11, 0, 0, 'achievement_wg_didnt_stand_a_chance'),
(12825,12,2,0,''), 
(13246,11,0,0,'achievement_been_waiting_long_time'), 
(13246,12,0,0,''), 
(13247,11,0,0,'achievement_been_waiting_long_time'), 
(13247,12,2,0,''), 
(13244,11,0,0,'achievement_been_waiting_long_time'), 
(13244,12,1,0,''), 
(13245,11,0,0,'achievement_been_waiting_long_time'), 
(13245,12,3,0,''), 
(13342,12,0,0,''), 
(13309,12,0,0,''), 
(13362,12,1,0,''), 
(13311,12,1,0,''), 
(12823,11,0,0,'achievement_neck_deep_in_vile'), 
(12823,12,0,0,''), 
(13163,11,0,0,'achievement_neck_deep_in_vile'), 
(13163,12,2,0,''), 
(13164,11,0,0,'achievement_neck_deep_in_vile'), 
(13164,12,1,0,''), 
(13243,11,0,0,'achievement_neck_deep_in_vile'), 
(13243,12,3,0,''), 
(12764,12,0,0,''), 
(12909,12,1,0,''), 
(12826,12,3,0,''), 
(13103,12,0,0,''), 
(13136,12,1,0,''), 
(13137,12,2,0,''), 
(13138,12,3,0,''), 
(12818,12,3,0,''),
(12822,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (10 player)
(12822,12,0,0, ''), -- All You Can Eat (10 player)
(12996,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (10 player) Heroic
(12996,12,2,0, ''), -- All You Can Eat (10 player) Heroic
(12972,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (25 player)
(12972,12,1,0, ''), -- All You Can Eat (25 player)
(12989,11,0,0, 'achievement_all_you_can_eat'), -- All You Can Eat (25 player) Heroic
(12989,12,3,0, ''), -- All You Can Eat (25 player) Heroic
(12758,12,0,0, ''), -- The Frostwing Halls (10 player) Sindragosa
(12955,12,1,0, ''), -- The Frostwing Halls (25 player) Sindragosa
(13049,12,2,0, ''), -- Heroic: The Frostwing Halls (10 player) Sindragosa
(13060,12,3,0, ''), -- Heroic: The Frostwing Halls (25 player) Sindragosa
(13102,12,0,0, ''), -- Sindragosa kills (Icecrown 10 player)
(13133,12,1,0, ''), -- Sindragosa kills (Icecrown 25 player)
(13134,12,2,0, ''), -- Sindragosa kills (Heroic Icecrown 10 player)
(13135,12,3,0, ''), -- Sindragosa kills (Heroic Icecrown 25 player)
(12977,11,0,0, 'achievement_flu_shot_shortage'),
(12967,11,0,0, 'achievement_flu_shot_shortage'),
(12986,11,0,0, 'achievement_flu_shot_shortage'),
(12982,11,0,0, 'achievement_flu_shot_shortage'),
(12778,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13036,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13035,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13037,11,0,0, 'achievement_ive_gone_and_made_a_mess'),
(13333,12,0,0,''), -- Lich King 10-player bosses defeated
(13353,12,1,0,''), -- Lich King 25-player bosses defeated
(12771,12,0,0,''), -- Storming the Citadel (10 player)
(13041,12,2,0,''), -- Heroic: Storming the Citadel (10 player)
(12947,12,0,0,''), -- Storming the Citadel (25 player)
(13052,12,3,0,''), -- Heroic: Storming the Citadel (25 player)
(12777,12,0,0,''), -- I'm on a Boat (10 player)
(13080,12,1,0,''), -- I'm on a Boat (25 player)
(13079,12,2,0,''), -- I'm on a Boat (10 player, Heroic)
(13081,12,3,0,''), -- I'm on a Boat (25 player, Heroic)
(12777,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (10 player)
(13080,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (25 player)
(13079,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (10 player, Heroic)
(13081,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (25 player, Heroic)
(13094,12,0,0,''), -- Gunship Battle victories (Icecrown 10 player)
(13110,12,2,0,''), -- Gunship Battle victories (Heroic Icecrown 10 player)
(13109,12,1,0,''), -- Gunship Battle victories (Icecrown 25 player)
(13111,12,3,0,''), -- Gunship Battle victories (Heroic Icecrown 25 player)
(13187,12,3,0,''),
(13198,12,2,0,''),
(10074,11,0,0,'achievement_nerf_engineering'),
(10074,12,0,0,''),
(10075,11,0,0,'achievement_nerf_engineering'),
(10075,12,1,0,''),
(10221,11,0,0,'achievement_heartbreaker'),
(10221,12,0,0,''),
(10220,11,0,0,'achievement_heartbreaker'),
(10220,12,1,0,''),
(10077,11,0,0,'achievement_nerf_gravity_bombs'),
(10077,12,0,0,''),
(10079,11,0,0,'achievement_nerf_gravity_bombs'),
(10079,12,1,0,''),
(10082, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10082, 12, 0, 0, ''),
(10083, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10083, 12, 0, 0, ''),
(10084, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10084, 12, 0, 0, ''),
(10085, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10085, 12, 1, 0, ''),
(10086, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10086, 12, 1, 0, ''),
(10087, 11, 0, 0, 'achievement_assembly_i_choose_you'),
(10087, 12, 1, 0, ''),
(7231,11,0,0,'achievement_on_the_rocks'),
(7322,11,0,0,'achievement_incredible_hulk'),
(10243,11,0,0,'achievement_nine_lives'),
(10399,11,0,0,'achievement_nine_lives'),
(10062,12,0,0, 'achievement_quick_shave'),
(10063,12,1,0, 'achievement_quick_shave'),
(10044,12,0,0, 'achievement_unbroken'),
(10045,12,1,0, 'achievement_unbroken'),
(10054,12,0,0, 'achievement_shutout'),
(10055,12,1,0, 'achievement_shutout'),
(10046,12,0,0, 'achievement_three_car_garage_chopper'),
(10047,12,0,0, 'achievement_three_car_garage_siege'),
(10048,12,0,0, 'achievement_three_car_garage_demolisher'),
(10049,12,1,0, 'achievement_three_car_garage_chopper'),
(10050,12,1,0, 'achievement_three_car_garage_siege'),
(10051,12,1,0, 'achievement_three_car_garage_demolisher'),
(10062,11,0,0, 'achievement_quick_shave'),
(10063,11,0,0, 'achievement_quick_shave'),
(10044,11,0,0, 'achievement_unbroken'),
(10045,11,0,0, 'achievement_unbroken'),
(10054,11,0,0, 'achievement_shutout'),
(10055,11,0,0, 'achievement_shutout'),
(10046,11,0,0, 'achievement_three_car_garage_chopper'),
(10047,11,0,0, 'achievement_three_car_garage_siege'),
(10048,11,0,0, 'achievement_three_car_garage_demolisher'),
(10049,11,0,0, 'achievement_three_car_garage_chopper'),
(10050,11,0,0, 'achievement_three_car_garage_siege'),
(10051,11,0,0, 'achievement_three_car_garage_demolisher'),
(10243,11,0,0,'achievement_nine_lives'),
(10399,11,0,0,'achievement_nine_lives'),
(10184,11,0,0,'achievement_crazy_cat_lady'),
(10400,11,0,0,'achievement_crazy_cat_lady'),
(7587,11,0,0,'achievement_void_dance'),
(12993,11,0,0, 'achievement_doesnt_go_to_eleven'),
(12752, 11, 0, 0, 'achievement_bronjahm_soul_power'),
(10445,11,0,0,'achievement_getting_back_to_nature'),
(10758,11,0,0,'achievement_getting_back_to_nature'),
(7320,11,0,0,'achievement_dehydration'),
(7595, 11,0,0, 'achievement_girl_love_to_skadi'),
(10066,11,0,0,'achievement_iron_dwarf_medium_rare'),
(10067,11,0,0,'achievement_iron_dwarf_medium_rare'),
(10062,12,0,0, 'achievement_quick_shave'),
(10063,12,1,0, 'achievement_quick_shave'),
(10044,12,0,0, 'achievement_unbroken'),
(10045,12,1,0, 'achievement_unbroken'),
(10054,12,0,0, 'achievement_shutout'),
(10055,12,1,0, 'achievement_shutout'),
(10046,12,0,0, 'achievement_three_car_garage_chopper'),
(10047,12,0,0, 'achievement_three_car_garage_siege'),
(10048,12,0,0, 'achievement_three_car_garage_demolisher'),
(10049,12,1,0, 'achievement_three_car_garage_chopper'),
(10050,12,1,0, 'achievement_three_car_garage_siege'),
(10051,12,1,0, 'achievement_three_car_garage_demolisher'),
(10062,11,0,0, 'achievement_quick_shave'),
(10063,11,0,0, 'achievement_quick_shave'),
(10044,11,0,0, 'achievement_unbroken'),
(10045,11,0,0, 'achievement_unbroken'),
(10054,11,0,0, 'achievement_shutout'),
(10055,11,0,0, 'achievement_shutout'),
(10046,11,0,0, 'achievement_three_car_garage_chopper'),
(10047,11,0,0, 'achievement_three_car_garage_siege'),
(10048,11,0,0, 'achievement_three_car_garage_demolisher'),
(10049,11,0,0, 'achievement_three_car_garage_chopper'),
(10050,11,0,0, 'achievement_three_car_garage_siege'),
(10051,11,0,0, 'achievement_three_car_garage_demolisher'),
(6133, 11, 0, 0, 'achievement_maybe_he_ll_get_dizzy'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(4240,11,0,0,'achievement_watch_him_die'),
(10463, 11, 0, 0, 'achievement_firefighter');
UPDATE `instance_template` SET `script`="instance_drak_tharon_keep" WHERE `map`=600;
UPDATE `instance_template` SET `script`='instance_maraudon' WHERE `map`=349;
UPDATE `instance_template` SET `script`='instance_the_stockade' WHERE `map`=34;
UPDATE `instance_template` SET `parent` = '870', `script` = 'instance_siege_of_the_niuzao_temple' WHERE `map` = '1011';
UPDATE `instance_template` SET `script`= 'instance_the_black_morass' WHERE `map`=269;
UPDATE `instance_template` SET `script`='instance_dire_maul' WHERE `map`=429;
UPDATE `instance_template` SET `script`='instance_ragefire_chasm' WHERE `map`=389;
UPDATE `instance_template` SET `script`='instance_the_botanica' WHERE `map`=553;
UPDATE `instance_template` SET `script`='instance_dragon_soul' WHERE `map`=967;
UPDATE `instance_template` SET `script`='instance_the_underbog' WHERE `map`=546;
UPDATE `instance_template` SET `script`='instance_the_slave_pens' WHERE `map`=547;
UPDATE `instance_template` SET `script`='instance_mana_tombs' WHERE `map`=557; 
UPDATE `instance_template` SET `script`='instance_hour_of_twilight' WHERE `map`=940;
UPDATE `instance_template` SET `script`='instance_well_of_eternity' WHERE `map`=939;
UPDATE `instance_template` SET `script`='instance_stonecore' WHERE `map`=725;
UPDATE `instance_template` SET `script`='instance_dragon_soul' WHERE `map`=967;
UPDATE `instance_template` SET `script`='instance_dragon_soul' WHERE `map`=967;
UPDATE `instance_template` SET `script`='instance_dragon_soul' WHERE `map`=967;
UPDATE `instance_template` SET `script`='instance_auchenai_crypts' WHERE `map`=558;
UPDATE `instance_template` SET `script`='instance_vault_of_archavon' WHERE `map`=624;
UPDATE `conditions` SET `ScriptName`="condition_is_wintergrasp_horde" WHERE `ConditionTypeOrReference`=48 AND `NegativeCondition`=0;
UPDATE `conditions` SET `ScriptName`="condition_is_wintergrasp_alliance" WHERE `ConditionTypeOrReference`=48 AND `NegativeCondition`=1;