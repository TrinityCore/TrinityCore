-- Fix bounding radius for 'Ice Tomb'
UPDATE `creature_model_info` SET `BoundingRadius`=7.5, `CombatReach`=6 WHERE `DisplayID`=30890;
