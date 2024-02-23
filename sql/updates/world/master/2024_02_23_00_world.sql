DELETE FROM `areatrigger_scripts` WHERE `entry` IN (6632, 6633, 5347, 5348);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6632, 'at_av_exploit'),
(6633, 'at_av_exploit'),
(5347, 'at_ds_pipe_knockback'),
(5348, 'at_ds_pipe_knockback');
