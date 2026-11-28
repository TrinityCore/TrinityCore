SET @CGUID := 11000000;

-- Transport: The Defiant Dragonscale (Orgrimmar <-> Waking Shores)
DELETE FROM `transports` WHERE `guid`=37;
INSERT INTO `transports` (`guid`, `entry`, `name`, `phaseUseFlags`, `phaseid`, `phasegroup`, `ScriptName`) VALUES 
(37, 375041, 'Orgrimmar and Waking Shores ("The Defiant Dragonscale")', 0, 0, 0, '');

DELETE FROM `gameobject_template_addon` WHERE `entry`=375041;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `artkit0`, `artkit1`, `artkit2`, `artkit3`, `artkit4`, `WorldEffectID`, `AIAnimKitID`) VALUES 
(375041, 0, 1048616, 0, 0, 0, 0, 0, 0, 0, 0, 0);

