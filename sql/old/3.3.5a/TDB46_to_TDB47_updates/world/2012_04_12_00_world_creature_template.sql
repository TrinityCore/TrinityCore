-- Update proper modelid for Celestial Steed (31957 is wrong)
UPDATE `creature_template` SET `modelid1`=31958,`modelid2`=0 WHERE `entry`=40625;
