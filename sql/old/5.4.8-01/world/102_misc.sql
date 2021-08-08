DELETE FROM `conditions` WHERE `SourceEntry` IN (43816, 43818, 43820, 43822);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 43816, 0, 0, 22, 0, 528, 0, 0, 0, 0, '', 'Charm of the Bloodletter, only for Zul Aman'),
(17, 0, 43820, 0, 0, 22, 0, 528, 0, 0, 0, 0, '', 'Charm of the Witch Doctor, only for Zul Aman'),
(17, 0, 43822, 0, 0, 22, 0, 528, 0, 0, 0, 0, '', 'Charm of the Raging Defender, only for Zul Aman'),
(17, 0, 43818, 0, 0, 22, 0, 528, 0, 0, 0, 0, '', 'Charm of Mighty Mojo, only for Zul Aman');

REPLACE INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES 
(16614, 0, 0, 0, 0, 'Item - Storm Gauntlets');
