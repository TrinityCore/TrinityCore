-- ToCr orbs

SET @NPC_ORB1  := 34606; -- Frost Sphere
SET @NPC_ORB2  := 34649; -- Frost Sphere

UPDATE `creature_template` SET `speed_walk`=1.2,`speed_run`=1.42,`InhabitType`=7 WHERE `entry` IN (@NPC_ORB1,@NPC_ORB2);

DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC_ORB1,@NPC_ORB2);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_ORB1,0,0x3000000,0x1,''),
(@NPC_ORB2,0,0x3000000,0x1,'');
