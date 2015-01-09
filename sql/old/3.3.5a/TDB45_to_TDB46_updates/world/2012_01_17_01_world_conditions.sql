-- Condition update to flags
DELETE FROM `conditions` WHERE `ConditionTypeOrReference`=5;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,13846,0,5,1106,127,0,0,'','Quest Contributin'' To The Cause - Requires Argent Crusade hated thru revered'),
(20,0,13846,0,5,1106,127,0,0,'','Quest Contributin'' To The Cause - Requires Argent Crusade hated thru revered'),
(14,21258,7594,0,5,270,120,0,0,'','Only show text_id 7594 if player is neutral thru revered with Zandalar Tribe (270)'),
(14,21258,7595,0,5,270,128,0,0,'','Only show text_id 7595 if player is exalted with Zandalar Tribe (270)'),
(15,21258,0,0,5,270,128,0,0,'','Only show gossip option if player is exalted with Zandalar Tribe (270)'),
(15,21259,0,0,5,270,128,0,0,'','Only show gossip option if player is exalted with Zandalar Tribe (270)'),
(15,21260,0,0,5,270,128,0,0,'','Only show gossip option if player is exalted with Zandalar Tribe (270)'),
(1,23342,32726,0,5,1015,240,0,0,'','Murkblood Escape Plans - when Netherwing friendly thru exalted'),
(1,23286,32726,0,5,1015,240,0,0,'','Murkblood Escape Plans - when Netherwing friendly thru exalted');
