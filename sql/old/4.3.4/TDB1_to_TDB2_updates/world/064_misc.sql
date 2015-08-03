DELETE FROM `gameobject_template` WHERE `entry` IN (206019, 205866, 205370, 205867, 205869, 205871, 205870, 205868);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(206019, 10, 9849, 'Air Portal Controller', '', 'Overloading', '', 93, 27659, 0, 1000, 0, 0, 0, 0, 0, 0, 86258, 0, 0, 1, 37153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205866, 8, 5974, 'Bonfire', '', '', '', 4, 10, 2066, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.62, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205370, 8, 8083, 'Flames', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205867, 8, 5974, 'Bonfire', '', '', '', 4, 10, 2066, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.469727, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205869, 8, 7748, 'Bonfire', '', '', '', 4, 10, 179900, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.89, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205871, 8, 7748, 'Bonfire', '', '', '', 4, 10, 179900, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.89, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205870, 8, 7748, 'Bonfire', '', '', '', 4, 10, 179900, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.89, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205868, 8, 7748, 'Bonfire', '', '', '', 4, 10, 179900, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.89, 0, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-


UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=51609; -- Sinestra Egg Cosmetic Stalker (DND)
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=46835; -- Sinestra Channel Target
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554688 WHERE `entry`=46842; -- Pulsing Twilight Egg
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=64 WHERE `entry`=45213; -- Sinestra
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=46834; -- Sinestra Controller
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=51629; -- Flames (DND)
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `faction_A`=2328, `faction_H`=2328, `speed_walk`=1.714286, `speed_run`=2.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2 WHERE `entry`=46277; -- Calen
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `npcflag`=16777216, `speed_walk`=0.7142857, `speed_run`=2, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=51551; -- Twilight Portal
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=46404; -- Twilight Skyterror
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2211, `faction_H`=2211, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=50721; -- Crushblow Defender
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `npcflag`=65536, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49747; -- Innkeeper Krum
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=126, `faction_H`=126, `npcflag`=129, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49755; -- Zay'hana
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=126, `faction_H`=126, `npcflag`=640, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49751; -- Malo'wa
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=104, `faction_H`=104, `npcflag`=2176, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49754; -- Hama Brightleaf
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.357143, `speed_run`=1.2, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=46091; -- Crushblow War Machine
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `npcflag`=4224, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49756; -- Zoklaw Irtak
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `npcflag`=8192, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=47116; -- Tokrog
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2305, `faction_H`=2305, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=45658; -- Warlord Zaela
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536 WHERE `entry`=45947; -- Jon-Jon Jellyneck
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `npcflag`=128, `speed_walk`=1.357143, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=49752; -- Rek Moshfang
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=68, `faction_H`=68, `npcflag`=3, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=768 WHERE `entry`=45665; -- Lady Cozwynn
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=45862; -- "Call in the Artillery" Southern Building Bunny
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200 WHERE `entry`=45877; -- "SI:7/Kor'kron Drop" Area Trigger Kill Credit
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=14, `faction_H`=14, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=48052; -- Sinestra Whelp Spawner
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2330, `faction_H`=2330, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=15 WHERE `entry`=46456; -- Lirastrasza


UPDATE `creature_model_info` SET `bounding_radius`=1.786, `combat_reach`=3 WHERE `modelid`=17456;
UPDATE `creature_model_info` SET `bounding_radius`=0.75, `combat_reach`=1.5 WHERE `modelid`=17612;
UPDATE `creature_model_info` SET `bounding_radius`=13, `combat_reach`=32.5, `gender`=1 WHERE `modelid`=34335;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34602;
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=34784;
UPDATE `creature_model_info` SET `bounding_radius`=3, `combat_reach`=10 WHERE `modelid`=35318;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35417;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36596;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37002;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37003;
UPDATE `creature_model_info` SET `bounding_radius`=0.8725, `combat_reach`=3.75, `gender`=1 WHERE `modelid`=37004;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37005;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=37006;


DELETE FROM `npc_vendor` WHERE `entry` IN (49756);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 49756 (Zoklaw Irtak)
(49756, 2901, 1, 0, 0, 1), -- Mining Pick
(49756, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(49756, 2880, 3, 0, 0, 1), -- Weak Flux
(49756, 3466, 4, 0, 0, 1), -- Strong Flux
(49756, 18567, 5, 0, 0, 1), -- Elemental Flux
(49756, 3857, 6, 0, 0, 1); -- Coal


DELETE FROM `creature_equip_template` WHERE `entry` IN (45681, 46204, 46205, 50721, 49756, 45658, 45947, 49752, 45665, 45838, 45798, 45787, 46203, 46204, 44771);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(45681, 61298, 0, 0), -- Garginox
(46204, 62034, 0, 0), -- Corrupted Elementalist
(46205, 61370, 0, 0), -- Citadel Veteran
(50721, 56912, 56174, 0), -- Crushblow Defender
(49756, 5956, 0, 0), -- Zoklaw Irtak
(45658, 57012, 0, 0), -- Warlord Zaela
(45947, 53963, 53934, 0), -- Jon-Jon Jellyneck
(49752, 1910, 0, 0), -- Rek Moshfang
(45665, 61291, 61295, 0), -- Lady Cozwynn
(45838, 41983, 0, 0), -- Twilight Ettin
(45798, 31604, 0, 0), -- Crushblow Warrior
(45787, 57129, 0, 0), -- Bloodeye Brute
(46203, 55131, 55051, 0), -- Twilight Vindicator
(44771, 57129, 0, 0); -- Gor'kresh
