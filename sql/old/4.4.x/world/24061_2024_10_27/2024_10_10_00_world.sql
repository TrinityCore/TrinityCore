SET @CGUID := 3990005;
SET @ES9ENTRY := 86;
SET @ES11ENTRY := 88;

UPDATE `creature_template` SET `npcflag`=4224, `unit_flags`=768 WHERE `entry`=51256; -- Knight-Lieutenant T'Maire Sydes
UPDATE `creature_template` SET `npcflag`=4224, `unit_flags`=768 WHERE `entry`=51255; -- Lieutenant Tristia
UPDATE `creature_template` SET `npcflag`=4224, `unit_flags`=768 WHERE `entry`=51254; -- Captain Dirgehammer
UPDATE `creature_template` SET `npcflag`=128 WHERE `entry`=52028; -- Talric Forthright

DELETE FROM `creature_template_addon` WHERE `entry` IN (51256, 51255, 51254);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(51256, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 51256 (Knight-Lieutenant T'Maire Sydes)
(51255, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '5301'), -- 51255 (Lieutenant Tristia) - Revenge Trigger
(51254, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '5301'); -- 51254 (Captain Dirgehammer) - Revenge Trigger

UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12783; -- 12783 (Lieutenant Karter)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12785; -- 12785 (Sergeant Major Clate)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12781; -- 12781 (Master Sergeant Biggins)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=12784; -- 12784 (Lieutenant Jackspring)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=44246; -- 44246 (Magatha Silverton)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=44245; -- 44245 (Faldren Tillsdale)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52028; -- 52028 (Talric Forthright)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52030; -- 52030 (Liliana Emberfrost)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52029; -- 52029 (Edlan Halsing)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=52027; -- 52027 (Larisse Pembraux)

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=56713 WHERE (`DifficultyID`=0 AND `Entry` IN (35477,1303,2198,68,18376,3626,1976,1292,14394,5564,2795,1321,43294,1320,23050,14721,5565,37574,43277,37543,44246,44245,332,44249,914,7207,52028,44247,52027,1326,1325,28355,1324,4075,5480,44256,5479,721,28347,4961,6946,1395,11096,44251,7208,13283,51998,52030,52029,8383,43694,43693,1341,1323,1721,918,49540,44252,12805));
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12783 AND `DifficultyID`=0); -- 12783 (Lieutenant Karter) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12785 AND `DifficultyID`=0); -- 12785 (Sergeant Major Clate) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12781 AND `DifficultyID`=0); -- 12781 (Master Sergeant Biggins) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12784 AND `DifficultyID`=0); -- 12784 (Lieutenant Jackspring) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=12778 AND `DifficultyID`=0); -- 12778 (Lieutenant Rachel Vaccar) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=51256 AND `DifficultyID`=0); -- 51256 (Knight-Lieutenant T'Maire Sydes) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=51255 AND `DifficultyID`=0); -- 51255 (Lieutenant Tristia) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=56713 WHERE (`Entry`=51254 AND `DifficultyID`=0); -- 51254 (Captain Dirgehammer) - CanSwim

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
DELETE FROM `creature` WHERE `guid`=314153 AND `id`=58154;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 12778, 0, 1519, 5149, '0', 0, 0, 0, 1, -8777.107421875, 414.270843505859375, 104.0040130615234375, 0.418879032135009765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Lieutenant Rachel Vaccar (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+1, 12805, 0, 1519, 5149, '0', 0, 0, 0, 1, -8759.1962890625, 389.1220703125, 101.1391830444335937, 0.715584993362426757, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Officer Areyn (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+2, 51254, 0, 1519, 5149, '0', 0, 0, 0, 1, -8781.1201171875, 420.380218505859375, 105.31573486328125, 5.98647928237915039, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Captain Dirgehammer (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+3, 51255, 0, 1519, 5149, '0', 0, 0, 0, 1, -8775.9755859375, 424.45660400390625, 105.31573486328125, 4.799655437469482421, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Lieutenant Tristia (Area: Old Town - Difficulty: 0) CreateObject1 (Auras: 5301 - Revenge Trigger)
(@CGUID+4, 51256, 0, 1519, 5149, '0', 0, 0, 0, 1, -8771.236328125, 422.263885498046875, 104.0040054321289062, 4.24114990234375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Knight-Lieutenant T'Maire Sydes (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+5, 52027, 0, 1519, 5149, '0', 0, 0, 0, 0, -8802.31640625, 343.91839599609375, 107.132568359375, 3.106686115264892578, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Larisse Pembraux (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+6, 52028, 0, 1519, 5149, '0', 0, 0, 0, 0, -8814.4970703125, 354.961822509765625, 107.1323928833007812, 4.852015495300292968, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713); -- Talric Forthright (Area: Old Town - Difficulty: 0) CreateObject1

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
DELETE FROM `game_event_creature` WHERE `guid`=314207;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@ES9ENTRY, @CGUID+2), -- Captain Dirgehammer
(@ES9ENTRY, @CGUID+3), -- Lieutenant Tristia
(@ES9ENTRY, @CGUID+4), -- Knight-Lieutenant T'Maire Sydes
(@ES11ENTRY, 314207); -- Lieutenant Tristia

UPDATE `creature` SET `position_x`=-8767.53515625, `position_y`=417.888885498046875, `position_z`=104.0040130615234375, `orientation`=3.804817676544189453, `VerifiedBuild`=56713 WHERE `id`=12781 AND `guid`=314213;
UPDATE `creature` SET `position_x`=-8753.4375, `position_y`=400.25347900390625, `position_z`=101.1394882202148437, `orientation`=5.026548385620117187, `VerifiedBuild`=56713 WHERE `id`=12783 AND `guid`=314211;
UPDATE `creature` SET `position_x`=-8775.482421875, `position_y`=411.322906494140625, `position_z`=104.0039825439453125, `orientation`=0.593411922454833984, `VerifiedBuild`=56713 WHERE `id`=12784 AND `guid`=314202;
UPDATE `creature` SET `position_x`=-8774.0244140625, `position_y`=409.11285400390625, `position_z`=104.0039825439453125, `orientation`=0.78539818525314331, `VerifiedBuild`=56713 WHERE `id`=12785 AND `guid`=314200;
UPDATE `creature` SET `position_x`=-8799.98046875, `position_y`=349.334991455078125, `position_z`=109.2183380126953125, `orientation`=3.682644605636596679, `VerifiedBuild`=56713 WHERE `id`=44245 AND `guid`=251002;
UPDATE `creature` SET `position_x`=-8802.3701171875, `position_y`=352.0360107421875, `position_z`=109.2183380126953125, `orientation`=3.96189737319946289, `VerifiedBuild`=56713 WHERE `id`=44246 AND `guid`=251000;
UPDATE `creature` SET `position_x`=-8788.16015625, `position_y`=425.48785400390625, `position_z`=105.31573486328125, `orientation`=5.934119224548339843, `VerifiedBuild`=56713 WHERE `id`=52029 AND `guid`=314198;
UPDATE `creature` SET `position_x`=-8779.4443359375, `position_y`=432.40972900390625, `position_z`=105.3157196044921875, `orientation`=4.86946868896484375, `VerifiedBuild`=56713 WHERE `id`=52030 AND `guid`=314208;

DELETE FROM `npc_vendor` WHERE (`entry`=12805 AND `item`=18606 AND `ExtendedCost`=7399 AND `type`=1) OR (`entry`=12805 AND `item`=18854 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12805 AND `item`=18443 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12805 AND `item`=18444 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12805 AND `item`=15198 AND `ExtendedCost`=7398 AND `type`=1) OR (`entry`=12805 AND `item`=15196 AND `ExtendedCost`=7397 AND `type`=1) OR (`entry`=51256 AND `item`=68773 AND `ExtendedCost`=1005 AND `type`=1) OR (`entry`=51256 AND `item`=68772 AND `ExtendedCost`=1005 AND `type`=1) OR (`entry`=51256 AND `item`=68774 AND `ExtendedCost`=1005 AND `type`=1) OR (`entry`=51256 AND `item`=68768 AND `ExtendedCost`=2552 AND `type`=1) OR (`entry`=51256 AND `item`=68770 AND `ExtendedCost`=2552 AND `type`=1) OR (`entry`=51256 AND `item`=68769 AND `ExtendedCost`=2552 AND `type`=1) OR (`entry`=51256 AND `item`=64687 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64761 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64740 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64742 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64741 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64790 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64793 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64791 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64688 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64762 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64689 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64763 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64852 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64851 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64714 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64713 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64718 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64719 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64705 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64753 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64754 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64870 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64869 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64684 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64683 AND `ExtendedCost`=3164 AND `type`=1) OR (`entry`=51256 AND `item`=64811 AND `ExtendedCost`=3162 AND `type`=1) OR (`entry`=51256 AND `item`=64812 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=51256 AND `item`=64813 AND `ExtendedCost`=3162 AND `type`=1) OR (`entry`=51256 AND `item`=64814 AND `ExtendedCost`=3162 AND `type`=1) OR (`entry`=51256 AND `item`=64815 AND `ExtendedCost`=3163 AND `type`=1) OR (`entry`=52030 AND `item`=44092 AND `ExtendedCost`=2543 AND `type`=1) OR (`entry`=52030 AND `item`=44096 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44094 AND `ExtendedCost`=2544 AND `type`=1) OR (`entry`=52030 AND `item`=44095 AND `ExtendedCost`=2543 AND `type`=1) OR (`entry`=52030 AND `item`=44091 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44093 AND `ExtendedCost`=2543 AND `type`=1) OR (`entry`=52030 AND `item`=44107 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44103 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44105 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44102 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44101 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44099 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44100 AND `ExtendedCost`=2542 AND `type`=1) OR (`entry`=52030 AND `item`=44098 AND `ExtendedCost`=2544 AND `type`=1) OR (`entry`=51255 AND `item`=67468 AND `ExtendedCost`=3205 AND `type`=1) OR (`entry`=51255 AND `item`=67469 AND `ExtendedCost`=3207 AND `type`=1) OR (`entry`=51255 AND `item`=67470 AND `ExtendedCost`=3201 AND `type`=1) OR (`entry`=51255 AND `item`=67471 AND `ExtendedCost`=9209 AND `type`=1) OR (`entry`=51255 AND `item`=67472 AND `ExtendedCost`=3206 AND `type`=1) OR (`entry`=51255 AND `item`=67473 AND `ExtendedCost`=3203 AND `type`=1) OR (`entry`=51255 AND `item`=67474 AND `ExtendedCost`=3202 AND `type`=1) OR (`entry`=51255 AND `item`=67466 AND `ExtendedCost`=3199 AND `type`=1) OR (`entry`=51255 AND `item`=67467 AND `ExtendedCost`=3200 AND `type`=1) OR (`entry`=51255 AND `item`=67475 AND `ExtendedCost`=3197 AND `type`=1) OR (`entry`=51255 AND `item`=67476 AND `ExtendedCost`=3174 AND `type`=1) OR (`entry`=51255 AND `item`=67477 AND `ExtendedCost`=3198 AND `type`=1) OR (`entry`=51255 AND `item`=67462 AND `ExtendedCost`=3194 AND `type`=1) OR (`entry`=51255 AND `item`=67463 AND `ExtendedCost`=3195 AND `type`=1) OR (`entry`=51255 AND `item`=67464 AND `ExtendedCost`=3193 AND `type`=1) OR (`entry`=51255 AND `item`=67465 AND `ExtendedCost`=3196 AND `type`=1) OR (`entry`=51255 AND `item`=67461 AND `ExtendedCost`=3192 AND `type`=1) OR (`entry`=51255 AND `item`=67458 AND `ExtendedCost`=3189 AND `type`=1) OR (`entry`=51255 AND `item`=67459 AND `ExtendedCost`=3190 AND `type`=1) OR (`entry`=51255 AND `item`=67460 AND `ExtendedCost`=3191 AND `type`=1) OR (`entry`=51255 AND `item`=67454 AND `ExtendedCost`=3185 AND `type`=1) OR (`entry`=51255 AND `item`=67455 AND `ExtendedCost`=3186 AND `type`=1) OR (`entry`=51255 AND `item`=67456 AND `ExtendedCost`=3187 AND `type`=1) OR (`entry`=51255 AND `item`=67457 AND `ExtendedCost`=3188 AND `type`=1) OR (`entry`=51255 AND `item`=67478 AND `ExtendedCost`=3184 AND `type`=1) OR (`entry`=51255 AND `item`=67479 AND `ExtendedCost`=3183 AND `type`=1) OR (`entry`=51255 AND `item`=67447 AND `ExtendedCost`=3180 AND `type`=1) OR (`entry`=51255 AND `item`=67449 AND `ExtendedCost`=3179 AND `type`=1) OR (`entry`=51255 AND `item`=67450 AND `ExtendedCost`=3175 AND `type`=1) OR (`entry`=51255 AND `item`=67451 AND `ExtendedCost`=3181 AND `type`=1) OR (`entry`=51255 AND `item`=67452 AND `ExtendedCost`=3177 AND `type`=1) OR (`entry`=51255 AND `item`=67453 AND `ExtendedCost`=3178 AND `type`=1) OR (`entry`=51255 AND `item`=65580 AND `ExtendedCost`=3224 AND `type`=1) OR (`entry`=51255 AND `item`=65581 AND `ExtendedCost`=3223 AND `type`=1) OR (`entry`=51255 AND `item`=65582 AND `ExtendedCost`=3222 AND `type`=1) OR (`entry`=51255 AND `item`=65583 AND `ExtendedCost`=3221 AND `type`=1) OR (`entry`=51255 AND `item`=65584 AND `ExtendedCost`=3220 AND `type`=1) OR (`entry`=51255 AND `item`=65607 AND `ExtendedCost`=3231 AND `type`=1) OR (`entry`=51255 AND `item`=65608 AND `ExtendedCost`=3230 AND `type`=1) OR (`entry`=51254 AND `item`=61350 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=51254 AND `item`=61351 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=51254 AND `item`=61338 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61329 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61355 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61354 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61353 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61347 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=51254 AND `item`=61359 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61360 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61361 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61357 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61358 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61348 AND `ExtendedCost`=3652 AND `type`=1) OR (`entry`=51254 AND `item`=61325 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61335 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61336 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61327 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61324 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61344 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61345 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61328 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61331 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61332 AND `ExtendedCost`=3417 AND `type`=1) OR (`entry`=51254 AND `item`=61330 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61333 AND `ExtendedCost`=3416 AND `type`=1) OR (`entry`=51254 AND `item`=61346 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61342 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61341 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61340 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61339 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61326 AND `ExtendedCost`=3415 AND `type`=1) OR (`entry`=51254 AND `item`=61047 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61046 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61045 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61035 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61034 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61033 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61032 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61031 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=61026 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60800 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60799 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60794 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60651 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60650 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60673 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60670 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60778 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60776 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60523 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60521 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60513 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60512 AND `ExtendedCost`=3168 AND `type`=1) OR (`entry`=51254 AND `item`=60509 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60508 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60422 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60421 AND `ExtendedCost`=3170 AND `type`=1) OR (`entry`=51254 AND `item`=60420 AND `ExtendedCost`=3170 AND `type`=1) OR (`entry`=51254 AND `item`=60419 AND `ExtendedCost`=3169 AND `type`=1) OR (`entry`=51254 AND `item`=60418 AND `ExtendedCost`=3170 AND `type`=1) OR (`entry`=52029 AND `item`=395 AND `ExtendedCost`=3410 AND `type`=2) OR (`entry`=52029 AND `item`=68813 AND `ExtendedCost`=9336 AND `type`=1) OR (`entry`=52029 AND `item`=52185 AND `ExtendedCost`=9335 AND `type`=1) OR (`entry`=52029 AND `item`=53010 AND `ExtendedCost`=9323 AND `type`=1) OR (`entry`=52029 AND `item`=52976 AND `ExtendedCost`=9325 AND `type`=1) OR (`entry`=52029 AND `item`=52721 AND `ExtendedCost`=9329 AND `type`=1) OR (`entry`=52029 AND `item`=52719 AND `ExtendedCost`=9331 AND `type`=1) OR (`entry`=52029 AND `item`=52555 AND `ExtendedCost`=9333 AND `type`=1) OR (`entry`=52029 AND `item`=52722 AND `ExtendedCost`=9327 AND `type`=1) OR (`entry`=12778 AND `item`=28941 AND `ExtendedCost`=7482 AND `type`=1) OR (`entry`=12778 AND `item`=28940 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28955 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28954 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28947 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28953 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28956 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28952 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28951 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28950 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28946 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28944 AND `ExtendedCost`=7477 AND `type`=1) OR (`entry`=12778 AND `item`=28957 AND `ExtendedCost`=7476 AND `type`=1) OR (`entry`=12778 AND `item`=28960 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=28959 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=28943 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=28949 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=28948 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=28942 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=28945 AND `ExtendedCost`=7475 AND `type`=1) OR (`entry`=12778 AND `item`=30350 AND `ExtendedCost`=7480 AND `type`=1) OR (`entry`=12778 AND `item`=28703 AND `ExtendedCost`=7479 AND `type`=1) OR (`entry`=12778 AND `item`=28702 AND `ExtendedCost`=7478 AND `type`=1) OR (`entry`=12778 AND `item`=28701 AND `ExtendedCost`=7478 AND `type`=1) OR (`entry`=12778 AND `item`=28700 AND `ExtendedCost`=7479 AND `type`=1) OR (`entry`=12778 AND `item`=28699 AND `ExtendedCost`=7478 AND `type`=1) OR (`entry`=12778 AND `item`=28246 AND `ExtendedCost`=7480 AND `type`=1) OR (`entry`=12778 AND `item`=28247 AND `ExtendedCost`=7480 AND `type`=1) OR (`entry`=12778 AND `item`=28999 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=28996 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=32986 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=28984 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=29000 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=28997 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=32987 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=28985 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=28998 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=28995 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=32985 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=28983 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=28377 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=28379 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=28378 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=25829 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=28244 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=28245 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12778 AND `item`=24546 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=24547 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12778 AND `item`=24545 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12778 AND `item`=24549 AND `ExtendedCost`=7470 AND `type`=1) OR (`entry`=12778 AND `item`=24544 AND `ExtendedCost`=7471 AND `type`=1) OR (`entry`=12778 AND `item`=32452 AND `ExtendedCost`=7467 AND `type`=1) OR (`entry`=12778 AND `item`=28346 AND `ExtendedCost`=7467 AND `type`=1) OR (`entry`=12778 AND `item`=28320 AND `ExtendedCost`=7468 AND `type`=1) OR (`entry`=12778 AND `item`=28319 AND `ExtendedCost`=7468 AND `type`=1) OR (`entry`=12778 AND `item`=28358 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28310 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28312 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28314 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28313 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28307 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28295 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28302 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28305 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28309 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28308 AND `ExtendedCost`=7472 AND `type`=1) OR (`entry`=12778 AND `item`=28297 AND `ExtendedCost`=7473 AND `type`=1) OR (`entry`=12778 AND `item`=32451 AND `ExtendedCost`=7473 AND `type`=1) OR (`entry`=12778 AND `item`=32450 AND `ExtendedCost`=7473 AND `type`=1) OR (`entry`=12778 AND `item`=28294 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=24557 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=24550 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=28300 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=28476 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=28299 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=28298 AND `ExtendedCost`=7474 AND `type`=1) OR (`entry`=12778 AND `item`=32819 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=32818 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=32989 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=32813 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=32794 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32793 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32990 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32789 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32806 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32805 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32988 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=32801 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=28380 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33057 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33064 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33056 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33066 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33068 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33065 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=33067 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=30490 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=30489 AND `ExtendedCost`=7461 AND `type`=1) OR (`entry`=12778 AND `item`=30488 AND `ExtendedCost`=7461 AND `type`=1) OR (`entry`=12778 AND `item`=30487 AND `ExtendedCost`=7460 AND `type`=1) OR (`entry`=12778 AND `item`=30486 AND `ExtendedCost`=7461 AND `type`=1) OR (`entry`=12778 AND `item`=33309 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12778 AND `item`=33313 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12778 AND `item`=32961 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12778 AND `item`=31978 AND `ExtendedCost`=7462 AND `type`=1) OR (`entry`=12778 AND `item`=32054 AND `ExtendedCost`=7463 AND `type`=1) OR (`entry`=12778 AND `item`=32962 AND `ExtendedCost`=7463 AND `type`=1) OR (`entry`=12778 AND `item`=32045 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32046 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32044 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32003 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32028 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32027 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32052 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=31958 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32026 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=31985 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=31965 AND `ExtendedCost`=7464 AND `type`=1) OR (`entry`=12778 AND `item`=32053 AND `ExtendedCost`=7465 AND `type`=1) OR (`entry`=12778 AND `item`=32964 AND `ExtendedCost`=7465 AND `type`=1) OR (`entry`=12778 AND `item`=32963 AND `ExtendedCost`=7465 AND `type`=1) OR (`entry`=12778 AND `item`=31986 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=32055 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=31984 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=32025 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=32014 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=31959 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=31966 AND `ExtendedCost`=7466 AND `type`=1) OR (`entry`=12778 AND `item`=33911 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33910 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33909 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33812 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33813 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33811 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33905 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33904 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33903 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33890 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33889 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33888 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33923 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=35319 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33922 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=35317 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33921 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33920 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33919 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=35320 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33918 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33853 AND `ExtendedCost`=7389 AND `type`=1) OR (`entry`=12778 AND `item`=33732 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33731 AND `ExtendedCost`=7454 AND `type`=1) OR (`entry`=12778 AND `item`=33730 AND `ExtendedCost`=7454 AND `type`=1) OR (`entry`=12778 AND `item`=33729 AND `ExtendedCost`=7390 AND `type`=1) OR (`entry`=12778 AND `item`=33728 AND `ExtendedCost`=7454 AND `type`=1) OR (`entry`=12778 AND `item`=33736 AND `ExtendedCost`=7458 AND `type`=1) OR (`entry`=12778 AND `item`=34033 AND `ExtendedCost`=7458 AND `type`=1) OR (`entry`=12778 AND `item`=33681 AND `ExtendedCost`=7458 AND `type`=1) OR (`entry`=12778 AND `item`=33764 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12778 AND `item`=34066 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12778 AND `item`=34059 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12778 AND `item`=33765 AND `ExtendedCost`=7459 AND `type`=1) OR (`entry`=12778 AND `item`=33755 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33801 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33756 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33754 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=34016 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33705 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33737 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33734 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33762 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33662 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33733 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=34015 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33689 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33669 AND `ExtendedCost`=7456 AND `type`=1) OR (`entry`=12778 AND `item`=33735 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12778 AND `item`=33661 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12778 AND `item`=33763 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12778 AND `item`=33743 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12778 AND `item`=33687 AND `ExtendedCost`=7455 AND `type`=1) OR (`entry`=12778 AND `item`=33006 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=34530 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=34529 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=33766 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=33716 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=34540 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=33688 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=33727 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=33663 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=33670 AND `ExtendedCost`=7457 AND `type`=1) OR (`entry`=12778 AND `item`=41588 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=41589 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=41590 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=41587 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=34576 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=35327 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=34580 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=34578 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=34577 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=34579 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=37864 AND `ExtendedCost`=7388 AND `type`=1) OR (`entry`=12778 AND `item`=44429 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=41592 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=41591 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=44431 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35148 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35178 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35163 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35146 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35176 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35161 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35145 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35175 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35160 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35140 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35170 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35155 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35135 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=37928 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35134 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=37929 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35133 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35132 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35131 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=37927 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35130 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35129 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12778 AND `item`=35070 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35069 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12778 AND `item`=35068 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12778 AND `item`=35067 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12778 AND `item`=35066 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12778 AND `item`=35073 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12778 AND `item`=34986 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12778 AND `item`=35074 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12778 AND `item`=35016 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12778 AND `item`=35008 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12778 AND `item`=35107 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12778 AND `item`=35065 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12778 AND `item`=35108 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12778 AND `item`=34985 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12778 AND `item`=35094 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35095 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35058 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35093 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35037 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35038 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35076 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35072 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35101 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=34988 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35071 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=34995 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35017 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=34996 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12778 AND `item`=35102 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12778 AND `item`=35082 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12778 AND `item`=35014 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12778 AND `item`=35018 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=35075 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=35047 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=35103 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=34987 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=35109 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=35015 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=35064 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=34989 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12778 AND `item`=34997 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=51409 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12784 AND `item`=51408 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12784 AND `item`=51407 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12784 AND `item`=51396 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12784 AND `item`=51533 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12784 AND `item`=51455 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12784 AND `item`=51452 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12784 AND `item`=51535 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12784 AND `item`=51532 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12784 AND `item`=51531 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12784 AND `item`=51451 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12784 AND `item`=51410 AND `ExtendedCost`=7902 AND `type`=1) OR (`entry`=12784 AND `item`=51530 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51527 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51525 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51523 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51521 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51519 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51517 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51515 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51480 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51456 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51453 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51449 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51447 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51445 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51443 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51441 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51439 AND `ExtendedCost`=7901 AND `type`=1) OR (`entry`=12784 AND `item`=51411 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51406 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51404 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51402 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51400 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51397 AND `ExtendedCost`=7899 AND `type`=1) OR (`entry`=12784 AND `item`=51394 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51392 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51390 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=51388 AND `ExtendedCost`=7893 AND `type`=1) OR (`entry`=12784 AND `item`=35094 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35073 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12784 AND `item`=34986 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12784 AND `item`=35074 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12784 AND `item`=35016 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12784 AND `item`=35008 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12784 AND `item`=35108 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12784 AND `item`=34985 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12784 AND `item`=35065 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12784 AND `item`=35107 AND `ExtendedCost`=7382 AND `type`=1) OR (`entry`=12784 AND `item`=35103 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=34987 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=35109 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=35102 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12784 AND `item`=35082 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12784 AND `item`=35014 AND `ExtendedCost`=7380 AND `type`=1) OR (`entry`=12784 AND `item`=35047 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=35075 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=35018 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=35058 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35095 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35093 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=34988 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35071 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35017 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=34996 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=34995 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35037 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35038 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35076 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35072 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35101 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12784 AND `item`=35064 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=34997 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=34989 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=35015 AND `ExtendedCost`=7379 AND `type`=1) OR (`entry`=12784 AND `item`=23453 AND `ExtendedCost`=7350 AND `type`=1) OR (`entry`=12784 AND `item`=23452 AND `ExtendedCost`=7350 AND `type`=1) OR (`entry`=12784 AND `item`=23451 AND `ExtendedCost`=7345 AND `type`=1) OR (`entry`=12784 AND `item`=18873 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18855 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18836 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18833 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18825 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=18838 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=18847 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=18843 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=23454 AND `ExtendedCost`=7345 AND `type`=1) OR (`entry`=12784 AND `item`=18865 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=23456 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=12584 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=18827 AND `ExtendedCost`=7347 AND `type`=1) OR (`entry`=12784 AND `item`=18869 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=23455 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18867 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18830 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12784 AND `item`=18876 AND `ExtendedCost`=7344 AND `type`=1) OR (`entry`=12785 AND `item`=18854 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12785 AND `item`=18443 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12785 AND `item`=18444 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12785 AND `item`=18442 AND `ExtendedCost`=838 AND `type`=1) OR (`entry`=12785 AND `item`=16480 AND `ExtendedCost`=7348 AND `type`=1) OR (`entry`=12785 AND `item`=16478 AND `ExtendedCost`=7351 AND `type`=1) OR (`entry`=12785 AND `item`=16479 AND `ExtendedCost`=7351 AND `type`=1) OR (`entry`=12785 AND `item`=16477 AND `ExtendedCost`=7351 AND `type`=1) OR (`entry`=12785 AND `item`=16484 AND `ExtendedCost`=7348 AND `type`=1) OR (`entry`=12785 AND `item`=16483 AND `ExtendedCost`=7348 AND `type`=1) OR (`entry`=12785 AND `item`=23315 AND `ExtendedCost`=7393 AND `type`=1) OR (`entry`=12785 AND `item`=23314 AND `ExtendedCost`=7392 AND `type`=1) OR (`entry`=12785 AND `item`=23301 AND `ExtendedCost`=7392 AND `type`=1) OR (`entry`=12785 AND `item`=23300 AND `ExtendedCost`=7392 AND `type`=1) OR (`entry`=12785 AND `item`=23287 AND `ExtendedCost`=7393 AND `type`=1) OR (`entry`=12785 AND `item`=23286 AND `ExtendedCost`=7393 AND `type`=1) OR (`entry`=12785 AND `item`=18445 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12785 AND `item`=18447 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12785 AND `item`=69861 AND `ExtendedCost`=821 AND `type`=1) OR (`entry`=12785 AND `item`=25829 AND `ExtendedCost`=7469 AND `type`=1) OR (`entry`=12785 AND `item`=37927 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35131 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35130 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35129 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=44429 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=44431 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=41591 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=41592 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35132 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35133 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35134 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35135 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=37928 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=37929 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35176 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35161 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35146 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35178 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35163 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35148 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35175 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35160 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35145 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35170 AND `ExtendedCost`=7386 AND `type`=1) OR (`entry`=12785 AND `item`=35155 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35140 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=51364 AND `ExtendedCost`=7932 AND `type`=1) OR (`entry`=12785 AND `item`=51361 AND `ExtendedCost`=7932 AND `type`=1) OR (`entry`=12785 AND `item`=51362 AND `ExtendedCost`=7930 AND `type`=1) OR (`entry`=12785 AND `item`=51359 AND `ExtendedCost`=7930 AND `type`=1) OR (`entry`=12785 AND `item`=51377 AND `ExtendedCost`=7963 AND `type`=1) OR (`entry`=12785 AND `item`=51355 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51353 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51349 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51357 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51347 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51335 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51333 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51331 AND `ExtendedCost`=7934 AND `type`=1) OR (`entry`=12785 AND `item`=51336 AND `ExtendedCost`=7935 AND `type`=1) OR (`entry`=12785 AND `item`=51358 AND `ExtendedCost`=7935 AND `type`=1) OR (`entry`=12785 AND `item`=51363 AND `ExtendedCost`=7931 AND `type`=1) OR (`entry`=12785 AND `item`=51360 AND `ExtendedCost`=7931 AND `type`=1) OR (`entry`=12785 AND `item`=51356 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51354 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51348 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51346 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51334 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51332 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51330 AND `ExtendedCost`=7933 AND `type`=1) OR (`entry`=12785 AND `item`=51545 AND `ExtendedCost`=7904 AND `type`=1) OR (`entry`=12785 AND `item`=51452 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12785 AND `item`=51455 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12785 AND `item`=51533 AND `ExtendedCost`=7903 AND `type`=1) OR (`entry`=12785 AND `item`=51544 AND `ExtendedCost`=7898 AND `type`=1) OR (`entry`=12785 AND `item`=51396 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12785 AND `item`=51409 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12785 AND `item`=51408 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12785 AND `item`=51407 AND `ExtendedCost`=7900 AND `type`=1) OR (`entry`=12785 AND `item`=51543 AND `ExtendedCost`=7897 AND `type`=1) OR (`entry`=12785 AND `item`=51542 AND `ExtendedCost`=7896 AND `type`=1) OR (`entry`=12785 AND `item`=51541 AND `ExtendedCost`=7895 AND `type`=1) OR (`entry`=12785 AND `item`=35070 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35094 AND `ExtendedCost`=7381 AND `type`=1) OR (`entry`=12785 AND `item`=35073 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12785 AND `item`=34986 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12785 AND `item`=35069 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12785 AND `item`=35016 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12785 AND `item`=35074 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12785 AND `item`=35008 AND `ExtendedCost`=7383 AND `type`=1) OR (`entry`=12785 AND `item`=35068 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12785 AND `item`=35067 AND `ExtendedCost`=7385 AND `type`=1) OR (`entry`=12785 AND `item`=35066 AND `ExtendedCost`=7384 AND `type`=1) OR (`entry`=12785 AND `item`=16342 AND `ExtendedCost`=7395 AND `type`=1) OR (`entry`=12785 AND `item`=18441 AND `ExtendedCost`=7396 AND `type`=1) OR (`entry`=12785 AND `item`=18440 AND `ExtendedCost`=1050 AND `type`=1) OR (`entry`=12781 AND `item`=18606 AND `ExtendedCost`=7399 AND `type`=1) OR (`entry`=12781 AND `item`=15198 AND `ExtendedCost`=7398 AND `type`=1) OR (`entry`=12781 AND `item`=15196 AND `ExtendedCost`=7397 AND `type`=1) OR (`entry`=12781 AND `item`=32453 AND `ExtendedCost`=1564 AND `type`=1) OR (`entry`=12781 AND `item`=32455 AND `ExtendedCost`=460 AND `type`=1) OR (`entry`=12781 AND `item`=18841 AND `ExtendedCost`=460 AND `type`=1) OR (`entry`=12781 AND `item`=18839 AND `ExtendedCost`=460 AND `type`=1) OR (`entry`=12781 AND `item`=44957 AND `ExtendedCost`=2588 AND `type`=1) OR (`entry`=52028 AND `item`=1901 AND `ExtendedCost`=3408 AND `type`=2) OR (`entry`=52028 AND `item`=68813 AND `ExtendedCost`=9337 AND `type`=1) OR (`entry`=52028 AND `item`=52185 AND `ExtendedCost`=9334 AND `type`=1) OR (`entry`=52028 AND `item`=53010 AND `ExtendedCost`=9322 AND `type`=1) OR (`entry`=52028 AND `item`=52976 AND `ExtendedCost`=9324 AND `type`=1) OR (`entry`=52028 AND `item`=52721 AND `ExtendedCost`=9328 AND `type`=1) OR (`entry`=52028 AND `item`=52719 AND `ExtendedCost`=9330 AND `type`=1) OR (`entry`=52028 AND `item`=52555 AND `ExtendedCost`=9332 AND `type`=1) OR (`entry`=52028 AND `item`=52722 AND `ExtendedCost`=9326 AND `type`=1) OR (`entry`=44246 AND `item`=57919 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57921 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57916 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57915 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57913 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57914 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57922 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57918 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57917 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58157 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58151 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58124 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58109 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58100 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58104 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58162 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58134 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58129 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=57925 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=57926 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=58153 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58139 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58159 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=57927 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=57928 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=57929 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=57931 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=44246 AND `item`=57933 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=44246 AND `item`=57934 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=44246 AND `item`=57930 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=44246 AND `item`=57932 AND `ExtendedCost`=3040 AND `type`=1) OR (`entry`=44246 AND `item`=58154 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58140 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58122 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58107 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58097 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58102 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58160 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58132 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58127 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=57923 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=57924 AND `ExtendedCost`=3041 AND `type`=1) OR (`entry`=44246 AND `item`=58155 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58150 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58123 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58108 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58098 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58103 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58161 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58133 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58128 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58158 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58152 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58125 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58110 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58099 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58105 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58163 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58138 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58130 AND `ExtendedCost`=3039 AND `type`=1) OR (`entry`=44246 AND `item`=58121 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58106 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58096 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58101 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58131 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44246 AND `item`=58126 AND `ExtendedCost`=3038 AND `type`=1) OR (`entry`=44245 AND `item`=390 AND `ExtendedCost`=3411 AND `type`=2) OR (`entry`=44245 AND `item`=65273 AND `ExtendedCost`=3120 AND `type`=1) OR (`entry`=44245 AND `item`=65272 AND `ExtendedCost`=3097 AND `type`=1) OR (`entry`=44245 AND `item`=65271 AND `ExtendedCost`=3056 AND `type`=1) OR (`entry`=44245 AND `item`=65270 AND `ExtendedCost`=3161 AND `type`=1) OR (`entry`=44245 AND `item`=65269 AND `ExtendedCost`=3086 AND `type`=1) OR (`entry`=44245 AND `item`=65268 AND `ExtendedCost`=3048 AND `type`=1) OR (`entry`=44245 AND `item`=65267 AND `ExtendedCost`=3115 AND `type`=1) OR (`entry`=44245 AND `item`=65266 AND `ExtendedCost`=3056 AND `type`=1) OR (`entry`=44245 AND `item`=65265 AND `ExtendedCost`=3160 AND `type`=1) OR (`entry`=44245 AND `item`=65264 AND `ExtendedCost`=3087 AND `type`=1) OR (`entry`=44245 AND `item`=60332 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=60331 AND `ExtendedCost`=3045 AND `type`=1) OR (`entry`=44245 AND `item`=60330 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=44245 AND `item`=60329 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=44245 AND `item`=60328 AND `ExtendedCost`=3051 AND `type`=1) OR (`entry`=44245 AND `item`=60327 AND `ExtendedCost`=3045 AND `type`=1) OR (`entry`=44245 AND `item`=60326 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=60325 AND `ExtendedCost`=3051 AND `type`=1) OR (`entry`=44245 AND `item`=60324 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=44245 AND `item`=60323 AND `ExtendedCost`=8872 AND `type`=1) OR (`entry`=44245 AND `item`=58180 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58181 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58182 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58183 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58184 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=64671 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=44245 AND `item`=64672 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=44245 AND `item`=64673 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=44245 AND `item`=64674 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=44245 AND `item`=64676 AND `ExtendedCost`=8865 AND `type`=1) OR (`entry`=44245 AND `item`=68812 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58185 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58187 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58188 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58189 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58195 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58197 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58198 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58199 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58481 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58482 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58484 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58485 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58486 AND `ExtendedCost`=8867 AND `type`=1) OR (`entry`=44245 AND `item`=58191 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58192 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58193 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58190 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=58194 AND `ExtendedCost`=8866 AND `type`=1) OR (`entry`=44245 AND `item`=67427 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=44245 AND `item`=65000 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=44245 AND `item`=67430 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=44245 AND `item`=65087 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=44245 AND `item`=67424 AND `ExtendedCost`=3329 AND `type`=1) OR (`entry`=12783 AND `item`=35906 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12783 AND `item`=29471 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12783 AND `item`=29468 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12783 AND `item`=29467 AND `ExtendedCost`=423 AND `type`=1) OR (`entry`=12783 AND `item`=29465 AND `ExtendedCost`=423 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12805, 15, 18606, 0, 7399, 1, 0, 0, 56713), -- Alliance Battle Standard
(12805, 7, 18854, 0, 7395, 1, 0, 0, 56713), -- Insignia of the Alliance
(12805, 5, 18443, 0, 7395, 1, 0, 0, 56713), -- Master Sergeant's Insignia
(12805, 4, 18444, 0, 7396, 1, 0, 0, 56713), -- Master Sergeant's Insignia
(12805, 2, 15198, 0, 7398, 1, 0, 0, 56713), -- Knight's Colors
(12805, 1, 15196, 0, 7397, 1, 0, 0, 56713), -- Private's Tabard
(51256, 171, 68773, 0, 1005, 1, 0, 0, 56713), -- Greater Inscription of Vicious Strength
(51256, 170, 68772, 0, 1005, 1, 0, 0, 56713), -- Greater Inscription of Vicious Intellect
(51256, 169, 68774, 0, 1005, 1, 0, 0, 56713), -- Greater Inscription of Vicious Agility
(51256, 168, 68768, 0, 2552, 1, 0, 0, 56713), -- Arcanum of Vicious Strength
(51256, 167, 68770, 0, 2552, 1, 0, 0, 56713), -- Arcanum of Vicious Intellect
(51256, 166, 68769, 0, 2552, 1, 0, 0, 56713), -- Arcanum of Vicious Agility
(51256, 161, 64687, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Badge of Conquest
(51256, 160, 64761, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Insignia of Conquest
(51256, 159, 64740, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Emblem of Cruelty
(51256, 158, 64742, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Emblem of Tenacity
(51256, 157, 64741, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Emblem of Meditation
(51256, 156, 64790, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Medallion of Cruelty
(51256, 153, 64793, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Medallion of Tenacity
(51256, 151, 64791, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Medallion of Meditation
(51256, 150, 64688, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Badge of Dominance
(51256, 149, 64762, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Insignia of Dominance
(51256, 148, 64689, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Badge of Victory
(51256, 147, 64763, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Insignia of Victory
(51256, 141, 64852, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Signet of Cruelty
(51256, 140, 64851, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Signet of Accuracy
(51256, 134, 64714, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Choker of Proficiency
(51256, 133, 64713, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Choker of Accuracy
(51256, 127, 64718, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Cloak of Alacrity
(51256, 126, 64719, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Cloak of Prowess
(51256, 18, 64705, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Bracers of Prowess
(51256, 11, 64753, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Girdle of Cruelty
(51256, 10, 64754, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Girdle of Prowess
(51256, 9, 64870, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Warboots of Cruelty
(51256, 8, 64869, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Warboots of Alacrity
(51256, 7, 64684, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Armplates of Proficiency
(51256, 6, 64683, 0, 3164, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Armplates of Alacrity
(51256, 5, 64811, 0, 3162, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Chestpiece
(51256, 4, 64812, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Gauntlets
(51256, 3, 64813, 0, 3162, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Helm
(51256, 2, 64814, 0, 3162, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Legguards
(51256, 1, 64815, 0, 3163, 1, 0, 0, 56713), -- Bloodthirsty Gladiator's Plate Shoulders
(52030, 15, 44092, 0, 2543, 1, 0, 0, 56713), -- Reforged Truesilver Champion
(52030, 14, 44096, 0, 2542, 1, 0, 0, 56713), -- Battleworn Thrash Blade
(52030, 13, 44094, 0, 2544, 1, 0, 0, 56713), -- The Blessed Hammer of Grace
(52030, 12, 44095, 0, 2543, 1, 0, 0, 56713), -- Grand Staff of Jordan
(52030, 11, 44091, 0, 2542, 1, 0, 0, 56713), -- Sharpened Scarlet Kris
(52030, 10, 44093, 0, 2543, 1, 0, 0, 56713), -- Upgraded Dwarven Hand Cannon
(52030, 9, 44107, 0, 2542, 1, 0, 0, 56713), -- Exquisite Sunderseer Mantle
(52030, 8, 44103, 0, 2542, 1, 0, 0, 56713), -- Exceptional Stormshroud Shoulders
(52030, 7, 44105, 0, 2542, 1, 0, 0, 56713), -- Lasting Feralheart Spaulders
(52030, 6, 44102, 0, 2542, 1, 0, 0, 56713), -- Aged Pauldrons of The Five Thunders
(52030, 5, 44101, 0, 2542, 1, 0, 0, 56713), -- Prized Beastmaster's Mantle
(52030, 4, 44099, 0, 2542, 1, 0, 0, 56713), -- Strengthened Stockade Pauldrons
(52030, 3, 44100, 0, 2542, 1, 0, 0, 56713), -- Pristine Lightforge Spaulders
(52030, 1, 44098, 0, 2544, 1, 0, 0, 56713), -- Inherited Insignia of the Alliance
(51255, 128, 67468, 0, 3205, 1, 0, 0, 56713), -- Vicious Gladiator's Quickblade
(51255, 127, 67469, 0, 3207, 1, 0, 0, 56713), -- Vicious Gladiator's Slicer
(51255, 126, 67470, 0, 3201, 1, 0, 0, 56713), -- Vicious Gladiator's Bonecracker
(51255, 125, 67471, 0, 9209, 1, 0, 0, 56713), -- Vicious Gladiator's Pummeler
(51255, 124, 67472, 0, 3206, 1, 0, 0, 56713), -- Vicious Gladiator's Shanker
(51255, 123, 67473, 0, 3203, 1, 0, 0, 56713), -- Vicious Gladiator's Hacker
(51255, 122, 67474, 0, 3202, 1, 0, 0, 56713), -- Vicious Gladiator's Cleaver
(51255, 121, 67466, 0, 3199, 1, 0, 0, 56713), -- Vicious Gladiator's Hatchet
(51255, 120, 67467, 0, 3200, 1, 0, 0, 56713), -- Vicious Gladiator's War Edge
(51255, 119, 67475, 0, 3197, 1, 0, 0, 56713), -- Vicious Gladiator's Redoubt
(51255, 118, 67476, 0, 3174, 1, 0, 0, 56713), -- Vicious Gladiator's Barrier
(51255, 117, 67477, 0, 3198, 1, 0, 0, 56713), -- Vicious Gladiator's Shield Wall
(51255, 116, 67462, 0, 3194, 1, 0, 0, 56713), -- Vicious Gladiator's Heavy Crossbow
(51255, 115, 67463, 0, 3195, 1, 0, 0, 56713), -- Vicious Gladiator's Rifle
(51255, 114, 67464, 0, 3193, 1, 0, 0, 56713), -- Vicious Gladiator's Baton of Light
(51255, 113, 67465, 0, 3196, 1, 0, 0, 56713), -- Vicious Gladiator's Touch of Defeat
(51255, 112, 67461, 0, 3192, 1, 0, 0, 56713), -- Vicious Gladiator's Longbow
(51255, 111, 67458, 0, 3189, 1, 0, 0, 56713), -- Vicious Gladiator's Slasher
(51255, 110, 67459, 0, 3190, 1, 0, 0, 56713), -- Vicious Gladiator's Fleshslicer
(51255, 109, 67460, 0, 3191, 1, 0, 0, 56713), -- Vicious Gladiator's Shiv
(51255, 108, 67454, 0, 3185, 1, 0, 0, 56713), -- Vicious Gladiator's Gavel
(51255, 107, 67455, 0, 3186, 1, 0, 0, 56713), -- Vicious Gladiator's Right Render
(51255, 106, 67456, 0, 3187, 1, 0, 0, 56713), -- Vicious Gladiator's Ripper
(51255, 105, 67457, 0, 3188, 1, 0, 0, 56713), -- Vicious Gladiator's Spellblade
(51255, 104, 67478, 0, 3184, 1, 0, 0, 56713), -- Vicious Gladiator's Reprieve
(51255, 103, 67479, 0, 3183, 1, 0, 0, 56713), -- Vicious Gladiator's Endgame
(51255, 102, 67447, 0, 3180, 1, 0, 0, 56713), -- Vicious Gladiator's Greatsword
(51255, 100, 67449, 0, 3179, 1, 0, 0, 56713), -- Vicious Gladiator's Energy Staff
(51255, 99, 67450, 0, 3175, 1, 0, 0, 56713), -- Vicious Gladiator's Battle Staff
(51255, 98, 67451, 0, 3181, 1, 0, 0, 56713), -- Vicious Gladiator's Pike
(51255, 97, 67452, 0, 3177, 1, 0, 0, 56713), -- Vicious Gladiator's Bonegrinder
(51255, 96, 67453, 0, 3178, 1, 0, 0, 56713), -- Vicious Gladiator's Decapitator
(51255, 19, 65580, 0, 3224, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Shoulders
(51255, 18, 65581, 0, 3223, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Legguards
(51255, 17, 65582, 0, 3222, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Helm
(51255, 16, 65583, 0, 3221, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Gauntlets
(51255, 15, 65584, 0, 3220, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Chestpiece
(51255, 2, 65607, 0, 3231, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Cruelty
(51255, 1, 65608, 0, 3230, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Alacrity
(51254, 198, 61350, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's Touch of Defeat
(51254, 197, 61351, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's Baton of Light
(51254, 196, 61338, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Gavel
(51254, 195, 61329, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Spellblade
(51254, 194, 61355, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Heavy Crossbow
(51254, 193, 61354, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Rifle
(51254, 192, 61353, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Longbow
(51254, 191, 61347, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's War Edge
(51254, 190, 61359, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Shield Wall
(51254, 189, 61360, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Barrier
(51254, 188, 61361, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Redoubt
(51254, 187, 61357, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Endgame
(51254, 186, 61358, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Reprieve
(51254, 185, 61348, 0, 3652, 1, 0, 0, 56713), -- Vicious Gladiator's Hatchet
(51254, 184, 61325, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Hacker
(51254, 183, 61335, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Pummeler
(51254, 182, 61336, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Bonecracker
(51254, 181, 61327, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Shanker
(51254, 180, 61324, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Cleaver
(51254, 179, 61344, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Slicer
(51254, 178, 61345, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Quickblade
(51254, 177, 61328, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Shiv
(51254, 176, 61331, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Fleshslicer
(51254, 175, 61332, 0, 3417, 1, 0, 0, 56713), -- Vicious Gladiator's Slasher
(51254, 174, 61330, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Ripper
(51254, 173, 61333, 0, 3416, 1, 0, 0, 56713), -- Vicious Gladiator's Right Render
(51254, 172, 61346, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Greatsword
(51254, 170, 61342, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Energy Staff
(51254, 169, 61341, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Battle Staff
(51254, 168, 61340, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Pike
(51254, 167, 61339, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Bonegrinder
(51254, 166, 61326, 0, 3415, 1, 0, 0, 56713), -- Vicious Gladiator's Decapitator
(51254, 161, 61047, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Insignia of Conquest
(51254, 160, 61046, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Insignia of Victory
(51254, 159, 61045, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Insignia of Dominance
(51254, 158, 61035, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Badge of Dominance
(51254, 157, 61034, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Badge of Victory
(51254, 156, 61033, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Badge of Conquest
(51254, 155, 61032, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Emblem of Tenacity
(51254, 154, 61031, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Emblem of Meditation
(51254, 153, 61026, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Emblem of Cruelty
(51254, 149, 60800, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Medallion of Tenacity
(51254, 148, 60799, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Medallion of Meditation
(51254, 147, 60794, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Medallion of Cruelty
(51254, 144, 60651, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Signet of Accuracy
(51254, 143, 60650, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Signet of Cruelty
(51254, 139, 60673, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Choker of Accuracy
(51254, 138, 60670, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Choker of Proficiency
(51254, 127, 60778, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Cloak of Prowess
(51254, 126, 60776, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Cloak of Alacrity
(51254, 24, 60523, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Armplates of Proficiency
(51254, 23, 60521, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Girdle of Prowess
(51254, 20, 60513, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Alacrity
(51254, 19, 60512, 0, 3168, 1, 0, 0, 56713), -- Vicious Gladiator's Armplates of Alacrity
(51254, 18, 60509, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Warboots of Cruelty
(51254, 17, 60508, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Girdle of Cruelty
(51254, 15, 60422, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Shoulders
(51254, 14, 60421, 0, 3170, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Legguards
(51254, 13, 60420, 0, 3170, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Helm
(51254, 12, 60419, 0, 3169, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Gauntlets
(51254, 11, 60418, 0, 3170, 1, 0, 0, 56713), -- Vicious Gladiator's Plate Chestpiece
(52029, 9, 395, 25000, 3410, 2, 0, 0, 56713), -- 395
(52029, 8, 68813, 0, 9336, 1, 0, 0, 56713), -- Satchel of Freshly-Picked Herbs
(52029, 7, 52185, 0, 9335, 1, 0, 0, 56713), -- Elementium Ore
(52029, 6, 53010, 0, 9323, 1, 0, 0, 56713), -- Embersilk Cloth
(52029, 5, 52976, 0, 9325, 1, 0, 0, 56713), -- Savage Leather
(52029, 4, 52721, 0, 9329, 1, 0, 0, 56713), -- Heavenly Shard
(52029, 3, 52719, 0, 9331, 1, 0, 0, 56713), -- Greater Celestial Essence
(52029, 2, 52555, 0, 9333, 1, 0, 0, 56713), -- Hypnotic Dust
(52029, 1, 52722, 0, 9327, 1, 0, 0, 56713), -- Maelstrom Crystal
(12778, 1008, 28941, 0, 7482, 1, 0, 0, 56713), -- Grand Marshal's Battletome
(12778, 1005, 28940, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Barricade
(12778, 1002, 28955, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Shiv
(12778, 1001, 28954, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Shanker
(12778, 999, 28947, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Fleshslicer
(12778, 997, 28953, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Ripper
(12778, 994, 28956, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Slicer
(12778, 993, 28952, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Quickblade
(12778, 990, 28951, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Pummeler
(12778, 989, 28950, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Bonecracker
(12778, 986, 28946, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Hacker
(12778, 985, 28944, 0, 7477, 1, 0, 0, 56713), -- Grand Marshal's Cleaver
(12778, 983, 28957, 0, 7476, 1, 0, 0, 56713), -- Grand Marshal's Spellblade
(12778, 981, 28960, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's Heavy Crossbow
(12778, 979, 28959, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's War Staff
(12778, 977, 28943, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's Warblade
(12778, 975, 28949, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's Painsaw
(12778, 972, 28948, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's Maul
(12778, 971, 28942, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's Bonegrinder
(12778, 969, 28945, 0, 7475, 1, 0, 0, 56713), -- Grand Marshal's Decapitator
(12778, 955, 30350, 0, 7480, 1, 0, 0, 56713), -- Medallion of the Alliance
(12778, 843, 28703, 0, 7479, 1, 0, 0, 56713), -- Grand Marshal's Plate Shoulders
(12778, 842, 28702, 0, 7478, 1, 0, 0, 56713), -- Grand Marshal's Plate Legguards
(12778, 841, 28701, 0, 7478, 1, 0, 0, 56713), -- Grand Marshal's Plate Helm
(12778, 840, 28700, 0, 7479, 1, 0, 0, 56713), -- Grand Marshal's Plate Gauntlets
(12778, 839, 28699, 0, 7478, 1, 0, 0, 56713), -- Grand Marshal's Plate Chestpiece
(12778, 788, 28246, 0, 7480, 1, 0, 0, 56713), -- Band of Triumph
(12778, 787, 28247, 0, 7480, 1, 0, 0, 56713), -- Band of Dominance
(12778, 786, 28999, 0, 7469, 1, 0, 0, 56713), -- Marshal's Scaled Bracers
(12778, 785, 28996, 0, 7469, 1, 0, 0, 56713), -- Marshal's Plate Bracers
(12778, 784, 32986, 0, 7469, 1, 0, 0, 56713), -- Marshal's Ornamented Bracers
(12778, 783, 28984, 0, 7469, 1, 0, 0, 56713), -- Marshal's Lamellar Bracers
(12778, 778, 29000, 0, 7470, 1, 0, 0, 56713), -- Marshal's Scaled Greaves
(12778, 777, 28997, 0, 7470, 1, 0, 0, 56713), -- Marshal's Plate Greaves
(12778, 776, 32987, 0, 7470, 1, 0, 0, 56713), -- Marshal's Ornamented Greaves
(12778, 775, 28985, 0, 7470, 1, 0, 0, 56713), -- Marshal's Lamellar Greaves
(12778, 770, 28998, 0, 7470, 1, 0, 0, 56713), -- Marshal's Scaled Belt
(12778, 769, 28995, 0, 7470, 1, 0, 0, 56713), -- Marshal's Plate Belt
(12778, 768, 32985, 0, 7470, 1, 0, 0, 56713), -- Marshal's Ornamented Belt
(12778, 767, 28983, 0, 7470, 1, 0, 0, 56713), -- Marshal's Lamellar Belt
(12778, 714, 28377, 0, 7469, 1, 0, 0, 56713), -- Sergeant's Heavy Cloak
(12778, 713, 28379, 0, 7469, 1, 0, 0, 56713), -- Sergeant's Heavy Cape
(12778, 712, 28378, 0, 7469, 1, 0, 0, 56713), -- Sergeant's Heavy Cape
(12778, 692, 25829, 0, 7469, 1, 0, 0, 56713), -- Talisman of the Alliance
(12778, 691, 28244, 0, 7469, 1, 0, 0, 56713), -- Pendant of Triumph
(12778, 690, 28245, 0, 7469, 1, 0, 0, 56713), -- Pendant of Dominance
(12778, 664, 24546, 0, 7470, 1, 0, 0, 56713), -- Gladiator's Plate Shoulders
(12778, 663, 24547, 0, 7471, 1, 0, 0, 56713), -- Gladiator's Plate Legguards
(12778, 662, 24545, 0, 7471, 1, 0, 0, 56713), -- Gladiator's Plate Helm
(12778, 661, 24549, 0, 7470, 1, 0, 0, 56713), -- Gladiator's Plate Gauntlets
(12778, 660, 24544, 0, 7471, 1, 0, 0, 56713), -- Gladiator's Plate Chestpiece
(12778, 604, 32452, 0, 7467, 1, 0, 0, 56713), -- Gladiator's Reprieve
(12778, 603, 28346, 0, 7467, 1, 0, 0, 56713), -- Gladiator's Endgame
(12778, 593, 28320, 0, 7468, 1, 0, 0, 56713), -- Gladiator's Touch of Defeat
(12778, 592, 28319, 0, 7468, 1, 0, 0, 56713), -- Gladiator's War Edge
(12778, 591, 28358, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Shield Wall
(12778, 590, 28310, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Shiv
(12778, 589, 28312, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Shanker
(12778, 588, 28314, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Fleshslicer
(12778, 587, 28313, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Ripper
(12778, 586, 28307, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Quickblade
(12778, 585, 28295, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Slicer
(12778, 584, 28302, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Bonecracker
(12778, 583, 28305, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Pummeler
(12778, 582, 28309, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Hacker
(12778, 581, 28308, 0, 7472, 1, 0, 0, 56713), -- Gladiator's Cleaver
(12778, 580, 28297, 0, 7473, 1, 0, 0, 56713), -- Gladiator's Spellblade
(12778, 579, 32451, 0, 7473, 1, 0, 0, 56713), -- Gladiator's Salvation
(12778, 578, 32450, 0, 7473, 1, 0, 0, 56713), -- Gladiator's Gavel
(12778, 577, 28294, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Heavy Crossbow
(12778, 576, 24557, 0, 7474, 1, 0, 0, 56713), -- Gladiator's War Staff
(12778, 575, 24550, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Greatsword
(12778, 574, 28300, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Painsaw
(12778, 573, 28476, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Maul
(12778, 572, 28299, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Bonegrinder
(12778, 571, 28298, 0, 7474, 1, 0, 0, 56713), -- Gladiator's Decapitator
(12778, 570, 32819, 0, 7388, 1, 0, 0, 56713), -- Veteran's Scaled Bracers
(12778, 569, 32818, 0, 7388, 1, 0, 0, 56713), -- Veteran's Plate Bracers
(12778, 568, 32989, 0, 7388, 1, 0, 0, 56713), -- Veteran's Ornamented Bracers
(12778, 567, 32813, 0, 7388, 1, 0, 0, 56713), -- Veteran's Lamellar Bracers
(12778, 566, 32794, 0, 7460, 1, 0, 0, 56713), -- Veteran's Scaled Greaves
(12778, 565, 32793, 0, 7460, 1, 0, 0, 56713), -- Veteran's Plate Greaves
(12778, 564, 32990, 0, 7460, 1, 0, 0, 56713), -- Veteran's Ornamented Greaves
(12778, 563, 32789, 0, 7460, 1, 0, 0, 56713), -- Veteran's Lamellar Greaves
(12778, 562, 32806, 0, 7460, 1, 0, 0, 56713); -- Veteran's Scaled Belt

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12778, 561, 32805, 0, 7460, 1, 0, 0, 56713), -- Veteran's Plate Belt
(12778, 560, 32988, 0, 7460, 1, 0, 0, 56713), -- Veteran's Ornamented Belt
(12778, 559, 32801, 0, 7460, 1, 0, 0, 56713), -- Veteran's Lamellar Belt
(12778, 534, 28380, 0, 7388, 1, 0, 0, 56713), -- Sergeant's Heavy Cloak
(12778, 524, 33057, 0, 7388, 1, 0, 0, 56713), -- Veteran's Band of Triumph
(12778, 523, 33064, 0, 7388, 1, 0, 0, 56713), -- Veteran's Band of Salvation
(12778, 522, 33056, 0, 7388, 1, 0, 0, 56713), -- Veteran's Band of Dominance
(12778, 521, 33066, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Triumph
(12778, 520, 33068, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Salvation
(12778, 519, 33065, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Dominance
(12778, 518, 33067, 0, 7388, 1, 0, 0, 56713), -- Veteran's Pendant of Conquest
(12778, 492, 30490, 0, 7460, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Shoulders
(12778, 491, 30489, 0, 7461, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Legguards
(12778, 490, 30488, 0, 7461, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Helm
(12778, 489, 30487, 0, 7460, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Gauntlets
(12778, 488, 30486, 0, 7461, 1, 0, 0, 56713), -- Merciless Gladiator's Plate Chestpiece
(12778, 432, 33309, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Redoubt
(12778, 431, 33313, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Barrier
(12778, 430, 32961, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Reprieve
(12778, 429, 31978, 0, 7462, 1, 0, 0, 56713), -- Merciless Gladiator's Endgame
(12778, 419, 32054, 0, 7463, 1, 0, 0, 56713), -- Merciless Gladiator's War Edge
(12778, 418, 32962, 0, 7463, 1, 0, 0, 56713), -- Merciless Gladiator's Touch of Defeat
(12778, 417, 32045, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Shield Wall
(12778, 416, 32046, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Shiv
(12778, 415, 32044, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Shanker
(12778, 414, 32003, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Fleshslicer
(12778, 413, 32028, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Ripper
(12778, 412, 32027, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Quickblade
(12778, 411, 32052, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Slicer
(12778, 410, 31958, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Bonecracker
(12778, 409, 32026, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Pummeler
(12778, 408, 31985, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Hacker
(12778, 407, 31965, 0, 7464, 1, 0, 0, 56713), -- Merciless Gladiator's Cleaver
(12778, 406, 32053, 0, 7465, 1, 0, 0, 56713), -- Merciless Gladiator's Spellblade
(12778, 405, 32964, 0, 7465, 1, 0, 0, 56713), -- Merciless Gladiator's Salvation
(12778, 404, 32963, 0, 7465, 1, 0, 0, 56713), -- Merciless Gladiator's Gavel
(12778, 403, 31986, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Crossbow of the Phoenix
(12778, 402, 32055, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's War Staff
(12778, 401, 31984, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Greatsword
(12778, 400, 32025, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Painsaw
(12778, 399, 32014, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Maul
(12778, 398, 31959, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Bonegrinder
(12778, 397, 31966, 0, 7466, 1, 0, 0, 56713), -- Merciless Gladiator's Decapitator
(12778, 396, 33911, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Scaled Greaves
(12778, 395, 33910, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Scaled Bracers
(12778, 394, 33909, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Scaled Belt
(12778, 393, 33812, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Plate Greaves
(12778, 392, 33813, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Plate Bracers
(12778, 391, 33811, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Plate Belt
(12778, 390, 33905, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Ornamented Greaves
(12778, 389, 33904, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Ornamented Bracers
(12778, 388, 33903, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Ornamented Belt
(12778, 387, 33890, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Lamellar Greaves
(12778, 386, 33889, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Lamellar Bracers
(12778, 385, 33888, 0, 7390, 1, 0, 0, 56713), -- Vindicator's Lamellar Belt
(12778, 351, 33923, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Triumph
(12778, 350, 35319, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Subjugation
(12778, 349, 33922, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Salvation
(12778, 348, 35317, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Reprieve
(12778, 347, 33921, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Dominance
(12778, 346, 33920, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Pendant of Conquest
(12778, 345, 33919, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Triumph
(12778, 344, 35320, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Subjugation
(12778, 343, 33918, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Salvation
(12778, 342, 33853, 0, 7389, 1, 0, 0, 56713), -- Vindicator's Band of Dominance
(12778, 316, 33732, 0, 7390, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Shoulders
(12778, 315, 33731, 0, 7454, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Legguards
(12778, 314, 33730, 0, 7454, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Helm
(12778, 313, 33729, 0, 7390, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Gauntlets
(12778, 312, 33728, 0, 7454, 1, 0, 0, 56713), -- Vengeful Gladiator's Plate Chestpiece
(12778, 256, 33736, 0, 7458, 1, 0, 0, 56713), -- Vengeful Gladiator's Reprieve
(12778, 255, 34033, 0, 7458, 1, 0, 0, 56713), -- Vengeful Gladiator's Grimoire
(12778, 254, 33681, 0, 7458, 1, 0, 0, 56713), -- Vengeful Gladiator's Endgame
(12778, 244, 33764, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's Touch of Defeat
(12778, 243, 34066, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's Piercing Touch
(12778, 242, 34059, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's Baton of Light
(12778, 241, 33765, 0, 7459, 1, 0, 0, 56713), -- Vengeful Gladiator's War Edge
(12778, 239, 33755, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Shield Wall
(12778, 238, 33801, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Mutilator
(12778, 237, 33756, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Shiv
(12778, 236, 33754, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Shanker
(12778, 235, 34016, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Slasher
(12778, 234, 33705, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Fleshslicer
(12778, 233, 33737, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Ripper
(12778, 232, 33734, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Quickblade
(12778, 231, 33762, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Slicer
(12778, 230, 33662, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Bonecracker
(12778, 229, 33733, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Pummeler
(12778, 228, 34015, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Chopper
(12778, 227, 33689, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Hacker
(12778, 226, 33669, 0, 7456, 1, 0, 0, 56713), -- Vengeful Gladiator's Cleaver
(12778, 225, 33735, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Redoubt
(12778, 224, 33661, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Barrier
(12778, 223, 33763, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Spellblade
(12778, 222, 33743, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Salvation
(12778, 221, 33687, 0, 7455, 1, 0, 0, 56713), -- Vengeful Gladiator's Gavel
(12778, 220, 33006, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Heavy Crossbow
(12778, 219, 34530, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Rifle
(12778, 218, 34529, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Longbow
(12778, 217, 33766, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's War Staff
(12778, 216, 33716, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Staff
(12778, 215, 34540, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Battle Staff
(12778, 214, 33688, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Greatsword
(12778, 213, 33727, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Painsaw
(12778, 212, 33663, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Bonegrinder
(12778, 211, 33670, 0, 7457, 1, 0, 0, 56713), -- Vengeful Gladiator's Decapitator
(12778, 210, 41588, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Aggression
(12778, 209, 41589, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Resolve
(12778, 208, 41590, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Courage
(12778, 207, 41587, 0, 7386, 1, 0, 0, 56713), -- Battlemaster's Celerity
(12778, 206, 34576, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Cruelty
(12778, 205, 35327, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Alacrity
(12778, 204, 34580, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Perseverance
(12778, 203, 34578, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Determination
(12778, 202, 34577, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Depravity
(12778, 201, 34579, 0, 7388, 1, 0, 0, 56713), -- Battlemaster's Audacity
(12778, 199, 37864, 0, 7388, 1, 0, 0, 56713), -- Medallion of the Alliance
(12778, 198, 44429, 0, 7386, 1, 0, 0, 56713), -- Volanthius Shroud
(12778, 197, 41592, 0, 7386, 1, 0, 0, 56713), -- The Gladiator's Resolution
(12778, 196, 41591, 0, 7386, 1, 0, 0, 56713), -- Sergeant's Reinforced Cape
(12778, 195, 44431, 0, 7386, 1, 0, 0, 56713), -- Cloak of Certain Reprieve
(12778, 194, 35148, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Greaves
(12778, 193, 35178, 0, 7386, 1, 0, 0, 56713), -- Guardian's Scaled Bracers
(12778, 192, 35163, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Belt
(12778, 191, 35146, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Greaves
(12778, 190, 35176, 0, 7386, 1, 0, 0, 56713), -- Guardian's Plate Bracers
(12778, 189, 35161, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Belt
(12778, 188, 35145, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Greaves
(12778, 187, 35175, 0, 7386, 1, 0, 0, 56713), -- Guardian's Ornamented Bracers
(12778, 186, 35160, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Belt
(12778, 185, 35140, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Greaves
(12778, 184, 35170, 0, 7386, 1, 0, 0, 56713), -- Guardian's Lamellar Bracers
(12778, 183, 35155, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Belt
(12778, 149, 35135, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Triumph
(12778, 148, 37928, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Subjugation
(12778, 147, 35134, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Salvation
(12778, 146, 37929, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Reprieve
(12778, 145, 35133, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Dominance
(12778, 144, 35132, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Conquest
(12778, 143, 35131, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Triumph
(12778, 142, 37927, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Subjugation
(12778, 141, 35130, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Salvation
(12778, 140, 35129, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Dominance
(12778, 114, 35070, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Shoulders
(12778, 113, 35069, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Legguards
(12778, 112, 35068, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Helm
(12778, 111, 35067, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Gauntlets
(12778, 110, 35066, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Chestpiece
(12778, 47, 35073, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Redoubt
(12778, 46, 34986, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Barrier
(12778, 45, 35074, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Reprieve
(12778, 44, 35016, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Grimoire
(12778, 43, 35008, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Endgame
(12778, 33, 35107, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Touch of Defeat
(12778, 32, 35065, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Piercing Touch
(12778, 31, 35108, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's War Edge
(12778, 30, 34985, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Baton of Light
(12778, 29, 35094, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shield Wall
(12778, 28, 35095, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shiv
(12778, 27, 35058, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Mutilator
(12778, 26, 35093, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shanker
(12778, 25, 35037, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slasher
(12778, 24, 35038, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Fleshslicer
(12778, 23, 35076, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Ripper
(12778, 22, 35072, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Quickblade
(12778, 21, 35101, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slicer
(12778, 20, 34988, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Bonecracker
(12778, 19, 35071, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Pummeler
(12778, 18, 34995, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Chopper
(12778, 17, 35017, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Hacker
(12778, 16, 34996, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Cleaver
(12778, 15, 35102, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Spellblade
(12778, 12, 35082, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Salvation
(12778, 11, 35014, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Gavel
(12778, 10, 35018, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Heavy Crossbow
(12778, 9, 35075, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Rifle
(12778, 8, 35047, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Longbow
(12778, 7, 35103, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Staff
(12778, 6, 34987, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Battle Staff
(12778, 5, 35109, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's War Staff
(12778, 4, 35015, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Greatsword
(12778, 3, 35064, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Painsaw
(12778, 2, 34989, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Bonegrinder
(12778, 1, 34997, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Decapitator
(12784, 108, 51409, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Reprieve
(12784, 107, 51408, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Grimoire
(12784, 106, 51407, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Compendium
(12784, 105, 51396, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Endgame
(12784, 104, 51533, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Shield Wall
(12784, 103, 51455, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Redoubt
(12784, 102, 51452, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Barrier
(12784, 101, 51535, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's War Edge
(12784, 100, 51532, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Baton of Light
(12784, 99, 51531, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Piercing Touch
(12784, 98, 51451, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Wand of Alacrity
(12784, 97, 51410, 0, 7902, 1, 0, 0, 56713), -- Wrathful Gladiator's Touch of Defeat
(12784, 96, 51530, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Slasher
(12784, 95, 51527, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Mutilator
(12784, 94, 51525, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Chopper
(12784, 93, 51523, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Ripper
(12784, 92, 51521, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Slicer
(12784, 91, 51519, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Pummeler
(12784, 90, 51517, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Shanker
(12784, 89, 51515, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Cleaver
(12784, 88, 51480, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Pike
(12784, 87, 51456, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Energy Staff
(12784, 86, 51453, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Gavel
(12784, 85, 51449, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Rifle
(12784, 84, 51447, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Quickblade
(12784, 83, 51445, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Bonecracker
(12784, 82, 51443, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Fleshslicer
(12784, 81, 51441, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Shiv
(12784, 80, 51439, 0, 7901, 1, 0, 0, 56713), -- Wrathful Gladiator's Hacker
(12784, 78, 51411, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Heavy Crossbow
(12784, 77, 51406, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Blade of Alacrity
(12784, 76, 51404, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Battle Staff
(12784, 75, 51402, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Focus Staff
(12784, 74, 51400, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's War Staff
(12784, 73, 51397, 0, 7899, 1, 0, 0, 56713), -- Wrathful Gladiator's Spellblade
(12784, 72, 51394, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Longbow
(12784, 71, 51392, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Greatsword
(12784, 70, 51390, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Bonegrinder
(12784, 69, 51388, 0, 7893, 1, 0, 0, 56713), -- Wrathful Gladiator's Decapitator
(12784, 68, 35094, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shield Wall
(12784, 67, 35073, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Redoubt
(12784, 66, 34986, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Barrier
(12784, 54, 35074, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Reprieve
(12784, 53, 35016, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Grimoire
(12784, 52, 35008, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Endgame
(12784, 51, 35108, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's War Edge
(12784, 50, 34985, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Baton of Light
(12784, 49, 35065, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Piercing Touch
(12784, 48, 35107, 0, 7382, 1, 0, 0, 56713), -- Brutal Gladiator's Touch of Defeat
(12784, 47, 35103, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Staff
(12784, 46, 34987, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Battle Staff
(12784, 45, 35109, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's War Staff
(12784, 44, 35102, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Spellblade
(12784, 43, 35082, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Salvation
(12784, 42, 35014, 0, 7380, 1, 0, 0, 56713), -- Brutal Gladiator's Gavel
(12784, 41, 35047, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Longbow
(12784, 40, 35075, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Rifle
(12784, 39, 35018, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Heavy Crossbow
(12784, 38, 35058, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Mutilator
(12784, 37, 35095, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shiv
(12784, 36, 35093, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shanker
(12784, 35, 34988, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Bonecracker
(12784, 34, 35071, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Pummeler
(12784, 33, 35017, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Hacker
(12784, 32, 34996, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Cleaver
(12784, 31, 34995, 0, 7381, 1, 0, 0, 56713); -- Brutal Gladiator's Chopper

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(12784, 30, 35037, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slasher
(12784, 29, 35038, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Fleshslicer
(12784, 28, 35076, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Ripper
(12784, 27, 35072, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Quickblade
(12784, 26, 35101, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Slicer
(12784, 25, 35064, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Painsaw
(12784, 24, 34997, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Decapitator
(12784, 23, 34989, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Bonegrinder
(12784, 22, 35015, 0, 7379, 1, 0, 0, 56713), -- Brutal Gladiator's Greatsword
(12784, 21, 23453, 0, 7350, 1, 0, 0, 56713), -- Grand Marshal's Tome of Restoration
(12784, 20, 23452, 0, 7350, 1, 0, 0, 56713), -- Grand Marshal's Tome of Power
(12784, 19, 23451, 0, 7345, 1, 0, 0, 56713), -- Grand Marshal's Mageblade
(12784, 18, 18873, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Stave
(12784, 17, 18855, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Hand Cannon
(12784, 16, 18836, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Repeater
(12784, 15, 18833, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Bullseye
(12784, 14, 18825, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Aegis
(12784, 13, 18838, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Dirk
(12784, 12, 18847, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Razor Hand Blade
(12784, 11, 18843, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Right Hand Blade
(12784, 10, 23454, 0, 7345, 1, 0, 0, 56713), -- Grand Marshal's Warhammer
(12784, 9, 18865, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Punisher
(12784, 8, 23456, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Swiftblade
(12784, 7, 12584, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Longsword
(12784, 6, 18827, 0, 7347, 1, 0, 0, 56713), -- Grand Marshal's Handaxe
(12784, 5, 18869, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Glaive
(12784, 4, 23455, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Demolisher
(12784, 3, 18867, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Battle Hammer
(12784, 2, 18830, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Sunderer
(12784, 1, 18876, 0, 7344, 1, 0, 0, 56713), -- Grand Marshal's Claymore
(12785, 442, 18854, 0, 7395, 1, 0, 0, 56713), -- Insignia of the Alliance
(12785, 440, 18443, 0, 7395, 1, 0, 0, 56713), -- Master Sergeant's Insignia
(12785, 439, 18444, 0, 7396, 1, 0, 0, 56713), -- Master Sergeant's Insignia
(12785, 438, 18442, 0, 838, 1, 0, 0, 56713), -- Master Sergeant's Insignia
(12785, 433, 16480, 0, 7348, 1, 0, 0, 56713), -- Field Marshal's Plate Shoulderguards
(12785, 432, 16478, 0, 7351, 1, 0, 0, 56713), -- Field Marshal's Plate Helm
(12785, 431, 16479, 0, 7351, 1, 0, 0, 56713), -- Marshal's Plate Legguards
(12785, 430, 16477, 0, 7351, 1, 0, 0, 56713), -- Field Marshal's Plate Armor
(12785, 427, 16484, 0, 7348, 1, 0, 0, 56713), -- Marshal's Plate Gauntlets
(12785, 426, 16483, 0, 7348, 1, 0, 0, 56713), -- Marshal's Plate Boots
(12785, 425, 23315, 0, 7393, 1, 0, 0, 56713), -- Lieutenant Commander's Plate Shoulders
(12785, 424, 23314, 0, 7392, 1, 0, 0, 56713), -- Lieutenant Commander's Plate Helmet
(12785, 421, 23301, 0, 7392, 1, 0, 0, 56713), -- Knight-Captain's Plate Leggings
(12785, 420, 23300, 0, 7392, 1, 0, 0, 56713), -- Knight-Captain's Plate Hauberk
(12785, 417, 23287, 0, 7393, 1, 0, 0, 56713), -- Knight-Lieutenant's Plate Greaves
(12785, 416, 23286, 0, 7393, 1, 0, 0, 56713), -- Knight-Lieutenant's Plate Gauntlets
(12785, 413, 18445, 0, 7395, 1, 0, 0, 56713), -- Sergeant Major's Plate Wristguards
(12785, 412, 18447, 0, 7396, 1, 0, 0, 56713), -- Sergeant Major's Plate Wristguards
(12785, 411, 69861, 0, 821, 1, 0, 0, 56713), -- Medallion of the Alliance
(12785, 408, 25829, 0, 7469, 1, 0, 0, 56713), -- Talisman of the Alliance
(12785, 407, 37927, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Subjugation
(12785, 406, 35131, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Triumph
(12785, 405, 35130, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Salvation
(12785, 404, 35129, 0, 7386, 1, 0, 0, 56713), -- Guardian's Band of Dominance
(12785, 403, 44429, 0, 7386, 1, 0, 0, 56713), -- Volanthius Shroud
(12785, 402, 44431, 0, 7386, 1, 0, 0, 56713), -- Cloak of Certain Reprieve
(12785, 401, 41591, 0, 7386, 1, 0, 0, 56713), -- Sergeant's Reinforced Cape
(12785, 400, 41592, 0, 7386, 1, 0, 0, 56713), -- The Gladiator's Resolution
(12785, 399, 35132, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Conquest
(12785, 398, 35133, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Dominance
(12785, 397, 35134, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Salvation
(12785, 396, 35135, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Triumph
(12785, 395, 37928, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Subjugation
(12785, 394, 37929, 0, 7386, 1, 0, 0, 56713), -- Guardian's Pendant of Reprieve
(12785, 393, 35176, 0, 7386, 1, 0, 0, 56713), -- Guardian's Plate Bracers
(12785, 392, 35161, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Belt
(12785, 391, 35146, 0, 7385, 1, 0, 0, 56713), -- Guardian's Plate Greaves
(12785, 390, 35178, 0, 7386, 1, 0, 0, 56713), -- Guardian's Scaled Bracers
(12785, 389, 35163, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Belt
(12785, 388, 35148, 0, 7385, 1, 0, 0, 56713), -- Guardian's Scaled Greaves
(12785, 387, 35175, 0, 7386, 1, 0, 0, 56713), -- Guardian's Ornamented Bracers
(12785, 386, 35160, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Belt
(12785, 385, 35145, 0, 7385, 1, 0, 0, 56713), -- Guardian's Ornamented Greaves
(12785, 384, 35170, 0, 7386, 1, 0, 0, 56713), -- Guardian's Lamellar Bracers
(12785, 383, 35155, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Belt
(12785, 382, 35140, 0, 7385, 1, 0, 0, 56713), -- Guardian's Lamellar Greaves
(12785, 318, 51364, 0, 7932, 1, 0, 0, 56713), -- Wrathful Gladiator's Bracers of Triumph
(12785, 317, 51361, 0, 7932, 1, 0, 0, 56713), -- Wrathful Gladiator's Bracers of Salvation
(12785, 306, 51362, 0, 7930, 1, 0, 0, 56713), -- Wrathful Gladiator's Girdle of Triumph
(12785, 304, 51359, 0, 7930, 1, 0, 0, 56713), -- Wrathful Gladiator's Girdle of Salvation
(12785, 299, 51377, 0, 7963, 1, 0, 0, 56713), -- Medallion of the Alliance
(12785, 298, 51355, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Triumph
(12785, 297, 51353, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Sundering
(12785, 296, 51349, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Deliverance
(12785, 295, 51357, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Victory
(12785, 294, 51347, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Salvation
(12785, 293, 51335, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Ascendancy
(12785, 292, 51333, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Subjugation
(12785, 291, 51331, 0, 7934, 1, 0, 0, 56713), -- Wrathful Gladiator's Pendant of Dominance
(12785, 290, 51336, 0, 7935, 1, 0, 0, 56713), -- Wrathful Gladiator's Band of Dominance
(12785, 289, 51358, 0, 7935, 1, 0, 0, 56713), -- Wrathful Gladiator's Band of Triumph
(12785, 285, 51363, 0, 7931, 1, 0, 0, 56713), -- Wrathful Gladiator's Greaves of Triumph
(12785, 282, 51360, 0, 7931, 1, 0, 0, 56713), -- Wrathful Gladiator's Greaves of Salvation
(12785, 277, 51356, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Victory
(12785, 276, 51354, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Triumph
(12785, 275, 51348, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Deliverance
(12785, 274, 51346, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Salvation
(12785, 273, 51334, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Ascendancy
(12785, 272, 51332, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Subjugation
(12785, 271, 51330, 0, 7933, 1, 0, 0, 56713), -- Wrathful Gladiator's Cloak of Dominance
(12785, 236, 51545, 0, 7904, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Shoulders
(12785, 226, 51452, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Barrier
(12785, 225, 51455, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Redoubt
(12785, 224, 51533, 0, 7903, 1, 0, 0, 56713), -- Wrathful Gladiator's Shield Wall
(12785, 201, 51544, 0, 7898, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Legguards
(12785, 188, 51396, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Endgame
(12785, 187, 51409, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Reprieve
(12785, 186, 51408, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Grimoire
(12785, 185, 51407, 0, 7900, 1, 0, 0, 56713), -- Wrathful Gladiator's Compendium
(12785, 180, 51543, 0, 7897, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Helm
(12785, 165, 51542, 0, 7896, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Gauntlets
(12785, 152, 51541, 0, 7895, 1, 0, 0, 56713), -- Wrathful Gladiator's Plate Chestpiece
(12785, 111, 35070, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Shoulders
(12785, 110, 35094, 0, 7381, 1, 0, 0, 56713), -- Brutal Gladiator's Shield Wall
(12785, 109, 35073, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Redoubt
(12785, 108, 34986, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Barrier
(12785, 73, 35069, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Legguards
(12785, 72, 35016, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Grimoire
(12785, 71, 35074, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Reprieve
(12785, 70, 35008, 0, 7383, 1, 0, 0, 56713), -- Brutal Gladiator's Endgame
(12785, 52, 35068, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Helm
(12785, 34, 35067, 0, 7385, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Gauntlets
(12785, 24, 35066, 0, 7384, 1, 0, 0, 56713), -- Brutal Gladiator's Plate Chestpiece
(12785, 3, 16342, 0, 7395, 1, 0, 0, 56713), -- Sergeant's Cape
(12785, 2, 18441, 0, 7396, 1, 0, 0, 56713), -- Sergeant's Cape
(12785, 1, 18440, 0, 1050, 1, 0, 0, 56713), -- Sergeant's Cape
(12781, 10, 18606, 0, 7399, 1, 0, 0, 56713), -- Alliance Battle Standard
(12781, 9, 15198, 0, 7398, 1, 0, 0, 56713), -- Knight's Colors
(12781, 8, 15196, 0, 7397, 1, 0, 0, 56713), -- Private's Tabard
(12781, 7, 32453, 0, 1564, 1, 0, 0, 56713), -- Star's Tears
(12781, 6, 32455, 0, 460, 1, 0, 0, 56713), -- Star's Lament
(12781, 3, 18841, 0, 460, 1, 0, 0, 56713), -- Combat Mana Potion
(12781, 2, 18839, 0, 460, 1, 0, 0, 56713), -- Combat Healing Potion
(12781, 1, 44957, 0, 2588, 1, 0, 0, 56713), -- Greater Inscription of the Gladiator
(52028, 9, 1901, 25000, 3408, 2, 0, 0, 56713), -- 1901
(52028, 8, 68813, 0, 9337, 1, 0, 0, 56713), -- Satchel of Freshly-Picked Herbs
(52028, 7, 52185, 0, 9334, 1, 0, 0, 56713), -- Elementium Ore
(52028, 6, 53010, 0, 9322, 1, 0, 0, 56713), -- Embersilk Cloth
(52028, 5, 52976, 0, 9324, 1, 0, 0, 56713), -- Savage Leather
(52028, 4, 52721, 0, 9328, 1, 0, 0, 56713), -- Heavenly Shard
(52028, 3, 52719, 0, 9330, 1, 0, 0, 56713), -- Greater Celestial Essence
(52028, 2, 52555, 0, 9332, 1, 0, 0, 56713), -- Hypnotic Dust
(52028, 1, 52722, 0, 9326, 1, 0, 0, 56713), -- Maelstrom Crystal
(44246, 66, 57919, 0, 3039, 1, 0, 0, 56713), -- Thatch Eave Vines
(44246, 65, 57921, 0, 3039, 1, 0, 0, 56713), -- Incense Infused Cummerbund
(44246, 64, 57916, 0, 3039, 1, 0, 0, 56713), -- Belt of the Dim Forest
(44246, 63, 57915, 0, 3039, 1, 0, 0, 56713), -- Belt of Barred Clouds
(44246, 62, 57913, 0, 3039, 1, 0, 0, 56713), -- Beech Green Belt
(44246, 61, 57914, 0, 3039, 1, 0, 0, 56713), -- Girdle of the Mountains
(44246, 60, 57922, 0, 3039, 1, 0, 0, 56713), -- Belt of the Falling Rain
(44246, 59, 57918, 0, 3039, 1, 0, 0, 56713), -- Sash of Musing
(44246, 58, 57917, 0, 3039, 1, 0, 0, 56713), -- Belt of the Still Stream
(44246, 57, 58157, 0, 3039, 1, 0, 0, 56713), -- Meadow Mantle
(44246, 56, 58151, 0, 3039, 1, 0, 0, 56713), -- Somber Shawl
(44246, 55, 58124, 0, 3039, 1, 0, 0, 56713), -- Wrap of the Valley Glades
(44246, 54, 58109, 0, 3039, 1, 0, 0, 56713), -- Pauldrons of the Forlorn
(44246, 53, 58100, 0, 3039, 1, 0, 0, 56713), -- Pauldrons of the High Requiem
(44246, 52, 58104, 0, 3039, 1, 0, 0, 56713), -- Sunburnt Pauldrons
(44246, 51, 58162, 0, 3039, 1, 0, 0, 56713), -- Summer Song Shoulderwraps
(44246, 50, 58134, 0, 3039, 1, 0, 0, 56713), -- Embrace of the Night
(44246, 49, 58129, 0, 3039, 1, 0, 0, 56713), -- Seafoam Mantle
(44246, 48, 57925, 0, 3041, 1, 0, 0, 56713), -- Shield of the Mists
(44246, 47, 57926, 0, 3041, 1, 0, 0, 56713), -- Shield of the Four Grey Towers
(44246, 46, 58153, 0, 3038, 1, 0, 0, 56713), -- Robes of Embalmed Darkness
(44246, 45, 58139, 0, 3038, 1, 0, 0, 56713), -- Chestguard of Forgetfulness
(44246, 44, 58159, 0, 3038, 1, 0, 0, 56713), -- Musk Rose Robes
(44246, 43, 57927, 0, 3041, 1, 0, 0, 56713), -- Throat Slasher
(44246, 42, 57928, 0, 3041, 1, 0, 0, 56713), -- Windslicer
(44246, 41, 57929, 0, 3041, 1, 0, 0, 56713), -- Dawnblaze Blade
(44246, 40, 57931, 0, 3040, 1, 0, 0, 56713), -- Amulet of Dull Dreaming
(44246, 39, 57933, 0, 3040, 1, 0, 0, 56713), -- String of Beaded Bubbles
(44246, 38, 57934, 0, 3040, 1, 0, 0, 56713), -- Celadon Pendant
(44246, 37, 57930, 0, 3040, 1, 0, 0, 56713), -- Pendant of Quiet Breath
(44246, 36, 57932, 0, 3040, 1, 0, 0, 56713), -- The Lustrous Eye
(44246, 35, 58154, 0, 3038, 1, 0, 0, 56713), -- Pensive Legwraps
(44246, 34, 58140, 0, 3038, 1, 0, 0, 56713), -- Leggings of Late Blooms
(44246, 33, 58122, 0, 3038, 1, 0, 0, 56713), -- Hillside Striders
(44246, 32, 58107, 0, 3038, 1, 0, 0, 56713), -- Legguards of the Gentle
(44246, 31, 58097, 0, 3038, 1, 0, 0, 56713), -- Greaves of Gallantry
(44246, 30, 58102, 0, 3038, 1, 0, 0, 56713), -- Greaves of Splendor
(44246, 29, 58160, 0, 3038, 1, 0, 0, 56713), -- Leggings of Charity
(44246, 28, 58132, 0, 3038, 1, 0, 0, 56713), -- Leggings of the Burrowing Mole
(44246, 27, 58127, 0, 3038, 1, 0, 0, 56713), -- Leggings of Soothing Silence
(44246, 26, 57923, 0, 3041, 1, 0, 0, 56713), -- Hermit's Lamp
(44246, 25, 57924, 0, 3041, 1, 0, 0, 56713), -- Apple-Bent Bough
(44246, 24, 58155, 0, 3038, 1, 0, 0, 56713), -- Cowl of Pleasant Gloom
(44246, 23, 58150, 0, 3038, 1, 0, 0, 56713), -- Cluster of Stars
(44246, 22, 58123, 0, 3038, 1, 0, 0, 56713), -- Willow Mask
(44246, 21, 58108, 0, 3038, 1, 0, 0, 56713), -- Crown of the Blazing Sun
(44246, 20, 58098, 0, 3038, 1, 0, 0, 56713), -- Helm of Easeful Death
(44246, 19, 58103, 0, 3038, 1, 0, 0, 56713), -- Helm of the Proud
(44246, 18, 58161, 0, 3038, 1, 0, 0, 56713), -- Mask of New Snow
(44246, 17, 58133, 0, 3038, 1, 0, 0, 56713), -- Mask of Vines
(44246, 16, 58128, 0, 3038, 1, 0, 0, 56713), -- Helm of the Inward Eye
(44246, 15, 58158, 0, 3039, 1, 0, 0, 56713), -- Gloves of the Painless Midnight
(44246, 14, 58152, 0, 3039, 1, 0, 0, 56713), -- Blessed Hands of Elune
(44246, 13, 58125, 0, 3039, 1, 0, 0, 56713), -- Gloves of the Passing Night
(44246, 12, 58110, 0, 3039, 1, 0, 0, 56713), -- Gloves of Curious Conscience
(44246, 11, 58099, 0, 3039, 1, 0, 0, 56713), -- Reaping Gauntlets
(44246, 10, 58105, 0, 3039, 1, 0, 0, 56713), -- Numbing Handguards
(44246, 9, 58163, 0, 3039, 1, 0, 0, 56713), -- Gloves of Purification
(44246, 8, 58138, 0, 3039, 1, 0, 0, 56713), -- Sticky Fingers
(44246, 7, 58130, 0, 3039, 1, 0, 0, 56713), -- Gleaning Gloves
(44246, 6, 58121, 0, 3038, 1, 0, 0, 56713), -- Vest of the True Companion
(44246, 5, 58106, 0, 3038, 1, 0, 0, 56713), -- Chestguard of Dancing Waves
(44246, 4, 58096, 0, 3038, 1, 0, 0, 56713), -- Breastplate of Raging Fury
(44246, 3, 58101, 0, 3038, 1, 0, 0, 56713), -- Chestplate of the Steadfast
(44246, 2, 58131, 0, 3038, 1, 0, 0, 56713), -- Tunic of Sinking Envy
(44246, 1, 58126, 0, 3038, 1, 0, 0, 56713), -- Vest of the Waking Dream
(44245, 235, 390, 25000, 3411, 2, 0, 0, 56713), -- 390
(44245, 234, 65273, 0, 3120, 1, 0, 0, 56713), -- Earthen Shoulderguards
(44245, 233, 65272, 0, 3097, 1, 0, 0, 56713), -- Earthen Legguards
(44245, 232, 65271, 0, 3056, 1, 0, 0, 56713), -- Earthen Faceguard
(44245, 231, 65270, 0, 3161, 1, 0, 0, 56713), -- Earthen Handguards
(44245, 230, 65269, 0, 3086, 1, 0, 0, 56713), -- Earthen Chestguard
(44245, 229, 65268, 0, 3048, 1, 0, 0, 56713), -- Earthen Pauldrons
(44245, 228, 65267, 0, 3115, 1, 0, 0, 56713), -- Earthen Legplates
(44245, 227, 65266, 0, 3056, 1, 0, 0, 56713), -- Earthen Helmet
(44245, 226, 65265, 0, 3160, 1, 0, 0, 56713), -- Earthen Gauntlets
(44245, 225, 65264, 0, 3087, 1, 0, 0, 56713), -- Earthen Battleplate
(44245, 114, 60332, 0, 8867, 1, 0, 0, 56713), -- Earthen Handguards
(44245, 113, 60331, 0, 3045, 1, 0, 0, 56713), -- Earthen Shoulderguards
(44245, 112, 60330, 0, 8872, 1, 0, 0, 56713), -- Earthen Legguards
(44245, 111, 60329, 0, 8872, 1, 0, 0, 56713), -- Earthen Chestguard
(44245, 110, 60328, 0, 3051, 1, 0, 0, 56713), -- Earthen Faceguard
(44245, 109, 60327, 0, 3045, 1, 0, 0, 56713), -- Earthen Pauldrons
(44245, 108, 60326, 0, 8867, 1, 0, 0, 56713), -- Earthen Gauntlets
(44245, 107, 60325, 0, 3051, 1, 0, 0, 56713), -- Earthen Helmet
(44245, 106, 60324, 0, 8872, 1, 0, 0, 56713), -- Earthen Legplates
(44245, 105, 60323, 0, 8872, 1, 0, 0, 56713), -- Earthen Battleplate
(44245, 44, 58180, 0, 8867, 1, 0, 0, 56713), -- License to Slay
(44245, 43, 58181, 0, 8867, 1, 0, 0, 56713), -- Fluid Death
(44245, 42, 58182, 0, 8867, 1, 0, 0, 56713), -- Bedrock Talisman
(44245, 41, 58183, 0, 8867, 1, 0, 0, 56713), -- Soul Casket
(44245, 40, 58184, 0, 8867, 1, 0, 0, 56713), -- Core of Ripeness
(44245, 39, 64671, 0, 8865, 1, 0, 0, 56713), -- Relic of Golganneth
(44245, 38, 64672, 0, 8865, 1, 0, 0, 56713), -- Relic of Norgannon
(44245, 37, 64673, 0, 8865, 1, 0, 0, 56713), -- Relic of Eonar
(44245, 36, 64674, 0, 8865, 1, 0, 0, 56713), -- Relic of Aggramar
(44245, 35, 64676, 0, 8865, 1, 0, 0, 56713), -- Relic of Khaz'goroth
(44245, 34, 68812, 0, 8866, 1, 0, 0, 56713), -- Hornet-Sting Band
(44245, 33, 58185, 0, 8866, 1, 0, 0, 56713), -- Band of Bees
(44245, 32, 58187, 0, 8866, 1, 0, 0, 56713), -- Ring of the Battle Anthem
(44245, 31, 58188, 0, 8866, 1, 0, 0, 56713), -- Band of Secret Names
(44245, 30, 58189, 0, 8866, 1, 0, 0, 56713), -- Twined Band of Flowers
(44245, 29, 58195, 0, 8867, 1, 0, 0, 56713), -- Woe Breeder's Boots
(44245, 28, 58197, 0, 8867, 1, 0, 0, 56713), -- Rock Furrow Boots
(44245, 27, 58198, 0, 8867, 1, 0, 0, 56713), -- Eternal Pathfinders
(44245, 26, 58199, 0, 8867, 1, 0, 0, 56713), -- Moccasins of Verdurous Glooms
(44245, 25, 58481, 0, 8867, 1, 0, 0, 56713); -- Boots of the Perilous Seas

INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(44245, 24, 58482, 0, 8867, 1, 0, 0, 56713), -- Treads of Fleeting Joy
(44245, 23, 58484, 0, 8867, 1, 0, 0, 56713), -- Fading Violet Sandals
(44245, 22, 58485, 0, 8867, 1, 0, 0, 56713), -- Melodious Slippers
(44245, 21, 58486, 0, 8867, 1, 0, 0, 56713), -- Slippers of Moving Waters
(44245, 20, 58191, 0, 8866, 1, 0, 0, 56713), -- Viewless Wings
(44245, 19, 58192, 0, 8866, 1, 0, 0, 56713), -- Gray Hair Cloak
(44245, 18, 58193, 0, 8866, 1, 0, 0, 56713), -- Haunt of Flies
(44245, 17, 58190, 0, 8866, 1, 0, 0, 56713), -- Floating Web
(44245, 16, 58194, 0, 8866, 1, 0, 0, 56713), -- Heavenly Breeze
(44245, 15, 67427, 0, 3329, 1, 0, 0, 56713), -- Leggings of the Forlorn Protector
(44245, 12, 65000, 0, 3329, 1, 0, 0, 56713), -- Crown of the Forlorn Protector
(44245, 9, 67430, 0, 3329, 1, 0, 0, 56713), -- Gauntlets of the Forlorn Protector
(44245, 6, 65087, 0, 3329, 1, 0, 0, 56713), -- Shoulders of the Forlorn Protector
(44245, 3, 67424, 0, 3329, 1, 0, 0, 56713), -- Chest of the Forlorn Protector
(12783, 5, 35906, 0, 423, 1, 0, 0, 56713), -- Reins of the Black War Elekk
(12783, 4, 29471, 0, 423, 1, 0, 0, 56713), -- Reins of the Black War Tiger
(12783, 3, 29468, 0, 423, 1, 0, 0, 56713), -- Black War Steed Bridle
(12783, 2, 29467, 0, 423, 1, 0, 0, 56713), -- Black War Ram
(12783, 1, 29465, 0, 423, 1, 0, 0, 56713); -- Black Battlestrider

UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=56713 WHERE (`entry`=12805 AND `item`=18442 AND `ExtendedCost`=838 AND `type`=1); -- Master Sergeant's Insignia
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=56713 WHERE (`entry`=12781 AND `item`=31855 AND `ExtendedCost`=0 AND `type`=1); -- Major Combat Mana Potion
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=56713 WHERE (`entry`=12781 AND `item`=31853 AND `ExtendedCost`=0 AND `type`=1); -- Major Combat Healing Potion
UPDATE `npc_vendor` SET `VerifiedBuild`=56713 WHERE (`entry`=52027 AND `item`=42991 AND `ExtendedCost`=3319 AND `type`=1) OR (`entry`=52027 AND `item`=42992 AND `ExtendedCost`=3319 AND `type`=1) OR (`entry`=52027 AND `item`=69893 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48716 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42945 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48718 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52027 AND `item`=42947 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52027 AND `item`=42948 AND `ExtendedCost`=3319 AND `type`=1) OR (`entry`=52027 AND `item`=42946 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52027 AND `item`=42943 AND `ExtendedCost`=2551 AND `type`=1) OR (`entry`=52027 AND `item`=42944 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48691 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42985 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48689 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42952 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42984 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48687 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48683 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42951 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48677 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42950 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=42949 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=48685 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=69890 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=52027 AND `item`=69889 AND `ExtendedCost`=3318 AND `type`=1) OR (`entry`=44252 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1);
