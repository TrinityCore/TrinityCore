SET @OGUID := 371;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+175;
-- Removed

UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=85, `faction_H`=85, `speed_walk`=1.385714, `speed_run`=6, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=51346; -- Orgrimmar Wind Rider
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=32520; -- Totally Generic Bunny (All Phase)
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=29, `faction_H`=29, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=40995; -- Azure Iron Ore
UPDATE `creature_template` SET `minlevel`=24, `maxlevel`=24, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=34295; -- Lord Magmathar
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=537166656, `dynamicflags`=32, `HoverHeight`=1 WHERE `entry`=48185; -- Whale Shark
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=37490; -- ELM General Purpose Bunny Infinite
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554688, `HoverHeight`=1 WHERE `entry`=46931; -- Star Fire Bunny
UPDATE `creature_template` SET `minlevel`=84, `maxlevel`=84, `faction_A`=1692, `faction_H`=1692, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432, `HoverHeight`=1 WHERE `entry`=46644; -- Peregrine Statue
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33587200, `HoverHeight`=1 WHERE `entry`=42098; -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=1692, `faction_H`=1692, `speed_walk`=0.5714286, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33849408, `HoverHeight`=1 WHERE `entry`=46646; -- Obsidian Colossus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=125, `faction_H`=125, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=40891; -- Dranosh'ar Laborer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=125, `faction_H`=125, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=40890; -- Dranosh'ar Archer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=125, `faction_H`=125, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=40892; -- Dranosh'ar Overseer
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction_A`=29, `faction_H`=29, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=10176; -- Kaltunk
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction_A`=29, `faction_H`=29, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3143; -- Gornek
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction_A`=7, `faction_H`=7, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=131072, `HoverHeight`=1 WHERE `entry`=44820; -- Training Dummy
UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `faction_A`=85, `faction_H`=85, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=5952; -- Den Grunt
UPDATE `creature_template` SET `minlevel`=11, `maxlevel`=11, `faction_A`=29, `faction_H`=29, `npcflag`=51, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=39214; -- Karranisha
UPDATE `creature_template` SET `minlevel`=11, `maxlevel`=11, `faction_A`=29, `faction_H`=29, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3153; -- Frang
UPDATE `creature_template` SET `minlevel`=11, `maxlevel`=11, `faction_A`=29, `faction_H`=29, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3160; -- Huklah
UPDATE `creature_template` SET `minlevel`=34, `maxlevel`=34, `faction_A`=29, `faction_H`=29, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3159; -- Kzan Thornslash
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction_A`=29, `faction_H`=29, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3161; -- Rarc
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction_A`=29, `faction_H`=29, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=39206; -- Acrypha
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction_A`=29, `faction_H`=29, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3157; -- Shikrik
UPDATE `creature_template` SET `minlevel`=8, `maxlevel`=8, `faction_A`=126, `faction_H`=126, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=5887; -- Canaga Earthcaller
UPDATE `creature_template` SET `minlevel`=8, `maxlevel`=8, `faction_A`=29, `faction_H`=29, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3155; -- Rwag
UPDATE `creature_template` SET `minlevel`=12, `maxlevel`=12, `faction_A`=29, `faction_H`=29, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3145; -- Zureetha Fargaze
UPDATE `creature_template` SET `minlevel`=4, `maxlevel`=4, `faction_A`=29, `faction_H`=29, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=11378; -- Foreman Thazz'ril
UPDATE `creature_template` SET `minlevel`=9, `maxlevel`=9, `faction_A`=29, `faction_H`=29, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=12776; -- Hraug
UPDATE `creature_template` SET `minlevel`=9, `maxlevel`=9, `faction_A`=29, `faction_H`=29, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3156; -- Nartok
UPDATE `creature_template` SET `minlevel`=4, `maxlevel`=4, `faction_A`=29, `faction_H`=29, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512, `HoverHeight`=1 WHERE `entry`=10556; -- Lazy Peon
UPDATE `creature_template` SET `minlevel`=8, `maxlevel`=8, `faction_A`=29, `faction_H`=29, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=9796; -- Galgar
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction_A`=29, `faction_H`=29, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3158; -- Duokna
UPDATE `creature_template` SET `maxlevel`=2, `faction_A`=190, `faction_H`=190, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=39317; -- Northwatch Scout
UPDATE `creature_template` SET `minlevel`=9, `maxlevel`=9, `faction_A`=29, `faction_H`=29, `npcflag`=640, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3882; -- Zlagk
UPDATE `creature_template` SET `faction_A`=7, `faction_H`=7, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=3300; -- Adder
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction_A`=69, `faction_H`=69, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512, `HoverHeight`=1 WHERE `entry`=44058; -- Horton Hornblower
UPDATE `creature_template` SET `faction_A`=31, `faction_H`=31, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=5951; -- Hare
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.5714286, `speed_run`=0.4, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=49837; -- Spiny Lizard
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `faction_A`=189, `faction_H`=189, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=39224; -- Lo'Shall
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=6, `faction_A`=7, `faction_H`=7, `speed_walk`=1.142857, `speed_run`=1.555556, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=5890; -- Redrock Earth Spirit
UPDATE `creature_template` SET `minlevel`=15, `maxlevel`=15, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1.555556, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=5891; -- Minor Manifestation of Earth
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction_A`=7, `faction_H`=7, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3124; -- Scorpid Worker
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction_A`=29, `faction_H`=29, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=256, `HoverHeight`=1 WHERE `entry`=39400; -- Farmer Krella
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `faction_A`=29, `faction_H`=29, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=256, `HoverHeight`=1 WHERE `entry`=39399; -- Farmer Lok'lub
UPDATE `creature_template` SET `faction_A`=189, `faction_H`=189, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3098; -- Mottled Boar
UPDATE `creature_template` SET `faction_A`=29, `faction_H`=29, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=39408; -- Durotar Farmhand
UPDATE `creature_template` SET `faction_A`=188, `faction_H`=188, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=49743; -- Dung Beetle
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=4, `faction_A`=7, `faction_H`=7, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `HoverHeight`=1 WHERE `entry`=3101; -- Vile Familiar
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=4, `faction_A`=7, `faction_H`=7, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3102; -- Felstalker
UPDATE `creature_template` SET `minlevel`=6, `maxlevel`=7, `faction_A`=109, `faction_H`=109, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3111; -- Razormane Quilboar
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction_A`=7, `faction_H`=7, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=3183; -- Yarrog Baneshadow
UPDATE `creature_template` SET `minlevel`=6, `maxlevel`=6, `faction_A`=109, `faction_H`=109, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3112; -- Razormane Scout
UPDATE `creature_template` SET `minlevel`=12, `maxlevel`=12, `faction_A`=29, `faction_H`=29, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=39326; -- Raggaran
UPDATE `creature_template` SET `minlevel`=6, `maxlevel`=7, `faction_A`=189, `faction_H`=189, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3099; -- Dire Mottled Boar
UPDATE `creature_template` SET `minlevel`=7, `maxlevel`=7, `faction_A`=413, `faction_H`=413, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3126; -- Armored Scorpid
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `faction_A`=126, `faction_H`=126, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=3287; -- Hana'zua
UPDATE `creature_template` SET `minlevel`=4, `maxlevel`=4, `faction_A`=7, `faction_H`=7, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=3281; -- Sarkoth
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2, `faction_A`=894, `faction_H`=894, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=39215; -- Captured Northwatch Scout


DELETE FROM `creature_template_addon` WHERE `entry` IN (51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 51346, 32520, 32520, 40995, 40995, 40995, 40995, 40995, 40995, 34295, 48185, 37490, 37490, 37490, 37490, 37490, 37490, 37490, 37490, 37490, 37490, 46931, 46931, 46931, 46931, 46644, 42098, 46644, 42098, 46644, 46646, 42098, 42098, 42098, 42098, 42098, 42098, 42098, 42098, 42098, 46644, 46644, 42098, 42098, 46644, 32520, 32520, 32520, 40891, 40891, 40890, 40890, 40892, 40890, 10176, 3143, 44820, 44820, 44820, 5952, 39214, 3153, 3160, 5952, 3159, 3161, 39206, 5952, 44820, 3157, 5887, 3155, 3145, 44820, 11378, 44820, 12776, 5952, 3156, 10556, 5952, 5952, 9796, 3158, 39317, 3882, 39317, 39317, 39317, 5952, 3300, 10556, 39317, 39317, 39317, 44058, 3300, 5951, 39317, 3300, 39317, 3300, 3300, 39317, 39317, 39317, 39317, 39317, 39317, 39317, 39317, 39317, 39317, 39317, 10556, 49837, 39317, 10556, 10556, 39317, 39317, 39317, 3300, 10556, 39317, 39317, 39317, 39317, 10556, 39317, 39224, 10556, 39317, 39317, 5890, 39317, 5890, 5891, 39317, 5890, 3124, 49837, 39400, 39399, 3098, 3098, 3098, 3098, 3098, 39408, 3098, 3098, 39408, 3098, 5951, 3098, 3098, 3098, 3098, 3098, 5951, 3098, 10556, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3098, 3300, 3300, 3098, 3124, 3300, 3124, 3098, 3098, 3098, 3124, 3124, 3124, 3300, 3124, 3124, 5951, 5951, 3124, 3124, 3124, 49743, 3300, 3124, 3124, 49743, 3124, 3101, 3101, 3124, 10556, 3124, 3124, 3124, 3124, 3124, 49743, 3124, 3124, 5951, 3300, 3300, 10556, 3124, 5952, 5952, 5951, 10556, 3124, 3124, 5951, 3101, 3101, 3101, 5951, 3101, 10556, 3101, 3101, 49743, 3101, 3101, 3101, 3101, 3101, 3101, 3101, 3101, 3101, 3101, 3101, 3101, 3102, 3101, 3102, 3101, 3101, 3102, 3102, 3101, 3101, 3101, 3101, 10556, 3101, 3101, 49743, 49837, 3101, 3102, 3102, 3101, 3102, 3101, 3101, 3101, 3102, 3101, 3102, 3101, 3101, 3102, 3101, 3102, 3101, 3102, 3101, 3101, 3111, 3111, 3102, 3102, 3102, 3183, 3101, 3111, 3112, 3112, 3101, 3101, 39326, 3099, 3111, 3126, 3126, 10556, 3101, 3101, 3300, 3101, 3300, 3101, 49743, 3101, 3101, 3124, 3101, 3124, 3124, 3300, 10556, 3124, 3124, 3124, 49743, 10556, 3124, 3124, 3124, 5951, 3124, 3124, 3124, 3124, 3124, 5951, 3124, 3124, 3124, 3124, 3300, 3287, 3124, 10556, 3124, 3124, 3124, 3124, 3124, 3124, 3124, 3124, 5951, 3124, 3124, 3124, 10556, 3124, 3124, 3281, 3124, 10556, 3300, 3124, 39215, 39215, 39215, 39215, 3124, 3124, 3124, 3124, 5952, 3300, 5952, 5952, 5952, 5952, 3099, 3099, 5951, 5951, 3099, 3099);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(51346, 17719, 0x3000000, 0x101, '95230'), -- Orgrimmar Wind Rider - Horde Flag
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(40995, 0, 0x0, 0x1, ''), -- Azure Iron Ore
(34295, 0, 0x3000000, 0x1, ''), -- Lord Magmathar
(48185, 0, 0x0, 0x1, '29266'), -- Whale Shark - Permanent Feign Death
(37490, 0, 0x0, 0x1, ''), -- ELM General Purpose Bunny Infinite
(46931, 0, 0x0, 0x1, ''), -- Star Fire Bunny
(46644, 0, 0x0, 0x1, ''), -- Peregrine Statue
(42098, 0, 0x0, 0x1, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(46646, 0, 0x0, 0x1, '86985'), -- Obsidian Colossus - Tol'vir Stoneform
(40891, 0, 0x0, 0x101, ''), -- Dranosh'ar Laborer
(40890, 0, 0x0, 0x101, ''), -- Dranosh'ar Archer
(40892, 0, 0x0, 0x101, ''), -- Dranosh'ar Overseer
(10176, 0, 0x0, 0x1, ''), -- Kaltunk
(3143, 0, 0x1, 0x1, ''), -- Gornek
(44820, 0, 0x0, 0x1, '83470'), -- Training Dummy - Arcane Missiles Trainer
(5952, 0, 0x0, 0x101, '18950'), -- Den Grunt - Invisibility and Stealth Detection
(39214, 0, 0x0, 0x1, ''), -- Karranisha
(3153, 0, 0x0, 0x1, ''), -- Frang
(3160, 0, 0x0, 0x1, ''), -- Huklah
(3159, 0, 0x0, 0x1, ''), -- Kzan Thornslash
(3161, 0, 0x0, 0x1, ''), -- Rarc
(39206, 0, 0x0, 0x1, ''), -- Acrypha
(3157, 0, 0x0, 0x1, ''), -- Shikrik
(5887, 0, 0x1, 0x1, ''), -- Canaga Earthcaller
(3155, 0, 0x0, 0x1, ''), -- Rwag
(3145, 0, 0x0, 0x1, ''), -- Zureetha Fargaze
(11378, 0, 0x0, 0x1, ''), -- Foreman Thazz'ril
(12776, 0, 0x0, 0x1, ''), -- Hraug
(3156, 0, 0x0, 0x1, ''), -- Nartok
(9796, 0, 0x0, 0x1, ''), -- Galgar
(3158, 0, 0x0, 0x1, ''), -- Duokna
(3882, 0, 0x0, 0x1, ''), -- Zlagk
(39317, 0, 0x0, 0x1, '58506'), -- Northwatch Scout - Stealth
(3300, 0, 0x0, 0x1, ''), -- Adder
(44058, 0, 0x0, 0x101, ''), -- Horton Hornblower
(5951, 0, 0x0, 0x1, ''), -- Hare
(49837, 0, 0x0, 0x1, ''), -- Spiny Lizard
(10556, 0, 0x0, 0x0, '17743'), -- Lazy Peon - Peon Sleeping
(39224, 0, 0x0, 0x1, ''), -- Lo'Shall
(5890, 0, 0x0, 0x1, '8203'), -- Redrock Earth Spirit - Elemental Spirit Invisibility
(5891, 0, 0x0, 0x1, '8203'), -- Minor Manifestation of Earth - Elemental Spirit Invisibility
(3124, 0, 0x0, 0x1, '6752'), -- Scorpid Worker - Weak Poison Proc
(39400, 0, 0x0, 0x1, '73901'), -- Farmer Krella - Durotar Gothic - Krella
(39399, 0, 0x0, 0x1, '73898'), -- Farmer Lok'lub - Durotar Gothic - Lok'lub
(3098, 0, 0x0, 0x1, ''), -- Mottled Boar
(39408, 0, 0x0, 0x1, ''), -- Durotar Farmhand
(49743, 0, 0x0, 0x1, ''), -- Dung Beetle
(3101, 0, 0x0, 0x1, ''), -- Vile Familiar
(3102, 0, 0x0, 0x1, ''), -- Felstalker
(3111, 0, 0x0, 0x1, '5280'), -- Razormane Quilboar - Razor Mane
(3183, 0, 0x0, 0x1, '75965'), -- Yarrog Baneshadow - Shadow Channeling
(3112, 0, 0x0, 0x1, ''), -- Razormane Scout
(39326, 0, 0x0, 0x1, ''), -- Raggaran
(3099, 0, 0x0, 0x1, ''), -- Dire Mottled Boar
(3126, 0, 0x0, 0x1, ''), -- Armored Scorpid
(3287, 0, 0x7, 0x1, ''), -- Hana'zua
(3281, 0, 0x0, 0x1, ''), -- Sarkoth
(39215, 0, 0x0, 0x1, ''); -- Captured Northwatch Scout


-- `creature_model_info` has empty data.
UPDATE `creature_model_info` SET `bounding_radius`=0.882, `combat_reach`=0.75 WHERE `modelid`=381;
UPDATE `creature_model_info` SET `bounding_radius`=0.7056, `combat_reach`=0.6 WHERE `modelid`=503;
UPDATE `creature_model_info` SET `bounding_radius`=0.1735, `combat_reach`=0.75 WHERE `modelid`=850;
UPDATE `creature_model_info` SET `bounding_radius`=0.124, `combat_reach`=0.6 WHERE `modelid`=1127;
UPDATE `creature_model_info` SET `bounding_radius`=0.093, `combat_reach`=0.45 WHERE `modelid`=1128;
UPDATE `creature_model_info` SET `bounding_radius`=0.2006, `combat_reach`=0.85 WHERE `modelid`=1185;
UPDATE `creature_model_info` SET `bounding_radius`=0.35, `combat_reach`=0.5 WHERE `modelid`=1206;
UPDATE `creature_model_info` SET `bounding_radius`=0.3132, `combat_reach`=1.35, `gender`=0 WHERE `modelid`=1254;
UPDATE `creature_model_info` SET `bounding_radius`=0.17625, `combat_reach`=0.75 WHERE `modelid`=1560;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1653;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=1875;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1876;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=1878;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=1879;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1880;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1881;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1883;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1884;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1885;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1886;
UPDATE `creature_model_info` SET `bounding_radius`=0.348, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1963;
UPDATE `creature_model_info` SET `bounding_radius`=0.35, `combat_reach`=0.5 WHERE `modelid`=1986;
UPDATE `creature_model_info` SET `bounding_radius`=0.35, `combat_reach`=0.5 WHERE `modelid`=1987;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=2025;
UPDATE `creature_model_info` SET `bounding_radius`=0.3550847, `combat_reach`=0.7101695 WHERE `modelid`=2485;
UPDATE `creature_model_info` SET `bounding_radius`=0.425, `combat_reach`=0.85 WHERE `modelid`=2487;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=2577;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=3753;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=4532;
UPDATE `creature_model_info` SET `bounding_radius`=0.75, `combat_reach`=1.5 WHERE `modelid`=6068;
UPDATE `creature_model_info` SET `bounding_radius`=0.05, `combat_reach`=0.15 WHERE `modelid`=7511;
UPDATE `creature_model_info` SET `bounding_radius`=0.05, `combat_reach`=0.15 WHERE `modelid`=8971;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=9151;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=9470;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=9794;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=9795;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=9796;
UPDATE `creature_model_info` SET `bounding_radius`=0.2976, `combat_reach`=1.2, `gender`=0 WHERE `modelid`=10038;
UPDATE `creature_model_info` SET `bounding_radius`=0.2976, `combat_reach`=1.2, `gender`=0 WHERE `modelid`=12089;
UPDATE `creature_model_info` SET `bounding_radius`=0.93, `combat_reach`=4.5 WHERE `modelid`=12110;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=14371;
UPDATE `creature_model_info` SET `bounding_radius`=0.05, `combat_reach`=0.15 WHERE `modelid`=15467;
UPDATE `creature_model_info` SET `bounding_radius`=0.05, `combat_reach`=0.15 WHERE `modelid`=15468;
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=1, `gender`=0 WHERE `modelid`=21342;
UPDATE `creature_model_info` SET `bounding_radius`=30, `combat_reach`=60 WHERE `modelid`=29167;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=31365;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31370;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31371;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31389;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31421;
UPDATE `creature_model_info` SET `bounding_radius`=0.7135729, `combat_reach`=0.6067797 WHERE `modelid`=31437;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31438;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=31447;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32167;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=32168;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32170;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=32171;
UPDATE `creature_model_info` SET `bounding_radius`=0.2832, `combat_reach`=1.8, `gender`=1 WHERE `modelid`=32176;
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=0.25 WHERE `modelid`=32244;
UPDATE `creature_model_info` SET `bounding_radius`=40, `combat_reach`=52 WHERE `modelid`=33618;
UPDATE `creature_model_info` SET `bounding_radius`=5.32, `combat_reach`=4 WHERE `modelid`=35199;
UPDATE `creature_model_info` SET `bounding_radius`=7.1, `combat_reach`=12.5, `gender`=0 WHERE `modelid`=35207;
UPDATE `creature_model_info` SET `bounding_radius`=0.031, `combat_reach`=0.1 WHERE `modelid`=36585;
UPDATE `creature_model_info` SET `bounding_radius`=0.031, `combat_reach`=0.1 WHERE `modelid`=36598;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37328;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37329;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37330;
UPDATE `creature_model_info` SET `bounding_radius`=0.236, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37331;

SET @CGUID := 2607;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+390;
-- Removed

DELETE FROM `npc_vendor` WHERE (`entry`=3159 AND `item`=2131) OR (`entry`=3159 AND `item`=1194) OR (`entry`=3159 AND `item`=2134) OR (`entry`=3159 AND `item`=2479) OR (`entry`=3159 AND `item`=2130) OR (`entry`=3159 AND `item`=2480) OR (`entry`=3159 AND `item`=2139) OR (`entry`=3159 AND `item`=2132) OR (`entry`=3159 AND `item`=28979) OR (`entry`=3159 AND `item`=25861) OR (`entry`=3160 AND `item`=193) OR (`entry`=3160 AND `item`=3595) OR (`entry`=3160 AND `item`=194) OR (`entry`=3160 AND `item`=195) OR (`entry`=3160 AND `item`=3596) OR (`entry`=3160 AND `item`=711) OR (`entry`=3160 AND `item`=85) OR (`entry`=3160 AND `item`=1835) OR (`entry`=3160 AND `item`=209) OR (`entry`=3160 AND `item`=210) OR (`entry`=3160 AND `item`=1836) OR (`entry`=3160 AND `item`=714) OR (`entry`=3161 AND `item`=2386) OR (`entry`=3161 AND `item`=2387) OR (`entry`=3161 AND `item`=2388) OR (`entry`=3161 AND `item`=2389) OR (`entry`=3161 AND `item`=2390) OR (`entry`=3161 AND `item`=2391) OR (`entry`=3161 AND `item`=17183) OR (`entry`=3161 AND `item`=1200) OR (`entry`=3158 AND `item`=4540) OR (`entry`=3158 AND `item`=159) OR (`entry`=3158 AND `item`=4496) OR (`entry`=3882 AND `item`=117) OR (`entry`=3882 AND `item`=2287) OR (`entry`=3882 AND `item`=3770) OR (`entry`=3882 AND `item`=3771) OR (`entry`=3882 AND `item`=4599) OR (`entry`=3882 AND `item`=8952) OR (`entry`=3882 AND `item`=159) OR (`entry`=3882 AND `item`=1179) OR (`entry`=3882 AND `item`=1205) OR (`entry`=3882 AND `item`=1708) OR (`entry`=3882 AND `item`=1645) OR (`entry`=3882 AND `item`=8766);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`) VALUES
-- 3159
(3159, 2131, 1, 0, 0), -- 2131
(3159, 1194, 2, 0, 0), -- 1194
(3159, 2134, 3, 0, 0), -- 2134
(3159, 2479, 4, 0, 0), -- 2479
(3159, 2130, 5, 0, 0), -- 2130
(3159, 2480, 6, 0, 0), -- 2480
(3159, 2139, 7, 0, 0), -- 2139
(3159, 2132, 8, 0, 0), -- 2132
(3159, 28979, 9, 0, 0), -- 28979
(3159, 25861, 10, 0, 0), -- 25861
-- 3160
(3160, 193, 1, 0, 0), -- 193
(3160, 3595, 2, 0, 0), -- 3595
(3160, 194, 3, 0, 0), -- 194
(3160, 195, 4, 0, 0), -- 195
(3160, 3596, 5, 0, 0), -- 3596
(3160, 711, 6, 0, 0), -- 711
(3160, 85, 7, 0, 0), -- 85
(3160, 1835, 8, 0, 0), -- 1835
(3160, 209, 9, 0, 0), -- 209
(3160, 210, 10, 0, 0), -- 210
(3160, 1836, 11, 0, 0), -- 1836
(3160, 714, 12, 0, 0), -- 714
-- 3161
(3161, 2386, 1, 0, 0), -- 2386
(3161, 2387, 2, 0, 0), -- 2387
(3161, 2388, 3, 0, 0), -- 2388
(3161, 2389, 4, 0, 0), -- 2389
(3161, 2390, 5, 0, 0), -- 2390
(3161, 2391, 6, 0, 0), -- 2391
(3161, 17183, 7, 0, 0), -- 17183
(3161, 1200, 8, 0, 0), -- 1200
-- 3158
(3158, 4540, 1, 0, 0), -- 4540
(3158, 159, 2, 0, 0), -- 159
(3158, 4496, 3, 0, 0), -- 4496
-- 3882
(3882, 117, 1, 0, 0), -- 117
(3882, 2287, 2, 0, 0), -- 2287
(3882, 3770, 3, 0, 0), -- 3770
(3882, 3771, 4, 0, 0), -- 3771
(3882, 4599, 5, 0, 0), -- 4599
(3882, 8952, 6, 0, 0), -- 8952
(3882, 159, 7, 0, 0), -- 159
(3882, 1179, 8, 0, 0), -- 1179
(3882, 1205, 9, 0, 0), -- 1205
(3882, 1708, 10, 0, 0), -- 1708
(3882, 1645, 11, 0, 0), -- 1645
(3882, 8766, 12, 0, 0); -- 8766

DELETE FROM `gossip_menu` WHERE (`entry`=523 AND `text_id`=1040) OR (`entry`=11185 AND `text_id`=5002) OR (`entry`=4651 AND `text_id`=565) OR (`entry`=4652 AND `text_id`=5006) OR (`entry`=141 AND `text_id`=4793) OR (`entry`=12670 AND `text_id`=12549) OR (`entry`=4643 AND `text_id`=5715);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(523, 1040), -- 3153
(11185, 5002), -- 39214
(4651, 565), -- 39206
(4652, 5006), -- 3157
(141, 4793), -- 3155
(12670, 12549), -- 12776
(4643, 5715); -- 3156

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=523 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(523, 0, 3, 'I require warrior training.', 0, 0, ''); -- 3153
