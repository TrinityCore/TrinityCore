SET @CGUID := 10006134;
SET @OGUID := 10001487;
SET @NPCTEXTID := 600098;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 99.7100677490234375, 523.96356201171875, -0.26998597383499145, 4.297485828399658203, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -23.8131484985351562, 534.3463134765625, 17.81618499755859375, 4.9728851318359375, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+2, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 39.21527862548828125, 427.57464599609375, 0.233369052410125732, 0.68871849775314331, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+3, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -15.8683586120605468, 508.053863525390625, 5.940677642822265625, 1.515475630760192871, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+4, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -21.4359760284423828, 492.35430908203125, 3.428853511810302734, 2.994193553924560546, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+5, 233330, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 70.3663177490234375, 480.529510498046875, 0.083389706909656524, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bilgewater Local (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+6, 233156, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 28.17013931274414062, 431.763885498046875, 0.146245524287223815, 0.700004458427429199, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Gear-Grinder (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+7, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 7.920337677001953125, 543.11541748046875, 5.895499706268310546, 3.599936723709106445, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+8, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 64.9312896728515625, 532.05584716796875, 3.470838546752929687, 1.159959316253662109, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+9, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 115.6302108764648437, 520.6805419921875, 0.072901815176010131, 4.297485828399658203, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+10, 234569, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 15.15625, 464.28472900390625, 1.660245537757873535, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- [DNT] Crash Target (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 473682 - [DNT] Cosmetic Object, 473733 - [DNT] Tool Rack Visual)
(@CGUID+11, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 25.31179428100585937, 558.095703125, 3.428853273391723632, 2.419584989547729492, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+12, 235621, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -12.3402776718139648, 528.2742919921875, 17.90953254699707031, 5.013825893402099609, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Ando the Gat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+13, 238781, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 39.48611068725585937, 490.90625, 9.7557830810546875, 2.212239742279052734, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Sound Stalker - 11.1 Amb - Undermine - Traffic Sound Stalker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 1221822 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Traffic Flyby - High, 1221953 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Traffic Flyby - Mid, 1221955 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Traffic Flyby - Low, 1221960 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Car Alarm, 1222253 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Distant Horns, 1222258 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Tire Skid, 1222826 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Engine Rev, 1223986 - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Rocket Fly By)
(@CGUID+14, 235620, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -14.296875, 528.14581298828125, 17.90953254699707031, 4.798557758331298828, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Sando the Rat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+15, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 13.10243034362792968, 448.848968505859375, 0.39249730110168457, 0.629299640655517578, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+16, 233330, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 61.61284637451171875, 480.786468505859375, 0.596742212772369384, 5.438474178314208984, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bilgewater Local (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+17, 233156, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 17.90277862548828125, 440.015625, 0.082438156008720397, 0.536886870861053466, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Gear-Grinder (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+18, 235622, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -13.9479169845581054, 511.296875, 17.90952873229980468, 1.648220777511596679, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mabel Hexkey (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+19, 235617, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 14.59895801544189453, 548.171875, 14.57619667053222656, 3.984224319458007812, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Paula Piranha (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+20, 235879, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -16.6423606872558593, 514.11114501953125, 17.90952873229980468, 0.995788931846618652, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Grit Alphadrill (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+21, 235616, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 9.668402671813964843, 544.67364501953125, 5.99286508560180664, 4.114192008972167968, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mickey Junkfeast (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+22, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -10.365234375, 505.193359375, 5.978585243225097656, 3.303944349288940429, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+23, 235878, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -18.026041030883789, 515.498291015625, 17.9095306396484375, 0.660962998867034912, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- CHUCK-135 (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+24, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 9.952626228332519531, 539.4654541015625, 5.89550018310546875, 0.216227903962135314, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+25, 233957, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -15.5520830154418945, 532.296875, 5.965087890625, 5.337119579315185546, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Hotel Guest (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+26, 234569, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 65.1649322509765625, 517.13018798828125, 0.191255927085876464, 4.697664260864257812, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- [DNT] Crash Target (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 473682 - [DNT] Cosmetic Object, 473732 - [DNT] Tool Rack Visual)
(@CGUID+27, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -36.2610321044921875, 550.0423583984375, 3.428853273391723632, 4.348265647888183593, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+28, 235626, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -24.0347232818603515, 537.53643798828125, 17.90953254699707031, 5.693109512329101562, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Lynndy Leatherbolts (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+29, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -24.0087776184082031, 536.4989013671875, 17.81618309020996093, 0.979034900665283203, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+30, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 6.001578330993652343, 542.17083740234375, 5.900990009307861328, 3.607818603515625, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+31, 233957, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -14.9704866409301757, 536.39581298828125, 5.965087890625, 0.797743499279022216, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Hotel Guest (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+32, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -49.6022415161132812, 526.4151611328125, 4.046823501586914062, 2.218998193740844726, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+33, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 2.856419801712036132, 570.27764892578125, 6.692375659942626953, 1.831820964813232421, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+34, 236332, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 1, 2.711805582046508789, 519.4757080078125, 6.004512786865234375, 2.153945446014404296, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Lolo Gumbat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+35, 234044, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -77.1285247802734375, 457.92626953125, 1.096628427505493164, 5.357714653015136718, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Scrungly Rat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 235613, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 13.26388931274414062, 531.0242919921875, 17.90953254699707031, 6.136590957641601562, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Fawkes Peppergear (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+37, 233957, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 1.684027791023254394, 517.592041015625, 5.96922159194946289, 3.106899023056030273, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Hotel Guest (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+38, 235612, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -24.9704856872558593, 530.39239501953125, 17.90953254699707031, 0.697884559631347656, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Scramblington Spoonfork (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+39, 233330, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 63.0555572509765625, 471.34375, 0.193578436970710754, 5.438474178314208984, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bilgewater Local (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+40, 235615, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -19.2829856872558593, 516.81427001953125, 17.90952873229980468, 0.507622480392456054, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Lathe Faceter (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+41, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -6.66419124603271484, 475.964324951171875, 3.428856849670410156, 2.583713054656982421, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+42, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 84.333404541015625, 534.16729736328125, 2.482617855072021484, 4.666055679321289062, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 233959, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 1, 15.421875, 520.83160400390625, 6.02064371109008789, 3.290914058685302734, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Monte Gazlowe (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+44, 235614, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -2.29166674613952636, 546.78643798828125, 17.90953254699707031, 1.756449103355407714, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Rubbel (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+45, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 107.0034713745117187, 523.34893798828125, 0.072901815176010131, 4.494287967681884765, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+46, 233958, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -9.66145801544189453, 522.3819580078125, 6.520642757415771484, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Paks Topskimmer (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+47, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -34.6123085021972656, 551.7874755859375, 3.428853511810302734, 2.830466270446777343, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+48, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 9.139039993286132812, 561.4635009765625, 5.945687770843505859, 4.510956764221191406, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+49, 233957, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 4.854166507720947265, 519.295166015625, 5.965089797973632812, 1.330271840095520019, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Hotel Guest (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+50, 237587, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 82.79340362548828125, 458.26910400390625, 16.36771774291992187, 2.287212133407592773, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechanized Peacekeeper (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 474480 - Unstable Mech)
(@CGUID+51, 234044, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 10.416015625, 427.083984375, 0.02427019365131855, 0.630211234092712402, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Scrungly Rat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 233330, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 62.17882156372070312, 464.595489501953125, 0.088541671633720397, 5.438474178314208984, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bilgewater Local (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+53, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 135.1354217529296875, 466.489593505859375, -2.21085476875305175, 2.675786495208740234, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+54, 225821, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 100.1200027465820312, 633.35601806640625, 13.785400390625, 3.996803998947143554, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- The Geargrinder (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 461000 - [DNT] Energy Override, 466615 - Protective Plating)
(@CGUID+55, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -27.479166030883789, 522.81427001953125, 6.03228759765625, 5.504944801330566406, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+56, 228662, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 137.0520782470703125, 474.786468505859375, -2.44974899291992187, 3.270444869995117187, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geargrinder Biker (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+57, 233960, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 13.26215267181396484, 519.0694580078125, 6.02064371109008789, 1.832186579704284667, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Grimla Fizzlecrank (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+58, 233957, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -12.6666669845581054, 533.234375, 5.965087890625, 0.119663283228874206, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Hotel Guest (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+59, 233963, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 1, 12.14409732818603515, 516.58331298828125, 6.02064371109008789, 1.465305805206298828, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Baron Revilgaz (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+60, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 14.583984375, 585.416015625, 3.428853273391723632, 5.933590888977050781, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+61, 231824, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 16.328125, 514.66668701171875, 17.94735527038574218, 2.629772424697875976, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Kari Bridgeblaster (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+62, 233962, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 10.59895801544189453, 518.7430419921875, 6.020607948303222656, 1.099921703338623046, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Marin Noggenfogger (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+63, 234044, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -50.015625, 451.0069580078125, 1.294481754302978515, 5.966217517852783203, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Scrungly Rat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, 13.20229148864746093, 574.5489501953125, 4.040043354034423828, 5.014180183410644531, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+65, 233330, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 53.86632156372070312, 463.807281494140625, 0.118744626641273498, 5.438474178314208984, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bilgewater Local (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+66, 231323, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -20.649240493774414, 570.67169189453125, 3.428853273391723632, 2.068634033203125, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Nibbler (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+67, 231318, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -26.0795955657958984, 532.3770751953125, 17.81567764282226562, 4.718881607055664062, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Hungry Croach (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@CGUID+68, 229180, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 1, 98.02777862548828125, 468.732635498046875, 16.33657264709472656, 2.974857330322265625, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Gunner (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+69, 229180, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 1, 71.42038726806640625, 441.4932861328125, 19.83173942565917968, 2.37111520767211914, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Gunner (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+70, 229180, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 1, 80.325103759765625, 446.472137451171875, 19.82956123352050781, 2.615826845169067382, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Gunner (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+71, 229180, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 1, 91.56621551513671875, 460.71710205078125, 19.82996940612792968, 2.196915149688720703, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Gunner (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+72, 234044, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0, 0, -113.208358764648437, 481.442596435546875, 1.776231050491333007, 3.261139631271362304, 604800, 3, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Scrungly Rat (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 234569, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 51.02951431274414062, 427.552093505859375, 0.01752810925245285, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- [DNT] Crash Target (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1 (Auras: 473682 - [DNT] Cosmetic Object, 473735 - [DNT] Tool Rack Visual)
(@CGUID+74, 234569, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 130.3802032470703125, 506.564239501953125, 0.143161669373512268, 3.320445775985717773, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- [DNT] Crash Target (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 473682 - [DNT] Cosmetic Object, 473723 - [DNT] Tool Rack Visual)
(@CGUID+75, 234569, 2769, 15522, 15522, '14,15,16,17,220', 0, 0, 0, 0, 105.9375, 435.317718505859375, 0.09574032574892044, 0.860037505626678466, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 59570); -- [DNT] Crash Target (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 473682 - [DNT] Cosmetic Object, 473734 - [DNT] Tool Rack Visual)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '471891'), -- Bilgewater Local - 471891 - Mod Scale 95-105%
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '471891'), -- Bilgewater Local - 471891 - Mod Scale 95-105%
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Hotel Guest
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Hotel Guest
(@CGUID+34, 0, 0, 0, 0, 0, 2, 0, 214, 0, 0, 0, 0, ''), -- Lolo Gumbat
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Hotel Guest
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '471891'), -- Bilgewater Local - 471891 - Mod Scale 95-105%
(@CGUID+43, 0, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 4, ''), -- Monte Gazlowe
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Paks Topskimmer
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Hotel Guest
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '474480'), -- Mechanized Peacekeeper - 474480 - Unstable Mech
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '471891'), -- Bilgewater Local - 471891 - Mod Scale 95-105%
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 4, ''), -- Grimla Fizzlecrank
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Hotel Guest
(@CGUID+59, 0, 0, 0, 0, 0, 0, 0, 333, 0, 0, 0, 4, ''), -- Baron Revilgaz
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Marin Noggenfogger
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, '471891'), -- Bilgewater Local - 471891 - Mod Scale 95-105%
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 214, 0, 0, 0, 0, '471891'), -- Darkfuse Gunner - 471891 - Mod Scale 95-105%
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 214, 0, 0, 0, 0, '471891'), -- Darkfuse Gunner - 471891 - Mod Scale 95-105%
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 214, 0, 0, 0, 0, '471891'), -- Darkfuse Gunner - 471891 - Mod Scale 95-105%
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 214, 0, 0, 0, 0, '471891'); -- Darkfuse Gunner - 471891 - Mod Scale 95-105%

DELETE FROM `creature_template_addon` WHERE `entry` IN (237599, 229180, 234569, 236332, 237587, 225821, 225822, 228881, 233962, 233963, 233960, 233330, 233959, 238781, 228665, 228662, 230853);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(237599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'), -- 237599 (Geargrinder Biker) - Ride Vehicle Hardcoded
(229180, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- 229180 (Darkfuse Gunner) - Mod Scale 95-105%
(234569, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '473682 473732'), -- 234569 ([DNT] Crash Target) - [DNT] Cosmetic Object, [DNT] Tool Rack Visual
(236332, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, ''), -- 236332 (Lolo Gumbat)
(237587, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '474480'), -- 237587 (Mechanized Peacekeeper) - Unstable Mech
(225821, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '461000 466615'), -- 225821 (The Geargrinder) - [DNT] Energy Override, Protective Plating
(225822, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '46598'), -- 225822 (Vexie Fullthrottle) - Ride Vehicle Hardcoded
(228881, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '268221'), -- 228881 ([DNT] Tank Turret) - Ride Vehicle
(233962, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 233962 (Marin Noggenfogger)
(233963, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, ''), -- 233963 (Baron Revilgaz)
(233960, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 233960 (Grimla Fizzlecrank)
(233330, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 233330 (Bilgewater Local) - Mod Scale 95-105%
(233959, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, ''), -- 233959 (Monte Gazlowe)
(238781, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1221822 1221953 1221955 1221960 1222253 1222258 1222826 1223986'), -- 238781 (Sound Stalker - 11.1 Amb - Undermine - Traffic Sound Stalker) - [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Traffic Flyby - High, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Traffic Flyby - Mid, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Traffic Flyby - Low, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Car Alarm, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Distant Horns, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Tire Skid, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Engine Rev, [DNT] 11.1 Sound - Undermine - Traffic - (1) Periodic Sound Trigger - Rocket Fly By
(228665, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'), -- 228665 (Geargrinder Biker) - Ride Vehicle Hardcoded
(228662, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- 228662 (Geargrinder Biker) - Mod Scale 105-110%
(230853, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '46598'); -- 230853 (Geargrinder Bomber) - Ride Vehicle Hardcoded

UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x8001, `VehicleId`=8650 WHERE `entry`=228662; -- Geargrinder Biker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231318; -- Hungry Croach
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x8001, `VehicleId`=8650 WHERE `entry`=228662; -- Geargrinder Biker
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=231323; -- Hungry Nibbler
UPDATE `creature_template` SET `faction`=35, `speed_walk`=2.799999952316284179, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=233330; -- Bilgewater Local
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x8001 WHERE `entry`=233156; -- Geargrinder Gear-Grinder
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x4000800, `unit_flags3`=0x8001, `flags_extra` = 128 WHERE `entry`=234569; -- [DNT] Crash Target
UPDATE `creature_template` SET `faction`=3534, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235621; -- Ando the Gat
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1000000, `flags_extra`=128 WHERE `entry` IN (240528, 238781); -- Sound Stalker - 11.1 Amb - Undermine - Traffic Sound Stalker
UPDATE `creature_template` SET `faction`=3534, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235620; -- Sando the Rat
UPDATE `creature_template` SET `faction`=3534, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235622; -- Mabel Hexkey
UPDATE `creature_template` SET `faction`=3534, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235617; -- Paula Piranha
UPDATE `creature_template` SET `faction`=3534, `npcflag`=4294967296, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235879; -- Grit Alphadrill
UPDATE `creature_template` SET `faction`=3534, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235616; -- Mickey Junkfeast
UPDATE `creature_template` SET `faction`=3534, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=235878; -- CHUCK-135
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=233957; -- Hotel Guest
UPDATE `creature_template` SET `faction`=3534, `npcflag`=4503599627370497, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235626; -- Lynndy Leatherbolts
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=236332; -- Lolo Gumbat
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=234044; -- Scrungly Rat
UPDATE `creature_template` SET `faction`=3476, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235613; -- Fawkes Peppergear
UPDATE `creature_template` SET `faction`=3476, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235612; -- Scramblington Spoonfork
UPDATE `creature_template` SET `faction`=3476, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235615; -- Lathe Faceter
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=233959; -- Monte Gazlowe
UPDATE `creature_template` SET `faction`=3476, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=235614; -- Rubbel
UPDATE `creature_template` SET `faction`=3476, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=233958; -- Paks Topskimmer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry` IN (227961, 237587); -- Mechanized Peacekeeper
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x200000, `unit_flags3`=0x1, `VehicleId`=8587 WHERE `entry`=225821; -- The Geargrinder
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=233960; -- Grimla Fizzlecrank
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=233963; -- Baron Revilgaz
UPDATE `creature_template` SET `faction`=3476, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=231824; -- Kari Bridgeblaster
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=233962; -- Marin Noggenfogger
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229180; -- Darkfuse Gunner
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x8000 WHERE `entry`=230853; -- Geargrinder Bomber
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x8001 WHERE `entry`=225822; -- Vexie Fullthrottle
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x8000 WHERE `entry`=228665; -- Geargrinder Biker

-- Gameobjects
DELETE FROM `gameobject_template` WHERE `entry` IN (484571, 516767, 484570, 494478, 505248, 504688, 494485, 494484, 494487, 494486, 494481, 499159, 494483, 494482, 499165, 499164, 494488, 499166, 499160, 499163, 494731, 494730, 455349, 455351, 505163, 504785, 455357, 455356, 455359, 455358, 455353, 525461, 504798, 455352, 504793, 455355, 525463, 455354, 525462, 504795, 499251, 455361, 525469, 455360, 525468, 525465, 525464, 525467, 525466, 484573, 504686, 484572, 499202, 504791, 504794, 506582);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(484571, 0, 99897, 'Alliance Gate', '', '', '', 1.009999990463256835, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Alliance Gate
(516767, 5, 98816, 'Poster', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Poster
(484570, 0, 99897, 'Alliance Gate', '', '', '', 1.080000042915344238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Alliance Gate
(494478, 0, 96878, 'Door', '', '', '', 1.403896570205688476, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(505248, 10, 99919, 'Rune Dispenser', '', '', '', 0.5, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 1227451, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 138188, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Rune Dispenser
(504688, 8, 76640, 'Scribe\'s Forgery Table', '', '', '', 0.800000011920928955, 2175, 10, 0, 0, 0, 0, 0, 0, 10816, 0, 30082, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Scribe's Forgery Table
(494485, 0, 96874, 'Door', '', '', '', 1.734099984169006347, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(494484, 0, 96874, 'Door', '', '', '', 1.699999690055847167, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(494487, 0, 96874, 'Door', '', '', '', 1.699999570846557617, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(494486, 0, 96874, 'Door', '', '', '', 1.734099984169006347, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(494481, 0, 96874, 'Door', '', '', '', 1.649999499320983886, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(499159, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(494483, 0, 96874, 'Door', '', '', '', 1.649999618530273437, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(494482, 0, 96874, 'Door', '', '', '', 1.734099864959716796, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(499165, 7, 93731, 'Bench', '', '', '', 0.999999821186065673, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(499164, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(494488, 0, 96874, 'Door', '', '', '', 1.715605139732360839, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(499166, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(499160, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(499163, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(494731, 0, 96874, 'Door', '', '', '', 1.066263198852539062, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(494730, 0, 96874, 'Door', '', '', '', 1.066263198852539062, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(455349, 7, 93731, 'Bench', '', '', '', 0.999999523162841796, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(455351, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(505163, 0, 97769, 'Alliance Gate', '', '', '', 1.049999952316284179, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Alliance Gate
(504785, 8, 76168, 'Undersmith\'s Table', '', '', '', 0.699999988079071044, 1, 10, 0, 0, 0, 0, 0, 0, 404, 0, 30078, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Undersmith's Table
(455357, 7, 92627, 'Stool', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Stool
(455356, 7, 92627, 'Stool', '', '', '', 0.999999821186065673, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Stool
(455359, 7, 89571, 'Fancy Chair', '', '', '', 0.999999821186065673, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(455358, 7, 89571, 'Fancy Chair', '', '', '', 0.999999821186065673, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(455353, 7, 92627, 'Stool', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Stool
(525461, 7, 97767, 'Bean Bag Chair', '', '', '', 0.999999880790710449, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(504798, 8, 76166, 'Tinker\'s Workbench', '', '', '', 0.800000011920928955, 2166, 10, 0, 0, 0, 0, 0, 0, 406, 0, 30080, 1, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Tinker's Workbench
(455352, 7, 93731, 'Bench', '', '', '', 0.999999761581420898, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bench
(504793, 8, 76632, 'Swindler\'s Lectern', '', '', '', 0.800000011920928955, 2173, 10, 0, 0, 0, 0, 0, 0, 402, 0, 30079, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Swindler's Lectern
(455355, 7, 89571, 'Fancy Chair', '', '', '', 0.999999821186065673, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(525463, 7, 97337, 'Bean Bag Chair', '', '', '', 0.999999761581420898, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(455354, 7, 89571, 'Fancy Chair', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(525462, 7, 97337, 'Bean Bag Chair', '', '', '', 0.999999761581420898, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(504795, 8, 76631, 'Leatherworker\'s Tool Bench', '', '', '', 0.800000011920928955, 2169, 10, 0, 0, 0, 0, 0, 0, 407, 0, 30084, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Leatherworker's Tool Bench
(499251, 7, 89571, 'Fancy Chair', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(455361, 7, 89571, 'Fancy Chair', '', '', '', 0.999999821186065673, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(525469, 7, 97337, 'Bean Bag Chair', '', '', '', 0.999999821186065673, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(455360, 7, 89571, 'Fancy Chair', '', '', '', 0.999999940395355224, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(525468, 7, 97767, 'Bean Bag Chair', '', '', '', 0.999999821186065673, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(525465, 7, 97337, 'Bean Bag Chair', '', '', '', 0.999999701976776123, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(525464, 7, 97767, 'Bean Bag Chair', '', '', '', 0.999999821186065673, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(525467, 7, 97767, 'Bean Bag Chair', '', '', '', 0.999999761581420898, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(525466, 7, 97767, 'Bean Bag Chair', '', '', '', 0.999999701976776123, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Bean Bag Chair
(484573, 0, 99897, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Alliance Gate
(504686, 8, 76589, 'Goblin-Sized Lab Bench', '', '', '', 0.800000011920928955, 2164, 10, 0, 0, 0, 0, 0, 0, 403, 0, 30076, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2164, 59570), -- Goblin-Sized Lab Bench
(484572, 0, 99897, 'Alliance Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Alliance Gate
(499202, 7, 89571, 'Fancy Chair', '', '', '', 0.999999761581420898, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fancy Chair
(504791, 8, 76170, 'Jeweler\'s Bench', '', '', '', 0.800000011920928955, 2168, 10, 0, 0, 0, 0, 0, 0, 5922, 0, 30083, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Jeweler's Bench
(504794, 8, 76167, 'Tailor\'s Work Table', '', '', '', 0.800000011920928955, 2174, 10, 0, 0, 0, 0, 0, 0, 408, 0, 30085, 2, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Tailor's Work Table
(506582, 1, 100397, 'Face-Lifter', '', '', '', 0.5, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570); -- Face-Lifter

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (484571, 484570, 494478, 494485, 494487, 494484, 494486, 494481, 494483, 494482, 494488, 494731, 494730, 505163, 484572, 484573);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(484571, 114, 0x20, 0, 0), -- Alliance Gate
(484570, 114, 0x20, 0, 0), -- Alliance Gate
(494478, 0, 0x30, 0, 0), -- Door
(494485, 0, 0x30, 0, 0), -- Door
(494487, 0, 0x30, 0, 0), -- Door
(494484, 0, 0x30, 0, 0), -- Door
(494486, 0, 0x30, 0, 0), -- Door
(494481, 0, 0x30, 0, 0), -- Door
(494483, 0, 0x30, 0, 0), -- Door
(494482, 0, 0x30, 0, 0), -- Door
(494488, 0, 0x30, 0, 0), -- Door
(494731, 0, 0x30, 0, 0), -- Door
(494730, 0, 0x30, 0, 0), -- Door
(505163, 114, 0x20, 0, 0), -- Alliance Gate
(484572, 114, 0x20, 0, 0), -- Alliance Gate
(484573, 114, 0x20, 0, 0); -- Alliance Gat

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+56;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 484571, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 133.0833282470703125, 474.8507080078125, -3.29690885543823242, 2.949595451354980468, 0, 0, 0.995395660400390625, 0.095851235091686248, 604800, 255, 1, 59570), -- Alliance Gate (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+1, 516767, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0.706597208976745605, 596.80731201171875, 17.63906288146972656, 4.857434272766113281, -0.54308843612670898, 0.521433830261230468, -0.39541530609130859, 0.526125907897949218, 604800, 255, 1, 59570), -- Poster (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+2, 484570, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 28.53125, 438.651031494140625, -1.6175774335861206, 0.898844838142395019, 0, 0, 0.434445381164550781, 0.900698184967041015, 604800, 255, 1, 59570), -- Alliance Gate (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+3, 494478, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -13.8223247528076171, 546.0106201171875, 5.832529544830322265, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+4, 505248, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -1.89583337306976318, 558.998291015625, 17.82619857788085937, 5.440874099731445312, 0, 0, -0.40881538391113281, 0.912617146968841552, 604800, 255, 1, 59570), -- Rune Dispenser (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+5, 504688, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 3.380208253860473632, 525.06768798828125, 17.74194717407226562, 5.463805675506591796, 0, 0, -0.39832496643066406, 0.917244374752044677, 604800, 255, 1, 59570), -- Scribe's Forgery Table (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+6, 494485, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 5.165510177612304687, 502.2872314453125, 5.981904983520507812, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+7, 494484, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -5.51047706604003906, 564.03076171875, 5.981904983520507812, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+8, 494487, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 30.6867523193359375, 538.32275390625, 5.981904983520507812, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+9, 494486, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 30.66113662719726562, 527.7828369140625, 6.068145275115966796, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+10, 494481, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -5.72841167449951171, 502.153076171875, 5.981904983520507812, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+11, 499159, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -23.218963623046875, 542.37420654296875, 5.948953628540039062, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+12, 494483, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -31.1230411529541015, 538.556884765625, 5.981904983520507812, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+13, 494482, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -31.2681541442871093, 527.8448486328125, 5.981904983520507812, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+14, 499165, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -41.225860595703125, 534.64422607421875, 6.707051277160644531, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+15, 499164, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -36.7888603210449218, 527.624755859375, 6.707051753997802734, 2.139628887176513671, 0, 0, 0.877111434936523437, 0.48028692603111267, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+16, 494488, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 5.078351974487304687, 564.044189453125, 5.981904983520507812, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+17, 499166, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -36.739044189453125, 538.6851806640625, 6.707051277160644531, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+18, 499160, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -25.6193504333496093, 540.27197265625, 5.948953628540039062, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+19, 499163, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -41.2045249938964843, 531.8770751953125, 6.707051753997802734, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+20, 494731, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -18.2211532592773437, 526.25, 5.941905021667480468, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+21, 494730, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -7.08251523971557617, 515.0386962890625, 5.941905021667480468, 3.926990509033203125, 0, 0, -0.92387962341308593, 0.382683247327804565, 604800, 255, 1, 59570), -- Door (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+22, 455349, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -6.41716861724853515, 549.5706787109375, 5.881754875183105468, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+23, 455351, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 16.07133674621582031, 527.0821533203125, 5.881753921508789062, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+24, 505163, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 31.42708396911621093, 502.76910400390625, 0.513888895511627197, 2.364918231964111328, 0, 0, 0.925539970397949218, 0.378649920225143432, 604800, 255, 0, 59570), -- Alliance Gate (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+25, 504785, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -20.7413196563720703, 543.04864501953125, 17.86402130126953125, 6.186475753784179687, 0, 0, -0.04833602905273437, 0.998831152915954589, 604800, 255, 1, 59570), -- Undersmith's Table (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+26, 455357, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 2.841243267059326171, 515.48846435546875, 5.881755828857421875, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Stool (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+27, 455356, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -9.65997505187988281, 523.70123291015625, 6.43730926513671875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 604800, 255, 1, 59570), -- Stool (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+28, 455359, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 13.36458778381347656, 512.0887451171875, 17.86402130126953125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+29, 455358, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 20.72269058227539062, 519.81463623046875, 17.86402130126953125, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+30, 455353, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 5.640529632568359375, 517.348876953125, 5.881753921508789062, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Stool (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+31, 525461, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0.500454902648925781, 514.7607421875, 5.881754875183105468, 1.621405363082885742, 0, 0, 0.724771499633789062, 0.688989341259002685, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+32, 504798, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -4.89409732818603515, 541.451416015625, 17.74194717407226562, 2.344598293304443359, 0, 0, 0.921645164489746093, 0.388033777475357055, 604800, 255, 1, 59570), -- Tinker's Workbench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+33, 455352, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 17.70462989807128906, 528.7154541015625, 5.881753921508789062, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+34, 504793, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 10.04166698455810546, 512.69268798828125, 17.86402130126953125, 1.634143710136413574, 0, 0, 0.729145050048828125, 0.684359192848205566, 604800, 255, 1, 59570), -- Swindler's Lectern (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+35, 455355, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -15.7143983840942382, 538.87396240234375, 5.881753921508789062, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+36, 525463, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -18.9522514343261718, 533.288818359375, 5.881754875183105468, 6.039627552032470703, 0, 0, -0.12147808074951171, 0.992594122886657714, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+37, 455354, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -18.0155696868896484, 536.34552001953125, 5.881752967834472656, 0, 0, 0, 0, 1, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+38, 525462, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -0.86119651794433593, 514.5313720703125, 5.881754875183105468, 0.748943269252777099, 0, 0, 0.365780830383300781, 0.930701017379760742, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+39, 504795, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -8.58854198455810546, 537.57464599609375, 17.74194717407226562, 2.372311115264892578, 0, 0, 0.92693328857421875, 0.375226199626922607, 604800, 255, 1, 59570), -- Leatherworker's Tool Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+40, 499251, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -14.9672374725341796, 553.03369140625, 17.86402130126953125, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+41, 455361, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -20.8462390899658203, 546.555419921875, 17.86402130126953125, 0.01374827791005373, 0, 0, 0.00687408447265625, 0.999976336956024169, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+42, 525469, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -21.0345821380615234, 543.11871337890625, 17.86401939392089843, 0.206334680318832397, 0, 0, 0.102984428405761718, 0.994682967662811279, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+43, 455360, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -13.3388633728027343, 553.869384765625, 17.86402130126953125, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+44, 525468, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -21.011972427368164, 544.3123779296875, 17.86402130126953125, 5.229222297668457031, 0, 0, -0.50292682647705078, 0.864328980445861816, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+45, 525465, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 0.325886726379394531, 551.505615234375, 5.800933837890625, 3.486468315124511718, 0, 0, -0.9851694107055664, 0.171584486961364746, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+46, 525464, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 18.04027938842773437, 532.50067138671875, 5.800936698913574218, 2.24745488166809082, 0, 0, 0.9017181396484375, 0.432324379682540893, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+47, 525467, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 16.87337493896484375, 514.9034423828125, 17.86402130126953125, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+48, 525466, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -1.09853553771972656, 551.562255859375, 5.800928115844726562, 4.563417911529541015, 0, 0, -0.7577667236328125, 0.652525544166564941, 604800, 255, 1, 59570), -- Bean Bag Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+49, 484573, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 103.7274322509765625, 520.1007080078125, -1.70402193069458007, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 604800, 255, 1, 59570), -- Alliance Gate (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+50, 504686, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 7.810763835906982421, 528.92535400390625, 17.74194717407226562, 5.478873729705810546, 0, 0, -0.3914031982421875, 0.920219302177429199, 604800, 255, 1, 59570), -- Goblin-Sized Lab Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+51, 484572, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 82.78125, 425.385406494140625, -2.86205887794494628, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 604800, 255, 1, 59570), -- Alliance Gate (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+52, 499202, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 19.73452568054199218, 517.9140625, 17.86402130126953125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 604800, 255, 1, 59570), -- Fancy Chair (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject1
(@OGUID+53, 504791, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -10.0416669845581054, 553.3125, 17.86402130126953125, 4.734510421752929687, 0, 0, -0.69924259185791015, 0.714884459972381591, 604800, 255, 1, 59570), -- Jeweler's Bench (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject2
(@OGUID+54, 504794, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, 20.28472328186035156, 523.07293701171875, 17.86402130126953125, 3.122257471084594726, 0, 0, 0.999953269958496093, 0.009667475707828998, 604800, 255, 1, 59570), -- Tailor's Work Table (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject2
(@OGUID+55, 506582, 2769, 15522, 15646, '14,15,16,17,220', 0, 0, -20.8298606872558593, 518.28643798828125, 18.00219154357910156, 0.58394700288772583, 0, 0, 0.287842750549316406, 0.957677721977233886, 604800, 255, 1, 59570), -- Face-Lifter (Area: The Incontinental Hotel - Difficulty: Mythic) CreateObject2
(@OGUID+56, 253128, 2769, 15347, 15388, '14,15,16,17,220', 0, 0, -11.6927080154418945, 544.078125, 6.921126365661621093, 5.497092723846435546, 0, 0, -0.38300418853759765, 0.923746585845947265, 604800, 255, 1, 59679); -- Instance Portal (Area: The Incontinental Hotel - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+56;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+3, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+6, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+7, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+8, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+9, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+10, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+11, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+12, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+13, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+14, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+15, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+16, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+17, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+18, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+19, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+20, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+21, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Door
(@OGUID+22, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+26, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+27, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+28, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+29, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+30, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+31, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+33, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bench
(@OGUID+35, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+36, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+37, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+38, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+40, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+41, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+42, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+43, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Fancy Chair
(@OGUID+44, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+45, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+46, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+47, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+48, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Bean Bag Chair
(@OGUID+52, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0); -- Fancy Chair

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (228662,228881, 225821);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(228662, 228665, 0, 1, 'Geargrinder Biker - Geargrinder Biker', 7, 0), -- Geargrinder Biker - Geargrinder Biker
(228881, 225822, 0, 1, '[DNT] Tank Turret - Vexie Fullthrottle', 8, 0), -- [DNT] Tank Turret - Vexie Fullthrottle
(225821, 228881, 0, 1, 'The Geargrinder - [DNT] Tank Turret', 7, 0), -- The Geargrinder - Geargrinder Bomber
(225821, 230853, 1, 1, 'The Geargrinder - Geargrinder Bomber', 7, 0), -- The Geargrinder - Geargrinder Bomber
(225821, 230853, 4, 1, 'The Geargrinder - Geargrinder Bomber', 7, 0), -- The Geargrinder - Geargrinder Bomber
(225821, 230853, 3, 1, 'The Geargrinder - Geargrinder Bomber', 7, 0), -- The Geargrinder - Geargrinder Bomber
(225821, 230853, 2, 1, 'The Geargrinder - Geargrinder Bomber', 7, 0); -- The Geargrinder - Geargrinder Bomber

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (225821, 228881, 235878, 228662);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(225821, 46598, 0, 0),
(228881, 268221, 0, 0),
(235878, 224326, 1, 1),
(228662, 46598, 0, 0);

-- Vendors
DELETE FROM `npc_vendor` WHERE (`entry`=231824 AND `item`=229341 AND `ExtendedCost`=9348 AND `type`=1) OR (`entry`=231824 AND `item`=229342 AND `ExtendedCost`=9348 AND `type`=1) OR (`entry`=231824 AND `item`=229343 AND `ExtendedCost`=9348 AND `type`=1) OR (`entry`=231824 AND `item`=229344 AND `ExtendedCost`=9348 AND `type`=1) OR (`entry`=231824 AND `item`=229346 AND `ExtendedCost`=9348 AND `type`=1) OR (`entry`=235613 AND `item`=226205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=226204 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=228930 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=212754 AND `ExtendedCost`=8502 AND `type`=1) OR (`entry`=235613 AND `item`=210828 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=230935 AND `ExtendedCost`=9354 AND `type`=1) OR (`entry`=235613 AND `item`=230936 AND `ExtendedCost`=9355 AND `type`=1) OR (`entry`=235613 AND `item`=230937 AND `ExtendedCost`=9353 AND `type`=1) OR (`entry`=235613 AND `item`=220789 AND `ExtendedCost`=10108 AND `type`=1) OR (`entry`=235613 AND `item`=220790 AND `ExtendedCost`=8582 AND `type`=1) OR (`entry`=235613 AND `item`=220788 AND `ExtendedCost`=8580 AND `type`=1) OR (`entry`=235613 AND `item`=227208 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235613 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235622 AND `item`=231270 AND `ExtendedCost`=9368 AND `type`=1) OR (`entry`=235622 AND `item`=231269 AND `ExtendedCost`=9367 AND `type`=1) OR (`entry`=235622 AND `item`=231267 AND `ExtendedCost`=9366 AND `type`=1) OR (`entry`=235621 AND `item`=229940 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235621 AND `item`=229924 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235621 AND `item`=229945 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235614 AND `item`=228930 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235614 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235614 AND `item`=226202 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235614 AND `item`=228956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=235614 AND `item`=228414 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227327 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227326 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227317 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227318 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227301 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227302 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227310 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227309 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227273 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=233958 AND `item`=227272 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(231824, 225, 229341, 0, 9348, 1, 0, 0, 59570), -- Aspectral Emissary's Arcane Vents
(231824, 224, 229342, 0, 9348, 1, 0, 0, 59570), -- Aspectral Emissary's Trousers
(231824, 223, 229343, 0, 9348, 1, 0, 0, 59570), -- Aspectral Emissary's Crystalline Cowl
(231824, 222, 229344, 0, 9348, 1, 0, 0, 59570), -- Aspectral Emissary's Hardened Grasp
(231824, 221, 229346, 0, 9348, 1, 0, 0, 59570), -- Aspectral Emissary's Primal Robes
(235613, 15, 226205, 0, 0, 1, 0, 0, 59570), -- Distilled Algari Freshwater
(235613, 14, 226204, 0, 0, 1, 0, 0, 59570), -- Fresh Parchment
(235613, 13, 228930, 0, 0, 1, 0, 0, 59570), -- Adorning Ribbon
(235613, 12, 224764, 0, 0, 1, 0, 0, 59570), -- Mosswool Thread
(235613, 11, 212754, 0, 8502, 1, 0, 0, 59570), -- Crystalforged Cauldron
(235613, 10, 210828, 0, 0, 1, 0, 0, 59570), -- Dilution Solution
(235613, 9, 211806, 0, 0, 1, 0, 0, 59570), -- Gilded Vial
(235613, 8, 230935, 0, 9354, 1, 0, 0, 59570), -- Enchanted Gilded Undermine Crest
(235613, 7, 230936, 0, 9355, 1, 0, 0, 59570), -- Enchanted Runed Undermine Crest
(235613, 6, 230937, 0, 9353, 1, 0, 0, 59570), -- Enchanted Weathered Undermine Crest
(235613, 5, 220789, 0, 10108, 1, 0, 0, 59570), -- Nascent Gilded Harbinger Crest
(235613, 4, 220790, 0, 8582, 1, 0, 0, 59570), -- Nascent Runed Harbinger Crest
(235613, 3, 220788, 0, 8580, 1, 0, 0, 59570), -- Nascent Weathered Harbinger Crest
(235613, 2, 227208, 0, 0, 1, 0, 0, 59570), -- Bismuth Rod
(235613, 1, 38682, 0, 0, 1, 0, 0, 59570), -- Enchanting Vellum
(235622, 3, 231270, 0, 9368, 1, 0, 0, 59570), -- Pack of Runed Undermine Crests
(235622, 2, 231269, 0, 9367, 1, 0, 0, 59570), -- Satchel of Carved Undermine Crests
(235622, 1, 231267, 0, 9366, 1, 0, 0, 59570), -- Pouch of Weathered Undermine Crests
(235621, 3, 229940, 0, 0, 1, 132366, 0, 59570), -- -Unknown-
(235621, 2, 229924, 0, 0, 1, 132363, 0, 59570), -- -Unknown-
(235621, 1, 229945, 0, 0, 1, 132354, 0, 59570), -- Thunderdrum Misfire
(235614, 5, 228930, 0, 0, 1, 0, 0, 59570), -- Adorning Ribbon
(235614, 4, 224764, 0, 0, 1, 0, 0, 59570), -- Mosswool Thread
(235614, 3, 226202, 0, 0, 1, 0, 0, 59570), -- Echoing Flux
(235614, 2, 228956, 0, 0, 1, 0, 0, 59570), -- Junk Bucket
(235614, 1, 228414, 0, 0, 1, 0, 0, 59570), -- Frayed Wiring
(233958, 11, 227327, 0, 0, 1, 0, 0, 59570), -- Rocky Road
(233958, 10, 227326, 0, 0, 1, 0, 0, 59570), -- Chalcocite Lava Cake
(233958, 9, 227325, 0, 0, 1, 0, 0, 59570), -- Stone Soup
(233958, 8, 227317, 0, 0, 1, 0, 0, 59570), -- Lava Cola
(233958, 7, 227318, 0, 0, 1, 0, 0, 59570), -- Quicksilver Sipper
(233958, 6, 227301, 0, 0, 1, 0, 0, 59570), -- Crystal Tots
(233958, 5, 227302, 0, 0, 1, 0, 0, 59570), -- Granite Salad
(233958, 4, 227310, 0, 0, 1, 0, 0, 59570), -- Magmalaid
(233958, 3, 227309, 0, 0, 1, 0, 0, 59570), -- Titanshake
(233958, 2, 227273, 0, 0, 1, 0, 0, 59570), -- Iron Poppers
(233958, 1, 227272, 0, 0, 1, 0, 0, 59570); -- Rock Lobster

-- Equipment
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (237599,229180,233963,233959,236332,230853,228665));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(237599, 1, 0, 0, 0, 0, 0, 0, 227293, 0, 0, 59538), -- Geargrinder Biker
(229180, 1, 37924, 0, 0, 0, 0, 0, 108713, 0, 0, 59538), -- Darkfuse Gunner
(233963, 1, 3364, 0, 0, 0, 0, 0, 0, 0, 0, 59538), -- Baron Revilgaz
(233959, 1, 221476, 0, 0, 0, 0, 0, 0, 0, 0, 59538), -- Monte Gazlowe
(236332, 1, 0, 0, 0, 0, 0, 0, 42822, 0, 0, 59538), -- Lolo Gumbat
(230853, 1, 0, 0, 0, 0, 0, 0, 227293, 0, 0, 59538), -- Geargrinder Bombe
(228665, 1, 0, 0, 0, 0, 0, 0, 227293, 0, 0, 59538); -- Geargrinder Biker

-- Models
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (127183, 124605, 125800, 127182, 126300, 125824, 125318, 125913, 125389, 126362, 126173, 126162, 126167, 122995, 125926, 121875, 122645, 122609, 122611, 121293, 123065, 123064, 121769, 125721, 125737, 125726, 127472, 125722, 125725, 125738, 126456, 125739, 125724, 125741, 125740, 125736, 125723, 122831, 121764, 126287, 125434, 125513, 125516, 125515, 125520, 125438, 126305, 122761, 125263, 122299, 125797, 127178, 127181, 127180, 126307, 124724, 127598, 123583, 122748, 126248, 127609, 125905, 122816, 121751, 125906, 127308, 126583, 127137, 123314, 123968, 121758, 126386, 127135, 121444, 122750, 124183, 127595, 121440, 127597, 123239, 125333, 121716, 126156, 123763, 123762, 126304, 127593, 121711, 124132, 127401, 125137, 127138, 120388, 121205, 125819, 125271, 122866, 124105, 123490, 122443, 122352, 122216, 121214, 127471, 122138, 127596, 123292, 124310, 123288, 127134, 127306, 127307, 125859, 127136, 127173, 127132, 127133, 122137, 123293, 126976, 127540, 123053, 123290, 126696, 124032, 124019, 124010, 125656, 127177, 120075, 126005, 125657, 125668, 125573, 124186, 124184, 125607, 125378, 124210, 122746, 125818, 125799, 122509, 122724, 125779, 126171, 127310, 125309, 125229, 125795, 120522, 122364, 122365, 125817, 125778, 127309, 125759, 125808, 126062, 125316, 122832, 127662, 127373, 125832, 125381, 123459, 123448, 126125, 125257, 125437, 126663, 125436, 125258, 125769, 125424, 125611, 125765, 125770, 123326, 127305, 125332, 126444, 126002, 125775, 125767, 125816, 126007, 125772, 122457, 123569, 127189, 125793, 126768, 125384, 126767, 125796, 122589, 126170, 125511, 125400, 125324, 125862, 125320, 125608, 120521, 124460, 124459, 125319, 122458, 122460, 122856, 120523, 125435, 122459, 126000, 125809, 125287, 125280, 125798, 125412, 126314, 125794, 125815, 125852, 125315, 127660, 125813, 120520, 120515, 124273, 124274, 125308, 125820, 126044, 125321, 125814, 124277, 124278, 124275, 124276, 121085, 120527, 125286, 127274, 120514, 120528, 120516, 122725, 123060, 125230, 120526, 125591, 125323, 127179);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(120523, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(127181, 0.305999994277954101, 1.5, 0, 59538),
(127182, 0.305999994277954101, 1.5, 0, 59679),
(120526, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(126663, 0.5, 1, 0, 59538),
(122458, 0.305999994277954101, 1.5, 0, 59538),
(125271, 0.305999994277954101, 1.5, 0, 59538),
(127133, 0.305999994277954101, 1.5, 0, 59538),
(125800, 0.305999994277954101, 1.5, 0, 59570),
(125797, 0.305999994277954101, 1.5, 0, 59538),
(121205, 0.336600005626678466, 1.65000009536743164, 0, 59538),
(123060, 0.305999994277954101, 1.5, 0, 59538),
(120388, 0.336600005626678466, 1.65000009536743164, 0, 59538),
(126156, 0.347222030162811279, 1.5, 0, 59538),
(126305, 0.347221970558166503, 1.499999880790710449, 0, 59538),
(127183, 0.305999994277954101, 1.5, 0, 59570),
(126307, 0.698715150356292724, 1.5, 0, 59538),
(120521, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(120516, 0.448203086853027343, 1, 0, 59538),
(127136, 0.305999994277954101, 1.5, 0, 59538),
(125859, 0.310000002384185791, 1, 0, 59538),
(127307, 0.305999994277954101, 1.5, 0, 59538),
(127138, 0.305999994277954101, 1.5, 0, 59538),
(120514, 0.448203086853027343, 1, 0, 59538),
(125137, 0.530352234840393066, 1.25, 0, 59538),
(125324, 0.305999994277954101, 1.5, 0, 59538),
(120522, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(127132, 0.305999994277954101, 1.5, 0, 59538),
(127173, 0.305999994277954101, 1.5, 0, 59538),
(125332, 0.305999994277954101, 1.5, 0, 59538),
(120515, 0.448203086853027343, 1, 0, 59538),
(120528, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(124310, 0.305999994277954101, 1.5, 0, 59538),
(125817, 0.305999994277954101, 1.5, 0, 59538),
(120527, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(127306, 0.305999994277954101, 1.5, 0, 59538),
(127134, 0.305999994277954101, 1.5, 0, 59538),
(122137, 0.310000002384185791, 10.5, 0, 59538),
(124605, 0.347000002861022949, 1.5, 0, 59538),
(126300, 0.305999994277954101, 1.5, 0, 59538),
(125824, 0.305999994277954101, 1.5, 0, 59538),
(125318, 0.305999994277954101, 1.5, 0, 59538),
(125913, 0.305999994277954101, 1.5, 0, 59538),
(125389, 0.305999994277954101, 1.5, 0, 59538),
(126362, 0.305999994277954101, 1.5, 0, 59538),
(126173, 4.128281593322753906, 4.5, 0, 59538),
(126162, 0.455761194229125976, 1.5, 0, 59538),
(126167, 4.128281593322753906, 4.5, 0, 59538),
(122995, 1, 1.5, 0, 59538),
(125926, 1, 1.5, 0, 59538),
(121875, 0.5, 1, 0, 59538),
(122645, 0.75, 1, 0, 59538),
(122609, 0.25, 1, 0, 59538),
(122611, 0.5, 1, 0, 59538),
(121293, 0.629803180694580078, 1.5, 0, 59538),
(123065, 0.305999994277954101, 1.5, 0, 59538),
(123064, 0.305999994277954101, 1.5, 0, 59538),
(121769, 0.749745011329650878, 1, 0, 59538),
(125721, 0.305999994277954101, 1.5, 0, 59538),
(125737, 0.305999994277954101, 1.5, 0, 59538),
(125726, 0.305999994277954101, 1.5, 0, 59538),
(127472, 2.893195867538452148, 2.5, 0, 59538),
(125722, 0.305999994277954101, 1.5, 0, 59538),
(125725, 0.305999994277954101, 1.5, 0, 59538),
(125738, 0.305999994277954101, 1.5, 0, 59538),
(126456, 0.310000002384185791, 1, 0, 59538),
(125739, 0.305999994277954101, 1.5, 0, 59538),
(125724, 0.305999994277954101, 1.5, 0, 59538),
(125741, 0.305999994277954101, 1.5, 0, 59538),
(125740, 0.305999994277954101, 1.5, 0, 59538),
(125736, 0.305999994277954101, 1.5, 0, 59538),
(125723, 0.305999994277954101, 1.5, 0, 59538),
(122831, 0.310000002384185791, 1, 0, 59538),
(121764, 0.749745011329650878, 1, 0, 59538),
(126287, 0.305999994277954101, 1.5, 0, 59538),
(125434, 0.305999994277954101, 1.5, 0, 59538),
(125513, 0.305999994277954101, 1.5, 0, 59538),
(125516, 0.305999994277954101, 1.5, 0, 59538),
(125515, 0.305999994277954101, 1.5, 0, 59538),
(125520, 0.305999994277954101, 1.5, 0, 59538),
(125438, 0.305999994277954101, 1.5, 0, 59538),
(122761, 0.310000002384185791, 1, 0, 59538),
(125263, 0.305999994277954101, 1.5, 0, 59538),
(122299, 1.509005904197692871, 0, 0, 59538),
(127178, 0.305999994277954101, 1.5, 0, 59538),
(127180, 0.305999994277954101, 1.5, 0, 59538),
(124724, 0.305999964475631713, 1.5, 0, 59538),
(127598, 0.305999994277954101, 1.5, 0, 59538),
(123583, 0.305999964475631713, 1.499999880790710449, 0, 59538),
(122748, 0.306000024080276489, 1.50000011920928955, 0, 59538),
(126248, 7.492770195007324218, 0, 0, 59538),
(127609, 0.5, 1, 0, 59538),
(125905, 0.698715150356292724, 1.5, 0, 59538),
(122816, 0.305999994277954101, 1.5, 0, 59538),
(121751, 5.83444976806640625, 5.599999904632568359, 0, 59538),
(125906, 0.698715150356292724, 1.5, 0, 59538),
(127308, 0.305999994277954101, 1.5, 0, 59538),
(126583, 0.698715150356292724, 1.5, 0, 59538),
(127137, 0.305999994277954101, 1.5, 0, 59538),
(123314, 0.310000002384185791, 1, 0, 59538),
(123968, 0.310000002384185791, 1, 0, 59538),
(121758, 0.749745011329650878, 1, 0, 59538),
(126386, 0.952285528182983398, 1, 0, 59538),
(127135, 0.305999994277954101, 1.5, 0, 59538),
(121444, 0.236000016331672668, 1.5, 0, 59538),
(122750, 0.207999989390373229, 1.499999880790710449, 0, 59538),
(124183, 1.019407987594604492, 2, 0, 59538),
(127595, 0.305999994277954101, 1.5, 0, 59538),
(121440, 0.372000008821487426, 1.5, 0, 59538),
(127597, 0.305999994277954101, 1.5, 0, 59538),
(123239, 1, 1.5, 0, 59538),
(125333, 0.305999994277954101, 1.5, 0, 59538),
(121716, 1.070488333702087402, 0, 0, 59538),
(123763, 0.372000008821487426, 1.5, 0, 59538),
(123762, 0.698715150356292724, 1.50000011920928955, 0, 59538),
(126304, 0.236000016331672668, 1.50000011920928955, 0, 59538),
(127593, 3.710472345352172851, 3.25, 0, 59538),
(121711, 1.070488333702087402, 0, 0, 59538),
(124132, 0.305999994277954101, 1.5, 0, 59538),
(127401, 5.241221427917480468, 13.5, 0, 59538),
(125819, 0.305999994277954101, 1.5, 0, 59538),
(122866, 0.305999994277954101, 1.5, 0, 59538),
(124105, 0.305999994277954101, 1.5, 0, 59538),
(123490, 7.390045166015625, 16, 0, 59538),
(122443, 0.305999994277954101, 1.5, 0, 59538),
(122352, 2.542831182479858398, 3, 0, 59538),
(122216, 8.060156822204589843, 14.5, 0, 59538),
(121214, 5.241221427917480468, 14.5, 0, 59538),
(127471, 2.893195867538452148, 2.5, 0, 59538),
(122138, 1.133485198020935058, 3, 0, 59538),
(127596, 1.007685065269470214, 2.40000009536743164, 0, 59538),
(123292, 0.305999994277954101, 1.5, 0, 59538),
(123288, 0.890208840370178222, 1.10000002384185791, 0, 59538),
(123293, 0.347222000360488891, 1.5, 0, 59538),
(126976, 8.060156822204589843, 13.5, 0, 59538),
(127540, 0.952285528182983398, 1, 0, 59538),
(123053, 2.893195867538452148, 2.5, 0, 59538),
(123290, 0.698715150356292724, 1.5, 0, 59538),
(126696, 0.384999990463256835, 0, 0, 59538),
(124032, 0.305999994277954101, 1.5, 0, 59538),
(124019, 0.305999994277954101, 1.5, 0, 59538),
(124010, 0.305999994277954101, 1.5, 0, 59538),
(125656, 0.305999994277954101, 1.5, 0, 59538),
(127177, 0.305999994277954101, 1.5, 0, 59538),
(120075, 0.135671228170394897, 0.450000017881393432, 0, 59538),
(126005, 0.5, 1, 0, 59538),
(125657, 0.305999994277954101, 1.5, 0, 59538),
(125668, 0.305999994277954101, 1.5, 0, 59538),
(125573, 0.305999994277954101, 1.5, 0, 59538),
(124186, 0.305999994277954101, 1.5, 0, 59538),
(124184, 0.305999994277954101, 1.5, 0, 59538),
(125607, 0.305999994277954101, 1.5, 0, 59538),
(125378, 0.305999994277954101, 1.5, 0, 59538),
(124210, 0.305999994277954101, 1.5, 0, 59538),
(122746, 0.310000002384185791, 1, 0, 59538),
(125818, 0.305999994277954101, 1.5, 0, 59538),
(125799, 0.305999994277954101, 1.5, 0, 59538),
(122509, 0.310000002384185791, 1, 0, 59538),
(122724, 0.310000002384185791, 1, 0, 59538),
(125779, 0.305999994277954101, 1.5, 0, 59538),
(126171, 0.305999994277954101, 1.5, 0, 59538),
(127310, 0.305999994277954101, 1.5, 0, 59538),
(125309, 0.305999994277954101, 1.5, 0, 59538),
(125229, 0.305999994277954101, 1.5, 0, 59538),
(125795, 0.305999994277954101, 1.5, 0, 59538),
(122364, 0.305999994277954101, 1.5, 0, 59538),
(122365, 0.305999994277954101, 1.5, 0, 59538),
(125778, 0.305999994277954101, 1.5, 0, 59538),
(127309, 0.305999994277954101, 1.5, 0, 59538),
(125759, 0.305999994277954101, 1.5, 0, 59538),
(125808, 0.305999994277954101, 1.5, 0, 59538),
(126062, 0.310000002384185791, 1, 0, 59538),
(125316, 0.305999994277954101, 1.5, 0, 59538),
(122832, 0.305999994277954101, 1.5, 0, 59538),
(127662, 0.372000008821487426, 1.20000004768371582, 0, 59538),
(127373, 0.305999994277954101, 1.5, 0, 59538),
(125832, 0.305999994277954101, 1.5, 0, 59538),
(125381, 0.305999994277954101, 1.5, 0, 59538),
(123459, 0.74693918228149414, 1.25, 0, 59538),
(123448, 0.17202778160572052, 1, 0, 59538),
(126125, 0.305999994277954101, 1.5, 0, 59538),
(125257, 0.305999994277954101, 1.5, 0, 59538),
(125437, 0.305999994277954101, 1.5, 0, 59538),
(125436, 0.305999994277954101, 1.5, 0, 59538),
(125258, 0.305999994277954101, 1.5, 0, 59538),
(125769, 0.305999994277954101, 1.5, 0, 59538),
(125424, 0.305999994277954101, 1.5, 0, 59538),
(125611, 0.305999994277954101, 1.5, 0, 59538),
(125765, 0.305999994277954101, 1.5, 0, 59538),
(125770, 0.305999994277954101, 1.5, 0, 59538),
(123326, 0.305999994277954101, 1.5, 0, 59538),
(127305, 0.305999994277954101, 1.5, 0, 59538),
(126444, 0.305999994277954101, 1.5, 0, 59538),
(126002, 0.5, 1, 0, 59538),
(125775, 0.305999994277954101, 1.5, 0, 59538),
(125767, 0.305999994277954101, 1.5, 0, 59538),
(125816, 0.305999994277954101, 1.5, 0, 59538),
(126007, 0.305999994277954101, 1.5, 0, 59538),
(125772, 0.305999994277954101, 1.5, 0, 59538),
(122457, 0.305999994277954101, 1.5, 0, 59538),
(123569, 1.085457324981689453, 0, 0, 59538),
(127189, 0.305999994277954101, 1.5, 0, 59538),
(125793, 0.305999994277954101, 1.5, 0, 59538),
(126768, 0.305999994277954101, 1.5, 0, 59538),
(125384, 0.305999994277954101, 1.5, 0, 59538),
(126767, 0.305999994277954101, 1.5, 0, 59538),
(125796, 0.305999994277954101, 1.5, 0, 59538),
(122589, 0.310000002384185791, 1, 0, 59538),
(126170, 0.305999994277954101, 1.5, 0, 59538),
(125511, 0.305999994277954101, 1.5, 0, 59538),
(125400, 0.305999994277954101, 1.5, 0, 59538),
(125862, 0.310000002384185791, 1, 0, 59538),
(125320, 0.305999994277954101, 1.5, 0, 59538),
(125608, 0.305999994277954101, 1.5, 0, 59538),
(124460, 0.305999994277954101, 1.5, 0, 59538),
(124459, 0.305999994277954101, 1.5, 0, 59538),
(125319, 0.305999994277954101, 1.5, 0, 59538),
(122460, 0.305999994277954101, 1.5, 0, 59538),
(122856, 2.893195867538452148, 2.5, 0, 59538),
(125435, 0.305999994277954101, 1.5, 0, 59538),
(122459, 0.305999994277954101, 1.5, 0, 59538),
(126000, 0.5, 1, 0, 59538),
(125809, 0.305999994277954101, 1.5, 0, 59538),
(125287, 0.305999994277954101, 1.5, 0, 59538),
(125280, 0.305999994277954101, 1.5, 0, 59538),
(125798, 0.305999994277954101, 1.5, 0, 59538),
(125412, 0.305999994277954101, 1.5, 0, 59538),
(126314, 1.976161122322082519, 0, 0, 59538),
(125794, 0.305999994277954101, 1.5, 0, 59538),
(125815, 0.305999994277954101, 1.5, 0, 59538),
(125852, 0.305999994277954101, 1.5, 0, 59538),
(125315, 0.305999994277954101, 1.5, 0, 59538),
(127660, 0.372000038623809814, 1.20000004768371582, 0, 59538),
(125813, 0.305999994277954101, 1.5, 0, 59538),
(120520, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(124273, 0.305999994277954101, 1.5, 0, 59538),
(124274, 0.305999994277954101, 1.5, 0, 59538),
(125308, 0.305999994277954101, 1.5, 0, 59538),
(125820, 0.305999994277954101, 1.5, 0, 59538),
(126044, 0.305999994277954101, 1.5, 0, 59538),
(125321, 0.305999994277954101, 1.5, 0, 59538),
(125814, 0.305999994277954101, 1.5, 0, 59538),
(124277, 0.305999994277954101, 1.5, 0, 59538),
(124278, 0.305999994277954101, 1.5, 0, 59538),
(124275, 0.305999994277954101, 1.5, 0, 59538),
(124276, 0.305999994277954101, 1.5, 0, 59538),
(121085, 0.305999994277954101, 1.5, 0, 59538),
(125286, 0.305999994277954101, 1.5, 0, 59538),
(127274, 0.310000002384185791, 1, 0, 59538),
(122725, 0.310000002384185791, 1, 0, 59538),
(125230, 0.305999994277954101, 1.5, 0, 59538),
(125591, 0.305999994277954101, 1.5, 0, 59538),
(125323, 0.305999994277954101, 1.5, 0, 59679),
(127179, 0.305999994277954101, 1.5, 0, 59570);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=14 AND `Entry` IN (225821,225822));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(225821, 14, 10, 640, 1, 321276, 0x20006C, 128), -- The Geargrinder
(225822, 14, 10, 5, 1, 317589, 0x20006C, 128); -- Vexie Fullthrottle

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=0 AND `Entry` IN (228662,228665)); -- Geargrinder Biker
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=231318 AND `DifficultyID`=0); -- 231318 (Hungry Croach) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=231323 AND `DifficultyID`=0); -- 231323 (Hungry Nibbler) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233330 AND `DifficultyID`=0); -- 233330 (Bilgewater Local) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2979, `VerifiedBuild`=59679 WHERE (`Entry`=233156 AND `DifficultyID`=0); -- 233156 (Geargrinder Gear-Grinder) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=234569 AND `DifficultyID`=0); -- 234569 ([DNT] Crash Target) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235621 AND `DifficultyID`=0); -- 235621 (Ando the Gat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x30000000, `VerifiedBuild`=59679 WHERE (`Entry`=238781 AND `DifficultyID`=0); -- 238781 (Sound Stalker - 11.1 Amb - Undermine - Traffic Sound Stalker) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235620 AND `DifficultyID`=0); -- 235620 (Sando the Rat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235622 AND `DifficultyID`=0); -- 235622 (Mabel Hexkey) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235617 AND `DifficultyID`=0); -- 235617 (Paula Piranha) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235879 AND `DifficultyID`=0); -- 235879 (Grit Alphadrill) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235616 AND `DifficultyID`=0); -- 235616 (Mickey Junkfeast) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2892, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235878 AND `DifficultyID`=0); -- 235878 (CHUCK-135) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233957 AND `DifficultyID`=0); -- 233957 (Hotel Guest) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235626 AND `DifficultyID`=0); -- 235626 (Lynndy Leatherbolts) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=236332 AND `DifficultyID`=0); -- 236332 (Lolo Gumbat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=234044 AND `DifficultyID`=0); -- 234044 (Scrungly Rat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235613 AND `DifficultyID`=0); -- 235613 (Fawkes Peppergear) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235612 AND `DifficultyID`=0); -- 235612 (Scramblington Spoonfork) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235615 AND `DifficultyID`=0); -- 235615 (Lathe Faceter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233959 AND `DifficultyID`=0); -- 233959 (Monte Gazlowe) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=2979, `StaticFlags1`=0x20000100, `VerifiedBuild`=59679 WHERE (`Entry`=225822 AND `DifficultyID`=0); -- 225822 (Vexie Fullthrottle) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=2979, `StaticFlags1`=0x20000100, `VerifiedBuild`=59679 WHERE (`Entry`=228881 AND `DifficultyID`=0); -- 228881 ([DNT] Tank Turret) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=235614 AND `DifficultyID`=0); -- 235614 (Rubbel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233958 AND `DifficultyID`=0); -- 233958 (Paks Topskimmer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2979, `StaticFlags1`=0x30000000, `VerifiedBuild`=59679 WHERE (`Entry`=237587 AND `DifficultyID`=0); -- 237587 (Mechanized Peacekeeper) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=2979, `VerifiedBuild`=59679 WHERE (`Entry`=225821 AND `DifficultyID`=0); -- 225821 (The Geargrinder) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233960 AND `DifficultyID`=0); -- 233960 (Grimla Fizzlecrank) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233963 AND `DifficultyID`=0); -- 233963 (Baron Revilgaz) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=231824 AND `DifficultyID`=0); -- 231824 (Kari Bridgeblaster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2979, `StaticFlags1`=0x10000000, `VerifiedBuild`=59679 WHERE (`Entry`=233962 AND `DifficultyID`=0); -- 233962 (Marin Noggenfogger) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2979, `StaticFlags1`=0x30000000, `VerifiedBuild`=59679 WHERE (`Entry`=229180 AND `DifficultyID`=0); -- 229180 (Darkfuse Gunner) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2979, `StaticFlags1`=0x30000100, `VerifiedBuild`=59679 WHERE (`Entry`=230853 AND `DifficultyID`=0); -- 230853 (Geargrinder Bomber) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2979, `StaticFlags1`=0x30000100, `VerifiedBuild`=59679 WHERE (`Entry`=228665 AND `DifficultyID`=0); -- 228665 (Geargrinder Biker) - Sessile, CanSwim, Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233958 AND `DifficultyID`=0); -- Paks Topskimmer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=0 AND `Entry` IN (228662,228665)); -- Geargrinder Biker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233330 AND `DifficultyID`=0); -- Bilgewater Local
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233156 AND `DifficultyID`=0); -- Geargrinder Gear-Grinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=234569 AND `DifficultyID`=0); -- [DNT] Crash Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233957 AND `DifficultyID`=0); -- Hotel Guest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=236332 AND `DifficultyID`=0); -- Lolo Gumbat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233959 AND `DifficultyID`=0); -- Monte Gazlowe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=228881 AND `DifficultyID`=0); -- [DNT] Tank Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=0 AND `Entry` IN (227961,237587)); -- Mechanized Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233960 AND `DifficultyID`=0); -- Grimla Fizzlecrank
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233963 AND `DifficultyID`=0); -- Baron Revilgaz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=233962 AND `DifficultyID`=0); -- Marin Noggenfogger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=229180 AND `DifficultyID`=0); -- Darkfuse Gunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=230853 AND `DifficultyID`=0); -- Geargrinder Bomber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`DifficultyID`=0 AND `Entry` IN (228662,228665)); -- Geargrinder Biker

-- Gossips
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=235615 AND `MenuID`=37951) OR (`CreatureID`=235621 AND `MenuID`=37947) OR (`CreatureID`=235620 AND `MenuID`=37946) OR (`CreatureID`=235612 AND `MenuID`=37949) OR (`CreatureID`=235626 AND `MenuID`=30243) OR (`CreatureID`=235617 AND `MenuID`=38147);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(235615, 37951, 59570), -- Lathe Faceter
(235621, 37947, 59570), -- Ando the Gat
(235620, 37946, 59570), -- Sando the Rat
(235612, 37949, 59570), -- Scramblington Spoonfork
(235626, 30243, 59570), -- Lynndy Leatherbolts
(235617, 38147, 59570); -- Paula Piranha

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+6;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 281718, 0, 0, 0, 0, 0, 0, 0, 59570), -- 235617 (Paula Piranha)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 233159, 0, 0, 0, 0, 0, 0, 0, 59570), -- 235626 (Lynndy Leatherbolts)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 280933, 0, 0, 0, 0, 0, 0, 0, 59570), -- 235620 (Sando the Rat)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 280935, 0, 0, 0, 0, 0, 0, 0, 59570), -- 235621 (Ando the Gat)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 280940, 0, 0, 0, 0, 0, 0, 0, 59570), -- 235612 (Scramblington Spoonfork)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 280946, 0, 0, 0, 0, 0, 0, 0, 59570), -- 235615 (Lathe Faceter)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 233214, 0, 0, 0, 0, 0, 0, 0, 59570); -- 504793 (Swindler's Lectern)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38147 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30243 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=37946 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=37947 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=37949 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=37951 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=30079 AND `TextID`=@NPCTEXTID+6);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38147, @NPCTEXTID+0, 59570), -- 235617 (Paula Piranha)
(30243, @NPCTEXTID+1, 59570), -- 235626 (Lynndy Leatherbolts)
(37946, @NPCTEXTID+2, 59570), -- 235620 (Sando the Rat)
(37947, @NPCTEXTID+3, 59570), -- 235621 (Ando the Gat)
(37949, @NPCTEXTID+4, 59570), -- 235612 (Scramblington Spoonfork)
(37951, @NPCTEXTID+5, 59570), -- 235615 (Lathe Faceter)
(30079, @NPCTEXTID+6, 59570); -- 504793 (Swindler's Lectern)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (30079,38147,37946,37947));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(30079, 107474, 0, 49, '<Take up your tools and practice enchanting.>', 0, 0, 0, 0, 0, 42379, 0, 0, NULL, 0, NULL, NULL, 59570),
(38147, 132218, 0, 53, 'Where do I stand with the Gallagio?', 0, 0, 0, 0, 0, 58586, 0, 0, NULL, 0, NULL, NULL, 59570),
(37946, 131916, 0, 1, 'Show me your wares.', 58437, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 59570), -- OptionBroadcastTextID: 58437 - 90189 - 180077
(37947, 131919, 0, 1, 'Show me your wares.', 58437, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 59570); -- OptionBroadcastTextID: 58437 - 90189 - 180077
