UPDATE `creature_template` SET `faction_A`='16',`faction_H`='16',`ScriptName`='npc_puddle_point' WHERE `entry`='90000'; 
DELETE FROM `areatrigger_actions` WHERE `entry` = '1016';
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `comment`) values('1016','0','1','0','8','143286','0','-143286','0','0','0','0','OO: Seeping sha');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `comment`) values('1016','1','2','1','8','143286','0','0','0','0','0','0','OO: Seeping sha remove');

