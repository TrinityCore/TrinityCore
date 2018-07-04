-- fix random inhabittype
UPDATE `creature_template` SET `inhabittype`=`inhabittype`&~8 WHERE `entry`=18679;
