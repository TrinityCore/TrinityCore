SET @NECROguid := 300100;
SET @NEWNECROguid := 42877;

DELETE FROM `creature` WHERE `guid` IN (@NECROguid,@NECROguid+1,@NECROguid+2);
DELETE FROM `creature` WHERE `guid` IN (@NEWNECROguid,@NEWNECROguid+1,@NEWNECROguid+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `MovementType`) VALUES
(@NEWNECROguid, 25378, 571, 1, 3, 4101.931641, 3761.125000, 92.664742, 4.909590, 180, 0, 0, 0),
(@NEWNECROguid+1, 25378, 571, 1, 3, 4133.339355, 3743.313721, 92.670166, 3.474295, 180, 0, 0, 0),
(@NEWNECROguid+2, 25378, 571, 1, 3, 4121.242676, 3708.384766, 92.665283, 1.864472, 180, 0, 0, 0);
