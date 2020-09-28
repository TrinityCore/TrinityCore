-- 
UPDATE `creature_text` SET `Emote`=53 WHERE `CreatureID`=28873 AND `GroupID`=0;  
UPDATE `creature_template_addon` SET `auras`="52243" WHERE `entry`=28750;
 
UPDATE `creature` SET `unit_flags`=768 WHERE `guid` IN (112203,112204,112205);
DELETE FROM `creature_addon` WHERE `guid` IN (112203,112204,112205);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`) VALUES
(112203,1,"29266"),
(112204,1,"29266"),
(112205,1,"29266");

DELETE FROM `creature_template_addon` WHERE `entry` IN (28221);
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(28221,0,"11959");
UPDATE `creature_template` SET `AIName` ='' WHERE `entry` = 28221;
DELETE FROM `smart_scripts` WHERE `source_type`IN (0) AND `entryorguid`IN (28221);

UPDATE `creature` SET  `position_x`=6290.406738, `position_y`=-2184.720947, `position_z`=240.059875 WHERE `guid`= 112188; 
UPDATE `creature` SET  `position_x`=6426.743164, `position_y`=-2258.166748, `position_z`=287.108734 WHERE `guid`= 112275; 
UPDATE `creature` SET  `position_x`=6418.568848, `position_y`=-2272.804199, `position_z`=287.967773 WHERE `guid`= 112290; 
UPDATE `creature` SET `id`=28844, `equipment_id`=1, `modelid`=0, `position_x`=6362.347168, `position_y`=-2260.4226, `position_z`=281.79498, `MovementType`=1, `wander_distance`=5 WHERE `guid`= 112183; 
UPDATE `creature` SET `id`=28844, `equipment_id`=1, `modelid`=0, `position_x`=6388.844727, `position_y`=-2219.6491, `position_z`=277.93396, `MovementType`=1, `wander_distance`=5 WHERE `guid`= 102596; 
UPDATE `creature` SET `id`=28844, `equipment_id`=1, `modelid`=0, `position_x`=6408.862793, `position_y`=-2282.7724, `position_z`=288.39938, `MovementType`=1, `wander_distance`=5 WHERE `guid`= 102594; 
UPDATE `creature` SET `id`=28844, `equipment_id`=1, `modelid`=0, `position_x`=6420.578125, `position_y`=-2289.0166, `position_z`=291.06971, `MovementType`=1, `wander_distance`=5 WHERE `guid`= 102599; 
UPDATE `creature` SET `id`=28844, `equipment_id`=1, `modelid`=0, `position_x`=6459.795411, `position_y`=-2282.3593, `position_z`=292.86065, `MovementType`=1, `wander_distance`=5 WHERE `guid`= 102597; 
