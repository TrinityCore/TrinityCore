DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9677;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=28217;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9677, 0, 0, 0, 1, 1, 51329, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if injured rainspeaker oracle has aura Feign Death'),
(15, 9677, 0, 0, 0, 9, 0, 12540, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if Just following orders taken'),
(15, 9677, 0, 0, 0, 8, 0, 12570, 0, 0, 1, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if Player does not have Fortunate Misunderstandings rewarded'),
(15, 9677, 0, 0, 0,28, 0, 12570, 0, 0, 1, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if Player does not have Fortunate Misunderstandings complete'),
(15, 9677, 0, 0, 1, 1, 1, 51329, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if injured rainspeaker oracle has aura Feign Death'),
(15, 9677, 0, 0, 1, 8, 0, 12540, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if Just following orders rewarded'),
(15, 9677, 0, 0, 1, 8, 0, 12570, 0, 0, 1, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if Player does not have Fortunate Misunderstandings rewarded'),
(15, 9677, 0, 0, 1,28, 0, 12570, 0, 0, 1, 0, 0, '', 'Injured Rainspeaker Oracle only display gossip if Player does not have Fortunate Misunderstandings complete'),
(22, 7, 28217, 0, 0, 9, 0, 12540, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle - Only run SAI if player has Just Following Orders taken'),
(22, 8, 28217, 0, 0, 9, 0, 12570, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle - Only run SAI if player has Fortunate Misunderstandings Taken'),
(22, 8, 28217, 0, 0, 1, 1, 51329, 0, 0, 1, 0, 0, '', 'Injured Rainspeaker Oracle - Only run SAI if Injured rainspeaker oracle does have aura - feign death'),
(22, 9, 28217, 0, 0, 16, 0, 1101, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle - Only run SAI if player is Alliance'),
(22, 10, 28217, 0, 0, 16, 0, 690, 0, 0, 0, 0, 0, '', 'Injured Rainspeaker Oracle - Only run SAI if player is Horde');
