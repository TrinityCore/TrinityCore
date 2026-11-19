UPDATE `creature_template` SET `baseattacktime`=2000,`speed_run`=0.99206 WHERE `entry`=35321;
UPDATE `creature_template` SET `npcflag`=`npcflag`|0x1000000,`spell1`=51421 WHERE `entry`=28366;
UPDATE `creature_template` SET `npcflag`=`npcflag`|0x1000000,`exp`=2,`minlevel`=75,`maxlevel`=75,`baseattacktime`=2000,`speed_run`=3.42857,`VehicleId`=107 WHERE `entry`=35299;
UPDATE `creature_model_info` SET `bounding_radius`=0.3055,`combat_reach`=1,`gender`=2 WHERE `modelid`=27101;
UPDATE `creature_model_info` SET `bounding_radius`=0.434,`combat_reach`=1.4,`gender`=0 WHERE `modelid`=29862;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=35299;
INSERT INTO `npc_spellclick_spells` VALUES
(35299,46598,0,0,0,1,0,0,0);
