-- make sure timers are real-time via flagsCustom
UPDATE `item_template` SET `flagsCustom`=`flagsCustom`|1 WHERE `entry` IN(39878,44623,44625,44626,44632,44717);
