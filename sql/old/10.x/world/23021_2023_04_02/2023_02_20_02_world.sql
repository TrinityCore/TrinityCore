SET @CGUID := 9003338;
SET @OGUID := 9000321;

SET @NPCTEXTID := 590036;

-- Transporter
DELETE FROM `transports` WHERE `guid` = 33;
INSERT INTO `transports` (`guid`, `entry`, `name`, `phaseUseFlags`, `phaseid`, `phasegroup`, `ScriptName`) VALUES
(33, 375073, 'Stormwind and Waking Shores ("The Rugged Dragonscale")', 0, 0, 0, '');

DELETE FROM `gameobject_template_addon` WHERE `entry`= 375073;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `WorldEffectID`, `AIAnimKitID`) VALUES
(375073, 0, 0x100028, 0, 0, 0, 0);

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+97;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 180538, 2524, 1519, 4411, '0', 0, 0, 0, 0, 3.34904026985168457, -0.16133457422256469, 37.34839630126953125, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- (Bunny) Sessile + Large AOI (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+1, 197503, 2524, 1519, 4411, '0', 0, 0, 0, 0, 1.879366517066955566, 1.662567138671875, 8.805849075317382812, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- The Rugged Dragonscale (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+2, 197611, 2524, 1519, 4411, '0', 0, 0, 0, 0, -0.2512407898902893, 4.58125162124633789, 6.183543205261230468, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- (Bunny) Sessile + Gigantic AOI (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+3, 197503, 2524, 1519, 4411, '0', 0, 0, 0, 0, 1.879366517066955566, 1.662567138671875, 8.805849075317382812, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- The Rugged Dragonscale (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+4, 197611, 2524, 1519, 4411, '0', 0, 0, 0, 0, 3.40557098388671875, 0.131810501217842102, 8.272027015686035156, 0, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48069), -- (Bunny) Sessile + Gigantic AOI (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+5, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, -27.8148231506347656, -6.25153589248657226, 11.3517303466796875, 1.230925202369689941, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+6, 194378, 2524, 1519, 4411, '0', 0, 0, 0, 1, -15.3168163299560546, 10.05295372009277343, 9.785700798034667968, 1.648361682891845703, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Hired Tidesage (Area: Stormwind Harbor - Difficulty: 0) (Auras: 237594 - Cosmetic - Water Channel)
(@CGUID+7, 194378, 2524, 1519, 4411, '0', 0, 0, 0, 1, -15.0272369384765625, -10.0071115493774414, 9.756842613220214843, 4.664150238037109375, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Hired Tidesage (Area: Stormwind Harbor - Difficulty: 0) (Auras: 237594 - Cosmetic - Water Channel)
(@CGUID+8, 196091, 2524, 1519, 4411, '0', 0, 0, 0, 1, -8.82646465301513671, 11.2667694091796875, 6.16873788833618164, 1.595898866653442382, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Korston Willard (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+9, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, -21.232269287109375, -3.72122526168823242, 10.56009864807128906, 1.623983263969421386, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0) (Auras: 374148 - Channel: Hold Compass + TalkQuestion (Explorer) [DNT])
(@CGUID+10, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, -22.5547218322753906, -2.65338778495788574, 10.77260494232177734, 3.925586938858032226, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0) (Auras: 372498 - Channel: Look Through Spyglass (Nightborne Male) [DNT])
(@CGUID+11, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, -18.640054702758789, -0.2143300324678421, 31.55849266052246093, 0.040592536330223083, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+12, 194490, 2524, 1519, 4411, '0', 0, 0, 0, 1, -10.0628557205200195, -10.8293657302856445, 6.169805049896240234, 1.418756961822509765, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Zuraan (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+13, 198362, 2524, 1519, 4411, '0', 0, 0, 0, 0, -1.98059511184692382, 8.003537178039550781, 6.182118415832519531, 1.581378340721130371, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- (Bunny) Crow's Nest (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+14, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 3.263731718063354492, -0.05001322552561759, 37.34839630126953125, 0.176693260669708251, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+15, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, -0.78258007764816284, 3.573533058166503906, 37.3484039306640625, 1.224529147148132324, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+16, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, -1.65199911594390869, -1.48895585536956787, 6.180759429931640625, 3.491937637329101562, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+17, 198363, 2524, 1519, 4411, '0', 0, 0, 0, 0, 1.114111781120300292, -1.10485804080963134, 62.03670883178710937, 3.210008859634399414, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- (Bunny) Crow's Nest [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+18, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 2.03907179832458496, 1.223812460899353027, 62.03670883178710937, 0.959222733974456787, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0) (Auras: 372498 - Channel: Look Through Spyglass (Nightborne Male) [DNT])
(@CGUID+19, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, 5.028229713439941406, -1.47142815589904785, 6.182877540588378906, 5.751345634460449218, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+20, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 23.47769355773925781, 11.19172477722167968, 6.362297534942626953, 4.947275161743164062, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+21, 194537, 2524, 1519, 4411, '0', 0, 0, 0, 0, 17.83073043823242187, -7.42013740539550781, 6.184665203094482421, 0.663221180438995361, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Tishad (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+22, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, 13.11567878723144531, -5.18981790542602539, 11.95417594909667968, 3.783195734024047851, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+23, 194470, 2524, 1519, 4411, '0', 0, 0, 0, 0, 14.16449260711669921, 1.634089827537536621, 6.205789089202880859, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Victor Bradwell (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+24, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 7.988283634185791015, 11.25578880310058593, 6.20257425308227539, 1.917884349822998046, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+25, 194536, 2524, 1519, 4411, '0', 0, 0, 0, 0, 19.69184303283691406, -7.2256927490234375, 6.224917888641357421, 2.434734821319580078, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Reluun (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+26, 194539, 2524, 1519, 4411, '0', 0, 0, 0, 1, 13.65427112579345703, 9.365904808044433593, 13.507904052734375, 5.490558147430419921, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Tizzi Twistcog (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+27, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 14.97393321990966796, -4.38739204406738281, 6.231508731842041015, 4.058600425720214843, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+28, 198748, 2524, 1519, 4411, '0', 0, 0, 0, 1, 36.44826507568359375, 3.880536317825317382, 19.4808197021484375, 3.719045639038085937, 120, 0, 0, 2258380, 3155, 0, 0, 0, 0, 48069), -- Expedition Escort (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+29, 194493, 2524, 1519, 4411, '0', 0, 0, 0, 0, 31.76350593566894531, 9.949885368347167968, 19.83477210998535156, 6.258297920227050781, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Ogdan Stoneforge (Area: Stormwind Harbor - Difficulty: 0) (Auras: 389730 - Cosmetic - SitHigh and Drink Breakable (10.0 Explorers Tankard))
(@CGUID+30, 194488, 2524, 1519, 4411, '0', 0, 0, 0, 0, 32.71043014526367187, -8.49995136260986328, 6.505216598510742187, 1.925407171249389648, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Guldros Onyxbrand (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+31, 194397, 2524, 1519, 4411, '0', 0, 0, 0, 0, 37.15568161010742187, 8.7976226806640625, 6.573340892791748046, 1.058295726776123046, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Nethandril Duskthorn (Area: Stormwind Harbor - Difficulty: 0) (Auras: 275283 - Cosmetic - Void Hands + UseStanding)
(@CGUID+32, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 36.18121719360351562, -6.68012666702270507, 14.38788509368896484, 0, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0) (Auras: 371465 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+33, 194378, 2524, 1519, 4411, '0', 0, 0, 0, 1, 41.50246047973632812, 11.21326065063476562, 20.04051971435546875, 1.656445622444152832, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Hired Tidesage (Area: Stormwind Harbor - Difficulty: 0) (Auras: 237594 - Cosmetic - Water Channel)
(@CGUID+34, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 38.61156082153320312, 2.702339410781860351, 7.2091827392578125, 3.403037548065185546, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0) (Auras: 371465 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+35, 194659, 2524, 1519, 4411, '0', 0, 0, 0, 0, 25.97134017944335937, 6.95246744155883789, 7.254109859466552734, 0, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48069), -- Dumpling (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+36, 194531, 2524, 1519, 4411, '0', 0, 0, 0, 0, 39.54948043823242187, -0.97569453716278076, 13.0307769775390625, 0.506144583225250244, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Selindra Nightdancer (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+37, 194538, 2524, 1519, 4411, '0', 0, 0, 0, 0, 26.81163787841796875, 6.826388835906982421, 6.332414627075195312, 2.286378860473632812, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Ji-Min Quickpaw (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+38, 194484, 2524, 1519, 4411, '0', 0, 0, 0, 0, 32.02232742309570312, -8.06710624694824218, 6.494704723358154296, 0.768538355827331542, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Clinkora Rustfuse (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+39, 194437, 2524, 1519, 4411, '0', 0, 0, 0, 0, 30.08919906616210937, -5.42627620697021484, 13.04108619689941406, 2.390864372253417968, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Salty Deckhand (Area: Stormwind Harbor - Difficulty: 0) (Auras: 374210 - Channel: Hold Duck Plushie + TalkQuestion [DNT] (Large Races not WAI))
(@CGUID+40, 194369, 2524, 1519, 4411, '0', 0, 0, 0, 0, 36.71170806884765625, -4.34244012832641601, 19.50551033020019531, 1.993219375610351562, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Alanatheth (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+41, 194534, 2524, 1519, 4411, '0', 0, 0, 0, 0, 42.76128387451171875, -0.07638958096504211, 13.03080463409423828, 3.159062385559082031, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Dauvin Thornworth (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+42, 194393, 2524, 1519, 4411, '0', 0, 0, 0, 0, 40.64383697509765625, 1.96880340576171875, 20.56963348388671875, 3.745630741119384765, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Clovis (Area: Stormwind Harbor - Difficulty: 0) (Auras: 383667 - Holding Bottles [DNT])
(@CGUID+43, 194378, 2524, 1519, 4411, '0', 0, 0, 0, 1, 41.42766189575195312, -11.2781867980957031, 20.02971839904785156, 4.693413734436035156, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069), -- Hired Tidesage (Area: Stormwind Harbor - Difficulty: 0) (Auras: 237594 - Cosmetic - Water Channel)
(@CGUID+44, 184288, 2524, 1519, 4411, '0', 0, 0, 0, 1, 39.03123092651367187, -0.00138939754106104, 20.56952667236328125, 3.346041679382324218, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 48069); -- Captain Ironbridge (Area: Stormwind Harbor - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+97;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- (Bunny) Sessile + Large AOI
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- The Rugged Dragonscale
(@CGUID+2, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- (Bunny) Sessile + Gigantic AOI
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- The Rugged Dragonscale
(@CGUID+4, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- (Bunny) Sessile + Gigantic AOI
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Hired Tidesage - 237594 - Cosmetic - Water Channel
(@CGUID+7, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Hired Tidesage - 237594 - Cosmetic - Water Channel
(@CGUID+8, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Korston Willard
(@CGUID+9, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Salty Deckhand - 374148 - Channel: Hold Compass + TalkQuestion (Explorer) [DNT]
(@CGUID+10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Salty Deckhand - 372498 - Channel: Look Through Spyglass (Nightborne Male) [DNT]
(@CGUID+11, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+12, 0, 0, 0, 0, 0, 1, 1, 64, 0, 0, 0, 0, ''), -- Zuraan
(@CGUID+14, 0, 0, 0, 0, 0, 1, 1, 720, 0, 0, 0, 0, ''), -- Salty Deckhand
(@CGUID+15, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+16, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+18, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Salty Deckhand - 372498 - Channel: Look Through Spyglass (Nightborne Male) [DNT]
(@CGUID+19, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+20, 0, 0, 0, 0, 0, 1, 1, 720, 0, 0, 0, 0, ''), -- Salty Deckhand
(@CGUID+21, 0, 0, 5, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Tishad
(@CGUID+22, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+23, 0, 0, 0, 0, 0, 1, 1, 0, 16425, 0, 0, 0, ''), -- Victor Bradwell
(@CGUID+24, 0, 0, 0, 0, 0, 1, 1, 569, 0, 0, 0, 0, ''), -- Salty Deckhand
(@CGUID+25, 0, 0, 5, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Reluun
(@CGUID+26, 0, 0, 0, 3, 0, 1, 1, 876, 0, 0, 0, 0, ''), -- Tizzi Twistcog
(@CGUID+27, 0, 0, 0, 0, 0, 1, 1, 569, 0, 0, 0, 0, ''), -- Salty Deckhand
(@CGUID+28, 0, 0, 0, 0, 0, 1, 1, 718, 0, 0, 0, 0, ''), -- Expedition Escort
(@CGUID+29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '389730'), -- Ogdan Stoneforge - 389730 - Cosmetic - SitHigh and Drink Breakable (10.0 Explorers Tankard)
(@CGUID+30, 0, 0, 0, 0, 0, 1, 1, 431, 0, 0, 0, 0, ''), -- Guldros Onyxbrand
(@CGUID+31, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '275283'), -- Nethandril Duskthorn - 275283 - Cosmetic - Void Hands + UseStanding
(@CGUID+32, 0, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, '371465'), -- Salty Deckhand - 371465 - Cosmetic - Sleep Zzz Breakable
(@CGUID+33, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Hired Tidesage - 237594 - Cosmetic - Water Channel
(@CGUID+34, 0, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, '371465'), -- Salty Deckhand - 371465 - Cosmetic - Sleep Zzz Breakable
(@CGUID+35, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Dumpling
(@CGUID+36, 0, 0, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Selindra Nightdancer
(@CGUID+37, 0, 0, 5, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ji-Min Quickpaw
(@CGUID+38, 0, 0, 0, 0, 0, 1, 1, 431, 0, 0, 0, 0, ''), -- Clinkora Rustfuse
(@CGUID+39, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Salty Deckhand - 374210 - Channel: Hold Duck Plushie + TalkQuestion [DNT] (Large Races not WAI)
(@CGUID+40, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Alanatheth
(@CGUID+41, 0, 0, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Dauvin Thornworth
(@CGUID+42, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '383667'), -- Clovis - 383667 - Holding Bottles [DNT]
(@CGUID+43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Hired Tidesage - 237594 - Cosmetic - Water Channel
(@CGUID+44, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- Captain Ironbridge

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+30;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 378009, 2524, 1519, 4411, '0', 0, 0, -23.9469242095947265, 1.575587630271911621, 10.89620780944824218, 1.038039922714233398, 0.016160964965820312, 0.077109336853027343, 0.491801261901855468, 0.867135822772979736, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2, 378009, 2524, 1519, 4411, '0', 0, 0, -22.8581371307373046, 2.029956817626953125, 10.74582386016845703, 0.310177356004714965, 0.021648406982421875, 0.050992012023925781, 0.152868270874023437, 0.986692726612091064, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+3, 378009, 2524, 1519, 4411, '0', 0, 0, -20.4031486511230468, 1.148966908454895019, 10.41737079620361328, 5.406891345977783203, -0.02964448928833007, 0.0589752197265625, -0.42141437530517578, 0.904462873935699462, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+4, 378009, 2524, 1519, 4411, '0', 0, 0, -20.3772144317626953, 1.124375462532043457, 11.19835186004638671, 0.039012476801872253, 0.006883144378662109, 0.046392440795898437, 0.019123077392578125, 0.998716533184051513, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+5, 378009, 2524, 1519, 4411, '0', 0, 0, -0.49330022931098937, 2.621035337448120117, 6.88206338882446289, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+6, 378009, 2524, 1519, 4411, '0', 0, 0, -0.86096554994583129, 2.148575782775878906, 6.098372459411621093, 1.186188340187072753, 0, 0, 0.558929443359375, 0.829215228557586669, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+7, 378009, 2524, 1519, 4411, '0', 0, 0, 0.090626820921897888, 3.139798402786254882, 6.10000467300415039, 0.636739850044250488, 0, 0, 0.313018798828125, 0.949746966361999511, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+8, 297565, 2524, 1519, 4411, '0', 0, 0, 24.80295753479003906, 8.652777671813964843, 6.296417236328125, 5.925393581390380859, 0, 0, -0.17794322967529296, 0.984040737152099609, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+9, 297567, 2524, 1519, 4411, '0', 0, 0, 24.91233253479003906, 6.583333969116210937, 6.301306724548339843, 0.811578273773193359, 0, 0, 0.394743919372558593, 0.918791174888610839, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+10, 378009, 2524, 1519, 4411, '0', 0, 0, 13.45494365692138671, 9.741224288940429687, 11.90144824981689453, 5.304310321807861328, 0.004258632659912109, -0.01103782653808593, -0.47003555297851562, 0.882568180561065673, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+11, 297570, 2524, 1519, 4411, '0', 0, 0, 17.65191268920898437, -5.5069427490234375, 6.182915687561035156, 6.047565937042236328, 0, 0, -0.11753749847412109, 0.993068456649780273, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+12, 297571, 2524, 1519, 4411, '0', 0, 0, 17.83073043823242187, -7.42013740539550781, 6.184665203094482421, 0.663221180438995361, 0, 0, 0.325566291809082031, 0.945519208908081054, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+13, 297572, 2524, 1519, 4411, '0', 0, 0, 19.69184303283691406, -7.2256927490234375, 6.224917888641357421, 2.434734821319580078, 0, 0, 0.938191413879394531, 0.346116840839385986, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+14, 378009, 2524, 1519, 4411, '0', 0, 0, 13.37487030029296875, 9.668082237243652343, 12.69262409210205078, 0.965165257453918457, 0, 0, 0.464068412780761718, 0.885799348354339599, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+15, 378009, 2524, 1519, 4411, '0', 0, 0, 12.41112041473388671, 10.53279590606689453, 11.79609394073486328, 6.009530067443847656, 0, 0, -0.13640117645263671, 0.990653693675994873, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+16, 378009, 2524, 1519, 4411, '0', 0, 0, 12.52218246459960937, 9.257086753845214843, 11.80961513519287109, 0, 0, 0, 0, 1, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+17, 378009, 2524, 1519, 4411, '0', 0, 0, 27.76638221740722656, -6.67591476440429687, 12.84737491607666015, 0.927953243255615234, 0, 0, 0.447507858276367187, 0.894280016422271728, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+18, 297566, 2524, 1519, 4411, '0', 0, 0, 26.81163787841796875, 6.826388835906982421, 6.332414627075195312, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+19, 297568, 2524, 1519, 4411, '0', 0, 0, 24.44184303283691406, -7.41666650772094726, 6.293860435485839843, 1.239181041717529296, 0, 0, 0.580701828002929687, 0.814116358757019042, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+20, 297569, 2524, 1519, 4411, '0', 0, 0, 26.290802001953125, -4.99999952316284179, 6.324167728424072265, 4.057891845703125, 0, 0, -0.89687252044677734, 0.442289173603057861, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+21, 378009, 2524, 1519, 4411, '0', 0, 0, 28.03834152221679687, -6.65667676925659179, 13.63187885284423828, 0.210185497999191284, 0, 0, 0.104899406433105468, 0.994482815265655517, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+22, 378009, 2524, 1519, 4411, '0', 0, 0, 28.47947502136230468, -7.81330442428588867, 12.88535785675048828, 6.031972408294677734, 0, 0, -0.12527656555175781, 0.992121875286102294, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+23, 378009, 2524, 1519, 4411, '0', 0, 0, 28.93377685546875, -6.3671736717224121, 12.90066337585449218, 0.121744938194751739, 0, 0, 0.060834884643554687, 0.998147845268249511, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+24, 297573, 2524, 1519, 4411, '0', 0, 0, 26.42448043823242187, -6.89236164093017578, 6.325334548950195312, 2.434734821319580078, 0, 0, 0.938191413879394531, 0.346116840839385986, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+25, 297574, 2524, 1519, 4411, '0', 0, 0, 26.90191459655761718, 8.975694656372070312, 6.335384845733642578, 4.127703666687011718, 0, 0, -0.8808908462524414, 0.473319470882415771, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+26, 378009, 2524, 1519, 4411, '0', 0, 0, 29.17286872863769531, -7.17419672012329101, 13.72285175323486328, 6.020996570587158203, 0, 0, -0.13071918487548828, 0.991419434547424316, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+27, 297562, 2524, 1519, 4411, '0', 0, 0, 39.26128387451171875, 1.47569429874420166, 13.0307769775390625, 5.785771369934082031, 0, 0, -0.24615097045898437, 0.969231486320495605, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+28, 378009, 2524, 1519, 4411, '0', 0, 0, 29.78159523010253906, -7.46976232528686523, 12.94453620910644531, 0.350457847118377685, 0, 0, 0.174333572387695312, 0.984686672687530517, 120, 255, 1, 48069), -- Crate [DNT] (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+29, 297563, 2524, 1519, 4411, '0', 0, 0, 39.54948043823242187, -0.97569453716278076, 13.0307769775390625, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 48069), -- Chair (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+30, 297564, 2524, 1519, 4411, '0', 0, 0, 42.76128387451171875, -0.07638958096504211, 13.03080463409423828, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 48069); -- Chair (Area: Stormwind Harbor - Difficulty: 0)

-- Creature Template
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=184639; -- Eager Acquisitionist
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=187194; -- Restless Explorer
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194531; -- Selindra Nightdancer
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=184288; -- Captain Ironbridge
UPDATE `creature_template` SET `gossip_menu_id`=28989, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194393; -- Clovis
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194534; -- Dauvin Thornworth
UPDATE `creature_template` SET `gossip_menu_id`=29004, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194488; -- Guldros Onyxbrand
UPDATE `creature_template` SET `gossip_menu_id`=29003, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194484; -- Clinkora Rustfuse
UPDATE `creature_template` SET `gossip_menu_id`=29008, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194538; -- Ji-Min Quickpaw
UPDATE `creature_template` SET `gossip_menu_id`=29015, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194397; -- Nethandril Duskthorn
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194369; -- Alanatheth
UPDATE `creature_template` SET `gossip_menu_id`=28991, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=194493; -- Ogdan Stoneforge
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=194659; -- Dumpling
UPDATE `creature_template` SET `gossip_menu_id`=29021, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194539; -- Tizzi Twistcog
UPDATE `creature_template` SET `gossip_menu_id`=28994, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194537; -- Tishad
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=194470; -- Victor Bradwell
UPDATE `creature_template` SET `gossip_menu_id`=29002, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194536; -- Reluun
UPDATE `creature_template` SET `gossip_menu_id`=28990, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194490; -- Zuraan
UPDATE `creature_template` SET `gossip_menu_id`=29374, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=196091; -- Korston Willard
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=198362; -- (Bunny) Crow's Nest
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=34816, `VehicleId`=8013 WHERE `entry`=198363; -- (Bunny) Crow's Nest [DNT]
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194378; -- Hired Tidesage
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194437; -- Salty Deckhand
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3272, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=198748; -- Expedition Escort
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=104859648, `unit_flags3`=1 WHERE `entry`=197503; -- The Rugged Dragonscale
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=43103; -- Bluetip Thresher
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=104859648, `unit_flags3`=1 WHERE `entry`=197611; -- (Bunny) Sessile + Gigantic AOI
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=187196; -- Rugged Artisan
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=180701; -- (Bunny) Sessile
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=187193; -- Brave Researcher
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=102762496, `unit_flags3`=1 WHERE `entry`=180538; -- (Bunny) Sessile + Large AOI

-- Equip Template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (194531,184288,194397,194539,194490,196091,194378,198748));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(194531, 1, 165624, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Selindra Nightdancer
(184288, 1, 159584, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Captain Ironbridge
(194397, 1, 27905, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Nethandril Duskthorn
(194539, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Tizzi Twistcog
(194490, 1, 116488, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Zuraan
(196091, 1, 158073, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Korston Willard
(194378, 1, 159568, 0, 0, 0, 0, 0, 0, 0, 0, 48069), -- Hired Tidesage
(198748, 1, 158912, 0, 0, 0, 0, 0, 0, 0, 0, 48069); -- Expedition Escort

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=194470 AND `item`=160484 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=194470 AND `item`=159850 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=194470 AND `item`=159845 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=194470 AND `item`=159849 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=194470 AND `item`=159847 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=194470 AND `item`=159846 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=194470 AND `item`=159848 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(194470, 7, 160484, 0, 0, 1, 0, 0, 48069), -- "Aurora Borealis"
(194470, 6, 159850, 0, 0, 1, 0, 0, 48069), -- Bitter Darkroot Vodka
(194470, 5, 159845, 0, 0, 1, 0, 0, 48069), -- Brennadam Apple Brandy
(194470, 4, 159849, 0, 0, 1, 0, 0, 48069), -- Hook Point Schnapps
(194470, 3, 159847, 0, 0, 1, 0, 0, 48069), -- Mildenhall Mead
(194470, 2, 159846, 0, 0, 1, 0, 0, 48069), -- Whitegrove Pale Ale
(194470, 1, 159848, 0, 0, 1, 0, 0, 48069); -- Blacktooth Bloodwine

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+10;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 226899, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194393 (Clovis)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 227024, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194539 (Tizzi Twistcog)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 226900, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194490 (Zuraan)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 226915, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194537 (Tishad)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 226974, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194536 (Reluun)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 229172, 0, 0, 0, 0, 0, 0, 0, 48069), -- 196091 (Korston Willard)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 226977, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194484 (Clinkora Rustfuse)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 226986, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194488 (Guldros Onyxbrand)
(@NPCTEXTID+8, 1, 0, 0, 0, 0, 0, 0, 0, 226999, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194538 (Ji-Min Quickpaw)
(@NPCTEXTID+9, 1, 0, 0, 0, 0, 0, 0, 0, 227016, 0, 0, 0, 0, 0, 0, 0, 48069), -- 194397 (Nethandril Duskthorn)
(@NPCTEXTID+10, 1, 0, 0, 0, 0, 0, 0, 0, 226902, 0, 0, 0, 0, 0, 0, 0, 48069); -- 194493 (Ogdan Stoneforge)

DELETE FROM `gossip_menu` WHERE (`MenuID`=28989 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=29021 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=28990 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=28994 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=29002 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=29374 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=29003 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=29004 AND `TextID`=@NPCTEXTID+7) OR (`MenuID`=29008 AND `TextID`=@NPCTEXTID+8) OR (`MenuID`=29015 AND `TextID`=@NPCTEXTID+9) OR (`MenuID`=28991 AND `TextID`=@NPCTEXTID+10);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(28989, @NPCTEXTID+0, 48069), -- 194393 (Clovis)
(29021, @NPCTEXTID+1, 48069), -- 194539 (Tizzi Twistcog)
(28990, @NPCTEXTID+2, 48069), -- 194490 (Zuraan)
(28994, @NPCTEXTID+3, 48069), -- 194537 (Tishad)
(29002, @NPCTEXTID+4, 48069), -- 194536 (Reluun)
(29374, @NPCTEXTID+5, 48069), -- 196091 (Korston Willard)
(29003, @NPCTEXTID+6, 48069), -- 194484 (Clinkora Rustfuse)
(29004, @NPCTEXTID+7, 48069), -- 194488 (Guldros Onyxbrand)
(29008, @NPCTEXTID+8, 48069), -- 194538 (Ji-Min Quickpaw)
(29015, @NPCTEXTID+9, 48069), -- 194397 (Nethandril Duskthorn)
(28991, @NPCTEXTID+10, 48069); -- 194493 (Ogdan Stoneforge)

 -- Hired Tidesage smart ai
SET @ENTRY := 194378;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 237594, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 237594 on Self');

-- Salty Deckhand smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 194437;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+9), -(@CGUID+10), -(@CGUID+18), -(@CGUID+39));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+9), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 374148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 374148 on Self'),
(-(@CGUID+10), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 372498, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 372498 on Self'),
(-(@CGUID+18), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 372498, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 372498 on Self'),
(-(@CGUID+39), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 374210, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 374210 on Self');
