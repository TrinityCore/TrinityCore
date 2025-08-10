SET @CGUID := 1252018;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+83;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 193420, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3933.688720703125, 4008.2373046875, 105.2834091186523437, 2.956860542297363281, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Desiccated Deer (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+1, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3910.682861328125, 4078.9111328125, 86.76601409912109375, 0.544660329818725585, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+2, 188689, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3795.700439453125, 3991.20556640625, 168.9792327880859375, 0.465317845344543457, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+3, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3907.75341796875, 4121.34619140625, 89.69671630859375, 2.50892949104309082, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+4, 193422, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3894.255126953125, 4082.53466796875, 88.6266021728515625, 4.358771800994873046, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Starving Bullfrog (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+5, 196121, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3912.29541015625, 4040.05810546875, 99.9551239013671875, 0.372308135032653808, 120, 0, 0, 83980, 2991, 0, 0, 0, 0, 47213), -- Sundered Sentinel (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 391245 - Supply-Laden) (possible waypoints or random movement)
(@CGUID+6, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3903.086669921875, 4044.76513671875, 99.88239288330078125, 2.530663251876831054, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+7, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3950.600830078125, 4051.3828125, 89.34944915771484375, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+8, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3869.732666015625, 3925.618896484375, 109.5178680419921875, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+9, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3907.299072265625, 4111.369140625, 90.1341094970703125, 4.792932510375976562, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3955.6806640625, 4045.286376953125, 89.37589263916015625, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+11, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3915.125, 4041.83251953125, 99.7295074462890625, 5.646639823913574218, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+12, 196121, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3912.26025390625, 4051.502685546875, 99.60579681396484375, 2.011648416519165039, 120, 0, 0, 83980, 2991, 0, 0, 0, 0, 47213), -- Sundered Sentinel (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+13, 196121, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3906.279052734375, 4125.98193359375, 89.75652313232421875, 3.178761720657348632, 120, 0, 0, 83980, 2991, 0, 0, 0, 0, 47213), -- Sundered Sentinel (Area: Tower of Iskhdormi - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3977.267333984375, 4105.99853515625, 90.5555572509765625, 4.662846565246582031, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+15, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3899.688720703125, 4075.84228515625, 87.340301513671875, 5.303608894348144531, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+16, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3902.423583984375, 4118.3759765625, 90.73992919921875, 3.535314559936523437, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+17, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3863.375, 3926.952392578125, 111.1778564453125, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+18, 193422, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3975.215576171875, 4064.70458984375, 89.70453643798828125, 0.532738804817199707, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Starving Bullfrog (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+19, 193430, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3900.970458984375, 4036.495849609375, 119.1272430419921875, 2.191366195678710937, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Prowling Vulture (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+20, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3883.609375, 4057.59375, 88.0864105224609375, 0, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+21, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3937.23046875, 4072.5771484375, 85.4722137451171875, 2.927575111389160156, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+22, 196121, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3885.02197265625, 4149.43603515625, 92.00644683837890625, 0.530074656009674072, 120, 0, 0, 83980, 2991, 0, 0, 0, 0, 47213), -- Sundered Sentinel (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+23, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3918.869873046875, 3956.21875, 110.5706253051757812, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+24, 188689, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3783.342041015625, 3989.724365234375, 169.660858154296875, 3.214988231658935546, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+25, 188689, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3792.267578125, 3987.386474609375, 169.18280029296875, 2.649774551391601562, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+26, 188689, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3783.234130859375, 3993.48828125, 169.3698577880859375, 2.348156213760375976, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+27, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3874.36279296875, 4149.75537109375, 91.41146087646484375, 3.535314321517944335, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+28, 188689, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3791.495849609375, 3992.689453125, 168.8687744140625, 0.067967087030410766, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+29, 188689, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3780.380126953125, 3997.135498046875, 170.5953216552734375, 3.019587516784667968, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 47213), -- Oozing Decay (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+30, 196121, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4000.358154296875, 4109.87158203125, 90.96807098388671875, 3.668121814727783203, 120, 0, 0, 83980, 2991, 0, 0, 0, 0, 47213), -- Sundered Sentinel (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+31, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3953.095458984375, 4151.751953125, 92.1177825927734375, 0, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+32, 199512, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4005.491455078125, 4040.670166015625, 99.957733154296875, 0.522346019744873046, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Dewcone (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 396916 - Water Infusion [DNT])
(@CGUID+33, 192049, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3975.281494140625, 4099.3740234375, 89.324188232421875, 0.174481391906738281, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47213), -- Swoglet (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+34, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3998.12841796875, 4135.34228515625, 91.3072509765625, 4.680173397064208984, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+35, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3982.453857421875, 4102.4345703125, 90.0268096923828125, 2.039251565933227539, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+36, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3973.6982421875, 4103.10546875, 89.6709747314453125, 5.65578460693359375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+37, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3945.875, 4139.8359375, 91.671142578125, 2.20297098159790039, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+38, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4006.560791015625, 4068.8369140625, 85.9723052978515625, 0, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+39, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4050.390625, 4073.252685546875, 94.18115234375, 0, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+40, 196121, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3956.96875, 4186.2646484375, 89.54607391357421875, 1.309942245483398437, 120, 0, 0, 83980, 2991, 0, 0, 0, 0, 47213), -- Sundered Sentinel (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+41, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3878.5869140625, 4145.06591796875, 91.2760467529296875, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+42, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3873.48779296875, 4145.93212890625, 91.6557769775390625, 2.50892949104309082, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+43, 193430, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3970.205322265625, 4182.54541015625, 118.9256591796875, 0.310195475816726684, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Prowling Vulture (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+44, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4014.993408203125, 4070.423583984375, 87.4332275390625, 3.926990985870361328, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+45, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3958.765625, 4156.2255859375, 91.9685516357421875, 4.781678676605224609, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+46, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3987.5869140625, 4134.47412109375, 91.64484405517578125, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+47, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3999.682373046875, 4130.53369140625, 91.1360626220703125, 3.065534830093383789, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 373664 - Carrying Crate)
(@CGUID+48, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3966.44970703125, 4155.68603515625, 91.6436920166015625, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+49, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3984.98095703125, 4162.59814453125, 91.6973876953125, 5.079067707061767578, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+50, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3988.78466796875, 4158.50244140625, 90.80100250244140625, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+51, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4055.255126953125, 4127.0615234375, 104.5035247802734375, 1.88110518455505371, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+52, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4064.26220703125, 4105.32275390625, 107.9136581420898437, 3.306958913803100585, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+53, 196119, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4052.05908203125, 4138.12158203125, 137.028778076171875, 0, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 47213), -- Dragonspawn Spell Weaver (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+54, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4005.8369140625, 4132.94775390625, 91.6379547119140625, 4.838380813598632812, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 373664 - Carrying Crate)
(@CGUID+55, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3973.767333984375, 4181.25, 91.01308441162109375, 5.663509368896484375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+56, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3920.013671875, 4183.87890625, 91.43035125732421875, 5.621323585510253906, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+57, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -3912.40966796875, 4179.90869140625, 89.58684539794921875, 2.50892949104309082, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+58, 193425, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3993.8994140625, 4158.9765625, 90.38074493408203125, 0, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Cricket (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+59, 193430, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3939.873779296875, 4232.85791015625, 96.5962066650390625, 1.647064924240112304, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Prowling Vulture (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+60, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4041.989013671875, 4070.3095703125, 94.312835693359375, 1.627795696258544921, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+61, 193427, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3989.501708984375, 4194.9462890625, 90.99863433837890625, 0, 120, 10, 0, 67184, 0, 1, 0, 0, 0, 47213), -- Tired Goat (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+62, 193427, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3961.0234375, 4202.68212890625, 88.43476104736328125, 5.840961933135986328, 120, 10, 0, 67184, 0, 1, 0, 0, 0, 47213), -- Tired Goat (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+63, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4054.37158203125, 4083.168212890625, 97.12067413330078125, 5.939969062805175781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+64, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4046.751220703125, 4129.97265625, 137.220550537109375, 2.060411453247070312, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+65, 189104, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3932.263916015625, 4209.90234375, 81.42632293701171875, 2.732983350753784179, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47213), -- Swoglet (Area: Tower of Iskhdormi - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+66, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4052.259765625, 4133.3330078125, 107.4687957763671875, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+67, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4061.2509765625, 4128.12841796875, 104.600738525390625, 0.839051783084869384, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+68, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4066.428466796875, 4104.88671875, 107.9695816040039062, 4.98274993896484375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+69, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4060.804443359375, 4135.37353515625, 137.142120361328125, 1.603762745857238769, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+70, 196123, 2444, 13646, 13887, '0', 0, 0, 0, 1, -4068.45947265625, 4110.87890625, 108.6701812744140625, 1.94411635398864746, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Tarasek Warrior (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+71, 197546, 2444, 13646, 13887, '0', 0, 0, 0, 0, -4065.015625, 4179.423828125, 47.70409011840820312, 5.74604034423828125, 120, 0, 0, 8, 0, 0, 0, 0, 0, 47213), -- Coastal Grizzly Cub (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+72, 193422, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3944.285400390625, 4238.22509765625, 78.83382415771484375, 5.448840618133544921, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Starving Bullfrog (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+73, 193430, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3874.976806640625, 4236.60888671875, 113.3520736694335937, 4.631242752075195312, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Prowling Vulture (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+74, 193422, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3851.569091796875, 4181.96435546875, 80.49452972412109375, 2.961040735244750976, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Starving Bullfrog (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+75, 189104, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3857.397705078125, 4210.9443359375, 81.5826568603515625, 4.19590616226196289, 120, 4, 0, 5, 0, 1, 0, 0, 0, 47213), -- Swoglet (Area: Tower of Iskhdormi - Difficulty: 0)
(@CGUID+76, 193427, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3818.798583984375, 4181.796875, 85.75205230712890625, 0, 120, 0, 0, 67184, 0, 0, 0, 0, 0, 47213), -- Tired Goat (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+77, 193427, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3824.04638671875, 4209.8447265625, 85.30358123779296875, 3.938722610473632812, 120, 0, 0, 67184, 0, 0, 0, 0, 0, 47213), -- Tired Goat (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+78, 193422, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3899.293701171875, 4233.068359375, 84.679351806640625, 5.924643516540527343, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Starving Bullfrog (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+79, 193427, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3903.975830078125, 4261.52099609375, 83.9424285888671875, 0, 120, 6, 0, 67184, 0, 1, 0, 0, 0, 47213), -- Tired Goat (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+80, 193427, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3915.26123046875, 4256.03955078125, 86.37198638916015625, 4.068813323974609375, 120, 6, 0, 67184, 0, 1, 0, 0, 0, 47213), -- Tired Goat (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+81, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3816.402099609375, 4146.2880859375, 80.4083099365234375, 1.375363349914550781, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+82, 193428, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3854.24609375, 4242.6328125, 82.67722320556640625, 0.642720162868499755, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Feral Hyena (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+83, 193431, 2444, 13646, 13887, '0', 0, 0, 0, 0, -3819.179443359375, 4145.14990234375, 80.67369842529296875, 2.250375270843505859, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 47213); -- Hungry Nibbler (Area: Tower of Iskhdormi - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+83;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Desiccated Deer - 383173 - Decaying
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Hungry Nibbler - 383173 - Decaying
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Starving Bullfrog - 383173 - Decaying
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '391245'), -- Sundered Sentinel - 391245 - Supply-Laden
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Hungry Nibbler - 383173 - Decaying
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Starving Bullfrog - 383173 - Decaying
(@CGUID+19, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '383173'), -- Prowling Vulture - 383173 - Decaying
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Hungry Nibbler - 383173 - Decaying
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Hungry Nibbler - 383173 - Decaying
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, 0, '396916'), -- Dewcone - 396916 - Water Infusion [DNT]
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Hungry Nibbler - 383173 - Decaying
(@CGUID+43, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '383173'), -- Prowling Vulture - 383173 - Decaying
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Hungry Nibbler - 383173 - Decaying
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, 0, '373664'), -- Tarasek Warrior - 373664 - Carrying Crate
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, 0, '373664'), -- Tarasek Warrior - 373664 - Carrying Crate
(@CGUID+59, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '383173'), -- Prowling Vulture - 383173 - Decaying
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Tired Goat - 383173 - Decaying
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Tired Goat - 383173 - Decaying
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- Starving Bullfrog - 383173 - Decaying
(@CGUID+73, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, '383173'), -- Prowling Vulture - 383173 - Decaying
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'); -- Starving Bullfrog - 383173 - Decaying

--  Creature Template
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=196119; -- Dragonspawn Spell Weaver
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=196121; -- Sundered Sentinel
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=196123; -- Tarasek Warrior

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (196121,196123));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(196121, 1, 191717, 0, 0, 0, 0, 0, 0, 0, 0, 47213), -- Sundered Sentinel
(196123, 1, 189699, 0, 0, 0, 0, 0, 0, 0, 0, 47213); -- Tarasek Warrior

-- Waypoints for CGUID+5
SET @PATH := (@CGUID+5) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3904.003, 4043.296, 99.94854, NULL, 6575),
(@PATH, 1, -3914.151, 4039.333, 99.9566, NULL, 5385);

UPDATE `creature` SET `position_x`= -3904.003, `position_y`= 4043.296, `position_z`= 99.94854, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+5, @PATH, 1);

-- Waypoints for CGUID+30
SET @PATH := (@CGUID+30) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4006.186, 4106.475, 90.81703, NULL, 0),
(@PATH, 1, -3989.988, 4115.899, 91.36079, NULL, 0),
(@PATH, 2, -3974.637, 4119.325, 91.59175, NULL, 0),
(@PATH, 3, -3964.071, 4120.104, 92.13575, NULL, 8491),
(@PATH, 4, -3974.637, 4119.325, 91.59175, NULL, 0),
(@PATH, 5, -3989.988, 4115.899, 91.36079, NULL, 0),
(@PATH, 6, -4006.186, 4106.475, 90.81703, NULL, 0),
(@PATH, 7, -4011.507, 4092.031, 89.3557, NULL, 8452);

UPDATE `creature` SET `position_x`= -4006.186, `position_y`= 4106.475, `position_z`= 90.81703, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+30;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+30, @PATH, 1);

-- Waypoints for CGUID+12
SET @PATH := (@CGUID+12) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3942.651, 4119.08, 94.50294, NULL, 0),
(@PATH, 1, -3935.899, 4110.774, 95.28138, NULL, 0),
(@PATH, 2, -3930.608, 4090.109, 98.84196, NULL, 0),
(@PATH, 3, -3920.964, 4069.948, 101.7247, NULL, 0),
(@PATH, 4, -3911.839, 4050.609, 99.6058, NULL, 6972),
(@PATH, 5, -3920.964, 4069.948, 101.7247, NULL, 0),
(@PATH, 6, -3930.608, 4090.109, 98.84196, NULL, 0),
(@PATH, 7, -3935.899, 4110.774, 95.28138, NULL, 0),
(@PATH, 8, -3942.651, 4119.08, 94.50294, NULL, 0),
(@PATH, 9, -3951.297, 4120.343, 93.22059, NULL, 6846);

UPDATE `creature` SET `position_x`= -3942.651, `position_y`= 4119.08, `position_z`= 94.50294, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+12, @PATH, 1);

-- Waypoints for CGUID+13
SET @PATH := (@CGUID+13) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3909.149, 4125.875, 89.74739, NULL, 0),
(@PATH, 1, -3913.745, 4131.421, 89.74739, NULL, 0),
(@PATH, 2, -3911.682, 4141.104, 90.08846, NULL, 0),
(@PATH, 3, -3903.085, 4151.649, 91.45394, NULL, 0),
(@PATH, 4, -3893.71, 4154.926, 91.84074, NULL, 0),
(@PATH, 5, -3882.915, 4160.471, 91.80033, NULL, 0),
(@PATH, 6, -3876.799, 4162.921, 91.50626, NULL, 0),
(@PATH, 7, -3863.005, 4154.159, 91.35078, NULL, 0),
(@PATH, 8, -3864.965, 4142.547, 93.28902, NULL, 0),
(@PATH, 9, -3872.135, 4137.083, 92.63798, NULL, 0),
(@PATH, 10, -3879.688, 4137.663, 92.66227, NULL, 0),
(@PATH, 11, -3891.188, 4135.21, 91.48405, NULL, 0),
(@PATH, 12, -3902.668, 4126.116, 89.76802, NULL, 0);

UPDATE `creature` SET `position_x`= -3909.149, `position_y`= 4125.875, `position_z`= 89.74739, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+13, @PATH, 1);

-- Waypoints for CGUID+40
SET @PATH := (@CGUID+40) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3984.906, 4167.188, 91.21494, NULL, 0),
(@PATH, 1, -3969.726, 4167.048, 91.45176, NULL, 0),
(@PATH, 2, -3959.839, 4175.517, 90.81948, NULL, 0),
(@PATH, 3, -3956.248, 4188.983, 89.31216, NULL, 0),
(@PATH, 4, -3958.877, 4201.669, 88.42085, NULL, 0),
(@PATH, 5, -3970.168, 4206.852, 91.15707, NULL, 0),
(@PATH, 6, -3978.304, 4200.243, 90.66611, NULL, 0),
(@PATH, 7, -3982.384, 4193.96, 90.21738, NULL, 0),
(@PATH, 8, -3987.441, 4189.802, 90.84238, NULL, 0),
(@PATH, 9, -3988.233, 4177.136, 89.99802, NULL, 0);

UPDATE `creature` SET `position_x`= -3984.906, `position_y`= 4167.188, `position_z`= 91.21494, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+40;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+40;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+40, @PATH, 1);

-- Waypoints for CGUID+22
SET @PATH := (@CGUID+22) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3963.859, 4170.938, 91.31142, NULL, 0),
(@PATH, 1, -3942.396, 4162.51, 90.5789, NULL, 0),
(@PATH, 2, -3920.401, 4151.627, 90.19064, NULL, 0),
(@PATH, 3, -3903.462, 4147.01, 90.76986, NULL, 0),
(@PATH, 4, -3888.53, 4147.38, 92.1193, NULL, 0),
(@PATH, 5, -3877.377, 4153.917, 91.87443, NULL, 0),
(@PATH, 6, -3875.868, 4163.451, 91.44267, NULL, 0),
(@PATH, 7, -3882.276, 4169.728, 89.35352, NULL, 0),
(@PATH, 8, -3896.252, 4166.594, 89.36246, NULL, 0),
(@PATH, 9, -3905.006, 4168.659, 90.80535, NULL, 0),
(@PATH, 10, -3932.502, 4177.556, 91.43035, NULL, 0),
(@PATH, 11, -3944.575, 4186.356, 89.47561, NULL, 0),
(@PATH, 12, -3952.837, 4188.042, 89.31216, NULL, 0),
(@PATH, 13, -3966.003, 4181.455, 90.68716, NULL, 0);

UPDATE `creature` SET `position_x`= -3963.859, `position_y`= 4170.938, `position_z`= 91.31142, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+22;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+22, @PATH, 1);

-- Waypoints for CGUID+54
SET @PATH := (@CGUID+54) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3999.927, 4140.386, 91.58312, NULL, 4236),
(@PATH, 1, -4001.076, 4135.486, 92.21011, NULL, 0),
(@PATH, 2, -4003.092, 4134.731, 91.95896, NULL, 0),
(@PATH, 3, -4005.837, 4132.948, 91.63795, NULL, 9101),
(@PATH, 4, -3999.927, 4140.386, 91.58312, NULL, 4142);

UPDATE `creature` SET `position_x`= -3999.927, `position_y`= 4140.386, `position_z`= 91.58312, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+54;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+54;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+54, @PATH, 1);
