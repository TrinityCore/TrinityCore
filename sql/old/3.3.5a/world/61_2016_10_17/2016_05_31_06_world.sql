-- 
-- remove mis-spawned Mistbat (entry: 16353)
DELETE FROM `creature` WHERE `guid`=57016;

-- remove one too many spawned Elder Springpaw (entry: 15651)
DELETE FROM `creature` WHERE `guid`=55946;

-- set random movement and spawn distance to the common value for that creature
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid`=55942;
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid`=55945;
