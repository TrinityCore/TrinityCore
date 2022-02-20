SET @GARRICK = 1568280;
SET @GARRICKGUID = -1050145;

-- Captain Garrick (Remove SmartAI and add ScriptName)
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_captain_garrick' WHERE `entry` = @GARRICK;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @GARRICKGUID AND `SourceType` = 0;

DELETE FROM `script_waypoint` WHERE `entry` = @GARRICK;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(@GARRICK, 0, -7.4451237, 0.7071281, 5.66273, 0, ''),
(@GARRICK, 1, -11.810547, 0.9604492, 5.5279408, 3500, 'Play Emote Salute'),
(@GARRICK, 2, -0.30212402, -1.4094238, 5.774313, 0, ''),
(@GARRICK, 3, 4.697876, -2.6594238, 5.524313, 0, ''),
(@GARRICK, 4, 8.697876, -4.159424, 5.524313, 0, ''),
(@GARRICK, 5, 12.447876, -5.159424, 5.524313, 0, ''),
(@GARRICK, 6, 15.947876, -5.409424, 6.274313, 0, ''),
(@GARRICK, 7, 18.947876, -5.409424, 9.274313, 0, ''),
(@GARRICK, 8, 21.197876, -4.659424, 9.774313, 0, ''),
(@GARRICK, 9, 30.197876, -3.6594238, 11.024313, 0, ''),
(@GARRICK, 10, 37.7063, -3.7792969, 12.020686, 0, ''),
(@GARRICK, 11, 37.76953, -3.3422852, 12.761156, 0, ''),
(@GARRICK, 12, 37.76953, -2.5922852, 12.761156, 0, ''),
(@GARRICK, 13, 37.832764, -1.4052734, 12.501625, 0, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 14350 AND `SourceEntry` = 10639 AND `ConditionValue1` = 56775;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionValue1`, `Comment`) VALUES 
(26, 14350, 10639, 56775, 'Allow Phase 14350 if Quest 56775 is rewarded');

DELETE FROM `phase_area` WHERE `AreaId` = 10639 AND `PhaseId` = 14350;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(10639, 14350, 'NPE Alliance Ship - Cosmetic: Captain Garrick (Quarterdeck) after Quest 56775 is rewarded');