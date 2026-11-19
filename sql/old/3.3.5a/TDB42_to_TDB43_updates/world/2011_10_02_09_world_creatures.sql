UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8040,`equipment_id`=1014 WHERE `entry` IN (35309,35310); -- Argent Lightwielder
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8040,`equipment_id`=279 WHERE `entry` IN (35307,35308); -- Argent Priestess
UPDATE `creature_template` SET `baseattacktime`=1500,`unit_flags`=`unit_flags`|0x140,`equipment_id`=1926 WHERE `entry` IN (35451,35490); -- The Black Knight

UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29763; -- Argent Lightwielder
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=29761; -- Argent Priestess
UPDATE `creature_model_info` SET `bounding_radius`=0.766,`combat_reach`=3,`gender`=0 WHERE `modelid`=29837; -- The Black Knight

DELETE FROM `creature_template_addon` WHERE `entry` IN (35309,35307,35451);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35309,0,0,1,0, NULL), -- Argent Lightwielder
(35307,0,0,1,0, NULL), -- Argent Priestess
(35451,0,0,1,0, NULL); -- The Black Knight

-- Related to last commit:
UPDATE `creature_model_info` SET `bounding_radius`=1.222,`combat_reach`=3,`gender`=0 WHERE `modelid`=23966; -- Rabid Grizzly
UPDATE `creature_model_info` SET `bounding_radius`=0.98,`combat_reach`=0.98,`gender`=0 WHERE `modelid`=23952; -- Blighted Elk
DELETE FROM `creature_template_addon` WHERE `entry` IN (26616,26643);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26616,0,0,1,0, NULL), -- Blighted Elk
(26643,0,0,1,0, NULL); -- Rabid Grizzly
