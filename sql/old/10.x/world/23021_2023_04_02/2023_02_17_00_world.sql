SET @CGUID := 9002602;
SET @OGUID := 9000220;

SET @NPCTEXTID := 590034;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+623;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3937.6474609375, 3195.3544921875, 171.956573486328125, 0.187370672821998596, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3907.7900390625, 3191.390625, 173.599334716796875, 3.570163488388061523, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+2, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3911.257080078125, 3195.455810546875, 174.1643829345703125, 5.183141231536865234, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+3, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3865.875, 3185.522705078125, 169.1646575927734375, 5.912621498107910156, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+4, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3909.017333984375, 3192.514892578125, 173.599334716796875, 3.752971410751342773, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 186399 - Cosmetic - SitGround (Breakable))
(@CGUID+5, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3859.072998046875, 3184.6962890625, 168.4307708740234375, 4.605200767517089843, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+6, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3886.442626953125, 3143.13720703125, 175.5822906494140625, 0.3486328125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+7, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3859.3681640625, 3181.953125, 168.7913665771484375, 1.677721142768859863, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+8, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3882.2275390625, 3130.3837890625, 175.183135986328125, 5.287893295288085937, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+9, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3913.09716796875, 3191.87939453125, 173.470306396484375, 3.039823770523071289, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+10, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3861.94091796875, 3186.3134765625, 168.5594329833984375, 5.154502391815185546, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+11, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3861.897705078125, 3183.80029296875, 168.8448333740234375, 0.17420855164527893, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+12, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3892.645263671875, 3180.83740234375, 173.37945556640625, 2.862966299057006835, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+13, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3942.259521484375, 3194.16748046875, 172.163604736328125, 0.136231780052185058, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3915.922607421875, 3180.77294921875, 173.70953369140625, 4.594938278198242187, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+15, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3940.466796875, 3196.76953125, 172.0624542236328125, 6.189176082611083984, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3897.232177734375, 3179.924560546875, 173.39306640625, 2.91587686538696289, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+17, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3881.62158203125, 3127.499267578125, 175.221343994140625, 1.777857422828674316, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+18, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3914.013916015625, 3195.9072265625, 173.525421142578125, 4.567687511444091796, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+19, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3915.59716796875, 3192.908935546875, 173.4703216552734375, 0.006885869428515434, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+20, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3881.161376953125, 3124.13623046875, 175.2240753173828125, 5.662030696868896484, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+21, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3885.192626953125, 3129.62841796875, 175.123809814453125, 2.433585882186889648, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+22, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3902.037109375, 3182.84130859375, 173.369415283203125, 2.907059907913208007, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3918.642333984375, 3233.4619140625, 161.9761810302734375, 2.358632326126098632, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+24, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3976.38916015625, 3162.5888671875, 175.1587982177734375, 2.910669326782226562, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+25, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3925.11376953125, 3081.652587890625, 175.0131683349609375, 3.650683403015136718, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+26, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3872.392333984375, 3094.8212890625, 180.6197357177734375, 2.451147317886352539, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+27, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3841.791015625, 3116.406494140625, 188.2092437744140625, 1.123337745666503906, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+28, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3975.694580078125, 3171.02685546875, 175.253997802734375, 3.053616285324096679, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+29, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3962.347412109375, 3199.703125, 172.333984375, 6.241848945617675781, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+30, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3881.430419921875, 3135.26416015625, 175.1280364990234375, 3.068902254104614257, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+31, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3997.40283203125, 3167.967041015625, 175.003997802734375, 5.193549633026123046, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+32, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3997.916015625, 3161.692626953125, 175.039459228515625, 0.436887323856353759, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+33, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3938.317626953125, 3104.377685546875, 175.076812744140625, 1.289802789688110351, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+34, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3962.611083984375, 3202.001708984375, 172.338348388671875, 2.08886575698852539, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+35, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3836.819580078125, 3096.40185546875, 188.43719482421875, 1.137872815132141113, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+36, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3971.69287109375, 3160.423095703125, 175.0843963623046875, 2.904958248138427734, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+37, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3950.119873046875, 3207.033935546875, 172.338348388671875, 1.596971988677978515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+38, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3847.697998046875, 3097.474853515625, 188.43719482421875, 1.014746427536010742, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+39, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3917.944580078125, 3231.388916015625, 162.1299896240234375, 0.955294489860534667, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+40, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3872.3466796875, 3194.760009765625, 171.543182373046875, 3.518653392791748046, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3988.482666015625, 3146.764892578125, 175.69158935546875, 4.929225444793701171, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+42, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3876.772705078125, 3090.9375, 178.30755615234375, 6.067058086395263671, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 169471 - Bloody Death)
(@CGUID+43, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3958.891357421875, 3129.567626953125, 176.5586395263671875, 1.17577981948852539, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+44, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3978.163330078125, 3175.765625, 175.94403076171875, 3.519632816314697265, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+45, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3850.84375, 3095.087646484375, 188.5251312255859375, 2.430286884307861328, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+46, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3842.288330078125, 3173.858642578125, 177.983367919921875, 4.921058177947998046, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+47, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3983.276123046875, 3148.665771484375, 175.013763427734375, 5.183141231536865234, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+48, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3927.77587890625, 3093.27392578125, 182.80572509765625, 2.206947803497314453, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 188209, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3932.001708984375, 3143.864501953125, 180.2187042236328125, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- [DNT] Wave Event Controller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+50, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3874.126708984375, 3095.479248046875, 179.07440185546875, 2.093372344970703125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+51, 192059, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3927.6201171875, 3119.90234375, 175.806732177734375, 5.291772365570068359, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Palamanther (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+52, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3874.364501953125, 3098.354248046875, 179.147796630859375, 4.620787620544433593, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+53, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3995.126953125, 3162.2529296875, 175.2160186767578125, 3.446765422821044921, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+54, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3978.451416015625, 3171.27001953125, 175.253997802734375, 0.129186213016510009, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+55, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3913.848876953125, 3231.6728515625, 161.9708099365234375, 1.858661651611328125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+56, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3872.30908203125, 3096.80029296875, 180.741790771484375, 3.269065380096435546, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+57, 187692, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3912.7744140625, 3227.2275390625, 162.9991302490234375, 1.82390594482421875, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Brackenhide Bully (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+58, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3877.689208984375, 3078.296875, 178.5756683349609375, 4.307224750518798828, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+59, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3880.479248046875, 3076.518310546875, 178.3914947509765625, 0.567515850067138671, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+60, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3986.6650390625, 3149.3837890625, 175.1239776611328125, 4.129742622375488281, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+61, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3971.2333984375, 3162.286865234375, 175.069305419921875, 2.935958147048950195, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+62, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3878.442626953125, 3083.690185546875, 178.82110595703125, 0.894883394241333007, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 169471 - Bloody Death)
(@CGUID+63, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3880.154541015625, 3079.26220703125, 177.966552734375, 5.0953369140625, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+64, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3851.970458984375, 3102.35595703125, 188.7532958984375, 0.308452099561691284, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+65, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3873.482666015625, 3099.858642578125, 180.137969970703125, 4.526947498321533203, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+66, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3926.016357421875, 3039.036865234375, 174.2951202392578125, 5.4977874755859375, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+67, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3874.74658203125, 3232.951416015625, 164.8872222900390625, 1.131455183029174804, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+68, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3849.962158203125, 3071.820068359375, 185.29559326171875, 0.602139592170715332, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]) (possible waypoints or random movement)
(@CGUID+69, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3834.835205078125, 3086.182373046875, 188.770538330078125, 1.079346656799316406, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+70, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4006.393798828125, 3078.3759765625, 182.0708160400390625, 0.475010782480239868, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3992.08154296875, 3070.708251953125, 181.2362823486328125, 2.550184488296508789, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+72, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3933.70166015625, 3250.369384765625, 167.74493408203125, 5.043975353240966796, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+73, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3991.83154296875, 3127.645751953125, 182.181182861328125, 3.108181715011596679, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+74, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3998.600830078125, 3082.373291015625, 180.03948974609375, 0.898750603199005126, 120, 10, 0, 134368, 6882, 1, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override) (possible waypoints or random movement)
(@CGUID+75, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3969.517822265625, 3054.177978515625, 174.5682830810546875, 4.357190608978271484, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+76, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3977.079833984375, 3202.0400390625, 186.4640350341796875, 2.735090970993041992, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+77, 192049, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3862.560791015625, 3246.907958984375, 165.099822998046875, 5.787899494171142578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Swoglet (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+78, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3833.982666015625, 3088.45654296875, 188.4534912109375, 4.498593807220458984, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+79, 198138, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3944.863525390625, 3042.68017578125, 171.6008148193359375, 3.62629103660583496, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Muckfish (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+80, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3834.010498046875, 3094.049560546875, 188.43719482421875, 1.050966978073120117, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+81, 198138, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3943.5703125, 3036.168212890625, 168.42303466796875, 5.342255592346191406, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Muckfish (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+82, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3999.939208984375, 3093.487060546875, 180.8252410888671875, 6.206614971160888671, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+83, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3991.9931640625, 3092.9072265625, 178.8916168212890625, 0.894883394241333007, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 162084 - Permanent Feign Death (Burned))
(@CGUID+84, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3997.817626953125, 3088.6572265625, 180.1482391357421875, 0.527459263801574707, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+85, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4003.3837890625, 3094.5859375, 181.5135955810546875, 0.456556349992752075, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+86, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4001.734375, 3091.33251953125, 181.359954833984375, 0.160267680883407592, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+87, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3999.317626953125, 3089.943603515625, 180.6319427490234375, 1.209585428237915039, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+88, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3995.663330078125, 3073.11376953125, 181.7914276123046875, 5.883110523223876953, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+89, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4000.064208984375, 3087.001708984375, 180.616668701171875, 0.715166330337524414, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+90, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4054.798583984375, 3109.514892578125, 186.715362548828125, 1.922415614128112792, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+91, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3997.210205078125, 3075.4697265625, 181.136016845703125, 0.133944213390350341, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+92, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3994.55908203125, 3076.192626953125, 181.424346923828125, 3.407798051834106445, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+93, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4070.3212890625, 3089.65283203125, 186.1151275634765625, 0.50152754783630371, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+94, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4030.763427734375, 3107.532958984375, 189.54931640625, 4.946586132049560546, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+95, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4075.041748046875, 3086.3203125, 180.566070556640625, 1.010908722877502441, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+96, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4051.359375, 3107.264892578125, 186.806549072265625, 2.465776681900024414, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+97, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4057.24609375, 3046.820556640625, 188.2035064697265625, 3.535332441329956054, 120, 10, 0, 67184, 6882, 1, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+98, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4044.2431640625, 3089.442626953125, 189.0068359375, 5.113162040710449218, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+99, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4045.897705078125, 3087.045166015625, 189.37353515625, 3.736680269241333007, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+100, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4055.717041015625, 3043.124267578125, 188.0890045166015625, 3.533806324005126953, 120, 10, 0, 134368, 6882, 1, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override) (possible waypoints or random movement)
(@CGUID+101, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4066.44091796875, 3053.6025390625, 190.7839508056640625, 5.001965045928955078, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+102, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4050.100830078125, 3109.89501953125, 186.366119384765625, 1.940051078796386718, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+103, 198138, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3952.839599609375, 3006.021240234375, 166.8729400634765625, 1.438607335090637207, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Muckfish (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+104, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4042.9375, 3086.361083984375, 188.8534698486328125, 1.578056573867797851, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+105, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3984.8564453125, 3049.236328125, 182.133544921875, 1.673770904541015625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+106, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4011.125, 3050.90283203125, 185.4719390869140625, 3.534970998764038085, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+107, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4014.21875, 3049.618896484375, 185.5230865478515625, 0, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+108, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4048.532958984375, 3089.5009765625, 189.5182647705078125, 4.876373767852783203, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+109, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4047.34033203125, 3067.32373046875, 189.010345458984375, 3.474821805953979492, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+110, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4045.678955078125, 3083.02001953125, 189.5098419189453125, 2.893439292907714843, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+111, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3984.861083984375, 2998.0791015625, 174.880767822265625, 4.625729084014892578, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+112, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4012, 3047.3828125, 185.1312408447265625, 2.088337421417236328, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+113, 187463, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3951.882080078125, 3019.221435546875, 171.904998779296875, 4.919233322143554687, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Detry Hornswald (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370506 - Bubble Helm)
(@CGUID+114, 187553, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4103.12158203125, 3074.8671875, 174.4866485595703125, 0.754780352115631103, 120, 0, 0, 268736, 6882, 0, 0, 0, 0, 48001), -- Bloodclaw (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 364022 - Channel: Earth Spikes [DNT])
(@CGUID+115, 192044, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3997.646728515625, 3031.15283203125, 176.44122314453125, 4.170732021331787109, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Tiny Timbertooth (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+116, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4050.15283203125, 3068.96533203125, 189.267364501953125, 5.535249233245849609, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+117, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4052.248291015625, 3067.080810546875, 188.5004730224609375, 5.855683803558349609, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+118, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4106.2255859375, 3077.94873046875, 174.4867095947265625, 0.754780352115631103, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+119, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4068.9306640625, 3084.4541015625, 184.382781982421875, 2.182706594467163085, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+120, 198138, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3943.578857421875, 2983.11083984375, 169.3662872314453125, 4.824832916259765625, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Muckfish (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+121, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4050.060791015625, 3066.382080078125, 188.548248291015625, 0.333228886127471923, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+122, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4051.380126953125, 2999.166748046875, 193.180419921875, 1.029841184616088867, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+123, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4023.8681640625, 3013.00341796875, 179.20111083984375, 3.412889957427978515, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+124, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4039.876708984375, 3030.489501953125, 189.1580657958984375, 5.163688182830810546, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+125, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3959.48291015625, 2973.413330078125, 170.7040863037109375, 3.151670217514038085, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+126, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3968.076416015625, 3004.077392578125, 174.436553955078125, 0, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 231580 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+127, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4026.388916015625, 3015.212646484375, 179.33782958984375, 5.092061042785644531, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+128, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4068.873291015625, 3062.850830078125, 196.4828033447265625, 1.914150238037109375, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+129, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4041.78466796875, 3027.302978515625, 190.091522216796875, 0.313952594995498657, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+130, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4040.16845703125, 3024.404541015625, 189.945404052734375, 0.964637935161590576, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+131, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4012.8212890625, 2968.52685546875, 180.3993072509765625, 5.252497673034667968, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+132, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4058.369873046875, 3000.151123046875, 178.0831756591796875, 6.254574298858642578, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+133, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4111.27099609375, 3069.4765625, 191.85302734375, 1.178032279014587402, 120, 0, 0, 134368, 6882, 0, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override)
(@CGUID+134, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3980.798583984375, 2971.65625, 174.521514892578125, 3.421967506408691406, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+135, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3906.130126953125, 3037.7890625, 196.6328582763671875, 3.356044769287109375, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT])
(@CGUID+136, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4038.814208984375, 3026.9619140625, 190.091522216796875, 2.904170751571655273, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+137, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4057.482666015625, 2996.298583984375, 178.0530853271484375, 0.521191835403442382, 120, 0, 0, 134368, 6882, 0, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override, 364119 - Channel: Earth [DNT])
(@CGUID+138, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4025.951416015625, 3011.15283203125, 179.23089599609375, 1.678145527839660644, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+139, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4087.369873046875, 3007.787353515625, 193.218414306640625, 1.417858481407165527, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+140, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4070.83154296875, 3051.572021484375, 190.8193511962890625, 3.077459335327148437, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+141, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4073.9462890625, 3051.580810546875, 190.535186767578125, 0.964621722698211669, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+142, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4028.37158203125, 3012.491455078125, 179.3087615966796875, 0.113197207450866699, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+143, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4081.363037109375, 3077.927490234375, 177.8912353515625, 1.12024843692779541, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+144, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3919.02783203125, 2971.498291015625, 173.8138427734375, 4.439560413360595703, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+145, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4014.25, 2964.8369140625, 180.315582275390625, 4.544528961181640625, 120, 0, 0, 134368, 6882, 0, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override, 364116 - Channel: Storm [DNT])
(@CGUID+146, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4072.326416015625, 3053.91748046875, 190.7973480224609375, 4.106214523315429687, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+147, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3973.173583984375, 2954.103271484375, 174.9165191650390625, 2.480457305908203125, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+148, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4057.9599609375, 2974.03369140625, 192.6209564208984375, 1.22913217544555664, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+149, 187578, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3967.526123046875, 2944.614501953125, 175.40460205078125, 3.83343052864074707, 120, 0, 0, 83980, 0, 0, 0, 33554432, 0, 48001), -- Trapped Bruffalon (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 131041 - Permanent Feign Death (Blood Pool and Flies))
(@CGUID+150, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4005.85791015625, 2992.213134765625, 175.9164276123046875, 6.222207069396972656, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+151, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4049.420166015625, 3003.78564453125, 192.5466461181640625, 4.63854217529296875, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+152, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4068.036376953125, 3030.103271484375, 189.589080810546875, 3.710524320602416992, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+153, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4074.041748046875, 3028.271728515625, 189.589080810546875, 0.711143374443054199, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391041 - Channel: Earth Orb [DNT])
(@CGUID+154, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4071.515625, 3034.512939453125, 189.5890350341796875, 5.01708221435546875, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+155, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4049.84716796875, 3000.98876953125, 192.8795318603515625, 3.967202663421630859, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+156, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4048.21533203125, 2999.468017578125, 192.5927581787109375, 2.66232156753540039, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+157, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4078.116455078125, 2960.2890625, 194.7360382080078125, 5.50562906265258789, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+158, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4019.560302734375, 2936.360107421875, 184.3223419189453125, 1.96145641803741455, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+159, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4108.328125, 3073.03125, 192.4495391845703125, 1.865527272224426269, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+160, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4082.5087890625, 3006.05810546875, 194.252685546875, 1.839367270469665527, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+161, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4062.660400390625, 2987.423095703125, 192.8101654052734375, 1.884494900703430175, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+162, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4094.072998046875, 2969.146728515625, 195.9759674072265625, 2.567639827728271484, 120, 0, 0, 134368, 6882, 0, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override)
(@CGUID+163, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4066.888671875, 2990.443359375, 192.9723663330078125, 1.619633316993713378, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+164, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4083.32470703125, 3009.022705078125, 193.279327392578125, 4.980959892272949218, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+165, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4068.19091796875, 2993.330810546875, 192.8351593017578125, 1.455456376075744628, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+166, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4084.489501953125, 3007.244873046875, 194.14263916015625, 3.077459335327148437, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+167, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4106.52587890625, 3075.733642578125, 193.2516021728515625, 2.913854122161865234, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+168, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4101.296875, 3013.56689453125, 194.08367919921875, 3.999750375747680664, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+169, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4098.50341796875, 3014.059814453125, 193.8493194580078125, 4.372922897338867187, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+170, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4100.4443359375, 3015.463623046875, 193.947906494140625, 2.324187040328979492, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+171, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4099.548828125, 3011.765625, 194.0659637451171875, 1.289920210838317871, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+172, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4111.40087890625, 3075.15185546875, 192.1886138916015625, 0.546972811222076416, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+173, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4072.6181640625, 2981.970458984375, 193.180908203125, 4.077155590057373046, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+174, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4074.022705078125, 2982.710205078125, 193.2313232421875, 4.464888572692871093, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+175, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4076.10595703125, 2988.366455078125, 193.2647705078125, 2.594386100769042968, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+176, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4090.729248046875, 3006.16064453125, 194.2254638671875, 5.755330562591552734, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+177, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4068.48193359375, 2989.554931640625, 192.9926910400390625, 1.807481288909912109, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+178, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4124.88037109375, 3059.833984375, 193.7911529541015625, 2.676087617874145507, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+179, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4116.236328125, 3037.224853515625, 191.85302734375, 3.816965818405151367, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+180, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4075.420166015625, 2977.89404296875, 194.2037200927734375, 0.890707552433013916, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+181, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4092.713623046875, 2993.65185546875, 195.32763671875, 0.055525843054056167, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+182, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4120.56591796875, 3038.197021484375, 191.85302734375, 5.353192806243896484, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+183, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4122.58154296875, 3034.533935546875, 191.85302734375, 0.247586622834205627, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+184, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4118.89599609375, 3039.10498046875, 191.85302734375, 4.632232189178466796, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+185, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4090.998291015625, 2991.31591796875, 195.30828857421875, 1.114193081855773925, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+186, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4072.2744140625, 2978.13720703125, 193.558135986328125, 2.335853338241577148, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+187, 199515, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4135.7744140625, 3057.880126953125, 190.7436676025390625, 0.81571662425994873, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48001), -- Breezecone (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 396915 - Air Infusion [DNT])
(@CGUID+188, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4067.74072265625, 2962.250732421875, 192.6259002685546875, 4.205968379974365234, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+189, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4111.783203125, 2995.756103515625, 196.189453125, 4.144171714782714843, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 392969 - Hold Bowl of Meat [DNT])
(@CGUID+190, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4101.15771484375, 2987.887451171875, 194.50897216796875, 5.438383102416992187, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+191, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4064.95361328125, 2961.3017578125, 192.5341949462890625, 4.147750377655029296, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+192, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4108.74853515625, 2989.430908203125, 195.8076324462890625, 0.722820281982421875, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 392969 - Hold Bowl of Meat [DNT])
(@CGUID+193, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4105.76220703125, 2973.90966796875, 194.314453125, 3.802917957305908203, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 392969 - Hold Bowl of Meat [DNT])
(@CGUID+194, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4056.8994140625, 2951.0166015625, 199.067169189453125, 5.638425350189208984, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+195, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4078.795166015625, 2956.59716796875, 194.340057373046875, 5.47559356689453125, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370774 - Channel: Wind [DNT])
(@CGUID+196, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4081.723876953125, 2956.07373046875, 194.7313232421875, 5.215816020965576171, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 364119 - Channel: Earth [DNT])
(@CGUID+197, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4067.88525390625, 2956.46728515625, 192.4205474853515625, 4.582991600036621093, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+198, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4117.4755859375, 2987.6259765625, 196.080841064453125, 4.292904376983642578, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+199, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4115.158203125, 2992.29345703125, 196.201385498046875, 4.217343330383300781, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+200, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4098.51904296875, 2970.65966796875, 196.412078857421875, 6.161051750183105468, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+201, 187578, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4002.673583984375, 2913.643310546875, 180.791534423828125, 5.745641708374023437, 120, 0, 0, 83980, 0, 0, 0, 33554432, 0, 48001), -- Trapped Bruffalon (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 131041 - Permanent Feign Death (Blood Pool and Flies))
(@CGUID+202, 187723, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4151.0400390625, 2961.66064453125, 195.121673583984375, 5.957762718200683593, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+203, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4108.46337890625, 2973.069580078125, 194.3710479736328125, 4.493229866027832031, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+204, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3978.03759765625, 2972.655517578125, 180.2176361083984375, 2.270973920822143554, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+205, 187552, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4151.55224609375, 2966.186767578125, 195.1222991943359375, 0.713393211364746093, 120, 0, 0, 134368, 6882, 0, 0, 0, 0, 48001), -- Stormfang Shaman (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371874 - Scheming Shaman Name Override, 364119 - Channel: Earth [DNT])
(@CGUID+206, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4128.05712890625, 3001.546142578125, 204.0016326904296875, 5.522944450378417968, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+207, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4119.40478515625, 2990.357666015625, 196.196563720703125, 2.236358642578125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+208, 187551, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4116.76220703125, 2989.8994140625, 196.142364501953125, 1.134342074394226074, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Dustcaller (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+209, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4024.505126953125, 2944.53125, 183.7506561279296875, 3.517363548278808593, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+210, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4109.54345703125, 2968.220458984375, 194.3710479736328125, 1.351637005805969238, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+211, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4027.626708984375, 2944.509521484375, 183.6600799560546875, 6.260708332061767578, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+212, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4124.814453125, 2933.50341796875, 192.1850128173828125, 0.743266940116882324, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+213, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4116.0693359375, 2976.8681640625, 194.84796142578125, 3.21908426284790039, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+214, 187743, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4123.958984375, 2930.12353515625, 190.877716064453125, 1.570796370506286621, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Crudely Bound Elemental (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+215, 187575, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3997.776123046875, 2909.989501953125, 181.452178955078125, 0.518983006477355957, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Vorquin (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+216, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4120.12158203125, 2976.009521484375, 194.356597900390625, 0.135165005922317504, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+217, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4114.57666015625, 2972.772705078125, 194.3712921142578125, 4.480714321136474609, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+218, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4120.3125, 2960.4169921875, 196.33355712890625, 0.233108386397361755, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+219, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4135.32275390625, 2957.26708984375, 195.0821990966796875, 1.929209470748901367, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 390870 - Dance! [DNT])
(@CGUID+220, 187931, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4103.21337890625, 2935.088623046875, 193.0325775146484375, 2.459204435348510742, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Bonecaster (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+221, 187930, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4107.92529296875, 2936.3916015625, 192.92279052734375, 3.658418893814086914, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Stormfang Hexspiter (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+222, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4104.27783203125, 2937.635498046875, 193.032989501953125, 4.23451995849609375, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+223, 187549, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4105.53125, 2935.21533203125, 193.0327606201171875, 1.092926979064941406, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Stormfang Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+224, 187573, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4048.34716796875, 2894.5478515625, 185.150177001953125, 2.781882762908935546, 120, 0, 0, 125970, 0, 0, 0, 0, 0, 48001), -- Trapped Mammoth (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+225, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4060.842041015625, 2924.775146484375, 190.958282470703125, 0.289280354976654052, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+226, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4058.27783203125, 2925.538330078125, 191.3145599365234375, 3.43087315559387207, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+227, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4060.873291015625, 2927.118896484375, 191.314849853515625, 1.900199532508850097, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+228, 187573, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4022.447998046875, 2894.046142578125, 181.734161376953125, 5.637973308563232421, 120, 0, 0, 125970, 0, 0, 0, 0, 0, 48001), -- Trapped Mammoth (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+229, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4021.796875, 2935.7666015625, 184.9877471923828125, 1.143170952796936035, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+230, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4058.2021484375, 2877.334228515625, 183.1749267578125, 1.950883388519287109, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+231, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4096.69775390625, 2907.229248046875, 189.21624755859375, 5.263508796691894531, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+232, 187578, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4076.970458984375, 2863.518310546875, 186.2314453125, 0.197543695569038391, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Bruffalon (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+233, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3995.28125, 2949.36279296875, 179.945098876953125, 2.502016305923461914, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+234, 187579, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4095.095458984375, 2904.8828125, 188.84149169921875, 4.282008171081542968, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Beaver (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+235, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4052.044189453125, 2911.386474609375, 189.19097900390625, 0.380506396293640136, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+236, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3999.6806640625, 2946.67529296875, 181.3007965087890625, 2.352763891220092773, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+237, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4093.557373046875, 2907.68310546875, 189.340362548828125, 4.900822639465332031, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+238, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4097.55712890625, 2904.239501953125, 188.909454345703125, 0.194243490695953369, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+239, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4030.788330078125, 2907.515625, 184.813720703125, 2.644358634948730468, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+240, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4008.714599609375, 2918.923095703125, 180.1017608642578125, 1.313969850540161132, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+241, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4012.095458984375, 2914.43115234375, 179.9867706298828125, 1.177958369255065917, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+242, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3984.03125, 2895.79638671875, 180.6547393798828125, 6.087762355804443359, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+243, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4012.038330078125, 2917.90966796875, 180.05120849609375, 1.258934259414672851, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+244, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4001.8056640625, 2919.5869140625, 181.1084442138671875, 5.025643825531005859, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+245, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3987.8818359375, 2936.969482421875, 177.2415924072265625, 1.914132237434387207, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+246, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4030.67529296875, 2910.27783203125, 185.1335601806640625, 3.517363548278808593, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+247, 198138, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3934.960205078125, 2959.992919921875, 170.67333984375, 0.471472561359405517, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Muckfish (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+248, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4097.01904296875, 2898.645751953125, 188.1202392578125, 0.608891308307647705, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+249, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4037.12158203125, 2905.481689453125, 185.506744384765625, 0.951257169246673583, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+250, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4038.651123046875, 2908.866455078125, 186.35089111328125, 0.078066840767860412, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+251, 187574, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3992.689208984375, 2879.90185546875, 180.7757415771484375, 0.484603703022003173, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Hornswog (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+252, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4034.92529296875, 2905.163330078125, 185.1348114013671875, 1.480882644653320312, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+253, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4005.70166015625, 2924.920166015625, 180.24176025390625, 1.541225075721740722, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+254, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4034.201416015625, 2908.78466796875, 185.532257080078125, 4.541801929473876953, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+255, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4001.060791015625, 2917.287353515625, 182.9842071533203125, 4.601132869720458984, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+256, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4006.718505859375, 2916.0751953125, 180.2935028076171875, 1.269425868988037109, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+257, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4008.80712890625, 2913.296630859375, 180.0398406982421875, 1.19065260887145996, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+258, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4092.927001953125, 2903.8603515625, 188.3043975830078125, 3.05194854736328125, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+259, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4032.9375, 2905.3056640625, 184.9981536865234375, 1.934736371040344238, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+260, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4094.845458984375, 2899.52783203125, 188.1201934814453125, 3.80309462547302246, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+261, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3998.1806640625, 2917.424560546875, 182.761444091796875, 3.951528072357177734, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+262, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4000.232666015625, 2912.08935546875, 182.427459716796875, 2.139785528182983398, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+263, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4023.411376953125, 2898.065185546875, 183.108184814453125, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+264, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3995.366455078125, 2909.077392578125, 181.421417236328125, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+265, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3998.786376953125, 2912.98095703125, 182.427459716796875, 2.434084892272949218, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+266, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3996.553955078125, 2915.1728515625, 183.0037384033203125, 3.424796342849731445, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+267, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4047.663330078125, 2890.204833984375, 186.2169036865234375, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+268, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4003.31591796875, 2913.208251953125, 182.427459716796875, 0.776757776737213134, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+269, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4057.819580078125, 2846.103271484375, 185.6920318603515625, 0.712122857570648193, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+270, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4019.15625, 2890.76123046875, 180.061065673828125, 2.61078047752380371, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+271, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4055.312255859375, 2876.940185546875, 183.0945281982421875, 2.025781869888305664, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+272, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4058.340087890625, 2877.017578125, 183.1185302734375, 2.071002006530761718, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+273, 187574, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4055.01220703125, 2841.1875, 186.3358154296875, 0.484603703022003173, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Hornswog (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+274, 187575, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4026.65625, 2844.31689453125, 180.283233642578125, 0.518983006477355957, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Vorquin (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+275, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4080.65966796875, 2875.9462890625, 184.4311370849609375, 5.469591140747070312, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+276, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4018.5869140625, 2892.6015625, 180.070465087890625, 3.547063112258911132, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+277, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4076.178955078125, 2876.44189453125, 184.6554107666015625, 4.35387420654296875, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+278, 3300, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4102.892578125, 2878.5537109375, 182.9666290283203125, 0.017576314508914947, 120, 0, 0, 1, 0, 0, 0, 0, 0, 48001), -- Adder (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+279, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4076.890625, 2873.3291015625, 184.470733642578125, 3.29055333137512207, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+280, 187578, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3949.380126953125, 2878.561767578125, 185.8031005859375, 5.920004844665527343, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Bruffalon (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+281, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4080.2431640625, 2871.788330078125, 184.504913330078125, 1.480612635612487792, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+282, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4078.9619140625, 2869.014892578125, 184.5321502685546875, 1.212281465530395507, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+283, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4075.963623046875, 2869.9462890625, 184.42822265625, 0.85523688793182373, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+284, 187580, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4038.3369140625, 2818.04345703125, 184.732666015625, 2.759203195571899414, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Ottuk (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+285, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4074.357666015625, 2861.463623046875, 187.0328216552734375, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+286, 187575, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4070.208251953125, 2818.279541015625, 190.5749053955078125, 2.176314830780029296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Vorquin (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+287, 187580, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4041.845458984375, 2816.48876953125, 184.728179931640625, 0.821683168411254882, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Ottuk (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+288, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4070.9150390625, 2851.7041015625, 190.014678955078125, 4.103637218475341796, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+289, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4053.35595703125, 2843.30029296875, 185.96881103515625, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+290, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4059.14404296875, 2848.84814453125, 185.5850677490234375, 3.074682950973510742, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+291, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4061.657958984375, 2849.0166015625, 185.454864501953125, 6.216275691986083984, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+292, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3982.354248046875, 2834.80810546875, 195.587554931640625, 5.468020439147949218, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+293, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3990.541748046875, 2882.1572265625, 181.0341033935546875, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+294, 187579, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4009.142333984375, 2858.67529296875, 180.277801513671875, 2.442167282104492187, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Beaver (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+295, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3991.005126953125, 2878.299560546875, 180.8256378173828125, 2.498091697692871093, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+296, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3982.9619140625, 2875.77685546875, 180.32965087890625, 3.669510602951049804, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+297, 187573, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3978.435791015625, 2830.203125, 197.3056182861328125, 5.038726806640625, 120, 0, 0, 125970, 0, 0, 0, 0, 0, 48001), -- Trapped Mammoth (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+298, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3985.2900390625, 2874.7509765625, 180.7303314208984375, 0.52329409122467041, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+299, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4023.928955078125, 2846.7275390625, 180.5915069580078125, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+300, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4025.177001953125, 2847.42529296875, 180.277801513671875, 0.729327976703643798, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+301, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4011.6025390625, 2850.3671875, 180.279449462890625, 3.766690254211425781, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+302, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4021.8056640625, 2850.6728515625, 180.27783203125, 5.098983287811279296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+303, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4023.786376953125, 2849.987060546875, 180.2777557373046875, 0.161248013377189636, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+304, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4006.5625, 2855.647705078125, 181.023712158203125, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+305, 187579, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4011.005126953125, 2856.104248046875, 180.2786102294921875, 3.174098014831542968, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Beaver (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+306, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4008.204833984375, 2851.263916015625, 180.2777862548828125, 0.983190059661865234, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+307, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4007.564208984375, 2849.038330078125, 180.92822265625, 4.046414375305175781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+308, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4010.0712890625, 2848.4765625, 180.395477294921875, 3.106560230255126953, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+309, 193511, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3723.130859375, 2972.562744140625, 253.3391571044921875, 3.751519203186035156, 120, 0, 0, 16796, 0, 0, 0, 0, 0, 48001), -- Woadspine (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+310, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4046.522705078125, 2815.94189453125, 184.708770751953125, 4.630021095275878906, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+311, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4016.84033203125, 2839.905517578125, 180.277801513671875, 3.890300750732421875, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+312, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4018.444580078125, 2836.072021484375, 180.3568878173828125, 4.313538074493408203, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+313, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4052.57421875, 2822.89453125, 184.830108642578125, 1.80426192283630371, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+314, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4044.47216796875, 2818.783935546875, 184.7292327880859375, 5.98110198974609375, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+315, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3982.8681640625, 2873.0009765625, 180.43475341796875, 2.264684438705444335, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+316, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4072.611083984375, 2820.493896484375, 190.99005126953125, 1.657330989837646484, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+317, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4016.265625, 2835.357666015625, 180.825347900390625, 1.904987454414367675, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+318, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4034.153076171875, 2829.98779296875, 206.102783203125, 1.730424761772155761, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+319, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4018.798583984375, 2838.0859375, 180.277801513671875, 0.748707890510559082, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+320, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3967.694580078125, 2880.55908203125, 182.001708984375, 2.278984546661376953, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+321, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4080.54345703125, 2809.38720703125, 189.57208251953125, 0.591297388076782226, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+322, 187578, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3994.23095703125, 2786.420166015625, 199.927581787109375, 1.194754719734191894, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Bruffalon (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+323, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4078.963623046875, 2811.3046875, 189.869781494140625, 5.558138370513916015, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+324, 187575, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3934.7275390625, 2855.694580078125, 211.1841278076171875, 0.338574588298797607, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Vorquin (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+325, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4039.3056640625, 2816.440185546875, 185.071380615234375, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+326, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4077.30029296875, 2809.16748046875, 189.890533447265625, 2.434215068817138671, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+327, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -4017.234375, 2810.576416015625, 198.0612640380859375, 3.121975898742675781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+328, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4021.833251953125, 2811.026123046875, 198.0600128173828125, 0.646849870681762695, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+329, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3981.315673828125, 2839.93701171875, 194.7201080322265625, 0.450547903776168823, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+330, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3979.647705078125, 2836.507080078125, 195.958282470703125, 4.886043071746826171, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+331, 187574, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3939.875, 2827.1171875, 203.17730712890625, 5.176091670989990234, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Hornswog (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+332, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4019.876708984375, 2811.0947265625, 198.30352783203125, 2.058079719543457031, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+333, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4021.098876953125, 2813.401123046875, 198.0612640380859375, 5.320338726043701171, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+334, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3938.013916015625, 2840.63720703125, 183.231292724609375, 2.915880203247070312, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+335, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4018.40625, 2812.873291015625, 198.0612640380859375, 3.856640100479125976, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+336, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3958.502685546875, 2882.29296875, 184.5725860595703125, 2.67857980728149414, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+337, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3963.12158203125, 2856.6962890625, 174.253692626953125, 2.037017583847045898, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+338, 187528, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3960.989501953125, 2857.268310546875, 174.266021728515625, 2.47207498550415039, 120, 0, 0, 335920, 0, 0, 0, 0, 0, 48001), -- Cracktooth (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+339, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3979.619873046875, 2826.286376953125, 197.614715576171875, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+340, 187580, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3919.921875, 2846.39501953125, 187.5270843505859375, 2.086434125900268554, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Ottuk (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+341, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3959.748291015625, 2859.428955078125, 174.268341064453125, 2.339606761932373046, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+342, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3995.553955078125, 2794.119873046875, 199.9878997802734375, 5.138019561767578125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+343, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3991.013916015625, 2795.007080078125, 199.741943359375, 0.097939878702163696, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+344, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3994.44970703125, 2791.68408203125, 199.987884521484375, 1.99642646312713623, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+345, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3953.892822265625, 2774.878173828125, 206.8207855224609375, 1.226259708404541015, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+346, 187575, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3966.588623046875, 2768.662353515625, 207.1168975830078125, 0.518983006477355957, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Vorquin (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+347, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3944.814208984375, 2868.390625, 185.414398193359375, 0.266804009675979614, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+348, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3991.45654296875, 2784.841064453125, 200.9178314208984375, 4.900822639465332031, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+349, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3947.411376953125, 2874.029541015625, 187.977691650390625, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+350, 187523, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3905.620849609375, 2863.72314453125, 189.463653564453125, 2.72062849998474121, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48001), -- Duskpaw Stalker (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371873 - Opportunistic Stalker Name Override) (possible waypoints or random movement)
(@CGUID+351, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3932.22412109375, 2879.4150390625, 184.690704345703125, 5.637731075286865234, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391245 - Supply-Laden) (possible waypoints or random movement)
(@CGUID+352, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3909.947998046875, 2805.259521484375, 200.913330078125, 3.566649198532104492, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+353, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3945.4306640625, 2841.552978515625, 183.4315643310546875, 5.787550926208496093, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+354, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3997.039306640625, 2771.041015625, 202.9071807861328125, 0.232952415943145751, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+355, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3934.3837890625, 2865.412353515625, 184.7198028564453125, 1.470350384712219238, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+356, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3944.114501953125, 2840.23095703125, 183.346099853515625, 0.743456006050109863, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 169471 - Bloody Death)
(@CGUID+357, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3939.078125, 2858.375, 211.1956329345703125, 5.592881202697753906, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+358, 187580, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3940.647705078125, 2764.3125, 214.3941650390625, 0.992351353168487548, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Ottuk (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+359, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3943.67529296875, 2838.795166015625, 183.2928466796875, 1.845982909202575683, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+360, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3942.350830078125, 2840.5947265625, 183.2303924560546875, 3.119646072387695312, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+361, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3984.80908203125, 2785.026123046875, 199.9691925048828125, 2.176373481750488281, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+362, 187573, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3909.163330078125, 2914.65966796875, 175.698089599609375, 0.994132459163665771, 120, 0, 0, 125970, 0, 0, 0, 33554432, 0, 48001), -- Trapped Mammoth (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 131041 - Permanent Feign Death (Blood Pool and Flies))
(@CGUID+363, 187578, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3915.329833984375, 2802.885498046875, 201.7216796875, 0.004876780323684215, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Bruffalon (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+364, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3941.185791015625, 2867.983642578125, 185.060760498046875, 3.029894351959228515, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+365, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3939.979248046875, 2824.491455078125, 203.501220703125, 4.900822639465332031, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+366, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3937.767333984375, 2824.32373046875, 203.14642333984375, 2.062180519104003906, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+367, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3936.71875, 2829.026123046875, 203.51043701171875, 3.91850590705871582, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+368, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3936.65283203125, 2826.26220703125, 203.27239990234375, 2.849753856658935546, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+369, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3939.166015625, 2848.21337890625, 218.552093505859375, 2.592208385467529296, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+370, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3959.189208984375, 2788.775146484375, 210.9775390625, 0.359881490468978881, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+371, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3956.20458984375, 2781.1728515625, 204.0518341064453125, 2.453112125396728515, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+372, 187574, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3923.37841796875, 2760.598876953125, 214.732666015625, 1.784271001815795898, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Hornswog (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+373, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3934.1806640625, 2858.14501953125, 211.33233642578125, 4.4589996337890625, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+374, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3931.892333984375, 2854.47216796875, 211.0868988037109375, 2.853159427642822265, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+375, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3928.69091796875, 2847.55029296875, 187.5119476318359375, 5.920656681060791015, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+376, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3934.104248046875, 2851.71435546875, 210.5493011474609375, 1.635330080986022949, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+377, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3931.76220703125, 2856.37158203125, 211.6422882080078125, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+378, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3975.0869140625, 2760.674560546875, 207.56597900390625, 4.629137992858886718, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+379, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3925.369873046875, 2840.91748046875, 187.50775146484375, 0.74903959035873413, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+380, 187523, 2444, 13646, 13848, '0', 0, 0, 0, 0, -4041.342041015625, 2819.97314453125, 184.729522705078125, 5.213961124420166015, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Duskpaw Stalker (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371873 - Opportunistic Stalker Name Override, 372408 - Stealth)
(@CGUID+381, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3926.157958984375, 2848.885498046875, 187.513031005859375, 6.25672006607055664, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+382, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3963.260498046875, 2771.052001953125, 207.0851287841796875, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+383, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3923.532958984375, 2839.006103515625, 187.5069427490234375, 1.968176126480102539, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+384, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3922.331787109375, 2819.314697265625, 201.7398681640625, 1.03156280517578125, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+385, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3921.91845703125, 2841.85498046875, 187.5069427490234375, 2.449769020080566406, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+386, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3924.1650390625, 2843.716064453125, 187.5091552734375, 5.7278594970703125, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+387, 187580, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3883.6181640625, 2815.468017578125, 203.28692626953125, 1.898253321647644042, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Ottuk (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+388, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3940.579833984375, 2760.085205078125, 214.5476837158203125, 0.29165235161781311, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+389, 187579, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3917.052001953125, 2847.00439453125, 187.5293121337890625, 1.539130210876464843, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Beaver (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+390, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3917.395751953125, 2842.702392578125, 189.9568328857421875, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+391, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3938.09033203125, 2760.55029296875, 214.5476837158203125, 3.437868118286132812, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+392, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3915.598876953125, 2805.673583984375, 200.7642822265625, 4.75482177734375, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+393, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3943.75, 2756.850830078125, 214.5476837158203125, 0.438804775476455688, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+394, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3944.413330078125, 2761.681396484375, 214.60955810546875, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+395, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3918.982666015625, 2804.9931640625, 200.9189453125, 5.450253486633300781, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+396, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3911.098876953125, 2801.92529296875, 202.2854766845703125, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+397, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3916.1025390625, 2773.0869140625, 214.8070220947265625, 2.266403913497924804, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+398, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3918.326416015625, 2773.0859375, 214.6820220947265625, 0.438804775476455688, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+399, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3925.45654296875, 2762.559814453125, 215.103912353515625, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+400, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3925.4033203125, 2764.693115234375, 214.67584228515625, 4.894259929656982421, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+401, 187566, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3893.333251953125, 2741.295166015625, 222.3394317626953125, 6.149657249450683593, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Hyena Matriarch (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+402, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3895.157958984375, 2801.871826171875, 201.633148193359375, 2.163675546646118164, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+403, 187579, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3912.34375, 2769.892333984375, 215.4422149658203125, 4.194466114044189453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Trapped Beaver (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+404, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3910.1962890625, 2772.185791015625, 215.5453948974609375, 2.104883193969726562, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+405, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3890.628173828125, 2803.534912109375, 201.822052001953125, 2.089942455291748046, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+406, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3893.37353515625, 2804.333740234375, 201.45489501953125, 2.168041467666625976, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+407, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3891.9775390625, 2806.744873046875, 201.420623779296875, 2.44764113426208496, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+408, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3895.372802734375, 2806.4013671875, 201.184478759765625, 2.718115568161010742, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+409, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3893.209228515625, 2801.24755859375, 201.76690673828125, 1.907378911972045898, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+410, 195446, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3883.529541015625, 2819.517333984375, 203.2429656982421875, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48001), -- Target (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: )
(@CGUID+411, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3877.475830078125, 2832.0947265625, 200.384918212890625, 1.900199532508850097, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+412, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3882.291015625, 2808.6259765625, 203.303558349609375, 4.712388992309570312, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+413, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3878.61328125, 2829.888671875, 200.863861083984375, 6.081218719482421875, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+414, 197820, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3877.177001953125, 2828.239501953125, 201.653656005859375, 2.103167295455932617, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+415, 187941, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3872.4931640625, 2800.513916015625, 205.053558349609375, 0.825454235076904296, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Duskpaw Hidestitcher (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+416, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3875.904541015625, 2799.408935546875, 204.8478240966796875, 0.650159120559692382, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+417, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3873.510498046875, 2838.8203125, 209.280853271484375, 5.920080184936523437, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+418, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3873.682373046875, 2798.78125, 205.0273895263671875, 0.992147326469421386, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+419, 187568, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3876.501953125, 2829.81640625, 201.428558349609375, 4.068981170654296875, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Duskpaw Scavenger (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+420, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3888.751708984375, 2742.170166015625, 223.7250518798828125, 4.661626815795898437, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+421, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3870.256591796875, 2772.685546875, 215.7225494384765625, 0.951909244060516357, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+422, 187510, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3868.046875, 2801.908935546875, 205.196502685546875, 0.786953389644622802, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Duskpaw Trapper (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+423, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3874.041748046875, 2876.04345703125, 190.1605377197265625, 2.243754863739013671, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+424, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3872.248291015625, 2874.5166015625, 190.3558197021484375, 4.571019649505615234, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+425, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3875.66845703125, 2879.083251953125, 190.1332244873046875, 5.37953948974609375, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+426, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3839.619873046875, 2822.942626953125, 204.09405517578125, 2.481321573257446289, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+427, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3841.92529296875, 2824.197998046875, 204.09405517578125, 5.900568485260009765, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+428, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3838.557373046875, 2820.17529296875, 203.9114532470703125, 3.775837659835815429, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+429, 187497, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3907.01708984375, 2946.381591796875, 172.8721160888671875, 1.107523679733276367, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48001), -- Waste Water Elemental (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+430, 187523, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3939.935791015625, 2821.802978515625, 203.17730712890625, 1.391332268714904785, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Duskpaw Stalker (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371873 - Opportunistic Stalker Name Override, 372408 - Stealth)
(@CGUID+431, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3897.71533203125, 2900.964599609375, 177.8306121826171875, 2.22875523567199707, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+432, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3841.072998046875, 2820.501708984375, 203.831207275390625, 3.732098579406738281, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+433, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3878.470458984375, 2878.375, 190.1575775146484375, 3.975903511047363281, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+434, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3838.402587890625, 2865.830810546875, 199.3695220947265625, 6.274072170257568359, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+435, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3829.166015625, 2820.8330078125, 206.4292144775390625, 1.590449810028076171, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+436, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3855.001708984375, 2890.37158203125, 195.3024139404296875, 2.093372344970703125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+437, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3840.335693359375, 2862.848388671875, 199.416595458984375, 6.162776470184326171, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+438, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3851.84375, 2892.518310546875, 195.4811859130859375, 3.541781902313232421, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+439, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3843.1865234375, 2879.639892578125, 200.1244659423828125, 0.235544979572296142, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+440, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3837.306640625, 2865.81884765625, 199.509490966796875, 0.080216191709041595, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+441, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3853.51904296875, 2893.99658203125, 194.552886962890625, 4.488227367401123046, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+442, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3855.526123046875, 2892.512939453125, 194.3767852783203125, 4.9525604248046875, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+443, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3852.229248046875, 2889.60498046875, 195.7895660400390625, 2.658865928649902343, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+444, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3843.30615234375, 2865.87744140625, 198.053192138671875, 5.999906063079833984, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+445, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3820.251708984375, 2840.681396484375, 202.2625274658203125, 2.670519828796386718, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+446, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3840.277099609375, 2868.847900390625, 198.7376251220703125, 6.1905975341796875, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+447, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3802.007080078125, 2821.228271484375, 205.6218719482421875, 1.190692901611328125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+448, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3803.203125, 2852.43310546875, 202.3819732666015625, 1.543488264083862304, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT])
(@CGUID+449, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3818.154541015625, 2843.08251953125, 202.2838592529296875, 1.941527009010314941, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+450, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3802.251708984375, 2823.83935546875, 205.621917724609375, 5.855193138122558593, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+451, 192059, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3870.833984375, 2930.728515625, 176.2213592529296875, 1.570796370506286621, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Palamanther (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+452, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3815.835205078125, 2841.440185546875, 202.274200439453125, 4.199200630187988281, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+453, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3818.39404296875, 2840.052978515625, 202.276397705078125, 0.496776163578033447, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+454, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3854.307373046875, 2928.82373046875, 187.9963531494140625, 1.674642562866210937, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+455, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3802.15234375, 2846.50244140625, 204.28009033203125, 1.91936957836151123, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+456, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3817.239501953125, 2880.038330078125, 207.1279144287109375, 2.100898504257202148, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+457, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3799.732666015625, 2822.690185546875, 205.6218719482421875, 2.713600635528564453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 369547 - Sparring Aura: Attack1H/CombatAbility1HBig01 [DNT])
(@CGUID+458, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3852.885498046875, 2931.244873046875, 187.3997955322265625, 3.846239566802978515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 369547 - Sparring Aura: Attack1H/CombatAbility1HBig01 [DNT])
(@CGUID+459, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3806.517333984375, 2881.12939453125, 200.6021881103515625, 4.338610172271728515, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+460, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3803.994873046875, 2876.9072265625, 200.5844879150390625, 4.099962711334228515, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]) (possible waypoints or random movement)
(@CGUID+461, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3855.609375, 2930.802001953125, 187.67803955078125, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+462, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3800.558837890625, 2880.42626953125, 200.7048492431640625, 4.341452598571777343, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+463, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3892.93505859375, 2948.868408203125, 180.906829833984375, 5.439499378204345703, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+464, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3831.8359375, 2936.878662109375, 183.4057769775390625, 0.707153856754302978, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+465, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3834.354248046875, 2935.248291015625, 183.8152618408203125, 0.574503481388092041, 120, 10, 0, 67184, 6882, 1, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+466, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3836.87255859375, 2933.617919921875, 184.1824493408203125, 0.800550818443298339, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+467, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3861.203125, 2953.26416015625, 179.6172637939453125, 1.736523747444152832, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+468, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3843.6650390625, 2956.81982421875, 181.7831268310546875, 5.578605175018310546, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+469, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3794.407958984375, 2913.989501953125, 208.860382080078125, 3.734921455383300781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+470, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3794.8369140625, 2916.092041015625, 208.8604583740234375, 3.269728422164916992, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+471, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3815.963623046875, 2939.8447265625, 184.904815673828125, 4.742166042327880859, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+472, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3823.74365234375, 2944.104736328125, 183.17425537109375, 5.238552093505859375, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+473, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3813.939208984375, 2943.5791015625, 185.1308441162109375, 3.392993927001953125, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+474, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3816.68408203125, 2943.290771484375, 183.9322662353515625, 0.104659318923950195, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+475, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3840.771728515625, 2959.9287109375, 181.8650665283203125, 5.578133106231689453, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+476, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3823.6748046875, 2950.19921875, 183.0865478515625, 5.202335357666015625, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+477, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3840.529296875, 2956.9384765625, 181.9451446533203125, 5.578691482543945312, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]) (possible waypoints or random movement)
(@CGUID+478, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3826.333251953125, 2960.47314453125, 184.5033416748046875, 4.019326210021972656, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+479, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3787.290283203125, 2822.248291015625, 204.8533477783203125, 1.037682175636291503, 120, 8, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+480, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3823.21533203125, 2959.80908203125, 184.0090484619140625, 4.748319625854492187, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+481, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3823.3681640625, 2961.490478515625, 184.52978515625, 2.534175395965576171, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+482, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3790.382080078125, 2913.8125, 207.453125, 2.016971111297607421, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+483, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3787.150634765625, 2826.512939453125, 205.293853759765625, 1.618152856826782226, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+484, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3815.734375, 2945.954833984375, 183.5036773681640625, 4.146616458892822265, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+485, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3784.64892578125, 2818.548095703125, 204.999420166015625, 2.432567358016967773, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+486, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3791.517333984375, 2916.185791015625, 208.104156494140625, 5.158563613891601562, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+487, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3826.083251953125, 2963.377685546875, 184.975982666015625, 5.675768375396728515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+488, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3777.720458984375, 2823.588623046875, 204.91107177734375, 6.262377262115478515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+489, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3790.3369140625, 2802.564208984375, 204.6477813720703125, 0.714820146560668945, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+490, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3807.37109375, 2957.158935546875, 185.5236358642578125, 3.634846210479736328, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+491, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3810.243896484375, 2958.02294921875, 185.4191436767578125, 3.634827136993408203, 120, 10, 0, 67184, 6882, 1, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+492, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3774.963623046875, 2823.53125, 204.9110565185546875, 3.120784521102905273, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+493, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3862.920166015625, 2974.401123046875, 180.286407470703125, 2.168109655380249023, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+494, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3784.053955078125, 2804.205810546875, 205.2160491943359375, 5.343641281127929687, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+495, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3785.401123046875, 2802.77783203125, 205.216766357421875, 6.1253814697265625, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+496, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3782.520751953125, 2801.89404296875, 205.267120361328125, 2.843880176544189453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+497, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3809.3798828125, 2960.895751953125, 185.7133636474609375, 0.453157514333724975, 120, 10, 0, 25194, 0, 1, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+498, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3774.178955078125, 2820.757080078125, 204.7915191650390625, 2.608561992645263671, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+499, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3780.383544921875, 2791.263916015625, 204.190185546875, 4.359688758850097656, 120, 6, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+500, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3746.671875, 2856.59033203125, 212.8639068603515625, 2.390140771865844726, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT])
(@CGUID+501, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3747.100830078125, 2853.6806640625, 212.6319732666015625, 2.290676355361938476, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+502, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3760.75537109375, 2818.319580078125, 204.016571044921875, 5.086587905883789062, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+503, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3749.353515625, 2844.75732421875, 212.8172760009765625, 4.699538230895996093, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+504, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3749.06591796875, 2857.653564453125, 212.981109619140625, 4.592907905578613281, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+505, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3746.838623046875, 2860.114501953125, 213.3038330078125, 0.250659912824630737, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+506, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3758.420166015625, 2787.720458984375, 204.6995697021484375, 1.946623921394348144, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+507, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3760.296875, 2792.50439453125, 205.0799102783203125, 5.549406051635742187, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+508, 187505, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3757.994873046875, 2790.1796875, 204.8078460693359375, 2.737488746643066406, 120, 0, 0, 335920, 0, 0, 0, 0, 0, 48001), -- Flayfist (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391413 - Gnoll Back Banner x3 [DNT])
(@CGUID+509, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3799.0625, 2972.01904296875, 184.178558349609375, 2.360617876052856445, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+510, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3868.15283203125, 2978.7978515625, 180.2528533935546875, 0.688532590866088867, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+511, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3864.78125, 2977.13720703125, 180.2864227294921875, 5.309702396392822265, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+512, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3829.3125, 2988.1796875, 186.713470458984375, 3.299622535705566406, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+513, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3845.62841796875, 2992.123291015625, 193.1414031982421875, 5.40003824234008789, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+514, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3860.541748046875, 2995.8759765625, 180.2864227294921875, 0.77044534683227539, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+515, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3858.470458984375, 2997.88623046875, 180.2864227294921875, 3.912038087844848632, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+516, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3793.44091796875, 2978.139892578125, 183.9069366455078125, 1.720533132553100585, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+517, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3780.557373046875, 2968.953125, 181.85675048828125, 5.472720146179199218, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+518, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3861.201416015625, 2998.137939453125, 180.2864227294921875, 5.887614250183105468, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+519, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3828.723876953125, 2990.572021484375, 186.793548583984375, 3.301811695098876953, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+520, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3779.392333984375, 2966.779541015625, 181.847076416015625, 2.101636171340942382, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+521, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3784.903076171875, 2966.68212890625, 181.8644256591796875, 5.682271480560302734, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+522, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3794.619873046875, 2972.385498046875, 182.9896697998046875, 2.429763317108154296, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+523, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3857.96875, 3000.84375, 180.486114501953125, 4.526947498321533203, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+524, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3781.270751953125, 2964.459228515625, 181.95721435546875, 4.995793342590332031, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+525, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3830.225830078125, 2989.663330078125, 186.603851318359375, 3.145421266555786132, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+526, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3779.50341796875, 2965.085205078125, 181.8850555419921875, 5.810334682464599609, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+527, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3782.05908203125, 2979.975830078125, 183.60125732421875, 2.033928632736206054, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+528, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3783.395751953125, 2982.673583984375, 183.7461395263671875, 1.589656233787536621, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+529, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3834.218017578125, 3023.823486328125, 189.409393310546875, 3.887515783309936523, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+530, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3838.446533203125, 3024.169189453125, 188.078094482421875, 3.870424985885620117, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+531, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3782.935791015625, 3002.43310546875, 191.047119140625, 0.073380738496780395, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+532, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3834.563720703125, 3019.594970703125, 189.032684326171875, 3.884508132934570312, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+533, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3838.792236328125, 3019.940673828125, 188.178192138671875, 3.856498241424560546, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+534, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3836.505126953125, 3021.882080078125, 188.985809326171875, 3.845450639724731445, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+535, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3823.32373046875, 3018.636474609375, 192.747467041015625, 4.883156776428222656, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+536, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3851.333251953125, 3023.997314453125, 187.94677734375, 2.126658439636230468, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+537, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3780.697998046875, 3000.2197265625, 190.869384765625, 1.828030943870544433, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+538, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3850.0400390625, 3026.1572265625, 188.054656982421875, 3.380215167999267578, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+539, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3777.958251953125, 3001.924560546875, 190.74395751953125, 3.301528215408325195, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+540, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3778.703125, 2999.744873046875, 190.814483642578125, 2.491280078887939453, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+541, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3816.173583984375, 3025.877685546875, 193.34979248046875, 3.918418169021606445, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+542, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3853.0244140625, 3026.7197265625, 188.0453033447265625, 5.268251419067382812, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+543, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3850.203125, 3030.43408203125, 188.0453033447265625, 4.277980804443359375, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+544, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3896.2119140625, 3013.644287109375, 181.14605712890625, 5.053744792938232421, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+545, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3817.64404296875, 3027.90283203125, 193.310760498046875, 1.828030943870544433, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+546, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3814.9375, 3028.521728515625, 193.26171875, 2.890093326568603515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 391245 - Supply-Laden)
(@CGUID+547, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3780.178955078125, 3003.056396484375, 190.9005584716796875, 4.531414985656738281, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+548, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3797.22802734375, 3028.740478515625, 196.5496826171875, 2.484215736389160156, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+549, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3800.22216796875, 3028.37158203125, 196.5267181396484375, 2.484351158142089843, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+550, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3770.06591796875, 3003.8056640625, 190.5785369873046875, 0.138810724020004272, 120, 10, 0, 8, 0, 1, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+551, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3817.125, 3030.739501953125, 193.1128387451171875, 4.531414985656738281, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+552, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3799.8388671875, 3025.396240234375, 196.8588104248046875, 2.484304428100585937, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+553, 197847, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3804.173583984375, 3042.654541015625, 195.810760498046875, 4.285969734191894531, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+554, 187565, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3814.57080078125, 3041.973388671875, 193.326263427734375, 0.859893858432769775, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Hyena Mongrel (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+555, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3767.013916015625, 3015.809814453125, 190.40631103515625, 3.311851739883422851, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+556, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3810.5791015625, 3043.23193359375, 194.342742919921875, 1.104526400566101074, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+557, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3868.760986328125, 3037.626953125, 190.3484649658203125, 3.141592741012573242, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+558, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3762.189208984375, 3012.6337890625, 190.4243011474609375, 4.422958850860595703, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+559, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3806.161376953125, 3043.943603515625, 195.5926513671875, 2.812611341476440429, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+560, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3911.57470703125, 3014.5390625, 175.370697021484375, 0, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 169471 - Bloody Death)
(@CGUID+561, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3805.217041015625, 3040.357666015625, 195.1371307373046875, 1.725259661674499511, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+562, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3859.645751953125, 3050.61376953125, 189.8790283203125, 1.828030943870544433, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+563, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3859.126708984375, 3053.450439453125, 189.5032196044921875, 4.35544586181640625, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371733 - Sparring Aura: AttackUnarmed [DNT])
(@CGUID+564, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3760.486083984375, 3017.181396484375, 190.659759521484375, 0.57925349473953247, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+565, 188260, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3792.47998046875, 2881.969970703125, 202.2599945068359375, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- [DNT] Wind Director (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+566, 187936, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3862.52783203125, 3052.15966796875, 189.5644378662109375, 6.191715240478515625, 120, 0, 0, 67184, 6882, 0, 0, 0, 0, 48001), -- Gnawbone Totemchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+567, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3857.4462890625, 3051.553955078125, 189.6309967041015625, 3.038709402084350585, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+568, 193425, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3806.183349609375, 3055.927001953125, 194.872161865234375, 4.716295242309570312, 120, 0, 0, 8, 0, 0, 0, 0, 0, 48001), -- Cricket (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+569, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3826.435791015625, 3066.046875, 192.2584228515625, 0.10457555204629898, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+570, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3823.8212890625, 3066.3212890625, 192.0225677490234375, 3.36040806770324707, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT])
(@CGUID+571, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3795.970458984375, 3062.08154296875, 195.211669921875, 4.139194965362548828, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+572, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3827.225830078125, 3068.991455078125, 192.1918487548828125, 0.180617719888687133, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+573, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3822.491455078125, 3068.974853515625, 192.725006103515625, 3.5525054931640625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+574, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3792.55908203125, 3062.439208984375, 195.0815277099609375, 3.911336183547973632, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+575, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3790.739501953125, 3065.849853515625, 195.392578125, 2.645235776901245117, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+576, 187502, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3821.76904296875, 3081.14404296875, 191.4495391845703125, 4.640824317932128906, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+577, 192111, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3829.65283203125, 3082.022705078125, 199.479705810546875, 0.673316359519958496, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Pine Flicker (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+578, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3812.9130859375, 3078.011474609375, 191.244354248046875, 2.161509037017822265, 120, 10, 0, 41990, 0, 1, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+579, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3822.69970703125, 3082.092041015625, 191.32904052734375, 3.622684717178344726, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+580, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3795.0556640625, 3065.765625, 194.8044281005859375, 3.963250160217285156, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+581, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3793.507080078125, 3066.526123046875, 195.04779052734375, 2.851508378982543945, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+582, 187691, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3808.236083984375, 3086.9306640625, 192.203033447265625, 6.067058086395263671, 120, 0, 0, 41990, 0, 0, 0, 33554432, 0, 48001), -- Brackenhide Scrabbler (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 169471 - Bloody Death)
(@CGUID+583, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3810.017333984375, 3088.842041015625, 192.0958251953125, 0.073380738496780395, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+584, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3821.551025390625, 3092.573486328125, 189.2827911376953125, 0.128497526049613952, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+585, 187500, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3791.0625, 3067.718017578125, 195.3177490234375, 3.963250160217285156, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48001), -- Gnawbone Grunt (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath)
(@CGUID+586, 187503, 2444, 13646, 13848, '0', 0, 0, 0, 1, -3808.03466796875, 3090.373291015625, 191.920196533203125, 5.110652923583984375, 120, 0, 0, 167960, 0, 0, 0, 0, 0, 48001), -- Gnawbone Underboss (Area: Brackenhide Waterhole - Difficulty: 0) (Auras: 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT])
(@CGUID+587, 196521, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3816.279541015625, 3100.005126953125, 191.2698822021484375, 3.522450447082519531, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+588, 192049, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3780.411376953125, 3093.4306640625, 192.8341522216796875, 4.46466064453125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Swoglet (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+589, 192044, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3808.046875, 3123.11328125, 188.865478515625, 0.937837600708007812, 120, 10, 0, 5, 0, 1, 0, 0, 0, 48001), -- Tiny Timbertooth (Area: Brackenhide Waterhole - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+590, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3763.7275390625, 3098.279052734375, 199.45806884765625, 3.476759910583496093, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+591, 198721, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3729.819580078125, 3080.6962890625, 195.962738037109375, 3.43311166763305664, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48001), -- Skitterfly (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+592, 193491, 2444, 13646, 13848, '0', 0, 0, 0, 0, -3720.28955078125, 2997.80615234375, 249.339599609375, 4.183254241943359375, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48001), -- Thickfur Ottuk (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+593, 189220, 2444, 13646, 13646, '0', 0, 0, 0, 0, -4277.74755859375, 2966.9375, 151.844940185546875, 2.67585301399230957, 120, 10, 0, 167960, 0, 1, 0, 0, 0, 48069), -- Highland Mammoth Bull (Area: The Azure Span - Difficulty: 0)
(@CGUID+594, 198202, 2444, 13646, 13848, '0', 19793, 0, 0, 0, -3964.9150390625, 2939.92529296875, 174.66229248046875, 2.201408863067626953, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Illusory Mage (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+595, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3949.723876953125, 3160.1103515625, 175.20245361328125, 6.167976856231689453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+596, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3912.3525390625, 3159.085205078125, 175.026885986328125, 3.361870765686035156, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+597, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3936.029541015625, 3138.325439453125, 174.988250732421875, 0.395689815282821655, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+598, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3930.427001953125, 3137.95654296875, 175.058074951171875, 1.546810865402221679, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+599, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3909.67529296875, 3135.194580078125, 174.933349609375, 2.763817787170410156, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+600, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3927.432373046875, 3137.037353515625, 175.254547119140625, 1.46104586124420166, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+601, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3946.869873046875, 3163.038330078125, 175.1829681396484375, 5.977605819702148437, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+602, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3907.94091796875, 3136.451416015625, 174.926055908203125, 2.363459110260009765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+603, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3949.435791015625, 3149.663330078125, 174.8625946044921875, 0.463834762573242187, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+604, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3922.279541015625, 3167.0556640625, 174.7567291259765625, 5.107741832733154296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+605, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3933.373291015625, 3138.279541015625, 175.0252227783203125, 1.079880952835083007, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+606, 198156, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3910.94091796875, 3139.498291015625, 175.2677459716796875, 2.777885675430297851, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Announcer (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+607, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3913.84716796875, 3160.6328125, 174.9968719482421875, 3.69133305549621582, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+608, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3943.376708984375, 3166.651123046875, 175.2000885009765625, 5.735437393188476562, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+609, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3907.244873046875, 3142.744873046875, 175.12481689453125, 2.978287696838378906, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+610, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3923.814208984375, 3168.807373046875, 174.7567291259765625, 5.035293102264404296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+611, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3946.989501953125, 3147.486083984375, 175.0113677978515625, 0.775284528732299804, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+612, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3939.4931640625, 3168.16748046875, 174.984130859375, 5.160653114318847656, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+613, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3946.182373046875, 3144.729248046875, 175.207183837890625, 0.829113423824310302, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+614, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3913.927001953125, 3133.682373046875, 174.9131927490234375, 2.186855316162109375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+615, 188333, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3915.529541015625, 3162.37158203125, 174.977935791015625, 4.51976633071899414, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Spectator (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+616, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3941.982666015625, 3139.990478515625, 175.025421142578125, 0.582286834716796875, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+617, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3917.4931640625, 3136.705810546875, 175.186065673828125, 2.224277496337890625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+618, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3907.541748046875, 3150.681396484375, 174.836639404296875, 3.356371164321899414, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+619, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3909.692626953125, 3157.137939453125, 175.13482666015625, 3.487411022186279296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+620, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3926.9775390625, 3170.739501953125, 174.7728118896484375, 4.693636894226074218, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+621, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3950.19091796875, 3158.084228515625, 174.8814239501953125, 6.098186969757080078, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+622, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3934.782958984375, 3170.521728515625, 175.059844970703125, 5.052895069122314453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
(@CGUID+623, 198169, 2444, 13646, 13848, '0', 18341, 0, 0, 0, -3950.692626953125, 3152.026123046875, 174.855377197265625, 0.124916635453701019, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069); -- Brackenhide Pyrotechnic Totem (Area: Brackenhide Waterhole - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+623;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Brackenhide Bully - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+3, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brackenhide Scrabbler
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '186399'), -- Hyena Mongrel - 186399 - Cosmetic - SitGround (Breakable)
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Brackenhide Bully - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Brackenhide Scrabbler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Brackenhide Bully
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Brackenhide Bully - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Brackenhide Scrabbler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+18, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Brackenhide Scrabbler
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Brackenhide Scrabbler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Brackenhide Scrabbler
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Brackenhide Scrabbler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Brackenhide Scrabbler
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Gnawbone Splintershield
(@CGUID+37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Brackenhide Bully
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Brackenhide Scrabbler - 169471 - Bloody Death
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Brackenhide Bully - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+46, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Brackenhide Bully
(@CGUID+48, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Brackenhide Scrabbler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Brawler
(@CGUID+57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Brackenhide Bully
(@CGUID+58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Brawler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Brackenhide Scrabbler - 169471 - Bloody Death
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Totemchewer - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+67, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+72, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+73, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override
(@CGUID+76, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+83, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '162084'), -- Brackenhide Scrabbler - 162084 - Permanent Feign Death (Burned)
(@CGUID+88, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override
(@CGUID+105, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+106, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+108, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+110, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+113, 0, 0, 0, 2, 0, 1, 0, 437, 0, 0, 0, 0, '370506'), -- Detry Hornswald - 370506 - Bubble Helm
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bloodclaw - 364022 - Channel: Earth Spikes [DNT]
(@CGUID+116, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+126, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '231580'), -- Stormfang Grunt - 231580 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+128, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override
(@CGUID+135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override, 364119 - Channel: Earth [DNT]
(@CGUID+138, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+145, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override
(@CGUID+149, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '131041'), -- Trapped Bruffalon - 131041 - Permanent Feign Death (Blood Pool and Flies)
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Bonecaster - 391041 - Channel: Earth Orb [DNT]
(@CGUID+155, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 392, 0, 0, 0, 0, ''), -- Stormfang Dustcaller
(@CGUID+159, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+168, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Bonecaster - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+175, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Stormfang Dustcaller
(@CGUID+176, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+179, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Dustcaller
(@CGUID+182, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+183, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+184, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Bonecaster
(@CGUID+186, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+187, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '396915'), -- Breezecone - 396915 - Air Infusion [DNT]
(@CGUID+189, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '392969'), -- Stormfang Grunt - 392969 - Hold Bowl of Meat [DNT]
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '392969'), -- Stormfang Grunt - 392969 - Hold Bowl of Meat [DNT]
(@CGUID+193, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '392969'), -- Stormfang Grunt - 392969 - Hold Bowl of Meat [DNT]
(@CGUID+194, 0, 0, 0, 3, 0, 1, 0, 615, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Dustcaller - 370774 - Channel: Wind [DNT]
(@CGUID+196, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Hexspiter - 364119 - Channel: Earth [DNT]
(@CGUID+198, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+200, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+201, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '131041'), -- Trapped Bruffalon - 131041 - Permanent Feign Death (Blood Pool and Flies)
(@CGUID+203, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+204, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+205, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371874'), -- Stormfang Shaman - 371874 - Scheming Shaman Name Override, 364119 - Channel: Earth [DNT]
(@CGUID+206, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+207, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+208, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Dustcaller - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+213, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+217, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Stormfang Grunt
(@CGUID+219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '390870'), -- Stormfang Grunt - 390870 - Dance! [DNT]
(@CGUID+221, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Stormfang Hexspiter
(@CGUID+223, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Stormfang Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+225, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Trapper - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+226, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Hidestitcher - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+227, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, '391245'), -- Duskpaw Trapper - 391245 - Supply-Laden
(@CGUID+229, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Hidestitcher
(@CGUID+231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Tendontearer
(@CGUID+233, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Duskpaw Trapper
(@CGUID+254, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Duskpaw Scavenger
(@CGUID+255, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+262, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+265, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+266, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+268, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+269, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Matriarch - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+275, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+277, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Hidestitcher - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+279, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+281, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+282, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Trapper - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+283, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+288, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+290, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Scavenger - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+291, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Scavenger - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+296, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Trapper - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+298, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Hidestitcher - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Duskpaw Scavenger - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+302, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Duskpaw Trapper
(@CGUID+303, 0, 0, 0, 0, 0, 1, 0, 10, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+306, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Duskpaw Scavenger - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+307, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Duskpaw Tendontearer - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+308, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+311, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Hidestitcher - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+312, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Duskpaw Scavenger - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+317, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Scavenger
(@CGUID+318, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+319, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Trapper - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+323, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Trapper - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Tendontearer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Hyena Mongrel - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Matriarch - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+337, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+338, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Cracktooth
(@CGUID+341, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+342, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Trapper - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+343, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Hidestitcher
(@CGUID+344, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Tendontearer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Tendontearer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+350, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371873'), -- Duskpaw Stalker - 371873 - Opportunistic Stalker Name Override
(@CGUID+351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391245'), -- Duskpaw Trapper - 391245 - Supply-Laden
(@CGUID+353, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+355, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Duskpaw Trapper
(@CGUID+356, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Duskpaw Scavenger - 169471 - Bloody Death
(@CGUID+359, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+360, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+361, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+362, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '131041'), -- Trapped Mammoth - 131041 - Permanent Feign Death (Blood Pool and Flies)
(@CGUID+364, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Hidestitcher - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+369, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+370, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+375, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Duskpaw Scavenger
(@CGUID+378, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+380, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, '371873 372408'), -- Duskpaw Stalker - 371873 - Opportunistic Stalker Name Override, 372408 - Stealth
(@CGUID+381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+386, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Hyena Mongrel - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+387, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391254'), -- Trapped Ottuk - 391254 - Hearty
(@CGUID+391, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Duskpaw Tendontearer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+393, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+397, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Matriarch - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+411, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Duskpaw Trapper
(@CGUID+413, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Scavenger
(@CGUID+414, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Tendontearer
(@CGUID+416, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+417, 0, 0, 0, 3, 0, 1, 0, 615, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+419, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Duskpaw Scavenger
(@CGUID+420, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, '391245'), -- Duskpaw Trapper - 391245 - Supply-Laden
(@CGUID+422, 0, 0, 0, 0, 0, 1, 0, 747, 0, 0, 0, 0, ''), -- Duskpaw Trapper
(@CGUID+423, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+425, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Splintershield - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+430, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, '371873 372408'), -- Duskpaw Stalker - 371873 - Opportunistic Stalker Name Override, 372408 - Stealth
(@CGUID+434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391245'), -- Gnawbone Totemchewer - 391245 - Supply-Laden
(@CGUID+436, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+438, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Brawler
(@CGUID+442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+443, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+448, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+452, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+453, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Brawler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+456, 0, 0, 0, 3, 0, 1, 0, 601, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+457, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369547'), -- Gnawbone Brawler - 369547 - Sparring Aura: Attack1H/CombatAbility1HBig01 [DNT]
(@CGUID+458, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369547'), -- Gnawbone Brawler - 369547 - Sparring Aura: Attack1H/CombatAbility1HBig01 [DNT]
(@CGUID+460, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+463, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+470, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Totemchewer
(@CGUID+477, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+481, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Brawler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+482, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+487, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Chainchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+489, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+492, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+493, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Brawler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+495, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Brawler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+498, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+500, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+504, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Hyena Mongrel - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+507, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391413'), -- Flayfist - 391413 - Gnoll Back Banner x3 [DNT]
(@CGUID+509, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+510, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+511, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+512, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+513, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+515, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+516, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+519, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+520, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+523, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+524, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+525, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Brawler
(@CGUID+526, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+528, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Hyena Mongrel
(@CGUID+536, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Brawler - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+537, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+542, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+544, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+546, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391245'), -- Gnawbone Brawler - 391245 - Supply-Laden
(@CGUID+547, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+551, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+553, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Splintershield - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Grunt - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+558, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Totemchewer - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+560, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Gnawbone Grunt - 169471 - Bloody Death
(@CGUID+561, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Totemchewer - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+562, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+563, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371733'), -- Gnawbone Grunt - 371733 - Sparring Aura: AttackUnarmed [DNT]
(@CGUID+564, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Chainchewer - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+567, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+570, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370828'), -- Gnawbone Grunt - 370828 - Conversation Aura: Talk/Laugh/Roar/Cower [DNT]
(@CGUID+571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Grunt - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+573, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Chainchewer
(@CGUID+575, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+577, 0, 0, 0, 3, 0, 1, 0, 615, 0, 0, 0, 0, ''), -- Pine Flicker
(@CGUID+579, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Gnawbone Grunt
(@CGUID+581, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Grunt - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+582, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Brackenhide Scrabbler - 169471 - Bloody Death
(@CGUID+585, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368927'), -- Gnawbone Grunt - 368927 - Cosmetic - Sleep Zzz (With Aggro Change) - Breath
(@CGUID+586, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371863 388589'), -- Gnawbone Underboss - 371863 - Ambitious Underboss Name Override + Banner [DNT], 388589 - Gnoll Back Banner [DNT]
(@CGUID+590, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skitterfly
(@CGUID+591, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Skitterfly

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+100;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 376377, 2444, 13646, 13848, '0', 19801, 0, -3937.94970703125, 3113.979248046875, 175.0377349853515625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+1, 376377, 2444, 13646, 13848, '0', 19801, 0, -3953.685791015625, 3098.991455078125, 174.9708251953125, 4.673987865447998046, 0, 0, -0.72055244445800781, 0.693400442600250244, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+2, 385378, 2444, 13646, 13848, '0', 0, 0, -3950.0087890625, 3209.59716796875, 172.4762115478515625, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+3, 385106, 2444, 13646, 13848, '0', 0, 0, -3889.578125, 3128.997314453125, 175.02886962890625, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+4, 385100, 2444, 13646, 13848, '0', 0, 0, -3836.953125, 3102.140625, 188.666534423828125, 4.450596809387207031, 0, 0, -0.7933511734008789, 0.608764231204986572, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+5, 376377, 2444, 13646, 13848, '0', 19801, 0, -3913.638916015625, 2973.609375, 175.007110595703125, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+6, 381020, 2444, 13646, 13848, '0', 0, 0, -3269.7119140625, 4510.9697265625, 0.345486104488372802, 0.471238404512405395, -0.00268840789794921, -0.02164745330810546, 0.233237266540527343, 0.972175180912017822, 120, 255, 0, 48001), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+7, 376377, 2444, 13646, 13848, '0', 19801, 0, -3960.65966796875, 2999.686767578125, 166.3937530517578125, 5.288181304931640625, 0, 0, -0.47723197937011718, 0.87877732515335083, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+8, 376377, 2444, 13646, 13848, '0', 19801, 0, -3940.48095703125, 3058.137939453125, 168.8661346435546875, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+9, 376535, 2444, 13646, 13848, '0', 0, 0, -3819.189208984375, 3071.87841796875, 191.9437255859375, 4.81806182861328125, 0, 0, -0.66877651214599609, 0.743463456630706787, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+10, 376377, 2444, 13646, 13848, '0', 19801, 0, -3965.616455078125, 3074.2578125, 174.566925048828125, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+11, 380948, 2444, 13646, 13848, '0', 0, 0, -3168.583251953125, 4463.4921875, 0.0791034996509552, 2.836153030395507812, 0.019017696380615234, -0.01068496704101562, 0.988101959228515625, 0.152245521545410156, 120, 255, 0, 48001), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+12, 376377, 2444, 13646, 13848, '0', 19801, 0, -3920.92529296875, 3074.4765625, 175.084747314453125, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+13, 376377, 2444, 13646, 13848, '0', 19801, 0, -3961.607666015625, 3086.46435546875, 174.947998046875, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+14, 376535, 2444, 13646, 13848, '0', 0, 0, -3871.013916015625, 3068.260498046875, 183.8590087890625, 5.036518573760986328, 0, 0, -0.58374500274658203, 0.811937034130096435, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+15, 376377, 2444, 13646, 13848, '0', 19801, 0, -3968.354248046875, 3053.798583984375, 173.98040771484375, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+16, 385098, 2444, 13646, 13848, '0', 0, 0, -3824.763916015625, 3069.107666015625, 191.853851318359375, 0.427606821060180664, 0, 0, 0.212178230285644531, 0.977230966091156005, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+17, 385099, 2444, 13646, 13848, '0', 0, 0, -3997.345458984375, 3165.201416015625, 175.1619720458984375, 3.534291028976440429, 0, 0, -0.98078536987304687, 0.195089906454086303, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+18, 376377, 2444, 13646, 13848, '0', 19801, 0, -3967.44970703125, 3032.091064453125, 173.40130615234375, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+19, 376535, 2444, 13646, 13848, '0', 0, 0, -3860.9775390625, 2966.710205078125, 180.6123809814453125, 5.68695831298828125, 0, 0, -0.2937173843383789, 0.955892324447631835, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+20, 376377, 2444, 13646, 13848, '0', 19801, 0, -3912.736083984375, 3005.72314453125, 174.8756561279296875, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+21, 376377, 2444, 13646, 13848, '0', 19801, 0, -3943.416748046875, 2996.267333984375, 166.396087646484375, 5.265894412994384765, 0, 0, -0.48699474334716796, 0.873404860496520996, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+22, 380947, 2444, 13646, 13848, '0', 0, 0, -3162.204833984375, 4472.05712890625, 0.409722238779067993, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 0, 48001), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+23, 376535, 2444, 13646, 13848, '0', 0, 0, -3807.56591796875, 3074.80908203125, 192.0692291259765625, 5.036518573760986328, 0, 0, -0.58374500274658203, 0.811937034130096435, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+24, 376377, 2444, 13646, 13848, '0', 19801, 0, -3948.732666015625, 2975.55908203125, 165.590911865234375, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+25, 376535, 2444, 13646, 13848, '0', 0, 0, -3767.460205078125, 3022.158935546875, 191.1073455810546875, 5.036518573760986328, 0, 0, -0.58374500274658203, 0.811937034130096435, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+26, 385104, 2444, 13646, 13848, '0', 0, 0, -3866.84716796875, 2981.369873046875, 180.3008575439453125, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+27, 376535, 2444, 13646, 13848, '0', 0, 0, -3807.263916015625, 3096.560791015625, 191.8639678955078125, 4.15158843994140625, 0, 0, -0.87517547607421875, 0.483805596828460693, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+28, 376377, 2444, 13646, 13848, '0', 19801, 0, -3937.126708984375, 3038.439208984375, 170.5538787841796875, 6.090929031372070312, 0.20553445816040039, -0.25742626190185546, -0.03317737579345703, 0.943602979183197021, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+29, 381019, 2444, 13646, 13848, '0', 0, 0, -3199.6181640625, 4622.62744140625, 4.076388835906982421, 5.061457157135009765, -0.01799440383911132, -0.0123300552368164, -0.57356739044189453, 0.818867862224578857, 120, 255, 0, 48001), -- Gnoll Cage 01 (Always Open) (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+30, 376377, 2444, 13646, 13848, '0', 19801, 0, -3987.03125, 2974.2353515625, 174.7452545166015625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+31, 376377, 2444, 13646, 13848, '0', 19801, 0, -3964.888916015625, 2961.454833984375, 171.92596435546875, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+32, 376377, 2444, 13646, 13848, '0', 19801, 0, -3987.010498046875, 2963.919189453125, 174.9716644287109375, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+33, 385105, 2444, 13646, 13848, '0', 0, 0, -4119.23095703125, 3035.43310546875, 191.9900970458984375, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+34, 379673, 2444, 13646, 13848, '0', 0, 0, -4002.5087890625, 2949.19970703125, 181.239837646484375, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+35, 376377, 2444, 13646, 13848, '0', 19801, 0, -3923.5869140625, 2947.2587890625, 166.992523193359375, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+36, 379673, 2444, 13646, 13848, '0', 0, 0, -3982.267333984375, 2937.8916015625, 175.977691650390625, 4.231187820434570312, 0, 0, -0.85523223876953125, 0.518244922161102294, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+37, 385101, 2444, 13646, 13848, '0', 0, 0, -4090.447998046875, 2971.689208984375, 196.1216278076171875, 5.471607208251953125, 0, 0, -0.39474391937255859, 0.918791174888610839, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+38, 376377, 2444, 13646, 13848, '0', 19801, 0, -3930.829833984375, 2924.41748046875, 173.25634765625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Rotting Pile (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+39, 385103, 2444, 13646, 13848, '0', 0, 0, -4114.09033203125, 2969.376708984375, 194.531768798828125, 1.911133170127868652, 0, 0, 0.816640853881835937, 0.577146172523498535, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+40, 376396, 2444, 13646, 13848, '0', 0, 0, -3995.328125, 2909.028564453125, 180.943572998046875, 5.559640884399414062, 0, 0, -0.35393238067626953, 0.935271024703979492, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+41, 379673, 2444, 13646, 13848, '0', 0, 0, -4066.095458984375, 2932.87158203125, 190.7870330810546875, 2.463850259780883789, 0, 0, 0.9431304931640625, 0.332422733306884765, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+42, 379673, 2444, 13646, 13848, '0', 0, 0, -4024.15283203125, 2923.507080078125, 186.2711029052734375, 5.449194908142089843, 0, 0, -0.4050149917602539, 0.914310038089752197, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+43, 376414, 2444, 13646, 13848, '0', 0, 0, -4033.4775390625, 2909.326416015625, 185.5942535400390625, 0.752097904682159423, -0.45563793182373046, -0.22731399536132812, 0.291742324829101562, 0.809696733951568603, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+44, 379673, 2444, 13646, 13848, '0', 0, 0, -3952.857666015625, 2901.759521484375, 180.725677490234375, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+45, 385102, 2444, 13646, 13848, '0', 0, 0, -4110.53466796875, 2934.811767578125, 193.04913330078125, 6.117380619049072265, 0, 0, -0.08280754089355468, 0.996565580368041992, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+46, 376396, 2444, 13646, 13848, '0', 0, 0, -4023.40283203125, 2898.09375, 182.6918487548828125, 2.198547601699829101, 0, 0, 0.890877723693847656, 0.454243183135986328, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+47, 379673, 2444, 13646, 13848, '0', 0, 0, -4099.99853515625, 2914.0322265625, 188.3868560791015625, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+48, 385096, 2444, 13646, 13848, '0', 0, 0, -4153.56787109375, 2957.515625, 195.2713470458984375, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+49, 376396, 2444, 13646, 13848, '0', 0, 0, -4093.526123046875, 2907.66845703125, 188.9054107666015625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+50, 376396, 2444, 13646, 13848, '0', 0, 0, -3990.50341796875, 2882.140625, 180.606048583984375, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+51, 379673, 2444, 13646, 13848, '0', 0, 0, -4032.350830078125, 2885.8203125, 181.5685882568359375, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+52, 379673, 2444, 13646, 13848, '0', 0, 0, -4044.088623046875, 2881.030517578125, 185.1024017333984375, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+53, 376414, 2444, 13646, 13848, '0', 0, 0, -4044.817626953125, 2882.443603515625, 187.369598388671875, 0.428975105285644531, 0, 0, 0.212846755981445312, 0.977085590362548828, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+54, 376414, 2444, 13646, 13848, '0', 0, 0, -3964.322998046875, 2881.2978515625, 184.5755157470703125, 3.285547256469726562, 0, 0, -0.99741077423095703, 0.07191506028175354, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+55, 379673, 2444, 13646, 13848, '0', 0, 0, -4103.38720703125, 2882.2822265625, 182.7474365234375, 3.019632339477539062, 0, 0, 0.998141288757324218, 0.060942310839891433, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+56, 376396, 2444, 13646, 13848, '0', 0, 0, -4074.317626953125, 2861.39404296875, 186.596588134765625, 4.18983316421508789, 0, 0, -0.86576461791992187, 0.500451445579528808, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+57, 376414, 2444, 13646, 13848, '0', 0, 0, -4011.685791015625, 2852.0869140625, 181.5911865234375, 5.467925071716308593, 0, 0, -0.39643478393554687, 0.918062865734100341, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+58, 385108, 2444, 13646, 13848, '0', 0, 0, -4022.757080078125, 2848.033935546875, 180.4154510498046875, 4.520405769348144531, 0, 0, -0.77162361145019531, 0.636079370975494384, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+59, 376396, 2444, 13646, 13848, '0', 0, 0, -4053.317626953125, 2843.29345703125, 185.4498291015625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+60, 380600, 2444, 13646, 13848, '0', 0, 0, -4233.21875, 3145.5634765625, 174.796875, 2.384970903396606445, 0, 0, 0.929289817810058593, 0.369351357221603393, 120, 255, 1, 48001), -- Enriched Earthen Shard (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+61, 379673, 2444, 13646, 13848, '0', 0, 0, -4038.520751953125, 2836.703125, 183.4365081787109375, 2.407464027404785156, 0, 0, 0.933384895324707031, 0.358876913785934448, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+62, 376414, 2444, 13646, 13848, '0', 0, 0, -4020.34033203125, 2837.630126953125, 182.3168182373046875, 3.383770465850830078, 0, 0, -0.99267768859863281, 0.12079312652349472, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+63, 376414, 2444, 13646, 13848, '0', 0, 0, -3947.8369140625, 2868.975830078125, 187.516510009765625, 1.930597186088562011, 0, 0, 0.822218894958496093, 0.569171369075775146, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+64, 376396, 2444, 13646, 13848, '0', 0, 0, -4072.548583984375, 2820.4853515625, 190.5197906494140625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+65, 376396, 2444, 13646, 13848, '0', 0, 0, -4039.26904296875, 2816.3369140625, 184.6642608642578125, 5.249300003051757812, 0, 0, -0.49422454833984375, 0.869334280490875244, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+66, 376414, 2444, 13646, 13848, '0', 0, 0, -3944.046875, 2842.317626953125, 183.14251708984375, 3.100615262985229492, 0.03952646255493164, 0.727138519287109375, -0.68524456024169921, 0.012128654867410659, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+67, 376396, 2444, 13646, 13848, '0', 0, 0, -3931.8369140625, 2856.30029296875, 211.1986083984375, 3.441575288772583007, 0, 0, -0.98877239227294921, 0.149429425597190856, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+68, 379673, 2444, 13646, 13848, '0', 0, 0, -3922.708251953125, 2861.359375, 185.8045806884765625, 0.59550255537033081, 0, 0, 0.293371200561523437, 0.955998599529266357, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+69, 379673, 2444, 13646, 13848, '0', 0, 0, -3909.53125, 2892.401123046875, 180.1386260986328125, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+70, 376414, 2444, 13646, 13848, '0', 0, 0, -3923.623291015625, 2859.768310546875, 187.5063018798828125, 1.257541298866271972, 0, 0, 0.588150978088378906, 0.808751165866851806, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+71, 376396, 2444, 13646, 13848, '0', 0, 0, -3979.5869140625, 2826.311767578125, 197.1175079345703125, 1.059999704360961914, 0, 0, 0.505533218383789062, 0.862807154655456542, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+72, 379673, 2444, 13646, 13848, '0', 0, 0, -3990.263916015625, 2812.66064453125, 195.9539642333984375, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+73, 379673, 2444, 13646, 13848, '0', 0, 0, -4071.479248046875, 2794.135498046875, 194.379638671875, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+74, 385097, 2444, 13646, 13848, '0', 0, 0, -3926.5625, 2845.721435546875, 187.6446075439453125, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+75, 376414, 2444, 13646, 13848, '0', 0, 0, -3926.3681640625, 2837.954833984375, 189.79302978515625, 2.549910545349121093, 0, 0, 0.956557273864746093, 0.291544497013092041, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+76, 376396, 2444, 13646, 13848, '0', 0, 0, -3939.970458984375, 2824.462646484375, 202.9822998046875, 2.048964977264404296, 0, 0, 0.854445457458496093, 0.519541144371032714, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+77, 376414, 2444, 13646, 13848, '0', 0, 0, -3928.407958984375, 2839.114501953125, 190.7171173095703125, 2.889859914779663085, 0, 0, 0.992089271545410156, 0.125534340739250183, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+78, 385109, 2444, 13646, 13848, '0', 0, 0, -3987.114501953125, 2794.1337890625, 200.0057220458984375, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+79, 376414, 2444, 13646, 13848, '0', 0, 0, -3989.5, 2782.673583984375, 200.601806640625, 2.282358646392822265, 0, 0, 0.909125328063964843, 0.41652265191078186, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+80, 379673, 2444, 13646, 13848, '0', 0, 0, -3889.81591796875, 2859.4853515625, 190.6611175537109375, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+81, 376396, 2444, 13646, 13848, '0', 0, 0, -3963.18408203125, 2771.0791015625, 206.615325927734375, 0.239127144217491149, 0, 0, 0.119278907775878906, 0.992860794067382812, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+82, 379673, 2444, 13646, 13848, '0', 0, 0, -3904.05908203125, 2818.37841796875, 198.9373931884765625, 2.319022655487060546, 0, 0, 0.916607856750488281, 0.399787485599517822, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+83, 379673, 2444, 13646, 13848, '0', 0, 0, -3968.013916015625, 2746.673583984375, 210.3759002685546875, 1.971535682678222656, 0, 0, 0.833696365356445312, 0.552223086357116699, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+84, 376396, 2444, 13646, 13848, '0', 0, 0, -3911.1025390625, 2801.873291015625, 201.802734375, 1.033450841903686523, 0, 0, 0.494035720825195312, 0.869441628456115722, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+85, 385107, 2444, 13646, 13848, '0', 0, 0, -3918.927001953125, 2776.217041015625, 214.766143798828125, 1.788962006568908691, 0, 0, 0.77988433837890625, 0.625923693180084228, 120, 255, 1, 48001), -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+86, 376396, 2444, 13646, 13848, '0', 0, 0, -3910.151123046875, 2772.2822265625, 215.052398681640625, 0.239127144217491149, 0, 0, 0.119278907775878906, 0.992860794067382812, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+87, 379673, 2444, 13646, 13848, '0', 0, 0, -3873.79345703125, 2844.93310546875, 200.06829833984375, 1.446206569671630859, 0, 0, 0.661714553833007812, 0.749755859375, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+88, 376396, 2444, 13646, 13848, '0', 0, 0, -3883.517333984375, 2819.5556640625, 202.84039306640625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+89, 376414, 2444, 13646, 13848, '0', 0, 0, -3910.9150390625, 2773.48095703125, 217.558502197265625, 0.311267882585525512, 0, 0, 0.15500640869140625, 0.987913489341735839, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+90, 376414, 2444, 13646, 13848, '0', 0, 0, -3937.3125, 2757.044189453125, 216.910064697265625, 2.711995124816894531, 0, 0, 0.977019309997558593, 0.213150843977928161, 120, 255, 1, 48001), -- Gnawed Keys (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+91, 376396, 2444, 13646, 13848, '0', 0, 0, -3925.463623046875, 2762.5634765625, 214.6914215087890625, 0, 0, 0, 0, 1, 120, 255, 1, 48001), -- Gnoll Stake (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+92, 379673, 2444, 13646, 13848, '0', 0, 0, -3911.473876953125, 2754.479248046875, 214.897064208984375, 2.833225488662719726, 0, 0, 0.988137245178222656, 0.153573378920555114, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+93, 379673, 2444, 13646, 13848, '0', 0, 0, -3891.546875, 2778.75439453125, 208.52935791015625, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+94, 379673, 2444, 13646, 13848, '0', 0, 0, -3854.541748046875, 2816.9853515625, 206.2357940673828125, 2.92641448974609375, 0, 0, 0.994217872619628906, 0.107381641864776611, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+95, 379673, 2444, 13646, 13848, '0', 0, 0, -3861.085205078125, 2805.080810546875, 204.7869110107421875, 5.554376602172851562, 0, 0, -0.35639286041259765, 0.934336185455322265, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+96, 376535, 2444, 13646, 13848, '0', 0, 0, -3843.60595703125, 2834.817626953125, 203.720672607421875, 5.852986335754394531, 0, 0, -0.21344470977783203, 0.976955175399780273, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+97, 379673, 2444, 13646, 13848, '0', 0, 0, -3887.473876953125, 2733.3603515625, 226.3047637939453125, 4.828885078430175781, 0, 0, -0.66474342346191406, 0.747071743011474609, 120, 255, 1, 48001), -- Duskpaw Snaptrap (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+98, 376535, 2444, 13646, 13848, '0', 0, 0, -3849.416748046875, 2895.923583984375, 195.5551605224609375, 3.128637075424194335, 0, 0, 0.999979019165039062, 0.006477782968431711, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+99, 376535, 2444, 13646, 13848, '0', 0, 0, -3799.779541015625, 2862.302001953125, 201.5183563232421875, 3.702948570251464843, 0, 0, -0.96086788177490234, 0.277007102966308593, 120, 255, 1, 48001), -- Gnawbone Weapon Rack (Area: Brackenhide Waterhole - Difficulty: 0)
(@OGUID+100, 385189, 2444, 13646, 13848, '0', 0, 0, -3758.339111328125, 3011.047119140625, 190.457275390625, 1.963498473167419433, 0, 0, 0.831470489501953125, 0.555568933486938476, 120, 255, 1, 48001); -- Campfire (Area: Brackenhide Waterhole - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+100;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+60, 0, 0, 0, 1, 19980, 4352), -- Enriched Earthen Shard
(@OGUID+100, 0, 0, 0.948323786258697509, 0.317304253578186035, 0, 0); -- Campfire

UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193491; -- Thickfur Ottuk
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_walk`=0.400000005960464477, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=189122; -- Palamanther
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110914, `unit_flags3`=16777216 WHERE `entry`=188260; -- [DNT] Wind Director
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187505; -- Flayfist
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187523; -- Duskpaw Stalker
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187528; -- Cracktooth
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187580; -- Trapped Ottuk
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187574; -- Trapped Hornswog
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=67143680, `unit_flags3`=16777216 WHERE `entry`=195446; -- Target
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187568; -- Duskpaw Scavenger
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187579; -- Trapped Beaver
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197820; -- Duskpaw Tendontearer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187941; -- Duskpaw Hidestitcher
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187510; -- Duskpaw Trapper
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187573; -- Trapped Mammoth
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187575; -- Trapped Vorquin
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777216 WHERE `entry`=199515; -- Breezecone
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187566; -- Hyena Matriarch
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=187578; -- Trapped Bruffalon
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187553; -- Bloodclaw
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=187463; -- Detry Hornswald
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187930; -- Stormfang Hexspiter
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187551; -- Stormfang Dustcaller
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2574, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187931; -- Stormfang Bonecaster
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187549; -- Stormfang Grunt
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.60000002384185791 WHERE `entry`=198138; -- Muckfish
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187552; -- Stormfang Shaman
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (187743, 187723); -- Crudely Bound Elemental
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187503; -- Gnawbone Underboss
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=196521; -- Gnawbone Chainchewer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187936; -- Gnawbone Totemchewer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110914, `unit_flags3`=16777216 WHERE `entry`=188209; -- [DNT] Wave Event Controller
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198721; -- Skitterfly
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=192111; -- Pine Flicker
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187500; -- Gnawbone Grunt
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187502; -- Gnawbone Brawler
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=197847; -- Gnawbone Splintershield
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=1932, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187497; -- Waste Water Elemental
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187692; -- Brackenhide Bully
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187565; -- Hyena Mongrel
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187691; -- Brackenhide Scrabbler
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=1667, `unit_flags`=32848, `unit_flags2`=2048 WHERE `entry`=187750; -- Deathwind
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=187748; -- Spineripper
UPDATE `creature_template` SET `gossip_menu_id`=30053, `minlevel`=68, `maxlevel`=68, `faction`=16, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=198156; -- Brackenhide Announcer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=198169; -- Brackenhide Pyrotechnic Totem
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=188333; -- Brackenhide Spectator
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000 WHERE `entry`=61245; -- Capacitor Totem
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198202; -- Illusory Mage

DELETE FROM `creature_template_addon` WHERE `entry` IN (198202);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198202, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 198202 (Illusory Mage)

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (187505,187523,187528,197820,187510,187503,196521,187502,197847,187692));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(187505, 1, 60963, 0, 0, 0, 0, 0, 0, 0, 0, 48001), -- Flayfist
(187523, 1, 0, 0, 0, 0, 0, 0, 191696, 0, 0, 48001), -- Duskpaw Stalker
(187528, 1, 0, 0, 0, 0, 0, 0, 191700, 0, 0, 48001), -- Cracktooth
(197820, 1, 107298, 0, 0, 107298, 0, 0, 0, 0, 0, 48001), -- Duskpaw Tendontearer
(187510, 1, 0, 0, 0, 0, 0, 0, 191696, 0, 0, 48001), -- Duskpaw Trapper
(187503, 1, 60824, 0, 0, 0, 0, 0, 0, 0, 0, 48001), -- Gnawbone Underboss
(196521, 1, 200062, 0, 0, 0, 0, 0, 0, 0, 0, 48001), -- Gnawbone Chainchewer
(187502, 1, 189553, 0, 0, 0, 0, 0, 0, 0, 0, 48001), -- Gnawbone Brawler
(197847, 1, 192563, 0, 0, 192565, 0, 0, 0, 0, 0, 48001), -- Gnawbone Splintershield
(187692, 1, 113621, 0, 0, 0, 0, 0, 0, 0, 0, 48001); -- Brackenhide Bully

DELETE FROM `spell_script_names` WHERE `spell_id` IN (169471, 131041, 162084, 231580);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(169471, 'spell_gen_feign_death_all_flags'),
(131041, 'spell_gen_feign_death_all_flags'),
(162084, 'spell_gen_feign_death_all_flags'),
(231580, 'spell_gen_feign_death_all_flags');

DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (192111, 195446, 198721, 198183, 187463, 198202);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(192111, 0, 0, 1, 0, 0, 0, NULL),
(195446, 0, 0, 1, 1, 0, 0, NULL),
(198721, 0, 0, 1, 0, 0, 0, NULL),
(198183, 0, 1, 0, 0, 0, 0, NULL),
(187463, 2, 0, 1, 1, 0, 0, NULL),
(198202, 2, 0, 0, 0, 0, 0, NULL);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (19801, 19793, 18341);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19801, 'Cosmetic - See Rotting Pile'),
(19793, 'Cosmetic - See Illusory Mage'),
(18341, 'Cosmetic - See the would-be warlords arena');

DELETE FROM `phase_area` WHERE `PhaseId` IN (19801, 19793, 18341);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13646, 19801, 'Cosmetic - See Rotting Pile'),
(13646, 19793, 'Cosmetic - See Illusory Mage'),
(13646, 18341, 'Cosmetic - See the would-be warlords arena');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 19801 AND `SourceEntry` = 13646) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 19793 AND `SourceEntry` = 13646) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 18341 AND `SourceEntry` = 13646);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 19801, 13646, 0, 0, 47, 0, 66262, 64, 0, 1, 0, 0, '', 'Apply Phase 19801 If Quest 66262 IS NOT in Progress'),
(26, 19793, 13646, 0, 0, 47, 0, 66264, 64, 0, 0, 0, 0, '', 'Apply Phase 19793 If Quest 66264 IS rewarded'),
(26, 19793, 13646, 0, 0, 47, 0, 66263, 64, 0, 0, 0, 0, '', 'Apply Phase 19793 If Quest 66263 IS rewarded'),
(26, 19793, 13646, 0, 0, 47, 0, 66267, 74, 0, 1, 0, 0, '', 'Apply Phase 19793 If Quest 66267 IS NOT in Progress | complete | rewarded'),
(26, 18341, 13646, 0, 0, 47, 0, 66270, 10, 0, 0, 0, 0, '', 'Apply Phase 18341 If Quest 66270 IS in Progress | complete');

-- Quest stuff
DELETE FROM `quest_request_items` WHERE `ID` IN (66270 /*Whack-a-Gnoll*/, 66269 /*Just To Be Sure*/, 66268 /*Third Try's the Charm*/, 66267 /*M.E.T.A.*/, 66266 /*Filthy Mongrels*/, 66265 /*Who's Next?*/, 66264 /*Disarmed and Docile*/, 66263 /*A Precision Approach*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(66270, 0, 604, 0, 0, 'What are you waiting for?', 48069), -- Whack-a-Gnoll
(66269, 0, 604, 0, 0, 'Don\'t they know they\'ve been outwitted?', 48069), -- Just To Be Sure
(66268, 0, 603, 0, 0, 'All according to plan!', 48069), -- Third Try's the Charm
(66267, 0, 604, 0, 0, 'Have you checked their pockets for keys? They have to keep them somewhere.', 48069), -- M.E.T.A.
(66266, 0, 604, 0, 0, 'Why, no I\'m not a \"dog person.\" Why do you ask?', 48069), -- Filthy Mongrels
(66265, 0, 1, 0, 0, 'How goes hunting the hunter?', 48069), -- Who's Next?
(66264, 1, 1, 0, 0, 'Surely they\'re just lying about?', 48069), -- Disarmed and Docile
(66263, 0, 603, 0, 0, 'Did I mention I\'m allergic to gnoll fur? My throat gets itchy just thinking about them.', 48069); -- A Precision Approach

DELETE FROM `creature_queststarter` WHERE (`id`=187463 AND `quest` IN (66270,66269,66268,66266,66265,66264,66263,66262)) OR (`id`=198202 AND `quest`=66267);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(187463, 66270, 48069), -- Whack-a-Gnoll offered Detry Hornswald
(187463, 66269, 48069), -- Just To Be Sure offered Detry Hornswald
(187463, 66268, 48069), -- Third Try's the Charm offered Detry Hornswald
(198202, 66267, 48069), -- M.E.T.A. offered Illusory Mage
(187463, 66266, 48069), -- Filthy Mongrels offered Detry Hornswald
(187463, 66265, 48069), -- Who's Next? offered Detry Hornswald
(187463, 66264, 48069), -- Disarmed and Docile offered Detry Hornswald
(187463, 66263, 48069), -- A Precision Approach offered Detry Hornswald
(187463, 66262, 48069); -- Waste Water Cleanup offered Detry Hornswald

DELETE FROM `creature_questender` WHERE (`id`=187463 AND `quest` IN (66270,66268,66269,66267,66266,66265,66264,66263,66262));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(187463, 66270, 48069), -- Whack-a-Gnoll ended by Detry Hornswald
(187463, 66268, 48069), -- Third Try's the Charm ended by Detry Hornswald
(187463, 66269, 48069), -- Just To Be Sure ended by Detry Hornswald
(187463, 66267, 48069), -- M.E.T.A. ended by Detry Hornswald
(187463, 66266, 48069), -- Filthy Mongrels ended by Detry Hornswald
(187463, 66265, 48069), -- Who's Next? ended by Detry Hornswald
(187463, 66264, 48069), -- Disarmed and Docile ended by Detry Hornswald
(187463, 66263, 48069), -- A Precision Approach ended by Detry Hornswald
(187463, 66262, 48069); -- Waste Water Cleanup ended by Detry Hornswald

DELETE FROM `quest_template_addon` WHERE `ID` IN (66263, 66264, 66269, 66268);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(66263, 0, 0, 0, 66262, 66267, -66263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- A Precision Approach
(66264, 0, 0, 0, 66262, 66267, -66263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Disarmed and Docile
(66269, 0, 0, 0, 0, 66270, -66269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Just To Be Sure
(66268, 0, 0, 0, 0, 66270, -66269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Third Try's the Charm

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19 AND `SourceGroup` = 0 AND `SourceEntry` IN (66265, 66266, 66268, 66269));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 66265, 0, 0, 8, 0, 66263, 0, 0, 0, 0, 0, '', 'Accept quest 66265 - Quest 66263 needs to be rewarded'),
(19, 0, 66265, 0, 0, 8, 0, 66264, 0, 0, 0, 0, 0, '', 'Accept quest 66265 - Quest 66264 needs to be rewarded'),
(19, 0, 66266, 0, 0, 8, 0, 66263, 0, 0, 0, 0, 0, '', 'Accept quest 66266 - Quest 66263 needs to be rewarded'),
(19, 0, 66266, 0, 0, 8, 0, 66264, 0, 0, 0, 0, 0, '', 'Accept quest 66266 - Quest 66264 needs to be rewarded'),
(19, 0, 66268, 0, 0, 8, 0, 66265, 0, 0, 0, 0, 0, '', 'Accept quest 66268 - Quest 66265 needs to be rewarded'),
(19, 0, 66268, 0, 0, 8, 0, 66266, 0, 0, 0, 0, 0, '', 'Accept quest 66268 - Quest 66266 needs to be rewarded'),
(19, 0, 66268, 0, 0, 8, 0, 66267, 0, 0, 0, 0, 0, '', 'Accept quest 66268 - Quest 66267 needs to be rewarded'),
(19, 0, 66269, 0, 0, 8, 0, 66265, 0, 0, 0, 0, 0, '', 'Accept quest 66269 - Quest 66265 needs to be rewarded'),
(19, 0, 66269, 0, 0, 8, 0, 66266, 0, 0, 0, 0, 0, '', 'Accept quest 66269 - Quest 66266 needs to be rewarded'),
(19, 0, 66269, 0, 0, 8, 0, 66267, 0, 0, 0, 0, 0, '', 'Accept quest 66269 - Quest 66267 needs to be rewarded');

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 217197, 0, 0, 0, 0, 0, 0, 0, 48069), -- 187463 (Detry Hornswald)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 232404, 0, 0, 0, 0, 0, 0, 0, 48069); -- 198156 (Brackenhide Announcer)

DELETE FROM `gossip_menu` WHERE (`MenuID`=27878 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30053 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(27878, @NPCTEXTID+0, 48069), -- 187463 (Detry Hornswald)
(30053, @NPCTEXTID+1, 48069); -- 198156 (Brackenhide Announcer)

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (187750,198156,198169,188333,198202,198236,65282,76168,187498,189988,198757,95072));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(187750, 0, 0, 0, 2316, 48069),
(198156, 0, 0, 0, 2316, 48069),
(198169, 0, 0, 0, 2316, 48069),
(188333, 0, 0, 0, 2316, 48069),
(198202, 0, 0, 0, 2316, 48069),
(198236, 0, 0, 0, 482, 48069),
(65282, 0, 0, 0, 482, 48069),
(76168, 0, 0, 0, 482, 48069),
(187498, 0, 0, 0, 2316, 48069),
(189988, 0, 0, 0, 482, 48069),
(198757, 0, 0, 0, 482, 48069),
(95072, 0, 0, 0, 482, 48069);

DELETE FROM `creature_model_info` WHERE `DisplayID`=111268;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(111268, 1, 1, 0, 48069);

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (187930, 187551, 187552, 187743, 187931, 187553);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (187553, -(@CGUID+196), -(@CGUID+195), -(@CGUID+145), -(@CGUID+122), -(@CGUID+205), -(@CGUID+153), -(@CGUID+137), -(@CGUID+152), -(@CGUID+154));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(187553, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364022, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth Spikes - to self'),
(-(@CGUID+196), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth - to self'),
(-(@CGUID+195), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 370774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Wind - to self'),
(-(@CGUID+145), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364116, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Storm - to self'),
(-(@CGUID+205), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth - to self'),
(-(@CGUID+137), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth - to self'),
(-(@CGUID+152), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth - to self'),
(-(@CGUID+154), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 364119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth - to self'),
(-(@CGUID+153), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 391041, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) Channel Earth Orb - to self'),
(-(@CGUID+122), 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 384076, 0, 0, 0, 0, 0, 10, (@CGUID+155), 187549, 0, 0, 0, 0, 0, 'OOC - Cast (no repeat) (Whirlwind) - to Stormfang Grunt');

-- Waypoints for CGUID+22
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+22;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+22, @CGUID+22, 0, 0, 515, 0, 0),
(@CGUID+22, @CGUID+16, 5, 40, 515, 2, 7),
(@CGUID+22, @CGUID+12, 5, 320, 515, 2, 7);

SET @PATH := (@CGUID+22) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3891.345, 3178.981, 173.1157, NULL, 0),
(@PATH, 1, -3899.653, 3182.272, 173.4907, NULL, 0),
(@PATH, 2, -3907.769, 3184.215, 173.3632, NULL, 3940),
(@PATH, 3, -3899.653, 3182.272, 173.4907, NULL, 0),
(@PATH, 4, -3891.345, 3178.981, 173.1157, NULL, 0),
(@PATH, 5, -3882.29, 3177.345, 172.2092, NULL, 0),
(@PATH, 6, -3874.28, 3180.207, 170.6544, NULL, 0),
(@PATH, 7, -3866.842, 3182.981, 169.4291, NULL, 3823),
(@PATH, 8, -3874.28, 3180.207, 170.6544, NULL, 0),
(@PATH, 9, -3882.29, 3177.345, 172.2092, NULL, 0);

UPDATE `creature` SET `position_x`= -3891.345, `position_y`= 3178.981, `position_z`= 173.1157, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+22;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+22, @PATH, 1);

-- Waypoints for CGUID+13
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+13;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+13, @CGUID+13, 0, 0, 515, 0, 0),
(@CGUID+13, @CGUID+15, 3, 30, 515, 5, 11),
(@CGUID+13, @CGUID+0, 6, 0, 515, 5, 11);

SET @PATH := (@CGUID+13) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3927.83, 3203.281, 170.8779, NULL, 0),
(@PATH, 1, -3921.948, 3196.08, 172.2049, NULL, 0),
(@PATH, 2, -3930.661, 3196.679, 171.8603, NULL, 0),
(@PATH, 3, -3941.752, 3194.579, 172.172, NULL, 0),
(@PATH, 4, -3948.585, 3197.141, 172.334, NULL, 0),
(@PATH, 5, -3953.158, 3197.98, 172.334, NULL, 3003),
(@PATH, 6, -3948.585, 3197.141, 172.334, NULL, 0),
(@PATH, 7, -3941.752, 3194.579, 172.172, NULL, 0),
(@PATH, 8, -3930.661, 3196.679, 171.8603, NULL, 0),
(@PATH, 9, -3921.948, 3196.08, 172.2049, NULL, 0),
(@PATH, 10, -3927.83, 3203.281, 170.8779, NULL, 0),
(@PATH, 11, -3923.203, 3224.498, 163.4521, NULL, 3315);

UPDATE `creature` SET `position_x`= -3927.83, `position_y`= 3203.281, `position_z`= 170.8779, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+13, @PATH, 1);

-- Waypoints for CGUID+29
SET @PATH := (@CGUID+29) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3951.095, 3200.635, 172.3771, NULL, 0),
(@PATH, 1, -3954.311, 3198.407, 172.334, NULL, 0),
(@PATH, 2, -3960.762, 3195.833, 172.334, NULL, 1851),
(@PATH, 3, -3957.736, 3200.728, 172.4018, NULL, 0),
(@PATH, 4, -3957.981, 3203.68, 172.7561, NULL, 0),
(@PATH, 5, -3960.106, 3204.347, 172.8138, NULL, 1606),
(@PATH, 6, -3959.144, 3199.677, 172.334, NULL, 0),
(@PATH, 7, -3961.573, 3198.893, 172.334, NULL, 0),
(@PATH, 8, -3963.332, 3199.744, 172.334, NULL, 1825),
(@PATH, 9, -3956.425, 3199.458, 172.334, NULL, 0),
(@PATH, 10, -3953.845, 3200.293, 172.3771, NULL, 0),
(@PATH, 11, -3951.375, 3201.878, 172.3771, NULL, 0),
(@PATH, 12, -3949.575, 3203.827, 172.3771, NULL, 0),
(@PATH, 13, -3949.066, 3205.906, 172.3771, NULL, 2697);

UPDATE `creature` SET `position_x`= -3951.095, `position_y`= 3200.635, `position_z`= 172.3771, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+29;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+29;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+29, @PATH, 1);

-- Waypoints for CGUID+534
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+534;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+534, @CGUID+534, 0, 0, 515, 1, 6),
(@CGUID+534, @CGUID+533, 4, 180, 515, 1, 6),
(@CGUID+534, @CGUID+532, 4, 270, 515, 1, 6),
(@CGUID+534, @CGUID+530, 4, 90, 515, 1, 6),
(@CGUID+534, @CGUID+529, 4, 0, 515, 1, 6);

SET @PATH := (@CGUID+534) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3848.014, 3066.379, 186.4418, NULL, 4121),
(@PATH, 1, -3840.188, 3058.999, 188.4832, NULL, 0),
(@PATH, 2, -3833.339, 3051.325, 189.8958, NULL, 0),
(@PATH, 3, -3825.345, 3043.317, 191.7555, NULL, 0),
(@PATH, 4, -3825.995, 3032.851, 192.0506, NULL, 0),
(@PATH, 5, -3832.141, 3025.578, 190.0083, NULL, 0),
(@PATH, 6, -3836.505, 3021.882, 188.9858, NULL, 3093),
(@PATH, 7, -3832.141, 3025.578, 190.0083, NULL, 0),
(@PATH, 8, -3825.995, 3032.851, 192.0506, NULL, 0),
(@PATH, 9, -3825.345, 3043.317, 191.7555, NULL, 0),
(@PATH, 10, -3833.339, 3051.325, 189.8958, NULL, 0),
(@PATH, 11, -3840.188, 3058.999, 188.4832, NULL, 0);

UPDATE `creature` SET `position_x`= -3848.014, `position_y`= 3066.379, `position_z`= 186.4418, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+534;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+534;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+534, @PATH, 1);

-- Waypoints for CGUID+68
SET @PATH := (@CGUID+68) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3844.25, 3082.152, 186.9489, NULL, 0),
(@PATH, 1, -3846.778, 3074.008, 185.6482, NULL, 0),
(@PATH, 2, -3850.976, 3071.123, 185.172, NULL, 0),
(@PATH, 3, -3855.342, 3073.985, 184.1009, NULL, 0),
(@PATH, 4, -3863.538, 3079.26, 181.6257, NULL, 0),
(@PATH, 5, -3869.905, 3083.602, 179.8241, NULL, 0),
(@PATH, 6, -3873.134, 3086.402, 179.0614, NULL, 3918),
(@PATH, 7, -3863.538, 3079.26, 181.6257, NULL, 0),
(@PATH, 8, -3855.342, 3073.985, 184.1009, NULL, 0),
(@PATH, 9, -3850.976, 3071.123, 185.172, NULL, 0),
(@PATH, 10, -3846.778, 3074.008, 185.6482, NULL, 0),
(@PATH, 11, -3844.25, 3082.152, 186.9489, NULL, 0),
(@PATH, 12, -3842.328, 3091.78, 188.4489, NULL, 3834);

UPDATE `creature` SET `position_x`= -3844.25, `position_y`= 3082.152, `position_z`= 186.9489, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+68;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+68;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+68, @PATH, 1, '371863 388589');

-- Waypoints for CGUID+556
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+556;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+556, @CGUID+556, 0, 0, 515, 1, 2),
(@CGUID+556, @CGUID+554, 3, 270, 515, 1, 2);

SET @PATH := (@CGUID+556) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3813.701, 3037.029, 193.1424, NULL, 0),
(@PATH, 1, -3808.358, 3047.629, 195.4961, NULL, 4160),
(@PATH, 2, -3813.701, 3037.029, 193.1424, NULL, 0),
(@PATH, 3, -3821.92, 3029.578, 192.5352, NULL, 4282);

UPDATE `creature` SET `position_x`= -3813.701, `position_y`= 3037.029, `position_z`= 193.1424, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+556;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+556;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+556, @PATH, 1);

-- Waypoints for CGUID+584
SET @PATH := (@CGUID+584) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3808.293, 3092.149, 191.8008, NULL, 2392),
(@PATH, 1, -3814.486, 3096.49, 190.3937, NULL, 0),
(@PATH, 2, -3815.604, 3099.002, 190.9922, NULL, 3171),
(@PATH, 3, -3820.378, 3093.047, 189.2507, NULL, 0),
(@PATH, 4, -3825.606, 3092.359, 188.7186, NULL, 0),
(@PATH, 5, -3830.55, 3091.075, 188.4789, NULL, 0),
(@PATH, 6, -3831.868, 3093.357, 188.4789, NULL, 2259),
(@PATH, 7, -3827.519, 3091.808, 188.6039, NULL, 0),
(@PATH, 8, -3821.536, 3092.575, 189.2854, NULL, 0),
(@PATH, 9, -3817.804, 3094.002, 189.3727, NULL, 0),
(@PATH, 10, -3814.207, 3096.35, 190.4437, NULL, 0),
(@PATH, 11, -3810.576, 3096.126, 191.0765, NULL, 0);

UPDATE `creature` SET `position_x`= -3808.293, `position_y`= 3092.149, `position_z`= 191.8008, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+584;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+584;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+584, @PATH, 1);

-- Waypoints for CGUID+578
SET @PATH := (@CGUID+578) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3816.269, 3082.664, 190.1068, NULL, 0),
(@PATH, 1, -3814.545, 3079.208, 190.7286, NULL, 0),
(@PATH, 2, -3813.769, 3075.684, 191.5648, NULL, 0),
(@PATH, 3, -3810.176, 3073.93, 192.1039, NULL, 2888),
(@PATH, 4, -3815.387, 3081.69, 190.3296, NULL, 0),
(@PATH, 5, -3817.905, 3086.73, 189.7025, NULL, 0),
(@PATH, 6, -3819.089, 3089.642, 189.3539, NULL, 0),
(@PATH, 7, -3818.705, 3091.878, 189.2289, NULL, 0),
(@PATH, 8, -3815.731, 3093.95, 189.79, NULL, 0),
(@PATH, 9, -3813.297, 3094.872, 190.649, NULL, 0),
(@PATH, 10, -3811.054, 3093.487, 191.3229, NULL, 0),
(@PATH, 11, -3810.476, 3090.744, 191.8253, NULL, 2553),
(@PATH, 12, -3814.774, 3094.609, 190.1382, NULL, 0),
(@PATH, 13, -3817.458, 3092.777, 189.267, NULL, 0),
(@PATH, 14, -3819.429, 3090.057, 189.3539, NULL, 0),
(@PATH, 15, -3817.859, 3086.378, 189.8539, NULL, 0),
(@PATH, 16, -3814.84, 3081.52, 190.384, NULL, 0),
(@PATH, 17, -3814.165, 3077.642, 191.2029, NULL, 0),
(@PATH, 18, -3812.512, 3074.468, 191.7928, NULL, 0),
(@PATH, 19, -3810.533, 3073.941, 191.967, NULL, 2520),
(@PATH, 20, -3815.283, 3081.501, 190.3647, NULL, 0),
(@PATH, 21, -3817.368, 3083.824, 190.0077, NULL, 0),
(@PATH, 22, -3821.019, 3082.236, 190.8561, NULL, 3137);

UPDATE `creature` SET `position_x`= -3816.269, `position_y`= 3082.664, `position_z`= 190.1068, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+578;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+578;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+578, @PATH, 1);

-- Waypoints for CGUID+549
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+549;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+549, @CGUID+549, 0, 0, 515, 0, 0),
(@CGUID+549, @CGUID+552, 4, 300, 515, 5, 11),
(@CGUID+549, @CGUID+548, 4, 60, 515, 5, 11);

SET @PATH := (@CGUID+549) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3768.745, 3001.543, 190.6876, NULL, 0),
(@PATH, 1, -3773.892, 3008.13, 190.6184, NULL, 0),
(@PATH, 2, -3782.175, 3009.609, 191.6514, NULL, 0),
(@PATH, 3, -3787.795, 3013.529, 192.9473, NULL, 0),
(@PATH, 4, -3791.201, 3021.409, 195.5011, NULL, 0),
(@PATH, 5, -3800.222, 3028.372, 196.5267, NULL, 3749),
(@PATH, 6, -3791.201, 3021.409, 195.5011, NULL, 0),
(@PATH, 7, -3787.795, 3013.529, 192.9473, NULL, 0),
(@PATH, 8, -3782.175, 3009.609, 191.6514, NULL, 0),
(@PATH, 9, -3773.892, 3008.13, 190.6184, NULL, 0),
(@PATH, 10, -3768.745, 3001.543, 190.6876, NULL, 0),
(@PATH, 11, -3761.913, 3004.019, 190.4312, NULL, 4880);

UPDATE `creature` SET `position_x`= -3768.745, `position_y`= 3001.543, `position_z`= 190.6876, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+549;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+549;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+549, @PATH, 1);

-- Waypoints for CGUID+477
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+477;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+477, @CGUID+477, 0, 0, 515, 0, 0),
(@CGUID+477, @CGUID+475, 4, 300, 515, 1, 8),
(@CGUID+477, @CGUID+468, 4, 60, 515, 1, 8);

SET @PATH := (@CGUID+477) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3840.529, 2956.938, 181.9451, NULL, 4136),
(@PATH, 1, -3849.67, 2964.708, 181.1951, NULL, 0),
(@PATH, 2, -3855.932, 2972.872, 180.3434, NULL, 0),
(@PATH, 3, -3853.92, 2980.199, 180.2998, NULL, 0),
(@PATH, 4, -3850.703, 2985.12, 180.2998, NULL, 0),
(@PATH, 5, -3852.297, 2991.384, 180.3367, NULL, 0),
(@PATH, 6, -3851.217, 2998.302, 181.7998, NULL, 0),
(@PATH, 7, -3846.181, 3008.184, 184.2118, NULL, 0),
(@PATH, 8, -3841.392, 3017.596, 187.1931, NULL, 3843),
(@PATH, 9, -3846.181, 3008.184, 184.2118, NULL, 0),
(@PATH, 10, -3851.207, 2998.406, 181.8349, NULL, 0),
(@PATH, 11, -3852.297, 2991.384, 180.3367, NULL, 0),
(@PATH, 12, -3850.703, 2985.12, 180.2998, NULL, 0),
(@PATH, 13, -3853.92, 2980.199, 180.2998, NULL, 0),
(@PATH, 14, -3855.932, 2972.872, 180.3434, NULL, 0),
(@PATH, 15, -3849.67, 2964.708, 181.1951, NULL, 0);

UPDATE `creature` SET `position_x`= -3840.529, `position_y`= 2956.938, `position_z`= 181.9451, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+477;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+477;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+477, @PATH, 1, '371863 388589');

-- Waypoints for CGUID+472
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+472;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+472, @CGUID+472, 0, 0, 515, 2, 3),
(@CGUID+472, @CGUID+476, 3, 90, 515, 2, 3);

SET @PATH := (@CGUID+472) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3820.422, 2938.388, 183.7025, NULL, 3247),
(@PATH, 1, -3826.781, 2949.335, 183.023, NULL, 0),
(@PATH, 2, -3832.375, 2960.292, 184.0506, NULL, 3349),
(@PATH, 3, -3826.781, 2949.335, 183.023, NULL, 0);

UPDATE `creature` SET `position_x`= -3820.422, `position_y`= 2938.388, `position_z`= 183.7025, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+472;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+472;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+472, @PATH, 1);

-- Waypoints for CGUID+491
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+491;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+491, @CGUID+491, 0, 0, 515, 0, 0),
(@CGUID+491, @CGUID+490, 2, 300, 515, 1, 5),
(@CGUID+491, @CGUID+497, 2, 60, 515, 1, 5);

SET @PATH := (@CGUID+491) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3800.859, 2963.068, 185.0191, NULL, 0),
(@PATH, 1, -3810.244, 2958.023, 185.4191, NULL, 3681),
(@PATH, 2, -3800.859, 2963.068, 185.0191, NULL, 0),
(@PATH, 3, -3795.464, 2966.649, 183.5018, NULL, 0),
(@PATH, 4, -3789.695, 2971.176, 182.3787, NULL, 0),
(@PATH, 5, -3784.365, 2972.381, 181.9197, NULL, 4968),
(@PATH, 6, -3789.695, 2971.176, 182.3787, NULL, 0),
(@PATH, 7, -3795.46, 2966.652, 183.5755, NULL, 0);

UPDATE `creature` SET `position_x`= -3800.859, `position_y`= 2963.068, `position_z`= 185.0191, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+491;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+491;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+491, @PATH, 1);

-- Waypoints for CGUID+465
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+465;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+465, @CGUID+465, 0, 0, 515, 0, 0),
(@CGUID+465, @CGUID+466, 3, 0, 515, 0, 0),
(@CGUID+465, @CGUID+464, 3, 180, 515, 0, 0);

SET @PATH := (@CGUID+465) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3834.354, 2935.248, 183.8153, NULL, 4038),
(@PATH, 1, -3842.601, 2929.923, 185.3199, NULL, 0),
(@PATH, 2, -3849.057, 2920, 187.535, NULL, 0),
(@PATH, 3, -3854.201, 2911.924, 188.99, NULL, 0),
(@PATH, 4, -3861.167, 2902.738, 190.2007, NULL, 0),
(@PATH, 5, -3866.182, 2896.869, 190.3533, NULL, 0),
(@PATH, 6, -3871.144, 2889.781, 190.5911, NULL, 2817),
(@PATH, 7, -3866.182, 2896.869, 190.3533, NULL, 0),
(@PATH, 8, -3861.167, 2902.738, 190.2007, NULL, 0),
(@PATH, 9, -3854.201, 2911.924, 188.99, NULL, 0),
(@PATH, 10, -3849.057, 2920, 187.535, NULL, 0),
(@PATH, 11, -3842.601, 2929.923, 185.3199, NULL, 0);

UPDATE `creature` SET `position_x`= -3834.354, `position_y`= 2935.248, `position_z`= 183.8153, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+465;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+465;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+465, @PATH, 1);

-- Waypoints for CGUID+448
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+448;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+448, @CGUID+448, 0, 0, 515, 0, 0),
(@CGUID+448, @CGUID+455, 3, 90, 515, 2, 9);

SET @PATH := (@CGUID+448) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3803.203, 2852.433, 202.382, NULL, 0),
(@PATH, 1, -3803.056, 2857.826, 201.2057, NULL, 0),
(@PATH, 2, -3801.049, 2860.739, 201.2836, NULL, 2107),
(@PATH, 3, -3803.51, 2852.246, 202.3574, NULL, 0),
(@PATH, 4, -3801.54, 2847.865, 204.187, NULL, 0),
(@PATH, 5, -3799.667, 2842.522, 205.7009, NULL, 0),
(@PATH, 6, -3796.738, 2839.797, 206.077, NULL, 0),
(@PATH, 7, -3794.887, 2841.589, 206.0492, NULL, 0),
(@PATH, 8, -3794.823, 2844.392, 205.7788, NULL, 0),
(@PATH, 9, -3797.326, 2845.41, 205.6036, NULL, 7453);

UPDATE `creature` SET `position_x`= -3803.203, `position_y`= 2852.433, `position_z`= 202.382, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+448;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+448;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+448, @PATH, 1, '371863 388589');

-- Waypoints for CGUID+434
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+434;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+434, @CGUID+434, 0, 0, 515, 7, 15),
(@CGUID+434, @CGUID+440, 4, 180, 515, 7, 15),
(@CGUID+434, @CGUID+446, 4, 270, 515, 7, 15),
(@CGUID+434, @CGUID+437, 4, 90, 515, 7, 15),
(@CGUID+434, @CGUID+444, 4, 0, 515, 7, 15);

SET @PATH := (@CGUID+434) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3835.745, 2845.719, 201.9769, NULL, 0),
(@PATH, 1, -3836.353, 2855.814, 200.7988, NULL, 0),
(@PATH, 2, -3835.62, 2862.191, 200.2245, NULL, 0),
(@PATH, 3, -3838.398, 2865.831, 199.3707, NULL, 0),
(@PATH, 4, -3844.247, 2865.887, 197.7137, NULL, 0),
(@PATH, 5, -3849.472, 2867.722, 196.1663, NULL, 0),
(@PATH, 6, -3859.984, 2871.713, 192.7888, NULL, 0),
(@PATH, 7, -3865.375, 2874.344, 191.2283, NULL, 3881),
(@PATH, 8, -3859.984, 2871.713, 192.7888, NULL, 0),
(@PATH, 9, -3849.472, 2867.722, 196.1663, NULL, 0),
(@PATH, 10, -3844.247, 2865.887, 197.7137, NULL, 0),
(@PATH, 11, -3838.398, 2865.831, 199.3707, NULL, 0),
(@PATH, 12, -3835.62, 2862.191, 200.2245, NULL, 0),
(@PATH, 13, -3836.353, 2855.814, 200.7988, NULL, 0),
(@PATH, 14, -3835.745, 2845.719, 201.9769, NULL, 0),
(@PATH, 15, -3839.415, 2834.776, 203.3131, NULL, 3814);

UPDATE `creature` SET `position_x`= -3835.745, `position_y`= 2845.719, `position_z`= 201.9769, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+434;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+434;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+434, @PATH, 1);

-- Waypoints for CGUID+460
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+460;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+460, @CGUID+460, 0, 0, 515, 0, 0),
(@CGUID+460, @CGUID+459, 3, 300, 515, 4, 11),
(@CGUID+460, @CGUID+462, 3, 60, 515, 4, 11);

SET @PATH := (@CGUID+460) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3804.441, 2892.848, 200.3803, NULL, 0),
(@PATH, 1, -3802.931, 2885.925, 200.5845, NULL, 0),
(@PATH, 2, -3803.995, 2876.907, 200.5845, NULL, 0),
(@PATH, 3, -3808.606, 2870.344, 200.5547, NULL, 0),
(@PATH, 4, -3816.172, 2866.26, 200.7616, NULL, 3495),
(@PATH, 5, -3808.606, 2870.344, 200.5547, NULL, 0),
(@PATH, 6, -3803.995, 2876.907, 200.5845, NULL, 0),
(@PATH, 7, -3802.931, 2885.925, 200.5845, NULL, 0),
(@PATH, 8, -3804.441, 2892.848, 200.3803, NULL, 0),
(@PATH, 9, -3806.723, 2900.52, 199.1446, NULL, 0),
(@PATH, 10, -3810.198, 2910.945, 195.0157, NULL, 0),
(@PATH, 11, -3816.655, 2927.563, 187.481, NULL, 3906),
(@PATH, 12, -3810.198, 2910.945, 195.0157, NULL, 0),
(@PATH, 13, -3806.72, 2900.528, 199.1492, NULL, 0);

UPDATE `creature` SET `position_x`= -3804.441, `position_y`= 2892.848, `position_z`= 200.3803, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+460;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+460;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+460, @PATH, 1, '371863 388589');

-- Waypoints for CGUID+483
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+483;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+483, @CGUID+483, 0, 0, 515, 0, 0),
(@CGUID+483, @CGUID+485, 3, 60, 515, 2, 5);

SET @PATH := (@CGUID+483) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3786.674, 2816.464, 204.9513, NULL, 0),
(@PATH, 1, -3787.285, 2829.338, 205.3578, NULL, 0),
(@PATH, 2, -3797.476, 2832.431, 206.216, NULL, 4175),
(@PATH, 3, -3787.285, 2829.338, 205.3578, NULL, 0),
(@PATH, 4, -3786.674, 2816.464, 204.9513, NULL, 0),
(@PATH, 5, -3777.582, 2809.925, 204.8842, NULL, 4177);

UPDATE `creature` SET `position_x`= -3786.674, `position_y`= 2816.464, `position_z`= 204.9513, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+483;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+483;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+483, @PATH, 1);

-- Waypoints for CGUID+406
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+406;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+406, @CGUID+406, 0, 0, 515, 0, 0),
(@CGUID+406, @CGUID+408, 4, 180, 515, 9, 19),
(@CGUID+406, @CGUID+402, 3, 270, 515, 9, 19),
(@CGUID+406, @CGUID+407, 3, 90, 515, 9, 19),
(@CGUID+406, @CGUID+405, 4, 30, 515, 9, 19),
(@CGUID+406, @CGUID+409, 4, 330, 515, 9, 19);

SET @PATH := (@CGUID+406) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3895.793, 2758.193, 215.3992, NULL, 0),
(@PATH, 1, -3893.976, 2769.543, 211.5481, NULL, 0),
(@PATH, 2, -3890.257, 2781.077, 207.7461, NULL, 0),
(@PATH, 3, -3887.089, 2789.767, 204.8029, NULL, 0),
(@PATH, 4, -3888.972, 2797.862, 202.7614, NULL, 0),
(@PATH, 5, -3894.439, 2805.908, 201.2833, NULL, 0),
(@PATH, 6, -3906.913, 2811.764, 199.8783, NULL, 0),
(@PATH, 7, -3919.528, 2809.431, 199.6195, NULL, 0),
(@PATH, 8, -3934.191, 2809.165, 200.1057, NULL, 0),
(@PATH, 9, -3949.047, 2806.01, 199.4335, NULL, 3427),
(@PATH, 10, -3934.191, 2809.165, 200.1057, NULL, 0),
(@PATH, 11, -3919.528, 2809.431, 199.6195, NULL, 0),
(@PATH, 12, -3906.913, 2811.764, 199.8783, NULL, 0),
(@PATH, 13, -3894.439, 2805.908, 201.2833, NULL, 0),
(@PATH, 14, -3888.972, 2797.862, 202.7614, NULL, 0),
(@PATH, 15, -3887.089, 2789.767, 204.8029, NULL, 0),
(@PATH, 16, -3890.257, 2781.077, 207.7461, NULL, 0),
(@PATH, 17, -3893.976, 2769.543, 211.5481, NULL, 0),
(@PATH, 18, -3895.793, 2758.193, 215.3992, NULL, 0),
(@PATH, 19, -3895.106, 2747.412, 220.0303, NULL, 3311);

UPDATE `creature` SET `position_x`= -3895.793, `position_y`= 2758.193, `position_z`= 215.3992, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+406;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+406;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+406, @PATH, 1);

-- Waypoints for CGUID+345
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+345;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+345, @CGUID+345, 0, 0, 515, 0, 0),
(@CGUID+345, @CGUID+371, 4, 60, 515, 4, 14);

SET @PATH := (@CGUID+345) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3974.395, 2796.174, 199.4692, NULL, 0),
(@PATH, 1, -3973.512, 2787.522, 199.9692, NULL, 0),
(@PATH, 2, -3962.344, 2782.229, 202.3967, NULL, 0),
(@PATH, 3, -3953.519, 2775.918, 206.5293, NULL, 0),
(@PATH, 4, -3958.25, 2762.738, 208.6727, NULL, 3793),
(@PATH, 5, -3953.52, 2775.918, 206.5942, NULL, 0),
(@PATH, 6, -3962.344, 2782.229, 202.3967, NULL, 0),
(@PATH, 7, -3973.512, 2787.522, 199.9692, NULL, 0),
(@PATH, 8, -3974.42, 2796.096, 199.531, NULL, 0),
(@PATH, 9, -3971.635, 2804.743, 198.3398, NULL, 0),
(@PATH, 10, -3978.438, 2812.058, 197.5965, NULL, 0),
(@PATH, 11, -3988.844, 2818.012, 195.5965, NULL, 0),
(@PATH, 12, -3998.726, 2820.845, 192.9979, NULL, 0),
(@PATH, 13, -4012.875, 2820.194, 189.0801, NULL, 0),
(@PATH, 14, -4027.875, 2820.457, 186.138, NULL, 4206),
(@PATH, 15, -4012.875, 2820.193, 189.138, NULL, 0),
(@PATH, 16, -3998.726, 2820.845, 192.9979, NULL, 0),
(@PATH, 17, -3989.098, 2818.121, 195.5965, NULL, 0),
(@PATH, 18, -3978.438, 2812.058, 197.5965, NULL, 0),
(@PATH, 19, -3971.635, 2804.743, 198.3398, NULL, 0);

UPDATE `creature` SET `position_x`= -3974.395, `position_y`= 2796.174, `position_z`= 199.4692, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+345;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+345;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+345, @PATH, 1);

-- Waypoints for CGUID+351
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+351;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+351, @CGUID+351, 0, 0, 515, 0, 0),
(@CGUID+351, @CGUID+242, 4, 60, 515, 3, 8);

SET @PATH := (@CGUID+351) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3950.776, 2890.793, 182.9683, NULL, 0),
(@PATH, 1, -3966.908, 2891.845, 180.7094, NULL, 0),
(@PATH, 2, -3988.583, 2891.783, 180.426, NULL, 0),
(@PATH, 3, -3999.599, 2895.324, 180.1616, NULL, 4450),
(@PATH, 4, -3988.583, 2891.783, 180.426, NULL, 0),
(@PATH, 5, -3966.908, 2891.845, 180.7094, NULL, 0),
(@PATH, 6, -3950.776, 2890.793, 182.9683, NULL, 0),
(@PATH, 7, -3940.72, 2885.813, 184.176, NULL, 0),
(@PATH, 8, -3922.658, 2872.21, 185.5883, NULL, 4277),
(@PATH, 9, -3940.72, 2885.813, 184.176, NULL, 0);

UPDATE `creature` SET `position_x`= -3950.776, `position_y`= 2890.793, `position_z`= 182.9683, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+351;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+351;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+351, @PATH, 1);

-- Waypoints for CGUID+230
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+230;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+230, @CGUID+230, 0, 0, 515, 0, 0),
(@CGUID+230, @CGUID+271, 4, 0, 515, 0, 0),
(@CGUID+230, @CGUID+272, 7, 0, 515, 0, 0);

SET @PATH := (@CGUID+230) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4048.932, 2864.2, 182.8318, NULL, 0),
(@PATH, 1, -4057.089, 2874.547, 183.1104, NULL, 0),
(@PATH, 2, -4063.479, 2890.505, 183.7916, NULL, 0),
(@PATH, 3, -4069.269, 2893.798, 184.3058, NULL, 0),
(@PATH, 4, -4074.811, 2905.045, 185.403, NULL, 0),
(@PATH, 5, -4079.878, 2923.121, 188.3222, NULL, 4097),
(@PATH, 6, -4074.811, 2905.045, 185.403, NULL, 0),
(@PATH, 7, -4069.269, 2893.798, 184.3058, NULL, 0),
(@PATH, 8, -4063.479, 2890.505, 183.7916, NULL, 0),
(@PATH, 9, -4057.089, 2874.547, 183.1104, NULL, 0),
(@PATH, 10, -4048.932, 2864.2, 182.8318, NULL, 0),
(@PATH, 11, -4038.264, 2849.12, 181.9391, NULL, 5200);

UPDATE `creature` SET `position_x`= -4048.932, `position_y`= 2864.2, `position_z`= 182.8318, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+230;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+230;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+230, @PATH, 1);

-- Waypoints for CGUID+240
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+240;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+240, @CGUID+240, 0, 0, 515, 0, 0),
(@CGUID+240, @CGUID+253, 4, 180, 515, 1, 6),
(@CGUID+240, @CGUID+243, 3, 270, 515, 1, 6),
(@CGUID+240, @CGUID+256, 3, 90, 515, 1, 6),
(@CGUID+240, @CGUID+241, 4, 30, 515, 1, 6),
(@CGUID+240, @CGUID+257, 4, 330, 515, 1, 6);

SET @PATH := (@CGUID+240) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4005.42, 2934.438, 180.2301, NULL, 4579),
(@PATH, 1, -4005.731, 2923.931, 180.243, NULL, 0),
(@PATH, 2, -4012.642, 2908.649, 179.6976, NULL, 0),
(@PATH, 3, -4010.297, 2897.622, 179.9467, NULL, 0),
(@PATH, 4, -4013.205, 2888.885, 179.6967, NULL, 0),
(@PATH, 5, -4015.005, 2878.014, 179.8217, NULL, 0),
(@PATH, 6, -4023.783, 2866.229, 180.3156, NULL, 3384),
(@PATH, 7, -4015.005, 2878.014, 179.8217, NULL, 0),
(@PATH, 8, -4013.205, 2888.885, 179.6967, NULL, 0),
(@PATH, 9, -4010.297, 2897.622, 179.9467, NULL, 0),
(@PATH, 10, -4012.642, 2908.649, 179.6976, NULL, 0),
(@PATH, 11, -4005.731, 2923.931, 180.243, NULL, 0);

UPDATE `creature` SET `position_x`= -4005.42, `position_y`= 2934.438, `position_z`= 180.2301, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+240;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+240;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+240, @PATH, 1);

-- Waypoints for CGUID+197
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+197;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+197, @CGUID+197, 0, 0, 515, 0, 0),
(@CGUID+197, @CGUID+148, 4, 90, 515, 5, 11),
(@CGUID+197, @CGUID+191, 3, 30, 515, 5, 11),
(@CGUID+197, @CGUID+188, 3, 330, 515, 5, 11);

SET @PATH := (@CGUID+197) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4087.814, 2946.688, 192.9482, NULL, 0),
(@PATH, 1, -4071.536, 2945.574, 191.6982, NULL, 0),
(@PATH, 2, -4068.896, 2948.642, 191.8232, NULL, 0),
(@PATH, 3, -4067.462, 2959.72, 192.6061, NULL, 0),
(@PATH, 4, -4064.276, 2965.213, 192.6592, NULL, 0),
(@PATH, 5, -4060.786, 2975.039, 192.8353, NULL, 3338),
(@PATH, 6, -4064.276, 2965.213, 192.6592, NULL, 0),
(@PATH, 7, -4067.462, 2959.72, 192.6061, NULL, 0),
(@PATH, 8, -4068.881, 2948.807, 191.8232, NULL, 0),
(@PATH, 9, -4071.536, 2945.574, 191.6982, NULL, 0),
(@PATH, 10, -4087.814, 2946.688, 192.9482, NULL, 0),
(@PATH, 11, -4099.179, 2940.394, 193.0732, NULL, 4708);

UPDATE `creature` SET `position_x`= -4087.814, `position_y`= 2946.688, `position_z`= 192.9482, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+197;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+197;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+197, @PATH, 1);

-- Waypoints for CGUID+165
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+165;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+165, @CGUID+165, 0, 0, 515, 0, 0),
(@CGUID+165, @CGUID+177, 3, 180, 515, 2, 10),
(@CGUID+165, @CGUID+163, 3, 30, 515, 2, 10),
(@CGUID+165, @CGUID+161, 3, 330, 515, 2, 10);

SET @PATH := (@CGUID+165) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4068.191, 2993.331, 192.8352, NULL, 0),
(@PATH, 1, -4067.083, 3002.876, 191.7352, NULL, 0),
(@PATH, 2, -4069.219, 3011.783, 190.785, NULL, 3808),
(@PATH, 3, -4067.127, 3003.029, 191.7678, NULL, 0),
(@PATH, 4, -4068.191, 2993.331, 192.8352, NULL, 0),
(@PATH, 5, -4063.938, 2983.956, 193.1034, NULL, 0),
(@PATH, 6, -4055.974, 2977.662, 192.2579, NULL, 0),
(@PATH, 7, -4048.186, 2978.987, 189.9178, NULL, 0),
(@PATH, 8, -4040.939, 2978.034, 186.956, NULL, 0),
(@PATH, 9, -4031.748, 2976.527, 183.7792, NULL, 0),
(@PATH, 10, -4023.363, 2973.267, 181.1664, NULL, 5117),
(@PATH, 11, -4031.748, 2976.527, 183.7792, NULL, 0),
(@PATH, 12, -4040.939, 2978.034, 186.956, NULL, 0),
(@PATH, 13, -4048.186, 2978.987, 189.9178, NULL, 0),
(@PATH, 14, -4055.974, 2977.662, 192.2579, NULL, 0),
(@PATH, 15, -4063.938, 2983.956, 193.1034, NULL, 0);

UPDATE `creature` SET `position_x`= -4068.191, `position_y`= 2993.331, `position_z`= 192.8352, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+165;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+165;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+165, @PATH, 1);

-- Waypoints for CGUID+100
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+100;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+100, @CGUID+100, 0, 0, 515, 0, 0),
(@CGUID+100, @CGUID+97, 4, 60, 515, 1, 7);

SET @PATH := (@CGUID+100) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4014.882, 3021.97, 178.949, NULL, 0),
(@PATH, 1, -4021.321, 3016.977, 179.0511, NULL, 4445),
(@PATH, 2, -4014.882, 3021.97, 178.949, NULL, 0),
(@PATH, 3, -4012.899, 3029.195, 180.4985, NULL, 0),
(@PATH, 4, -4016.304, 3036.617, 182.0878, NULL, 0),
(@PATH, 5, -4028.066, 3047.656, 185.0305, NULL, 0),
(@PATH, 6, -4037.932, 3050.578, 186.4547, NULL, 0),
(@PATH, 7, -4055.717, 3043.124, 188.089, NULL, 3332),
(@PATH, 8, -4037.932, 3050.578, 186.4547, NULL, 0),
(@PATH, 9, -4028.066, 3047.656, 185.0305, NULL, 0),
(@PATH, 10, -4016.304, 3036.617, 182.0878, NULL, 0),
(@PATH, 11, -4012.899, 3029.195, 180.4985, NULL, 0);

UPDATE `creature` SET `position_x`= -4014.882, `position_y`= 3021.97, `position_z`= 178.949, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+100;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+100;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+100, @PATH, 1);

-- Waypoints for CGUID+74
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+74;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+74, @CGUID+74, 0, 0, 515, 0, 0),
(@CGUID+74, @CGUID+70, 4, 60, 515, 5, 12);

SET @PATH := (@CGUID+74) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4034.486, 3092.01, 186.4098, NULL, 0),
(@PATH, 1, -4033.222, 3086.074, 185.957, NULL, 0),
(@PATH, 2, -4026.63, 3080.732, 184.6499, NULL, 0),
(@PATH, 3, -4014.603, 3070.341, 183.3313, NULL, 0),
(@PATH, 4, -4008.198, 3070.433, 182.548, NULL, 0),
(@PATH, 5, -3998.601, 3082.373, 180.0395, NULL, 3446),
(@PATH, 6, -4006.752, 3072.242, 182.1413, NULL, 0),
(@PATH, 7, -4011.42, 3069.628, 183.0742, NULL, 0),
(@PATH, 8, -4019.505, 3072.612, 184.0163, NULL, 0),
(@PATH, 9, -4027.592, 3081.472, 184.8913, NULL, 0),
(@PATH, 10, -4033.163, 3085.744, 185.9104, NULL, 0),
(@PATH, 11, -4035.313, 3092.786, 186.6952, NULL, 0),
(@PATH, 12, -4046.807, 3104.628, 186.9909, NULL, 3468);

UPDATE `creature` SET `position_x`= -4034.486, `position_y`= 3092.01, `position_z`= 186.4098, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+74;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+74;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+74, @PATH, 1);

-- Waypoints for CGUID+24
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+24;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+24, @CGUID+24, 0, 0, 515, 0, 0),
(@CGUID+24, @CGUID+36, 4, 0, 515, 0, 0),
(@CGUID+24, @CGUID+61, 7, 0, 515, 0, 0);

SET @PATH := (@CGUID+24) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3977.234, 3150.465, 175.0395, NULL, 0),
(@PATH, 1, -3977.323, 3139.216, 175.1829, NULL, 0),
(@PATH, 2, -3981.144, 3127.311, 175.9258, NULL, 3836),
(@PATH, 3, -3977.323, 3139.216, 175.1829, NULL, 0),
(@PATH, 4, -3977.234, 3150.465, 175.0395, NULL, 0),
(@PATH, 5, -3982.705, 3157.009, 175.0395, NULL, 0),
(@PATH, 6, -3977.038, 3162.741, 175.1645, NULL, 0),
(@PATH, 7, -3966.148, 3160.181, 175.0696, NULL, 0),
(@PATH, 8, -3959.722, 3162.47, 175.2287, NULL, 0),
(@PATH, 9, -3954.53, 3173.281, 174.959, NULL, 0),
(@PATH, 10, -3946.844, 3176.658, 174.6272, NULL, 0),
(@PATH, 11, -3944.766, 3190.508, 172.584, NULL, 2518),
(@PATH, 12, -3946.844, 3176.658, 174.709, NULL, 0),
(@PATH, 13, -3954.53, 3173.281, 174.959, NULL, 0),
(@PATH, 14, -3959.722, 3162.47, 175.2287, NULL, 0),
(@PATH, 15, -3966.148, 3160.181, 175.0696, NULL, 0),
(@PATH, 16, -3977.038, 3162.741, 175.1645, NULL, 0),
(@PATH, 17, -3982.705, 3157.009, 175.0395, NULL, 0);

UPDATE `creature` SET `position_x`= -3977.234, `position_y`= 3150.465, `position_z`= 175.0395, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+24;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+24, @PATH, 1);

-- Waypoints for CGUID+219
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+219;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+219, @CGUID+219, 0, 0, 515, 0, 0),
(@CGUID+219, @CGUID+214, 8, 30, 515, 0, 0),
(@CGUID+219, @CGUID+212, 8, 330, 515, 0, 0);

SET @PATH := (@CGUID+219) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -4140.799, 3032.576, 191.6571, NULL, 0, 1),
(@PATH, 1, -4139.913, 3025.094, 191.7821, NULL, 0, 1),
(@PATH, 2, -4140.813, 3011.64, 191.6978, NULL, 0, 1),
(@PATH, 3, -4141.186, 3001.167, 192.2821, NULL, 0, 1),
(@PATH, 4, -4137.056, 2989.037, 193.4635, NULL, 0, 1),
(@PATH, 5, -4135.431, 2980.621, 194.5792, NULL, 0, 1),
(@PATH, 6, -4139.491, 2970.865, 195.138, NULL, 0, 1),
(@PATH, 7, -4140.516, 2962.615, 195.0744, NULL, 0, 1),
(@PATH, 8, -4142.002, 2947.3, 194.0295, NULL, 0, 1),
(@PATH, 9, -4143.359, 2937.171, 193.7307, NULL, 0, 1),
(@PATH, 10, -4139.403, 2929.699, 192.5159, NULL, 0, 1),
(@PATH, 11, -4133.045, 2926.773, 190.4049, NULL, 0, 1),
(@PATH, 12, -4125.035, 2929.912, 190.7545, NULL, 0, 1),
(@PATH, 13, -4120.802, 2935.071, 193.5633, NULL, 0, 1),
(@PATH, 14, -4119.59, 2943.62, 194.4798, NULL, 0, 1),
(@PATH, 15, -4123.974, 2952.39, 194.6113, NULL, 0, 1),
(@PATH, 16, -4134.963, 2956.308, 195.0825, NULL, 0, 1),
(@PATH, 17, -4139.198, 2967.612, 195.0792, NULL, 0, 1),
(@PATH, 18, -4137.972, 2974.523, 194.9542, NULL, 0, 1),
(@PATH, 19, -4134.986, 2982.447, 194.498, NULL, 0, 1),
(@PATH, 20, -4136.712, 2993.984, 193.2706, NULL, 0, 1),
(@PATH, 21, -4137.693, 3005.286, 192.2103, NULL, 0, 1),
(@PATH, 22, -4135.253, 3012.883, 191.7821, NULL, 0, 1),
(@PATH, 23, -4128.09, 3016.556, 191.8455, NULL, 0, 1),
(@PATH, 24, -4113.713, 3022.258, 191.8947, NULL, 0, 1),
(@PATH, 25, -4106.663, 3031.865, 191.8947, NULL, 0, 1),
(@PATH, 26, -4105.573, 3044.103, 191.7837, NULL, 0, 1),
(@PATH, 27, -4107.682, 3051.322, 191.7837, NULL, 0, 1),
(@PATH, 28, -4111.95, 3061.055, 191.7837, NULL, 0, 1),
(@PATH, 29, -4120.327, 3076.04, 190.9574, NULL, 0, 1),
(@PATH, 30, -4133.512, 3077.222, 189.4847, NULL, 0, 1),
(@PATH, 31, -4141.832, 3064.284, 187.6393, NULL, 0, 1),
(@PATH, 32, -4148.417, 3050.056, 187.9778, NULL, 0, 1),
(@PATH, 33, -4145.393, 3039.131, 190.6485, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -4140.799, `position_y`= 3032.576, `position_z`= 191.6571, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+219;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+219;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+219, @PATH, 1);

-- Waypoints for CGUID+192
SET @PATH := (@CGUID+192) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4098.42, 2990.642, 194.5974, NULL, 0),
(@PATH, 1, -4099.531, 2993.857, 194.7224, NULL, 0),
(@PATH, 2, -4099.467, 2997.083, 194.9709, NULL, 0),
(@PATH, 3, -4098.162, 3000.604, 194.8828, NULL, 0),
(@PATH, 4, -4096.181, 3004.09, 194.7678, NULL, 2968),
(@PATH, 5, -4102.416, 3000.904, 195.3947, NULL, 0),
(@PATH, 6, -4106.203, 3000.682, 196.1335, NULL, 0),
(@PATH, 7, -4109.613, 2999.151, 196.4341, NULL, 0),
(@PATH, 8, -4111.863, 2995.631, 196.1895, NULL, 0),
(@PATH, 9, -4112.106, 2992.921, 196.1895, NULL, 0),
(@PATH, 10, -4113.189, 2990.576, 196.0645, NULL, 0),
(@PATH, 11, -4114.566, 2990.538, 196.1895, NULL, 3027),
(@PATH, 12, -4116.349, 2986.155, 195.8405, NULL, 2615),
(@PATH, 13, -4111.999, 2989.722, 196.0623, NULL, 0),
(@PATH, 14, -4109.658, 2990.94, 195.9355, NULL, 0),
(@PATH, 15, -4105.417, 2989.575, 195.1519, NULL, 0),
(@PATH, 16, -4101.342, 2988.465, 194.5914, NULL, 0),
(@PATH, 17, -4095.948, 2989.265, 194.4967, NULL, 0),
(@PATH, 18, -4093.316, 2990.706, 194.9724, NULL, 2935);

UPDATE `creature` SET `position_x`= -4098.42, `position_y`= 2990.642, `position_z`= 194.5974, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+192;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+192;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+192, @PATH, 1, '392969');

-- Waypoints for CGUID+189
SET @PATH := (@CGUID+189) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4093.97, 2984.292, 194.3474, NULL, 0),
(@PATH, 1, -4098.774, 2984.267, 194.3474, NULL, 0),
(@PATH, 2, -4102.943, 2982.497, 194.5673, NULL, 0),
(@PATH, 3, -4105.338, 2979.379, 194.3556, NULL, 0),
(@PATH, 4, -4109.465, 2978.741, 194.4912, NULL, 0),
(@PATH, 5, -4112.59, 2979.122, 194.3145, NULL, 0),
(@PATH, 6, -4113.703, 2981.907, 194.9395, NULL, 0),
(@PATH, 7, -4112.759, 2985.235, 195.6147, NULL, 0),
(@PATH, 8, -4111.096, 2986.966, 195.9569, NULL, 0),
(@PATH, 9, -4110.416, 2986.559, 195.8265, NULL, 2432),
(@PATH, 10, -4105.979, 2988.036, 195.2495, NULL, 0),
(@PATH, 11, -4101.724, 2987.562, 194.5289, NULL, 0),
(@PATH, 12, -4093.925, 2984.604, 194.3474, NULL, 0),
(@PATH, 13, -4088.887, 2983.373, 194.3474, NULL, 0),
(@PATH, 14, -4079.483, 2982.057, 193.9626, NULL, 2979),
(@PATH, 15, -4093.97, 2984.292, 194.3474, NULL, 0);

UPDATE `creature` SET `position_x`= -4093.97, `position_y`= 2984.292, `position_z`= 194.3474, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+189;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+189;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `auras`) VALUES
(@CGUID+189, @PATH, 1, '392969');
