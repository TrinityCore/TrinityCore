SET @GUID := 152021 ; -- Set GUID

SET @BG_Zar := 32832;
SET @Moonstrike := 32834;
SET @ZomBocom := 31865;
SET @Xazi := 31864;
SET @Nargle := 31863;
SET @Krezzik := 32405;
SET @Argex := 32407;
SET @Thunderhorn := 32383;
SET @Doris := 32385;
SET @Tristia := 32380;
SET @Dirgehammer := 32381;

DELETE FROM `creature` WHERE `id` IN (@BG_Zar,@Moonstrike,@ZomBocom,@Xazi,@Nargle,@Kezzik,@Argex,@Thunderhorn,@Doris,@Tristia,@Dirgehammer);
INSERT INTO creature
(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES
(@GUID,@Nargle,571,1,1,26463,0,5753.74,585.413,615.052,0,180,0,0,1,0,0,0,0,0,0), -- Nargle Lashcord
(@GUID+1,@Argex,1,1,1,27953,0,-7123.33,-3766.68,9.40339,0,180,0,0,1,0,0,0,0,0,0), -- Argex Irongut
(@GUID+2,@Krezzik,530,1,1,0,0,3066.45,3638.87,145.218,0.875901,120,0,0,1,0,0,0,0,0,0), -- Krezzik the Striker
(@GUID+3,@Xazi,571,1,1,26464,0,5751.54,584.66,615.052,0,180,0,0,1,0,0,0,0,0,0), -- Xazi Smolderpipe
(@GUID+4,@ZomBocom,571,1,1,26465,0,5751.73,582.943,615.052,0,180,0,0,1,0,0,0,0,0,0), -- Zom Bocom
(@GUID+5,@Doris,1,1,1,0,0,1673.07,-4201.89,56.3826,3.62927,25,0,0,55888,0,0,0,0,0,0), -- Doris
(@GUID+6,@BG_Zar,1,1,1,0,0,1670.17,-4199.26,56.3827,3.98664,25,0,0,11828,0,0,0,0,0,0), -- BG_Zar
(@GUID+7,@Thunderhorn,1,1,1,0,0,1669.09,-4196.78,56.3827,4.10416,25,0,0,11828,0,0,0,0,0,0), -- Thunderhorn
(@GUID+8,@Moonstrike,0,1,1,28301,0,-8775.85,423.96,105.233,5.73298,180,0,0,11828,0,0,0,0,0,0), -- Moonstrike
(@GUID+9,@Tristia,0,1,1,21512,0,-8773.78,425.804,105.233,4.80621,180,0,0,11828,0,0,0,0,0,0), -- Tristia
(@GUID+10,@Dirgehammer,0,1,1,12917,0,-8781.18,419.883,105.233,6.18459,180,0,0,7048,0,0,0,0,0,0); -- Dirgehammer

DELETE FROM `game_event_creature` WHERE `eventEntry`=57;
INSERT INTO `game_event_creature` (`guid`,`eventEntry`) VALUES
(@GUID,57), -- Nargle Lashcord (31863)
(@GUID+1,57), -- Argex Irongut (32407)
(@GUID+2,57), -- Krezzik the Striker (32405)
(@GUID+3,57), -- Xazi Smolderpipe (31864)
(@GUID+4,57), -- Zom Bocom (31865)
(@GUID+5,57), -- Doris Volanthius (32385)
(@GUID+6,57), -- Blood Guard Zar'shi (32832)
(@GUID+7,57), -- Sergeant Thunderhorn (32383)
(@GUID+8,57), -- Knight Lieutenant Moonstrike (32834)
(@GUID+9,57), -- Lieutenant Tristia (32380)
(@GUID+10,57); -- Captain Dirgehammer (32381)
-- ----------------------
-- -- Vendor Templates --
-- ---------------------- 
SET @31600HP := 2560;
SET @38000HP := 2561;
SET @1660RT_39400HP := 2564;
SET @1750RT_47400HP := 2565;
SET @1600RT_47400HP := 2566;
SET @1690RT_47400HP := 2567;
SET @49600HP := 2559;
SET @50000HP := 2570;
SET @60000HP := 2569;
SET @1800RT_62000HP := 2568;
SET @1720RT_62000HP := 2563;
SET @1630RT_62000HP := 2562;
SET @7200HP_200AP := 2443;
SET @9600HP_275AP := 2445;
SET @12000HP_350AP := 2440;
SET @1615RT_7200HP_400AP := 2452;
SET @1775RT_9600HP_550AP := 2459;
SET @1645RT_12000HP_700AP := 2454;
SET @1735RT_12000HP_700AP := 2453;
SET @1675RT_12000HP_700AP := 2451;
SET @1930RT_2250AP := 2469;
SET @1930RT_1200AP := 2468;
SET @1930RT_4500AP := 2460;
SET @1930RT_3150AP := 2466;
SET @1930RT_1350AP := 2467;
SET @1750RT_1350AP := 2463;
SET @2050RT_1750AP := 2470;
SET @1810RT_2250AP := 2465;
SET @1870RT_2250AP := 2462;
SET @1990RT_2250AP := 2464;

-- Vendor Defines:
SET @BG_Zar := 32832; -- (34061/34062/34063) as s6/s7/s8?
SET @Moonstrike := 32834; -- (34082/34083/34084) as s6/s7/s8?
SET @ZomBocom := 31865; -- (or 29541 or 40205)
SET @Xazi := 31864; -- (or 29540 or 40210)
SET @Nargle := 31863; -- (or 29539 or 40211)
SET @Kezzik := 32405; -- (or 32356 or 40207)
SET @Argex := 32407; -- (or 32359 or 40215)
SET @Thunderhorn := 32383; -- (most likely) (34036/34037/34038) as s6/s7/s8?
SET @Doris := 32385; -- (most likely) (34058/34059/34060) as s6/s7/s8?
SET @Tristia := 32380; -- (most likely) (34076,34077,34078) as s6/s7/s8?

DELETE FROM `npc_vendor` WHERE `entry` IN (@BG_Zar,@Moonstrike,@ZomBocom,@Xazi,@Nargle,@Kezzik,@Argex,@Thunderhorn,@Doris,@Tristia);
INSERT INTO `npc_vendor` 
(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`)
VALUES 
-- Spacer
(@BG_Zar,0,40779,0,0,@60000HP), -- Savage Gladiator Chest DK
(@BG_Zar,0,40799,0,0,@50000HP), -- Savage Gladiator Gloves DK
(@BG_Zar,0,40817,0,0,@60000HP), -- Savage Gladiator Helm DK
(@BG_Zar,0,40837,0,0,@60000HP), -- Savage Gladiator Legs DK
(@BG_Zar,0,40857,0,0,@50000HP), -- Savage Gladiator Shoulders DK
(@BG_Zar,0,41272,0,0,@60000HP), -- Savage Gladiator Chest Druid1
(@BG_Zar,0,41268,0,0,@50000HP), -- Savage Gladiator Gloves Druid1
(@BG_Zar,0,41269,0,0,@60000HP), -- Savage Gladiator Helm Druid1
(@BG_Zar,0,41270,0,0,@60000HP), -- Savage Gladiator Legs Druid1
(@BG_Zar,0,41271,0,0,@50000HP), -- Savage Gladiator Shoulders Druid1
(@BG_Zar,0,41658,0,0,@60000HP), -- Savage Gladiator Chest Druid2
(@BG_Zar,0,41770,0,0,@50000HP), -- Savage Gladiator Gloves Druid2
(@BG_Zar,0,41675,0,0,@60000HP), -- Savage Gladiator Helm Druid2
(@BG_Zar,0,41664,0,0,@60000HP), -- Savage Gladiator Legs Druid2
(@BG_Zar,0,41712,0,0,@50000HP), -- Savage Gladiator Shoulders Druid2
(@BG_Zar,0,41313,0,0,@60000HP), -- Savage Gladiator Chest Druid3
(@BG_Zar,0,41290,0,0,@50000HP), -- Savage Gladiator Gloves Druid3
(@BG_Zar,0,41324,0,0,@60000HP), -- Savage Gladiator Helm Druid3
(@BG_Zar,0,41301,0,0,@60000HP), -- Savage Gladiator Legs Druid3
(@BG_Zar,0,41278,0,0,@50000HP), -- Savage Gladiator Shoulders Druid3
(@BG_Zar,0,41084,0,0,@60000HP), -- Savage Gladiator Chest Hunter
(@BG_Zar,0,41140,0,0,@50000HP), -- Savage Gladiator Gloves Hunter
(@BG_Zar,0,41154,0,0,@60000HP), -- Savage Gladiator Helm Hunter
(@BG_Zar,0,41202,0,0,@60000HP), -- Savage Gladiator Legs Hunter
(@BG_Zar,0,41214,0,0,@50000HP), -- Savage Gladiator Shoulders Hunter
(@BG_Zar,0,41949,0,0,@60000HP), -- Savage Gladiator Chest Mage
(@BG_Zar,0,41968,0,0,@50000HP), -- Savage Gladiator Gloves Mage
(@BG_Zar,0,41943,0,0,@60000HP), -- Savage Gladiator Helm Mage
(@BG_Zar,0,41956,0,0,@60000HP), -- Savage Gladiator Legs Mage
(@BG_Zar,0,41962,0,0,@50000HP), -- Savage Gladiator Shoulders Mage
(@BG_Zar,0,40898,0,0,@60000HP), -- Savage Gladiator Chest Paladin1
(@BG_Zar,0,40918,0,0,@50000HP), -- Savage Gladiator Gloves Paladin1
(@BG_Zar,0,40930,0,0,@60000HP), -- Savage Gladiator Helm Paladin1
(@BG_Zar,0,40936,0,0,@60000HP), -- Savage Gladiator Legs Paladin1
(@BG_Zar,0,40960,0,0,@50000HP), -- Savage Gladiator Shoulders Paladin1
(@BG_Zar,0,40780,0,0,@60000HP), -- Savage Gladiator Chest Paladin2
(@BG_Zar,0,40798,0,0,@50000HP), -- Savage Gladiator Gloves Paladin2
(@BG_Zar,0,40818,0,0,@60000HP), -- Savage Gladiator Helm Paladin2
(@BG_Zar,0,40838,0,0,@60000HP), -- Savage Gladiator Legs Paladin2
(@BG_Zar,0,40858,0,0,@50000HP), -- Savage Gladiator Shoulders Paladin2
(@BG_Zar,0,41851,0,0,@60000HP), -- Savage Gladiator Chest Priest1
(@BG_Zar,0,41847,0,0,@50000HP), -- Savage Gladiator Gloves Priest1
(@BG_Zar,0,41848,0,0,@60000HP), -- Savage Gladiator Helm Priest1
(@BG_Zar,0,41849,0,0,@60000HP), -- Savage Gladiator Legs Priest1
(@BG_Zar,0,41850,0,0,@50000HP), -- Savage Gladiator Shoulders Priest1
(@BG_Zar,0,41918,0,0,@60000HP), -- Savage Gladiator Chest Priest2
(@BG_Zar,0,41937,0,0,@50000HP), -- Savage Gladiator Gloves Priest2
(@BG_Zar,0,41912,0,0,@60000HP), -- Savage Gladiator Helm Priest2
(@BG_Zar,0,41924,0,0,@60000HP), -- Savage Gladiator Legs Priest2
(@BG_Zar,0,41930,0,0,@50000HP), -- Savage Gladiator Shoulders Priest2
(@BG_Zar,0,41647,0,0,@60000HP), -- Savage Gladiator Chest Rogue
(@BG_Zar,0,41643,0,0,@50000HP), -- Savage Gladiator Gloves Rogue
(@BG_Zar,0,41644,0,0,@60000HP), -- Savage Gladiator Helm Rogue
(@BG_Zar,0,41645,0,0,@60000HP), -- Savage Gladiator Legs Rogue
(@BG_Zar,0,41646,0,0,@50000HP), -- Savage Gladiator Shoulders Rogue
(@BG_Zar,0,41078,0,0,@60000HP), -- Savage Gladiator Chest Shaman1
(@BG_Zar,0,41134,0,0,@50000HP), -- Savage Gladiator Gloves Shaman1
(@BG_Zar,0,41148,0,0,@60000HP), -- Savage Gladiator Helm Shaman1
(@BG_Zar,0,41160,0,0,@60000HP), -- Savage Gladiator Legs Shaman1
(@BG_Zar,0,41208,0,0,@50000HP), -- Savage Gladiator Shoulders Shaman1
(@BG_Zar,0,40987,0,0,@60000HP), -- Savage Gladiator Chest Shaman2
(@BG_Zar,0,41004,0,0,@50000HP), -- Savage Gladiator Gloves Shaman2
(@BG_Zar,0,41016,0,0,@60000HP), -- Savage Gladiator Helm Shaman2
(@BG_Zar,0,41030,0,0,@60000HP), -- Savage Gladiator Legs Shaman2
(@BG_Zar,0,41041,0,0,@50000HP), -- Savage Gladiator Shoulders Shaman2
(@BG_Zar,0,40986,0,0,@60000HP), -- Savage Gladiator Chest Shaman3
(@BG_Zar,0,40998,0,0,@50000HP), -- Savage Gladiator Gloves Shaman3
(@BG_Zar,0,41010,0,0,@60000HP), -- Savage Gladiator Helm Shaman3
(@BG_Zar,0,41023,0,0,@60000HP), -- Savage Gladiator Legs Shaman3
(@BG_Zar,0,41024,0,0,@50000HP), -- Savage Gladiator Shoulders Shaman3
(@BG_Zar,0,41996,0,0,@60000HP), -- Savage Gladiator Chest Warlock
(@BG_Zar,0,42014,0,0,@50000HP), -- Savage Gladiator Gloves Warlock
(@BG_Zar,0,41990,0,0,@60000HP), -- Savage Gladiator Helm Warlock
(@BG_Zar,0,42002,0,0,@60000HP), -- Savage Gladiator Legs Warlock
(@BG_Zar,0,42008,0,0,@50000HP), -- Savage Gladiator Shoulders Warlock
(@BG_Zar,0,40778,0,0,@60000HP), -- Savage Gladiator Chest Warrior
(@BG_Zar,0,40797,0,0,@50000HP), -- Savage Gladiator Gloves Warrior
(@BG_Zar,0,40816,0,0,@60000HP), -- Savage Gladiator Helm Warrior
(@BG_Zar,0,40836,0,0,@60000HP), -- Savage Gladiator Legs Warrior
(@BG_Zar,0,40856,0,0,@50000HP), -- Savage Gladiator Shoulders Warrior
-- Spacer
(@Moonstrike,0,40779,0,0,@60000HP), -- Savage Gladiator Chest DK
(@Moonstrike,0,40799,0,0,@50000HP), -- Savage Gladiator Gloves DK
(@Moonstrike,0,40817,0,0,@60000HP), -- Savage Gladiator Helm DK
(@Moonstrike,0,40837,0,0,@60000HP), -- Savage Gladiator Legs DK
(@Moonstrike,0,40857,0,0,@50000HP), -- Savage Gladiator Shoulders DK
(@Moonstrike,0,41272,0,0,@60000HP), -- Savage Gladiator Chest Druid1
(@Moonstrike,0,41268,0,0,@50000HP), -- Savage Gladiator Gloves Druid1
(@Moonstrike,0,41269,0,0,@60000HP), -- Savage Gladiator Helm Druid1
(@Moonstrike,0,41270,0,0,@60000HP), -- Savage Gladiator Legs Druid1
(@Moonstrike,0,41271,0,0,@50000HP), -- Savage Gladiator Shoulders Druid1
(@Moonstrike,0,41658,0,0,@60000HP), -- Savage Gladiator Chest Druid2
(@Moonstrike,0,41770,0,0,@50000HP), -- Savage Gladiator Gloves Druid2
(@Moonstrike,0,41675,0,0,@60000HP), -- Savage Gladiator Helm Druid2
(@Moonstrike,0,41664,0,0,@60000HP), -- Savage Gladiator Legs Druid2
(@Moonstrike,0,41712,0,0,@50000HP), -- Savage Gladiator Shoulders Druid2
(@Moonstrike,0,41313,0,0,@60000HP), -- Savage Gladiator Chest Druid3
(@Moonstrike,0,41290,0,0,@50000HP), -- Savage Gladiator Gloves Druid3
(@Moonstrike,0,41324,0,0,@60000HP), -- Savage Gladiator Helm Druid3
(@Moonstrike,0,41301,0,0,@60000HP), -- Savage Gladiator Legs Druid3
(@Moonstrike,0,41278,0,0,@50000HP), -- Savage Gladiator Shoulders Druid3
(@Moonstrike,0,41084,0,0,@60000HP), -- Savage Gladiator Chest Hunter
(@Moonstrike,0,41140,0,0,@50000HP), -- Savage Gladiator Gloves Hunter
(@Moonstrike,0,41154,0,0,@60000HP), -- Savage Gladiator Helm Hunter
(@Moonstrike,0,41202,0,0,@60000HP), -- Savage Gladiator Legs Hunter
(@Moonstrike,0,41214,0,0,@50000HP), -- Savage Gladiator Shoulders Hunter
(@Moonstrike,0,41949,0,0,@60000HP), -- Savage Gladiator Chest Mage
(@Moonstrike,0,41968,0,0,@50000HP), -- Savage Gladiator Gloves Mage
(@Moonstrike,0,41943,0,0,@60000HP), -- Savage Gladiator Helm Mage
(@Moonstrike,0,41956,0,0,@60000HP), -- Savage Gladiator Legs Mage
(@Moonstrike,0,41962,0,0,@50000HP), -- Savage Gladiator Shoulders Mage
(@Moonstrike,0,40898,0,0,@60000HP), -- Savage Gladiator Chest Paladin1
(@Moonstrike,0,40918,0,0,@50000HP), -- Savage Gladiator Gloves Paladin1
(@Moonstrike,0,40930,0,0,@60000HP), -- Savage Gladiator Helm Paladin1
(@Moonstrike,0,40936,0,0,@60000HP), -- Savage Gladiator Legs Paladin1
(@Moonstrike,0,40960,0,0,@50000HP), -- Savage Gladiator Shoulders Paladin1
(@Moonstrike,0,40780,0,0,@60000HP), -- Savage Gladiator Chest Paladin2
(@Moonstrike,0,40798,0,0,@50000HP), -- Savage Gladiator Gloves Paladin2
(@Moonstrike,0,40818,0,0,@60000HP), -- Savage Gladiator Helm Paladin2
(@Moonstrike,0,40838,0,0,@60000HP), -- Savage Gladiator Legs Paladin2
(@Moonstrike,0,40858,0,0,@50000HP), -- Savage Gladiator Shoulders Paladin2
(@Moonstrike,0,41851,0,0,@60000HP), -- Savage Gladiator Chest Priest1
(@Moonstrike,0,41847,0,0,@50000HP), -- Savage Gladiator Gloves Priest1
(@Moonstrike,0,41848,0,0,@60000HP), -- Savage Gladiator Helm Priest1
(@Moonstrike,0,41849,0,0,@60000HP), -- Savage Gladiator Legs Priest1
(@Moonstrike,0,41850,0,0,@50000HP), -- Savage Gladiator Shoulders Priest1
(@Moonstrike,0,41918,0,0,@60000HP), -- Savage Gladiator Chest Priest2
(@Moonstrike,0,41937,0,0,@50000HP), -- Savage Gladiator Gloves Priest2
(@Moonstrike,0,41912,0,0,@60000HP), -- Savage Gladiator Helm Priest2
(@Moonstrike,0,41924,0,0,@60000HP), -- Savage Gladiator Legs Priest2
(@Moonstrike,0,41930,0,0,@50000HP), -- Savage Gladiator Shoulders Priest2
(@Moonstrike,0,41647,0,0,@60000HP), -- Savage Gladiator Chest Rogue
(@Moonstrike,0,41643,0,0,@50000HP), -- Savage Gladiator Gloves Rogue
(@Moonstrike,0,41644,0,0,@60000HP), -- Savage Gladiator Helm Rogue
(@Moonstrike,0,41645,0,0,@60000HP), -- Savage Gladiator Legs Rogue
(@Moonstrike,0,41646,0,0,@50000HP), -- Savage Gladiator Shoulders Rogue
(@Moonstrike,0,41078,0,0,@60000HP), -- Savage Gladiator Chest Shaman1
(@Moonstrike,0,41134,0,0,@50000HP), -- Savage Gladiator Gloves Shaman1
(@Moonstrike,0,41148,0,0,@60000HP), -- Savage Gladiator Helm Shaman1
(@Moonstrike,0,41160,0,0,@60000HP), -- Savage Gladiator Legs Shaman1
(@Moonstrike,0,41208,0,0,@50000HP), -- Savage Gladiator Shoulders Shaman1
(@Moonstrike,0,40987,0,0,@60000HP), -- Savage Gladiator Chest Shaman2
(@Moonstrike,0,41004,0,0,@50000HP), -- Savage Gladiator Gloves Shaman2
(@Moonstrike,0,41016,0,0,@60000HP), -- Savage Gladiator Helm Shaman2
(@Moonstrike,0,41030,0,0,@60000HP), -- Savage Gladiator Legs Shaman2
(@Moonstrike,0,41041,0,0,@50000HP), -- Savage Gladiator Shoulders Shaman2
(@Moonstrike,0,40986,0,0,@60000HP), -- Savage Gladiator Chest Shaman3
(@Moonstrike,0,40998,0,0,@50000HP), -- Savage Gladiator Gloves Shaman3
(@Moonstrike,0,41010,0,0,@60000HP), -- Savage Gladiator Helm Shaman3
(@Moonstrike,0,41023,0,0,@60000HP), -- Savage Gladiator Legs Shaman3
(@Moonstrike,0,41024,0,0,@50000HP), -- Savage Gladiator Shoulders Shaman3
(@Moonstrike,0,41996,0,0,@60000HP), -- Savage Gladiator Chest Warlock
(@Moonstrike,0,42014,0,0,@50000HP), -- Savage Gladiator Gloves Warlock
(@Moonstrike,0,41990,0,0,@60000HP), -- Savage Gladiator Helm Warlock
(@Moonstrike,0,42002,0,0,@60000HP), -- Savage Gladiator Legs Warlock
(@Moonstrike,0,42008,0,0,@50000HP), -- Savage Gladiator Shoulders Warlock
(@Moonstrike,0,40778,0,0,@60000HP), -- Savage Gladiator Chest Warrior
(@Moonstrike,0,40797,0,0,@50000HP), -- Savage Gladiator Gloves Warrior
(@Moonstrike,0,40816,0,0,@60000HP), -- Savage Gladiator Helm Warrior
(@Moonstrike,0,40836,0,0,@60000HP), -- Savage Gladiator Legs Warrior
(@Moonstrike,0,40856,0,0,@50000HP), -- Savage Gladiator Shoulders Warrior
-- Double Spacer
-- Double Spacer
(@ZomBocom,0,40779,0,0,@12000HP_350AP), -- Savage Gladiator Chest DK
(@ZomBocom,0,40799,0,0,@7200HP_200AP), -- Savage Gladiator Gloves DK
(@ZomBocom,0,40817,0,0,@12000HP_350AP), -- Savage Gladiator Helm DK
(@ZomBocom,0,40837,0,0,@12000HP_350AP), -- Savage Gladiator Legs DK
(@ZomBocom,0,40857,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders DK
(@ZomBocom,0,41272,0,0,@12000HP_350AP), -- Savage Gladiator Chest Druid1
(@ZomBocom,0,41268,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Druid1
(@ZomBocom,0,41269,0,0,@12000HP_350AP), -- Savage Gladiator Helm Druid1
(@ZomBocom,0,41270,0,0,@12000HP_350AP), -- Savage Gladiator Legs Druid1
(@ZomBocom,0,41271,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Druid1
(@ZomBocom,0,41658,0,0,@12000HP_350AP), -- Savage Gladiator Chest Druid2
(@ZomBocom,0,41770,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Druid2
(@ZomBocom,0,41675,0,0,@12000HP_350AP), -- Savage Gladiator Helm Druid2
(@ZomBocom,0,41664,0,0,@12000HP_350AP), -- Savage Gladiator Legs Druid2
(@ZomBocom,0,41712,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Druid2
(@ZomBocom,0,41313,0,0,@12000HP_350AP), -- Savage Gladiator Chest Druid3
(@ZomBocom,0,41290,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Druid3
(@ZomBocom,0,41324,0,0,@12000HP_350AP), -- Savage Gladiator Helm Druid3
(@ZomBocom,0,41301,0,0,@12000HP_350AP), -- Savage Gladiator Legs Druid3
(@ZomBocom,0,41278,0,0,@9600HP_200AP), -- Savage Gladiator Shoulders Druid3
(@ZomBocom,0,41084,0,0,@12000HP_350AP), -- Savage Gladiator Chest Hunter
(@ZomBocom,0,41140,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Hunter
(@ZomBocom,0,41154,0,0,@12000HP_350AP), -- Savage Gladiator Helm Hunter
(@ZomBocom,0,41202,0,0,@12000HP_350AP), -- Savage Gladiator Legs Hunter
(@ZomBocom,0,41214,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Hunter
(@ZomBocom,0,41949,0,0,@12000HP_350AP), -- Savage Gladiator Chest Mage
(@ZomBocom,0,41968,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Mage
(@ZomBocom,0,41943,0,0,@12000HP_350AP), -- Savage Gladiator Helm Mage
(@ZomBocom,0,41956,0,0,@12000HP_350AP), -- Savage Gladiator Legs Mage
(@ZomBocom,0,41962,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Mage
(@ZomBocom,0,40898,0,0,@12000HP_350AP), -- Savage Gladiator Chest Paladin1
(@ZomBocom,0,40918,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Paladin1
(@ZomBocom,0,40930,0,0,@12000HP_350AP), -- Savage Gladiator Helm Paladin1
(@ZomBocom,0,40936,0,0,@12000HP_350AP), -- Savage Gladiator Legs Paladin1
(@ZomBocom,0,40960,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Paladin1
(@ZomBocom,0,40780,0,0,@12000HP_350AP), -- Savage Gladiator Chest Paladin2
(@ZomBocom,0,40798,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Paladin2
(@ZomBocom,0,40818,0,0,@12000HP_350AP), -- Savage Gladiator Helm Paladin2
(@ZomBocom,0,40838,0,0,@12000HP_350AP), -- Savage Gladiator Legs Paladin2
(@ZomBocom,0,40858,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Paladin2
(@ZomBocom,0,41851,0,0,@12000HP_350AP), -- Savage Gladiator Chest Priest1
(@ZomBocom,0,41847,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Priest1
(@ZomBocom,0,41848,0,0,@12000HP_350AP), -- Savage Gladiator Helm Priest1
(@ZomBocom,0,41849,0,0,@12000HP_350AP), -- Savage Gladiator Legs Priest1
(@ZomBocom,0,41850,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Priest1
(@ZomBocom,0,41918,0,0,@12000HP_350AP), -- Savage Gladiator Chest Priest2
(@ZomBocom,0,41937,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Priest2
(@ZomBocom,0,41912,0,0,@12000HP_350AP), -- Savage Gladiator Helm Priest2
(@ZomBocom,0,41924,0,0,@12000HP_350AP), -- Savage Gladiator Legs Priest2
(@ZomBocom,0,41930,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Priest2
(@ZomBocom,0,41647,0,0,@12000HP_350AP), -- Savage Gladiator Chest Rogue
(@ZomBocom,0,41643,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Rogue
(@ZomBocom,0,41644,0,0,@12000HP_350AP), -- Savage Gladiator Helm Rogue
(@ZomBocom,0,41645,0,0,@12000HP_350AP), -- Savage Gladiator Legs Rogue
(@ZomBocom,0,41646,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Rogue
(@ZomBocom,0,41078,0,0,@12000HP_350AP), -- Savage Gladiator Chest Shaman1
(@ZomBocom,0,41134,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Shaman1
(@ZomBocom,0,41148,0,0,@12000HP_350AP), -- Savage Gladiator Helm Shaman1
(@ZomBocom,0,41160,0,0,@12000HP_350AP), -- Savage Gladiator Legs Shaman1
(@ZomBocom,0,41208,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Shaman1
(@ZomBocom,0,40987,0,0,@12000HP_350AP), -- Savage Gladiator Chest Shaman2
(@ZomBocom,0,41004,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Shaman2
(@ZomBocom,0,41016,0,0,@12000HP_350AP), -- Savage Gladiator Helm Shaman2
(@ZomBocom,0,41030,0,0,@12000HP_350AP), -- Savage Gladiator Legs Shaman2
(@ZomBocom,0,41041,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Shaman2
(@ZomBocom,0,40986,0,0,@12000HP_350AP), -- Savage Gladiator Chest Shaman3
(@ZomBocom,0,40998,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Shaman3
(@ZomBocom,0,41010,0,0,@12000HP_350AP), -- Savage Gladiator Helm Shaman3
(@ZomBocom,0,41023,0,0,@12000HP_350AP), -- Savage Gladiator Legs Shaman3
(@ZomBocom,0,41024,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Shaman3
(@ZomBocom,0,41996,0,0,@12000HP_350AP), -- Savage Gladiator Chest Warlock
(@ZomBocom,0,42014,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Warlock
(@ZomBocom,0,41990,0,0,@12000HP_350AP), -- Savage Gladiator Helm Warlock
(@ZomBocom,0,42002,0,0,@12000HP_350AP), -- Savage Gladiator Legs Warlock
(@ZomBocom,0,42008,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Warlock
(@ZomBocom,0,40778,0,0,@12000HP_350AP), -- Savage Gladiator Chest Warrior
(@ZomBocom,0,40797,0,0,@7200HP_200AP), -- Savage Gladiator Gloves Warrior
(@ZomBocom,0,40816,0,0,@12000HP_350AP), -- Savage Gladiator Helm Warrior
(@ZomBocom,0,40836,0,0,@12000HP_350AP), -- Savage Gladiator Legs Warrior
(@ZomBocom,0,40856,0,0,@9600HP_275AP), -- Savage Gladiator Shoulders Warrior
-- NEXT SET SPACER
-- NEXT SET SPACER
-- NEXT SET SPACER
(@Xazi,0,40781,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest DK
(@Xazi,0,40803,0,0,@1615RT_7200HP_400AP),  -- Hateful Gladiator Gloves DK
(@Xazi,0,40820,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm DK
(@Xazi,0,40841,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs DK
(@Xazi,0,40860,0,0,@1775RT_9600HP_550AP),  -- Hateful Gladiator Shoulders DK
(@Xazi,0,41308,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Druid1
(@Xazi,0,41284,0,0,@1615RT_7200HP_400AP),  -- Hateful Gladiator Gloves Druid1
(@Xazi,0,41319,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Druid1
(@Xazi,0,41296,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Druid1
(@Xazi,0,41273,0,0,@1775RT_9600HP_550AP),  -- Hateful Gladiator Shoulders Druid1
(@Xazi,0,41659,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Druid2
(@Xazi,0,41771,0,0,@1615RT_7200HP_400AP),  -- Hateful Gladiator Gloves Druid2
(@Xazi,0,41676,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Druid2
(@Xazi,0,41665,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Druid2
(@Xazi,0,41713,0,0,@1775RT_9600HP_550AP),  -- Hateful Gladiator Shoulders Druid2
(@Xazi,0,41314,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Druid3
(@Xazi,0,41291,0,0,@1615RT_7200HP_400AP),  -- Hateful Gladiator Gloves Druid3
(@Xazi,0,41325,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Druid3
(@Xazi,0,41302,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Druid3
(@Xazi,0,41279,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Druid3
(@Xazi,0,41085,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Hunter
(@Xazi,0,41141,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Hunter
(@Xazi,0,41155,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Hunter
(@Xazi,0,41203,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Hunter
(@Xazi,0,41215,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Hunter
(@Xazi,0,41950,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Mage
(@Xazi,0,41969,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Mage
(@Xazi,0,41944,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Mage
(@Xazi,0,41957,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Mage
(@Xazi,0,41963,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Mage
(@Xazi,0,40904,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Paladin1
(@Xazi,0,40925,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Paladin1
(@Xazi,0,40931,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Paladin1
(@Xazi,0,40937,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Paladin1
(@Xazi,0,40961,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Paladin1
(@Xazi,0,40782,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Paladin2
(@Xazi,0,40802,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Paladin2
(@Xazi,0,40821,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Paladin2
(@Xazi,0,40842,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Paladin2
(@Xazi,0,40861,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Paladin2
(@Xazi,0,41857,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Priest1
(@Xazi,0,41872,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Priest1
(@Xazi,0,41852,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Priest1
(@Xazi,0,41862,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Priest1
(@Xazi,0,41867,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Priest1
(@Xazi,0,41919,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Priest2
(@Xazi,0,41938,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Priest2
(@Xazi,0,41913,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Priest2
(@Xazi,0,41925,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Priest2
(@Xazi,0,41931,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Priest2
(@Xazi,0,41648,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Rogue
(@Xazi,0,41765,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Rogue
(@Xazi,0,41670,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Rogue
(@Xazi,0,41653,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Rogue
(@Xazi,0,41681,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Rogue
(@Xazi,0,41079,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Shaman1
(@Xazi,0,41135,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Shaman1
(@Xazi,0,41149,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Shaman1
(@Xazi,0,41162,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Shaman1
(@Xazi,0,41209,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Shaman1
(@Xazi,0,40989,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Shaman2
(@Xazi,0,41005,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Shaman2
(@Xazi,0,41017,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Shaman2
(@Xazi,0,41031,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Shaman2
(@Xazi,0,41042,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Shaman2
(@Xazi,0,40988,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Shaman3
(@Xazi,0,40999,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Shaman3
(@Xazi,0,41011,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Shaman3
(@Xazi,0,41025,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Shaman3
(@Xazi,0,41036,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Shaman3
(@Xazi,0,42001,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Warlock
(@Xazi,0,42015,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Warlock
(@Xazi,0,41991,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Warlock
(@Xazi,0,42003,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Warlock
(@Xazi,0,42009,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Warlock
(@Xazi,0,40783,0,0,@1675RT_12000HP_700AP), -- Hateful Gladiator Chest Warrior
(@Xazi,0,40801,0,0,@1615RT_7200HP_400AP), -- Hateful Gladiator Gloves Warrior
(@Xazi,0,40819,0,0,@1735RT_12000HP_700AP), -- Hateful Gladiator Helm Warrior
(@Xazi,0,40840,0,0,@1645RT_12000HP_700AP), -- Hateful Gladiator Legs Warrior
(@Xazi,0,40859,0,0,@1775RT_9600HP_550AP), -- Hateful Gladiator Shoulders Warrior
-- NEXT SET SPACER
-- NEXT SET SPACER
-- NEXT SET SPACER
(@Nargle,0,40784,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest DK
(@Nargle,0,40806,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves DK
(@Nargle,0,40824,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm DK
(@Nargle,0,40845,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs DK
(@Nargle,0,40863,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders DK
(@Nargle,0,41309,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid1
(@Nargle,0,41286,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid1
(@Nargle,0,41320,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid1
(@Nargle,0,41297,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid1
(@Nargle,0,41274,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid1
(@Nargle,0,41660,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid2
(@Nargle,0,41772,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid2
(@Nargle,0,41677,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid2
(@Nargle,0,41666,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid2
(@Nargle,0,41714,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid2
(@Nargle,0,41315,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid3
(@Nargle,0,41292,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid3
(@Nargle,0,41326,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid3
(@Nargle,0,41303,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid3
(@Nargle,0,41280,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid3
(@Nargle,0,41086,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Hunter
(@Nargle,0,41142,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Hunter
(@Nargle,0,41156,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Hunter
(@Nargle,0,41204,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Hunter
(@Nargle,0,41216,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Hunter
(@Nargle,0,41951,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Mage
(@Nargle,0,41970,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Mage
(@Nargle,0,41945,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Mage
(@Nargle,0,41958,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Mage
(@Nargle,0,41964,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Mage
(@Nargle,0,40905,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Paladin1
(@Nargle,0,40926,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Paladin1
(@Nargle,0,40932,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Paladin1
(@Nargle,0,40938,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Paladin1
(@Nargle,0,40962,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Paladin1
(@Nargle,0,40785,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Paladin2
(@Nargle,0,40805,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Paladin2
(@Nargle,0,40825,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Paladin2
(@Nargle,0,40846,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Paladin2
(@Nargle,0,40864,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Paladin2
(@Nargle,0,41858,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Priest1
(@Nargle,0,41873,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Priest1
(@Nargle,0,41853,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Priest1
(@Nargle,0,41863,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Priest1
(@Nargle,0,41868,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Priest1
(@Nargle,0,41920,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Priest2
(@Nargle,0,41939,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Priest2
(@Nargle,0,41914,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Priest2
(@Nargle,0,41926,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Priest2
(@Nargle,0,41933,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Priest2
(@Nargle,0,41649,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Rogue
(@Nargle,0,41766,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Rogue
(@Nargle,0,41671,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Rogue
(@Nargle,0,41654,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Rogue
(@Nargle,0,41682,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Rogue
(@Nargle,0,41080,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman1
(@Nargle,0,41136,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman1
(@Nargle,0,41150,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman1
(@Nargle,0,41198,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman1
(@Nargle,0,41210,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman1
(@Nargle,0,40991,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman2
(@Nargle,0,41006,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman2
(@Nargle,0,41018,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman2
(@Nargle,0,41032,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman2
(@Nargle,0,41043,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman2
(@Nargle,0,40990,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman3
(@Nargle,0,41000,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman3
(@Nargle,0,41012,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman3
(@Nargle,0,41026,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman3
(@Nargle,0,41037,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman3
(@Nargle,0,41997,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Warlock
(@Nargle,0,42016,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Warlock
(@Nargle,0,41992,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Warlock
(@Nargle,0,42004,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Warlock
(@Nargle,0,42010,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Warlock
(@Nargle,0,40786,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Warrior
(@Nargle,0,40804,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Warrior
(@Nargle,0,40823,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Warrior
(@Nargle,0,40844,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Warrior
(@Nargle,0,40862,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Warrior
-- Weapons
(@Nargle,0,42490,0,0,@1930RT_4500AP),-- Deadly Gladiator Longbow (bow)
(@Nargle,0,42495,0,0,@1930RT_4500AP),-- Deadly Gladiator Heavy Crossbow (crossbow)
(@Nargle,0,42255,0,0,@1930RT_3150AP),-- Deadly Gladiator Mutilator (dagger) offhand
(@Nargle,0,42242,0,0,@1930RT_3150AP),-- Deadly Gladiator Shanker (dagger) One Hand
(@Nargle,0,42248,0,0,@1930RT_3150AP),-- Deadly Gladiator Shiv (dagger) offhand
(@Nargle,0,42346,0,0,@1930RT_3150AP),-- Deadly Gladiator Spellblade (dagger) Main Hand
(@Nargle,0,42265,0,0,@1930RT_3150AP),-- Deadly Gladiator Left Render (Fist Weapon) offhand
(@Nargle,0,42270,0,0,@1930RT_3150AP),-- Deadly Gladiator Left Ripper (Fist Weapon) offhand
(@Nargle,0,42260,0,0,@1930RT_3150AP),-- Deadly Gladiator Right Ripper (Fist Weapon) main hand
(@Nargle,0,42485,0,0,@1930RT_4500AP),-- Deadly Gladiator Rifle (Gun)
(@Nargle,0,42232,0,0,@1930RT_3150AP),-- Deadly Gladiator Chopper (1haxe) offhand
(@Nargle,0,42208,0,0,@1930RT_3150AP),-- Deadly Gladiator Cleaver (1haxe) mainhand
(@Nargle,0,42227,0,0,@1930RT_3150AP),-- Deadly Gladiator Hacker (1haxe) offhand
(@Nargle,0,42237,0,0,@1930RT_3150AP),-- Deadly Gladiator Waraxe (1haxe) one hand
(@Nargle,0,42280,0,0,@1930RT_3150AP),-- Deadly Gladiator Bonecracker (1hmace) offhand
(@Nargle,0,42352,0,0,@1930RT_3150AP),-- Deadly Gladiator Gavel (1h mace) main hand
(@Nargle,0,42275,0,0,@1930RT_3150AP),-- Deadly Gladiator Pummeler (1h mace) one hand
(@Nargle,0,42290,0,0,@1930RT_3150AP),-- Deadly Gladiator Quickblade (1h sword) off hand
(@Nargle,0,42285,0,0,@1930RT_3150AP),-- Deadly Gladiator Slicer (1h sword) one hand
(@Nargle,0,42327,0,0,@1930RT_4500AP),-- Deadly Gladiator Pike (polearm)
(@Nargle,0,42362,0,0,@1930RT_4500AP),-- Deadly Gladiator Battle Staff (staff)
(@Nargle,0,42384,0,0,@1930RT_4500AP),-- Deadly Gladiator Energy Staff (staff)
(@Nargle,0,44420,0,0,@1930RT_4500AP),-- Deadly Gladiator Focus Staff (staff)
(@Nargle,0,42390,0,0,@1930RT_4500AP),-- Deadly Gladiator Staff (staff)
(@Nargle,0,44419,0,0,@1930RT_4500AP),-- Deadly Gladiator War Staff (staff)
(@Nargle,0,42450,0,0,@1930RT_2250AP),-- Deadly Gladiator War Edge (Thrown)
(@Nargle,0,42317,0,0,@1930RT_4500AP),-- Deadly Gladiator Decapitator (2haxe)
(@Nargle,0,42322,0,0,@1930RT_4500AP),-- Deadly Gladiator Bonegrinder (2hmace)
(@Nargle,0,42332,0,0,@1930RT_4500AP),-- Deadly Gladiator Greatsword (2h Sword)
(@Nargle,0,42513,0,0,@1930RT_2250AP),-- Deadly Gladiator Baton of Light (wand)
(@Nargle,0,42519,0,0,@1930RT_2250AP),-- Deadly Gladiator Piercing Touch (wand)
(@Nargle,0,42502,0,0,@1930RT_2250AP),-- Deadly Gladiator Touch of Defeat (wand)
(@Nargle,0,42564,0,0,@1930RT_2250AP),-- Deadly Gladiator Barrier (shield)
(@Nargle,0,42570,0,0,@1930RT_2250AP),-- Deadly Gladiator Redoubt (shield)
(@Nargle,0,42559,0,0,@1930RT_2250AP),-- Deadly Gladiator Shield Wall (shield)
(@Nargle,0,42588,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Resolve (Relic)
(@Nargle,0,42583,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Steadfastness (Relic)
(@Nargle,0,42578,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Tenacity (Relic)
(@Nargle,0,42852,0,0,@1930RT_1200AP),-- Deadly Gladiator Libram of Fortitude (Relic)
(@Nargle,0,42614,0,0,@1930RT_1200AP),-- Deadly Gladiator Libram of Justice (Relic)
(@Nargle,0,42620,0,0,@1930RT_1200AP),-- Deadly Gladiator Sigil of Strife (Relic)
(@Nargle,0,42607,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of Indomitability (Relic)
(@Nargle,0,42602,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of Survival (Relic)
(@Nargle,0,42597,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of the Third Wind (Relic)
-- Spacer
(@Kezzik,0,40784,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest DK
(@Kezzik,0,40806,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves DK
(@Kezzik,0,40824,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm DK
(@Kezzik,0,40845,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs DK
(@Kezzik,0,40863,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders DK
(@Kezzik,0,41309,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid1
(@Kezzik,0,41286,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid1
(@Kezzik,0,41320,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid1
(@Kezzik,0,41297,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid1
(@Kezzik,0,41274,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid1
(@Kezzik,0,41660,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid2
(@Kezzik,0,41772,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid2
(@Kezzik,0,41677,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid2
(@Kezzik,0,41666,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid2
(@Kezzik,0,41714,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid2
(@Kezzik,0,41315,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid3
(@Kezzik,0,41292,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid3
(@Kezzik,0,41326,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid3
(@Kezzik,0,41303,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid3
(@Kezzik,0,41280,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid3
(@Kezzik,0,41086,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Hunter
(@Kezzik,0,41142,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Hunter
(@Kezzik,0,41156,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Hunter
(@Kezzik,0,41204,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Hunter
(@Kezzik,0,41216,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Hunter
(@Kezzik,0,41951,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Mage
(@Kezzik,0,41970,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Mage
(@Kezzik,0,41945,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Mage
(@Kezzik,0,41958,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Mage
(@Kezzik,0,41964,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Mage
(@Kezzik,0,40905,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Paladin1
(@Kezzik,0,40926,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Paladin1
(@Kezzik,0,40932,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Paladin1
(@Kezzik,0,40938,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Paladin1
(@Kezzik,0,40962,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Paladin1
(@Kezzik,0,40785,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Paladin2
(@Kezzik,0,40805,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Paladin2
(@Kezzik,0,40825,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Paladin2
(@Kezzik,0,40846,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Paladin2
(@Kezzik,0,40864,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Paladin2
(@Kezzik,0,41858,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Priest1
(@Kezzik,0,41873,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Priest1
(@Kezzik,0,41853,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Priest1
(@Kezzik,0,41863,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Priest1
(@Kezzik,0,41868,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Priest1
(@Kezzik,0,41920,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Priest2
(@Kezzik,0,41939,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Priest2
(@Kezzik,0,41914,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Priest2
(@Kezzik,0,41926,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Priest2
(@Kezzik,0,41933,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Priest2
(@Kezzik,0,41649,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Rogue
(@Kezzik,0,41766,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Rogue
(@Kezzik,0,41671,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Rogue
(@Kezzik,0,41654,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Rogue
(@Kezzik,0,41682,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Rogue
(@Kezzik,0,41080,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman1
(@Kezzik,0,41136,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman1
(@Kezzik,0,41150,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman1
(@Kezzik,0,41198,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman1
(@Kezzik,0,41210,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman1
(@Kezzik,0,40991,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman2
(@Kezzik,0,41006,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman2
(@Kezzik,0,41018,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman2
(@Kezzik,0,41032,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman2
(@Kezzik,0,41043,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman2
(@Kezzik,0,40990,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman3
(@Kezzik,0,41000,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman3
(@Kezzik,0,41012,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman3
(@Kezzik,0,41026,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman3
(@Kezzik,0,41037,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman3
(@Kezzik,0,41997,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Warlock
(@Kezzik,0,42016,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Warlock
(@Kezzik,0,41992,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Warlock
(@Kezzik,0,42004,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Warlock
(@Kezzik,0,42010,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Warlock
(@Kezzik,0,40786,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Warrior
(@Kezzik,0,40804,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Warrior
(@Kezzik,0,40823,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Warrior
(@Kezzik,0,40844,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Warrior
(@Kezzik,0,40862,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Warrior
-- Weapons
(@Kezzik,0,42490,0,0,@1930RT_4500AP),-- Deadly Gladiator Longbow (bow)
(@Kezzik,0,42495,0,0,@1930RT_4500AP),-- Deadly Gladiator Heavy Crossbow (crossbow)
(@Kezzik,0,42255,0,0,@1930RT_3150AP),-- Deadly Gladiator Mutilator (dagger) offhand
(@Kezzik,0,42242,0,0,@1930RT_3150AP),-- Deadly Gladiator Shanker (dagger) One Hand
(@Kezzik,0,42248,0,0,@1930RT_3150AP),-- Deadly Gladiator Shiv (dagger) offhand
(@Kezzik,0,42346,0,0,@1930RT_3150AP),-- Deadly Gladiator Spellblade (dagger) Main Hand
(@Kezzik,0,42265,0,0,@1930RT_3150AP),-- Deadly Gladiator Left Render (Fist Weapon) offhand
(@Kezzik,0,42270,0,0,@1930RT_3150AP),-- Deadly Gladiator Left Ripper (Fist Weapon) offhand
(@Kezzik,0,42260,0,0,@1930RT_3150AP),-- Deadly Gladiator Right Ripper (Fist Weapon) main hand
(@Kezzik,0,42485,0,0,@1930RT_4500AP),-- Deadly Gladiator Rifle (Gun)
(@Kezzik,0,42232,0,0,@1930RT_3150AP),-- Deadly Gladiator Chopper (1haxe) offhand
(@Kezzik,0,42208,0,0,@1930RT_3150AP),-- Deadly Gladiator Cleaver (1haxe) mainhand
(@Kezzik,0,42227,0,0,@1930RT_3150AP),-- Deadly Gladiator Hacker (1haxe) offhand
(@Kezzik,0,42237,0,0,@1930RT_3150AP),-- Deadly Gladiator Waraxe (1haxe) one hand
(@Kezzik,0,42280,0,0,@1930RT_3150AP),-- Deadly Gladiator Bonecracker (1hmace) offhand
(@Kezzik,0,42352,0,0,@1930RT_3150AP),-- Deadly Gladiator Gavel (1h mace) main hand
(@Kezzik,0,42275,0,0,@1930RT_3150AP),-- Deadly Gladiator Pummeler (1h mace) one hand
(@Kezzik,0,42290,0,0,@1930RT_3150AP),-- Deadly Gladiator Quickblade (1h sword) off hand
(@Kezzik,0,42285,0,0,@1930RT_3150AP),-- Deadly Gladiator Slicer (1h sword) one hand
(@Kezzik,0,42327,0,0,@1930RT_4500AP),-- Deadly Gladiator Pike (polearm)
(@Kezzik,0,42362,0,0,@1930RT_4500AP),-- Deadly Gladiator Battle Staff (staff)
(@Kezzik,0,42384,0,0,@1930RT_4500AP),-- Deadly Gladiator Energy Staff (staff)
(@Kezzik,0,44420,0,0,@1930RT_4500AP),-- Deadly Gladiator Focus Staff (staff)
(@Kezzik,0,42390,0,0,@1930RT_4500AP),-- Deadly Gladiator Staff (staff)
(@Kezzik,0,44419,0,0,@1930RT_4500AP),-- Deadly Gladiator War Staff (staff)
(@Kezzik,0,42450,0,0,@1930RT_2250AP),-- Deadly Gladiator War Edge (Thrown)
(@Kezzik,0,42317,0,0,@1930RT_4500AP),-- Deadly Gladiator Decapitator (2haxe)
(@Kezzik,0,42322,0,0,@1930RT_4500AP),-- Deadly Gladiator Bonegrinder (2hmace)
(@Kezzik,0,42332,0,0,@1930RT_4500AP),-- Deadly Gladiator Greatsword (2h Sword)
(@Kezzik,0,42513,0,0,@1930RT_2250AP),-- Deadly Gladiator Baton of Light (wand)
(@Kezzik,0,42519,0,0,@1930RT_2250AP),-- Deadly Gladiator Piercing Touch (wand)
(@Kezzik,0,42502,0,0,@1930RT_2250AP),-- Deadly Gladiator Touch of Defeat (wand)
(@Kezzik,0,42564,0,0,@1930RT_2250AP),-- Deadly Gladiator Barrier (shield)
(@Kezzik,0,42570,0,0,@1930RT_2250AP),-- Deadly Gladiator Redoubt (shield)
(@Kezzik,0,42559,0,0,@1930RT_2250AP),-- Deadly Gladiator Shield Wall (shield)
(@Kezzik,0,42588,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Resolve (Relic)
(@Kezzik,0,42583,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Steadfastness (Relic)
(@Kezzik,0,42578,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Tenacity (Relic)
(@Kezzik,0,42852,0,0,@1930RT_1200AP),-- Deadly Gladiator Libram of Fortitude (Relic)
(@Kezzik,0,42614,0,0,@1930RT_1200AP),-- Deadly Gladiator Libram of Justice (Relic)
(@Kezzik,0,42620,0,0,@1930RT_1200AP),-- Deadly Gladiator Sigil of Strife (Relic)
(@Kezzik,0,42607,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of Indomitability (Relic)
(@Kezzik,0,42602,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of Survival (Relic)
(@Kezzik,0,42597,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of the Third Wind (Relic)
-- Spacer
(@Argex,0,40784,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest DK
(@Argex,0,40806,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves DK
(@Argex,0,40824,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm DK
(@Argex,0,40845,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs DK
(@Argex,0,40863,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders DK
(@Argex,0,41309,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid1
(@Argex,0,41286,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid1
(@Argex,0,41320,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid1
(@Argex,0,41297,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid1
(@Argex,0,41274,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid1
(@Argex,0,41660,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid2
(@Argex,0,41772,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid2
(@Argex,0,41677,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid2
(@Argex,0,41666,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid2
(@Argex,0,41714,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid2
(@Argex,0,41315,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Druid3
(@Argex,0,41292,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Druid3
(@Argex,0,41326,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Druid3
(@Argex,0,41303,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Druid3
(@Argex,0,41280,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Druid3
(@Argex,0,41086,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Hunter
(@Argex,0,41142,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Hunter
(@Argex,0,41156,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Hunter
(@Argex,0,41204,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Hunter
(@Argex,0,41216,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Hunter
(@Argex,0,41951,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Mage
(@Argex,0,41970,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Mage
(@Argex,0,41945,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Mage
(@Argex,0,41958,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Mage
(@Argex,0,41964,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Mage
(@Argex,0,40905,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Paladin1
(@Argex,0,40926,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Paladin1
(@Argex,0,40932,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Paladin1
(@Argex,0,40938,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Paladin1
(@Argex,0,40962,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Paladin1
(@Argex,0,40785,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Paladin2
(@Argex,0,40805,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Paladin2
(@Argex,0,40825,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Paladin2
(@Argex,0,40846,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Paladin2
(@Argex,0,40864,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Paladin2
(@Argex,0,41858,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Priest1
(@Argex,0,41873,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Priest1
(@Argex,0,41853,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Priest1
(@Argex,0,41863,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Priest1
(@Argex,0,41868,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Priest1
(@Argex,0,41920,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Priest2
(@Argex,0,41939,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Priest2
(@Argex,0,41914,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Priest2
(@Argex,0,41926,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Priest2
(@Argex,0,41933,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Priest2
(@Argex,0,41649,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Rogue
(@Argex,0,41766,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Rogue
(@Argex,0,41671,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Rogue
(@Argex,0,41654,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Rogue
(@Argex,0,41682,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Rogue
(@Argex,0,41080,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman1
(@Argex,0,41136,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman1
(@Argex,0,41150,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman1
(@Argex,0,41198,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman1
(@Argex,0,41210,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman1
(@Argex,0,40991,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman2
(@Argex,0,41006,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman2
(@Argex,0,41018,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman2
(@Argex,0,41032,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman2
(@Argex,0,41043,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman2
(@Argex,0,40990,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Shaman3
(@Argex,0,41000,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Shaman3
(@Argex,0,41012,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Shaman3
(@Argex,0,41026,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Shaman3
(@Argex,0,41037,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Shaman3
(@Argex,0,41997,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Warlock
(@Argex,0,42016,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Warlock
(@Argex,0,41992,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Warlock
(@Argex,0,42004,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Warlock
(@Argex,0,42010,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Warlock
(@Argex,0,40786,0,0,@1870RT_2250AP), -- Deadly Gladiator Chest Warrior
(@Argex,0,40804,0,0,@1750RT_1350AP), -- Deadly Gladiator Gloves Warrior
(@Argex,0,40823,0,0,@1990RT_2250AP), -- Deadly Gladiator Helm Warrior
(@Argex,0,40844,0,0,@1810RT_2250AP), -- Deadly Gladiator Legs Warrior
(@Argex,0,40862,0,0,@2050RT_1750AP), -- Deadly Gladiator Shoulders Warrior
-- Weapons
(@Argex,0,42490,0,0,@1930RT_4500AP),-- Deadly Gladiator Longbow (bow)
(@Argex,0,42495,0,0,@1930RT_4500AP),-- Deadly Gladiator Heavy Crossbow (crossbow)
(@Argex,0,42255,0,0,@1930RT_3150AP),-- Deadly Gladiator Mutilator (dagger) offhand
(@Argex,0,42242,0,0,@1930RT_3150AP),-- Deadly Gladiator Shanker (dagger) One Hand
(@Argex,0,42248,0,0,@1930RT_3150AP),-- Deadly Gladiator Shiv (dagger) offhand
(@Argex,0,42346,0,0,@1930RT_3150AP),-- Deadly Gladiator Spellblade (dagger) Main Hand
(@Argex,0,42265,0,0,@1930RT_3150AP),-- Deadly Gladiator Left Render (Fist Weapon) offhand
(@Argex,0,42270,0,0,@1930RT_3150AP),-- Deadly Gladiator Left Ripper (Fist Weapon) offhand
(@Argex,0,42260,0,0,@1930RT_3150AP),-- Deadly Gladiator Right Ripper (Fist Weapon) main hand
(@Argex,0,42485,0,0,@1930RT_4500AP),-- Deadly Gladiator Rifle (Gun)
(@Argex,0,42232,0,0,@1930RT_3150AP),-- Deadly Gladiator Chopper (1haxe) offhand
(@Argex,0,42208,0,0,@1930RT_3150AP),-- Deadly Gladiator Cleaver (1haxe) mainhand
(@Argex,0,42227,0,0,@1930RT_3150AP),-- Deadly Gladiator Hacker (1haxe) offhand
(@Argex,0,42237,0,0,@1930RT_3150AP),-- Deadly Gladiator Waraxe (1haxe) one hand
(@Argex,0,42280,0,0,@1930RT_3150AP),-- Deadly Gladiator Bonecracker (1hmace) offhand
(@Argex,0,42352,0,0,@1930RT_3150AP),-- Deadly Gladiator Gavel (1h mace) main hand
(@Argex,0,42275,0,0,@1930RT_3150AP),-- Deadly Gladiator Pummeler (1h mace) one hand
(@Argex,0,42290,0,0,@1930RT_3150AP),-- Deadly Gladiator Quickblade (1h sword) off hand
(@Argex,0,42285,0,0,@1930RT_3150AP),-- Deadly Gladiator Slicer (1h sword) one hand
(@Argex,0,42327,0,0,@1930RT_4500AP),-- Deadly Gladiator Pike (polearm)
(@Argex,0,42362,0,0,@1930RT_4500AP),-- Deadly Gladiator Battle Staff (staff)
(@Argex,0,42384,0,0,@1930RT_4500AP),-- Deadly Gladiator Energy Staff (staff)
(@Argex,0,44420,0,0,@1930RT_4500AP),-- Deadly Gladiator Focus Staff (staff)
(@Argex,0,42390,0,0,@1930RT_4500AP),-- Deadly Gladiator Staff (staff)
(@Argex,0,44419,0,0,@1930RT_4500AP),-- Deadly Gladiator War Staff (staff)
(@Argex,0,42450,0,0,@1930RT_2250AP),-- Deadly Gladiator War Edge (Thrown)
(@Argex,0,42317,0,0,@1930RT_4500AP),-- Deadly Gladiator Decapitator (2haxe)
(@Argex,0,42322,0,0,@1930RT_4500AP),-- Deadly Gladiator Bonegrinder (2hmace)
(@Argex,0,42332,0,0,@1930RT_4500AP),-- Deadly Gladiator Greatsword (2h Sword)
(@Argex,0,42513,0,0,@1930RT_2250AP),-- Deadly Gladiator Baton of Light (wand)
(@Argex,0,42519,0,0,@1930RT_2250AP),-- Deadly Gladiator Piercing Touch (wand)
(@Argex,0,42502,0,0,@1930RT_2250AP),-- Deadly Gladiator Touch of Defeat (wand)
(@Argex,0,42564,0,0,@1930RT_2250AP),-- Deadly Gladiator Barrier (shield)
(@Argex,0,42570,0,0,@1930RT_2250AP),-- Deadly Gladiator Redoubt (shield)
(@Argex,0,42559,0,0,@1930RT_2250AP),-- Deadly Gladiator Shield Wall (shield)
(@Argex,0,42588,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Resolve (Relic)
(@Argex,0,42583,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Steadfastness (Relic)
(@Argex,0,42578,0,0,@1930RT_1200AP),-- Deadly Gladiator Idol of Tenacity (Relic)
(@Argex,0,42852,0,0,@1930RT_1200AP),-- Deadly Gladiator Libram of Fortitude (Relic)
(@Argex,0,42614,0,0,@1930RT_1200AP),-- Deadly Gladiator Libram of Justice (Relic)
(@Argex,0,42620,0,0,@1930RT_1200AP),-- Deadly Gladiator Sigil of Strife (Relic)
(@Argex,0,42607,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of Indomitability (Relic)
(@Argex,0,42602,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of Survival (Relic)
(@Argex,0,42597,0,0,@1930RT_1200AP),-- Deadly Gladiator Totem of the Third Wind (Relic)
-- NEXT SET SPACER
-- NEXT SET SPACER
-- NEXT SET SPACER
(@Thunderhorn,0,42110,0,0,@38000HP), -- Hateful Gladiator Band of Dominance
(@Thunderhorn,0,42112,0,0,@38000HP), -- Hateful Gladiator Band of Triumph
(@Thunderhorn,0,42057,0,0,@38000HP), -- Hateful Gladiator's Cloak of Ascendancy
(@Thunderhorn,0,42059,0,0,@38000HP), -- Hateful Gladiator's Cloak of Deliverance
(@Thunderhorn,0,42055,0,0,@38000HP), -- Hateful Gladiator's Cloak of Dominance
(@Thunderhorn,0,42058,0,0,@38000HP), -- Hateful Gladiator's Cloak of Salvation
(@Thunderhorn,0,42056,0,0,@38000HP), -- Hateful Gladiator's Cloak of Subjugation
(@Thunderhorn,0,42060,0,0,@38000HP), -- Hateful Gladiator's Cloak of Triumph
(@Thunderhorn,0,42061,0,0,@38000HP), -- Hateful Gladiator's Cloak of Victory
(@Thunderhorn,0,42024,0,0,@38000HP), -- Hateful Gladiator's Pendant of Ascendancy
(@Thunderhorn,0,42025,0,0,@38000HP), -- Hateful Gladiator's Pendant of Deliverance
(@Thunderhorn,0,42022,0,0,@38000HP), -- Hateful Gladiator's Pendant of Dominance
(@Thunderhorn,0,42026,0,0,@38000HP), -- Hateful Gladiator's Pendant of Salvation
(@Thunderhorn,0,42023,0,0,@38000HP), -- Hateful Gladiator's Pendant of Subjugation
(@Thunderhorn,0,42020,0,0,@38000HP), -- Hateful Gladiator's Pendant of Triumph
(@Thunderhorn,0,42021,0,0,@38000HP), -- Hateful Gladiator's Pendant of Victory
(@Thunderhorn,0,41638,0,0,@31600HP), -- Hateful Gladiator's Armwraps of Dominance
(@Thunderhorn,0,41332,0,0,@31600HP), -- Hateful Gladiator's Armwraps of Salvation
(@Thunderhorn,0,41830,0,0,@31600HP), -- Hateful Gladiator's Armwraps of Triumph
(@Thunderhorn,0,40972,0,0,@31600HP), -- Hateful Gladiator's Bracers of Salvation
(@Thunderhorn,0,40887,0,0,@31600HP), -- Hateful Gladiator's Bracers of Triumph
(@Thunderhorn,0,41907,0,0,@31600HP), -- Hateful Gladiator's Cuffs of Dominance
(@Thunderhorn,0,41878,0,0,@31600HP), -- Hateful Gladiator's Cuffs of Salvation
(@Thunderhorn,0,41063,0,0,@31600HP), -- Hateful Gladiator's Wristguards of Dominance
(@Thunderhorn,0,41047,0,0,@31600HP), -- Hateful Gladiator's Wristguards of Salvation
(@Thunderhorn,0,41223,0,0,@31600HP), -- Hateful Gladiator's Wristguards of Triumph
(@Thunderhorn,0,41633,0,0,@49600HP), -- Hateful Gladiator's Boots of Dominance
(@Thunderhorn,0,41331,0,0,@49600HP), -- Hateful Gladiator's Boots of Salvation
(@Thunderhorn,0,41828,0,0,@49600HP), -- Hateful Gladiator's Boots of Triumph
(@Thunderhorn,0,40973,0,0,@49600HP), -- Hateful Gladiator's Greaves of Salvation
(@Thunderhorn,0,40878,0,0,@49600HP), -- Hateful Gladiator's Greaves of Triumph
(@Thunderhorn,0,41073,0,0,@49600HP), -- Hateful Gladiator's Sabatons of Dominance
(@Thunderhorn,0,41049,0,0,@49600HP), -- Hateful Gladiator's Sabatons of Salvation
(@Thunderhorn,0,41228,0,0,@49600HP), -- Hateful Gladiator's Sabatons of Triumph
(@Thunderhorn,0,41901,0,0,@49600HP), -- Hateful Gladiator's Slippers of Dominance
(@Thunderhorn,0,41879,0,0,@49600HP), -- Hateful Gladiator's Slippers of Salvation
(@Thunderhorn,0,41628,0,0,@49600HP), -- Hateful Gladiator's Belt of Dominance
(@Thunderhorn,0,41330,0,0,@49600HP), -- Hateful Gladiator's Belt of Salvation
(@Thunderhorn,0,41827,0,0,@49600HP), -- Hateful Gladiator's Belt of Triumph
(@Thunderhorn,0,41896,0,0,@49600HP), -- Hateful Gladiator's Cord of Dominance
(@Thunderhorn,0,41877,0,0,@49600HP), -- Hateful Gladiator's Cord of Salvation
(@Thunderhorn,0,40966,0,0,@49600HP), -- Hateful Gladiator's Girdle of Salvation
(@Thunderhorn,0,40877,0,0,@49600HP), -- Hateful Gladiator's Girdle of Triumph
(@Thunderhorn,0,41068,0,0,@49600HP), -- Hateful Gladiator's Waistguard of Dominance
(@Thunderhorn,0,41050,0,0,@49600HP), -- Hateful Gladiator's Waistguard of Salvation
(@Thunderhorn,0,41233,0,0,@49600HP), -- Hateful Gladiator's Waistguard of Triumph
(@Thunderhorn,0,42122,0,0,@49600HP), -- Medallion of the Horde
-- NEXT SET SPACER
-- NEXT SET SPACER
-- NEXT SET SPACER
(@Doris,0,42129,0,0,@1800RT_62000HP), -- Battlemasters Accuracy   213
(@Doris,0,42130,0,0,@1800RT_62000HP), -- Battlemasters Avidity    213
(@Doris,0,42132,0,0,@1800RT_62000HP), -- Battlemasters Bravery    213
(@Doris,0,42131,0,0,@1800RT_62000HP), -- Battlemasters Conviction 213
(@Doris,0,42128,0,0,@1800RT_62000HP), -- Battlemasters Hostility  213
(@Doris,0,42064,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Ascendancy
(@Doris,0,42066,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Deliverance
(@Doris,0,42062,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Dominance
(@Doris,0,42065,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Salvation
(@Doris,0,42063,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Subjugation
(@Doris,0,42067,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Triumph
(@Doris,0,42068,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Victory
(@Doris,0,41634,0,0,@1720RT_62000HP), -- Deadly Gladiator Boots of Dominance
(@Doris,0,41620,0,0,@1720RT_62000HP), -- Deadly Gladiator Boots of Salvation
(@Doris,0,41835,0,0,@1720RT_62000HP), -- Deadly Gladiator Boots of Triumph
(@Doris,0,40975,0,0,@1720RT_62000HP), -- Deadly Gladiator Greaves of Salvation
(@Doris,0,40880,0,0,@1720RT_62000HP), -- Deadly Gladiator Greaves of Triumph
(@Doris,0,41074,0,0,@1720RT_62000HP), -- Deadly Gladiator Sabatons of Dominance
(@Doris,0,41054,0,0,@1720RT_62000HP), -- Deadly Gladiator Sabatons of Salvation
(@Doris,0,41229,0,0,@1720RT_62000HP), -- Deadly Gladiator Sabatons of Triumph
(@Doris,0,41902,0,0,@1720RT_62000HP), -- Deadly Gladiator Treads of Dominance
(@Doris,0,41884,0,0,@1720RT_62000HP), -- Deadly Gladiator Treads of Salvation
(@Doris,0,42114,0,0,@1690RT_47400HP), -- Deadly Gladiator Band of Ascendancy
(@Doris,0,42115,0,0,@1690RT_47400HP), -- Deadly Gladiator Band of Victory
(@Doris,0,41639,0,0,@1660RT_39400HP), -- Deadly Gladiator Armwraps of Dominance
(@Doris,0,41624,0,0,@1660RT_39400HP), -- Deadly Gladiator Armwraps of Salvation
(@Doris,0,41839,0,0,@1660RT_39400HP), -- Deadly Gladiator Armwraps of Triumph
(@Doris,0,40982,0,0,@1660RT_39400HP), -- Deadly Gladiator Bracers of Salvation
(@Doris,0,40888,0,0,@1660RT_39400HP), -- Deadly Gladiator Bracers of Triumph
(@Doris,0,41908,0,0,@1660RT_39400HP), -- Deadly Gladiator Cuffs of Dominance
(@Doris,0,41892,0,0,@1660RT_39400HP), -- Deadly Gladiator Cuffs of Salvation
(@Doris,0,41064,0,0,@1660RT_39400HP), -- Deadly Gladiator Wristguards of Dominance
(@Doris,0,41059,0,0,@1660RT_39400HP), -- Deadly Gladiator Wristguards of Salvation
(@Doris,0,41224,0,0,@1660RT_39400HP), -- Deadly Gladiator Wristguards of Triumph
(@Doris,0,41629,0,0,@1630RT_62000HP), -- Deadly Gladiator Belt of Dominance
(@Doris,0,41616,0,0,@1630RT_62000HP), -- Deadly Gladiator Belt of Salvation
(@Doris,0,41831,0,0,@1630RT_62000HP), -- Deadly Gladiator Belt of Triumph
(@Doris,0,41897,0,0,@1630RT_62000HP), -- Deadly Gladiator Cord of Dominance
(@Doris,0,41880,0,0,@1630RT_62000HP), -- Deadly Gladiator Cord of Salvation
(@Doris,0,40974,0,0,@1630RT_62000HP), -- Deadly Gladiator Girdle of Salvation
(@Doris,0,40879,0,0,@1630RT_62000HP), -- Deadly Gladiator Girdle of Triumph
(@Doris,0,41069,0,0,@1630RT_62000HP), -- Deadly Gladiator Waistguard of Dominance
(@Doris,0,41048,0,0,@1630RT_62000HP), -- Deadly Gladiator Waistguard of Salvation
(@Doris,0,41234,0,0,@1630RT_62000HP), -- Deadly Gladiator Waistguard of Triumph
(@Doris,0,42030,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Ascendancy
(@Doris,0,42032,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Deliverance
(@Doris,0,42029,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Dominance
(@Doris,0,42033,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Salvation
(@Doris,0,42031,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Subjugation
(@Doris,0,42027,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Triumph
(@Doris,0,42028,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Victory
-- Spacer
(@Tristia,0,42129,0,0,@1800RT_62000HP), -- Battlemasters Accuracy   213
(@Tristia,0,42130,0,0,@1800RT_62000HP), -- Battlemasters Avidity    213
(@Tristia,0,42132,0,0,@1800RT_62000HP), -- Battlemasters Bravery    213
(@Tristia,0,42131,0,0,@1800RT_62000HP), -- Battlemasters Conviction 213
(@Tristia,0,42128,0,0,@1800RT_62000HP), -- Battlemasters Hostility  213
(@Tristia,0,42064,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Ascendancy
(@Tristia,0,42066,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Deliverance
(@Tristia,0,42062,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Dominance
(@Tristia,0,42065,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Salvation
(@Tristia,0,42063,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Subjugation
(@Tristia,0,42067,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Triumph
(@Tristia,0,42068,0,0,@1750RT_47400HP), -- Deadly Gladiator Cloack of Victory
(@Tristia,0,41634,0,0,@1720RT_62000HP), -- Deadly Gladiator Boots of Dominance
(@Tristia,0,41620,0,0,@1720RT_62000HP), -- Deadly Gladiator Boots of Salvation
(@Tristia,0,41835,0,0,@1720RT_62000HP), -- Deadly Gladiator Boots of Triumph
(@Tristia,0,40975,0,0,@1720RT_62000HP), -- Deadly Gladiator Greaves of Salvation
(@Tristia,0,40880,0,0,@1720RT_62000HP), -- Deadly Gladiator Greaves of Triumph
(@Tristia,0,41074,0,0,@1720RT_62000HP), -- Deadly Gladiator Sabatons of Dominance
(@Tristia,0,41054,0,0,@1720RT_62000HP), -- Deadly Gladiator Sabatons of Salvation
(@Tristia,0,41229,0,0,@1720RT_62000HP), -- Deadly Gladiator Sabatons of Triumph
(@Tristia,0,41902,0,0,@1720RT_62000HP), -- Deadly Gladiator Treads of Dominance
(@Tristia,0,41884,0,0,@1720RT_62000HP), -- Deadly Gladiator Treads of Salvation
(@Tristia,0,42114,0,0,@1690RT_47400HP), -- Deadly Gladiator Band of Ascendancy
(@Tristia,0,42115,0,0,@1690RT_47400HP), -- Deadly Gladiator Band of Victory
(@Tristia,0,41639,0,0,@1660RT_39400HP), -- Deadly Gladiator Armwraps of Dominance
(@Tristia,0,41624,0,0,@1660RT_39400HP), -- Deadly Gladiator Armwraps of Salvation
(@Tristia,0,41839,0,0,@1660RT_39400HP), -- Deadly Gladiator Armwraps of Triumph
(@Tristia,0,40982,0,0,@1660RT_39400HP), -- Deadly Gladiator Bracers of Salvation
(@Tristia,0,40888,0,0,@1660RT_39400HP), -- Deadly Gladiator Bracers of Triumph
(@Tristia,0,41908,0,0,@1660RT_39400HP), -- Deadly Gladiator Cuffs of Dominance
(@Tristia,0,41892,0,0,@1660RT_39400HP), -- Deadly Gladiator Cuffs of Salvation
(@Tristia,0,41064,0,0,@1660RT_39400HP), -- Deadly Gladiator Wristguards of Dominance
(@Tristia,0,41059,0,0,@1660RT_39400HP), -- Deadly Gladiator Wristguards of Salvation
(@Tristia,0,41224,0,0,@1660RT_39400HP), -- Deadly Gladiator Wristguards of Triumph
(@Tristia,0,41629,0,0,@1630RT_62000HP), -- Deadly Gladiator Belt of Dominance
(@Tristia,0,41616,0,0,@1630RT_62000HP), -- Deadly Gladiator Belt of Salvation
(@Tristia,0,41831,0,0,@1630RT_62000HP), -- Deadly Gladiator Belt of Triumph
(@Tristia,0,41897,0,0,@1630RT_62000HP), -- Deadly Gladiator Cord of Dominance
(@Tristia,0,41880,0,0,@1630RT_62000HP), -- Deadly Gladiator Cord of Salvation
(@Tristia,0,40974,0,0,@1630RT_62000HP), -- Deadly Gladiator Girdle of Salvation
(@Tristia,0,40879,0,0,@1630RT_62000HP), -- Deadly Gladiator Girdle of Triumph
(@Tristia,0,41069,0,0,@1630RT_62000HP), -- Deadly Gladiator Waistguard of Dominance
(@Tristia,0,41048,0,0,@1630RT_62000HP), -- Deadly Gladiator Waistguard of Salvation
(@Tristia,0,41234,0,0,@1630RT_62000HP), -- Deadly Gladiator Waistguard of Triumph
(@Tristia,0,42030,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Ascendancy
(@Tristia,0,42032,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Deliverance
(@Tristia,0,42029,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Dominance
(@Tristia,0,42033,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Salvation
(@Tristia,0,42031,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Subjugation
(@Tristia,0,42027,0,0,@1600RT_47400HP), -- Deadly Gladiator Pendant of Triumph
(@Tristia,0,42028,0,0,@1600RT_47400HP); -- Deadly Gladiator Pendant of Victory
