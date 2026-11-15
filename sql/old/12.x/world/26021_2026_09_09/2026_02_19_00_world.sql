SET @CGUID := 11000100;
SET @OGUID := 11000000;

SET @NPCTEXTID := 610002;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+56;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4971.126953125, -5044.8056640625, 198.989227294921875, 0.638297557830810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+1, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4985.8818359375, -5052.7900390625, 197.3719329833984375, 4.984168052673339843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+2, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5037.15478515625, -5088.328125, 197.732635498046875, 1.694147586822509765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+3, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4979.96533203125, -5053.767578125, 196.9564666748046875, 4.895166873931884765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+4, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4969.47216796875, -5038.62158203125, 199.4388580322265625, 1.328086495399475097, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+5, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5008.0712890625, -5031.01220703125, 195.62530517578125, 6.275734424591064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+6, 249999, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5001.24853515625, -5017.875, 197.1177978515625, 3.817080020904541015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Shan (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+7, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4994.5068359375, -5042.84033203125, 197.2259063720703125, 0.20652174949645996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+8, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4995.43212890625, -5034.2568359375, 196.587310791015625, 3.0001373291015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+9, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4993.98291015625, -5040.8193359375, 197.2646942138671875, 6.275734901428222656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+10, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4975.814453125, -5044.14404296875, 198.438079833984375, 1.933497548103332519, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 174127 - UseKneeling)
(@CGUID+11, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5005.212890625, -5050.2421875, 194.90032958984375, 2.907874107360839843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+12, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4996.05224609375, -5029.28125, 196.126251220703125, 4.565880298614501953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 174127 - UseKneeling)
(@CGUID+13, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 2, -4973.65625, -5029.4462890625, 198.3276214599609375, 0.573106944561004638, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+14, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5014.9912109375, -5055.88037109375, 195.7083282470703125, 4.574382781982421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+16, 249197, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5013.625, -5057.05712890625, 195.8836822509765625, 4.837193012237548828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Armorer Kalinovan (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+17, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4981.658203125, -5040.10595703125, 198.5344696044921875, 0.155717164278030395, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+18, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5040.578125, -5086.56787109375, 198.149169921875, 6.108037471771240234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+19, 237504, 0, 4922, 4922, '0', 27453, 0, 0, 1, -4993.71875, -5066.96533203125, 194.8557586669921875, 4.195984840393066406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Grand Magister Rommath (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+20, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4994.59228515625, -5045.0849609375, 197.063262939453125, 0.20652174949645996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+21, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5018.6494140625, -5043.34228515625, 195.3802032470703125, 3.794791698455810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+22, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5015.20849609375, -5061.07470703125, 196.1805572509765625, 0.947215557098388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+23, 237506, 0, 4922, 4922, '0', 27453, 0, 0, 1, -4994.673828125, -5069.345703125, 194.8094482421875, 1.30216217041015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Magister Umbric (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1249978 - [DNT] RP Chat Bubble)
(@CGUID+24, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5023.72314453125, -5063.12890625, 195.8147125244140625, 2.327123641967773437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+25, 249196, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5013.91845703125, -5060.1162109375, 196.142364501953125, 1.269718527793884277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Materialist Ophinell (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+26, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5019.76416015625, -5045.08349609375, 195.735687255859375, 1.001331925392150878, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+27, 249541, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4995.74462890625, -5061.34228515625, 195.231231689453125, 5.649254798889160156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Farstrider Helia (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+28, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4989.611328125, -5043.40966796875, 197.700103759765625, 3.332261323928833007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+29, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4969.75537109375, -5043.7880859375, 199.1597137451171875, 3.663061380386352539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+30, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5003.96337890625, -5090.8369140625, 194.5930328369140625, 3.603682994842529296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+31, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5029.5712890625, -5082.8974609375, 196.6885833740234375, 0.557758629322052001, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+32, 249994, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5001.703125, -5086.689453125, 194.898406982421875, 0.587304770946502685, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Riftwalker Dellyn (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+33, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5012.79150390625, -5089.33984375, 195.72760009765625, 0.888574600219726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+34, 249995, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5003.033203125, -5084.57470703125, 194.9622039794921875, 0.587304770946502685, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Riftwalker Soran (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+35, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5021.814453125, -5090.29345703125, 197.185546875, 4.665406703948974609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+36, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5014.70849609375, -5086.6181640625, 195.844879150390625, 2.935244560241699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+37, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5033.6943359375, -5047.3369140625, 197.591400146484375, 0.196390017867088317, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+38, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5033.05224609375, -5062.50341796875, 196.4577178955078125, 5.6346435546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+39, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5025.8505859375, -5066.0380859375, 196.1237335205078125, 1.399336099624633789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+40, 249996, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5006.27294921875, -5019.51416015625, 196.6754913330078125, 2.597052335739135742, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 65893), -- Teely (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 244519 - Void Infested)
(@CGUID+41, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5029.673828125, -5072.705078125, 196.685455322265625, 1.146155238151550292, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+42, 249998, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5006.0224609375, -5021.26416015625, 196.5396728515625, 0.489578485488891601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Voidlight Everdawn (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+43, 249542, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5033.9150390625, -5071.89404296875, 196.6855010986328125, 1.010324478149414062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Riftblade Maella (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+44, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5005.4775390625, -5091.87158203125, 194.6150360107421875, 0.337612122297286987, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+45, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5026.017578125, -5064.205078125, 196.142242431640625, 4.665406703948974609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+46, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5023.751953125, -5102.60400390625, 198.196807861328125, 0.457683414220809936, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+47, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5012.4912109375, -5122.69287109375, 196.443359375, 4.839010238647460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+48, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5034.3525390625, -5086.953125, 197.212982177734375, 3.542521953582763671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+49, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5037.75537109375, -5086.40966796875, 197.60321044921875, 4.494048595428466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+50, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5009.0849609375, -5122.40283203125, 194.9400177001953125, 5.313063621520996093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+51, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5028.69921875, -5101.705078125, 198.7400360107421875, 0.071811713278293609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+52, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5020.98095703125, -5094.703125, 197.841827392578125, 1.327726364135742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+53, 245514, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4968.4443359375, -5026.57470703125, 200.9065399169921875, 4.452251911163330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- (Bunny) Sessile (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+54, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5028.93212890625, -5096.1005859375, 198.37738037109375, 3.889490604400634765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 174127 - UseKneeling)
(@CGUID+55, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5018.5068359375, -5099.91162109375, 197.718414306640625, 4.659598350524902343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+56, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5039.96875, -5084.9775390625, 197.87060546875, 5.584947109222412109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893); -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+56;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Blood Elf Farstrider
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Blood Knight Adept
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Blood Elf Farstrider
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'), -- Vigilant Magister - 174127 - UseKneeling
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'), -- Blood Knight Adept - 174127 - UseKneeling
(@CGUID+13, 0, 0, 0, 0, 0, 2, 0, 376, 0, 0, 0, 0, ''), -- Blood Elf Farstrider
(@CGUID+19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Grand Magister Rommath
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Blood Elf Farstrider - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '1249978'), -- Magister Umbric - 1249978 - [DNT] RP Chat Bubble
(@CGUID+26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Farstrider Helia
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Blood Elf Farstrider - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Riftwalker Dellyn
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Riftwalker Soran
(@CGUID+35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+38, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ren'dorei Scout - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244519'), -- Teely - 244519 - Void Infested
(@CGUID+44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ren'dorei Scout - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+46, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+50, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+52, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Arcanist
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'), -- Ren'dorei Arcanist - 174127 - UseKneeling
(@CGUID+56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Ren'dorei Scout

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 566765, 0, 4922, 4922, '0', 27265, 0, -5017.98974609375, -5086.82275390625, 197.3301849365234375, 0, 0, 0, 0, 1, 120, 255, 1, 65893), -- Stolen Twilight's Blade Stratagem (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+1, 508355, 0, 4922, 4922, '0', 27265, 0, -5030.33154296875, -5047.12158203125, 196.7599945068359375, 0, 0, 0, 0, 1, 120, 255, 1, 65893), -- Portal to Dornogal (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+2, 508353, 0, 4922, 4922, '0', 27265, 0, -5003.83154296875, -5031.783203125, 195.6225128173828125, 0.240502700209617614, 0, 0, 0.119961738586425781, 0.992778539657592773, 120, 255, 1, 65893), -- Portal to Orgrimmar (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+3, 566765, 0, 4922, 4922, '0', 27265, 0, -4975.2880859375, -5041.923828125, 199.766082763671875, 0, 0, 0, 0, 1, 120, 255, 1, 65893), -- Stolen Twilight's Blade Stratagem (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+4, 508350, 0, 4922, 4922, '0', 27265, 0, -5026.205078125, -5081.51025390625, 196.7755889892578125, 0.474069505929946899, 0, 0, 0.234821319580078125, 0.972038567066192626, 120, 255, 1, 65893); -- Portal to Stormwind (Area: Twilight Highlands - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 19925, 0), -- Stolen Twilight's Blade Stratagem
(@OGUID+2, 0, 0, 0, 1, 0, 3503), -- Portal to Orgrimmar
(@OGUID+3, 0, 0, 0, 1, 19925, 0), -- Stolen Twilight's Blade Stratagem
(@OGUID+4, 0, 0, 0, 1, 0, 3503); -- Portal to Stormwind

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (508350 /*Portal to Stormwind*/, 508353 /*Portal to Orgrimmar*/, 566765 /*Stolen Twilight's Blade Stratagem*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(508350, 1732, 0x20, 0, 3503), -- Portal to Stormwind
(508353, 1735, 0x20, 0, 3503), -- Portal to Orgrimmar
(566765, 0, 0x40000, 19925, 0); -- Stolen Twilight's Blade Stratagem

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (508355 /*Portal to Dornogal*/, 508350 /*Portal to Stormwind*/, 508353 /*Portal to Orgrimmar*/, 566765 /*Stolen Twilight's Blade Stratagem*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(508355, 22, 94774, 'Portal to Dornogal', '', '', '', 1, 1286852, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 2838, 65893), -- Portal to Dornogal
(508350, 22, 66650, 'Portal to Stormwind', '', '', '', 0.85000002384185791, 370479, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Portal to Stormwind
(508353, 22, 66649, 'Portal to Orgrimmar', '', '', '', 1, 370494, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Portal to Orgrimmar
(566765, 10, 101083, 'Stolen Twilight\'s Blade Stratagem', 'inspect', 'Perusing', '', 0.800000011920928955, 43, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1241557, 0, 0, 0, 43683, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65893); -- Stolen Twilight's Blade Stratagem

UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=231467; -- Scruff
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=245477; -- Rhay'Dahr
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=245514; -- (Bunny) Sessile
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x4800 WHERE `entry`=249542; -- Riftblade Maella
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=249998; -- Voidlight Everdawn
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=249996; -- Teely
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x4800 WHERE `entry`=249995; -- Riftwalker Soran
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x4800 WHERE `entry`=249994; -- Riftwalker Dellyn
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=249200; -- Ren'dorei Arcanist
UPDATE `creature_template` SET `faction`=1604, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=249541; -- Farstrider Helia
UPDATE `creature_template` SET `faction`=35, `npcflag`=130, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x4800 WHERE `entry`=249196; -- Materialist Ophinell
UPDATE `creature_template` SET `faction`=1732, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x4800 WHERE `entry`=237506; -- Magister Umbric
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=249194; -- Ren'dorei Scout
UPDATE `creature_template` SET `faction`=1604, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=237504; -- Grand Magister Rommath
UPDATE `creature_template` SET `faction`=1604, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x4800 WHERE `entry`=249197; -- Armorer Kalinovan
UPDATE `creature_template` SET `faction`=1604, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x4800 WHERE `entry`=249999; -- Blood Knight Shan
UPDATE `creature_template` SET `faction`=1604, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=249199; -- Blood Knight Adept
UPDATE `creature_template` SET `faction`=1604, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=249534; -- Blood Elf Farstrider
UPDATE `creature_template` SET `faction`=1604, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=249198; -- Vigilant Magister

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (27265,27453);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(27265, 'Cosmetic - See Twilight Ascension Hub'),
(27453, 'Cosmetic - See Magister Umbric and Grand Magister Rommath');

DELETE FROM `phase_area` WHERE `PhaseId` IN (27265,27453);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4922, 27265, 'See Twilight Ascension Hub'),
(4922, 27453, 'See Magister Umbric and Grand Magister Rommath');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=237506 AND `MenuID`=39732) OR (`CreatureID`=237504 AND `MenuID`=39745);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(237506, 39732, 65893), -- Magister Umbric
(237504, 39745, 65893); -- Grand Magister Rommath

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 293769, 0, 0, 0, 0, 0, 0, 0, 65893), -- 237504 (Grand Magister Rommath)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 292744, 0, 0, 0, 0, 0, 0, 0, 65893), -- 237504 (Grand Magister Rommath)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 292724, 0, 0, 0, 0, 0, 0, 0, 65893), -- 237506 (Magister Umbric)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 292726, 0, 0, 0, 0, 0, 0, 0, 65893); -- 237506 (Magister Umbric)

DELETE FROM `gossip_menu` WHERE (`MenuID`=39893 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=39745 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=39732 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=39733 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39893, @NPCTEXTID+0, 65893), -- 237504 (Grand Magister Rommath)
(39745, @NPCTEXTID+1, 65893), -- 237504 (Grand Magister Rommath)
(39732, @NPCTEXTID+2, 65893), -- 237506 (Magister Umbric)
(39733, @NPCTEXTID+3, 65893); -- 237506 (Magister Umbric)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (39732,39893,39745,39733));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39732, 134418, 0, 0, 'How do you feel about working with Grand Magister Rommath?', 0, 0, 0, 39733, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65893),
(39893, 134680, 0, 0, 'Let\'s talk about something else.', 172206, 0, 0, 39745, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65893), -- OptionBroadcastTextID: 172206 - 174968
(39745, 134681, 0, 0, 'How do you feel about working with Magister Umbric?', 0, 0, 0, 39893, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65893),
(39733, 134419, 0, 0, 'Let\'s talk about something else.', 172206, 0, 0, 39732, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65893); -- OptionBroadcastTextID: 172206 - 174968

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (249542,249995,249994,237506,249194,237504,249199,249534)) OR (`ID`=2 AND `CreatureID`=249534);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(249542, 1, 230720, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Riftblade Maella
(249995, 1, 230646, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Riftwalker Soran
(249994, 1, 230646, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Riftwalker Dellyn
(237506, 1, 126782, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Magister Umbric
(249194, 1, 259264, 0, 0, 259264, 0, 0, 0, 0, 0, 65893), -- Ren'dorei Scout
(237504, 1, 29114, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Grand Magister Rommath
(249534, 2, 0, 0, 0, 0, 0, 0, 245689, 0, 0, 65893), -- Blood Elf Farstrider
(249199, 1, 245684, 0, 0, 0, 0, 0, 0, 0, 0, 65893), -- Blood Knight Adept
(249534, 1, 245684, 0, 0, 0, 0, 0, 0, 0, 0, 65893); -- Blood Elf Farstrider

-- NPCSpellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 249996;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(249996, 339596, 1, 0);

-- Spelltarget
DELETE FROM `spell_target_position` WHERE (`ID`=446538 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(446538, 0, 0, 2552, 2915.679931640625, -2400.330078125, 265.8599853515625, 65893); -- Spell: 446538 (Portal: Dornogal) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=231467 AND `DifficultyID`=0); -- 231467 (Scruff) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x30000000, `VerifiedBuild`=65893 WHERE (`Entry`=245477 AND `DifficultyID`=0); -- 245477 (Rhay'Dahr) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `StaticFlags1`=0x20000100, `VerifiedBuild`=65893 WHERE (`Entry`=245514 AND `DifficultyID`=0); -- 245514 ((Bunny) Sessile) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249542 AND `DifficultyID`=0); -- 249542 (Riftblade Maella) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249998 AND `DifficultyID`=0); -- 249998 (Voidlight Everdawn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249995 AND `DifficultyID`=0); -- 249995 (Riftwalker Soran) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249994 AND `DifficultyID`=0); -- 249994 (Riftwalker Dellyn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249200 AND `DifficultyID`=0); -- 249200 (Ren'dorei Arcanist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249541 AND `DifficultyID`=0); -- 249541 (Farstrider Helia) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249196 AND `DifficultyID`=0); -- 249196 (Materialist Ophinell) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `StaticFlags1`=0x12000000, `VerifiedBuild`=65893 WHERE (`Entry`=237506 AND `DifficultyID`=0); -- 237506 (Magister Umbric) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249194 AND `DifficultyID`=0); -- 249194 (Ren'dorei Scout) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313, `StaticFlags1`=0x12000000, `VerifiedBuild`=65893 WHERE (`Entry`=237504 AND `DifficultyID`=0); -- 237504 (Grand Magister Rommath) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249197 AND `DifficultyID`=0); -- 249197 (Armorer Kalinovan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249999 AND `DifficultyID`=0); -- 249999 (Blood Knight Shan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249199 AND `DifficultyID`=0); -- 249199 (Blood Knight Adept) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249534 AND `DifficultyID`=0); -- 249534 (Blood Elf Farstrider) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65893 WHERE (`Entry`=249198 AND `DifficultyID`=0); -- 249198 (Vigilant Magister) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=56, `StaticFlags1`=0x10000000, `VerifiedBuild`=65940 WHERE (`Entry`=249996 AND `DifficultyID`=0); -- 249996 (Teely) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (121851, 129679, 136344, 136338, 136346, 136329, 136349, 136328, 136323, 136336, 136414, 136423, 136341, 136332, 136314, 136354, 136348, 136331, 136496, 136497, 136339, 136322, 137025, 136679, 129388, 136463, 136316, 136708, 140873, 136580, 136802, 136681, 136713, 137023, 136700, 136761, 136578, 137024, 137020, 136764, 136762, 137022, 136583, 136581, 136768, 136352, 136351, 136334, 136350, 129389, 136333, 136317, 136330, 136353, 136318, 136321, 137028, 137018, 137017, 136772, 136763, 136699, 136795, 136579, 141128, 124895, 130586, 127809, 124913, 124897, 130658, 130657, 130611, 124892, 130564, 126123, 130690, 130610, 130691, 130563, 130636, 130570, 124915, 127812, 130571, 125467, 130619, 130614, 130608, 126161, 136682, 136327, 137021, 136320, 136347, 136711, 136797, 136582);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121851, 0.27641347050666809, 0, 0, 65893),
(129679, 2.8288726806640625, 1, 0, 65893),
(136344, 0.347222000360488891, 1.5, 0, 65893),
(136338, 0.347222000360488891, 1.5, 0, 65893),
(136346, 0.347222000360488891, 1.5, 0, 65893),
(136329, 0.347222000360488891, 1.5, 0, 65893),
(136349, 0.347222000360488891, 1.5, 0, 65893),
(136328, 0.347222000360488891, 1.5, 0, 65893),
(136323, 0.347222000360488891, 1.5, 0, 65893),
(136336, 0.347222000360488891, 1.5, 0, 65893),
(136414, 0.347222000360488891, 1.5, 0, 65893),
(136423, 0.347222000360488891, 1.5, 0, 65893),
(136341, 0.347222000360488891, 1.5, 0, 65893),
(136332, 0.347222000360488891, 1.5, 0, 65893),
(136314, 0.347222000360488891, 1.5, 0, 65893),
(136354, 0.347222000360488891, 1.5, 0, 65893),
(136348, 0.347222000360488891, 1.5, 0, 65893),
(136331, 0.347222000360488891, 1.5, 0, 65893),
(136496, 0.347222000360488891, 1.5, 0, 65893),
(136497, 0.347222000360488891, 1.5, 0, 65893),
(136339, 0.347222000360488891, 1.5, 0, 65893),
(136322, 0.347222000360488891, 1.5, 0, 65893),
(137025, 0.382999986410140991, 1.5, 0, 65893),
(136679, 0.382999986410140991, 1.5, 0, 65893),
(129388, 0.347222000360488891, 1.5, 0, 65893),
(136463, 0.347222000360488891, 1.5, 0, 65893),
(136316, 0.347222000360488891, 1.5, 0, 65893),
(136708, 0.382999986410140991, 1.5, 0, 65893),
(140873, 0.459600001573562622, 1.80000007152557373, 0, 65893),
(136580, 0.382999986410140991, 1.5, 0, 65893),
(136802, 0.382999986410140991, 1.5, 0, 65893),
(136681, 0.382999986410140991, 1.5, 0, 65893),
(136713, 0.382999986410140991, 1.5, 0, 65893),
(137023, 0.382999986410140991, 1.5, 0, 65893),
(136700, 0.382999986410140991, 1.5, 0, 65893),
(136761, 0.382999986410140991, 1.5, 0, 65893),
(136578, 0.382999986410140991, 1.5, 0, 65893),
(137024, 0.382999986410140991, 1.5, 0, 65893),
(137020, 0.382999986410140991, 1.5, 0, 65893),
(136764, 0.382999986410140991, 1.5, 0, 65893),
(136762, 0.382999986410140991, 1.5, 0, 65893),
(137022, 0.382999986410140991, 1.5, 0, 65893),
(136583, 0.382999986410140991, 1.5, 0, 65893),
(136581, 0.382999986410140991, 1.5, 0, 65893),
(136768, 0.382999986410140991, 1.5, 0, 65893),
(136352, 0.347222000360488891, 1.5, 0, 65940),
(136351, 0.347222000360488891, 1.5, 0, 65940),
(136334, 0.347222000360488891, 1.5, 0, 65940),
(136350, 0.347222000360488891, 1.5, 0, 65940),
(129389, 0.347222000360488891, 1.5, 0, 65940),
(136333, 0.347222000360488891, 1.5, 0, 65940),
(136317, 0.347222000360488891, 1.5, 0, 65940),
(136330, 0.347222000360488891, 1.5, 0, 65940),
(136353, 0.347222000360488891, 1.5, 0, 65940),
(136318, 0.347222000360488891, 1.5, 0, 65940),
(136321, 0.347222000360488891, 1.5, 0, 65940),
(137028, 0.382999986410140991, 1.5, 0, 65940),
(137018, 0.382999986410140991, 1.5, 0, 65940),
(137017, 0.382999986410140991, 1.5, 0, 65940),
(136772, 0.382999986410140991, 1.5, 0, 65940),
(136763, 0.382999986410140991, 1.5, 0, 65940),
(136699, 0.382999986410140991, 1.5, 0, 65940),
(136795, 0.382999986410140991, 1.5, 0, 65940),
(136579, 0.382999986410140991, 1.5, 0, 65940),
(141128, 1.475100517272949218, 1.5, 0, 65940),
(124895, 0.520799994468688964, 2.099999904632568359, 0, 65940),
(130586, 0.536199986934661865, 2.10000014305114746, 0, 65940),
(127809, 0.433999985456466674, 1.399999976158142089, 0, 65940),
(124913, 1.891321063041687011, 1.20000004768371582, 0, 65940),
(124897, 0.520799994468688964, 2.099999904632568359, 0, 65940),
(130658, 0.459600001573562622, 1.80000007152557373, 0, 65940),
(130657, 0.459600001573562622, 1.80000007152557373, 0, 65940),
(130611, 0.249600008130073547, 1.80000007152557373, 0, 65940),
(124892, 0.536199986934661865, 2.099999904632568359, 0, 65940),
(130564, 0.416400015354156494, 1.80000007152557373, 0, 65940),
(126123, 0.312499791383743286, 1.349999904632568359, 0, 65940),
(130690, 0.428399980068206787, 2.10000014305114746, 0, 65940),
(130610, 0.367200016975402832, 1.80000007152557373, 0, 65940),
(130691, 0.428399980068206787, 2.10000014305114746, 0, 65940),
(130563, 0.416400015354156494, 1.80000007152557373, 0, 65940),
(130636, 0.536199986934661865, 2.099999904632568359, 0, 65940),
(130570, 1.010800004005432128, 4.199999809265136718, 0, 65940),
(124915, 1.232741117477416992, 2.5, 0, 65940),
(127812, 0.433999985456466674, 1.399999976158142089, 0, 65940),
(130571, 0.977200031280517578, 4.199999809265136718, 0, 65940),
(125467, 0.459600001573562622, 1.80000007152557373, 0, 65940),
(130619, 0.459600001573562622, 1.80000007152557373, 0, 65940),
(130614, 0.367200016975402832, 1.80000007152557373, 0, 65940),
(130608, 0.838458240032196044, 1.80000007152557373, 0, 65940),
(126161, 6.437046527862548828, 0, 0, 65940),
(136682, 0.382999986410140991, 1.5, 0, 65940),
(136327, 0.347222000360488891, 1.5, 0, 65940),
(137021, 0.382999986410140991, 1.5, 0, 65940),
(136320, 0.347222000360488891, 1.5, 0, 65940),
(136347, 0.347222000360488891, 1.5, 0, 65940),
(136711, 0.382999986410140991, 1.5, 0, 65940),
(136797, 0.382999986410140991, 1.5, 0, 65940),
(136582, 0.382999986410140991, 1.5, 0, 65940);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=249197 AND `item`=269897 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246995 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246670 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246669 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246668 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246667 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246666 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246665 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246664 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246663 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246662 AND `ExtendedCost`=10493 AND `type`=1) OR (`entry`=249197 AND `item`=246660 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246659 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246658 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246657 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246656 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246655 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246654 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246653 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246652 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246651 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246650 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246649 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246648 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246647 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246646 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246645 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246644 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246643 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246642 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246641 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246640 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246639 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246638 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246637 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246636 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246635 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246634 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246633 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246632 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246631 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246630 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246629 AND `ExtendedCost`=10492 AND `type`=1) OR (`entry`=249197 AND `item`=246677 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246676 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246675 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246679 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246678 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246674 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246673 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249197 AND `item`=246672 AND `ExtendedCost`=10494 AND `type`=1) OR (`entry`=249196 AND `item`=246627 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=249196 AND `item`=249468 AND `ExtendedCost`=10587 AND `type`=1) OR (`entry`=249196 AND `item`=244911 AND `ExtendedCost`=10491 AND `type`=1) OR (`entry`=249196 AND `item`=246628 AND `ExtendedCost`=10491 AND `type`=1) OR (`entry`=249196 AND `item`=232856 AND `ExtendedCost`=10491 AND `type`=1) OR (`entry`=249196 AND `item`=251997 AND `ExtendedCost`=10646 AND `type`=1) OR (`entry`=249196 AND `item`=245330 AND `ExtendedCost`=10486 AND `type`=1) OR (`entry`=249196 AND `item`=245284 AND `ExtendedCost`=10486 AND `type`=1) OR (`entry`=249196 AND `item`=249438 AND `ExtendedCost`=10573 AND `type`=1) OR (`entry`=249196 AND `item`=248218 AND `ExtendedCost`=10573 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(249197, 51, 269897, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Crossbow
(249197, 50, 246995, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Dagger
(249197, 49, 246670, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Warglaive
(249197, 48, 246669, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Shield
(249197, 47, 246668, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Censer
(249197, 46, 246667, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Greatsword
(249197, 45, 246666, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Staff
(249197, 44, 246665, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Spear
(249197, 43, 246664, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Cudgel
(249197, 42, 246663, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Mace
(249197, 41, 246662, 0, 10493, 1, 0, 0, 65893), -- Ascension Arrestor's Axe
(249197, 40, 246660, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Bracers
(249197, 39, 246659, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Greatbelt
(249197, 38, 246658, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Pauldrons
(249197, 37, 246657, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Greaves
(249197, 36, 246656, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Bascinet
(249197, 35, 246655, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Gauntlets
(249197, 34, 246654, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Sollerets
(249197, 33, 246653, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Surcoat
(249197, 32, 246652, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Mail Cuffs
(249197, 31, 246651, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Girdle
(249197, 30, 246650, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Spaulders
(249197, 29, 246649, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Petticoat
(249197, 28, 246648, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Helmet
(249197, 27, 246647, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Grips
(249197, 26, 246646, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Boots
(249197, 25, 246645, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Hauberk
(249197, 24, 246644, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Bindings
(249197, 23, 246643, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Clasp
(249197, 22, 246642, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Mantle
(249197, 21, 246641, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Breeches
(249197, 20, 246640, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Hood
(249197, 19, 246639, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Gloves
(249197, 18, 246638, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Shoes
(249197, 17, 246637, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Doublet
(249197, 16, 246636, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Wraps
(249197, 15, 246635, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Cincture
(249197, 14, 246634, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Amice
(249197, 13, 246633, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Leggings
(249197, 12, 246632, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Mitre
(249197, 11, 246631, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Mitts
(249197, 10, 246630, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Soles
(249197, 9, 246629, 0, 10492, 1, 0, 0, 65893), -- Ascension Arrestor's Robe
(249197, 8, 246677, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Band
(249197, 7, 246676, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Ring
(249197, 6, 246675, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Cloak
(249197, 5, 246679, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Pendant
(249197, 4, 246678, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Choker
(249197, 3, 246674, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Cape
(249197, 2, 246673, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Cowl
(249197, 1, 246672, 0, 10494, 1, 0, 0, 65893), -- Ascension Arrestor's Shawl
(249196, 11, 246627, 0, 0, 1, 152620, 0, 65893), -- Twilight's Blade Tabard
(249196, 10, 249468, 0, 10587, 1, 0, 0, 65893), -- Twilight's Blade Top Secret Strategy Training Guide
(249196, 9, 244911, 0, 10491, 1, 0, 0, 65893), -- Rhay'Dahr
(249196, 8, 246628, 0, 10491, 1, 0, 0, 65893), -- Emerald Sporbit
(249196, 7, 232856, 0, 10491, 1, 0, 0, 65893), -- Scruff
(249196, 5, 251997, 0, 10646, 1, 0, 0, 65893), -- Sin'dorei Winged Chaise
(249196, 4, 245330, 0, 10486, 1, 0, 0, 65893), -- Enchanted Blood Elven Candelabra
(249196, 3, 245284, 0, 10486, 1, 0, 0, 65893), -- Silvermoon Wooden Chair
(249196, 2, 249438, 0, 10573, 1, 0, 0, 65893), -- Ensemble: Well-Worn Twilight Cultist's Attire
(249196, 1, 248218, 0, 10573, 1, 0, 0, 65893); -- Arsenal: Weathered Twilight's Hammer Armaments

-- Blood Elf Farstrider smart ai
SET @ENTRY := 249534;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 0, 80, 24953400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Blood Elf Farstrider #0 (24953400) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 8, 0, 0, 0, 80, 24953401, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Start timed action list id #Blood Elf Farstrider #1 (24953401) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 2, 0, 0, 0, 80, 24953400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Blood Elf Farstrider #0 (24953400) (update out of combat)', ''),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 7, 0, 0, 0, 80, 24953401, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 7 - Self: Start timed action list id #Blood Elf Farstrider #1 (24953401) (update out of combat)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 249534 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 249534, 0, 0, 58, 1, 0, 0, 0, 'CosmeticOne', 0, 'Object has StringID CosmeticOne'),
(22, 2, 249534, 0, 0, 58, 1, 0, 0, 0, 'CosmeticOne', 0, 'Object has StringID CosmeticOne'),
(22, 3, 249534, 0, 0, 58, 1, 0, 0, 0, 'CosmeticTwo', 0, 'Object has StringID CosmeticTwo'),
(22, 4, 249534, 0, 0, 58, 1, 0, 0, 0, 'CosmeticTwo', 0, 'Object has StringID CosmeticTwo');

-- Ren'dorei Scout smart ai
SET @ENTRY := 249194;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 0, 0, 0, 0, 80, 24953400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform - Self: Start timed action list id #Blood Elf Farstrider #0 (24953400) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 0, 80, 24953401, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #Blood Elf Farstrider #1 (24953401) (update out of combat)', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 1, 0, 0, 0, 80, 24953401, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Blood Elf Farstrider #1 (24953401) (update out of combat)', ''),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 6, 0, 0, 0, 80, 24953400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #Blood Elf Farstrider #0 (24953400) (update out of combat)', ''),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 2, 2, 0, 0, 0, 80, 24953401, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Blood Elf Farstrider #1 (24953401) (update out of combat)', ''),
(@ENTRY, 0, 5, 0, 34, 0, 100, 0, 2, 6, 0, 0, 0, 80, 24953400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Start timed action list id #Blood Elf Farstrider #0 (24953400) (update out of combat)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 249194 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 249194, 0, 0, 58, 1, 0, 0, 0, 'CosmeticOne', 0, 'Object has StringID CosmeticOne'),
(22, 2, 249194, 0, 0, 58, 1, 0, 0, 0, 'CosmeticOne', 0, 'Object has StringID CosmeticOne'),
(22, 3, 249194, 0, 0, 58, 1, 0, 0, 0, 'CosmeticTwo', 0, 'Object has StringID CosmeticTwo'),
(22, 4, 249194, 0, 0, 58, 1, 0, 0, 0, 'CosmeticTwo', 0, 'Object has StringID CosmeticTwo'),
(22, 5, 249194, 0, 0, 58, 1, 0, 0, 0, 'CosmeticThree', 0, 'Object has StringID CosmeticThree'),
(22, 6, 249194, 0, 0, 58, 1, 0, 0, 0, 'CosmeticThree', 0, 'Object has StringID CosmeticThree');

UPDATE `creature` SET `StringID` = 'CosmeticOne' WHERE `guid` IN (@CGUID+11,@CGUID+24);
UPDATE `creature` SET `StringID` = 'CosmeticTwo' WHERE `guid` IN (@CGUID+8,@CGUID+33);
UPDATE `creature` SET `StringID` = 'CosmeticThree' WHERE `guid` = @CGUID+51;

-- Timed list 24953400 smart ai
SET @ENTRY := 24953400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 1239411, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 1239411 on self', '');

-- Timed list 24953401 smart ai
SET @ENTRY := 24953401;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set emote state to 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 28, 1239411, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell  1239411', '');

 -- Vigilant Magister smart ai
SET @ENTRY := 249198;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 374151, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 374151 on self', ''),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 0, 85, 32783, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 32783 on self', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 249198 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 249198, 0, 0, 58, 1, 0, 0, 0, 'CosmeticBook', 0, 'Object has StringID CosmeticBook'),
(22, 2, 249198, 0, 0, 58, 1, 0, 0, 0, 'CosmeticChannel', 0, 'Object has StringID CosmeticChannel');

 -- Ren'dorei Arcanist smart ai
SET @ENTRY := 249200;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 85, 374151, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 374151 on self', ''),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 0, 85, 32783, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell 32783 on self', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 249200 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 249200, 0, 0, 58, 1, 0, 0, 0, 'CosmeticBook', 0, 'Object has StringID CosmeticBook'),
(22, 2, 249200, 0, 0, 58, 1, 0, 0, 0, 'CosmeticChannel', 0, 'Object has StringID CosmeticChannel');

UPDATE `creature` SET `StringID` = 'CosmeticBook' WHERE `guid` IN (@CGUID+4, @CGUID+17, @CGUID+36, @CGUID+41);
UPDATE `creature` SET `StringID` = 'CosmeticChannel' WHERE `guid` IN (@CGUID+5,@CGUID+31,@CGUID+37);

-- Path for Blood Elf Farstrider
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 249534;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Blood Elf Farstrider - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5014.6025, -5046.5938, 195.3017, NULL, 0),
(@PATH, 1, -5015.0054, -5045.2065, 195.30716, NULL, 0),
(@PATH, 2, -5014.972, -5044.741, 195.30609, NULL, 3543),
(@PATH, 3, -5007.3784, -5051.5728, 195.02281, NULL, 0),
(@PATH, 4, -4991.629, -5048.8223, 197.41649, NULL, 0),
(@PATH, 5, -4985.926, -5043.1973, 197.91628, NULL, 0),
(@PATH, 6, -4982.9844, -5037.1426, 198.1511, NULL, 0),
(@PATH, 7, -4977.413, -5035.6406, 198.3216, NULL, 0),
(@PATH, 8, -4970.009, -5033.424, 198.89052, NULL, 4195),
(@PATH, 9, -4977.0728, -5035.7207, 198.35178, NULL, 0),
(@PATH, 10, -4982.597, -5036.4443, 198.16248, NULL, 0),
(@PATH, 11, -4986.6895, -5048.4463, 197.54451, NULL, 0),
(@PATH, 12, -5000.3423, -5051.405, 195.08887, NULL, 0),
(@PATH, 13, -5012.151, -5048.5903, 194.9519, NULL, 0);

UPDATE `creature` SET `position_x`=-5014.6025, `position_y`=-5046.5938, `position_z`=195.3017, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

-- Path for Blood Elf Farstrider
SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 249534;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Blood Elf Farstrider - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5005.724, -5041.165, 195.59567, NULL, 0),
(@PATH, 1, -5009.0835, -5039.58, 195.3284, NULL, 0),
(@PATH, 2, -5009.514, -5039.625, 195.28021, NULL, 3941),
(@PATH, 3, -5002.2363, -5040.578, 196.0754, NULL, 0),
(@PATH, 4, -4996.299, -5037.3438, 196.68828, NULL, 0),
(@PATH, 5, -4994.8525, -5035.1353, 196.739, NULL, 0),
(@PATH, 6, -4995.0454, -5034.519, 196.66348, NULL, 0),
(@PATH, 7, -4995.432, -5034.257, 196.58731, NULL, 4621);

UPDATE `creature` SET `position_x`=-5005.724, `position_y`=-5041.165, `position_z`=195.59567, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

-- Path for Rendorei Scout
SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 249194;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ren''dorei Scout - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5029.125, -5061.6895, 196.43124, NULL, 4182),
(@PATH, 1, -5023.0503, -5065.6875, 195.7934, NULL, 0),
(@PATH, 2, -5018.288, -5074.4272, 195.87125, NULL, 0),
(@PATH, 3, -5017.9004, -5083.4277, 195.89474, NULL, 4534),
(@PATH, 4, -5019.4204, -5067.6895, 196.1417, NULL, 0),
(@PATH, 5, -5025.953, -5060.7676, 196.01257, NULL, 0),
(@PATH, 6, -5028.182, -5060.7554, 196.34377, NULL, 0);

UPDATE `creature` SET `position_x`=-5029.125, `position_y`=-5061.6895, `position_z`=196.43124, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

-- Path for Rendorei Scout
SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 249194;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ren''dorei Scout - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5003.08, -5075.988, 195.24622, NULL, 0),
(@PATH, 1, -4997.7744, -5074.705, 194.51404, NULL, 3935),
(@PATH, 2, -5005.6284, -5077.7866, 195.36081, NULL, 0),
(@PATH, 3, -5010.453, -5085.483, 195.11127, NULL, 0),
(@PATH, 4, -5014.8853, -5090.1772, 196.17369, NULL, 0),
(@PATH, 5, -5016.3975, -5089.8438, 196.37933, NULL, 0),
(@PATH, 6, -5016.618, -5088.913, 196.30661, NULL, 3797),
(@PATH, 7, -5008.2065, -5083.6997, 194.96996, NULL, 0);

UPDATE `creature` SET `position_x`=-5003.08, `position_y`=-5075.988, `position_z`=195.24622, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

-- Path for Rendorei Scout
SET @MOVERGUID := @CGUID+51;
SET @ENTRY := 249194;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ren''dorei Scout - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5025.979, -5095.0454, 198.14531, NULL, 0),
(@PATH, 1, -5027.8633, -5090.416, 197.52495, NULL, 0),
(@PATH, 2, -5027.979, -5089.0645, 197.26584, NULL, 3346),
(@PATH, 3, -5034.2153, -5092.7554, 198.30481, NULL, 0),
(@PATH, 4, -5034.2085, -5098.75, 198.89166, NULL, 0),
(@PATH, 5, -5029.8804, -5101.79, 198.94894, NULL, 0),
(@PATH, 6, -5025.408, -5101.4688, 198.26086, NULL, 3822);

UPDATE `creature` SET `position_x`=-5025.979, `position_y`=-5095.0454, `position_z`=198.14531, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);
