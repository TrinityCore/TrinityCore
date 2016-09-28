--
UPDATE `creature` SET `spawntimesecs`=0 WHERE `id`=23784;

DELETE FROM `creature_text` WHERE `entry`=23784;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23784, 0, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22485), 12, 1, 100, 0, 0, 0, 22485, 0, "Apothecary Hanes"),
(23784, 1, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22486), 12, 1, 100, 0, 0, 0, 22486, 0, "Apothecary Hanes"),
(23784, 2, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22487), 12, 1, 100, 0, 0, 0, 22487, 0, "Apothecary Hanes"),
(23784, 3, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22489), 12, 1, 100, 0, 0, 0, 22489, 0, "Apothecary Hanes"),
(23784, 4, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22490), 12, 1, 100, 0, 0, 0, 22490, 0, "Apothecary Hanes"),
(23784, 5, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22491), 14, 1, 100, 0, 0, 0, 22491, 0, "Apothecary Hanes"),
(23784, 6, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22492), 12, 1, 100, 0, 0, 0, 22492, 0, "Apothecary Hanes"),
(23784, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22493), 14, 1, 100, 0, 0, 0, 22493, 0, "Apothecary Hanes"),
(23784, 8, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=22494), 12, 1, 100, 0, 0, 0, 22494, 0, "Apothecary Hanes");

DELETE FROM `script_waypoint` WHERE `entry`=23784;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(23784, 1, 1379.813, -6409.201, 1.664683, 0, "Apothecary Hanes"),
(23784, 2, 1380.114, -6401.745, 2.539683, 8000, "Apothecary Hanes"),
(23784, 3, 1382.692, -6398.32, 3.308795, 0, "Apothecary Hanes"),
(23784, 4, 1386.27, -6393.396, 3.577907, 0, "Apothecary Hanes"),
(23784, 5, 1394.768, -6387.708, 3.702907, 0, "Apothecary Hanes"),
(23784, 6, 1405.694, -6380.924, 4.62476, 0, "Apothecary Hanes"),
(23784, 7, 1416.18, -6370.656, 6.12476, 0, "Apothecary Hanes"),
(23784, 8, 1425.048, -6361.604, 6.229269, 0, "Apothecary Hanes"),
(23784, 9, 1427.955, -6350.528, 6.354269, 0, "Apothecary Hanes"),
(23784, 10, 1424.617, -6340.581, 5.729269, 0, "Apothecary Hanes"),
(23784, 11, 1416.344, -6335.909, 5.729269, 0, "Apothecary Hanes"),
(23784, 12, 1404.921, -6335.286, 6.229269, 0, "Apothecary Hanes"),
(23784, 13, 1400.859, -6340.079, 6.479269, 8000, "Apothecary Hanes"),
(23784, 14, 1407.071, -6332.194, 6.256171, 0, "Apothecary Hanes"),
(23784, 15, 1418.821, -6332.194, 6.006171, 0, "Apothecary Hanes"),
(23784, 16, 1419.282, -6332.309, 5.533074, 0, "Apothecary Hanes"),
(23784, 17, 1428.454, -6335.082, 5.604269, 0, "Apothecary Hanes"),
(23784, 18, 1446.955, -6338.777, 8.005317, 0, "Apothecary Hanes"),
(23784, 19, 1457.27, -6343.141, 8.380317, 0, "Apothecary Hanes"),
(23784, 20, 1465.724, -6345.168, 7.755317, 2000, "Apothecary Hanes"),
(23784, 21, 1471.415, -6348.291, 7.692434, 7000, "Apothecary Hanes"),
(23784, 22, 1462.058, -6341.999, 8.005317, 0, "Apothecary Hanes"),
(23784, 23, 1465.077, -6331.357, 7.559553, 0, "Apothecary Hanes"),
(23784, 24, 1475.621, -6327.219, 7.073432, 0, "Apothecary Hanes"),
(23784, 25, 1490.551, -6315.318, 8.323432, 0, "Apothecary Hanes"),
(23784, 26, 1497.682, -6311.022, 7.448432, 0, "Apothecary Hanes"),
(23784, 27, 1505.303, -6313.513, 6.831386, 0, "Apothecary Hanes"),
(23784, 28, 1506.431, -6317.528, 7.331386, 24000, "Apothecary Hanes"),
(23784, 29, 1504.416, -6305.003, 6.581386, 0, "Apothecary Hanes"),
(23784, 30, 1513.499, -6287.491, 5.818699, 0, "Apothecary Hanes"),
(23784, 31, 1513.937, -6277.724, 5.568699, 0, "Apothecary Hanes"),
(23784, 32, 1523.013, -6259.255, 4.647499, 0, "Apothecary Hanes"),
(23784, 33, 1538.941, -6220.414, 6.448732, 0, "Apothecary Hanes"),
(23784, 34, 1554.772, -6204.828, 6.698732, 0, "Apothecary Hanes"),
(23784, 35, 1566.746, -6192.293, 7.72767, 0, "Apothecary Hanes"),
(23784, 36, 1583.782, -6168.592, 8.35267, 0, "Apothecary Hanes"),
(23784, 37, 1588.554, -6163.325, 7.94416, 0, "Apothecary Hanes"),
(23784, 38, 1600.514, -6157.163, 8.714622, 0, "Apothecary Hanes"),
(23784, 39, 1606.814 ,-6158.777, 8.839622, 0, "Apothecary Hanes"),
(23784, 40, 1615.063 ,-6157.817, 9.339622, 10000, "Apothecary Hanes");

DELETE FROM `creature_equip_template` WHERE `creatureid`=23784;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(23784, 2, 1906, 0, 0, 0);

UPDATE `spelleffect_dbc` SET `Effect`=76, `EffectMiscValue`=182071 WHERE `EffectSpellId`=42686;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42685;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 42685, 0, 0, 31, 0, 3, 23968, 0, 0, 0, 0, "", "Spell 'Burn' targets NPC 'Hanes Fire Trigger' OR"),
(13, 1, 42685, 0, 1, 31, 0, 3, 23784, 0, 0, 0, 0, "", "Spell 'Burn' targets NPC 'Apothecary Hanes'");
