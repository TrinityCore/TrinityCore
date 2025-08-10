SET @CGUID := 1051943;
SET @OGUID := 600246;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 156821, 2236, 10581, 10581, '150', 0, 0, 0, 1, 831.357666015625, -1794.3038330078125, 181.27142333984375, 4.981048107147216796, 7200, 0, 0, 252, 205, 0, 0, 0, 0, 49570), -- Darkmaul Shadowcaller (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 305886 - Arcane Channel)
(@CGUID+1, 156825, 2236, 10581, 10581, '150', 0, 0, 0, 1, 816.17218017578125, -1782.96875, 181.4786376953125, 3.761460065841674804, 7200, 0, 0, 288, 0, 0, 0, 0, 0, 49570), -- Darkmaul Centurion (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+2, 156828, 2236, 10581, 10581, '150', 0, 0, 0, 0, 835.109375, -1807.9774169921875, 184.0892486572265625, 0, 7200, 0, 0, 238, 0, 0, 0, 0, 0, 49570), -- Shadowy Orb (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 305885 - Arcane Lock)
(@CGUID+3, 156825, 2236, 10581, 10581, '150', 0, 0, 0, 1, 843.88726806640625, -1865.58203125, 187.9647216796875, 0.881374239921569824, 7200, 0, 0, 288, 0, 0, 0, 0, 0, 49570), -- Darkmaul Centurion (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+4, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 891.43603515625, -1773.525146484375, 181.19171142578125, 2.297332525253295898, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 844.7672119140625, -1761.644287109375, 181.39483642578125, 2.144350528717041015, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 157328, 2236, 10581, 10581, '150', 0, 0, 0, 0, 839.170166015625, -1906.6927490234375, 234.7349700927734375, 4.471726417541503906, 7200, 0, 0, 252, 0, 0, 0, 0, 0, 49570), -- Darkmaul Channeler (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 306457 - Dark Ritual)
(@CGUID+7, 156821, 2236, 10581, 10581, '150', 0, 0, 0, 1, 846.81768798828125, -1811.2899169921875, 181.27142333984375, 2.882283926010131835, 7200, 0, 0, 252, 205, 0, 0, 0, 0, 49570), -- Darkmaul Shadowcaller (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 305886 - Arcane Channel)
(@CGUID+8, 156825, 2236, 10581, 10581, '150', 0, 0, 0, 1, 884.34722900390625, -1908.2239990234375, 211.024688720703125, 2.211764335632324218, 7200, 0, 0, 288, 0, 0, 0, 0, 0, 49570), -- Darkmaul Centurion (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+9, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 877.564697265625, -1826.155517578125, 181.3948516845703125, 5.735508441925048828, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 915.6767578125, -1795.92578125, 249.2879791259765625, 5.219739913940429687, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 156821, 2236, 10581, 10581, '150', 0, 0, 0, 1, 826.87677001953125, -1815.2552490234375, 181.27142333984375, 0.95785754919052124, 7200, 0, 0, 252, 205, 0, 0, 0, 0, 49570), -- Darkmaul Shadowcaller (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 305886 - Arcane Channel)
(@CGUID+12, 156501, 2236, 10581, 10581, '150', 0, 0, 0, 0, 831.404541015625, -1802.4132080078125, 248.6796875, 2.030389785766601562, 7200, 0, 0, 1218, 100, 0, 0, 0, 0, 49570), -- Ravnyr (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 318318 - Awaken (DNT))
(@CGUID+13, 156825, 2236, 10581, 10581, '150', 0, 0, 0, 1, 891.1632080078125, -1904.939208984375, 211.024688720703125, 2.211764335632324218, 7200, 0, 0, 288, 0, 0, 0, 0, 0, 49570), -- Darkmaul Centurion (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+14, 156814, 2236, 10581, 10581, '150', 0, 0, 0, 1, 825.10589599609375, -1775.123291015625, 248.6848602294921875, 5.979738235473632812, 7200, 0, 0, 1218, 249, 0, 0, 0, 0, 49570), -- Gor'groth (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 306097 - Summon Ghouls)
(@CGUID+15, 157328, 2236, 10581, 10581, '150', 0, 0, 0, 0, 871.40625, -1871.736083984375, 248.8018341064453125, 4.022061347961425781, 7200, 0, 0, 252, 0, 0, 0, 0, 0, 49570), -- Darkmaul Channeler (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 306457 - Dark Ritual)
(@CGUID+16, 157300, 2236, 10581, 10581, '150', 0, 0, 0, 1, 913.77606201171875, -1953.361083984375, 211.024688720703125, 2.125648260116577148, 7200, 0, 0, 870, 0, 0, 0, 0, 0, 49570), -- Tunk (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+17, 165198, 2236, 10581, 10581, '150', 0, 0, 0, 0, 832.84027099609375, -1805.3004150390625, 248.6804962158203125, 0, 7200, 0, 0, 119, 0, 0, 0, 0, 0, 49570), -- InvisBunny (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: 321806 - Necrotic Storm (Cosmetic 01))
(@CGUID+18, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 853.1070556640625, -1832.0548095703125, 248.6716766357421875, 3.850758075714111328, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 789.33880615234375, -1822.114013671875, 181.39483642578125, 3.952449798583984375, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 799.86944580078125, -1841.644287109375, 181.4062042236328125, 1.52156233787536621, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 915.78167724609375, -1870.70556640625, 196.6319122314453125, 4.391551017761230468, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 869.6441650390625, -1863.8690185546875, 248.9327545166015625, 2.909489631652832031, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+23, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 862.93328857421875, -1868.9619140625, 248.8384552001953125, 5.526076316833496093, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+24, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 795.11285400390625, -1838.482666015625, 257.248504638671875, 0, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 875.59442138671875, -1873.66455078125, 248.885009765625, 3.064635276794433593, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 761.14990234375, -1786.6700439453125, 248.770111083984375, 0.306713670492172241, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 868.88543701171875, -1878.6658935546875, 248.858001708984375, 6.232998847961425781, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+28, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 852.9757080078125, -1908.21875, 196.32904052734375, 0, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@CGUID+29, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 902.5970458984375, -1870.5595703125, 248.9082489013671875, 0.373412966728210449, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+30, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 833.4759521484375, -1910.63427734375, 232.9278564453125, 4.42017221450805664, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@CGUID+31, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 845.369140625, -1901.677734375, 237.407257080078125, 0.850063681602478027, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@CGUID+32, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 843.25518798828125, -1912.7257080078125, 232.6168060302734375, 2.514199256896972656, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@CGUID+33, 166262, 2236, 10581, 10581, '150', 0, 0, 0, 0, 835.21173095703125, -1913.820068359375, 231.82806396484375, 2.960769176483154296, 7200, 6, 0, 21, 0, 1, 0, 0, 0, 49570), -- Decaying Corpse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@CGUID+34, 168740, 2236, 10581, 10581, '150', 0, 0, 0, 0, 869.584716796875, -1926.924560546875, 210.98858642578125, 1.328571796417236328, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Recluse (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@CGUID+35, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 938.7138671875, -1923.637939453125, 210.98858642578125, 1.915426611900329589, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570), -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 168738, 2236, 10581, 10581, '150', 0, 0, 0, 0, 842.7252197265625, -1969.9239501953125, 217.5979461669921875, 1.265888214111328125, 7200, 10, 0, 5, 0, 1, 0, 0, 0, 49570); -- Citadel Rat (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 336442, 2236, 10581, 10581, '150', 0, 0, 894.65673828125, -1829.4703369140625, 249.114227294921875, 4.860551357269287109, 0, 0, -0.65283203125, 0.757502675056457519, 7200, 255, 0, 49570), -- 6DU_HighmaulRaid_Door02 (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@OGUID+1, 252247, 2236, 10581, 10581, '150', 0, 0, 914.8038330078125, -1762.1961669921875, 184.3816070556640625, 3.632784366607666015, 0, 0, -0.96999263763427734, 0.243134275078773498, 7200, 255, 1, 49570), -- Instance Portal (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@OGUID+2, 334502, 2236, 10581, 10581, '150', 0, 0, 861.404541015625, -1957.845458984375, 217.443145751953125, 0.510369598865509033, 0, 0, 0.252424240112304687, 0.967616677284240722, 7200, 255, 1, 49570), -- TEMP DOOR (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@OGUID+3, 334578, 2236, 10581, 10581, '150', 0, 0, 849.86456298828125, -1834.842041015625, 181.30084228515625, 2.070149421691894531, 0, 0, 0.859900474548339843, 0.510461747646331787, 7200, 255, 1, 49570), -- Shadowy Door (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
(@OGUID+4, 336441, 2236, 10581, 10581, '150', 0, 0, 844.3118896484375, -1897.404541015625, 356.63299560546875, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 7200, 255, 1, 49570); -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001 (Area: Darkmaul Citadel - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.951056420803070068, -0.30901727080345153, 0, 0), -- 6DU_HighmaulRaid_Door02
(@OGUID+4, 0, 0, 0.951056420803070068, -0.30901727080345153, 0, 0); -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001

-- Creature Template
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (156913, 166262); -- Decaying Corpse
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=16777216, `flags_extra` = 128 WHERE `entry`=165198; -- InvisBunny
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=157300; -- Tunk
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=156814; -- Gor'groth
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=33587520, `unit_flags2`=2099200 WHERE `entry`=156501; -- Ravnyr
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=168738; -- Citadel Rat
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=157328; -- Darkmaul Channeler
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=168740; -- Citadel Recluse
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=4196352 WHERE `entry`=156828; -- Shadowy Orb
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=156825; -- Darkmaul Centurion
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=156821; -- Darkmaul Shadowcaller

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (156501, 156814, 156828, 157328, 156821, 156825, 157300);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(156501, 0, 0, 0, 0, 0, 1, 0, 0, 11415, 0, 0, 3, ''), -- 156501 (Ravnyr)
(156814, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 156814 (Gor'groth)
(156828, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '305885'), -- 156828 (Shadowy Orb)
(157328, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '214567'), -- 157328 (Darkmaul Channeler) - 214567 - Mod Scale 90-110%
(156821, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Darkmaul Shadowcaller
(156825, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Darkmaul Centurion
(157300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 157300 (Tunk)

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (156828);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(156828, 0, 0, 1, 1, 0, 0, NULL);

 -- Darkmaul Channeler smart ai
SET @ENTRY := 157328;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 306457, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC after 1s (once) - Self: Cast spell 306457 on Self');

-- Waypoints for CGUID+1
SET @PATH := ((@CGUID+1) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 810.1371, -1787.276, 181.5017, NULL, 0),
(@PATH, 1, 804.8351, -1801.014, 181.5524, NULL, 0),
(@PATH, 2, 807.9167, -1820.616, 181.4882, NULL, 4584),
(@PATH, 3, 804.8351, -1801.014, 181.5524, NULL, 0),
(@PATH, 4, 810.1371, -1787.276, 181.5017, NULL, 0),
(@PATH, 5, 822.3143, -1778.585, 181.4552, NULL, 0),
(@PATH, 6, 833.6268, -1776.045, 181.4288, NULL, 4604),
(@PATH, 7, 822.3143, -1778.585, 181.4552, NULL, 0);

UPDATE `creature` SET `position_x`= 810.1371, `position_y`= -1787.276, `position_z`= 181.5017, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+1, @PATH, 1, 3);

-- Waypoints for CGUID+3
SET @PATH := ((@CGUID+3) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 838.3351, -1902.979, 196.4424, NULL, 0),
(@PATH, 1, 825.6614, -1895.762, 196.3948, NULL, 0),
(@PATH, 2, 829.2361, -1883.356, 196.5681, NULL, 0),
(@PATH, 3, 843.8873, -1865.582, 187.9647, NULL, 5196),
(@PATH, 4, 829.2554, -1883.333, 196.6822, NULL, 0),
(@PATH, 5, 825.6614, -1895.762, 196.3948, NULL, 0),
(@PATH, 6, 838.3351, -1902.979, 196.4424, NULL, 0),
(@PATH, 7, 848.8663, -1896.222, 196.3948, NULL, 0),
(@PATH, 8, 864.2587, -1880.941, 207.7968, NULL, 5093),
(@PATH, 9, 848.8663, -1896.222, 196.3948, NULL, 0);

UPDATE `creature` SET `position_x`= 838.3351, `position_y`= -1902.979, `position_z`= 196.4424, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+3, @PATH, 1, 3);
