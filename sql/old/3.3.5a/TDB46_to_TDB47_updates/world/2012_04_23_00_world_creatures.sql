UPDATE `creature_template` SET `flags_extra`=0x82,`ModelId1`=1126,`ModelId2`=16925 WHERE `entry` IN (38008,38641,38773,38774); -- Blood Orb Controller
UPDATE `creature_template` SET `flags_extra`=0x80,`ModelId1`=19725,`ModelId2`=31095,`baseattacktime`=2000,`speed_walk`=0.8,`speed_run`=0.28571 WHERE `entry` IN (38454,38775,38776,38777); -- Kinetic Bomb
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`ModelId1`=19725,`ModelId2`=21342 WHERE `entry`=38458; -- Kinetic Bomb Target
UPDATE `creature_template` SET `baseattacktime`=2000,`speed_walk`=4.4,`ModelId1`=19725,`ModelId2`=26767 WHERE `entry` IN (38332,38451); -- Ball of Flame
UPDATE `creature_template` SET `flags_extra`=0x80 WHERE `entry`=37950; -- Valithria Dreamwalker
UPDATE `creature_template` SET `InhabitType`=4 WHERE `InhabitType`&4 AND `flags_extra`&0x80; -- make flying triggers fly
UPDATE `creature_template` SET `InhabitType`=4,`HoverHeight`=12 WHERE `entry`=37126; -- Sister Svalna
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=37950; -- Valithria Dreamwalker
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=0,`gender`=0 WHERE `modelid`=31095; -- Kinetic Bomb
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=0 WHERE `modelid`=21342; -- Kinetic Bomb Target
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=0 WHERE `modelid`=26767; -- Ball of Flame
UPDATE `creature_template_addon` SET `bytes1`=50331648,`bytes2`=1,`mount`=0,`emote`=0,`auras`=NULL WHERE `entry`=38454; -- Kinetic Bomb
