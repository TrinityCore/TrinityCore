SET @CGUID := 10004462;
SET @OGUID := 10001058;

SET @NPCTEXTID := 600038;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+39;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5812.705078125, -3027.619873046875, 210.525146484375, 4.444715023040771484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 392617 - Dragonspawn Channel Omni 50%, Blue [DNT])
(@CGUID+1, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5801.19091796875, -3038.998291015625, 210.579681396484375, 1.730684518814086914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT])
(@CGUID+2, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5815.765625, -3068.510498046875, 211.6707763671875, 3.692539453506469726, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+3, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5779.41650390625, -3038.338623046875, 210.517425537109375, 2.54568791389465332, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura)
(@CGUID+4, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5769.02197265625, -3066.76171875, 211.7526397705078125, 3.657093763351440429, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura)
(@CGUID+5, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5811.5703125, -3091.592041015625, 211.7563934326171875, 5.914660930633544921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+6, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5788.3818359375, -2991.91845703125, 210.517425537109375, 0.471630364656448364, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel)
(@CGUID+7, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5785.6259765625, -3042.078125, 210.517425537109375, 1.560038208961486816, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura)
(@CGUID+8, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5772.4296875, -3087.0400390625, 211.69256591796875, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+9, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5720.4599609375, -2996.00341796875, 211.63836669921875, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+10, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5829.27978515625, -3040.20654296875, 211.5830841064453125, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+11, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5777.384765625, -3012.901123046875, 210.623443603515625, 2.855153560638427734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura)
(@CGUID+12, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5811.8818359375, -3084.1494140625, 211.54327392578125, 3.634238481521606445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel)
(@CGUID+13, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5751.52001953125, -3040.314208984375, 210.750335693359375, 3.703835725784301757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+14, 231436, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5847.1943359375, -3022.866455078125, 251.130401611328125, 3.132126808166503906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Stasis-Locked Obsidian Warder (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465756 - Stasis Dracthyr - Spawn Aura, 362331 - Stasis)
(@CGUID+15, 231436, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5724.29248046875, -3046.75341796875, 211.5432586669921875, 0.467626571655273437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Stasis-Locked Obsidian Warder (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465756 - Stasis Dracthyr - Spawn Aura, 362331 - Stasis)
(@CGUID+16, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5762.76220703125, -3004.56591796875, 210.517425537109375, 2.273596525192260742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel)
(@CGUID+17, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5768.22412109375, -2982.927001953125, 211.777374267578125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+18, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5820.85693359375, -3006.520751953125, 210.743621826171875, 3.882602214813232421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT])
(@CGUID+19, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5820.70068359375, -3009.423583984375, 210.731292724609375, 1.935643672943115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT])
(@CGUID+20, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5802.1962890625, -3045.739501953125, 210.517425537109375, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+21, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5812.09912109375, -2999.84716796875, 210.7043914794921875, 1.859863758087158203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel)
(@CGUID+22, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5823.62841796875, -3019.432373046875, 210.9457244873046875, 3.118480682373046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 374153 - Channel: Read Floating Book (Dragon) [DNT])
(@CGUID+23, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5807.37060546875, -3086.27783203125, 211.543243408203125, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+24, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5806.2568359375, -3043.723876953125, 210.517425537109375, 2.141343355178833007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura)
(@CGUID+25, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5803.2490234375, -3038.720458984375, 210.517425537109375, 2.316331863403320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT])
(@CGUID+26, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5807.81005859375, -2994.116455078125, 210.8588409423828125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+27, 229075, 2785, 15509, 15510, '0', 24727, 0, 0, 0, 5751.6162109375, -3023.958251953125, 250.304931640625, 3.106686115264892578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Scalecommander Emberthal (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+28, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5810.99560546875, -3013.853759765625, 210.4547882080078125, 1.935326814651489257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 386797 - Channel: Carry Explorers League Supplies (Crate,Barrel,Jug,Scrolls) [DNT])
(@CGUID+29, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5765.26904296875, -3088.19091796875, 211.543243408203125, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+30, 231436, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5827.681640625, -2981.892333984375, 251.1304168701171875, 3.873660087585449218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Stasis-Locked Obsidian Warder (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465756 - Stasis Dracthyr - Spawn Aura, 362331 - Stasis)
(@CGUID+31, 231436, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5842.18994140625, -3041.23779296875, 211.543304443359375, 3.077945232391357421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Stasis-Locked Obsidian Warder (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465756 - Stasis Dracthyr - Spawn Aura, 362331 - Stasis)
(@CGUID+32, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5759.38623046875, -3073.125, 211.5432586669921875, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+33, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5817.931640625, -3007.40625, 210.714141845703125, 0.014193050563335418, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT])
(@CGUID+34, 230635, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5731.1474609375, -3010.123291015625, 211.543243408203125, 3.703835964202880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Enchanted Broom (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+35, 230648, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5740.552734375, -3005.154052734375, 211.653839111328125, 2.714114189147949218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Obsidian Warder Custodian (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura)
(@CGUID+36, 231544, 2785, 15509, 15510, '0', 24739, 0, 0, 0, 5810.86474609375, -3036.953125, 210.517425537109375, 2.34015965461730957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Scalecommander Cindrethresh (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+37, 231436, 2785, 15509, 15510, '0', 0, 0, 0, 0, 5828.64501953125, -3065.22216796875, 251.130340576171875, 2.295064687728881835, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Stasis-Locked Obsidian Warder (Area: The War Creche - Difficulty: 0) CreateObject1 (Auras: 465756 - Stasis Dracthyr - Spawn Aura, 362331 - Stasis)
(@CGUID+38, 231540, 2785, 15509, 15510, '0', 24740, 0, 0, 0, 5810.6103515625, -3036.677001953125, 210.517425537109375, 2.320264101028442382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534), -- Scalecommander Azurathel (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+39, 229075, 2785, 15509, 15510, '0', 24726, 0, 0, 0, 5777.5380859375, -3024.177001953125, 210.498260498046875, 0.084208622574806213, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57534); -- Scalecommander Emberthal (Area: The War Creche - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+39;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 392617'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 392617 - Dragonspawn Channel Omni 50%, Blue [DNT]
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 364146'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT]
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 364146'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT]
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 364146'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT]
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 267221 - Kneel/Use Standing Channel
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 374153'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 374153 - Channel: Read Floating Book (Dragon) [DNT]
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '465709 465695'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 364146'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT]
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695 364146'), -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura, 364146 - Channel: Drink Bottle (SitGround) [DNT]
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465709 465695'); -- Obsidian Warder Custodian - 465709 - Dracthyr Custodian - Spawn Aura - Alliance, 465695 - Dracthyr Custodian - Spawn Aura

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+22;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 377591, 2785, 15509, 15510, '0', 0, 0, 5797.75927734375, -2897.719482421875, 207.07818603515625, 6.03359079360961914, 0, 0, -0.12447357177734375, 0.992222905158996582, 120, 255, 1, 57534), -- Lingering Everflame (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+1, 377596, 2785, 15509, 15510, '0', 0, 0, 5794.10498046875, -3093.44287109375, 263.763824462890625, 2.167680978775024414, 0, 0, 0.883761405944824218, 0.467937797307968139, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+2, 377601, 2785, 15509, 15510, '0', 0, 0, 5712.94287109375, -3023.697509765625, 263.107757568359375, 6.225575447082519531, 0, 0, -0.02880096435546875, 0.999585151672363281, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+3, 377599, 2785, 15509, 15510, '0', 0, 0, 5734.8740234375, -3075.489990234375, 263.107757568359375, 0.736512541770935058, 0, 0, 0.359989166259765625, 0.932956516742706298, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+4, 377592, 2785, 15509, 15510, '0', 0, 0, 5814.96630859375, -3086.807373046875, 211.436279296875, 6.03359079360961914, 0, 0, -0.12447357177734375, 0.992222905158996582, 120, 255, 1, 57534), -- Lingering Everflame (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+5, 377594, 2785, 15509, 15510, '0', 0, 0, 5779.7666015625, -3093.101318359375, 263.763824462890625, 0.902321338653564453, 0, 0, 0.436010360717773437, 0.899941682815551757, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+6, 378891, 2785, 15509, 15510, '0', 0, 0, 5808.0087890625, -2990.225830078125, 210.8043365478515625, 5.112595081329345703, 0, 0, -0.5524454116821289, 0.833549082279205322, 120, 255, 1, 57534), -- Explorer's Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+7, 375503, 2785, 15509, 15510, '0', 0, 0, 5736.240234375, -3035.570068359375, 252.6009979248046875, 2.157087326049804687, 0, 0, 0.881270408630371093, 0.472612351179122924, 120, 255, 1, 57534), -- Edict: Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+8, 462378, 2785, 15509, 15510, '0', 0, 0, 5802.96337890625, -2981.385498046875, 209.9539337158203125, 1.257520079612731933, 0, 0, 0.58814239501953125, 0.808757364749908447, 120, 255, 1, 57534), -- Door (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+9, 376748, 2785, 15509, 15510, '0', 0, 0, 5803.82666015625, -2991.28125, 210.6916961669921875, 5.112595081329345703, 0, 0, -0.5524454116821289, 0.833549082279205322, 120, 255, 1, 57534), -- Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+10, 381460, 2785, 15509, 15510, '0', 0, 0, 5758.86474609375, -3067.986083984375, 211.6034698486328125, 5.269672393798828125, 0, 0, -0.48534393310546875, 0.87432330846786499, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+11, 381460, 2785, 15509, 15510, '0', 0, 0, 5742.40185546875, -2995.270751953125, 211.6260528564453125, 3.541172981262207031, 0, 0, -0.98010826110839843, 0.198463648557662963, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+12, 376744, 2785, 15509, 15510, '0', 0, 0, 5803.4599609375, -2989.03466796875, 210.719879150390625, 0, 0, 0, 0, 1, 120, 255, 1, 57534), -- Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+13, 381460, 2785, 15509, 15510, '0', 0, 0, 5734.640625, -3016.100830078125, 251.1759490966796875, 3.33856058120727539, 0, 0, -0.99515438079833984, 0.098324738442897796, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+14, 376744, 2785, 15509, 15510, '0', 0, 0, 5806.13037109375, -2991.045166015625, 210.7659454345703125, 5.400973320007324218, 0, 0, -0.42693996429443359, 0.904279947280883789, 120, 255, 1, 57534), -- Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+15, 378891, 2785, 15509, 15510, '0', 0, 0, 5801.62744140625, -2990.32470703125, 210.6977691650390625, 5.112595081329345703, 0, 0, -0.5524454116821289, 0.833549082279205322, 120, 255, 1, 57534), -- Explorer's Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+16, 381460, 2785, 15509, 15510, '0', 0, 0, 5798.0068359375, -3074.310791015625, 211.6244659423828125, 6.005605697631835937, 0, 0, -0.13834476470947265, 0.990384101867675781, 120, 255, 1, 57534), -- Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+17, 378891, 2785, 15509, 15510, '0', 0, 0, 5804.8818359375, -2990.145751953125, 210.71173095703125, 5.112595081329345703, 0, 0, -0.5524454116821289, 0.833549082279205322, 120, 255, 1, 57534), -- Explorer's Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+18, 378891, 2785, 15509, 15510, '0', 0, 0, 5802.5166015625, -2986.454833984375, 210.7381134033203125, 5.726742744445800781, 0, 0, -0.27464580535888671, 0.961545467376708984, 120, 255, 1, 57534), -- Explorer's Crate (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+19, 467064, 2785, 15509, 15510, '0', 0, 0, 5806.5234375, -3039.369873046875, 212.0197296142578125, 5.435505867004394531, 0, 0, -0.41126346588134765, 0.911516487598419189, 120, 255, 1, 57534), -- Quest Journal (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+20, 377897, 2785, 15509, 15510, '0', 0, 0, 5901.9482421875, -2910.326171875, 207.1034393310546875, 5.143473625183105468, 0, 0, -0.53951072692871093, 0.841978728771209716, 120, 255, 1, 57534), -- Lingering Everflame (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+21, 462394, 2785, 15509, 15510, '0', 24592, 0, 5811.88037109375, -3032.545166015625, 210.4381866455078125, 5.9085235595703125, 0, 0, -0.18623733520507812, 0.982504785060882568, 120, 255, 1, 57534), -- Portal to Stormwind (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+22, 467029, 2785, 15509, 15510, '0', 24593, 0, 5811.88037109375, -3032.545166015625, 210.4381866455078125, 5.9085235595703125, 0, 0, -0.18623733520507812, 0.982504785060882568, 120, 255, 1, 57534); -- Portal to Orgrimmar (Area: The War Creche - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+22;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Lingering Everflame
(@OGUID+1, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Obsidian Warders
(@OGUID+2, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Obsidian Warders
(@OGUID+3, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Obsidian Warders
(@OGUID+4, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Lingering Everflame
(@OGUID+5, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Obsidian Warders
(@OGUID+20, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Lingering Everflame
(@OGUID+21, 0, 0, 0, 1, 0, 16743), -- Portal to Stormwind
(@OGUID+22, 0, 0, 0, 1, 0, 16743); -- Portal to Orgrimmar

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (231436 /*231436 (Stasis-Locked Obsidian Warder) - Stasis Dracthyr - Spawn Aura, Stasis*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(231436, 0, 0, 0, 0, 0, 1, 0, 0, 23987, 0, 0, 0, '465756 362331'); -- 231436 (Stasis-Locked Obsidian Warder) - Stasis Dracthyr - Spawn Aura, Stasis

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (467029 /*Portal to Orgrimmar*/, 462394 /*Portal to Stormwind*/, 467064 /*Quest Journal*/, 376748 /*Crate*/, 376744 /*Crate*/, 378891 /*Explorer's Crate*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(467029, 0, 0x0, 0, 16743), -- Portal to Orgrimmar
(462394, 0, 0x0, 0, 16743), -- Portal to Stormwind
(467064, 0, 0x204000, 0, 0), -- Quest Journal
(376748, 1375, 0x20, 0, 0), -- Crate
(376744, 1375, 0x20, 0, 0), -- Crate
(378891, 0, 0x20, 0, 0); -- Explorer's Crate

-- Template
UPDATE `creature_template` SET `faction`=3340, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=231540; -- Scalecommander Azurathel
UPDATE `creature_template` SET `faction`=188, `npcflag`=2, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=209681; -- Squally
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=229075; -- Scalecommander Emberthal
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x80200 WHERE `entry`=231436; -- Stasis-Locked Obsidian Warder
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=231544; -- Scalecommander Cindrethresh
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x1000000 WHERE `entry`=230635; -- Enchanted Broom
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=230648; -- Obsidian Warder Custodian

DELETE FROM `gameobject_template` WHERE `entry` IN (467064 /*Quest Journal*/, 467029 /*Portal to Orgrimmar*/, 462394 /*Portal to Stormwind*/, 470000 /*Edict: Dark Talons*/, 462378 /*Door*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(467064, 3, 74795, 'Quest Journal', 'questinteract', '', '', 1, 2124, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128210, 0, 0, 0, 0, 2991, 57534), -- Quest Journal
(467029, 22, 66649, 'Portal to Orgrimmar', 'questinteract', '', '', 1, 464441, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2991, 57534), -- Portal to Orgrimmar
(462394, 22, 66650, 'Portal to Stormwind', 'questinteract', '', '', 1, 461393, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2991, 57534), -- Portal to Stormwind
(470000, 9, 73022, 'Edict: Dark Talons', '', '', '', 2, 8606, 11, 2, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57534), -- Edict: Dark Talons
(462378, 5, 74399, 'Door', 'questinteract', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2799, 57534); -- Door

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=28332 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(28332, 0, 0, 57534);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=24255 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(24255, 0, 28332, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 57534); -- Spell: 362331 (Stasis)

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=3502;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3502, 0, 4373, 0);

-- Gameobject Loot
DELETE FROM `gameobject_loot_template` WHERE `Entry` = 128210;
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(128210, 0, 229165, 100, 1, 1, 0, 1, 1, 'Quest Journal');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=231540 AND `MenuID`=36614) OR (`CreatureID`=231544 AND `MenuID`=36617) OR (`CreatureID`=229075 AND `MenuID`=36466);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(231540, 36614, 57534), -- Scalecommander Azurathel
(231544, 36617, 57534), -- Scalecommander Cindrethresh
(229075, 36466, 57534); -- Scalecommander Emberthal

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 272766, 0, 0, 0, 0, 0, 0, 0, 57534), -- 231540 (Scalecommander Azurathel)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 271447, 0, 0, 0, 0, 0, 0, 0, 57534), -- 229075 (Scalecommander Emberthal)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 272775, 0, 0, 0, 0, 0, 0, 0, 57534); -- 231544 (Scalecommander Cindrethresh)

DELETE FROM `gossip_menu` WHERE (`MenuID`=36614 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=36466 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=36617 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36614, @NPCTEXTID+0, 57534), -- 231540 (Scalecommander Azurathel)
(36466, @NPCTEXTID+1, 57534), -- 229075 (Scalecommander Emberthal)
(36617, @NPCTEXTID+2, 57534); -- 231544 (Scalecommander Cindrethresh)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=36466 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(36466, 124402, 0, 0, 'What\'s happened since I slept?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57534);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (36466));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 36466, 0, 0, 0, 9, 0, 84424, 0, 0, '', 0, 'Player for which gossip text is shown has quest Forward, To Adventure! (84424) active'),
(15, 36466, 0, 0, 0, 48, 0, 453265, 0, 1, '', 1, 'Player for which gossip text is shown has quest objective 453265 == 1 (but hasn\'t rewarded quest yet)');

-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (24592,24593,24740,24739,24727,24726);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(24592, 'Cosmetic - See Portal to Stormwind'),
(24593, 'Cosmetic - See Portal to Orgrimmar'),
(24740, 'Cosmetic - See Scalecommander Azurathel'),
(24739, 'Cosmetic - See Scalecommander Cindrethresh'),
(24727, 'Cosmetic - See Scalecommander Emberthal (up)'),
(24726, 'Cosmetic - See Scalecommander Emberthal (down)');

DELETE FROM `phase_area` WHERE `PhaseId` IN (24592,24593,24740,24739,24727,24726); 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(15509, 24592, 'Cosmetic - See Portal to Stormwind'),
(15509, 24593, 'Cosmetic - See Portal to Orgrimmar'),
(15509, 24740, 'Cosmetic - See Scalecommander Azurathel'),
(15509, 24739, 'Cosmetic - See Scalecommander Cindrethresh)'),
(15509, 24727, 'Cosmetic - See Scalecommander Emberthal (up)'),
(15509, 24726, 'Cosmetic - See Scalecommander Emberthal (down)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (24592,24593,24740,24739,24727,24726) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 24727, 0, 0, 0, 47, 0, 84424, 2|8|64, 0, 1, 'Apply Phase 24727 if Quest 84424 is not taken | complete | rewarded'),
(26, 24726, 0, 0, 0, 47, 0, 84424, 2|8|64, 0, 0, 'Apply Phase 24726 if Quest 84424 is taken | complete | rewarded'),
(26, 24592, 0, 0, 0, 47, 0, 84424, 2|8|64, 0, 0, 'Apply Phase 24592 if Quest 84424 is taken | complete | rewarded'),
(26, 24593, 0, 0, 0, 47, 0, 84424, 2|8|64, 0, 0, 'Apply Phase 24593 if Quest 84424 is taken | complete | rewarded'),
(26, 24740, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Apply Phase 24740 if player is Alliance'),
(26, 24739, 0, 0, 0, 6, 0, 67, 0, 0, 0, 'Apply Phase 24739 if player is Horde');

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID`=84423;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(84423, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome back to the land of the living, $c. \n\nThere is much for you to catch up on.', 57534); -- Shaking the Dust Off

DELETE FROM `quest_details` WHERE `ID` IN (82672 /*Another Timely Invitation*/, 84424 /*Forward, To Adventure!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(82672, 0, 0, 0, 0, 0, 0, 0, 0, 57534), -- Another Timely Invitation
(84424, 1, 0, 0, 0, 0, 0, 0, 0, 57534); -- Forward, To Adventure!

DELETE FROM `creature_queststarter` WHERE (`id`=229075 AND `quest`=84424);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(229075, 84424, 57534); -- Forward, To Adventure! offered by Scalecommander Emberthal

DELETE FROM `creature_questender` WHERE (`id`=229075 AND `quest`=84423);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(229075, 84423, 57534); -- Shaking the Dust Off ended by Scalecommander Emberthal

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=2373 AND `QuestLineId`=5676);
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(2373, 5676, 57534);

DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2373 AND `QuestId`=84423);
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2373, 84423, 57534); -- Shaking the Dust Off

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (107471, 111078, 107469);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(107471, 0.722000002861022949, 2, 0, 57534),
(111078, 0.866400063037872314, 2.40000009536743164, 0, 57534),
(107469, 0.722000002861022949, 2, 0, 57534);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2991, `StaticFlags1`=0x10000000, `VerifiedBuild`=57534 WHERE (`Entry`=231540 AND `DifficultyID`=0); -- 231540 (Scalecommander Azurathel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x30000000, `VerifiedBuild`=57534 WHERE (`Entry`=209681 AND `DifficultyID`=0); -- 209681 (Squally) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=0x10000000, `VerifiedBuild`=57534 WHERE (`Entry`=229075 AND `DifficultyID`=0); -- 229075 (Scalecommander Emberthal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2991, `StaticFlags1`=0x10000100, `StaticFlags3`=0x40000, `VerifiedBuild`=57534 WHERE (`Entry`=231436 AND `DifficultyID`=0); -- 231436 (Stasis-Locked Obsidian Warder) - Sessile, CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2991, `StaticFlags1`=0x10000000, `VerifiedBuild`=57534 WHERE (`Entry`=231544 AND `DifficultyID`=0); -- 231544 (Scalecommander Cindrethresh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags3`=0x2000000, `VerifiedBuild`=57534 WHERE (`Entry`=230635 AND `DifficultyID`=0); -- 230635 (Enchanted Broom) - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2991, `StaticFlags1`=0x10000000, `VerifiedBuild`=57534 WHERE (`Entry`=230648 AND `DifficultyID`=0); -- 230648 (Obsidian Warder Custodian) - CanSwim

 -- Obsidian Warder Custodian smart ai
SET @ENTRY := 230648;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+6), -(@CGUID+12), -(@CGUID+16), -(@CGUID+21), -(@CGUID+22), -(@CGUID+28), -(@CGUID+35), -(@CGUID+4));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(-(@CGUID+6), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 267221, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 267221 on Self', ''),
(-(@CGUID+12), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 267221, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 267221 on Self', ''),
(-(@CGUID+16), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 267221, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 267221 on Self', ''),
(-(@CGUID+21), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 267221, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 267221 on Self', ''),
(-(@CGUID+22), 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 374153, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 374153 on Self', ''),
(-(@CGUID+28), 0, 0, 0, 34, 0, 100, 0, 2, 0, 0, 0, 0, 80, 23064801, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #Obsidian Warder Custodian #1 (23064801) (update out of combat)', ''),
(-(@CGUID+28), 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 0, 80, 23064800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #Obsidian Warder Custodian #0 (23064800) (update out of combat)', ''),
(-(@CGUID+35), 0, 0, 0, 34, 0, 100, 0, 2, 5, 0, 0, 0, 80, 23064801, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 5 - Self: Start timed action list id #Obsidian Warder Custodian #1 (23064801) (update out of combat)', ''),
(-(@CGUID+35), 0, 1, 0, 34, 0, 100, 0, 2, 1, 0, 0, 0, 80, 23064800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Obsidian Warder Custodian #0 (23064800) (update out of combat)', ''),
(-(@CGUID+4), 0, 0, 0, 34, 0, 100, 0, 2, 20, 0, 0, 0, 80, 23064801, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 20 - Self: Start timed action list id #Obsidian Warder Custodian #1 (23064801) (update out of combat)', ''),
(-(@CGUID+4), 0, 1, 0, 34, 0, 100, 0, 2, 6, 0, 0, 0, 80, 23064800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #Obsidian Warder Custodian #0 (23064800) (update out of combat)', '');

-- Timed list 23064800 smart ai
SET @ENTRY := 23064800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 11, 386797, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast spell  386797 on Self', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 91, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove stand state STAND', '');

-- Timed list 23064801 smart ai
SET @ENTRY := 23064801;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 28, 386797, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell  386797', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 91, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Remove stand state STAND', '');

-- Path for Obsidian Warder Custodian
SET @MOVERGUID := @CGUID+28;
SET @ENTRY := 230648;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Obsidian Warder Custodian - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5804.416, -2993.1008, 210.94255, NULL, 5081),
(@PATH, 1, 5812.6553, -3011.1807, 210.8172, NULL, 0),
(@PATH, 2, 5817.8604, -3026.8352, 210.87814, NULL, 0),
(@PATH, 3, 5814.5527, -3044.444, 211.00539, NULL, 4686),
(@PATH, 4, 5816.35, -3027.8855, 210.57262, NULL, 0),
(@PATH, 5, 5808.8457, -3008.2205, 210.55844, NULL, 0);

UPDATE `creature` SET `position_x`=5804.416, `position_y`=-2993.1008, `position_z`=210.94255, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Obsidian Warder Custodian
SET @MOVERGUID := @CGUID+35;
SET @ENTRY := 230648;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Obsidian Warder Custodian - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5736.4575, -3003.2883, 211.54863, NULL, 0),
(@PATH, 1, 5719.309, -2999.139, 211.8094, NULL, 4792),
(@PATH, 2, 5752.269, -3008.3958, 210.82245, NULL, 0),
(@PATH, 3, 5767.7065, -3007.3906, 210.51595, NULL, 0),
(@PATH, 4, 5785.462, -3000.2136, 210.54874, NULL, 0),
(@PATH, 5, 5800.182, -2990.8906, 210.84962, NULL, 5014),
(@PATH, 6, 5789.5337, -2997.0452, 210.4561, NULL, 0),
(@PATH, 7, 5776.8115, -3002.014, 210.52242, NULL, 0),
(@PATH, 8, 5769.308, -3004.8977, 210.53537, NULL, 0),
(@PATH, 9, 5758.649, -3010.7393, 211.02902, NULL, 0),
(@PATH, 10, 5745.9766, -3007.625, 211.67764, NULL, 0);

UPDATE `creature` SET `position_x`=5736.4575, `position_y`=-3003.2883, `position_z`=211.54863, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Obsidian Warder Custodian
SET @MOVERGUID := @CGUID+4;
SET @ENTRY := 230648;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, NULL, 'Obsidian Warder Custodian - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5785.9966, -3023.2188, 210.5412, NULL, 0),
(@PATH, 1, 5782.518, -3027.6145, 210.5227, NULL, 0),
(@PATH, 2, 5781.9966, -3036.9531, 210.60121, NULL, 0),
(@PATH, 3, 5780.126, -3045.842, 210.52669, NULL, 0),
(@PATH, 4, 5769.298, -3065.9236, 211.82315, NULL, 0),
(@PATH, 5, 5763.241, -3070.0364, 211.70564, NULL, 0),
(@PATH, 6, 5758.965, -3070.6396, 211.47305, NULL, 4468),
(@PATH, 7, 5768.0522, -3070.3352, 211.62875, NULL, 0),
(@PATH, 8, 5770.0386, -3065.0388, 211.85017, NULL, 0),
(@PATH, 9, 5771.854, -3059.236, 210.76627, NULL, 0),
(@PATH, 10, 5771.7173, -3047.3074, 210.47159, NULL, 0),
(@PATH, 11, 5767.424, -3033.0486, 210.61974, NULL, 0),
(@PATH, 12, 5770.566, -3022.606, 210.51762, NULL, 0),
(@PATH, 13, 5778.3374, -3017.2854, 210.7196, NULL, 0),
(@PATH, 14, 5788.954, -3009.1165, 210.5777, NULL, 0),
(@PATH, 15, 5799.039, -2998.1477, 210.48505, NULL, 0),
(@PATH, 16, 5799.99, -2996.8982, 210.48602, NULL, 0),
(@PATH, 17, 5801.2134, -2995.292, 210.41139, NULL, 0),
(@PATH, 18, 5801.4526, -2994.9778, 210.55629, NULL, 0),
(@PATH, 19, 5801.6133, -2994.7668, 210.53221, NULL, 0),
(@PATH, 20, 5803.1475, -2992.7517, 210.95895, NULL, 5501);

UPDATE `creature` SET `position_x`=5785.9966, `position_y`=-3023.2188, `position_z`=210.5412, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
