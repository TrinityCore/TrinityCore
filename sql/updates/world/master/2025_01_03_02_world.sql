SET @CGUID := 10005242;
SET @OGUID := 10001350;

SET @NPCTEXTID := 600071;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+44;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233379, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3232.624267578125, -3047.913330078125, 341.357025146484375, 0.020863203331828117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Earthen Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+1, 236057, 2552, 14771, 14771, '0', 0, 0, 0, 0, 3249.45654296875, -3073.364501953125, 347.410888671875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Watcher Umjin (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+2, 231534, 2552, 14771, 14771, '0', 0, 0, 0, 0, 3234.20751953125, -3047.510498046875, 341.357025146484375, 4.341081619262695312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Captain Krazz (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+3, 233379, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3217.703125, -3037.638916015625, 341.35699462890625, 4.117817401885986328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Earthen Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+4, 233379, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3218.3515625, -3052.625, 341.3570556640625, 0.358701169490814208, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Earthen Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+5, 236058, 2552, 14771, 14771, '0', 0, 0, 0, 0, 3229.413330078125, -3066.395751953125, 343.010711669921875, 1.704148769378662109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Watcher Du'una (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+6, 236059, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3220.651123046875, -3051.286376953125, 341.357025146484375, 4.019763946533203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Crewman Boltshine (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+7, 231542, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3246.1259765625, -3011.036376953125, 346.5330810546875, 5.180139064788818359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Mounted Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+8, 231542, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3201.42529296875, -3046.098876953125, 350.398681640625, 5.202288627624511718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Mounted Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+9, 233379, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3233.947021484375, -3049.161376953125, 341.357025146484375, 1.395307302474975585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Earthen Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+10, 236055, 2552, 14771, 14771, '0', 0, 0, 0, 0, 3230.854248046875, -3053.819580078125, 341.3570556640625, 5.727922439575195312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Chief Officer Hammerflange (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 1216769 - Cooking)
(@CGUID+11, 233379, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3216.421142578125, -3039.751708984375, 341.35699462890625, 1.13375401496887207, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Earthen Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+12, 231542, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3198.5244140625, -3041.69091796875, 343.738739013671875, 5.332429885864257812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Mounted Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+13, 231542, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3241.033935546875, -2976.68408203125, 383.29656982421875, 4.594642162322998046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Mounted Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+14, 231542, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3201.463623046875, -3020.145751953125, 345.465606689453125, 5.459173202514648437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Mounted Stormranger (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+15, 215357, 2552, 14771, 14771, '0', 0, 0, 0, 0, 3205.991455078125, -3000.630126953125, 342.67535400390625, 1.013928771018981933, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Velocity (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+16, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 2, 3152.859375, -2994.359375, 344.81146240234375, 3.42229008674621582, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+17, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 6, 3220.06689453125, -2976.654541015625, 342.002166748046875, 4.824759960174560546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+18, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 1, 3229.442626953125, -2976.854248046875, 342, 4.636026382446289062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+19, 219014, 2552, 14771, 14771, '0', 0, 0, 0, 5, 3150.8837890625, -2994.928955078125, 344.81146240234375, 0.28069731593132019, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT], 18950 - Invisibility and Stealth Detection)
(@CGUID+20, 215355, 2552, 14771, 14771, '0', 0, 0, 0, 0, 3206.77685546875, -2999.701416015625, 342.698699951171875, 4.113892555236816406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Jack-Pierre (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 431021 - Cosmetic Aura: Crown)
(@CGUID+21, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3083.33251953125, -2889.560791015625, 365.211151123046875, 5.674371242523193359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+22, 214947, 2552, 14771, 0, '0', 0, 0, 0, 0, 3157.741455078125, -2980.529541015625, 348.9178466796875, 0.125353932380676269, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58238), -- Eye of Topaz (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+23, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3081.81689453125, -2988.3056640625, 365.21868896484375, 5.051800251007080078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+24, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 1, 3087.5, -2947.818115234375, 365.126312255859375, 1.570796370506286621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+25, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3085.006103515625, -2890.7275390625, 365.211151123046875, 2.532778501510620117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+26, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 7, 3089.618896484375, -3052.53125, 363.87005615234375, 1.740766763687133789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+27, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3118.87060546875, -2917.5869140625, 369.124481201171875, 1.859456300735473632, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+28, 226603, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3088.882080078125, -2888.295166015625, 366.440765380859375, 1.565147757530212402, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Ironus Coldsteel (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 455646 - Unbothered and Moisturized)
(@CGUID+29, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 1, 3084.62841796875, -3043.142333984375, 363.870025634765625, 5.316864490509033203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+30, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 5, 3094.702392578125, -3044.126708984375, 363.870025634765625, 3.602092504501342773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+31, 219982, 2552, 14771, 15182, '0', 0, 0, 0, 3, 3090.36328125, -3047.413330078125, 363.804107666015625, 3.22027134895324707, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+32, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 5, 3092.30126953125, -3051.8125, 363.87005615234375, 2.35074782371520996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+33, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 7, 3082.630126953125, -3044.697998046875, 363.870025634765625, 5.885114192962646484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+34, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3119.307373046875, -2915.7431640625, 369.124481201171875, 4.380611419677734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+35, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3083.473876953125, -2891.5400390625, 365.211151123046875, 1.268476366996765136, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+36, 219982, 2552, 14771, 15182, '0', 0, 0, 0, 1, 3087.063720703125, -3047.673583984375, 363.8192138671875, 0.078712366521358489, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+37, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3082.5009765625, -2990.2431640625, 365.2100830078125, 1.910207509994506835, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+38, 219014, 2552, 14771, 15182, '0', 0, 0, 0, 6, 3080.940185546875, -3052.607666015625, 363.87005615234375, 3.309943199157714843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Peacekeeper (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+39, 219370, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3091.2666015625, -2880.654541015625, 365.222412109375, 0.636078476905822753, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Wedekind (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+40, 219371, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3092.912353515625, -2879.439208984375, 365.223175048828125, 3.777671337127685546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Mickde (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+41, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3113.126708984375, -2872.8212890625, 387.765167236328125, 0.825501084327697753, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+42, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3112.639892578125, -2869.717041015625, 387.765167236328125, 5.728389739990234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1 (Auras: 439015 - Holding Mead Mug [DNT])
(@CGUID+43, 219126, 2552, 14771, 15182, '0', 0, 0, 0, 0, 3115.630126953125, -2870.451416015625, 387.765167236328125, 3.995951652526855468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238), -- Oathsworn Citizen (Area: Stoneward's Rise - Difficulty: 0) CreateObject1
(@CGUID+44, 214947, 2552, 14771, 0, '0', 0, 0, 0, 0, 3077.231689453125, -2995.241455078125, 367.247222900390625, 5.045444488525390625, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 58238); -- Eye of Topaz (Area: 0 - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+44;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+7, 0, 123979, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Mounted Stormranger
(@CGUID+8, 0, 123976, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Mounted Stormranger
(@CGUID+12, 0, 123978, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Mounted Stormranger
(@CGUID+13, 0, 123978, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Mounted Stormranger
(@CGUID+14, 0, 123976, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Mounted Stormranger
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Oathsworn Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Oathsworn Citizen - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439015'), -- Oathsworn Citizen - 439015 - Holding Mead Mug [DNT]
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''); -- Oathsworn Citizen

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 428856, 2552, 14771, 14771, '0', 0, 0, 3218.953125, -3050.42529296875, 341.276519775390625, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 58238), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+1, 428978, 2552, 14771, 14771, '0', 0, 0, 3099.618896484375, -2959.68408203125, 365.126312255859375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58238), -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+2, 428937, 2552, 14771, 14771, '0', 0, 0, 3079.439208984375, -3050.239501953125, 363.786712646484375, 0.008726147934794425, 0, 0, 0.004363059997558593, 0.999990463256835937, 120, 255, 1, 58238), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+3, 428871, 2552, 14771, 14771, '0', 0, 0, 3220.989501953125, -3052.486083984375, 341.265106201171875, 2.95832991600036621, 0, 0, 0.995804786682128906, 0.091503240168094635, 120, 255, 1, 58238), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+4, 428938, 2552, 14771, 14771, '0', 0, 0, 3097.80810546875, -3050.616455078125, 363.786712646484375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58238), -- Chair (Area: Dornogal - Difficulty: 0) CreateObject1
(@OGUID+5, 428940, 2552, 14771, 14771, '0', 0, 0, 3099.4609375, -2967.678955078125, 365.125885009765625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 58238); -- Bench (Area: Dornogal - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (473902 /*Zeppelin to Dornogal*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(473902, 0, 0x100020, 0, 0); -- Zeppelin to Dornogal

DELETE FROM `creature_template_addon` WHERE `entry` IN (236055 /*236055 (Chief Officer Hammerflange) - Cooking*/, 231542 /*231542 (Mounted Stormranger)*/, 236057 /*236057 (Watcher Umjin)*/, 233379 /*233379 (Earthen Stormranger)*/, 215355, 219370, 226603);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(236055, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1216769'), -- 236055 (Chief Officer Hammerflange) - Cooking
(231542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 231542 (Mounted Stormranger)
(236057, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 236057 (Watcher Umjin)
(233379, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 233379 (Earthen Stormranger)
(215355, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '431021'), -- 215355 (Jack-Pierre) - Cosmetic Aura: Crown
(219370, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- 219370 (Wedekind) - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(226603, 0, 0, 0, 0, 0, 1, 0, 0, 29111, 0, 0, 0, '455646'); -- 226603 (Ironus Coldsteel) - Unbothered and Moisturized

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=236055; -- Chief Officer Hammerflange
UPDATE `creature_template` SET `faction`=3395, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x800000 WHERE `entry`=231542; -- Mounted Stormranger
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=236058; -- Watcher Du'una
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=236057; -- Watcher Umjin
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=233379; -- Earthen Stormranger
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=215355; -- Jack-Pierre
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=215357; -- Velocity
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=219371; -- Mickde
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=219370; -- Wedekind
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=226603; -- Ironus Coldsteel

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x30000100, `VerifiedBuild`=58238 WHERE (`Entry`=236055 AND `DifficultyID`=0); -- 236055 (Chief Officer Hammerflange) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x30000000, `VerifiedBuild`=58238 WHERE (`Entry`=231542 AND `DifficultyID`=0); -- 231542 (Mounted Stormranger) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x30000100, `VerifiedBuild`=58238 WHERE (`Entry`=236058 AND `DifficultyID`=0); -- 236058 (Watcher Du'una) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=58238 WHERE (`Entry`=236057 AND `DifficultyID`=0); -- 236057 (Watcher Umjin) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=236059 AND `DifficultyID`=0); -- 236059 (Crewman Boltshine) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=863, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=233379 AND `DifficultyID`=0); -- 233379 (Earthen Stormranger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=215355 AND `DifficultyID`=0); -- 215355 (Jack-Pierre) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=215357 AND `DifficultyID`=0); -- 215357 (Velocity) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=219371 AND `DifficultyID`=0); -- 219371 (Mickde) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=219370 AND `DifficultyID`=0); -- 219370 (Wedekind) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=226603 AND `DifficultyID`=0); -- 226603 (Ironus Coldsteel) - CanSwim

-- Difficulty override
DELETE FROM `creature_static_flags_override` WHERE `SpawnId` = @CGUID+13;
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+13, 0, 0x10000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=236057 AND `MenuID`=37731) OR (`CreatureID`=236058 AND `MenuID`=37730) OR (`CreatureID`=231534 AND `MenuID`=37701);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(236057, 37731, 58238), -- Watcher Umjin
(236058, 37730, 58238), -- Watcher Du'una
(231534, 37701, 58238); -- Captain Krazz

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 279729, 0, 0, 0, 0, 0, 0, 0, 58238), -- 231534 (Captain Krazz)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 279768, 0, 0, 0, 0, 0, 0, 0, 58238), -- 236058 (Watcher Du'una)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 279769, 0, 0, 0, 0, 0, 0, 0, 58238), -- 236057 (Watcher Umjin)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 279704, 0, 0, 0, 0, 0, 0, 0, 58238); -- 231534 (Captain Krazz)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37717 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37730 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=37731 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=37701 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37717, @NPCTEXTID+0, 58238), -- 231534 (Captain Krazz)
(37730, @NPCTEXTID+1, 58238), -- 236058 (Watcher Du'una)
(37731, @NPCTEXTID+2, 58238), -- 236057 (Watcher Umjin)
(37701, @NPCTEXTID+3, 58238); -- 231534 (Captain Krazz)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37701 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37701, 131551, 0, 0, 'What do you know about the Siren Isle?', 0, 0, 0, 37717, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58238);

-- Chief Officer Hammerflange smart ai
SET @ENTRY := 236055;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 1216769, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 1216769 on self', '');

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 219014;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3087.91, -2904.57, 365.1263, NULL, 6607),
(@PATH, 1, 3092.757, -2962.4094, 365.1263, NULL, 0),
(@PATH, 2, 3092.9412, -2990.2488, 365.1263, NULL, 0),
(@PATH, 3, 3089.5828, -3001.2815, 365.024, NULL, 0),
(@PATH, 4, 3089.8892, -3034.8074, 365.33688, NULL, 0),
(@PATH, 5, 3089.9985, -3037.069, 364.34845, NULL, 0),
(@PATH, 6, 3088.79, -3043.4, 363.88498, NULL, 2098),
(@PATH, 7, 3087.6946, -3001.2383, 365.02402, NULL, 0),
(@PATH, 8, 3085.7185, -2990.1296, 365.1263, NULL, 0),
(@PATH, 9, 3085.5364, -2962.6116, 365.1263, NULL, 0),
(@PATH, 10, 3082.5898, -2907.9004, 365.12634, NULL, 0);

UPDATE `creature` SET `position_x`=3087.91, `position_y`=-2904.57, `position_z`=365.1263, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
