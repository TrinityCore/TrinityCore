-- Rescue_Krennan
-- conditions [68219] 
DELETE FROM `conditions` where `SourceEntry` = '68219';
INSERT INTO `conditions` (SourceTypeOrReferenceId,SourceGroup,SourceEntry,SourceId,ElseGroup,ConditionTypeOrReference,ConditionTarget,ConditionValue1,ConditionValue2,ConditionValue3,NegativeCondition,ErrorTextId,ScriptName,Comment) VALUES 
('17', '0', '68219', '0', '0', '30', '0', '300246', '10', '0', '0', '30088', '', 'Needs to be near Krennan Aranas');

-- entry [300246]
UPDATE `gameobject_template` SET `data0` = '1630' WHERE `entry` = '300246';

DELETE FROM `gameobject` where `id` = '300246';
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES ('6017495', '300246', '654', '4755', '4757', '1', '4294967295', '-1675.29', '1349.98', '15.4272', '2.9546', '0', '0', '0.995633', '0.0933583', '300', '0', '1', '0');

DELETE FROM trinity_string where entry = '30088';
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('30088', 'You must be near Krennan Aranas!');

-- creature_text [35753] 
DELETE FROM `creature_text` where `entry` = '35753';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35753', '0', '1', 'Help!  Up here!', '14', '0', '100', '0', '0', '20921', 'Krennan Aranas In Tree');

-- creature_text [35905] 
DELETE FROM `creature_text` where `entry` = '35905';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35905', '0', '0', 'Rescue Krennan Aranas by using your vehicle\'s ability.$B|TInterfaceIconsinv_misc_groupneedmore.blp:64|t', '42', '0', '100', '0', '0', '0', 'King Greymane\'s Horse');

UPDATE `quest_template` SET `RequiredNpcOrGo1` = 357531 WHERE `Id` = 14293;

-- script_waypoint [35905] 
DELETE FROM `script_waypoint` where `entry` = '35905';
INSERT INTO `script_waypoint` (entry,pointid,location_x,location_y,location_z,waittime,point_comment) VALUES 
('35905', '1', '-1791.55', '1381.92', '19.8183', '0', ''),
('35905', '2', '-1772.75', '1361.92', '19.6939', '0', ''),
('35905', '3', '-1759.41', '1357.74', '19.9291', '0', ''),
('35905', '4', '-1713.19', '1347.35', '19.6855', '0', ''),
('35905', '5', '-1706.18', '1347.33', '19.9', '0', ''),
('35905', '6', '-1668.35', '1348.68', '15.1382', '0', ''),
('35905', '7', '-1664.11', '1356.47', '15.1351', '0', ''),
('35905', '8', '-1678.52', '1360.17', '15.1359', '0', ''),
('35905', '9', '-1702.23', '1353.7', '19.2279', '0', ''),
('35905', '10', '-1742.5', '1366.78', '19.9632', '0', ''),
('35905', '11', '-1762.66', '1390.97', '19.9748', '0', ''),
('35905', '12', '-1774.7', '1431.09', '19.7806', '0', '');