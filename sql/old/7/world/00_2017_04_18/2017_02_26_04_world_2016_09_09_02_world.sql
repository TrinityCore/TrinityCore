-- fix Sniffing out the Perpetrator (Horde side), issue #17914
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=29695 AND `SourceEntry`=40971;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
	(1,29695,40971,0,47,12855,(2|8|64),0,0,"Brann's Communicator - Only drop if player has 'Sniffing out the Perpetrator' (12855) completed or rewarded."),
	(1,29695,40971,0, 2,40971,     1,1,1,"Brann's Communicator - Only drop if player does not have 1 Brann's Communicator in their inventory or bank."),
	(1,29695,40971,1,47,12910,(2|8|64),0,0,"Brann's Communicator - Only drop if player has 'Sniffing out the Perpetrator' (12910) completed or rewarded."),
	(1,29695,40971,1, 2,40971,     1,1,1,"Brann's Communicator - Only drop if player does not have 1 Brann's Communicator in their inventory or bank.");
