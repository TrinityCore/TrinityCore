SET @CGUID := 3990000;
SET @ES9ENTRY := 86;
SET @ES11ENTRY := 88;

UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=12788; -- Legionnaire Teena
UPDATE `creature_template` SET `npcflag`=4224, `unit_flags`=768 WHERE `entry`=46595; -- Blood Guard Zar'shi
UPDATE `creature_template` SET `npcflag`=4224, `unit_flags`=768 WHERE `entry`=46594; -- Sergeant Thunderhorn
UPDATE `creature_template` SET `npcflag`=4224, `unit_flags`=768 WHERE `entry`=46593; -- Doris Chiltonius
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=52034; -- Togar

DELETE FROM `creature_template_addon` WHERE `entry` IN (12788, 46595, 46594, 46593);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(12788, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 12788 (Legionnaire Teena)
(46595, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 46595 (Blood Guard Zar'shi)
(46594, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 46594 (Sergeant Thunderhorn)
(46593, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- 46593 (Doris Chiltonius)

UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12793; -- 12793 (Brave Stonehide)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12794; -- 12794 (Stone Guard Zarg)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12795; -- 12795 (First Sergeant Hola'mahi)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12796; -- 12796 (Raider Bork)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=46556; -- 46556 (Jamus'Vaz)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=46555; -- 46555 (Gunra)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52033; -- 52033 (Rogoc)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52034; -- 52034 (Togar)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52036; -- 52036 (Galra)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52037; -- 52037 (Zulna)

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=56713 WHERE (`DifficultyID`=0 AND `Entry` IN (57801,55382,54471,52037,52036,52034,52033,51195,50488,50477,50323,49837,49743,49737,49622,49573,49131,47571,47253,47248,47247,47246,47233,46985,46742,46741,46709,46708,46667,46642,46622,46572,46556,46555,46512,46359,46358,46357,46082,46080,46078,45830,45780,45720,45717,45714,45709,45662,45661,45659,45566,45563,45559,45558,45339,45337,45211,45139,45138,45137,45094,45093,45025,45023,45019,44978,44975,44919,44868,44867,44866,44865,44851,44338,44158,43239,42859,42548,42506,42504,41266,37072,35364,35068,34955,34765,32520,31725,31724,29238,27818,27489,26537,23635,20492,20491,20489,16012,14498,12796,11017,10880,10685,9564,9317,8404,7793,7792,7790,7311,7231,7230,7088,7010,6987,6986,6929,6466,5951,5910,5817,5811,5614,5613,5611,5610,5609,5606,5603,5597,5188,4953,4485,4311,4047,4043,3413,3412,3409,3400,3372,3371,3370,3369,3368,3366,3365,3364,3363,3361,3360,3359,3354,3353,3351,3350,3342,3333,3332,3331,3329,3328,3327,3323,3321,3319,3317,3316,3315,3314,3313,3312,3310,3300,3296,3216,3144,3127,2857,2855,1420));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12788 AND `DifficultyID`=0); -- 12788 (Legionnaire Teena) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12793 AND `DifficultyID`=0); -- 12793 (Brave Stonehide) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12794 AND `DifficultyID`=0); -- 12794 (Stone Guard Zarg) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12795 AND `DifficultyID`=0); -- 12795 (First Sergeant Hola'mahi) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=46595 AND `DifficultyID`=0); -- 46595 (Blood Guard Zar'shi) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=46594 AND `DifficultyID`=0); -- 46594 (Sergeant Thunderhorn) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=46593 AND `DifficultyID`=0); -- 46593 (Doris Chiltonius) - CanSwim

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 12788, 1, 1637, 5170, '0', 0, 0, 0, 1, 1641.2135009765625, -4170.88720703125, 55.90607452392578125, 5.769526481628417968, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Legionnaire Teena (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@CGUID+1, 52037, 1, 1637, 5170, '0', 0, 0, 0, 0, 1659.220458984375, -4354.81787109375, 64.61993408203125, 1.117010712623596191, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Zulna (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@CGUID+2, 46593, 1, 1637, 5356, '0', 0, 0, 0, 0, 1678.4200439453125, -4182.52978515625, 56.40143203735351562, 3.211405754089355468, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Doris Chiltonius (Area: Grommash Hold - Difficulty: 0) CreateObject1
(@CGUID+3, 46594, 1, 1637, 5170, '0', 0, 0, 0, 1, 1677.0999755859375, -4176.0400390625, 56.38853073120117187, 3.612831592559814453, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Sergeant Thunderhorn (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@CGUID+4, 46595, 1, 1637, 5170, '0', 0, 0, 0, 1, 1671.6600341796875, -4168.72021484375, 56.31843185424804687, 3.996803998947143554, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713); -- Blood Guard Zar'shi (Area: Valley of Strength - Difficulty: 0) CreateObject1

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
DELETE FROM `game_event_creature` WHERE `guid`=287063;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@ES9ENTRY, @CGUID+2), -- Doris Chiltonius
(@ES9ENTRY, @CGUID+3), -- Sergeant Thunderhorn
(@ES9ENTRY, @CGUID+4), -- Blood Guard Zar'shi
(@ES11ENTRY, 287063); -- Doris Chiltonius

UPDATE `creature` SET `position_x`=1650.2708740234375, `position_y`=-4164.49658203125, `position_z`=56.02971649169921875, `orientation`=5.379091262817382812, `VerifiedBuild`=56713 WHERE `id`=12793 AND `guid`=287051;
UPDATE `creature` SET `position_x`=1639.02783203125, `position_y`=-4176.37158203125, `position_z`=55.87273788452148437, `orientation`=6.19142770767211914, `VerifiedBuild`=56713 WHERE `id`=12794 AND `guid`=287068;
UPDATE `creature` SET `position_x`=1639.2847900390625, `position_y`=-4173.6337890625, `position_z`=55.87497329711914062, `orientation`=5.668282985687255859, `VerifiedBuild`=56713 WHERE `id`=12795 AND `guid`=287059;
UPDATE `creature` SET `position_x`=1642.138916015625, `position_y`=-4232.4619140625, `position_z`=52.21760177612304687, `orientation`=4.485496044158935546, `VerifiedBuild`=56713 WHERE `id`=12796 AND `guid`=287096;
UPDATE `creature` SET `position_x`=1653.34033203125, `position_y`=-4348.73291015625, `position_z`=64.61993408203125, `orientation`=0.471238881349563598, `VerifiedBuild`=56713 WHERE `id`=46555 AND `guid`=310910;
UPDATE `creature` SET `position_x`=1655.420166015625, `position_y`=-4353.29541015625, `position_z`=64.61993408203125, `orientation`=0.680678427219390869, `VerifiedBuild`=56713 WHERE `id`=46556 AND `guid`=310911;
UPDATE `creature` SET `position_x`=1653.704833984375, `position_y`=-4163.32470703125, `position_z`=56.0696563720703125, `orientation`=4.86946868896484375, `VerifiedBuild`=56713 WHERE `id`=52033 AND `guid`=287046;
UPDATE `creature` SET `position_x`=1663.35595703125, `position_y`=-4353.0849609375, `position_z`=64.61993408203125, `orientation`=2.199114799499511718, `VerifiedBuild`=56713 WHERE `id`=52034 AND `guid`=310915;
UPDATE `creature` SET `position_x`=1657.43408203125, `position_y`=-4162.93408203125, `position_z`=56.1173858642578125, `orientation`=4.620166778564453125, `VerifiedBuild`=56713 WHERE `id`=52036 AND `guid`=287044;

DELETE FROM `npc_vendor` WHERE (`entry`=46593 AND `item`=67468 AND `ExtendedCost`=3205 AND `type`=1) OR (`entry`=46593 AND `item`=67469 AND `ExtendedCost`=3207 AND `type`=1) OR (`entry`=46593 AND `item`=67470 AND `ExtendedCost`=3201 AND `type`=1) OR (`entry`=46593 AND `item`=67471 AND `ExtendedCost`=9209 AND `type`=1) OR (`entry`=46593 AND `item`=67472 AND `ExtendedCost`=3206 AND `type`=1) OR (`entry`=46593 AND `item`=67473 AND `ExtendedCost`=3203 AND `type`=1) OR (`entry`=46593 AND `item`=67474 AND `ExtendedCost`=3202 AND `type`=1) OR (`entry`=46593 AND `item`=67466 AND `ExtendedCost`=3199 AND `type`=1) OR (`entry`=46593 AND `item`=67467 AND `ExtendedCost`=3200 AND `type`=1) OR (`entry`=46593 AND `item`=67475 AND `ExtendedCost`=3197 AND `type`=1) OR (`entry`=46593 AND `item`=67476 AND `ExtendedCost`=3174 AND `type`=1) OR (`entry`=46593 AND `item`=67477 AND `ExtendedCost`=3198 AND `type`=1) OR (`entry`=46593 AND `item`=67462 AND `ExtendedCost`=3194 AND `type`=1) OR (`entry`=46593 AND `item`=67463 AND `ExtendedCost`=3195 AND `type`=1) OR (`entry`=46593 AND `item`=67464 AND `ExtendedCost`=3193 AND `type`=1) OR (`entry`=46593 AND `item`=67465 AND `ExtendedCost`=3196 AND `type`=1) OR (`entry`=46593 AND `item`=67461 AND `ExtendedCost`=3192 AND `type`=1) OR (`entry`=46593 AND `item`=67458 AND `ExtendedCost`=3189 AND `type`=1) OR (`entry`=46593 AND `item`=67459 AND `ExtendedCost`=3190 AND `type`=1) OR (`entry`=46593 AND `item`=67460 AND `ExtendedCost`=3191 AND `type`=1) OR (`entry`=46593 AND `item`=67454 AND `ExtendedCost`=3185 AND `type`=1) OR (`entry`=46593 AND `item`=67455 AND `ExtendedCost`=3186 AND `type`=1) OR (`entry`=46593 AND `item`=67456 AND `ExtendedCost`=3187 AND `type`=1) OR (`entry`=46593 AND `item`=67457 AND `ExtendedCost`=3188 AND `type`=1) OR (`entry`=46593 AND `item`=67478 AND `ExtendedCost`=3184 AND `type`=1) OR (`entry`=46593 AND `item`=67479 AND `ExtendedCost`=3183 AND `type`=1) OR (`entry`=46593 AND `item`=67447 AND `ExtendedCost`=3180 AND `type`=1) OR (`entry`=46593 AND `item`=67449 AND `ExtendedCost`=3179 AND `type`=1) OR (`entry`=46593 AND `item`=67450 AND `ExtendedCost`=3175 AND `type`=1) OR (`entry`=46593 AND `item`=67451 AND `ExtendedCost`=3181 AND `type`=1) OR (`entry`=46593 AND `item`=67452 AND `ExtendedCost`=3177 AND `type`=1) OR (`entry`=46593 AND `item`=67453 AND `ExtendedCost`=3178 AND `type`=1) OR (`entry`=46593 AND `item`=65580 AND `ExtendedCost`=3224 AND `type`=1) OR (`entry`=46593 AND `item`=65581 AND `ExtendedCost`=3223 AND `type`=1) OR (`entry`=46593 AND `item`=65582 AND `ExtendedCost`=3222 AND `type`=1) OR (`entry`=46593 AND `item`=65583 AND `ExtendedCost`=3221 AND `type`=1) OR (`entry`=46593 AND `item`=65584 AND `ExtendedCost`=3220 AND `type`=1) OR (`entry`=46593 AND `item`=65607 AND `ExtendedCost`=3231 AND `type`=1) OR (`entry`=46593 AND `item`=65608 AND `ExtendedCost`=3230 AND `type`=1) OR (`entry`=46594 AND `item`=61350 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=46594 AND `item`=61351 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=46594 AND `item`=61338 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61329 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61355 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61354 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61353 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61347 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=46594 AND `item`=61359 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61360 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61361 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61357 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61358 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61348 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=46594 AND `item`=61325 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61335 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61336 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61327 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61324 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61344 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61345 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61328 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61331 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61332 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=46594 AND `item`=61330 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61333 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=46594 AND `item`=61346 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61342 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61341 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61340 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61339 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61326 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=46594 AND `item`=61047 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61046 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61045 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61035 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61034 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61033 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61032 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61031 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=61026 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60807 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60806 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60801 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60651 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60650 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60673 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60670 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60778 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60776 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60523 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60521 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60513 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60512 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=46594 AND `item`=60509 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60508 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60422 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60421 AND `ExtendedCost`=3170 AND `type`=1) OR (`entry`=46594 AND `item`=60420 AND `ExtendedCost`=3170 AND `type`=1) OR (`entry`=46594 AND `item`=60419 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=46594 AND `item`=60418 AND `ExtendedCost`=3170 AND `type`=1) OR (`entry`=46595 AND `item`=68773 AND `ExtendedCost`=1005 AND `type`=1) OR (`entry`=46595 AND `item`=68772 AND `ExtendedCost`=1005 AND `type`=1) OR (`entry`=46595 AND `item`=68774 AND `ExtendedCost`=1005 AND `type`=1) OR (`entry`=46595 AND `item`=68768 AND `ExtendedCost`=2552 AND `type`=1) OR (`entry`=46595 AND `item`=68770 AND `ExtendedCost`=2552 AND `type`=1) OR (`entry`=46595 AND `item`=68769 AND `ExtendedCost`=2552 AND `type`=1) OR (`entry`=46595 AND `item`=64687 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64761 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64740 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64742 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64741 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64789 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64794 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64792 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64688 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64762 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64689 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64763 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64852 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64851 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64714 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64713 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64718 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64719 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64705 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64753 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64754 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64870 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64869 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64684 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64683 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=46595 AND `item`=64811 AND `ExtendedCost`=3162 AND `type`=1) OR (`entry`=46595 AND `item`=64812 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=46595 AND `item`=64813 AND `ExtendedCost`=3162 AND `type`=1) OR (`entry`=46595 AND `item`=64814 AND `ExtendedCost`=3162 AND `type`=1) OR (`entry`=46595 AND `item`=64815 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=52036 AND `item`=44092 AND `ExtendedCost`=2543 AND `type`=1) OR (`entry`=52036 AND `item`=44096 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44094 AND `ExtendedCost`=2544 AND `type`=1) OR (`entry`=52036 AND `item`=44095 AND `ExtendedCost`=2543 AND `type`=1) OR (`entry`=52036 AND `item`=44091 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44093 AND `ExtendedCost`=2543 AND `type`=1) OR (`entry`=52036 AND `item`=44107 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44103 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44105 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44102 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44101 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44099 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44100 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52036 AND `item`=44097 AND `ExtendedCost`=2544 AND `type`=1) OR (`entry`=52033 AND `item`=395 AND `ExtendedCost`=3410 AND `type`=2) OR (`entry`=52033 AND `item`=68813 AND `ExtendedCost`=9336 AND `type`=1) OR (`entry`=52033 AND `item`=52185 AND `ExtendedCost`=9335 AND `type`=1) OR (`entry`=52033 AND `item`=53010 AND `ExtendedCost`=9323 AND `type`=1) OR (`entry`=52033 AND `item`=52976 AND `ExtendedCost`=9325 AND `type`=1) OR (`entry`=52033 AND `item`=52721 AND `ExtendedCost`=9329 AND `type`=1) OR (`entry`=52033 AND `item`=52719 AND `ExtendedCost`=9331 AND `type`=1) OR (`entry`=52033 AND `item`=52555 AND `ExtendedCost`=9333 AND `type`=1) OR (`entry`=52033 AND `item`=52722 AND `ExtendedCost`=9327 AND `type`=1) OR (`entry`=12793 AND `item`=18607 AND `ExtendedCost`=7399 AND `type`=1) OR (`entry`=12793 AND `item`=15199 AND `ExtendedCost`=7398 AND `type`=1) OR (`entry`=12793 AND `item`=15197 AND `ExtendedCost`=7397 AND `type`=1) OR (`entry`=12793 AND `item`=32453 AND `ExtendedCost`=1564 AND `type`=1) OR (`entry`=12793 AND `item`=32455 AND `ExtendedCost`=460 AND `type`=1) OR (`entry`=12793 AND `item`=18841 AND `ExtendedCost`=460 AND `type`=1) OR (`entry`=12793 AND `item`=18839 AND `ExtendedCost`=460 AND `type`=1) OR (`entry`=12793 AND `item`=44957 AND `ExtendedCost`=2588 AND `type`=1) OR (`entry`=12788 AND `item`=30344 AND `ExtendedCost`=7480 AND `type`=1) OR (`entry`=12788 AND `item`=28855 AND `ExtendedCost`=7479 AND `type`=1) OR (`entry`=12788 AND `item`=28854 AND `ExtendedCost`=7478 AND `type`=1) OR (`entry`=12788 AND `item`=28853 AND `ExtendedCost`=7478 AND `type`=1) OR (`entry`=12788 AND `item`=28852 AND `ExtendedCost`=7479 AND `type`=1) OR (`entry`=12788 AND `item`=28851 AND `ExtendedCost`=7478 AND `type`=1) OR (`entry`=12788 AND `item`=28246 AND `ExtendedCost`=7480 AND `type`=1) OR (`entry`=12788 AND `item`=28247 AND `ExtendedCost`=7480 AND `type`=1) OR (`entry`=12788 AND `item`=28938 AND `ExtendedCost`=7482 AND `type`=1) OR (`entry`=12788 AND `item`=28939 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28930 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28929 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28922 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28928 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28937 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28926 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28925 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28924 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28921 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28920 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12788 AND `item`=28931 AND `ExtendedCost`=7476 AND `type`=1) OR (`entry`=12788 AND `item`=28933 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28935 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28293 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28923 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28919 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28917 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28918 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12788 AND `item`=28646 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=28381 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=32983 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=28643 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=28645 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=28383 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=32984 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=28642 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=28644 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=28385 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=32982 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=28641 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=28377 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12788 AND `item`=28379 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12788 AND `item`=28378 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12788 AND `item`=24551 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12788 AND `item`=28244 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12788 AND `item`=28245 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12788 AND `item`=24546 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=24547 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=24545 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=24549 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12788 AND `item`=24544 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12788 AND `item`=32452 AND `ExtendedCost`=7467 AND `type`=1) OR (`entry`=12788 AND `item`=28346 AND `ExtendedCost`=7467 AND `type`=1) OR (`entry`=12788 AND `item`=28320 AND `ExtendedCost`=7468 AND `type`=1) OR (`entry`=12788 AND `item`=28319 AND `ExtendedCost`=7468 AND `type`=1) OR (`entry`=12788 AND `item`=28358 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28310 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28312 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28314 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28313 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28307 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28295 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28302 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28305 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28309 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28308 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12788 AND `item`=28297 AND `ExtendedCost`=7473 AND `type`=1) OR (`entry`=12788 AND `item`=32451 AND `ExtendedCost`=7473 AND `type`=1) OR (`entry`=12788 AND `item`=32450 AND `ExtendedCost`=7473 AND `type`=1) OR (`entry`=12788 AND `item`=28294 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=24557 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=24550 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=28300 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=28476 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=28299 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=28298 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12788 AND `item`=32819 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=32818 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=32989 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=32813 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=32794 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32793 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32990 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32789 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32806 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32805 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32988 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=32801 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=28380 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33057 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33064 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33056 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33066 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33068 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33065 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=33067 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=30490 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=30489 AND `ExtendedCost`=7461 AND `type`=1) OR (`entry`=12788 AND `item`=30488 AND `ExtendedCost`=7461 AND `type`=1) OR (`entry`=12788 AND `item`=30487 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12788 AND `item`=30486 AND `ExtendedCost`=7461 AND `type`=1) OR (`entry`=12788 AND `item`=33309 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12788 AND `item`=33313 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12788 AND `item`=32961 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12788 AND `item`=31978 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12788 AND `item`=32054 AND `ExtendedCost`=7463 AND `type`=1) OR (`entry`=12788 AND `item`=32962 AND `ExtendedCost`=7463 AND `type`=1) OR (`entry`=12788 AND `item`=32045 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32046 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32044 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32003 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32028 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32027 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32052 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=31958 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32026 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=31985 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=31965 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12788 AND `item`=32053 AND `ExtendedCost`=7465 AND `type`=1) OR (`entry`=12788 AND `item`=32964 AND `ExtendedCost`=7465 AND `type`=1) OR (`entry`=12788 AND `item`=32963 AND `ExtendedCost`=7465 AND `type`=1) OR (`entry`=12788 AND `item`=31986 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=32055 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=31984 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=32025 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=32014 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=31959 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=31966 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12788 AND `item`=33911 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33910 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33909 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33812 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33813 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33811 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33905 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33904 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33903 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33890 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33889 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33888 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33923 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=35319 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33922 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=35317 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33921 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33920 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33919 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=35320 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33918 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33853 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12788 AND `item`=33732 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33731 AND `ExtendedCost`=7454 AND `type`=1) OR (`entry`=12788 AND `item`=33730 AND `ExtendedCost`=7454 AND `type`=1) OR (`entry`=12788 AND `item`=33729 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12788 AND `item`=33728 AND `ExtendedCost`=7454 AND `type`=1) OR (`entry`=12788 AND `item`=33736 AND `ExtendedCost`=7458 AND `type`=1) OR (`entry`=12788 AND `item`=34033 AND `ExtendedCost`=7458 AND `type`=1) OR (`entry`=12788 AND `item`=33681 AND `ExtendedCost`=7458 AND `type`=1) OR (`entry`=12788 AND `item`=33764 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12788 AND `item`=34066 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12788 AND `item`=34059 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12788 AND `item`=33765 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12788 AND `item`=33755 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33801 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33756 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33754 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=34016 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33705 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33737 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33734 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33762 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33662 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33733 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=34015 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33689 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33669 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12788 AND `item`=33735 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12788 AND `item`=33661 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12788 AND `item`=33763 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12788 AND `item`=33743 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12788 AND `item`=33687 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12788 AND `item`=33006 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=34530 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=34529 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=33766 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=33716 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=34540 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=33688 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=33727 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=33663 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=33670 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12788 AND `item`=41588 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=41589 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=41590 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=41587 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=34576 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=35327 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=34580 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=34578 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=34577 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=34579 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=37865 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12788 AND `item`=44429 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=41592 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=41591 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=44431 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35148 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35178 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35163 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35146 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35176 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35161 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35145 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35175 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35160 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35140 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35170 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35155 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35135 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=37928 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35134 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=37929 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35133 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35132 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35131 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=37927 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35130 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35129 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12788 AND `item`=35070 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35069 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12788 AND `item`=35068 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12788 AND `item`=35067 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12788 AND `item`=35066 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12788 AND `item`=35073 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12788 AND `item`=34986 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12788 AND `item`=35074 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12788 AND `item`=35016 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12788 AND `item`=35008 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12788 AND `item`=35107 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12788 AND `item`=35065 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12788 AND `item`=35108 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12788 AND `item`=34985 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12788 AND `item`=35094 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35095 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35058 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35093 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35037 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35038 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35076 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35072 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35101 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=34988 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35071 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=34995 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35017 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=34996 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12788 AND `item`=35102 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12788 AND `item`=35082 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12788 AND `item`=35014 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12788 AND `item`=35018 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=35075 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=35047 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=35103 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=34987 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=35109 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=35015 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=35064 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=34989 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12788 AND `item`=34997 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12795 AND `item`=18834 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12795 AND `item`=16335 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12795 AND `item`=18428 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12795 AND `item`=15200 AND `ExtendedCost`=838 AND `type`=1) OR (`entry`=12795 AND `item`=16541 AND `ExtendedCost`=7351 AND `type`=1) OR (`entry`=12795 AND `item`=16542 AND `ExtendedCost`=7351 AND `type`=1) OR (`entry`=12795 AND `item`=16544 AND `ExtendedCost`=7348 AND `type`=1) OR (`entry`=12795 AND `item`=16543 AND `ExtendedCost`=7351 AND `type`=1) OR (`entry`=12795 AND `item`=16545 AND `ExtendedCost`=7348 AND `type`=1) OR (`entry`=12795 AND `item`=16548 AND `ExtendedCost`=7348 AND `type`=1) OR (`entry`=12795 AND `item`=23244 AND `ExtendedCost`=7392 AND `type`=1) OR (`entry`=12795 AND `item`=23243 AND `ExtendedCost`=7393 AND `type`=1) OR (`entry`=12795 AND `item`=22872 AND `ExtendedCost`=7392 AND `type`=1) OR (`entry`=12795 AND `item`=22873 AND `ExtendedCost`=7392 AND `type`=1) OR (`entry`=12795 AND `item`=22868 AND `ExtendedCost`=7393 AND `type`=1) OR (`entry`=12795 AND `item`=22858 AND `ExtendedCost`=7393 AND `type`=1) OR (`entry`=12795 AND `item`=18429 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12795 AND `item`=18430 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12795 AND `item`=69862 AND `ExtendedCost`=821 AND `type`=1) OR (`entry`=12795 AND `item`=24551 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12795 AND `item`=37927 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35131 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35130 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35129 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=44429 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=44431 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=41591 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=41592 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35132 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35133 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35134 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35135 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=37928 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=37929 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35176 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35161 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35146 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35178 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35163 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35148 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35175 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35160 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35145 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35170 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12795 AND `item`=35155 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35140 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=51364 AND `ExtendedCost`=7932 AND `type`=1) OR (`entry`=12795 AND `item`=51361 AND `ExtendedCost`=7932 AND `type`=1) OR (`entry`=12795 AND `item`=51362 AND `ExtendedCost`=7930 AND `type`=1) OR (`entry`=12795 AND `item`=51359 AND `ExtendedCost`=7930 AND `type`=1) OR (`entry`=12795 AND `item`=51378 AND `ExtendedCost`=7963 AND `type`=1) OR (`entry`=12795 AND `item`=51355 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51353 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51349 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51357 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51347 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51335 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51333 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51331 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12795 AND `item`=51336 AND `ExtendedCost`=7935 AND `type`=1) OR (`entry`=12795 AND `item`=51358 AND `ExtendedCost`=7935 AND `type`=1) OR (`entry`=12795 AND `item`=51363 AND `ExtendedCost`=7931 AND `type`=1) OR (`entry`=12795 AND `item`=51360 AND `ExtendedCost`=7931 AND `type`=1) OR (`entry`=12795 AND `item`=51356 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51354 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51348 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51346 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51334 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51332 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51330 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12795 AND `item`=51545 AND `ExtendedCost`=7904 AND `type`=1) OR (`entry`=12795 AND `item`=51452 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12795 AND `item`=51455 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12795 AND `item`=51533 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12795 AND `item`=51544 AND `ExtendedCost`=7898 AND `type`=1) OR (`entry`=12795 AND `item`=51396 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12795 AND `item`=51409 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12795 AND `item`=51408 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12795 AND `item`=51407 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12795 AND `item`=51543 AND `ExtendedCost`=7897 AND `type`=1) OR (`entry`=12795 AND `item`=51542 AND `ExtendedCost`=7896 AND `type`=1) OR (`entry`=12795 AND `item`=51541 AND `ExtendedCost`=7895 AND `type`=1) OR (`entry`=12795 AND `item`=18461 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12795 AND `item`=16341 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12795 AND `item`=18427 AND `ExtendedCost`=1050 AND `type`=1) OR (`entry`=12795 AND `item`=35070 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35094 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12795 AND `item`=35073 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12795 AND `item`=34986 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12795 AND `item`=35069 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12795 AND `item`=35016 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12795 AND `item`=35074 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12795 AND `item`=35008 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12795 AND `item`=35068 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12795 AND `item`=35067 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12795 AND `item`=35066 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12794 AND `item`=51409 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12794 AND `item`=51408 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12794 AND `item`=51407 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12794 AND `item`=51396 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12794 AND `item`=51533 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12794 AND `item`=51455 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12794 AND `item`=51452 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12794 AND `item`=51535 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12794 AND `item`=51532 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12794 AND `item`=51531 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12794 AND `item`=51451 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12794 AND `item`=51410 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12794 AND `item`=51530 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51527 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51525 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51523 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51521 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51519 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51517 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51515 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51480 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51456 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51453 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51449 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51447 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51445 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51443 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51441 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51439 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12794 AND `item`=51411 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51406 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51404 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51402 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51400 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51397 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12794 AND `item`=51394 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51392 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51390 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=51388 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12794 AND `item`=35094 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35073 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12794 AND `item`=34986 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12794 AND `item`=35074 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12794 AND `item`=35016 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12794 AND `item`=35008 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12794 AND `item`=35108 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12794 AND `item`=34985 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12794 AND `item`=35065 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12794 AND `item`=35107 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12794 AND `item`=35103 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=34987 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=35109 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=35102 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12794 AND `item`=35082 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12794 AND `item`=35014 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12794 AND `item`=35047 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=35075 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=35018 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=35058 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35095 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35093 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=34988 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35071 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35017 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=34996 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=34995 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35037 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35038 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35076 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35072 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35101 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12794 AND `item`=35064 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=34997 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=34989 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=35015 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12794 AND `item`=23469 AND `ExtendedCost`=7350 AND `type`=1) OR (`entry`=12794 AND `item`=23468 AND `ExtendedCost`=7350 AND `type`=1) OR (`entry`=12794 AND `item`=23466 AND `ExtendedCost`=7345 AND `type`=1) OR (`entry`=12794 AND `item`=18874 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18860 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18837 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18835 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18826 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=18840 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=18848 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=18844 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=23464 AND `ExtendedCost`=7345 AND `type`=1) OR (`entry`=12794 AND `item`=18866 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=23467 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=16345 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=18828 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12794 AND `item`=18871 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=23465 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18868 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18831 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12794 AND `item`=18877 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12796 AND `item`=34129 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12796 AND `item`=29472 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12796 AND `item`=29470 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12796 AND `item`=29469 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12796 AND `item`=29466 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=52034 AND `item`=1901 AND `ExtendedCost`=3408 AND `type`=2) OR (`entry`=52034 AND `item`=68813 AND `ExtendedCost`=9337 AND `type`=1) OR (`entry`=52034 AND `item`=52185 AND `ExtendedCost`=9334 AND `type`=1) OR (`entry`=52034 AND `item`=53010 AND `ExtendedCost`=9322 AND `type`=1) OR (`entry`=52034 AND `item`=52976 AND `ExtendedCost`=9324 AND `type`=1) OR (`entry`=52034 AND `item`=52721 AND `ExtendedCost`=9328 AND `type`=1) OR (`entry`=52034 AND `item`=52719 AND `ExtendedCost`=9330 AND `type`=1) OR (`entry`=52034 AND `item`=52555 AND `ExtendedCost`=9332 AND `type`=1) OR (`entry`=52034 AND `item`=52722 AND `ExtendedCost`=9326 AND `type`=1) OR (`entry`=46556 AND `item`=390 AND `ExtendedCost`=3411 AND `type`=2) OR (`entry`=46556 AND `item`=65273 AND `ExtendedCost`=3120 AND `type`=1) OR (`entry`=46556 AND `item`=65272 AND `ExtendedCost`=3097 AND `type`=1) OR (`entry`=46556 AND `item`=65271 AND `ExtendedCost`=3056 AND `type`=1) OR (`entry`=46556 AND `item`=65270 AND `ExtendedCost`=3161 AND `type`=1) OR (`entry`=46556 AND `item`=65269 AND `ExtendedCost`=3086 AND `type`=1) OR (`entry`=46556 AND `item`=65268 AND `ExtendedCost`=3048 AND `type`=1) OR (`entry`=46556 AND `item`=65267 AND `ExtendedCost`=3115 AND `type`=1) OR (`entry`=46556 AND `item`=65266 AND `ExtendedCost`=3056 AND `type`=1) OR (`entry`=46556 AND `item`=65265 AND `ExtendedCost`=3160 AND `type`=1) OR (`entry`=46556 AND `item`=65264 AND `ExtendedCost`=3087 AND `type`=1) OR (`entry`=46556 AND `item`=60332 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=60331 AND `ExtendedCost`=3045 AND `type`=1) OR (`entry`=46556 AND `item`=60330 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=46556 AND `item`=60329 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=46556 AND `item`=60328 AND `ExtendedCost`=3051 AND `type`=1) OR (`entry`=46556 AND `item`=60327 AND `ExtendedCost`=3045 AND `type`=1) OR (`entry`=46556 AND `item`=60326 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=60325 AND `ExtendedCost`=3051 AND `type`=1) OR (`entry`=46556 AND `item`=60324 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=46556 AND `item`=60323 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=46556 AND `item`=58180 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58181 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58182 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58183 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58184 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=64671 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=46556 AND `item`=64672 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=46556 AND `item`=64673 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=46556 AND `item`=64674 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=46556 AND `item`=64676 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=46556 AND `item`=68812 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58185 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58187 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58188 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58189 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58195 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58197 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58198 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58199 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58481 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58482 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58484 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58485 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58486 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=46556 AND `item`=58191 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58192 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58193 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58190 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=58194 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=46556 AND `item`=67427 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=46556 AND `item`=65000 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=46556 AND `item`=67430 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=46556 AND `item`=65087 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=46556 AND `item`=67424 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=46555 AND `item`=57919 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57921 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57916 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57915 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57913 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57914 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57922 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57918 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57917 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58157 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58151 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58124 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58109 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58100 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58104 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58162 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58134 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58129 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=57925 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=57926 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=58153 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58139 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58159 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=57927 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=57928 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=57929 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=57931 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=46555 AND `item`=57933 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=46555 AND `item`=57934 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=46555 AND `item`=57930 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=46555 AND `item`=57932 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=46555 AND `item`=58154 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58140 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58122 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58107 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58097 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58102 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58160 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58132 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58127 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=57923 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=57924 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=46555 AND `item`=58155 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58150 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58123 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58108 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58098 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58103 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58161 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58133 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58128 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58158 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58152 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58125 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58110 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58099 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58105 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58163 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58138 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58130 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=46555 AND `item`=58121 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58106 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58096 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58101 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58131 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=46555 AND `item`=58126 AND `ExtendedCost`=3038 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(46593, 128, 67468, 0, 3205, 1, 0, 0, 56713), -- Vicious Gladiator's Quickblade
(46593, 127, 67469, 0, 3207, 1, 0, 0, 56713), -- Vicious Gladiator's Slicer
(46593, 126, 67470, 0, 3201, 1, 0, 0, 56713), -- Vicious Gladiator's Bonecracker
(46593, 125, 67471, 0, 9209, 1, 0, 0, 56713), -- Vicious Gladiator's Pummeler
(46593, 124, 67472, 0, 3206, 1, 0, 0, 56713), -- Vicious Gladiator's Shanker
(46593, 123, 67473, 0, 3203, 1, 0, 0, 56713), -- Vicious Gladiator's Hacker
(46593, 122, 67474, 0, 3202, 1, 0, 0, 56713), -- Vicious Gladiator's Cleaver
(46593, 121, 67466, 0, 3199, 1, 0, 0, 56713), -- Vicious Gladiator's Hatchet
(46593, 120, 67467, 0, 3200, 1, 0, 0, 56713), -- Vicious Gladiator's War Edge
(46593, 119, 67475, 0, 3197, 1, 0, 0, 56713), -- Vicious Gladiator's Redoubt
(46593, 118, 67476, 0, 3174, 1, 0, 0, 56713), -- Vicious Gladiator's Barrier
(46593, 117, 67477, 0, 3198, 1, 0, 0, 56713), -- Vicious Gladiator's Shield Wall
(46593, 116, 67462, 0, 3194, 1, 0, 0, 56713), -- Vicious Gladiator's Heavy Crossbow
(46593, 115, 67463, 0, 3195, 1, 0, 0, 56713), -- Vicious Gladiator's Rifle
(46593, 114, 67464, 0, 3193, 1, 0, 0, 56713), -- Vicious Gladiator's Baton of Light
(46593, 113, 67465, 0, 3196, 1, 0, 0, 56713), -- Vicious Gladiator's Touch of Defeat
(46593, 112, 67461, 0, 3192, 1, 0, 0, 56713), -- Vicious Gladiator's Longbow
(46593, 111, 67458, 0, 3189, 1, 0, 0, 56713), -- Vicious Gladiator's Slasher
(46593, 110, 67459, 0, 3190, 1, 0, 0, 56713), -- Vicious Gladiator's Fleshslicer
(46593, 109, 67460, 0, 3191, 1, 0, 0, 56713), -- Vicious Gladiator's Shiv
(46593, 108, 67454, 0, 3185, 1, 0, 0, 56713), -- Vicious Gladiator's Gavel
(46593, 107, 67455, 0, 3186, 1, 0, 0, 56713), -- Vicious Gladiator's Right Render
(46593, 106, 67456, 0, 3187, 1, 0, 0, 56713), -- Vicious Gladiator's Ripper
(46593, 105, 67457, 0, 3188, 1, 0, 0, 56713), -- Vicious Gladiator's Spellblade
(46593, 104, 67478, 0, 3184, 1, 0, 0, 56713), -- Vicious Gladiator's Reprieve
(46593, 103, 67479, 0, 3183, 1, 0, 0, 56713), -- Vicious Gladiator's Endgame
(46593, 102, 67447, 0, 3180, 1, 0, 0, 56713), -- Vicious Gladiator's Greatsword
(46593, 100, 67449, 0, 3179, 1, 0, 0, 56713), -- Vicious Gladiator's Energy Staff
(46593, 99, 67450, 0, 3175, 1, 0, 0, 56713), -- Vicious Gladiator's Battle Staff
(46593, 98, 67451, 0, 3181, 1, 0, 0, 56713), -- Vicious Gladiator's Pike
(46593, 97, 67452, 0, 3177, 1, 0, 0, 56713), -- Vicious Gladiator's Bonegrinder
(46593, 96, 67453, 0, 3178, 1, 0, 0, 56713), -- Vicious Gladiator's Decapitator
(46593, 19, 65580, 0, 3224, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Shoulders
(46593, 18, 65581, 0, 3223, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Legguards
(46593, 17, 65582, 0, 3222, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Helm
(46593, 16, 65583, 0, 3221, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Gauntlets
(46593, 15, 65584, 0, 3220, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Chestpiece
(46593, 2, 65607, 0, 3231, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Cruelty
(46593, 1, 65608, 0, 3230, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Alacrity
(46594, 198, 61350, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's Touch of Defeat
(46594, 197, 61351, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's Baton of Light
(46594, 196, 61338, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Gavel
(46594, 195, 61329, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Spellblade
(46594, 194, 61355, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Heavy Crossbow
(46594, 193, 61354, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Rifle
(46594, 192, 61353, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Longbow
(46594, 191, 61347, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's War Edge
(46594, 190, 61359, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Shield Wall
(46594, 189, 61360, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Barrier
(46594, 188, 61361, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Redoubt
(46594, 187, 61357, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Endgame
(46594, 186, 61358, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Reprieve
(46594, 185, 61348, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's Hatchet
(46594, 184, 61325, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Hacker
(46594, 183, 61335, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Pummeler
(46594, 182, 61336, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Bonecracker
(46594, 181, 61327, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Shanker
(46594, 180, 61324, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Cleaver
(46594, 179, 61344, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Slicer
(46594, 178, 61345, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Quickblade
(46594, 177, 61328, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Shiv
(46594, 176, 61331, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Fleshslicer
(46594, 175, 61332, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Slasher
(46594, 174, 61330, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Ripper
(46594, 173, 61333, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Right Render
(46594, 172, 61346, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Greatsword
(46594, 170, 61342, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Energy Staff
(46594, 169, 61341, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Battle Staff
(46594, 168, 61340, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Pike
(46594, 167, 61339, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Bonegrinder
(46594, 166, 61326, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Decapitator
(46594, 161, 61047, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Insignia of Conquest
(46594, 160, 61046, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Insignia of Victory
(46594, 159, 61045, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Insignia of Dominance
(46594, 158, 61035, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Badge of Dominance
(46594, 157, 61034, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Badge of Victory
(46594, 156, 61033, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Badge of Conquest
(46594, 155, 61032, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Emblem of Tenacity
(46594, 154, 61031, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Emblem of Meditation
(46594, 153, 61026, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Emblem of Cruelty
(46594, 152, 60807, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Medallion of Tenacity
(46594, 151, 60806, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Medallion of Meditation
(46594, 150, 60801, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Medallion of Cruelty
(46594, 144, 60651, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Signet of Accuracy
(46594, 143, 60650, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Signet of Cruelty
(46594, 139, 60673, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Choker of Accuracy
(46594, 138, 60670, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Choker of Proficiency
(46594, 127, 60778, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Cloak of Prowess
(46594, 126, 60776, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Cloak of Alacrity
(46594, 24, 60523, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Armplates of Proficiency
(46594, 23, 60521, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Girdle of Prowess
(46594, 20, 60513, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Alacrity
(46594, 19, 60512, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Armplates of Alacrity
(46594, 18, 60509, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Cruelty
(46594, 17, 60508, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Girdle of Cruelty
(46594, 15, 60422, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Shoulders
(46594, 14, 60421, 0, 3170, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Legguards
(46594, 13, 60420, 0, 3170, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Helm
(46594, 12, 60419, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Gauntlets
(46594, 11, 60418, 0, 3170, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Chestpiece
(46595, 171, 68773, 0, 1005, 1, 0, 0, 56713), -- Greater Inscription of Vicious Strength
(46595, 170, 68772, 0, 1005, 1, 0, 0, 56713), -- Greater Inscription of Vicious Intellect
(46595, 169, 68774, 0, 1005, 1, 0, 0, 56713), -- Greater Inscription of Vicious Agility
(46595, 168, 68768, 0, 2552, 1, 0, 0, 56713), -- Arcanum of Vicious Strength
(46595, 167, 68770, 0, 2552, 1, 0, 0, 56713), -- Arcanum of Vicious Intellect
(46595, 166, 68769, 0, 2552, 1, 0, 0, 56713), -- Arcanum of Vicious Agility
(46595, 161, 64687, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Badge of Conquest
(46595, 160, 64761, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Insignia of Conquest
(46595, 159, 64740, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Emblem of Cruelty
(46595, 158, 64742, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Emblem of Tenacity
(46595, 157, 64741, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Emblem of Meditation
(46595, 155, 64789, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Medallion of Cruelty
(46595, 154, 64794, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Medallion of Tenacity
(46595, 152, 64792, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Medallion of Meditation
(46595, 150, 64688, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Badge of Dominance
(46595, 149, 64762, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Insignia of Dominance
(46595, 148, 64689, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Badge of Victory
(46595, 147, 64763, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Insignia of Victory
(46595, 141, 64852, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Signet of Cruelty
(46595, 140, 64851, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Signet of Accuracy
(46595, 134, 64714, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Choker of Proficiency
(46595, 133, 64713, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Choker of Accuracy
(46595, 127, 64718, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Cloak of Alacrity
(46595, 126, 64719, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Cloak of Prowess
(46595, 18, 64705, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Bracers of Prowess
(46595, 11, 64753, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Girdle of Cruelty
(46595, 10, 64754, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Girdle of Prowess
(46595, 9, 64870, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Warboots of Cruelty
(46595, 8, 64869, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Warboots of Alacrity
(46595, 7, 64684, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Armplates of Proficiency
(46595, 6, 64683, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Armplates of Alacrity
(46595, 5, 64811, 0, 3162, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Chestpiece
(46595, 4, 64812, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Gauntlets
(46595, 3, 64813, 0, 3162, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Helm
(46595, 2, 64814, 0, 3162, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Legguards
(46595, 1, 64815, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Shoulders
(52036, 15, 44092, 0, 2543, 1, 0, 0, 56713), -- Reforged Truesilver Champion
(52036, 14, 44096, 0, 2542, 1, 0, 0, 56713), -- Battleworn Thrash Blade
(52036, 13, 44094, 0, 2544, 1, 0, 0, 56713), -- The Blessed Hammer of Grace
(52036, 12, 44095, 0, 2543, 1, 0, 0, 56713), -- Grand Staff of Jordan
(52036, 11, 44091, 0, 2542, 1, 0, 0, 56713), -- Sharpened Scarlet Kris
(52036, 10, 44093, 0, 2543, 1, 0, 0, 56713), -- Upgraded Dwarven Hand Cannon
(52036, 9, 44107, 0, 2542, 1, 0, 0, 56713), -- Exquisite Sunderseer Mantle
(52036, 8, 44103, 0, 2542, 1, 0, 0, 56713), -- Exceptional Stormshroud Shoulders
(52036, 7, 44105, 0, 2542, 1, 0, 0, 56713), -- Lasting Feralheart Spaulders
(52036, 6, 44102, 0, 2542, 1, 0, 0, 56713), -- Aged Pauldrons of The Five Thunders
(52036, 5, 44101, 0, 2542, 1, 0, 0, 56713), -- Prized Beastmaster's Mantle
(52036, 4, 44099, 0, 2542, 1, 0, 0, 56713), -- Strengthened Stockade Pauldrons
(52036, 3, 44100, 0, 2542, 1, 0, 0, 56713), -- Pristine Lightforge Spaulders
(52036, 2, 44097, 0, 2544, 1, 0, 0, 56713), -- Inherited Insignia of the Horde
(52033, 9, 395, 25000, 3410, 2, 0, 0, 56713), -- 395
(52033, 8, 68813, 0, 9336, 1, 0, 0, 56713), -- Satchel of Freshly-Picked Herbs
(52033, 7, 52185, 0, 9335, 1, 0, 0, 56713), -- Elementium Ore
(52033, 6, 53010, 0, 9323, 1, 0, 0, 56713), -- Embersilk Cloth
(52033, 5, 52976, 0, 9325, 1, 0, 0, 56713), -- Savage Leather
(52033, 4, 52721, 0, 9329, 1, 0, 0, 56713), -- Heavenly Shard
(52033, 3, 52719, 0, 9331, 1, 0, 0, 56713), -- Greater Celestial Essence
(52033, 2, 52555, 0, 9333, 1, 0, 0, 56713), -- Hypnotic Dust
(52033, 1, 52722, 0, 9327, 1, 0, 0, 56713), -- Maelstrom Crystal
(12793, 10, 18607, 0, 7399, 1, 0, 0, 56713), -- Horde Battle Standard
(12793, 9, 15199, 0, 7398, 1, 0, 0, 56713), -- Stone Guard's Herald
(12793, 8, 15197, 0, 7397, 1, 0, 0, 56713), -- Scout's Tabard
(12793, 7, 32453, 0, 1564, 1, 0, 0, 56713), -- Star's Tears
(12793, 6, 32455, 0, 460, 1, 0, 0, 56713), -- Star's Lament
(12793, 3, 18841, 0, 460, 1, 0, 0, 56713), -- Combat Mana Potion
(12793, 2, 18839, 0, 460, 1, 0, 0, 56713), -- Combat Healing Potion
(12793, 1, 44957, 0, 2588, 1, 0, 0, 56713), -- Greater Inscription of the Gladiator
(12788, 999, 30344, 0, 7480, 1, 0, 0, 56713), -- Medallion of the Horde
(12788, 963, 28855, 0, 7479, 1, 0, 0, 56713), -- High Warlord's Plate Shoulders
(12788, 962, 28854, 0, 7478, 1, 0, 0, 56713), -- High Warlord's Plate Legguards
(12788, 961, 28853, 0, 7478, 1, 0, 0, 56713), -- High Warlord's Plate Helm
(12788, 960, 28852, 0, 7479, 1, 0, 0, 56713), -- High Warlord's Plate Gauntlets
(12788, 959, 28851, 0, 7478, 1, 0, 0, 56713), -- High Warlord's Plate Chestpiece
(12788, 828, 28246, 0, 7480, 1, 0, 0, 56713), -- Band of Triumph
(12788, 827, 28247, 0, 7480, 1, 0, 0, 56713), -- Band of Dominance
(12788, 825, 28938, 0, 7482, 1, 0, 0, 56713), -- High Warlord's Battletome
(12788, 824, 28939, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Barricade
(12788, 822, 28930, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Shiv
(12788, 821, 28929, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Shanker
(12788, 818, 28922, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Fleshslicer
(12788, 816, 28928, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Ripper
(12788, 814, 28937, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Slicer
(12788, 813, 28926, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Quickblade
(12788, 810, 28925, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Pummeler
(12788, 809, 28924, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Bonecracker
(12788, 806, 28921, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Hacker
(12788, 805, 28920, 0, 7477, 1, 0, 0, 56713), -- High Warlord's Cleaver
(12788, 802, 28931, 0, 7476, 1, 0, 0, 56713), -- High Warlord's Spellblade
(12788, 800, 28933, 0, 7475, 1, 0, 0, 56713), -- High Warlord's Heavy Crossbow
(12788, 798, 28935, 0, 7475, 1, 0, 0, 56713), -- High Warlord's War Staff
(12788, 796, 28293, 0, 7475, 1, 0, 0, 56713), -- High Warlord's Claymore
(12788, 794, 28923, 0, 7475, 1, 0, 0, 56713), -- High Warlord's Painsaw
(12788, 792, 28919, 0, 7475, 1, 0, 0, 56713), -- High Warlord's Maul
(12788, 791, 28917, 0, 7475, 1, 0, 0, 56713), -- High Warlord's Bonegrinder
(12788, 788, 28918, 0, 7475, 1, 0, 0, 56713), -- High Warlord's Decapitator
(12788, 782, 28646, 0, 7471, 1, 0, 0, 56713), -- General's Scaled Bracers
(12788, 781, 28381, 0, 7471, 1, 0, 0, 56713), -- General's Plate Bracers
(12788, 780, 32983, 0, 7471, 1, 0, 0, 56713), -- General's Ornamented Bracers
(12788, 779, 28643, 0, 7471, 1, 0, 0, 56713), -- General's Lamellar Bracers
(12788, 774, 28645, 0, 7470, 1, 0, 0, 56713), -- General's Scaled Greaves
(12788, 773, 28383, 0, 7470, 1, 0, 0, 56713), -- General's Plate Greaves
(12788, 772, 32984, 0, 7470, 1, 0, 0, 56713), -- General's Ornamented Greaves
(12788, 771, 28642, 0, 7470, 1, 0, 0, 56713), -- General's Lamellar Greaves
(12788, 766, 28644, 0, 7470, 1, 0, 0, 56713), -- General's Scaled Belt
(12788, 765, 28385, 0, 7470, 1, 0, 0, 56713), -- General's Plate Belt
(12788, 764, 32982, 0, 7470, 1, 0, 0, 56713), -- General's Ornamented Belt
(12788, 763, 28641, 0, 7470, 1, 0, 0, 56713), -- General's Lamellar Belt
(12788, 714, 28377, 0, 7469, 1, 0, 0, 56713), -- Sergeant's Heavy Cloak
(12788, 713, 28379, 0, 7469, 1, 0, 0, 56713), -- Sergeant's Heavy Cape
(12788, 712, 28378, 0, 7469, 1, 0, 0, 56713), -- Sergeant's Heavy Cape
(12788, 693, 24551, 0, 7469, 1, 0, 0, 56713), -- Talisman of the Horde
(12788, 691, 28244, 0, 7469, 1, 0, 0, 56713), -- Pendant of Triumph
(12788, 690, 28245, 0, 7469, 1, 0, 0, 56713), -- Pendant of Dominance
(12788, 664, 24546, 0, 7470, 1, 0, 0, 56713), -- Gladiator's Plate Shoulders
(12788, 663, 24547, 0, 7471, 1, 0, 0, 56713), -- Gladiator's Plate Legguards
(12788, 662, 24545, 0, 7471, 1, 0, 0, 56713), -- Gladiator's Plate Helm
(12788, 661, 24549, 0, 7470, 1, 0, 0, 56713), -- Gladiator's Plate Gauntlets
(12788, 660, 24544, 0, 7471, 1, 0, 0, 56713), -- Gladiator's Plate Chestpiece
(12788, 604, 32452, 0, 7467, 1, 0, 0, 56713), -- Gladiator's Reprieve
(12788, 603, 28346, 0, 7467, 1, 0, 0, 56713), -- Gladiator's Endgame
(12788, 593, 28320, 0, 7468, 1, 0, 0, 56713), -- Gladiator's Touch of Defeat
(12788, 592, 28319, 0, 7468, 1, 0, 0, 56713), -- Gladiator's War Edge
(12788, 591, 28358, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Shield Wall
(12788, 590, 28310, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Shiv
(12788, 589, 28312, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Shanker
(12788, 588, 28314, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Fleshslicer
(12788, 587, 28313, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Ripper
(12788, 586, 28307, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Quickblade
(12788, 585, 28295, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Slicer
(12788, 584, 28302, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Bonecracker
(12788, 583, 28305, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Pummeler
(12788, 582, 28309, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Hacker
(12788, 581, 28308, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Cleaver
(12788, 580, 28297, 0, 7473, 1, 0, 0, 56713), -- Gladiator's Spellblade
(12788, 579, 32451, 0, 7473, 1, 0, 0, 56713), -- Gladiator's Salvation
(12788, 578, 32450, 0, 7473, 1, 0, 0, 56713), -- Gladiator's Gavel
(12788, 577, 28294, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Heavy Crossbow
(12788, 576, 24557, 0, 7474, 1, 0, 0, 56713), -- Gladiator's War Staff
(12788, 575, 24550, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Greatsword
(12788, 574, 28300, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Painsaw
(12788, 573, 28476, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Maul
(12788, 572, 28299, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Bonegrinder
(12788, 571, 28298, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Decapitator
(12788, 570, 32819, 0, 7388, 1, 0, 0, 56713), -- Veteran's Scaled Bracers
(12788, 569, 32818, 0, 7388, 1, 0, 0, 56713), -- Veteran's Plate Bracers
(12788, 568, 32989, 0, 7388, 1, 0, 0, 56713), -- Veteran's Ornamented Bracers
(12788, 567, 32813, 0, 7388, 1, 0, 0, 56713), -- Veteran's Lamellar Bracers
(12788, 566, 32794, 0, 7460, 1, 0, 0, 56713), -- Veteran's Scaled Greaves
(12788, 565, 32793, 0, 7460, 1, 0, 0, 56713), -- Veteran's Plate Greaves
(12788, 564, 32990, 0, 7460, 1, 0, 0, 56713); -- Veteran's Ornamented Greaves

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12788, 563, 32789, 0, 7460, 1, 0, 0, 56713), -- Veteran's Lamellar Greaves
(12788, 562, 32806, 0, 7460, 1, 0, 0, 56713), -- Veteran's Scaled Belt
(12788, 561, 32805, 0, 7460, 1, 0, 0, 56713), -- Veteran's Plate Belt
(12788, 560, 32988, 0, 7460, 1, 0, 0, 56713), -- Veteran's Ornamented Belt
(12788, 559, 32801, 0, 7460, 1, 0, 0, 56713), -- Veteran's Lamellar Belt
(12788, 534, 28380, 0, 7388, 1, 0, 0, 56713), -- Sergeant's Heavy Cloak
(12788, 524, 33057, 0, 7388, 1, 0, 0, 56713), -- Veteran's Band of Triumph
(12788, 523, 33064, 0, 7388, 1, 0, 0, 56713), -- Veteran's Band of Salvation
(12788, 522, 33056, 0, 7388, 1, 0, 0, 56713), -- Veteran's Band of Dominance
(12788, 521, 33066, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Triumph
(12788, 520, 33068, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Salvation
(12788, 519, 33065, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Dominance
(12788, 518, 33067, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Conquest
(12788, 492, 30490, 0, 7460, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Shoulders
(12788, 491, 30489, 0, 7461, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Legguards
(12788, 490, 30488, 0, 7461, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Helm
(12788, 489, 30487, 0, 7460, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Gauntlets
(12788, 488, 30486, 0, 7461, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Chestpiece
(12788, 432, 33309, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Redoubt
(12788, 431, 33313, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Barrier
(12788, 430, 32961, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Reprieve
(12788, 429, 31978, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Endgame
(12788, 419, 32054, 0, 7463, 1, 0, 0, 56713), -- Merciless Gladiator's War Edge
(12788, 418, 32962, 0, 7463, 1, 0, 0, 56713), -- Merciless Gladiator's Touch of Defeat
(12788, 417, 32045, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Shield Wall
(12788, 416, 32046, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Shiv
(12788, 415, 32044, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Shanker
(12788, 414, 32003, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Fleshslicer
(12788, 413, 32028, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Ripper
(12788, 412, 32027, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Quickblade
(12788, 411, 32052, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Slicer
(12788, 410, 31958, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Bonecracker
(12788, 409, 32026, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Pummeler
(12788, 408, 31985, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Hacker
(12788, 407, 31965, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Cleaver
(12788, 406, 32053, 0, 7465, 1, 0, 0, 56713), -- Merciless Gladiator's Spellblade
(12788, 405, 32964, 0, 7465, 1, 0, 0, 56713), -- Merciless Gladiator's Salvation
(12788, 404, 32963, 0, 7465, 1, 0, 0, 56713), -- Merciless Gladiator's Gavel
(12788, 403, 31986, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Crossbow of the Phoenix
(12788, 402, 32055, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's War Staff
(12788, 401, 31984, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Greatsword
(12788, 400, 32025, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Painsaw
(12788, 399, 32014, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Maul
(12788, 398, 31959, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Bonegrinder
(12788, 397, 31966, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Decapitator
(12788, 396, 33911, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Scaled Greaves
(12788, 395, 33910, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Scaled Bracers
(12788, 394, 33909, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Scaled Belt
(12788, 393, 33812, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Plate Greaves
(12788, 392, 33813, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Plate Bracers
(12788, 391, 33811, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Plate Belt
(12788, 390, 33905, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Ornamented Greaves
(12788, 389, 33904, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Ornamented Bracers
(12788, 388, 33903, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Ornamented Belt
(12788, 387, 33890, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Lamellar Greaves
(12788, 386, 33889, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Lamellar Bracers
(12788, 385, 33888, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Lamellar Belt
(12788, 351, 33923, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Triumph
(12788, 350, 35319, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Subjugation
(12788, 349, 33922, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Salvation
(12788, 348, 35317, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Reprieve
(12788, 347, 33921, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Dominance
(12788, 346, 33920, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Conquest
(12788, 345, 33919, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Triumph
(12788, 344, 35320, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Subjugation
(12788, 343, 33918, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Salvation
(12788, 342, 33853, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Dominance
(12788, 316, 33732, 0, 7390, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Shoulders
(12788, 315, 33731, 0, 7454, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Legguards
(12788, 314, 33730, 0, 7454, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Helm
(12788, 313, 33729, 0, 7390, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Gauntlets
(12788, 312, 33728, 0, 7454, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Chestpiece
(12788, 256, 33736, 0, 7458, 1, 0, 0, 56713), -- Vengeful Gladiator's Reprieve
(12788, 255, 34033, 0, 7458, 1, 0, 0, 56713), -- Vengeful Gladiator's Grimoire
(12788, 254, 33681, 0, 7458, 1, 0, 0, 56713), -- Vengeful Gladiator's Endgame
(12788, 244, 33764, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's Touch of Defeat
(12788, 243, 34066, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's Piercing Touch
(12788, 242, 34059, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's Baton of Light
(12788, 241, 33765, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's War Edge
(12788, 239, 33755, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Shield Wall
(12788, 238, 33801, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Mutilator
(12788, 237, 33756, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Shiv
(12788, 236, 33754, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Shanker
(12788, 235, 34016, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Slasher
(12788, 234, 33705, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Fleshslicer
(12788, 233, 33737, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Ripper
(12788, 232, 33734, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Quickblade
(12788, 231, 33762, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Slicer
(12788, 230, 33662, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Bonecracker
(12788, 229, 33733, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Pummeler
(12788, 228, 34015, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Chopper
(12788, 227, 33689, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Hacker
(12788, 226, 33669, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Cleaver
(12788, 225, 33735, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Redoubt
(12788, 224, 33661, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Barrier
(12788, 223, 33763, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Spellblade
(12788, 222, 33743, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Salvation
(12788, 221, 33687, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Gavel
(12788, 220, 33006, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Heavy Crossbow
(12788, 219, 34530, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Rifle
(12788, 218, 34529, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Longbow
(12788, 217, 33766, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's War Staff
(12788, 216, 33716, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Staff
(12788, 215, 34540, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Battle Staff
(12788, 214, 33688, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Greatsword
(12788, 213, 33727, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Painsaw
(12788, 212, 33663, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Bonegrinder
(12788, 211, 33670, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Decapitator
(12788, 210, 41588, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Aggression
(12788, 209, 41589, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Resolve
(12788, 208, 41590, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Courage
(12788, 207, 41587, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Celerity
(12788, 206, 34576, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Cruelty
(12788, 205, 35327, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Alacrity
(12788, 204, 34580, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Perseverance
(12788, 203, 34578, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Determination
(12788, 202, 34577, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Depravity
(12788, 201, 34579, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Audacity
(12788, 200, 37865, 0, 7388, 1, 0, 0, 56713), -- Medallion of the Horde
(12788, 198, 44429, 0, 7386, 1, 0, 0, 56713), -- Volanthius Shroud
(12788, 197, 41592, 0, 7386, 1, 0, 0, 56713), -- The Gladiator's Resolution
(12788, 196, 41591, 0, 7386, 1, 0, 0, 56713), -- Sergeant's Reinforced Cape
(12788, 195, 44431, 0, 7386, 1, 0, 0, 56713), -- Cloak of Certain Reprieve
(12788, 194, 35148, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Greaves
(12788, 193, 35178, 0, 7386, 1, 0, 0, 56713), -- Guardian's Scaled Bracers
(12788, 192, 35163, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Belt
(12788, 191, 35146, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Greaves
(12788, 190, 35176, 0, 7386, 1, 0, 0, 56713), -- Guardian's Plate Bracers
(12788, 189, 35161, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Belt
(12788, 188, 35145, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Greaves
(12788, 187, 35175, 0, 7386, 1, 0, 0, 56713), -- Guardian's Ornamented Bracers
(12788, 186, 35160, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Belt
(12788, 185, 35140, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Greaves
(12788, 184, 35170, 0, 7386, 1, 0, 0, 56713), -- Guardian's Lamellar Bracers
(12788, 183, 35155, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Belt
(12788, 149, 35135, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Triumph
(12788, 148, 37928, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Subjugation
(12788, 147, 35134, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Salvation
(12788, 146, 37929, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Reprieve
(12788, 145, 35133, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Dominance
(12788, 144, 35132, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Conquest
(12788, 143, 35131, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Triumph
(12788, 142, 37927, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Subjugation
(12788, 141, 35130, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Salvation
(12788, 140, 35129, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Dominance
(12788, 114, 35070, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Shoulders
(12788, 113, 35069, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Legguards
(12788, 112, 35068, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Helm
(12788, 111, 35067, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Gauntlets
(12788, 110, 35066, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Chestpiece
(12788, 47, 35073, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Redoubt
(12788, 46, 34986, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Barrier
(12788, 45, 35074, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Reprieve
(12788, 44, 35016, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Grimoire
(12788, 43, 35008, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Endgame
(12788, 33, 35107, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Touch of Defeat
(12788, 32, 35065, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Piercing Touch
(12788, 31, 35108, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's War Edge
(12788, 30, 34985, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Baton of Light
(12788, 29, 35094, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shield Wall
(12788, 28, 35095, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shiv
(12788, 27, 35058, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Mutilator
(12788, 26, 35093, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shanker
(12788, 25, 35037, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slasher
(12788, 24, 35038, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Fleshslicer
(12788, 23, 35076, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Ripper
(12788, 22, 35072, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Quickblade
(12788, 21, 35101, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slicer
(12788, 20, 34988, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Bonecracker
(12788, 19, 35071, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Pummeler
(12788, 18, 34995, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Chopper
(12788, 17, 35017, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Hacker
(12788, 16, 34996, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Cleaver
(12788, 15, 35102, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Spellblade
(12788, 12, 35082, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Salvation
(12788, 11, 35014, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Gavel
(12788, 10, 35018, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Heavy Crossbow
(12788, 9, 35075, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Rifle
(12788, 8, 35047, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Longbow
(12788, 7, 35103, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Staff
(12788, 6, 34987, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Battle Staff
(12788, 5, 35109, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's War Staff
(12788, 4, 35015, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Greatsword
(12788, 3, 35064, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Painsaw
(12788, 2, 34989, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Bonegrinder
(12788, 1, 34997, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Decapitator
(12795, 446, 18834, 0, 7395, 1, 0, 0, 56713), -- Insignia of the Horde
(12795, 440, 16335, 0, 7395, 1, 0, 0, 56713), -- Senior Sergeant's Insignia
(12795, 439, 18428, 0, 7396, 1, 0, 0, 56713), -- Senior Sergeant's Insignia
(12795, 438, 15200, 0, 838, 1, 0, 0, 56713), -- Senior Sergeant's Insignia
(12795, 425, 16541, 0, 7351, 1, 0, 0, 56713), -- Warlord's Plate Armor
(12795, 424, 16542, 0, 7351, 1, 0, 0, 56713), -- Warlord's Plate Headpiece
(12795, 423, 16544, 0, 7348, 1, 0, 0, 56713), -- Warlord's Plate Shoulders
(12795, 422, 16543, 0, 7351, 1, 0, 0, 56713), -- General's Plate Leggings
(12795, 421, 16545, 0, 7348, 1, 0, 0, 56713), -- General's Plate Boots
(12795, 420, 16548, 0, 7348, 1, 0, 0, 56713), -- General's Plate Gauntlets
(12795, 419, 23244, 0, 7392, 1, 0, 0, 56713), -- Champion's Plate Helm
(12795, 418, 23243, 0, 7393, 1, 0, 0, 56713), -- Champion's Plate Shoulders
(12795, 417, 22872, 0, 7392, 1, 0, 0, 56713), -- Legionnaire's Plate Hauberk
(12795, 416, 22873, 0, 7392, 1, 0, 0, 56713), -- Legionnaire's Plate Leggings
(12795, 415, 22868, 0, 7393, 1, 0, 0, 56713), -- Blood Guard's Plate Gauntlets
(12795, 414, 22858, 0, 7393, 1, 0, 0, 56713), -- Blood Guard's Plate Greaves
(12795, 413, 18429, 0, 7395, 1, 0, 0, 56713), -- First Sergeant's Plate Bracers
(12795, 412, 18430, 0, 7396, 1, 0, 0, 56713), -- First Sergeant's Plate Bracers
(12795, 384, 69862, 0, 821, 1, 0, 0, 56713), -- Medallion of the Horde
(12795, 383, 24551, 0, 7469, 1, 0, 0, 56713), -- Talisman of the Horde
(12795, 381, 37927, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Subjugation
(12795, 380, 35131, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Triumph
(12795, 379, 35130, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Salvation
(12795, 378, 35129, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Dominance
(12795, 377, 44429, 0, 7386, 1, 0, 0, 56713), -- Volanthius Shroud
(12795, 376, 44431, 0, 7386, 1, 0, 0, 56713), -- Cloak of Certain Reprieve
(12795, 375, 41591, 0, 7386, 1, 0, 0, 56713), -- Sergeant's Reinforced Cape
(12795, 374, 41592, 0, 7386, 1, 0, 0, 56713), -- The Gladiator's Resolution
(12795, 373, 35132, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Conquest
(12795, 372, 35133, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Dominance
(12795, 371, 35134, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Salvation
(12795, 370, 35135, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Triumph
(12795, 369, 37928, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Subjugation
(12795, 368, 37929, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Reprieve
(12795, 367, 35176, 0, 7386, 1, 0, 0, 56713), -- Guardian's Plate Bracers
(12795, 366, 35161, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Belt
(12795, 365, 35146, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Greaves
(12795, 364, 35178, 0, 7386, 1, 0, 0, 56713), -- Guardian's Scaled Bracers
(12795, 363, 35163, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Belt
(12795, 362, 35148, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Greaves
(12795, 361, 35175, 0, 7386, 1, 0, 0, 56713), -- Guardian's Ornamented Bracers
(12795, 360, 35160, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Belt
(12795, 359, 35145, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Greaves
(12795, 358, 35170, 0, 7386, 1, 0, 0, 56713), -- Guardian's Lamellar Bracers
(12795, 357, 35155, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Belt
(12795, 356, 35140, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Greaves
(12795, 290, 51364, 0, 7932, 1, 0, 0, 56713), -- Wrathful Gladiator's Bracers of Triumph
(12795, 289, 51361, 0, 7932, 1, 0, 0, 56713), -- Wrathful Gladiator's Bracers of Salvation
(12795, 278, 51362, 0, 7930, 1, 0, 0, 56713), -- Wrathful Gladiator's Girdle of Triumph
(12795, 276, 51359, 0, 7930, 1, 0, 0, 56713), -- Wrathful Gladiator's Girdle of Salvation
(12795, 272, 51378, 0, 7963, 1, 0, 0, 56713), -- Medallion of the Horde
(12795, 270, 51355, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Triumph
(12795, 269, 51353, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Sundering
(12795, 268, 51349, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Deliverance
(12795, 267, 51357, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Victory
(12795, 266, 51347, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Salvation
(12795, 265, 51335, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Ascendancy
(12795, 264, 51333, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Subjugation
(12795, 263, 51331, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Dominance
(12795, 262, 51336, 0, 7935, 1, 0, 0, 56713), -- Wrathful Gladiator's Band of Dominance
(12795, 261, 51358, 0, 7935, 1, 0, 0, 56713), -- Wrathful Gladiator's Band of Triumph
(12795, 257, 51363, 0, 7931, 1, 0, 0, 56713), -- Wrathful Gladiator's Greaves of Triumph
(12795, 254, 51360, 0, 7931, 1, 0, 0, 56713), -- Wrathful Gladiator's Greaves of Salvation
(12795, 249, 51356, 0, 7933, 1, 0, 0, 56713); -- Wrathful Gladiator's Cloak of Victory

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12795, 248, 51354, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Triumph
(12795, 247, 51348, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Deliverance
(12795, 246, 51346, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Salvation
(12795, 245, 51334, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Ascendancy
(12795, 244, 51332, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Subjugation
(12795, 243, 51330, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Dominance
(12795, 218, 51545, 0, 7904, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Shoulders
(12795, 208, 51452, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Barrier
(12795, 207, 51455, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Redoubt
(12795, 206, 51533, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Shield Wall
(12795, 183, 51544, 0, 7898, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Legguards
(12795, 170, 51396, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Endgame
(12795, 169, 51409, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Reprieve
(12795, 168, 51408, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Grimoire
(12795, 167, 51407, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Compendium
(12795, 162, 51543, 0, 7897, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Helm
(12795, 147, 51542, 0, 7896, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Gauntlets
(12795, 134, 51541, 0, 7895, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Chestpiece
(12795, 108, 18461, 0, 7395, 1, 0, 0, 56713), -- Sergeant's Cloak
(12795, 107, 16341, 0, 7396, 1, 0, 0, 56713), -- Sergeant's Cloak
(12795, 106, 18427, 0, 1050, 1, 0, 0, 56713), -- Sergeant's Cloak
(12795, 88, 35070, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Shoulders
(12795, 87, 35094, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shield Wall
(12795, 86, 35073, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Redoubt
(12795, 85, 34986, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Barrier
(12795, 50, 35069, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Legguards
(12795, 49, 35016, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Grimoire
(12795, 48, 35074, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Reprieve
(12795, 47, 35008, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Endgame
(12795, 29, 35068, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Helm
(12795, 11, 35067, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Gauntlets
(12795, 1, 35066, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Chestpiece
(12794, 108, 51409, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Reprieve
(12794, 107, 51408, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Grimoire
(12794, 106, 51407, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Compendium
(12794, 105, 51396, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Endgame
(12794, 104, 51533, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Shield Wall
(12794, 103, 51455, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Redoubt
(12794, 102, 51452, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Barrier
(12794, 101, 51535, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's War Edge
(12794, 100, 51532, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Baton of Light
(12794, 99, 51531, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Piercing Touch
(12794, 98, 51451, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Wand of Alacrity
(12794, 97, 51410, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Touch of Defeat
(12794, 96, 51530, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Slasher
(12794, 95, 51527, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Mutilator
(12794, 94, 51525, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Chopper
(12794, 93, 51523, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Ripper
(12794, 92, 51521, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Slicer
(12794, 91, 51519, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Pummeler
(12794, 90, 51517, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Shanker
(12794, 89, 51515, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Cleaver
(12794, 88, 51480, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Pike
(12794, 87, 51456, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Energy Staff
(12794, 86, 51453, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Gavel
(12794, 85, 51449, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Rifle
(12794, 84, 51447, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Quickblade
(12794, 83, 51445, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Bonecracker
(12794, 82, 51443, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Fleshslicer
(12794, 81, 51441, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Shiv
(12794, 80, 51439, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Hacker
(12794, 78, 51411, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Heavy Crossbow
(12794, 77, 51406, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Blade of Alacrity
(12794, 76, 51404, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Battle Staff
(12794, 75, 51402, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Focus Staff
(12794, 74, 51400, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's War Staff
(12794, 73, 51397, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Spellblade
(12794, 72, 51394, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Longbow
(12794, 71, 51392, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Greatsword
(12794, 70, 51390, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Bonegrinder
(12794, 69, 51388, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Decapitator
(12794, 68, 35094, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shield Wall
(12794, 67, 35073, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Redoubt
(12794, 66, 34986, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Barrier
(12794, 54, 35074, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Reprieve
(12794, 53, 35016, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Grimoire
(12794, 52, 35008, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Endgame
(12794, 51, 35108, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's War Edge
(12794, 50, 34985, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Baton of Light
(12794, 49, 35065, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Piercing Touch
(12794, 48, 35107, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Touch of Defeat
(12794, 47, 35103, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Staff
(12794, 46, 34987, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Battle Staff
(12794, 45, 35109, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's War Staff
(12794, 44, 35102, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Spellblade
(12794, 43, 35082, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Salvation
(12794, 42, 35014, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Gavel
(12794, 41, 35047, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Longbow
(12794, 40, 35075, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Rifle
(12794, 39, 35018, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Heavy Crossbow
(12794, 38, 35058, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Mutilator
(12794, 37, 35095, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shiv
(12794, 36, 35093, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shanker
(12794, 35, 34988, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Bonecracker
(12794, 34, 35071, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Pummeler
(12794, 33, 35017, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Hacker
(12794, 32, 34996, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Cleaver
(12794, 31, 34995, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Chopper
(12794, 30, 35037, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slasher
(12794, 29, 35038, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Fleshslicer
(12794, 28, 35076, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Ripper
(12794, 27, 35072, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Quickblade
(12794, 26, 35101, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slicer
(12794, 25, 35064, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Painsaw
(12794, 24, 34997, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Decapitator
(12794, 23, 34989, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Bonegrinder
(12794, 22, 35015, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Greatsword
(12794, 21, 23469, 0, 7350, 1, 0, 0, 56713), -- High Warlord's Tome of Mending
(12794, 20, 23468, 0, 7350, 1, 0, 0, 56713), -- High Warlord's Tome of Destruction
(12794, 19, 23466, 0, 7345, 1, 0, 0, 56713), -- High Warlord's Spellblade
(12794, 18, 18874, 0, 7344, 1, 0, 0, 56713), -- High Warlord's War Staff
(12794, 17, 18860, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Street Sweeper
(12794, 16, 18837, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Crossbow
(12794, 15, 18835, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Recurve
(12794, 14, 18826, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Shield Wall
(12794, 13, 18840, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Razor
(12794, 12, 18848, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Razor Claw
(12794, 11, 18844, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Right Claw
(12794, 10, 23464, 0, 7345, 1, 0, 0, 56713), -- High Warlord's Battle Mace
(12794, 9, 18866, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Bludgeon
(12794, 8, 23467, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Quickblade
(12794, 7, 16345, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Blade
(12794, 6, 18828, 0, 7347, 1, 0, 0, 56713), -- High Warlord's Cleaver
(12794, 5, 18871, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Pig Sticker
(12794, 4, 23465, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Destroyer
(12794, 3, 18868, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Pulverizer
(12794, 2, 18831, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Battle Axe
(12794, 1, 18877, 0, 7344, 1, 0, 0, 56713), -- High Warlord's Greatsword
(12796, 5, 34129, 0, 423, 1, 0, 0, 56713), -- Swift Warstrider
(12796, 4, 29472, 0, 423, 1, 0, 0, 56713), -- Whistle of the Black War Raptor
(12796, 3, 29470, 0, 423, 1, 0, 0, 56713), -- Red Skeletal Warhorse
(12796, 2, 29469, 0, 423, 1, 0, 0, 56713), -- Horn of the Black War Wolf
(12796, 1, 29466, 0, 423, 1, 0, 0, 56713), -- Black War Kodo
(52034, 9, 1901, 25000, 3408, 2, 0, 0, 56713), -- 1901
(52034, 8, 68813, 0, 9337, 1, 0, 0, 56713), -- Satchel of Freshly-Picked Herbs
(52034, 7, 52185, 0, 9334, 1, 0, 0, 56713), -- Elementium Ore
(52034, 6, 53010, 0, 9322, 1, 0, 0, 56713), -- Embersilk Cloth
(52034, 5, 52976, 0, 9324, 1, 0, 0, 56713), -- Savage Leather
(52034, 4, 52721, 0, 9328, 1, 0, 0, 56713), -- Heavenly Shard
(52034, 3, 52719, 0, 9330, 1, 0, 0, 56713), -- Greater Celestial Essence
(52034, 2, 52555, 0, 9332, 1, 0, 0, 56713), -- Hypnotic Dust
(52034, 1, 52722, 0, 9326, 1, 0, 0, 56713), -- Maelstrom Crystal
(46556, 235, 390, 25000, 3411, 2, 0, 0, 56713), -- 390
(46556, 234, 65273, 0, 3120, 1, 0, 0, 56713), -- Earthen Shoulderguards
(46556, 233, 65272, 0, 3097, 1, 0, 0, 56713), -- Earthen Legguards
(46556, 232, 65271, 0, 3056, 1, 0, 0, 56713), -- Earthen Faceguard
(46556, 231, 65270, 0, 3161, 1, 0, 0, 56713), -- Earthen Handguards
(46556, 230, 65269, 0, 3086, 1, 0, 0, 56713), -- Earthen Chestguard
(46556, 229, 65268, 0, 3048, 1, 0, 0, 56713), -- Earthen Pauldrons
(46556, 228, 65267, 0, 3115, 1, 0, 0, 56713), -- Earthen Legplates
(46556, 227, 65266, 0, 3056, 1, 0, 0, 56713), -- Earthen Helmet
(46556, 226, 65265, 0, 3160, 1, 0, 0, 56713), -- Earthen Gauntlets
(46556, 225, 65264, 0, 3087, 1, 0, 0, 56713), -- Earthen Battleplate
(46556, 114, 60332, 0, 8867, 1, 0, 0, 56713), -- Earthen Handguards
(46556, 113, 60331, 0, 3045, 1, 0, 0, 56713), -- Earthen Shoulderguards
(46556, 112, 60330, 0, 8872, 1, 0, 0, 56713), -- Earthen Legguards
(46556, 111, 60329, 0, 8872, 1, 0, 0, 56713), -- Earthen Chestguard
(46556, 110, 60328, 0, 3051, 1, 0, 0, 56713), -- Earthen Faceguard
(46556, 109, 60327, 0, 3045, 1, 0, 0, 56713), -- Earthen Pauldrons
(46556, 108, 60326, 0, 8867, 1, 0, 0, 56713), -- Earthen Gauntlets
(46556, 107, 60325, 0, 3051, 1, 0, 0, 56713), -- Earthen Helmet
(46556, 106, 60324, 0, 8872, 1, 0, 0, 56713), -- Earthen Legplates
(46556, 105, 60323, 0, 8872, 1, 0, 0, 56713), -- Earthen Battleplate
(46556, 44, 58180, 0, 8867, 1, 0, 0, 56713), -- License to Slay
(46556, 43, 58181, 0, 8867, 1, 0, 0, 56713), -- Fluid Death
(46556, 42, 58182, 0, 8867, 1, 0, 0, 56713), -- Bedrock Talisman
(46556, 41, 58183, 0, 8867, 1, 0, 0, 56713), -- Soul Casket
(46556, 40, 58184, 0, 8867, 1, 0, 0, 56713), -- Core of Ripeness
(46556, 39, 64671, 0, 8865, 1, 0, 0, 56713), -- Relic of Golganneth
(46556, 38, 64672, 0, 8865, 1, 0, 0, 56713), -- Relic of Norgannon
(46556, 37, 64673, 0, 8865, 1, 0, 0, 56713), -- Relic of Eonar
(46556, 36, 64674, 0, 8865, 1, 0, 0, 56713), -- Relic of Aggramar
(46556, 35, 64676, 0, 8865, 1, 0, 0, 56713), -- Relic of Khaz'goroth
(46556, 34, 68812, 0, 8866, 1, 0, 0, 56713), -- Hornet-Sting Band
(46556, 33, 58185, 0, 8866, 1, 0, 0, 56713), -- Band of Bees
(46556, 32, 58187, 0, 8866, 1, 0, 0, 56713), -- Ring of the Battle Anthem
(46556, 31, 58188, 0, 8866, 1, 0, 0, 56713), -- Band of Secret Names
(46556, 30, 58189, 0, 8866, 1, 0, 0, 56713), -- Twined Band of Flowers
(46556, 29, 58195, 0, 8867, 1, 0, 0, 56713), -- Woe Breeder's Boots
(46556, 28, 58197, 0, 8867, 1, 0, 0, 56713), -- Rock Furrow Boots
(46556, 27, 58198, 0, 8867, 1, 0, 0, 56713), -- Eternal Pathfinders
(46556, 26, 58199, 0, 8867, 1, 0, 0, 56713), -- Moccasins of Verdurous Glooms
(46556, 25, 58481, 0, 8867, 1, 0, 0, 56713), -- Boots of the Perilous Seas
(46556, 24, 58482, 0, 8867, 1, 0, 0, 56713), -- Treads of Fleeting Joy
(46556, 23, 58484, 0, 8867, 1, 0, 0, 56713), -- Fading Violet Sandals
(46556, 22, 58485, 0, 8867, 1, 0, 0, 56713), -- Melodious Slippers
(46556, 21, 58486, 0, 8867, 1, 0, 0, 56713), -- Slippers of Moving Waters
(46556, 20, 58191, 0, 8866, 1, 0, 0, 56713), -- Viewless Wings
(46556, 19, 58192, 0, 8866, 1, 0, 0, 56713), -- Gray Hair Cloak
(46556, 18, 58193, 0, 8866, 1, 0, 0, 56713), -- Haunt of Flies
(46556, 17, 58190, 0, 8866, 1, 0, 0, 56713), -- Floating Web
(46556, 16, 58194, 0, 8866, 1, 0, 0, 56713), -- Heavenly Breeze
(46556, 15, 67427, 0, 3329, 1, 0, 0, 56713), -- Leggings of the Forlorn Protector
(46556, 12, 65000, 0, 3329, 1, 0, 0, 56713), -- Crown of the Forlorn Protector
(46556, 9, 67430, 0, 3329, 1, 0, 0, 56713), -- Gauntlets of the Forlorn Protector
(46556, 6, 65087, 0, 3329, 1, 0, 0, 56713), -- Shoulders of the Forlorn Protector
(46556, 3, 67424, 0, 3329, 1, 0, 0, 56713), -- Chest of the Forlorn Protector
(46555, 66, 57919, 0, 3039, 1, 0, 0, 56713), -- Thatch Eave Vines
(46555, 65, 57921, 0, 3039, 1, 0, 0, 56713), -- Incense Infused Cummerbund
(46555, 64, 57916, 0, 3039, 1, 0, 0, 56713), -- Belt of the Dim Forest
(46555, 63, 57915, 0, 3039, 1, 0, 0, 56713), -- Belt of Barred Clouds
(46555, 62, 57913, 0, 3039, 1, 0, 0, 56713), -- Beech Green Belt
(46555, 61, 57914, 0, 3039, 1, 0, 0, 56713), -- Girdle of the Mountains
(46555, 60, 57922, 0, 3039, 1, 0, 0, 56713), -- Belt of the Falling Rain
(46555, 59, 57918, 0, 3039, 1, 0, 0, 56713), -- Sash of Musing
(46555, 58, 57917, 0, 3039, 1, 0, 0, 56713), -- Belt of the Still Stream
(46555, 57, 58157, 0, 3039, 1, 0, 0, 56713), -- Meadow Mantle
(46555, 56, 58151, 0, 3039, 1, 0, 0, 56713), -- Somber Shawl
(46555, 55, 58124, 0, 3039, 1, 0, 0, 56713), -- Wrap of the Valley Glades
(46555, 54, 58109, 0, 3039, 1, 0, 0, 56713), -- Pauldrons of the Forlorn
(46555, 53, 58100, 0, 3039, 1, 0, 0, 56713), -- Pauldrons of the High Requiem
(46555, 52, 58104, 0, 3039, 1, 0, 0, 56713), -- Sunburnt Pauldrons
(46555, 51, 58162, 0, 3039, 1, 0, 0, 56713), -- Summer Song Shoulderwraps
(46555, 50, 58134, 0, 3039, 1, 0, 0, 56713), -- Embrace of the Night
(46555, 49, 58129, 0, 3039, 1, 0, 0, 56713), -- Seafoam Mantle
(46555, 48, 57925, 0, 3041, 1, 0, 0, 56713), -- Shield of the Mists
(46555, 47, 57926, 0, 3041, 1, 0, 0, 56713), -- Shield of the Four Grey Towers
(46555, 46, 58153, 0, 3038, 1, 0, 0, 56713), -- Robes of Embalmed Darkness
(46555, 45, 58139, 0, 3038, 1, 0, 0, 56713), -- Chestguard of Forgetfulness
(46555, 44, 58159, 0, 3038, 1, 0, 0, 56713), -- Musk Rose Robes
(46555, 43, 57927, 0, 3041, 1, 0, 0, 56713), -- Throat Slasher
(46555, 42, 57928, 0, 3041, 1, 0, 0, 56713), -- Windslicer
(46555, 41, 57929, 0, 3041, 1, 0, 0, 56713), -- Dawnblaze Blade
(46555, 40, 57931, 0, 3040, 1, 0, 0, 56713), -- Amulet of Dull Dreaming
(46555, 39, 57933, 0, 3040, 1, 0, 0, 56713), -- String of Beaded Bubbles
(46555, 38, 57934, 0, 3040, 1, 0, 0, 56713), -- Celadon Pendant
(46555, 37, 57930, 0, 3040, 1, 0, 0, 56713), -- Pendant of Quiet Breath
(46555, 36, 57932, 0, 3040, 1, 0, 0, 56713), -- The Lustrous Eye
(46555, 35, 58154, 0, 3038, 1, 0, 0, 56713), -- Pensive Legwraps
(46555, 34, 58140, 0, 3038, 1, 0, 0, 56713), -- Leggings of Late Blooms
(46555, 33, 58122, 0, 3038, 1, 0, 0, 56713), -- Hillside Striders
(46555, 32, 58107, 0, 3038, 1, 0, 0, 56713), -- Legguards of the Gentle
(46555, 31, 58097, 0, 3038, 1, 0, 0, 56713), -- Greaves of Gallantry
(46555, 30, 58102, 0, 3038, 1, 0, 0, 56713), -- Greaves of Splendor
(46555, 29, 58160, 0, 3038, 1, 0, 0, 56713), -- Leggings of Charity
(46555, 28, 58132, 0, 3038, 1, 0, 0, 56713), -- Leggings of the Burrowing Mole
(46555, 27, 58127, 0, 3038, 1, 0, 0, 56713), -- Leggings of Soothing Silence
(46555, 26, 57923, 0, 3041, 1, 0, 0, 56713), -- Hermit's Lamp
(46555, 25, 57924, 0, 3041, 1, 0, 0, 56713), -- Apple-Bent Bough
(46555, 24, 58155, 0, 3038, 1, 0, 0, 56713), -- Cowl of Pleasant Gloom
(46555, 23, 58150, 0, 3038, 1, 0, 0, 56713), -- Cluster of Stars
(46555, 22, 58123, 0, 3038, 1, 0, 0, 56713), -- Willow Mask
(46555, 21, 58108, 0, 3038, 1, 0, 0, 56713), -- Crown of the Blazing Sun
(46555, 20, 58098, 0, 3038, 1, 0, 0, 56713), -- Helm of Easeful Death
(46555, 19, 58103, 0, 3038, 1, 0, 0, 56713), -- Helm of the Proud
(46555, 18, 58161, 0, 3038, 1, 0, 0, 56713), -- Mask of New Snow
(46555, 17, 58133, 0, 3038, 1, 0, 0, 56713), -- Mask of Vines
(46555, 16, 58128, 0, 3038, 1, 0, 0, 56713), -- Helm of the Inward Eye
(46555, 15, 58158, 0, 3039, 1, 0, 0, 56713), -- Gloves of the Painless Midnight
(46555, 14, 58152, 0, 3039, 1, 0, 0, 56713); -- Blessed Hands of Elune

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(46555, 13, 58125, 0, 3039, 1, 0, 0, 56713), -- Gloves of the Passing Night
(46555, 12, 58110, 0, 3039, 1, 0, 0, 56713), -- Gloves of Curious Conscience
(46555, 11, 58099, 0, 3039, 1, 0, 0, 56713), -- Reaping Gauntlets
(46555, 10, 58105, 0, 3039, 1, 0, 0, 56713), -- Numbing Handguards
(46555, 9, 58163, 0, 3039, 1, 0, 0, 56713), -- Gloves of Purification
(46555, 8, 58138, 0, 3039, 1, 0, 0, 56713), -- Sticky Fingers
(46555, 7, 58130, 0, 3039, 1, 0, 0, 56713), -- Gleaning Gloves
(46555, 6, 58121, 0, 3038, 1, 0, 0, 56713), -- Vest of the True Companion
(46555, 5, 58106, 0, 3038, 1, 0, 0, 56713), -- Chestguard of Dancing Waves
(46555, 4, 58096, 0, 3038, 1, 0, 0, 56713), -- Breastplate of Raging Fury
(46555, 3, 58101, 0, 3038, 1, 0, 0, 56713), -- Chestplate of the Steadfast
(46555, 2, 58131, 0, 3038, 1, 0, 0, 56713), -- Tunic of Sinking Envy
(46555, 1, 58126, 0, 3038, 1, 0, 0, 56713); -- Vest of the Waking Dream

UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=56713 WHERE (`entry`=12793 AND `item`=31855 AND `ExtendedCost`=0 AND `type`=1); -- Major Combat Mana Potion
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=56713 WHERE (`entry`=12793 AND `item`=31853 AND `ExtendedCost`=0 AND `type`=1); -- Major Combat Healing Potion
UPDATE `npc_vendor` SET `VerifiedBuild`=56713 WHERE (`entry`=52037 AND `item`=42991 AND `ExtendedCost`=3319 AND `type`=1) OR (`entry`=52037 AND `item`=42992 AND `ExtendedCost`=3319 AND `type`=1) OR (`entry`=52037 AND `item`=69893 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48716 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42945 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48718 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52037 AND `item`=42947 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52037 AND `item`=42948 AND `ExtendedCost`=3319 AND `type`=1) OR (`entry`=52037 AND `item`=42946 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52037 AND `item`=42943 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52037 AND `item`=42944 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48691 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42985 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48689 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42952 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42984 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48687 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48683 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42951 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48677 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42950 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=42949 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=48685 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=69890 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52037 AND `item`=69889 AND `ExtendedCost`=3318 AND `type`=1);
