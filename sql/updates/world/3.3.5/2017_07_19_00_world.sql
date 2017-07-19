-- Fixes "Bring 'Em Back Alive" Borean quest
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
(16, 0, 25596, 0, 1, 23, 0, 4144, 0, 0, 0, 0, 0, '','Bring Em Back Alive: Dismount when player outside of intended zone'),
(16, 0, 25596, 0, 2, 23, 0, 4143, 0, 0, 0, 0, 0, '','Bring Em Back Alive: Dismount when player outside of intended zone'),
(16, 0, 25596, 0, 3, 23, 0, 4142, 0, 0, 0, 0, 0, '','Bring Em Back Alive: Dismount when player outside of intended zone'),
(16, 0, 25596, 0, 4, 23, 0, 4141, 0, 0, 0, 0, 0, '','Bring Em Back Alive: Dismount when player outside of intended zone');
