-- Clean up some duplicate spawns
DELETE FROM `creature` WHERE `guid` IN (376609, 376563, 376561, 376532, 376521, 376575);
DELETE FROM `creature_addon` WHERE `guid` IN (376609, 376397,376563, 376561, 376532, 376521, 376575);

-- Creature Rampaging Worgen 35660 SAI
SET @ENTRY := 35660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell 8599 on Self // Rampaging Worgen - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Rampaging Worgen - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 3, 0, 1, 0, 100, 1, 60000, 60000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 60000 and 60000 ms (and later repeats every 0 and 0 ms) - Self: Despawn instantly // "),
(@ENTRY, 0, 4, 0, 1, 0, 100, 1, 3000, 3000, 0, 0, 29, 0, 0, 0, 0, 0, 0, 11, 35830, 15, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3000 and 3000 ms (and later repeats every 0 and 0 ms) - Self: Follow Creature Gilneas Evacuation Facing Marker (First) (35830) in 15 yd by distance 0, angle 0 // "),
(@ENTRY, 0, 5, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 4000 and 4000 ms (and later repeats every 0 and 0 ms) - Self: Set react state to REACT_AGGRESSIVE // ");

UPDATE `gameobject_template_addon` SET `flags`= 4 WHERE `entry`= 195327;

DELETE FROM `quest_poi` WHERE (`QuestID`=24676 AND `id`=3) OR (`QuestID`=24676 AND `id`=2) OR (`QuestID`=24676 AND `id`=1) OR (`QuestID`=24676 AND `id`=0) OR (`QuestID`=24674 AND `id`=1) OR (`QuestID`=24674 AND `id`=0) OR (`QuestID`=24675 AND `id`=2) OR (`QuestID`=24675 AND `id`=1) OR (`QuestID`=24675 AND `id`=0) OR (`QuestID`=24575 AND `id`=2) OR (`QuestID`=24575 AND `id`=1) OR (`QuestID`=24575 AND `id`=0) OR (`QuestID`=24677 AND `id`=0) OR (`QuestID`=24592 AND `id`=2) OR (`QuestID`=24592 AND `id`=1) OR (`QuestID`=24592 AND `id`=0) OR (`QuestID`=24672 AND `id`=0) OR (`QuestID`=24673 AND `id`=0) OR (`QuestID`=24593 AND `id`=3) OR (`QuestID`=24593 AND `id`=2) OR (`QuestID`=24593 AND `id`=1) OR (`QuestID`=24593 AND `id`=0) OR (`QuestID`=24646 AND `id`=1) OR (`QuestID`=24646 AND `id`=0) OR (`QuestID`=24628 AND `id`=1) OR (`QuestID`=24628 AND `id`=0) OR (`QuestID`=24627 AND `id`=1) OR (`QuestID`=24627 AND `id`=0) OR (`QuestID`=24617 AND `id`=0) OR (`QuestID`=24616 AND `id`=1) OR (`QuestID`=24616 AND `id`=0) OR (`QuestID`=24578 AND `id`=0) OR (`QuestID`=24501 AND `id`=1) OR (`QuestID`=24501 AND `id`=0) OR (`QuestID`=24495 AND `id`=3) OR (`QuestID`=24495 AND `id`=2) OR (`QuestID`=24495 AND `id`=1) OR (`QuestID`=24495 AND `id`=0) OR (`QuestID`=24484 AND `id`=1) OR (`QuestID`=24484 AND `id`=0) OR (`QuestID`=24483 AND `id`=0) OR (`QuestID`=24472 AND `id`=2) OR (`QuestID`=24472 AND `id`=1) OR (`QuestID`=24472 AND `id`=0) OR (`QuestID`=24468 AND `id`=1) OR (`QuestID`=24468 AND `id`=0) OR (`QuestID`=24438 AND `id`=0) OR (`QuestID`=14466 AND `id`=0) OR (`QuestID`=14465 AND `id`=0) OR (`QuestID`=14463 AND `id`=0) OR (`QuestID`=14405 AND `id`=0) OR (`QuestID`=14402 AND `id`=0) OR (`QuestID`=14401 AND `id`=1) OR (`QuestID`=14401 AND `id`=0) OR (`QuestID`=14400 AND `id`=1) OR (`QuestID`=14400 AND `id`=0) OR (`QuestID`=14399 AND `id`=1) OR (`QuestID`=14399 AND `id`=0) OR (`QuestID`=14412 AND `id`=1) OR (`QuestID`=14412 AND `id`=0) OR (`QuestID`=14404 AND `id`=3) OR (`QuestID`=14404 AND `id`=2) OR (`QuestID`=14404 AND `id`=1) OR (`QuestID`=14404 AND `id`=0) OR (`QuestID`=14416 AND `id`=1) OR (`QuestID`=14416 AND `id`=0) OR (`QuestID`=14406 AND `id`=0) OR (`QuestID`=14403 AND `id`=0) OR (`QuestID`=14398 AND `id`=0) OR (`QuestID`=14397 AND `id`=0) OR (`QuestID`=14395 AND `id`=1) OR (`QuestID`=14395 AND `id`=0) OR (`QuestID`=14396 AND `id`=0) OR (`QuestID`=14386 AND `id`=1) OR (`QuestID`=14386 AND `id`=0) OR (`QuestID`=14368 AND `id`=3) OR (`QuestID`=14368 AND `id`=2) OR (`QuestID`=14368 AND `id`=1) OR (`QuestID`=14368 AND `id`=0) OR (`QuestID`=14382 AND `id`=2) OR (`QuestID`=14382 AND `id`=1) OR (`QuestID`=14382 AND `id`=0) OR (`QuestID`=14369 AND `id`=1) OR (`QuestID`=14369 AND `id`=0) OR (`QuestID`=14367 AND `id`=0) OR (`QuestID`=14366 AND `id`=0) OR (`QuestID`=14347 AND `id`=1) OR (`QuestID`=14347 AND `id`=0) OR (`QuestID`=14348 AND `id`=1) OR (`QuestID`=14348 AND `id`=0) OR (`QuestID`=14336 AND `id`=0) OR (`QuestID`=14321 AND `id`=0) OR (`QuestID`=14320 AND `id`=0) OR (`QuestID`=14313 AND `id`=0) OR (`QuestID`=14222 AND `id`=1) OR (`QuestID`=14222 AND `id`=0) OR (`QuestID`=14221 AND `id`=0) OR (`QuestID`=14218 AND `id`=7) OR (`QuestID`=14218 AND `id`=6) OR (`QuestID`=14218 AND `id`=5) OR (`QuestID`=14218 AND `id`=4) OR (`QuestID`=14218 AND `id`=3) OR (`QuestID`=14218 AND `id`=2) OR (`QuestID`=14218 AND `id`=1) OR (`QuestID`=14218 AND `id`=0) OR (`QuestID`=14212 AND `id`=0) OR (`QuestID`=14294 AND `id`=0) OR (`QuestID`=14293 AND `id`=1) OR (`QuestID`=14293 AND `id`=0) OR (`QuestID`=14214 AND `id`=0) OR (`QuestID`=14204 AND `id`=1) OR (`QuestID`=14204 AND `id`=0) OR (`QuestID`=14159 AND `id`=0) OR (`QuestID`=26129 AND `id`=0) OR (`QuestID`=14154 AND `id`=1) OR (`QuestID`=14154 AND `id`=0) OR (`QuestID`=28850 AND `id`=0) OR (`QuestID`=24930 AND `id`=2) OR (`QuestID`=24930 AND `id`=1) OR (`QuestID`=24930 AND `id`=0) OR (`QuestID`=14157 AND `id`=0) OR (`QuestID`=14286 AND `id`=0) OR (`QuestID`=14265 AND `id`=0) OR (`QuestID`=14099 AND `id`=0) OR (`QuestID`=14094 AND `id`=3) OR (`QuestID`=14094 AND `id`=2) OR (`QuestID`=14094 AND `id`=1) OR (`QuestID`=14094 AND `id`=0) OR (`QuestID`=14098 AND `id`=2) OR (`QuestID`=14098 AND `id`=1) OR (`QuestID`=14098 AND `id`=0) OR (`QuestID`=14093 AND `id`=3) OR (`QuestID`=14093 AND `id`=2) OR (`QuestID`=14093 AND `id`=1) OR (`QuestID`=14093 AND `id`=0) OR (`QuestID`=14091 AND `id`=0) OR (`QuestID`=14078 AND `id`=0) OR (`QuestID`=31814 AND `id`=2) OR (`QuestID`=31814 AND `id`=1) OR (`QuestID`=31814 AND `id`=0);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(24676, 3, -1, 654, 545, 0, 0, 1, 25383), -- Push Them Out
(24676, 2, 0, 654, 545, 0, 0, 1, 25383), -- Push Them Out
(24676, 1, 0, 654, 545, 0, 0, 1, 25383), -- Push Them Out
(24676, 0, 0, 654, 545, 0, 0, 1, 25383), -- Push Them Out
(24674, 1, -1, 654, 545, 0, 0, 1, 25383), -- Slaves to No One
(24674, 0, 0, 654, 545, 0, 0, 1, 25383), -- Slaves to No One
(24675, 2, -1, 654, 545, 0, 0, 1, 25383), -- Last Meal
(24675, 1, 0, 654, 545, 0, 0, 1, 25383), -- Last Meal
(24675, 0, 0, 654, 545, 0, 0, 1, 25383), -- Last Meal
(24575, 2, -1, 654, 545, 0, 0, 1, 25383), -- Liberation Day
(24575, 1, 27, 654, 545, 0, 0, 1, 25383), -- Liberation Day
(24575, 0, 0, 654, 545, 0, 0, 1, 25383), -- Liberation Day
(24677, 0, -1, 654, 545, 0, 0, 1, 25383), -- Flank the Forsaken
(24592, 2, -1, 654, 545, 0, 0, 1, 25383), -- Betrayal at Tempest's Reach
(24592, 1, 0, 654, 545, 0, 0, 1, 25383), -- Betrayal at Tempest's Reach
(24592, 0, 0, 654, 545, 0, 0, 1, 25383), -- Betrayal at Tempest's Reach
(24672, 0, -1, 654, 545, 0, 0, 1, 25383), -- Onwards and Upwards
(24673, 0, -1, 654, 545, 0, 0, 1, 25383), -- Return to Stormglen
(24593, 3, -1, 654, 545, 0, 0, 1, 25383), -- Neither Human Nor Beast
(24593, 2, 0, 654, 545, 0, 0, 1, 25383), -- Neither Human Nor Beast
(24593, 1, 0, 654, 545, 0, 0, 1, 25383), -- Neither Human Nor Beast
(24593, 0, 0, 654, 545, 0, 0, 1, 25383), -- Neither Human Nor Beast
(24646, 1, -1, 654, 545, 0, 0, 1, 25383), -- Take Back What's Ours
(24646, 0, 0, 654, 545, 0, 0, 1, 25383), -- Take Back What's Ours
(24628, 1, -1, 654, 545, 0, 0, 1, 25383), -- Preparations
(24628, 0, 0, 654, 545, 0, 0, 1, 25383), -- Preparations
(24627, 1, -1, 654, 545, 0, 0, 1, 25383), -- At Our Doorstep
(24627, 0, 0, 654, 545, 0, 0, 1, 25383), -- At Our Doorstep
(24617, 0, -1, 654, 545, 0, 0, 1, 25383), -- Tal'doren, the Wild Home
(24616, 1, 0, 654, 545, 0, 0, 1, 25383), -- Losing Your Tail
(24616, 0, -1, 654, 545, 0, 0, 1, 25383), -- Losing Your Tail
(24578, 0, -1, 654, 545, 0, 0, 1, 25383), -- The Blackwald
(24501, 1, -1, 654, 545, 0, 0, 1, 25383), -- Queen-Sized Troubles
(24501, 0, 0, 654, 545, 0, 0, 1, 25383), -- Queen-Sized Troubles
(24495, 3, -1, 654, 545, 0, 0, 1, 25383), -- Pieces of the Past
(24495, 2, 0, 654, 545, 0, 0, 1, 25383), -- Pieces of the Past
(24495, 1, -1, 638, 539, 0, 0, 1, 25383), -- Pieces of the Past
(24495, 0, 0, 638, 539, 0, 0, 1, 25383), -- Pieces of the Past
(24484, 1, -1, 654, 545, 0, 0, 1, 25383), -- Pest Control
(24484, 0, 0, 654, 545, 0, 0, 1, 25383), -- Pest Control
(24483, 0, -1, 654, 545, 0, 0, 1, 25383), -- Stormglen
(24472, 2, -1, 654, 545, 0, 0, 1, 25383), -- Introductions Are in Order
(24472, 1, 0, 654, 545, 0, 0, 1, 25383), -- Introductions Are in Order
(24472, 0, 0, 654, 545, 0, 0, 1, 25383), -- Introductions Are in Order
(24468, 1, 0, 654, 545, 0, 0, 7, 25383), -- Stranded at the Marsh
(24468, 0, -1, 654, 545, 0, 0, 1, 25383), -- Stranded at the Marsh
(24438, 0, -1, 654, 545, 0, 0, 1, 25383), -- Exodus
(14466, 0, -1, 654, 545, 0, 0, 1, 25383), -- The King's Observatory
(14465, 0, -1, 654, 545, 0, 0, 1, 25383), -- To Greymane Manor
(14463, 0, -1, 654, 545, 0, 0, 1, 25383), -- Horses for Duskhaven
(14405, 0, -1, 654, 545, 0, 0, 1, 25383), -- Escape By Sea
(14402, 0, -1, 654, 545, 0, 0, 1, 25383), -- Ready to Go
(14401, 1, -1, 654, 545, 0, 0, 7, 25383), -- Grandma's Cat
(14401, 0, 0, 654, 545, 0, 0, 1, 25383), -- Grandma's Cat
(14400, 1, -1, 654, 545, 0, 0, 7, 25383), -- I Can't Wear This
(14400, 0, 0, 654, 545, 0, 0, 1, 25383), -- I Can't Wear This
(14399, 1, -1, 654, 545, 0, 0, 7, 25383), -- Grandma's Lost It Alright
(14399, 0, 0, 654, 545, 0, 0, 1, 25383), -- Grandma's Lost It Alright
(14412, 1, -1, 654, 545, 0, 0, 1, 25383), -- Washed Up
(14412, 0, 0, 654, 545, 0, 0, 1, 25383), -- Washed Up
(14404, 3, -1, 654, 545, 0, 0, 1, 25383), -- Not Quite Shipshape
(14404, 2, 0, 654, 545, 0, 0, 1, 25383), -- Not Quite Shipshape
(14404, 1, 0, 654, 545, 0, 0, 1, 25383), -- Not Quite Shipshape
(14404, 0, 0, 654, 545, 0, 0, 1, 25383), -- Not Quite Shipshape
(14416, 1, -1, 654, 545, 0, 0, 1, 25383), -- The Hungry Ettin
(14416, 0, 0, 654, 545, 0, 0, 1, 25383), -- The Hungry Ettin
(14406, 0, -1, 654, 545, 0, 0, 1, 25383), -- The Crowley Orchard
(14403, 0, -1, 654, 545, 0, 0, 1, 25383), -- The Hayward Brothers
(14398, 0, -1, 654, 678, 0, 0, 7, 25383), -- Grandma Wahl
(14397, 0, -1, 654, 545, 0, 0, 1, 25383), -- Evacuation
(14395, 1, 0, 654, 545, 0, 0, 1, 25383), -- Gasping for Breath
(14395, 0, -1, 654, 545, 0, 0, 1, 25383), -- Gasping for Breath
(14396, 0, -1, 654, 545, 0, 0, 1, 25383), -- As the Land Shatters
(14386, 1, -1, 654, 545, 0, 0, 1, 25383), -- Leader of the Pack
(14386, 0, 0, 654, 545, 0, 0, 1, 25383), -- Leader of the Pack
(14368, 3, -1, 654, 545, 0, 0, 1, 25383), -- Save the Children!
(14368, 2, 0, 654, 545, 0, 0, 1, 25383), -- Save the Children!
(14368, 1, 0, 654, 545, 0, 0, 1, 25383), -- Save the Children!
(14368, 0, 0, 654, 545, 0, 0, 1, 25383), -- Save the Children!
(14382, 2, -1, 654, 545, 0, 0, 1, 25383), -- Two By Sea
(14382, 1, 0, 654, 545, 0, 0, 1, 25383), -- Two By Sea
(14382, 0, 0, 654, 545, 0, 0, 1, 25383), -- Two By Sea
(14369, 1, -1, 654, 545, 0, 0, 1, 25383), -- Unleash the Beast
(14369, 0, 0, 654, 545, 0, 0, 1, 25383), -- Unleash the Beast
(14367, 0, -1, 654, 545, 0, 0, 1, 25383), -- The Allens' Storm Cellar
(14366, 0, -1, 654, 545, 0, 0, 1, 25383), -- Holding Steady
(14347, 1, -1, 654, 545, 0, 0, 1, 25383), -- Hold the Line
(14347, 0, 0, 654, 545, 0, 0, 1, 25383), -- Hold the Line
(14348, 1, -1, 654, 545, 0, 0, 1, 25383), -- You Can't Take 'Em Alone
(14348, 0, 26, 654, 545, 0, 0, 1, 25383), -- You Can't Take 'Em Alone
(14336, 0, -1, 654, 545, 0, 0, 1, 25383), -- Kill or Be Killed
(14321, 0, -1, 654, 545, 0, 0, 1, 25383), -- Invasion
(14320, 0, -1, 654, 545, 0, 0, 1, 25383), -- In Need of Ingredients
(14313, 0, -1, 654, 545, 0, 0, 1, 25383), -- Among Humans Again
(14222, 1, -1, 654, 545, 0, 0, 1, 25383), -- Last Stand
(14222, 0, 0, 654, 545, 0, 0, 1, 25383), -- Last Stand
(14221, 0, -1, 654, 545, 0, 0, 1, 25383), -- Never Surrender, Sometimes Retreat
(14218, 7, -1, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 6, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 5, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 4, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 3, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 2, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 1, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14218, 0, 0, 654, 611, 0, 0, 1, 25383), -- By Blood and Ash
(14212, 0, -1, 654, 545, 0, 0, 1, 25383), -- Sacrifices
(14294, 0, -1, 654, 545, 0, 0, 1, 25383), -- Time to Regroup
(14293, 1, 0, 654, 611, 0, 0, 1, 25383), -- Save Krennan Aranas
(14293, 0, -1, 654, 611, 0, 0, 1, 25383), -- Save Krennan Aranas
(14214, 0, -1, 654, 545, 0, 0, 1, 25383), -- Message to Greymane
(14204, 1, -1, 654, 545, 0, 0, 1, 25383), -- From the Shadows
(14204, 0, 0, 654, 545, 0, 0, 1, 25383), -- From the Shadows
(14159, 0, -1, 654, 545, 0, 0, 1, 25383), -- The Rebel Lord's Arsenal
(26129, 0, -1, 654, 545, 0, 0, 1, 25383), -- Brothers In Arms
(14154, 1, 30, 654, 545, 0, 0, 7, 25383), -- By the Skin of His Teeth
(14154, 0, -1, 654, 545, 0, 0, 3, 25383), -- By the Skin of His Teeth
(28850, 0, -1, 654, 611, 0, 0, 1, 25383), -- The Prison Rooftop
(24930, 2, -1, 654, 545, 0, 0, 1, 25383), -- While You're At It
(24930, 1, 0, 654, 545, 0, 0, 1, 25383), -- While You're At It
(24930, 0, 0, 638, 539, 0, 0, 1, 25383), -- While You're At It
(14157, 0, -1, 654, 611, 0, 0, 3, 25383), -- Old Divisions
(14286, 0, -1, 654, 545, 0, 0, 1, 25383), -- Safety in Numbers
(14265, 0, -1, 654, 545, 0, 0, 1, 25383), -- Your Instructor
(14099, 0, -1, 654, 545, 0, 0, 1, 25383), -- Royal Orders
(14094, 3, -1, 654, 545, 0, 0, 1, 25383), -- Salvage the Supplies
(14094, 2, 0, 654, 545, 0, 0, 1, 25383), -- Salvage the Supplies
(14094, 1, -1, 638, 539, 0, 0, 1, 25383), -- Salvage the Supplies
(14094, 0, 0, 638, 539, 0, 0, 1, 25383), -- Salvage the Supplies
(14098, 2, -1, 654, 611, 0, 0, 1, 25383), -- Evacuate the Merchant Square
(14098, 1, 0, 654, 545, 0, 0, 3, 25383), -- Evacuate the Merchant Square
(14098, 0, 0, 654, 545, 0, 0, 3, 25383), -- Evacuate the Merchant Square
(14093, 3, -1, 654, 545, 0, 0, 1, 25383), -- All Hell Breaks Loose
(14093, 2, 0, 654, 545, 0, 0, 1, 25383), -- All Hell Breaks Loose
(14093, 1, -1, 638, 539, 0, 0, 1, 25383), -- All Hell Breaks Loose
(14093, 0, 0, 638, 539, 0, 0, 3, 25383), -- All Hell Breaks Loose
(14091, 0, -1, 654, 545, 0, 0, 1, 25383), -- Something's Amiss
(14078, 0, -1, 654, 611, 0, 0, 1, 25383), -- Lockdown!
(31814, 2, 32, 1, 11, 0, 0, 0, 25383), -- Analynn
(31814, 1, 0, 1, 43, 0, 0, 0, 25383), -- Analynn
(31814, 0, -1, 1, 43, 0, 0, 0, 25383); -- Analynn

UPDATE `quest_offer_reward` SET `RewardText`='You''ve done it again, $n.  The freed villagers are eager to help us against the Forsaken in any way they can.', `VerifiedBuild`=25383 WHERE `ID`=24575; -- Liberation Day
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $n.  Our people will no longer suffer under that monstrosity''s yoke.', `VerifiedBuild`=25383 WHERE `ID`=24674; -- Slaves to No One
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $n.  Our men and women will have a last good meal before they set off for battle.', `VerifiedBuild`=25383 WHERE `ID`=24675; -- Last Meal
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='I am glad to have you here, $n.  We''re surrounded by Forsaken on all sides and can use all the help we can get.', `VerifiedBuild`=25383 WHERE `ID`=24677; -- Flank the Forsaken
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='I wish it could''ve been avoided, $n.  Let us ensure this is resolved without further bloodshed.', `VerifiedBuild`=25383 WHERE `ID`=24592; -- Betrayal at Tempest's Reach
UPDATE `quest_offer_reward` SET `RewardText`='$n!$B$BGenn... they''ve taken Genn... they''ve taken... our king!', `VerifiedBuild`=25383 WHERE `ID`=24672; -- Onwards and Upwards
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=24673; -- Return to Stormglen
UPDATE `quest_offer_reward` SET `RewardText`='It is done then, $n.  You are one of us now.', `VerifiedBuild`=25383 WHERE `ID`=24593; -- Neither Human Nor Beast
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='I knew we could count on you.  You''ve done well, $n.', `VerifiedBuild`=25383 WHERE `ID`=24646; -- Take Back What's Ours
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=25383 WHERE `ID`=24628; -- Preparations
UPDATE `quest_offer_reward` SET `RewardText`='You are as good as I remember, $n.  It is good to have you back.', `VerifiedBuild`=25383 WHERE `ID`=24627; -- At Our Doorstep
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You''re all right, $n!  I''ve been waiting for this day for a long time, it truly is great to see you friend.$B$BI''ve heard of what you''ve done and I''m thankful... especially for Lorna -- she''s all I''ve left.  I will send for her right away.', `VerifiedBuild`=25383 WHERE `ID`=24617; -- Tal'doren, the Wild Home
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `RewardText`='Well done, $n.  The scout never had a chance.', `VerifiedBuild`=25383 WHERE `ID`=24616; -- Losing Your Tail
UPDATE `quest_offer_reward` SET `RewardText`='I''ve been expecting you, $n.  Do not be alarmed.$B$BMy name is Belysra .  I am a priestess of the moon... a night elf.$B$BYou might not know my people, but the destinies of our two races have been linked since the Curse befell you.', `VerifiedBuild`=25383 WHERE `ID`=24578; -- The Blackwald
UPDATE `quest_offer_reward` SET `RewardText`='Great job, $n.  We''ve heard rumors of survivors further in the mountains.  Now we''ll be able to send scouts there.', `VerifiedBuild`=25383 WHERE `ID`=24501; -- Queen-Sized Troubles
UPDATE `quest_offer_reward` SET `RewardText`='You''ve done well, $n.  The spiders are everywhere, however, and I''m afraid we''ve barely put a dent in their numbers.', `VerifiedBuild`=25383 WHERE `ID`=24484; -- Pest Control
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $n.  It will take some time, but I''ll try to make sense of what we have.', `VerifiedBuild`=25383 WHERE `ID`=24495; -- Pieces of the Past
UPDATE `quest_offer_reward` SET `RewardText`='It''s good to see you made it, $n.  It looks like most everybody did.$B$BWe''re not doing too bad so far for an emergency evacuation.', `VerifiedBuild`=25383 WHERE `ID`=24483; -- Stormglen
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `RewardText`='You definitely got the ettin angry, $n.   I heard him myself.$B$BLet''s hope this works.', `VerifiedBuild`=25383 WHERE `ID`=24472; -- Introductions Are in Order
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You''ve done it again, $n.  You have my thanks.', `VerifiedBuild`=25383 WHERE `ID`=24468; -- Stranded at the Marsh
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25, `RewardText`='Thanks for stopping, $n.  Our carriage got hit pretty bad.$B$BThe one in front of us got it worse.', `VerifiedBuild`=25383 WHERE `ID`=24438; -- Exodus
UPDATE `quest_offer_reward` SET `RewardText`='Look, $n!  Look at what''s become of Duskhaven!$B$BLook at what''s become of the last safe place in Gilneas!', `VerifiedBuild`=25383 WHERE `ID`=14467; -- Alas, Gilneas!
UPDATE `quest_offer_reward` SET `RewardText`='There you are, $n.  I''ve been expecting you.$B$BI got word of your recovery and... wait -- do you feel that?', `VerifiedBuild`=25383 WHERE `ID`=14466; -- The King's Observatory
UPDATE `quest_offer_reward` SET `Emote1`=2, `RewardText`='$n.  I''ve heard much about you.$B$BI understand you were crucial in my family''s survival during the outbreak in Gilneas City.', `VerifiedBuild`=25383 WHERE `ID`=14465; -- To Greymane Manor
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $n.  I think I speak for everyone when I say the sooner we get out of here, the better.', `VerifiedBuild`=25383 WHERE `ID`=14463; -- Horses for Duskhaven
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14401; -- Grandma's Cat
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You''re a peach, $n.  Thanks!', `VerifiedBuild`=25383 WHERE `ID`=14400; -- I Can't Wear This
UPDATE `quest_offer_reward` SET `RewardText`='Why thank you, $n.  I hope you didn''t peek!$B$BWhere are your manners, dear?', `VerifiedBuild`=25383 WHERE `ID`=14399; -- Grandma's Lost It Alright
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14398; -- Grandma Wahl
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14412; -- Washed Up
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='This is great, $n.  I should be able to finish the repairs in no time.', `VerifiedBuild`=25383 WHERE `ID`=14404; -- Not Quite Shipshape
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14403; -- The Hayward Brothers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14416; -- The Hungry Ettin
UPDATE `quest_offer_reward` SET `RewardText`='Stay back! Don''t make me...$B$BIs it you?  By the Light!  It''s you, $n!', `VerifiedBuild`=25383 WHERE `ID`=14406; -- The Crowley Orchard
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14397; -- Evacuation
UPDATE `quest_offer_reward` SET `RewardText`='You did what you could, $n.  With any luck a few others will find their way to shore.', `VerifiedBuild`=25383 WHERE `ID`=14395; -- Gasping for Breath
UPDATE `quest_offer_reward` SET `RewardText`='The ocean, $n.  It swallowed everything... the land... the Forsaken... our men!', `VerifiedBuild`=25383 WHERE `ID`=14396; -- As the Land Shatters
UPDATE `quest_offer_reward` SET `RewardText`='You did it, $n.  That should take the wind out of their sails.', `VerifiedBuild`=25383 WHERE `ID`=14386; -- Leader of the Pack
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $n.  You might be a bloody beast, but you''re our beast.', `VerifiedBuild`=25383 WHERE `ID`=14382; -- Two By Sea
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $n.  You might be a bloody beast, but you''re our beast.', `VerifiedBuild`=25383 WHERE `ID`=14382; -- Two By Sea
UPDATE `quest_offer_reward` SET `RewardText`='Not bad, $n.  It''s a good thing you''re on our side.', `VerifiedBuild`=25383 WHERE `ID`=14369; -- Unleash the Beast
UPDATE `quest_offer_reward` SET `RewardText`='My children are safe!  You''ve done a wonderful thing, $n.  I don''t know how to thank you!', `VerifiedBuild`=25383 WHERE `ID`=14368; -- Save the Children!
UPDATE `quest_offer_reward` SET `RewardText`='The Forsaken are here in full strength, $n.  We barely have enough men to hold them back.', `VerifiedBuild`=25383 WHERE `ID`=14367; -- The Allens' Storm Cellar
UPDATE `quest_offer_reward` SET `RewardText`='Great news, $n.  I''ve sent the remaining militia to the shore to meet the Forsaken force head on.', `VerifiedBuild`=25383 WHERE `ID`=14366; -- Holding Steady
UPDATE `quest_offer_reward` SET `RewardText`='You and me, $n.  We make a great team...$B$BIt''s good to have you back.', `VerifiedBuild`=25383 WHERE `ID`=14348; -- You Can't Take 'Em Alone
UPDATE `quest_offer_reward` SET `RewardText`='Yes, $n!  Just like old times...$B$BI''m going to have to work hard at not shooting you, but Krennan explained everything to us.', `VerifiedBuild`=25383 WHERE `ID`=14347; -- Hold the Line
UPDATE `quest_offer_reward` SET `RewardText`='$n!!!  You ARE alive!$B$BI thought I was having dreams about the old days when I heard your voice...', `VerifiedBuild`=25383 WHERE `ID`=14336; -- Kill or Be Killed
UPDATE `quest_offer_reward` SET `RewardText`='Forsaken!  Quick, $n!  We must mount a defense.', `VerifiedBuild`=25383 WHERE `ID`=14321; -- Invasion
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14320; -- In Need of Ingredients
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14313; -- Among Humans Again
UPDATE `quest_offer_reward` SET `RewardText`='I need you to pull through, $n.  This dosage is strong enough to kill a horse.$B$BBut I know you.  I know what you''re made of.  You will be fine.$B$BTrust me.  I know what you''re going through.$B$BNow drink up and close your eyes.', `VerifiedBuild`=25383 WHERE `ID`=14375; -- Last Chance at Humanity
UPDATE `quest_offer_reward` SET `RewardText`='They... they''ve stopped coming.$B$BNo, $n.  That''s not a good thing.', `VerifiedBuild`=25383 WHERE `ID`=14222; -- Last Stand
UPDATE `quest_offer_reward` SET `RewardText`='We''ve given them everything we have... yet still they come.  Do not worry, $n.  We''ll slay many more before today is over.', `VerifiedBuild`=25383 WHERE `ID`=14221; -- Never Surrender, Sometimes Retreat
UPDATE `quest_offer_reward` SET `RewardText`='You''ve done well, $n.  You''ve done more than could be asked of any Gilnean.$B$BWe''re running low on ammunition.  It''s time to regroup inside now.', `VerifiedBuild`=25383 WHERE `ID`=14218; -- By Blood and Ash
UPDATE `quest_offer_reward` SET `RewardText`='Brace yourself, $n.$B$BHere they come.', `VerifiedBuild`=25383 WHERE `ID`=14212; -- Sacrifices
UPDATE `quest_offer_reward` SET `RewardText`='We''re left with very few choices, $n.  What we do next will be a critical decision.', `VerifiedBuild`=25383 WHERE `ID`=14294; -- Time to Regroup
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $n.  We''ll make sure Krennan makes it out of the city alive.', `VerifiedBuild`=25383 WHERE `ID`=14293; -- Save Krennan Aranas
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14214; -- Message to Greymane
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14204; -- From the Shadows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14159; -- The Rebel Lord's Arsenal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=26129; -- Brothers In Arms
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=24930; -- While You're At It
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $n.  Thanks to you a good man has survived.', `VerifiedBuild`=25383 WHERE `ID`=14154; -- By the Skin of His Teeth
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=28850; -- The Prison Rooftop
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14157; -- Old Divisions
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14286; -- Safety in Numbers
UPDATE `quest_offer_reward` SET `RewardText`='$n!  Where have you been?$B$BAnyway... it''s great to see you in one piece.', `VerifiedBuild`=25383 WHERE `ID`=14265; -- Your Instructor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14099; -- Royal Orders
UPDATE `quest_offer_reward` SET `RewardText`='Good job, $n.  Thanks to you, many Gilneans will live to see another day.', `VerifiedBuild`=25383 WHERE `ID`=14098; -- Evacuate the Merchant Square
UPDATE `quest_offer_reward` SET `RewardText`='It''s no use, $n!  They''re not letting up.', `VerifiedBuild`=25383 WHERE `ID`=14093; -- All Hell Breaks Loose
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14094; -- Salvage the Supplies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14091; -- Something's Amiss
UPDATE `quest_offer_reward` SET `VerifiedBuild`=25383 WHERE `ID`=14078; -- Lockdown!

DELETE FROM `quest_poi_points` WHERE (`QuestID`=24675 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=14369 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=14369 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=14157 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=14098 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31814 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31814 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=31814 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(24675, 2, 0, -1366, 1217, 25383), -- Last Meal
(14369, 1, 0, -1844, 2567, 25383), -- Unleash the Beast
(14369, 0, 9, -2211, 2475, 25383), -- Unleash the Beast
(14369, 0, 8, -2243, 2554, 25383), -- Unleash the Beast
(14369, 0, 7, -2115, 2683, 25383), -- Unleash the Beast
(14369, 0, 6, -2103, 2686, 25383), -- Unleash the Beast
(14369, 0, 5, -1958, 2711, 25383), -- Unleash the Beast
(14369, 0, 4, -1943, 2694, 25383), -- Unleash the Beast
(14369, 0, 3, -1933, 2563, 25383), -- Unleash the Beast
(14369, 0, 2, -1978, 2528, 25383), -- Unleash the Beast
(14369, 0, 1, -2058, 2470, 25383), -- Unleash the Beast
(14369, 0, 0, -2179, 2462, 25383), -- Unleash the Beast
(14157, 0, 0, -1749, 1426, 25383), -- Old Divisions
(14098, 2, 0, -1438, 1401, 25383), -- Evacuate the Merchant Square
(31814, 2, 0, -222, -3165, 25383), -- Analynn
(31814, 1, 0, 3537, 535, 25383), -- Analynn
(31814, 0, 0, 3537, 535, 25383); -- Analynn

UPDATE `quest_poi_points` SET `X`=-1673, `Y`=1345, `VerifiedBuild`=25383 WHERE (`QuestID`=14293 AND `Idx1`=1 AND `Idx2`=0); -- Save Krennan Aranas
UPDATE `quest_poi_points` SET `X`=-1786, `Y`=1438, `VerifiedBuild`=25383 WHERE (`QuestID`=14293 AND `Idx1`=0 AND `Idx2`=0); -- Save Krennan Aranas

DELETE FROM `quest_details` WHERE `ID` IN (24676 /*Push Them Out*/, 24674 /*Slaves to No One*/, 24675 /*Last Meal*/, 24575 /*Liberation Day*/, 24677 /*Flank the Forsaken*/, 24592 /*Betrayal at Tempest's Reach*/, 24672 /*Onwards and Upwards*/, 24673 /*Return to Stormglen*/, 24593 /*Neither Human Nor Beast*/, 24646 /*Take Back What's Ours*/, 24628 /*Preparations*/, 24627 /*At Our Doorstep*/, 24617 /*Tal'doren, the Wild Home*/, 24616 /*Losing Your Tail*/, 24578 /*The Blackwald*/, 24501 /*Queen-Sized Troubles*/, 24495 /*Pieces of the Past*/, 24484 /*Pest Control*/, 24483 /*Stormglen*/, 24472 /*Introductions Are in Order*/, 24468 /*Stranded at the Marsh*/, 24438 /*Exodus*/, 14466 /*The King's Observatory*/, 14465 /*To Greymane Manor*/, 14463 /*Horses for Duskhaven*/, 14405 /*Escape By Sea*/, 14402 /*Ready to Go*/, 14401 /*Grandma's Cat*/, 14400 /*I Can't Wear This*/, 14399 /*Grandma's Lost It Alright*/, 14412 /*Washed Up*/, 14404 /*Not Quite Shipshape*/, 14416 /*The Hungry Ettin*/, 14406 /*The Crowley Orchard*/, 14403 /*The Hayward Brothers*/, 14398 /*Grandma Wahl*/, 14397 /*Evacuation*/, 14395 /*Gasping for Breath*/, 14396 /*As the Land Shatters*/, 14386 /*Leader of the Pack*/, 14368 /*Save the Children!*/, 14382 /*Two By Sea*/, 14369 /*Unleash the Beast*/, 14367 /*The Allens' Storm Cellar*/, 14366 /*Holding Steady*/, 14347 /*Hold the Line*/, 14348 /*You Can't Take 'Em Alone*/, 14336 /*Kill or Be Killed*/, 14321 /*Invasion*/, 14320 /*In Need of Ingredients*/, 14313 /*Among Humans Again*/, 14222 /*Last Stand*/, 14221 /*Never Surrender, Sometimes Retreat*/, 14218 /*By Blood and Ash*/, 14212 /*Sacrifices*/, 14294 /*Time to Regroup*/, 14293 /*Save Krennan Aranas*/, 14214 /*Message to Greymane*/, 14204 /*From the Shadows*/, 14159 /*The Rebel Lord's Arsenal*/, 26129 /*Brothers In Arms*/, 14154 /*By the Skin of His Teeth*/, 28850 /*The Prison Rooftop*/, 24930 /*While You're At It*/, 14157 /*Old Divisions*/, 14286 /*Safety in Numbers*/, 14265 /*Your Instructor*/, 14099 /*Royal Orders*/, 14094 /*Salvage the Supplies*/, 14098 /*Evacuate the Merchant Square*/, 14093 /*All Hell Breaks Loose*/, 14091 /*Something's Amiss*/, 14078 /*Lockdown!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(24676, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Push Them Out
(24674, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Slaves to No One
(24675, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Last Meal
(24575, 1, 274, 0, 0, 0, 0, 0, 0, 25383), -- Liberation Day
(24677, 274, 0, 0, 0, 0, 0, 0, 0, 25383), -- Flank the Forsaken
(24592, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Betrayal at Tempest's Reach
(24672, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Onwards and Upwards
(24673, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Return to Stormglen
(24593, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Neither Human Nor Beast
(24646, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Take Back What's Ours
(24628, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Preparations
(24627, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- At Our Doorstep
(24617, 25, 0, 0, 0, 0, 0, 0, 0, 25383), -- Tal'doren, the Wild Home
(24616, 1, 25, 0, 0, 0, 0, 0, 0, 25383), -- Losing Your Tail
(24578, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Blackwald
(24501, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Queen-Sized Troubles
(24495, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Pieces of the Past
(24484, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Pest Control
(24483, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Stormglen
(24472, 1, 6, 5, 0, 0, 0, 0, 0, 25383), -- Introductions Are in Order
(24468, 1, 25, 0, 0, 0, 0, 0, 0, 25383), -- Stranded at the Marsh
(24438, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Exodus
(14466, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The King's Observatory
(14465, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- To Greymane Manor
(14463, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Horses for Duskhaven
(14405, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Escape By Sea
(14402, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Ready to Go
(14401, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Grandma's Cat
(14400, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- I Can't Wear This
(14399, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Grandma's Lost It Alright
(14412, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Washed Up
(14404, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Not Quite Shipshape
(14416, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Hungry Ettin
(14406, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Crowley Orchard
(14403, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Hayward Brothers
(14398, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Grandma Wahl
(14397, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Evacuation
(14395, 25, 6, 1, 0, 0, 0, 0, 0, 25383), -- Gasping for Breath
(14396, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- As the Land Shatters
(14386, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Leader of the Pack
(14368, 18, 0, 0, 0, 0, 0, 0, 0, 25383), -- Save the Children!
(14382, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Two By Sea
(14369, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Unleash the Beast
(14367, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Allens' Storm Cellar
(14366, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Holding Steady
(14347, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Hold the Line
(14348, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- You Can't Take 'Em Alone
(14336, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Kill or Be Killed
(14321, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Invasion
(14320, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- In Need of Ingredients
(14313, 1, 5, 274, 0, 0, 0, 0, 0, 25383), -- Among Humans Again
(14222, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Last Stand
(14221, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Never Surrender, Sometimes Retreat
(14218, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- By Blood and Ash
(14212, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Sacrifices
(14294, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Time to Regroup
(14293, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Save Krennan Aranas
(14214, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Message to Greymane
(14204, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- From the Shadows
(14159, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Rebel Lord's Arsenal
(26129, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Brothers In Arms
(14154, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- By the Skin of His Teeth
(28850, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Prison Rooftop
(24930, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- While You're At It
(14157, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Old Divisions
(14286, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Safety in Numbers
(14265, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Your Instructor
(14099, 25, 0, 0, 0, 0, 0, 0, 0, 25383), -- Royal Orders
(14094, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Salvage the Supplies
(14098, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Evacuate the Merchant Square
(14093, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- All Hell Breaks Loose
(14091, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Something's Amiss
(14078, 0, 0, 0, 0, 0, 0, 0, 0, 25383); -- Lockdown!

UPDATE `quest_request_items` SET `CompletionText`='Did you get what I needed, $n?', `VerifiedBuild`=25383 WHERE `ID`=24675; -- Last Meal
UPDATE `quest_request_items` SET `CompletionText`='Do you have the scythe, $n?', `VerifiedBuild`=25383 WHERE `ID`=24646; -- Take Back What's Ours
UPDATE `quest_request_items` SET `CompletionText`='You''ve returned, $n.', `VerifiedBuild`=25383 WHERE `ID`=24628; -- Preparations
UPDATE `quest_request_items` SET `CompletionText`='How did it go, $n?', `VerifiedBuild`=25383 WHERE `ID`=24472; -- Introductions Are in Order
UPDATE `quest_request_items` SET `CompletionText`='You''re such a charming young $gman:lady;, $n.', `VerifiedBuild`=25383 WHERE `ID`=14401; -- Grandma's Cat
UPDATE `quest_request_items` SET `CompletionText`='Do you have my supplies, $n?', `VerifiedBuild`=25383 WHERE `ID`=14404; -- Not Quite Shipshape
UPDATE `quest_request_items` SET `CompletionText`='Have you salvaged the supplies, $n?', `VerifiedBuild`=25383 WHERE `ID`=14094; -- Salvage the Supplies

UPDATE `creature_addon` SET `emote`= 333 WHERE `guid`= 376570;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 3 WHERE `guid` IN (376655, 376654, 376510);

UPDATE `creature_addon` SET `emote`= 27, `Auras`= '67503' WHERE `guid`= 376582;
UPDATE `creature_addon` SET `emote`= 375 WHERE `guid`= 376579;

-- Creature Lord Darius Crowley 35077 SAI
SET @ENTRY := 35077;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 3 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 11, 66914, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14154 - Self: Cast spell 66914 on Action invoker // "),
(@ENTRY, 0, 1, 0, 37, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Disable combat based movement // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 6000, 6000, 15000, 17000, 11, 67825, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 15000 and 17000 ms) - Self: Cast spell 67825 on Victim // ");

UPDATE `creature_template` SET `DamageModifier`= 3 WHERE `entry`= 35124;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_gen_gilneas_prison_periodic_dummy');
 
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66853, 'spell_gen_gilneas_prison_periodic_dummy');

DELETE FROM `spell_target_position` WHERE `ID` IN (66925, 66836);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(66925, 0, 654, -1636.292, 1481.836, 70.94804, 4.081235),
(66836, 0, 654, -1620.981, 1509.193, 67.10413, 3.919209);

UPDATE `creature_template` SET `scriptname`= 'npc_worgen_runt' WHERE `entry` IN (35456, 35188);

-- Creature Worgen Alpha 35167 SAI
SET @ENTRY := 35167;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell 8599 on Self // Worgen Alpha - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // Worgen Alpha - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1639.317, 1491.14, 67.34758, 0, "On just summoned - Self: Move to None (point id 0) // ");
