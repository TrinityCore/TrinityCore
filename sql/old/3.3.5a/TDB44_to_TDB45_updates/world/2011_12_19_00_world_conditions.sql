UPDATE spell_dbc SET EffectImplicitTargetA1 = 22, EffectImplicitTargetB1 = 7 WHERE Id = 58630;

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceEntry IN (61863, 68663);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceEntry, ConditionTypeOrReference, ConditionValue1, Comment) VALUES
(13, 61863, 18, 1, 'The Prophet Tharon''ja - Achievement Check'),
(13, 68663, 18, 1, 'The Black Knight - Kill Credit'),
(13, 58630, 18, 1, 'Mal''Ganis - Kill Credit');
