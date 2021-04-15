-- Set Entry 18955 "Camera Shaker - 30-90 seconds" as trigger and remove random movement
UPDATE `creature_template` SET `modelid1`=16925, `modelid2`=16480, `flags_extra`=`flags_extra`|128 WHERE `entry`=18955;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=18955;
