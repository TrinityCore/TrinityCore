-- Spotlight aura for spotlight NPC
DELETE FROM `creature_template_addon` WHERE `entry`=19913;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(19913,0,0,0,0,'39312');

-- Scriptnames for areatriggers
SET @AT_AREA_52_SOUTH := 4472;
SET @AT_AREA_52_NORTH := 4466;
SET @AT_AREA_52_WEST := 4471;
SET @AT_AREA_52_EAST := 4422;
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (@AT_AREA_52_SOUTH,@AT_AREA_52_NORTH,@AT_AREA_52_WEST,@AT_AREA_52_EAST);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(@AT_AREA_52_SOUTH,"at_area_52_entrance"),(@AT_AREA_52_NORTH,"at_area_52_entrance"),(@AT_AREA_52_WEST,"at_area_52_entrance"),(@AT_AREA_52_EAST,"at_area_52_entrance");
