-- http://www.wowwiki.com/Goblin_starting_experience

/*
 * First Island
 */

-- Don't Go Into the Light!
-- UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14239;
-- Goblin Escape Pods
UPDATE `quest_template` SET `PrevQuestId` = 14239 WHERE `Id`= 14001;
-- Get Our Stuff Back!
UPDATE `quest_template` SET `PrevQuestId` = 14001, `NextQuestId` = 14248, `ExclusiveGroup` = -14014 WHERE `Id`= 14014;
-- It's Our Problem Now
UPDATE `quest_template` SET `PrevQuestId` = 14001, `NextQuestId` = 14248, `ExclusiveGroup` = -14014 WHERE `Id`= 14473;
-- Monkey Business
UPDATE `quest_template` SET `PrevQuestId` = 14001, `NextQuestId` = 14248, `ExclusiveGroup` = -14014 WHERE `Id`= 14019;
-- Help Wanted
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 14248;
-- Miner Troubles
UPDATE `quest_template` SET `PrevQuestId` = 14248, `NextQuestId` = 14234, `ExclusiveGroup` = -14031 WHERE `Id`= 14021;
-- Capturing the Unknown
UPDATE `quest_template` SET `PrevQuestId` = 14248, `NextQuestId` = 14234, `ExclusiveGroup` = -14031 WHERE `Id`= 14031;
-- Orcs Can Write?
UPDATE `quest_template` SET `PrevQuestId` = 14248, `NextQuestId` = 14234, `ExclusiveGroup` = -14031 WHERE `Id`= 14233;
-- The Enemy of My Enemy
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 14234;
-- The Vicious Vale
UPDATE `quest_template` SET `PrevQuestId` = 14234 WHERE `Id`= 14235;
-- Weed Whacker
UPDATE `quest_template` SET `PrevQuestId` = 14235 WHERE `Id`= 14236;
-- Back to Aggra
UPDATE `quest_template` SET `PrevQuestId` = 14236 WHERE `Id`= 14303;
-- Forward Movement
UPDATE `quest_template` SET `PrevQuestId` = 14303 WHERE `Id`= 14237;
-- Infrared = Infradead
UPDATE `quest_template` SET `PrevQuestId` = 14237 WHERE `Id`= 14238;
-- To the Cliffs
UPDATE `quest_template` SET `PrevQuestId` = 14238 WHERE `Id`= 14240;
-- Get to the Gyrochoppa!
UPDATE `quest_template` SET `PrevQuestId` = 14240 WHERE `Id`= 14241;
-- Precious Cargo
UPDATE `quest_template` SET `PrevQuestId` = 14241 WHERE `Id`= 14242;
-- Meet Me Up Top
UPDATE `quest_template` SET `PrevQuestId` = 14242 WHERE `Id`= 14326;
-- Warchief's Revenge
UPDATE `quest_template` SET `PrevQuestId` = 14326 WHERE `Id`= 14243;
-- Farewell, For Now
UPDATE `quest_template` SET `PrevQuestId` = 14243 WHERE `Id`= 14445;
-- Up, Up & Away!
UPDATE `quest_template` SET `PrevQuestId` = 14445 WHERE `Id`= 14244;

/*
 * Town-In-A-Box
 */

-- It's a Town-In-A-Box
UPDATE `quest_template` SET `PrevQuestId` = 14244 WHERE `Id`= 14245;
-- Hobart Needs You
UPDATE `quest_template` SET `PrevQuestId` = 14245 WHERE `Id`= 27139;
-- Cluster Cluck
UPDATE `quest_template` SET `PrevQuestId` = 27139 WHERE `Id`= 24671;
-- Trading Up
UPDATE `quest_template` SET `PrevQuestId` = 24671 WHERE `Id`= 24741;
-- The Biggest Egg Ever
UPDATE `quest_template` SET `PrevQuestId` = 24741 WHERE `Id`= 24744;
-- Who's Top of the Food Chain Now?
UPDATE `quest_template` SET `PrevQuestId` = 24744 WHERE `Id`= 24816;
-- A Goblin in Shark's Clothing
UPDATE `quest_template` SET `PrevQuestId` = 24816 WHERE `Id`= 24817;
-- Invasion Imminent!
UPDATE `quest_template` SET `PrevQuestId` = 24817 WHERE `Id`= 24856;
-- Bilgewater Cartel Represent
UPDATE `quest_template` SET `PrevQuestId` = 24856, `NextQuestId` = 24864, `ExclusiveGroup` = -24858 WHERE `Id`= 24858; 
-- Naga Hide
UPDATE `quest_template` SET `PrevQuestId` = 24856, `NextQuestId` = 24864, `ExclusiveGroup` = -24858 WHERE `Id`= 24859; 
-- Irresistible Pool Pony
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 24864;
-- Surrender or Else!
UPDATE `quest_template` SET `PrevQuestId` = 24864 WHERE `Id`= 24868;
-- Get Back to Town
UPDATE `quest_template` SET `PrevQuestId` = 24868 WHERE `Id`= 24897;

/*
 * Pygmy mayhem
 */

-- Town-In-A-Box: Under Attack
UPDATE `quest_template` SET `PrevQuestId` = 24897 WHERE `Id`= 24901;
-- Oomlot Village
UPDATE `quest_template` SET `PrevQuestId` = 24901 WHERE `Id`= 24924;
-- Free the Captives
UPDATE `quest_template` SET `PrevQuestId` = 24924,`NextQuestId` = 24937, `ExclusiveGroup` = -24925 WHERE `Id`= 24925;
-- Send a Message
UPDATE `quest_template` SET `PrevQuestId` = 24924,`NextQuestId` = 24937, `ExclusiveGroup` = -24925 WHERE `Id`= 24929;
-- Oomlot Dealt With
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 24937;
-- Up the Volcano
UPDATE `quest_template` SET `PrevQuestId` = 24937 WHERE `Id`= 24940;
-- Zombies vs. Super Booster Rocket Boots
UPDATE `quest_template` SET `PrevQuestId` = 24940,`NextQuestId` = 24952, `ExclusiveGroup` = -24945 WHERE `Id`= 24942;
-- Three Little Pygmies
UPDATE `quest_template` SET `PrevQuestId` = 24940,`NextQuestId` = 24952, `ExclusiveGroup` = -24945 WHERE `Id`= 24945;
-- Rockin' Powder
UPDATE `quest_template` SET `PrevQuestId` = 24940,`NextQuestId` = 24952, `ExclusiveGroup` = -24945 WHERE `Id`= 24946;
-- Rocket Boot Boost
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 24952;
-- Children of a Turtle God
UPDATE `quest_template` SET `PrevQuestId` = 24952 WHERE `Id`= 24954;
-- Volcanoth!
UPDATE `quest_template` SET `PrevQuestId` = 24954 WHERE `Id`= 24958;
-- Old Friends
UPDATE `quest_template` SET `PrevQuestId` = 24958 WHERE `Id`= 25023;

/*
 * Warchief's Lookout
 */

-- Repel the Paratroopers
UPDATE `quest_template` SET `PrevQuestId` = 25023,`NextQuestId` = 25066, `ExclusiveGroup` = -25024 WHERE `Id`= 25024;
-- The Heads of the SI:7
UPDATE `quest_template` SET `PrevQuestId` = 25023,`NextQuestId` = 25066, `ExclusiveGroup` = -25024 WHERE `Id`= 25093;
-- Mine Disposal, the Goblin Way
UPDATE `quest_template` SET `PrevQuestId` = 25023,`NextQuestId` = 25066, `ExclusiveGroup` = -25024 WHERE `Id`= 25058;
-- The Pride of Kezan
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 25066;
-- The Warchief Wants You
UPDATE `quest_template` SET `PrevQuestId` = 25066 WHERE `Id`= 25098;
-- Borrow Bastia
UPDATE `quest_template` SET `PrevQuestId` = 25098 WHERE `Id`= 25099;
-- Let's Ride
UPDATE `quest_template` SET `PrevQuestId` = 25099 WHERE `Id`= 25100;
-- The Gallywix Labor Mine
UPDATE `quest_template` SET `PrevQuestId` = 25100 WHERE `Id`= 25109;
-- Kaja'Cola Gives You IDEAS! (TM)
UPDATE `quest_template` SET `PrevQuestId` = 25109 WHERE `Id`= 25110;
-- Morale Boost
UPDATE `quest_template` SET `PrevQuestId` = 25110,`NextQuestId` = 25125, `ExclusiveGroup` = -25122 WHERE `Id`= 25122;
-- Throw It On the Ground!
UPDATE `quest_template` SET `PrevQuestId` = 25110,`NextQuestId` = 25125, `ExclusiveGroup` = -25122 WHERE `Id`= 25123;
-- Light at the End of the Tunnel
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 25125;
-- Wild Mine Cart Ride
UPDATE `quest_template` SET `PrevQuestId` = 25125 WHERE `Id`= 25184;
-- Shredder Shutdown
UPDATE `quest_template` SET `PrevQuestId` = 25184,`NextQuestId` = 25204, `ExclusiveGroup` = -25200 WHERE `Id`= 25200;
-- The Ultimate Footbomb Uniform
UPDATE `quest_template` SET `PrevQuestId` = 25184,`NextQuestId` = 25204, `ExclusiveGroup` = -25200 WHERE `Id`= 25201;
-- Release the Valves
UPDATE `quest_template` SET `PrevQuestId` = 0 WHERE `Id`= 25204;
-- Good-bye, Sweet Oil
UPDATE `quest_template` SET `PrevQuestId` = 25204 WHERE `Id`= 25207;


-- The Slave Pits
UPDATE `quest_template` SET `PrevQuestId` = 25207 WHERE `Id`= 25213;


-- Final Confrontation
UPDATE `quest_template` SET `PrevQuestId` = 25207 WHERE `Id`= 25251;
-- Victory!
UPDATE `quest_template` SET `PrevQuestId` = 25251 WHERE `Id`= 25265;
-- Warchief's Emissary
UPDATE `quest_template` SET `PrevQuestId` = 25265 WHERE `Id`= 25266;
-- Message for Garrosh‎‎
UPDATE `quest_template` SET `PrevQuestId` = 25266 WHERE `Id`= 25267;
-- Report to the Labor Captain‎
UPDATE `quest_template` SET `PrevQuestId` = 25267 WHERE `Id`= 25275;
