-- 
SET @CGUID := 253771;
SET @OGUID := 211081;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+550;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+6, 53488, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -560.0018, -530.7379, 890.6761, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Summon Enabler Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 99201 - Summon Enabler)
(@CGUID+7, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -473.345, -525.483, 892.4473, 3.281219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+8, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -476.142, -533.194, 890.6763, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+9, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -469.651, -530.432, 893.5003, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+10, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -451.6563, -504.9688, 894.9089, 0.8028514, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+11, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -449.9884, -517.5735, 894.088, 1.080439, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+12, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -472.253, -536.538, 892.4653, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+13, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -453.846, -528.0276, 894.0881, 5.1953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+14, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -454.1754, -497.5365, 894.9089, 6.056293, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+15, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -453.9896, -562.4879, 894.9089, 5.916666, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+16, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -479.991, -531.123, 890.6763, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+17, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -455.9789, -528.5204, 894.0886, 4.099702, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+18, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -479.318, -524.196, 890.6763, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+19, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -456.4307, -520.5366, 894.0881, 1.464224, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+20, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -450.2511, -528.7861, 894.0882, 6.019217, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+21, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -455.7848, -516.7451, 894.0878, 0.5708838, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+22, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -452.2517, -570.1389, 894.9089, 0.6806784, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+23, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -448.3517, -522.8997, 894.1291, 6.245685, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+24, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -456.0172, -522.6824, 894.0881, 0.3098949, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+25, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -452.1892, -493.7778, 894.9089, 5.550147, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+26, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -449.6142, -511.3437, 894.088, 1.119685, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+27, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -456.3458, -526.6609, 894.0883, 4.72186, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+28, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -478.148, -538.096, 890.6763, 3.01942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+29, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -476.521, -528.498, 890.6763, 3.211406, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+30, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -451.5642, -559.0104, 894.9089, 5.410521, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+31, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -444.566, -491.2049, 894.9089, 4.520403, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+32, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -443.8438, -557.2847, 894.9089, 4.380776, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+33, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -448.5104, -572.5434, 894.9089, 1.27409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+34, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -420.3333, -493.1632, 894.9089, 5.445427, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+35, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -422.7674, -500.8073, 894.9089, 0.2268928, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+36, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -440.6458, -493.5208, 894.9089, 3.944444, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+37, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -414.988, -499.075, 894.6703, 5.393067, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84568 - Phase-Twist)
(@CGUID+38, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -422.5399, -567.4618, 894.9089, 0.296706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+39, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -440.4236, -504.5746, 894.9089, 2.426008, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+40, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -420.3576, -570.7899, 894.9089, 0.8028514, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+41, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -420.8299, -504.3246, 894.9089, 0.7330383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+42, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -420.6441, -559.5139, 894.9089, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+43, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -438.7135, -501.0469, 894.9089, 2.897247, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+44, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -446.358, -499.215, 894.6703, 3.525565, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84568 - Phase-Twist)
(@CGUID+45, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -440.309, -559.632, 894.9089, 3.874631, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+46, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -422.5139, -496.5139, 894.9089, 5.951573, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+47, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -440.9583, -570.8577, 894.9089, 2.303835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+48, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -422.783, -563.2448, 894.9089, 6.073746, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+49, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -446.252, -564.891, 894.6703, 3.647738, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84568 - Phase-Twist)
(@CGUID+50, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -414.884, -565.012, 894.6703, 0.7853982, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84568 - Phase-Twist)
(@CGUID+51, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -438.5677, -567.5313, 894.9089, 2.827433, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+52, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -413.1337, -506.8715, 894.9089, 1.797689, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+53, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -448.0799, -506.8698, 894.9089, 1.32645, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+54, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -416.4236, -491.184, 894.9089, 4.921828, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+55, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -407.1337, -497.0538, 894.9089, 3.438299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+56, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -362.7794, -524.0903, 894.58, 6.178653, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+57, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -409.4184, -559.0504, 894.9089, 3.979351, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+58, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -409.1146, -493.5417, 894.9089, 3.909538, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+59, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -363.4055, -530.0576, 894.58, 6.178653, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+60, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -409.1024, -570.3785, 894.9089, 2.373648, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+61, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -407.2153, -501.6545, 894.9089, 2.80998, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+62, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -409.5573, -505.0295, 894.9089, 2.303835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+63, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -398.2065, -548.2385, 894.0871, 4.744542, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+64, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -393.8363, -545.1528, 894.5801, 3.124424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+65, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -393.7332, -539.1537, 894.5801, 3.124424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+66, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -398.9564, -539.064, 894.0872, 3.124425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+67, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -397.8227, -533.334, 894.0869, 3.078277, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+68, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -407.4167, -562.4184, 894.9089, 3.420845, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+69, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -396.6529, -530.6254, 894.087, 1.859064, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+70, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -416.7691, -572.8229, 894.9089, 1.343904, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+71, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -355.8893, -530.8461, 894.6088, 6.178656, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+72, 45264, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -393.4382, -533.334, 894.58, 3.068504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+73, 45266, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -393.5272, -527.1555, 894.58, 3.124424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+74, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -407.2014, -566.7239, 894.9089, 2.9147, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+75, 45265, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -357.4272, -525.6479, 894.58, 0.9888877, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84849 - Soul Blade)
(@CGUID+76, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -394.5213, -550.0142, 894.5389, 5.185206, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+77, 45267, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -413.184, -557.1146, 894.9089, 4.520403, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Phase-Twister (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+78, 45261, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -398.0121, -545.0811, 894.087, 3.124422, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84827 - Shield Mastery)
(@CGUID+79, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -344.839, -720.163, 891.7643, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+80, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -350.571, -725.417, 891.7633, 1.064651, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+81, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -348.538, -700.247, 888.1903, 5.532694, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+82, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -353.764, -706.361, 888.1903, 2.303835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+83, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -347.578, -717.302, 891.7633, 1.047198, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+84, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -352.804, -695.064, 888.1903, 5.358161, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+85, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -346.434, -724.049, 891.7643, 1.099557, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+86, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -347.08, -728.128, 891.7643, 1.117011, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+87, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -358.964, -702.148, 888.1903, 2.303835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+88, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -350.564, -721.663, 891.7633, 1.012291, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+89, 44797, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -353.179, -700.667, 888.1903, 5.532694, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Time Warden (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+90, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -189.415, -732.878, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+91, 44652, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -279.111, -680.594, 888.1913, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Slate Dragon (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+92, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -230.665, -718.797, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+93, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -208.443, -739.306, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+94, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -933.864, -578.0896, 831.9018, 2.622164, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+95, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -242.097, -805.613, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+96, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -918.995, -583.804, 831.9843, 3.501734, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+97, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -209.033, -715.948, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+98, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -260.908, -765.717, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+99, 44687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -265.891, -740.023, 907.3633, 2.338741, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Proto-Behemoth (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83412 - Force Flying, 84106 - Dancing Flames, 83956 - Superheated Breath)
(@CGUID+100, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -256.325, -787.965, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+101, 44600, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -290.964, -713.484, 888.2043, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Halfus Wyrmbreaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 39171 - Malevolent Strikes, 83693 - Frenzied Assault, 83952 - Shadow Wrapped) (possible waypoints or random movement)
(@CGUID+102, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -939.981, -588.087, 831.9843, 1.862976, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+103, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -231.026, -701.149, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+104, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -340.75, -722.476, 891.7643, 1.169371, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+105, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -279.719, -773.378, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+106, 44645, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -280.118, -659.385, 888.1883, 1.675516, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Nether Scion (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+107, 42098, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -239.958, -782.721, 812.3493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+108, 44641, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -342.002, -726.528, 891.7643, 1.169371, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Orphaned Emerald Whelp (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+109, 44650, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -318.705, -722.688, 888.1913, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Storm Rider (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+110, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -946.311, -577.569, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+111, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -320.158, -727.995, 888.1913, 3.246312, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+112, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -274.8906, -656.8351, 888.1893, 4.956735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+113, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -284.868, -661.151, 888.1903, 1.710423, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+114, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -277.955, -687.788, 888.1923, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+115, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -314.986, -717.396, 888.1903, 0.2617994, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+116, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -280.724, -674.46, 888.1903, 0.08726646, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+117, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -273.922, -675.948, 888.1893, 6.195919, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+118, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -283.142, -685.325, 888.1913, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+119, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -321.974, -718.424, 888.1913, 0.3839724, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+120, 44765, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -273.01, -684.694, 888.1913, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spike (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83480 - Spike Visual)
(@CGUID+121, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -448.806, -672.181, 894.6663, 6.038839, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+122, 46965, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -663.141, -684.913, 834.7153, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cho'gall (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 87482 - Periodic Player Search Trigger)
(@CGUID+123, 47079, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -517.281, -703.354, 785.3463, 0.6386635, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lava Scarab (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+124, 47079, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -456.17, -662.503, 778.5073, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lava Scarab (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+125, 46952, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -451.438, -685.332, 894.6663, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+126, 47079, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -495.991, -688.823, 785.3463, 3.825245, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lava Scarab (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+127, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -448.602, -697.616, 894.6633, 0.4363323, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+128, 47079, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -445.056, -706.049, 778.5073, 1.771204, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lava Scarab (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+129, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -586.7327, -631.717, 834.7148, 4.782202, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+130, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -583.8073, -717.4375, 834.7148, 4.939282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+131, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -595.0799, -636.0504, 834.7148, 5.794493, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+132, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -582.17, -723.396, 834.7153, 0.6457718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+133, 47079, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -521.415, -675.712, 785.3463, 6.018116, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lava Scarab (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+134, 47151, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -577.5104, -728.8542, 834.7148, 1.989675, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+135, 47081, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -573.538, -719.878, 834.7153, 3.001966, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+136, 47150, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -583.2934, -730.8854, 834.7148, 1.37881, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+137, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -596.8507, -640.4045, 834.7148, 0.06981317, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+138, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -591.8993, -631.7761, 834.7148, 5.183628, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+139, 47079, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -464.984, -692.545, 785.3463, 3.132068, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lava Scarab (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+140, 47081, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -577.566, -715.7379, 834.7148, 3.787364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+141, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -593.875, -628.8073, 834.7148, 5.061455, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+142, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -603.3195, -638.2795, 834.7148, 5.5676, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+143, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -582.2778, -636.3976, 834.7148, 3.438299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+144, 47151, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -623.816, -647.6996, 834.7148, 2.740167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+145, 47150, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -625.9271, -640.4375, 834.7148, 3.926991, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+146, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -587.066, -626.6823, 834.7148, 4.694936, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+147, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -623.269, -738.898, 834.7143, 2.321288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+148, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -627.6146, -649.6511, 834.7148, 2.234021, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+149, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -599.4792, -632.5816, 834.7148, 5.427974, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+150, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -621.1077, -745.3489, 834.7148, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+151, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -585.385, -722.53, 834.7153, 0.2617994, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+152, 47151, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -588.076, -717.471, 834.7153, 5.445427, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+153, 47150, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -589.455, -724.906, 834.7153, 0.3490658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+154, 46952, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -656.394, -696.481, 834.7153, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+155, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -647.797, -672.542, 834.7153, 3.822271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+156, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -628.493, -644.3871, 834.7148, 3.839724, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+157, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -649.672, -679.969, 834.7153, 3.508112, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+158, 47151, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -644.7899, -704.5278, 834.7148, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+159, 47150, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -649.9636, -709.882, 834.7148, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+160, 46952, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -657.023, -669.576, 834.7153, 4.328416, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+161, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -660.42, -697.372, 834.7153, 1.745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+162, 47151, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -656.922, -709.627, 834.7153, 1.902409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+163, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -660.252, -667.686, 834.7153, 4.433136, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+164, 46952, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -648.806, -684.971, 834.7153, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+165, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -653.477, -694.368, 834.7153, 2.321288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+166, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -631.7535, -645.0538, 834.7148, 4.223697, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+167, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -654.521, -673.438, 834.7153, 6.213372, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+168, 47081, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -655.342, -714.7448, 834.7148, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+169, 47081, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -651.21, -703.512, 834.7153, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+170, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -646.448, -697.309, 834.7153, 2.548181, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+171, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -627.9739, -745.6736, 834.7148, 1.396263, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+172, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -627.818, -740.076, 834.7153, 1.762783, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+173, 47151, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -638.375, -642.2761, 834.7148, 5.5676, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+174, 47081, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -637.8854, -652.0816, 834.7148, 0.296706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+175, 47150, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -634.118, -637.8594, 834.7148, 4.956735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+176, 46952, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -641.885, -685.115, 834.7153, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+177, 46951, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -649.323, -689.858, 834.7153, 2.80998, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+178, 47081, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -632.4271, -653.9705, 834.7148, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+179, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -725.221, -642.396, 834.3303, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+180, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -725.377, -716.927, 831.9843, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+181, 47150, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -665.729, -709.622, 834.7153, 1.37881, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+182, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -714.431, -674.51, 831.9813, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+183, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -713.681, -717.589, 833.3923, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+184, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.717, -657.243, 831.9843, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+185, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -714.703, -654.512, 832.4553, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+186, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.3, -769.868, 850.0473, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+187, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -706.589, -688.766, 831.9613, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+188, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -714.146, -701.741, 831.9843, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+189, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -715.352, -631.644, 836.7803, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+190, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.872, -731.773, 835.7693, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+191, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -713.927, -689.358, 831.9803, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+192, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.976, -743.757, 836.7773, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+193, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -715.116, -642.521, 836.0923, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+194, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -692.877, -688.375, 834.7733, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+195, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -725.628, -671.646, 831.9843, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+196, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -713.432, -731.102, 836.7823, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+197, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.873, -616.878, 836.7763, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+198, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -715.747, -768.009, 836.7733, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+199, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -715.854, -616.559, 836.7753, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+200, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -725.3698, -600.2066, 850.8423, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+201, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -714.576, -666.49, 831.9843, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+202, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -700.708, -681.743, 833.8353, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+203, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.913, -701.007, 831.9843, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+204, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -725.339, -601.031, 836.7773, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+205, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.625, -630.392, 836.7813, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+206, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.51, -759.604, 836.7763, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+207, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -724.262, -773.118, 836.7753, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+208, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -715.995, -754.495, 836.7753, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+209, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -716.319, -600.712, 836.7733, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+210, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -725.163, -687.493, 831.9823, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+211, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -649.372, -666.09, 834.7153, 3.717551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+212, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -636.273, -735.965, 834.7153, 0.7504916, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+213, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -635.175, -729.597, 834.7153, 5.689773, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+214, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -646.0295, -662.6111, 834.7148, 3.612832, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+215, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -658.9011, -697.7136, 834.7148, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+216, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -648.1233, -656.7969, 834.7148, 3.769911, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+217, 47161, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -634.3455, -743.434, 834.7148, 1.029744, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 42459 - Dual Wield)
(@CGUID+218, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -656.227, -664.17, 834.7143, 3.961897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 88204 - Arcane Infused Fists)
(@CGUID+219, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -660.941, -661.828, 834.7143, 4.13643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+220, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -633.142, -740.071, 834.7153, 1.151917, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+221, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -643.9705, -668.6805, 834.7148, 3.787364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 88204 - Arcane Infused Fists)
(@CGUID+222, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -655.2917, -669.3472, 834.7148, 3.647738, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+223, 47087, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -653.559, -657.622, 834.7153, 3.961897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 88204 - Arcane Infused Fists)
(@CGUID+224, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -651.559, -661.814, 834.7153, 3.787364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+225, 47086, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -640.1163, -739.2465, 834.7148, 0.6632251, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+226, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -662.403, -701.109, 834.7143, 2.251475, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+227, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.896, -671.622, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+228, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.635, -631.693, 836.7823, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+229, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.604, -620.927, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+230, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.701, -771.53, 836.7813, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+231, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -748.0208, -685.9375, 831.9724, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86287 - Summon Twilight Portal)
(@CGUID+232, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.9375, -601.6788, 851.0323, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+233, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.814, -735.149, 836.2393, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+234, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.724, -684.797, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+235, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.661, -696.71, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+236, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.4809, -770.5538, 851.1473, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+237, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.877, -723.238, 832.4553, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+238, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.667, -609.014, 836.7793, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+239, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.53, -655.889, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+240, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -741.016, -746.552, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+241, 45993, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -743.1458, -742.3195, 836.7814, 1.500983, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Theralion (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86360 - Twilight Shift, 88520 - Hittin' Ya Proc Trigger) (possible waypoints or random movement)
(@CGUID+242, 46364, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.804, -683.642, 858.6563, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Theralion Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+243, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.434, -777.5486, 858.8013, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+244, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.839, -710.5, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+245, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.592, -643.976, 833.3923, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+246, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.764, -759.62, 836.7793, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+247, 45992, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -742.6198, -627.3906, 836.7814, 4.642576, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86360 - Twilight Shift, 88520 - Hittin' Ya Proc Trigger)
(@CGUID+248, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.6771, -592.3281, 859.4563, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+249, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.4149, -767.2205, 849.9223, 4.729842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+250, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.906, -741.59, 836.7793, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+251, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.014, -674.186, 831.9813, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+252, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.509, -650.469, 832.4553, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+253, 46296, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -759.2274, -603.4236, 851.0353, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Breath Flight Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+254, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.705, -696.806, 831.9823, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+255, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -740.755, -592.372, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+256, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.51, -751.458, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+257, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.321, -620.125, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+258, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.493, -662.523, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+259, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.078, -718.453, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+260, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.752, -637.04, 836.2393, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+261, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.599, -730.118, 835.3073, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+262, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.462, -710.234, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+263, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.564, -606.696, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+264, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.102, -686.938, 831.9833, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+265, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -757.267, -764.887, 836.7773, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+266, 47152, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -666.064, -703.797, 834.7143, 1.553343, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+267, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -769.778, -666.995, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+268, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -769.201, -633.422, 836.7803, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+269, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -770.257, -655.33, 832.9223, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+270, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -766.924, -614.302, 836.7753, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+271, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -769.693, -712.913, 832.4553, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+272, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -769.293, -722.781, 834.7973, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+273, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -770.2379, -677.7778, 831.9763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+274, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -768.804, -643.29, 835.7693, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+275, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -770.1996, -700.7743, 831.9806, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+276, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -765.446, -760.66, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+277, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -765.418, -752.922, 836.7763, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+278, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -770.543, -691.556, 831.9753, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+279, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -758.962, -596.828, 836.7723, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+280, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -766.924, -614.302, 836.7753, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+281, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -769.05, -736.208, 836.7803, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+282, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -777.6563, -682.3993, 831.9801, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+283, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -767.403, -602.637, 836.7723, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+284, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -764.693, -769.252, 836.7733, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+285, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -767.403, -602.637, 836.7723, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+286, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -764.78, -776.219, 794.1253, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+287, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -784.7639, -688.4965, 831.9816, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+288, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -793.087, -682.694, 831.9843, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+289, 49813, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -842.6476, -721.4983, 831.9843, 1.553343, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Evolved Drakonaar (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 93373 - Blade Tempest)
(@CGUID+290, 49813, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -849.5184, -621.5737, 831.9009, 5.11685, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Evolved Drakonaar (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+291, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -970.0286, -619.9232, 831.9068, 0.7197221, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+292, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -967.8049, -608.2154, 831.9063, 3.72732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+293, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -959.747, -574.266, 831.9843, 1.099951, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+294, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -956.9133, -591.3535, 831.9024, 2.973428, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+295, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -976.2995, -622.8874, 831.9062, 0.1321412, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+296, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -966.4766, -590.4571, 831.9018, 6.069686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+297, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -965.0588, -565.779, 831.9047, 0.3645574, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+298, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -976.0753, -604.3624, 831.9037, 2.526084, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+299, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -968.4642, -576.7635, 831.9017, 3.316683, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+300, 49821, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -971.7311, -607.0129, 831.9045, 0.9292434, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Zephyr (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 87906 - Stormling) (possible waypoints or random movement)
(@CGUID+301, 49825, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -971.8889, -608.3871, 831.9053, 0.7071324, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Deluge (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 93335 - Icy Shroud) (possible waypoints or random movement)
(@CGUID+302, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -979.0881, -596.5236, 831.9028, 3.154681, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+303, 49825, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -974.234, -582.7315, 831.901, 6.265959, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Deluge (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 93335 - Icy Shroud) (possible waypoints or random movement)
(@CGUID+304, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -965.5173, -552.4434, 831.9083, 3.244958, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+305, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -974.7892, -573.8582, 831.9019, 6.032576, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+306, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -985.4318, -589.2419, 831.9008, 0.1236518, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+307, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -980.4402, -563.764, 831.905, 0.8214153, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+308, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -978.4641, -582.463, 831.9009, 0.3581111, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+309, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -983.9661, -605.5043, 831.9033, 2.164809, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+310, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -975.0161, -559.468, 831.9062, 3.412115, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+311, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -986.3915, -617.0246, 831.9048, 6.026263, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+312, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -996.3832, -626.8102, 831.9068, 2.608278, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+313, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -979.4747, -552.9483, 831.9065, 3.180738, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+314, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1001.296, -629.8384, 831.9086, 5.830029, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+315, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -991.203, -575.0413, 831.9014, 0.09209222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+316, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -992.1273, -585.4781, 831.9, 5.435618, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+317, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -998.1052, -613.3066, 831.9029, 0.4010979, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+318, 49826, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -983.5356, -554.4149, 831.9058, 0.2324942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Rumbler (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+319, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -977.4371, -540.7712, 831.9074, 2.330196, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+320, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -999.6204, -582.0424, 831.9005, 0.2580743, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+321, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -986.6545, -546.5402, 831.9065, 5.808068, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+322, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -988.6606, -556.623, 831.9049, 5.989425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+323, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -997.3163, -599.7664, 831.9017, 2.794732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+324, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1008.74, -634.3183, 831.901, 5.951, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+325, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1000.899, -564.6099, 831.9023, 0.48634, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+326, 49821, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1003.799, -552.3964, 831.9037, 3.086954, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Zephyr (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 87906 - Stormling) (possible waypoints or random movement)
(@CGUID+327, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1013.865, -604.1934, 831.9011, 5.47485, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+328, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1003.91, -591.939, 831.9843, 5.93377, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+329, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -997.0698, -532.7996, 831.9067, 0.265731, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+330, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1012.361, -624.3463, 831.9099, 5.642484, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+331, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1006.315, -576.921, 831.9008, 5.930938, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+332, 49826, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1005.852, -593.2968, 831.9008, 4.771876, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Rumbler (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+333, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1012.636, -609.6308, 831.9014, 0.9293534, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+334, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1013.823, -586.5485, 831.901, 0.5634055, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+335, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1016.346, -545.8197, 831.9091, 4.897568, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+336, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1025.507, -564.8829, 831.9025, 2.492389, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+337, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1016.694, -555.4166, 831.904, 3.541871, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+338, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1035.745, -622.0859, 835.1806, 1.778935, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+339, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1023.088, -575.2911, 831.9014, 4.118245, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+340, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1017.099, -530.2889, 831.8799, 3.718594, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+341, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1034.28, -577.443, 831.9843, 5.051197, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+342, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1014.631, -567.7534, 831.901, 4.093147, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+343, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1028.449, -613.769, 833.8303, 2.273932, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+344, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1036.78, -605.793, 833.5931, 0.09583206, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+345, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1023.11, -592.632, 831.9843, 0.6557097, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+346, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1026.219, -583.9678, 831.9016, 3.605762, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+347, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1022.866, -634.0983, 832.1116, 4.837193, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+348, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1002.084, -541.3051, 831.9067, 3.969351, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+349, 49817, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1012.71, -582.3578, 831.9001, 3.245869, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Inferno (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 93336 - Ward of Combustion) (possible waypoints or random movement)
(@CGUID+350, 49817, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1020.643, -582.511, 831.9014, 3.164096, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bound Inferno (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 93336 - Ward of Combustion) (possible waypoints or random movement)
(@CGUID+351, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1029.309, -597.3824, 831.9014, 5.760507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+352, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1005.731, -552.8406, 831.9034, 3.505759, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+353, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1032.62, -543.7817, 835.264, 1.972785, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+354, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1044.18, -625.247, 835.1163, 0.5691338, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+355, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1040.31, -564.786, 833.6565, 0.02850492, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+356, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1043.617, -596.4669, 834.0994, 2.455135, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+357, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1043.255, -613.6236, 835.1808, 2.575387, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+358, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1052.719, -602.1031, 835.1408, 4.453825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+359, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1041.329, -574.4738, 832.8795, 0.5602997, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+360, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1055.453, -591.1892, 835.0756, 3.85047, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+361, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1042.874, -584.5643, 833.0053, 0.7387276, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+362, 43686, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1051.52, -600.976, 835.2843, 0.03490658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ignacious (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 82777 - Flame Torrent)
(@CGUID+363, 43688, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1060.87, -634.283, 877.7733, 0.8552113, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arion (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 34098 - ClearAllDebuffs)
(@CGUID+364, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1045.253, -604.7658, 835.2675, 1.086, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+365, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1052.348, -582.67, 835.0413, 4.387584, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+366, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1037.22, -554.545, 834.8113, 4.427449, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+367, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1052.06, -615.9723, 835.0327, 5.30512, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+368, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1070.354, -575.8802, 837.8397, 5.161081, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+369, 45685, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1092.61, -798.776, 840.4153, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Old God Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+370, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -972.825, -619.894, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+371, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1046.134, -547.2751, 835.0547, 0.8791474, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+372, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1043.009, -537.6044, 835.0541, 3.087628, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+373, 43687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1053.37, -564.056, 835.2423, 5.707227, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Feludius (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+374, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1086.58, -575.212, 841.3673, 3.738967, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+375, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1060.428, -585.048, 835.0448, 0.8471344, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+376, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1049.709, -559.8333, 835.162, 5.412726, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+377, 43689, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1059.68, -531.37, 877.7733, 5.689773, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Terrastra (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 83718 - Harden Skin)
(@CGUID+378, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1099.525, -584.1587, 841.2836, 4.704775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+379, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1085.674, -587.1256, 841.2835, 0.5149932, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+380, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -972.222, -548.712, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+381, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1055.528, -572.0411, 835.1694, 3.251894, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+382, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -955.512, -583.161, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+383, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1071.336, -587.7813, 838.109, 0.6193197, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+384, 45420, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1071.969, -581.5579, 838.0984, 6.102999, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Plume Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84911 - Lava Seed) (possible waypoints or random movement)
(@CGUID+385, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1008.22, -600.741, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+386, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1010.18, -636.564, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+387, 43691, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1008.67, -582.721, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Controller (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+388, 45700, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1108.446, -789.4514, 835.0883, 5.934119, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+389, 45700, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1108.993, -798.7847, 835.0882, 6.248279, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+390, 45700, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1108.448, -806.9549, 835.0883, 0.1745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+391, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1007.51, -565.024, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+392, 45699, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1113.38, -784.057, 835.1293, 3.735005, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85575 - Shadow Mending)
(@CGUID+393, 45687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1115.748, -796.0775, 835.0051, 4.655481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+394, 45699, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1113.729, -798.7031, 835.0884, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85575 - Shadow Mending)
(@CGUID+395, 45699, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1114.54, -811.313, 835.1293, 2.460914, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85575 - Shadow Mending)
(@CGUID+396, 45687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1123.335, -795.3395, 835.011, 1.534804, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+397, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1008.07, -534.792, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+398, 46147, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -735.0226, -685.691, 831.9722, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Valiona (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 93029 - Summon Twilight Sentry)
(@CGUID+399, 45687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1127.538, -798.0226, 835.0933, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+400, 45676, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1153.65, -755.609, 835.1293, 1.710423, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Guardian (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85413 - Pooled Blood Grow Visual)
(@CGUID+401, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1046.1, -617.335, 835.1553, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
-- (@CGUID+402, 45848, UNKNOWN, 5334, 5334, 3, 1, 169, 0, 0, 0, -0.07075573, -0.3206706, 0.3000276, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spray Blood (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+403, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -766.8671, -696.8567, 832.8965, 5.833842, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+404, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -715.4695, -739.8562, 837.693, 3.970282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+405, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -701.5867, -686.9615, 834.885, 3.898602, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+406, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -740.2249, -691.2647, 832.8937, 0.8176798, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+407, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -767.8703, -740.1144, 837.6913, 2.943735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+408, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -719.673, -726.3986, 836.213, 0.361836, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+409, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -768.0758, -720.1797, 835.4668, 4.828467, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+410, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -753.0229, -696.3515, 832.8958, 3.152586, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+411, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -738.8265, -670.2379, 832.8953, 5.653172, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+412, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -725.4732, -662.5917, 832.8983, 3.51264, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+413, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -736.026, -699.3331, 832.8961, 3.186763, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight)
(@CGUID+414, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -750.354, -671.5327, 832.895, 0.1977664, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+415, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -729.463, -741.9197, 837.6959, 5.061383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+416, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -740.0013, -726.7675, 835.1035, 1.553241, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+417, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -758.6226, -726.1312, 835.7926, 1.327131, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+418, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -744.0849, -708.0941, 832.8992, 2.937789, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight)
(@CGUID+419, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -712.9019, -717.9011, 835.0236, 2.214314, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+420, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -753.6905, -708.2728, 832.8996, 6.041525, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+421, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -775.1526, -707.4477, 833.8156, 1.6687, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+422, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -752.7634, -721.0743, 833.8799, 3.905548, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+423, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -744.3312, -663.2892, 832.8984, 2.998811, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+424, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -774.578, -687.122, 831.9733, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+425, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -747.0059, -743.9884, 837.6974, 5.420568, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+426, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -760.9524, -661.3225, 832.8995, 2.871414, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+427, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -730.3557, -720.5337, 833.6421, 5.467758, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+428, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -732.2816, -679.9801, 832.8911, 1.014137, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+429, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -758.9839, -689.5512, 832.8939, 3.809277, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+430, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -736.3352, -654.1136, 832.9021, 0.1161416, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+431, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -725.1524, -709.1758, 832.8988, 3.674961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+432, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -717.2882, -671.9202, 832.8942, 2.495436, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+433, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -764.4043, -672.4624, 832.8949, 6.233963, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+434, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -739.7856, -753.944, 837.6943, 5.087186, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+435, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -714.8995, -765.0818, 837.6855, 4.708003, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+436, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -757.3348, -640.5387, 836.5634, 0.2481678, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+437, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -731.3069, -761.6029, 837.6905, 1.665239, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+438, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -750.686, -779.358, 836.7703, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+439, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -749.4989, -763.1446, 837.6902, 5.595331, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+440, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -744.1171, -638.5109, 836.4183, 5.869873, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+441, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -727.1998, -639.5955, 836.6259, 5.223423, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+442, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -743.0797, -768.5047, 837.6887, 2.781163, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+443, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -754.4359, -627.9141, 837.6957, 2.39681, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+444, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -762.5661, -758.8089, 837.6888, 0.8366088, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+445, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -786.9932, -685.6622, 832.8999, 4.027124, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+446, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -720.7719, -630.9174, 837.6955, 2.722281, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+447, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -768.7952, -651.6185, 835.0521, 4.45599, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+448, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -753.7148, -650.3845, 833.4879, 5.292862, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+449, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -717.5218, -753.6583, 837.6886, 5.668316, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+450, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -769.8934, -632.1737, 837.692, 4.282431, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+451, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -755.7855, -750.8789, 837.6928, 0.3805608, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+452, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -717.8464, -650.1019, 834.7164, 6.280114, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+453, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -735.111, -631.0513, 837.6986, 5.16844, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+454, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -730.3085, -780.3134, 837.699, 0.581578, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+455, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -743.6366, -597.1542, 837.6867, 0.9497343, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+456, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -731.427, -589.0553, 837.6845, 3.825204, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+457, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -744.3016, -619.5187, 837.6958, 6.12604, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+458, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -761.8356, -602.1738, 837.6858, 2.636185, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+459, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -749.047, -589.9739, 837.7122, 2.20824, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+460, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -727.1582, -617.7188, 837.6913, 5.259856, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+461, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -764.3317, -616.7997, 837.6893, 1.606703, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+462, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -727.873, -601.8998, 837.6879, 4.405547, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+463, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -752.4962, -611.7874, 837.692, 4.371703, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+464, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -734.9903, -607.4755, 837.6908, 1.012318, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+465, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -719.5505, -608.1597, 837.6873, 1.280379, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+466, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -741.724, -708.582, 831.9843, 2.894177, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+467, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -731.8214, -700.8787, 832.8964, 5.536945, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight) (possible waypoints or random movement)
(@CGUID+468, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -741.698, -689.557, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight)
(@CGUID+469, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -732.438, -680.899, 831.9843, 1.616692, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight)
(@CGUID+470, 46304, 671, 5334, 5334, 15, 1, 290, 0, 0, 0, -740.533, -671.238, 831.9843, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Twilight (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 86302 - Unstable Twilight)
(@CGUID+471, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -481.7153, -568.0261, 894.6633, 0.6632251, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+472, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -479.9583, -497.0104, 894.6633, 5.77704, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+473, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -380.191, -568.3368, 894.6633, 2.356194, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
-- (@CGUID+474, 45848, UNKNOWN, 5334, 5334, 3, 1, 169, 0, 0, 0, -0.07075573, -0.3206706, 0.3000276, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Spray Blood (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+475, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1057.55, -582.234, 835.0943, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+476, 45676, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1171.05, -754.099, 835.1293, 1.413717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Guardian (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85413 - Pooled Blood Grow Visual)
(@CGUID+477, 44553, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1045.57, -546.745, 835.1403, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ascendant Council Target Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+478, 45687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1202.289, -790.4569, 835.0446, 1.606954, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+479, 45687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1206.924, -812.3461, 835.0457, 2.376071, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+480, 45700, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1216.109, -798.6667, 835.1148, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+481, 45699, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1210.52, -786.564, 835.1293, 5.654867, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85575 - Shadow Mending)
(@CGUID+482, 45687, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1197.031, -801.0104, 835.1247, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+483, 45699, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1211.17, -798.7205, 835.1293, 6.213372, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85575 - Shadow Mending)
(@CGUID+484, 45700, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1216.38, -807.493, 835.1293, 2.722714, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+485, 45700, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1215.52, -791.188, 835.1293, 3.438299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+486, 43324, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1162.32, -861.495, 841.5903, 1.605703, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cho'gall (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 88648 - Sit Throne, 73878 - Boss Hittin' Ya)
(@CGUID+487, 45699, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1211.81, -813.09, 835.1293, 0.8901179, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 85575 - Shadow Mending)
(@CGUID+488, 45685, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1234.34, -798.465, 840.7063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Old God Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: )
(@CGUID+489, 43735, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1009.01, -582.467, 831.9843, 6.265732, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elementium Monstrosity (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 84526 - Electric Instability)
(@CGUID+490, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -482.0035, -568.493, 894.6632, 0.8552113, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+491, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -479.9566, -496.9445, 894.6633, 5.707227, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
-- (@CGUID+493, 43888, UNKNOWN, 5334, 5334, 3, 1, 169, 0, 0, 0, -0.2370273, 0, 1.548556, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Malformation (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 82167 - Corruption: Malformation) - !!! on transport - transport template not found !!!
(@CGUID+494, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1075.951, -701.6996, 441.0677, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+495, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -994.842, -829.4514, 438.7515, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+496, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -986.4827, -725.7309, 435.9988, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+497, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1005.342, -653.0313, 439.0823, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+498, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1038.215, -766.0364, 437.7898, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+499, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1068.304, -830.5938, 452.0094, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+500, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -977.7639, -826.2118, 438.1003, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+501, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1064.823, -830.9514, 449.6106, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+502, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1043.953, -768.8438, 434.2498, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+503, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -975.8246, -726.3802, 437.1228, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+504, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1082.075, -715.1962, 438.7717, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+505, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -893.4254, -752.1441, 442.4785, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+506, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1004.731, -738.382, 438.1567, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+507, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1038.663, -773.2518, 437.2552, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+508, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -987.0104, -662.4496, 440.9741, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+509, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -947.3594, -810.3941, 437.3804, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+510, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1084.292, -724.0139, 435.1678, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+511, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -986.7014, -830.0399, 438.4399, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+512, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1024.28, -749.9132, 437.8808, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+513, 36737, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -948.092, -731.5087, 438.6763, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95824 - Lava Visual (DND))
(@CGUID+514, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -972.2396, -826.3715, 437.5063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+515, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -888.3438, -773.3871, 442.7499, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+516, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1071.87, -688.2153, 439.2569, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+517, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -960.6198, -813.5903, 438.6804, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+518, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -931.5643, -787.2882, 436.1369, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+519, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -938.7917, -761.257, 437.7297, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+520, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -957.9948, -678.2136, 434.631, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+521, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1015.533, -745.4323, 438.7277, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+522, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1043.28, -782.5555, 435.6493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+523, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -1043.372, -791.007, 435.3601, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+524, 51609, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -967.0521, -679.0868, 433.6933, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Egg Cosmetic Stalker (DND) (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+525, 48052, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -1146.2, -684.108, 459.4363, 2.129302, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Whelp Spawner (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+526, 46834, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -984.271, -776.491, 438.6763, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Controller (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+527, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -996.7344, -731.1545, 438.3048, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+528, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -998.559, -711.1545, 439.3392, 2.844887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+529, 48052, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -1139.64, -668.274, 457.4993, 2.129302, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Whelp Spawner (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+530, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -932.1215, -774.4445, 439.7818, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+531, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -999.3333, -693.7205, 440.8748, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+532, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -994.3299, -665.816, 440.4507, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+533, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -912.8768, -770.6337, 440.4303, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+534, 48052, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -1003.56, -588.097, 455.9774, 5.742133, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Whelp Spawner (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+535, 15214, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -963.3837, -750.2656, 438.6763, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Invisible Stalker (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+536, 48052, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -961.92, -592.002, 453.7503, 5.742133, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Whelp Spawner (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+537, 51629, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -895.8924, -765.8889, 442.1663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Flames (DND) (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95823 - Flames (DND))
(@CGUID+538, 48052, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -837.809, -761.042, 466.3763, 5.742133, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Whelp Spawner (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+539, 45213, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -946.5, -730.995, 437.0903, 4.13643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 89350 - Drained)
(@CGUID+540, 46835, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -988.96, -787.071, 444.2303, 0.8552113, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sinestra Channel Target (Area: The Bastion of Twilight - Difficulty: 6) (Auras: ) (possible waypoints or random movement)
(@CGUID+541, 46842, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -896.797, -766.221, 442.0393, 4.555309, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Pulsing Twilight Egg (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+542, 46842, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -993.602, -665.991, 440.4233, 4.555309, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Pulsing Twilight Egg (Area: The Bastion of Twilight - Difficulty: 6)
(@CGUID+543, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -481.8108, -568.1059, 894.6633, 0.8028514, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+544, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -380.2257, -568.257, 894.6633, 2.373648, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+545, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -480.1424, -496.7674, 894.6633, 5.585053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+546, 51551, 671, 5334, 5334, 15, 1, 169, 0, 0, 0, -382.2083, -497.5017, 894.6633, 3.822271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Portal (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 95716 - Twilight Portal Visual)
(@CGUID+550, 46277, 671, 5334, 5334, 12, 1, 169, 0, 0, 0, -1010.747, -813.0486, 438.6769, 0.6283185, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Calen (Area: The Bastion of Twilight - Difficulty: 6) (Auras: 87229 - Fiery Barrier)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+550;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+6, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+7, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+8, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+9, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+10, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+11, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+12, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+13, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+14, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+15, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+16, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+17, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+18, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+19, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+20, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+21, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+22, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+23, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+24, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+25, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+26, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+27, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+28, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+29, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+30, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+31, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+32, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+33, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+34, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+35, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+36, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+37, 0, 0, 0, 1, 0, '84568'), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) - 84568 - Phase-Twist
(@CGUID+38, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+39, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+40, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+41, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+42, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+43, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+44, 0, 0, 0, 1, 0, '84568'), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) - 84568 - Phase-Twist
(@CGUID+45, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+47, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+48, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+49, 0, 0, 0, 1, 0, '84568'), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) - 84568 - Phase-Twist
(@CGUID+50, 0, 0, 0, 1, 0, '84568'), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating) - 84568 - Phase-Twist
(@CGUID+51, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+52, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+53, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+54, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+55, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+56, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+57, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+58, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+59, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+60, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+61, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+62, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+63, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+64, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+65, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+66, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+67, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+68, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+69, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+70, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+71, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+72, 0, 0, 0, 1, 0, ''), -- Twilight Crossfire
(@CGUID+73, 0, 0, 0, 1, 0, ''), -- Twilight Dark Mender
(@CGUID+74, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+75, 0, 0, 0, 1, 0, '84849'), -- Twilight Soul Blade - 84849 - Soul Blade
(@CGUID+76, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+77, 0, 0, 0, 1, 0, ''), -- Twilight Phase-Twister
(@CGUID+78, 0, 0, 0, 1, 0, '84827'), -- Twilight Shadow Knight - 84827 - Shield Mastery
(@CGUID+79, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+80, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+81, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+82, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+83, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+84, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+85, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+86, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+87, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+88, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+89, 0, 0, 0, 1, 0, ''), -- Time Warden
(@CGUID+90, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+91, 0, 0, 0, 1, 0, ''), -- Slate Dragon
(@CGUID+92, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+93, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+94, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+95, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+96, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+97, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+98, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+99, 0, 0, 50331648, 1, 0, '83412'), -- Proto-Behemoth - 83412 - Force Flying, 84106 - Dancing Flames, 83956 - Superheated Breath
(@CGUID+100, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+101, 0, 0, 0, 1, 0, ''), -- Halfus Wyrmbreaker - 39171 - Malevolent Strikes, 83693 - Frenzied Assault, 83952 - Shadow Wrapped
(@CGUID+102, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+103, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+104, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+105, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+106, 0, 0, 0, 1, 0, ''), -- Nether Scion
(@CGUID+107, 0, 0, 0, 1, 0, ''), -- Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
(@CGUID+108, 0, 0, 0, 1, 0, ''), -- Orphaned Emerald Whelp
(@CGUID+109, 0, 0, 0, 1, 0, ''), -- Storm Rider
(@CGUID+110, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+111, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+112, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+113, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+114, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+115, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+116, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+117, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+118, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+119, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+120, 0, 0, 0, 1, 0, '83480'), -- Spike - 83480 - Spike Visual
(@CGUID+121, 0, 0, 0, 1, 0, ''), -- Chosen Warrior
(@CGUID+122, 0, 0, 0, 1, 0, '87482'), -- Cho'gall - 87482 - Periodic Player Search Trigger
(@CGUID+123, 0, 0, 0, 1, 0, ''), -- Lava Scarab
(@CGUID+124, 0, 0, 0, 1, 0, ''), -- Lava Scarab
(@CGUID+125, 0, 0, 0, 1, 0, ''), -- Chosen Seer
(@CGUID+126, 0, 0, 0, 1, 0, ''), -- Lava Scarab
(@CGUID+127, 0, 0, 0, 1, 0, ''), -- Chosen Warrior
(@CGUID+128, 0, 0, 0, 1, 0, ''), -- Lava Scarab
(@CGUID+129, 0, 0, 0, 1, 0, ''), -- Azureborne Destroyer
(@CGUID+130, 0, 0, 0, 1, 0, ''), -- Twilight Elementalist
(@CGUID+131, 0, 0, 0, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+132, 0, 0, 0, 1, 0, ''), -- Twilight Elementalist
(@CGUID+133, 0, 0, 0, 1, 0, ''), -- Lava Scarab
(@CGUID+134, 0, 0, 0, 1, 0, ''), -- Wind Breaker
(@CGUID+135, 0, 0, 0, 1, 0, ''), -- Elemental Firelord
(@CGUID+136, 0, 0, 0, 1, 0, ''), -- Earth Ravager
(@CGUID+137, 0, 0, 0, 1, 0, ''), -- Azureborne Destroyer
(@CGUID+138, 0, 0, 0, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+139, 0, 0, 0, 1, 0, ''), -- Lava Scarab
(@CGUID+140, 0, 0, 0, 1, 0, ''), -- Elemental Firelord
(@CGUID+141, 0, 0, 0, 1, 0, ''), -- Azureborne Destroyer
(@CGUID+142, 0, 0, 0, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+143, 0, 0, 0, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+144, 0, 0, 0, 1, 0, ''), -- Wind Breaker
(@CGUID+145, 0, 0, 0, 1, 0, ''), -- Earth Ravager
(@CGUID+146, 0, 0, 0, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+147, 0, 0, 0, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+148, 0, 0, 0, 1, 0, ''), -- Twilight Elementalist
(@CGUID+149, 0, 0, 0, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+150, 0, 0, 0, 1, 0, ''), -- Azureborne Destroyer
(@CGUID+151, 0, 0, 0, 1, 0, ''), -- Twilight Elementalist
(@CGUID+152, 0, 0, 0, 1, 0, ''), -- Wind Breaker
(@CGUID+153, 0, 0, 0, 1, 0, ''), -- Earth Ravager
(@CGUID+154, 0, 0, 8, 1, 0, ''), -- Chosen Seer
(@CGUID+155, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+156, 0, 0, 0, 1, 0, ''), -- Twilight Elementalist
(@CGUID+157, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+158, 0, 0, 8, 1, 0, ''), -- Wind Breaker
(@CGUID+159, 0, 0, 8, 1, 0, ''), -- Earth Ravager
(@CGUID+160, 0, 0, 8, 1, 0, ''), -- Chosen Seer
(@CGUID+161, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+162, 0, 0, 8, 1, 0, ''), -- Wind Breaker
(@CGUID+163, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+164, 0, 0, 8, 1, 0, ''), -- Chosen Seer
(@CGUID+165, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+166, 0, 0, 0, 1, 0, ''), -- Twilight Elementalist
(@CGUID+167, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+168, 0, 0, 8, 1, 0, ''), -- Elemental Firelord
(@CGUID+169, 0, 0, 8, 1, 0, ''), -- Elemental Firelord
(@CGUID+170, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+171, 0, 0, 0, 1, 0, ''), -- Azureborne Destroyer
(@CGUID+172, 0, 0, 0, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+173, 0, 0, 0, 1, 0, ''), -- Wind Breaker
(@CGUID+174, 0, 0, 0, 1, 0, ''), -- Elemental Firelord
(@CGUID+175, 0, 0, 0, 1, 0, ''), -- Earth Ravager
(@CGUID+176, 0, 0, 8, 1, 0, ''), -- Chosen Seer
(@CGUID+177, 0, 0, 8, 1, 0, ''), -- Chosen Warrior
(@CGUID+178, 0, 0, 0, 1, 0, ''), -- Elemental Firelord
(@CGUID+179, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+180, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+181, 0, 0, 8, 1, 0, ''), -- Earth Ravager
(@CGUID+182, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+183, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+184, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+185, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+186, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+187, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+188, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+189, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+190, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+191, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+192, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+193, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+194, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+195, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+196, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+197, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+198, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+199, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+200, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+201, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+202, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+203, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+204, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+205, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+206, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+207, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+208, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+209, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+210, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+211, 0, 0, 8, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+212, 0, 0, 0, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+213, 0, 0, 0, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+214, 0, 0, 8, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+215, 0, 0, 8, 1, 0, ''), -- Twilight Elementalist
(@CGUID+216, 0, 0, 8, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+217, 0, 0, 0, 1, 0, '42459'), -- Twilight Brute - 42459 - Dual Wield
(@CGUID+218, 0, 0, 8, 1, 0, '88204'), -- Azureborne Destroyer - 88204 - Arcane Infused Fists
(@CGUID+219, 0, 0, 8, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+220, 0, 0, 0, 1, 0, ''), -- Azureborne Destroyer
(@CGUID+221, 0, 0, 8, 1, 0, '88204'), -- Azureborne Destroyer - 88204 - Arcane Infused Fists
(@CGUID+222, 0, 0, 8, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+223, 0, 0, 8, 1, 0, '88204'), -- Azureborne Destroyer - 88204 - Arcane Infused Fists
(@CGUID+224, 0, 0, 8, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+225, 0, 0, 0, 1, 0, ''), -- Crimsonborne Firestarter
(@CGUID+226, 0, 0, 8, 1, 0, ''), -- Twilight Elementalist
(@CGUID+227, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+228, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+229, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+230, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+231, 0, 0, 50331648, 1, 0, '86287'), -- Valiona - 86287 - Summon Twilight Portal
(@CGUID+232, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+233, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+234, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+235, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+236, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+237, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+238, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+239, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+240, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+241, 0, 0, 0, 1, 0, '86360 88520'), -- Theralion - 86360 - Twilight Shift, 88520 - Hittin' Ya Proc Trigger
(@CGUID+242, 0, 0, 50331648, 1, 0, ''), -- Theralion Flight Target Stalker
(@CGUID+243, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+244, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+245, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+246, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+247, 0, 0, 0, 1, 0, '86360 88520'), -- Valiona - 86360 - Twilight Shift, 88520 - Hittin' Ya Proc Trigger
(@CGUID+248, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+249, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+250, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+251, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+252, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+253, 0, 0, 50331648, 1, 0, ''), -- Breath Flight Target Stalker
(@CGUID+254, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+255, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+256, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+257, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+258, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+259, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+260, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+261, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+262, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+263, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+264, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+265, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+266, 0, 0, 8, 1, 0, ''), -- Twilight Elementalist
(@CGUID+267, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+268, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+269, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+270, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+271, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+272, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+273, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+274, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+275, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+276, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+277, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+278, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+279, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+280, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+281, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+282, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+283, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+284, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+285, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+286, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+287, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+288, 0, 0, 50331648, 1, 0, ''), -- Valiona
(@CGUID+289, 0, 0, 0, 1, 0, '93373'), -- Evolved Drakonaar - 93373 - Blade Tempest
(@CGUID+290, 0, 0, 0, 1, 0, ''), -- Evolved Drakonaar
(@CGUID+291, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+292, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+293, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+294, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+295, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+296, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+297, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+298, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+299, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+300, 0, 0, 0, 1, 0, '87906'), -- Bound Zephyr - 87906 - Stormling
(@CGUID+301, 0, 0, 0, 1, 0, '93335'), -- Bound Deluge - 93335 - Icy Shroud
(@CGUID+302, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+303, 0, 0, 0, 1, 0, '93335'), -- Bound Deluge - 93335 - Icy Shroud
(@CGUID+304, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+305, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+306, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+307, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+308, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+309, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+310, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+311, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+312, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+313, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+314, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+315, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+316, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+317, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+318, 0, 0, 0, 1, 0, ''), -- Bound Rumbler
(@CGUID+319, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+320, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+321, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+322, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+323, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+324, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+325, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+326, 0, 0, 0, 1, 0, '87906'), -- Bound Zephyr - 87906 - Stormling
(@CGUID+327, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+328, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+329, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+330, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+331, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+332, 0, 0, 0, 1, 0, ''), -- Bound Rumbler
(@CGUID+333, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+334, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+335, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+336, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+337, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+338, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+339, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+340, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+341, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+342, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+343, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+344, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+345, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+346, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+347, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+348, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+349, 0, 0, 0, 1, 0, '93336'), -- Bound Inferno - 93336 - Ward of Combustion
(@CGUID+350, 0, 0, 0, 1, 0, '93336'), -- Bound Inferno - 93336 - Ward of Combustion
(@CGUID+351, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+352, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+353, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+354, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+355, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+356, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+357, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+358, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+359, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+360, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+361, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+362, 0, 0, 0, 1, 0, '82777'), -- Ignacious - 82777 - Flame Torrent
(@CGUID+363, 0, 0, 0, 1, 0, '34098'), -- Arion - 34098 - ClearAllDebuffs
(@CGUID+364, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+365, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+366, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+367, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+368, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+369, 0, 0, 50331648, 1, 0, ''), -- Old God Portal
(@CGUID+370, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+371, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+372, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+373, 0, 0, 0, 1, 0, ''), -- Feludius
(@CGUID+374, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+375, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+376, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+377, 0, 0, 0, 1, 0, '83718'), -- Terrastra - 83718 - Harden Skin
(@CGUID+378, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+379, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+380, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+381, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+382, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+383, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+384, 0, 0, 0, 1, 0, ''), -- Ascendant Council Plume Stalker - 84911 - Lava Seed
(@CGUID+385, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+386, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+387, 0, 0, 0, 1, 0, ''), -- Ascendant Council Controller
(@CGUID+388, 0, 0, 0, 1, 0, ''), -- Twilight Portal Shaper
(@CGUID+389, 0, 0, 0, 1, 0, ''), -- Twilight Portal Shaper
(@CGUID+390, 0, 0, 0, 1, 0, ''), -- Twilight Portal Shaper
(@CGUID+391, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+392, 0, 0, 0, 1, 0, '85575'), -- Twilight Shadow Mender - 85575 - Shadow Mending
(@CGUID+393, 0, 0, 0, 1, 0, ''), -- Twilight-Shifter
(@CGUID+394, 0, 0, 0, 1, 0, '85575'), -- Twilight Shadow Mender - 85575 - Shadow Mending
(@CGUID+395, 0, 0, 0, 1, 0, '85575'), -- Twilight Shadow Mender - 85575 - Shadow Mending
(@CGUID+396, 0, 0, 0, 1, 0, ''), -- Twilight-Shifter
(@CGUID+397, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+398, 0, 0, 50331648, 1, 0, '93029'), -- Valiona - 93029 - Summon Twilight Sentry
(@CGUID+399, 0, 0, 0, 1, 0, ''), -- Twilight-Shifter
(@CGUID+400, 0, 0, 0, 1, 0, '85413'), -- Faceless Guardian - 85413 - Pooled Blood Grow Visual
(@CGUID+401, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+402, 0, 0, 0, 1, 0, '46598'), -- Spray Blood - 46598 - Ride Vehicle Hardcoded
(@CGUID+403, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+404, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+405, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+406, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+407, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+408, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+409, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+410, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+411, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+412, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+413, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+414, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+415, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+416, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+417, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+418, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+419, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+420, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+421, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+422, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+423, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+424, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+425, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+426, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+427, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+428, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+429, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+430, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+431, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+432, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+433, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+434, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+435, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+436, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+437, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+438, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+439, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+440, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+441, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+442, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+443, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+444, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+445, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+446, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+447, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+448, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+449, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+450, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+451, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+452, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+453, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+454, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+455, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+456, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+457, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+458, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+459, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+460, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+461, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+462, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+463, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+464, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+465, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+466, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+467, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+468, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+469, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+470, 0, 0, 33554432, 1, 0, '86302'), -- Unstable Twilight - 86302 - Unstable Twilight
(@CGUID+471, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+472, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+473, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+474, 0, 0, 0, 1, 0, '46598'), -- Spray Blood - 46598 - Ride Vehicle Hardcoded
(@CGUID+475, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+476, 0, 0, 0, 1, 0, '85413'), -- Faceless Guardian - 85413 - Pooled Blood Grow Visual
(@CGUID+477, 0, 0, 0, 1, 0, ''), -- Ascendant Council Target Stalker
(@CGUID+478, 0, 0, 0, 1, 0, ''), -- Twilight-Shifter
(@CGUID+479, 0, 0, 0, 1, 0, ''), -- Twilight-Shifter
(@CGUID+480, 0, 0, 0, 1, 0, ''), -- Twilight Portal Shaper
(@CGUID+481, 0, 0, 0, 1, 0, '85575'), -- Twilight Shadow Mender - 85575 - Shadow Mending
(@CGUID+482, 0, 0, 0, 1, 0, ''), -- Twilight-Shifter
(@CGUID+483, 0, 0, 0, 1, 0, '85575'), -- Twilight Shadow Mender - 85575 - Shadow Mending
(@CGUID+484, 0, 0, 0, 1, 0, ''), -- Twilight Portal Shaper
(@CGUID+485, 0, 0, 0, 1, 0, ''), -- Twilight Portal Shaper
(@CGUID+486, 0, 0, 0, 1, 0, '88648 73878'), -- Cho'gall - 88648 - Sit Throne, 73878 - Boss Hittin' Ya
(@CGUID+487, 0, 0, 0, 1, 0, '85575'), -- Twilight Shadow Mender - 85575 - Shadow Mending
(@CGUID+488, 0, 0, 50331648, 1, 0, ''), -- Old God Portal
(@CGUID+489, 0, 0, 0, 1, 0, '84526'), -- Elementium Monstrosity - 84526 - Electric Instability
(@CGUID+490, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+491, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+493, 0, 0, 0, 1, 0, '82167'), -- Malformation - 82167 - Corruption: Malformation
(@CGUID+494, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+495, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+496, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+497, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+498, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+499, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+500, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+501, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+502, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+503, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+504, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+505, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+506, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+507, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+508, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+509, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+510, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+511, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+512, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+513, 0, 0, 0, 1, 0, '95824'), -- Invisible Stalker - 95824 - Lava Visual (DND)
(@CGUID+514, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+515, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+516, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+517, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+518, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+519, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+520, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+521, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+522, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+523, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+524, 0, 0, 50331648, 1, 0, ''), -- Sinestra Egg Cosmetic Stalker (DND)
(@CGUID+525, 0, 0, 0, 1, 0, ''), -- Sinestra Whelp Spawner
(@CGUID+526, 0, 0, 0, 1, 0, ''), -- Sinestra Controller
(@CGUID+527, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+528, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+529, 0, 0, 0, 1, 0, ''), -- Sinestra Whelp Spawner
(@CGUID+530, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+531, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+532, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+533, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+534, 0, 0, 0, 1, 0, ''), -- Sinestra Whelp Spawner
(@CGUID+535, 0, 0, 0, 1, 0, ''), -- Invisible Stalker
(@CGUID+536, 0, 0, 0, 1, 0, ''), -- Sinestra Whelp Spawner
(@CGUID+537, 0, 0, 0, 1, 0, '95823'), -- Flames (DND) - 95823 - Flames (DND)
(@CGUID+538, 0, 0, 0, 1, 0, ''), -- Sinestra Whelp Spawner
(@CGUID+539, 0, 0, 0, 1, 0, '89350'), -- Sinestra - 89350 - Drained
(@CGUID+540, 0, 0, 50331648, 1, 0, ''), -- Sinestra Channel Target
(@CGUID+541, 0, 0, 0, 1, 0, ''), -- Pulsing Twilight Egg
(@CGUID+542, 0, 0, 0, 1, 0, ''), -- Pulsing Twilight Egg
(@CGUID+543, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+544, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+545, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+546, 0, 0, 0, 1, 0, '95716'), -- Twilight Portal - 95716 - Twilight Portal Visual
(@CGUID+548, 0, 0, 0, 1, 0, '87654'), -- Pulsing Twilight Egg - 87654 - Twilight Carapace
(@CGUID+549, 0, 0, 0, 1, 0, '87654'), -- Pulsing Twilight Egg - 87654 - Twilight Carapace
(@CGUID+550, 0, 0, 0, 1, 0, '87229'); -- Calen - 87229 - Fiery Barrier

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+39;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 214441, 671, 5334, 5334, 15, 1, 169, 0, -576.0087, -531.2952, 891.1975, 6.252921, 0, 0, -0.01513195, 0.9998855, 7200, 255, 1, 26365), -- Instance Portal (Raid 4 Difficulties) (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+2, 203632, 671, 5334, 5334, 15, 1, 169, 0, -681.4639, -481.472, 849.821, 4.43314, 0, 0, -0.7986345, 0.6018164, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers38 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+3, 203633, 671, 5334, 5334, 15, 1, 169, 0, -697.8575, -531.371, 850.855, 4.607672, 0, 0, -0.743144, 0.6691315, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers39 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+4, 205087, 671, 5334, 5334, 15, 1, 169, 0, -346.672, -723.26, 888.106, 5.532695, 0, 0, -0.3665009, 0.9304177, 7200, 255, 1, 26365), -- Whelp Cage (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+5, 203717, 671, 5334, 5334, 15, 1, 169, 0, -494.9928, -741.5729, 789.7661, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers53 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+6, 203719, 671, 5334, 5334, 15, 1, 169, 0, -410.5504, -741.5729, 829.6565, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers55 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+7, 203718, 671, 5334, 5334, 15, 1, 169, 0, -461.9913, -741.5729, 818.1387, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers54 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+8, 203721, 671, 5334, 5334, 15, 1, 169, 0, -461.9913, -741.5729, 854.5433, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers51 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+9, 203720, 671, 5334, 5334, 15, 1, 169, 0, -410.5504, -741.5729, 866.0612, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers50 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+10, 203723, 671, 5334, 5334, 15, 1, 169, 0, -691.3508, -735.5428, 849.821, 4.73857, 0, 0, -0.6977901, 0.7163023, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers56 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+11, 203722, 671, 5334, 5334, 15, 1, 169, 0, -494.9928, -741.5729, 826.1708, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers52 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+12, 203724, 671, 5334, 5334, 15, 1, 169, 0, -691.9807, -788.062, 850.855, 4.913104, 0, 0, -0.6327047, 0.7743931, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers57 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+13, 205223, 671, 5334, 5334, 15, 1, 169, 0, -418.7024, -684.3792, 894.5637, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Halfus Exit (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+14, 205222, 671, 5334, 5334, 15, 1, 169, 0, -320.1577, -585.8331, 894.5637, 4.71239, 0, 0, -0.7071066, 0.7071069, 7200, 255, 0, 26365), -- Halfus Entrance (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+15, 205225, 671, 5334, 5334, 15, 1, 169, 0, -798.0338, -684.8916, 831.8848, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Dragon Siblings Door Exit (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+16, 205224, 671, 5334, 5334, 15, 1, 169, 0, -686.7169, -684.8929, 834.6735, 0, 0, 0, 0, 1, 7200, 255, 0, 26365), -- Dragon Siblings Door Entrance (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+17, 205088, 671, 5334, 5334, 15, 1, 169, 0, -346.672, -723.26, 888.106, 5.532695, 0, 0, -0.3665009, 0.9304177, 7200, 255, 1, 26365), -- Whelp Cage Base (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+18, 205901, 671, 5334, 5334, 15, 1, 169, 0, -1160.209, -885.417, 845.7918, 3.141593, 0, 0, -1, 0, 7200, 255, 0, 26365), -- Twilight's Hammer Throne (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+19, 205227, 671, 5334, 5334, 15, 1, 169, 0, -1108.584, -582.7432, 841.2673, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Ascendant Council Exit (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+20, 205226, 671, 5334, 5334, 15, 1, 169, 0, -908.4063, -582.7527, 831.8848, 0, 0, 0, 0, 1, 7200, 255, 0, 26365), -- Ascended Council Entrance (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+21, 205228, 671, 5334, 5334, 15, 1, 169, 0, -1162.039, -694.7305, 841.2673, 1.570796, 0, 0, 0.7071066, 0.7071069, 7200, 255, 0, 26365), -- Cho'gall Entrance (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+22, 205950, 671, 5334, 5334, 15, 1, 169, 0, -1090.319, -799.0902, 834.5636, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Twilight's Hammer Portal (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+23, 207679, 671, 5334, 5334, 15, 1, 169, 0, -1030.437, -827.9797, 440.6256, 3.141593, 0, 0, -1, 0, 7200, 255, 0, 26365), -- Doodad_GrimBatolRaid_Fire_Wall_01 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+24, 203725, 671, 5334, 5334, 15, 1, 169, 0, -308.0302, -805.9411, 887.7798, 2.076939, 0, 0, 0.8616285, 0.5075394, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers45 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+25, 203727, 671, 5334, 5334, 15, 1, 169, 0, -195.1089, -720.5842, 887.5658, 3.298687, 0, 0, -0.9969168, 0.07846643, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers44 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+26, 203728, 671, 5334, 5334, 15, 1, 169, 0, -155.5638, -714.3209, 874.7802, 3.298687, 0, 0, -0.9969168, 0.07846643, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers49 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+27, 203726, 671, 5334, 5334, 15, 1, 169, 0, -288.6194, -840.9591, 874.9942, 2.076939, 0, 0, 0.8616285, 0.5075394, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers48 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+28, 205951, 671, 5334, 5334, 15, 1, 169, 0, -1232.079, -799.0903, 834.5636, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Twilight's Hammer Portal (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+29, 205898, 671, 5334, 5334, 15, 1, 169, 0, -1162.033, -798.9507, 834.6038, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_GrimBatolRaid_TrapDoor01 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+30, 203992, 671, 5334, 5334, 15, 1, 169, 0, -1103.725, -724.1163, 468.1491, 4.913104, 0, 0, -0.6327047, 0.7743931, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers62 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+31, 203999, 671, 5334, 5334, 15, 1, 169, 0, -1011.884, -710.1545, 448.8809, 1.378809, 0, 0, 0.6360779, 0.7716249, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers70 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+32, 203991, 671, 5334, 5334, 15, 1, 169, 0, -1150.309, -700.045, 435.3874, 4.913104, 0, 0, -0.6327047, 0.7743931, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers61 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+33, 203993, 671, 5334, 5334, 15, 1, 169, 0, -1001.527, -771.3469, 468.3632, 5.000371, 0, 0, -0.5983238, 0.8012544, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers63 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+34, 203995, 671, 5334, 5334, 15, 1, 169, 0, -1083.594, -670.895, 452.7349, 5.960301, 0, 0, -0.1607418, 0.9869965, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers66 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+35, 203994, 671, 5334, 5334, 15, 1, 169, 0, -1083.594, -670.895, 422.5634, 5.960301, 0, 0, -0.1607418, 0.9869965, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers64 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+36, 203996, 671, 5334, 5334, 15, 1, 169, 0, -1011.884, -710.1545, 422.5634, 1.378809, 0, 0, 0.6360779, 0.7716249, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers67 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+37, 203998, 671, 5334, 5334, 15, 1, 169, 0, -959.235, -699.8132, 448.8809, 0.3316126, 0, 0, 0.1650476, 0.9862856, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers69 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+38, 203997, 671, 5334, 5334, 15, 1, 169, 0, -959.235, -699.8132, 422.5634, 0.3316126, 0, 0, 0.1650476, 0.9862856, 7200, 255, 1, 26365), -- Doodad_StratholmeFloatingEmbers68 (Area: The Bastion of Twilight - Difficulty: 6)
(@OGUID+39, 208045, 671, 5334, 5334, 15, 1, 169, 0, -962.9202, -749.7118, 438.5929, 4.031712, 0, 0, -0.902585, 0.4305117, 7200, 255, 1, 26365); -- Cache of the Broodmother (Area: The Bastion of Twilight - Difficulty: 6)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+39;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+2, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers38
(@OGUID+3, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers39
(@OGUID+5, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers53
(@OGUID+6, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers55
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers54
(@OGUID+8, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers51
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers50
(@OGUID+10, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers56
(@OGUID+11, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers52
(@OGUID+12, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers57
(@OGUID+13, 0, 0, 1, -0.00000004371139), -- Halfus Exit
(@OGUID+14, 0, 0, 1, -0.00000004371139), -- Halfus Entrance
(@OGUID+15, 0, 0, 1, -0.00000004371139), -- Dragon Siblings Door Exit
(@OGUID+16, 0, 0, 1, -0.00000004371139), -- Dragon Siblings Door Entrance
(@OGUID+18, 0, 0, 1, -0.00000004371139), -- Twilight's Hammer Throne
(@OGUID+19, 0, 0, 1, -0.00000004371139), -- Ascendant Council Exit
(@OGUID+20, 0, 0, 1, -0.00000004371139), -- Ascended Council Entrance
(@OGUID+21, 0, 0, 1, -0.00000004371139), -- Cho'gall Entrance
(@OGUID+22, 0, 0, 1, -0.00000004371139), -- Twilight's Hammer Portal
(@OGUID+23, 0, 0, 1, -0.00000004371139), -- Doodad_GrimBatolRaid_Fire_Wall_01
(@OGUID+24, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers45
(@OGUID+25, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers44
(@OGUID+26, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers49
(@OGUID+27, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers48
(@OGUID+28, 0, 0, 1, -0.00000004371139), -- Twilight's Hammer Portal
(@OGUID+29, 0, 0, 1, -0.00000004371139), -- Doodad_GrimBatolRaid_TrapDoor01
(@OGUID+30, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers62
(@OGUID+31, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers70
(@OGUID+32, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers61
(@OGUID+33, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers63
(@OGUID+34, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers66
(@OGUID+35, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers64
(@OGUID+36, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers67
(@OGUID+37, 0, 0, 1, -0.00000004371139), -- Doodad_StratholmeFloatingEmbers69
(@OGUID+38, 0, 0, 1, -0.00000004371139); -- Doodad_StratholmeFloatingEmbers68

DELETE FROM `creature_template_addon` WHERE `entry` IN (46277 /*46277 (Calen) - Fiery Barrier*/, 46842 /*46842 (Pulsing Twilight Egg)*/, 46835 /*46835 (Sinestra Channel Target)*/, 45213 /*45213 (Sinestra) - Drained*/, 51629 /*51629 (Flames (DND)) - Flames (DND)*/, 46834 /*46834 (Sinestra Controller)*/, 48052 /*48052 (Sinestra Whelp Spawner)*/, 51609 /*51609 (Sinestra Egg Cosmetic Stalker (DND))*/, 43888 /*43888 (Malformation) - Corruption: Malformation*/, 43735 /*43735 (Elementium Monstrosity) - Electric Instability*/, 43324 /*43324 (Cho'gall) - Sit Throne, Boss Hittin' Ya*/, 43999 /*43999 (Corruption)*/, 51551 /*51551 (Twilight Portal) - Twilight Portal Visual*/, 46304 /*46304 (Unstable Twilight) - Unstable Twilight*/, 45848 /*45848 (Spray Blood) - Ride Vehicle Hardcoded*/, 45676 /*45676 (Faceless Guardian) - Pooled Blood Grow Visual*/, 45687 /*45687 (Twilight-Shifter)*/, 45699 /*45699 (Twilight Shadow Mender) - Shadow Mending*/, 45700 /*45700 (Twilight Portal Shaper)*/, 43691 /*43691 (Ascendant Council Controller)*/, 43689 /*43689 (Terrastra) - Harden Skin*/, 43687 /*43687 (Feludius)*/, 44553 /*44553 (Ascendant Council Target Stalker)*/, 45685 /*45685 (Old God Portal)*/, 43688 /*43688 (Arion) - ClearAllDebuffs*/, 43686 /*43686 (Ignacious) - Flame Torrent*/, 49817 /*49817 (Bound Inferno) - Ward of Combustion*/, 49826 /*49826 (Bound Rumbler)*/, 49825 /*49825 (Bound Deluge) - Icy Shroud*/, 49821 /*49821 (Bound Zephyr) - Stormling*/, 49813 /*49813 (Evolved Drakonaar) - Blade Tempest*/, 45992 /*45992 (Valiona) - Twilight Shift, Hittin' Ya Proc Trigger*/, 46364 /*46364 (Theralion Flight Target Stalker)*/, 45993 /*45993 (Theralion) - Twilight Shift, Hittin' Ya Proc Trigger*/, 46296 /*46296 (Breath Flight Target Stalker)*/, 46147 /*46147 (Valiona)*/, 47161 /*47161 (Twilight Brute) - Dual Wield*/, 47150 /*47150 (Earth Ravager)*/, 47081 /*47081 (Elemental Firelord)*/, 47151 /*47151 (Wind Breaker)*/, 47086 /*47086 (Crimsonborne Firestarter)*/, 47152 /*47152 (Twilight Elementalist)*/, 47087 /*47087 (Azureborne Destroyer)*/, 46952 /*46952 (Chosen Seer)*/, 47079 /*47079 (Lava Scarab)*/, 46965 /*46965 (Cho'gall) - Periodic Player Search Trigger*/, 46951 /*46951 (Chosen Warrior)*/, 44650 /*44650 (Storm Rider)*/, 44645 /*44645 (Nether Scion)*/, 44600 /*44600 (Halfus Wyrmbreaker) - Malevolent Strikes, Frenzied Assault, Shadow Wrapped*/, 44687 /*44687 (Proto-Behemoth) - Force Flying, Dancing Flames, Superheated Breath*/, 45420 /*45420 (Ascendant Council Plume Stalker) - Lava Seed*/, 44652 /*44652 (Slate Dragon)*/, 44797 /*44797 (Time Warden)*/, 44765 /*44765 (Spike) - Spike Visual*/, 44641 /*44641 (Orphaned Emerald Whelp)*/, 45265 /*45265 (Twilight Soul Blade) - Soul Blade*/, 45267 /*45267 (Twilight Phase-Twister)*/, 45266 /*45266 (Twilight Dark Mender)*/, 45261 /*45261 (Twilight Shadow Knight) - Shield Mastery*/, 45264 /*45264 (Twilight Crossfire)*/, 46404 /*46404 (Twilight Skyterror)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(46277, 0, 0, 0, 1, 0, '87229'), -- 46277 (Calen) - Fiery Barrier
(46842, 0, 0, 0, 1, 0, ''), -- 46842 (Pulsing Twilight Egg)
(46835, 0, 0, 50331648, 1, 0, ''), -- 46835 (Sinestra Channel Target)
(45213, 0, 0, 0, 1, 0, '89350'), -- 45213 (Sinestra) - Drained
(51629, 0, 0, 0, 1, 0, '95823'), -- 51629 (Flames (DND)) - Flames (DND)
(46834, 0, 0, 0, 1, 0, ''), -- 46834 (Sinestra Controller)
(48052, 0, 0, 0, 1, 0, ''), -- 48052 (Sinestra Whelp Spawner)
(51609, 0, 0, 50331648, 1, 0, ''), -- 51609 (Sinestra Egg Cosmetic Stalker (DND))
(43888, 0, 0, 0, 1, 0, '82167'), -- 43888 (Malformation) - Corruption: Malformation
(43735, 0, 0, 0, 1, 0, '84526'), -- 43735 (Elementium Monstrosity) - Electric Instability
(43324, 0, 0, 0, 1, 0, '88648 73878'), -- 43324 (Cho'gall) - Sit Throne, Boss Hittin' Ya
(43999, 0, 0, 50331648, 1, 0, ''), -- 43999 (Corruption)
(51551, 0, 0, 0, 1, 0, '95716'), -- 51551 (Twilight Portal) - Twilight Portal Visual
(46304, 0, 0, 33554432, 1, 0, '86302'), -- 46304 (Unstable Twilight) - Unstable Twilight
(45848, 0, 0, 0, 1, 0, '46598'), -- 45848 (Spray Blood) - Ride Vehicle Hardcoded
(45676, 0, 0, 0, 1, 0, '85413'), -- 45676 (Faceless Guardian) - Pooled Blood Grow Visual
(45687, 0, 0, 0, 1, 0, ''), -- 45687 (Twilight-Shifter)
(45699, 0, 0, 0, 1, 0, '85575'), -- 45699 (Twilight Shadow Mender) - Shadow Mending
(45700, 0, 0, 0, 1, 0, ''), -- 45700 (Twilight Portal Shaper)
(43691, 0, 0, 0, 1, 0, ''), -- 43691 (Ascendant Council Controller)
(43689, 0, 0, 0, 1, 0, '83718'), -- 43689 (Terrastra) - Harden Skin
(43687, 0, 0, 0, 1, 0, ''), -- 43687 (Feludius)
(44553, 0, 0, 0, 1, 0, ''), -- 44553 (Ascendant Council Target Stalker)
(45685, 0, 0, 50331648, 1, 0, ''), -- 45685 (Old God Portal)
(43688, 0, 0, 0, 1, 0, '34098'), -- 43688 (Arion) - ClearAllDebuffs
(43686, 0, 0, 0, 1, 0, '82777'), -- 43686 (Ignacious) - Flame Torrent
(49817, 0, 0, 0, 1, 0, '93336'), -- 49817 (Bound Inferno) - Ward of Combustion
(49826, 0, 0, 0, 1, 0, ''), -- 49826 (Bound Rumbler)
(49825, 0, 0, 0, 1, 0, '93335'), -- 49825 (Bound Deluge) - Icy Shroud
(49821, 0, 0, 0, 1, 0, '87906'), -- 49821 (Bound Zephyr) - Stormling
(49813, 0, 0, 0, 1, 0, '93373'), -- 49813 (Evolved Drakonaar) - Blade Tempest
(45992, 0, 0, 0, 1, 0, '86360 88520'), -- 45992 (Valiona) - Twilight Shift, Hittin' Ya Proc Trigger
(46364, 0, 0, 50331648, 1, 0, ''), -- 46364 (Theralion Flight Target Stalker)
(45993, 0, 0, 0, 1, 0, '86360 88520'), -- 45993 (Theralion) - Twilight Shift, Hittin' Ya Proc Trigger
(46296, 0, 0, 50331648, 1, 0, ''), -- 46296 (Breath Flight Target Stalker)
(46147, 0, 0, 50331648, 1, 0, ''), -- 46147 (Valiona)
(47161, 0, 0, 0, 1, 0, '42459'), -- 47161 (Twilight Brute) - Dual Wield
(47150, 0, 0, 0, 1, 0, ''), -- 47150 (Earth Ravager)
(47081, 0, 0, 0, 1, 0, ''), -- 47081 (Elemental Firelord)
(47151, 0, 0, 0, 1, 0, ''), -- 47151 (Wind Breaker)
(47086, 0, 0, 0, 1, 0, ''), -- 47086 (Crimsonborne Firestarter)
(47152, 0, 0, 0, 1, 0, ''), -- 47152 (Twilight Elementalist)
(47087, 0, 0, 0, 1, 0, ''), -- 47087 (Azureborne Destroyer)
(46952, 0, 0, 0, 1, 0, ''), -- 46952 (Chosen Seer)
(47079, 0, 0, 0, 1, 0, ''), -- 47079 (Lava Scarab)
(46965, 0, 0, 0, 1, 0, '87482'), -- 46965 (Cho'gall) - Periodic Player Search Trigger
(46951, 0, 0, 0, 1, 0, ''), -- 46951 (Chosen Warrior)
(44650, 0, 0, 0, 1, 0, ''), -- 44650 (Storm Rider)
(44645, 0, 0, 0, 1, 0, ''), -- 44645 (Nether Scion)
(44600, 0, 0, 0, 1, 0, '39171 83693 83952'), -- 44600 (Halfus Wyrmbreaker) - Malevolent Strikes, Frenzied Assault, Shadow Wrapped
(44687, 0, 0, 50331648, 1, 0, '83412 84106 83956'), -- 44687 (Proto-Behemoth) - Force Flying, Dancing Flames, Superheated Breath
(45420, 0, 0, 0, 1, 0, ''), -- 45420 (Ascendant Council Plume Stalker) - Lava Seed
(44652, 0, 0, 0, 1, 0, ''), -- 44652 (Slate Dragon)
(44797, 0, 0, 0, 1, 0, ''), -- 44797 (Time Warden)
(44765, 0, 0, 0, 1, 0, '83480'), -- 44765 (Spike) - Spike Visual
(44641, 0, 0, 0, 1, 0, ''), -- 44641 (Orphaned Emerald Whelp)
(45265, 0, 0, 0, 1, 0, '84849'), -- 45265 (Twilight Soul Blade) - Soul Blade
(45267, 0, 0, 0, 1, 0, ''), -- 45267 (Twilight Phase-Twister)
(45266, 0, 0, 0, 1, 0, ''), -- 45266 (Twilight Dark Mender)
(45261, 0, 0, 0, 1, 0, '84827'), -- 45261 (Twilight Shadow Knight) - Shield Mastery
(45264, 0, 0, 0, 1, 0, ''), -- 45264 (Twilight Crossfire)
(46404, 0, 0, 50397184, 1, 0, ''); -- 46404 (Twilight Skyterror)

UPDATE `creature_model_info` SET `BoundingRadius`=3.829555 WHERE `DisplayID`=27710;
UPDATE `creature_model_info` SET `BoundingRadius`=5.095089 WHERE `DisplayID`=34576;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3542514, `CombatReach`=0.5 WHERE `DisplayID`=34683;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6324, `CombatReach`=2.55, `Gender`=0 WHERE `DisplayID`=34627;
UPDATE `creature_model_info` SET `BoundingRadius`=2.114326 WHERE `DisplayID`=37194;
UPDATE `creature_model_info` SET `BoundingRadius`=2.190339 WHERE `DisplayID`=36757;
UPDATE `creature_model_info` SET `BoundingRadius`=2.194608 WHERE `DisplayID`=37193;
UPDATE `creature_model_info` SET `BoundingRadius`=2.145878 WHERE `DisplayID`=37195;
UPDATE `creature_model_info` SET `BoundingRadius`=8.428684 WHERE `DisplayID`=36633;
UPDATE `creature_model_info` SET `BoundingRadius`=2.503245 WHERE `DisplayID`=35432;
UPDATE `creature_model_info` SET `BoundingRadius`=1.81228 WHERE `DisplayID`=35166;
UPDATE `creature_model_info` SET `BoundingRadius`=1.839324 WHERE `DisplayID`=35170;
UPDATE `creature_model_info` SET `BoundingRadius`=2.412815 WHERE `DisplayID`=31514;
UPDATE `creature_model_info` SET `BoundingRadius`=2.578788 WHERE `DisplayID`=31499;
UPDATE `creature_model_info` SET `BoundingRadius`=4.245908 WHERE `DisplayID`=35367;
UPDATE `creature_model_info` SET `BoundingRadius`=7.385158 WHERE `DisplayID`=34015;
UPDATE `creature_model_info` SET `BoundingRadius`=6.44934 WHERE `DisplayID`=34021;
UPDATE `creature_model_info` SET `BoundingRadius`=20.39789 WHERE `DisplayID`=28949;
UPDATE `creature_model_info` SET `BoundingRadius`=7.692793 WHERE `DisplayID`=34023;
UPDATE `creature_model_info` SET `BoundingRadius`=6.580666 WHERE `DisplayID`=34025;
UPDATE `creature_model_info` SET `BoundingRadius`=1.391193 WHERE `DisplayID`=34020;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3 WHERE `DisplayID`=16925;

UPDATE `creature_equip_template` SET `ItemID1`=60812 WHERE (`CreatureID`=44600 AND `ID`=1); -- Halfus Wyrmbreaker
UPDATE `creature_equip_template` SET `ItemID2`=0 WHERE (`CreatureID`=45267 AND `ID`=1); -- Twilight Phase-Twister

-- Template Updates

-- Generic Triggers and flying creatures
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (42098, 46296, 45685, 44687, 46835);
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry` IN (42098, 44765, 46304, 46296, 45420, 45685, 46834, 51629, 51609, 46835);

-- Slate Dragon
UPDATE `creature_template` SET `npcflag`= 1, `gossip_menu_id`= 12078 WHERE `entry`= 44652;

-- Sinestra
UPDATE `creature_template` SET `InhabitType`= 11 WHERE `entry`= 45213;

-- Make several gameobjects not selectable
UPDATE `gameobject_template_addon` SET `flags`= 16 WHERE `entry` IN (205901, 205223, 205222, 205224, 205225, 205088, 205226, 205227, 205228, 205950, 205951, 205087);

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=11884 AND `TextID`=16952) OR (`MenuID`=12079 AND `TextID`=16955) OR (`MenuID`=12076 AND `TextID`=16665) OR (`MenuID`=12078 AND `TextID`=16954) OR (`MenuID`=12077 AND `TextID`=16953);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(11884, 16952), -- 44641 (Orphaned Emerald Whelp)
(12079, 16955), -- 44650 (Storm Rider)
(12076, 16665), -- 44797 (Time Warden)
(12078, 16954), -- 44652 (Slate Dragon)
(12077, 16953); -- 44645 (Nether Scion)

-- Creature Twilight Phase-Twister 45267 SAI
SET @ENTRY := 45267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 8000, 8000, 0, 0, 11, 84737, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Twist Phase (84737) on Self // ");

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 84737 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 84737, 0, 0, 31, 0, 3, 42098, 0, 0, 0, '', 'Twist Phase - Target Invisible Stalker');
