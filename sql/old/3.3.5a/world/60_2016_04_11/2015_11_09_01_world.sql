-- 
UPDATE `gossip_menu_option` SET `option_text`="What's on the auction house today?", `OptionBroadcastTextID`=35877 WHERE `menu_id`=10656 AND id=0;

UPDATE `conditions` SET `ConditionTypeOrReference`=17, `ConditionValue1`=2796, `comment`="Only allow players who have the achievement Brew of the Month to access vendor" WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9549 AND `ElseGroup`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9549 AND `ElseGroup`=2;
