DELETE FROM `achievement_criteria_data` WHERE `ScriptName` IN (
'achievement_pardon_denied',
'achievement_to_the_ground');
 
DELETE FROM `world_states` WHERE `ID` IN (5670, 5672);
INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5670, 0, 33, 'Shadowfang Keep - Baron Ashbury - Pardon Denied'),
(5672, 0, 33, 'Shadowfang Keep - Commander Srpingvale - To the Ground!');
