-- 
-- Silithus Stone spells should ignore LoS
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (24803,24745,24747,24757,24759,24761,24762,24766,24769,24771,24773,24785,24787,24791,24792,24793);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 24803, 64, '', '', 'Abyssal Punishment ignores LoS'),
(0, 24745, 64, '', '', 'Summon Templar, Trigger ignores LoS'),
(0, 24747, 64, '', '', 'Summon Templar Fire, Trigger ignores LoS'),
(0, 24757, 64, '', '', 'Summon Templar Air, Trigger ignores LoS'),
(0, 24759, 64, '', '', 'Summon Templar Earth, Trigger ignores LoS'),
(0, 24761, 64, '', '', 'Summon Templar Water, Trigger ignores LoS'),
(0, 24762, 64, '', '', 'Summon Duke, Trigger ignores LoS'),
(0, 24766, 64, '', '', 'Summon Duke Fire, Trigger ignores LoS'),
(0, 24769, 64, '', '', 'Summon Duke Air, Trigger ignores LoS'),
(0, 24771, 64, '', '', 'Summon Duke Earth, Trigger ignores LoS'),
(0, 24773, 64, '', '', 'Summon Duke Water, Trigger ignores LoS'),
(0, 24785, 64, '', '', 'Summon Royal, Trigger ignores LoS'),
(0, 24787, 64, '', '', 'Summon Royal Fire, Trigger ignores LoS'),
(0, 24791, 64, '', '', 'Summon Royal Air, Trigger ignores LoS'),
(0, 24792, 64, '', '', 'Summon Royal Earth, Trigger ignores LoS'),
(0, 24793, 64, '', '', 'Summon Royal Water, Trigger ignores LoS');
