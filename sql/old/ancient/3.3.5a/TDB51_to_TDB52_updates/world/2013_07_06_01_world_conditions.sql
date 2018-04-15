UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`=12486;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) and `SourceEntry`IN(11595,11596,11597,12486);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(20,0,12486,0,0,8,0,11595,0,0,0,0,0, '', 'To Bor gorok Outpost,Quickly! once The Defense of Warsong Hold Has been completed'),
(19,0,12486,0,0,8,0,11595,0,0,0,0,0, '', 'To Bor gorok Outpost,Quickly! once The Defense of Warsong Hold Has been completed'),
(20,0,12486,0,1,8,0,11596,0,0,0,0,0, '', 'To Bor gorok Outpost,Quickly! once The Defense of Warsong Hold Has been completed'),
(19,0,12486,0,1,8,0,11596,0,0,0,0,0, '', 'To Bor gorok Outpost,Quickly! once The Defense of Warsong Hold Has been completed'),
(20,0,12486,0,2,8,0,11597,0,0,0,0,0, '', 'To Bor gorok Outpost,Quickly! once The Defense of Warsong Hold Has been completed'),
(19,0,12486,0,2,8,0,11597,0,0,0,0,0, '', 'To Bor gorok Outpost,Quickly! once The Defense of Warsong Hold Has been completed'),
(20,0,11595,0,0,8,0,7784,0,0,0,0,0, '', 'Defense of Warsong Hold (11595) Only if player has completed The Lord of Blackrock'),
(19,0,11595,0,0,8,0,7784,0,0,0,0,0, '', 'Defense of Warsong Hold (11595) Only if player has completed The Lord of Blackrock'),
(20,0,11596,0,0,8,0,7784,0,0,1,0,0, '', 'Defense of Warsong Hold (11596) Only if player has not completed The Lord of Blackrock'),
(19,0,11596,0,0,8,0,7784,0,0,1,0,0, '', 'Defense of Warsong Hold (11596) Only if player has not completed The Lord of Blackrock'),
(20,0,11596,0,0,8,0,8743,0,0,1,0,0, '', 'Defense of Warsong Hold (11596) Only if player has not completed Bang a Gong'),
(19,0,11596,0,0,8,0,8743,0,0,1,0,0, '', 'Defense of Warsong Hold (11596) Only if player has not completed Bang a Gong'),
(20,0,11597,0,0,8,0,8743,0,0,0,0,0, '', 'Defense of Warsong Hold (11597) Only if player has completed Bang a Gong'),
(19,0,11597,0,0,8,0,8743,0,0,0,0,0, '', 'Defense of Warsong Hold (11597) Only if player has completed Bang a Gong');
