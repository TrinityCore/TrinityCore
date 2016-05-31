-- Fix Frozen Earth SAI
UPDATE `smart_scripts` SET `target_type`=1,`target_param1`=0,`target_param2`=0 WHERE `comment` LIKE 'Frozen Earth%' AND `action_param1`=51590;
