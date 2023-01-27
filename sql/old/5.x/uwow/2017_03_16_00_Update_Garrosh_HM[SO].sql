UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='72215'; 
UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='71865';
UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='72239';
UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='72228';
UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='72238';
UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='72236';
UPDATE `creature` SET `spawnMask`='16632' WHERE `id`='72237';
UPDATE `creature_template` SET `IconName`='interact',`npcflag`='16777216',`unit_flags2`='67110912',`ScriptName`='npc_portal_to_reality' WHERE `entry`='74007';
DELETE FROM `creature` WHERE `id` = '73059';
DELETE FROM `areatrigger_data` WHERE `entry` = '1275';
INSERT INTO `areatrigger_data` (`entry`, `spellId`, `customEntry`, `customVisualId`, `Radius`, `RadiusTarget`, `Height`, `HeightTarget`, `Float4`, `Float5`, `isMoving`, `moveType`, `waitTime`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `hitType`, `MoveCurveID`, `ElapsedTime`, `MorphCurveID`, `FacingCurveID`, `ScaleCurveID`, `HasFollowsTerrain`, `HasAttached`, `HasAbsoluteOrientation`, `HasDynamicShape`, `HasFaceMovementDir`, `windX`, `windY`, `windZ`, `windSpeed`, `windType`, `polygon`, `comment`) values('1275','147135','5236','33542','6','6','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','Bombartment');
UPDATE `areatrigger_data` SET `Radius`='7',`RadiusTarget`='7' WHERE `entry`='1369';
DELETE FROM `areatrigger_actions` WHERE `entry` = '1369'; 
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1369','0','1','0','8','148299','0','0','0','0','0','0','0','OO:Iron Star Impact');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1369','1','1','0','1','148299','0','144489','0','0','0','0','0','OO:Iron Star Impact for Adds');
DELETE FROM `spell_script_names` WHERE `spell_id` = '148299';
DELETE FROM `spell_script_names` WHERE `spell_id` = '147173';
DELETE FROM `spell_script_names` WHERE `spell_id` = '147236';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '148299','spell_unstable_iron_star_dummy');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ( '147236','spell_malice_energy');



 
