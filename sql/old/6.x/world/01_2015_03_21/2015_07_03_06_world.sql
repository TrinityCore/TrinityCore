ALTER TABLE `conditions` CHANGE `ConditionValue1` `ConditionValue1` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `conditions` CHANGE `ConditionValue2` `ConditionValue2` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `conditions` CHANGE `ConditionValue3` `ConditionValue3` INT(10) UNSIGNED NOT NULL DEFAULT '0';

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10144 AND `SourceEntry`=1 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=16;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(15,10144,1,0,16,33555378,0,0,0,'','Show the gossip if the player is from the horde', 0);
