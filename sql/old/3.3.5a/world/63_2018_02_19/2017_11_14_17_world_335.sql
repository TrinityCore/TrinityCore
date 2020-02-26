-- Love is in the Air: "A Gift for the ..." quests
DELETE FROM `quest_request_items` WHERE `ID` IN (24597,24609,24610,24611,24612,24613,24614,24615);
INSERT INTO `quest_request_items` (`ID`,`CompletionText`,`VerifiedBuild`) VALUES
(24597,'Well met, $c. Did you have something for me?',-1),
(24609,'Well met, $c. Did you have something for me?',-1),
(24610,'Well met, $c. Did you have something for me?',-1),
(24611,'Well met, $c. Did you have something for me?',-1),
(24612,'Well met, $c. Did you have something for me?',-1),
(24613,'Well met, $c. Did you have something for me?',-1),
(24614,'Well met, $c. Did you have something for me?',-1),
(24615,'Well met, $c. Did you have something for me?',-1);
DELETE FROM `quest_offer_reward` WHERE `ID` IN (24597,24609,24610,24611,24612,24613,24614,24615);
INSERT INTO `quest_offer_reward` (`ID`,`RewardText`,`VerifiedBuild`) VALUES
(24597,'My thanks for this Lovely Charm Bracelet.',-1),
(24609,'My thanks for this Lovely Charm Bracelet.',-1),
(24610,'My thanks for this Lovely Charm Bracelet.',-1),
(24611,'My thanks for this Lovely Charm Bracelet.',-1),
(24612,'My thanks for this Lovely Charm Bracelet.',-1),
(24613,'My thanks for this Lovely Charm Bracelet.',-1),
(24614,'My thanks for this Lovely Charm Bracelet.',-1),
(24615,'My thanks for this Lovely Charm Bracelet.',-1);
