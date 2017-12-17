-- 
-- Phase: 128
-- Duplicates Removed
DELETE FROM `creature` WHERE `guid` IN (130365,130370,130364,130374,130372,130377,130367,130375,130366,130361,130371);
DELETE FROM `creature_addon` WHERE `guid` IN (130365,130370,130364,130374,130372,130377,130367,130375,130366,130361,130371);

UPDATE `creature` SET `phaseMask` = 128, `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 130400;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 130401;
UPDATE `creature` SET `spawndist` = 20, `MovementType` = 1 WHERE `id` = 29189;
UPDATE `creature` SET `phaseMask` = 128 WHERE `guid` IN (130387,130419);
UPDATE `creature` SET `spawndist` = 10, `MovementType` = 1 WHERE `guid` IN (130368,130369);

-- Howling Geist 
UPDATE `creature` SET `position_x` = 2597.903076, `position_y` = -5549.420410, `position_z` = 159.772934, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130387;
UPDATE `creature` SET `position_x` = 2622.867432, `position_y` = -5481.481934, `position_z` = 156.948212, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130386;
UPDATE `creature` SET `position_x` = 2659.806885, `position_y` = -5537.375000, `position_z` = 163.303589, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130385;
UPDATE `creature` SET `position_x` = 2697.650391, `position_y` = -5469.664063, `position_z` = 156.943970, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130383;
UPDATE `creature` SET `position_x` = 2735.920410, `position_y` = -5363.948730, `position_z` = 157.715302, `spawndist` = 20, `MovementType` = 1 WHERE `guid` = 130381;
