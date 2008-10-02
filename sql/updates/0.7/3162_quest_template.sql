UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|'32' WHERE `Repeatable`='1';
ALTER TABLE `quest_template` DROP `Repeatable`;