-- Corpulen Horror spawns in area The Fleshwerks
SET @CGUID = 127272;

DELETE FROM `creature` WHERE `id` = 30696;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@CGUID+0, 30696, 571, 1, 1, 0, 0, 6975.386, 3462.006, 710.9403, 6.126106, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+1, 30696, 571, 1, 1, 0, 0, 6982.377, 3478.588, 710.9403, 5.811946, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+2, 30696, 571, 1, 1, 0, 0, 6920.697, 3446.544, 710.2005, 3.097477, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks) 
(@CGUID+3, 30696, 571, 1, 1, 0, 0, 6932.927, 3502.471, 705.0461, 3.281219, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+4, 30696, 571, 1, 1, 0, 0, 6903.668, 3478.428, 700.0414, 3.093731, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+5, 30696, 571, 1, 1, 0, 0, 6895.87, 3460.794, 700.7824, 1.592374, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks) 
(@CGUID+6, 30696, 571, 1, 1, 0, 0, 6868.874, 3435.562, 705.6059, 1.542484, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+7, 30696, 571, 1, 1, 0, 0, 6869.054, 3493.792, 695.7783, 5.440073, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+8, 30696, 571, 1, 1, 0, 0, 6875.154, 3513.065, 698.8162, 3.944444, 120, 0, 0, 0,  0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+9, 30696, 571, 1, 1, 0, 0, 6836.296, 3505.824, 690.3577, 0.5061455, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+10, 30696, 571, 1, 1, 0, 0, 6823.636, 3484.259, 688.4615, 6.278303, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+11, 30696, 571, 1, 1, 0, 0, 6729.185, 3433.822, 682.3103, 2.64319, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+12, 30696, 571, 1, 1, 0, 0, 6676.063, 3349.062, 704.616, 2.582512, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+13, 30696, 571, 1, 1, 0, 0, 6699.958, 3422.957, 679.4948, 3.363122, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+14, 30696, 571, 1, 1, 0, 0, 6548.099, 3309.558, 665.8171, 2.951326, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+15, 30696, 571, 1, 1, 0, 0, 6535.431, 3322.088, 664.9422, 5.877358, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+16, 30696, 571, 1, 1, 0, 0, 6530.748, 3296.081, 664.9409, 3.446935, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+17, 30696, 571, 1, 1, 0, 0, 6534.971, 3260.271, 666.9742, 0.2021571, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+18, 30696, 571, 1, 1, 0, 0, 6477.204, 3257.901, 643.6331, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+19, 30696, 571, 1, 1, 0, 0, 6488.242, 3194.719, 652.9039, 1.48353, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks)
(@CGUID+20, 30696, 571, 1, 1, 0, 0, 6412.273, 3236.912, 640.3326, 0.7460284, 120, 0, 0, 0, 0, 0, 0, 0, 0), -- Corpulent Horror (Area: The Fleshwerks
(@CGUID+21, 30696, 571, 1, 1, 0, 0, 6413.427, 3218.029, 638.4678, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0); -- Corpulent Horror (Area: The Fleshwerks)
