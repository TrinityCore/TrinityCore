
SET @CGUID := 11000000; -- @TODO
SET @OGUID := 11000000; -- @TODO
SET @NPCTEXTID := 11000000; -- @TODO

DELETE FROM `phase_name` WHERE `ID`=12651;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12651, 'Kul Tiran Unlock - Port Fogtide Part 2 Ship in progress');

DELETE FROM `phase_area` WHERE `PhaseId`=12651;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9579, 12651, 'Kul Tiran Unlock - Port Fogtide Part 2 Ship in progress - Tidecross'),
(9578, 12651, 'Kul Tiran Unlock - Port Fogtide Part 2 Ship in progress - Port Fogtide'),
(9622, 12651, 'Kul Tiran Unlock - Port Fogtide Part 2 Ship in progress - Krakens Reach');

-- conditions for part 1
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12607));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12607, 0, 0, 0, 47, 0, 54721, 74, 0, '', 0, 'Player have I\'m Too Old for This Ship (54721) in state incomplete, complete, rewarded'),
(26, 12607, 0, 0, 0, 47, 0, 54734, 74, 0, '', 1, 'Player doesn\'t have Summon from Dorian (54734) in state incomplete, complete, rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12651));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12651, 0, 0, 0, 47, 0, 54734, 74, 0, '', 0, 'Player have Summon from Dorian (54734) in state incomplete, complete, rewarded');
-- (26, 12651, 0, 0, 0, 47, 0, 54733, 64, 0, '', 1, 'Player doesn\'t have Make It Wright (54733) in state rewarded');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3503.9375, -467.489593505859375, 7.555978775024414062, 5.929232597351074218, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+1, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3491.275146484375, -430.02777099609375, 6.551049232482910156, 3.094370603561401367, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 288674 - [DNT] Carry Barrel)
(@CGUID+2, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3521.9912109375, -402.578765869140625, 6.622796535491943359, 1.416983842849731445, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3538.885498046875, -460.354156494140625, 5.755243301391601562, 3.335588455200195312, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+4, 148878, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3525.181884765625, -396.569976806640625, 6.678244590759277343, 5.97829294204711914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Rain (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3459.75927734375, -463.16949462890625, 22.06969261169433593, 1.91583251953125, 120, 12, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 148873, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3495.322021484375, -434.0625, 6.641434192657470703, 0.108713433146476745, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Sal Atwater (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+7, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3509.799560546875, -399.005279541015625, 6.673553943634033203, 4.388257503509521484, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3505.517333984375, -482.270843505859375, 8.953426361083984375, 0.468110203742980957, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+9, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3489.213623046875, -449.954864501953125, 7.54573678970336914, 3.202278614044189453, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+10, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3473.07666015625, -459.929595947265625, 6.257065773010253906, 4.599532127380371093, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 149459, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3477.623779296875, -454.3121337890625, 6.2860565185546875, 0.905193090438842773, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Algerson Lumberjack (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 289903 - [DNT] Log Carry) (possible waypoints or random movement)
(@CGUID+12, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3496.8994140625, -390.579864501953125, 6.229865074157714843, 4.760436534881591796, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 288674 - [DNT] Carry Barrel) (possible waypoints or random movement)
(@CGUID+13, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3476.022216796875, -411.022216796875, 29.72323989868164062, 1.663059473037719726, 120, 12, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3451.158935546875, -428.921875, 6.964962959289550781, 1.125535488128662109, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 288674 - [DNT] Carry Barrel) (possible waypoints or random movement)
(@CGUID+15, 150593, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3516.306396484375, -399.93402099609375, 6.5433349609375, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Fog Ward (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+16, 149460, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3464.16064453125, -467.21527099609375, 6.372937202453613281, 5.664390087127685546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Thornspeaker Adept (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 13236 - Nature Channeling) (possible waypoints or random movement)
(@CGUID+17, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3537.147705078125, -479.279510498046875, 4.414155960083007812, 2.744014739990234375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+18, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3466.10791015625, -439.538848876953125, 6.701312065124511718, 5.603239059448242187, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 148878, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3576.22998046875, -511.8975830078125, 0.139411062002182006, 3.96189737319946289, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Rain (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 149459, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3459.879150390625, -451.454071044921875, 7.004036426544189453, 0.063723325729370117, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Algerson Lumberjack (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 289903 - [DNT] Log Carry) (possible waypoints or random movement)
(@CGUID+21, 148918, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3472.012939453125, -454.977447509765625, 7.234241962432861328, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Fog Ward (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+22, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3520.476806640625, -469.41650390625, 40.40647506713867187, 2.891007661819458007, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+23, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3597.33935546875, -460.086029052734375, 6.842020034790039062, 0.934704482555389404, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292545 - [DNT] Carry Metal Bars) (possible waypoints or random movement)
(@CGUID+24, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3455.718017578125, -425.079864501953125, 6.864545822143554687, 2.622152566909790039, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+25, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3588.538330078125, -466.774322509765625, 6.787623882293701171, 2.13268446922302246, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 288674 - [DNT] Carry Barrel) (possible waypoints or random movement)
(@CGUID+26, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3489.530517578125, -442.19097900390625, 7.687883377075195312, 3.295198678970336914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+27, 148878, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3497.884033203125, -510.926239013671875, 1, 0.091147646307945251, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Bound Rain (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3457.271728515625, -425.805572509765625, 6.73656463623046875, 0.801665067672729492, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 288674 - [DNT] Carry Barrel) (possible waypoints or random movement)
(@CGUID+29, 148878, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3472.743408203125, -457.288360595703125, 6.7742919921875, 3.258090019226074218, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Rain (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+30, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3590.650146484375, -462.583343505859375, 6.956211566925048828, 3.447292327880859375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+31, 148878, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3462.687255859375, -520.73974609375, 1, 3.509704828262329101, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Bound Rain (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 148884, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3616.08251953125, -418.94964599609375, 7.518727779388427734, 4.002597808837890625, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Hearth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 191749 - Giant Growth - 200%, 170528 - Fire Channeling)
(@CGUID+33, 150582, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3435.618896484375, -464.8194580078125, 11.56913375854492187, 6.254444122314453125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Hurricane (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+34, 149460, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3476.838623046875, -478.661468505859375, 6.219222068786621093, 2.722713708877563476, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Thornspeaker Adept (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 13236 - Nature Channeling)
(@CGUID+35, 149460, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3469.3447265625, -472.720489501953125, 6.302554130554199218, 0.32438632845878601, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Thornspeaker Adept (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 289899 - [DNT] Thornspeaker Channel)
(@CGUID+36, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3513.830078125, -393.169097900390625, 6.540601253509521484, 3.478809356689453125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292545 - [DNT] Carry Metal Bars) (possible waypoints or random movement)
(@CGUID+37, 149460, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3462.733642578125, -477.201385498046875, 6.219220638275146484, 0.312385052442550659, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Thornspeaker Adept (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 13236 - Nature Channeling) (possible waypoints or random movement)
(@CGUID+38, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3528.978759765625, -457.4312744140625, 55.34879684448242187, 2.109078407287597656, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+39, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3540.0009765625, -439.717010498046875, 8.481699943542480468, 3.335588455200195312, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+40, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3518.552734375, -468.701080322265625, 67.2623443603515625, 2.680313825607299804, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+41, 149459, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3463.3701171875, -454.567657470703125, 6.755833148956298828, 0.222221463918685913, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Algerson Lumberjack (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 289903 - [DNT] Log Carry) (possible waypoints or random movement)
(@CGUID+42, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3528.45703125, -477.126068115234375, 47.25809860229492187, 2.228374242782592773, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+43, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3517.272216796875, -393.648651123046875, 20.6115875244140625, 4.998493194580078125, 120, 12, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+44, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3506.4697265625, -383.203125, 6.22986602783203125, 3.63104104995727539, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292545 - [DNT] Carry Metal Bars) (possible waypoints or random movement)
(@CGUID+45, 148884, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3503.40966796875, -384.557281494140625, 8.117907524108886718, 4.857143402099609375, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Hearth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 191749 - Giant Growth - 200%, 170528 - Fire Channeling)
(@CGUID+46, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3520.783203125, -398.169830322265625, 6.540468215942382812, 4.102970123291015625, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3517.9482421875, -446.911712646484375, 46.40807342529296875, 2.680040597915649414, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+48, 148878, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3516.319580078125, -402.039947509765625, 6.549485683441162109, 1.679615259170532226, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Rain (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+49, 148870, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3489.651123046875, -431.8975830078125, 6.53093576431274414, 3.100516080856323242, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Dorian Atwater (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 133464 - Read Scroll)
(@CGUID+50, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3489.182373046875, -446.359375, 7.53641510009765625, 3.055814266204833984, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+51, 148798, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3487.052001953125, -431.736114501953125, 6.4989471435546875, 6.203412055969238281, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Lady Jaina Proudmoore (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+52, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3491.800048828125, -452.0360107421875, 20.70771598815917968, 4.765447139739990234, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292541 - [DNT] Elemental Channel Log Carry) (possible waypoints or random movement)
(@CGUID+53, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3504.7275390625, -390.00347900390625, 9.72844696044921875, 1.918662548065185546, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+54, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3474.4619140625, -439.642120361328125, 6.247789382934570312, 2.126332283020019531, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3611.023681640625, -421.25494384765625, 5.454006195068359375, 0.571752548217773437, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 288674 - [DNT] Carry Barrel) (possible waypoints or random movement)
(@CGUID+56, 148879, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3619.7431640625, -420.501739501953125, 5.454006195068359375, 2.660472393035888671, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Earth (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292545 - [DNT] Carry Metal Bars) (possible waypoints or random movement)
(@CGUID+57, 149470, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3612.853271484375, -423.5225830078125, 8.819629669189453125, 1.064115047454833984, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Bound Sky (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 292540 - [DNT] Elemental Channel Wind)
(@CGUID+58, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3570.1259765625, -510.1580810546875, 0.140338972210884094, 6.240226268768310546, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+59, 150594, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3574.756103515625, -513.5225830078125, 0.222981601953506469, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Fog Ward (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@CGUID+60, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3566.899658203125, -521.04681396484375, 0.140679240226745605, 3.409952163696289062, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+61, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3578.470947265625, -508.69049072265625, 0.139513865113258361, 0.163397297263145446, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+62, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3576.797607421875, -523.86578369140625, 0.139753475785255432, 0.790193736553192138, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+63, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3582.564697265625, -516.5252685546875, 0.21472063660621643, 2.839137792587280273, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3600, -452.083984375, 6.066155433654785156, 1.819838643074035644, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3601.039794921875, -446.986602783203125, 5.700663566589355468, 0.271035879850387573, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+66, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3606.784423828125, -451.95416259765625, 5.96304178237915039, 5.612282276153564453, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+67, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3606.9912109375, -459.939453125, 6.558324813842773437, 1.298968195915222167, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3601.67041015625, -460.162353515625, 6.545730113983154296, 3.258351087570190429, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+69, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3632.75927734375, -491.807220458984375, 6.588262081146240234, 0.5032196044921875, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3640.511474609375, -495.920867919921875, 6.588136672973632812, 1.631531357765197753, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+71, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3634.2578125, -501.454925537109375, 6.666406154632568359, 2.179827213287353515, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3642.28076171875, -510.402862548828125, 6.588134765625, 0.790786802768707275, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 151030, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3627.17919921875, -512.40008544921875, 6.533264636993408203, 1.647073268890380859, 120, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 54904), -- Purified Waters (Area: Port Fogtide - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 134696, 1643, 9042, 9578, '0', 12651, 0, 0, 1, 3346.368896484375, -378.435760498046875, 18.62731361389160156, 1.479342818260192871, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Marla Featherfoot (Area: Port Fogtide - Difficulty: 0) CreateObject1 - !!! already present in database !!!
(@CGUID+75, 134747, 1643, 9042, 9578, '0', 12651, 0, 0, 1, 3352.390625, -351.68402099609375, 15.71787548065185546, 4.428467273712158203, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Tidesage Defector (Area: Port Fogtide - Difficulty: 0) CreateObject1 - !!! already present in database !!!
(@CGUID+76, 142634, 1643, 9042, 9578, '0', 12651, 0, 0, 0, 3335.232666015625, -372.78125, 13.08397769927978515, 1.577361583709716796, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904), -- Sister Alison (Area: Port Fogtide - Difficulty: 0) CreateObject1 - !!! already present in database !!!
(@CGUID+77, 134747, 1643, 9042, 9578, '0', 12651, 0, 0, 1, 3352.244873046875, -342.774322509765625, 16.65855789184570312, 5.851102352142333984, 120, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 54904), -- Tidesage Defector (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 247866 - Set Health % (Uses Override Points) (No Health Regen)) - !!! already present in database !!!
(@CGUID+78, 134747, 1643, 9042, 9578, '0', 12651, 0, 0, 1, 3347.98876953125, -343.15972900390625, 16.64837265014648437, 3.745503902435302734, 120, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 54904), -- Tidesage Defector (Area: Port Fogtide - Difficulty: 0) CreateObject1 (Auras: 247866 - Set Health % (Uses Override Points) (No Health Regen)) - !!! already present in database !!!
(@CGUID+79, 142609, 1643, 9042, 9579, '0', 12651, 0, 0, 0, 3345.7041015625, -340.84027099609375, 15.88854312896728515, 0.272221922874450683, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54904); -- Handyman Gareth (Area: Tidecross - Difficulty: 0) CreateObject1 - !!! already present in database !!!

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bound Sky
(@CGUID+9, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+13, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bound Sky
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Fog Ward
(@CGUID+22, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+26, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+27, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bound Rain
(@CGUID+31, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bound Rain
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Hurricane
(@CGUID+38, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+40, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+42, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+43, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Bound Sky
(@CGUID+47, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+50, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+52, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292541'), -- Bound Sky - 292541 - [DNT] Elemental Channel Log Carry
(@CGUID+75, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0, 0, ''), -- Tidesage Defector - !!! already present in database !!!
(@CGUID+77, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '247866'), -- Tidesage Defector - 247866 - Set Health % (Uses Override Points) (No Health Regen) - !!! already present in database !!!
(@CGUID+78, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '247866'); -- Tidesage Defector - 247866 - Set Health % (Uses Override Points) (No Health Regen) - !!! already present in database !!!

DELETE FROM `creature_template_addon` WHERE `entry` IN (148798 /*148798 (Lady Jaina Proudmoore)*/, 148870 /*148870 (Dorian Atwater)*/, 148884 /*148884 (Bound Hearth)*/, 148878 /*148878 (Bound Rain)*/, 148918 /*148918 (Fog Ward)*/, 149459 /*149459 (Algerson Lumberjack) - [DNT] Log Carry*/, 148879 /*148879 (Bound Earth) - [DNT] Carry Barrel*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(148798, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 148798 (Lady Jaina Proudmoore)
(148870, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '133464'), -- 148870 (Dorian Atwater) - Read Scroll
(148884, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '191749'), -- 148884 (Bound Hearth) - Giant Growth - 200%, 170528 Fire Channeling
(148878, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 148878 (Bound Rain)
(148918, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 148918 (Fog Ward)
-- (149460, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '13236'), -- 149460 (Thornspeaker Adept) - Nature Channeling
-- (@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '289899'), -- Thornspeaker Adept - 289899 - [DNT] Thornspeaker Channel
-- (149459, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '289903'), -- 149459 (Algerson Lumberjack) - [DNT] Log Carry
-- (148879, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '288674'), -- 148879 (Bound Earth) - [DNT] Carry Barrel
-- (@CGUID+56, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '292545'), -- Bound Earth - 292545 - [DNT] Carry Metal Bars

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (148798,149459));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(148798, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- Lady Jaina Proudmoore
(149459, 1, 109579, 0, 0, 0, 0, 0, 0, 0, 0, 54904); -- Algerson Lumberjack

UPDATE `creature_equip_template` SET `VerifiedBuild`=54904 WHERE (`ID`=1 AND `CreatureID` IN (134696,134747));

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=148798 AND `MenuID`=23722);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(148798, 23722, 54904); -- Lady Jaina Proudmoore

UPDATE `creature_template_gossip` SET `VerifiedBuild`=54904 WHERE (`CreatureID`=142609 AND `MenuID`=23171) OR (`CreatureID`=148873 AND `MenuID`=23726);

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 167409, 0, 0, 0, 0, 0, 0, 0, 54904); -- 148798 (Lady Jaina Proudmoore)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23722 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23722, @NPCTEXTID+0, 54904); -- 148798 (Lady Jaina Proudmoore)

UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=134747; -- Tidesage Defector
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry` IN (150594, 148918, 150593); -- Fog Ward
UPDATE `creature_template` SET `faction`=2992, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=148798; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=148884; -- Bound Hearth
UPDATE `creature_template` SET `faction`=1683, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=149460; -- Thornspeaker Adept
UPDATE `creature_template` SET `faction`=2909, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=149459; -- Algerson Lumberjack
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=148878; -- Bound Rain
UPDATE `creature_template` SET `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=151030; -- Purified Waters
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=149470; -- Bound Sky

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry` IN(150593, 150594, 148918);

UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54904 WHERE (`Entry`=135238 AND `DifficultyID`=0); -- 135238 (War Supply Crate) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=483, `StaticFlags1`=805306368, `StaticFlags3`=262144, `VerifiedBuild`=54904 WHERE (`Entry`=138694 AND `DifficultyID`=0); -- 138694 (Zeppelin) - CanSwim, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=794, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=148798 AND `DifficultyID`=0); -- 148798 (Lady Jaina Proudmoore) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=148878 AND `DifficultyID`=0); -- 148878 (Bound Rain) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=805306368, `VerifiedBuild`=54904 WHERE (`Entry`=148884 AND `DifficultyID`=0); -- 148884 (Bound Hearth) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=805306624, `VerifiedBuild`=54904 WHERE (`Entry`=148918 AND `DifficultyID`=0); -- 148918 (Fog Ward) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=149459 AND `DifficultyID`=0); -- 149459 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=149460 AND `DifficultyID`=0); -- 149460 (Thornspeaker Adept) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=805306368, `VerifiedBuild`=54904 WHERE (`Entry`=149470 AND `DifficultyID`=0); -- 149470 (Bound Sky) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=805306624, `VerifiedBuild`=54904 WHERE (`Entry`=150593 AND `DifficultyID`=0); -- 150593 (Fog Ward) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=805306624, `VerifiedBuild`=54904 WHERE (`Entry`=150594 AND `DifficultyID`=0); -- 150594 (Fog Ward) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54904 WHERE (`Entry`=151030 AND `DifficultyID`=0); -- 151030 (Purified Waters) - CanSwim

DELETE FROM `creature_model_info` WHERE `DisplayID`=90999;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(90999, 0.347222000360488891, 1.5, 0, 54904);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+67;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 317060, 1643, 9042, 9578, '0', 12651, 0, 3605.1337890625, -423.102447509765625, 5.454006671905517578, 3.952234983444213867, 0, 0, -0.918975830078125, 0.39431387186050415, 120, 255, 1, 54904), -- [DNT] Mine Cart (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+2, 317060, 1643, 9042, 9578, '0', 12651, 0, 3496.803955078125, -393.70660400390625, 6.37481546401977539, 4.8787078857421875, 0, 0, -0.64592838287353515, 0.763398051261901855, 120, 255, 1, 54904), -- [DNT] Mine Cart (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+3, 317047, 1643, 9042, 9578, '0', 12651, 0, 3427.869873046875, -441.958343505859375, 10.69652080535888671, 0.440376549959182739, 0, 0, 0.218413352966308593, 0.975856363773345947, 120, 255, 1, 54904), -- [DNT] Log Pile 02 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+4, 317058, 1643, 9042, 9578, '0', 12651, 0, 3474.197998046875, -474.18402099609375, 6.21922159194946289, 0.855132997035980224, 0, 0, 0.4146575927734375, 0.909977495670318603, 120, 255, 1, 54904), -- [DNT] Witch Organ Energy (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+5, 317050, 1643, 9042, 9578, '0', 12651, 0, 3588.62060546875, -462.73089599609375, 6.505585193634033203, 0.162689283490180969, 0, 0, 0.081254959106445312, 0.996693372726440429, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+6, 322682, 1643, 9042, 9578, '0', 12651, 0, 3519.302978515625, -388.16839599609375, 6.27419137954711914, 4.872119903564453125, 0, 0, -0.64843940734863281, 0.761266231536865234, 120, 255, 1, 54904), -- [DNT] Metal Bars Full (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+7, 322682, 1643, 9042, 9578, '0', 12651, 0, 3619.255126953125, -433.118072509765625, 5.454006671905517578, 4.460577964782714843, 0, 0, -0.79030323028564453, 0.612715899944305419, 120, 255, 1, 54904), -- [DNT] Metal Bars Full (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+8, 317050, 1643, 9042, 9578, '0', 12651, 0, 3454.1728515625, -423.51910400390625, 6.94265604019165039, 1.003343939781188964, 0, 0, 0.480892181396484375, 0.876779735088348388, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+9, 317050, 1643, 9042, 9578, '0', 12651, 0, 3453.853271484375, -424.03125, 8.038369178771972656, 1.003343939781188964, 0, 0, 0.480892181396484375, 0.876779735088348388, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+10, 317050, 1643, 9042, 9578, '0', 12651, 0, 3587.615478515625, -462.82464599609375, 8.753516197204589843, 0.162689283490180969, 0, 0, 0.081254959106445312, 0.996693372726440429, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+11, 322682, 1643, 9042, 9578, '0', 12651, 0, 3618.166748046875, -432.864593505859375, 5.454006671905517578, 4.460577964782714843, 0, 0, -0.79030323028564453, 0.612715899944305419, 120, 255, 1, 54904), -- [DNT] Metal Bars Full (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+12, 322682, 1643, 9042, 9578, '0', 12651, 0, 3517.189208984375, -388.442718505859375, 6.229865074157714843, 4.872119903564453125, 0, 0, -0.64843940734863281, 0.761266231536865234, 120, 255, 1, 54904), -- [DNT] Metal Bars Full (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+13, 316864, 1643, 9042, 9578, '0', 12651, 0, 3420.49560546875, -448.197906494140625, 11.59019184112548828, 5.678603649139404296, 0.020766735076904296, 0.066593170166015625, -0.2969827651977539, 0.95233154296875, 120, 255, 1, 54904), -- [DNT] Wagon (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+14, 317061, 1643, 9042, 9578, '0', 12651, 0, 3620.67529296875, -431.086822509765625, 5.454006671905517578, 4.48772287368774414, 0, 0, -0.78191471099853515, 0.623385429382324218, 120, 255, 1, 54904), -- [DNT] Metal Bars (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+15, 317050, 1643, 9042, 9578, '0', 12651, 0, 3452.053955078125, -426.951385498046875, 6.906596660614013671, 1.003343939781188964, 0, 0, 0.480892181396484375, 0.876779735088348388, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+16, 317048, 1643, 9042, 9578, '0', 12651, 0, 3419.987060546875, -457.842010498046875, 10.96670246124267578, 0.845271706581115722, 0, 0, 0.410165786743164062, 0.91201096773147583, 120, 255, 1, 54904), -- [DNT] Log Pile 01 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+17, 317061, 1643, 9042, 9578, '0', 12651, 0, 3511.8671875, -388.414947509765625, 6.22986602783203125, 4.899263858795166015, 0, 0, -0.63804817199707031, 0.769996464252471923, 120, 255, 1, 54904), -- [DNT] Metal Bars (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+18, 317060, 1643, 9042, 9578, '0', 12651, 0, 3605.58154296875, -420.0850830078125, 5.454006671905517578, 4.279789447784423828, 0, 0, -0.84238719940185546, 0.538872718811035156, 120, 255, 1, 54904), -- [DNT] Mine Cart (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+19, 317060, 1643, 9042, 9578, '0', 12651, 0, 3499.0625, -393.348968505859375, 6.383344650268554687, 4.8515625, 0, 0, -0.65622997283935546, 0.75456094741821289, 120, 255, 1, 54904), -- [DNT] Mine Cart (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+20, 322187, 1643, 9042, 9578, '0', 12651, 0, 3516.306396484375, -399.93402099609375, 6.460001468658447265, 0, 0, 0, 0, 1, 120, 255, 1, 54904), -- Fog Ward (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+22, 317053, 1643, 9042, 9578, '0', 12651, 0, 3470.454833984375, -476.154510498046875, 6.219220638275146484, 0, 0, 0, 0, 1, 120, 255, 1, 54904), -- [DNT] Witch Energy (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+23, 317050, 1643, 9042, 9578, '0', 12651, 0, 3587.61376953125, -462.708343505859375, 7.64171600341796875, 4.88246011734008789, 0, 0, -0.64449501037597656, 0.764608502388000488, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+24, 317058, 1643, 9042, 9578, '0', 12651, 0, 3467.04248046875, -469.805572509765625, 6.2233428955078125, 4.890765190124511718, 0, 0, -0.64131450653076171, 0.767278075218200683, 120, 255, 1, 54904), -- [DNT] Witch Organ Energy (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+25, 317050, 1643, 9042, 9578, '0', 12651, 0, 3453.12939453125, -425.25, 9.150170326232910156, 2.566761016845703125, 0, 0, 0.958979606628417968, 0.283475011587142944, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+26, 317050, 1643, 9042, 9578, '0', 12651, 0, 3587.900146484375, -464.2100830078125, 7.64171600341796875, 4.88246011734008789, 0, 0, -0.64449501037597656, 0.764608502388000488, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+27, 317050, 1643, 9042, 9578, '0', 12651, 0, 3588.009521484375, -464.810760498046875, 6.54600381851196289, 4.88246011734008789, 0, 0, -0.64449501037597656, 0.764608502388000488, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+28, 322682, 1643, 9042, 9578, '0', 12651, 0, 3518.287353515625, -388.239593505859375, 7.19522857666015625, 4.872119903564453125, 0, 0, -0.64843940734863281, 0.761266231536865234, 120, 255, 1, 54904), -- [DNT] Metal Bars Full (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+29, 322188, 1643, 9042, 9578, '0', 12651, 0, 3574.756103515625, -513.5225830078125, 0.139648258686065673, 0, 0, 0, 0, 1, 120, 255, 1, 54904), -- Fog Ward (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+30, 317050, 1643, 9042, 9578, '0', 12651, 0, 3453.729248046875, -425.708343505859375, 6.909856319427490234, 2.566761016845703125, 0, 0, 0.958979606628417968, 0.283475011587142944, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+31, 317050, 1643, 9042, 9578, '0', 12651, 0, 3453.052978515625, -425.3350830078125, 8.038369178771972656, 1.003343939781188964, 0, 0, 0.480892181396484375, 0.876779735088348388, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+32, 317061, 1643, 9042, 9578, '0', 12651, 0, 3618.647705078125, -430.62847900390625, 5.454006671905517578, 6.094811916351318359, 0, 0, -0.09404754638671875, 0.995567739009857177, 120, 255, 1, 54904), -- [DNT] Metal Bars (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+33, 317050, 1643, 9042, 9578, '0', 12651, 0, 3587.268310546875, -460.84027099609375, 6.509944915771484375, 4.88246011734008789, 0, 0, -0.64449501037597656, 0.764608502388000488, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+35, 317060, 1643, 9042, 9578, '0', 12651, 0, 3606.849853515625, -424.8819580078125, 5.454006671905517578, 3.925094366073608398, 0, 0, -0.92424201965332031, 0.381807148456573486, 120, 255, 1, 54904), -- [DNT] Mine Cart (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+36, 317050, 1643, 9042, 9578, '0', 12651, 0, 3452.32373046875, -424.642364501953125, 6.9022369384765625, 2.566761016845703125, 0, 0, 0.958979606628417968, 0.283475011587142944, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+37, 317048, 1643, 9042, 9578, '0', 12651, 0, 3420.963623046875, -448.338531494140625, 13.66962909698486328, 0.980639398097991943, 0.061537742614746093, 0.032848358154296875, 0.469760894775390625, 0.880033373832702636, 120, 255, 1, 54904), -- [DNT] Log Pile 01 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+39, 317047, 1643, 9042, 9578, '0', 12651, 0, 3473.877685546875, -473.78125, 6.21922159194946289, 0, 0, 0, 0, 1, 120, 255, 1, 54904), -- [DNT] Log Pile 02 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+40, 317047, 1643, 9042, 9578, '0', 12651, 0, 3485.432373046875, -445.880218505859375, 6.474015712738037109, 3.138830423355102539, 0, 0, 0.999999046325683593, 0.001381067908369004, 120, 255, 1, 54904), -- [DNT] Log Pile 02 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+41, 316789, 1643, 9042, 9578, '0', 12651, 0, 3472.012939453125, -454.977447509765625, 7.150908470153808593, 0, 0, 0, 0, 1, 120, 255, 1, 54904), -- Fog Ward (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+42, 317050, 1643, 9042, 9578, '0', 12651, 0, 3586.86376953125, -462.88714599609375, 6.513204097747802734, 0.162689283490180969, 0, 0, 0.081254959106445312, 0.996693372726440429, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+43, 317062, 1643, 9042, 9578, '0', 12651, 0, 3616.02685546875, -419.102447509765625, 5.454006671905517578, 2.468703746795654296, 0, 0, 0.943934440612792968, 0.330132931470870971, 120, 255, 1, 54904), -- [DNT] Forge (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+46, 322682, 1643, 9042, 9578, '0', 12651, 0, 3620.212646484375, -433.463531494140625, 5.454006671905517578, 4.460577964782714843, 0, 0, -0.79030323028564453, 0.612715899944305419, 120, 255, 1, 54904), -- [DNT] Metal Bars Full (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+48, 317050, 1643, 9042, 9578, '0', 12651, 0, 3452.290771484375, -426.486114501953125, 8.038369178771972656, 1.003343939781188964, 0, 0, 0.480892181396484375, 0.876779735088348388, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+49, 317050, 1643, 9042, 9578, '0', 12651, 0, 3587.403564453125, -461.345489501953125, 7.64171600341796875, 4.88246011734008789, 0, 0, -0.64449501037597656, 0.764608502388000488, 120, 255, 1, 54904), -- [DNT] Large Crate (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+50, 322681, 1643, 9042, 9578, '0', 12651, 0, 3522.131103515625, -463.586822509765625, 3.138062238693237304, 1.578130006790161132, 0, 0, 0.709694862365722656, 0.704509198665618896, 120, 255, 1, 54904), -- In Progress Ship (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+53, 317062, 1643, 9042, 9578, '0', 12651, 0, 3503.478271484375, -384.696197509765625, 6.229865550994873046, 3.323264598846435546, 0, 0, -0.99587726593017578, 0.090710975229740142, 120, 255, 1, 54904), -- [DNT] Forge (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+54, 317061, 1643, 9042, 9578, '0', 12651, 0, 3509.826416015625, -388.805572509765625, 6.229865550994873046, 0.22316482663154602, 0, 0, 0.11135101318359375, 0.993781149387359619, 120, 255, 1, 54904), -- [DNT] Metal Bars (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+55, 317048, 1643, 9042, 9578, '0', 12651, 0, 3467.9541015625, -476.548614501953125, 6.219220638275146484, 4.259103298187255859, 0, 0, -0.8479156494140625, 0.530131161212921142, 120, 255, 1, 54904), -- [DNT] Log Pile 01 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+56, 317060, 1643, 9042, 9578, '0', 12651, 0, 3493.979248046875, -393.89410400390625, 6.397325992584228515, 0.1007162407040596, 0, 0, 0.050336837768554687, 0.998732328414916992, 120, 255, 1, 54904), -- [DNT] Mine Cart (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+57, 317048, 1643, 9042, 9578, '0', 12651, 0, 3467.202392578125, -469.739593505859375, 6.222222328186035156, 1.932656168937683105, 0, 0, 0.822804450988769531, 0.568324625492095947, 120, 255, 1, 54904), -- [DNT] Log Pile 01 No Phasing (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+58, 296059, 1643, 9042, 9578, '0', 12651, 0, 3534.8984375, -243.309036254882812, 67.08513641357421875, 6.073750019073486328, 0, 0, -0.10452651977539062, 0.9945220947265625, 120, 255, 1, 54904), -- Campfire (Area: Port Fogtide - Difficulty: 0) CreateObject1
(@OGUID+59, 296619, 1643, 9042, 9578, '0', 12651, 0, 3531.794189453125, -231.373260498046875, 67.33464813232421875, 4.398229122161865234, 0, 0, -0.80901718139648437, 0.587784945964813232, 120, 255, 1, 54904); -- Chair (Area: Port Fogtide - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template` WHERE `entry` IN (316789 /*Fog Ward*/, 322681 /*In Progress Ship*/, 322188 /*Fog Ward*/, 317050 /*[DNT] Large Crate*/, 317047 /*[DNT] Log Pile 02 No Phasing*/, 317060 /*[DNT] Mine Cart*/, 317048 /*[DNT] Log Pile 01 No Phasing*/, 317061 /*[DNT] Metal Bars*/, 317058 /*[DNT] Witch Organ Energy*/, 317062 /*[DNT] Forge*/, 322682 /*[DNT] Metal Bars Full*/, 322187 /*Fog Ward*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(316789, 10, 50437, 'Fog Ward', 'questinteract', 'Placing', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 288759, 0, 0, 0, 145722, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 674, 54904), -- Fog Ward
(322681, 43, 52525, 'In Progress Ship', '', '', '', 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- In Progress Ship
(322188, 10, 50437, 'Fog Ward', 'questinteract', 'Placing', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 292015, 0, 0, 0, 145722, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 674, 54904), -- Fog Ward
(317050, 5, 44888, '[DNT] Large Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Large Crate
(317047, 5, 45298, '[DNT] Log Pile 02 No Phasing', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Log Pile 02 No Phasing
(317060, 5, 17776, '[DNT] Mine Cart', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Mine Cart
(317048, 5, 46177, '[DNT] Log Pile 01 No Phasing', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Log Pile 01 No Phasing
(317061, 5, 6463, '[DNT] Metal Bars', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Metal Bars
(317058, 5, 54571, '[DNT] Witch Organ Energy', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Witch Organ Energy
(317062, 5, 41814, '[DNT] Forge', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Forge
(322682, 5, 6458, '[DNT] Metal Bars Full', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54904), -- [DNT] Metal Bars Full
(322187, 10, 50437, 'Fog Ward', 'questinteract', 'Placing', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 292014, 0, 0, 0, 145722, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 674, 54904); -- Fog Ward

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (322681 /*In Progress Ship*/, 316789 /*Fog Ward*/, 322188 /*Fog Ward*/, 322187 /*Fog Ward*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(322681, 0, 1048608, 0, 0), -- In Progress Ship
(316789, 0, 262144, 0, 0), -- Fog Ward
(322188, 0, 262144, 0, 0), -- Fog Ward
(322187, 0, 262144, 0, 0); -- Fog Ward

-- (149470, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '292540'); -- 149470 (Bound Sky) - [DNT] Elemental Channel Wind
UPDATE `creature` SET `StringId`='wind_channel' WHERE `guid` IN(@CGUID+0, @CGUID+3, @CGUID+8, @CGUID+17, @CGUID+39, @CGUID+53, @CGUID+57);

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
-- (@CGUID+0, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL), -- Bound Sky
-- (@CGUID+3, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL), -- Bound Sky
-- (@CGUID+8, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL), -- Bound Sky
-- (@CGUID+17, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL), -- Bound Sky
-- (@CGUID+39, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL), -- Bound Sky
(@CGUID+31, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL), -- Bound Rain
(@CGUID+27, 0, 536870912, NULL, NULL, NULL, NULL, NULL, NULL, NULL); -- Bound Rain

-- Algerson Lumberjack smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 149459;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+20), -(@CGUID+41), -(@CGUID+11));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+20), 0, 0, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 80, 14945900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Algerson Lumberjack #0 (14945900) (update out of combat)'),
(-(@CGUID+20), 0, 1, 0, '', 34, 0, 100, 0, 2, 15, 0, 0, 80, 14945901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 15 - Self: Start timed action list id #Algerson Lumberjack #1 (14945901) (update out of combat)'),
(-(@CGUID+41), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 14945900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #Algerson Lumberjack #0 (14945900) (update out of combat)'),
(-(@CGUID+41), 0, 1, 0, '', 34, 0, 100, 0, 2, 11, 0, 0, 80, 14945901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 11 - Self: Start timed action list id #Algerson Lumberjack #1 (14945901) (update out of combat)'),
(-(@CGUID+11), 0, 0, 0, '', 34, 0, 100, 0, 2, 4, 0, 0, 80, 14945900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #Algerson Lumberjack #0 (14945900) (update out of combat)'),
(-(@CGUID+11), 0, 1, 0, '', 34, 0, 100, 0, 2, 19, 0, 0, 80, 14945901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 19 - Self: Start timed action list id #Algerson Lumberjack #1 (14945901) (update out of combat)');

-- Timed list 14945900 smart ai
SET @ENTRY := 14945900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 28, 289903, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell  289903'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Remove stand state KNEEL');

-- Timed list 14945901 smart ai
SET @ENTRY := 14945901;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 289903, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Cast spell  289903 on Self'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove stand state KNEEL');

-- Thornspeaker Adept smart ai
SET @ENTRY := 149460;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+16), -(@CGUID+37));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 13236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  13236 on Self'),
(-(@CGUID+16), 0, 0, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 80, 14946000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #Thornspeaker Adept #0 (14946000) (update out of combat)'),
(-(@CGUID+16), 0, 1, 0, '', 34, 0, 100, 0, 2, 7, 0, 0, 80, 14946000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 7 - Self: Start timed action list id #Thornspeaker Adept #0 (14946000) (update out of combat)'),
(-(@CGUID+37), 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 80, 14946000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Thornspeaker Adept #0 (14946000) (update out of combat)'),
(-(@CGUID+37), 0, 1, 0, '', 34, 0, 100, 0, 2, 4, 0, 0, 80, 14946000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #Thornspeaker Adept #0 (14946000) (update out of combat)');

-- Timed list 14946000 smart ai
SET @ENTRY := 14946000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 11, 13236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  13236 on Self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 6000, 6000, 0, 0, 92, 0, 13236, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Interrupt casted spell  13236');

UPDATE `creature` SET `StringId` = "NatureChannel" WHERE `guid` IN (@CGUID+35, @CGUID+34);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'NatureChannel', 0, 'Scripted creature has StringId ''NatureChannel''');

-- Bound Rain smart ai
SET @ENTRY := 148878;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+4), -(@CGUID+19), -(@CGUID+29), -(@CGUID+48));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+4), 0, 0, 0, '', 34, 0, 100, 0, 2, 30, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 30 - Self: Cast spell 288669 on self'),
(-(@CGUID+4), 0, 1, 0, '', 34, 0, 100, 0, 2, 46, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 46 - Self: Cast spell 288669 on self'),
(-(@CGUID+4), 0, 2, 0, '', 34, 0, 100, 0, 2, 54, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 54 - Self: Cast spell 288669 on self'),
(-(@CGUID+4), 0, 3, 0, '', 34, 0, 100, 0, 2, 64, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 64 - Self: Cast spell 288669 on self'),
(-(@CGUID+19), 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Cast spell 288669 on self'),
(-(@CGUID+19), 0, 1, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Cast spell 288669 on self'),
(-(@CGUID+29), 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Cast spell 288669 on self'),
(-(@CGUID+29), 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Cast spell 288669 on self'),
(-(@CGUID+48), 0, 0, 0, '', 34, 0, 100, 0, 2, 1, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Cast spell 288669 on self'),
(-(@CGUID+48), 0, 1, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 85, 288669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Cast spell 288669 on self');

-- Bound Earth smart ai
SET @ENTRY := 148879;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+36), -(@CGUID+25), -(@CGUID+14), -(@CGUID+44), -(@CGUID+12), -(@CGUID+23), -(@CGUID+55), -(@CGUID+56));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 60, 0, 100, 0, 2000, 3000, 2000, 3000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds - Self: Play emote 35'),
(-(@CGUID+36), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start path #14887900, walk, do not repeat, Passive'),
(-(@CGUID+36), 0, 1, 0, '', 58, 0, 100, 0, 13, 14887900, 0, 0, 80, 14887900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887900 ended - Self: Start timed action list id #Bound Earth #0 (14887900) (update out of combat)'),
(-(@CGUID+36), 0, 2, 0, '', 58, 0, 100, 0, 1, 14887901, 0, 0, 80, 14887901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887901 ended - Self: Start timed action list id #Bound Earth #1 (14887901) (update out of combat)'),
(-(@CGUID+25), 0, 0, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 85, 288674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Cast spell 288674 on self'),
(-(@CGUID+25), 0, 1, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 85, 292547, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Cast spell 292547 on self'),
(-(@CGUID+14), 0, 0, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 85, 288674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Cast spell 288674 on self'),
(-(@CGUID+14), 0, 1, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 85, 292547, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Cast spell 292547 on self'),
(-(@CGUID+44), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887905, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start path #14887905, walk, do not repeat, Passive'),
(-(@CGUID+44), 0, 1, 0, '', 58, 0, 100, 0, 1, 14887905, 0, 0, 80, 14887902, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887903 ended - Self: Start timed action list id #Bound Earth #0 (14887902) (update out of combat)'),
(-(@CGUID+44), 0, 2, 0, '', 58, 0, 100, 0, 1, 14887906, 0, 0, 80, 14887903, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887902 ended - Self: Start timed action list id #Bound Earth #0 (14887903) (update out of combat)'),
(-(@CGUID+12), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887907, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start path #14887907, walk, do not repeat, Passive'),
(-(@CGUID+12), 0, 1, 0, '', 58, 0, 100, 0, 1, 14887907, 0, 0, 80, 14887904, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887907 ended - Self: Start timed action list id #Bound Earth #0 (14887904) (update out of combat)'),
(-(@CGUID+12), 0, 2, 0, '', 58, 0, 100, 0, 0, 14887908, 0, 0, 80, 14887905, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887908 ended - Self: Start timed action list id #Bound Earth #0 (14887905) (update out of combat)'),
(-(@CGUID+23), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887909, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start path #14887909, walk, do not repeat, Passive'),
(-(@CGUID+23), 0, 1, 0, '', 58, 0, 100, 0, 0, 14887909, 0, 0, 80, 14887906, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 0 of path 14887909 ended - Self: Start timed action list id #Bound Earth #6 (14887906) (update out of combat)'),
(-(@CGUID+23), 0, 2, 0, '', 58, 0, 100, 0, 9, 14887910, 0, 0, 80, 14887907, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 14887910 ended - Self: Start path #14887909, walk, do not repeat, Passive'),
(-(@CGUID+55), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 85, 288674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform - Self: Cast spell 288674 on self'),
(-(@CGUID+55), 0, 1, 2, '', 34, 0, 100, 0, 2, 1, 0, 0, 28, 288674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Remove aura due to spell  288674'),
(-(@CGUID+55), 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Play emote 35'),
(-(@CGUID+56), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887912, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Start path #14887912, walk, do not repeat, Passive'),
(-(@CGUID+56), 0, 1, 0, '', 58, 0, 100, 0, 0, 14887912, 0, 0, 80, 14887908, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887912 ended - Self: Start timed action list id #Bound Earth #0 (14887908) (update out of combat)'),
(-(@CGUID+56), 0, 2, 0, '', 58, 0, 100, 0, 1, 14887913, 0, 0, 80, 14887909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14887913 ended - Self: Start timed action list id #Bound Earth #0 (14887909) (update out of combat)');

UPDATE `creature` SET `StringId` = "EarthEmote" WHERE `guid` IN (@CGUID+24, @CGUID+30);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'EarthEmote', 0, 'Scripted creature has StringId ''EarthEmote''');

-- Timed list for Bound Earths smart ai
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (14887900, 14887901, 14887902, 14887903, 14887904, 14887905, 14887906, 14887907, 14887908, 14887909);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(14887900, 9, 0, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Cast spell  292545 on Self'),
(14887900, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887901, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #14887901, walk, do not repeat, Passive'),
(14887901, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  292545'),
(14887901, 9, 1, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, 14887900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #14887900, walk, do not repeat, Passive'),
(14887902, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 292545 on self'),
(14887902, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 14887906, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #14887906, walk, do not repeat, Passive'),
(14887903, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  292545'),
(14887903, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 35'),
(14887903, 9, 2, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 14887905, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #14887905, walk, do not repeat, Passive'),
(14887904, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 288674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  288674'),
(14887904, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 35'),
(14887904, 9, 2, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 14887908, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #14887908, walk, do not repeat, Passive'),
(14887905, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 288674, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 288674 on self'),
(14887905, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 14887907, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #14887907, walk, do not repeat, Passive'),
(14887906, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  292545'),
(14887906, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 35'),
(14887906, 9, 2, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 14887910, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #14887910, walk, do not repeat, Passive'),
(14887907, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 292545 on self'),
(14887907, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 14887909, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Start path #14887909, walk, do not repeat, Passive'),
(14887908, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 292545 on self'),
(14887908, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14887913, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #14887913, walk, do not repeat, Passive'),
(14887909, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 28, 292545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  292545'),
(14887909, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 35'),
(14887909, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, 14887912, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #14887912, walk, do not repeat, Passive');

-- Bound Sky
SET @ENTRY := 149470;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` =	(@ENTRY);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+26), -(@CGUID+50), -(@CGUID+9));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 292540, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell [DNT] Elemental Channel Wind 292540 on Self'),
(-(@CGUID+26), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 28, 292541, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Remove aura due to spell  292541'),
(-(@CGUID+26), 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 85, 292541, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Cast spell 292541 on self'),
(-(@CGUID+50), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 28, 292541, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Remove aura due to spell  292541'),
(-(@CGUID+50), 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 85, 292541, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Cast spell 292541 on self'),
(-(@CGUID+9), 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 28, 292541, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Remove aura due to spell  292541'),
(-(@CGUID+9), 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 85, 292541, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Cast spell 292541 on self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` IN(1, 2) AND `SourceEntry` = @ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @ENTRY, 0, 0, 58, 1, 0, 0, 0, 'wind_channel', 0, 'Scripted creature has StringId ''wind_channel''');

-- Bound Hearth
SET @ENTRY := 148884;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(@ENTRY);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 170528, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell Fire Channeling 170528 on Self');

-- Path for Algerson Lumberjack (@CGUID+20)
SET @ENTRY := 149459;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Algerson Lumberjack - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3473.647, -451.2865, 6.561516, NULL, 0),
(@PATH, 1, 3478.235, -449.6042, 6.219221, NULL, 0),
(@PATH, 2, 3481.59, -448.7031, 6.536415, NULL, 2494),
(@PATH, 3, 3473.661, -451.2934, 6.562116, NULL, 0),
(@PATH, 4, 3468.082, -453.4961, 6.716773, NULL, 0),
(@PATH, 5, 3463.292, -454.5955, 6.759929, NULL, 0),
(@PATH, 6, 3459.485, -455.4045, 7.019666, NULL, 0),
(@PATH, 7, 3455.644, -455.9844, 7.355092, NULL, 0),
(@PATH, 8, 3452.226, -456.0729, 7.73463, NULL, 0),
(@PATH, 9, 3448.894, -455.2135, 8.132842, NULL, 0),
(@PATH, 10, 3445.895, -454.651, 8.500305, NULL, 0),
(@PATH, 11, 3442.047, -453.5566, 8.941502, NULL, 0),
(@PATH, 12, 3438.404, -452.6892, 9.357908, NULL, 0),
(@PATH, 13, 3435.401, -452.4028, 9.737416, NULL, 0),
(@PATH, 14, 3432.429, -452.0017, 10.13694, NULL, 0),
(@PATH, 15, 3424.491, -449.6424, 10.8954, NULL, 3740),
(@PATH, 16, 3432.129, -452.0938, 10.19211, NULL, 0),
(@PATH, 17, 3435.609, -452.3056, 9.696251, NULL, 0),
(@PATH, 18, 3438.644, -452.7066, 9.32616, NULL, 0),
(@PATH, 19, 3442.172, -453.5, 8.928696, NULL, 0),
(@PATH, 20, 3445.979, -454.5278, 8.474858, NULL, 0),
(@PATH, 21, 3449.135, -455.3906, 8.107546, NULL, 0),
(@PATH, 22, 3452.285, -456.0608, 7.727624, NULL, 0),
(@PATH, 23, 3455.53, -455.9566, 7.365634, NULL, 0),
(@PATH, 24, 3459.404, -455.3368, 7.02638, NULL, 0),
(@PATH, 25, 3463.224, -454.6007, 6.764235, NULL, 0),
(@PATH, 26, 3467.997, -453.5226, 6.666351, NULL, 0);

UPDATE `creature` SET `position_x`= 3473.647, `position_y`= -451.2865, `position_z`= 6.561516, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+20;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+20, @PATH, 1);

-- Path for Algerson Lumberjack (@CGUID+41)
SET @ENTRY := 149459;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Algerson Lumberjack - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3482.253, -450.6024, 6.628699, NULL, 2394),
(@PATH, 1, 3475.704, -456.724, 6.492946, NULL, 0),
(@PATH, 2, 3471.398, -459, 6.298636, NULL, 0),
(@PATH, 3, 3467.137, -458.8021, 6.443162, NULL, 0),
(@PATH, 4, 3463.199, -458.8854, 6.687185, NULL, 0),
(@PATH, 5, 3459.597, -459.1424, 6.968785, NULL, 0),
(@PATH, 6, 3455.598, -459.1816, 7.365374, NULL, 0),
(@PATH, 7, 3451.613, -458.8457, 7.928059, NULL, 0),
(@PATH, 8, 3447.952, -457.3976, 8.425508, NULL, 0),
(@PATH, 9, 3442.836, -456.2257, 9.154314, NULL, 0),
(@PATH, 10, 3437.919, -455.6007, 9.77174, NULL, 0),
(@PATH, 11, 3422.823, -456.1441, 10.87831, NULL, 3083),
(@PATH, 12, 3437.823, -455.793, 9.775505, NULL, 0),
(@PATH, 13, 3442.789, -456.3887, 9.162362, NULL, 0),
(@PATH, 14, 3447.711, -457.2773, 8.472588, NULL, 0),
(@PATH, 15, 3451.793, -458.8924, 7.895484, NULL, 0),
(@PATH, 16, 3455.453, -459.1389, 7.390513, NULL, 0),
(@PATH, 17, 3459.637, -459.0764, 6.967345, NULL, 0),
(@PATH, 18, 3463.187, -458.9479, 6.686261, NULL, 0),
(@PATH, 19, 3467.124, -458.8576, 6.442389, NULL, 0),
(@PATH, 20, 3471.308, -459.0035, 6.301458, NULL, 0),
(@PATH, 21, 3475.763, -456.6823, 6.489424, NULL, 0),
(@PATH, 22, 3479.072, -452.4705, 6.219221, NULL, 0);

UPDATE `creature` SET `position_x`= 3482.253, `position_y`= -450.6024, `position_z`= 6.628699, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+41;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+41;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+41, @PATH, 1);

-- Path for Algerson Lumberjack (@CGUID+11)
SET @ENTRY := 149459;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Algerson Lumberjack - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3470.892, -449.0764, 6.434424, NULL, 0),
(@PATH, 1, 3474.668, -448.342, 6.222525, NULL, 0),
(@PATH, 2, 3477.788, -447.5538, 6.219221, NULL, 0),
(@PATH, 3, 3480.164, -446.6736, 6.536415, NULL, 0),
(@PATH, 4, 3481.752, -446.4201, 6.536415, NULL, 2072),
(@PATH, 5, 3474.708, -448.151, 6.22213, NULL, 0),
(@PATH, 6, 3470.791, -449.0938, 6.442294, NULL, 0),
(@PATH, 7, 3466.766, -450.1337, 6.631496, NULL, 0),
(@PATH, 8, 3463.092, -450.8507, 6.819525, NULL, 0),
(@PATH, 9, 3460.744, -451.4566, 6.957411, NULL, 0),
(@PATH, 10, 3456.73, -451.7795, 7.22099, NULL, 0),
(@PATH, 11, 3453.286, -452.2726, 7.647101, NULL, 0),
(@PATH, 12, 3449.906, -452.1563, 7.875305, NULL, 0),
(@PATH, 13, 3445.486, -451.533, 8.287125, NULL, 0),
(@PATH, 14, 3441.245, -450.6858, 8.769094, NULL, 0),
(@PATH, 15, 3437.785, -449.8264, 9.166505, NULL, 0),
(@PATH, 16, 3435.806, -448.9618, 9.359734, NULL, 0),
(@PATH, 17, 3433.493, -447.1788, 9.855354, NULL, 0),
(@PATH, 18, 3432.199, -444.5052, 10.30766, NULL, 0),
(@PATH, 19, 3431.523, -442.8941, 10.54981, 3.53958, 3320),
(@PATH, 20, 3433.505, -447.1024, 9.855389, NULL, 0),
(@PATH, 21, 3435.915, -449.1337, 9.359541, NULL, 0),
(@PATH, 22, 3441.44, -450.6649, 8.740758, NULL, 0),
(@PATH, 23, 3445.595, -451.4549, 8.266153, NULL, 0),
(@PATH, 24, 3450.061, -452.1684, 7.862629, NULL, 0),
(@PATH, 25, 3453.129, -452.2083, 7.65522, NULL, 0),
(@PATH, 26, 3456.869, -451.6597, 7.210527, NULL, 0),
(@PATH, 27, 3460.737, -451.3993, 6.95804, NULL, 0),
(@PATH, 28, 3462.997, -450.8281, 6.825394, NULL, 0),
(@PATH, 29, 3466.726, -450.3229, 6.628074, NULL, 0);

UPDATE `creature` SET `position_x`= 3470.892, `position_y`= -449.0764, `position_z`= 6.434424, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+11;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+11;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+11, @PATH, 1);

-- Path for Thornspeaker Adept (@CGUID+16)
SET @ENTRY := 149460;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Thornspeaker Adept - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3468.961, -480.7535, 6.21922, NULL, 0),
(@PATH, 1, 3467.662, -480.4462, 6.21922, NULL, 0),
(@PATH, 2, 3465.063, -479.0608, 6.219221, NULL, 0),
(@PATH, 3, 3463.709, -478.1337, 6.21922, 0.333578, 5757),
(@PATH, 4, 3467.756, -480.4063, 6.21922, NULL, 0),
(@PATH, 5, 3465.122, -479.1146, 6.219221, NULL, 0),
(@PATH, 6, 3463.701, -478.1649, 6.21922, NULL, 0),
(@PATH, 7, 3462.734, -477.2014, 6.219221, 0.382282, 6396);

UPDATE `creature` SET `position_x`= 3468.961, `position_y`= -480.7535, `position_z`= 6.21922, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+16, @PATH, 1);

-- Path for Thornspeaker Adept (@CGUID+37)
SET @ENTRY := 149460;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Thornspeaker Adept - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3462.446, -471.3403, 6.2484, NULL, 0),
(@PATH, 1, 3464.137, -473.9635, 6.219221, 5.783279, 5320),
(@PATH, 2, 3462.165, -469.9288, 6.375082, NULL, 0),
(@PATH, 3, 3463.45, -467.9097, 6.373864, NULL, 29),
(@PATH, 4, 3464.161, -467.2153, 6.372937, 5.154395, 6505);

UPDATE `creature` SET `position_x`= 3462.446, `position_y`= -471.3403, `position_z`= 6.2484, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+37;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+37;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+37, @PATH, 1);

-- Path for Bound Rain (@CGUID+4)
SET @ENTRY := 148878;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Rain - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3533.393, -397.3316, 6.536415, NULL, 0),
(@PATH, 1, 3538.171, -397.3906, 6.536415, NULL, 0),
(@PATH, 2, 3542.98, -398.25, 6.181812, NULL, 0),
(@PATH, 3, 3548.542, -401.6007, 5.032543, NULL, 0),
(@PATH, 4, 3550.645, -405.1962, 3.875688, NULL, 0),
(@PATH, 5, 3551.382, -408.941, 2.538238, NULL, 0),
(@PATH, 6, 3551.878, -413.541, 0.9812957, NULL, 0),
(@PATH, 7, 3551.825, -415.6586, 0.810083, NULL, 0),
(@PATH, 8, 3551.876, -419.6458, 0.5855561, NULL, 0),
(@PATH, 9, 3551.527, -422.5556, 0.6263947, NULL, 0),
(@PATH, 10, 3551.935, -426.7344, 0.6482621, NULL, 0),
(@PATH, 11, 3552.416, -431.9583, 0.5364151, NULL, 0),
(@PATH, 12, 3552.991, -437.8611, 0.5364151, NULL, 0),
(@PATH, 13, 3554.251, -443.0746, 0.5364151, NULL, 0),
(@PATH, 14, 3556.45, -448.3993, 0.5364151, NULL, 0),
(@PATH, 15, 3559.595, -450.2379, 0.4363933, NULL, 0),
(@PATH, 16, 3561.516, -451.8108, 0.4605311, NULL, 0),
(@PATH, 17, 3563.832, -453.4809, 0.4812481, NULL, 0),
(@PATH, 18, 3565.625, -455.209, 0.1394179, NULL, 0),
(@PATH, 19, 3566.99, -457.3316, 0.1394085, NULL, 0),
(@PATH, 20, 3568.952, -463.0191, 0.1394086, NULL, 0),
(@PATH, 21, 3569.049, -466.8195, 0.1394114, NULL, 0),
(@PATH, 22, 3568.68, -471.7465, 0.1394043, NULL, 0),
(@PATH, 23, 3567.395, -479.2274, 0.1406678, NULL, 0),
(@PATH, 24, 3566.109, -489.7135, 0.1024922, NULL, 0),
(@PATH, 25, 3565.349, -497.7222, 0.06058206, NULL, 0),
(@PATH, 26, 3565.625, -503.1649, 0.09019928, NULL, 0),
(@PATH, 27, 3566.675, -505.566, 0.1406792, NULL, 0),
(@PATH, 28, 3567.77, -508.0035, 0.1406792, NULL, 0),
(@PATH, 29, 3570.108, -510.9445, 0.1401049, NULL, 0),
(@PATH, 30, 3572.242, -512.342, 0.1394111, NULL, 3407),
(@PATH, 31, 3565.34, -497.717, 0.06008763, NULL, 0),
(@PATH, 32, 3566.239, -489.6059, 0.1113421, NULL, 0),
(@PATH, 33, 3567.564, -479.3385, 0.1406679, NULL, 0),
(@PATH, 34, 3568.757, -471.3559, 0.1394043, NULL, 0),
(@PATH, 35, 3568.299, -459.4496, 0.1394131, NULL, 0),
(@PATH, 36, 3563.456, -453.3438, 0.4759149, NULL, 0),
(@PATH, 37, 3556.595, -448.5695, 0.5364151, NULL, 0),
(@PATH, 38, 3552.894, -437.6962, 0.5364151, NULL, 0),
(@PATH, 39, 3551.841, -426.6858, 0.6581953, NULL, 0),
(@PATH, 40, 3552.075, -419.6215, 0.5842304, NULL, 0),
(@PATH, 41, 3551.463, -408.967, 2.53228, NULL, 0),
(@PATH, 42, 3549.295, -402.6059, 4.71714, NULL, 0),
(@PATH, 43, 3539.774, -397.5208, 6.445149, NULL, 0),
(@PATH, 44, 3529.023, -397.0746, 6.636003, NULL, 0),
(@PATH, 45, 3523.15, -396.4288, 6.625124, NULL, 0),
(@PATH, 46, 3518, -398.25, 6.536415, NULL, 3332),
(@PATH, 47, 3500.122, -400.5156, 6.449436, NULL, 0),
(@PATH, 48, 3493.936, -404.2309, 6.478412, NULL, 0),
(@PATH, 49, 3486.475, -412.0074, 6.73954, NULL, 0),
(@PATH, 50, 3481.77, -419.6701, 6.595543, NULL, 0),
(@PATH, 51, 3476.711, -428.7691, 6.219221, NULL, 0),
(@PATH, 52, 3474.49, -434.2517, 6.219909, NULL, 0),
(@PATH, 53, 3472.009, -441.217, 6.375546, NULL, 0),
(@PATH, 54, 3471.476, -452.6632, 6.893717, NULL, 3927),
(@PATH, 55, 3458.152, -451.7188, 7.118642, NULL, 0),
(@PATH, 56, 3455.089, -441.2743, 7.106831, NULL, 0),
(@PATH, 57, 3456.224, -432.4063, 6.970465, NULL, 0),
(@PATH, 58, 3460.393, -424.1736, 6.515959, NULL, 0),
(@PATH, 59, 3471.258, -413.2257, 6.228273, NULL, 0),
(@PATH, 60, 3479.131, -406.4323, 6.219221, NULL, 0),
(@PATH, 61, 3487.839, -400.0695, 6.460245, NULL, 0),
(@PATH, 62, 3497.904, -396.3177, 6.403718, NULL, 0),
(@PATH, 63, 3507.294, -396.0156, 6.56063, NULL, 0),
(@PATH, 64, 3513.556, -398.6528, 6.613803, NULL, 4239),
(@PATH, 65, 3519.234, -395.7222, 6.536415, NULL, 0),
(@PATH, 66, 3523.349, -395.9931, 6.639274, NULL, 0),
(@PATH, 67, 3529.184, -397.0538, 6.634171, NULL, 0);

UPDATE `creature` SET `position_x`= 3533.393, `position_y`= -397.3316, `position_z`= 6.536415, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+4;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+4, @PATH, 1);

-- Path for Bound Rain (@CGUID+19)
SET @ENTRY := 148878;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Rain - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3574.001, -516.059, 0.1401944, NULL, 0),
(@PATH, 1, 3572.991, -515.5712, 0.139734, 0.845176, 4012),
(@PATH, 2, 3577.373, -513.6823, 0.1394111, NULL, 0),
(@PATH, 3, 3576.23, -511.8976, 0.1394111, 4.005749, 4136);

UPDATE `creature` SET `position_x`= 3574.001, `position_y`= -516.059, `position_z`= 0.1401944, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+19;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+19;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+19, @PATH, 1);

-- Path for Bound Rain (@CGUID+29)
SET @ENTRY := 148878;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Rain - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3475.06, -454.5469, 6.84343, NULL, 0),
(@PATH, 1, 3474.866, -453.2379, 6.759498, 3.682426, 4830),
(@PATH, 2, 3471.944, -457.382, 6.723109, 1.543962, 3658);

UPDATE `creature` SET `position_x`= 3475.06, `position_y`= -454.5469, `position_z`= 6.84343, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+29;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+29;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+29, @PATH, 1);

-- Path for Bound Rain (@CGUID+48)
SET @ENTRY := 148878;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Rain - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3518.225, -398.3246, 6.536415, NULL, 0),
(@PATH, 1, 3516.381, -397.6059, 6.536415, 4.714788, 4354),
(@PATH, 2, 3517.406, -402.0313, 6.490189, NULL, 0),
(@PATH, 3, 3516.32, -402.0399, 6.549486, 1.642137, 4117);

UPDATE `creature` SET `position_x`= 3518.225, `position_y`= -398.3246, `position_z`= 6.536415, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+48;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+48;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+48, @PATH, 1);

-- Path for Bound Sky (@CGUID+26)
SET @ENTRY := 149470;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Sky - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3517.161, -461.7309, 9.592692, NULL, 2107),
(@PATH, 1, 3491.084, -450.1389, 6.459798, NULL, 0),
(@PATH, 2, 3489.214, -449.9549, 7.545737, 3.138, 2409);

UPDATE `creature` SET `position_x`= 3517.161, `position_y`= -461.7309, `position_z`= 9.592692, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+26;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+26, @PATH, 1);

-- Path for Bound Sky (@CGUID+50)
SET @ENTRY := 149470;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Sky - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3518.056, -442.0573, 16.0355, NULL, 1887),
(@PATH, 1, 3490.517, -446.1181, 6.459798, NULL, 0),
(@PATH, 2, 3489.182, -446.3594, 7.536415, 3.138, 1289);

UPDATE `creature` SET `position_x`= 3518.056, `position_y`= -442.0573, `position_z`= 16.0355, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+50;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+50;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+50, @PATH, 1);

-- Path for Bound Sky (@CGUID+9)
SET @ENTRY := 149470;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Sky - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3521.378, -428.9184, 22.61455, NULL, 1880),
(@PATH, 1, 3491.201, -441.9323, 6.459798, NULL, 0),
(@PATH, 2, 3489.531, -442.191, 7.687883, 3.138, 2443);

UPDATE `creature` SET `position_x`= 3521.378, `position_y`= -428.9184, `position_z`= 22.61455, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+9;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+9, @PATH, 1);

-- Path for Bound Earth (@CGUID+36)
SET @ENTRY := 148879;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3511.931, -393.8351, 6.570199, NULL, 0),
(@PATH, 1, 3506.124, -394.9375, 6.489294, NULL, 0),
(@PATH, 2, 3499.204, -395.6233, 6.423976, NULL, 0),
(@PATH, 3, 3494.426, -396.6441, 6.528594, NULL, 0),
(@PATH, 4, 3488.5, -398.592, 6.370513, NULL, 0),
(@PATH, 5, 3482.033, -402.8576, 6.474612, NULL, 0),
(@PATH, 6, 3478.32, -405.2691, 6.219221, NULL, 0),
(@PATH, 7, 3475.372, -407.717, 6.226359, NULL, 0),
(@PATH, 8, 3472.582, -410.8108, 6.22848, NULL, 0),
(@PATH, 9, 3469.283, -414.2431, 6.228461, NULL, 0),
(@PATH, 10, 3465.898, -416.8629, 6.228561, NULL, 0),
(@PATH, 11, 3462.64, -418.757, 6.22857, NULL, 0),
(@PATH, 12, 3458.815, -420.9826, 6.240358, NULL, 0),
(@PATH, 13, 3456.044, -422.3976, 6.444465, NULL, 0);

SET @ENTRY := 148879;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3516.479, -392.1597, 6.46443, NULL, 0),
(@PATH, 1, 3518.457, -390.2621, 6.229866, NULL, 0);

-- Path for Bound Earth (@CGUID+28)
SET @ENTRY := 148879;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3480.162, -404.5035, 6.219221, NULL, 0),
(@PATH, 1, 3488.044, -402.1632, 6.540464, NULL, 0),
(@PATH, 2, 3496.815, -399.6771, 6.458083, NULL, 0),
(@PATH, 3, 3507.49, -397.1389, 6.592052, NULL, 0),
(@PATH, 4, 3518.38, -394.7917, 6.536415, NULL, 0),
(@PATH, 5, 3530.015, -395.2795, 6.585658, NULL, 0),
(@PATH, 6, 3540.609, -396.4184, 6.418515, NULL, 0),
(@PATH, 7, 3550.307, -400.7135, 5.060926, NULL, 0),
(@PATH, 8, 3552.394, -407.7847, 2.918721, NULL, 0),
(@PATH, 9, 3552.875, -416.0338, 0.7338668, NULL, 0),
(@PATH, 10, 3553.655, -430.2225, 0.398216, NULL, 0),
(@PATH, 11, 3554.684, -435.566, 0.5364151, NULL, 0),
(@PATH, 12, 3558.05, -446.8455, 0.5364151, NULL, 0),
(@PATH, 13, 3561.205, -451.342, 0.4522954, NULL, 0),
(@PATH, 14, 3568.712, -458.2934, 0.139411, NULL, 0),
(@PATH, 15, 3571.131, -467.8594, 0.1390966, NULL, 0),
(@PATH, 16, 3569.934, -476.7379, 0.1396657, NULL, 0),
(@PATH, 17, 3569.233, -485.8941, 0.1406794, NULL, 0),
(@PATH, 18, 3568.577, -494.6354, 0.1406794, NULL, 0),
(@PATH, 19, 3569.347, -505.3594, 0.1406792, NULL, 0),
(@PATH, 20, 3571.029, -508.7153, 0.1405034, NULL, 2277),
(@PATH, 21, 3568.577, -494.6354, 0.1406794, NULL, 0),
(@PATH, 22, 3569.934, -476.7379, 0.1396657, NULL, 0),
(@PATH, 23, 3571.131, -467.8594, 0.1390966, NULL, 0),
(@PATH, 24, 3570.503, -461.7969, 0.1394076, NULL, 0),
(@PATH, 25, 3565.756, -455.6545, 0.139416, NULL, 0),
(@PATH, 26, 3558.05, -446.8455, 0.5364151, NULL, 0),
(@PATH, 27, 3555.622, -441.3802, 0.5364151, NULL, 0),
(@PATH, 28, 3553.666, -430.3663, 0.4293294, NULL, 0),
(@PATH, 29, 3552.933, -420.9965, 0.5984111, NULL, 0),
(@PATH, 30, 3552.684, -411.8854, 1.660688, NULL, 0),
(@PATH, 31, 3550.307, -400.7135, 5.060926, NULL, 0),
(@PATH, 32, 3544.293, -397.276, 6.148439, NULL, 0),
(@PATH, 33, 3535.788, -395.7274, 6.536415, NULL, 0),
(@PATH, 34, 3518.38, -394.7917, 6.536415, NULL, 0),
(@PATH, 35, 3507.49, -397.1389, 6.592052, NULL, 0),
(@PATH, 36, 3496.815, -399.6771, 6.458083, NULL, 0),
(@PATH, 37, 3488.044, -402.1632, 6.540464, NULL, 0),
(@PATH, 38, 3480.162, -404.5035, 6.219221, NULL, 0),
(@PATH, 39, 3467.981, -416.8264, 6.228371, NULL, 0),
(@PATH, 40, 3462.487, -420.4254, 6.22858, NULL, 0),
(@PATH, 41, 3457.272, -425.8056, 6.736565, NULL, 1375),
(@PATH, 42, 3474.909, -410.8629, 6.228006, NULL, 0);

UPDATE `creature` SET `position_x`= 3480.162, `position_y`= -404.5035, `position_z`= 6.219221, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+28;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+28;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+28, @PATH, 1, '288674');

-- Path for Bound Earth (@CGUID+25)
SET @ENTRY := 148879;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3544.935, -474.3021, 19.25133, NULL, 4857),
(@PATH, 1, 3590.013, -466.2656, 6.658915, NULL, 0),
(@PATH, 2, 3590.013, -466.2656, 6.658915, NULL, 0),
(@PATH, 3, 3588.538, -466.7743, 6.787624, 1.8435, 1819);

UPDATE `creature` SET `position_x`= 3544.935, `position_y`= -474.3021, `position_z`= 19.25133, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+25;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+25;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+25, @PATH, 1);

-- Path for Bound Earth (@CGUID+14)
SET @ENTRY := 148879;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3500.963, -478.1059, 19.45249, NULL, 3869),
(@PATH, 1, 3452.482, -430.6181, 6.96937, NULL, 0),
(@PATH, 2, 3451.159, -428.9219, 6.964963, 1.5389, 1977);

UPDATE `creature` SET `position_x`= 3500.963, `position_y`= -478.1059, `position_z`= 19.45249, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+14;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+14, @PATH, 1);

-- Path for Bound Earth (@CGUID+44)
SET @ENTRY := 148879;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3507.054, -383.0885, 6.229866, NULL, 0),
(@PATH, 1, 3510.981, -386.8038, 6.229866, NULL, 0);

SET @ENTRY := 148879;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3507.054, -383.0885, 6.229866, NULL, 0),
(@PATH, 1, 3506.47, -383.2031, 6.229866, NULL, 0);

-- Path for Bound Earth (@CGUID+12)
SET @ENTRY := 148879;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3497.281, -384.8646, 6.238497, NULL, 0),
(@PATH, 1, 3500.482, -384.4358, 6.229869, NULL, 0);

SET @ENTRY := 148879;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3496.899, -390.5799, 6.229865, NULL, 0);

-- Path for Bound Earth (@CGUID+23)
SET @ENTRY := 148879;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3615.669, -434.7344, 5.454005, NULL, 0);

SET @ENTRY := 148879;
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3612.395, -440.3715, 5.47196, NULL, 0),
(@PATH, 1, 3610.66, -443.0035, 5.518145, NULL, 0),
(@PATH, 2, 3607.953, -446.5035, 5.549231, NULL, 0),
(@PATH, 3, 3604.274, -451.8663, 5.98228, NULL, 0),
(@PATH, 4, 3600.522, -455.849, 6.308846, NULL, 0),
(@PATH, 5, 3596.877, -460.5729, 6.907444, NULL, 0),
(@PATH, 6, 3595.692, -461.9879, 7.241344, NULL, 0),
(@PATH, 7, 3592.788, -464.691, 6.828588, NULL, 0),
(@PATH, 8, 3591.228, -465.3594, 6.971381, NULL, 0),
(@PATH, 9, 3589.978, -465.4236, 6.928508, NULL, 0);

-- Path for Bound Earth (@CGUID+55)
SET @ENTRY := 148879;
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3609.346, -422.3333, 5.454006, NULL, 2484),
(@PATH, 1, 3611.65, -420.852, 5.454006, NULL, 1394);

UPDATE `creature` SET `position_x`= 3609.346, `position_y`= -422.3333, `position_z`= 5.454006, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+55;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+55;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+55, @PATH, 1);

-- Path for Bound Earth (@CGUID+56)
SET @ENTRY := 148879;
SET @PATHOFFSET := 12;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3619.617, -428.6302, 5.454007, NULL, 0);

SET @ENTRY := 148879;
SET @PATHOFFSET := 13;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Bound Earth - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3620.619, -421.4722, 5.454007, NULL, 0),
(@PATH, 1, 3619.743, -420.5017, 5.454006, NULL, 0);
