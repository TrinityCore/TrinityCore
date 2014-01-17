DELETE FROM `spell_bonus_data` WHERE `entry` IN (48568,48567,33745);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(48568,0,0,0,0.01,'Druid - Lacerate Rank 3($AP*0.05/number of ticks)'),
(48567,0,0,0,0.01,'Druid - Lacerate Rank 2($AP*0.05/number of ticks)'),
(33745,0,0,0,0.01,'Druid - Lacerate Rank 1($AP*0.05/number of ticks)');
