SET @CGUID := 11000430;
SET @OGUID := 11000008;

SET @NPCTEXTID := 610009;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+216;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 211137, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4438.4150390625, -4921.20849609375, 14.58650875091552734, 3.177709341049194335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+1, 246409, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4480.17529296875, -4908.5849609375, 13.32403278350830078, 5.545542716979980468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Zul'jarra (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+2, 213786, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4476.8349609375, -4912.71337890625, 13.44758033752441406, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+3, 211151, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4437.63623046875, -4914.20849609375, 14.64127731323242187, 5.729500293731689453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+4, 211149, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4475.705078125, -4907.26220703125, 13.49157619476318359, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+5, 211149, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4433.28466796875, -4923.51416015625, 14.78823280334472656, 1.828124880790710449, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+6, 254929, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4467.2255859375, -4894.455078125, 13.57268047332763671, 5.258516788482666015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Papa (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+7, 211152, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4440.2509765625, -4917.16650390625, 14.58111858367919921, 3.685639142990112304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+8, 211150, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4433.20654296875, -4915.392578125, 15.29960918426513671, 4.279088497161865234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+9, 255407, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4449.5205078125, -4925.291015625, 14.09206771850585937, 3.681848526000976562, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Gulpling (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+10, 254927, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4474.1474609375, -4897.76953125, 13.57105064392089843, 3.972083091735839843, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Fetid Roach (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+11, 211151, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4478.541015625, -4917.8818359375, 13.37950325012207031, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+12, 255827, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4449.09912109375, -4912.29541015625, 13.85124778747558593, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 472701 - Helper)
(@CGUID+13, 211111, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4434.58349609375, -4918.73291015625, 14.76352214813232421, 3.90152287483215332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+14, 211137, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4484.6630859375, -4908.6005859375, 13.30395793914794921, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+15, 255407, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4481.931640625, -4936.021484375, 13.06563472747802734, 3.101282358169555664, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Gulpling (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+16, 255407, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4464.86083984375, -4938.68505859375, 12.39996337890625, 1.00405287742614746, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Gulpling (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+17, 210930, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4477.38525390625, -4914.24462890625, 13.42934703826904296, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+18, 248897, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4480.892578125, -4911.9130859375, 13.34032630920410156, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ethereal Pyre (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+19, 254927, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4446.09619140625, -4916.6796875, 13.93190860748291015, 2.007129669189453125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Fetid Roach (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+20, 255407, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4474.4619140625, -4918.17138671875, 13.48775577545166015, 0.010216200724244117, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Gulpling (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+21, 254927, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4468.18798828125, -4927.39501953125, 13.55449676513671875, 2.450300931930541992, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Fetid Roach (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+22, 245139, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4618.7119140625, -4888.28125, -21.8822879791259765, 3.262831449508666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Stormbound Mystic (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+23, 245716, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4308.97998046875, -5178.6494140625, 100.17791748046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Barrel of Apples (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1279403 - [DNT] Lootable Offering Visual)
(@CGUID+24, 257419, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4330.251953125, -5025.93212890625, 100.42822265625, 2.2030792236328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Warding Incense (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+25, 210930, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4333.78564453125, -4955.4619140625, 103.3016738891601562, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+26, 255420, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4490.02001953125, -4891.142578125, 12.90264892578125, 3.758415460586547851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Sprocket (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+27, 248908, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4339.3359375, -4942.72412109375, 104.4021530151367187, 6.150688648223876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ethereal Pyre (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+28, 245638, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4219.08837890625, -5087.80029296875, 89.54437255859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Salmon Pool (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1239051 - Salmon Pool)
(@CGUID+29, 210930, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4304.49462890625, -4987.8369140625, 96.5413970947265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+30, 245139, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4817.939453125, -4869.314453125, -55.9288215637207031, 3.334614276885986328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Stormbound Mystic (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+31, 244889, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4316.54931640625, -4958.38525390625, 100.6486129760742187, 0.01468520238995552, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Loa Speaker Nanea (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1263952 - [DNT] Nanea Shoulders, 1247531 - Display Color Override, 1249100 - Burden of War, 1250975 - Ghostly Projection)
(@CGUID+32, 211151, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4302.09375, -4979.32666015625, 97.408599853515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+33, 261055, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4526.462890625, -4905.73974609375, 13.767913818359375, 3.141592741012573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ethereal Pyre (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+34, 210932, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4550.49853515625, -4902.86474609375, 13.72763824462890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+35, 211150, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4487.4775390625, -4915.517578125, 13.26296234130859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+36, 254924, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4341.3896484375, -5012.4912109375, 102.8901748657226562, 1.996457815170288085, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+37, 255407, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4478.92724609375, -4887.203125, 12.71645832061767578, 4.157253742218017578, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Gulpling (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+38, 245143, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4617.31591796875, -4894.09912109375, -21.8033332824707031, 3.28849959373474121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ruthless Totemcaller (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1250569 - Wear Helmet, 42459 - Dual Wield)
(@CGUID+39, 245716, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4115.5322265625, -5127.048828125, 104.6384658813476562, 5.971379756927490234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Barrel of Apples (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1279403 - [DNT] Lootable Offering Visual)
(@CGUID+40, 245139, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4859.12060546875, -4864.46728515625, -53.6967315673828125, 3.163949251174926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Stormbound Mystic (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+41, 254923, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4328.0078125, -4994.6875, 100.5382232666015625, 2.050176858901977539, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+42, 252041, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4305.54443359375, -5008.47900390625, 97.27301025390625, 1.577386021614074707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Satiated Avatar of Starvation (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 1254815 - Well Fed)
(@CGUID+43, 241813, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4347.0869140625, -5012.51025390625, 103.9473876953125, 0.64805692434310913, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+44, 211152, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4301.2412109375, -4974.033203125, 98.43219757080078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+45, 211149, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4296.41162109375, -4987.4375, 95.2532806396484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+46, 254927, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4549.12255859375, -4901.73779296875, 13.79124641418457031, 3.257672071456909179, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Fetid Roach (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+47, 211137, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4290.3046875, -4986.2568359375, 93.477813720703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+48, 244941, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4297.0078125, -4982.2587890625, 96.3289031982421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Berry Bush (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1239302 - Alluring Scent, 1279403 - [DNT] Lootable Offering Visual)
(@CGUID+49, 245716, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4348.29541015625, -5170.24658203125, 104.465484619140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Barrel of Apples (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1279403 - [DNT] Lootable Offering Visual)
(@CGUID+50, 245750, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4166.1875, -4971.96533203125, 93.03708648681640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Berry Bush (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1239302 - Alluring Scent, 1279403 - [DNT] Lootable Offering Visual)
(@CGUID+51, 245139, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4939.99462890625, -4854.51904296875, -32.7397537231445312, 3.163949251174926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Stormbound Mystic (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+52, 245146, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4934.5380859375, -4851.00537109375, -32.6845703125, 3.31565260887145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Grizzled Warbringer (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+53, 245146, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4777.251953125, -4874.1630859375, -38.994781494140625, 3.160244226455688476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Grizzled Warbringer (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+54, 210932, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4626.60498046875, -4894.27587890625, -23.0550651550292968, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+55, 241813, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4339.36181640625, -5022.92626953125, 101.5020523071289062, 1.28887641429901123, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+56, 245146, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4935.328125, -4859.43603515625, -32.6822471618652343, 3.31565260887145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Grizzled Warbringer (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+57, 211150, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4300.6162109375, -4984.21728515625, 96.2666778564453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+58, 254924, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4337.8017578125, -4995.2294921875, 102.7182159423828125, 1.107898116111755371, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+59, 210932, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4509.6962890625, -4908.15625, 13.42204666137695312, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+60, 211152, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4488.88818359375, -4905.3681640625, 13.27858448028564453, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+61, 213786, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4302.1640625, -4983.61279296875, 96.5389404296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+62, 245716, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4123.947265625, -5115.08349609375, 101.1563186645507812, 6.077584743499755859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Barrel of Apples (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1279403 - [DNT] Lootable Offering Visual)
(@CGUID+63, 245139, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4619.6337890625, -4899.13525390625, -21.8275947570800781, 3.163949251174926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Stormbound Mystic (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+64, 246409, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4957.33984375, -4844.56982421875, -23.4106006622314453, 6.021385669708251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Zul'jarra (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+65, 254927, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4649.22119140625, -4904.72900390625, -26.7110633850097656, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Fetid Roach (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+66, 254927, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4640.88525390625, -4863.93212890625, -28.6435375213623046, 2.541669845581054687, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Fetid Roach (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+67, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4276.720703125, -4987.51318359375, 88.53133392333984375, 1.162187099456787109, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+68, 245698, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4248.134765625, -5169.5068359375, 98.57867431640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Salmon Pool (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1239214 - Salmon Pool)
(@CGUID+69, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4202.27197265625, -5024.53515625, 87.772003173828125, 0.517398953437805175, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+70, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4314.9853515625, -5068.40087890625, 100.1189041137695312, 1.3554764986038208, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+71, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4159.67529296875, -4998.91650390625, 90.4255828857421875, 5.078410625457763671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+72, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4194.7890625, -4981.765625, 85.82221221923828125, 0.336734890937805175, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+73, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4238.6181640625, -4991.59716796875, 87.22705078125, 1.453580975532531738, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 18950 - Invisibility and Stealth Detection)
(@CGUID+74, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4297.47509765625, -5108.5009765625, 98.45742034912109375, 1.371822714805603027, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 18950 - Invisibility and Stealth Detection)
(@CGUID+75, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4194.78466796875, -5062.63525390625, 89.0661163330078125, 2.30993056297302246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+76, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4257.19873046875, -5047.56103515625, 99.497833251953125, 5.31028604507446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+77, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4193.353515625, -4986.76904296875, 86.2714691162109375, 0.721004664897918701, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+78, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4290.24560546875, -5045.375, 98.1533203125, 1.270578980445861816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+79, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4169.13916015625, -5021.7900390625, 88.11284637451171875, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+80, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4272.04443359375, -5002.78662109375, 86.61473846435546875, 3.722004890441894531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+81, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4259.25341796875, -4967.3837890625, 90.25521087646484375, 6.110576152801513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+82, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4163.8076171875, -4968.34375, 93.4427642822265625, 3.98015451431274414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+83, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4262.8681640625, -5003.30224609375, 85.98007965087890625, 5.090020179748535156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+84, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4311.2900390625, -5120.046875, 99.84200286865234375, 1.072675466537475585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+85, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4196.47216796875, -4986.28125, 86.011474609375, 0.727106869220733642, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1236801 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+86, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4238.31591796875, -5065.32470703125, 94.53623199462890625, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+87, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4153.71435546875, -5000.5244140625, 90.42510986328125, 6.055881977081298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+88, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4253.87841796875, -5072.59033203125, 99.197509765625, 0.917462170124053955, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 18950 - Invisibility and Stealth Detection)
(@CGUID+89, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4166.16748046875, -4997.205078125, 90.3368072509765625, 3.45103001594543457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+90, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4317.15283203125, -5064.7412109375, 100.36285400390625, 3.845853805541992187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+91, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4310.6728515625, -5035.890625, 98.8306884765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+92, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4261.97900390625, -5052.546875, 98.46916961669921875, 4.530139923095703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+93, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4259.73876953125, -4963.93603515625, 90.1566925048828125, 4.526015758514404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1236801 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+94, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4298.71728515625, -5129.1943359375, 99.0542449951171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+95, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4195.94287109375, -5067.8837890625, 89.83428955078125, 5.781849384307861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+96, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4209.4677734375, -4981.6025390625, 87.273193359375, 4.329421043395996093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+97, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4259.05126953125, -5051.41845703125, 98.8541717529296875, 4.189478397369384765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+98, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4299.31005859375, -5045.44287109375, 99.68535614013671875, 1.709743022918701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+99, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4193.19775390625, -5058.064453125, 88.56396484375, 5.054661273956298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+100, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4199.869140625, -5065.158203125, 88.92901611328125, 0.68765801191329956, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+101, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4160.27001953125, -5003.47021484375, 90.155120849609375, 5.966549873352050781, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+102, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4162.0634765625, -5003.6318359375, 90.08978271484375, 2.180411577224731445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+103, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4315.2646484375, -5121.43603515625, 100.1631927490234375, 1.813080549240112304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+104, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4323.880859375, -5132.380859375, 100.2061614990234375, 2.21068429946899414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+105, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4189.52001953125, -5060.6943359375, 88.67983245849609375, 5.539064407348632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+106, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4224.63720703125, -4996.95849609375, 85.7831573486328125, 2.532696723937988281, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+107, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4162.017578125, -4992.3349609375, 91.71701812744140625, 5.136224746704101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+108, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4258.3330078125, -4968.75, 89.977508544921875, 5.297764778137207031, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+109, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4298.2646484375, -5039.376953125, 100.1323165893554687, 4.859283447265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+110, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4211.77001953125, -5028.67724609375, 85.844818115234375, 6.196368217468261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+111, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4178.68603515625, -5021.0380859375, 87.4886932373046875, 2.971761703491210937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 18950 - Invisibility and Stealth Detection)
(@CGUID+112, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4315.2490234375, -5117.1181640625, 99.5706634521484375, 4.365396022796630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+113, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4319.96533203125, -5114.60400390625, 98.47939300537109375, 4.365396022796630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+114, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4300, -5079.166015625, 98.4610595703125, 0.846240162849426269, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+115, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4279.92724609375, -5090.98095703125, 103.9194183349609375, 1.305745720863342285, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+116, 247012, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4339.86181640625, -4931.36962890625, 105.6365966796875, 2.245645046234130859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Waystone (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1246125 - [DNT]Waystone Visual)
(@CGUID+117, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4167.89306640625, -5039.314453125, 89.98850250244140625, 2.809684038162231445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+118, 252041, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4328.01416015625, -5143.81787109375, 100.8490982055664062, 3.022559881210327148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Satiated Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 1254815 - Well Fed)
(@CGUID+119, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4163.9619140625, -5037.578125, 90.179046630859375, 5.614151954650878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+120, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4165.0244140625, -5041.68212890625, 90.390838623046875, 0.720505952835083007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+121, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4265.4765625, -5151.0712890625, 98.29998779296875, 3.345350027084350585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil)
(@CGUID+122, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4282.7509765625, -5157.26220703125, 99.46709442138671875, 4.187730789184570312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+123, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4344.4287109375, -5165.81591796875, 102.77386474609375, 1.948713898658752441, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+124, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4160.2490234375, -5041.203125, 90.23519134521484375, 1.589136958122253417, 7200, 0, 0, 0, NULL, 768, 1, 8193, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+125, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4180.13818359375, -5085.896484375, 93.126800537109375, 2.695410490036010742, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+126, 211152, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4350.9443359375, -5164.0556640625, 104.1047286987304687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+127, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4265.236328125, -5147.91845703125, 98.1591033935546875, 3.497744560241699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+128, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4350.87353515625, -5163.13916015625, 103.8205795288085937, 1.149100422859191894, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+129, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4191.93798828125, -5100.20751953125, 94.5496978759765625, 5.981145858764648437, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+130, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4339.7958984375, -5163.78662109375, 102.0494232177734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+131, 252041, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4186.77783203125, -5101.76416015625, 94.81771087646484375, 2.422978639602661132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Satiated Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 1254815 - Well Fed)
(@CGUID+132, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4307.88916015625, -5170.77587890625, 100.1666793823242187, 4.672759532928466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+133, 213786, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4345.759765625, -5167.73095703125, 103.20416259765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+134, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4312.87353515625, -5170.67529296875, 100.380218505859375, 3.129043817520141601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+135, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4166.99072265625, -5071.39404296875, 90.21814727783203125, 4.466759681701660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 18950 - Invisibility and Stealth Detection)
(@CGUID+136, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4350.337890625, -5170.330078125, 104.6348724365234375, 2.991391420364379882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+137, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4265.1787109375, -5154.048828125, 98.2900390625, 3.077419042587280273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+138, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4325.462890625, -5173.408203125, 101.100738525390625, 1.639182686805725097, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+139, 211150, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4343.9931640625, -5167.43408203125, 102.6626052856445312, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+140, 211151, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4345.0390625, -5172.484375, 102.963226318359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+141, 211137, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4353.6416015625, -5167.84716796875, 105.005218505859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+142, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4301.2724609375, -5171.79150390625, 100.4922256469726562, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+143, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4237.87060546875, -5151.1416015625, 100.427490234375, 6.076594829559326171, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+144, 211150, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4308.5244140625, -5174.0869140625, 100.2121124267578125, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+145, 211151, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4303.6318359375, -5175.126953125, 100.3645858764648437, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+146, 211152, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4313.87353515625, -5174.1025390625, 100.2881927490234375, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+147, 211149, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4348.66845703125, -5174.205078125, 104.2550048828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+148, 213786, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4307.70166015625, -5172.57275390625, 100.2204360961914062, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+149, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4216.642578125, -5141.15966796875, 98.96282958984375, 4.487066268920898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+150, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4214.22998046875, -5145.67529296875, 99.0020904541015625, 0.727836072444915771, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+151, 260195, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4308.90625, -5177.61279296875, 130.37884521484375, 1.803434610366821289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Magical Mountain Seagull (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+152, 213786, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4248.83056640625, -5170.0625, 98.0625457763671875, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+153, 211151, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4243.564453125, -5166.3525390625, 98.072998046875, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+154, 211150, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4253.43603515625, -5169.76025390625, 98.0625457763671875, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+155, 241816, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4218.79150390625, -5145.421875, 98.8695068359375, 2.964620351791381835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+156, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4161.5166015625, -5088.21728515625, 93.1201629638671875, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+157, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4216.11279296875, -5144.68408203125, 99.01770782470703125, 1.589136958122253417, 7200, 0, 0, 0, NULL, 768, 1, 8193, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+158, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4212.408203125, -5150.63720703125, 99.267364501953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+159, 211149, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4304.69287109375, -5179.001953125, 100.532989501953125, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+160, 211149, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4251.009765625, -5164.63916015625, 98.01171112060546875, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+161, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4306.97900390625, -5181.1630859375, 100.5985870361328125, 0.66098487377166748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+162, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4306.55712890625, -5177.673828125, 100.3314361572265625, 5.706905841827392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+163, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4248.94091796875, -5165.71533203125, 98.0565185546875, 4.667697906494140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State, 18950 - Invisibility and Stealth Detection)
(@CGUID+164, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4145.5068359375, -5071.82666015625, 94.671875, 5.885994911193847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+165, 211137, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4312.7568359375, -5178.61962890625, 100.4895858764648437, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+166, 245752, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4288.74462890625, -4958.48974609375, 118.754302978515625, 5.046964168548583984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Keen-Eyed Screecher (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+167, 211137, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4250.25, -5173.96337890625, 98.0738677978515625, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+168, 211152, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4245.2275390625, -5173.90478515625, 98.07555389404296875, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+169, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4186.89013671875, -5136.83251953125, 98.3038482666015625, 5.506074428558349609, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+170, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4138.30712890625, -5069.79345703125, 94.2024993896484375, 4.167443275451660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+171, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4143.49658203125, -5071.8369140625, 94.57928466796875, 0.226878955960273742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+172, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4244.36279296875, -5171, 98.0625457763671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+173, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4140.45654296875, -5079.7705078125, 95.1507568359375, 4.646525382995605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+174, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4218.986328125, -5170.55908203125, 99.88683319091796875, 0.860709130764007568, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+175, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4122.916015625, -5091.666015625, 100.3120803833007812, 6.172528266906738281, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+176, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4141.3037109375, -5103.34716796875, 96.84561920166015625, 2.149580955505371093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+177, 254923, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4181.25, -5158.333984375, 98.3612060546875, 1.723273277282714843, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Snake (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+178, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4159.970703125, -5153.546875, 99.6666717529296875, 5.014565944671630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+179, 211149, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4126.44970703125, -5116.783203125, 100.755767822265625, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+180, 245825, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4269.046875, -5209.73779296875, 110.0806961059570312, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- LT Offering Stalker (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+181, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4164.296875, -5158.2744140625, 98.47396087646484375, 0.36899694800376892, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+182, 257419, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4188.23291015625, -5175.63525390625, 101.3555068969726562, 0.772132396697998046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Warding Incense (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+183, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4160.77099609375, -5156.0087890625, 99.35590362548828125, 1.606670141220092773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+184, 211137, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4123.76025390625, -5111.12841796875, 100.9570159912109375, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+185, 213786, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4127.5380859375, -5115.28466796875, 100.56402587890625, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+186, 254924, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4141.576171875, -5139.302734375, 99.7413482666015625, 4.712388992309570312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 66838), -- Timid Treehopper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+187, 211150, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4126.158203125, -5113.47900390625, 100.69781494140625, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+188, 241809, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4167.27099609375, -5157.61474609375, 98.18576812744140625, 3.450577974319458007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Curious Yearling (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+189, 241808, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4164.86474609375, -5152.72216796875, 99.22570037841796875, 1.080504059791564941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Territorial Matriarch (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241219 - Matriarch's Vigil, 1236801 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+190, 241814, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4125.63037109375, -5127.359375, 102.47222900390625, 2.584401845932006835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Earthwhisper Tender (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+191, 210930, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4125.77978515625, -5125.02978515625, 101.9416122436523437, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+192, 241813, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4124.6962890625, -5121.02978515625, 100.9601287841796875, 3.3152313232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Thornclaw Gatherer (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1241217 - Shredding Claws)
(@CGUID+193, 211151, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4122.37158203125, -5118.408203125, 101.3485183715820312, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+194, 211152, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4119.55908203125, -5115.88720703125, 101.9957275390625, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+195, 245855, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4119.859375, -5124.17724609375, 103.0399322509765625, 0.164674967527389526, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit of Hunger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+196, 244041, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4267.2958984375, -5214.05712890625, 109.379364013671875, 3.883824825286865234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Meat Pile (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+197, 211151, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4116.2587890625, -5125.53662109375, 103.8976593017578125, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+198, 213786, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4117.65087890625, -5128.9443359375, 104.4093093872070312, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+199, 211150, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4116.080078125, -5129.7744140625, 104.8579788208007812, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+200, 211149, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4117.11181640625, -5127.59716796875, 104.2301788330078125, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+201, 211152, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4114.5166015625, -5124.2255859375, 104.3929824829101562, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+202, 211137, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4113.5224609375, -5129.81591796875, 104.935455322265625, 5.423309326171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Path Helper (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+203, 241805, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4259.126953125, -5245.3037109375, 109.0399322509765625, 3.45283055305480957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+204, 241805, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4232.71630859375, -5238.892578125, 109.0399322509765625, 5.085548877716064453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+205, 241805, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4254.1708984375, -5239.85791015625, 109.039093017578125, 4.085669517517089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+206, 241805, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4247.38916015625, -5236.91845703125, 109.0395584106445312, 4.72601175308227539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+207, 241805, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4239.6484375, -5236.54150390625, 109.0399322509765625, 4.894677162170410156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+208, 244061, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4212.3427734375, -5235.68603515625, 108.8611526489257812, 6.251031398773193359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Mushroom Pile (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+209, 241805, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4228.189453125, -5244.392578125, 109.0399322509765625, 5.614514827728271484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Avatar of Starvation (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1227959 - Mask State)
(@CGUID+210, 241812, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4242.38720703125, -5250.6494140625, 109.0399322509765625, 1.530134081840515136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- The Hoardmonger (Area: The Foraging - Difficulty: Normal) CreateObject1 (Auras: 1235414 - Display Color Override, 1236823 - [DNT] Cosmetic - Sleep Zzz, 422356 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+211, 244036, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 0, 0, 4266.3662109375, -5266.60791015625, 109.1284027099609375, 2.123056650161743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Bone Pile (Area: The Foraging - Difficulty: Normal) CreateObject1
(@CGUID+212, 245143, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4701.15966796875, -4922.6474609375, -10.0277271270751953, 1.901738762855529785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ruthless Totemcaller (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1250569 - Wear Helmet, 42459 - Dual Wield)
(@CGUID+213, 245190, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 4695.03662109375, -4886.84375, -26.3428077697753906, 3.199767827987670898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Loyal Saberfang (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+214, 245143, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4689.8193359375, -4849.26416015625, -10.0273609161376953, 4.01878976821899414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Ruthless Totemcaller (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1250569 - Wear Helmet, 42459 - Dual Wield)
(@CGUID+215, 245145, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 1, 4695.361328125, -4883.95654296875, -26.3762245178222656, 3.291513681411743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Bonded Beasttamer (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@CGUID+216, 246404, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 0, 0, 5015.9599609375, -4846, -23.4111995697021484, 3.281219005584716796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Nalorakk (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1 (Auras: 1243865 - Immune to Daze [DNT], 1281970 - [DNT] Disable VO, 1254622 - Watchful Gaze, 422362 - Bot AI Follow Advert)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+216;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, ''), -- Zul'jarra
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 4, ''), -- Stormbound Mystic
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 4, ''), -- Stormbound Mystic
(@CGUID+64, 0, 0, 0, 0, 0, 0, 0, 0, 27383, 0, 0, 4, ''), -- Zul'jarra
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '1241217'), -- Thornclaw Gatherer - 1241217 - Shredding Claws
(@CGUID+85, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1236801'), -- Curious Yearling - 1236801 - [DNT] Cosmetic - Sleep Zzz
(@CGUID+93, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1236801'), -- Keen-Eyed Screecher - 1236801 - [DNT] Cosmetic - Sleep Zzz
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Curious Yearling
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Earthwhisper Tender
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Curious Yearling
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- Timid Treehopper - 214567 - Mod Scale 90-110%
(@CGUID+106, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- Snake - 214567 - Mod Scale 90-110%
(@CGUID+108, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- Timid Treehopper - 214567 - Mod Scale 90-110%
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Earthwhisper Tender
(@CGUID+110, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Keen-Eyed Screecher
(@CGUID+112, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1241219'), -- Territorial Matriarch - 1241219 - Matriarch's Vigil
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Curious Yearling
(@CGUID+115, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Keen-Eyed Screecher
(@CGUID+120, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Curious Yearling
(@CGUID+123, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '1241217'), -- Thornclaw Gatherer - 1241217 - Shredding Claws
(@CGUID+124, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Territorial Matriarch
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Curious Yearling
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '1241217'), -- Thornclaw Gatherer - 1241217 - Shredding Claws
(@CGUID+132, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1241217'), -- Thornclaw Gatherer - 1241217 - Shredding Claws
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Curious Yearling
(@CGUID+149, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Keen-Eyed Screecher
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Keen-Eyed Screecher
(@CGUID+151, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Magical Mountain Seagull
(@CGUID+157, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Territorial Matriarch
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Earthwhisper Tender
(@CGUID+164, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '1241217'), -- Thornclaw Gatherer - 1241217 - Shredding Claws
(@CGUID+170, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Earthwhisper Tender
(@CGUID+171, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Earthwhisper Tender
(@CGUID+189, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1241219 1236801'), -- Territorial Matriarch - 1241219 - Matriarch's Vigil, 1236801 - [DNT] Cosmetic - Sleep Zzz
(@CGUID+190, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Earthwhisper Tender
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, '1241217'), -- Thornclaw Gatherer - 1241217 - Shredding Claws
(@CGUID+195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1227959'); -- Spirit of Hunger - 1227959 - Mask State

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 570512, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 4527.6708984375, -4905.71044921875, 13.63506698608398437, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 7200, 255, 1, 66838), -- Cave Door (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@OGUID+1, 616377, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 4480.689453125, -4912.03759765625, 13.36997413635253906, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 7200, 255, 1, 66838), -- Ethereal Pyre (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@OGUID+2, 252248, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 4410.66943359375, -4919.94091796875, 21.45351982116699218, 3.033326148986816406, 0, 0, 0.99853515625, 0.054106760770082473, 7200, 255, 1, 66838), -- Instance Portal (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@OGUID+3, 531150, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 4241.68603515625, -5284.25, 109.6128463745117187, 4.782205104827880859, 0, 0, -0.68199729919433593, 0.731354713439941406, 7200, 255, 1, 66838), -- Water Door (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@OGUID+4, 613266, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 4339.45068359375, -4942.67529296875, 103.9313735961914062, 3.070511341094970703, -0.03115701675415039, 0.004240036010742187, 0.998870849609375, 0.035613581538200378, 7200, 255, 1, 66838), -- Ethereal Pyre (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@OGUID+5, 581781, 2825, 16368, 16640, '1,2,8,23,205', '0', 0, 4954.72216796875, -4853.25537109375, -23.009073257446289, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 7200, 255, 0, 66838), -- Vine Door (Area: Dreamer's Passage - Difficulty: Normal) CreateObject1
(@OGUID+6, 531148, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 4248.20654296875, -5290.28662109375, 166.0091552734375, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 7200, 255, 1, 66838), -- Tunnel Waterfall (Area: The Foraging - Difficulty: Normal) CreateObject1
(@OGUID+7, 613253, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 4348.57568359375, -5170.421875, 104.0381927490234375, 3.149658918380737304, -0.15089941024780273, 0.045528411865234375, 0.98749542236328125, 0.003059073351323604, 7200, 255, 1, 66838), -- Barrel of Apples (Area: The Foraging - Difficulty: Normal) CreateObject1
(@OGUID+8, 613256, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 4309.0224609375, -5178.6474609375, 100.3107681274414062, 3.132735729217529296, -0.01547527313232421, 0.031268119812011718, 0.999379158020019531, 0.004913235083222389, 7200, 255, 1, 66838), -- Barrel of Apples (Area: The Foraging - Difficulty: Normal) CreateObject1
(@OGUID+9, 613262, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 4123.626953125, -5115.15087890625, 101.0173568725585937, 1.253117799758911132, 0.019550800323486328, 0.052631378173828125, 0.584254264831542968, 0.809626221656799316, 7200, 255, 1, 66838), -- Barrel of Apples (Area: The Foraging - Difficulty: Normal) CreateObject1
(@OGUID+10, 613254, 2825, 16368, 16388, '1,2,8,23,205', '0', 0, 4115.15625, -5127.47216796875, 104.2875289916992187, 0.174526706337928771, -0.09450769424438476, 0.078387260437011718, 0.094057083129882812, 0.987966120243072509, 7200, 255, 1, 66838); -- Barrel of Apples (Area: The Foraging - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.998134791851043701, -0.06104859709739685, 0, 0), -- Cave Door
(@OGUID+1, 0, 0, 0.998134791851043701, -0.06104859709739685, 0, 0); -- Ethereal Pyre

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (241812 /*241812 (The Hoardmonger) - Display Color Override, [DNT] Cosmetic - Sleep Zzz, Bot AI Follow Advert, Dual Wield*/, 241805 /*241805 (Avatar of Starvation) - Mask State*/, 260195 /*260195 (Magical Mountain Seagull)*/, 247012 /*247012 (Waystone) - [DNT]Waystone Visual*/, 241816 /*241816 (Keen-Eyed Screecher) - [DNT] Cosmetic - Sleep Zzz*/, 241809 /*241809 (Curious Yearling) - [DNT] Cosmetic - Sleep Zzz*/, 241808 /*241808 (Territorial Matriarch) - Matriarch's Vigil*/, 245855 /*245855 (Spirit of Hunger) - Mask State, Invisibility and Stealth Detection*/, 245698 /*245698 (Salmon Pool) - Salmon Pool*/, 249411 /*249411 (Loa Speaker Nanea) - Ride Vehicle Hardcoded*/, 245146 /*245146 (Grizzled Warbringer)*/, 245750 /*245750 (Berry Bush) - Alluring Scent, [DNT] Lootable Offering Visual*/, 244941 /*244941 (Berry Bush) - Alluring Scent, [DNT] Lootable Offering Visual*/, 241813 /*241813 (Thornclaw Gatherer) - Shredding Claws*/, 252041 /*252041 (Satiated Avatar of Starvation) - Mask State, Well Fed*/, 254923 /*254923 (Snake) - Mod Scale 90-110%*/, 245143 /*245143 (Ruthless Totemcaller) - Wear Helmet, Dual Wield*/, 254924 /*254924 (Timid Treehopper) - Mod Scale 90-110%*/, 244889 /*244889 (Loa Speaker Nanea) - [DNT] Nanea Shoulders, Display Color Override, Burden of War, Ghostly Projection*/, 245148 /*245148 (Grizzled Warbringer) - Ride Vehicle Hardcoded*/, 245638 /*245638 (Salmon Pool) - Salmon Pool*/, 255420 /*255420 (Sprocket) - Mod Scale 90-110%*/, 245716 /*245716 (Barrel of Apples) - [DNT] Lootable Offering Visual*/, 245139 /*245139 (Stormbound Mystic)*/, 255827 /*255827 (Helper) - Helper*/, 254927 /*254927 (Fetid Roach) - Mod Scale 90-110%*/, 255407 /*255407 (Gulpling) - Mod Scale 90-110%*/, 254929 /*254929 (Papa) - Mod Scale 90-110%*/, 246409 /*246409 (Zul'jarra)*/, 246404);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(241812, 0, 0, 0, 0, 0, 1, 0, 0, 22246, 0, 0, 0, '1235414 1236823 422356 42459'), -- 241812 (The Hoardmonger) - Display Color Override, [DNT] Cosmetic - Sleep Zzz, Bot AI Follow Advert, Dual Wield
(241805, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1227959'), -- 241805 (Avatar of Starvation) - Mask State
(260195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 260195 (Magical Mountain Seagull)
(247012, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1246125'), -- 247012 (Waystone) - [DNT]Waystone Visual
(241816, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 241816 (Keen-Eyed Screecher) - [DNT] Cosmetic - Sleep Zzz
(241809, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 241809 (Curious Yearling) - [DNT] Cosmetic - Sleep Zzz
(241808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1241219'), -- 241808 (Territorial Matriarch) - Matriarch's Vigil
(245855, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1227959 18950'), -- 245855 (Spirit of Hunger) - Mask State, Invisibility and Stealth Detection
(245698, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '1239214'), -- 245698 (Salmon Pool) - Salmon Pool
(249411, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 249411 (Loa Speaker Nanea) - Ride Vehicle Hardcoded
(245146, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 245146 (Grizzled Warbringer)
(245750, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1239302 1279403'), -- 245750 (Berry Bush) - Alluring Scent, [DNT] Lootable Offering Visual
(244941, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1239302 1279403'), -- 244941 (Berry Bush) - Alluring Scent, [DNT] Lootable Offering Visual
(241813, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1241217'), -- 241813 (Thornclaw Gatherer) - Shredding Claws
(252041, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1227959 1254815'), -- 252041 (Satiated Avatar of Starvation) - Mask State, Well Fed
(254923, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 254923 (Snake) - Mod Scale 90-110%
(245143, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1250569 42459'), -- 245143 (Ruthless Totemcaller) - Wear Helmet, Dual Wield
(254924, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 254924 (Timid Treehopper) - Mod Scale 90-110%
(244889, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1263952 1247531 1249100 1250975'), -- 244889 (Loa Speaker Nanea) - [DNT] Nanea Shoulders, Display Color Override, Burden of War, Ghostly Projection
(245148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 245148 (Grizzled Warbringer) - Ride Vehicle Hardcoded
(245638, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '1239051'), -- 245638 (Salmon Pool) - Salmon Pool
(255420, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 255420 (Sprocket) - Mod Scale 90-110%
(245716, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1279403'), -- 245716 (Barrel of Apples) - [DNT] Lootable Offering Visual
(245139, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 245139 (Stormbound Mystic)
(255827, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '472701'), -- 255827 (Helper) - Helper
(254927, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 254927 (Fetid Roach) - Mod Scale 90-110%
(255407, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 255407 (Gulpling) - Mod Scale 90-110%
(254929, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 254929 (Papa) - Mod Scale 90-110%
(246409, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, ''), -- 246409 (Zul'jarra)
(246404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1243865 1281970 1254622 422362'); -- 246404 (Nalorakk) - Immune to Daze [DNT], [DNT] Disable VO, Watchful Gaze, Bot AI Follow Advert

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (549042 /*Salmon Pool*/, 527975 /*Collision*/, 548681 /*Salmon Pool*/, 581781 /*Vine Door*/, 531150 /*Water Door*/, 570512 /*Cave Door*/, 531148);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(549042, 190, 0x0, 0, 0), -- Salmon Pool
(527975, 35, 0x800020, 0, 0), -- Collision
(548681, 190, 0x0, 0, 0), -- Salmon Pool
(581781, 0, 0x800030, 0, 0), -- Vine Door
(531150, 0, 0x30, 0, 0), -- Water Door
(570512, 0, 0x30, 0, 0), -- Cave Door
(531148, 0, 0x10, 0, 0); -- Tunnel Waterfall

-- Template
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40008001 WHERE `entry`=244036; -- Bone Pile
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x340 WHERE `entry`=241812; -- The Hoardmonger
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40008001 WHERE `entry`=244061; -- Mushroom Pile
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800 WHERE `entry`=241805; -- Avatar of Starvation
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x40008001 WHERE `entry`=244041; -- Meat Pile
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x8001, `flags_extra` = 128 WHERE `entry`=245825; -- LT Offering Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry` IN (245752, 241816); -- Keen-Eyed Screecher
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=260195; -- Magical Mountain Seagull
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41008001 WHERE `entry`=247012; -- Waystone
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=241814; -- Earthwhisper Tender
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=241808; -- Territorial Matriarch
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=245855; -- Spirit of Hunger
UPDATE `creature_template` SET `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=241809; -- Curious Yearling
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4000800, `unit_flags3`=0x41000001 WHERE `entry` IN (245698, 245638); -- Salmon Pool
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.60000002384185791, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x1080000 WHERE `entry`=250991; -- You
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000040, `unit_flags2`=0x4000000, `unit_flags3`=0x8001 WHERE `entry`=249411; -- Loa Speaker Nanea
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `VehicleId`=9015 WHERE `entry`=245146; -- Grizzled Warbringer
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4000800, `unit_flags3`=0x41000001 WHERE `entry` IN (245750, 244941); -- Berry Bush
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=241813; -- Thornclaw Gatherer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=252041; -- Satiated Avatar of Starvation
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=254923; -- Snake
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=245143; -- Ruthless Totemcaller
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=254924; -- Timid Treehopper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41008001 WHERE `entry` IN (261055, 248897); -- Ethereal Pyre
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x340, `VehicleId`=9091 WHERE `entry`=244889; -- Loa Speaker Nanea
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=245148; -- Grizzled Warbringer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4000800, `unit_flags3`=0x41008001 WHERE `entry`=248908; -- Ethereal Pyre
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=255420; -- Sprocket
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4000800, `unit_flags3`=0x41000001 WHERE `entry`=257419; -- Warding Incense
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4000800, `unit_flags3`=0x41008001 WHERE `entry`=245716; -- Barrel of Apples
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=245139; -- Stormbound Mystic
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000000, `unit_flags3`=0x41008001 WHERE `entry`=255827; -- Helper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=254927; -- Fetid Roach
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=255407; -- Gulpling
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=254929; -- Papa
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000000, `unit_flags3`=0x41008001, `flags_extra` = 128 WHERE `entry`=213786; -- Path Helper
UPDATE `creature_template` SET `faction`=1665, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=0x2000, `unit_flags3`=0x1 WHERE `entry`=246409; -- Zul'jarra
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x340 WHERE `entry`=246404; -- Nalorakk
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=245145; -- Bonded Beasttamer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=245190; -- Loyal Saberfang

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=244036 AND `DifficultyID`=0); -- 244036 (Bone Pile) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241812 AND `DifficultyID`=0); -- 241812 (The Hoardmonger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=244061 AND `DifficultyID`=0); -- 244061 (Mushroom Pile) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241805 AND `DifficultyID`=0); -- 241805 (Avatar of Starvation) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=244041 AND `DifficultyID`=0); -- 244041 (Meat Pile) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245825 AND `DifficultyID`=0); -- 245825 (LT Offering Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x30000000, `VerifiedBuild`=66838 WHERE (`Entry`=245752 AND `DifficultyID`=0); -- 245752 (Keen-Eyed Screecher) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=260195 AND `DifficultyID`=0); -- 260195 (Magical Mountain Seagull) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x20000100, `VerifiedBuild`=66838 WHERE (`Entry`=247012 AND `DifficultyID`=0); -- 247012 (Waystone) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241814 AND `DifficultyID`=0); -- 241814 (Earthwhisper Tender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241808 AND `DifficultyID`=0); -- 241808 (Territorial Matriarch) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245855 AND `DifficultyID`=0); -- 245855 (Spirit of Hunger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241809 AND `DifficultyID`=0); -- 241809 (Curious Yearling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241816 AND `DifficultyID`=0); -- 241816 (Keen-Eyed Screecher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=245698 AND `DifficultyID`=0); -- 245698 (Salmon Pool) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=250991 AND `DifficultyID`=0); -- 250991 (You) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3906, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=249411 AND `DifficultyID`=0); -- 249411 (Loa Speaker Nanea) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245146 AND `DifficultyID`=0); -- 245146 (Grizzled Warbringer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=245750 AND `DifficultyID`=0); -- 245750 (Berry Bush) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=244941 AND `DifficultyID`=0); -- 244941 (Berry Bush) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=241813 AND `DifficultyID`=0); -- 241813 (Thornclaw Gatherer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=252041 AND `DifficultyID`=0); -- 252041 (Satiated Avatar of Starvation) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=66838 WHERE (`Entry`=254923 AND `DifficultyID`=0); -- 254923 (Snake) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245143 AND `DifficultyID`=0); -- 245143 (Ruthless Totemcaller) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=66838 WHERE (`Entry`=254924 AND `DifficultyID`=0); -- 254924 (Timid Treehopper) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=210932 AND `DifficultyID`=0); -- 210932 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=261055 AND `DifficultyID`=0); -- 261055 (Ethereal Pyre) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=244889 AND `DifficultyID`=0); -- 244889 (Loa Speaker Nanea) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=245148 AND `DifficultyID`=0); -- 245148 (Grizzled Warbringer) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=245638 AND `DifficultyID`=0); -- 245638 (Salmon Pool) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=248908 AND `DifficultyID`=0); -- 248908 (Ethereal Pyre) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=66838 WHERE (`Entry`=255420 AND `DifficultyID`=0); -- 255420 (Sprocket) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=257419 AND `DifficultyID`=0); -- 257419 (Warding Incense) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=245716 AND `DifficultyID`=0); -- 245716 (Barrel of Apples) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245139 AND `DifficultyID`=0); -- 245139 (Stormbound Mystic) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=66838 WHERE (`Entry`=248897 AND `DifficultyID`=0); -- 248897 (Ethereal Pyre) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=66838 WHERE (`DifficultyID`=1 AND `Entry` IN (210930,213786));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=211111 AND `DifficultyID`=1); -- 211111 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x30000100, `VerifiedBuild`=66838 WHERE (`Entry`=255827 AND `DifficultyID`=0); -- 255827 (Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=66838 WHERE (`Entry`=254927 AND `DifficultyID`=0); -- 254927 (Fetid Roach) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=66838 WHERE (`Entry`=255407 AND `DifficultyID`=0); -- 255407 (Gulpling) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=211150 AND `DifficultyID`=1); -- 211150 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=211152 AND `DifficultyID`=1); -- 211152 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=66838 WHERE (`Entry`=254929 AND `DifficultyID`=0); -- 254929 (Papa) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=211149 AND `DifficultyID`=1); -- 211149 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=211151 AND `DifficultyID`=1); -- 211151 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=246409 AND `DifficultyID`=0); -- 246409 (Zul'jarra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2940, `VerifiedBuild`=66838 WHERE (`Entry`=211137 AND `DifficultyID`=1); -- 211137 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=246404 AND `DifficultyID`=0); -- 246404 (Nalorakk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245145 AND `DifficultyID`=0); -- 245145 (Bonded Beasttamer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3906, `StaticFlags1`=0x10000000, `VerifiedBuild`=66838 WHERE (`Entry`=245190 AND `DifficultyID`=0); -- 245190 (Loyal Saberfang) - CanSwim

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 294690, 0, 0, 0, 0, 0, 0, 0, 66838); -- 616377 (Ethereal Pyre)

DELETE FROM `gossip_menu` WHERE (`MenuID`=40087 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40087, @NPCTEXTID+0, 66838); -- 616377 (Ethereal Pyre)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=40087 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(40087, 135009, 0, 0, '<Meditate on the sound of the flames.>', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838);

DELETE FROM `gossip_menu` WHERE (`MenuID`=40088 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40088, @NPCTEXTID+0, 66838); -- 613266 (Ethereal Pyre)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=40088 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(40088, 135010, 0, 0, '<Meditate on the sound of the flames.>', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 66838);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry` IN (245146,244889)) OR (`entry`=249280 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(245146, 245148, 0, 0, 'Grizzled Warbringer - Grizzled Warbringer', 8, 0), -- Grizzled Warbringer - Grizzled Warbringer
(244889, 249411, 0, 1, 'Loa Speaker Nanea - Loa Speaker Nanea', 8, 0), -- Loa Speaker Nanea - Loa Speaker Nanea
(249280, 256995, 0, 1, 'En\'liahn - En\'liahn', 8, 0); -- En'liahn - En'liahn

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (245716,245638,244941,245750,245698,245146,249280);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(245716, 1239300, 1, 0),
(245638, 1239040, 1, 0),
(244941, 1239001, 1, 0),
(245750, 1239001, 1, 0),
(245698, 1239227, 1, 0),
(245146, 46598, 1, 0),
(249280, 46598, 1, 0);

-- Path for Spirit of Hunger
SET @MOVERGUID := @CGUID+74;
SET @ENTRY := 245855;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Spirit of Hunger - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4300.1206, -5077.9966, 98.46927, NULL, 0),
(@PATH, 1, 4308.752, -5053.174, 98.51996, NULL, 0),
(@PATH, 2, 4316.5454, -5015.401, 98.19628, NULL, 5482),
(@PATH, 3, 4308.752, -5053.174, 98.51996, NULL, 0),
(@PATH, 4, 4300.1206, -5077.9966, 98.46927, NULL, 0),
(@PATH, 5, 4300.3267, -5094.3594, 98.391304, NULL, 0),
(@PATH, 6, 4296.2725, -5114.4653, 98.485306, NULL, 0),
(@PATH, 7, 4299.4966, -5130.5957, 98.92946, NULL, 5017),
(@PATH, 8, 4296.2725, -5114.4653, 98.485306, NULL, 0),
(@PATH, 9, 4300.3267, -5094.3594, 98.391304, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1227959 18950');

-- Path for Spirit of Hunger
SET @MOVERGUID := @CGUID+135;
SET @ENTRY := 245855;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Spirit of Hunger - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4161.4272, -5116.4966, 95.84447, NULL, 0),
(@PATH, 1, 4167.5845, -5133.1772, 97.36687, NULL, 0),
(@PATH, 2, 4194.3193, -5151.53, 98.306915, NULL, 5274),
(@PATH, 3, 4167.5845, -5133.1772, 97.36687, NULL, 0),
(@PATH, 4, 4161.4272, -5116.4966, 95.84447, NULL, 0),
(@PATH, 5, 4162.1294, -5090.8145, 93.3008, NULL, 0),
(@PATH, 6, 4166.9907, -5071.394, 90.21815, NULL, 5261),
(@PATH, 7, 4162.127, -5090.8086, 93.3236, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1227959 18950');

-- Path for Thornclaw Gatherer
SET @MOVERGUID := @CGUID+55;
SET @ENTRY := 241813;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Thornclaw Gatherer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4338.541, -5024.672, 100.87391, NULL, 6747),
(@PATH, 1, 4340.8066, -5017.9307, 102.55328, NULL, 1896);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1241217');

-- Path for Thornclaw Gatherer
SET @MOVERGUID := @CGUID+43;
SET @ENTRY := 241813;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Thornclaw Gatherer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4342.5903, -5015.9165, 103.055984, NULL, 1356),
(@PATH, 1, 4347.087, -5012.5103, 103.94739, NULL, 5013);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1241217');

-- Path for Thornclaw Gatherer
SET @MOVERGUID := @CGUID+78;
SET @ENTRY := 241813;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Thornclaw Gatherer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4296.9434, -5043.1855, 99.66165, NULL, 3319),
(@PATH, 1, 4290.2456, -5045.375, 98.15332, 1.27057, 5768);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1241217');

-- Path for Thornclaw Gatherer
SET @MOVERGUID := @CGUID+128;
SET @ENTRY := 241813;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Thornclaw Gatherer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4348.8003, -5167.7603, 103.923935, NULL, 1831),
(@PATH, 1, 4351.9106, -5160.8335, 104.07092, 1.1491, 4247);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1241217');

-- Path for Thornclaw Gatherer
SET @MOVERGUID := @CGUID+173;
SET @ENTRY := 241813;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Thornclaw Gatherer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4138.3813, -5073.7153, 94.83013, NULL, 4119),
(@PATH, 1, 4140.5234, -5078.759, 95.05564, NULL, 0),
(@PATH, 2, 4139.3066, -5081.6235, 95.50525, NULL, 4962);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1241217');
