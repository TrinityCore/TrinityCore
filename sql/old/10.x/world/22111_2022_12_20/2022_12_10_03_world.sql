SET @CGUID := 460930;
SET @OGUID := 395737;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89734, 974, 5861, 5904, '0', 0, 0, 0, 0, -4409.21337890625, 6366.12060546875, 13.50523948669433593, 2.654129743576049804, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Rocketeer (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179281 - Powerup Visual - Pitstop - Rocketeer, Mount Advanced)
(@CGUID+1, 89736, 974, 5861, 5904, '0', 0, 0, 0, 0, -4425.7724609375, 6373.7822265625, 13.50523948669433593, 5.815080165863037109, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Wanderluster (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179273 - Powerup Visual - Pitstop - Wanderluster, Mount Advanced)
(@CGUID+2, 90148, 974, 5861, 5904, '0', 0, 0, 0, 0, -4409.4931640625, 6374.8349609375, 13.50523948669433593, 3.375472068786621093, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Racing Strider (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179749 - Powerup Visual - Pitstop - Tallstrider Advanced)
(@CGUID+3, 89734, 974, 5861, 5904, '0', 0, 0, 0, 0, -4408.5068359375, 6273.9931640625, 13.89466476440429687, 3.053420782089233398, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Rocketeer (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179281 - Powerup Visual - Pitstop - Rocketeer, Mount Advanced)
(@CGUID+4, 89736, 974, 5861, 5904, '0', 0, 0, 0, 0, -4424.27587890625, 6273.73193359375, 13.89584636688232421, 0.117442205548286437, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Wanderluster (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179273 - Powerup Visual - Pitstop - Wanderluster, Mount Advanced)
(@CGUID+5, 89732, 974, 5861, 5904, '0', 0, 0, 0, 0, -4425.32470703125, 6365.3203125, 13.50523948669433593, 6.226679325103759765, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Powermonger (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179277 - Powerup Visual - Pitstop - Powermonger, Mount Advanced)
(@CGUID+6, 89732, 974, 5861, 5904, '0', 0, 0, 0, 0, -4424.0693359375, 6265.54150390625, 13.94834709167480468, 6.237830638885498046, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Powermonger (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179277 - Powerup Visual - Pitstop - Powermonger, Mount Advanced)
(@CGUID+7, 90148, 974, 5861, 5904, '0', 0, 0, 0, 0, -4408.14404296875, 6265.77783203125, 13.94806671142578125, 2.210808277130126953, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Racing Strider (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179749 - Powerup Visual - Pitstop - Tallstrider Advanced)
(@CGUID+8, 74056, 974, 5861, 5904, '0', 0, 0, 0, 1, -4417.673828125, 6358.51025390625, 15.52252388000488281, 0.544945597648620605, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Malle Earnhard (Area: Darkmoon Boardwalk - Difficulty: 0)
(@CGUID+9, 90473, 974, 5861, 5904, '0', 0, 0, 0, 1, -4408.95166015625, 6279.205078125, 14.6503143310546875, 3.060221433639526367, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Patti Earnhard (Area: Darkmoon Boardwalk - Difficulty: 0)
(@CGUID+10, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.21533203125, 6274.2041015625, 13.71255874633789062, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73813 - Citizen Costume)
(@CGUID+11, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4399.6806640625, 6414.7041015625, 15.16792106628417968, 2.922005414962768554, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 71084 - Citizen Costume)
(@CGUID+12, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4401.96533203125, 6391.11376953125, 14.53761482238769531, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73809 - Citizen Costume)
(@CGUID+13, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4402.31591796875, 6415.52685546875, 13.68542671203613281, 2.757519960403442382, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73809 - Citizen Costume)
(@CGUID+14, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4401.83154296875, 6413.43603515625, 14.16103744506835937, 2.757519960403442382, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73809 - Citizen Costume)
(@CGUID+15, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4401.15625, 6389.8837890625, 14.98537540435791015, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73104 - Citizen Costume)
(@CGUID+16, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4402.30908203125, 6417.27587890625, 13.71753120422363281, 2.922005414962768554, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73815 - Citizen Costume)
(@CGUID+17, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4402.32275390625, 6400.66650390625, 13.796844482421875, 3.25595402717590332, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+18, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4402.392578125, 6403.033203125, 13.79646587371826171, 3.25595402717590332, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73813 - Citizen Costume)
(@CGUID+19, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4397.3994140625, 6273.0634765625, 15.19376468658447265, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+20, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4401.72412109375, 6399.640625, 14.24470043182373046, 3.09146881103515625, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+21, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4399.68408203125, 6400.79345703125, 15.25401592254638671, 3.09146881103515625, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73811 - Citizen Costume)
(@CGUID+22, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.18603515625, 6388.6630859375, 15.59764766693115234, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+23, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.251953125, 6276.4609375, 13.76355171203613281, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 71084 - Citizen Costume)
(@CGUID+24, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.173828125, 6390.69091796875, 15.73886775970458984, 3.25329756736755371, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+25, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4401.265625, 6386.76025390625, 14.97508716583251953, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73809 - Citizen Costume)
(@CGUID+26, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4399.70166015625, 6399.2900390625, 15.23775005340576171, 2.922005414962768554, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+27, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.61279296875, 6416.22119140625, 14.66377449035644531, 2.757519960403442382, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+28, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4402.4306640625, 6413.93408203125, 13.73136711120605468, 2.757519960403442382, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+29, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.85595703125, 6403.986328125, 14.89526844024658203, 3.281445980072021484, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73813 - Citizen Costume)
(@CGUID+30, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4398.36279296875, 6275.3212890625, 14.73030757904052734, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73813 - Citizen Costume)
(@CGUID+31, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4401.50537109375, 6403.73291015625, 14.34080696105957031, 3.25595402717590332, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73815 - Citizen Costume)
(@CGUID+32, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4399.19775390625, 6272.111328125, 14.19003677368164062, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+33, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4402.16845703125, 6387.96875, 14.41534709930419921, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73811 - Citizen Costume)
(@CGUID+34, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.30029296875, 6417.9599609375, 14.81303882598876953, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73813 - Citizen Costume)
(@CGUID+35, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.99462890625, 6413.72900390625, 14.62116336822509765, 2.922005414962768554, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+36, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.3369140625, 6263.296875, 13.77440643310546875, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73809 - Citizen Costume)
(@CGUID+37, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4400.267578125, 6261.923828125, 13.73682117462158203, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+38, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4398.5087890625, 6262.62060546875, 14.76891231536865234, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+39, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4397.73779296875, 6259.017578125, 15.20176887512207031, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+40, 55347, 974, 5861, 5904, '0', 0, 0, 0, 0, -4399.54345703125, 6260.80908203125, 14.18574047088623046, 3.253297328948974609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+41, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4399.5537109375, 6248.595703125, 14.33590888977050781, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+42, 55348, 974, 5861, 5904, '0', 0, 0, 0, 0, -4398.71533203125, 6244.9443359375, 14.69170475006103515, 2.947497129440307617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 73814 - Citizen Costume)
(@CGUID+43, 74388, 974, 5861, 5904, '0', 0, 0, 0, 0, -4408.34716796875, 6385.9150390625, 13.50523948669433593, 4.725545406341552734, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Camp Post (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State)
(@CGUID+44, 74388, 974, 5861, 5904, '0', 0, 0, 0, 0, -4426.76904296875, 6385.328125, 13.50523948669433593, 4.653382778167724609, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Camp Post (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State)
(@CGUID+45, 74388, 974, 5861, 5904, '0', 0, 0, 0, 0, -4406.751953125, 6252.34814453125, 13.97506141662597656, 4.602067947387695312, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Camp Post (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State)
(@CGUID+46, 74388, 974, 5861, 5904, '0', 0, 0, 0, 0, -4425.40283203125, 6252.244140625, 13.97578239440917968, 1.542731404304504394, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Camp Post (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State)
(@CGUID+47, 74333, 974, 5861, 5904, '0', 0, 0, 0, 0, -4417.828125, 6383.49462890625, 13.50523948669433593, 4.797967910766601562, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Arch, Start Race (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 149665 - Powerup - Area Trigger - Start Arch)
(@CGUID+48, 74333, 974, 5861, 5904, '0', 0, 0, 0, 0, -4416.6181640625, 6256.220703125, 13.97569561004638671, 4.707498550415039062, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Arch, Start Race (Area: Darkmoon Boardwalk - Difficulty: 0) (Auras: 149665 - Powerup - Area Trigger - Start Arch)
(@CGUID+49, 93835, 974, 5861, 5904, '0', 0, 0, 0, 0, -4419.85400390625, 6296.8818359375, 13.869903564453125, 3.924604654312133789, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Thorina (Area: Darkmoon Boardwalk - Difficulty: 0)
(@CGUID+50, 55103, 974, 5861, 5904, '0', 0, 0, 0, 0, -4423.1630859375, 6293.07470703125, 13.86382865905761718, 6.247150897979736328, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Galissa Sundew (Area: Darkmoon Boardwalk - Difficulty: 0)
(@CGUID+51, 93808, 974, 5861, 5904, '0', 0, 0, 0, 0, -4426.17529296875, 6292.275390625, 14.41958045959472656, 0.013728062622249126, 120, 0, 0, 27, 0, 0, 0, 0, 0, 46924), -- Ghostshell Crab (Area: Darkmoon Boardwalk - Difficulty: 0)
(@CGUID+52, 93804, 974, 5861, 5904, '0', 0, 0, 0, 0, -4422.9287109375, 6290.00244140625, 13.94439888000488281, 0.404267847537994384, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924); -- Costumed Entertainer (Area: Darkmoon Boardwalk - Difficulty: 0)

-- Delete old Portals
DELETE FROM `gameobject` WHERE `guid` IN (213395, 212440);

-- Move Tatia Brine
UPDATE `creature` SET `position_x`= -4423.034, `position_y`= 6295.53125, `position_z`= 13.86851692199707031, `orientation`= 6.217611 WHERE `guid` = 290561;

-- Move Steven Stagnaro
UPDATE `creature` SET `position_x`= -4419.8110, `position_y`= 6289.228, `position_z`= 13.98196, `orientation`= 0.709314 WHERE `guid` = 290562;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 974, 5861, 5904, '0', 0, 0, -4408.60400390625, 6278.79541015625, 13.84513568878173828, 4.70208597183227539, 0, 0, -0.7107400894165039, 0.70345473289489746, 120, 255, 1, 46924), -- Haystack 01 (Area: Darkmoon Boardwalk - Difficulty: 0)
(@OGUID+1, 179968, 974, 5861, 5904, '0', 0, 0, -4408.74658203125, 6279.57666015625, 13.87330436706542968, 1.576887726783752441, 0, 0, 0.709257125854492187, 0.704949855804443359, 120, 255, 1, 46924), -- Haystack 01 (Area: Darkmoon Boardwalk - Difficulty: 0)
(@OGUID+2, 216667, 974, 5861, 5904, '0', 0, 0, -4447.79150390625, 6329.22900390625, 13.26463031768798828, 3.09826970100402832, 0, 0, 0.999765396118164062, 0.021659828722476959, 120, 255, 1, 46924); -- Portal Back (Area: Darkmoon Boardwalk - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179281'), -- Rocketeer - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179281 - Powerup Visual - Pitstop - Rocketeer, Mount Advanced
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179273'), -- Wanderluster - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179273 - Powerup Visual - Pitstop - Wanderluster, Mount Advanced
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179749'), -- Racing Strider - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179749 - Powerup Visual - Pitstop - Tallstrider Advanced
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179281'), -- Rocketeer - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179281 - Powerup Visual - Pitstop - Rocketeer, Mount Advanced
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179273'), -- Wanderluster - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179273 - Powerup Visual - Pitstop - Wanderluster, Mount Advanced
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179277'), -- Powermonger - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179277 - Powerup Visual - Pitstop - Powermonger, Mount Advanced
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179277'), -- Powermonger - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179277 - Powerup Visual - Pitstop - Powermonger, Mount Advanced
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, 0, '152760 151025 179749'), -- Racing Strider - 152760 - Powerup - Area Trigger - Pitstop - OnSpawn, 151025 - Powerup - Area Trigger - Generic - Load Data, 179749 - Powerup Visual - Pitstop - Tallstrider Advanced
(@CGUID+10, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73813'), -- Horde Citizen - 73813 - Citizen Costume
(@CGUID+11, 0, 0, 1, 1, 0, 0, 0, 0, 0, '71084'), -- Horde Citizen - 71084 - Citizen Costume
(@CGUID+12, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73809'), -- Alliance Citizen - 73809 - Citizen Costume
(@CGUID+13, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73809'), -- Alliance Citizen - 73809 - Citizen Costume
(@CGUID+14, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73809'), -- Alliance Citizen - 73809 - Citizen Costume
(@CGUID+15, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73104'), -- Alliance Citizen - 73104 - Citizen Costume
(@CGUID+16, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73815'), -- Horde Citizen - 73815 - Citizen Costume
(@CGUID+17, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+18, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73813'), -- Horde Citizen - 73813 - Citizen Costume
(@CGUID+19, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+20, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+21, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73811'), -- Alliance Citizen - 73811 - Citizen Costume
(@CGUID+22, 0, 0, 1, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+23, 0, 0, 1, 1, 0, 0, 0, 0, 0, '71084'), -- Horde Citizen - 71084 - Citizen Costume
(@CGUID+24, 0, 0, 1, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+25, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73809'), -- Alliance Citizen - 73809 - Citizen Costume
(@CGUID+26, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+27, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+28, 0, 0, 1, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+29, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73813'), -- Horde Citizen - 73813 - Citizen Costume
(@CGUID+30, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73813'), -- Horde Citizen - 73813 - Citizen Costume
(@CGUID+31, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73815'), -- Horde Citizen - 73815 - Citizen Costume
(@CGUID+32, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+33, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73811'), -- Alliance Citizen - 73811 - Citizen Costume
(@CGUID+34, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73813'), -- Horde Citizen - 73813 - Citizen Costume
(@CGUID+35, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+36, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73809'), -- Alliance Citizen - 73809 - Citizen Costume
(@CGUID+37, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+38, 0, 0, 1, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+39, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+40, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+41, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+42, 0, 0, 1, 1, 0, 0, 0, 0, 0, '73814'), -- Horde Citizen - 73814 - Citizen Costume
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, 4, '149746 151532'), -- Camp Post - 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, 4, '149746 151532'), -- Camp Post - 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, 4, '149746 151532'), -- Camp Post - 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, 4, '149746 151532'), -- Camp Post - 149746 - Powerup - Area Trigger - Camp, 151532 - Aura Very Tall - Yellow - State
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, 3, '149665'), -- Arch, Start Race - 149665 - Powerup - Area Trigger - Start Arch
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, 3, '149665'), -- Arch, Start Race - 149665 - Powerup - Area Trigger - Start Arch
(@CGUID+49, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Thorina
