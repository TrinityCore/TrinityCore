SET @CGUID := 10002295;
SET @OGUID := 10000567;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+281;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 216088, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2659.6884765625, -4854.81787109375, 99.5995330810546875, 2.484215736389160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Wenbrandt (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 437154 - [DNT] Beat Up) (possible waypoints or random movement)
(@CGUID+1, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2685.833740234375, -4871.96337890625, 99.66069793701171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+2, 211137, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2651.94091796875, -4853.99853515625, 99.93251800537109375, 4.841020107269287109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+3, 211149, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2646.411376953125, -4851.88916015625, 99.5995330810546875, 4.823210716247558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+4, 211151, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2648.10498046875, -4847.6650390625, 99.5995330810546875, 4.850669384002685546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+5, 211150, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2655.60498046875, -4850.048828125, 99.5995330810546875, 5.033595561981201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+6, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2659.393798828125, -4856.9052734375, 99.925079345703125, 2.757639646530151367, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!)
(@CGUID+7, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2627.9228515625, -4895.5625, 99.79264068603515625, 2.580692529678344726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+8, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2637.201416015625, -4845.84765625, 99.683380126953125, 4.318947792053222656, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2692.593994140625, -4871.96337890625, 99.66069793701171875, 3.141592741012573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 441408 - Thirsty)
(@CGUID+10, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2626.3203125, -4891.86962890625, 99.79264068603515625, 5.250285148620605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+11, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2685.833740234375, -4870.96337890625, 99.66069793701171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+12, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2669.333984375, -4894.14208984375, 99.71082305908203125, 5.034189224243164062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 440682 - [DNT] Holding Mug, 422355 - Bot AI Follow Advert, 441408 - Thirsty)
(@CGUID+13, 210269, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2671.775390625, -4893.671875, 99.71082305908203125, 4.796164512634277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Hired Muscle (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422354 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection, 441408 - Thirsty)
(@CGUID+14, 213839, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2650.9599609375, -4851.990234375, 99.91973876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 428569 - Passive, 413569 - Bot AI Follow Advert)
(@CGUID+15, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2628.6103515625, -4893.1806640625, 99.79264068603515625, 3.311147689819335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+16, 211152, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2657.654541015625, -4845.05908203125, 99.5995330810546875, 5.272263526916503906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+17, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2625.6484375, -4894.625, 99.80821990966796875, 0.720699310302734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+18, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2665.54248046875, -4870.96337890625, 99.6529998779296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+19, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2606.671875, -4886.384765625, 99.71669769287109375, 0.203732743859291076, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 440682 - [DNT] Holding Mug)
(@CGUID+20, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2606.96240234375, -4889.091796875, 99.71669769287109375, 6.177661895751953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+21, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2683.072998046875, -4901.6796875, 99.71082305908203125, 4.600342750549316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert, 440682 - [DNT] Holding Mug)
(@CGUID+22, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2672.302490234375, -4870.96337890625, 99.6529998779296875, 3.141592741012573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+23, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2626.66064453125, -4874.5224609375, 100.032257080078125, 3.158909559249877929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+24, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2680.586669921875, -4901.666015625, 99.71082305908203125, 4.838365077972412109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+25, 214920, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2688.34716796875, -4896.9853515625, 99.80399322509765625, 2.301241159439086914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Tasting Room Attendant (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 434685 - [DNT] Drink Tray)
(@CGUID+26, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2614.267578125, -4885.98779296875, 99.71669769287109375, 3.34533095359802246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+27, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2672.08935546875, -4898.92919921875, 99.71082305908203125, 1.966275334358215332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 440682 - [DNT] Holding Mug)
(@CGUID+28, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2614.41845703125, -4889.091796875, 99.71669769287109375, 3.03603982925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+29, 214920, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2646.880859375, -4903.2255859375, 99.80399322509765625, 0.246466234326362609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Tasting Room Attendant (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 434685 - [DNT] Drink Tray)
(@CGUID+30, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2661.9775390625, -4912.03662109375, 99.79264068603515625, 0.240367859601974487, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert, 441408 - Thirsty)
(@CGUID+31, 210269, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2682.0703125, -4908.35400390625, 99.8040008544921875, 1.517481684684753417, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Hired Muscle (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422354 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection)
(@CGUID+32, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2672.3056640625, -4882.73828125, 99.71082305908203125, 4.600342750549316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+33, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2614.21142578125, -4872.26171875, 99.803985595703125, 2.85126495361328125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!)
(@CGUID+34, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2622.983642578125, -4877.2724609375, 99.79264068603515625, 1.486586570739746093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+35, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2665.192626953125, -4910.140625, 99.79264068603515625, 4.015634059906005859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+36, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2683.03466796875, -4906.8671875, 99.71082305908203125, 1.770452857017517089, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+37, 210269, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2646.077392578125, -4914.86962890625, 99.79264068603515625, 4.33263397216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Hired Muscle (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422354 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection)
(@CGUID+38, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2679.75927734375, -4871.17041015625, 99.8040008544921875, 6.15808725357055664, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!)
(@CGUID+39, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2620.912353515625, -4874.38037109375, 100.03704833984375, 0.162603557109832763, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+40, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2665.944580078125, -4913.1962890625, 99.79264068603515625, 3.194735527038574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert, 441408 - Thirsty)
(@CGUID+41, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2671.5908203125, -4887.95654296875, 99.71082305908203125, 1.770452857017517089, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+42, 210269, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2680.05419921875, -4908.5830078125, 99.8040008544921875, 1.513911843299865722, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Hired Muscle (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422354 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection)
(@CGUID+43, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2669.272216796875, -4888.11279296875, 99.71082305908203125, 1.379362940788269042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+44, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2619.537353515625, -4910.1162109375, 99.79264068603515625, 4.015634059906005859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+45, 214920, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2617.421142578125, -4915.15087890625, 99.79264068603515625, 0.964332759380340576, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Tasting Room Attendant (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 434685 - [DNT] Drink Tray)
(@CGUID+46, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2643.885498046875, -4901.38037109375, 99.792633056640625, 3.4289703369140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+47, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2718.489501953125, -4880.33251953125, 103.0071258544921875, 0.692324638366699218, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 454194 - Carry Crates) (possible waypoints or random movement)
(@CGUID+48, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2721.2275390625, -4884.04541015625, 102.0784988403320312, 3.277445793151855468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames)
(@CGUID+49, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2696.280029296875, -4899.0458984375, 99.6567230224609375, 4.712389945983886718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+50, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2697.280029296875, -4899.0458984375, 99.6567230224609375, 4.712389945983886718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+51, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2642.376708984375, -4915.1962890625, 99.79264068603515625, 0.503288447856903076, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+52, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2678.1015625, -4887.42822265625, 99.71082305908203125, 0.203732743859291076, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+53, 219415, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2693.0322265625, -4889.91845703125, 100.8405685424804687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cooking Pot (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 439179 - [DNT] Cooking Pot)
(@CGUID+54, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2697.280029296875, -4881.2646484375, 99.67913818359375, 1.570795774459838867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+55, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2644.708251953125, -4917.796875, 99.79264068603515625, 1.227253317832946777, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+56, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2696.280029296875, -4905.80615234375, 99.6567230224609375, 1.570795774459838867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 440682 - [DNT] Holding Mug)
(@CGUID+57, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2684.809326171875, -4890.13525390625, 99.71082305908203125, 3.03603982925415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+58, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2643.11376953125, -4903.59033203125, 99.792633056640625, 2.2566070556640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+59, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2678.0751953125, -4889.8994140625, 99.71082305908203125, 6.177661895751953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+60, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2641.5078125, -4900.72216796875, 99.792633056640625, 5.543485641479492187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+61, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2696.280029296875, -4874.50439453125, 99.67913818359375, 4.712389945983886718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+62, 214668, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2616.322021484375, -4912.01220703125, 99.79264068603515625, 0.240367859601974487, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422355 - Bot AI Follow Advert)
(@CGUID+63, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2696.280029296875, -4881.2646484375, 99.67913818359375, 1.570795774459838867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+64, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2718.42529296875, -4887.40283203125, 102.9345779418945312, 1.618943095207214355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+65, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2737.295166015625, -4884.0087890625, 102.9238052368164062, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+66, 214697, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2661.95068359375, -4942.24267578125, 99.8040008544921875, 4.249289512634277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Chef Chewie (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 434743 - Compliments of the Chef, 422354 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection)
(@CGUID+67, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2684.190185546875, -4931.2412109375, 99.9157257080078125, 2.996589899063110351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+68, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2581.62060546875, -4928.90283203125, 99.7878875732421875, 2.938131332397460937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+69, 210933, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2649.049560546875, -4941.5087890625, 99.79264068603515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+70, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2681.068603515625, -4930.20654296875, 99.9157257080078125, 0.000283360335743054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+71, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2581.7890625, -4920.47900390625, 99.7878875732421875, 3.371717453002929687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+72, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2693.83984375, -4911.71044921875, 99.8040008544921875, 2.130848407745361328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+73, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2627.12060546875, -4923.1474609375, 99.9157257080078125, 2.996589899063110351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk)
(@CGUID+74, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2633.04931640625, -4936.69287109375, 99.803985595703125, 5.466128826141357421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+75, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2716.7197265625, -4898.84228515625, 103.0899124145507812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+76, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2684.108642578125, -4929.02587890625, 99.9157257080078125, 2.996589899063110351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+77, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2627.202392578125, -4925.36279296875, 99.9157257080078125, 2.996589899063110351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk)
(@CGUID+78, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2695.44970703125, -4928.939453125, 99.79280853271484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+79, 210271, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2656.927001953125, -4952.91162109375, 99.80399322509765625, 1.543931484222412109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Brew Master Aldryr (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422356 - Bot AI Follow Advert, 440682 - [DNT] Holding Mug)
(@CGUID+80, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2605.504638671875, -4903.62646484375, 99.8040008544921875, 1.604737043380737304, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!)
(@CGUID+81, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2624.080810546875, -4924.328125, 99.9157257080078125, 0.000283360335743054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk)
(@CGUID+82, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2763.794189453125, -4895.25537109375, 102.3919143676757812, 3.312439680099487304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames)
(@CGUID+83, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2760.3056640625, -4894.9912109375, 103.31878662109375, 3.936847686767578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 384670 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+84, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2565.47607421875, -4936.83935546875, 99.96250152587890625, 3.628978967666625976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+85, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2717.343017578125, -4925.5693359375, 99.7864990234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+86, 210933, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2636.01220703125, -4943.8662109375, 99.79264068603515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+87, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2655.666748046875, -4947.0185546875, 99.6858367919921875, 4.367510795593261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+88, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2718.686279296875, -4937.9287109375, 99.80399322509765625, 3.627507686614990234, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2574.0703125, -4924.861328125, 99.7878875732421875, 0.015015434473752975, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+90, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2761.7890625, -4884.4775390625, 103.0071182250976562, 1.269869089126586914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 287319 - Carry Crate) (possible waypoints or random movement)
(@CGUID+91, 222889, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2753.80908203125, -4916.53466796875, 99.95145416259765625, 4.748180866241455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+92, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2662.500244140625, -4948.44140625, 99.6858367919921875, 3.97467660903930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+93, 210933, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2621.142333984375, -4946.26416015625, 99.79264068603515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+94, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2563.73779296875, -4933.96630859375, 99.848541259765625, 6.260149478912353515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+95, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2642.693603515625, -4946.93798828125, 99.6858367919921875, 4.712389945983886718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+96, 210932, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2588.51904296875, -4925.46533203125, 99.7878875732421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+97, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2579.841064453125, -4958.5322265625, 99.36309814453125, 5.891296863555908203, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+98, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2758.78759765625, -4925.02685546875, 99.8832855224609375, 0.208399698138236999, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+99, 219667, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2719.7744140625, -4939.98291015625, 99.7864990234375, 0.789694368839263916, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flamethrower (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 439603 - [DNT] Flamethrower Visual)
(@CGUID+100, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2722.9619140625, -4957.38525390625, 99.80040740966796875, 2.291218757629394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+101, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2540.760498046875, -4917.63525390625, 99.7878875732421875, 3.422780990600585937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+102, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2718.08154296875, -4957.1025390625, 99.80040740966796875, 1.33762216567993164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+103, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2759.162841796875, -4925.29345703125, 99.87985992431640625, 6.171475410461425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+104, 218523, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2651.154541015625, -4977.3994140625, 110.5240631103515625, 1.57137000560760498, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Goldie Baronbottom (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 437208 - [DNT] Spotlight On Me)
(@CGUID+105, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2716.621337890625, -4953.4443359375, 99.85594940185546875, 2.575342893600463867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+106, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2758.991455078125, -4923.17138671875, 99.8961181640625, 6.102622032165527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+107, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2619.057373046875, -4959.64111328125, 99.8040008544921875, 3.699333906173706054, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+108, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2557.470458984375, -4930.2587890625, 99.803985595703125, 4.772984504699707031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+109, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2596.590087890625, -4956.28759765625, 99.60086822509765625, 3.670204877853393554, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+110, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2720.702392578125, -4951.87158203125, 99.80040740966796875, 5.078343391418457031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 384670 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+111, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2764.150146484375, -4886.2880859375, 102.9238128662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+112, 210933, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2604.606689453125, -4956.2412109375, 99.85910797119140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+113, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2536.1650390625, -4913.58349609375, 99.975372314453125, 3.044617652893066406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+114, 220946, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2547.242431640625, -4924.7998046875, 99.86749267578125, 3.128467082977294921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Honey Harvester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+115, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2587.852783203125, -4980.95703125, 98.1444091796875, 1.012022137641906738, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+116, 222951, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2761.552978515625, -4935.6181640625, 102.7654953002929687, 4.425432205200195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- I'pa (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+117, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2572.905517578125, -4961.373046875, 99.37677001953125, 5.233235359191894531, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+118, 222964, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2762.520751953125, -4924.005859375, 99.81816864013671875, 6.277856349945068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames) (possible waypoints or random movement)
(@CGUID+119, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2570.21875, -4957.44140625, 99.69341278076171875, 2.506124019622802734, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+120, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2592.612060546875, -4986.18798828125, 98.02944183349609375, 4.784493446350097656, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+121, 223423, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2723.389892578125, -4962.33154296875, 99.8040008544921875, 3.115553140640258789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Careless Hopgoblin (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448943 - Carry Cinderbrew Barrel, 449106 - Delicate Brew Barrel, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+122, 222889, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2769.4375, -4916.50537109375, 99.8937225341796875, 4.748180866241455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+123, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2574.85693359375, -4957.43505859375, 100.35888671875, 1.257797956466674804, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+124, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2593.294677734375, -4984.02392578125, 98.016082763671875, 6.243724346160888671, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+125, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2535.772705078125, -4922.0869140625, 99.8040008544921875, 4.460120677947998046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+126, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2595.173828125, -4975.14306640625, 123.427886962890625, 5.939889907836914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+127, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2572.469970703125, -4961.48388671875, 99.54022979736328125, 3.169167995452880859, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+128, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2590.290771484375, -4982.494140625, 98.86016845703125, 3.300658226013183593, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+129, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2577.0869140625, -4959.607421875, 99.81980133056640625, 5.519060611724853515, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+130, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2774.26806640625, -4895.52880859375, 103.3977432250976562, 3.628606796264648437, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+131, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2577.952392578125, -4963.072265625, 100.1974334716796875, 0.338222861289978027, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+132, 210933, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2592.3525390625, -4965.984375, 99.58905029296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+133, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2750.777099609375, -4946.59716796875, 99.80399322509765625, 1.24135136604309082, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+134, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2769.538330078125, -4940.50537109375, 99.80040740966796875, 5.623977184295654296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+135, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2576.60693359375, -4961.658203125, 99.397735595703125, 3.085184335708618164, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+136, 223423, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2783.6025390625, -4886.06494140625, 103.0071258544921875, 6.240266323089599609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Careless Hopgoblin (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448943 - Carry Cinderbrew Barrel, 449106 - Delicate Brew Barrel, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+137, 222889, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2744.44091796875, -4943.77587890625, 103.58990478515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+138, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2753.465576171875, -4937.86279296875, 99.80399322509765625, 1.423642277717590332, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+139, 222964, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2751.447998046875, -4943.14599609375, 98.80040740966796875, 2.931279659271240234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames, 447046 - Secret Ingredient)
(@CGUID+140, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2709.2109375, -4990.95166015625, 99.80040740966796875, 3.695897579193115234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+141, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2592.05322265625, -4988.197265625, 122.8216323852539062, 3.800265073776245117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2757.50439453125, -4972.77099609375, 99.80040740966796875, 1.26476287841796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+143, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2507.58642578125, -4926.49267578125, 104.1842269897460937, 3.742911577224731445, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+144, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2789.764892578125, -4886.43603515625, 102.9238052368164062, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+145, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2774.63232421875, -4939.650390625, 99.8040008544921875, 2.536336421966552734, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+146, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2810.626708984375, -4886.80224609375, 102.9238128662109375, 1.037985086441040039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+147, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2509.885009765625, -4927.29833984375, 102.1674728393554687, 4.6785736083984375, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+148, 210933, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2583.48095703125, -4982.46875, 96.91094970703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+149, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2520.368896484375, -4943.5224609375, 99.8643646240234375, 3.13609170913696289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+150, 210932, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2524.072998046875, -4924.8837890625, 99.7878875732421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+151, 222964, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2772.5166015625, -4943.44287109375, 98.80040740966796875, 0.0002284992224304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames, 447046 - Secret Ingredient)
(@CGUID+152, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2590.521240234375, -4978.29248046875, 116.2449417114257812, 0.366606384515762329, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+153, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2759.001708984375, -4967.50537109375, 98.80040740966796875, 4.934018135070800781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+154, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2762.157958984375, -4968.87841796875, 99.80040740966796875, 4.10095071792602539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+155, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2713.283935546875, -4991.4375, 99.80040740966796875, 4.351012229919433593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+156, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2755.944580078125, -4969.2724609375, 99.80040740966796875, 6.260754108428955078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+157, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2514.350341796875, -4924.8671875, 104.1631927490234375, 2.162421703338623046, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+158, 222889, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2778.3125, -4943.94970703125, 103.9578475952148437, 3.27102971076965332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+159, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2511.076416015625, -4919.99462890625, 101.8501434326171875, 5.804408550262451171, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+160, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2512.003662109375, -4913.92041015625, 99.80980682373046875, 0.473218470811843872, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+161, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2589.614990234375, -4985.25048828125, 98.051300048828125, 4.078449726104736328, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+162, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2717.341064453125, -4994.06787109375, 99.80040740966796875, 5.534435272216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+163, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2715.26220703125, -4987.74853515625, 98.80040740966796875, 4.081566810607910156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames)
(@CGUID+164, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2771.641357421875, -4925.525390625, 99.803985595703125, 5.238902091979980468, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+165, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2506.632080078125, -4947.19287109375, 99.7878875732421875, 5.096068382263183593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+166, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2812.560791015625, -4884.1474609375, 102.94952392578125, 0.657255887985229492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+167, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2547.607666015625, -4964.484375, 121.617095947265625, 3.183805465698242187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+168, 218002, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2569.6328125, -5007.70166015625, 97.02895355224609375, 3.217099189758300781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Benk Buzzbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422362 - Bot AI Follow Advert)
(@CGUID+169, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2807.396728515625, -4909.3681640625, 99.807861328125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+170, 225633, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2743.28466796875, -5001.2255859375, 103.7865524291992187, 0.89211583137512207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+171, 219667, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2507.5322265625, -4914.8193359375, 99.7878875732421875, 0.789694368839263916, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flamethrower (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 439603 - [DNT] Flamethrower Visual)
(@CGUID+172, 210270, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2748.35400390625, -4993.111328125, 99.83221435546875, 0.353370159864425659, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Brew Drop (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 422358 - Bot AI Follow Advert) (possible waypoints or random movement)
(@CGUID+173, 225633, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2724.65185546875, -5000.7822265625, 104.0402908325195312, 6.266391754150390625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+174, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2816.903076171875, -4884.7802734375, 103.0692977905273437, 1.470647454261779785, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+175, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2505.0947265625, -4923.65625, 101.3788375854492187, 3.062983512878417968, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+176, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2746.483642578125, -4995.55224609375, 99.80040740966796875, 4.438020706176757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+177, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2814.271728515625, -4881.41650390625, 101.9446182250976562, 4.299724102020263671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames)
(@CGUID+178, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2715.5576171875, -4993.9873046875, 99.8040008544921875, 5.633607387542724609, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+179, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2521.072265625, -4949.60888671875, 99.78984832763671875, 2.285863876342773437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+180, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2589.70654296875, -4996.68896484375, 119.878265380859375, 1.708658218383789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+181, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2508.616455078125, -4951.55029296875, 99.7878875732421875, 2.166010618209838867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+182, 223423, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2747.4287109375, -4989.36767578125, 99.8048858642578125, 0.382497131824493408, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Careless Hopgoblin (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448943 - Carry Cinderbrew Barrel, 449106 - Delicate Brew Barrel, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+183, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2815.1259765625, -4886.49658203125, 101.9345779418945312, 2.434707164764404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames)
(@CGUID+184, 220946, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2514.34423828125, -4943.818359375, 99.85422515869140625, 1.578667759895324707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Honey Harvester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+185, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2753.138916015625, -4993.158203125, 99.80040740966796875, 5.201746940612792968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+186, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2516.76806640625, -4945.20458984375, 99.82872772216796875, 3.537324428558349609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+187, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2761.0947265625, -4972.48291015625, 99.80040740966796875, 2.333825588226318359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+188, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2508.1904296875, -4969.6171875, 102.213043212890625, 4.90108489990234375, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+189, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2807.759521484375, -4932.98291015625, 99.7864990234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+190, 223423, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2804.8349609375, -4942.96435546875, 99.8711395263671875, 4.821036338806152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Careless Hopgoblin (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448943 - Carry Cinderbrew Barrel, 449106 - Delicate Brew Barrel, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+191, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2510.2666015625, -4975.53759765625, 103.1577606201171875, 4.459846973419189453, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+192, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2519.799560546875, -4971.84716796875, 99.7878875732421875, 2.887331008911132812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+193, 214673, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2807.8125, -4942.63720703125, 99.89099884033203125, 4.825295448303222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Flavor Scientist (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448487 - Jetpack, 448491 - Jetpack Flames) (possible waypoints or random movement)
(@CGUID+194, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2556.576171875, -4991.11181640625, 114.2112503051757812, 1.423197746276855468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+195, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2759.612060546875, -4987.9931640625, 99.80040740966796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+196, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2510.300537109375, -4966.81689453125, 101.932769775390625, 5.110954761505126953, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+197, 223423, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2810.797607421875, -4942.30810546875, 99.9109039306640625, 4.822395801544189453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Careless Hopgoblin (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 448943 - Carry Cinderbrew Barrel, 449106 - Delicate Brew Barrel, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+198, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2536.21923828125, -4987.67041015625, 123.4278793334960937, 0.864005684852600097, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+199, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2755.10498046875, -4995.74658203125, 99.80040740966796875, 4.438020706176757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+200, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2557.2177734375, -4991.91748046875, 116.7364349365234375, 1.008301854133605957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+201, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2509.014892578125, -4973.005859375, 102.3187103271484375, 5.092188835144042968, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+202, 225633, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2755.427001953125, -5000.4775390625, 103.3175506591796875, 4.422156333923339843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Mead Machine (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+203, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2571.992431640625, -5030.20361328125, 100.0627899169921875, 3.784600019454956054, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+204, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2577.7158203125, -5026.9140625, 114.1640548706054687, 4.629977703094482421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+205, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2569.969970703125, -5011.5458984375, 131.7011566162109375, 1.06950235366821289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+206, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2786.15185546875, -4977.06103515625, 100.122528076171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+207, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2519.916748046875, -4995.38037109375, 99.7878875732421875, 3.281832456588745117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+208, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2577.652587890625, -5029.04931640625, 114.4693145751953125, 4.73255014419555664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+209, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2804.959228515625, -4973.65966796875, 100.81829833984375, 4.322099685668945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+210, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2802.119140625, -4977.31982421875, 99.78275299072265625, 0.501712977886199951, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+211, 210931, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2808.107666015625, -4957.015625, 99.7864990234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+212, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2575.774169921875, -5030.70263671875, 100.1165390014648437, 0.089711822569370269, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+213, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2569.32373046875, -5013.142578125, 118.3280487060546875, 3.038515329360961914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+214, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2505.212158203125, -4971.47900390625, 100.8246307373046875, 5.15769815444946289, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+215, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2575.182373046875, -5028.62646484375, 100.1974334716796875, 3.960091352462768554, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+216, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2650.78466796875, -5031.958984375, 110.4020843505859375, 5.121761798858642578, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+217, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2578.82373046875, -5028.3505859375, 100.4772186279296875, 0.817234516143798828, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+218, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2506.776611328125, -4973.45556640625, 101.756988525390625, 4.597675323486328125, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+219, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2573.46923828125, -5030.97900390625, 101.1217575073242187, 2.941803455352783203, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+220, 219202, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2611.489501953125, -5038.1787109375, 122.5066375732421875, 5.988169670104980468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Fradd (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+221, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2571.633056640625, -5024.95263671875, 125.7405776977539062, 2.281577348709106445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+222, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2567.350830078125, -5027.68408203125, 97.0995330810546875, 5.605441570281982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+223, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2551.8125, -5005.1650390625, 116.7062301635742187, 1.509403347969055175, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+224, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2550.479248046875, -5029.9931640625, 98.80118560791015625, 3.86295628547668457, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+225, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2585.046142578125, -5048.96728515625, 99.04742431640625, 5.433307170867919921, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+226, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2524.859619140625, -5019.3876953125, 100.1946258544921875, 2.883342266082763671, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+227, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2549.101806640625, -5034.7607421875, 99.04210662841796875, 4.43965911865234375, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+228, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2516.538330078125, -4999.5625, 99.7878875732421875, 2.214122295379638671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+229, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2585.779052734375, -5043.177734375, 99.9583740234375, 3.81713414192199707, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+230, 218671, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2810.08154296875, -4974.375, 99.7864990234375, 4.510342597961425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Pyromaniac (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@CGUID+231, 221194, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2515.7197265625, -5013.69091796875, 100.1409378051757812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- [DNT] Beehive Trash Stalker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: )
(@CGUID+232, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2547.9091796875, -5036.21875, 124.3400115966796875, 4.720520973205566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+233, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2512.716064453125, -4996.02783203125, 100.2861328125, 0.979012072086334228, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+234, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2550.357177734375, -5035.60791015625, 98.34661865234375, 4.55566263198852539, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+235, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2561.330322265625, -5033.9375, 121.9443511962890625, 5.937505722045898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+236, 220060, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2808.373779296875, -4978.33251953125, 99.80156707763671875, 0.492844998836517333, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Taste Tester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+237, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2557.671875, -5032.4130859375, 97.20641326904296875, 4.365952491760253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+238, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2583.85009765625, -5046.1650390625, 99.43310546875, 3.435565471649169921, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+239, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2549.021728515625, -5022.5458984375, 125.3975982666015625, 4.590119838714599609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+240, 220946, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2562.4453125, -5045.26416015625, 97.00069427490234375, 1.438786625862121582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Honey Harvester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 384670 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+241, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2591.77197265625, -5037.091796875, 120.3756942749023437, 1.656610608100891113, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+242, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2584.12451171875, -5043.9951171875, 98.4522705078125, 5.293188095092773437, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+243, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2550.9326171875, -5034.59716796875, 98.9160919189453125, 4.009023666381835937, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+244, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2570.439697265625, -5021.76123046875, 124.3896636962890625, 1.519181013107299804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+245, 210932, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2513.013916015625, -4994.14599609375, 99.7878875732421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+246, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2548.9501953125, -5031.99365234375, 98.19461822509765625, 1.508025050163269042, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+247, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2581.5732421875, -5046.546875, 100.3480453491210937, 4.904601573944091796, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+248, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2798.27392578125, -4982.2529296875, 99.80399322509765625, 5.833667278289794921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+249, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2564.734130859375, -5099.52734375, 108.5715103149414062, 2.659241914749145507, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+250, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2519.015625, -5059.767578125, 100.1409530639648437, 1.893571376800537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+251, 218876, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2587.103515625, -5066.45556640625, 100.1946258544921875, 3.185458660125732421, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Rat (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+252, 210932, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2519.33154296875, -5050.345703125, 100.1409530639648437, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+253, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2553.734375, -5044.76025390625, 127.6663894653320312, 5.961931705474853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+254, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2563.020263671875, -5096.65283203125, 107.3897323608398437, 3.313036441802978515, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+255, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2586.91845703125, -5072.265625, 100.1410064697265625, 2.379880189895629882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+256, 217126, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2639.35595703125, -4948.4375, -136.78375244140625, 4.014444351196289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Over-Indulged Patron (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 275612 - Drunk, 440682 - [DNT] Holding Mug)
(@CGUID+257, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2568.93115234375, -5096.11474609375, 108.0238723754882812, 4.163989067077636718, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+258, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2516.22998046875, -5055.3349609375, 100.1409530639648437, 5.439642906188964843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+259, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 2, 2562.7587890625, -5099.07470703125, 100.796234130859375, 1.028680086135864257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+260, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2567.80126953125, -5099.33740234375, 109.4189453125, 5.582107067108154296, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+261, 210932, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2565.9384765625, -5065.078125, 100.1410064697265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Path Helper (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+262, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2566.64794921875, -5098.27880859375, 108.1770782470703125, 1.185409784317016601, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+263, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2547.497314453125, -5064.46533203125, 100.1410064697265625, 4.886841773986816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+264, 220946, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2537.519775390625, -5064.9892578125, 100.1946182250976562, 5.587016105651855468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Honey Harvester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 422360 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+265, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2546.57470703125, -5071.98779296875, 100.1409988403320312, 1.304757118225097656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+266, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2571.390625, -5100.95361328125, 109.3171463012695312, 3.160084724426269531, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+267, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2565.36376953125, -5096.080078125, 100.796234130859375, 4.055979728698730468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+268, 220141, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2583.30029296875, -5063.375, 100.1410064697265625, 4.247960090637207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Royal Jelly Purveyor (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+269, 210265, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2551.978271484375, -5070.7568359375, 100.1410064697265625, 2.623009204864501953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Worker Bee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+270, 219955, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2553.325927734375, -5048.783203125, 124.4923553466796875, 2.148210763931274414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Cinderbee (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (possible waypoints or random movement)
(@CGUID+271, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2535.79931640625, -5067.4609375, 100.1946182250976562, 5.58721160888671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+272, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2582.247314453125, -5071.126953125, 100.1410064697265625, 1.080325126647949218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+273, 210264, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2578.728271484375, -5065.62158203125, 100.1410064697265625, 5.121885299682617187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Bee Wrangler (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+274, 220946, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2564.981689453125, -5104.783203125, 100.796539306640625, 0.695838153362274169, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Honey Harvester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 384670 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+275, 218877, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2563.37646484375, -5096.349609375, 100.8039932250976562, 3.508438348770141601, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Cockroach (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 438265 - [DNT] On Fire!) (possible waypoints or random movement)
(@CGUID+276, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2563.61767578125, -5102.68701171875, 108.9766921997070312, 2.402835845947265625, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+277, 220946, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 1, 2566.233642578125, -5109.314453125, 100.796539306640625, 1.926924824714660644, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Venture Co. Honey Harvester (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 384670 - [DNT] Cosmetic - Sleep Zzz)
(@CGUID+278, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2562.8330078125, -5100.35498046875, 109.5232696533203125, 5.553096294403076171, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+279, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2561.345703125, -5104.20556640625, 108.3493270874023437, 4.413217544555664062, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+280, 218865, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2566.620849609375, -5100.58154296875, 110.4891128540039062, 2.662736177444458007, 7200, 2, 0, 1, NULL, NULL, NULL, NULL, 56647), -- Bee-let (Area: The Flaming Taps - Difficulty: Follower) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 441394 - Bee Venom) (possible waypoints or random movement)
(@CGUID+281, 219415, 2661, 15103, 15338, '1,2,8,23', 0, 0, 0, 0, 2693.0322265625, -4889.91845703125, 100.8405685424804687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 56647); -- Cooking Pot (Area: The Flaming Taps - Difficulty: Follower) CreateObject2 (Auras: 439179 - [DNT] Cooking Pot)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+281;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+11, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+12, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682 422355'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug, 422355 - Bot AI Follow Advert, 441408
(@CGUID+13, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422354 18950'), -- Hired Muscle - 422354 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection
(@CGUID+18, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+19, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Pyromaniac - 440682 - [DNT] Holding Mug
(@CGUID+34, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+21, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422355 440682'), -- Venture Co. Patron - 422355 - Bot AI Follow Advert, 440682 - [DNT] Holding Mug
(@CGUID+22, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+24, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+26, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+27, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Pyromaniac - 440682 - [DNT] Holding Mug
(@CGUID+28, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Pyromaniac - 440682 - [DNT] Holding Mug
(@CGUID+32, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+36, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+41, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+43, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames
(@CGUID+49, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+50, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Patron - 440682 - [DNT] Holding Mug
(@CGUID+52, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+54, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+56, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '440682'), -- Venture Co. Pyromaniac - 440682 - [DNT] Holding Mug
(@CGUID+57, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+59, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+61, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+63, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+82, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames
(@CGUID+83, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '384670'), -- Taste Tester - 384670 - [DNT] Cosmetic - Sleep Zzz
(@CGUID+87, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+92, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612 440682'), -- Over-Indulged Patron - 275612 - Drunk, 440682 - [DNT] Holding Mug
(@CGUID+100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+139, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491 447046'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames, 447046 - Secret Ingredient
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 613, 0, 0, 0, 0, ''), -- Taste Tester
(@CGUID+151, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491 447046'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames, 447046 - Secret Ingredient
(@CGUID+153, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- Flavor Scientist
(@CGUID+155, 0, 0, 0, 0, 0, 1, 0, 613, 0, 0, 0, 0, ''), -- Taste Tester
(@CGUID+162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+163, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames
(@CGUID+165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- Royal Jelly Purveyor - 214567 - Mod Scale 90-110%
(@CGUID+166, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+177, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames
(@CGUID+183, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- Flavor Scientist - 448487 - Jetpack, 448491 - Jetpack Flames
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- Royal Jelly Purveyor - 214567 - Mod Scale 90-110%
(@CGUID+199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Pyromaniac
(@CGUID+240, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '384670'), -- Venture Co. Honey Harvester - 384670 - [DNT] Cosmetic - Sleep Zzz
(@CGUID+263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '214567'), -- Royal Jelly Purveyor - 214567 - Mod Scale 90-110%
(@CGUID+274, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '384670'), -- Venture Co. Honey Harvester - 384670 - [DNT] Cosmetic - Sleep Zzz
(@CGUID+277, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '384670'); -- Venture Co. Honey Harvester - 384670 - [DNT] Cosmetic - Sleep Zzz

UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` = 216088;
UPDATE `creature` SET `curHealthPct` = 50 WHERE `guid` = @CGUID+0;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+69;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 252245, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2650.880126953125, -4835.8818359375, 101.0417327880859375, 4.677209377288818359, 0, 0, -0.71943473815917968, 0.694560050964355468, 7200, 255, 1, 56647), -- Instance Portal (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+1, 429361, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2665.54248046875, -4871.46337890625, 99.6529998779296875, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+2, 429360, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2672.302490234375, -4871.46337890625, 99.6529998779296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+3, 429377, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2672.3056640625, -4882.73828125, 99.71082305908203125, 4.600342750549316406, 0, 0, -0.7455911636352539, 0.666403651237487792, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+4, 429379, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2671.5908203125, -4887.95654296875, 99.71082305908203125, 1.770452857017517089, 0, 0, 0.774058341979980468, 0.633114278316497802, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+5, 429378, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2669.8193359375, -4882.724609375, 99.71082305908203125, 4.838365077972412109, 0, 0, -0.6611948013305664, 0.750214278697967529, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+6, 429359, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2685.833740234375, -4871.46337890625, 99.66069793701171875, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+7, 429380, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2669.272216796875, -4888.11279296875, 99.71082305908203125, 1.379362940788269042, 0, 0, 0.63629150390625, 0.771448731422424316, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+8, 429382, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2669.333984375, -4894.14208984375, 99.71082305908203125, 5.034189224243164062, 0, 0, -0.58469009399414062, 0.811256766319274902, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+9, 429389, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2678.0751953125, -4889.8994140625, 99.71082305908203125, 6.177661895751953125, 0, 0, -0.05273723602294921, 0.998608410358428955, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+10, 429388, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2678.1015625, -4887.42822265625, 99.71082305908203125, 0.203732743859291076, 0, 0, 0.101690292358398437, 0.994816124439239501, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+11, 429391, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2683.072998046875, -4901.6796875, 99.71082305908203125, 4.600342750549316406, 0, 0, -0.7455911636352539, 0.666403651237487792, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+12, 429390, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2678.513671875, -4892.6962890625, 99.71082305908203125, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+13, 429385, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2684.658447265625, -4887.7451171875, 99.71082305908203125, 3.34533095359802246, 0, 0, -0.99481582641601562, 0.10169299691915512, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+14, 429384, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2669.845703125, -4899.53369140625, 99.71082305908203125, 1.57518923282623291, 0, 0, 0.708658218383789062, 0.70555192232131958, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+15, 429387, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2684.306396484375, -4893.546875, 99.71082305908203125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+16, 429386, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2684.809326171875, -4890.13525390625, 99.71082305908203125, 3.03603982925415039, 0, 0, 0.998607635498046875, 0.052751891314983367, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+17, 429367, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2614.267578125, -4885.98779296875, 99.71669769287109375, 3.34533095359802246, 0, 0, -0.99481582641601562, 0.10169299691915512, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+18, 429372, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2606.508544921875, -4891.65283203125, 99.71669769287109375, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+19, 429369, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2614.249755859375, -4892.50341796875, 99.71669769287109375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+20, 429368, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2614.41845703125, -4889.091796875, 99.71669769287109375, 3.03603982925415039, 0, 0, 0.998607635498046875, 0.052751891314983367, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+21, 429371, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2606.96240234375, -4889.091796875, 99.71669769287109375, 6.177661895751953125, 0, 0, -0.05273723602294921, 0.998608410358428955, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+22, 429370, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2606.671875, -4886.384765625, 99.71669769287109375, 0.203732743859291076, 0, 0, 0.101690292358398437, 0.994816124439239501, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+23, 408880, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2701.30419921875, -4928.4111328125, 100.185546875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- 11EA_Earthen_Navigation_Door03 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+24, 429358, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2692.593994140625, -4871.46337890625, 99.66069793701171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+25, 429355, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2696.780029296875, -4881.2646484375, 99.67913818359375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+26, 429354, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2696.780029296875, -4874.50439453125, 99.67913818359375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+27, 429392, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2680.586669921875, -4901.666015625, 99.71082305908203125, 4.838365077972412109, 0, 0, -0.6611948013305664, 0.750214278697967529, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+28, 408879, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2600.28271484375, -4925.154296875, 100.1077041625976562, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- 11EA_Earthen_Navigation_Door03 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+29, 429381, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2671.775390625, -4893.671875, 99.71082305908203125, 4.796164512634277343, 0, 0, -0.67687606811523437, 0.736096978187561035, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+30, 429383, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2672.08935546875, -4898.92919921875, 99.71082305908203125, 1.966275334358215332, 0, 0, 0.832241058349609375, 0.554413974285125732, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+31, 408881, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2608.90625, -4953.88623046875, 99.9393310546875, 0.675406098365783691, 0, 0, 0.331320762634277343, 0.94351816177368164, 7200, 255, 1, 56647), -- 11EA_Earthen_Navigation_Door03 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+32, 408882, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2691.990234375, -4955.15380859375, 99.88901519775390625, 2.466183662414550781, 0, 0, 0.943517684936523437, 0.331322133541107177, 7200, 255, 1, 56647), -- 11EA_Earthen_Navigation_Door03 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+33, 429357, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2696.780029296875, -4905.80615234375, 99.6567230224609375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+34, 429356, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2696.780029296875, -4899.0458984375, 99.6567230224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 56647), -- Bench (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+35, 429393, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2683.03466796875, -4906.8671875, 99.71082305908203125, 1.770452857017517089, 0, 0, 0.774058341979980468, 0.633114278316497802, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+36, 429394, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2680.716064453125, -4907.0234375, 99.71082305908203125, 1.379362940788269042, 0, 0, 0.63629150390625, 0.771448731422424316, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+37, 454731, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2698.100341796875, -4890.177734375, 99.59328460693359375, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 7200, 255, 1, 56647), -- Cooking Fire (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+38, 429376, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2637.65087890625, -4951.0751953125, 99.6858367919921875, 5.743211746215820312, 0, 0, -0.26671886444091796, 0.963774383068084716, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+39, 429365, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2645.797607421875, -4947.0029296875, 99.6858367919921875, 4.969731330871582031, 0, 0, -0.61052799224853515, 0.791994690895080566, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+40, 429364, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2649.151123046875, -4947.0029296875, 99.6858367919921875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+41, 429366, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2642.693603515625, -4946.93798828125, 99.6858367919921875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+42, 429363, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2652.255126953125, -4946.55859375, 99.6858367919921875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+43, 429362, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2655.666748046875, -4947.0185546875, 99.6858367919921875, 4.367510795593261718, 0, 0, -0.81794929504394531, 0.575290322303771972, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+44, 429373, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2662.500244140625, -4948.44140625, 99.6858367919921875, 3.97467660903930664, 0, 0, -0.91449356079101562, 0.404600471258163452, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+45, 429375, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2639.14599609375, -4948.6796875, 99.6858367919921875, 5.508551597595214843, 0, 0, -0.37770557403564453, 0.925925731658935546, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+46, 429374, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2664.3291015625, -4950.4990234375, 99.6858367919921875, 3.51449894905090332, 0, 0, -0.98266792297363281, 0.185374617576599121, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+47, 429353, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2659.266845703125, -4947.0185546875, 99.6858367919921875, 4.80010986328125, 0, 0, -0.67542266845703125, 0.737430810928344726, 7200, 255, 1, 56647), -- Stool (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+48, 415782, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2641.935546875, -4964.00341796875, 102.0509414672851562, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 56647), -- Keg Tap (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+49, 444271, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2695.181884765625, -4991.18603515625, 112.1128768920898437, 3.574542045593261718, 0, 0, -0.97666072845458984, 0.214787840843200683, 7200, 255, 1, 56647), -- 11DU_Brewery_Door01 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+50, 444272, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2607.937744140625, -4991.7763671875, 112.3121795654296875, 2.783516883850097656, 0, 0, 0.984015464782714843, 0.178082972764968872, 7200, 255, 0, 56647), -- 11DU_Brewery_Door01 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+51, 441647, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2754.11474609375, -4897.5361328125, 103.2612533569335937, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 7200, 255, 1, 56647), -- 11EA_Earthen_Furniture_Bar_Stool01 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+52, 441646, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2756.61376953125, -4897.5361328125, 103.2612533569335937, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 56647), -- 11EA_Earthen_Furniture_Bar_Stool01 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+53, 415781, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2650.96484375, -4964.00341796875, 102.0509414672851562, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 56647), -- Keg Tap (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+54, 415780, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2659.84619140625, -4964.00341796875, 102.0509414672851562, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 56647), -- Keg Tap (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+55, 410143, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2789.436767578125, -4977.31201171875, 100.1880111694335937, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 56647), -- 11EA_Earthen_Navigation_Door02 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+56, 437503, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2650.793212890625, -5013.0146484375, 110.323638916015625, 1.538478970527648925, 0, 0, 0.695589065551757812, 0.718439877033233642, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+57, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2634.09033203125, -5032.3369140625, 110.4487686157226562, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+58, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2671.752685546875, -5026.65478515625, 108.4874114990234375, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+59, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2630.530517578125, -5024.6875, 109.7270889282226562, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+60, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2668.311767578125, -5033.0625, 110.296173095703125, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+61, 429397, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2622.98828125, -5026.494140625, 114.3407821655273437, 6.135456562042236328, 0, 0, -0.07379722595214843, 0.997273266315460205, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+62, 429396, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2622.967041015625, -5028.7236328125, 114.3407745361328125, 0.654204964637756347, 0, 0, 0.321300506591796875, 0.946977317333221435, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+63, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2672.0166015625, -5029.88916015625, 110.2482070922851562, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+64, 441645, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2795.02392578125, -4961.57177734375, 99.703155517578125, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 7200, 255, 1, 56647), -- 11EA_Earthen_Furniture_Bar_Stool01 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+65, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2670.87060546875, -5032.79541015625, 111.5479888916015625, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+66, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2630.237060546875, -5026.20654296875, 108.236602783203125, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+67, 456468, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2631.1494140625, -5033.09375, 110.6634063720703125, 0, 0, 0, 0, 1, 7200, 255, 1, 56647), -- Collsion Blocker (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+68, 437341, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2679.833251953125, -5032.46142578125, 114.3407745361328125, 1.194390773773193359, 0, 0, 0.562325477600097656, 0.826916038990020751, 7200, 255, 1, 56647), -- Chair (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
(@OGUID+69, 440897, 2661, 15103, 15338, '1,2,8,23', 0, 0, 2513.802978515625, -5009.31689453125, 100.2737808227539062, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 0, 56647); -- 11EA_Earthen_Navigation_Door01 (Area: The Flaming Taps - Difficulty: Follower) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+69;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+2, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+3, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+4, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+5, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+6, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+7, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+8, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+9, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+10, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+11, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+12, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+13, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+14, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+15, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+16, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+17, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+18, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+19, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+20, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+21, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+22, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+23, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Navigation_Door03
(@OGUID+24, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+25, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+26, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+27, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+28, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Navigation_Door03
(@OGUID+29, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+30, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+31, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Navigation_Door03
(@OGUID+32, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Navigation_Door03
(@OGUID+33, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+34, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Bench
(@OGUID+35, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+36, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+37, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Cooking Fire
(@OGUID+38, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+39, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+40, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+41, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+42, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+43, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+44, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+45, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+46, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+47, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Stool
(@OGUID+48, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 18307), -- Keg Tap
(@OGUID+49, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11DU_Brewery_Door01
(@OGUID+50, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11DU_Brewery_Door01
(@OGUID+51, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Furniture_Bar_Stool01
(@OGUID+52, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Furniture_Bar_Stool01
(@OGUID+53, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 18307), -- Keg Tap
(@OGUID+54, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 18307), -- Keg Tap
(@OGUID+55, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Navigation_Door02
(@OGUID+56, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+61, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+62, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+64, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- 11EA_Earthen_Furniture_Bar_Stool01
(@OGUID+68, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Chair
(@OGUID+69, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0); -- 11EA_Earthen_Navigation_Door01

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (223498 /*223498 (Bee-let) - Mod Scale 90-110%*/, 223497 /*223497 (Worker Bee) - Mod Scale 95-120%*/, 223562 /*223562 (Brew Drop) - Mod Scale 90-110%*/, 220368 /*220368 (Failed Batch) - Failed Batch*/, 220830 /*220830 (Mug of Cinderbrew) - [DNT] Highlight*/, 215819 /*215819 (Thirsty Patron) - Rowdy Yell*/, 219202 /*219202 (Fradd)*/, 219203 /*219203 (Bredd) - Ride Vehicle Hardcoded*/, 225633 /*225633 (Mead Machine)*/, 218002 /*218002 (Benk Buzzbee) - Bot AI Follow Advert*/, 218000 /*218000 (Benk Buzzbee) - [DNT] Spawn Cosmetic Aura, Ride Vehicle Hardcoded*/, 219955 /*219955 (Cinderbee)*/, 223423 /*223423 (Careless Hopgoblin) - Carry Cinderbrew Barrel, Delicate Brew Barrel, Invisibility and Stealth Detection*/, 222964 /*222964 (Flavor Scientist) - Jetpack, Jetpack Flames*/, 222951 /*222951 (I'pa)*/, 220946 /*220946 (Venture Co. Honey Harvester) - Bot AI Follow Advert, Invisibility and Stealth Detection*/, 218523 /*218523 (Goldie Baronbottom) - [DNT] Spotlight On Me*/, 220141 /*220141 (Royal Jelly Purveyor) - Mod Scale 90-110%*/, 219667 /*219667 (Flamethrower) - [DNT] Flamethrower Visual*/, 210270 /*210270 (Brew Drop) - Mod Scale 90-110%, Bot AI Follow Advert*/, 218865 /*218865 (Bee-let) - Mod Scale 90-110%, Bee Venom*/, 222889 /*222889 (Mead Machine)*/, 210264 /*210264 (Bee Wrangler) - Mod Scale 90-110%*/, 220060 /*220060 (Taste Tester) - [DNT] Cosmetic - Sleep Zzz*/, 210271 /*210271 (Brew Master Aldryr) - Bot AI Follow Advert, [DNT] Holding Mug*/, 210933 /*210933 (Path Helper) - Bot AI Follow Advert*/, 210265 /*210265 (Worker Bee) - Mod Scale 95-120%*/, 214697 /*214697 (Chef Chewie) - Compliments of the Chef, Bot AI Follow Advert, Invisibility and Stealth Detection*/, 219415 /*219415 (Cooking Pot) - [DNT] Cooking Pot*/, 214673 /*214673 (Flavor Scientist) - Jetpack, Jetpack Flames*/, 214920 /*214920 (Tasting Room Attendant) - [DNT] Drink Tray*/, 217126 /*217126 (Over-Indulged Patron) - Drunk, [DNT] Holding Mug*/, 209068 /*209068 (Ash) - Predator's Thirst, Pet Check, Scale, Pet Active*/, 209065 /*209065 (Austin Huxworth) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Mail, Proc, Scale, Override Energy Bar Color, Predator's Thirst, AI Buff Watcher, Bot AI Follow Advert*/, 213839 /*213839 (Path Helper) - Passive, Bot AI Follow Advert*/, 210269 /*210269 (Hired Muscle) - Bot AI Follow Advert, Invisibility and Stealth Detection, Thirsty*/, 209057 /*209057 (Captain Garrick) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Plate, Proc, Scale, AI Buff Watcher, Bot AI Follow Advert, Devotion Aura, Devotion Aura*/, 218671 /*218671 (Venture Co. Pyromaniac) - Thirsty*/, 209072 /*209072 (Crenna Earth-Daughter) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Leather, Proc, Scale, AI Buff Watcher, Ysera's Gift, Bot AI Follow Advert*/, 209069 /*209069 (Nyx) - Predator's Thirst, Pet Check, Scale*/, 214390 /*214390 (Shuja Grimaxe) - Join Player Party, AI Regen / Crit, Adaptation, General Defensive Passive - Mail, Proc, Scale, AI Buff Watcher, Bot AI Follow Advert*/, 214668 /*214668 (Venture Co. Patron) - Bot AI Follow Advert*/, 218877 /*218877 (Cockroach) - [DNT] On Fire!*/, 216088 /*216088 (Wenbrandt) - [DNT] Beat Up*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(223498, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 223498 (Bee-let) - Mod Scale 90-110%
(223497, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123978'), -- 223497 (Worker Bee) - Mod Scale 95-120%
(223562, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 223562 (Brew Drop) - Mod Scale 90-110%
(220368, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '441505'), -- 220368 (Failed Batch) - Failed Batch
(220830, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '454452'), -- 220830 (Mug of Cinderbrew) - [DNT] Highlight
(215819, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 215819 (Thirsty Patron) - Rowdy Yell
(219202, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 219202 (Fradd)
(219203, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 219203 (Bredd) - Ride Vehicle Hardcoded
(225633, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 225633 (Mead Machine)
(218002, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 4, '422362'), -- 218002 (Benk Buzzbee) - Bot AI Follow Advert
(218000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '439188'), -- 218000 (Benk Buzzbee) - [DNT] Spawn Cosmetic Aura
(219955, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 219955 (Cinderbee)
(223423, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '448943 449106 18950'), -- 223423 (Careless Hopgoblin) - Carry Cinderbrew Barrel, Delicate Brew Barrel, Invisibility and Stealth Detection
(222964, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- 222964 (Flavor Scientist) - Jetpack, Jetpack Flames
(222951, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222951 (I'pa)
(220946, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422360 18950'), -- 220946 (Venture Co. Honey Harvester) - Bot AI Follow Advert, Invisibility and Stealth Detection
(218523, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '437208'), -- 218523 (Goldie Baronbottom) - [DNT] Spotlight On Me
(220141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 220141 (Royal Jelly Purveyor) - Mod Scale 90-110%
(219667, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439603'), -- 219667 (Flamethrower) - [DNT] Flamethrower Visual
(210270, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567 422358'), -- 210270 (Brew Drop) - Mod Scale 90-110%, Bot AI Follow Advert
(218865, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '214567 441394'), -- 218865 (Bee-let) - Mod Scale 90-110%, Bee Venom
(222889, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222889 (Mead Machine)
(210264, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '214567'), -- 210264 (Bee Wrangler) - Mod Scale 90-110%
(220060, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220060 (Taste Tester)
(210271, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '422356'), -- 210271 (Brew Master Aldryr) - Bot AI Follow Advert, [DNT] Holding Mug
(210933, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '423677'), -- 210933 (Path Helper) - Bot AI Follow Advert
(210265, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123978'), -- 210265 (Worker Bee) - Mod Scale 95-120%
(214697, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '434743 422354 18950'), -- 214697 (Chef Chewie) - Compliments of the Chef, Bot AI Follow Advert, Invisibility and Stealth Detection
(219415, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439179'), -- 219415 (Cooking Pot) - [DNT] Cooking Pot
(214673, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '448487 448491'), -- 214673 (Flavor Scientist) - Jetpack, Jetpack Flames
(214920, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '434685'), -- 214920 (Tasting Room Attendant) - [DNT] Drink Tray
(217126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '275612'), -- 217126 (Over-Indulged Patron) - Drunk, [DNT] Holding Mug
(213839, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '428569 413569'), -- 213839 (Path Helper) - Passive, Bot AI Follow Advert
(210269, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422354 18950'), -- 210269 (Hired Muscle) - Bot AI Follow Advert, Invisibility and Stealth Detection
(218671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 218671 (Venture Co. Pyromaniac)
(214668, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '422355'), -- 214668 (Venture Co. Patron) - Bot AI Follow Advert
(218877, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '438265'), -- 218877 (Cockroach) - [DNT] On Fire!
(216088, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '437154'); -- 216088 (Wenbrandt) - [DNT] Beat Up

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (440897 /*11EA_Earthen_Navigation_Door01*/, 410143 /*11EA_Earthen_Navigation_Door02*/, 415780 /*Keg Tap*/, 415781 /*Keg Tap*/, 444272 /*11DU_Brewery_Door01*/, 444271 /*11DU_Brewery_Door01*/, 415782 /*Keg Tap*/, 408882 /*11EA_Earthen_Navigation_Door03*/, 408881 /*11EA_Earthen_Navigation_Door03*/, 408879 /*11EA_Earthen_Navigation_Door03*/, 408880 /*11EA_Earthen_Navigation_Door03*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(440897, 0, 48, 0, 0), -- 11EA_Earthen_Navigation_Door01
(410143, 0, 48, 0, 0), -- 11EA_Earthen_Navigation_Door02
(415780, 0, 16, 0, 18307), -- Keg Tap
(415781, 0, 16, 0, 18307), -- Keg Tap
(444272, 0, 48, 0, 0), -- 11DU_Brewery_Door01
(444271, 0, 48, 0, 0), -- 11DU_Brewery_Door01
(415782, 0, 16, 0, 18307), -- Keg Tap
(408882, 0, 48, 0, 0), -- 11EA_Earthen_Navigation_Door03
(408881, 0, 48, 0, 0), -- 11EA_Earthen_Navigation_Door03
(408879, 0, 48, 0, 0), -- 11EA_Earthen_Navigation_Door03
(408880, 0, 48, 0, 0); -- 11EA_Earthen_Navigation_Door03

-- Template
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=226170; -- Unbound Meadworker
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=226409; -- Wenbrandt
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `speed_walk`=1.20000004768371582, `speed_run`=1, `BaseAttackTime`=2000 WHERE `entry`=227120; -- Meredy Huntswell
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048, `VehicleId`=8327 WHERE `entry` IN (218960, 215582); -- Bee Line
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=17301504 WHERE `entry`=218307; -- Gold Coin
UPDATE `creature_template` SET `faction`=2753, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=17301504 WHERE `entry`=217837; -- Cinderbrew Bomb
UPDATE `creature_template` SET `faction`=2753, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=220224; -- Cinderbrew Bomb
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=219588; -- Yes Man
UPDATE `creature_template` SET `faction`=14, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=214661; -- Goldie Baronbottom
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=215575; -- Bee Line
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=16384, `unit_flags3`=524289, `VehicleId`=584 WHERE `entry`=218016; -- Ravenous Cinderbee
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110944, `unit_flags3`=1095237633 WHERE `entry`=219005; -- Honey Barrel
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=223498; -- Bee-let
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=223497; -- Worker Bee
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.399999976158142089, `speed_run`=0.5, `BaseAttackTime`=2000, `unit_flags3`=2621440 WHERE `entry`=219301; -- Brew Drop
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=210267; -- I'pa
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=223562; -- Brew Drop
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1074266112 WHERE `entry`=220368; -- Failed Batch
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912, `unit_flags3`=1091043329 WHERE `entry`=220830; -- Mug of Cinderbrew
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=215819; -- Thirsty Patron
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=219201; -- Fradd
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=8402 WHERE `entry`=219200; -- Bredd
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1073741825, `flags_extra` = 128 WHERE `entry`=221194; -- [DNT] Beehive Trash Stalker
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=8403 WHERE `entry`=219202; -- Fradd
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=219203; -- Bredd
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=32768 WHERE `entry`=225633; -- Mead Machine
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=8388608, `VehicleId`=8382 WHERE `entry`=218002; -- Benk Buzzbee
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=67110912, `unit_flags3`=32768 WHERE `entry`=218000; -- Benk Buzzbee
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags3`=1 WHERE `entry`=219955; -- Cinderbee
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67110912, `unit_flags3`=1073774592 WHERE `entry`=222951; -- I'pa
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry` IN (222964, 214673); -- Flavor Scientist
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220141; -- Royal Jelly Purveyor
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=218865; -- Bee-let
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048 WHERE `entry`=218523; -- Goldie Baronbottom
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=210270; -- Brew Drop
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1073774592 WHERE `entry`=222889; -- Mead Machine
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220060; -- Taste Tester
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=220946; -- Venture Co. Honey Harvester
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=219667; -- Flamethrower
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=223423; -- Careless Hopgoblin
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=210264; -- Bee Wrangler
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=214697; -- Chef Chewie
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=64 WHERE `entry`=210271; -- Brew Master Aldryr
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=210265; -- Worker Bee
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=219415; -- Cooking Pot
UPDATE `creature_template` SET `faction`=3446, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217126; -- Over-Indulged Patron
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=216088; -- Wenbrandt
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=218876; -- Rat
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=218671; -- Venture Co. Pyromaniac
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=218877; -- Cockroach
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=210269; -- Hired Muscle
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `VehicleId`=8364 WHERE `entry`=214920; -- Tasting Room Attendant
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1600, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=214668; -- Venture Co. Patron
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=1090551809, `flags_extra` = 128 WHERE `entry`=210933; -- Path Helper
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry` IN (48342, 48343, 48341); -- Goblin Cocktail

DELETE FROM `gameobject_template` WHERE `entry` IN (454052 /*Wenbrandt's Mace*/, 440284 /*Goldie's Letter*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(454052, 5, 93119, 'Wenbrandt\'s Mace', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647), -- Wenbrandt's Mace
(440284, 10, 9327, 'Goldie\'s Letter', 'inspect', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34483, 0, 0, 121015, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56647); -- Goldie's Letter

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=214920 AND `seat_id` IN (4,3,2,1,0)) OR (`entry`=219200 AND `seat_id`=0) OR (`entry`=218002 AND `seat_id`=0) OR (`entry`=219202 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(214920, 48343, 4, 0, 'Tasting Room Attendant - Goblin Cocktail', 8, 0), -- Tasting Room Attendant - Goblin Cocktail
(214920, 48342, 3, 0, 'Tasting Room Attendant - Goblin Cocktail', 8, 0), -- Tasting Room Attendant - Goblin Cocktail
(214920, 48341, 2, 0, 'Tasting Room Attendant - Goblin Cocktail', 8, 0), -- Tasting Room Attendant - Goblin Cocktail
(214920, 48341, 1, 0, 'Tasting Room Attendant - Goblin Cocktail', 8, 0), -- Tasting Room Attendant - Goblin Cocktail
(214920, 48340, 0, 0, 'Tasting Room Attendant - Drink Tray', 8, 0), -- Tasting Room Attendant - Drink Tray
(219200, 219201, 0, 0, 'Bredd - Fradd', 8, 0), -- Bredd - Fradd
(218002, 218000, 0, 0, 'Benk Buzzbee - Benk Buzzbee', 8, 0), -- Benk Buzzbee - Benk Buzzbee
(219202, 219203, 0, 0, 'Fradd - Bredd', 8, 0); -- Fradd - Bredd

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (48341, 48343, 48342, 214920, 219200, 218002, 219202, 220830, 218016, 215575);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(48341, 89908, 1, 0),
(48343, 89908, 1, 0),
(48342, 89908, 1, 0),
(214920, 46598, 1, 0),
(219200, 46598, 1, 0),
(218002, 46598, 1, 0),
(219202, 46598, 1, 0),
(220830, 431895, 1, 0),
(218016, 438745, 1, 0),
(215575, 431393, 1, 0);

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (214673, 222964);
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(214673, 1, 0, 0, NULL),
(222964, 1, 0, 0, NULL);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (123097, 121109, 121102, 120631, 120498, 117177, 118074, 118270, 119017, 124003);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(123097, 1.80593729019165039, 2, 0, 56647),
(121109, 0.305999994277954101, 1.5, 0, 56647),
(121102, 1.805937409400939941, 2.000000238418579101, 0, 56647),
(120631, 1.083562374114990234, 1.20000004768371582, 0, 56647),
(120498, 0.310000002384185791, 1.00000011920928955, 0, 56647),
(117177, 1.103178024291992187, 2, 0, 56647),
(118074, 0.5, 1.5, 0, 56647),
(118270, 0.418749630451202392, 0, 0, 56647),
(119017, 0.372000008821487426, 1.5, 0, 56647),
(124003, 1.805937409400939941, 2.000000238418579101, 0, 56647);

UPDATE `creature_model_info` SET `VerifiedBuild`=56647 WHERE `DisplayID` IN (117360, 113755, 120661, 104042, 114807, 110046, 92725, 116130, 88201, 38615, 119028, 119459, 100041, 36638, 119445, 118076, 118378, 120557, 117818, 121056, 118003, 121064, 119460, 121061, 118000, 117828, 121055, 118004, 108585, 11686, 121087, 119441, 121036, 116429, 121058, 117811, 119022, 119437, 119021, 119019, 121035, 119023, 118068, 119026, 119018, 119032, 119020, 114514, 74917, 119013, 121034, 119015, 119030, 36116, 36117, 36114, 12191, 118999, 36115, 119034, 121037, 119033);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226170 AND `DifficultyID`=0); -- 226170 (Unbound Meadworker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=226409 AND `DifficultyID`=0); -- 226409 (Wenbrandt) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=227120 AND `DifficultyID`=0); -- 227120 (Meredy Huntswell) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=218960 AND `DifficultyID`=0); -- 218960 (Bee Line) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218307 AND `DifficultyID`=0); -- 218307 (Gold Coin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=217837 AND `DifficultyID`=0); -- 217837 (Cinderbrew Bomb) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220224 AND `DifficultyID`=0); -- 220224 (Cinderbrew Bomb) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=215582 AND `DifficultyID`=0); -- 215582 (Bee Line) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=219588 AND `DifficultyID`=0); -- 219588 (Yes Man) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214661 AND `DifficultyID`=0); -- 214661 (Goldie Baronbottom) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=215575 AND `DifficultyID`=0); -- 215575 (Bee Line) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `StaticFlags3`=262144, `VerifiedBuild`=56647 WHERE (`Entry`=218016 AND `DifficultyID`=0); -- 218016 (Ravenous Cinderbee) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=219005 AND `DifficultyID`=0); -- 219005 (Honey Barrel) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306368, `VerifiedBuild`=56647 WHERE (`Entry`=223498 AND `DifficultyID`=0); -- 223498 (Bee-let) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223497 AND `DifficultyID`=0); -- 223497 (Worker Bee) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=219301 AND `DifficultyID`=0); -- 219301 (Brew Drop) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210267 AND `DifficultyID`=0); -- 210267 (I'pa) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223562 AND `DifficultyID`=0); -- 223562 (Brew Drop) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=220368 AND `DifficultyID`=0); -- 220368 (Failed Batch) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=220830 AND `DifficultyID`=0); -- 220830 (Mug of Cinderbrew) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=215819 AND `DifficultyID`=0); -- 215819 (Thirsty Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=181, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=223273 AND `DifficultyID`=0); -- 223273 (Entropic Rift) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=219201 AND `DifficultyID`=0); -- 219201 (Fradd) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=219200 AND `DifficultyID`=0); -- 219200 (Bredd) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=221194 AND `DifficultyID`=0); -- 221194 ([DNT] Beehive Trash Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536870912, `VerifiedBuild`=56647 WHERE (`Entry`=219202 AND `DifficultyID`=0); -- 219202 (Fradd) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=219203 AND `DifficultyID`=0); -- 219203 (Bredd) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306368, `VerifiedBuild`=56647 WHERE (`Entry`=225633 AND `DifficultyID`=0); -- 225633 (Mead Machine) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218002 AND `DifficultyID`=0); -- 218002 (Benk Buzzbee) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=218000 AND `DifficultyID`=0); -- 218000 (Benk Buzzbee) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306368, `VerifiedBuild`=56647 WHERE (`Entry`=219955 AND `DifficultyID`=0); -- 219955 (Cinderbee) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=222951 AND `DifficultyID`=0); -- 222951 (I'pa) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=222964 AND `DifficultyID`=0); -- 222964 (Flavor Scientist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220141 AND `DifficultyID`=0); -- 220141 (Royal Jelly Purveyor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306368, `VerifiedBuild`=56647 WHERE (`Entry`=218865 AND `DifficultyID`=0); -- 218865 (Bee-let) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218523 AND `DifficultyID`=0); -- 218523 (Goldie Baronbottom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210270 AND `DifficultyID`=0); -- 210270 (Brew Drop) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=222889 AND `DifficultyID`=0); -- 222889 (Mead Machine) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220060 AND `DifficultyID`=0); -- 220060 (Taste Tester) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=220946 AND `DifficultyID`=0); -- 220946 (Venture Co. Honey Harvester) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=219667 AND `DifficultyID`=0); -- 219667 (Flamethrower) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=223423 AND `DifficultyID`=0); -- 223423 (Careless Hopgoblin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210264 AND `DifficultyID`=0); -- 210264 (Bee Wrangler) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214697 AND `DifficultyID`=0); -- 214697 (Chef Chewie) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210271 AND `DifficultyID`=0); -- 210271 (Brew Master Aldryr) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210265 AND `DifficultyID`=0); -- 210265 (Worker Bee) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=56647 WHERE (`Entry`=219415 AND `DifficultyID`=0); -- 219415 (Cooking Pot) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214673 AND `DifficultyID`=0); -- 214673 (Flavor Scientist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=217126 AND `DifficultyID`=0); -- 217126 (Over-Indulged Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `VerifiedBuild`=56647 WHERE (`Entry`=216088 AND `DifficultyID`=0); -- 216088 (Wenbrandt) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=56647 WHERE (`Entry`=218876 AND `DifficultyID`=0); -- 218876 (Rat) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=218671 AND `DifficultyID`=0); -- 218671 (Venture Co. Pyromaniac) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=56647 WHERE (`Entry`=218877 AND `DifficultyID`=0); -- 218877 (Cockroach) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=210269 AND `DifficultyID`=0); -- 210269 (Hired Muscle) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214920 AND `DifficultyID`=0); -- 214920 (Tasting Room Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=268435456, `VerifiedBuild`=56647 WHERE (`Entry`=214668 AND `DifficultyID`=0); -- 214668 (Venture Co. Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=56647 WHERE (`Entry`=210933 AND `DifficultyID`=0); -- 210933 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=48342 AND `DifficultyID`=1); -- 48342 (Goblin Cocktail) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=48343 AND `DifficultyID`=1); -- 48343 (Goblin Cocktail) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=48340 AND `DifficultyID`=1); -- 48340 (Drink Tray) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56647 WHERE (`Entry`=48341 AND `DifficultyID`=1); -- 48341 (Goblin Cocktail) - Sessile, Floating

-- Venture Co. Pyromaniac smart ai
SET @ENTRY := 218671;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+47));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(-(@CGUID+47), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 454194, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 454194 on self', '');

-- Path for Chef Chewie
SET @MOVERGUID := @CGUID+66;
SET @ENTRY := 214697;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Chef Chewie - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2645.4927, -4927.1436, 99.80399, NULL, 0),
(@PATH, 1, 2642.8948, -4924.9556, 99.80399, NULL, 0),
(@PATH, 2, 2640.2969, -4922.7676, 99.80399, NULL, 0),
(@PATH, 3, 2634.5183, -4909.578, 99.80399, NULL, 0),
(@PATH, 4, 2620.8403, -4902.566, 99.80399, NULL, 0),
(@PATH, 5, 2614.2908, -4895.9517, 99.80399, NULL, 10911),
(@PATH, 6, 2630.409, -4901.4517, 99.80399, NULL, 0),
(@PATH, 7, 2639.461, -4917.2554, 99.80399, NULL, 0),
(@PATH, 8, 2654.7126, -4929.816, 99.80399, NULL, 0),
(@PATH, 9, 2660.2595, -4946.521, 99.804, NULL, 8540),
(@PATH, 10, 2665.2102, -4930.4775, 99.80399, NULL, 0),
(@PATH, 11, 2670.1182, -4918.1353, 99.804, NULL, 0),
(@PATH, 12, 2673.2744, -4908.6895, 99.804, NULL, 10730),
(@PATH, 13, 2670.1423, -4920.3804, 99.804, NULL, 0),
(@PATH, 14, 2663.6165, -4938.9062, 99.804, NULL, 0),
(@PATH, 15, 2660.4106, -4945.3267, 99.804, NULL, 11145),
(@PATH, 16, 2652.4307, -4932.988, 99.80399, NULL, 0);

UPDATE `creature` SET `position_x`=2645.4927, `position_y`=-4927.1436, `position_z`=99.80399, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`,`auras`) VALUES
(@MOVERGUID, @PATH, 1, '434743 422354 18950');

-- Path for Tasting Room Attendant
SET @MOVERGUID := @CGUID+25;
SET @ENTRY := 214920;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Tasting Room Attendant - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2687.654, -4894.245, 99.803986, NULL, 0),
(@PATH, 1, 2688.9668, -4896.587, 99.80399, NULL, 0),
(@PATH, 2, 2690.2795, -4898.9287, 99.804, NULL, 0),
(@PATH, 3, 2692.349, -4901.398, 99.804, NULL, 0),
(@PATH, 4, 2693.0737, -4902.262, 99.80399, NULL, 0),
(@PATH, 5, 2687.5894, -4896.139, 99.803986, NULL, 0),
(@PATH, 6, 2686.816, -4886.533, 99.804, NULL, 0),
(@PATH, 7, 2689.197, -4876.0884, 99.80399, NULL, 7992),
(@PATH, 8, 2686.1953, -4882.1943, 99.804, NULL, 0),
(@PATH, 9, 2686.4062, -4889.0054, 99.80399, NULL, 0),
(@PATH, 10, 2687.3203, -4893.6494, 99.803986, NULL, 0);

UPDATE `creature` SET `position_x`=2687.654, `position_y`=-4894.245, `position_z`=99.803986, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '434685');

-- Path for Tasting Room Attendant
SET @MOVERGUID := @CGUID+45;
SET @ENTRY := 214920;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Tasting Room Attendant - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2619.215, -4921.4507, 99.80399, NULL, 0),
(@PATH, 1, 2616.1553, -4919.7236, 99.80399, NULL, 0),
(@PATH, 2, 2613.0955, -4917.9966, 99.80399, NULL, 0),
(@PATH, 3, 2610.5479, -4912.616, 99.80399, NULL, 0),
(@PATH, 4, 2609.381, -4901.4375, 99.80399, NULL, 0),
(@PATH, 5, 2610.1243, -4895.1475, 99.80399, NULL, 8620),
(@PATH, 6, 2610.9688, -4915.238, 99.80399, NULL, 0),
(@PATH, 7, 2617.7673, -4918.8647, 99.80399, NULL, 0),
(@PATH, 8, 2624.7666, -4922.5938, 99.80399, NULL, 7422);

UPDATE `creature` SET `position_x`=2619.215, `position_y`=-4921.4507, `position_z`=99.80399, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '434685');

-- Path for Tasting Room Attendant
SET @MOVERGUID := @CGUID+29;
SET @ENTRY := 214920;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Tasting Room Attendant - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2656.2214, -4907.672, 99.80399, NULL, 0),
(@PATH, 1, 2649.6753, -4904.7207, 99.80399, NULL, 0),
(@PATH, 2, 2644.9124, -4903.7207, 99.80399, NULL, 6790),
(@PATH, 3, 2656.4158, -4900.8267, 99.80399, NULL, 0),
(@PATH, 4, 2667.9487, -4898.7207, 99.80399, NULL, 8785),
(@PATH, 5, 2664.7014, -4905.7603, 99.80399, NULL, 0),
(@PATH, 6, 2663.3333, -4909.818, 99.80399, NULL, 8522);

UPDATE `creature` SET `position_x`=2656.2214, `position_y`=-4907.672, `position_z`=99.80399, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '434685');

-- Path for Hired Muscle
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+42;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+42, @CGUID+42, 0, 0, 515, 0, 0),
(@CGUID+42, @CGUID+31, 2, 90, 515, 0, 0);

SET @MOVERGUID := @CGUID+42;
SET @ENTRY := 210269;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Hired Muscle - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2666.3306, -4948.649, 99.80399, NULL, 8804),
(@PATH, 1, 2666.1821, -4947.625, 99.80399, NULL, 0),
(@PATH, 2, 2665.5046, -4942.9487, 99.804, NULL, 0),
(@PATH, 3, 2667.2722, -4940.4927, 99.804, NULL, 0),
(@PATH, 4, 2668.8936, -4938.0454, 99.804, NULL, 0),
(@PATH, 5, 2670.5525, -4935.4897, 99.804, NULL, 0),
(@PATH, 6, 2672.2114, -4932.934, 99.804, NULL, 0),
(@PATH, 7, 2673.8132, -4930.4575, 99.804, NULL, 0),
(@PATH, 8, 2675.378, -4927.861, 99.804, NULL, 0),
(@PATH, 9, 2676.952, -4925.249, 99.804, NULL, 0),
(@PATH, 10, 2677.889, -4922.9507, 99.804, NULL, 0),
(@PATH, 11, 2678.7493, -4920.0127, 99.804, NULL, 0),
(@PATH, 12, 2679.596, -4917.121, 99.804, NULL, 0),
(@PATH, 13, 2679.7366, -4914.556, 99.804, NULL, 0),
(@PATH, 14, 2679.898, -4911.531, 99.804, NULL, 0),
(@PATH, 15, 2680.0605, -4908.4873, 99.804, NULL, 0),
(@PATH, 16, 2680.0732, -4908.2476, 99.804, NULL, 8655),
(@PATH, 17, 2682.9692, -4912.8486, 99.804, NULL, 0),
(@PATH, 18, 2682.2039, -4915.7954, 99.804, NULL, 0),
(@PATH, 19, 2681.4526, -4918.7026, 99.804, NULL, 0),
(@PATH, 20, 2680.7207, -4921.6504, 99.804, NULL, 0),
(@PATH, 21, 2679.9863, -4924.608, 99.804, NULL, 0),
(@PATH, 22, 2679.2544, -4927.555, 99.804, NULL, 0),
(@PATH, 23, 2678.5188, -4930.5176, 99.804, NULL, 0),
(@PATH, 24, 2677.1343, -4933.97, 99.804, NULL, 0),
(@PATH, 25, 2675.3574, -4936.384, 99.804, NULL, 0),
(@PATH, 26, 2673.5505, -4938.839, 99.804, NULL, 0),
(@PATH, 27, 2671.7466, -4941.29, 99.804, NULL, 0),
(@PATH, 28, 2669.9324, -4943.755, 99.804, NULL, 0),
(@PATH, 29, 2668.1284, -4946.206, 99.804, NULL, 0);

UPDATE `creature` SET `position_x`=2666.3306, `position_y`=-4948.649, `position_z`=99.80399 WHERE `guid`= @CGUID+31;
UPDATE `creature` SET `position_x`=2666.3306, `position_y`=-4948.649, `position_z`=99.80399, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Over-Indulged Patron
SET @MOVERGUID := @CGUID+74;
SET @ENTRY := 217126;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Over-Indulged Patron - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2626.3462, -4926.673, 99.80399, NULL, 3329),
(@PATH, 1, 2627.6306, -4929.4805, 99.80399, NULL, 0),
(@PATH, 2, 2628.915, -4932.288, 99.80399, NULL, 0),
(@PATH, 3, 2629.904, -4933.342, 99.80399, NULL, 0),
(@PATH, 4, 2635.2378, -4939.0244, 99.803986, NULL, 0),
(@PATH, 5, 2640.3984, -4946.7065, 99.803986, NULL, 4724),
(@PATH, 6, 2635.5676, -4943.1943, 99.803986, NULL, 0),
(@PATH, 7, 2631.2456, -4937.597, 99.803986, NULL, 0),
(@PATH, 8, 2627.756, -4931.401, 99.80399, NULL, 0);

UPDATE `creature` SET `position_x`=2626.3462, `position_y`=-4926.673, `position_z`=99.80399, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '275612');

-- Path for Brew Master Aldryr
SET @MOVERGUID := @CGUID+79;
SET @ENTRY := 210271;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Brew Master Aldryr - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2645.8682, -4952.8613, 99.80401, 2.0703, 11510),
(@PATH, 1, 2652.9019, -4952.8022, 99.80401, NULL, 0),
(@PATH, 2, 2656.927, -4952.9116, 99.80399, 1.2847, 7563);

UPDATE `creature` SET `position_x`=2645.8682, `position_y`=-4952.8613, `position_z`=99.80401, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Taste Tester
SET @MOVERGUID := @CGUID+90;
SET @ENTRY := 220060;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Taste Tester - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2760.388, -4889.887, 103.00712, NULL, 0),
(@PATH, 1, 2761.0642, -4886.8125, 103.00712, NULL, 0),
(@PATH, 2, 2761.8682, -4884.222, 103.00712, NULL, 0),
(@PATH, 3, 2763.698, -4882.2397, 103.00712, NULL, 0),
(@PATH, 4, 2765.7551, -4879.8594, 103.00712, NULL, 1570),
(@PATH, 5, 2761.9973, -4884.222, 103.00712, NULL, 0),
(@PATH, 6, 2761.2058, -4886.2188, 103.00712, NULL, 0),
(@PATH, 7, 2760.3855, -4890.4707, 103.00712, NULL, 0),
(@PATH, 8, 2759.0754, -4892.538, 103.23541, NULL, 0),
(@PATH, 9, 2758.625, -4894.6997, 103.39775, NULL, 5330);

UPDATE `creature` SET `position_x`=2760.388, `position_y`=-4889.887, `position_z`=103.00712, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '287319');

-- Path for Careless Hopgoblin
SET @MOVERGUID := @CGUID+136;
SET @ENTRY := 223423;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Careless Hopgoblin - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2755.7236, -4885.49, 103.00712, NULL, 0),
(@PATH, 1, 2754.2727, -4885.513, 103.00712, NULL, 0),
(@PATH, 2, 2752.8218, -4885.536, 103.00712, NULL, 0),
(@PATH, 3, 2751.1892, -4885.5625, 103.00712, NULL, 0),
(@PATH, 4, 2749.8843, -4885.568, 103.00712, NULL, 0),
(@PATH, 5, 2746.051, -4885.5845, 103.00712, NULL, 0),
(@PATH, 6, 2733.3242, -4885.639, 103.007126, NULL, 0),
(@PATH, 7, 2732.9497, -4885.6406, 103.007126, NULL, 3613),
(@PATH, 8, 2751.1892, -4885.5625, 103.00712, NULL, 0),
(@PATH, 9, 2768.73, -4885.2812, 103.00711, NULL, 0),
(@PATH, 10, 2781.929, -4885.993, 103.007126, NULL, 0),
(@PATH, 11, 2794.9133, -4886.5503, 103.007126, NULL, 0),
(@PATH, 12, 2802.6328, -4887.316, 103.12594, NULL, 3697),
(@PATH, 13, 2794.9133, -4886.5503, 103.007126, NULL, 0),
(@PATH, 14, 2781.929, -4885.993, 103.007126, NULL, 0),
(@PATH, 15, 2768.73, -4885.2812, 103.00711, NULL, 0);

UPDATE `creature` SET `position_x`=2755.7236, `position_y`=-4885.49, `position_z`=103.00712, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '448943 449106 18950');

-- Path for Careless Hopgoblin
SET @MOVERGUID := @CGUID+182;
SET @ENTRY := 223423;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Careless Hopgoblin - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2742.434, -4991.3774, 99.80639, NULL, 0),
(@PATH, 1, 2746.405, -4989.78, 99.80519, NULL, 0),
(@PATH, 2, 2750.376, -4988.182, 99.80399, NULL, 0),
(@PATH, 3, 2751.3833, -4988.132, 99.80399, NULL, 0),
(@PATH, 4, 2758.3645, -4987.7847, 99.803986, NULL, 2371),
(@PATH, 5, 2750.376, -4988.182, 99.80399, NULL, 0),
(@PATH, 6, 2741.8481, -4991.613, 99.86812, NULL, 0),
(@PATH, 7, 2732.2136, -4991.9966, 99.89162, NULL, 0),
(@PATH, 8, 2724.9446, -4987.1753, 99.86972, NULL, 0),
(@PATH, 9, 2717.948, -4987.0767, 99.850975, NULL, 2364),
(@PATH, 10, 2724.9446, -4987.1753, 99.86972, NULL, 0),
(@PATH, 11, 2732.2136, -4991.9966, 99.89162, NULL, 0),
(@PATH, 12, 2741.8481, -4991.613, 99.86812, NULL, 0);

UPDATE `creature` SET `position_x`=2742.434, `position_y`=-4991.3774, `position_z`=99.80639, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '448943 449106 18950');

-- Path for Careless Hopgoblin
SET @MOVERGUID := @CGUID+121;
SET @ENTRY := 223423;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Careless Hopgoblin - Cosmetic');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2758.4714, -4956.802, 99.80398, NULL, 0),
(@PATH, 1, 2746.3733, -4959.4956, 99.803986, NULL, 0),
(@PATH, 2, 2734.2751, -4962.1895, 99.80399, NULL, 0),
(@PATH, 3, 2728.1892, -4962.4565, 99.804, NULL, 0),
(@PATH, 4, 2723.39, -4962.3315, 99.804, NULL, 4046),
(@PATH, 5, 2728.1892, -4962.4565, 99.804, NULL, 0),
(@PATH, 6, 2734.2751, -4962.1895, 99.80399, NULL, 0),
(@PATH, 7, 2742.1165, -4960.432, 99.80399, NULL, 0),
(@PATH, 8, 2749.3342, -4958.8438, 99.803986, NULL, 2797);

UPDATE `creature` SET `position_x`=2742.434, `position_y`=-4991.3774, `position_z`=99.80639, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '448943 449106 18950');

-- Path for Flavor Scientist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+193;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+193, @CGUID+193, 0, 0, 515, 6, 10),
(@CGUID+193, @CGUID+197, 3, 270, 515, 6, 10),
(@CGUID+193, @CGUID+190, 3, 90, 515, 6, 10);

SET @MOVERGUID := @CGUID+193;
SET @ENTRY := 214673;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Flavor Scientist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2807.8447, -4949.8755, 102.84695, NULL, 0),
(@PATH, 1, 2807.8838, -4948.549, 101.866104, NULL, 0),
(@PATH, 2, 2807.9229, -4947.222, 100.88526, NULL, 0),
(@PATH, 3, 2808.007, -4944.3525, 100.903175, NULL, 0),
(@PATH, 4, 2806.9307, -4934.8594, 100.83581, NULL, 0),
(@PATH, 5, 2807.5894, -4922.8403, 100.90097, NULL, 0),
(@PATH, 6, 2807.5088, -4914.2725, 100.81581, NULL, 2926),
(@PATH, 7, 2807.5894, -4922.8403, 100.90097, NULL, 0),
(@PATH, 8, 2806.9307, -4934.8594, 100.83581, NULL, 0),
(@PATH, 9, 2808.007, -4944.3525, 100.903175, NULL, 0),
(@PATH, 10, 2807.6477, -4956.578, 100.84344, NULL, 1572);

UPDATE `creature` SET `position_x`=2807.8447, `position_y`=-4949.8755, `position_z`=102.84695, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '448487 448491');

-- Path for Flavor Scientist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+118;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+118, @CGUID+118, 0, 0, 515, 1, 0),
(@CGUID+118, @CGUID+106, 2, 270, 515, 1, 0),
(@CGUID+118, @CGUID+103, 2, 40, 515, 1, 0),
(@CGUID+118, @CGUID+98, 2, 320, 515, 1, 0);

SET @MOVERGUID := @CGUID+118;
SET @ENTRY := 222964;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Flavor Scientist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2753.39, -4923.96, 100.85059, NULL, 11809),
(@PATH, 1, 2769.39, -4924.04, 100.803986, NULL, 10596);

UPDATE `creature` SET `position_x`=2753.39, `position_y`=-4923.96, `position_z`=100.85059, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '448487 448491');

-- Path for Venture Co Honey Harvester
SET @MOVERGUID := @CGUID+114;
SET @ENTRY := 220946;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Venture Co. Honey Harvester - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2547.9644, -4924.809, 99.90516, NULL, 0),
(@PATH, 1, 2538.309, -4924.682, 99.804, NULL, 0),
(@PATH, 2, 2531.4688, -4924.809, 99.854744, NULL, 0),
(@PATH, 3, 2525.5642, -4924.684, 99.87205, NULL, 2249),
(@PATH, 4, 2531.4688, -4924.809, 99.854744, NULL, 0),
(@PATH, 5, 2538.309, -4924.682, 99.804, NULL, 0),
(@PATH, 6, 2547.951, -4924.809, 99.905594, NULL, 0),
(@PATH, 7, 2556.3542, -4924.6665, 99.803986, NULL, 3489);

UPDATE `creature` SET `position_x`=2547.9644, `position_y`=-4924.809, `position_z`=99.90516, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '422360 18950');

-- Path for Venture Co Honey Harvester
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+264;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+264, @CGUID+264, 0, 0, 515, 1, 0),
(@CGUID+264, @CGUID+271, 2, 90, 515, 1, 0);

SET @MOVERGUID := @CGUID+264;
SET @ENTRY := 220946;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Venture Co. Honey Harvester - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2541.1416, -5068.0156, 100.19462, NULL, 2155),
(@PATH, 1, 2526.6528, -5055.9097, 100.19461, NULL, 2136);

UPDATE `creature` SET `position_x`=2541.1416, `position_y`=-5068.0156, `position_z`=100.19462, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '422360 18950');

-- Path for Venture Co Honey Harvester
SET @MOVERGUID := @CGUID+184;
SET @ENTRY := 220946;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Venture Co. Honey Harvester - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2513.9426, -4962.502, 99.90725, NULL, 0),
(@PATH, 1, 2514.3933, -4952.4497, 99.87366, NULL, 0),
(@PATH, 2, 2514.3577, -4945.512, 99.857994, NULL, 0),
(@PATH, 3, 2514.3125, -4939.7744, 99.84522, NULL, 2790),
(@PATH, 4, 2514.3577, -4945.512, 99.857994, NULL, 0),
(@PATH, 5, 2514.3933, -4952.4497, 99.87366, NULL, 0),
(@PATH, 6, 2513.9426, -4962.502, 99.90725, NULL, 0),
(@PATH, 7, 2514.1182, -4981.097, 99.80496, NULL, 2873);

UPDATE `creature` SET `position_x`=2513.9426, `position_y`=-4962.502, `position_z`=99.90725, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '422360 18950');
