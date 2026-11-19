-- Update for Forgotten npcs to award credit.
UPDATE `smart_scripts` SET `action_type`=85 WHERE  `entryorguid`=27224 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85 WHERE  `entryorguid`=27225 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85 WHERE  `entryorguid`=27229 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `action_type`=85 WHERE  `entryorguid`=27226 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Forced model for Channel Bunny... should've used that earlier.
UPDATE `creature` SET `modelid`=16925, `position_x`=1924.63, `position_y`=5574.76, `position_z`=273.122 WHERE `guid`=74872;
