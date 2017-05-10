DELETE FROM `quest_poi` WHERE `questid` IN (25663, 25665, 25664, 25656, 25655, 25731, 25740, 25746, 25758, 25763, 25764, 25761, 25776, 25795, 25807, 25810, 25523, 25525, 25544, 25560);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(25663, 0, -1, 1, 606, 0, 0, 7), -- An Offering for Aviana
(25663, 1, 0, 1, 606, 0, 0, 7), -- An Offering for Aviana
(25665, 0, -1, 1, 606, 0, 0, 1), -- A Plea From Beyond
(25664, 0, -1, 1, 606, 0, 0, 1), -- A Prayer and a Wing
(25664, 1, 4, 1, 606, 0, 0, 7), -- A Prayer and a Wing
(25664, 2, 4, 1, 606, 0, 0, 7), -- A Prayer and a Wing
(25656, 0, 4, 1, 606, 0, 0, 3), -- Scrambling for Eggs
(25656, 2, -1, 1, 606, 0, 0, 1), -- Scrambling for Eggs
(25656, 3, 4, 1, 606, 0, 0, 7), -- Scrambling for Eggs
(25656, 4, 4, 1, 606, 0, 0, 7), -- Scrambling for Eggs
(25655, 0, 0, 1, 606, 0, 0, 3), -- The Wormwing Problem
(25655, 1, 0, 1, 606, 0, 0, 1), -- The Wormwing Problem
(25655, 2, 0, 1, 606, 0, 0, 3), -- The Wormwing Problem
(25655, 4, -1, 1, 606, 0, 0, 1), -- The Wormwing Problem
(25731, 1, -1, 1, 606, 0, 0, 1), -- A Bird in Hand
(25731, 2, 1, 1, 606, 0, 0, 7), -- A Bird in Hand
(25731, 3, 1, 1, 606, 0, 0, 7), -- A Bird in Hand
(25731, 4, 1, 1, 606, 0, 0, 7), -- A Bird in Hand
(25731, 5, 1, 1, 606, 0, 0, 7), -- A Bird in Hand
(25740, 0, -1, 1, 606, 0, 0, 1), -- Fact-Finding Mission
(25746, 0, 0, 1, 606, 0, 0, 3), -- Sethria's Brood
(25746, 1, 0, 1, 606, 0, 0, 3), -- Sethria's Brood
(25746, 2, -1, 1, 606, 0, 0, 1), -- Sethria's Brood
(25758, 0, 4, 1, 606, 0, 0, 3), -- A Gap in Their Armor
(25758, 1, 4, 1, 606, 0, 0, 3), -- A Gap in Their Armor
(25758, 2, -1, 1, 606, 0, 0, 1), -- A Gap in Their Armor
(25763, 0, -1, 1, 606, 0, 0, 1), -- The Codex of Shadows
(25764, 0, -1, 1, 606, 0, 0, 1), -- Egg Hunt
(25764, 1, 0, 1, 606, 0, 0, 7), -- Egg Hunt
(25761, 0, 0, 1, 606, 0, 0, 3), -- Disassembly
(25761, 1, 0, 1, 606, 0, 0, 3), -- Disassembly
(25761, 2, -1, 1, 606, 0, 0, 1), -- Disassembly
(25776, 0, 0, 1, 606, 0, 0, 1), -- Sethria's Demise
(25776, 1, -1, 1, 606, 0, 0, 1), -- Sethria's Demise
(25795, 0, -1, 1, 606, 0, 0, 1), -- Return to the Shrine
(25807, 0, -1, 1, 606, 0, 0, 1), -- An Ancient Reborn
(25807, 1, 0, 1, 606, 0, 0, 7), -- An Ancient Reborn
(25810, 0, -1, 1, 606, 0, 0, 3), -- The Hatchery Must Burn
(25523, 0, -1, 1, 606, 0, 0, 1), -- Flight in the Firelands
(25525, 0, -1, 1, 606, 0, 0, 1), -- Wave One
(25525, 1, 0, 1, 606, 0, 0, 7), -- Wave One
(25544, 0, -1, 1, 606, 0, 0, 1), -- Wave Two
(25544, 1, 0, 1, 606, 0, 0, 7), -- Wave Two
(25560, 0, 0, 1, 606, 0, 0, 3), -- Egg Wave
(25560, 1, -1, 1, 606, 0, 0, 1); -- Egg Wave


DELETE FROM `quest_poi_points` WHERE (`questId`=25663 AND `id`=0) OR (`questId`=25663 AND `id`=1) OR (`questId`=25665 AND `id`=0) OR (`questId`=25664 AND `id`=0) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=1) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25664 AND `id`=2) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=0) OR (`questId`=25656 AND `id`=2) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=3) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25656 AND `id`=4) OR (`questId`=25655 AND `id`=0) OR (`questId`=25655 AND `id`=0) OR (`questId`=25655 AND `id`=0) OR (`questId`=25655 AND `id`=0) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=1) OR (`questId`=25655 AND `id`=2) OR (`questId`=25655 AND `id`=2) OR (`questId`=25655 AND `id`=2) OR (`questId`=25655 AND `id`=2) OR (`questId`=25655 AND `id`=2) OR (`questId`=25655 AND `id`=4) OR (`questId`=25731 AND `id`=1) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=2) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=3) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=4) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25731 AND `id`=5) OR (`questId`=25740 AND `id`=0) OR (`questId`=25746 AND `id`=0) OR (`questId`=25746 AND `id`=0) OR (`questId`=25746 AND `id`=0) OR (`questId`=25746 AND `id`=0) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=1) OR (`questId`=25746 AND `id`=2) OR (`questId`=25758 AND `id`=0) OR (`questId`=25758 AND `id`=0) OR (`questId`=25758 AND `id`=0) OR (`questId`=25758 AND `id`=0) OR (`questId`=25758 AND `id`=0) OR (`questId`=25758 AND `id`=0) OR (`questId`=25758 AND `id`=1) OR (`questId`=25758 AND `id`=1) OR (`questId`=25758 AND `id`=1) OR (`questId`=25758 AND `id`=1) OR (`questId`=25758 AND `id`=1) OR (`questId`=25758 AND `id`=2) OR (`questId`=25763 AND `id`=0) OR (`questId`=25764 AND `id`=0) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25764 AND `id`=1) OR (`questId`=25761 AND `id`=0) OR (`questId`=25761 AND `id`=0) OR (`questId`=25761 AND `id`=0) OR (`questId`=25761 AND `id`=1) OR (`questId`=25761 AND `id`=1) OR (`questId`=25761 AND `id`=1) OR (`questId`=25761 AND `id`=1) OR (`questId`=25761 AND `id`=1) OR (`questId`=25761 AND `id`=2) OR (`questId`=25776 AND `id`=0) OR (`questId`=25776 AND `id`=1) OR (`questId`=25795 AND `id`=0) OR (`questId`=25807 AND `id`=0) OR (`questId`=25807 AND `id`=1) OR (`questId`=25810 AND `id`=0) OR (`questId`=25523 AND `id`=0) OR (`questId`=25525 AND `id`=0) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25525 AND `id`=1) OR (`questId`=25544 AND `id`=0) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25544 AND `id`=1) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=0) OR (`questId`=25560 AND `id`=1);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(25663, 0, 0, 4942, -2672), -- An Offering for Aviana
(25663, 1, 0, 4946, -2672), -- An Offering for Aviana
(25665, 0, 0, 4887, -2816), -- A Plea From Beyond
(25664, 0, 0, 4887, -2816), -- A Prayer and a Wing
(25664, 1, 0, 4969, -3067), -- A Prayer and a Wing
(25664, 1, 1, 5000, -2997), -- A Prayer and a Wing
(25664, 1, 2, 5194, -2469), -- A Prayer and a Wing
(25664, 1, 3, 5202, -2427), -- A Prayer and a Wing
(25664, 1, 4, 5139, -2423), -- A Prayer and a Wing
(25664, 1, 5, 5089, -2469), -- A Prayer and a Wing
(25664, 1, 6, 5058, -2508), -- A Prayer and a Wing
(25664, 1, 7, 5027, -2570), -- A Prayer and a Wing
(25664, 1, 8, 5000, -2632), -- A Prayer and a Wing
(25664, 1, 9, 4965, -2788), -- A Prayer and a Wing
(25664, 1, 10, 4949, -2865), -- A Prayer and a Wing
(25664, 1, 11, 4922, -3001), -- A Prayer and a Wing
(25664, 2, 0, 4938, -2469), -- A Prayer and a Wing
(25664, 2, 1, 4957, -2469), -- A Prayer and a Wing
(25664, 2, 2, 4973, -2454), -- A Prayer and a Wing
(25664, 2, 3, 4976, -2423), -- A Prayer and a Wing
(25664, 2, 4, 4976, -2403), -- A Prayer and a Wing
(25664, 2, 5, 4965, -2376), -- A Prayer and a Wing
(25664, 2, 6, 4949, -2365), -- A Prayer and a Wing
(25664, 2, 7, 4918, -2369), -- A Prayer and a Wing
(25664, 2, 8, 4895, -2388), -- A Prayer and a Wing
(25664, 2, 9, 4887, -2403), -- A Prayer and a Wing
(25664, 2, 10, 4891, -2431), -- A Prayer and a Wing
(25664, 2, 11, 4914, -2458), -- A Prayer and a Wing
(25656, 0, 0, 4922, -2574), -- Scrambling for Eggs
(25656, 0, 1, 4967, -2543), -- Scrambling for Eggs
(25656, 0, 2, 4980, -2512), -- Scrambling for Eggs
(25656, 0, 3, 4968, -2472), -- Scrambling for Eggs
(25656, 0, 4, 4908, -2286), -- Scrambling for Eggs
(25656, 0, 5, 4817, -2218), -- Scrambling for Eggs
(25656, 0, 6, 4774, -2344), -- Scrambling for Eggs
(25656, 0, 7, 4820, -2471), -- Scrambling for Eggs
(25656, 0, 8, 4853, -2526), -- Scrambling for Eggs
(25656, 2, 0, 4909, -2720), -- Scrambling for Eggs
(25656, 3, 0, 4720, -2873), -- Scrambling for Eggs
(25656, 3, 1, 4740, -2861), -- Scrambling for Eggs
(25656, 3, 2, 4740, -2815), -- Scrambling for Eggs
(25656, 3, 3, 4740, -2768), -- Scrambling for Eggs
(25656, 3, 4, 4736, -2729), -- Scrambling for Eggs
(25656, 3, 5, 4716, -2710), -- Scrambling for Eggs
(25656, 3, 6, 4685, -2718), -- Scrambling for Eggs
(25656, 3, 7, 4681, -2733), -- Scrambling for Eggs
(25656, 3, 8, 4674, -2776), -- Scrambling for Eggs
(25656, 3, 9, 4674, -2811), -- Scrambling for Eggs
(25656, 3, 10, 4677, -2838), -- Scrambling for Eggs
(25656, 3, 11, 4697, -2858), -- Scrambling for Eggs
(25656, 4, 0, 4829, -3129), -- Scrambling for Eggs
(25656, 4, 1, 4852, -3106), -- Scrambling for Eggs
(25656, 4, 2, 4860, -3055), -- Scrambling for Eggs
(25656, 4, 3, 4856, -3009), -- Scrambling for Eggs
(25656, 4, 4, 4852, -2989), -- Scrambling for Eggs
(25656, 4, 5, 4837, -2958), -- Scrambling for Eggs
(25656, 4, 6, 4806, -2955), -- Scrambling for Eggs
(25656, 4, 7, 4771, -2962), -- Scrambling for Eggs
(25656, 4, 8, 4763, -3001), -- Scrambling for Eggs
(25656, 4, 9, 4763, -3040), -- Scrambling for Eggs
(25656, 4, 10, 4775, -3087), -- Scrambling for Eggs
(25656, 4, 11, 4794, -3114), -- Scrambling for Eggs
(25655, 0, 0, 4733, -2874), -- The Wormwing Problem
(25655, 0, 1, 4711, -2777), -- The Wormwing Problem
(25655, 0, 2, 4629, -2791), -- The Wormwing Problem
(25655, 0, 3, 4685, -2919), -- The Wormwing Problem
(25655, 1, 0, 5039, -2636), -- The Wormwing Problem
(25655, 1, 1, 5043, -2610), -- The Wormwing Problem
(25655, 1, 2, 5050, -2548), -- The Wormwing Problem
(25655, 1, 3, 5021, -2476), -- The Wormwing Problem
(25655, 1, 4, 4860, -2209), -- The Wormwing Problem
(25655, 1, 5, 4842, -2365), -- The Wormwing Problem
(25655, 1, 6, 4864, -2486), -- The Wormwing Problem
(25655, 1, 7, 4921, -2616), -- The Wormwing Problem
(25655, 2, 0, 4848, -3145), -- The Wormwing Problem
(25655, 2, 1, 4886, -3078), -- The Wormwing Problem
(25655, 2, 2, 4853, -3004), -- The Wormwing Problem
(25655, 2, 3, 4808, -2995), -- The Wormwing Problem
(25655, 2, 4, 4790, -3082), -- The Wormwing Problem
(25655, 4, 0, 4909, -2720), -- The Wormwing Problem
(25731, 1, 0, 4909, -2720), -- A Bird in Hand
(25731, 2, 0, 4973, -2621), -- A Bird in Hand
(25731, 2, 1, 4992, -2566), -- A Bird in Hand
(25731, 2, 2, 4996, -2551), -- A Bird in Hand
(25731, 2, 3, 5004, -2500), -- A Bird in Hand
(25731, 2, 4, 5004, -2473), -- A Bird in Hand
(25731, 2, 5, 4984, -2438), -- A Bird in Hand
(25731, 2, 6, 4953, -2415), -- A Bird in Hand
(25731, 2, 7, 4926, -2473), -- A Bird in Hand
(25731, 2, 8, 4926, -2535), -- A Bird in Hand
(25731, 2, 9, 4926, -2566), -- A Bird in Hand
(25731, 2, 10, 4930, -2601), -- A Bird in Hand
(25731, 2, 11, 4941, -2632), -- A Bird in Hand
(25731, 3, 0, 4790, -2850), -- A Bird in Hand
(25731, 3, 1, 4790, -2842), -- A Bird in Hand
(25731, 3, 2, 4790, -2830), -- A Bird in Hand
(25731, 3, 3, 4790, -2807), -- A Bird in Hand
(25731, 3, 4, 4786, -2768), -- A Bird in Hand
(25731, 3, 5, 4782, -2768), -- A Bird in Hand
(25731, 3, 6, 4775, -2772), -- A Bird in Hand
(25731, 3, 7, 4767, -2780), -- A Bird in Hand
(25731, 3, 8, 4763, -2784), -- A Bird in Hand
(25731, 3, 9, 4755, -2792), -- A Bird in Hand
(25731, 3, 10, 4740, -2811), -- A Bird in Hand
(25731, 3, 11, 4743, -2815), -- A Bird in Hand
(25731, 4, 0, 4864, -3067), -- A Bird in Hand
(25731, 4, 1, 4868, -3067), -- A Bird in Hand
(25731, 4, 2, 4891, -3052), -- A Bird in Hand
(25731, 4, 3, 4907, -3040), -- A Bird in Hand
(25731, 4, 4, 4910, -3036), -- A Bird in Hand
(25731, 4, 5, 4918, -3024), -- A Bird in Hand
(25731, 4, 6, 4910, -3013), -- A Bird in Hand
(25731, 4, 7, 4887, -2989), -- A Bird in Hand
(25731, 4, 8, 4883, -2986), -- A Bird in Hand
(25731, 4, 9, 4833, -2962), -- A Bird in Hand
(25731, 4, 10, 4829, -2966), -- A Bird in Hand
(25731, 4, 11, 4829, -2970), -- A Bird in Hand
(25731, 5, 0, 4895, -2500), -- A Bird in Hand
(25731, 5, 1, 4918, -2489), -- A Bird in Hand
(25731, 5, 2, 4922, -2473), -- A Bird in Hand
(25731, 5, 3, 4922, -2446), -- A Bird in Hand
(25731, 5, 4, 4922, -2415), -- A Bird in Hand
(25731, 5, 5, 4922, -2400), -- A Bird in Hand
(25731, 5, 6, 4922, -2376), -- A Bird in Hand
(25731, 5, 7, 4903, -2357), -- A Bird in Hand
(25731, 5, 8, 4879, -2357), -- A Bird in Hand
(25731, 5, 9, 4864, -2462), -- A Bird in Hand
(25731, 5, 10, 4864, -2485), -- A Bird in Hand
(25731, 5, 11, 4875, -2493), -- A Bird in Hand
(25740, 0, 0, 4193, -2321), -- Fact-Finding Mission
(25746, 0, 0, 3436, -2393), -- Sethria's Brood
(25746, 0, 1, 3670, -2295), -- Sethria's Brood
(25746, 0, 2, 3668, -2186), -- Sethria's Brood
(25746, 0, 3, 3421, -2237), -- Sethria's Brood
(25746, 1, 0, 4114, -2355), -- Sethria's Brood
(25746, 1, 1, 4136, -2316), -- Sethria's Brood
(25746, 1, 2, 4124, -2277), -- Sethria's Brood
(25746, 1, 3, 4079, -2228), -- Sethria's Brood
(25746, 1, 4, 3963, -2200), -- Sethria's Brood
(25746, 1, 5, 3913, -2199), -- Sethria's Brood
(25746, 1, 6, 3724, -2184), -- Sethria's Brood
(25746, 1, 7, 3736, -2290), -- Sethria's Brood
(25746, 2, 0, 4193, -2321), -- Sethria's Brood
(25758, 0, 0, 4042, -2271), -- A Gap in Their Armor
(25758, 0, 1, 4039, -2216), -- A Gap in Their Armor
(25758, 0, 2, 3895, -2152), -- A Gap in Their Armor
(25758, 0, 3, 3817, -2199), -- A Gap in Their Armor
(25758, 0, 4, 3930, -2266), -- A Gap in Their Armor
(25758, 0, 5, 4031, -2269), -- A Gap in Their Armor
(25758, 1, 0, 3600, -2362), -- A Gap in Their Armor
(25758, 1, 1, 3664, -2270), -- A Gap in Their Armor
(25758, 1, 2, 3759, -2207), -- A Gap in Their Armor
(25758, 1, 3, 3629, -2200), -- A Gap in Their Armor
(25758, 1, 4, 3519, -2282), -- A Gap in Their Armor
(25758, 2, 0, 4193, -2321), -- A Gap in Their Armor
(25763, 0, 0, 4193, -2321), -- The Codex of Shadows
(25764, 0, 0, 4193, -2321), -- Egg Hunt
(25764, 1, 0, 3439, -2431), -- Egg Hunt
(25764, 1, 1, 3940, -2271), -- Egg Hunt
(25764, 1, 2, 3963, -2202), -- Egg Hunt
(25764, 1, 3, 3913, -2167), -- Egg Hunt
(25764, 1, 4, 3843, -2143), -- Egg Hunt
(25764, 1, 5, 3746, -2143), -- Egg Hunt
(25764, 1, 6, 3622, -2147), -- Egg Hunt
(25764, 1, 7, 3556, -2159), -- Egg Hunt
(25764, 1, 8, 3486, -2186), -- Egg Hunt
(25764, 1, 9, 3424, -2221), -- Egg Hunt
(25764, 1, 10, 3385, -2260), -- Egg Hunt
(25764, 1, 11, 3389, -2369), -- Egg Hunt
(25761, 0, 0, 3541, -2361), -- Disassembly
(25761, 0, 1, 3730, -2264), -- Disassembly
(25761, 0, 2, 3607, -2193), -- Disassembly
(25761, 1, 0, 4014, -2275), -- Disassembly
(25761, 1, 1, 3992, -2184), -- Disassembly
(25761, 1, 2, 3868, -2154), -- Disassembly
(25761, 1, 3, 3778, -2225), -- Disassembly
(25761, 1, 4, 3949, -2285), -- Disassembly
(25761, 2, 0, 4193, -2321), -- Disassembly
(25776, 0, 0, 3422, -2438), -- Sethria's Demise
(25776, 1, 0, 4193, -2321), -- Sethria's Demise
(25795, 0, 0, 4887, -2816), -- Return to the Shrine
(25807, 0, 0, 4837, -2812), -- An Ancient Reborn
(25807, 1, 0, 4810, -2804), -- An Ancient Reborn
(25810, 0, 0, 4540, -2596), -- The Hatchery Must Burn
(25523, 0, 0, 4594, -2526), -- Flight in the Firelands
(25525, 0, 0, 4594, -2526), -- Wave One
(25525, 1, 0, 4549, -2590), -- Wave One
(25525, 1, 1, 4584, -2590), -- Wave One
(25525, 1, 2, 4615, -2574), -- Wave One
(25525, 1, 3, 4639, -2528), -- Wave One
(25525, 1, 4, 4623, -2493), -- Wave One
(25525, 1, 5, 4608, -2477), -- Wave One
(25525, 1, 6, 4577, -2454), -- Wave One
(25525, 1, 7, 4553, -2454), -- Wave One
(25525, 1, 8, 4522, -2473), -- Wave One
(25525, 1, 9, 4503, -2504), -- Wave One
(25525, 1, 10, 4503, -2528), -- Wave One
(25525, 1, 11, 4507, -2563), -- Wave One
(25544, 0, 0, 4594, -2526), -- Wave Two
(25544, 1, 0, 4561, -2586), -- Wave Two
(25544, 1, 1, 4596, -2582), -- Wave Two
(25544, 1, 2, 4615, -2570), -- Wave Two
(25544, 1, 3, 4631, -2539), -- Wave Two
(25544, 1, 4, 4631, -2508), -- Wave Two
(25544, 1, 5, 4623, -2477), -- Wave Two
(25544, 1, 6, 4596, -2450), -- Wave Two
(25544, 1, 7, 4545, -2446), -- Wave Two
(25544, 1, 8, 4518, -2462), -- Wave Two
(25544, 1, 9, 4503, -2485), -- Wave Two
(25544, 1, 10, 4507, -2528), -- Wave Two
(25544, 1, 11, 4518, -2559), -- Wave Two
(25560, 0, 0, 4776, -2509), -- Egg Wave
(25560, 0, 1, 4821, -2474), -- Egg Wave
(25560, 0, 2, 4830, -2425), -- Egg Wave
(25560, 0, 3, 4827, -2328), -- Egg Wave
(25560, 0, 4, 4820, -2321), -- Egg Wave
(25560, 0, 5, 4741, -2268), -- Egg Wave
(25560, 0, 6, 4549, -2270), -- Egg Wave
(25560, 0, 7, 4530, -2274), -- Egg Wave
(25560, 0, 8, 4517, -2286), -- Egg Wave
(25560, 0, 9, 4514, -2310), -- Egg Wave
(25560, 0, 10, 4581, -2455), -- Egg Wave
(25560, 0, 11, 4667, -2510), -- Egg Wave
(25560, 1, 0, 4594, -2526); -- Egg Wave
