-- 
DELETE FROM `quest_poi` WHERE (`QuestID`=26830 AND `id`=3) OR (`QuestID`=26830 AND `id`=2) OR (`QuestID`=26830 AND `id`=1) OR (`QuestID`=26830 AND `id`=0) OR (`QuestID`=26621 AND `id`=4) OR (`QuestID`=26621 AND `id`=3) OR (`QuestID`=26621 AND `id`=2) OR (`QuestID`=26621 AND `id`=1) OR (`QuestID`=26621 AND `id`=0) OR (`QuestID`=26608 AND `id`=1) OR (`QuestID`=26608 AND `id`=0) OR (`QuestID`=26388 AND `id`=2) OR (`QuestID`=26388 AND `id`=1) OR (`QuestID`=26388 AND `id`=0) OR (`QuestID`=28849 AND `id`=1) OR (`QuestID`=28849 AND `id`=0) OR (`QuestID`=26293 AND `id`=1) OR (`QuestID`=26293 AND `id`=0) OR (`QuestID`=27584 AND `id`=2) OR (`QuestID`=27584 AND `id`=1) OR (`QuestID`=27584 AND `id`=0) OR (`QuestID`=27607 AND `id`=1) OR (`QuestID`=27607 AND `id`=0) OR (`QuestID`=26784 AND `id`=2) OR (`QuestID`=26784 AND `id`=1) OR (`QuestID`=26784 AND `id`=0) OR (`QuestID`=26622 AND `id`=2) OR (`QuestID`=26622 AND `id`=1) OR (`QuestID`=26622 AND `id`=0) OR (`QuestID`=26619 AND `id`=1) OR (`QuestID`=26619 AND `id`=0) OR (`QuestID`=26549 AND `id`=2) OR (`QuestID`=26549 AND `id`=1) OR (`QuestID`=26549 AND `id`=0) OR (`QuestID`=26538 AND `id`=2) OR (`QuestID`=26538 AND `id`=1) OR (`QuestID`=26538 AND `id`=0) OR (`QuestID`=26372 AND `id`=1) OR (`QuestID`=26372 AND `id`=0) OR (`QuestID`=26294 AND `id`=3) OR (`QuestID`=26294 AND `id`=2) OR (`QuestID`=26294 AND `id`=1) OR (`QuestID`=26294 AND `id`=0) OR (`QuestID`=27583 AND `id`=1) OR (`QuestID`=27583 AND `id`=0) OR (`QuestID`=26798 AND `id`=1) OR (`QuestID`=26798 AND `id`=0) OR (`QuestID`=26786 AND `id`=1) OR (`QuestID`=26786 AND `id`=0) OR (`QuestID`=26540 AND `id`=1) OR (`QuestID`=26540 AND `id`=0) OR (`QuestID`=26539 AND `id`=1) OR (`QuestID`=26539 AND `id`=0) OR (`QuestID`=26358 AND `id`=1) OR (`QuestID`=26358 AND `id`=0) OR (`QuestID`=26374 AND `id`=2) OR (`QuestID`=26374 AND `id`=1) OR (`QuestID`=26374 AND `id`=0) OR (`QuestID`=26324 AND `id`=1) OR (`QuestID`=26324 AND `id`=0) OR (`QuestID`=26311 AND `id`=2) OR (`QuestID`=26311 AND `id`=1) OR (`QuestID`=26311 AND `id`=0) OR (`QuestID`=28909 AND `id`=3) OR (`QuestID`=28909 AND `id`=2) OR (`QuestID`=28909 AND `id`=1) OR (`QuestID`=28909 AND `id`=0) OR (`QuestID`=27586 AND `id`=2) OR (`QuestID`=27586 AND `id`=1) OR (`QuestID`=27586 AND `id`=0) OR (`QuestID`=26840 AND `id`=1) OR (`QuestID`=26840 AND `id`=0) OR (`QuestID`=26788 AND `id`=2) OR (`QuestID`=26788 AND `id`=1) OR (`QuestID`=26788 AND `id`=0) OR (`QuestID`=26337 AND `id`=2) OR (`QuestID`=26337 AND `id`=1) OR (`QuestID`=26337 AND `id`=0) OR (`QuestID`=26361 AND `id`=2) OR (`QuestID`=26361 AND `id`=1) OR (`QuestID`=26361 AND `id`=0) OR (`QuestID`=26335 AND `id`=1) OR (`QuestID`=26335 AND `id`=0);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(26830, 3, 32, 1, 321, 0, 0, 0, 26365), -- Traitor's Bait
(26830, 2, 1, 1, 321, 0, 0, 2, 26365), -- Traitor's Bait
(26830, 1, 0, 1, 321, 0, 0, 0, 26365), -- Traitor's Bait
(26830, 0, -1, 1, 321, 0, 0, 2, 26365), -- Traitor's Bait
(26621, 4, 32, 0, 700, 0, 0, 0, 26365), -- Insurrection
(26621, 3, 2, 0, 700, 0, 0, 1, 26365), -- Insurrection
(26621, 2, 1, 0, 700, 0, 0, 1, 26365), -- Insurrection
(26621, 1, 0, 0, 700, 0, 0, 7, 26365), -- Insurrection
(26621, 0, -1, 0, 700, 0, 0, 1, 26365), -- Insurrection
(26608, 1, 32, 0, 700, 0, 0, 0, 26365), -- Negotiations Terminated
(26608, 0, -1, 0, 700, 0, 0, 1, 26365), -- Negotiations Terminated
(26388, 2, 32, 1, 181, 0, 0, 0, 26365), -- Twilight Skies
(26388, 1, 0, 1, 181, 0, 0, 7, 26365), -- Twilight Skies
(26388, 0, -1, 0, 700, 0, 0, 1, 26365), -- Twilight Skies
(28849, 1, 32, 1, 181, 0, 0, 0, 26365), -- Twilight Skies
(28849, 0, -1, 1, 181, 0, 0, 1, 26365), -- Twilight Skies
(26293, 1, 32, 1, 321, 0, 0, 0, 26365), -- Machines of War
(26293, 0, -1, 1, 181, 0, 0, 0, 26365), -- Machines of War
(27584, 2, 32, 0, 700, 0, 0, 0, 26365), -- Blood in the Surf
(27584, 1, 0, 0, 700, 0, 0, 3, 26365), -- Blood in the Surf
(27584, 0, -1, 0, 700, 0, 0, 1, 26365), -- Blood in the Surf
(27607, 1, 32, 0, 700, 0, 0, 0, 26365), -- The Southern Flank
(27607, 0, -1, 0, 700, 0, 0, 1, 26365), -- The Southern Flank
(26784, 2, 32, 736, 770, 0, 0, 0, 26365), -- Muddied Waters
(26784, 1, 0, 0, 700, 0, 0, 1, 26365), -- Muddied Waters
(26784, 0, -1, 0, 700, 0, 0, 1, 26365), -- Muddied Waters
(26622, 2, 32, 0, 700, 0, 0, 0, 26365), -- Death to Mor'ghor
(26622, 1, 0, 0, 700, 0, 0, 1, 26365), -- Death to Mor'ghor
(26622, 0, -1, 0, 700, 0, 0, 1, 26365), -- Death to Mor'ghor
(26619, 1, 32, 736, 770, 0, 0, 0, 26365), -- You Say You Want a Revolution
(26619, 0, -1, 0, 700, 0, 0, 1, 26365), -- You Say You Want a Revolution
(26549, 2, 32, 0, 700, 0, 0, 2, 26365), -- Madness
(26549, 1, 0, 0, 700, 0, 0, 2, 26365), -- Madness
(26549, 0, -1, 0, 700, 0, 0, 0, 26365), -- Madness
(26538, 2, 32, 736, 770, 0, 0, 0, 26365), -- Emergency Aid
(26538, 1, 0, 0, 700, 0, 0, 3, 26365), -- Emergency Aid
(26538, 0, -1, 0, 700, 0, 0, 3, 26365), -- Emergency Aid
(26372, 1, 32, 1, 181, 0, 0, 0, 26365), -- Pre-Flight Checklist
(26372, 0, -1, 1, 181, 0, 0, 1, 26365), -- Pre-Flight Checklist
(26294, 3, 32, 1, 321, 0, 0, 0, 26365), -- Weapons of Mass Dysfunction
(26294, 2, 1, 1, 181, 0, 0, 2, 26365), -- Weapons of Mass Dysfunction
(26294, 1, 0, 1, 181, 0, 0, 2, 26365), -- Weapons of Mass Dysfunction
(26294, 0, -1, 1, 321, 0, 0, 0, 26365), -- Weapons of Mass Dysfunction
(27583, 1, 32, 0, 700, 0, 0, 0, 26365), -- The Northern Flank
(27583, 0, -1, 0, 700, 0, 0, 1, 26365), -- The Northern Flank
(26798, 1, 32, 0, 770, 0, 0, 0, 26365), -- Saurfang Will be Pleased
(26798, 0, -1, 1, 321, 0, 0, 0, 26365), -- Saurfang Will be Pleased
(26786, 1, 32, 736, 770, 0, 0, 0, 26365), -- Securing the Beach Head
(26786, 0, -1, 0, 700, 0, 0, 1, 26365), -- Securing the Beach Head
(26540, 1, 32, 0, 770, 0, 0, 0, 26365), -- Dangerous Compassion
(26540, 0, -1, 0, 770, 0, 0, 0, 26365), -- Dangerous Compassion
(26539, 1, 32, 736, 770, 0, 0, 0, 26365), -- Stalled Negotiations
(26539, 0, -1, 0, 700, 0, 0, 1, 26365), -- Stalled Negotiations
(26358, 1, 32, 1, 181, 0, 0, 0, 26365), -- Ready the Air Force
(26358, 0, -1, 1, 181, 0, 0, 1, 26365), -- Ready the Air Force
(26374, 2, 32, 1, 181, 0, 0, 0, 26365), -- Ready the Ground Troops
(26374, 1, 0, 1, 181, 0, 0, 3, 26365), -- Ready the Ground Troops
(26374, 0, -1, 1, 181, 0, 0, 1, 26365), -- Ready the Ground Troops
(26324, 1, 32, 1, 321, 0, 0, 0, 26365), -- Where Is My Warfleet?
(26324, 0, -1, 1, 181, 0, 0, 0, 26365), -- Where Is My Warfleet?
(26311, 2, 32, 1, 321, 0, 0, 0, 26365), -- Unfamiliar Waters
(26311, 1, 0, 1, 321, 0, 0, 1, 26365), -- Unfamiliar Waters
(26311, 0, -1, 1, 321, 0, 0, 1, 26365), -- Unfamiliar Waters
(28909, 3, 32, 1, 321, 0, 0, 0, 26365), -- Sauranok Will Point the Way
(28909, 2, 32, 1, 321, 0, 0, 0, 26365), -- Sauranok Will Point the Way
(28909, 1, 32, 1, 321, 0, 0, 0, 26365), -- Sauranok Will Point the Way
(28909, 0, -1, 1, 321, 0, 0, 1, 26365), -- Sauranok Will Point the Way
(27586, 2, 32, 0, 700, 0, 0, 0, 26365), -- Shells on the Sea Shore
(27586, 1, 0, 0, 700, 0, 0, 1, 26365), -- Shells on the Sea Shore
(27586, 0, -1, 0, 700, 0, 0, 1, 26365), -- Shells on the Sea Shore
(26840, 1, 32, 1, 321, 0, 0, 0, 26365), -- Return to the Highlands
(26840, 0, -1, 0, 700, 0, 0, 0, 26365), -- Return to the Highlands
(26788, 2, 32, 0, 700, 0, 0, 2, 26365), -- Cementing Our Victory
(26788, 1, 0, 0, 700, 0, 0, 0, 26365), -- Cementing Our Victory
(26788, 0, -1, 0, 700, 0, 0, 0, 26365), -- Cementing Our Victory
(26337, 2, 32, 1, 181, 0, 0, 0, 26365), -- Beating the Market
(26337, 1, 0, 1, 181, 0, 0, 1, 26365), -- Beating the Market
(26337, 0, -1, 1, 181, 0, 0, 1, 26365), -- Beating the Market
(26361, 2, 32, 1, 181, 0, 0, 0, 26365), -- Smoot's Samophlange
(26361, 1, 0, 1, 181, 0, 0, 7, 26365), -- Smoot's Samophlange
(26361, 0, -1, 1, 181, 0, 0, 1, 26365), -- Smoot's Samophlange
(26335, 1, 32, 1, 181, 0, 0, 0, 26365), -- Ready the Navy
(26335, 0, -1, 1, 181, 0, 0, 1, 26365); -- Ready the Navy

DELETE FROM `quest_poi_points` WHERE (`QuestID`=26830 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=26621 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=26608 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26388 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=28849 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27584 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=27584 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27584 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=27607 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27607 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=26784 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=26622 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26619 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26549 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26538 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=26372 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26294 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=27583 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27583 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=26798 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26786 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26540 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26539 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26358 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26374 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26324 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26311 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=28909 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=28909 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=28909 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=28909 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=27586 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=27586 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=27586 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=26840 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=26788 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=26337 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26361 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=26335 AND `Idx1`=1 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(26830, 3, 0, 1664, -4346, 26365), -- Traitor's Bait
(26621, 4, 0, -4084, -6407, 26365), -- Insurrection
(26621, 2, 8, -4075, -6465, 26365), -- Insurrection
(26621, 2, 7, -4022, -6277, 26365), -- Insurrection
(26621, 2, 6, -4019, -6268, 26365), -- Insurrection
(26621, 2, 5, -3990, -6285, 26365), -- Insurrection
(26621, 2, 4, -3926, -6378, 26365), -- Insurrection
(26621, 2, 3, -3899, -6505, 26365), -- Insurrection
(26621, 2, 2, -3907, -6513, 26365), -- Insurrection
(26621, 2, 1, -3972, -6531, 26365), -- Insurrection
(26621, 1, 11, -4031, -6544, 26365), -- Insurrection
(26621, 1, 10, -4083, -6500, 26365), -- Insurrection
(26621, 1, 9, -4087, -6444, 26365), -- Insurrection
(26621, 1, 8, -4087, -6396, 26365), -- Insurrection
(26621, 1, 7, -4087, -6348, 26365), -- Insurrection
(26608, 1, 0, -4084, -6407, 26365), -- Negotiations Terminated
(26388, 2, 0, 2664, -6169, 26365), -- Twilight Skies
(28849, 1, 0, 3527, -6692, 26365), -- Twilight Skies
(27584, 2, 0, -3676, -6140, 26365), -- Blood in the Surf
(27584, 1, 9, -3843, -6354, 26365), -- Blood in the Surf
(27584, 1, 8, -3811, -6299, 26365), -- Blood in the Surf
(27584, 1, 7, -3722, -6231, 26365), -- Blood in the Surf
(27584, 1, 6, -3611, -6147, 26365), -- Blood in the Surf
(27584, 1, 5, -3509, -6119, 26365), -- Blood in the Surf
(27584, 1, 4, -3448, -6175, 26365), -- Blood in the Surf
(27584, 1, 3, -3547, -6233, 26365), -- Blood in the Surf
(27584, 1, 2, -3631, -6265, 26365), -- Blood in the Surf
(27584, 1, 1, -3740, -6335, 26365), -- Blood in the Surf
(27584, 1, 0, -3791, -6366, 26365), -- Blood in the Surf
(27584, 0, 0, -3676, -6140, 26365), -- Blood in the Surf
(27607, 1, 0, -4084, -6407, 26365), -- The Southern Flank
(27607, 0, 0, -4354, -6562, 26365), -- The Southern Flank
(26784, 2, 0, -4052, -6327, 26365), -- Muddied Waters
(26784, 1, 7, -4000, -5989, 26365), -- Muddied Waters
(26784, 1, 6, -3679, -5794, 26365), -- Muddied Waters
(26784, 1, 5, -3644, -5775, 26365), -- Muddied Waters
(26784, 1, 4, -3616, -5805, 26365), -- Muddied Waters
(26784, 1, 3, -3635, -5839, 26365), -- Muddied Waters
(26784, 1, 2, -3765, -6023, 26365), -- Muddied Waters
(26784, 1, 1, -3845, -6112, 26365), -- Muddied Waters
(26622, 2, 0, -4084, -6407, 26365), -- Death to Mor'ghor
(26619, 1, 0, -3911, -6791, 26365), -- You Say You Want a Revolution
(26549, 2, 0, -3980, -6590, 26365), -- Madness
(26538, 0, 0, -3931, -6475, 26365), -- Emergency Aid
(26372, 1, 0, 3500, -6380, 26365), -- Pre-Flight Checklist
(26294, 3, 0, 2482, -4815, 26365), -- Weapons of Mass Dysfunction
(27583, 1, 0, -4084, -6407, 26365), -- The Northern Flank
(27583, 0, 0, -3676, -6140, 26365), -- The Northern Flank
(26798, 1, 0, -4052, -6327, 26365), -- Saurfang Will be Pleased
(26786, 1, 0, -4021, -6379, 26365), -- Securing the Beach Head
(26540, 1, 0, -3895, -6471, 26365), -- Dangerous Compassion
(26539, 1, 0, -3908, -6786, 26365), -- Stalled Negotiations
(26358, 1, 0, 3527, -6692, 26365), -- Ready the Air Force
(26374, 2, 0, 3529, -6691, 26365), -- Ready the Ground Troops
(26324, 1, 0, 1664, -4346, 26365), -- Where Is My Warfleet?
(26311, 2, 0, 1663, -4340, 26365), -- Unfamiliar Waters
(28909, 3, 0, 1670, -4343, 26365), -- Sauranok Will Point the Way
(28909, 2, 0, 2124, -4739, 26365), -- Sauranok Will Point the Way
(28909, 1, 0, 1664, -4346, 26365), -- Sauranok Will Point the Way
(28909, 0, 0, 1663, -4340, 26365), -- Sauranok Will Point the Way
(27586, 2, 0, -3681, -6143, 26365), -- Shells on the Sea Shore
(27586, 1, 10, -3803, -6339, 26365), -- Shells on the Sea Shore
(27586, 1, 9, -3810, -6320, 26365), -- Shells on the Sea Shore
(27586, 1, 8, -3775, -6272, 26365), -- Shells on the Sea Shore
(27586, 1, 7, -3650, -6190, 26365), -- Shells on the Sea Shore
(27586, 1, 6, -3585, -6156, 26365), -- Shells on the Sea Shore
(27586, 1, 5, -3507, -6165, 26365), -- Shells on the Sea Shore
(27586, 1, 4, -3475, -6170, 26365), -- Shells on the Sea Shore
(27586, 1, 3, -3474, -6195, 26365), -- Shells on the Sea Shore
(27586, 1, 2, -3491, -6215, 26365), -- Shells on the Sea Shore
(27586, 1, 1, -3726, -6326, 26365), -- Shells on the Sea Shore
(27586, 1, 0, -3779, -6349, 26365), -- Shells on the Sea Shore
(27586, 0, 0, -3681, -6143, 26365), -- Shells on the Sea Shore
(26840, 1, 0, 1664, -4346, 26365), -- Return to the Highlands
(26788, 2, 0, -4043, -6358, 26365), -- Cementing Our Victory
(26788, 1, 11, -3932, -6137, 26365), -- Cementing Our Victory
(26788, 1, 10, -3957, -6044, 26365), -- Cementing Our Victory
(26788, 1, 9, -3967, -5974, 26365), -- Cementing Our Victory
(26788, 1, 8, -3732, -5833, 26365), -- Cementing Our Victory
(26788, 1, 7, -3691, -5809, 26365), -- Cementing Our Victory
(26788, 1, 6, -3674, -5875, 26365), -- Cementing Our Victory
(26788, 1, 5, -3673, -5888, 26365), -- Cementing Our Victory
(26788, 1, 4, -3732, -5981, 26365), -- Cementing Our Victory
(26788, 1, 3, -3770, -6026, 26365), -- Cementing Our Victory
(26788, 1, 2, -3805, -6062, 26365), -- Cementing Our Victory
(26788, 1, 1, -3825, -6081, 26365), -- Cementing Our Victory
(26337, 2, 0, 3639, -6326, 26365), -- Beating the Market
(26361, 2, 0, 3500, -6380, 26365), -- Smoot's Samophlange
(26335, 1, 0, 3529, -6691, 26365); -- Ready the Navy

UPDATE `quest_poi_points` SET `X`=1750, `Y`=-4273, `VerifiedBuild`=26365 WHERE (`QuestID`=26830 AND `Idx1`=2 AND `Idx2`=0); -- Traitor's Bait
UPDATE `quest_poi_points` SET `X`=1753, `Y`=-4271, `VerifiedBuild`=26365 WHERE (`QuestID`=26830 AND `Idx1`=1 AND `Idx2`=0); -- Traitor's Bait
UPDATE `quest_poi_points` SET `X`=1668, `Y`=-4345, `VerifiedBuild`=26365 WHERE (`QuestID`=26830 AND `Idx1`=0 AND `Idx2`=0); -- Traitor's Bait
UPDATE `quest_poi_points` SET `X`=-4051, `Y`=-6456, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=6); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-4080, `Y`=-6347, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=5); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3963, `Y`=-6289, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=4); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3926, `Y`=-6337, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=3); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3899, `Y`=-6379, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=2); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3945, `Y`=-6488, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=1); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3992, `Y`=-6528, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=3 AND `Idx2`=0); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-4016, `Y`=-6541, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=2 AND `Idx2`=0); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-4039, `Y`=-6313, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=6); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3978, `Y`=-6300, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=5); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3935, `Y`=-6321, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=4); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3917, `Y`=-6369, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=3); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3913, `Y`=-6461, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=2); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3917, `Y`=-6513, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=1); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3978, `Y`=-6548, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=1 AND `Idx2`=0); -- Insurrection
UPDATE `quest_poi_points` SET `X`=-3896, `Y`=-6474, `VerifiedBuild`=26365 WHERE (`QuestID`=26621 AND `Idx1`=0 AND `Idx2`=0); -- Insurrection
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26608 AND `Idx1`=0 AND `Idx2`=0); -- Negotiations Terminated
UPDATE `quest_poi_points` SET `X`=2621, `Y`=-6187, `VerifiedBuild`=26365 WHERE (`QuestID`=26388 AND `Idx1`=1 AND `Idx2`=0); -- Twilight Skies
UPDATE `quest_poi_points` SET `X`=-3908, `Y`=-6786, `VerifiedBuild`=26365 WHERE (`QuestID`=26388 AND `Idx1`=0 AND `Idx2`=0); -- Twilight Skies
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=28849 AND `Idx1`=0 AND `Idx2`=0); -- Twilight Skies
UPDATE `quest_poi_points` SET `X`=1664, `Y`=-4346, `VerifiedBuild`=26365 WHERE (`QuestID`=26293 AND `Idx1`=1 AND `Idx2`=0); -- Machines of War
UPDATE `quest_poi_points` SET `X`=2481, `VerifiedBuild`=26365 WHERE (`QuestID`=26293 AND `Idx1`=0 AND `Idx2`=0); -- Machines of War
UPDATE `quest_poi_points` SET `X`=-3922, `Y`=-6180, `VerifiedBuild`=26365 WHERE (`QuestID`=26784 AND `Idx1`=1 AND `Idx2`=0); -- Muddied Waters
UPDATE `quest_poi_points` SET `X`=-4052, `Y`=-6327, `VerifiedBuild`=26365 WHERE (`QuestID`=26784 AND `Idx1`=0 AND `Idx2`=0); -- Muddied Waters
UPDATE `quest_poi_points` SET `X`=-4112, `Y`=-6416, `VerifiedBuild`=26365 WHERE (`QuestID`=26622 AND `Idx1`=1 AND `Idx2`=0); -- Death to Mor'ghor
UPDATE `quest_poi_points` SET `X`=-4021, `Y`=-6379, `VerifiedBuild`=26365 WHERE (`QuestID`=26622 AND `Idx1`=0 AND `Idx2`=0); -- Death to Mor'ghor
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26619 AND `Idx1`=0 AND `Idx2`=0); -- You Say You Want a Revolution
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26549 AND `Idx1`=1 AND `Idx2`=0); -- Madness
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26549 AND `Idx1`=0 AND `Idx2`=0); -- Madness
UPDATE `quest_poi_points` SET `X`=-3911, `Y`=-6791, `VerifiedBuild`=26365 WHERE (`QuestID`=26538 AND `Idx1`=2 AND `Idx2`=0); -- Emergency Aid
UPDATE `quest_poi_points` SET `X`=-3922, `VerifiedBuild`=26365 WHERE (`QuestID`=26538 AND `Idx1`=1 AND `Idx2`=0); -- Emergency Aid
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26372 AND `Idx1`=0 AND `Idx2`=0); -- Pre-Flight Checklist
UPDATE `quest_poi_points` SET `X`=2402, `Y`=-4796, `VerifiedBuild`=26365 WHERE (`QuestID`=26294 AND `Idx1`=2 AND `Idx2`=0); -- Weapons of Mass Dysfunction
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26294 AND `Idx1`=1 AND `Idx2`=0); -- Weapons of Mass Dysfunction
UPDATE `quest_poi_points` SET `X`=1664, `Y`=-4346, `VerifiedBuild`=26365 WHERE (`QuestID`=26294 AND `Idx1`=0 AND `Idx2`=0); -- Weapons of Mass Dysfunction
UPDATE `quest_poi_points` SET `X`=1664, `Y`=-4346, `VerifiedBuild`=26365 WHERE (`QuestID`=26798 AND `Idx1`=0 AND `Idx2`=0); -- Saurfang Will be Pleased
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26786 AND `Idx1`=0 AND `Idx2`=0); -- Securing the Beach Head
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26540 AND `Idx1`=0 AND `Idx2`=0); -- Dangerous Compassion
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26539 AND `Idx1`=0 AND `Idx2`=0); -- Stalled Negotiations
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26358 AND `Idx1`=0 AND `Idx2`=0); -- Ready the Air Force
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=7); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=6); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=5); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=4); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=3); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=2); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=1); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=1 AND `Idx2`=0); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26374 AND `Idx1`=0 AND `Idx2`=0); -- Ready the Ground Troops
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26324 AND `Idx1`=0 AND `Idx2`=0); -- Where Is My Warfleet?
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26311 AND `Idx1`=1 AND `Idx2`=0); -- Unfamiliar Waters
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26311 AND `Idx1`=0 AND `Idx2`=0); -- Unfamiliar Waters
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26840 AND `Idx1`=0 AND `Idx2`=0); -- Return to the Highlands
UPDATE `quest_poi_points` SET `X`=-3907, `Y`=-6139, `VerifiedBuild`=26365 WHERE (`QuestID`=26788 AND `Idx1`=1 AND `Idx2`=0); -- Cementing Our Victory
UPDATE `quest_poi_points` SET `X`=-4029, `Y`=-6352, `VerifiedBuild`=26365 WHERE (`QuestID`=26788 AND `Idx1`=0 AND `Idx2`=0); -- Cementing Our Victory
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26337 AND `Idx1`=1 AND `Idx2`=4); -- Beating the Market
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26337 AND `Idx1`=1 AND `Idx2`=3); -- Beating the Market
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26337 AND `Idx1`=1 AND `Idx2`=2); -- Beating the Market
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26337 AND `Idx1`=1 AND `Idx2`=1); -- Beating the Market
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26337 AND `Idx1`=1 AND `Idx2`=0); -- Beating the Market
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26337 AND `Idx1`=0 AND `Idx2`=0); -- Beating the Market
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=11); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=10); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=9); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=8); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=7); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=6); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=5); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=4); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=3); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=2); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=1); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=1 AND `Idx2`=0); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26361 AND `Idx1`=0 AND `Idx2`=0); -- Smoot's Samophlange
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=26335 AND `Idx1`=0 AND `Idx2`=0); -- Ready the Navy

SET @CGUID:=258761;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+563;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 49743, 1, 1637, 5170, 1, 169, 0, 0, 0, 1669.82, -4454.333, 96.67023, 3.31474, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dung Beetle (Area: Valley of Strength - Difficulty: 1)
(@CGUID+1, 49743, 1, 1637, 5170, 1, 169, 0, 0, 0, 1639.126, -4453.682, 96.86819, 6.024271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dung Beetle (Area: Valley of Strength - Difficulty: 1)
(@CGUID+2, 52382, 1, 1637, 5356, 1, 169, 0, 0, 0, 1673.214, -4354.397, 27.09088, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ziradormi (Area: Grommash Hold - Difficulty: 1) (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+3, 42637, 1, 1637, 5356, 1, 169, 0, 0, 0, 1663.122, -4340.153, 26.4407, 4.34587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sauranok the Mystic (Area: Grommash Hold - Difficulty: 1) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+4, 49743, 1, 1637, 5356, 1, 169, 0, 0, 0, 1522.902, -4381.818, 20.62967, 5.340795, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dung Beetle (Area: Grommash Hold - Difficulty: 1)
-- (@CGUID+5, 66437, 1, 1637, 5168, 1, 169, 0, 0, 0, 2012.55, -4702.452, 28.77902, 0.8710433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Arcanist Xu (Area: Valley of Honor - Difficulty: 0) (Auras: 32783 - Arcane Channeling)
-- (@CGUID+6, 89830, 1, 1637, 5167, 1, 169, 0, 0, 0, 1636.594, -4381.391, 21.19601, 5.026548, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Brew Vendor (Area: The Drag - Difficulty: 0)
(@CGUID+7, 50367, 1, 16, 4828, 1, 236, 0, 0, 0, 2663.843, -6168.656, 138.185, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Friz Groundspin (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+8, 47206, 1, 16, 4828, 1, 236, 0, 0, 0, 2664.98, -6168.65, 138.1903, 1.58825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Loudspeaker (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+9, 47208, 1, 16, 4828, 1, 236, 0, 0, 0, 2664.54, -6177.08, 138.0111, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Assistant Greely (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+10, 47209, 1, 16, 4828, 1, 236, 0, 0, 0, 2663.31, -6178.47, 138.0793, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Hobart Grapplehammer (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+11, 47210, 1, 16, 4828, 1, 236, 0, 0, 0, 2667.096, -6175.608, 138.9248, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Defense Cannon (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
(@CGUID+12, 47217, 1, 16, 4828, 1, 236, 0, 0, 0, 2664.69, -6175.613, 137.4353, 3.106686, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: 79428 - Parachute Holder)
(@CGUID+13, 42267, 741, 16, 4828, 1, 236, 0, 0, 0, -17.8958, -8.12408, -15.73877, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Garrosh Formation Bunny (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
-- (@CGUID+1013, 42268, UNKNOWN, 16, 4828, 1, 236, 0, 0, 0, -35, 42, -70, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Garrosh's Airship (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+14, 42247, 741, 16, 4828, 1, 236, 0, 0, 0, -17.7612, -9.97555, -15.69357, 2.984513, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zeppelin Formation Bunny 04 (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
(@CGUID+15, 42245, 741, 16, 4828, 1, 236, 0, 0, 0, -17.8297, -10.5894, -15.77057, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zeppelin Formation Bunny 02 (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
(@CGUID+16, 42246, 741, 16, 4828, 1, 236, 0, 0, 0, -17.8816, -10.278, -15.72467, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zeppelin Formation Bunny 03 (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
(@CGUID+17, 42255, 741, 16, 4828, 1, 236, 0, 0, 0, -17.8506, -9.56128, -15.74577, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Support Formation Bunny (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
-- (@CGUID+1018, 42204, UNKNOWN, 16, 4828, 1, 236, 0, 0, 0, 133, 21, 63, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Indomitable (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+18, 42576, 741, 16, 4828, 1, 236, 0, 0, 0, 3.78204, -1.01867, -17.76957, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Drake Rigging Bunny (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
-- (@CGUID+1020, 42577, UNKNOWN, 16, 4828, 1, 236, 0, 0, 0, -35, 0, -42, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Twilight Drake Swarmer (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded, 16245 - Freeze Anim) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+19, 42300, 741, 16, 4828, 1, 236, 0, 0, 0, 11.79519, -5.001086, -16.60061, 3.735005, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kor'kron Air Marine (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+20, 42300, 741, 16, 4828, 1, 236, 0, 0, 0, -13.9199, -9.79252, -16.34217, 0.7679449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kor'kron Air Marine (Area: Southern Rocketway Terminus - Difficulty: 0)
-- (@CGUID+1023, 50369, UNKNOWN, 16, 4828, 1, 236, 0, 0, 0, -70, -60, 40, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deathwing (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+21, 43869, 741, 16, 4828, 1, 236, 0, 0, 0, -2.96676, -3.70849, -17.66797, 3.700098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zeppelin Explosion Bunny (Large) (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+22, 42243, 741, 16, 4828, 1, 236, 0, 0, 0, -17.4878, -4.66261, -15.80167, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fergus Gearchum (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+23, 42195, 741, 16, 4828, 1, 236, 0, 0, 0, -13.1321, -8.03381, -16.46307, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Captain Krazz (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+24, 51137, 741, 16, 4828, 1, 236, 0, 0, 0, -2.593544, -7.091013, -17.70335, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- <Internal> Horde Zeppelin Sound Bunny (Area: Southern Rocketway Terminus - Difficulty: 0)
(@CGUID+25, 51137, 741, 16, 4828, 1, 236, 0, 0, 0, 15.74312, -7.892086, -9.897807, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- <Internal> Horde Zeppelin Sound Bunny (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: 94225 - Twilight Skies: Zep Ambient Loop Sound)
(@CGUID+26, 51033, 741, 16, 4828, 1, 236, 0, 0, 0, -9.426493, -1.025291, -15.99072, 3.298672, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deathwing Zeppelin Ride Vehicle (Area: Southern Rocketway Terminus - Difficulty: 0) (Auras: )
(@CGUID+27, 42314, 741, 11, 2365, 1, 236, 0, 0, 0, -16.17475, -2.350158, -14.91692, 2.268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Defense Cannon (Area: The Great Sea - Difficulty: 0) (Auras: )
(@CGUID+28, 42300, 741, 11, 2365, 1, 236, 0, 0, 0, -13.9199, -9.79252, -16.34217, 0.7679449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kor'kron Air Marine (Area: The Great Sea - Difficulty: 0)
(@CGUID+29, 42267, 741, 11, 2365, 1, 236, 0, 0, 0, -17.8958, -8.12408, -15.73877, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Garrosh Formation Bunny (Area: The Great Sea - Difficulty: 0) (Auras: )
-- (@CGUID+1033, 42268, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, -7, 23.1, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Garrosh's Airship (Area: The Great Sea - Difficulty: 0) (Auras: 78865 - Garrosh Airship FX, 63313 - Ride Vehicle) - !!! on transport - transport template not found !!!
-- (@CGUID+1034, 42257, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, 35, 35, 42, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Support Fleet (Area: The Great Sea - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+1035, 42258, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, 35, -35, 42, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Support Fleet (Area: The Great Sea - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+1036, 42206, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, 84, -42, 14, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Skyshredder (Area: The Great Sea - Difficulty: 0) (Auras: 78701 - Goblin Zeppelin Engines, 63313 - Ride Vehicle) - !!! on transport - transport template not found !!!
-- (@CGUID+1037, 50369, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, -70, -60, 40, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deathwing (Area: The Great Sea - Difficulty: 0) (Auras: 63313 - Ride Vehicle) - !!! on transport - transport template not found !!!
-- (@CGUID+1038, 42207, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, 42, -98, -14, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Heart of Orgrimmar (Area: The Great Sea - Difficulty: 0) (Auras: 78701 - Goblin Zeppelin Engines, 63313 - Ride Vehicle) - !!! on transport - transport template not found !!!
(@CGUID+30, 42246, 741, 11, 2365, 1, 236, 0, 0, 0, -17.8816, -10.278, -15.72467, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zeppelin Formation Bunny 03 (Area: The Great Sea - Difficulty: 0) (Auras: )
(@CGUID+31, 42255, 741, 11, 2365, 1, 236, 0, 0, 0, -17.8506, -9.56128, -15.74577, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Support Formation Bunny (Area: The Great Sea - Difficulty: 0) (Auras: )
(@CGUID+32, 51033, 741, 11, 2365, 1, 236, 0, 0, 0, -9.426493, -1.025291, -15.99072, 3.298672, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deathwing Zeppelin Ride Vehicle (Area: The Great Sea - Difficulty: 0) (Auras: )
-- (@CGUID+1042, 42205, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, 84, 42, 14, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Impervious (Area: The Great Sea - Difficulty: 0) (Auras: 78701 - Goblin Zeppelin Engines, 63313 - Ride Vehicle) - !!! on transport - transport template not found !!!
(@CGUID+33, 43868, 741, 11, 2365, 1, 236, 0, 0, 0, 9.27824, -12.2987, -16.60057, 2.460914, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zeppelin Explosion Bunny (Area: The Great Sea - Difficulty: 0) (Auras: 78905 - Spinning Out of Control State)
(@CGUID+34, 42243, 741, 11, 2365, 1, 236, 0, 0, 0, -17.4878, -4.66261, -15.80167, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Fergus Gearchum (Area: The Great Sea - Difficulty: 0)
-- (@CGUID+1045, 42204, UNKNOWN, 11, 2365, 1, 236, 0, 0, 0, 42, 98, -14, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- The Indomitable (Area: The Great Sea - Difficulty: 0) - !!! on transport - transport template not found !!!
(@CGUID+35, 42300, 741, 11, 2365, 1, 236, 0, 0, 0, 11.79519, -5.001086, -16.60061, 3.735005, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kor'kron Air Marine (Area: The Great Sea - Difficulty: 0)
(@CGUID+36, 45749, 741, 11, 2365, 1, 236, 0, 0, 0, 4.40083, -7.27264, -17.76497, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Aura Generator Bunny (Area: The Great Sea - Difficulty: 0) (Auras: 85358 - Transport Phase Bunny Spell)
(@CGUID+37, 51137, 741, 11, 2365, 1, 236, 0, 0, 0, 15.74312, -7.892086, -9.897807, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- <Internal> Horde Zeppelin Sound Bunny (Area: The Great Sea - Difficulty: 0) (Auras: 94225 - Twilight Skies: Zep Ambient Loop Sound, 94209 - Twilight Skies: Engine Loop Sound)
(@CGUID+38, 42576, 741, 11, 2365, 1, 236, 0, 0, 0, 3.78204, -1.01867, -17.76957, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Drake Rigging Bunny (Area: The Great Sea - Difficulty: 0) (Auras: )
(@CGUID+39, 42314, 741, 11, 2365, 1, 236, 0, 0, 0, 11.87956, -0.492997, -16.26089, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Air Defense Cannon (Area: The Great Sea - Difficulty: 0) (Auras: )
(@CGUID+40, 50964, 0, 11, 0, 1, 236, 0, 0, 0, -2385.123, -2781.815, -2.772678, 6.093308, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Chops (Area: 0 - Difficulty: 0) -- 6x only
(@CGUID+41, 45694, 0, 4922, 0, 1, 236, 0, 0, 0, -2650.832, -4911.332, 133.2503, 4.066617, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+42, 45511, 0, 4922, 0, 1, 236, 0, 0, 0, -2611.108, -4931.457, 144.6913, 3.907559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+43, 45694, 0, 4922, 0, 1, 236, 0, 0, 0, -2689.2, -4923.925, 137.3543, 5.151112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+44, 45694, 0, 4922, 0, 1, 236, 0, 0, 0, -2589.556, -4971.537, 132.8083, 3.268889, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+45, 45511, 0, 4922, 0, 1, 236, 0, 0, 0, -2723.939, -4956.323, 139.6534, 5.903189, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+46, 45510, 0, 4922, 0, 1, 236, 0, 0, 0, -2590.106, -5009.366, 134.1073, 2.7665, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+47, 45693, 0, 4922, 0, 1, 236, 0, 0, 0, -2722.859, -5002.255, 139.8613, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+48, 45511, 0, 4922, 0, 1, 236, 0, 0, 0, -2703.434, -5042.316, 145.1263, 0.9829037, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+49, 45511, 0, 4922, 0, 1, 236, 0, 0, 0, -2619.665, -5045.406, 145.8973, 2.156552, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+50, 45694, 0, 4922, 0, 1, 236, 0, 0, 0, -2662.523, -5058.573, 133.3713, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tentacle of Iso'rath (Area: 0 - Difficulty: 0) (Auras: 87237 - Generic Quest Invisibility 18)
(@CGUID+51, 51131, 0, 4922, 0, 1, 236, 0, 0, 0, -2526.526, -4438.812, 98.82122, 4.487787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wildhammer Homesteader (Area: 0 - Difficulty: 0)
(@CGUID+52, 51131, 0, 4922, 0, 1, 236, 0, 0, 0, -2502.906, -4484.389, 101.9383, 2.151757, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wildhammer Homesteader (Area: 0 - Difficulty: 0)
(@CGUID+53, 51131, 0, 4922, 0, 1, 236, 0, 0, 0, -2481.031, -4460.203, 91.31958, 0.2094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wildhammer Homesteader (Area: 0 - Difficulty: 0)
(@CGUID+54, 51131, 0, 4922, 0, 1, 236, 0, 0, 0, -2441.549, -4489.618, 85.89758, 2.042035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wildhammer Homesteader (Area: 0 - Difficulty: 0)
(@CGUID+55, 51131, 0, 4922, 0, 1, 236, 0, 0, 0, -2479.207, -4493.764, 97.58525, 2.017036, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wildhammer Homesteader (Area: 0 - Difficulty: 0)
(@CGUID+56, 51131, 0, 4922, 0, 1, 236, 0, 0, 0, -2447.575, -4483.5, 86.47533, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wildhammer Homesteader (Area: 0 - Difficulty: 0)
(@CGUID+57, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1918.352, -6179.872, 160.236, 4.398516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+58, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1868.224, -6327.347, 155.1239, 0.8894643, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+59, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1831.392, -6314.871, 162.6356, 0.8567601, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+60, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1848.841, -6307.877, 154.9402, 0.9425982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+61, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1956.278, -6297.665, 153.7861, 1.256728, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+62, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1980.433, -6275.702, 156.3436, 1.25702, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+63, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1856.899, -6361.179, 157.1186, 0.8909976, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+64, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1922.778, -6430.474, 148.0417, 0.8906103, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+65, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2003.9, -6379.11, 154.3552, 1.257455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+66, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1930.743, -6483.131, 158.4269, 0.8904108, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+67, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2074.171, -6461.426, 155.6923, 1.257279, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+68, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2060.411, -6432.68, 155.115, 1.256334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+69, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -1993.805, -6549.486, 148.0616, 4.0311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+70, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2039.68, -6583.967, 151.0265, 0.8901624, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+71, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2188.928, -6586.037, 171.0402, 0.4365832, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+72, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2072.659, -6635.819, 162.4696, 0.890892, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+73, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2100.319, -6663.085, 180.1969, 0.7670004, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+74, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2180.506, -6595.109, 177.4379, 0.6279011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+75, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2190.635, -6660.675, 182.312, 0.5236136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+76, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2094.384, -6694.928, 167.2773, 0.8912811, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+77, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2128.114, -6723.645, 180.7704, 0.8889149, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+78, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2178.723, -6735.435, 188.6958, 0.889169, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+79, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2219.102, -6763.262, 186.8693, 4.031921, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+80, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2347.648, -6756.252, 197.578, 0.5226876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+81, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2399.766, -6769.142, 198.4539, 0.5230706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+82, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2422.846, -6836.654, 198.644, 3.667135, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+83, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2298.856, -6899.221, 191.64, 0.8894643, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+84, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2309.924, -6869.263, 197.4965, 0.6804118, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+85, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2357.644, -6960.987, 192.2237, 0.6999373, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+86, 42516, 0, 4922, 308, 1, 236, 0, 0, 0, -2493.299, -6852.063, 208.5093, 3.665206, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: The Forbidding Sea - Difficulty: 0)
(@CGUID+87, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -2397.177, -6963.453, 197.2291, 0.5758175, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+88, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -2588.896, -6945.319, 215.9588, 6.247531, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+89, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -2633.915, -6941.927, 219.2313, 5.619071, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+90, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3093.513, -6701.757, 172.0891, 5.533939, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+91, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3004.644, -6674.323, 192.1062, 5.531398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+92, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3111.918, -6700.43, 172.9932, 5.532027, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+93, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3011.054, -6669.783, 226.2685, 2.26911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+94, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3032.264, -6627.893, 202.4448, 2.2691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+95, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3176.999, -6649.209, 174.4112, 5.532961, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+96, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3051.921, -6588.72, 217.7136, 2.268656, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+97, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3186.65, -6626.17, 255.493, 5.530931, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+98, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3175.686, -6563.495, 221.6156, 5.72418, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+99, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3137.94, -6553.526, 202.9993, 5.586997, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+100, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3140.813, -6512.449, 163.3281, 5.828018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+101, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3238.612, -6610.042, 226.5551, 5.532802, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+102, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3176.254, -6495.443, 169.271, 5.637601, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+103, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3257.868, -6506.082, 191.6282, 5.968132, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+104, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3238.127, -6548.439, 214.7365, 5.827561, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+105, 42516, 0, 4922, 0, 1, 236, 0, 0, 0, -3311.521, -6521.95, 198.1573, 5.969757, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Twilight Swarmer (Area: 0 - Difficulty: 0)
(@CGUID+106, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3907.17, -6514.07, 12.81793, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+107, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3929.58, -6524.33, 37.91513, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+108, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3896.65, -6505.06, 12.42693, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+109, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3936, -6528.5, 37.91803, 4.817109, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+110, 42603, 741, 4922, 5136, 1, 236, 0, 0, 0, -11.82407, -14.34003, -17.04284, 1.239184, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79428 - Parachute Holder) (possible waypoints or random movement)
(@CGUID+111, 42603, 741, 4922, 5136, 1, 236, 0, 0, 0, -11.89372, -1.482646, -16.85438, 4.852015, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79428 - Parachute Holder) (possible waypoints or random movement)
(@CGUID+112, 42603, 741, 4922, 5136, 1, 236, 0, 0, 0, 9.70767, -15.2628, -17.44627, 1.570796, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79428 - Parachute Holder) (possible waypoints or random movement)
(@CGUID+113, 42603, 741, 4922, 5136, 1, 236, 0, 0, 0, 9.84694, -0.555471, -17.50177, 4.660029, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79428 - Parachute Holder) (possible waypoints or random movement)
(@CGUID+114, 42603, 741, 4922, 5136, 1, 236, 0, 0, 0, -5.21494, -15.6542, -17.68167, 1.396263, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79428 - Parachute Holder) (possible waypoints or random movement)
(@CGUID+115, 42603, 741, 4922, 5136, 1, 236, 0, 0, 0, -5.51011, -0.325175, -17.58987, 4.782202, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Emergency Rampless Debarkation Device (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79428 - Parachute Holder) (possible waypoints or random movement)
(@CGUID+116, 43482, 0, 4922, 5136, 1, 229, 0, 0, 0, -3973.24, -6589.62, 2.121533, 1.27409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+117, 43187, 0, 4922, 5136, 1, 229, 0, 0, 0, -3975.2, -6593.06, 1.242993, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ornak (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+118, 43683, 0, 4922, 5136, 1, 229, 0, 0, 0, -3973.9, -6824.46, 37.7163, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+119, 43683, 0, 4922, 5136, 1, 229, 0, 0, 0, -3934.44, -6837.3, 26.78703, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+120, 43482, 0, 4922, 5136, 1, 229, 0, 0, 0, -3939.587, -6798.352, 6.863057, 2.119729, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+121, 43482, 0, 4922, 5136, 1, 229, 0, 0, 0, -3914.894, -6795.071, 9.076434, 2.422286, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+122, 42978, 0, 4922, 5336, 1, 229, 0, 0, 0, -3907.52, -6785.77, 10.04264, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Admiral Stonefist (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+123, 43683, 0, 4922, 5336, 1, 229, 0, 0, 0, -4012.65, -6891.47, 56.48208, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Remains of the Fleet - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+124, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3949.23, -6787.6, 7.620714, 0.01745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+125, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3936.75, -6798.7, 6.803904, 2.216568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+126, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3937.94, -6794.72, 6.936994, 4.206244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+127, 43186, 0, 4922, 5336, 1, 229, 0, 0, 0, -3930.45, -6790.05, 7.548433, 1.902409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Juice Gnugat (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+128, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3946.39, -6791.01, 7.414174, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+129, 43193, 0, 4922, 5336, 1, 229, 0, 0, 0, -3911.08, -6790.88, 9.541663, 2.076942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Warlord Krogg (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+130, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3911.95, -6779.08, 10.00018, 3.961897, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+131, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3943.88, -6799.52, 7.131594, 0.9948376, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+132, 43188, 0, 4922, 5336, 1, 229, 0, 0, 0, -3934.93, -6786.31, 6.953043, 0.8552113, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Horzog (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+133, 43192, 0, 4922, 5336, 1, 229, 0, 0, 0, -3914.96, -6797.35, 9.044493, 1.43117, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+134, 43482, 0, 4922, 5136, 1, 229, 0, 0, 0, -3978.59, -6589.78, 2.546403, 2.251475, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+135, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3953.271, -6535.589, 13.98444, 3.844026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+136, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3974.186, -6527.91, 13.6431, 5.011819, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+137, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3977.22, -6553.66, 11.08933, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+138, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3963.78, -6546.24, 13.00313, 1.884956, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+139, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4007.73, -6555.69, 11.87153, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+140, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3953.85, -6541.79, 13.96173, 2.565634, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+141, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3991.16, -6531.021, 14.37045, 0.1932041, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+142, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4003.11, -6514.15, 14.2464, 2.076942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+143, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3995.6, -6510.73, 14.38353, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+144, 43483, 0, 4922, 5136, 1, 229, 0, 0, 0, -3958.78, -6504.61, 16.73643, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Invisible Bunny Trigger - Chapter I Only (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+145, 43421, 0, 4922, 5136, 1, 229, 0, 0, 0, -4049.39, -6531.21, 15.3849, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Blacksmith (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+146, 43421, 0, 4922, 5136, 1, 229, 0, 0, 0, -4044.42, -6527.39, 15.39213, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Blacksmith (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+147, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3976.584, -6495.602, 14.80319, 4.056391, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+148, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3975.92, -6491.9, 16.13663, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+149, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4040.47, -6511.93, 14.61403, 5.532694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+150, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -4051.35, -6517.52, 14.40453, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+151, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4049.81, -6516.14, 14.47033, 4.520403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+152, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3926.626, -6489.895, 14.60243, 1.903032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+153, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3930.18, -6483.57, 14.49483, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+154, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3903.75, -6488.24, 16.37353, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+155, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3943.218, -6462.85, 14.63583, 2.133353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+156, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3938.9, -6456.4, 16.32483, 3.944444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+157, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -4054.61, -6476.99, 39.40483, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+158, 43190, 0, 4922, 5136, 1, 229, 0, 0, 0, -3892.94, -6473.44, 15.46543, 2.792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zaela (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+159, 43191, 0, 4922, 5136, 1, 229, 0, 0, 0, -3894.53, -6471.06, 15.46543, 3.577925, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gregor (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+160, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4095.7, -6502.36, 56.26233, 5.148721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+161, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -4063.8, -6477.4, 39.39003, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+162, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4064.94, -6475.06, 39.40133, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+163, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4053.746, -6432.268, 39.3361, 5.825421, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+164, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4106.88, -6499.64, 62.75293, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+165, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4100.75, -6482.47, 62.79993, 1.22173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+166, 43483, 0, 4922, 5136, 1, 229, 0, 0, 0, -3969.28, -6414.23, 22.81973, 1.082104, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Invisible Bunny Trigger - Chapter I Only (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+167, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3968.742, -6432.793, 20.05309, 5.045691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+168, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3930.467, -6408.656, 27.95636, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+169, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3924.77, -6402.8, 28.08703, 2.96706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+170, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3950.74, -6408.07, 28.81293, 1.762783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+171, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4008.329, -6415.495, 38.27458, 1.022815, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+172, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4029.56, -6406.71, 40.24313, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+173, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3924.32, -6367.33, 29.59193, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+174, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3950.475, -6342.314, 27.51623, 1.71714, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+175, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3910.16, -6356.949, 29.10942, 5.327964, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+176, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3966.11, -6350.24, 28.93143, 0.1570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+177, 43483, 0, 4922, 5136, 1, 229, 0, 0, 0, -4019.28, -6374.85, 37.14683, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Invisible Bunny Trigger - Chapter I Only (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+178, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3882.14, -6376.83, 28.91253, 2.722714, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+179, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3889.74, -6367.68, 29.06173, 3.647738, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+180, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3900.1, -6363.27, 28.9997, 0.6283185, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+181, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4041.48, -6361.91, 37.4708, 4.134498, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+182, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3911.63, -6338.37, 27.96533, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+183, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4058.1, -6399.28, 38.14803, 0.4363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+184, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4021.79, -6343.6, 37.96753, 5.689773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+185, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3925.82, -6327.28, 27.95833, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+186, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3909.06, -6333.24, 27.67933, 0.715585, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+187, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3915.02, -6321.6, 27.93503, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+188, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3936.19, -6316.89, 29.58763, 2.844887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+189, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -3938.91, -6309.99, 29.75663, 5.550147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+190, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3872.76, -6354.86, 29.06173, 5.934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+191, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3979.766, -6303.442, 27.48427, 4.920739, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+192, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3955.22, -6285.96, 51.86723, 3.560472, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+193, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3911.64, -6284.474, 28.9784, 2.344231, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+194, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3947.5, -6272.57, 51.82303, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+195, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3964.112, -6284.795, 27.28354, 4.439147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+196, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -3925.74, -6272.29, 29.06173, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+197, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3937.63, -6280.09, 51.89833, 0.01745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+198, 43421, 0, 4922, 5136, 1, 229, 0, 0, 0, -4009.51, -6316.49, 39.387, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Blacksmith (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+199, 43389, 0, 4922, 5136, 1, 229, 0, 0, 0, -4016.01, -6316.32, 39.38573, 4.904375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gorthul (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81204 - I am a Fake Flight Master)
(@CGUID+200, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -3998.42, -6270.96, 25.71843, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+201, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4030.5, -6328.02, 38.17843, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+202, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4053.22, -6274.19, 5.592594, 2.129302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+203, 43386, 0, 4922, 5136, 1, 229, 0, 0, 0, -4032.78, -6325.45, 37.97923, 5.270895, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+204, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4044.1, -6387.755, 37.90518, 2.269641, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+205, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4065.261, -6349.183, 37.7577, 0.3816632, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+206, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4063.6, -6388.03, 37.96293, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+207, 43483, 0, 4922, 5136, 1, 229, 0, 0, 0, -4067.02, -6395.5, 38.73263, 0.4363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Invisible Bunny Trigger - Chapter I Only (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+208, 43387, 0, 4922, 5136, 1, 229, 0, 0, 0, -4084.25, -6285.99, 6.116903, 0.2792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+209, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4093.35, -6277.78, 26.94283, 2.792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+210, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4095.44, -6269.24, 26.85773, 1.919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+211, 43390, 0, 4922, 5136, 1, 229, 0, 0, 0, -4102.31, -6285.98, 20.37153, 3.926991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+212, 43583, 0, 4922, 5336, 1, 238, 0, 0, 0, -4022.68, -6613.91, 56.42842, 1.413717, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Remains of the Fleet - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+213, 43583, 0, 4922, 5336, 1, 238, 0, 0, 0, -3907.9, -6575.38, 48.93633, 2.321288, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Remains of the Fleet - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+214, 43601, 0, 4922, 5336, 1, 238, 0, 0, 0, -3939.86, -6524.17, 37.96823, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Remains of the Fleet - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+215, 43602, 0, 4922, 5336, 1, 238, 0, 0, 0, -4025.03, -6554.25, 14.80603, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Small Dragonmaw Fires (Area: Remains of the Fleet - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+216, 43582, 0, 4922, 5336, 1, 238, 0, 0, 0, -3977.93, -6593.3, 1.406653, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ornak (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+217, 43601, 0, 4922, 5336, 1, 238, 0, 0, 0, -4056.67, -6534.89, 15.39183, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Remains of the Fleet - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+218, 43602, 0, 4922, 5336, 1, 238, 0, 0, 0, -3978.72, -6487.78, 16.02463, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Small Dragonmaw Fires (Area: Remains of the Fleet - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+219, 43579, 0, 4922, 5336, 1, 238, 0, 0, 0, -3976.32, -6590.98, 1.979983, 2.216568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Remains of the Fleet - Difficulty: 0)
(@CGUID+220, 43601, 0, 4922, 5336, 1, 238, 0, 0, 0, -3933.18, -6511.36, 14.50383, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Remains of the Fleet - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+221, 43602, 0, 4922, 5336, 1, 238, 0, 0, 0, -4026.72, -6507.86, 16.99143, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Small Dragonmaw Fires (Area: Remains of the Fleet - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+222, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4005.428, -6568.092, 8.897085, 3.987572, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+223, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3979.87, -6572.44, 9.206993, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+224, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3999.588, -6572.7, 8.681272, 4.689542, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+225, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4011.047, -6572.516, 8.080863, 0.491195, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+226, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3992.02, -6565.455, 10.14973, 6.089566, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+227, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3988.424, -6566.16, 10.23153, 4.759297, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+228, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3999.67, -6576.29, 7.871284, 1.675516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+229, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4007.814, -6570.786, 8.100816, 1.305296, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+230, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3988.296, -6568.869, 9.499291, 1.617814, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+231, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3973.014, -6557.941, 10.87099, 4.601114, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+232, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3974.299, -6561.504, 10.63093, 5.125051, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+233, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3991.664, -6576.784, 7.355686, 4.719124, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+234, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4006.88, -6567.35, 8.976363, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+235, 43601, 0, 4922, 5136, 1, 238, 0, 0, 0, -3884.27, -6479.79, 29.79173, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+236, 43602, 0, 4922, 5136, 1, 238, 0, 0, 0, -4045.8, -6478.08, 39.47903, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Small Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+237, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4005.694, -6564.062, 10.08357, 4.366142, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+238, 43583, 0, 4922, 5136, 1, 238, 0, 0, 0, -4118.54, -6544.38, 72.40352, 1.169371, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+239, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3972.83, -6564.86, 10.38383, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+240, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3973.421, -6561.581, 10.69871, 4.890742, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+241, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4007.732, -6567.231, 8.995413, 4.689316, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+242, 43583, 0, 4922, 5136, 1, 238, 0, 0, 0, -3837.96, -6497.36, 46.18143, 2.949606, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Goblin Barrage Balloon (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+243, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3991.64, -6580.3, 6.316393, 1.675516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+244, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4013.044, -6533.378, 14.16232, 4.655323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+245, 43601, 0, 4922, 5136, 1, 238, 0, 0, 0, -4102.34, -6495.35, 56.28753, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+246, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4008.64, -6548.58, 12.31933, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+247, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3989.2, -6537.106, 13.3897, 3.276854, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+248, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3991.007, -6530.224, 14.35669, 1.887732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+249, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3992.592, -6526.923, 14.17241, 5.159996, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+250, 43601, 0, 4922, 5136, 1, 238, 0, 0, 0, -4099.87, -6498.26, 62.80233, 4.24115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+251, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3986.034, -6537.037, 13.22005, 0.02208512, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+252, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4016.349, -6531.795, 13.7584, 4.088078, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+253, 43602, 0, 4922, 5136, 1, 238, 0, 0, 0, -3907.48, -6426.62, 28.08673, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Small Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+254, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4015.111, -6530.358, 13.93666, 5.312381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+255, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3974.446, -6496.74, 14.6198, 5.010522, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+256, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3981.003, -6499.334, 14.87395, 0.650668, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+257, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3975.08, -6495.02, 15.01293, 5.480334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+258, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3978.086, -6497.114, 14.96575, 0.6083348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+259, 43602, 0, 4922, 5136, 1, 238, 0, 0, 0, -4073.64, -6405.32, 62.94773, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Small Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+260, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3950.907, -6496.61, 15.92017, 3.486952, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+261, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3957.367, -6486.575, 13.98816, 0.8209646, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury) (possible waypoints or random movement)
(@CGUID+262, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3954.255, -6497.815, 16.80543, 5.604481, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+263, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3943.13, -6484.561, 13.97559, 4.119123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+264, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3951.41, -6500.11, 16.79083, 1.204277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+265, 43601, 0, 4922, 5136, 1, 238, 0, 0, 0, -4101.65, -6401.67, 70.33584, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+266, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3945.18, -6487.6, 14.05273, 1.134464, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+267, 43601, 0, 4922, 5136, 1, 238, 0, 0, 0, -4125.38, -6431.09, 65.85194, 0.4014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+268, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -4031.077, -6443.891, 38.64389, 4.501827, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+270, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4078.276, -6468.452, 38.02157, 3.264291, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+271, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4055.542, -6459.083, 39.68114, 3.150035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+272, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -4054.792, -6455.545, 38.8103, 5.350319, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+273, 43601, 0, 4922, 5136, 1, 238, 0, 0, 0, -3888.24, -6390.4, 33.15723, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Fires (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81555 - Cosmetic - Tree Fire 2 (With Sound))
(@CGUID+274, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4053.855, -6459.084, 39.55687, 1.829651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+275, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4052.18, -6458.113, 38.88646, 0.5378435, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+276, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4018.778, -6422.751, 37.68005, 4.051395, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury) (possible waypoints or random movement)
(@CGUID+277, 43189, 0, 4922, 5136, 1, 238, 0, 0, 0, -4111.87, -6416.01, 37.78813, 0.4537856, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Warchief Mor'ghor (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+278, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -4011.727, -6396.163, 37.79636, 3.708469, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+279, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4028.576, -6381.589, 37.44508, 6.20635, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+280, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4030.261, -6381.331, 37.52699, 1.185768, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+281, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -4011.105, -6400.317, 37.80634, 5.024933, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+282, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -4028.887, -6377.94, 37.76198, 4.157207, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+283, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4028.272, -6376.419, 37.59807, 4.328041, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+284, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4009.753, -6393.314, 37.99516, 4.47419, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+285, 43678, 0, 4922, 5136, 1, 238, 0, 0, 0, -4061.988, -6393.918, 38.01872, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Felblade (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+286, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4105.127, -6363.702, 37.91845, 3.730712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+287, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3971.112, -6432.634, 20.76233, 6.073723, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+288, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3969.256, -6427.306, 20.93292, 4.884035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+289, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3971.679, -6429.04, 21.30426, 4.86889, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+290, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4051.83, -6360.02, 39.27883, 5.934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+291, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3965.245, -6431.968, 19.58659, 2.835507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+292, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4050.622, -6363.482, 39.45652, 1.906466, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+293, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3968.633, -6430.897, 20.45466, 2.594036, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+294, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4049.59, -6366.14, 39.50403, 5.707227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+295, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4025.444, -6376.732, 37.45338, 3.479022, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+296, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -4111.548, -6368.06, 38.22129, 3.749113, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+297, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3965.122, -6430.216, 19.72282, 1.576125, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+298, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3994.38, -6363.616, 34.85728, 5.707191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+299, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4001.271, -6358.924, 36.56598, 5.401802, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury) (possible waypoints or random movement)
(@CGUID+300, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3947.212, -6383.87, 27.29226, 0.5274084, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+301, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3923.92, -6399.42, 28.08703, 2.6529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+302, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3924.851, -6398.172, 28.0055, 2.152645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+303, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3924.6, -6396.4, 28.09123, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+304, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3946.88, -6371.136, 27.37432, 5.579013, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury) (possible waypoints or random movement)
(@CGUID+305, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3958.02, -6332.746, 27.33614, 3.880415, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+306, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3955.098, -6334.405, 27.54411, 1.532475, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+307, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3955.989, -6330.855, 27.62858, 4.964478, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+308, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4011.5, -6317.78, 39.38333, 4.939282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+309, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3955.068, -6333.634, 27.71965, 5.067014, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+310, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3921.514, -6396.656, 28.0055, 3.996104, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+311, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3954.564, -6331.087, 27.74043, 0.1312302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+312, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3956.519, -6331.357, 27.35512, 5.148828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+313, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3962.112, -6341.054, 28.30038, 4.829234, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury) (possible waypoints or random movement)
(@CGUID+314, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3923.988, -6377.52, 27.47783, 5.686853, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury) (possible waypoints or random movement)
(@CGUID+315, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3928.454, -6334.801, 27.43787, 0.9876118, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+316, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3925.94, -6337.47, 27.39183, 4.417973, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+317, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3927.004, -6340.979, 27.4264, 1.27638, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+318, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3969.58, -6295.395, 27.60911, 4.057073, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+319, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3925.235, -6341.067, 27.7013, 6.246338, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+320, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3929.401, -6336.261, 27.40051, 5.947032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+321, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3886.26, -6520.79, 3.020643, 2.775074, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+322, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3880.933, -6511.24, 4.566568, 5.961536, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+323, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3881.64, -6518.89, 2.034203, 2.722714, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+324, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3877.53, -6511.03, 2.730153, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+325, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3884.475, -6516.732, 3.706492, 5.7575, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+326, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3888.966, -6518.917, 4.637684, 5.67765, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+327, 43576, 0, 4922, 5136, 1, 238, 0, 0, 0, -3898.48, -6472.47, 15.46543, 5.323254, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gorthul (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+328, 43580, 0, 4922, 5136, 1, 238, 0, 0, 0, -3898.99, -6475.69, 15.46543, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gregor (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+329, 43581, 0, 4922, 5136, 1, 238, 0, 0, 0, -3896.32, -6474.26, 15.46543, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zaela (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+330, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -3886.093, -6525.264, 1.480174, 2.459114, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+331, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3888.648, -6523.188, 3.076435, 0.787439, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+332, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3986.568, -6284.015, 27.54192, 3.385811, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+333, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -3990.12, -6284.9, 27.34163, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+334, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4051.391, -6267.927, 5.375351, 3.117646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82836 - Blood Fury)
(@CGUID+335, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4063.83, -6272.5, 5.057213, 6.056293, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+336, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4060.335, -6272.168, 5.017675, 3.236169, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+337, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4049.74, -6257.07, 3.927563, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+338, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4055.04, -6267.84, 5.027703, 6.038839, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+339, 43579, 0, 4922, 5136, 1, 238, 0, 0, 0, -4047.956, -6266.742, 5.868059, 3.473968, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+340, 43575, 0, 4922, 5136, 1, 238, 0, 0, 0, -4046.422, -6258.593, 4.270905, 2.711119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Enforcer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+341, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3996.25, -6510.94, 14.38823, 5.096361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+342, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3951.41, -6500.11, 16.79083, 1.204277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+343, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3927.26, -6488.22, 14.87923, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+344, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3929.32, -6464.14, 14.51153, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+345, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3972.56, -6407.9, 23.77143, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+346, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4049.729, -6460.65, 39.18114, 1.305818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+347, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4000.015, -6359.27, 36.33229, 5.480025, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+348, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -4051.83, -6360.02, 39.27883, 5.934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+349, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3975.08, -6495.02, 15.01293, 5.480334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+350, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3974.87, -6408.86, 23.88433, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+351, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3999.92, -6392.91, 39.00453, 2.076942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+352, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3971.29, -6493.46, 14.47683, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+353, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3933.17, -6409.9, 27.83673, 1.762783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+354, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4026.5, -6538.81, 14.11203, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+355, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3927.26, -6488.22, 14.87923, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+356, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3951.45, -6534.05, 14.08613, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+357, 43578, 0, 4922, 5136, 1, 238, 0, 0, 0, -3996.25, -6510.94, 14.38823, 5.096361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+358, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3999.36, -6512.83, 14.34653, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+359, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3944.83, -6438.41, 17.06823, 3.665191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+360, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3993.73, -6381.8, 37.84643, 2.722714, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+361, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3953.01, -6453.84, 14.70503, 1.989675, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+362, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3999.8, -6373.25, 36.44253, 4.206244, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+363, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3924.6, -6396.4, 28.09123, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+364, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -3951.41, -6500.11, 16.79083, 1.204277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+365, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3992.507, -6525.331, 13.92634, 1.668523, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+366, 43394, 0, 4922, 5136, 1, 238, 0, 0, 0, -3906.772, -6383.657, 27.8805, 3.6539, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warlock (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+367, 43939, 0, 4922, 5136, 1, 238, 0, 0, 0, -4099.25, -6394.29, 38.72333, 3.01942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zaela (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+368, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4056.37, -6470.08, 39.56463, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+369, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4049.59, -6366.14, 39.50403, 5.707227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+370, 43577, 0, 4922, 5136, 1, 238, 0, 0, 0, -4021.41, -6342.68, 37.98033, 5.916666, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+371, 44024, 0, 4922, 5136, 1, 247, 0, 0, 0, -4051.87, -6327.38, 38.25563, 5.480334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Artesh (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+372, 44026, 0, 4922, 5136, 1, 247, 0, 0, 0, -4042.7, -6327.03, 44.68103, 2.565634, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Shaman (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+373, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -4117.42, -6403.92, 87.59414, 2.129302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+374, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4020.77, -6339.607, 37.94297, 2.861385, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+375, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4073.99, -6344.74, 37.37933, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+376, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4067.6, -6374.78, 38.66243, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+377, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4023.34, -6341.94, 37.97083, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+378, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4024.608, -6430.384, 37.62182, 3.946867, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+379, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4064.82, -6389.72, 37.96293, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+380, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3993.5, -6372.69, 35.70003, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+381, 44042, 0, 4922, 5136, 1, 247, 0, 0, 0, -4029.27, -6352.05, 37.66273, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ornak (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+382, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4053.11, -6414.1, 38.50193, 2.129302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+383, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4061.57, -6398.32, 38.10643, 0.4712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+384, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -4109.66, -6488.39, 62.81393, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+385, 44026, 0, 4922, 5136, 1, 247, 0, 0, 0, -4054.63, -6317.74, 44.99503, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Shaman (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+386, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4103.89, -6484.06, 62.77093, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+387, 44026, 0, 4922, 5136, 1, 247, 0, 0, 0, -4046.34, -6318.9, 44.92623, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Shaman (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+388, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -4072.26, -6417.6, 62.93533, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+389, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4090.07, -6486.67, 39.39363, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+390, 44026, 0, 4922, 5136, 1, 247, 0, 0, 0, -4055.86, -6323.37, 44.91063, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Shaman (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+391, 44026, 0, 4922, 5136, 1, 247, 0, 0, 0, -4055.72, -6328.47, 44.29893, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Shaman (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+392, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3994.57, -6355.27, 34.79513, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+393, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -4097.34, -6283.27, 26.88773, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+394, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4063.451, -6450.054, 37.14638, 3.596327, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+395, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -4058.71, -6538.88, 15.23033, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+396, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -3952.34, -6277.57, 51.90323, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+397, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -3932.08, -6519.59, 48.19663, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+398, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -3904.28, -6421.11, 28.08703, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+399, 43958, 0, 4922, 5136, 1, 247, 0, 0, 0, -4024.64, -6399.16, 38.27783, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+400, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4035.35, -6360.32, 37.57843, 5.166174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+401, 43958, 0, 4922, 5136, 1, 247, 0, 0, 0, -4044.59, -6391.28, 37.99183, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+402, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4055.84, -6382.81, 37.96353, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+403, 43958, 0, 4922, 5136, 1, 247, 0, 0, 0, -4010.01, -6362.55, 37.54123, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+404, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4041.73, -6364.15, 37.69393, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+405, 43943, 0, 4922, 5136, 1, 247, 0, 0, 0, -4020.82, -6379.41, 37.25293, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Garrosh Hellscream (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+406, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4003.54, -6390.99, 38.72963, 2.565634, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+407, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4035.01, -6396.13, 38.28943, 0.9773844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+408, 43958, 0, 4922, 5136, 1, 247, 0, 0, 0, -4058.73, -6397.1, 38.11163, 2.007129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+409, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4051.11, -6393.89, 37.96943, 2.007129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+410, 43958, 0, 4922, 5136, 1, 247, 0, 0, 0, -4004.85, -6367.52, 37.10713, 3.543018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+411, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4008.1, -6395.59, 38.14343, 2.234021, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+412, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4002.07, -6384.49, 38.22863, 2.932153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+413, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4062.19, -6386.71, 37.97383, 5.410521, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+414, 43958, 0, 4922, 5136, 1, 247, 0, 0, 0, -4048.74, -6377.64, 37.97633, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Merchant (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+415, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4015.98, -6358.97, 37.76423, 4.34587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 49414 - Generic Quest Invisibility 1, 82259 - Horde Banner)
(@CGUID+416, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3971.907, -6424.423, 21.75295, 1.706523, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+417, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3966.901, -6415.542, 22.57443, 4.600062, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+418, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3941.576, -6390.79, 27.14311, 3.586468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+419, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3970.19, -6367.89, 29.62133, 0.1919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+420, 44003, 0, 4922, 5136, 1, 247, 0, 0, 0, -3886.67, -6481.69, 29.68123, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Smoke (Area: Dragonmaw Port - Difficulty: 0) (Auras: 69494 - Cosmetic - Billowing Smoke Cloud)
(@CGUID+421, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3971.05, -6350.07, 30.28963, 0.03490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+422, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3931.916, -6370.654, 27.85213, 2.46264, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+423, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4008.64, -6285.41, 27.59053, 2.373648, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+424, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3950.563, -6330.928, 29.22775, 2.401418, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+425, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3943.08, -6317.64, 29.6664, 5.174013, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+426, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3986.666, -6291.612, 27.6505, 5.091541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+427, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3914.79, -6333.23, 27.55113, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+428, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3960.06, -6269.9, 28.3722, 2.983626, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+429, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3918.273, -6330.797, 27.46188, 0.3575193, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+430, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3987.44, -6258.73, 29.47303, 0.5759587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+431, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3917.21, -6339.81, 27.92703, 3.717551, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+432, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3960.94, -6280.37, 29.98333, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+433, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3943.36, -6295.89, 29.35113, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+434, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3924.42, -6326.44, 28.03453, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+435, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4001.18, -6269.44, 24.94533, 2.6529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+436, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3936.73, -6281.55, 45.36413, 3.525565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+437, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3953.24, -6291.83, 29.72083, 2.792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+438, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3948.26, -6290.14, 45.36413, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+439, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3916.55, -6322.14, 27.95463, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+440, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3994.84, -6254.05, 29.74693, 0.2792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+441, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3922.319, -6332.688, 27.47536, 3.842993, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+442, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3911.15, -6352.36, 29.01093, 1.117011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+443, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3908.34, -6337.21, 27.98963, 0.7679449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+444, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3919.91, -6295.59, 29.06173, 2.321288, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+445, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3942.89, -6266.06, 29.06173, 4.34587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+446, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4083.05, -6268.05, 5.305664, 4.939282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+447, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4098.3, -6269.78, 20.40373, 5.8294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+448, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4074.57, -6245.16, 1.396063, 2.775074, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+449, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4101.25, -6274.82, 26.85153, 2.670354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+450, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3886.06, -6342.81, 29.06173, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+451, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3873.97, -6365.07, 29.06173, 4.590216, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+452, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3871.61, -6379.47, 29.06173, 2.879793, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+453, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3909.17, -6389.69, 27.98383, 4.817109, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+454, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3922.99, -6458.06, 16.22373, 5.201081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+455, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3933.44, -6504.85, 14.50383, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+456, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3959.046, -6477.83, 14.31626, 2.597553, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+457, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3921.4, -6487.39, 16.21263, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+458, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3972.78, -6521.515, 13.67783, 1.827289, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+459, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3965.619, -6517.093, 14.13674, 4.924047, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+460, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3953.615, -6531.285, 13.94173, 3.196568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 82334 - Orc Carrying Stone Block)
(@CGUID+461, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3992.07, -6525.795, 13.9191, 3.281085, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 81245 - Orc Carrying Logs)
(@CGUID+462, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4016.26, -6504.43, 16.43593, 0.8901179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+463, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3937.55, -6512.29, 37.96823, 4.415683, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+464, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3929.22, -6520.77, 37.88893, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+465, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3946.71, -6519.01, 31.42913, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+466, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3911.81, -6515.67, 14.26743, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+467, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3937.76, -6508.9, 14.50503, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+468, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3941.28, -6528.06, 37.88193, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+469, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -3973.85, -6551.63, 11.12503, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+470, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -3970.09, -6552.65, 11.41193, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+471, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4107.71, -6499.22, 62.75303, 3.996804, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+472, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4047.11, -6526.39, 15.36623, 5.148721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+473, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4095.07, -6501.42, 56.26803, 5.131268, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+474, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4069.42, -6529.56, 14.91173, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+475, 43941, 0, 4922, 5136, 1, 247, 0, 0, 0, -4015.14, -6558.4, 12.58673, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+476, 44002, 0, 4922, 5136, 1, 247, 0, 0, 0, -4007.4, -6557.55, 11.64443, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+477, 49562, 0, 4922, 0, 1, 169, 0, 0, 0, -4035.004, -6269.519, 10.70274, 3.033945, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+478, 49567, 0, 4922, 0, 1, 169, 0, 0, 0, -3988.042, -6303.905, 29.86776, 4.660029, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: 0 - Difficulty: 0)
(@CGUID+479, 48689, 0, 4922, 0, 1, 169, 0, 0, 0, -3959.356, -6323.252, 27.48335, 3.570187, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Highlands Mouse (Area: 0 - Difficulty: 0)
(@CGUID+480, 47174, 0, 4922, 0, 1, 169, 0, 0, 0, -4011.67, -6326.58, 39.39233, 4.660029, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gorthul (Area: 0 - Difficulty: 0)
(@CGUID+481, 49562, 0, 4922, 0, 1, 169, 0, 0, 0, -4027.231, -6317.499, 69.8851, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: 0 - Difficulty: 0)
(@CGUID+482, 42775, 0, 4922, 0, 1, 169, 0, 0, 0, -4072.413, -6265.332, 5.057204, 2.792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bilgewater Dockworker (Area: 0 - Difficulty: 0) (Auras: 79841 - Goblin Holding a Rivet Gun)
(@CGUID+483, 49547, 0, 4922, 0, 1, 169, 0, 0, 0, -3947.064, -6311.024, 29.74969, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Frenk (Area: 0 - Difficulty: 0)
(@CGUID+484, 49562, 0, 4922, 0, 1, 169, 0, 0, 0, -4027.655, -6312.552, 69.88123, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: 0 - Difficulty: 0)
(@CGUID+485, 49562, 0, 4922, 0, 1, 169, 0, 0, 0, -3943.031, -6321.175, 29.87924, 4.13643, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: 0 - Difficulty: 0)
(@CGUID+486, 49562, 0, 4922, 0, 1, 169, 0, 0, 0, -3957.167, -6302.84, 29.87924, 3.263766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: 0 - Difficulty: 0)
(@CGUID+487, 49562, 0, 4922, 5136, 1, 247, 0, 0, 0, -4029.814, -6332.549, 37.97685, 4.904375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+488, 49562, 0, 4922, 5136, 1, 247, 0, 0, 0, -4035.682, -6332.944, 38.01312, 4.869469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+489, 48689, 0, 4922, 5136, 1, 247, 0, 0, 0, -4006.725, -6340.937, 38.29737, 6.143568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Highlands Mouse (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+490, 44050, 0, 4922, 5136, 1, 247, 0, 0, 0, -4050.3, -6322.54, 38.25563, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Portal to Orgrimmar (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+491, 42775, 0, 4922, 5136, 1, 169, 0, 0, 0, -4088.25, -6288.691, 7.317355, 5.759586, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bilgewater Dockworker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79841 - Goblin Holding a Rivet Gun)
(@CGUID+492, 48535, 763, 4922, 5136, 1, 169, 0, 0, 0, -12.05273, -6.253418, -16.3745, 1.525331, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Krazzworks Sky Marshall (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+493, 48535, 763, 4922, 5136, 1, 169, 0, 0, 0, 7.3889, -7.71648, -23.53657, 3.246312, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Krazzworks Sky Marshall (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+494, 48535, 763, 4922, 5136, 1, 169, 0, 0, 0, 6.63632, -3.07199, -17.71427, 1.22173, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Krazzworks Sky Marshall (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+495, 42775, 0, 4922, 5136, 1, 169, 0, 0, 0, -4101.446, -6310.276, 19.09839, 2.740167, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bilgewater Dockworker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+496, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4046.83, -6372.167, 38.06984, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+497, 46764, 763, 4922, 5136, 1, 169, 0, 0, 0, 4.15988, -11.1731, -17.82867, 3.368485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Captain Smoldersmitten (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+498, 42775, 0, 4922, 5136, 1, 169, 0, 0, 0, -4092.396, -6306.646, 19.31345, 1.989675, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bilgewater Dockworker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+499, 42775, 0, 4922, 5136, 1, 169, 0, 0, 0, -4096.245, -6287.745, 5.10198, 1.989675, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Bilgewater Dockworker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+500, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4068.101, -6411.583, 39.73769, 5.550147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+501, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -3958.808, -6310.993, 29.85325, 4.823185, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+502, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4077.116, -6392.299, 39.73769, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+503, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4082.076, -6394.092, 39.73769, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+504, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4033.97, -6399.749, 38.53699, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+505, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -3931.814, -6361.905, 29.87367, 3.700098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+506, 50456, 0, 4922, 5136, 1, 169, 0, 0, 0, -3919.505, -6405.743, 28.08708, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Hortak Kenzo (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+507, 50457, 0, 4922, 5136, 1, 169, 0, 0, 0, -3916.411, -6398.297, 28.08708, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Brot (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+508, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -3924.467, -6389.479, 29.73655, 2.75762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+509, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3946.413, -6405.95, 28.38717, 0.08726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+510, 50172, 0, 4922, 5136, 1, 169, 0, 0, 0, -3912.156, -6401.467, 28.08708, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Threm Blackscalp (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+511, 50433, 0, 4922, 5136, 1, 169, 0, 0, 0, -3914.587, -6406.019, 28.08708, 2.094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Aristaleon Sunweaver (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+512, 49554, 0, 4922, 5136, 1, 169, 0, 0, 0, -4007.2, -6424.113, 38.13563, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kanath (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+513, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3939.335, -6437.499, 16.547, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+514, 49498, 0, 4922, 5136, 1, 169, 0, 0, 0, -4009.872, -6439.905, 41.42448, 1.675516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Innkeeper Lutz (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+515, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -3960.361, -6449.665, 17.11443, 1.78837, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+516, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3942.969, -6470.429, 14.32487, 1.248701, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+517, 45439, 0, 4922, 5136, 1, 169, 0, 0, 0, -3939.836, -6461.549, 14.75817, 3.157186, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cockroach (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+518, 45987, 0, 4922, 5136, 1, 169, 0, 0, 0, -3845.608, -6330.817, 25.26819, 0.9985043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Defender (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+519, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4007.603, -6431.071, 41.42026, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+520, 49572, 0, 4922, 5136, 1, 169, 0, 0, 0, -3998.142, -6454.944, 41.41826, 4.590216, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+521, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -3920.205, -6484.043, 17.28573, 2.96706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+522, 50165, 0, 4922, 5136, 1, 169, 0, 0, 0, -3888.913, -6474.241, 18.5182, 3.368485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gregory Kauffman (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+523, 49572, 0, 4922, 5136, 1, 169, 0, 0, 0, -4011.293, -6462.128, 41.40435, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+524, 50461, 0, 4922, 5136, 1, 169, 0, 0, 0, -4004.137, -6462.293, 41.40711, 4.921828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Marlow Harston (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+525, 50146, 0, 4922, 5136, 1, 169, 0, 0, 0, -3892.674, -6483.814, 18.54453, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Agatian Fallanos (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+526, 49572, 0, 4922, 5136, 1, 169, 0, 0, 0, -4000.554, -6466.729, 49.24205, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: 34664 - Sleep Visual - Flavor)
(@CGUID+527, 50248, 0, 4922, 5136, 1, 169, 0, 0, 0, -3888.769, -6477.689, 18.50931, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Una Kobuna (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+528, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3976.505, -6490.46, 15.59157, 2.159825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+529, 50459, 0, 4922, 5136, 1, 169, 0, 0, 0, -3888.757, -6480.962, 18.51713, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Victor Quivias (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+530, 50462, 0, 4922, 5136, 1, 169, 0, 0, 0, -3892.625, -6472.005, 18.54486, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Digel East Nickens (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+531, 49506, 0, 4922, 5136, 1, 169, 0, 0, 0, -4008.177, -6465.628, 41.41748, 1.58825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Cerie Bowden (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+532, 49519, 0, 4922, 5136, 1, 169, 0, 0, 0, -4006.389, -6457.472, 41.02163, 2.6529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lizzy "Lemons" (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+533, 49572, 0, 4922, 5136, 1, 169, 0, 0, 0, -3998.606, -6458.63, 41.42027, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+534, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3897.883, -6474.318, 18.31026, 3.372128, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 92372 - Orc Carrying Horde Crate)
(@CGUID+535, 49569, 0, 4922, 5136, 1, 169, 0, 0, 0, -3931.635, -6540.617, 14.40488, 2.094951, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Porter (Area: Dragonmaw Port - Difficulty: 0) (Auras: 92372 - Orc Carrying Horde Crate) (possible waypoints or random movement)
(@CGUID+536, 2110, 0, 4922, 5136, 1, 169, 0, 0, 0, -3988.768, -6511.209, 14.03511, 5.608445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Black Rat (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+537, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3929.788, -6517.518, 14.50378, 4.468043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+538, 49549, 0, 4922, 5136, 1, 169, 0, 0, 0, -4016.918, -6507.592, 15.83025, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Jodan (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+539, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3995.622, -6493.856, 15.83025, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+540, 50460, 0, 4922, 5136, 1, 169, 0, 0, 0, -4010.719, -6501.42, 15.83025, 5.201081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zim Bamzabble (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+541, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -3992.702, -6519.303, 13.8441, 4.401241, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 92372 - Orc Carrying Horde Crate)
(@CGUID+542, 50375, 0, 4922, 5136, 1, 169, 0, 0, 0, -4023.385, -6510.887, 15.83025, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Kuldar Steeltooth (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+543, 49570, 0, 4922, 5136, 1, 169, 0, 0, 0, -3977.576, -6551.887, 16.99825, 3.473205, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+544, 49571, 0, 4922, 5136, 1, 169, 0, 0, 0, -3977.026, -6553.309, 16.22566, 2.129302, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Shaman (Area: Dragonmaw Port - Difficulty: 0) (Auras: 13236 - Nature Channeling) (possible waypoints or random movement)
(@CGUID+545, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -3980.861, -6540.321, 16.10161, 2.251475, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+546, 49570, 0, 4922, 5136, 1, 169, 0, 0, 0, -3982.729, -6557.028, 16.309, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+547, 49570, 0, 4922, 5136, 1, 169, 0, 0, 0, -3976.674, -6558.212, 17.55667, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+548, 48689, 0, 4922, 5136, 1, 169, 0, 0, 0, -4009.126, -6535.143, 14.04573, 1.654608, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Highlands Mouse (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+549, 49570, 0, 4922, 5136, 1, 169, 0, 0, 0, -3988.564, -6552.753, 17.55667, 1.43117, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0) (Auras: )
(@CGUID+550, 49570, 0, 4922, 5136, 1, 169, 0, 0, 0, -3984.858, -6558.92, 16.309, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Wounded Axebite Warrior (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+551, 49569, 0, 4922, 5136, 1, 169, 0, 0, 0, -4023.662, -6566.96, 14.72784, 6.102337, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Dragonmaw Porter (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+552, 49557, 0, 4922, 5136, 1, 169, 0, 0, 0, -4053.901, -6521.965, 15.56927, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dakam (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+553, 49551, 0, 4922, 5136, 1, 169, 0, 0, 0, -4053.785, -6527.059, 15.37534, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Grizz (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+554, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -4101.143, -6477.264, 39.78838, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+555, 48689, 0, 4922, 5136, 1, 169, 0, 0, 0, -4078.899, -6469.705, 38.8963, 4.485883, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Highlands Mouse (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+556, 49567, 0, 4922, 5136, 1, 169, 0, 0, 0, -4053.587, -6462.618, 39.79681, 4.206244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Worker (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+557, 44169, 0, 4922, 5136, 1, 169, 0, 0, 0, -4084.17, -6406.63, 40.08133, 0.4363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Zaela (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+558, 49562, 0, 4922, 5136, 1, 169, 0, 0, 0, -4072.964, -6414.035, 39.73769, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Dragonmaw Guard (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+559, 48535, 762, 4922, 5136, 1, 169, 0, 0, 0, -15.9296, -10.8046, -15.32037, 4.258604, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Krazzworks Sky Marshall (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+560, 46763, 762, 4922, 5136, 1, 169, 0, 0, 0, 4.26206, -11.6361, -17.82397, 3.420845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Captain Fizzlesneer (Area: Dragonmaw Port - Difficulty: 0)
(@CGUID+561, 48535, 762, 4922, 5136, 1, 169, 0, 0, 0, -1.119912, -2.805727, -17.92167, 6.221152, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Krazzworks Sky Marshall (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+562, 48535, 762, 4922, 5136, 1, 169, 0, 0, 0, 2.31688, -7.91102, -23.63947, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Krazzworks Sky Marshall (Area: Dragonmaw Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+563, 42775, 0, 4922, 5136, 1, 169, 0, 0, 0, -4135.477, -6295.187, 3.450411, 3.990831, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Bilgewater Dockworker (Area: Dragonmaw Port - Difficulty: 0) (Auras: 79756 - Goblin Carrying a Metal Crate)

UPDATE `creature` SET `terrainSwapMap`= 736 WHERE `PhaseId` IN (229,238,247) AND `guid` BETWEEN @CGUID+0 AND @CGUID+563 AND `map`=0;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+563;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+2, 0, 0, 33619968, 1, 0, 0, 0, 0, "94223"),
(@CGUID+3, 0, 0, 65536, 257, 0, 0, 0, 0, "49414"),
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ""),
-- (@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, "32783"),
-- (@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+7, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+9, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+10, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+11, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+13, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+14, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+15, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+16, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+17, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+18, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+19, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+20, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+22, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+23, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+24, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+25, 0, 0, 50331648, 1, 0, 0, 0, 0, "94225"),
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+27, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+28, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+29, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+30, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+31, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, "78905"),
(@CGUID+34, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+35, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, "85358"),
(@CGUID+37, 0, 0, 50331648, 1, 0, 0, 0, 0, "94225 94209"),
(@CGUID+38, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+39, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+41, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+42, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+43, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+44, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+45, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+46, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+47, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+48, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+49, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+50, 0, 0, 65536, 1, 0, 0, 0, 0, "87237"),
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+57, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+58, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+59, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+60, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+61, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+62, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+63, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+64, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+65, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+66, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+67, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+68, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+69, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+70, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+71, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+72, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+73, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+74, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+75, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+76, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+77, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+78, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+79, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+80, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+81, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+82, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+83, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+84, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+85, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+86, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+87, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+89, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+90, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+91, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+92, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+93, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+94, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+95, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+96, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+97, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+98, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+99, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+100, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+101, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+102, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+103, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+104, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+105, 0, 0, 50331648, 1, 0, 0, 0, 0, ""), 
(@CGUID+106, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+107, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+108, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+109, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+115, 0, 0, 0, 1, 0, 0, 0, 0, "79428"),
(@CGUID+116, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+117, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+118, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+119, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+120, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+121, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+122, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+123, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+124, 0, 0, 1, 257, 0, 0, 0, 0, ""), 
(@CGUID+125, 0, 0, 1, 257, 0, 0, 0, 0, ""), 
(@CGUID+126, 0, 0, 1, 257, 0, 0, 0, 0, ""), 
(@CGUID+127, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+128, 0, 0, 3, 257, 0, 0, 0, 0, ""), 
(@CGUID+129, 0, 0, 0, 256, 0, 0, 0, 0, ""), 
(@CGUID+130, 0, 0, 3, 257, 0, 0, 0, 0, ""), 
(@CGUID+131, 0, 0, 3, 257, 0, 0, 0, 0, ""), 
(@CGUID+132, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+133, 0, 0, 1, 257, 0, 0, 0, 0, ""), 
(@CGUID+134, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+135, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+136, 0, 0, 0, 256, 0, 0, 0, 0, ""), 
(@CGUID+137, 0, 0, 0, 0, 0, 0, 0, 0,  ""),
(@CGUID+138, 0, 0, 0, 257, 0, 0, 0, 0,  ""),
(@CGUID+139, 0, 0, 0, 0, 0, 0, 0, 0,  ""),
(@CGUID+140, 0, 0, 0, 257, 0, 0, 0, 0,  ""),
(@CGUID+141, 0, 0, 0, 257, 0, 0, 0, 0,  ""),
(@CGUID+142, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+143, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+145, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+146, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+147, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+148, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(@CGUID+149, 0, 0, 0, 0, 0, 0, 0, 0,  ""),
(@CGUID+150, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+151, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+152, 0, 0, 0, 256, 0, 0, 0, 0, "81245"),
(@CGUID+153, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+154, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+155, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+156, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(@CGUID+157, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+158, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+159, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+160, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(@CGUID+161, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+162, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+163, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+164, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(@CGUID+165, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, ""), 
(@CGUID+167, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+168, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+169, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+170, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+171, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+172, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+173, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+174, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+175, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+176, 0, 0, 0, 0, 0, 0, 0, 0, ""),
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+178, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+179, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+180, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+181, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+182, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+183, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+184, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+185, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+186, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+187, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+188, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+189, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+190, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+191, 0, 0, 0, 256, 0, 0, 0, 0, "81245"),
(@CGUID+192, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+193, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+194, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+195, 0, 0, 0, 256, 0, 0, 0, 0, "81245"),
(@CGUID+196, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+197, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+198, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+199, 0, 0, 0, 257, 0, 0, 0, 0, "81204"),
(@CGUID+200, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+201, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+202, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+203, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+204, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+205, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+206, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, ""), 
(@CGUID+208, 0, 0, 1, 257, 0, 0, 0, 0, ""), 
(@CGUID+209, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+210, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+211, 0, 0, 0, 0, 0, 0, 0, 0, ""), 
(@CGUID+212, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+213, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+216, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+221, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+222, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+231, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+235, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+238, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+241, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+242, 0, 0, 50331648, 1, 0, 0, 0, 0, ""),
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+249, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+251, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+252, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+254, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+255, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+256, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+257, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+260, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+263, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+264, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+271, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, "81555"),
(@CGUID+274, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+275, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+279, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+280, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+283, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+284, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+286, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+288, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+289, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+290, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+291, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+292, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+294, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+295, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+297, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+298, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+299, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+301, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+302, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+303, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+305, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+307, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+308, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+309, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+311, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+312, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+315, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+316, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+317, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+319, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+320, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+327, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+328, 0, 0, 1, 257, 0, 0, 0, 0, ""),
(@CGUID+329, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+332, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, "82836"),
(@CGUID+335, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+341, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+342, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+343, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+344, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+345, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+346, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+347, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+348, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+349, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+350, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+351, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+352, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+353, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+354, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+355, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+356, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+357, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+358, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+359, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+360, 0, 0, 0, 257, 0, 0, 0, 0, ""), 
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+363, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+364, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, "79877"),
(@CGUID+368, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+369, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+370, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+371, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+374, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+375, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+376, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+377, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+381, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+382, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+386, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+389, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+394, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+399, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+400, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+401, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+402, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+403, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+404, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+405, 0, 0, 65536, 1, 0, 0, 0, 0, "49414"),
(@CGUID+406, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+407, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+408, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+409, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+410, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+411, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+412, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+413, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+414, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+415, 0, 0, 65536, 257, 0, 0, 0, 0, "49414 82259"),
(@CGUID+416, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+417, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+418, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, "69494"),
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+422, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+424, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+425, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+426, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+427, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+428, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+429, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+430, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+431, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+433, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+434, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+436, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+438, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+440, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+441, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+442, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+444, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+445, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+446, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+447, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+448, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+450, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+451, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+452, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+453, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+454, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+455, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+456, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+457, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+458, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+459, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+460, 0, 0, 0, 257, 0, 0, 0, 0, "82334"),
(@CGUID+461, 0, 0, 0, 257, 0, 0, 0, 0, "81245"),
(@CGUID+462, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+463, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+465, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+466, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+467, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+470, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+472, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+474, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+475, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+477, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+478, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+480, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+481, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+482, 0, 0, 0, 2, 0, 0, 0, 0, "79841"),
(@CGUID+483, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+484, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+485, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+486, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+487, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+488, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+490, 0, 0, 65536, 1, 0, 0, 0, 0, ""),
(@CGUID+491, 0, 0, 0, 2, 0, 0, 0, 0, "79841"),
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+495, 0, 0, 0, 2, 0, 0, 0, 0, ""),
(@CGUID+496, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+497, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+500, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+501, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+502, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+503, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+504, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+505, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+506, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+507, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+508, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+509, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+510, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+511, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+512, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+513, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+514, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+515, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+516, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+519, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+520, 0, 0, 1, 256, 0, 0, 0, 0, ""),
(@CGUID+521, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+522, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+523, 0, 0, 0, 256, 0, 0, 0, 0, ""),
(@CGUID+524, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+525, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+526, 0, 0, 3, 257, 0, 0, 0, 0, "34664"),
(@CGUID+527, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+528, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+529, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+530, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+531, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+532, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+533, 0, 0, 1, 256, 0, 0, 0, 0, ""),
(@CGUID+534, 0, 0, 0, 257, 0, 0, 0, 0, "92372"),
(@CGUID+535, 0, 0, 0, 257, 0, 0, 0, 0, "92372"),
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+537, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+538, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+539, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+540, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+541, 0, 0, 0, 257, 0, 0, 0, 0, "92372"),
(@CGUID+542, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+543, 0, 0, 3, 1, 0, 0, 0, 0, ""),
(@CGUID+544, 0, 0, 8, 257, 0, 0, 0, 0, "13236"),
(@CGUID+545, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+546, 0, 0, 1, 1, 0, 0, 0, 0, ""),
(@CGUID+547, 0, 0, 3, 1, 0, 0, 0, 0, ""),
(@CGUID+548, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+549, 0, 0, 3, 1, 0, 0, 0, 0, ""),
(@CGUID+550, 0, 0, 1, 1, 0, 0, 0, 0, ""),
(@CGUID+551, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+552, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+553, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+554, 0, 0, 8, 257, 0, 0, 0, 0, ""),
(@CGUID+555, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+556, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+557, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+558, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+559, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+560, 0, 0, 0, 257, 0, 0, 0, 0, ""),
(@CGUID+561, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+562, 0, 0, 0, 1, 0, 0, 0, 0, ""),
(@CGUID+563, 0, 0, 0, 1, 0, 0, 0, 0, "79756");

SET @OGUID:=212121;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+76;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 164871, 591, 16, 4828, 1, 1, 169, 0, 0, 0, 0, 0.7348916, 0, 0, 0.3592329, 0.9332479, 120, 255, 1, 26365), -- 0 (Area: Southern Rocketway Terminus - Difficulty: 0) - !!! transport !!!
(@OGUID+1, 204956, 0, 4922, 5136, 1, 1, 229, 0, -3953.139, -6504.25, 16.204, 0.165805, 0, 0, 0.08280754, 0.9965656, 120, 255, 1, 26365), -- Brazier (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+2, 204955, 0, 4922, 5136, 1, 1, 229, 0, -3966.74, -6376.351, 29.6423, 0.165805, 0, 0, 0.08280754, 0.9965656, 120, 255, 1, 26365), -- Brazier (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+3, 204954, 0, 4922, 5136, 1, 1, 229, 0, -3975.05, -6338.729, 30.055, 0.165805, 0, 0, 0.08280754, 0.9965656, 120, 255, 1, 26365), -- Brazier (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+4, 204957, 0, 4922, 5136, 1, 1, 229, 0, -4024.681, -6359.53, 37.2511, 0.3141565, 0, 0, 0.1564331, 0.9876885, 120, 255, 1, 26365), -- Brazier (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+5, 204373, 0, 4922, 5136, 1, 1, 229, 0, -4102.55, -6412.78, 37.7048, 3.263772, 0, 0, -0.9981346, 0.06105176, 120, 255, 1, 26365), -- Dragonmaw Bonfire (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+6, 204373, 0, 4922, 5136, 1, 1, 229, 0, -4103.17, -6411.44, 37.6931, 3.804818, 0, 0, -0.9455185, 0.3255684, 120, 255, 1, 26365), -- Dragonmaw Bonfire (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+7, 207614, 0, 4922, 5136, 1, 1, 238, 0, -4015.609, -6427.481, 37.76855, 4.782203, 0, 0, -0.6819983, 0.7313538, 120, 255, 1, 26365), -- Mailbox (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+8, 204876, 0, 4922, 5136, 1, 1, 247, 0, -4050.35, -6322.48, 38.1723, 5.044002, 0, 0, -0.5807028, 0.8141156, 120, 255, 1, 26365), -- Dragonmaw Portal (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+9, 206329, 741, 4922, 5479, 1, 1, 169, 0, 0, 0, 0, 4.840187, 0, 0, -0.660511, 0.7508164, 120, 255, 1, 26365), -- 0 (Area: Slithering Cove - Difficulty: 0) - !!! transport !!!
(@OGUID+10, 207162, 763, 4922, 5353, 1, 1, 169, 0, 9.96847, -12.8853, -23.5857, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Verrall Delta - Difficulty: 0)
(@OGUID+11, 204917, 0, 4922, 0, 1, 1, 169, 0, -4038.4, -6314.7, 38.7043, 5.567601, 0, 0, -0.3502073, 0.9366722, 120, 255, 1, 26365), -- Dragonmaw Portal (Area: 0 - Difficulty: 0)
(@OGUID+12, 175080, 589, 1637, 5429, 1, 1, 169, 0, 0, 0, 0, 4.012959, 0, 0, -0.9065819, 0.42203, 120, 255, 1, 26365), -- 0 (Area: The Western Earthshrine - Difficulty: 0) - !!! transport !!!
(@OGUID+13, 186238, 613, 1637, 0, 1, 1, 169, 0, 0, 0, 0, 3.325501, 0, 0, -0.9957752, 0.09182446, 120, 255, 1, 26365), -- 0 (Area: 0 - Difficulty: 0) - !!! transport !!!
(@OGUID+14, 207162, 763, 4922, 5136, 1, 1, 169, 0, -2.65251, -8.45707, -23.7296, 1.553341, 0, 0, 0.7009087, 0.7132511, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+15, 207162, 763, 4922, 5136, 1, 1, 169, 0, 9.91323, -2.7291, -23.587, 4.729844, 0, 0, -0.7009087, 0.7132511, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+16, 192035, 0, 4922, 5136, 1, 1, 169, 0, -4072.793, -6364.023, 76.17047, 0.4363316, 0, 0, 0.2164392, 0.9762961, 120, 255, 1, 26365), -- Bonfire (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+17, 207162, 763, 4922, 5136, 1, 1, 169, 0, -2.62212, -7.23497, -23.7308, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+18, 207571, 763, 4922, 5136, 1, 1, 169, 0, -4.223741, -10.42916, -17.757, 5.654869, 0, 0, -0.3090162, 0.9510568, 120, 255, 1, 26365), -- Airbase in a Box Brochure (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+19, 208312, 0, 4922, 5136, 1, 1, 169, 0, -4020.122, -6499.856, 15.2258, 5.445428, 0, 0, -0.4067364, 0.9135455, 120, 255, 1, 26365), -- Forge (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+20, 192034, 0, 4922, 5136, 1, 1, 169, 0, -4044.511, -6424.674, 76.19215, 0.4366352, 0.009350777, 0.01467705, 0.2164068, 0.9761482, 120, 255, 1, 26365), -- Bonfire (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+21, 202569, 0, 4922, 5136, 1, 1, 169, 0, -3976.445, -6557.338, 17.08168, 1.151916, 0, 0, 0.5446386, 0.8386708, 120, 255, 1, 26365), -- Pillow (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+22, 207649, 0, 4922, 5136, 1, 1, 169, 0, -3983.587, -6557.413, 16.22566, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 26365), -- [DND] Cannon Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+23, 207651, 0, 4922, 5136, 1, 1, 169, 0, -3983.993, -6558.597, 16.22566, 0.7155849, 0, 0, 0.3502073, 0.9366722, 120, 255, 1, 26365), -- [DND] Golem Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+24, 207655, 0, 4922, 5136, 1, 1, 169, 0, -3983.087, -6557.931, 16.22566, 3.804818, 0, 0, -0.9455185, 0.3255684, 120, 255, 1, 26365), -- [DND] Jaguar Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+25, 202569, 0, 4922, 5136, 1, 1, 169, 0, -3976.658, -6558.071, 17.06829, 1.082103, 0, 0, 0.5150375, 0.8571676, 120, 255, 1, 26365), -- Pillow (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+26, 207648, 0, 4922, 5136, 1, 1, 169, 0, -3983.736, -6558.035, 16.22566, 0.6981314, 0, 0, 0.34202, 0.9396927, 120, 255, 1, 26365), -- [DND] Large Map (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+27, 207649, 0, 4922, 5136, 1, 1, 169, 0, -3983.722, -6558.882, 16.22566, 0.6806767, 0, 0, 0.333806, 0.9426418, 120, 255, 1, 26365), -- [DND] Cannon Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+28, 207651, 0, 4922, 5136, 1, 1, 169, 0, -3983.326, -6557.691, 16.22566, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 26365), -- [DND] Golem Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+29, 207655, 0, 4922, 5136, 1, 1, 169, 0, -3983.887, -6558.035, 16.22566, 0.6632232, 0, 0, 0.3255672, 0.9455189, 120, 255, 1, 26365), -- [DND] Jaguar Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+30, 202569, 0, 4922, 5136, 1, 1, 169, 0, -3988.767, -6553.408, 17.09416, 1.431168, 0, 0, 0.6560583, 0.7547102, 120, 255, 1, 26365), -- Pillow (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+31, 202569, 0, 4922, 5136, 1, 1, 169, 0, -3988.462, -6551.853, 17.05085, 1.396262, 0, 0, 0.642787, 0.766045, 120, 255, 1, 26365), -- Pillow (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+32, 202569, 0, 4922, 5136, 1, 1, 169, 0, -3988.566, -6552.609, 17.08686, 1.326448, 0, 0, 0.6156607, 0.7880114, 120, 255, 1, 26365), -- Pillow (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+33, 207649, 0, 4922, 5136, 1, 1, 169, 0, -3983.179, -6558.422, 16.22566, 3.857183, 0, 0, -0.9366713, 0.3502098, 120, 255, 1, 26365), -- [DND] Cannon Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+34, 202569, 0, 4922, 5136, 1, 1, 169, 0, -3976.972, -6558.828, 17.09416, 1.186823, 0, 0, 0.5591927, 0.8290377, 120, 255, 1, 26365), -- Pillow (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+35, 207649, 0, 4922, 5136, 1, 1, 169, 0, -3984.358, -6558.167, 16.22566, 0.6981314, 0, 0, 0.34202, 0.9396927, 120, 255, 1, 26365), -- [DND] Cannon Piece (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+36, 207348, 0, 4922, 5136, 1, 1, 169, 0, -3899.342, -6589.592, 14.37029, 2.234018, 0, 0, 0.8987932, 0.4383728, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+37, 207348, 0, 4922, 5136, 1, 1, 169, 0, -3899.594, -6589.167, 15.49241, 2.722713, 0, 0, 0.9781475, 0.2079121, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+38, 207348, 0, 4922, 5136, 1, 1, 169, 0, -3900.979, -6587.335, 14.39229, 3.787367, 0, 0, -0.9483232, 0.3173059, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+39, 207348, 0, 4922, 5136, 1, 1, 169, 0, -3900.024, -6588.384, 14.4046, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+40, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4014.066, -6568.663, 14.43051, 1.431168, 0, 0, 0.6560583, 0.7547102, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+41, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4014.82, -6568.476, 15.59797, 2.007128, 0, 0, 0.8433914, 0.5372996, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+42, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4015.425, -6568.463, 14.42657, 1.431168, 0, 0, 0.6560583, 0.7547102, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+43, 208311, 0, 4922, 5136, 1, 1, 169, 0, -3885.49, -6643.71, 0, 3.141593, 0, 0, -1, 0, 120, 255, 1, 26365), -- Deepsea Sagefish School (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+44, 208311, 0, 4922, 5136, 1, 1, 169, 0, -3880.33, -6707.91, 0, 3.141593, 0, 0, -1, 0, 120, 255, 1, 26365), -- Deepsea Sagefish School (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+45, 194802, 0, 4922, 5136, 1, 1, 169, 0, -4054.142, -6524.466, 14.5795, 0.087266, 0, 0, 0.04361916, 0.9990482, 120, 255, 1, 26365), -- Anvil (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+46, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4039.87, -6614.222, 14.4447, 2.91469, 0, 0, 0.9935713, 0.1132084, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+47, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4040.26, -6615.658, 15.51127, 1.815142, 0, 0, 0.7880106, 0.6156617, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+48, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4040.245, -6615.556, 14.43246, 1.326448, 0, 0, 0.6156607, 0.7880114, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+49, 207348, 0, 4922, 5136, 1, 1, 169, 0, -4039.797, -6612.802, 14.45813, 1.431168, 0, 0, 0.6560583, 0.7547102, 120, 255, 1, 26365), -- Horde Crate (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+50, 192037, 0, 4922, 5136, 1, 1, 169, 0, -4113.668, -6456.922, 76.1954, 0.4362591, 0.007559299, -0.004104614, 0.2164316, 0.9762599, 120, 255, 1, 26365), -- Bonfire (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+51, 205356, 0, 4922, 5136, 1, 1, 169, 0, -4447.26, -6519.05, 13.0676, 0.06981169, 0, 0, 0.03489876, 0.9993908, 120, 255, 1, 26365), -- Beach Head Banner - Horde (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+52, 205356, 0, 4922, 5136, 1, 1, 169, 0, -4449.34, -6519.23, 13.0591, 3.228859, 0, 0, -0.9990482, 0.04361926, 120, 255, 1, 26365), -- Beach Head Banner - Horde (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+53, 205358, 0, 4922, 5136, 1, 1, 169, 0, -4448.2, -6519.13, 4.63473, 0.087266, 0, 0, 0.04361916, 0.9990482, 120, 255, 1, 26365), -- Beach Head Control Point (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+54, 192036, 0, 4922, 5136, 1, 1, 169, 0, -4141.607, -6397.432, 76.33009, 0.4192687, -0.01562405, -0.01034069, 0.2079487, 0.9779603, 120, 255, 1, 26365), -- Bonfire (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+55, 207162, 762, 4922, 5136, 1, 1, 169, 0, -3.69946, -8.73328, -23.78, 0, 0, 0, 0, 1, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+56, 207162, 762, 4922, 5136, 1, 1, 169, 0, -3.67054, -6.83675, -23.7809, 0, 0, 0, 0, 1, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+57, 207162, 762, 4922, 5136, 1, 1, 169, 0, 10.2938, -12.5444, -23.5793, 0, 0, 0, 0, 1, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+58, 207162, 762, 4922, 5136, 1, 1, 169, 0, 10.4664, -3.06272, -23.577, 0, 0, 0, 0, 1, 120, 255, 1, 26365), -- Crate of Fine Cloth (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+59, 207571, 762, 4922, 5136, 1, 1, 169, 0, 14.71849, -4.923897, -24.0275, 4.101525, 0, 0, -0.8870106, 0.4617491, 120, 255, 1, 26365), -- Airbase in a Box Brochure (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+60, 205821, 0, 4922, 5136, 1, 1, 169, 0, -3840.98, -6302.94, 27.6732, 5.742135, 0, 0, -0.2672377, 0.9636307, 120, 255, 1, 26365), -- Goblin Shore Battery (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+61, 208311, 0, 4922, 5136, 1, 1, 169, 0, -4119.71, -6204.46, 0, 3.141593, 0, 0, -1, 0, 120, 255, 1, 26365), -- Deepsea Sagefish School (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+62, 208311, 0, 4922, 5136, 1, 1, 169, 0, -4274.24, -6447.721, 0, 3.141593, 0, 0, -1, 0, 120, 255, 1, 26365), -- Deepsea Sagefish School (Area: Dragonmaw Port - Difficulty: 0)
(@OGUID+63, 205171, 0, 4922, 5136, 1, 1,  238, 0, -4115.17, -6422.464, 38.75443, 1.989676, 0, 0, 0.8386707, 0.5446388, 120, 255, 1, 16057), -- 205171 (Area: -1 - Difficulty: 0)
(@OGUID+64, 205167, 0, 4922, 5136, 1, 1,  238, 0, -4115.743, -6405.313, 38.75443, 6.021387, 0, 0, -0.1305256, 0.9914449, 120, 255, 1, 16057), -- 205167 (Area: -1 - Difficulty: 0)
(@OGUID+65, 205168, 0, 4922, 5136, 1, 1,  238, 0, -4094.031, -6412.706, 38.72658, 2.216565, 0, 0, 0.8949337, 0.4461992, 120, 255, 1, 16057), -- 205168 (Area: -1 - Difficulty: 0)
(@OGUID+66, 205170, 0, 4922, 5136, 1, 1,  238, 0, -4099.069, -6403.438, 38.72658, 3.953173, 0, 0, -0.9187908, 0.3947448, 120, 255, 1, 16057), -- 205170 (Area: -1 - Difficulty: 0)
(@OGUID+67, 205169, 0, 4922, 5136, 1, 1,  238, 0, -4106.429, -6425.879, 38.75443, 2.216565, 0, 0, 0.8949337, 0.4461992, 120, 255, 1, 16057), -- 205169 (Area: -1 - Difficulty: 0)
(@OGUID+68, 205166, 0, 4922, 5136, 1, 1,  238, 0, -4119.136, -6413.855, 38.6495, 0.023984, 0, 0, 0.8949337, 0.4461992, 120, 255, 1, 16057), -- 205169 (Area: -1 - Difficulty: 0)
(@OGUID+69, 205187, 0, 4922, 5136, 1, 1, 238, 0, -3894.981, -6475.841, 15.50604, 4.81711, 0, 0, -0.6691303, 0.743145, 120, 255, 1, 16057), -- 205187 (Area: -1 - Difficulty: 0)
(@OGUID+70, 205187, 0, 4922, 5136, 1, 1, 238, 0, -4046.796, -6325.804, 38.29633, 0.5497788, 0, 0, 0.2714405, 0.9624552, 120, 255, 1, 16057), -- 205187 (Area: -1 - Difficulty: 0)
(@OGUID+71, 205177, 0, 4922, 5136, 1, 1, 238, 0, -3910.94, -6420.585, 28.22387, 0, 0, 0, 0, 1, 120, 255, 1, 16057), -- 205177 (Area: -1 - Difficulty: 0)
(@OGUID+72, 205178, 0, 4922, 5136, 1, 1, 238, 0, -3908.025, -6420.55, 28.29038, 3.054283, 0, 0, 0.9990473, 0.04364112, 120, 255, 1, 16057), -- 205178 (Area: -1 - Difficulty: 0)
(@OGUID+73, 204353, 0, 4922, 5136, 1, 1, 238, 0, -3928.66, -6779.98, -4.28453, 1.902409, 0, 0, 0.8141155, 0.580703, 120, 255, 1, 16057), -- 204353 (Area: -1 - Difficulty: 0)
(@OGUID+74, 205174, 0, 4922, 5136, 1, 1, 238, 0, -4051.371, -6539.028, 15.83129, 2.530723, 0, 0, 0.9537163, 0.3007079, 120, 255, 1, 16057), -- 205174 (Area: -1 - Difficulty: 0)
(@OGUID+75, 208805, 0, 4922, 5136, 1, 1, 238, 0, -4052.809, -6531.33, 13.84975, 0.5585039, 0, 0, 0.2756367, 0.9612619, 120, 255, 1, 16057), -- 208805 (Area: -1 - Difficulty: 0)
(@OGUID+76, 205173, 0, 4922, 5136, 1, 1, 238, 0, -4056.525, -6526.443, 15.56209, 4.747296, 0, 0, -0.6946583, 0.7193398, 120, 255, 1, 16057); -- 205173 (Area: -1 - Difficulty: 0)

UPDATE `gameobject` SET `terrainSwapMap`= 736 WHERE `PhaseId` IN (229,238,247) AND `guid` BETWEEN @OGUID+0 AND @OGUID+76 AND `map`=0;

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+76;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+9, 0, 0, -0.4226183, 0.9063078), -- Gate
(@OGUID+16, 0, 0, 0.2164396, 0.976296), -- Bonfire
(@OGUID+20, 0, 0, 0.2164396, 0.976296), -- Bonfire
(@OGUID+45, 0, 0, 0.04361947, 0.9990482), -- Anvil
(@OGUID+50, 0, 0, 0.2164396, 0.976296), -- Bonfire
(@OGUID+54, 0, 0, 0.2164396, 0.976296), -- Bonfire
(@OGUID+63, 0, 0, 0.2079118, 0.9781476), -- 205171
(@OGUID+64, 0, 0, 0.2079118, 0.9781476), -- 205167
(@OGUID+65, 0, 0, 0.2079118, 0.9781476), -- 205168
(@OGUID+66, 0, 0, 0.2079118, 0.9781476), -- 205170
(@OGUID+67, 0, 0, 0.2079118, 0.9781476), -- 205169
(@OGUID+68, 0, 0, 0.2079118, 0.9781476), -- 205166
(@OGUID+69, 0, 0, 0.9986295, -0.05233606), -- 205187
(@OGUID+70, 0, 0, -0.4886211, 0.8724961), -- 205187
(@OGUID+71, 0, 0, 0.9381913, 0.3461172), -- 205177
(@OGUID+72, 0, 0, 0.9381913, 0.3461172), -- 205178
(@OGUID+74, 0, 0, 0.2756375, 0.9612617), -- 205174
(@OGUID+75, 0, 0, 0.2756375, 0.9612617), -- 208805
(@OGUID+76, 0, 0, 0.2756375, 0.9612617); -- 205173

DELETE FROM `creature_template_addon` WHERE `entry` IN (49025 /*49025 (Highbank Cannoneer)*/, 45169 /*45169 (Lieutenant Emry)*/, 45368 /*45368 (Highbank Sniper)*/, 46090 /*46090 (Juice Gnugat)*/, 46089 /*46089 (Rok'tar)*/, 46101 /*46101 (Bilgewater Salvage Expert)*/, 45178 /*45178 (Axebite Defender)*/, 45406 /*45406 (Highbank)*/, 45388 /*45388 (Dragonmaw Hold) - Blade Strike*/, 45174 /*45174 (Highbank Marine)*/, 45175 /*45175 (Axebite Marine)*/, 45185 /*45185 (Diamond-Blade Shredder)*/, 45396 /*45396 (Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI))*/, 44169 /*44169 (Zaela)*/, 49551 /*49551 (Grizz)*/, 49557 /*49557 (Dakam)*/, 49571 /*49571 (Dragonmaw Shaman) - Nature Channeling*/, 49570 /*49570 (Wounded Axebite Warrior)*/, 50375 /*50375 (Kuldar Steeltooth)*/, 50460 /*50460 (Zim Bamzabble)*/, 49549 /*49549 (Jodan)*/, 49569 /*49569 (Dragonmaw Porter) - Orc Carrying Horde Crate*/, 49519 /*49519 (Lizzy "Lemons")*/, 49506 /*49506 (Cerie Bowden)*/, 50462 /*50462 (Digel East Nickens)*/, 50459 /*50459 (Victor Quivias)*/, 50248 /*50248 (Una Kobuna)*/, 50146 /*50146 (Agatian Fallanos)*/, 50461 /*50461 (Marlow Harston)*/, 50165 /*50165 (Gregory Kauffman)*/, 49572 /*49572 (Axebite Warrior)*/, 49498 /*49498 (Innkeeper Lutz)*/, 49554 /*49554 (Kanath)*/, 50433 /*50433 (Aristaleon Sunweaver)*/, 50172 /*50172 (Threm Blackscalp)*/, 50457 /*50457 (Brot)*/, 50456 /*50456 (Hortak Kenzo)*/, 42594 /*42594 (Orgrimmar Thief)*/, 44120 /*44120 (Sauranok the Mystic)*/, 31727 /*31727 (Grunt Grikee)*/, 31726 /*31726 (Grunt Gritch)*/, 31725 /*31725 (Sky-Captain LaFontaine)*/, 31724 /*31724 (Crewman Paltertop)*/, 31723 /*31723 (Crewman Barrowswizzle)*/, 31720 /*31720 (Crewman Shubbscoop)*/, 69977 /*69977 (Blood Guard Zar'shi)*/, 69978 /*69978 (Sergeant Thunderhorn)*/, 73151 /*73151 (Deathguard Netharian)*/, 89175 /*89175 (Dysong)*/, 88706 /*88706 (Murgul)*/, 88705 /*88705 (Kranosh)*/, 88704 /*88704 (Gran'dul)*/, 133271 /*133271 (Highmountain Pathfinder)*/, 61369 /*61369 (Toad)*/, 44050 /*44050 (Dragonmaw Portal to Orgrimmar)*/, 49547 /*49547 (Frenk)*/, 47174 /*47174 (Gorthul)*/, 48689 /*48689 (Highlands Mouse)*/, 49567 /*49567 (Dragonmaw Worker)*/, 49562 /*49562 (Dragonmaw Guard)*/, 31889 /*31889 (Grizzly Squirrel)*/, 61326 /*61326 (Scorpid)*/, 61439 /*61439 (Rattlesnake)*/, 44011 /*44011 (Muddied Water Elemental) - Muddy*/, 45983 /*45983 (Fergus Gearchum)*/, 45982 /*45982 (Gralok)*/, 62904 /*62904 (Yellow-Bellied Marmot)*/, 46971 /*46971 (Highland Doe)*/, 46970 /*46970 (Highland Elk)*/, 46153 /*46153 (Highland Worg)*/, 46162 /*46162 (Tawny Owl)*/, 46158 /*46158 (Untamed Gryphon)*/, 48683 /*48683 (Yellow-Bellied Marmot)*/, 46023 /*46023 (Goblin Mortar Emplacement)*/, 45987 /*45987 (Dragonmaw Defender)*/, 45985 /*45985 (Blackscale Mistress)*/, 45984 /*45984 (Blackscale Raider)*/, 45989 /*45989 (Goblin Bombardier)*/, 43943 /*43943 (Garrosh Hellscream) - Generic Quest Invisibility 1*/, 43958 /*43958 (Dragonmaw Merchant) - Generic Quest Invisibility 1, Horde Banner*/, 44042 /*44042 (Ornak)*/, 44002 /*44002 (Dragonmaw Warrior)*/, 43941 /*43941 (Dragonmaw Worker) - Orc Carrying Stone Block*/, 44003 /*44003 (Dragonmaw Smoke) - Cosmetic - Billowing Smoke Cloud*/, 44026 /*44026 (Dragonmaw Shaman)*/, 44024 /*44024 (Artesh)*/, 43939 /*43939 (Zaela) - Bloodthirst*/, 43581 /*43581 (Zaela)*/, 43580 /*43580 (Gregor)*/, 43576 /*43576 (Gorthul)*/, 43678 /*43678 (Dragonmaw Felblade)*/, 43189 /*43189 (Warchief Mor'ghor)*/, 43394 /*43394 (Dragonmaw Warlock)*/, 43577 /*43577 (Dragonmaw Worker)*/, 43575 /*43575 (Dragonmaw Enforcer) - Blood Fury*/, 43578 /*43578 (Dragonmaw Merchant)*/, 43579 /*43579 (Axebite Warrior)*/, 43582 /*43582 (Ornak)*/, 43602 /*43602 (Small Dragonmaw Fires) - Cosmetic - Tree Fire 2 (With Sound)*/, 43601 /*43601 (Dragonmaw Fires) - Cosmetic - Tree Fire 2 (With Sound)*/, 43583 /*43583 (Goblin Barrage Balloon)*/, 43389 /*43389 (Gorthul) - I am a Fake Flight Master*/, 43191 /*43191 (Gregor)*/, 43190 /*43190 (Zaela)*/, 43421 /*43421 (Dragonmaw Blacksmith)*/, 43483 /*43483 (Dragonmaw Invisible Bunny Trigger - Chapter I Only)*/, 43386 /*43386 (Dragonmaw Merchant)*/, 43387 /*43387 (Dragonmaw Worker)*/, 43188 /*43188 (Horzog)*/, 43193 /*43193 (Warlord Krogg)*/, 43186 /*43186 (Juice Gnugat)*/, 43192 /*43192 (Wounded Axebite Warrior)*/, 42978 /*42978 (Admiral Stonefist)*/, 43683 /*43683 (Goblin Barrage Balloon)*/, 43187 /*43187 (Ornak)*/, 43482 /*43482 (Axebite Warrior)*/, 42603 /*42603 (Emergency Rampless Debarkation Device) - Parachute Holder*/, 43390 /*43390 (Dragonmaw Enforcer)*/, 42516 /*42516 (Twilight Swarmer)*/, 51131 /*51131 (Wildhammer Homesteader)*/, 45693 /*45693 (Tentacle of Iso'rath) - Generic Quest Invisibility 18*/, 45510 /*45510 (Tentacle of Iso'rath) - Generic Quest Invisibility 18*/, 45511 /*45511 (Tentacle of Iso'rath) - Generic Quest Invisibility 18*/, 45694 /*45694 (Tentacle of Iso'rath) - Generic Quest Invisibility 18*/, 50964 /*50964 (Chops)*/, 42314 /*42314 (Air Defense Cannon)*/, 51033 /*51033 (Deathwing Zeppelin Ride Vehicle)*/, 51137 /*51137 (<Internal> Horde Zeppelin Sound Bunny)*/, 42195 /*42195 (Captain Krazz)*/, 42243 /*42243 (Fergus Gearchum)*/, 43869 /*43869 (Zeppelin Explosion Bunny (Large))*/, 43868 /*43868 (Zeppelin Explosion Bunny)*/, 50369 /*50369 (Deathwing) - Ride Vehicle Hardcoded*/, 42300 /*42300 (Kor'kron Air Marine)*/, 42577 /*42577 (Twilight Drake Swarmer) - Ride Vehicle Hardcoded, Freeze Anim*/, 42576 /*42576 (Drake Rigging Bunny)*/, 45749 /*45749 (Aura Generator Bunny)*/, 42206 /*42206 (The Skyshredder) - Ride Vehicle Hardcoded*/, 42207 /*42207 (Heart of Orgrimmar) - Ride Vehicle Hardcoded*/, 42254 /*42254 (Main Air Support Fleet) - Ride Vehicle Hardcoded*/, 42519 /*42519 (Twilight Sky Terror) - Ride Vehicle Hardcoded, Freeze Anim*/, 42258 /*42258 (Air Support Fleet) - Ride Vehicle Hardcoded*/, 42257 /*42257 (Air Support Fleet) - Ride Vehicle Hardcoded*/, 42277 /*42277 (Garrosh Hellscream) - Ride Vehicle Hardcoded*/, 42568 /*42568 (Twilight Sky Screamer) - Ride Vehicle Hardcoded*/, 42567 /*42567 (Twilight Sky Screamer) - Ride Vehicle Hardcoded*/, 42566 /*42566 (Twilight Sky Screamer) - Ride Vehicle Hardcoded*/, 42561 /*42561 (Twilight Sky Screamer) - Ride Vehicle Hardcoded*/, 42320 /*42320 (Twilight Sky Terror) - Ride Vehicle Hardcoded, Freeze Anim*/, 42205 /*42205 (The Impervious) - Ride Vehicle Hardcoded*/, 42204 /*42204 (The Indomitable) - Ride Vehicle Hardcoded*/, 42255 /*42255 (Air Support Formation Bunny)*/, 42246 /*42246 (Zeppelin Formation Bunny 03)*/, 42245 /*42245 (Zeppelin Formation Bunny 02)*/, 42247 /*42247 (Zeppelin Formation Bunny 04)*/, 42241 /*42241 (Zeppelin Formation Bunny 01)*/, 42268 /*42268 (Garrosh's Airship) - Ride Vehicle Hardcoded*/, 42267 /*42267 (Garrosh Formation Bunny)*/, 47217 /*47217 (Emergency Rampless Debarkation Device) - Parachute Holder*/, 47210 /*47210 (Air Defense Cannon)*/, 47209 /*47209 (Hobart Grapplehammer)*/, 47208 /*47208 (Assistant Greely)*/, 47206 /*47206 (Loudspeaker)*/, 50367 /*50367 (Friz Groundspin)*/, 62120 /*62120 (Rabid Nut Varmint 5000)*/, 70165 /*70165 (Julie Fabernackle)*/, 125216 /*125216 (Kruda Thunderhand)*/, 60761 /*60761 (Shore Crab)*/, 62121 /*62121 (Turquoise Turtle)*/, 61255 /*61255 (Skunk)*/, 61080 /*61080 (Rabbit)*/, 61158 /*61158 (Shore Crab)*/, 130911 /*130911 (Charles Gastly)*/, 65065 /*65065 (Red Dragon Turtle)*/, 42707 /*42707 (Twilight Nightblade)*/, 70301 /*70301 (Softpaws)*/, 65074 /*65074 (Great Blue Dragon Turtle)*/, 66022 /*66022 (Turtlemaster Odai)*/, 65076 /*65076 (Great Brown Dragon Turtle)*/, 65071 /*65071 (Great Green Dragon Turtle)*/, 35845 /*35845 (Dave's Industrial Light and Magic Bunny (Small)(Sessile))*/, 88543 /*88543 (Orgrimmar Mage) - Arcane Channeling*/, 89830 /*89830 (Brew Vendor)*/, 88703 /*88703 (Grunt Arhung)*/, 14720 /*14720 (High Overlord Saurfang)*/, 89713 /*89713 (Koak Hoburn)*/, 38821 /*38821 (Dave's Industrial Light and Magic Bunny (Medium)(Sessile))*/, 65078 /*65078 (Great Purple Dragon Turtle)*/, 16869 /*16869 (Jising)*/, 66437 /*66437 (Arcanist Xu) - Arcane Channeling*/, 69333 /*69333 (Disciple Jusi)*/, 68869 /*68869 (Luo Luo) - Panda*/, 62445 /*62445 (Ji Firepaw)*/, 65061 /*65061 (Brown Dragon Turtle)*/, 65060 /*65060 (Blue Dragon Turtle)*/, 2756 /*2756 (Chao-Ju)*/, 16868 /*16868 (Winsum)*/, 65008 /*65008 (Huojin Monk)*/, 5034 /*5034 (Winwa)*/, 5029 /*5029 (Jiming)*/, 65063 /*65063 (Purple Dragon Turtle)*/, 65058 /*65058 (Black Dragon Turtle)*/, 121541 /*121541 (Ban-Lu)*/, 64105 /*64105 (Muffin)*/, 114840 /*114840 (PvP Training Dummy) - Training Dummy Marker, PvP Rules Enabled for Dummy, Orc Male Mask*/, 62193 /*62193 (Rok'kal) - Fishing*/, 62197 /*62197 (Zazzle) - Grit's Flamethrower Backpack*/, 62196 /*62196 (Flekky Nox) - Frost Armor*/, 42548 /*42548 (Muddy Crawfish)*/, 62200 /*62200 (Sasi)*/, 62199 /*62199 (Gogu)*/, 62822 /*62822 (Cousin Slowhands) - Grand Expedition Yak, Grummle Booth B*/, 62821 /*62821 (Mystic Birdhat)*/, 68979 /*68979 (Voidbinder Zorlan)*/, 62194 /*62194 (Ukos Bloodwhisper)*/, 63626 /*63626 (Varzok)*/, 62198 /*62198 (Omakka Wolfbrother)*/, 72559 /*72559 (Thunder Bluff Protector) - Cosmetic - Sleep Zzz Breakable*/, 88702 /*88702 (Grunt Nolo)*/, 88701 /*88701 (Grunt Meena)*/, 62195 /*62195 (Shang'gok)*/, 42637 /*42637 (Sauranok the Mystic) - Generic Quest Invisibility 1*/, 52382 /*52382 (Ziradormi) - Generic Quest Invisibility 25*/, 62115 /*62115 (Dung Beetle)*/, 62114 /*62114 (Spiny Lizard)*/, 74228 /*74228 (Darkspear Headhunter)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(49025, 0, 0, 0, 1, 0, ''), -- 49025 (Highbank Cannoneer)
(45169, 0, 0, 0, 1, 0, ''), -- 45169 (Lieutenant Emry)
(45368, 0, 0, 0, 257, 0, ''), -- 45368 (Highbank Sniper)
(46090, 0, 0, 0, 257, 0, ''), -- 46090 (Juice Gnugat)
(46089, 0, 0, 0, 258, 0, ''), -- 46089 (Rok'tar)
(46101, 0, 0, 0, 257, 0, ''), -- 46101 (Bilgewater Salvage Expert)
(45178, 0, 0, 0, 257, 0, ''), -- 45178 (Axebite Defender)
(45406, 0, 0, 0, 1, 0, ''), -- 45406 (Highbank)
(45388, 0, 0, 0, 1, 0, '84834'), -- 45388 (Dragonmaw Hold) - Blade Strike
(45174, 0, 0, 0, 1, 0, ''), -- 45174 (Highbank Marine)
(45175, 0, 0, 0, 1, 0, ''), -- 45175 (Axebite Marine)
(45185, 0, 0, 0, 1, 0, ''), -- 45185 (Diamond-Blade Shredder)
(45396, 0, 0, 0, 1, 0, ''), -- 45396 (Dave's Industrial Light and Magic Bunny (Medium)(Sessile)(Large AOI))
(44169, 0, 0, 0, 257, 0, ''), -- 44169 (Zaela)
(49551, 0, 0, 0, 257, 0, ''), -- 49551 (Grizz)
(49557, 0, 0, 0, 257, 0, ''), -- 49557 (Dakam)
(49571, 0, 0, 8, 257, 0, '13236'), -- 49571 (Dragonmaw Shaman) - Nature Channeling
(49570, 0, 0, 3, 1, 0, ''), -- 49570 (Wounded Axebite Warrior)
(50375, 0, 0, 0, 257, 0, ''), -- 50375 (Kuldar Steeltooth)
(50460, 0, 0, 0, 257, 0, ''), -- 50460 (Zim Bamzabble)
(49549, 0, 0, 0, 257, 0, ''), -- 49549 (Jodan)
(49569, 0, 0, 0, 257, 0, '92372'), -- 49569 (Dragonmaw Porter) - Orc Carrying Horde Crate
(49519, 0, 0, 0, 257, 0, ''), -- 49519 (Lizzy "Lemons")
(49506, 0, 0, 0, 257, 0, ''), -- 49506 (Cerie Bowden)
(50462, 0, 0, 0, 257, 0, ''), -- 50462 (Digel East Nickens)
(50459, 0, 0, 0, 257, 0, ''), -- 50459 (Victor Quivias)
(50248, 0, 0, 0, 257, 0, ''), -- 50248 (Una Kobuna)
(50146, 0, 0, 0, 257, 0, ''), -- 50146 (Agatian Fallanos)
(50461, 0, 0, 0, 257, 0, ''), -- 50461 (Marlow Harston)
(50165, 0, 0, 0, 257, 0, ''), -- 50165 (Gregory Kauffman)
(49572, 0, 0, 1, 256, 0, ''), -- 49572 (Axebite Warrior)
(49498, 0, 0, 0, 257, 0, ''), -- 49498 (Innkeeper Lutz)
(49554, 0, 0, 0, 257, 0, ''), -- 49554 (Kanath)
(50433, 0, 0, 0, 257, 0, ''), -- 50433 (Aristaleon Sunweaver)
(50172, 0, 0, 0, 257, 0, ''), -- 50172 (Threm Blackscalp)
(50457, 0, 0, 0, 257, 0, ''), -- 50457 (Brot)
(50456, 0, 0, 0, 257, 0, ''), -- 50456 (Hortak Kenzo)
(42594, 0, 0, 0, 1, 0, ''), -- 42594 (Orgrimmar Thief)
(44120, 0, 0, 0, 1, 0, ''), -- 44120 (Sauranok the Mystic)
(31727, 0, 0, 0, 1, 0, ''), -- 31727 (Grunt Grikee)
(31726, 0, 0, 0, 1, 0, ''), -- 31726 (Grunt Gritch)
(31725, 0, 0, 0, 1, 0, ''), -- 31725 (Sky-Captain LaFontaine)
(31724, 0, 0, 0, 1, 0, ''), -- 31724 (Crewman Paltertop)
(31723, 0, 0, 0, 1, 0, ''), -- 31723 (Crewman Barrowswizzle)
(31720, 0, 0, 0, 1, 0, ''), -- 31720 (Crewman Shubbscoop)
(69977, 0, 0, 0, 0, 0, ''), -- 69977 (Blood Guard Zar'shi)
(69978, 0, 0, 0, 0, 0, ''), -- 69978 (Sergeant Thunderhorn)
(73151, 0, 51048, 0, 0, 0, ''), -- 73151 (Deathguard Netharian)
(89175, 0, 0, 0, 257, 0, ''), -- 89175 (Dysong)
(88706, 0, 0, 0, 257, 0, ''), -- 88706 (Murgul)
(88705, 0, 0, 0, 257, 0, ''), -- 88705 (Kranosh)
(88704, 0, 0, 0, 257, 0, ''), -- 88704 (Gran'dul)
(133271, 0, 0, 0, 0, 0, ''), -- 133271 (Highmountain Pathfinder)
(61369, 0, 0, 0, 1, 0, ''), -- 61369 (Toad)
(44050, 0, 0, 65536, 1, 0, ''), -- 44050 (Dragonmaw Portal to Orgrimmar)
(49547, 0, 0, 0, 257, 0, ''), -- 49547 (Frenk)
(47174, 0, 0, 0, 257, 0, ''), -- 47174 (Gorthul)
(48689, 0, 0, 0, 1, 0, ''), -- 48689 (Highlands Mouse)
(49567, 0, 0, 8, 257, 0, ''), -- 49567 (Dragonmaw Worker)
(49562, 0, 0, 0, 257, 0, ''), -- 49562 (Dragonmaw Guard)
(31889, 0, 0, 0, 1, 0, ''), -- 31889 (Grizzly Squirrel)
(61326, 0, 0, 0, 1, 0, ''), -- 61326 (Scorpid)
(61439, 0, 0, 0, 1, 0, ''), -- 61439 (Rattlesnake)
(44011, 0, 0, 0, 1, 0, '82383'), -- 44011 (Muddied Water Elemental) - Muddy
(45983, 0, 0, 0, 257, 0, ''), -- 45983 (Fergus Gearchum)
(45982, 0, 0, 0, 257, 0, ''), -- 45982 (Gralok)
(62904, 0, 0, 0, 1, 0, ''), -- 62904 (Yellow-Bellied Marmot)
(46971, 0, 0, 0, 1, 0, ''), -- 46971 (Highland Doe)
(46970, 0, 0, 0, 1, 0, ''), -- 46970 (Highland Elk)
(46153, 0, 0, 0, 1, 0, ''), -- 46153 (Highland Worg)
(46162, 0, 0, 0, 1, 0, ''), -- 46162 (Tawny Owl)
(46158, 0, 0, 0, 1, 0, ''), -- 46158 (Untamed Gryphon)
(48683, 0, 0, 0, 1, 0, ''), -- 48683 (Yellow-Bellied Marmot)
(46023, 0, 0, 0, 1, 0, ''), -- 46023 (Goblin Mortar Emplacement)
(45987, 0, 0, 0, 1, 0, ''), -- 45987 (Dragonmaw Defender)
(45985, 0, 0, 0, 1, 0, ''), -- 45985 (Blackscale Mistress)
(45984, 0, 0, 0, 1, 0, ''), -- 45984 (Blackscale Raider)
(45989, 0, 0, 0, 1, 0, ''), -- 45989 (Goblin Bombardier)
(43943, 0, 0, 65536, 1, 0, '49414'), -- 43943 (Garrosh Hellscream) - Generic Quest Invisibility 1
(43958, 0, 0, 65536, 257, 0, '49414 82259'), -- 43958 (Dragonmaw Merchant) - Generic Quest Invisibility 1, Horde Banner
(44042, 0, 0, 0, 257, 0, ''), -- 44042 (Ornak)
(44002, 0, 0, 0, 1, 0, ''), -- 44002 (Dragonmaw Warrior)
(43941, 0, 0, 0, 257, 0, '82334'), -- 43941 (Dragonmaw Worker) - Orc Carrying Stone Block
(44003, 0, 0, 0, 1, 0, '69494'), -- 44003 (Dragonmaw Smoke) - Cosmetic - Billowing Smoke Cloud
(44026, 0, 0, 0, 1, 0, ''), -- 44026 (Dragonmaw Shaman)
(44024, 0, 0, 0, 257, 0, ''), -- 44024 (Artesh)
(43939, 0, 0, 0, 1, 0, '79877'), -- 43939 (Zaela) - Bloodthirst
(43581, 0, 0, 0, 257, 0, ''), -- 43581 (Zaela)
(43580, 0, 0, 1, 257, 0, ''), -- 43580 (Gregor)
(43576, 0, 0, 8, 257, 0, ''), -- 43576 (Gorthul)
(43678, 0, 0, 0, 1, 0, ''), -- 43678 (Dragonmaw Felblade)
(43189, 0, 0, 0, 1, 0, ''), -- 43189 (Warchief Mor'ghor)
(43394, 0, 0, 0, 1, 0, ''), -- 43394 (Dragonmaw Warlock)
(43577, 0, 0, 0, 257, 0, ''), -- 43577 (Dragonmaw Worker)
(43575, 0, 0, 0, 1, 0, '82836'), -- 43575 (Dragonmaw Enforcer) - Blood Fury
(43578, 0, 0, 0, 257, 0, ''), -- 43578 (Dragonmaw Merchant)
(43579, 0, 0, 0, 1, 0, ''), -- 43579 (Axebite Warrior)
(43582, 0, 0, 0, 257, 0, ''), -- 43582 (Ornak)
(43602, 0, 0, 0, 1, 0, '81555'), -- 43602 (Small Dragonmaw Fires) - Cosmetic - Tree Fire 2 (With Sound)
(43601, 0, 0, 0, 1, 0, '81555'), -- 43601 (Dragonmaw Fires) - Cosmetic - Tree Fire 2 (With Sound)
(43583, 0, 0, 50331648, 1, 0, ''), -- 43583 (Goblin Barrage Balloon)
(43389, 0, 0, 0, 257, 0, '81204'), -- 43389 (Gorthul) - I am a Fake Flight Master
(43191, 0, 0, 0, 257, 0, ''), -- 43191 (Gregor)
(43190, 0, 0, 0, 256, 0, ''), -- 43190 (Zaela)
(43421, 0, 0, 0, 256, 0, ''), -- 43421 (Dragonmaw Blacksmith)
(43483, 0, 0, 0, 1, 0, ''), -- 43483 (Dragonmaw Invisible Bunny Trigger - Chapter I Only)
(43386, 0, 0, 0, 257, 0, ''), -- 43386 (Dragonmaw Merchant)
(43387, 0, 0, 0, 257, 0, ''), -- 43387 (Dragonmaw Worker)
(43188, 0, 0, 0, 257, 0, ''), -- 43188 (Horzog)
(43193, 0, 0, 0, 256, 0, ''), -- 43193 (Warlord Krogg)
(43186, 0, 0, 0, 257, 0, ''), -- 43186 (Juice Gnugat)
(43192, 0, 0, 1, 257, 0, ''), -- 43192 (Wounded Axebite Warrior)
(42978, 0, 0, 0, 257, 0, ''), -- 42978 (Admiral Stonefist)
(43683, 0, 0, 50331648, 1, 0, ''), -- 43683 (Goblin Barrage Balloon)
(43187, 0, 0, 0, 257, 0, ''), -- 43187 (Ornak)
(43482, 0, 0, 0, 257, 0, ''), -- 43482 (Axebite Warrior)
(42603, 0, 0, 0, 1, 0, '79428'), -- 42603 (Emergency Rampless Debarkation Device) - Parachute Holder
(43390, 0, 0, 0, 0, 0, ''), -- 43390 (Dragonmaw Enforcer)
(42516, 0, 0, 50331648, 1, 0, ''), -- 42516 (Twilight Swarmer)
(51131, 0, 0, 0, 1, 0, ''), -- 51131 (Wildhammer Homesteader)
(45693, 0, 0, 65536, 1, 0, '87237'), -- 45693 (Tentacle of Iso'rath) - Generic Quest Invisibility 18
(45510, 0, 0, 65536, 1, 0, '87237'), -- 45510 (Tentacle of Iso'rath) - Generic Quest Invisibility 18
(45511, 0, 0, 65536, 1, 0, '87237'), -- 45511 (Tentacle of Iso'rath) - Generic Quest Invisibility 18
(45694, 0, 0, 65536, 1, 0, '87237'), -- 45694 (Tentacle of Iso'rath) - Generic Quest Invisibility 18
(50964, 0, 0, 0, 1, 0, ''), -- 50964 (Chops)
(42314, 0, 0, 0, 257, 0, ''), -- 42314 (Air Defense Cannon)
(51033, 0, 0, 0, 1, 0, ''), -- 51033 (Deathwing Zeppelin Ride Vehicle)
(51137, 0, 0, 50331648, 1, 0, ''), -- 51137 (<Internal> Horde Zeppelin Sound Bunny)
(42195, 0, 0, 0, 256, 0, ''), -- 42195 (Captain Krazz)
(42243, 0, 0, 0, 257, 0, ''), -- 42243 (Fergus Gearchum)
(43869, 0, 0, 0, 1, 0, ''), -- 43869 (Zeppelin Explosion Bunny (Large))
(43868, 0, 0, 0, 1, 0, ''), -- 43868 (Zeppelin Explosion Bunny)
(50369, 0, 0, 50331648, 1, 0, ''), -- 50369 (Deathwing) - Ride Vehicle Hardcoded
(42300, 0, 0, 0, 257, 0, ''), -- 42300 (Kor'kron Air Marine)
(42577, 0, 0, 50331648, 1, 0, '16245'), -- 42577 (Twilight Drake Swarmer) - Ride Vehicle Hardcoded, Freeze Anim
(42576, 0, 0, 50331648, 1, 0, ''), -- 42576 (Drake Rigging Bunny)
(45749, 0, 0, 0, 1, 0, ''), -- 45749 (Aura Generator Bunny)
(42206, 0, 0, 50331648, 1, 0, ''), -- 42206 (The Skyshredder) - Ride Vehicle Hardcoded
(42207, 0, 0, 50331648, 1, 0, ''), -- 42207 (Heart of Orgrimmar) - Ride Vehicle Hardcoded
(42254, 0, 0, 50331648, 1, 0, ''), -- 42254 (Main Air Support Fleet) - Ride Vehicle Hardcoded
(42519, 0, 0, 50331648, 1, 0, '16245'), -- 42519 (Twilight Sky Terror) - Ride Vehicle Hardcoded, Freeze Anim
(42258, 0, 0, 50331648, 1, 0, ''), -- 42258 (Air Support Fleet) - Ride Vehicle Hardcoded
(42257, 0, 0, 50331648, 1, 0, ''), -- 42257 (Air Support Fleet) - Ride Vehicle Hardcoded
(42277, 0, 0, 0, 1, 0, ''), -- 42277 (Garrosh Hellscream) - Ride Vehicle Hardcoded
(42568, 0, 0, 50331648, 1, 0, ''), -- 42568 (Twilight Sky Screamer) - Ride Vehicle Hardcoded
(42567, 0, 0, 50331648, 1, 0, ''), -- 42567 (Twilight Sky Screamer) - Ride Vehicle Hardcoded
(42566, 0, 0, 50331648, 1, 0, ''), -- 42566 (Twilight Sky Screamer) - Ride Vehicle Hardcoded
(42561, 0, 0, 50331648, 1, 0, ''), -- 42561 (Twilight Sky Screamer) - Ride Vehicle Hardcoded
(42320, 0, 0, 50331648, 1, 0, '16245'), -- 42320 (Twilight Sky Terror) - Ride Vehicle Hardcoded, Freeze Anim
(42205, 0, 0, 50331648, 1, 0, ''), -- 42205 (The Impervious) - Ride Vehicle Hardcoded
(42204, 0, 0, 50331648, 1, 0, ''), -- 42204 (The Indomitable) - Ride Vehicle Hardcoded
(42255, 0, 0, 50331648, 1, 0, ''), -- 42255 (Air Support Formation Bunny)
(42246, 0, 0, 50331648, 1, 0, ''), -- 42246 (Zeppelin Formation Bunny 03)
(42245, 0, 0, 50331648, 1, 0, ''), -- 42245 (Zeppelin Formation Bunny 02)
(42247, 0, 0, 50331648, 1, 0, ''), -- 42247 (Zeppelin Formation Bunny 04)
(42241, 0, 0, 50331648, 1, 0, ''), -- 42241 (Zeppelin Formation Bunny 01)
(42268, 0, 0, 50331648, 1, 0, ''), -- 42268 (Garrosh's Airship) - Ride Vehicle Hardcoded
(42267, 0, 0, 50331648, 1, 0, ''), -- 42267 (Garrosh Formation Bunny)
(47217, 0, 0, 0, 1, 0, '79428'), -- 47217 (Emergency Rampless Debarkation Device) - Parachute Holder
(47210, 0, 0, 0, 257, 0, ''), -- 47210 (Air Defense Cannon)
(47209, 0, 0, 0, 257, 0, ''), -- 47209 (Hobart Grapplehammer)
(47208, 0, 0, 0, 257, 0, ''), -- 47208 (Assistant Greely)
(47206, 0, 0, 0, 1, 0, ''), -- 47206 (Loudspeaker)
(50367, 0, 0, 0, 257, 0, ''), -- 50367 (Friz Groundspin)
(62120, 0, 0, 0, 1, 0, ''), -- 62120 (Rabid Nut Varmint 5000)
(70165, 0, 0, 0, 1, 0, ''), -- 70165 (Julie Fabernackle)
(125216, 0, 0, 0, 257, 0, ''), -- 125216 (Kruda Thunderhand)
(60761, 0, 0, 0, 1, 0, ''), -- 60761 (Shore Crab)
(62121, 0, 0, 0, 1, 0, ''), -- 62121 (Turquoise Turtle)
(61255, 0, 0, 0, 1, 0, ''), -- 61255 (Skunk)
(61080, 0, 0, 0, 1, 0, ''), -- 61080 (Rabbit)
(61158, 0, 0, 0, 1, 0, ''), -- 61158 (Shore Crab)
(130911, 0, 0, 0, 257, 0, ''), -- 130911 (Charles Gastly)
(65065, 0, 0, 50331648, 1, 0, ''), -- 65065 (Red Dragon Turtle)
(42707, 0, 0, 0, 1, 0, ''), -- 42707 (Twilight Nightblade)
(70301, 0, 0, 1, 257, 0, ''), -- 70301 (Softpaws)
(65074, 0, 0, 0, 1, 0, ''), -- 65074 (Great Blue Dragon Turtle)
(66022, 0, 0, 0, 1, 0, ''), -- 66022 (Turtlemaster Odai)
(65076, 0, 0, 0, 1, 0, ''), -- 65076 (Great Brown Dragon Turtle)
(65071, 0, 0, 50331648, 1, 0, ''), -- 65071 (Great Green Dragon Turtle)
(35845, 0, 0, 0, 1, 0, ''), -- 35845 (Dave's Industrial Light and Magic Bunny (Small)(Sessile))
(88543, 0, 0, 0, 1, 0, '32783'), -- 88543 (Orgrimmar Mage) - Arcane Channeling
(89830, 0, 0, 0, 1, 0, ''), -- 89830 (Brew Vendor)
(88703, 0, 0, 0, 257, 0, ''), -- 88703 (Grunt Arhung)
(14720, 0, 0, 0, 257, 0, ''), -- 14720 (High Overlord Saurfang)
(89713, 0, 0, 0, 1, 0, ''), -- 89713 (Koak Hoburn)
(38821, 0, 0, 0, 1, 0, ''), -- 38821 (Dave's Industrial Light and Magic Bunny (Medium)(Sessile))
(65078, 0, 0, 0, 1, 0, ''), -- 65078 (Great Purple Dragon Turtle)
(16869, 0, 0, 0, 1, 0, ''), -- 16869 (Jising)
(66437, 0, 0, 0, 1, 0, '32783'), -- 66437 (Arcanist Xu) - Arcane Channeling
(69333, 0, 0, 0, 257, 0, ''), -- 69333 (Disciple Jusi)
(68869, 0, 0, 1, 1, 0, '19231'), -- 68869 (Luo Luo) - Panda
(62445, 0, 0, 0, 1, 0, ''), -- 62445 (Ji Firepaw)
(65061, 0, 0, 0, 1, 0, ''), -- 65061 (Brown Dragon Turtle)
(65060, 0, 0, 0, 1, 0, ''), -- 65060 (Blue Dragon Turtle)
(2756, 0, 0, 0, 1, 0, ''), -- 2756 (Chao-Ju)
(16868, 0, 0, 0, 1, 0, ''), -- 16868 (Winsum)
(65008, 0, 0, 0, 1, 0, ''), -- 65008 (Huojin Monk)
(5034, 0, 0, 0, 1, 0, ''), -- 5034 (Winwa)
(5029, 0, 0, 0, 1, 0, ''), -- 5029 (Jiming)
(65063, 0, 0, 0, 1, 0, ''), -- 65063 (Purple Dragon Turtle)
(65058, 0, 0, 0, 1, 0, ''), -- 65058 (Black Dragon Turtle)
(121541, 0, 0, 0, 1, 0, ''), -- 121541 (Ban-Lu)
(64105, 0, 0, 0, 257, 0, ''), -- 64105 (Muffin)
(114840, 0, 0, 0, 1, 0, '98892 228695 228689'), -- 114840 (PvP Training Dummy) - Training Dummy Marker, PvP Rules Enabled for Dummy, Orc Male Mask
(62193, 0, 0, 1, 257, 0, '116562'), -- 62193 (Rok'kal) - Fishing
(62197, 0, 0, 0, 258, 0, '94218'), -- 62197 (Zazzle) - Grit's Flamethrower Backpack
(62196, 0, 0, 0, 257, 0, '79865'), -- 62196 (Flekky Nox) - Frost Armor
(42548, 0, 0, 0, 1, 0, ''), -- 42548 (Muddy Crawfish)
(62200, 0, 0, 0, 1, 0, ''), -- 62200 (Sasi)
(62199, 0, 0, 0, 1, 0, ''), -- 62199 (Gogu)
(62822, 0, 0, 0, 1, 0, '122729 123240'), -- 62822 (Cousin Slowhands) - Grand Expedition Yak, Grummle Booth B
(62821, 0, 0, 0, 1, 0, ''), -- 62821 (Mystic Birdhat)
(68979, 0, 0, 0, 1, 0, ''), -- 68979 (Voidbinder Zorlan)
(62194, 0, 0, 0, 257, 0, ''), -- 62194 (Ukos Bloodwhisper)
(63626, 0, 0, 0, 1, 0, ''), -- 63626 (Varzok)
(62198, 0, 0, 0, 257, 0, ''), -- 62198 (Omakka Wolfbrother)
(72559, 0, 0, 3, 1, 0, '55701'), -- 72559 (Thunder Bluff Protector) - Cosmetic - Sleep Zzz Breakable
(88702, 0, 0, 0, 257, 0, ''), -- 88702 (Grunt Nolo)
(88701, 0, 0, 1, 257, 0, ''), -- 88701 (Grunt Meena)
(62195, 0, 0, 0, 257, 0, ''), -- 62195 (Shang'gok)
(42637, 0, 0, 65536, 257, 0, '49414'), -- 42637 (Sauranok the Mystic) - Generic Quest Invisibility 1
(52382, 0, 0, 33619968, 1, 0, '94223'), -- 52382 (Ziradormi) - Generic Quest Invisibility 25
(62115, 0, 0, 0, 1, 0, ''), -- 62115 (Dung Beetle)
(62114, 0, 0, 0, 1, 0, ''), -- 62114 (Spiny Lizard)
(74228, 0, 0, 0, 257, 0, ''); -- 74228 (Darkspear Headhunter)

DELETE FROM `creature_template_addon` WHERE `entry`>59072; -- 443 only

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=45439; -- 45439 (Cockroach)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=45230; -- 45230 (Orgrimmar Brave)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=24929; -- 24929 (Crewman Crosswire)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=6370; -- 6370 (Makrinni Scrabbler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=6350; -- 6350 (Makrinni Razorclaw)
UPDATE `creature_template_addon` SET `auras`='42459' WHERE `entry`=36974; -- 36974 (Newt)
UPDATE `creature_template_addon` SET `auras`='42459' WHERE `entry`=36973; -- 36973 (Patch)
UPDATE `creature_template_addon` SET `auras`='42459' WHERE `entry`=36975; -- 36975 (Volt)
UPDATE `creature_template_addon` SET `auras`='42459' WHERE `entry`=36976; -- 36976 (Ticker)
UPDATE `creature_template_addon` SET `auras`='79841' WHERE `entry`=42836; -- 42836 (Bilgewater Mechanic)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=6352; -- 6352 (Coralshell Lurker)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=35095; -- 35095 (Talrendis Scout)
UPDATE `creature_template_addon` SET `auras`='61573 98892' WHERE `entry`=32667; -- 32667 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='61573 98892' WHERE `entry`=32666; -- 32666 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='98892 61573' WHERE `entry`=31144; -- 31144 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='98892 61573' WHERE `entry`=46647; -- 46647 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='98892 61573' WHERE `entry`=31146; -- 31146 (Raider's Training Dummy)
UPDATE `creature_template_addon` SET `auras`='96850 16245 97577' WHERE `entry`=52810; -- 52810 (Toy Cart Bunny)
UPDATE `creature_template_addon` SET `auras`='96847' WHERE `entry`=52812; -- 52812 (Toy Cart)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=43062; -- 43062 (Bort)
UPDATE `creature_template_addon` SET `mount`=29260 WHERE `entry`=50488; -- 50488 (Stone Guard Nargol)
UPDATE `creature_template_addon` SET `mount`=29261 WHERE `entry`=50477; -- 50477 (Champion Uru'zin)
UPDATE `creature_template_addon` SET `auras`='81245' WHERE `entry`=44158; -- 44158 (Orgrimmar Skyway Peon)
UPDATE `creature_template_addon` SET `mount`=17699 WHERE `entry`=44919; -- 44919 (Maztha)

UPDATE `creature_model_info` SET `BoundingRadius`=0.3 WHERE `DisplayID`=38418;
UPDATE `creature_model_info` SET `BoundingRadius`=0.386562, `CombatReach`=1.5, `Gender`=2 WHERE `DisplayID`=4449;
UPDATE `creature_model_info` SET `BoundingRadius`=1.423153 WHERE `DisplayID`=30501;
UPDATE `creature_model_info` SET `BoundingRadius`=0.045, `CombatReach`=0.225 WHERE `DisplayID`=38631;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3062559 WHERE `DisplayID`=4959;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3062559 WHERE `DisplayID`=4960;
UPDATE `creature_model_info` SET `BoundingRadius`=1.824283 WHERE `DisplayID`=5489;
UPDATE `creature_model_info` SET `BoundingRadius`=1.078952 WHERE `DisplayID`=8013;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9200326, `Gender`=2 WHERE `DisplayID`=22003;
UPDATE `creature_model_info` SET `BoundingRadius`=1.073914 WHERE `DisplayID`=34304;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186 WHERE `DisplayID`=34303;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8499918 WHERE `DisplayID`=32904;
UPDATE `creature_model_info` SET `BoundingRadius`=10.3549 WHERE `DisplayID`=32371;
UPDATE `creature_model_info` SET `BoundingRadius`=1.038879 WHERE `DisplayID`=32907;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1850153, `CombatReach`=1.5 WHERE `DisplayID`=26532;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=0.375 WHERE `DisplayID`=32789;
UPDATE `creature_model_info` SET `BoundingRadius`=1.80051 WHERE `DisplayID`=2426;
UPDATE `creature_model_info` SET `BoundingRadius`=2.070586 WHERE `DisplayID`=3215;
UPDATE `creature_model_info` SET `BoundingRadius`=5.458125 WHERE `DisplayID`=23365;
UPDATE `creature_model_info` SET `BoundingRadius`=1.431885, `CombatReach`=2 WHERE `DisplayID`=11261;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2610845 WHERE `DisplayID`=27881;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8233339, `CombatReach`=1.15 WHERE `DisplayID`=4981;
UPDATE `creature_model_info` SET `BoundingRadius`=1.429294 WHERE `DisplayID`=6747;
UPDATE `creature_model_info` SET `BoundingRadius`=2.368339 WHERE `DisplayID`=3166;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3 WHERE `DisplayID`=29821;
UPDATE `creature_model_info` SET `BoundingRadius`=1.819436 WHERE `DisplayID`=14593;
UPDATE `creature_model_info` SET `BoundingRadius`=0.212633 WHERE `DisplayID`=30413;
UPDATE `creature_model_info` SET `BoundingRadius`=3.007739 WHERE `DisplayID`=37138;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8121765 WHERE `DisplayID`=14732;
UPDATE `creature_model_info` SET `BoundingRadius`=4.119178, `CombatReach`=3 WHERE `DisplayID`=25092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7082875 WHERE `DisplayID`=14573;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7082875 WHERE `DisplayID`=14575;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8315721 WHERE `DisplayID`=23519;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4501274, `CombatReach`=0.3125 WHERE `DisplayID`=18269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9288539 WHERE `DisplayID`=20833;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1773533, `CombatReach`=1 WHERE `DisplayID`=20543;
UPDATE `creature_model_info` SET `Gender`=1 WHERE `DisplayID`=37331;
UPDATE `creature_model_info` SET `BoundingRadius`=0.146088 WHERE `DisplayID`=14616;
UPDATE `creature_model_info` SET `Gender`=2 WHERE `DisplayID`=17722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736 WHERE `DisplayID`=36584;
UPDATE `creature_model_info` SET `BoundingRadius`=1.960739 WHERE `DisplayID`=31988;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736 WHERE `DisplayID`=36598;
UPDATE `creature_model_info` SET `BoundingRadius`=1.218375, `CombatReach`=5.0625 WHERE `DisplayID`=5205;
UPDATE `creature_model_info` SET `Gender`=1 WHERE `DisplayID`=37330;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736 WHERE `DisplayID`=36585;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736 WHERE `DisplayID`=36583;

DELETE FROM `npc_vendor` WHERE `entry` IN (50460,50375,50459,49498,49549,50462,50165,50248,50146);	
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `VerifiedBuild`) VALUES --  `PlayerConditionID`, `IgnoreFiltering`
(50460, 24, 20815, 0, 0, 1, 26365), -- Jeweler's Kit
(50460, 23, 3857, 0, 0, 1, 26365), -- Coal
(50460, 22, 30746, 0, 0, 1, 26365), -- Mining Sack
(50460, 21, 4470, 0, 0, 1, 26365), -- Simple Wood
(50460, 20, 10647, 0, 0, 1, 26365), -- Engineer's Ink
(50460, 19, 39354, 0, 0, 1, 26365), -- Light Parchment
(50460, 18, 3466, 0, 0, 1, 26365), -- Strong Flux
(50460, 17, 2880, 0, 0, 1, 26365), -- Weak Flux
(50460, 16, 39684, 0, 0, 1, 26365), -- Hair Trigger
(50460, 15, 40533, 0, 0, 1, 26365), -- Walnut Stock
(50460, 14, 4400, 0, 0, 1, 26365), -- Heavy Stock
(50460, 13, 4399, 0, 0, 1, 26365), -- Wooden Stock
-- (50460, 12, 90146, 0, 0, 1, 26365), -- Tinker's Kit
(50460, 11, 2901, 0, 0, 1, 26365), -- Mining Pick
(50460, 10, 5956, 0, 0, 1, 26365), -- Blacksmith Hammer
(50460, 9, 68660, 0, 989, 1, 26365), -- Mystic Cogwheel
(50460, 8, 59489, 0, 3310, 1, 26365), -- Precise Cogwheel
(50460, 7, 59477, 0, 3392, 1, 26365), -- Subtle Cogwheel
(50460, 6, 59478, 0, 3311, 1, 26365), -- Smooth Cogwheel
(50460, 5, 59479, 0, 3311, 1, 26365), -- Quick Cogwheel
(50460, 4, 59480, 0, 3308, 1, 26365), -- Fractured Cogwheel
(50460, 3, 59491, 0, 3305, 1, 26365), -- Flashing Cogwheel
(50460, 2, 59493, 0, 3307, 1, 26365), -- Rigid Cogwheel
(50460, 1, 59496, 0, 3306, 1, 26365), -- Sparkling Cogwheel
(50375, 34, 66101, 0, 3314, 1, 26365), -- Plans: Pyrium Shield Spike
(50375, 33, 66130, 0, 3314, 1, 26365), -- Plans: Vicious Ornate Pyrium Legguards
(50375, 32, 66131, 0, 3314, 1, 26365), -- Plans: Vicious Ornate Pyrium Helm
(50375, 31, 66132, 0, 3314, 1, 26365), -- Plans: Vicious Ornate Pyrium Breastplate
(50375, 30, 66100, 0, 3314, 1, 26365), -- Plans: Ebonsteel Belt Buckle
(50375, 29, 66122, 0, 3314, 1, 26365), -- Plans: Vicious Pyrium Legguards
(50375, 28, 66123, 0, 3314, 1, 26365), -- Plans: Vicious Pyrium Helm
(50375, 27, 66124, 0, 3314, 1, 26365), -- Plans: Vicious Pyrium Breastplate
(50375, 26, 66129, 0, 3313, 1, 26365), -- Plans: Vicious Ornate Pyrium Shoulders
(50375, 25, 66116, 0, 3313, 1, 26365), -- Plans: Elementium Stormshield
(50375, 24, 66110, 0, 3313, 1, 26365), -- Plans: Elementium Spellblade
(50375, 23, 66114, 0, 3313, 1, 26365), -- Plans: Elementium Shank
(50375, 22, 66112, 0, 3313, 1, 26365), -- Plans: Elementium Poleaxe
(50375, 21, 66115, 0, 3313, 1, 26365), -- Plans: Elementium Earthguard
(50375, 20, 66121, 0, 3313, 1, 26365), -- Plans: Vicious Pyrium Shoulders
(50375, 19, 66128, 0, 3313, 1, 26365), -- Plans: Vicious Ornate Pyrium Boots
(50375, 18, 66108, 0, 3313, 1, 26365), -- Plans: Light Elementium Chestguard
(50375, 17, 66104, 0, 3313, 1, 26365), -- Plans: Hardened Elementium Hauberk
(50375, 16, 66111, 0, 3313, 1, 26365), -- Plans: Elementium Hammer
(50375, 15, 66106, 0, 3313, 1, 26365), -- Plans: Elementium Deathplate
(50375, 14, 66113, 0, 3313, 1, 26365), -- Plans: Elementium Bonesplitter
(50375, 13, 67606, 0, 3314, 1, 26365), -- Plans: Forged Elementium Mindcrusher
(50375, 12, 67603, 0, 3313, 1, 26365), -- Plans: Elementium Gutslicer
(50375, 11, 66120, 0, 3313, 1, 26365), -- Plans: Vicious Pyrium Boots
(50375, 10, 66127, 0, 3312, 1, 26365), -- Plans: Vicious Ornate Pyrium Belt
(50375, 9, 66109, 0, 3312, 1, 26365), -- Plans: Light Elementium Belt
(50375, 8, 66105, 0, 3312, 1, 26365), -- Plans: Hardened Elementium Girdle
(50375, 7, 66107, 0, 3312, 1, 26365), -- Plans: Elementium Girdle of Pain
(50375, 6, 66119, 0, 3312, 1, 26365), -- Plans: Vicious Pyrium Belt
(50375, 5, 66103, 0, 3312, 1, 26365), -- Plans: Pyrium Weapon Chain
(50375, 4, 66126, 0, 3312, 1, 26365), -- Plans: Vicious Ornate Pyrium Gauntlets
(50375, 3, 66125, 0, 3312, 1, 26365), -- Plans: Vicious Ornate Pyrium Bracers
(50375, 2, 66118, 0, 3312, 1, 26365), -- Plans: Vicious Pyrium Gauntlets
(50375, 1, 66117, 0, 3312, 1, 26365), -- Plans: Vicious Pyrium Bracers
(50459, 282, 11291, 0, 0, 1, 26365), -- Star Wood
(50459, 281, 4470, 0, 0, 1, 26365), -- Simple Wood
(50459, 280, 10938, 1, 0, 1, 26365), -- Lesser Magic Essence
(50459, 279, 10940, 3, 0, 1, 26365), -- Strange Dust
(50459, 278, 6217, 0, 0, 1, 26365), -- Copper Rod
(50459, 277, 38682, 0, 0, 1, 26365), -- Enchanting Vellum
(49498, 6, 58257, 0, 0, 1, 26365), -- Highland Spring Water
(49498, 5, 58256, 0, 0, 1, 26365), -- Sparkling Oasis Water
(49498, 4, 58274, 0, 0, 1, 26365), -- Fresh Water
(49498, 3, 58269, 0, 0, 1, 26365), -- Massive Turkey Leg
(49498, 2, 58268, 0, 0, 1, 26365), -- Roasted Beef
(49498, 1, 58280, 0, 0, 1, 26365), -- Stewed Rabbit
(49549, 22, 2451, 0, 0, 1, 26365), -- Crested Heater Shield        -- ignore filter
(49549, 21, 17190, 0, 0, 1, 26365), -- Ornate Buckler              -- ignore filter
(49549, 20, 62259, 0, 0, 1, 26365), -- Grunt's Plate Helm          -- ignore filter
(49549, 19, 62257, 0, 0, 1, 26365), -- Grunt's Plate Gloves        -- ignore filter
(49549, 18, 62256, 0, 0, 1, 26365), -- Grunt's Plate Bracers       -- ignore filter
(49549, 17, 62255, 0, 0, 1, 26365), -- Grunt's Plate Boots         -- ignore filter
(49549, 16, 62258, 0, 0, 1, 26365), -- Grunt's Plate Leggings      -- ignore filter
(49549, 15, 62254, 0, 0, 1, 26365), -- Grunt's Plate Belt          -- ignore filter
(49549, 14, 62253, 0, 0, 1, 26365), -- Grunt's Plate Armor         -- ignore filter
(49549, 13, 62266, 0, 0, 1, 26365), -- Grunt's Chain Circlet       -- ignore filter
(49549, 12, 62263, 0, 0, 1, 26365), -- Grunt's Chain Gloves        -- ignore filter
(49549, 11, 62262, 0, 0, 1, 26365), -- Grunt's Chain Bracers       -- ignore filter
(49549, 10, 62261, 0, 0, 1, 26365), -- Grunt's Chain Boots         -- ignore filter
(49549, 9, 62264, 0, 0, 1, 26365), -- Grunt's Chain Leggings       -- ignore filter
(49549, 8, 62260, 0, 0, 1, 26365), -- Grunt's Chain Belt           -- ignore filter
(49549, 7, 62265, 0, 0, 1, 26365), -- Grunt's Chain Vest           -- ignore filter
(49549, 6, 3857, 0, 0, 1, 26365), -- Coal
(49549, 5, 18567, 0, 0, 1, 26365), -- Elemental Flux
(49549, 4, 3466, 0, 0, 1, 26365), -- Strong Flux
(49549, 3, 2880, 0, 0, 1, 26365), -- Weak Flux
(49549, 2, 5956, 0, 0, 1, 26365), -- Blacksmith Hammer
(49549, 1, 2901, 0, 0, 1, 26365), -- Mining Pick
(50462, 1, 64670, 0, 0, 1, 26365), -- Vanishing Powder
(50165, 2, 52188, 0, 0, 1, 26365), -- Jeweler's Setting
(50165, 1, 20815, 0, 0, 1, 26365), -- Jeweler's Kit
(50248, 10, 67335, 0, 0, 1, 26365), -- Silver Charm Bracelet
(50248, 9, 67319, 0, 0, 1, 26365), -- Preserved Ogre Eye
(50248, 8, 67348, 0, 0, 1, 26365), -- Bleached Jawbone
(50248, 7, 68047, 0, 0, 1, 26365), -- Scavenged Dragon Horn
(50248, 6, 62323, 0, 0, 1, 26365), -- Deathwing Scale Fragment
(50248, 5, 64670, 0, 0, 1, 26365), -- Vanishing Powder
(50248, 4, 39354, 0, 0, 1, 26365), -- Light Parchment
(50248, 3, 39489, 0, 0, 1, 26365), -- Scribe's Satchel
(50248, 2, 39505, 0, 0, 1, 26365), -- Virtuoso Inking Set
(50248, 1, 3371, 0, 0, 1, 26365), -- Crystal Vial
(50146, 14, 52735, 0, 3017, 1, 26365), -- Formula: Enchant Weapon - Windwalk
(50146, 13, 52733, 0, 3017, 1, 26365), -- Formula: Enchant Weapon - Power Torrent
(50146, 12, 52736, 0, 3017, 1, 26365), -- Formula: Enchant Weapon - Landslide
(50146, 11, 64415, 0, 3016, 1, 26365), -- Formula: Enchant Gloves - Mighty Strength
(50146, 10, 64414, 0, 3016, 1, 26365), -- Formula: Enchant Gloves - Greater Mastery
(50146, 9, 52737, 0, 3016, 1, 26365), -- Formula: Enchant Cloak - Greater Critical Strike
(50146, 8, 52739, 0, 3016, 1, 26365), -- Formula: Enchant Chest - Peerless Stats
(50146, 7, 52740, 0, 3016, 1, 26365), -- Formula: Enchant Chest - Greater Stamina
(50146, 6, 64413, 0, 3016, 1, 26365), -- Formula: Enchant Bracer - Greater Speed
(50146, 5, 52738, 0, 3016, 1, 26365), -- Formula: Enchant Bracer - Greater Critical Strike
(50146, 4, 64412, 0, 3016, 1, 26365), -- Formula: Enchant Boots - Lavawalker
(50146, 3, 64411, 0, 3016, 1, 26365), -- Formula: Enchant Boots - Assassin's Step
(50146, 2, 67308, 0, 3326, 1, 26365); -- Formula: Enchanted Lantern

UPDATE `npc_vendor` SET `incrtime`=120 WHERE `item` IN (10938,10940) AND `entry`=50459;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=42775 AND `ID`=7) OR (`CreatureID`=42775 AND `ID`=6) OR (`CreatureID`=46709 AND `ID`=2) OR (`CreatureID`=69977 AND `ID`=1) OR (`CreatureID`=69978 AND `ID`=1) OR (`CreatureID`=73151 AND `ID`=1) OR (`CreatureID`=88706 AND `ID`=1) OR (`CreatureID`=88705 AND `ID`=1) OR (`CreatureID`=88704 AND `ID`=1) OR (`CreatureID`=133271 AND `ID`=1) OR (`CreatureID`=42775 AND `ID`=5) OR (`CreatureID`=43941 AND `ID`=1) OR (`CreatureID`=43421 AND `ID`=1) OR (`CreatureID`=43387 AND `ID`=1) OR (`CreatureID`=51131 AND `ID`=1) OR (`CreatureID`=42775 AND `ID`=4) OR (`CreatureID`=42775 AND `ID`=3) OR (`CreatureID`=70165 AND `ID`=1) OR (`CreatureID`=37010 AND `ID`=1) OR (`CreatureID`=42775 AND `ID`=2) OR (`CreatureID`=42836 AND `ID`=3) OR (`CreatureID`=42836 AND `ID`=2) OR (`CreatureID`=42775 AND `ID`=1) OR (`CreatureID`=125216 AND `ID`=1) OR (`CreatureID`=42646 AND `ID`=1) OR (`CreatureID`=44158 AND `ID`=3) OR (`CreatureID`=44158 AND `ID`=2) OR (`CreatureID`=44158 AND `ID`=1) OR (`CreatureID`=46622 AND `ID`=1) OR (`CreatureID`=89830 AND `ID`=1) OR (`CreatureID`=88703 AND `ID`=1) OR (`CreatureID`=69333 AND `ID`=1) OR (`CreatureID`=42650 AND `ID`=3) OR (`CreatureID`=42650 AND `ID`=2) OR (`CreatureID`=42650 AND `ID`=1) OR (`CreatureID`=3296 AND `ID`=2) OR (`CreatureID`=62193 AND `ID`=1) OR (`CreatureID`=62197 AND `ID`=1) OR (`CreatureID`=62196 AND `ID`=1) OR (`CreatureID`=68979 AND `ID`=1) OR (`CreatureID`=62194 AND `ID`=1) OR (`CreatureID`=72559 AND `ID`=1) OR (`CreatureID`=88702 AND `ID`=1) OR (`CreatureID`=88701 AND `ID`=1) OR (`CreatureID`=62195 AND `ID`=1) OR (`CreatureID`=44851 AND `ID`=1) OR (`CreatureID`=74228 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(42775, 7, 1903, 0, 33080), -- Bilgewater Dockworker
(42775, 6, 1902, 0, 33080), -- Bilgewater Dockworker
(46709, 2, 2196, 0, 0), -- Arugi
-- (69977, 1, 37123, 0, 0), -- Blood Guard Zar'shi
-- (69978, 1, 14824, 0, 0), -- Sergeant Thunderhorn
-- (73151, 1, 100541, 0, 0), -- Deathguard Netharian
-- (88706, 1, 5304, 0, 0), -- Murgul
-- (88705, 1, 5277, 0, 0), -- Kranosh
-- (88704, 1, 5277, 0, 0), -- Gran'dul
-- (133271, 1, 0, 0, 34268), -- Highmountain Pathfinder
(42775, 5, 0, 0, 33080), -- Bilgewater Dockworker
(43941, 1, 1902, 0, 0), -- Dragonmaw Worker
(43421, 1, 5956, 0, 0), -- Dragonmaw Blacksmith
(43387, 1, 1902, 0, 0), -- Dragonmaw Worker
(51131, 1, 1910, 0, 0), -- Wildhammer Homesteader
(42775, 4, 1910, 0, 0), -- Bilgewater Dockworker
(42775, 3, 12801, 0, 0), -- Bilgewater Dockworker
-- (70165, 1, 0, 0, 15460), -- Julie Fabernackle
(37010, 1, 31824, 0, 0), -- Artillery Technician
(42775, 2, 31824, 0, 0), -- Bilgewater Dockworker
(42836, 3, 31824, 0, 0), -- Bilgewater Mechanic
(42836, 2, 31824, 0, 33080), -- Bilgewater Mechanic
(42775, 1, 1903, 0, 0), -- Bilgewater Dockworker
-- (125216, 1, 111625, 0, 0), -- Kruda Thunderhand
(42646, 1, 2703, 0, 0), -- AWOL Grunt
(44158, 3, 1902, 0, 0), -- Orgrimmar Skyway Peon
(44158, 2, 1903, 0, 0), -- Orgrimmar Skyway Peon
(44158, 1, 3367, 0, 0), -- Orgrimmar Skyway Peon
(46622, 1, 3346, 0, 0), -- Vuvanzi
-- (89830, 1, 33161, 0, 0), -- Brew Vendor
-- (88703, 1, 5289, 0, 5260), -- Grunt Arhung
-- (69333, 1, 89988, 0, 0), -- Disciple Jusi
(42650, 3, 1910, 0, 0), -- Goblin Siegeworker
(42650, 2, 1902, 0, 0), -- Goblin Siegeworker
(42650, 1, 1903, 0, 0), -- Goblin Siegeworker
(3296, 2, 0, 0, 2507), -- Orgrimmar Grunt
-- (62193, 1, 1117, 0, 0), -- Rok'kal
-- (62197, 1, 0, 0, 30128), -- Zazzle
-- (62196, 1, 2177, 0, 0), -- Flekky Nox
-- (68979, 1, 29417, 71741, 0), -- Voidbinder Zorlan
-- (62194, 1, 76711, 73203, 0), -- Ukos Bloodwhisper
-- (72559, 1, 33609, 12454, 49462), -- Thunder Bluff Protector
-- (88702, 1, 2704, 0, 0), -- Grunt Nolo
-- (88701, 1, 5287, 0, 0), -- Grunt Meena
-- (62195, 1, 73893, 0, 0), -- Shang'gok
(44851, 1, 3346, 0, 0); -- Mezlik
-- (74228, 1, 13631, 0, 5870); -- Darkspear Headhunter

UPDATE `creature_equip_template` SET `ItemID1`=0, `ItemID3`=33080 WHERE (`CreatureID`=42836 AND `ID`=1); -- Bilgewater Mechanic
-- UPDATE `creature_equip_template` SET `ItemID1`=155857 WHERE (`CreatureID`=14720 AND `ID`=1); -- High Overlord Saurfang
UPDATE `creature_equip_template` SET `ItemID1`=2827 WHERE (`CreatureID`=46709 AND `ID`=1); -- Arugi

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (43209,42205,51033,37139,36972,52812,42314,42576,42204,42204,42204,42204,42246,42255,42255,42255,42247,42268,42268,43195,42247,42246,52809,52812);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(43209, 43208, 0, 1, 'Landing Boat - Axebite Warrior', 5, 0), -- Landing Boat - Axebite Warrior
(42205, 42320, 0, 1, 'The Impervious - Twilight Sky Terror', 5, 0), -- The Impervious - Twilight Sky Terror
(51033, 50369, 0, 1, 'Deathwing Zeppelin Ride Vehicle - Deathwing', 5, 0), -- Deathwing Zeppelin Ride Vehicle - Deathwing
(37139, 37140, 0, 1, 'Wings of Steel - Airborne Priest', 5, 0), -- Wings of Steel - Airborne Priest
(36972, 36787, 0, 1, 'Grit - Oil Canister (Small)', 5, 0), -- Grit - Oil Canister (Small)
(52812, 52810, 0, 1, 'Toy Cart - Toy Cart Bunny', 5, 0), -- Toy Cart - Toy Cart Bunny
(42314, 48535, 0, 1, 'Air Defense Cannon - Krazzworks Sky Marshall', 5, 0), -- Air Defense Cannon - Krazzworks Sky Marshall
(42576, 42577, 0, 1, 'Drake Rigging Bunny - Twilight Drake Swarmer', 5, 0), -- Drake Rigging Bunny - Twilight Drake Swarmer
(42204, 42568, 6, 1, 'The Indomitable - Twilight Sky Screamer', 5, 0), -- The Indomitable - Twilight Sky Screamer
(42204, 42567, 4, 1, 'The Indomitable - Twilight Sky Screamer', 5, 0), -- The Indomitable - Twilight Sky Screamer
(42204, 42566, 2, 1, 'The Indomitable - Twilight Sky Screamer', 5, 0), -- The Indomitable - Twilight Sky Screamer
(42204, 42561, 0, 1, 'The Indomitable - Twilight Sky Screamer', 5, 0), -- The Indomitable - Twilight Sky Screamer
(42246, 42206, 1, 1, 'Zeppelin Formation Bunny 03 - The Skyshredder', 5, 0), -- Zeppelin Formation Bunny 03 - The Skyshredder
(42255, 42258, 4, 1, 'Air Support Formation Bunny - Air Support Fleet', 5, 0), -- Air Support Formation Bunny - Air Support Fleet
(42255, 42257, 2, 1, 'Air Support Formation Bunny - Air Support Fleet', 5, 0), -- Air Support Formation Bunny - Air Support Fleet
(42255, 42254, 0, 1, 'Air Support Formation Bunny - Main Air Support Fleet', 5, 0), -- Air Support Formation Bunny - Main Air Support Fleet
(42247, 42207, 1, 1, 'Zeppelin Formation Bunny 04 - Heart of Orgrimmar', 5, 0), -- Zeppelin Formation Bunny 04 - Heart of Orgrimmar
(42268, 42519, 1, 1, 'Garrosh''s Airship - Twilight Sky Terror', 5, 0), -- Garrosh's Airship - Twilight Sky Terror
(42268, 42277, 0, 1, 'Garrosh''s Airship - Garrosh Hellscream', 5, 0), -- Garrosh's Airship - Garrosh Hellscream
(43195, 43208, 0, 1, 'Landing Boat - Axebite Warrior', 5, 0), -- Landing Boat - Axebite Warrior
(42247, 42207, 0, 1, 'Zeppelin Formation Bunny 04 - Heart of Orgrimmar', 5, 0), -- Zeppelin Formation Bunny 04 - Heart of Orgrimmar
(42246, 42206, 0, 1, 'Zeppelin Formation Bunny 03 - The Skyshredder', 5, 0), -- Zeppelin Formation Bunny 03 - The Skyshredder
(52809, 52812, 0, 1, 'Toy Cart on Blax Bottlerocket', 5, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (42204,42671,42673,35111,42646,42644,36917,37139,36437,42603,52809,52812,43209,43195,42205,51033,36972,42314,42576,42246,42255,42247,42268);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42671, 79568, 1, 0),
(42673, 79545, 1, 0),
(35111, 66778, 1, 0),
(42646, 80017, 1, 0),
(42644, 79936, 1, 0),
(36917, 81432, 1, 0),
(37139, 46598, 1, 0),
(36437, 68726, 1, 0),
(42603, 79418, 1, 0),
(42603, 90102, 1, 0),
(52809, 46598, 0, 0),
(52812, 46598, 0, 0),
(43209, 46598, 0, 0),
(43195, 46598, 0, 0),
(42205, 63313, 0, 0),
(51033, 46598, 0, 0),
(36972, 46598, 0, 0),
(42314, 46598, 0, 0),
(42576, 46598, 0, 0),
(42246, 63313, 0, 0),
(42255, 46598, 0, 0),
(42247, 63313, 0, 0),
(42204, 46598, 0, 0),
(42268, 46598, 0, 0);

UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216  WHERE `entry` IN (42671,42673,35111,42646,42644,36917,37139,36437,42603,52809,52812,43209,43195,42205,51033,36972,42314,42576,42246,42255,42247,42268);
UPDATE `gossip_menu_option` SET `OptionID`=3, `OptionNpcFlag`=128 WHERE `MenuID`=12759;

DELETE FROM `gossip_menu` WHERE (`MenuID`=6022 AND `TextId`=7174) OR (`MenuID`=11809 AND `TextId`=16558) OR (`MenuID`=14013 AND `TextId`=4793) OR (`MenuID`=14012 AND `TextId`=4793) OR (`MenuID`=14226 AND `TextId`=4793) OR (`MenuID`=11804 AND `TextId`=16554) OR (`MenuID`=11737 AND `TextId`=16430) OR (`MenuID`=11704 AND `TextId`=16447) OR (`MenuID`=11653 AND `TextId`=16284) OR (`MenuID`=14221 AND `TextId`=16881);
INSERT INTO `gossip_menu` (`MenuID`, `TextId`) VALUES
(6022, 7174), -- 14720 (High Overlord Saurfang)
(11809, 16558), -- 44158 (Orgrimmar Skyway Peon)
(14013, 4793), -- 3328 (Ormok)
(14012, 4793), -- 3327 (Gest)
(14226, 4793), -- 47233 (Gordul)
(11804, 16554), -- 44160 (Suspicious Peon)
(11737, 16430), -- 43390 (Dragonmaw Enforcer)
(11704, 16447), -- 43582 (Ornak)
(11653, 16284), -- 42638 (Herezegor Flametusk)
(14221, 16881); -- 49896 (Fizz Lighter)

DELETE FROM `gossip_menu_option` WHERE `MenuID`=11809 AND `OptionID`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `ActionMenuID`) VALUES
(11809, 0, 0, 'Has a secret cult infiltrated the Orgrimmar skyway?', 0,11808);
UPDATE `gossip_menu_option` SET `ActionMenuID`=11807 WHERE `MenuID`=11806 ;
UPDATE `gossip_menu_option` SET `ActionMenuID`=11805 WHERE `MenuID`=11804 ;
UPDATE `gossip_menu_option` SET `ActionMenuID`=11806 WHERE `MenuID`=11805 ;

-- DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=11809 AND `OptionIndex`=0) OR (`MenuId`=11806 AND `OptionIndex`=0) OR (`MenuId`=11804 AND `OptionIndex`=0) OR (`MenuId`=11805 AND `OptionIndex`=0);
-- INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
-- (11809, 0, 11808, 0),
-- (11806, 0, 11807, 0),
-- (11804, 0, 11805, 0),
-- (11805, 0, 11806, 0);

SET @GROUP_ID:=0;
SET @ID:=0;
DELETE FROM  `creature_text` WHERE `CreatureID` IN (35845,42195,42243,42277,42300,42638,42641,42644,42646,42650,42671,42707,42709,42775,42777,42978,43187,43188,43189,43190,43191,43193,43238,43260,43581,43627,43628,43869,43939,43943,43962,44024,44120,44160,45982,47206,47206,47208,47209);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(35845, @GROUP_ID+0, @ID+0, 'You sense that you are being followed...', 16, 0, 100, 0, 0, 3325, 0, 'Dave''s Industrial Light and Magic Bunny (Small)(Sessile) to Player'),
(42195, @GROUP_ID+0, @ID+0, 'Take us out, Mister Gearchum.', 12, 0, 100, 1, 0, 19660, 0, 'Captain Krazz'),
(42195, @GROUP_ID+1, @ID+0, 'Chart a course east with all possible speed. We''ll rendezvous with the main fleet.', 12, 0, 100, 5, 0, 19661, 0, 'Captain Krazz'),
(42195, @GROUP_ID+2, @ID+0, 'Signal the fleet to fall into formation.', 12, 0, 100, 1, 0, 19663, 0, 'Captain Krazz'),
(42195, @GROUP_ID+3, @ID+0, 'Order the fleet into close formation. Keep it tight, everyone!', 12, 0, 100, 25, 0, 19664, 0, 'Captain Krazz'),
(42195, @GROUP_ID+4, @ID+0, 'Heart of Orgrimmar, you''re coming in too low. Too low!', 12, 0, 100, 1, 0, 19665, 0, 'Captain Krazz'),
(42195, @GROUP_ID+5, @ID+0, 'Pull up! Pull down! PULL SOMETHING!', 14, 0, 100, 5, 0, 0, 0, 'Captain Krazz'),
(42195, @GROUP_ID+6, @ID+0, 'The valley should mask our movements. Stay low. Stay close.', 12, 0, 100, 1, 0, 19666, 0, 'Captain Krazz'),
(42195, @GROUP_ID+7, @ID+0, 'I don''t want to see any more mistakes!', 12, 0, 100, 5, 0, 0, 0, 'Captain Krazz'),
(42195, @GROUP_ID+8, @ID+0, 'What - WHAT!? What does he think he''s DOING? The carriers are unprotected.', 12, 0, 100, 5, 0, 19667, 0, 'Captain Krazz'),
(42195, @GROUP_ID+9, @ID+0, 'What kind of madman orders away his close air support?', 12, 0, 100, 6, 0, 19668, 0, 'Captain Krazz'),
(42195, @GROUP_ID+10, @ID+0, 'Mister Gearchum, signal the fleet. Defensive formations!', 12, 0, 100, 1, 0, 19669, 0, 'Captain Krazz'),
(42195, @GROUP_ID+11, @ID+0, 'We''re without our escort. I want to see interlocking fields of fire. Now, now!', 12, 0, 100, 5, 0, 19670, 0, 'Captain Krazz'),
(42195, @GROUP_ID+12, @ID+0, 'What the WHAT!?', 12, 0, 100, 0, 0, 19671, 0, 'Captain Krazz'),
(42195, @GROUP_ID+13, @ID+0, 'The guns, man the guns! Fire everything we''ve got!', 14, 0, 100, 5, 0, 19672, 0, 'Captain Krazz'),
(42195, @GROUP_ID+14, @ID+0, 'Egah - all hands aft. One''s aboard. Shoot it! Kill it!', 12, 0, 100, 5, 0, 19673, 0, 'Captain Krazz'),
(42195, @GROUP_ID+15, @ID+0, 'Somebody, DO SOMETHING! That''s an order!', 12, 0, 100, 15, 0, 19674, 0, 'Captain Krazz'),
(42195, @GROUP_ID+16, @ID+0, 'Tamp down the inflammants. Batten up the gear carriage. Rudder for the shore.', 12, 0, 100, 1, 0, 19675, 0, 'Captain Krazz'),
(42195, @GROUP_ID+17, @ID+0, 'Everyone, to the parachutes!', 14, 0, 100, 15, 0, 19677, 0, 'Captain Krazz'),
(42195, @GROUP_ID+18, @ID+0, 'Mayday! Mayday! Mayday! Bail out everyone. BAIL!', 14, 0, 100, 5, 0, 19676, 0, 'Captain Krazz'),
(42243, @GROUP_ID+0, @ID+0, 'Aye aye, sir.', 12, 0, 100, 66, 0, 19597, 0, 'Fergus Gearchum'),
(42243, @GROUP_ID+1, @ID+0, 'Approaching the Thandol Span, sir.', 12, 0, 100, 25, 0, 19599, 0, 'Fergus Gearchum'),
(42243, @GROUP_ID+2, @ID+0, 'Oh, the Goblinity!', 14, 0, 100, 15, 0, 19600, 0, 'Fergus Gearchum'),
(42243, @GROUP_ID+3, @ID+0, 'Coming up on the Twilight Highlands, Captain. ', 12, 0, 100, 25, 0, 19601, 0, 'Fergus Gearchum'),
(42243, @GROUP_ID+4, @ID+0, 'Captain, sir! Alliance naval fleet sighted off the port bow.', 12, 0, 100, 25, 0, 19602, 0, 'Fergus Gearchum'),
(42243, @GROUP_ID+5, @ID+0, 'It''s tangled up in the rigging.', 12, 0, 100, 1, 0, 19603, 0, 'Fergus Gearchum'),
(42243, @GROUP_ID+6, @ID+0, 'She''s breaking up, sir!', 12, 0, 100, 5, 0, 19604, 0, 'Fergus Gearchum'),
(42277, @GROUP_ID+0, @ID+0, 'Fellow warriors of the Horde. Hear me now!', 14, 0, 100, 15, 0, 20542, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+1, @ID+0, 'Ahead hides our foe. Worshippers of chaos who seek to remake the world.', 14, 0, 100, 1, 0, 20564, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+2, @ID+0, 'A new world is coming, friends. But it is not the world of their design.', 14, 0, 100, 273, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+3, @ID+0, 'Together, we will crush the Twilight''s Hammer, raze their stronghold,', 14, 0, 100, 25, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+4, @ID+0, 'salt the earth, and burn the bodies. All will tremble at our might. ', 14, 0, 100, 5, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+5, @ID+0, 'Then we will stand astride this world as its masters -', 14, 0, 100, 1, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+6, @ID+0, 'united in our conviction, unrivaled in strength, beholden to no one. ', 14, 0, 100, 5, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+7, @ID+0, 'Today, WE will remake the world. OUR world. FOR THE HORDE!', 14, 0, 100, 15, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+8, @ID+0, 'The Alliance steams in close formation without escort.', 14, 0, 100, 1, 0, 20543, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+9, @ID+0, 'Air guard, attack!! Strafe them now, while they cannot maneuver!', 14, 0, 100, 5, 0, 0, 0, 'Garrosh Hellscream to Garrosh Formation Bunny'),
(42277, @GROUP_ID+10, @ID+0, 'GET!', 14, 0, 100, 5, 0, 20544, 0, 'Garrosh Hellscream to Garrosh''s Airship'),
(42277, @GROUP_ID+11, @ID+0, 'OFF!', 14, 0, 100, 5, 0, 0, 0, 'Garrosh Hellscream to Garrosh''s Airship'),
(42277, @GROUP_ID+12, @ID+0, 'MY!', 14, 0, 100, 5, 0, 0, 0, 'Garrosh Hellscream to Garrosh''s Airship'),
(42277, @GROUP_ID+13, @ID+0, 'SHIP!', 14, 0, 100, 5, 0, 21505, 0, 'Garrosh Hellscream to Garrosh''s Airship'),
(42300, @GROUP_ID+0, @ID+0, 'Look - dwarves. Hah! They sulk like prairie dogs in holes in the ground.', 12, 0, 100, 25, 0, 21501, 0, 'Kor''kron Air Marine'),
(42300, @GROUP_ID+1, @ID+0, 'A winner.', 12, 0, 100, 1, 0, 21502, 0, 'Kor''kron Air Marine'),
(42300, @GROUP_ID+2, @ID+0, 'It''s an attack!', 14, 0, 100, 5, 0, 21503, 0, 'Kor''kron Air Marine'),
(42300, @GROUP_ID+3, @ID+0, 'They''re after the Warchief -', 12, 0, 100, 5, 0, 21504, 0, 'Kor''kron Air Marine'),
(42300, @GROUP_ID+4, @ID+0, 'The Warchief''s zeppelin is in flames! It''s going down!', 12, 0, 100, 25, 0, 21505, 0, 'Kor''kron Air Marine'),
(42638, @GROUP_ID+0, @ID+0, 'I will help, but know that you''re stepping into a viper''s nest. Let me draw you a map - wha - behind you!', 12, 0, 100, 5, 0, 3325, 0, 'Herezegor Flametusk to Player'),
(42638, @GROUP_ID+1, @ID+0, '%s motions for you to speak with him again.', 16, 0, 100, 0, 0, 0, 0, 'Herezegor Flametusk to Player'),
(42638, @GROUP_ID+2, @ID+0, 'You fight without honor and die like vermin!', 12, 0, 100, 0, 0, 3325, 0, 'Herezegor Flametusk to Twilight Nightblade'),
(42638, @GROUP_ID+3, @ID+0, '%s scrawls out a depiction of his home port on a torn parchment.', 16, 0, 100, 397, 0, 0, 0, 'Herezegor Flametusk to Player'),
(42638, @GROUP_ID+4, @ID+0, 'There you have it, $n. All the safe approaches to the Twilight Highlands. Unleash havoc on our foes!', 12, 0, 100, 1, 0, 0, 0, 'Herezegor Flametusk to Player'),
(42641, @GROUP_ID+0, @ID+0, 'My warriors! You have already proven your valor. This is why the Warchief has selected you.', 12, 0, 100, 1, 0, 0, 0, 'Warlord Krogg'),
(42641, @GROUP_ID+1, @ID+0, 'Our destination is the Twilight Highlands. We strike at the beating heart of our enemy.', 12, 0, 100, 274, 0, 0, 0, 'Warlord Krogg'),
(42644, @GROUP_ID+0, @ID+0, 'All hail Samophlange!', 12, 0, 100, 5, 0, 0, 0, 'Smoot'),
(42644, @GROUP_ID+1, @ID+0, '$n stiff-arms Smoot and throws him to the ground.', 16, 0, 100, 0, 0, 0, 0, 'Smoot to Player'),
(42646, @GROUP_ID+0, @ID+0, '$gRight away, sir:Right away ma''am;!', 12, 0, 100, 2, 0, 0, 0, 'AWOL Grunt to Player'),
(42646, @GROUP_ID+1, @ID+0, 'Please don''t tell the Warlord...', 12, 0, 100, 2, 0, 0, 0, 'AWOL Grunt to Player'),
(42646, @GROUP_ID+2, @ID+0, '$gSir, yes sir:Ma''am, yes ma''am;!', 12, 0, 100, 2, 0, 0, 0, 'AWOL Grunt to Player'),
(42646, @GROUP_ID+3, @ID+0, 'It won''t happen again, $gsir:ma''am;.', 12, 0, 100, 16, 0, 0, 0, 'AWOL Grunt to Player'),
(42650, @GROUP_ID+0, @ID+0, 'We''ll get right on this, $gsir:ma''am;!', 12, 0, 100, 432, 0, 0, 0, 'Goblin Siegeworker to Player'),
(42650, @GROUP_ID+1, @ID+0, 'We''re on it!', 12, 0, 100, 432, 0, 0, 0, 'Goblin Siegeworker to Player'),
(42650, @GROUP_ID+2, @ID+0, 'Yes $gsir:ma''am;! Right away, $gsir:ma''am;! ', 12, 0, 100, 432, 0, 0, 0, 'Goblin Siegeworker to Player'),
(42671, @GROUP_ID+0, @ID+0, 'This baby is all mine! I call her, "The Throttler."', 12, 0, 100, 66, 0, 0, 0, 'Chief Engineer to Player'),
(42671, @GROUP_ID+1, @ID+0, 'Ready for inspection! ...Be gentle.', 12, 0, 100, 66, 0, 0, 0, 'Chief Engineer to Player'),
(42671, @GROUP_ID+2, @ID+0, 'Uh oh. Um. Oops.', 12, 0, 100, 0, 0, 0, 0, 'Chief Engineer to Player'),
(42671, @GROUP_ID+3, @ID+0, 'Look, look, it''s okay! It''s just a tiny little glitch. See?', 12, 0, 100, 0, 0, 0, 0, 'Chief Engineer to Player'),
(42671, @GROUP_ID+4, @ID+0, 'A little paint and it''ll be fine!', 12, 0, 100, 0, 0, 0, 0, 'Chief Engineer to Player'),
(42707, @GROUP_ID+0, @ID+0, 'Cover the door - we''ve got him!', 12, 0, 100, 0, 0, 0, 0, 'Twilight Nightblade to Player'),
(42709, @GROUP_ID+0, @ID+0, 'Oh no not de bar! Take it outside, mon!', 12, 0, 100, 0, 0, 0, 0, 'Gravy to Player'),
(42775, @GROUP_ID+0, @ID+0, 'What can I do for you, chief?', 12, 0, 100, 432, 0, 0, 0, 'Bilgewater Dockworker to Player'),
(42777, @GROUP_ID+0, @ID+0, 'Nobody tells me how to run my business here.', 12, 0, 100, 25, 0, 0, 0, 'Bilgewater Foreman to Player'),
(42777, @GROUP_ID+1, @ID+0, 'It was just a couple of rivets. That ship had plenty!', 12, 0, 100, 5, 0, 0, 0, 'Bilgewater Foreman'),
(42777, @GROUP_ID+2, @ID+0, 'I''m sure it would''ve been seaworthy in calm waters.', 12, 0, 100, 15, 0, 0, 0, 'Bilgewater Foreman'),
(42777, @GROUP_ID+3, @ID+0, 'Less rivets mean a cleaner environment!', 12, 0, 100, 25, 0, 0, 0, 'Bilgewater Foreman'),
(42777, @GROUP_ID+4, @ID+0, '...can we settle this with cash?', 12, 0, 100, 0, 0, 0, 0, 'Bilgewater Foreman'),
(42777, @GROUP_ID+5, @ID+0, 'Okay okay, stop! Stop! You make a compelling argument.', 12, 0, 100, 5, 0, 0, 0, 'Bilgewater Foreman'),
(42777, @GROUP_ID+6, @ID+0, 'I''ll double the worker shifts and put in my own money to get those ships seaworthy and back on schedule. Count on it!', 12, 0, 100, 1, 0, 0, 0, 'Bilgewater Foreman'),
(42978, @GROUP_ID+0, @ID+0, 'What do we do now? Surely the Warchief would want us to storm the port in force!', 12, 0, 100, 5, 0, 0, 0, 'Admiral Stonefist to Player'),
(43187, @GROUP_ID+0, @ID+0, 'Ornak orders a boat to push off for the fleet.', 16, 0, 100, 0, 0, 0, 0, 'Ornak to Player'),
(43188, @GROUP_ID+0, @ID+0, 'See me if you need a boat to the shore, $n!', 12, 0, 100, 0, 0, 0, 0, 'Horzog to Player'),
(43188, @GROUP_ID+1, @ID+0, 'Horzog orders a landing boat to be lowered into the water. ', 16, 0, 100, 0, 0, 0, 0, 'Horzog to Player'),
(43189, @GROUP_ID+0, @ID+0, 'This pathetic revolution ends here!', 12, 0, 100, 0, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43189, @GROUP_ID+1, @ID+0, 'Pathetic worms. Prepare to face the Mor''ghor Slam!', 14, 0, 100, 397, 0, 0, 0, 'Warchief Mor''ghor'),
(43189, @GROUP_ID+2, @ID+0, 'Zaela ... traitorous fool ... have you sold your soul to the Horde? Are you and I so different? Cast your lot with Hellscream, then. See where he takes you.', 12, 0, 100, 0, 0, 0, 0, 'Warchief Mor''ghor to Dragonmaw Shaman'),
(43190, @GROUP_ID+0, @ID+0, 'Gregor, you coward! Orcs of pure blood are dying off our shores. If you doom them, you doom us all.', 12, 0, 100, 5, 0, 0, 0, 'Zaela to Player'),
(43190, @GROUP_ID+1, @ID+0, 'Hurry, Gorthul. Undo $ghis:her; bonds.', 12, 0, 100, 0, 0, 0, 0, 'Zaela to Player'),
(43190, @GROUP_ID+2, @ID+0, '$n, I''ve rescued your equipment for you. I think you''ve seen all you need to see.', 12, 0, 100, 1, 0, 0, 0, 'Zaela to Player'),
(43190, @GROUP_ID+3, @ID+0, 'Remember, $n. Not all Dragonmaw are your enemies!', 12, 0, 100, 1, 0, 0, 0, 'Zaela to Player'),
(43191, @GROUP_ID+0, @ID+0, 'I ... I can''t give you any of our supplies! Our Warchief... He would...', 12, 0, 100, 274, 0, 0, 0, 'Gregor to Player'),
(43191, @GROUP_ID+1, @ID+0, 'Very well, Zaela. I trust you to do the right thing. $C, I can help your fallen warriors...', 12, 0, 100, 2, 0, 0, 0, 'Gregor to Player'),
(43193, @GROUP_ID+0, @ID+0, 'Perhaps. And perhaps we would win, but at what cost? Maybe $n has a better plan...', 12, 0, 100, 274, 0, 0, 0, 'Warlord Krogg to Player'),
(43238, @GROUP_ID+0, @ID+0, 'I am ready, $n. Soon the Dragonmaw will join the Horde!', 12, 0, 100, 0, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+1, @ID+0, 'I hear a great Dragonmaw medicine man lives here, in the large hut to our right.', 12, 0, 100, 25, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+2, @ID+0, 'After these negotiations, I am looking forward to a long and prosperous life.', 12, 0, 100, 1, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+3, @ID+0, 'The Dragonmaw Warchief is in the largest building up on the hilltop here. I''m sure he''ll be reasonable.', 12, 0, 100, 1, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+4, @ID+0, 'This is it! Stay close and let me do the talking. I''m an expert.', 12, 0, 100, 1, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+5, @ID+0, 'Most esteemed Warchief -', 12, 0, 100, 2, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+6, @ID+0, 'Warchief, you misunderstand. Garrosh Hellscream will have a beach head on these shores, with or without your help. What we ask -', 12, 0, 100, 1, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+7, @ID+0, 'But the Horde has assembled an enormous host! A vast fleet of war machines and hardened veterans. Hellscream would as soon crush you as-', 12, 0, 100, 274, 0, 0, 0, 'Horde Negotiator to Player'),
(43238, @GROUP_ID+8, @ID+0, 'This is madness!', 12, 0, 100, 15, 0, 0, 0, 'Horde Negotiator to Player'),
(43260, @GROUP_ID+0, @ID+0, 'Quit wasting words, worm. If you want the aid of the Dragonmaw, you should''ve come on bent knee and with offerings of gold.', 12, 0, 100, 25, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43260, @GROUP_ID+1, @ID+0, 'Was that a THREAT? I knew Hellscream in Outland. A whimpering whelp. He is no Warchief.', 12, 0, 100, 11, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43260, @GROUP_ID+2, @ID+0, 'Bring him on!', 12, 0, 100, 5, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43260, @GROUP_ID+3, @ID+0, 'This is...', 12, 0, 100, 0, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43260, @GROUP_ID+4, @ID+0, 'DRAGONMAW!!', 14, 0, 100, 0, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43260, @GROUP_ID+5, @ID+0, 'Keep the $c alive. $gHe:She; will be our bargaining chip.', 12, 0, 100, 1, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43260, @GROUP_ID+6, @ID+0, 'Call for the others. We will crush Hellscream''s Horde and hurl their bodies to the sea...', 12, 0, 100, 273, 0, 0, 0, 'Warchief Mor''ghor to Player'),
(43581, @GROUP_ID+0, @ID+0, 'Abandon the port? Has Mor''ghor beaten all the sense out of you? This attack is our best opportunity to take our destiny into our own - wait! Here comes $n from the Horde!', 12, 0, 100, 1, 0, 0, 0, 'Zaela to Player'),
(43627, @GROUP_ID+0, @ID+0, 'For the Horde!', 12, 0, 100, 4, 0, 0, 0, 'Dragonmaw Warrior to Player'),
(43628, @GROUP_ID+0, @ID+0, 'Victory for the Dragonmaw!', 12, 0, 100, 0, 0, 0, 0, 'Dragonmaw Shaman to Player'),
(43869, @GROUP_ID+0, @ID+0, 'She''s going to blow! Get a parachute and jump!', 41, 0, 100, 0, 0, 0, 0, 'Zeppelin Explosion Bunny (Large)'),
(43939, @GROUP_ID+0, @ID+0, 'Mor''ghor! You should''ve stayed in Outland with the rest of your half-demon scum. There''s no place for you here.', 12, 0, 100, 5, 0, 21599, 0, 'Zaela to Warchief Mor''ghor'),
(43943, @GROUP_ID+0, @ID+0, 'Ahh, there she is. The battle-maiden of the Dragonmaw. Let me see your face.', 12, 0, 100, 1, 0, 20514, 0, 'Garrosh Hellscream to Player'),
(43943, @GROUP_ID+1, @ID+0, 'Blood and honor, hero. The Horde welcomes you. Your people will be put to the test as we obliterate Twilight''s Hammer and lay claim to this distant shore. But first... some unfinished business.', 12, 0, 100, 273, 0, 20515, 0, 'Garrosh Hellscream to Player'),
(43962, @GROUP_ID+0, @ID+0, 'Wherever the Horde takes us, we will keep our heads high and our blood pure. Good riddance, Mor''ghor. A new Dragonmaw dawns this day.', 12, 0, 100, 0, 0, 21600, 0, 'Zaela to Player'),
(43962, @GROUP_ID+1, @ID+0, 'Hellscream, I am Zaela of the Dragonmaw. Your people have freed mine from tyranny. We are your instrument. The strength of the Dragonmaw is yours to command. For the Horde!', 12, 0, 100, 0, 0, 21601, 0, 'Zaela to Player'),
(44024, @GROUP_ID+0, @ID+0, 'Step on through, $n!', 12, 0, 100, 0, 0, 0, 0, 'Artesh to Player'),
(44120, @GROUP_ID+0, @ID+0, 'Silence, idiot.', 12, 0, 100, 0, 0, 0, 0, 'Sauranok the Mystic to Player'),
(44120, @GROUP_ID+1, @ID+0, 'Hear anything interesting, $n? Your little revelation about me is about to cost you your life.', 12, 0, 100, 1, 0, 0, 0, 'Sauranok the Mystic to Player'),
(44120, @GROUP_ID+2, @ID+0, 'The Twilight''s Hammer has agents everywhere! Kill me and a dozen take my place!', 12, 0, 100, 0, 0, 0, 0, 'Sauranok the Mystic'),
(44120, @GROUP_ID+3, @ID+0, 'My powers of sight... I beheld the future... I have seen what is to come...', 12, 0, 100, 0, 0, 0, 0, 'Sauranok the Mystic'),
(44120, @GROUP_ID+4, @ID+0, 'This world unravels. If you could see the horrors I have seen... ', 12, 0, 100, 0, 0, 0, 0, 'Sauranok the Mystic'),
(44120, @GROUP_ID+5, @ID+0, 'To serve is madness, but defiance ... impossible!', 12, 0, 100, 0, 0, 0, 0, 'Sauranok the Mystic'),
(44160, @GROUP_ID+0, @ID+0, 'Wait, uh - you put words in my mouth! Not fair!', 12, 0, 100, 0, 0, 0, 0, 'Suspicious Peon to Player'),
(45982, @GROUP_ID+0, @ID+0, 'Hold the line!', 14, 0, 100, 22, 0, 0, 0, 'Gralok to Player'),
(47206, @GROUP_ID+0, @ID+0, 'Zeppelin arrival in two minutes.', 12, 0, 100, 0, 0, 22491, 0, 'Loudspeaker'),
(47206, @GROUP_ID+1, @ID+0, 'Zeppelin arrival in one minute. One minute.', 12, 0, 100, 0, 0, 22491, 0, 'Loudspeaker'),
(47208, @GROUP_ID+0, @ID+0, 'You''ll also find a complementary bag of peanuts.', 12, 0, 100, 1, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+1, @ID+0, 'Nothing keeps a fleet of combustible dirigibles safer than randomly flinging molten metal in every conceivable direction!', 12, 0, 100, 4, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+2, @ID+0, 'With Pleasure!', 12, 0, 100, 273, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+3, @ID+0, 'I can hit my house from here!', 12, 0, 100, 5, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+4, @ID+0, 'No.', 12, 0, 100, 6, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+5, @ID+0, 'Maybe.', 12, 0, 100, 0, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+6, @ID+0, 'A little.', 12, 0, 100, 0, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+7, @ID+0, 'We call them "Emergency Rampless Debarkation Devices."', 12, 0, 100, 1, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+8, @ID+0, 'Oh hells no! Those things are death-traps!', 12, 0, 100, 5, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+9, @ID+0, 'From all of us at Bilgewater Harbor...', 12, 0, 100, 1, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47208, @GROUP_ID+10, @ID+0, 'Have fun storming the Highlands!', 12, 0, 100, 3, 0, 0, 0, 'Assistant Greely to Loudspeaker'),
(47209, @GROUP_ID+0, @ID+0, 'Should your zeppelin be attacked en-route, panic is inadvisable.', 12, 0, 100, 274, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+1, @ID+0, 'Instead, look for a number of deck-mounted flak cannons positioned for just such an emergency.', 12, 0, 100, 1, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+2, @ID+0, 'Greely, show them how the guns work.', 12, 0, 100, 25, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+3, @ID+0, 'Simply aim and pull the trigger. Or don''t aim. I wash my hands of the whole thing.', 12, 0, 100, 1, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+4, @ID+0, 'Greely, you''re not randomly firing that thing into Bilgewater Port, are you?', 12, 0, 100, 6, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+5, @ID+0, 'In the unlikely event that a catastrophic failure does not instantly kill everyone aboard...', 12, 0, 100, 1, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+6, @ID+0, '...a number of parachutes will appear along the railings.', 12, 0, 100, 273, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+7, @ID+0, 'Simply grab a nearby parachute to be vaulted clear of the burning zeppelin. Hopefully onto dry land.', 12, 0, 100, 1, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+8, @ID+0, 'Greely, would you like to demonstrate how our parachutes work?', 12, 0, 100, 6, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+9, @ID+0, 'Very well then. I see that the Spear of Durotar has almost arrived.', 12, 0, 100, 1, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker'),
(47209, @GROUP_ID+10, @ID+0, 'Your safety and well-being are no longer any concern of mine.', 12, 0, 100, 274, 0, 0, 0, 'Hobart Grapplehammer to Loudspeaker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 25 AND `SourceEntry`= 736;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUES 
(25, 736, 6, 67, 0, 'Terrainwap: Dragonmaw Port visible only for Horde'),
(25, 736, 8, 26830, 1, 'Terrainwap: Dragonmaw Port inactive when rewarded quest 26830');

DELETE FROM `terrain_swap_defaults` WHERE `TerrainSwapMap`= 736;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(0, 736, 'Twilight Highlands - Dragonmaw Port');

UPDATE `creature_addon` SET `bytes2`=257, `aiAnimKit`=645 WHERE `guid` IN(370878);
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (52810);
