-- Skin loot entry
SET @LibraryLaborer := 29724;
SET @UldarBoss := 29725;
SET @AirStrip := 29726;
SET @ReavandDispo := 29727;
SET @HallsofStone := 29728;
SET @Dirkee := 29729;
SET @Recovery := 29730;
-- Ref Loot Entry
SET @UldarBossRef := 50013;
SET @AirStripRef := 50013+1;
SET @HallsofStoneRef := 50013+2;
SET @ReavandDispoRef := 50013+3;
SET @LibraryLaborerRef := 50013+4;
-- Add loot to the skinning table
DELETE FROM `skinning_loot_template` WHERE `entry` IN (@Recovery,@Dirkee,@LibraryLaborer,@ReavandDispo,@HallsofStone,@AirStrip,@UldarBoss);
INSERT INTO `skinning_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@Recovery, 41338, 42, 1, 0, 1, 3), -- Sprung Whirlygig
(@Recovery, 41337, 44, 1, 0, 1, 3), -- Whizzed out Gizmo
(@Recovery, 39690, 9, 1, 0, 1, 3), -- Volatile Blasting trigger
(@Recovery, 39681, 4, 1, 0, 2, 4), -- Handfull of copper bolts
(@Recovery, 49050, 0.5, 1, 0, 1, 1), -- jeeves
(@Recovery, 39682, 0.5, 1, 0, 1, 1), -- Overcharged Capacitor
(@Dirkee, 41338, 42, 1, 0, 1, 3), -- Sprung Whirlygig
(@Dirkee, 41337, 44.5, 1, 0, 1, 3), -- Whizzed out Gizmo
(@Dirkee, 39690, 10, 1, 0, 1, 3), -- Volatile Blasting trigger
(@Dirkee, 39681, 3, 1, 0, 2, 4), -- Handfull of copper bolts
(@Dirkee, 49050, 0.5, 1, 0, 1, 1), -- jeeves
(@LibraryLaborer , 1, 100, 1, 0, -@LibraryLaborerRef, 1),
(@ReavandDispo, 1, 100, 1, 0, -@ReavandDispoRef, 1),
(@HallsofStone, 1, 100, 1, 0, -@HallsofStoneRef, 1),
(@AirStrip, 1, 100, 1, 0, -@AirStripRef, 1),
(@UldarBoss, 1, 100, 1, 0, -@UldarBossRef, 1);
-- Add loot to the reference table
DELETE FROM `reference_loot_template` WHERE `entry` IN (@AirStripRef,@ReavandDispoRef,@LibraryLaborerRef,@HallsofStoneRef,@UldarBossRef);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@AirStripRef, 41338, 33, 1, 0, 1, 1), -- Sprung Whirlygig
(@AirStripRef, 41337, 42, 1, 0, 1, 1), -- Whizzed out Gizmo
(@AirStripRef, 39690, 13, 1, 0, 1, 3), -- Volatile Blasting trigger
(@AirStripRef, 39681, 10, 1, 0, 1, 4), -- Handfull of copper bolts
(@AirStripRef, 39686, 1.2, 1, 0, 1, 1), -- Frost steel Tube
(@AirStripRef, 49050, 0.8, 1, 0, 1, 1), -- jeeves
(@ReavandDispoRef, 41338, 40, 1, 0, 1, 3), -- Sprung Whirlygig
(@ReavandDispoRef, 41337, 40, 1, 0, 1, 3), -- Whizzed out Gizmo
(@ReavandDispoRef, 39690, 9.5, 1, 0, 1, 3), -- Volatile Blasting trigger
(@ReavandDispoRef, 39681, 9.5, 1, 0, 2, 4), -- Handfull of copper bolts
(@ReavandDispoRef, 39686, 0.5, 1, 0, 1, 1), -- Frost steel Tube
(@ReavandDispoRef, 49050, 0.5, 1, 0, 1, 1), -- jeeves
(@LibraryLaborerRef, 41338, 43, 1, 0, 1, 3), -- Sprung Whirlygig
(@LibraryLaborerRef, 41337, 42, 1, 0, 1, 3), -- Whizzed out Gizmo
(@LibraryLaborerRef, 39690, 9, 1, 0, 1, 3), -- Volatile Blasting trigger
(@LibraryLaborerRef, 39681, 4, 1, 0, 2, 4), -- Handfull of copper bolts
(@LibraryLaborerRef, 49050, 1, 1, 0, 1, 1), -- jeeves
(@LibraryLaborerRef, 39686, 0.5, 1, 0, 1, 1), -- Frost steel Tube
(@LibraryLaborerRef, 39682, 0.5, 1, 0, 1, 1), -- Overcharged Capacitor
(@HallsofStoneRef, 41338, 43.5, 1, 0, 1, 3), -- Sprung Whirlygig
(@HallsofStoneRef, 41337, 42, 1, 0, 1, 3), -- Whizzed out Gizmo
(@HallsofStoneRef, 39690, 8, 1, 0, 1, 3), -- Volatile Blasting trigger
(@HallsofStoneRef, 39681, 5, 1, 0, 2, 4), -- Handfull of copper bolts
(@HallsofStoneRef, 49050, 0.5, 1, 0, 1, 1), -- jeeves
(@HallsofStoneRef, 39686, 0.5, 1, 0, 1, 1), -- Frost steel Tube
(@HallsofStoneRef, 39682, 0.5, 1, 0, 1, 1), -- Overcharged Capacitor
(@UldarBossRef, 35627, 43, 1, 0, 2, 10), -- Eternal Shadow
(@UldarBossRef, 35624, 42, 1, 0, 4, 10), -- Eternal Earth
(@UldarBossRef, 35623, 43, 1, 0, 2, 6), -- Eternal Air
(@UldarBossRef, 36860, 42, 1, 0, 2, 6), -- Eternal Fire
(@UldarBossRef, 39690, 30, 1, 0, 16, 19), -- Volatile Blasting trigger
(@UldarBossRef, 39686, 26, 1, 0, 2, 3), -- Frost steel Tube
(@UldarBossRef, 39682, 22, 1, 0, 5, 5), -- Overcharged Capacitor
(@UldarBossRef, 39681, 21, 1, 0, 8, 10), -- Handfull of copper bolts
(@UldarBossRef, 49050, 2, 1, 0, 1, 1); -- jeeves

UPDATE `creature_template` SET `skinloot`=@LibraryLaborer WHERE `entry` IN (29389,29724); -- Library Guardian and Mechagnome Laborer
UPDATE `creature_template` SET `skinloot`=@ReavandDispo WHERE `entry` IN (34273,34274,29382); -- Stromforged Reaver and XB-488 Disposalbot
UPDATE `creature_template` SET `skinloot`=@Dirkee WHERE `entry`=32500; -- Dirkee
UPDATE `creature_template` SET `skinloot`=@Recovery WHERE `entry` IN (34267,34268); -- Parts Recovery Technician
UPDATE `creature_template` SET `skinloot`=@AirStrip WHERE `entry` IN (32358,25792,25758,25752,25753,25814,25793); -- Fumblub Gearwind, Scavenge-bot 005-B6, Defendo-tank 66D, Scavenge-bot 004-A8, Sentry-bot 57-K, Fizzcrank Mechagnome, 55-D Collect-a-tron
UPDATE `creature_template` SET `skinloot`=@HallsofStone WHERE `entry` IN (27972,31383,27971,31387); -- Lightning Construct, Unrelenting Construct
UPDATE `creature_template` SET `skinloot`=@UldarBoss WHERE `entry` IN (34332,34106,33113,34003,33293,33885); -- Leviathan Mk II, Flame Leviathan, XT-002 Deconstructor
