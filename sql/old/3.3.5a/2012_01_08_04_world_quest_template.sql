-- Update quest 13093 (sharable/repeatable quest)
UPDATE `quest_template` SET `PrevQuestId`=13092,`Flags`=`Flags`|8192,`SpecialFlags`=1,`OfferRewardText`='Choose your fate, $N.',`RequestItemsText`='Bring me more vrykul bones and we will influence the fates in your favor.' WHERE `id`=13093;
