-- Corpulen Horror spawns in area The Fleshwerks
SET @CGUID = 634;

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=30696; 4.x removed
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=30696;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=30696;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30696,0,0,0,9,0,100,0,8,40,3500,4100,11,50335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Corpulent Horror - Cast Scourge Hook - In Range');

DELETE FROM `creature_template_addon` WHERE `entry`=30696;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(30696, 0, 0x0, 0x1, ''); -- Corpulent Horror

UPDATE `creature_template` SET `faction_A`=2102, `faction_H`=2102, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=30696; -- Corpulent Horror
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
