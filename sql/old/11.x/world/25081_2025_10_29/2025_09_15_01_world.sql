SET @CGUID := 7003590;
SET @OGUID := 7000681;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 121620, 1643, 8721, 8852, '0', 0, 0, 0, 0, -207, 2098.697998046875, 62.33990478515625, 2.501895427703857421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+1, 121620, 1643, 8721, 8852, '0', 0, 0, 0, 0, -247.670135498046875, 2132.802001953125, 63.0606536865234375, 4.588072776794433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+2, 121620, 1643, 8721, 8852, '0', 0, 0, 0, 0, -255.725692749023437, 2099.072998046875, 61.2655487060546875, 5.854166984558105468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+3, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -228.699661254882812, 2131.401123046875, 61.34502410888671875, 6.259618282318115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2
(@CGUID+4, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -226.574661254882812, 2132.260498046875, 61.34328079223632812, 3.798971891403198242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2
(@CGUID+5, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -242.01910400390625, 2109.053955078125, 67.83048248291015625, 1.412065863609313964, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2
(@CGUID+6, 129908, 1643, 8721, 8904, '0', 0, 0, 0, 0, -315.119781494140625, 2119.151123046875, 77.52124786376953125, 2.496338129043579101, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Woodlands Recluse (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+7, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -227.711807250976562, 2130.241455078125, 61.33203887939453125, 1.137654423713684082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2
(@CGUID+8, 121620, 1643, 8721, 8852, '0', 0, 0, 0, 0, -230.536453247070312, 2059.395751953125, 58.31372833251953125, 1.514426469802856445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+9, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -241.461807250976562, 2136.564208984375, 69.782318115234375, 5.307258129119873046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+10, 122961, 1643, 8721, 8852, '0', 0, 0, 0, 0, -283.3194580078125, 2144.46875, 79.86499786376953125, 4.226171493530273437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Cursed Game-hawk (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 253956 - Possessed)
(@CGUID+11, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -206.241317749023437, 2097.670166015625, 66.91942596435546875, 2.930638313293457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+12, 121620, 1643, 8721, 8852, '0', 0, 0, 0, 0, -258.145843505859375, 2156.467041015625, 66.13021087646484375, 4.558325767517089843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+13, 121684, 1643, 8721, 8904, '0', 0, 0, 0, 0, -310.59375, 2114.12841796875, 76.49868011474609375, 4.760544300079345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Smoochums (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1
(@CGUID+14, 121620, 1643, 8721, 8852, '0', 0, 0, 0, 0, -216.380203247070312, 2110.2900390625, 61.65161895751953125, 1.27909553050994873, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+15, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -243.463546752929687, 2100.111083984375, 70.455474853515625, 5.947761058807373046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+16, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -240.642364501953125, 2078.44970703125, 70.3778228759765625, 6.098418235778808593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+17, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -243.623260498046875, 2119.4462890625, 68.94051361083984375, 0.049120407551527023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+18, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -218.26910400390625, 2077.442626953125, 65.0976409912109375, 1.318473577499389648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+19, 121610, 1643, 8721, 8852, '0', 0, 0, 0, 0, -195.59722900390625, 2082.204833984375, 69.95484161376953125, 2.258758544921875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Watchful Raven (Area: Glenbrook Homestead - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+20, 129908, 1643, 8721, 8904, '0', 0, 0, 0, 0, -304.140625, 2108.76904296875, 75.53656005859375, 2.520004749298095703, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Woodlands Recluse (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+21, 129764, 1643, 8721, 8904, '0', 0, 0, 0, 0, -299.69097900390625, 2152.661376953125, 75.8958587646484375, 0.410748928785324096, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Hexcrazed Doe (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+22, 129908, 1643, 8721, 8904, '0', 0, 0, 0, 0, -318.7725830078125, 2104.725830078125, 77.5648040771484375, 3.64345550537109375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Woodlands Recluse (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+23, 129908, 1643, 8721, 8904, '0', 0, 0, 0, 0, -270.953125, 2159.154541015625, 70.9869537353515625, 2.839523077011108398, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Woodlands Recluse (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2
(@CGUID+24, 129764, 1643, 8721, 8904, '0', 0, 0, 0, 0, -299.942718505859375, 2154.546875, 76.18402862548828125, 6.17005014419555664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Hexcrazed Doe (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+25, 121620, 1643, 8721, 8904, '0', 0, 0, 0, 0, -257.076385498046875, 2130.51904296875, 63.58786392211914062, 3.891466617584228515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Darkmaw Prowler (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject2 (Auras: 254701 - Possessed)
(@CGUID+26, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -268.400360107421875, 2071.049560546875, 61.56212234497070312, 6.158946037292480468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 124316, 1643, 8721, 8904, '0', 0, 0, 0, 0, -210.748260498046875, 2113.178955078125, 61.93177032470703125, 5.140850067138671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Pig (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+28, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -258.6475830078125, 2154.395751953125, 66.04390716552734375, 5.075294017791748046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+29, 124316, 1643, 8721, 8904, '0', 0, 0, 0, 0, -211.835067749023437, 2104.41845703125, 61.97541427612304687, 2.184660673141479492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Pig (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+30, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -213.446182250976562, 2110.614501953125, 61.79383087158203125, 0.408152341842651367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 138767 - Custom - Permanent Feign Death)
(@CGUID+31, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -258.53125, 2154.928955078125, 66.04512786865234375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 138767 - Custom - Permanent Feign Death)
(@CGUID+32, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -208.274307250976562, 2110.748291015625, 62.1163177490234375, 2.305501222610473632, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 138767 - Custom - Permanent Feign Death)
(@CGUID+33, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -202.345916748046875, 2129.921875, 64.3500518798828125, 3.141592741012573242, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -259.305572509765625, 2176.647705078125, 66.39715576171875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 138767 - Custom - Permanent Feign Death)
(@CGUID+35, 124316, 1643, 8721, 8904, '0', 0, 0, 0, 0, -216.189239501953125, 2112.291748046875, 61.64409637451171875, 5.735554218292236328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Pig (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+36, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -255.729019165039062, 2187.936279296875, 68.14447784423828125, 4.693384647369384765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+37, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -258.767364501953125, 2155.364501953125, 66.03820037841796875, 3.354825735092163085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+38, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -202.69915771484375, 2124.989501953125, 64.13677215576171875, 4.565979957580566406, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 124316, 1643, 8721, 8904, '0', 0, 0, 0, 0, -208.51910400390625, 2099.654541015625, 62.24478912353515625, 0.866686880588531494, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Pig (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+40, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -229.649383544921875, 2082.688232421875, 61.55254745483398437, 0.640896439552307128, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -248.5701904296875, 2166.6669921875, 65.82982635498046875, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1
(@CGUID+42, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -217.260421752929687, 2103.4775390625, 61.66666412353515625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 138767 - Custom - Permanent Feign Death)
(@CGUID+43, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -253.355911254882812, 2174.376708984375, 66.145904541015625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+44, 124316, 1643, 8721, 8904, '0', 0, 0, 0, 0, -239.180557250976562, 2087.225830078125, 60.91320037841796875, 4.281611442565917968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Pig (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+45, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -250.819076538085937, 2171.904052734375, 65.94525146484375, 6.247649192810058593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1
(@CGUID+46, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -257.87847900390625, 2154.947998046875, 66.05495452880859375, 2.041521310806274414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+47, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -213.563430786132812, 2079.584716796875, 64.65447998046875, 6.043421268463134765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+48, 124316, 1643, 8721, 8904, '0', 0, 0, 0, 0, -227.470489501953125, 2131.145751953125, 61.33857345581054687, 2.184660673141479492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Pig (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+49, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -205.534149169921875, 2128.931396484375, 64.04351043701171875, 0.841255903244018554, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 129926, 1643, 8721, 8904, '0', 0, 0, 0, 0, -259.81597900390625, 2176.333251953125, 66.4002838134765625, 4.383038520812988281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Chicken (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (Auras: 169471 - Bloody Death)
(@CGUID+51, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -262.285308837890625, 2084.9765625, 61.560546875, 4.856213569641113281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163), -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1
(@CGUID+52, 124429, 1643, 8721, 8904, '0', 0, 0, 0, 0, -192.028945922851562, 2068.298095703125, 70.12723541259765625, 3.565534114837646484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 63163); -- Scavenging Rat (Area: Glenbrook Hunting Grounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Watchful Raven
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Watchful Raven
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Watchful Raven
(@CGUID+21, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Hexcrazed Doe - 123169 - Mod Scale 105-110%
(@CGUID+27, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Pig - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Chicken - 169471 - Bloody Death
(@CGUID+29, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Pig - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+30, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '138767'), -- Chicken - 138767 - Custom - Permanent Feign Death
(@CGUID+31, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '138767'), -- Chicken - 138767 - Custom - Permanent Feign Death
(@CGUID+32, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '138767'), -- Chicken - 138767 - Custom - Permanent Feign Death
(@CGUID+34, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '138767'), -- Chicken - 138767 - Custom - Permanent Feign Death
(@CGUID+35, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Pig - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Chicken - 169471 - Bloody Death
(@CGUID+39, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Pig - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+42, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '138767'), -- Chicken - 138767 - Custom - Permanent Feign Death
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Chicken - 169471 - Bloody Death
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Pig - 169471 - Bloody Death
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Chicken - 169471 - Bloody Death
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'), -- Pig - 169471 - Bloody Death
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '169471'); -- Chicken - 169471 - Bloody Death

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 295778, 1643, 8721, 8852, '0', 0, 0, -255.296920776367187, 2090.9287109375, 62.20907211303710937, 2.665482759475708007, 0.000527381896972656, 0.010519981384277343, 0.971739768981933593, 0.235819622874259948, 120, 255, 1, 63163), -- Fire (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+1, 295778, 1643, 8721, 8852, '0', 0, 0, -259.794097900390625, 2124.765625, 63.38506317138671875, 4.089076995849609375, -0.01301336288452148, 0.018374443054199218, -0.88967418670654296, 0.456040382385253906, 120, 255, 1, 63163), -- Fire (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+2, 295778, 1643, 8721, 8852, '0', 0, 0, -199.375930786132812, 2131.210693359375, 63.97809219360351562, 1.078379154205322265, -0.01748418807983398, -0.01418685913085937, 0.513249397277832031, 0.857944130897521972, 120, 255, 1, 63163), -- Fire (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+3, 295778, 1643, 8721, 8852, '0', 0, 0, -262.519134521484375, 2188.455810546875, 67.745391845703125, 3.67892313003540039, -0.00899887084960937, 0.020639419555664062, -0.96390056610107421, 0.265308767557144165, 120, 255, 1, 63163), -- Fire (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+4, 270917, 1643, 8721, 8852, '0', 0, 0, -310.96875, 2112.75, 76.4367828369140625, 0.128059744834899902, 0.019237518310546875, 0.068603515625, 0.062236785888671875, 0.995514988899230957, 120, 255, 1, 63163), -- Glenbrook Register (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+5, 226941, 1643, 8721, 8852, '0', 0, 0, -255.930557250976562, 2126.6337890625, 63.30929183959960937, 0.999860644340515136, 0, 0, 0.479364395141601562, 0.877615988254547119, 120, 255, 1, 63163), -- Blood Splat (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+6, 271123, 1643, 8721, 8852, '0', 0, 0, -310.541656494140625, 2113.567626953125, 76.35105133056640625, 0.364725828170776367, -0.01018333435058593, 0.239767074584960937, 0.167990684509277343, 0.956131339073181152, 120, 255, 1, 63163), -- Fish Bones (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+7, 226941, 1643, 8721, 8852, '0', 0, 0, -132.291671752929687, 2269.24658203125, 61.74735641479492187, 2.948801040649414062, 0, 0, 0.995357513427734375, 0.096246540546417236, 120, 255, 1, 63163), -- Blood Splat (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+8, 271121, 1643, 8721, 8852, '0', 0, 0, -311.71875, 2114.005126953125, 76.60269927978515625, 4.522019386291503906, -0.429840087890625, 0.606579780578613281, -0.47476482391357421, 0.471059262752532958, 120, 255, 1, 63163), -- Backpack (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+9, 226941, 1643, 8721, 8852, '0', 0, 0, -215.5625, 2110.05029296875, 61.60590362548828125, 3.271259546279907226, 0, 0, -0.99789905548095703, 0.064787946641445159, 120, 255, 1, 63163); -- Blood Splat (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, -0.0098505113273859, 0.003730420488864183, 0.073740787804126739, 0.997221827507019042, 0, 0), -- Fire
(@OGUID+1, 0.021481763571500778, 0.006747439038008451, 0.707038938999176025, 0.706816017627716064, 0, 0), -- Fire
(@OGUID+2, 0.008137930184602737, -0.02099444717168807, -0.65906083583831787, 0.751752495765686035, 0, 0), -- Fire
(@OGUID+3, 0.022405685856938362, 0.002231418155133724, 0.548284471035003662, 0.835988759994506835, 0, 0), -- Fire
(@OGUID+5, 0, 0, 0, 1, 0, 5605), -- Blood Splat
(@OGUID+7, 0, 0, 0, 1, 0, 5605), -- Blood Splat
(@OGUID+9, 0, 0, 0, 1, 0, 5605); -- Blood Splat

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (128361,122961,129926,124316,121620,129764);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(128361, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '254723 123169'), -- 128361 (Hexcrazed Greatstag) - Possessed
(122961, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '253956'), -- 122961 (Cursed Game-hawk) - Possessed
(129926, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 129926 (Chicken) - Bloody Death
(124316, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 124316 (Pig) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(121620, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '254701'), -- 121620 (Darkmaw Prowler)
(129764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 257339'); -- 129764 (Hexcrazed Doe) - Mod Scale 105-110%, Possessed

-- Template
UPDATE `creature_template` SET `unit_flags`=0x0 WHERE `entry`=121620; -- Darkmaw Prowler
UPDATE `creature_template` SET `faction`=31, `unit_flags`=0x300, `unit_flags3`=0x4000000 WHERE `entry`=124316; -- Pig

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` IN (138767,169471);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(138767, 'spell_gen_feign_death_all_flags_no_uninteractible'),
(169471, 'spell_gen_feign_death_all_flags_no_uninteractible');

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63163 WHERE (`Entry`=122961 AND `DifficultyID`=0); -- 122961 (Cursed Game-hawk) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63163 WHERE (`Entry`=129926 AND `DifficultyID`=0); -- 129926 (Chicken) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63163 WHERE (`Entry`=121620 AND `DifficultyID`=0); -- 121620 (Darkmaw Prowler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63163 WHERE (`Entry`=129764 AND `DifficultyID`=0); -- 129764 (Hexcrazed Doe) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63163 WHERE (`Entry`=121684 AND `DifficultyID`=0); -- 121684 (Smoochums) - CanSwim

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=63163 WHERE `DisplayID` IN (80884, 70440, 4959, 36299, 70451, 87370, 80919, 22469, 78849, 36298, 70445, 81079, 66640, 21342, 79843, 86197, 70448, 81029, 70442, 80910, 304, 81081, 80962, 16358, 5369, 16356, 81061, 70446, 80951, 80850);
UPDATE `creature_model_info` SET `BoundingRadius`=1.847484946250915527, `VerifiedBuild`=63163 WHERE `DisplayID`=32546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.166421815752983093, `CombatReach`=0.60000002384185791, `VerifiedBuild`=63163 WHERE `DisplayID`=76482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382819831371307373, `CombatReach`=1, `VerifiedBuild`=63163 WHERE `DisplayID`=36357;

-- Quest
DELETE FROM `creature_questender` WHERE (`id`=121684 AND `quest`=47428);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(121684, 47428, 63163); -- Kitty? ended by Smoochums

-- Watchful Raven smart ai
SET @ENTRY := 121610;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 258247, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 258247 on self', '');

UPDATE `creature` SET `StringId` = 'ChannelPerched' WHERE `guid` IN (@CGUID+9,@CGUID+11,@CGUID+15,@CGUID+16,@CGUID+17,@CGUID+18,@CGUID+19);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 121610 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 121610, 0, 0, 58, 1, 0, 0, 0, 'ChannelPerched', 0, 'Object has StringID ChannelPerched');

-- Darkmaw Prowler smart ai
SET @ENTRY := 121620;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 145953, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 145953 on self', ''),
(@ENTRY, 0, 1, 0, 1, 0, 100, 1, 1000, 3000, 0, 0, 0, 85, 257295, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time between 1second and 3seconds (OOC) - Self: Cast spell 257295 on self', '');

UPDATE `creature` SET `StringId` = 'CosmeticSleep' WHERE `guid` IN (@CGUID+1, @CGUID+2, @CGUID+25);
UPDATE `creature` SET `StringId` = 'CosmeticEat' WHERE `guid` IN (@CGUID+12, @CGUID+14, @CGUID+0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 121620 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 121620, 0, 0, 58, 1, 0, 0, 0, 'CosmeticSleep', 0, 'Object has StringID CosmeticSleep'),
(22, 2, 121620, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEat', 0, 'Object has StringID CosmeticEat');

-- Path for Cursed Game-Hawk
SET @MOVERGUID := @CGUID+10;
SET @ENTRY := 122961;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Cursed Game-hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -286.89587, 2137.7021, 79.865, NULL, 0),
(@PATH, 1, -284.64, 2130.3884, 79.865, NULL, 0),
(@PATH, 2, -277.87332, 2126.812, 79.865, NULL, 0),
(@PATH, 3, -270.55966, 2129.0679, 79.865, NULL, 0),
(@PATH, 4, -266.98325, 2135.8345, 79.865, NULL, 0),
(@PATH, 5, -269.2391, 2143.1482, 79.865, NULL, 0),
(@PATH, 6, -276.0058, 2146.7246, 79.865, NULL, 0),
(@PATH, 7, -283.31946, 2144.4688, 79.865, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '253956');

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+5;
SET @ENTRY := 121610;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -240.80934, 2116.6113, 67.83048, NULL, 0),
(@PATH, 1, -234.60999, 2121.0999, 67.83048, NULL, 0),
(@PATH, 2, -227.05252, 2119.8901, 67.83048, NULL, 0),
(@PATH, 3, -222.56403, 2113.6907, 67.83048, NULL, 0),
(@PATH, 4, -223.7738, 2106.1333, 67.83048, NULL, 0),
(@PATH, 5, -229.97316, 2101.6448, 67.83048, NULL, 0),
(@PATH, 6, -237.53061, 2102.8545, 67.83048, NULL, 0),
(@PATH, 7, -242.0191, 2109.054, 67.83048, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
