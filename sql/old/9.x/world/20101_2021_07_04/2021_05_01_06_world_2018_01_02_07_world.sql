-- 'Cabal Agent' is not a CIVILIAN
UPDATE `creature_template` SET `flags_extra`=`flags_extra`&(~2) WHERE `entry`=19503;
