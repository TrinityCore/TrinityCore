--
SET @RidingLowlevel := 202010;
SET @RidingMedlevel := 202011;
SET @RidingHighlevel := 202012;

SET @RidingSkill := 762;
SET @ApprenticeRiding := 33389;
SET @JourneymanRiding := 33392;
SET @ExpertRiding := 34092;
SET @ArtisanRiding := 34093;
SET @ColdWeatherFlying := 54198;
SET @FlightMastersLicense := 90267;
SET @WisdomOfTheFourWinds := 115913;
SET @MasterRiding := 90266;

DELETE FROM `npc_trainer` WHERE `ID` IN (@RidingLowlevel,@RidingMedlevel,@RidingHighlevel);
DELETE FROM `npc_trainer` WHERE `SpellID` IN (-@RidingLowlevel,-@RidingMedlevel,-@RidingHighlevel);

INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
-- Riding Low Level
(@RidingLowlevel,@ApprenticeRiding,40000,0,0,20), -- Spell Apprentice Riding
(@RidingLowlevel,@JourneymanRiding,500000,@RidingSkill,75,40), -- Spell Journeyman Riding
-- Riding Med Level
(@RidingMedlevel,@ApprenticeRiding,40000,0,0,20), -- Spell Aprentice Riding
(@RidingMedlevel,@JourneymanRiding,500000,@RidingSkill,75,40), -- Spell Journeyman Riding
(@RidingMedlevel,@ExpertRiding,2500000,@RidingSkill,150,60), -- Spell Expert Riding
(@RidingMedlevel,@ArtisanRiding,50000000,@RidingSkill,225,70), -- Spell Artisan Riding
(@RidingMedlevel,@ColdWeatherFlying,5000000,@RidingSkill,225,68), -- Spell Cold Weather Flying
(@RidingMedlevel,@FlightMastersLicense,2500000,@RidingSkill,225,60), -- Spell Flight Master's License
(@RidingMedlevel,@MasterRiding,50000000,@RidingSkill,300,80), -- Spell Master Riding
-- Riding High Level
(@RidingHighlevel,@ApprenticeRiding,40000,0,0,20), -- Spell Aprentice Riding
(@RidingHighlevel,@JourneymanRiding,500000,@RidingSkill,75,40), -- Spell Journeyman Riding
(@RidingHighlevel,@ExpertRiding,2500000,@RidingSkill,150,60), -- Spell Expert Riding
(@RidingHighlevel,@ArtisanRiding,50000000,@RidingSkill,225,70), -- Spell Artisan Riding
(@RidingHighlevel,@ColdWeatherFlying,5000000,@RidingSkill,225,68), -- Spell Cold Weather Flying
(@RidingHighlevel,@FlightMastersLicense,2500000,@RidingSkill,225,60), -- Spell Flight Master's License
(@RidingHighlevel,@MasterRiding,50000000,@RidingSkill,300,80), -- Spell Master Riding
(@RidingHighlevel,@WisdomOfTheFourWinds,25000000,@RidingSkill,225,85), -- Spell Wisdom of the Four Winds
-- Trainer
(60166,-@RidingHighlevel,0,0,0,0), -- Trainer Cloudrunner Leng - Vale of Eternal Blossoms
(60167,-@RidingHighlevel,0,0,0,0), -- Trainer Skydancer Shun - Vale of Eternal Blossom
(43769,-@RidingHighlevel,0,0,0,0), -- Trainer Bralla Cloudwing - Stormwind City
(43693,-@RidingHighlevel,0,0,0,0), -- Trainer Darlene Stokx - Stormwind City
(35100,-@RidingHighlevel,0,0,0,0), -- Trainer Hargen Bronzewing - Hellfire Peninsula
(31238,-@RidingHighlevel,0,0,0,0), -- Trainer Hira Snowdawn - Dalaran
(20511,-@RidingHighlevel,0,0,0,0), -- Trainer Ilsa Blusterbrew - Shadowmoon Valley
(35133,-@RidingHighlevel,0,0,0,0), -- Trainer Maigra Keenfeather - Borean Tundra
(44919,-@RidingHighlevel,0,0,0,0), -- Trainer Maztha - Orgrimmar
(20500,-@RidingHighlevel,0,0,0,0), -- Trainer Olrokk - Shadowmoon Valley
(28746,-@RidingHighlevel,0,0,0,0), -- Trainer Pilot Vic - Sholazar Basin
(31247,-@RidingHighlevel,0,0,0,0), -- Trainer Roxi Ramrocket - The Storm Peaks
(35093,-@RidingHighlevel,0,0,0,0), -- Trainer Wind Rider Jahubo - Hellfire Peninsula
(35135,-@RidingHighlevel,0,0,0,0), -- Trainer Wind Rider Sabamba - Borean Tundra
(20914,-@RidingHighlevel,0,0,0,0), -- Trainer Aalun - The Exodar
(7954,-@RidingHighlevel,0,0,0,0), -- Trainer Binjy Featherwhistle - Dun Morogh
(4753,-@RidingHighlevel,0,0,0,0), -- Trainer Jartsam - Darnassus
(3690,-@RidingHighlevel,0,0,0,0), -- Trainer Kar Stormsinger - Mulgore
(4752,-@RidingHighlevel,0,0,0,0), -- Trainer Kildar - Orgrimmar
(70296,-@RidingHighlevel,0,0,0,0), -- Trainer Mei Lin - Stormwind City
(16280,-@RidingHighlevel,0,0,0,0), -- Trainer Perascamin - Everson Woods
(4732,-@RidingHighlevel,0,0,0,0), -- Trainer Randal Hunter - Elwynn Forest
(48513,-@RidingHighlevel,0,0,0,0), -- Trainer Revi Ramrod - Orgrimmar
(53407,-@RidingHighlevel,0,0,0,0), -- Trainer Sansha MacVince - Dustwallow Marsh
(70301,-@RidingHighlevel,0,0,0,0), -- Trainer Softpaws - Orgrimmar
(4772,-@RidingHighlevel,0,0,0,0), -- Trainer Ultham Ironhorn - Dun Morogh
(4773,-@RidingHighlevel,0,0,0,0), -- Trainer Velma Warnam - Tirisfal Glades
(7953,-@RidingHighlevel,0,0,0,0); -- Trainer Xar'Ti - Durotar
