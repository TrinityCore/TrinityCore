DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=35 AND `SourceEntry` IN (26154,44889,46614,46050,47629,51629,46736,46623,46727,48473,48474);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(35, 0, 26154, 0, 0, 22, 0, 609, 0, 0, '', 1, 0, 0, '', 'Learn Runeforging automatically - outside Ebon Hold'),
(35, 0, 44889, 0, 0, 56, 0, 83446, 0, 0, '', 0, 0, 0, '', 'Learn Touch of Death Notification Driver automatically - outside Exile''s Reach'),
(35, 0, 46614, 0, 0, 56, 0, 94589, 0, 0, '', 0, 0, 0, '', 'Learn Emerald Blossom automatically - outside The Forbidden Reach'),
(35, 0, 46050, 0, 0, 56, 0, 94589, 0, 0, '', 0, 0, 0, '', 'Learn Deep Breath automatically - outside The Forbidden Reach'),
(35, 0, 47629, 0, 0, 15, 0, 4096, 0, 0, '', 1, 0, 0, '', 'Learn Chosen Identity automatically - never as Evoker'),
(35, 0, 51629, 0, 0, 47, 0, 65101, 64, 0, '', 0, 0, 0, '', 'Learn Visage automatically - when An Iconic, Draconic Look is completed'),
(35, 0, 51629, 0, 1, 47, 0, 65613, 64, 0, '', 0, 0, 0, '', 'Learn Visage automatically - when An Iconic, Draconic Look is completed'),
(35, 0, 46736, 0, 0, 15, 0, 4096, 0, 0, '', 1, 0, 0, '', 'Learn Visage automatically - never as Evoker'),
(35, 0, 46623, 0, 0, 56, 0, 94589, 0, 0, '', 0, 0, 0, '', 'Learn Soar automatically - outside The Forbidden Reach'),
(35, 0, 46727, 0, 0, 56, 0, 96275, 0, 0, '', 0, 0, 0, '', 'Learn Activating Specialization automatically - outside The Forbidden Reach'),
(35, 0, 48473, 0, 0, 47, 0, 24593, 64, 0, '', 0, 0, 0, '', 'Learn Calm the Wolf automatically - when Neither Human Nor Beast is completed'),
(35, 0, 48473, 0, 1, 22, 0, 654, 0, 0, '', 1, 0, 0, '', 'Learn Calm the Wolf automatically - outside Gilneas'),
(35, 0, 48474, 0, 0, 47, 0, 24593, 64, 0, '', 0, 0, 0, '', 'Learn Calm the Wolf automatically - when Neither Human Nor Beast is completed'),
(35, 0, 48474, 0, 1, 22, 0, 654, 0, 0, '', 1, 0, 0, '', 'Learn Calm the Wolf automatically - outside Gilneas');
