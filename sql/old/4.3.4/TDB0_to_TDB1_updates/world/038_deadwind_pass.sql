DELETE FROM `gameobject_template` WHERE `entry`=176574;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(176574, 8, 216, 'Cauldron', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595); -- Cauldron

SET @OGUID := 89;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 176558, 0, 1, 1, -10879.24, -2155.033, 117.1314, 1.152369, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: 0)
(@OGUID+1, 176574, 0, 1, 1, -10802.03, -2192.335, 117.1313, 6.237644, 0, 0, 0, 1, 120, 255, 1), -- Cauldron (Area: The Vice)
(@OGUID+2, 207489, 0, 1, 1, -10803.14, -2201.677, 117.1313, 2.146753, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: The Vice)
(@OGUID+3, 176559, 0, 1, 1, -11003.67, -2307.094, 117.1314, 2.460005, 0, 0, 0, 1, 120, 255, 1), -- Cauldron (Area: The Vice)
(@OGUID+4, 176560, 0, 1, 1, -11083.09, -2303.917, 117.1314, 3.345237, 0, 0, 0, 1, 120, 255, 1), -- Bonfire (Area: The Vice)
(@OGUID+5, 176464, 0, 1, 1, -10436.73, -2140.204, 90.77924, 4.101525, 0, 0, 0, 1, 120, 255, 1), -- Campfire (Area: 0)
(@OGUID+6, 177185, 0, 1, 1, -10451.55, -1721.817, 86.44454, 5.218536, 0, 0, 0, 1, 120, 255, 1), -- Abandon hope, all ye who enter here. (Area: 0)
(@OGUID+7, 177186, 0, 1, 1, -10451.48, -1721.776, 87.8886, 1.806413, 0, 0, 0, 1, 120, 255, 1), -- Turn Back! (Area: 0)
(@OGUID+8, 160866, 0, 1, 1, -11182.31, -1851.328, 73.94241, 3.988081, 0, 0, 0.1779436, 0.9840407, 120, 255, 1), -- Pew (Area: Morgan's Plot)
(@OGUID+9, 160867, 0, 1, 1, -11185.03, -1852.347, 73.94241, 3.630291, 0, 0, 0.1779436, 0.9840407, 120, 255, 1), -- Pew (Area: Morgan's Plot)
(@OGUID+10, 160869, 0, 1, 1, -11171.69, -1859.701, 73.94241, 2.295104, 0, 0, 0.1779436, 0.9840407, 120, 255, 1), -- Pew (Area: Morgan's Plot)
(@OGUID+11, 160871, 0, 1, 1, -11177.52, -1848.642, 73.94241, 4.843292, 0, 0, 0.1779436, 0.9840407, 120, 255, 1), -- Pew (Area: Morgan's Plot)
(@OGUID+12, 160868, 0, 1, 1, -11181.55, -1861.522, 73.94241, 3.150327, 0, 0, 0.1779436, 0.9840407, 120, 255, 1), -- Pew (Area: Morgan's Plot)
(@OGUID+13, 160870, 0, 1, 1, -11175.2, -1860.019, 73.94241, 2.111848, 0, 0, 0.1779436, 0.9840407, 120, 255, 1), -- Pew (Area: Morgan's Plot)
(@OGUID+14, 181963, 0, 1, 1, -11182.62, -1958.317, 55.73286, 4.625124, 0, 0, 0, 1, 120, 255, 1), -- Charred Bone Fragment (Area: Karazhan)
(@OGUID+15, 184463, 0, 1, 1, -11129.27, -1994.17, 48.45858, 1.40499, 0, 0, 0, 1, 120, 255, 1); -- Meeting Stone (Area: Karazhan)

UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=56, `faction_A`=14, `faction_H`=14, `speed_walk`=1.428571, `speed_run`=1.2, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=7376; -- Sky Shadow
UPDATE `creature_template` SET `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=51983; -- Deadwind Widow
UPDATE `creature_template` SET `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33587968, `HoverHeight`=1 WHERE `entry`=51984; -- Deadwind Widow Invisible Stalker
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=70, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1.111112, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=12377; -- Wailing Spectre
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=69, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1.111112, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `HoverHeight`=1 WHERE `entry`=12378; -- Damned Soul
UPDATE `creature_template` SET `minlevel`=57, `maxlevel`=58, `faction_A`=45, `faction_H`=45, `speed_walk`=1.142857, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `HoverHeight`=1 WHERE `entry`=7372; -- Deadwind Warlock
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=57, `faction_A`=45, `faction_H`=45, `speed_walk`=1.142857, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `HoverHeight`=1 WHERE `entry`=7379; -- Deadwind Ogre Mage
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=56, `faction_A`=45, `faction_H`=45, `speed_walk`=1.142857, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=7369; -- Deadwind Brute
UPDATE `creature_template` SET `minlevel`=49, `maxlevel`=52, `faction_A`=22, `faction_H`=22, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=51987; -- Deadwind Widow
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=70, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `HoverHeight`=1 WHERE `entry`=12379; -- Unliving Caretaker
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=69, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `HoverHeight`=1 WHERE `entry`=7370; -- Restless Shade
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=70, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `HoverHeight`=1 WHERE `entry`=12380; -- Unliving Resident
UPDATE `creature_template` SET `minlevel`=56, `maxlevel`=57, `faction_A`=45, `faction_H`=45, `speed_walk`=1.142857, `speed_run`=1.6, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=7371; -- Deadwind Mauler
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=32520; -- Totally Generic Bunny (All Phase)
UPDATE `creature_template` SET `gossip_menu_id`=8441, `minlevel`=69, `maxlevel`=69, `faction_A`=1696, `faction_H`=1696, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=18253; -- Archmage Leryda
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=114, `faction_H`=114, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=18162; -- Underground Pond Credit Marker
UPDATE `creature_template` SET `gossip_menu_id`=7594, `minlevel`=70, `maxlevel`=70, `faction_A`=1696, `faction_H`=1696, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=17613; -- Archmage Alturus
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction_A`=1696, `faction_H`=1696, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=18255; -- Apprentice Darius
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=32638; -- Hakmud of Argus
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=32639; -- Gnimo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=114, `faction_H`=114, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=18161; -- Underground Well Credit Marker


DELETE FROM `creature_template_addon` WHERE `entry` IN (7376, 7376, 51983, 51984, 51983, 51984, 7376, 7376, 51983, 51983, 51984, 7376, 7376, 7376, 51983, 51983, 51983, 51984, 51983, 7376, 51984, 51983, 7376, 51984, 51984, 51983, 51983, 51983, 51983, 7376, 12377, 7376, 12378, 51983, 51983, 51983, 51984, 51984, 51984, 7372, 7379, 7369, 51987, 51987, 7379, 7379, 7379, 7379, 7369, 51987, 51987, 51987, 51987, 7379, 51987, 7379, 51987, 7369, 7379, 7369, 7379, 51987, 7379, 7379, 7379, 7369, 51987, 51987, 51987, 51987, 12379, 12379, 12377, 12378, 7370, 12377, 7370, 12377, 7370, 12378, 12377, 7370, 12379, 12377, 12377, 12378, 7370, 12379, 12378, 12377, 12378, 12379, 12378, 12377, 12377, 7370, 12378, 12378, 12380, 12379, 7370, 12380, 7371, 7372, 7372, 7371, 51987, 51987, 51987, 51987, 51987, 51987, 51987, 51983, 51984, 51983, 51984, 51984, 51983, 51983, 51983, 51984, 51983, 51984, 51983, 51984, 51984, 51983, 7376, 51984, 51983, 51983, 51984, 51984, 51984, 51983, 51983, 51984, 51983, 51984, 51983, 51984, 51984, 51984, 51983, 51983, 51984, 51984, 51983, 51983, 51984, 51984, 51983, 51983, 51983, 51984, 51984, 51984, 51984, 51983, 51983, 51983, 51983, 51983, 51983, 51984, 51984, 51984, 51984, 51983, 51983, 51983, 51983, 7376, 51983, 32520, 32520, 32520, 32520, 12377, 7370, 12379, 7370, 12377, 18253, 12380, 12380, 12380, 12379, 12379, 12378, 12379, 12380, 12380, 12378, 12377, 12377, 12378, 7370, 12379, 7370, 12377, 12379, 18162, 12380, 18162, 12380, 12380, 18162, 12380, 12380, 12380, 17613, 18255, 12380, 12380, 12380, 12380, 12380, 12380, 12377, 7370, 12380, 51987, 51987, 12379, 32520, 32520, 32520, 32520, 32638, 32639, 12378, 7370, 12377, 12380, 18161, 7370, 12377, 12379, 12378, 7370, 32520, 32520, 32520, 32520, 7371, 7371, 7372, 51987, 51987, 7372, 7372, 7371, 51987, 51987, 51987, 7369, 51987, 51987, 51987, 51983);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(7376, 0, 0x0, 0x1, ''), -- Sky Shadow
-- (51983, 0, 0x0, 0x1, '96199'), -- Deadwind Widow - Deadwind Web
(51984, 0, 0x0, 0x1, ''), -- Deadwind Widow Invisible Stalker
(51983, 0, 0x0, 0x1, ''), -- Deadwind Widow
(12377, 0, 0x0, 0x1, ''), -- Wailing Spectre
(12378, 0, 0x0, 0x1, ''), -- Damned Soul
(7372, 0, 0x0, 0x1, ''), -- Deadwind Warlock
-- (7379, 0, 0x0, 0x1, ''), -- Deadwind Ogre Mage
(7369, 0, 0x0, 0x1, '8876'), -- Deadwind Brute - Thrash
(51987, 0, 0x0, 0x1, ''), -- Deadwind Widow
-- (7379, 0, 0x0, 0x1, '12550'), -- Deadwind Ogre Mage - Lightning Shield
(7379, 0, 0x0, 0x1, '12550 6742'), -- Deadwind Ogre Mage - Lightning Shield, Bloodlust
(12379, 0, 0x0, 0x1, ''), -- Unliving Caretaker
(7370, 0, 0x0, 0x1, ''), -- Restless Shade
(12380, 0, 0x0, 0x1, ''), -- Unliving Resident
(7371, 0, 0x0, 0x1, ''), -- Deadwind Mauler
(32520, 0, 0x0, 0x1, ''), -- Totally Generic Bunny (All Phase)
(18253, 0, 0x0, 0x1, ''), -- Archmage Leryda
(18162, 0, 0x0, 0x1, ''), -- Underground Pond Credit Marker
(17613, 0, 0x0, 0x1, ''), -- Archmage Alturus
(18255, 0, 0x0, 0x1, ''), -- Apprentice Darius
(32638, 0, 0x0, 0x1, '61424'), -- Hakmud of Argus - Traveler's Tundra Mammoth
(32639, 0, 0x0, 0x1, '61424'), -- Gnimo - Traveler's Tundra Mammoth
(18161, 0, 0x0, 0x1, ''); -- Underground Well Credit Marker

UPDATE `creature_model_info` SET `bounding_radius`=0.8, `combat_reach`=0.8 WHERE `modelid`=4870;
UPDATE `creature_model_info` SET `bounding_radius`=0.15, `combat_reach`=1.875 WHERE `modelid`=10826;
UPDATE `creature_model_info` SET `bounding_radius`=2.09855, `combat_reach`=3.525, `gender`=0 WHERE `modelid`=11533;
UPDATE `creature_model_info` SET `bounding_radius`=2.2325, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=11536;
UPDATE `creature_model_info` SET `bounding_radius`=2.35, `combat_reach`=3.525, `gender`=0 WHERE `modelid`=11537;
UPDATE `creature_model_info` SET `bounding_radius`=2.5, `combat_reach`=3.75, `gender`=0 WHERE `modelid`=11538;
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=2.25 WHERE `modelid`=11649;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=12430;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=12431;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=13949;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=13950;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=13951;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=13952;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=13953;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=13954;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=17123;
UPDATE `creature_model_info` SET `bounding_radius`=0.44045, `combat_reach`=1.725, `gender`=1 WHERE `modelid`=17641;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=17645;
UPDATE `creature_model_info` SET `bounding_radius`=0.125, `combat_reach`=0.25 WHERE `modelid`=23711;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=28111;
UPDATE `creature_model_info` SET `bounding_radius`=0.465, `combat_reach`=1.5 WHERE `modelid`=28282;

SET @CGUID := 1118;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+261;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 7376, 0, 1, 1, -10528.57, -1747.725, 88.69102, 4.117302, 120, 0, 0), -- Sky Shadow (Area: -Unknown-)
(@CGUID+1, 7376, 0, 1, 1, -10376.99, -1770.518, 96.25208, 2.558559, 120, 0, 0), -- Sky Shadow (Area: Deadman's Crossing)
(@CGUID+2, 51983, 0, 1, 1, -10561.45, -1838.767, 126.973, 2.495821, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+3, 51984, 0, 1, 1, -10565.5, -1775.889, 119.9772, 1.658063, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+4, 51983, 0, 1, 1, -10565.49, -1775.861, 117.4535, 2.495821, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+5, 51984, 0, 1, 1, -10561.47, -1838.795, 129.838, 1.658063, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+6, 7376, 0, 1, 1, -10558.13, -1778.215, 94.70944, 2.415599, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+7, 7376, 0, 1, 1, -10562.01, -1714.788, 95.09022, 6.210905, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+8, 51983, 0, 1, 1, -10680.07, -1834.25, 137.0993, 5.983475, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+9, 51983, 0, 1, 1, -10572.87, -1843.575, 126.7888, 0.3665192, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+10, 51984, 0, 1, 1, -10571.99, -1843.554, 129.6538, 5.811946, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+11, 7376, 0, 1, 1, -10559.31, -1857.101, 111.7748, 0.3340956, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+12, 7376, 0, 1, 1, -10685.85, -1877.929, 114.5874, 4.852045, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+13, 7376, 0, 1, 1, -10622.92, -1918.75, 118.7153, 5.55906, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+14, 51983, 0, 1, 1, -10626.37, -1947.192, 144.2927, 2.012865, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine) (possible waypoints or random movement)
(@CGUID+15, 51983, 0, 1, 1, -10629.8, -1975.611, 147.2144, 0.5172054, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine) (possible waypoints or random movement)
(@CGUID+16, 51983, 0, 1, 1, -10537.63, -1950.804, 108.1456, 4.331677, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine) (possible waypoints or random movement)
(@CGUID+17, 51984, 0, 1, 1, -10728.45, -2007.446, 163.5349, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+18, 51983, 0, 1, 1, -10727.87, -2008.481, 156.0327, 2.932153, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+19, 7376, 0, 1, 1, -10714.34, -2026.301, 122.7333, 4.733871, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+20, 51984, 0, 1, 1, -10754.63, -1826.146, 141.1527, 5.811946, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+21, 51983, 0, 1, 1, -10755.5, -1826.167, 139.1808, 0.3665192, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+22, 7376, 0, 1, 1, -10738.5, -1839.249, 114.6958, 0.6895798, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+23, 51984, 0, 1, 1, -10868.31, -1891.849, 141.0696, 0.7330383, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+24, 51984, 0, 1, 1, -10849.67, -1896.247, 133.703, 5.811946, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+25, 51983, 0, 1, 1, -10868.81, -1892.797, 135.4476, 0.9599311, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+26, 51983, 0, 1, 1, -10850.55, -1896.267, 129.8015, 0.3665192, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+27, 51983, 0, 1, 1, -10842.06, -1900.384, 142.9395, 3.729835, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine) (possible waypoints or random movement)
(@CGUID+28, 51983, 0, 1, 1, -10863.37, -1886.65, 154.7358, 1.175888, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine) (possible waypoints or random movement)
(@CGUID+29, 7376, 0, 1, 1, -10843.4, -1883.508, 114.5566, 3.926991, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+30, 12377, 0, 1, 1, -10959.43, -1891.494, -17.20676, 4.954043, 120, 0, 0), -- Wailing Spectre (Area: Deadwind Ravine)
(@CGUID+31, 7376, 0, 1, 1, -10905.05, -1953.397, 114.849, 0.154168, 120, 0, 0), -- Sky Shadow (Area: Deadwind Ravine)
(@CGUID+32, 12378, 0, 1, 1, -10929.13, -1873.094, -17.68215, 0.4255078, 120, 0, 0), -- Damned Soul (Area: Deadwind Ravine)
(@CGUID+33, 51983, 0, 1, 1, -10882.62, -2047.285, 145.3849, 5.846853, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+34, 51983, 0, 1, 1, -10893.23, -2064.351, 151.9095, 2.932153, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+35, 51983, 0, 1, 1, -10885.4, -2058.712, 152.0483, 2.932153, 120, 0, 0), -- Deadwind Widow (Area: Deadwind Ravine)
(@CGUID+36, 51984, 0, 1, 1, -10881.59, -2047.58, 151.7857, 5.61996, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+37, 51984, 0, 1, 1, -10886.7, -2057.726, 157.2521, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+38, 51984, 0, 1, 1, -10893.8, -2063.316, 157.9161, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Deadwind Ravine)
(@CGUID+39, 7372, 0, 1, 1, -10945.9, -2156.291, 116.1444, 1.703605, 120, 0, 0), -- Deadwind Warlock (Area: 0)
(@CGUID+40, 7379, 0, 1, 1, -10885.63, -2147.69, 117.2564, 1.929932, 120, 0, 0), -- Deadwind Ogre Mage (Area: 0)
(@CGUID+41, 7369, 0, 1, 1, -10871.04, -2144.27, 117.2564, 5.355483, 120, 0, 0), -- Deadwind Brute (Area: 0)
(@CGUID+42, 51987, 0, 1, 1, -10872.27, -2139.397, 117.2564, 4.959772, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+43, 51987, 0, 1, 1, -10875.32, -2141.641, 117.2564, 3.734061, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+44, 7379, 0, 1, 1, -10847.02, -2116.657, 121.2564, 6.225863, 120, 0, 0), -- Deadwind Ogre Mage (Area: 0)
(@CGUID+45, 7379, 0, 1, 1, -10873.2, -2169.075, 117.2564, 0.8920119, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+46, 7379, 0, 1, 1, -10826.48, -2145.127, 122.2352, 3.284276, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+47, 7379, 0, 1, 1, -10812.24, -2194.704, 117.2563, 3.190124, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+48, 7369, 0, 1, 1, -10802.33, -2180.277, 117.3438, 2.342447, 120, 0, 0), -- Deadwind Brute (Area: The Vice)
(@CGUID+49, 51987, 0, 1, 1, -10800.8, -2175.488, 117.3041, 4.40456, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+50, 51987, 0, 1, 1, -10802.88, -2185.271, 117.2563, 1.46154, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+51, 51987, 0, 1, 1, -10823.48, -2141.096, 122.1702, 4.072746, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+52, 51987, 0, 1, 1, -10811.31, -2199.64, 117.3103, 1.758081, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+53, 7379, 0, 1, 1, -10860.15, -2278.95, 117.2563, 3.233772, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+54, 51987, 0, 1, 1, -10855.35, -2277.453, 117.2563, 3.444014, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+55, 7379, 0, 1, 1, -10916.1, -2217.219, 117.3953, 1.922373, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+56, 51987, 0, 1, 1, -10917.65, -2212.438, 117.4255, 5.025305, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+57, 7369, 0, 1, 1, -10948.86, -2282.981, 117.2563, 4.698759, 120, 0, 0), -- Deadwind Brute (Area: The Vice)
(@CGUID+58, 7379, 0, 1, 1, -10869.08, -2290.724, 117.2563, 5.414701, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+59, 7369, 0, 1, 1, -11012.43, -2307.54, 117.2563, 2.598985, 120, 0, 0), -- Deadwind Brute (Area: The Vice)
(@CGUID+60, 7379, 0, 1, 1, -10997.07, -2304.261, 117.2564, 5.962799, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+61, 51987, 0, 1, 1, -10924.17, -2195.778, 119.8964, 0, 120, 0, 0), -- Deadwind Widow (Area: The Vice) (possible waypoints or random movement)
(@CGUID+62, 7379, 0, 1, 1, -11080.76, -2280.235, 117.2564, 3.820437, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+63, 7379, 0, 1, 1, -11085.94, -2321.74, 117.2563, 2.729552, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+64, 7379, 0, 1, 1, -11146.76, -2270.454, 121.3982, 3.402273, 120, 0, 0), -- Deadwind Ogre Mage (Area: The Vice)
(@CGUID+65, 7369, 0, 1, 1, -11121.16, -2297.764, 117.2564, 1.055471, 120, 0, 0), -- Deadwind Brute (Area: The Vice)
(@CGUID+66, 51987, 0, 1, 1, -11125.98, -2296.344, 117.2564, 5.996577, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+67, 51987, 0, 1, 1, -11125.62, -2300.091, 117.2563, 4.809819, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+68, 51987, 0, 1, 1, -11151.64, -2271.565, 121.2715, 0.2235284, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+69, 51987, 0, 1, 1, -11070.41, -2338.845, 129.8966, 2.024582, 120, 0, 0), -- Deadwind Widow (Area: The Vice) (possible waypoints or random movement)
(@CGUID+70, 12379, 0, 1, 1, -11150.94, -2226.766, 22.70701, 0.6847295, 120, 0, 0), -- Unliving Caretaker (Area: The Vice)
(@CGUID+71, 12379, 0, 1, 1, -11136.57, -2208.983, 22.5736, 4.520443, 120, 0, 0), -- Unliving Caretaker (Area: The Vice)
(@CGUID+72, 12377, 0, 1, 1, -11102.06, -2213.408, 13.73716, 0.7548007, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+73, 12378, 0, 1, 1, -11118.43, -2200.699, 19.22469, 1.771417, 120, 0, 0), -- Damned Soul (Area: The Vice)
(@CGUID+74, 7370, 0, 1, 1, -11219.5, -2249.678, 22.70681, 3.130857, 120, 0, 0), -- Restless Shade (Area: The Vice)
(@CGUID+75, 12377, 0, 1, 1, -11147.89, -2180.099, 22.70598, 5.068253, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+76, 7370, 0, 1, 1, -11167.31, -2204.875, 22.723, 0.2589826, 120, 0, 0), -- Restless Shade (Area: The Vice)
(@CGUID+77, 12377, 0, 1, 1, -11176.86, -2225.787, 22.73167, 5.612465, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+78, 7370, 0, 1, 1, -11175.77, -2201.269, 22.73979, 1.68254, 120, 0, 0), -- Restless Shade (Area: The Vice)
(@CGUID+79, 12378, 0, 1, 1, -11148.47, -2199.559, 22.71799, 1.073814, 120, 0, 0), -- Damned Soul (Area: The Vice)
(@CGUID+80, 12377, 0, 1, 1, -11175.15, -2250.751, 22.70705, 0.9404468, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+81, 7370, 0, 1, 1, -11191.86, -2226.874, 22.72908, 5.834827, 120, 0, 0), -- Restless Shade (Area: The Vice)
(@CGUID+82, 12379, 0, 1, 1, -11174.07, -2178.206, 22.74032, 0.2948173, 120, 0, 0), -- Unliving Caretaker (Area: The Vice)
(@CGUID+83, 12377, 0, 1, 1, -11191.97, -2194.057, 20.28182, 1.080769, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+84, 12377, 0, 1, 1, -11218.13, -2220.869, 22.73924, 1.145352, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+85, 12378, 0, 1, 1, -11243.39, -2222.004, 22.70713, 3.745733, 120, 0, 0), -- Damned Soul (Area: The Vice)
(@CGUID+86, 7370, 0, 1, 1, -11215.25, -2193.976, 22.73078, 1.479637, 120, 0, 0), -- Restless Shade (Area: The Vice)
(@CGUID+87, 12379, 0, 1, 1, -11243.86, -2197.172, 22.70129, 3.326696, 120, 0, 0), -- Unliving Caretaker (Area: The Vice)
(@CGUID+88, 12378, 0, 1, 1, -11211.26, -2175.588, 22.73472, 4.354125, 120, 0, 0), -- Damned Soul (Area: The Vice)
(@CGUID+89, 12377, 0, 1, 1, -11237.34, -2200.314, 22.7022, 6.213243, 120, 0, 0), -- Wailing Spectre (Area: The Vice)
(@CGUID+90, 12378, 0, 1, 1, -11217.16, -2173.257, 22.71326, 4.491487, 120, 0, 0), -- Damned Soul (Area: The Vice)
(@CGUID+91, 12379, 0, 1, 1, -11211.56, -2147.622, 22.70712, 3.207755, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+92, 12378, 0, 1, 1, -11238.31, -2171.327, 22.70729, 2.262226, 120, 0, 0), -- Damned Soul (Area: Karazhan)
(@CGUID+93, 12377, 0, 1, 1, -11168.6, -2154.643, 22.70679, 3.30434, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+94, 12377, 0, 1, 1, -11190.34, -2152.725, 22.69926, 1.619176, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+95, 7370, 0, 1, 1, -11202.32, -2099.971, 31.23894, 1.313295, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+96, 12378, 0, 1, 1, -11202, -2127.27, 26.97308, 1.361642, 120, 0, 0), -- Damned Soul (Area: Karazhan)
(@CGUID+97, 12378, 0, 1, 1, -11168.57, -2105.431, 31.23894, 5.686547, 120, 0, 0), -- Damned Soul (Area: Karazhan)
(@CGUID+98, 12380, 0, 1, 1, -11163.54, -2073.959, 48.21117, 4.90663, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+99, 12379, 0, 1, 1, -11167.9, -2079.205, 35.50479, 0.6745554, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+100, 7370, 0, 1, 1, -11173.08, -2131.643, 26.97308, 0.6002267, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+101, 12380, 0, 1, 1, -11197.23, -2099.525, 31.23894, 2.967332, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+102, 7371, 0, 1, 1, -11129.71, -2387.558, 107.7762, 1.070543, 120, 0, 0), -- Deadwind Mauler (Area: The Vice)
(@CGUID+103, 7372, 0, 1, 1, -11111.88, -2366.274, 112.1887, 1.989021, 120, 0, 0), -- Deadwind Warlock (Area: The Vice)
(@CGUID+104, 7372, 0, 1, 1, -11083.08, -2407.034, 112.1655, 0.5179946, 120, 0, 0), -- Deadwind Warlock (Area: The Vice)
(@CGUID+105, 7371, 0, 1, 1, -11095.18, -2378.604, 112.4252, 2.711926, 120, 0, 0), -- Deadwind Mauler (Area: The Vice)
(@CGUID+106, 51987, 0, 1, 1, -10855.48, -2277.084, 117.2563, 3.522018, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+107, 51987, 0, 1, 1, -10811.31, -2199.642, 117.3104, 1.75689, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+108, 51987, 0, 1, 1, -10872.27, -2139.397, 117.2564, 4.959772, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+109, 51987, 0, 1, 1, -10853.36, -2114.398, 121.4661, 5.801017, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+110, 51987, 0, 1, 1, -10883.63, -2117.868, 125.3863, 0, 120, 0, 0), -- Deadwind Widow (Area: The Vice) (possible waypoints or random movement)
(@CGUID+111, 51987, 0, 1, 1, -10799.33, -2170.405, 117.2147, 0.5112913, 120, 0, 0), -- Deadwind Widow (Area: The Vice) (possible waypoints or random movement)
(@CGUID+112, 51987, 0, 1, 1, -10810.92, -2129.108, 121.6512, 3.839724, 120, 0, 0), -- Deadwind Widow (Area: The Vice) (possible waypoints or random movement)
(@CGUID+113, 51983, 0, 1, 1, -10809.78, -2024.63, 153.9027, 2.932153, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+114, 51984, 0, 1, 1, -10810.35, -2023.595, 155.3702, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: The Vice)
(@CGUID+115, 51983, 0, 1, 1, -10797.86, -2030.405, 163.2353, 2.51902, 120, 0, 0), -- Deadwind Widow (Area: The Vice) (possible waypoints or random movement)
(@CGUID+116, 51984, 0, 1, 1, -10587.9, -2163.181, 125.9995, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+117, 51984, 0, 1, 1, -10595.59, -2163.181, 123.8875, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+118, 51983, 0, 1, 1, -10587.87, -2163.365, 118.3809, 0.8203048, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+119, 51983, 0, 1, 1, -10634.3, -2106.686, 122.2081, 0.9599311, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+120, 51983, 0, 1, 1, -10555.82, -2110.285, 127.797, 2.879793, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+121, 51984, 0, 1, 1, -10556.37, -2095.924, 127.2958, 1.37881, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+122, 51983, 0, 1, 1, -10624.91, -2096.608, 130.1015, 2.932153, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+123, 51984, 0, 1, 1, -10625.26, -2096.568, 135.0164, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+124, 51983, 0, 1, 1, -10556.34, -2095.899, 125.0656, 0.4886922, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+125, 51984, 0, 1, 1, -10634.34, -2106.503, 124.3656, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+126, 51984, 0, 1, 1, -10555.85, -2108.663, 135.293, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+127, 51983, 0, 1, 1, -10609.37, -2058.334, 140.699, 1.570796, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+128, 7376, 0, 1, 1, -10647.74, -2086.836, 106.4407, 5.720204, 120, 0, 0), -- Sky Shadow (Area: Sleeping Gorge)
(@CGUID+129, 51984, 0, 1, 1, -10576.42, -2160.667, 121.8314, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+130, 51983, 0, 1, 1, -10576.39, -2160.851, 118.308, 3.176499, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+131, 51983, 0, 1, 1, -10550.81, -2122.007, 123.6176, 2.129302, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+132, 51984, 0, 1, 1, -10550.85, -2122.031, 130.303, 1.37881, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+133, 51984, 0, 1, 1, -10522.3, -2082.175, 117.8029, 1.37881, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+134, 51984, 0, 1, 1, -10531.89, -2078.167, 117.5321, 1.37881, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: Sleeping Gorge)
(@CGUID+135, 51983, 0, 1, 1, -10531.86, -2078.142, 114.6403, 2.129302, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+136, 51983, 0, 1, 1, -10522.27, -2082.151, 110.1686, 3.769911, 120, 0, 0), -- Deadwind Widow (Area: Sleeping Gorge)
(@CGUID+137, 51984, 0, 1, 1, -10565.15, -2236.646, 127.4855, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+138, 51983, 0, 1, 1, -10576.98, -2236.828, 127.1936, 4.101524, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+139, 51984, 0, 1, 1, -10593.65, -2233.411, 131.3071, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+140, 51983, 0, 1, 1, -10593.62, -2233.595, 123.7477, 2.86234, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+141, 51984, 0, 1, 1, -10577.02, -2236.646, 133.1959, 0.8028514, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+142, 51984, 0, 1, 1, -10431.51, -1988.616, 141.8188, 1.37881, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+143, 51984, 0, 1, 1, -10445.66, -1991.813, 122.81, 1.256637, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+144, 51983, 0, 1, 1, -10445.66, -1991.8, 119.7718, 4.24115, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+145, 51983, 0, 1, 1, -10431.48, -1988.592, 140.2973, 3.769911, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+146, 51984, 0, 1, 1, -10409.7, -1993.531, 132.4373, 1.256637, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+147, 51984, 0, 1, 1, -10418.2, -1991.594, 137.132, 4.415683, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+148, 51983, 0, 1, 1, -10418.2, -1991.625, 135.8527, 0.5235988, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+149, 51983, 0, 1, 1, -10409.7, -1993.521, 129.9135, 4.24115, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+150, 51984, 0, 1, 1, -10435.48, -1834.997, 122.9402, 4.537856, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+151, 51984, 0, 1, 1, -10445.08, -1833.929, 123.7423, 1.658063, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+152, 51983, 0, 1, 1, -10411.46, -1834.896, 117.1319, 0, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+153, 51983, 0, 1, 1, -10445.06, -1833.901, 121.3773, 2.495821, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+154, 51983, 0, 1, 1, -10435.51, -1835.014, 119.163, 5.375614, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+155, 51984, 0, 1, 1, -10470.08, -1754.099, 112.5507, 1.658063, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+156, 51984, 0, 1, 1, -10443.46, -1745.691, 113.6526, 4.520403, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+157, 51984, 0, 1, 1, -10451.21, -1747.182, 120.1666, 1.658063, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+158, 51984, 0, 1, 1, -10460.7, -1751, 123.1282, 5.707227, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+159, 51983, 0, 1, 1, -10424.55, -1747.021, 126.2103, 0.3421696, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+160, 51983, 0, 1, 1, -10451.12, -1747.177, 116.458, 2.495821, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+161, 51983, 0, 1, 1, -10460.7, -1750.97, 119.5102, 5.707227, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+162, 51983, 0, 1, 1, -10443.49, -1745.533, 109.6665, 5.689773, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+163, 51983, 0, 1, 1, -10469.98, -1754.094, 108.8805, 2.495821, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+164, 51983, 0, 1, 1, -10509.34, -1746.705, 115.3389, 0.9599311, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+165, 51984, 0, 1, 1, -10508.84, -1745.757, 120.8959, 0.7330383, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+166, 51984, 0, 1, 1, -10468.97, -1694.2, 105.525, 0.6981317, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+167, 51984, 0, 1, 1, -10451.29, -1689.856, 98.30666, 2.007129, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+168, 51984, 0, 1, 1, -10459.01, -1693.747, 103.6555, 0.6981317, 120, 0, 0), -- Deadwind Widow Invisible Stalker (Area: 0)
(@CGUID+169, 51983, 0, 1, 1, -10469.17, -1693.639, 103.5358, 5.986479, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+170, 51983, 0, 1, 1, -10458.98, -1693.26, 97.86857, 1.53589, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+171, 51983, 0, 1, 1, -10451.29, -1689.826, 95.98993, 5.044002, 120, 0, 0), -- Deadwind Widow (Area: 0)
(@CGUID+172, 51983, 0, 1, 1, -10318.81, -1923.561, 117.7149, 0.9929801, 120, 0, 0), -- Deadwind Widow (Area: 0) (possible waypoints or random movement)
(@CGUID+173, 7376, 0, 1, 1, -10297.41, -2015.105, 51.22813, 5.2382, 120, 0, 0), -- Sky Shadow (Area: 0)
(@CGUID+174, 51983, 0, 1, 1, -10279.37, -2027.24, 131.3739, 0.9675337, 120, 0, 0), -- Deadwind Widow (Area: 0) (possible waypoints or random movement)
(@CGUID+175, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Deadwind Ravine)
(@CGUID+176, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Deadwind Ravine)
(@CGUID+177, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Deadwind Ravine)
(@CGUID+178, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: Deadwind Ravine)
(@CGUID+179, 12377, 0, 1, 1, -11070.88, -1978.618, -23.61323, 4.507004, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+180, 7370, 0, 1, 1, -11060.18, -1971.028, -24.31667, 2.908457, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+181, 12379, 0, 1, 1, -11036.66, -1919.999, -29.6922, 3.570958, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+182, 7370, 0, 1, 1, -11062.1, -1930.61, -5.890127, 0.5079729, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+183, 12377, 0, 1, 1, -11039.28, -1925.251, -4.826036, 0.4049629, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+184, 18253, 0, 1, 1, -11116.54, -2014.393, 47.16093, 2.86234, 120, 0, 0), -- Archmage Leryda (Area: Karazhan)
(@CGUID+185, 12380, 0, 1, 1, -11113.85, -2058.257, 46.48965, 3.967499, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+186, 12380, 0, 1, 1, -11115.9, -2080.612, 48.29555, 1.116775, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+187, 12380, 0, 1, 1, -11138.02, -2070.313, 46.77367, 0.4572684, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+188, 12379, 0, 1, 1, -11105.63, -2003.759, 13.19544, 3.093096, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+189, 12379, 0, 1, 1, -11099.63, -1952.914, 1.341808, 3.883672, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+190, 12378, 0, 1, 1, -11086.03, -1910.168, 4.17801, 2.17961, 120, 0, 0), -- Damned Soul (Area: Karazhan)
(@CGUID+191, 12379, 0, 1, 1, -11094.36, -1918.374, 3.984428, 5.900394, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+192, 12380, 0, 1, 1, -11098.75, -1958.651, 1.240991, 1.480163, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+193, 12380, 0, 1, 1, -11053.82, -1880.109, 50.77724, 4.448174, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+194, 12378, 0, 1, 1, -11035.22, -1908.676, -3.510551, 3.778478, 120, 0, 0), -- Damned Soul (Area: Karazhan)
(@CGUID+195, 12377, 0, 1, 1, -11031.6, -1867.8, -30.96659, 1.250105, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+196, 12377, 0, 1, 1, -11068.03, -1863.601, -26.98, 3.144048, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+197, 12378, 0, 1, 1, -11129.59, -1893.985, -12.47979, 2.278972, 120, 0, 0), -- Damned Soul (Area: Karazhan)
(@CGUID+198, 7370, 0, 1, 1, -11125.13, -1859.446, -11.23999, 3.960066, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+199, 12379, 0, 1, 1, -11074.51, -1864.453, -25.70583, 1.12924, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+200, 7370, 0, 1, 1, -10955.91, -1853.835, -17.75451, 3.142199, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+201, 12377, 0, 1, 1, -11017.24, -1837.797, -32.66328, 1.563004, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+202, 12379, 0, 1, 1, -11129.86, -1927.401, -13.16843, 4.995819, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+203, 18162, 0, 1, 1, -11162.21, -1904.72, -17.7047, 1.22173, 120, 0, 0), -- Underground Pond Credit Marker (Area: Karazhan)
(@CGUID+204, 12380, 0, 1, 1, -11151.22, -1880.445, 63.27288, 1.228768, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+205, 18162, 0, 1, 1, -11161.13, -1869.051, -18.24408, 0.2617994, 120, 0, 0), -- Underground Pond Credit Marker (Area: Morgan's Plot)
(@CGUID+206, 12380, 0, 1, 1, -11181.8, -1857.227, 73.86137, 3.411398, 120, 0, 0), -- Unliving Resident (Area: Morgan's Plot)
(@CGUID+207, 12380, 0, 1, 1, -11174.33, -1854.212, 73.86137, 3.471251, 120, 0, 0), -- Unliving Resident (Area: Morgan's Plot)
(@CGUID+208, 18162, 0, 1, 1, -11169.02, -1926.591, -17.67675, 4.747295, 120, 0, 0), -- Underground Pond Credit Marker (Area: Morgan's Plot)
(@CGUID+209, 12380, 0, 1, 1, -11167.45, -1965.342, 35.74852, 4.280645, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+210, 12380, 0, 1, 1, -11170.28, -1948.44, 57.32413, 6.001934, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+211, 12380, 0, 1, 1, -11220.36, -2011.196, 47.80703, 1.235318, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+212, 17613, 0, 1, 1, -11127.23, -2006.657, 47.60226, 4.45059, 120, 0, 0), -- Archmage Alturus (Area: Karazhan) (possible waypoints or random movement)
(@CGUID+213, 18255, 0, 1, 1, -11123.3, -2006.769, 47.27247, 4.468043, 120, 0, 0), -- Apprentice Darius (Area: Karazhan)
(@CGUID+214, 12380, 0, 1, 1, -11155.14, -2002.535, 35.73947, 0.4324527, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+215, 12380, 0, 1, 1, -11188.13, -2032.247, 47.12939, 5.699091, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+216, 12380, 0, 1, 1, -11161.35, -2007.236, 47.11598, 2.028223, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+217, 12380, 0, 1, 1, -11186.1, -2000.503, 35.73947, 3.986001, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+218, 12380, 0, 1, 1, -11181.91, -1967.674, 35.74852, 0.1178636, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+219, 12380, 0, 1, 1, -11151.99, -1969.411, 35.74852, 5.068385, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+220, 12377, 0, 1, 1, -11147.24, -1972.668, 22.90755, 3.515693, 120, 0, 0), -- Wailing Spectre (Area: Karazhan)
(@CGUID+221, 7370, 0, 1, 1, -11170.63, -1969.093, 22.81395, 2.584775, 120, 0, 0), -- Restless Shade (Area: Karazhan)
(@CGUID+222, 12380, 0, 1, 1, -11198.06, -2075.237, 35.50479, 4.374774, 120, 0, 0), -- Unliving Resident (Area: Karazhan)
(@CGUID+223, 51987, 0, 1, 1, -11147.62, -2273.712, 121.6314, 0.1743992, 120, 0, 0), -- Deadwind Widow (Area: Karazhan)
(@CGUID+224, 51987, 0, 1, 1, -11125.98, -2296.344, 117.2564, 5.996577, 120, 0, 0), -- Deadwind Widow (Area: Karazhan)
(@CGUID+225, 12379, 0, 1, 1, -11275.32, -2193.299, 22.70718, 5.961154, 120, 0, 0), -- Unliving Caretaker (Area: Karazhan)
(@CGUID+226, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+227, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+228, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+229, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+230, 32638, 0, 1, 1, -11120.56, -2012.008, 47.09197, 4.321871, 120, 0, 0), -- Hakmud of Argus (Area: The Master's Cellar) (possible waypoints or random movement)
(@CGUID+231, 32639, 0, 1, 1, -11120.56, -2012.008, 47.09197, 4.321871, 120, 0, 0), -- Gnimo (Area: The Master's Cellar) (possible waypoints or random movement)
(@CGUID+232, 12378, 0, 1, 1, -11309.22, -2186.775, 22.70722, 1.378307, 120, 0, 0), -- Damned Soul (Area: The Master's Cellar)
(@CGUID+233, 7370, 0, 1, 1, -11322.94, -2185.416, 22.70722, 0.9131182, 120, 0, 0), -- Restless Shade (Area: The Master's Cellar)
(@CGUID+234, 12377, 0, 1, 1, -11349.61, -2189.905, 22.70722, 2.528725, 120, 0, 0), -- Wailing Spectre (Area: The Master's Cellar)
(@CGUID+235, 12380, 0, 1, 1, -11357.61, -2186.246, 22.90536, 6.194345, 120, 0, 0), -- Unliving Resident (Area: The Master's Cellar)
(@CGUID+236, 18161, 0, 1, 1, -11370.62, -2165.587, 22.31588, 1.343904, 120, 0, 0), -- Underground Well Credit Marker (Area: The Master's Cellar)
(@CGUID+237, 7370, 0, 1, 1, -11394.15, -2200.703, 23.10025, 2.611075, 120, 0, 0), -- Restless Shade (Area: The Master's Cellar)
(@CGUID+238, 12377, 0, 1, 1, -11384.28, -2162.753, 23.13158, 0.603655, 120, 0, 0), -- Wailing Spectre (Area: The Master's Cellar)
(@CGUID+239, 12379, 0, 1, 1, -11385.13, -2182.71, 23.07271, 4.098912, 120, 0, 0), -- Unliving Caretaker (Area: The Master's Cellar)
(@CGUID+240, 12378, 0, 1, 1, -11374.02, -2203.752, 22.92156, 4.495811, 120, 0, 0), -- Damned Soul (Area: The Master's Cellar)
(@CGUID+241, 7370, 0, 1, 1, -11370.2, -2169.093, 22.43494, 1.393352, 120, 0, 0), -- Restless Shade (Area: The Master's Cellar)
(@CGUID+242, 32520, 0, 1, 1, -5691.65, 5556.92, -1154.687, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+243, 32520, 0, 1, 1, -6148.39, 5539.97, -1207.787, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+244, 32520, 0, 1, 1, -6014.71, 5479.63, -1208.007, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+245, 32520, 0, 1, 1, -6305.162, 5582.533, -1172.063, 0, 120, 0, 0), -- Totally Generic Bunny (All Phase) (Area: The Master's Cellar)
(@CGUID+246, 7371, 0, 1, 1, -11152.32, -2403.073, 107.5037, 2.824408, 120, 0, 0), -- Deadwind Mauler (Area: The Vice)
(@CGUID+247, 7371, 0, 1, 1, -11122.35, -2415.991, 108.4813, 4.746519, 120, 0, 0), -- Deadwind Mauler (Area: The Vice)
(@CGUID+248, 7372, 0, 1, 1, -11105.28, -2417.209, 110.8368, 0.4379298, 120, 0, 0), -- Deadwind Warlock (Area: The Vice)
(@CGUID+249, 51987, 0, 1, 1, -11147.56, -2273.906, 121.6314, 0.2147139, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+250, 51987, 0, 1, 1, -11081.39, -2325.333, 117.4579, 2.330542, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+251, 7372, 0, 1, 1, -11104.2, -2466.368, 109.7494, 4.926589, 120, 0, 0), -- Deadwind Warlock (Area: Grosh'gok Compound)
(@CGUID+252, 7372, 0, 1, 1, -11161.85, -2488.719, 105.3946, 4.831919, 120, 0, 0), -- Deadwind Warlock (Area: Grosh'gok Compound)
(@CGUID+253, 7371, 0, 1, 1, -10895, -2346.389, 116.6386, 5.67689, 120, 0, 0), -- Deadwind Mauler (Area: The Vice)
(@CGUID+254, 51987, 0, 1, 1, -10855.48, -2277.084, 117.2563, 3.522018, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+255, 51987, 0, 1, 1, -10810.42, -2200, 117.2563, 1.672929, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+256, 51987, 0, 1, 1, -10918.58, -2210.633, 117.9034, 5.139521, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+257, 7369, 0, 1, 1, -10871.13, -2144.697, 117.2564, 5.097537, 120, 0, 0), -- Deadwind Brute (Area: The Vice)
(@CGUID+258, 51987, 0, 1, 1, -10827.84, -2143.192, 122.1043, 3.964947, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+259, 51987, 0, 1, 1, -10871.69, -2139.703, 117.2564, 4.824372, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+260, 51987, 0, 1, 1, -10851.54, -2115.449, 121.3514, 5.851059, 120, 0, 0), -- Deadwind Widow (Area: The Vice)
(@CGUID+261, 51983, 0, 1, 1, -10435.51, -1835.014, 119.163, 5.375614, 120, 0, 0); -- Deadwind Widow (Area: Deadwind Ravine)


DELETE FROM `npc_vendor` WHERE (`entry`=18255 AND `item`=33205) OR (`entry`=18255 AND `item`=29187) OR (`entry`=18255 AND `item`=33209) OR (`entry`=18255 AND `item`=31401) OR (`entry`=18255 AND `item`=33165) OR (`entry`=18255 AND `item`=33124);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`) VALUES
-- 18255 (Apprentice Darius)
(18255, 33205, 1, 0, 0), -- Pattern: Shadowprowler's Chestguard
(18255, 29187, 2, 0, 0), -- Inscription of Endurance
(18255, 33209, 3, 0, 0), -- Recipe: Flask of Chromatic Wonder
(18255, 31401, 4, 0, 0), -- Design: The Frozen Eye
(18255, 33165, 5, 0, 0), -- Formula: Enchant Weapon - Greater Agility
(18255, 33124, 6, 0, 0); -- Pattern: Cloak of Darkness


DELETE FROM `npc_text` WHERE `ID` IN (9242, 10884);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(9242, 'Karazhan is more than a mere building, $N.  If you traced the ley-lines traversing Azeroth you would find that they all converge right about there.$B$B<Alturus points at an invisible spot below the tower.>$B$BFascinating, isn''t it?', '', 0, 1, 0, 0, 0, 0, 0, 0, 'Archmage Alvareux once wrote a treatise exploring a fascinating theory.  He proposed the existence of an exact copy of Karazhan in a world other than our own and that both somehow shared the same space.$B$BHe went mad soon after.  A real pity.', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 9242
(10884, '', 'I have a proposal for you, $r.  Please consider your choices carefully - your decision cannot be easily reversed.$B$BIt is time we formalized your allegiance to our organization.  I must know in what capacity you wish to serve us so that we may reward you appropriately.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 10884
