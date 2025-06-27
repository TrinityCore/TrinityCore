-- NPC Engineer Helice
UPDATE creature_text SET emote = 5 WHERE CreatureID = 28787 AND GroupID = 0;
UPDATE creature_text SET emote = 25 WHERE CreatureID = 28787 AND GroupID = 1;
UPDATE creature_text SET emote = 11 WHERE CreatureID = 28787 AND GroupID = 3;
UPDATE creature_text SET emote = 25 WHERE CreatureID = 28787 AND GroupID = 4;
UPDATE creature_text SET emote = 5 WHERE CreatureID = 28787 AND GroupID = 5;
UPDATE creature_text SET emote = 4 WHERE CreatureID = 28787 AND GroupID = 6;

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceEntry IN (52369, 52371);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
(13, 1, 52369, 0, 0, 31, 0, 3, 28789, 0, 0, 0, 0, '', 'Spell ''Detonate Explosives'' targets trigger'),
(13, 1, 52371, 0, 0, 31, 0, 3, 28789, 0, 0, 0, 0, '', 'Spell ''Detonate Explosives'' targets trigger');

DELETE FROM spell_script_names WHERE spell_id IN (52369, 52371);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(52369, 'spell_q12688_detonate_1'),
(52371, 'spell_q12688_detonate_2');

-- Flames
DELETE FROM gameobject WHERE guid IN (9577, 9578, 9579, 9598, 9599, 9600);
INSERT INTO gameobject (guid, id, map, zoneId, areaId, spawnMask, phaseMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, ScriptName, VerifiedBuild) VALUES
(9577, 182071, 571, 0, 0, 1, 1, 5921.53, 5371.77, -96.3387, 0, 0, 0, 0.688354, 0.725374, 0, 0, 1, '', 0),
(9578, 182071, 571, 0, 0, 1, 1, 5919.42, 5366.92, -96.0911, 0, 0, 0, 0.608761, 0.793354, 0, 0, 1, '', 0),
(9579, 182071, 571, 0, 0, 1, 1, 5920.25, 5372.41, -98.8582, 0, 0, 0, -0.325567, 0.945519, 0, 0, 1, '', 0),
(9598, 182071, 571, 0, 0, 1, 1, 5888.68, 5377.42, -92.6171, 0, 0, 0, 0.9612608, 0.2756405, 0, 0, 1, '', 0),
(9599, 182071, 571, 0, 0, 1, 1, 5886.48, 5379.05, -92.9799, 0, 0, 0, 0.41469288, 0.90996146, 0, 0, 1, '', 0),
(9600, 182071, 571, 0, 0, 1, 1, 5887.20, 5381.18, -93.5000, 0, 0, 0, 0.061048508, 0.9981348, 0, 0, 1, '', 0);

DELETE FROM spawn_group_template WHERE groupId IN (67, 68);
INSERT INTO spawn_group_template (groupId, groupName, groupFlags) VALUES
(67, 'Quest "Engineering a Disaster" (12688) - Spell Detonate (52369)', 4),
(68, 'Quest "Engineering a Disaster" (12688) - Spell Detonate (52371)', 4);

DELETE FROM spawn_group WHERE groupId IN (67, 68);
INSERT INTO spawn_group (groupId, spawnType, spawnId) VALUES
(67, 1, 9577),
(67, 1, 9578),
(67, 1, 9579),
(68, 1, 9598),
(68, 1, 9599),
(68, 1, 9600);
