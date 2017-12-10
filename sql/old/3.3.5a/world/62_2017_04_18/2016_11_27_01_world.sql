--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=29857 AND `SourceEntry`=55460;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(18, 29857, 55460, 0, 0, 9, 0, 12910, 0, 0, 0, 0, 0, '', "Ride Frostbite (Khaliisi's Pet) Spellclick requires Active (taken) quest 'Sniffing Out the Perpetrator'.");
--
