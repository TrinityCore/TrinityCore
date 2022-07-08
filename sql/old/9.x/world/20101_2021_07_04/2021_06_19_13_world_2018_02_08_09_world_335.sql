-- Zorbin Fandazzle --> Add gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=11361;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,11361,7116,0,0,8,0,25465,0,0,0,0,0,"","Show gossip text 5444 if quest 'Still With The Zapped Giants' is rewarded"),
(14,11361,7116,0,0,8,0,25466,0,0,0,0,0,"","Show gossip text 5444 if quest 'Even More Fuel for the Zapping' is rewarded"),
(15,11361,0,0,0,8,0,25465,0,0,0,0,0,"","Show gossip option if quest 'Still With The Zapped Giants' is rewarded"),
(15,11361,0,0,0,8,0,25466,0,0,0,0,0,"","Show gossip option if quest 'Even More Fuel for the Zapping' is rewarded");

UPDATE `gossip_menu_option` SET `OptionType`=3,`OptionNpcFlag`=128 WHERE `MenuID`=11361 AND `OptionIndex`=0;
