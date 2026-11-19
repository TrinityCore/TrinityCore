-- Fix Creature Loot of Rare Elite Mobs in Northrend
UPDATE `creature_template` SET `lootid`=`entry` WHERE `entry` IN (32357,32358,32361,32400,32409,32417,32517,32485,32481,32377,32386,32398,32422,32429,32438,38453,32447,32471,32475,33776,32630,32500,32491,35189,32501,32495,32487);
-- Loot
DELETE FROM `creature_loot_template` WHERE `entry` IN (32357,32358,32361,32400,32409,32417,32517,32485,32481,32377,32386,32398,32422,32429,32438,38453,32447,32471,32475,33776,32630,32500,32491,35189,32501,32495,32487);
INSERT INTO `creature_loot_template`
 (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`)
 VALUES
-- Old Crystalbark
(32357,44649,100,1,0,1,1), -- Crystalbark's Toenail
(32357,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Fumblub Gearwind
(32358,44666,100,1,0,1,1), -- Fumblub's Seat Cushion
(32358,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Icehorn
(32361,44667,100,1,0,1,1), -- Mammoth-Hair Crown
(32361,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Tukemuth
(32400,44673,100,1,0,1,1), -- Mammoth-Riding Boots
(32400,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
(32400,42104,-33,1,0,1,1), -- QUEST: Northern Ivory
-- Crazed Indu'le Survivor
(32409,44672,100,1,0,1,1), -- Seal-Fur Spaulders
(32409,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Scarlet Highlord Daion
(32417,44671,100,1,0,1,1), -- Highlord's Padded Legguards
(32417,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Loque'nahak
(32517,44688,75,1,1,1,1), -- Loque'Nahak's Severed Fang (GROUP 1)
(32517,44687,25,1,1,1,1), -- Loque'Nahak's Pelt(GROUP 1)
(32517,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- King Krush
(32485,44683,100,1,0,1,1), -- King's Eyesocket
(32485,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Aotona
(32481,44691,100,1,0,1,1), -- Aotona's Collar
(32481,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Perobas the Bloodthirster
(32377,44669,100,1,0,1,1), -- Worgen-Scored Shackles
(32377,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Vigdis die Kriegsmaid
(32386,44670,100,1,0,1,1), -- Soul-Sealed Belt
(32386,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- King Ping
(32398,44668,100,1,0,1,1), -- Egg-Warming Blanket
(32398,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Grocklar
(32422,44675,100,1,0,1,1), -- Rock-Giant's Pinky Cover
(32422,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Seething Hate
(32429,44674,100,1,0,1,1), -- Ichor-Stained Wraps
(32429,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Syreian the Bonecarver
(32438,44676,100,1,0,1,1), -- Syreian's Leggings
(32438,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Arcturis
(38453,51958,100,1,0,1,1), -- Pristine Glowbear Pelt
(38453,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Zul'drak Sentinel
(32447,44677,100,1,0,1,1), -- Eternal Observer's Legplates
(32447,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Griegen
(32471,44686,100,1,0,1,1), -- Ethereal Terror Handwraps
(32471,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Terror Spinner
(32475,44685,100,1,0,1,1), -- Calcified Web Spaulders
(32475,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Gondria
(33776,46324,100,1,0,1,1), -- Gondria's Spectral Claw
(33776,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Vyragosa
(32630,44732,100,1,0,1,1), -- Azure Dragonleather Helm
(32630,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Dirkee
(32500,44681,85,1,1,1,1), -- Titanium Brain-Gear (GROUP 1)
(32500,44708,15,1,1,1,1), -- Dirkee's Superstructure (GROUP 1)
(32500,44663,100,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Time-Lost Proto Drake
(32491,44682,99,1,0,1,1), -- Time-Forward Talisman
(32491,44168,99,1,0,1,1), -- Reins of the Time-Lost Proto-Drake
(32491,44663,99,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Skoll
(35189,49227,98,1,0,1,1), -- Skoll's Fang
(35189,44663,99,1,0,1,1), -- Abandoned Adventurer's Satchel
-- High Thane Jorfus
(32501,44695,99,1,0,1,1), -- Corroded Faceguard
(32501,44663,96,1,0,1,1), -- Abandoned Adventurer's Satchel
(32501,41989,-33,1,0,1,1), -- QUEST: Vrykul Amulet
-- Hildana Deathstealer
(32495,44697,99,1,0,1,1), -- Val'kyr Vestments
(32495,44663,96,1,0,1,1), -- Abandoned Adventurer's Satchel
-- Putridus the Ancient
(32487,44696,98,1,0,1,1), -- Giant's Toewrap
(32487,44663,93,1,0,1,1); -- Abandoned Adventurer's Satchel
