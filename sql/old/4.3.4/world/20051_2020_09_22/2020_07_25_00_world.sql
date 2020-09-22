-- High Prophet Skeram
UPDATE `creature_template` SET `unit_flags`= 64 WHERE `entry`= 15263;

-- Ouro
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0 WHERE `guid`= 88073;
UPDATE `creature_template` SET `ScriptName`= 'npc_ouro_spawner' WHERE `entry`= 15957;

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 15517;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(15517, 0, 1, 1);
