-- Change Flags for the Body and Heart Quest
UPDATE `quest_template` SET `Flags`=`Flags`&~2, `SpecialFlags`=`SpecialFlags`|2 WHERE `id` IN (6001,6002);
