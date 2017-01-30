--
UPDATE `creature_template` SET `minlevel`=1,`maxlevel`=1,`faction`=35,`unit_flags`=33554440,`VehicleId`=550,`InhabitType`=4,`ScriptName`="npc_eagle_spirit" WHERE `entry`=36790;
 
DELETE FROM `creature_template_addon` WHERE `entry`=36790;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (36790,0,0,50331648,1,0,'69324');
--
